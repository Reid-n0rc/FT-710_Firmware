// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== cpp_task_thunk @ 20162d04 (12 bytes)

/* task entry for C++ objects: exinf = object, calls obj->vtbl[0] */

void cpp_task_thunk(void *param_1)

{
                    /* WARNING: Could not recover jumptable at 0x20162d0c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)**(undefined4 **)param_1)();
  return;
}


// ===== FUN_20162d10 @ 20162d10 (40 bytes)

void FUN_20162d10(void)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 uStack_10;
  undefined4 uStack_c;
  
  local_18 = 0;
  uStack_14 = 1;
  uStack_10 = 0;
  uStack_c = 0;
  itron_acre_mbx(0,&local_18);
  return;
}


// ===== FUN_20162d3c @ 20162d3c (12 bytes)

void FUN_20162d3c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  itron_snd_mbx(param_2,param_3);
  return;
}


// ===== FUN_20162d48 @ 20162d48 (12 bytes)

void FUN_20162d48(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x2e04) = param_2;
  return;
}


// ===== scif_rxi_isr @ 20162dd8 (312 bytes)

/* 1 byte -> RX ring, set_flg(obj+0x818, 1) */

void scif_rxi_isr(scif_uart *uart)

{
  scif_regs *psVar1;
  
  uart->rxi_count = uart->rxi_count + 1;
  psVar1 = uart->regs;
  if ((psVar1->scfsr & 0xff9d) != 0) {
    uart->rx_errors = uart->rx_errors + 1;
  }
  if ((psVar1->scfsr & 2) != 0) {
    if (((uart->rx_wr < uart->rx_rd) || (0x3fe < (int)((uint)uart->rx_wr - (uint)uart->rx_rd))) &&
       ((uart->rx_rd <= uart->rx_wr || ((int)((uint)uart->rx_rd - (uint)uart->rx_wr) < 2)))) {
      psVar1->scfsr = psVar1->scfsr & 0xfffd;
      uart->rx_count = uart->rx_count + 1;
      uart->rx_overflow = uart->rx_overflow + 1;
      return;
    }
    uart->rx_buf[uart->rx_wr] = psVar1->scfrdr;
    DataMemoryBarrier(2);
    uart->rx_wr = uart->rx_wr + 1 & 0x3ff;
    uart->regs->scfsr = uart->regs->scfsr & 0xfffd;
    if (uart->rx_flg != 0) {
      gic_disable_irq(uart->rxi_isr->intno);
    }
    itron_set_flg(uart->rx_flg,1);
    uart->rx_count = uart->rx_count + 1;
    thunk_FUN_20114850(&uart->rx_time);
    return;
  }
  uart->rxi_no_data = uart->rxi_no_data + 1;
  return;
}


// ===== scif_txi_isr @ 20162f10 (156 bytes)

/* TX ring -> SCFTDR */

void scif_txi_isr(scif_uart *uart)

{
  scif_regs *psVar1;
  
  uart->txi_count = uart->txi_count + 1;
  psVar1 = uart->regs;
  if ((psVar1->scfsr & 0x20) == 0) {
    uart->txi_not_ready = uart->txi_not_ready + 1;
    return;
  }
  if (uart->tx_rd != uart->tx_wr) {
    psVar1->scftdr = uart->tx_buf[uart->tx_rd];
    DataMemoryBarrier(2);
    uart->tx_rd = uart->tx_rd + 1 & 0x3ff;
    uart->regs->scfsr = uart->regs->scfsr & 0xff9f;
    uart->tx_count = uart->tx_count + 1;
    thunk_FUN_20114850(&uart->tx_time);
    return;
  }
  psVar1->scscr = psVar1->scscr & 0xff7f;
  return;
}


// ===== uart_obj_init @ 20162fac (104 bytes)

uint uart_obj_init(scif_uart *uart,scif_regs *regs,t_cisr *rxi,t_cisr *txi,uint flg)

{
  uint uVar1;
  
  if (uart->regs == (scif_regs *)0x0) {
    uart->regs = regs;
    uart->rx_flg = flg;
    uart->rxi_isr = rxi;
    uart->txi_isr = txi;
    uVar1 = itron_acre_isr(0,txi);
    if (((int)uVar1 < 1) || (uVar1 = itron_acre_isr(0,uart->rxi_isr), (int)uVar1 < 1)) {
      return 0xffffffff;
    }
  }
  else {
    uart->rx_flg = flg;
  }
  return 0;
}


// ===== scif_irq_off @ 20163014 (36 bytes)

void scif_irq_off(scif_uart *uart)

{
  gic_disable_irq(uart->txi_isr->intno);
  gic_disable_irq(uart->rxi_isr->intno);
  return;
}


// ===== scif_read @ 20163038 (96 bytes)

/* non-blocking read from the 1 KB RX ring */

int scif_read(scif_uart *uart,byte *buf,int n)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0;
  while ((bVar2 = n != 0, n = n + -1, bVar2 && (uart->rx_wr != uart->rx_rd))) {
    *buf = uart->rx_buf[uart->rx_rd];
    DataMemoryBarrier(2);
    uart->rx_rd = uart->rx_rd + 1 & 0x3ff;
    iVar1 = iVar1 + 1;
    buf = buf + 1;
  }
  gic_enable_irq(uart->rxi_isr->intno);
  return iVar1;
}


