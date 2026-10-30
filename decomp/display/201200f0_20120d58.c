// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== userdef_riic2_wait_tx_empty @ 201200f0 (20 bytes)

/* Spins until the ch2 transmit-empty flag 0x2080045A is set [fact]; Renesas RZ/A1H RIIC sample
   driver (riic.c / riic_userdef.c) [inference: same call structure, per-channel flag bytes and mode
   arguments] */

void userdef_riic2_wait_tx_empty(void)

{
  do {
  } while (DAT_2080045a == '\0');
  return;
}


// ===== userdef_riic3_wait_tx_empty @ 20120104 (20 bytes)

/* Spins until the ch3 transmit-empty flag 0x2080045B is set [fact]; Renesas RZ/A1H RIIC sample
   driver (riic.c / riic_userdef.c) [inference: same call structure, per-channel flag bytes and mode
   arguments] */

void userdef_riic3_wait_tx_empty(void)

{
  do {
  } while (DAT_2080045b == '\0');
  return;
}


// ===== userdef_riic0_wait_tx_end @ 20120118 (48 bytes)

/* (mode): spins until the ch0 transmit-end flag (mode 0) or receive-full flag (mode 1) is set
   [fact]; Renesas RZ/A1H RIIC sample driver (riic.c / riic_userdef.c) [inference: same call
   structure, per-channel flag bytes and mode arguments] */

void userdef_riic0_wait_tx_end(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045c == '\0');
    return;
  }
  do {
  } while (DAT_20800454 == '\0');
  return;
}


// ===== userdef_riic1_wait_tx_end @ 20120148 (48 bytes)

/* (mode): spins until the ch1 transmit-end flag (mode 0) or receive-full flag (mode 1) is set
   [fact]; Renesas RZ/A1H RIIC sample driver (riic.c / riic_userdef.c) [inference: same call
   structure, per-channel flag bytes and mode arguments] */

void userdef_riic1_wait_tx_end(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045d == '\0');
    return;
  }
  do {
  } while (DAT_20800455 == '\0');
  return;
}


// ===== userdef_riic2_wait_tx_end @ 201201c4 (48 bytes)

/* (mode): spins until the ch2 transmit-end flag (mode 0) or receive-full flag (mode 1) is set
   [fact]; Renesas RZ/A1H RIIC sample driver (riic.c / riic_userdef.c) [inference: same call
   structure, per-channel flag bytes and mode arguments] */

void userdef_riic2_wait_tx_end(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045e == '\0');
    return;
  }
  do {
  } while (DAT_20800456 == '\0');
  return;
}


// ===== userdef_riic3_wait_tx_end @ 201201f4 (48 bytes)

/* (mode): spins until the ch3 transmit-end flag (mode 0) or receive-full flag (mode 1) is set
   [fact]; Renesas RZ/A1H RIIC sample driver (riic.c / riic_userdef.c) [inference: same call
   structure, per-channel flag bytes and mode arguments] */

void userdef_riic3_wait_tx_end(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045f == '\0');
    return;
  }
  do {
  } while (DAT_20800457 == '\0');
  return;
}


// ===== userdef_riic0_wait_bus_master @ 20120224 (72 bytes)

/* (mode): spins on RIIC0CR2 bit 7 (BBSY) until set (mode 1) or clear (mode 0) [fact]; was
   riic_init, but it opens nothing (the channel open is userdef_riic0_init 0x2011FC8C); Renesas
   RZ/A1H RIIC sample riic_userdef.c [inference: same call structure, per-channel flag bytes and
   mode arguments] */