// ===== scif_start @ 20163098 (52 bytes)

/* scif_open + enable RXI/TXI in the GIC */

void scif_start(scif_uart *uart,uint baud,int bits,int parity,uint stop)

{
  scif_open(uart,baud,bits,parity,stop);
  gic_enable_irq(uart->txi_isr->intno);
  gic_enable_irq(uart->rxi_isr->intno);
  return;
}


// ===== scif_open @ 201630cc (324 bytes)

/* (baud, bits, parity, stop): SCSMR, SCBRR (0x16 + SEMR 0x81 for 345600), FIFO reset */

void scif_open(scif_uart *uart,uint param_2,int param_3,int param_4,uint param_5)

{
  char cVar1;
  byte bVar2;
  ushort uVar3;
  
  uVar3 = 0;
  if (param_3 == 7) {
    uVar3 = 0x40;
  }
  if (param_4 != 0) {
    if (param_4 == 1) {
      uVar3 = uVar3 | 0x20;
    }
    else if (param_4 == 2) {
      uVar3 = uVar3 | 0x30;
    }
  }
  if (param_5 != 1) {
    uVar3 = uVar3 | 8;
  }
  if (param_2 < 0x54600) {
    cVar1 = __aeabi_uidivmod(64000000,param_2 << 5);
    bVar2 = cVar1 - 1;
  }
  else {
    bVar2 = 0x16;
  }
  uart->rx_wr = 0;
  uart->rx_rd = 0;
  uart->tx_wr = 0;
  uart->tx_rd = 0;
  uart->rxi_count = 0;
  uart->rx_count = 0;
  uart->rx_errors = 0;
  uart->rxi_no_data = 0;
  uart->txi_count = 0;
  uart->tx_count = 0;
  uart->txi_not_ready = 0;
  uart->regs->scscr = 0;
  uart->regs->scfcr = uart->regs->scfcr | 6;
  uart->regs->scfsr = uart->regs->scfsr & 0xff6e;
  uart->regs->sclsr = 0;
  uart->regs->scscr = 0;
  uart->regs->scsmr = uVar3;
  uart->regs->scbrr = bVar2;
  if (param_2 < 0x54600) {
    uart->regs->scemr = 0;
  }
  else {
    uart->regs->scemr = uart->regs->scemr | 0x81;
  }
  if ((param_5 & 0x80) != 0) {
    uart->regs->scfcr = uart->regs->scfcr | 1;
  }
  uart->regs->scfcr = uart->regs->scfcr & 0xfff9;
  uart->regs->scscr = uart->regs->scscr | 0xf8;
  return;
}


// ===== scif_read_timeout @ 20163218 (104 bytes)

/* retries every 1 ms up to n times */

int scif_read_timeout(int *param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  iVar3 = 0;
  while( true ) {
    iVar3 = iVar3 + 1;
    iVar1 = (**(code **)(*param_1 + 0x10))(param_1,param_2 + iVar2,param_3 - iVar2);
    iVar2 = iVar2 + iVar1;
    if (iVar2 == param_3) {
      return param_3;
    }
    if (param_4 < iVar3) break;
    itron_dly_tsk(1);
  }
  return -1;
}


// ===== scif_flush @ 20163280 (88 bytes)

uint scif_flush(scif_uart *uart)

{
  gic_disable_irq(uart->txi_isr->intno);
  gic_disable_irq(uart->rxi_isr->intno);
  uart->rx_wr = 0;
  uart->rx_rd = 0;
  uart->tx_wr = 0;
  uart->tx_rd = 0;
  gic_enable_irq(uart->txi_isr->intno);
  gic_enable_irq(uart->rxi_isr->intno);
  return 0;
}


// ===== scif_write @ 201632d8 (136 bytes)

/* copy into the 1 KB TX ring, enable TIE */

uint scif_write(scif_uart *uart,byte *buf,uint n)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)uart->tx_wr;
  uVar3 = (uint)uart->tx_rd;
  if (uVar2 < uVar3) {
    uVar3 = (uVar3 - uVar2) - 1;
  }
  else {
    uVar3 = 0x3ff - (uVar2 - uVar3);
  }
  uVar1 = n;
  if (uVar3 < n) {
    n = 0;
  }
  else {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      uart->tx_buf[uVar2] = *buf;
      uVar2 = uVar2 + 1 & 0x3ff;
      buf = buf + 1;
    }
    uart->tx_wr = (ushort)uVar2;
    DataMemoryBarrier(2);
    uart->regs->scscr = uart->regs->scscr | 0x80;
  }
  return n;
}


// ===== FUN_20163360 @ 20163360 (12 bytes)

void FUN_20163360(undefined4 *param_1)

{
  *param_1 = &PTR_uart_obj_init_2042803c;
  return;
}


// ===== FUN_201633a0 @ 201633a0 (108 bytes)

void FUN_201633a0(int param_1,int param_2,int param_3,int param_4,uint param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_4 == 0) {
    iVar2 = 0;
    do {
      *(undefined1 *)(param_2 + iVar2) =
           *(undefined1 *)(param_1 + (*(byte *)(param_3 + iVar2) ^ param_5));
      iVar2 = iVar2 + 1;
    } while (iVar2 < 800);
    return;
  }
  iVar2 = 0;
  do {
    iVar1 = FUN_201341cc(*(byte *)(param_3 + iVar2) ^ param_5,param_4);
    *(undefined1 *)(param_2 + iVar2) = *(undefined1 *)(param_1 + iVar1);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 800);
  return;
}


// ===== FUN_20163428 @ 20163428 (136 bytes)

undefined4 FUN_20163428(int param_1,int param_2,int param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  
  iVar2 = param_1 + param_2 * 800 + 0xa323;
  param_1 = param_1 + param_2 * 0x100;
  if (param_3 == 8) {
    FUN_201633a0(param_1,param_4,iVar2,param_5);
    uVar1 = FUN_20164674(0x20470330);
    return uVar1;
  }
  if (param_3 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_4,iVar2,param_5);
    uVar1 = FUN_20164654(0x20473b7c);
    return uVar1;
  }
  iVar2 = 0;
  do {
    iVar2 = iVar2 + 1;
  } while (iVar2 < 800);
  return 0;
}


// ===== FUN_201635b8 @ 201635b8 (44 bytes)

void FUN_201635b8(int param_1,undefined1 *param_2)

{
  *param_2 = *(undefined1 *)(param_1 + 0xe);
  param_2[1] = *(undefined1 *)(param_1 + 0xf);
  param_2[2] = *(undefined1 *)(param_1 + 0x11);
  param_2[3] = *(undefined1 *)(param_1 + 0x12);
  param_2[4] = 0;
  return;
}