void userdef_riic0_wait_bus_master(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC0CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC0CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== userdef_riic1_wait_bus_master @ 2012026c (72 bytes)

/* (mode): spins on RIIC1CR2 bit 7 (BBSY) until set (mode 1) or clear (mode 0) [fact]; Renesas
   RZ/A1H RIIC sample driver (riic.c / riic_userdef.c) [inference: same call structure, per-channel
   flag bytes and mode arguments] */

void userdef_riic1_wait_bus_master(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC1CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC1CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== userdef_riic2_wait_bus_master @ 201202b4 (72 bytes)

/* (mode): spins on RIIC2CR2 bit 7 (BBSY) until set (mode 1) or clear (mode 0) [fact]; Renesas
   RZ/A1H RIIC sample driver (riic.c / riic_userdef.c) [inference: same call structure, per-channel
   flag bytes and mode arguments] */

void userdef_riic2_wait_bus_master(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC2CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC2CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== userdef_riic3_wait_bus_master @ 201202fc (72 bytes)

/* (mode): spins on RIIC3CR2 bit 7 (BBSY) until set (mode 1) or clear (mode 0) [fact]; Renesas
   RZ/A1H RIIC sample driver (riic.c / riic_userdef.c) [inference: same call structure, per-channel
   flag bytes and mode arguments] */

void userdef_riic3_wait_bus_master(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC3CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC3CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== userdef_riic0_wait_stop @ 20120344 (36 bytes)

/* Spins until RIIC0SR2 bit 3 (STOP) is set [fact]; Renesas RZ/A1H RIIC sample driver (riic.c /
   riic_userdef.c) [inference: same call structure, per-channel flag bytes and mode arguments] */

void userdef_riic0_wait_stop(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC0SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== userdef_riic1_wait_stop @ 20120368 (36 bytes)

/* Spins until RIIC1SR2 bit 3 (STOP) is set [fact]; Renesas RZ/A1H RIIC sample driver (riic.c /
   riic_userdef.c) [inference: same call structure, per-channel flag bytes and mode arguments] */

void userdef_riic1_wait_stop(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC1SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== userdef_riic2_wait_stop @ 2012038c (36 bytes)

/* Spins until RIIC2SR2 bit 3 (STOP) is set [fact]; Renesas RZ/A1H RIIC sample driver (riic.c /
   riic_userdef.c) [inference: same call structure, per-channel flag bytes and mode arguments] */

void userdef_riic2_wait_stop(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC2SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== userdef_riic3_wait_stop @ 201203b0 (36 bytes)

/* Spins until RIIC3SR2 bit 3 (STOP) is set [fact]; Renesas RZ/A1H RIIC sample driver (riic.c /
   riic_userdef.c) [inference: same call structure, per-channel flag bytes and mode arguments] */

void userdef_riic3_wait_stop(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC3SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== riic0_ri_isr @ 201203d4 (8 bytes)

/* ISR stub: R_RIIC_RiInterrupt(0); RIIC0 RI vector per peripherals.md [fact] */

void riic0_ri_isr(void)

{
  R_RIIC_RiInterrupt(0);
  return;
}


// ===== riic0_ti_isr @ 201203dc (8 bytes)

/* ISR stub: R_RIIC_TiInterrupt(0); RIIC0 TI vector [fact] */

void riic0_ti_isr(void)

{
  R_RIIC_TiInterrupt(0);
  return;
}


// ===== riic0_tei_isr @ 201203e4 (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120ccc) */
/* WARNING: Removing unreachable block (ram,0x20120cd4) */
/* WARNING: Removing unreachable block (ram,0x20120cf8) */
/* WARNING: Removing unreachable block (ram,0x20120cdc) */
/* WARNING: Removing unreachable block (ram,0x20120ce0) */
/* WARNING: Removing unreachable block (ram,0x20120ce4) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120cf0) */
/* ISR stub: R_RIIC_TeiInterrupt(0) (inlined); RIIC0 TEI vector [fact] */

undefined4 riic0_tei_isr(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  userdef_riic0_set_tx_end(0);
  pvVar1 = riic_base(0);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== riic1_ri_isr @ 201203ec (8 bytes)

/* ISR stub: R_RIIC_RiInterrupt(1); RIIC1 RI vector per peripherals.md [fact] */

void riic1_ri_isr(void)

{
  R_RIIC_RiInterrupt(1);
  return;
}


// ===== riic1_ti_isr @ 201203f4 (8 bytes)

/* ISR stub: R_RIIC_TiInterrupt(1); RIIC1 TI vector [fact] */

void riic1_ti_isr(void)

{
  R_RIIC_TiInterrupt(1);
  return;
}


// ===== riic1_tei_isr @ 201203fc (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120cd4) */
/* WARNING: Removing unreachable block (ram,0x20120cf8) */
/* WARNING: Removing unreachable block (ram,0x20120cdc) */
/* WARNING: Removing unreachable block (ram,0x20120ce0) */
/* WARNING: Removing unreachable block (ram,0x20120ce4) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120ce8) */
/* ISR stub: R_RIIC_TeiInterrupt(1) (inlined); RIIC1 TEI vector [fact] */

undefined4 riic1_tei_isr(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  userdef_riic1_set_tx_end();
  pvVar1 = riic_base(1);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== riic2_ri_isr @ 20120404 (8 bytes)

/* ISR stub: R_RIIC_RiInterrupt(2); RIIC2 RI vector per peripherals.md [fact] */

void riic2_ri_isr(void)

{
  R_RIIC_RiInterrupt(2);
  return;
}


// ===== riic2_ti_isr @ 2012040c (8 bytes)

/* ISR stub: R_RIIC_TiInterrupt(2); RIIC2 TI vector [fact] */

void riic2_ti_isr(void)

{
  R_RIIC_TiInterrupt(2);
  return;
}


// ===== riic2_tei_isr @ 20120414 (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120cdc) */
/* WARNING: Removing unreachable block (ram,0x20120ce0) */
/* WARNING: Removing unreachable block (ram,0x20120ce4) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120cf0) */
/* WARNING: Removing unreachable block (ram,0x20120ce8) */
/* ISR stub: R_RIIC_TeiInterrupt(2) (inlined); RIIC2 TEI vector [fact] */

undefined4 riic2_tei_isr(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  userdef_riic2_set_tx_end();
  pvVar1 = riic_base(2);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== riic3_ri_isr @ 2012041c (8 bytes)

/* ISR stub: R_RIIC_RiInterrupt(3); RIIC3 RI vector per peripherals.md [fact] */

void riic3_ri_isr(void)

{
  R_RIIC_RiInterrupt(3);
  return;
}


// ===== riic3_ti_isr @ 20120424 (8 bytes)

/* ISR stub: R_RIIC_TiInterrupt(3); RIIC3 TI vector [fact] */

void riic3_ti_isr(void)

{
  R_RIIC_TiInterrupt(3);
  return;
}


// ===== riic3_tei_isr @ 2012042c (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120cf0) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120cf8) */
/* WARNING: Removing unreachable block (ram,0x20120ce8) */
/* ISR stub: R_RIIC_TeiInterrupt(3) (inlined); RIIC3 TEI vector [fact] */

undefined4 riic3_tei_isr(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  userdef_riic3_set_tx_end();
  pvVar1 = riic_base(3);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== R_RIIC_Init @ 20120454 (80 bytes)

/* (ch 0..3): calls userdef_riic{ch}_init, returns 0, or -1 for ch > 3; task_tsc2007 opens ch 2
   (input.md) [fact]; Renesas sample R_RIIC_Init [inference] */

undefined4 R_RIIC_Init(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      userdef_riic0_init();
    }
    else if (param_1 == 1) {
      userdef_riic1_init();
    }
    else if (param_1 == 2) {
      userdef_riic2_init();
    }
    else if (param_1 == 3) {
      userdef_riic3_init();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== riic_base @ 201204a4 (48 bytes)

/* (ch 0..3): RIIC register base 0xFCFEE000 + 0x400*ch (docs/memory-maps.md) [fact] */

void * riic_base(int param_1)

{
  dword *pdVar1;
  
  pdVar1 = &RIIC_RIIC0CR1;
  if (param_1 != 0) {
    if (param_1 == 1) {
      pdVar1 = &RIIC_RIIC1CR1;
    }
    else if (param_1 == 2) {
      pdVar1 = &RIIC_RIIC2CR1;
    }
    else if (param_1 == 3) {
      pdVar1 = &RIIC_RIIC3CR1;
    }
  }
  return pdVar1;
}


// ===== riic_transmit_stop @ 201204d4 (56 bytes)

/* (ch): clears ICSR2 STOP (bit 3), sets ICCR2 SP (bit 3) [fact]; Renesas sample riic_transmit_stop
   [inference] */

void riic_transmit_stop(int param_1)

{
  void *pvVar1;
  
  pvVar1 = riic_base(param_1);
  reg_rmw8((int)pvVar1 + 0x24,0,3,8);
  reg_rmw8((int)pvVar1 + 4,1,3,8);
  return;
}


// ===== riic_transmit_restart @ 2012050c (180 bytes)

/* (ch): waits for bus busy, clears the flags, sets ICCR2 RS (bit 2) [fact]; Renesas sample
   riic_transmit_restart [inference] */

void riic_transmit_restart(int param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    userdef_riic0_wait_bus_master(1);
    userdef_riic0_init_rx_full();
    userdef_riic0_init_tx_empty();
    userdef_riic0_init_tx_end(0);
  }
  else if (param_1 == 1) {
    userdef_riic1_wait_bus_master(1);
    userdef_riic1_init_rx_full();
    userdef_riic1_init_tx_empty();
    userdef_riic1_init_tx_end(0);
  }
  else if (param_1 == 2) {
    userdef_riic2_wait_bus_master(1);
    userdef_riic2_init_rx_full();
    userdef_riic2_init_tx_empty();
    userdef_riic2_init_tx_end(0);
  }
  else if (param_1 == 3) {
    userdef_riic3_wait_bus_master(1);
    userdef_riic3_init_rx_full();
    userdef_riic3_init_tx_empty();
    userdef_riic3_init_tx_end(0);
  }
  pvVar1 = riic_base(param_1);
  reg_rmw8((int)pvVar1 + 4,1,2,4);
  return;
}


// ===== riic_transmit_start @ 201205c0 (180 bytes)

/* (ch): waits for bus free, clears the flags, sets ICCR2 ST (bit 1) [fact]; Renesas sample
   riic_transmit_start [inference] */

void riic_transmit_start(int param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    userdef_riic0_wait_bus_master(0);
    userdef_riic0_init_rx_full();
    userdef_riic0_init_tx_empty();
    userdef_riic0_init_tx_end(0);
  }
  else if (param_1 == 1) {
    userdef_riic1_wait_bus_master(0);
    userdef_riic1_init_rx_full();
    userdef_riic1_init_tx_empty();
    userdef_riic1_init_tx_end(0);
  }
  else if (param_1 == 2) {
    userdef_riic2_wait_bus_master(0);
    userdef_riic2_init_rx_full();
    userdef_riic2_init_tx_empty();
    userdef_riic2_init_tx_end(0);
  }
  else if (param_1 == 3) {
    userdef_riic3_wait_bus_master(0);
    userdef_riic3_init_rx_full();
    userdef_riic3_init_tx_empty();
    userdef_riic3_init_tx_end(0);
  }
  pvVar1 = riic_base(param_1);
  reg_rmw8((int)pvVar1 + 4,1,1,2);
  return;
}


// ===== R_RIIC_SendCond @ 20120674 (76 bytes)

/* (ch, cond): 0 start, 1 restart, 2 stop condition; -1 for a bad argument [fact]; Renesas sample
   R_RIIC_SendCond [inference] */

undefined4 R_RIIC_SendCond(uint param_1,uint param_2)

{
  if ((param_1 < 4) && (param_2 < 3)) {
    if (param_2 == 0) {
      riic_transmit_start();
    }
    else if (param_2 == 1) {
      riic_transmit_restart();
    }
    else if (param_2 == 2) {
      riic_transmit_stop();
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== riic_transmit @ 201206c0 (144 bytes)

/* (ch, byte): returns -2 on NACK (ICSR2 bit 4), else waits for transmit-empty and writes ICDRT
   (+0x3C) [fact] */

undefined4 riic_transmit(int param_1,undefined1 param_2)

{
  byte bVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  pvVar2 = riic_base(param_1);
  bVar1 = reg_read8((byte *)((int)pvVar2 + 0x24),4,0x10);
  if (bVar1 == 0) {
    uVar3 = 0;
    if (param_1 == 0) {
      userdef_riic0_wait_tx_empty();
      userdef_riic0_init_tx_empty();
    }
    else if (param_1 == 1) {
      userdef_riic1_wait_tx_empty();
      userdef_riic1_init_tx_empty();
    }
    else if (param_1 == 2) {
      userdef_riic2_wait_tx_empty();
      userdef_riic2_init_tx_empty();
    }
    else if (param_1 == 3) {
      userdef_riic3_wait_tx_empty();
      userdef_riic3_init_tx_empty();
    }
    *(undefined1 *)((int)pvVar2 + 0x3c) = param_2;
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}


// ===== R_RIIC_WriteSlaveAddr @ 20120750 (204 bytes)

/* (ch, addr byte, mode): riic_transmit then waits for transmit end (mode 0) or receive full (mode
   1); -2 on NACK [fact]; tsc2007_write_cmd / tsc2007_read12 call it [fact]; Renesas sample name
   [inference] */

int R_RIIC_WriteSlaveAddr(uint param_1,undefined1 param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  
  if ((param_1 < 4) && (param_3 < 2)) {
    iVar2 = riic_transmit(param_1,param_2);
    if (iVar2 == 0) {
      if (param_1 == 0) {
        userdef_riic0_wait_tx_end(param_3);
        userdef_riic0_init_tx_end(param_3);
      }
      else if (param_1 == 1) {
        userdef_riic1_wait_tx_end(param_3);
        userdef_riic1_init_tx_end(param_3);
      }
      else if (param_1 == 2) {
        userdef_riic2_wait_tx_end(param_3);
        userdef_riic2_init_tx_end(param_3);
      }
      else if (param_1 == 3) {
        userdef_riic3_wait_tx_end(param_3);
        userdef_riic3_init_tx_end(param_3);
      }
      pvVar3 = riic_base(param_1);
      bVar1 = reg_read8((byte *)((int)pvVar3 + 0x24),4,0x10);
      if (bVar1 != 0) {
        iVar2 = -2;
      }
    }
    return iVar2;
  }
  return -1;
}


// ===== R_RIIC_Write @ 2012081c (232 bytes)

/* (ch, buf, n): riic_transmit per byte, then waits for transmit end; -2 on NACK [fact]; Renesas
   sample name [inference] */

int R_RIIC_Write(uint param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  if (3 < param_1) {
    return -1;
  }
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    do {
      iVar2 = riic_transmit(param_1,*(undefined1 *)(param_2 + uVar4));
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
    if (param_1 == 0) {
      userdef_riic0_wait_tx_end(0);
      userdef_riic0_init_tx_end(0);
    }
    else if (param_1 == 1) {
      userdef_riic1_wait_tx_end(0);
      userdef_riic1_init_tx_end(0);
    }
    else if (param_1 == 2) {
      userdef_riic2_wait_tx_end(0);
      userdef_riic2_init_tx_end(0);
    }
    else if (param_1 == 3) {
      userdef_riic3_wait_tx_end(0);
      userdef_riic3_init_tx_end(0);
    }
    pvVar3 = riic_base(param_1);
    bVar1 = reg_read8((byte *)((int)pvVar3 + 0x24),4,0x10);
    iVar2 = 0;
    if (bVar1 != 0) {
      iVar2 = -2;
    }
  }
  return iVar2;
}


// ===== riic_clear_nack @ 20120904 (20 bytes)

/* (base): clears ICSR2 NACKF (bit 4) [fact] */

void riic_clear_nack(int param_1)

{
  reg_rmw8(param_1 + 0x24,0,4,0x10);
  return;
}


// ===== riic_detect_stop @ 20120918 (100 bytes)

/* (ch): waits for the STOP flag, clears NACKF and STOP [fact]; Renesas sample riic_detect_stop
   [inference] */

void riic_detect_stop(int param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    userdef_riic0_wait_stop();
  }
  else if (param_1 == 1) {
    userdef_riic1_wait_stop();
  }
  else if (param_1 == 2) {
    userdef_riic2_wait_stop();
  }
  else if (param_1 == 3) {
    userdef_riic3_wait_stop();
  }
  pvVar1 = riic_base(param_1);
  riic_clear_nack();
  reg_rmw8((int)pvVar1 + 0x24,0,3,8);
  return;
}


// ===== riic_receive @ 2012097c (248 bytes)

/* (ch, mode, *out): waits for receive full; mode 1/2/3 set ICMR3 ACKBT/WAIT bits, 4 issues the stop
   condition; reads ICDRR (+0x40) [fact] */

void riic_receive(int param_1,undefined4 param_2,undefined1 *param_3)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    userdef_riic0_wait_rx_full();
    userdef_riic0_init_rx_full();
  }
  else if (param_1 == 1) {
    userdef_riic1_wait_rx_full();
    userdef_riic1_init_rx_full();
  }
  else if (param_1 == 2) {
    userdef_riic2_wait_rx_full();
    userdef_riic2_init_rx_full();
  }
  else if (param_1 == 3) {
    userdef_riic3_wait_rx_full();
    userdef_riic3_init_rx_full();
  }
  pvVar1 = riic_base(param_1);
  switch(param_2) {
  case 1:
    reg_rmw8((int)pvVar1 + 0x10,1,4,0x10);
    reg_rmw8((int)pvVar1 + 0x10,0,3,8);
    break;
  case 2:
    reg_rmw8((int)pvVar1 + 0x10,1,6,0x40);
    break;
  case 3:
    reg_rmw8((int)pvVar1 + 0x10,1,4,0x10);
    reg_rmw8((int)pvVar1 + 0x10,1,3,8);
    break;
  case 4:
    riic_transmit_stop(param_1);
  }
  *param_3 = *(undefined1 *)((int)pvVar1 + 0x40);
  return;
}


// ===== riic_receive_dummy @ 20120a88 (20 bytes)

/* (ch): only computes the channel base in this build (the dummy ICDRR read is gone in the
   decompile) [fact] */

void riic_receive_dummy(uint param_1)

{
  riic_base(param_1);
  return;
}


// ===== R_RIIC_Read @ 20120a9c (272 bytes)

/* (ch, buf, n): n-byte master receive with ICMR3 WAIT/ACKBT handling for the last two bytes, then
   stop and riic_detect_stop [fact]; Renesas sample name [inference] */

undefined4 R_RIIC_Read(uint param_1,int param_2,uint param_3)

{
  void *pvVar1;
  
  if (3 < param_1) {
    return 0xffffffff;
  }
  if (param_3 != 0) {
    pvVar1 = riic_base(param_1);
    if (param_3 == 1) {
      reg_rmw8((int)pvVar1 + 0x10,1,6,0x40);
      reg_rmw8((int)pvVar1 + 0x10,1,4,0x10);
      reg_rmw8((int)pvVar1 + 0x10,1,3,8);
    }
    riic_receive_dummy(param_1);
    if (param_3 != 1) {
      if (param_3 != 2) {
        for (; 3 < param_3; param_3 = param_3 - 1) {
          riic_receive(param_1,0,param_2);
          param_2 = param_2 + 1;
        }
        riic_receive(param_1,2,param_2);
        param_2 = param_2 + 1;
      }
      riic_receive(param_1,3,param_2);
      param_2 = param_2 + 1;
    }
    riic_receive(param_1,4,param_2);
    reg_rmw8((int)pvVar1 + 0x10,0,6,0x40);
    riic_detect_stop(param_1);
    return 0;
  }
  return 0;
}


// ===== R_RIIC_ReadDummy @ 20120bac (28 bytes)

/* (ch): riic_receive_dummy; -1 for ch > 3 [fact] */

undefined4 R_RIIC_ReadDummy(uint param_1)

{
  if (param_1 < 4) {
    riic_receive_dummy(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ===== R_RIIC_DetectStop @ 20120bc8 (28 bytes)

/* (ch): riic_detect_stop; -1 for ch > 3 [fact] */

undefined4 R_RIIC_DetectStop(uint param_1)

{
  if (param_1 < 4) {
    riic_detect_stop(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ===== R_RIIC_ClearNack @ 20120be4 (32 bytes)

/* (ch): riic_clear_nack; -1 for ch > 3 [fact] */

undefined4 R_RIIC_ClearNack(uint param_1)

{
  if (param_1 < 4) {
    riic_base(param_1);
    riic_clear_nack();
    return 0;
  }
  return 0xffffffff;
}


// ===== R_RIIC_RiInterrupt @ 20120c04 (80 bytes)

/* (ch): userdef_riic{ch}_set_rx_full; target of the RI ISR stubs (GIC 190/198/206/214,
   peripherals.md) [fact] */

undefined4 R_RIIC_RiInterrupt(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      userdef_riic0_set_rx_full();
    }
    else if (param_1 == 1) {
      userdef_riic1_set_rx_full();
    }
    else if (param_1 == 2) {
      userdef_riic2_set_rx_full();
    }
    else if (param_1 == 3) {
      userdef_riic3_set_rx_full();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== R_RIIC_TiInterrupt @ 20120c54 (80 bytes)

/* (ch): userdef_riic{ch}_set_tx_empty; target of the TI ISR stubs (GIC 191/199/207/215) [fact] */

undefined4 R_RIIC_TiInterrupt(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      userdef_riic0_set_tx_empty();
    }
    else if (param_1 == 1) {
      userdef_riic1_set_tx_empty();
    }
    else if (param_1 == 2) {
      userdef_riic2_set_tx_empty();
    }
    else if (param_1 == 3) {
      userdef_riic3_set_tx_empty();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== R_RIIC_TeiInterrupt @ 20120cb0 (136 bytes)

/* (ch): userdef_riic{ch}_set_tx_end, then clears ICSR2 TEND (bit 6) [fact]; target of the TEI ISR
   stubs (GIC 189/197/205/213) */

undefined4
R_RIIC_TeiInterrupt(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  void *pvVar2;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      userdef_riic0_set_tx_end(0);
    }
    else if (param_1 == 1) {
      userdef_riic1_set_tx_end();
    }
    else if (param_1 == 2) {
      userdef_riic2_set_tx_end();
    }
    else if (param_1 == 3) {
      userdef_riic3_set_tx_end();
    }
    pvVar2 = riic_base(param_1);
    reg_rmw8((int)pvVar2 + 0x24,0,6,0x40,param_4);
    reg_read8((byte *)((int)pvVar2 + 0x24),6,0x40);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== afscope_init @ 20120d38 (108 bytes)

/* gui_start: clears the AF-FFT ring indices, builds the colour tables of 0x208DCE3C / 0x208DD53C
   and sets the 600-byte record 0x208DD73C (first 200 bytes 0xFF) [fact] */

void afscope_init(void)

{
  DAT_208dd994 = 0;
  DAT_208dd995 = 0;
  afscope_map0_init(&DAT_208dce3c);
  afscope_map1_init(&DAT_208dce3c);
  afscope_map2_init(&DAT_208dce3c);
  afscope_map3_init(&DAT_208dce3c);
  afscope_map4_init(&DAT_208dce3c);
  FUN_20162b50(&DAT_208dd53c);
  __aeabi_memclr4(&DAT_208dd73c,600);
  __aeabi_memset_veneer(&DAT_208dd73c,200,0xff);
  return;
}


// ===== afscope_store_frame @ 20120d40 (188 bytes)

/* 600 B -> 0x208DD73C */

void afscope_store_frame(char *param_1)

{
  if (DAT_208dd994 == '\0') {
    if (*param_1 == '\x01') {
      if ((DAT_208004a0 != '\0') || (DAT_208dd995 != '\0')) goto LAB_20157258;
      memcpy(&DAT_208dd73c,param_1,600);
      DAT_208dd73c = 0xff;
      DAT_208dd73d = 0xff;
      if (((ushort)DAT_20808a84 & 0x400) != 0) {
        memcpy(&DAT_208dd73c,&DAT_20166de8,200);
        memcpy(&DAT_208dd804,&DAT_20166eb0,400);
        return;
      }
    }
  }
  else if (DAT_208dd995 != '\0') {
LAB_20157258:
    __aeabi_memset_veneer(&DAT_208dd73c,600,0xff);
    return;
  }
  return;
}


// ===== affft_wf_freeze_set @ 20120d4c (20 bytes)

/* (v): 0x208DD994 = v; affft_wf_add_row adds no row while it is set; gui_screen_update sets it
   [fact] */

void affft_wf_freeze_set(undefined1 param_1)

{
  DAT_208dd994 = param_1;
  return;
}


// ===== afscope_clear @ 20120d58 (8 bytes)

/* afscope_obj_clear(0x208DCE3C); scope_area_setup calls it [fact] */

void afscope_clear(void)

{
  afscope_obj_clear(&DAT_208dce3c);
  return;
}