// ===== FUN_201635e4 @ 201635e4 (24 bytes)

void FUN_201635e4(int param_1,undefined4 param_2)

{
  sprintf_veneer(param_2,&UNK_20428286,param_1 + 4,param_1 + 0xe);
  return;
}


// ===== fwname_pattern_match @ 20163600 (84 bytes)

/* prefix + 4 chars + ".sfl", case-insensitive, exact length */

uint fwname_pattern_match(int *param_1,int param_2,int param_3)

{
  int iVar1;
  uint uVar2;
  
  if (((*param_1 == param_3) && (iVar1 = strncasecmp(param_1[1],param_2,param_1[3]), iVar1 == 0)) &&
     (iVar1 = strncasecmp(param_1[2],param_1[4] + param_2,param_1[5]), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== scif_has_flag @ 20163654 (16 bytes)

/* RX event flag bound? */

byte scif_has_flag(scif_uart *uart)

{
  return uart->rx_flg != 0;
}


// ===== FUN_20163668 @ 20163668 (28 bytes)

void FUN_20163668(undefined2 *param_1)

{
  undefined2 *puVar1;
  
  if (((uint)param_1 & 1) == 0) {
    *(undefined1 *)(param_1 + 2) = 0;
    puVar1 = param_1;
  }
  else {
    puVar1 = (undefined2 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = 0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}


// ===== FUN_20163684 @ 20163684 (36 bytes)

void FUN_20163684(undefined2 *param_1)

{
  undefined2 *puVar1;
  
  if (((uint)param_1 & 1) == 0) {
    param_1[2] = 0;
    puVar1 = param_1;
  }
  else {
    *(undefined1 *)((int)param_1 + 5) = 0;
    puVar1 = (undefined2 *)((int)param_1 + 1);
    *(undefined1 *)param_1 = 0;
  }
  *puVar1 = 0;
  puVar1[1] = 0;
  return;
}


// ===== FUN_201636a8 @ 201636a8 (16 bytes)

void FUN_201636a8(undefined4 *param_1)

{
  *param_1 = 0;
  *(undefined1 *)(param_1 + 1) = 0;
  return;
}


// ===== FUN_201636b8 @ 201636b8 (20 bytes)

void FUN_201636b8(undefined4 *param_1)

{
  *param_1 = 0;
  param_1[1] = 0;
  *(undefined1 *)(param_1 + 2) = 0;
  return;
}


// ===== copy5 @ 201636cc (44 bytes)

/* Copies 5 bytes (encoder events, E1/E2 frames) [fact] */

void copy5(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  return;
}


// ===== FUN_201636f8 @ 201636f8 (52 bytes)

void FUN_201636f8(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  return;
}


// ===== FUN_2016372c @ 2016372c (68 bytes)

void FUN_2016372c(undefined1 *param_1,undefined1 *param_2)

{
  *param_1 = *param_2;
  param_1[1] = param_2[1];
  param_1[2] = param_2[2];
  param_1[3] = param_2[3];
  param_1[4] = param_2[4];
  param_1[5] = param_2[5];
  param_1[6] = param_2[6];
  param_1[7] = param_2[7];
  return;
}


// ===== FUN_20163770 @ 20163770 (28 bytes)

void FUN_20163770(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  *(undefined2 *)(param_1 + 2) = *(undefined2 *)(param_2 + 2);
  return;
}


// ===== FUN_2016378c @ 2016378c (20 bytes)

void FUN_2016378c(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  *(undefined1 *)(param_1 + 1) = *(undefined1 *)(param_2 + 1);
  return;
}


// ===== FUN_201637a0 @ 201637a0 (28 bytes)

void FUN_201637a0(undefined4 *param_1,undefined4 *param_2)

{
  *param_1 = *param_2;
  *(undefined2 *)(param_1 + 1) = *(undefined2 *)(param_2 + 1);
  *(undefined1 *)((int)param_1 + 6) = *(undefined1 *)((int)param_2 + 6);
  return;
}


// ===== FUN_201637bc @ 201637bc (28 bytes)

void FUN_201637bc(undefined4 *param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = param_2[1];
  *param_1 = *param_2;
  param_1[1] = uVar1;
  *(undefined1 *)(param_1 + 2) = *(undefined1 *)(param_2 + 2);
  return;
}


// ===== FUN_201637d8 @ 201637d8 (24 bytes)

void FUN_201637d8(ushort *param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = param_2 & 0xff | param_2 << 8;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  param_1[2] = uVar1;
  return;
}


// ===== FUN_201637f0 @ 201637f0 (24 bytes)

void FUN_201637f0(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = param_2 & 0xff | (param_2 & 0xff) << 8;
  uVar1 = uVar1 | uVar1 << 0x10;
  *param_1 = uVar1;
  param_1[1] = uVar1;
  return;
}


// ===== FUN_20163808 @ 20163808 (40 bytes)

uint FUN_20163808(int param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 0;
  if (param_1 != 0 || (param_2 & 0xfffff) != 0) {
    uVar1 = 4;
  }
  if ((param_2 & 0x7fffffff) >> 0x14 != 0) {
    uVar1 = uVar1 | 1;
  }
  if ((param_2 & 0x7fffffff) >> 0x14 == 0x7ff) {
    uVar1 = uVar1 | 2;
  }
  if (uVar1 == 1) {
    uVar1 = 5;
  }
  return uVar1;
}


// ===== FUN_2016385a @ 2016385a (10 bytes)

void FUN_2016385a(void)

{
  __cxa_pure_virtual(0);
  return;
}


// ===== FUN_20163864 @ 20163864 (14 bytes)

undefined4 FUN_20163864(int param_1)

{
  if (param_1 - 0x30U < 10) {
    return 1;
  }
  return 0;
}


// ===== FUN_20163874 @ 20163874 (34 bytes)

undefined4 FUN_20163874(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  
  if (((param_2 != (uint *)0x0) && ((char)*param_2 != '\0')) &&
     (uVar1 = strcmp((uint *)(BYTE_ARRAY_204286f8 + 4),param_2), uVar1 != 0)) {
    return 0;
  }
  return 0x20428704;
}


// ===== FUN_201638a0 @ 201638a0 (34 bytes)

undefined4 FUN_201638a0(undefined4 param_1,uint *param_2)

{
  uint uVar1;
  
  if (((param_2 != (uint *)0x0) && ((char)*param_2 != '\0')) &&
     (uVar1 = strcmp((uint *)(BYTE_ARRAY_204286f8 + 0x114),param_2), uVar1 != 0)) {
    return 0;
  }
  return 0x20428814;
}


// ===== FUN_201638cc @ 201638cc (12 bytes)

void FUN_201638cc(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_201638d8 @ 201638d8 (40 bytes)

void FUN_201638d8(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x4b0);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x968) = param_1;
  return;
}


// ===== FUN_20163900 @ 20163900 (56 bytes)

void FUN_20163900(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)((int)param_1 + iVar2 + 8) = *(undefined2 *)((int)param_2 + iVar1 + 8);
  } while (iVar3 < 0x4b0);
  *param_1 = *param_2;
  param_1[1] = param_1 + 2;
  param_1[0x25a] = param_1;
  return;
}


// ===== FUN_20163938 @ 20163938 (264 bytes)

void FUN_20163938(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  
  uVar9 = param_4;
  uVar8 = __aeabi_i2d(param_6);
  __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = __aeabi_d2iz();
  uVar6 = (uint)*param_5;
  *param_1 = *(undefined4 *)param_5;
  iVar3 = (param_5[1] - 1) * uVar6;
  iVar7 = *(int *)(param_5 + 2) + iVar3 * 2;
  iVar3 = iVar3 * 2 + 8;
  iVar4 = 0;
  if (0 < param_6) {
    do {
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar1) * 2 + iVar3) = 0;
    } while (iVar4 < param_6);
  }
  iVar4 = 0;
  if (0 < param_6) {
    do {
      uVar8 = __aeabi_i2d(iVar4);
      __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = __aeabi_d2iz();
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar5 * uVar6) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - iVar1) * 2);
    } while (iVar4 < param_6);
  }
  if (iVar2 < param_6) {
    do {
      iVar4 = iVar2 * uVar6;
      iVar2 = iVar2 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar4) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - (param_6 + -1) * uVar6) * 2);
    } while (iVar2 < param_6);
  }
  return;
}


// ===== FUN_20163a40 @ 20163a40 (160 bytes)

void FUN_20163a40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  
  iVar2 = 0;
  if (*param_5 != 0) {
    do {
      uVar3 = (uint)param_5[1];
      iVar1 = 0;
      if (uVar3 != 0) {
        do {
          if (*(short *)(*(int *)(param_5 + 2) + iVar2 * 2 + (uint)*param_5 * iVar1 * 2) != 0) {
            FUN_20163938(param_1,iVar1,param_3,param_4,param_5,uVar3 - iVar1,iVar2);
            break;
          }
          iVar1 = iVar1 + 1;
        } while (iVar1 < (int)uVar3);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < (int)(uint)*param_5);
  }
  return;
}


// ===== FUN_20163ae0 @ 20163ae0 (44 bytes)

void FUN_20163ae0(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x870);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x10e8) = param_1;
  return;
}


// ===== FUN_20163b0c @ 20163b0c (12 bytes)

void FUN_20163b0c(undefined2 *param_1,undefined2 param_2,undefined2 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
  return;
}


// ===== FUN_20163b18 @ 20163b18 (48 bytes)

void FUN_20163b18(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x15cc);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x2ba0) = param_1;
  return;
}


// ===== FUN_20163b48 @ 20163b48 (12 bytes)

undefined4 FUN_20163b48(int param_1)

{
  return *(undefined4 *)(param_1 + 0x2ba0);
}


// ===== FUN_20163b54 @ 20163b54 (72 bytes)

void FUN_20163b54(undefined4 *param_1,undefined4 *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = iVar3 * 2;
    iVar2 = iVar3 * 2;
    iVar3 = iVar3 + 1;
    *(undefined2 *)((int)param_1 + iVar2 + 8) = *(undefined2 *)((int)param_2 + iVar1 + 8);
  } while (iVar3 < 0x15cc);
  *param_1 = *param_2;
  param_1[1] = param_1 + 2;
  param_1[0xae8] = param_1;
  return;
}


// ===== FUN_20163b9c @ 20163b9c (264 bytes)

void FUN_20163b9c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 ushort *param_5,int param_6,int param_7)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int iVar7;
  undefined8 uVar8;
  undefined4 uVar9;
  
  uVar9 = param_4;
  uVar8 = __aeabi_i2d(param_6);
  __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = __aeabi_d2iz();
  uVar6 = (uint)*param_5;
  *param_1 = *(undefined4 *)param_5;
  iVar3 = (param_5[1] - 1) * uVar6;
  iVar7 = *(int *)(param_5 + 2) + iVar3 * 2;
  iVar3 = iVar3 * 2 + 8;
  iVar4 = 0;
  if (0 < param_6) {
    do {
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar1) * 2 + iVar3) = 0;
    } while (iVar4 < param_6);
  }
  iVar4 = 0;
  if (0 < param_6) {
    do {
      uVar8 = __aeabi_i2d(iVar4);
      __aeabi_dmul((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = __aeabi_d2iz();
      iVar1 = iVar4 * uVar6;
      iVar4 = iVar4 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar5 * uVar6) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - iVar1) * 2);
    } while (iVar4 < param_6);
  }
  if (iVar2 < param_6) {
    do {
      iVar4 = iVar2 * uVar6;
      iVar2 = iVar2 + 1;
      *(undefined2 *)((int)param_1 + (param_7 - iVar4) * 2 + iVar3) =
           *(undefined2 *)(iVar7 + (param_7 - (param_6 + -1) * uVar6) * 2);
    } while (iVar2 < param_6);
  }
  return;
}

