// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20162d48 @ 20162d48 (12 bytes)

void FUN_20162d48(int param_1,undefined1 param_2)

{
  *(undefined1 *)(param_1 + 0x2e04) = param_2;
  return;
}


// ===== scif_rxi_isr @ 20162dd8 (312 bytes)

/* 1 byte -> RX ring, set_flg(obj+0x818, 1) */

void scif_rxi_isr(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x81c) = *(int *)(param_1 + 0x81c) + 1;
  iVar1 = *(int *)(param_1 + 4);
  if ((*(ushort *)(iVar1 + 0x10) & 0xff9d) != 0) {
    *(int *)(param_1 + 0x828) = *(int *)(param_1 + 0x828) + 1;
  }
  if ((*(ushort *)(iVar1 + 0x10) & 2) != 0) {
    if (((*(ushort *)(param_1 + 10) < *(ushort *)(param_1 + 8)) ||
        (0x3fe < (int)((uint)*(ushort *)(param_1 + 10) - (uint)*(ushort *)(param_1 + 8)))) &&
       ((*(ushort *)(param_1 + 8) <= *(ushort *)(param_1 + 10) ||
        ((int)((uint)*(ushort *)(param_1 + 8) - (uint)*(ushort *)(param_1 + 10)) < 2)))) {
      *(ushort *)(iVar1 + 0x10) = *(ushort *)(iVar1 + 0x10) & 0xfffd;
      *(int *)(param_1 + 0x820) = *(int *)(param_1 + 0x820) + 1;
      *(int *)(param_1 + 0x824) = *(int *)(param_1 + 0x824) + 1;
      return;
    }
    *(undefined1 *)((uint)*(ushort *)(param_1 + 10) + param_1 + 0xc) = *(undefined1 *)(iVar1 + 0x14)
    ;
    DataMemoryBarrier(2);
    *(ushort *)(param_1 + 10) = *(short *)(param_1 + 10) + 1U & 0x3ff;
    *(ushort *)(*(int *)(param_1 + 4) + 0x10) = *(ushort *)(*(int *)(param_1 + 4) + 0x10) & 0xfffd;
    if (*(int *)(param_1 + 0x818) != 0) {
      gic_disable_irq(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
    }
    itron_set_flg(*(undefined4 *)(param_1 + 0x818),1);
    *(int *)(param_1 + 0x820) = *(int *)(param_1 + 0x820) + 1;
    FUN_20114850(param_1 + 0x840);
    return;
  }
  *(int *)(param_1 + 0x82c) = *(int *)(param_1 + 0x82c) + 1;
  return;
}


// ===== scif_txi_isr @ 20162f10 (156 bytes)

/* TX ring -> SCFTDR */

void scif_txi_isr(int param_1)

{
  int iVar1;
  
  *(int *)(param_1 + 0x830) = *(int *)(param_1 + 0x830) + 1;
  iVar1 = *(int *)(param_1 + 4);
  if ((*(ushort *)(iVar1 + 0x10) & 0x20) == 0) {
    *(int *)(param_1 + 0x838) = *(int *)(param_1 + 0x838) + 1;
    return;
  }
  if (*(short *)(param_1 + 0x40c) != *(short *)(param_1 + 0x40e)) {
    *(undefined1 *)(iVar1 + 0xc) =
         *(undefined1 *)((uint)*(ushort *)(param_1 + 0x40c) + param_1 + 0x410);
    DataMemoryBarrier(2);
    *(ushort *)(param_1 + 0x40c) = *(short *)(param_1 + 0x40c) + 1U & 0x3ff;
    *(ushort *)(*(int *)(param_1 + 4) + 0x10) = *(ushort *)(*(int *)(param_1 + 4) + 0x10) & 0xff9f;
    *(int *)(param_1 + 0x834) = *(int *)(param_1 + 0x834) + 1;
    FUN_20114850(param_1 + 0x848);
    return;
  }
  *(ushort *)(iVar1 + 8) = *(ushort *)(iVar1 + 8) & 0xff7f;
  return;
}


// ===== uart_obj_init @ 20162fac (104 bytes)

undefined4
uart_obj_init(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
             undefined4 param_5)

{
  int iVar1;
  
  if (*(int *)(param_1 + 4) == 0) {
    *(undefined4 *)(param_1 + 4) = param_2;
    *(undefined4 *)(param_1 + 0x818) = param_5;
    *(undefined4 *)(param_1 + 0x810) = param_3;
    *(undefined4 *)(param_1 + 0x814) = param_4;
    iVar1 = itron_acre_isr(0,param_4);
    if ((iVar1 < 1) || (iVar1 = itron_acre_isr(0,*(undefined4 *)(param_1 + 0x810)), iVar1 < 1)) {
      return 0xffffffff;
    }
  }
  else {
    *(undefined4 *)(param_1 + 0x818) = param_5;
  }
  return 0;
}


// ===== scif_irq_off @ 20163014 (36 bytes)

void scif_irq_off(int param_1)

{
  gic_disable_irq(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  gic_disable_irq(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  return;
}


// ===== scif_read @ 20163038 (96 bytes)

/* non-blocking read from the 1 KB RX ring */

int scif_read(int param_1,undefined1 *param_2,int param_3)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0;
  while ((bVar2 = param_3 != 0, param_3 = param_3 + -1, bVar2 &&
         (*(short *)(param_1 + 10) != *(short *)(param_1 + 8)))) {
    *param_2 = *(undefined1 *)((uint)*(ushort *)(param_1 + 8) + param_1 + 0xc);
    DataMemoryBarrier(2);
    *(ushort *)(param_1 + 8) = *(short *)(param_1 + 8) + 1U & 0x3ff;
    iVar1 = iVar1 + 1;
    param_2 = param_2 + 1;
  }
  gic_enable_irq(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  return iVar1;
}


// ===== scif_start @ 20163098 (52 bytes)

/* scif_open + enable RXI/TXI in the GIC */

void scif_start(int param_1)

{
  undefined4 extraout_r1;
  undefined4 extraout_r2;
  undefined4 in_stack_00000000;
  
  scif_open(param_1);
  gic_enable_irq(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  gic_enable_irq(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8),extraout_r1,extraout_r2,
                 in_stack_00000000);
  return;
}


// ===== scif_open @ 201630cc (324 bytes)

/* (baud, bits, parity, stop): SCSMR, SCBRR (0x16 + SEMR 0x81 for 345600), FIFO reset */

void scif_open(int param_1,uint param_2,int param_3,int param_4,uint param_5)

{
  char cVar1;
  ushort uVar2;
  
  uVar2 = 0;
  if (param_3 == 7) {
    uVar2 = 0x40;
  }
  if (param_4 != 0) {
    if (param_4 == 1) {
      uVar2 = uVar2 | 0x20;
    }
    else if (param_4 == 2) {
      uVar2 = uVar2 | 0x30;
    }
  }
  if (param_5 != 1) {
    uVar2 = uVar2 | 8;
  }
  if (param_2 < 0x54600) {
    cVar1 = FUN_20156260(64000000,param_2 << 5);
    cVar1 = cVar1 + -1;
  }
  else {
    cVar1 = '\x16';
  }
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 0x40e) = 0;
  *(undefined2 *)(param_1 + 0x40c) = 0;
  *(undefined4 *)(param_1 + 0x81c) = 0;
  *(undefined4 *)(param_1 + 0x820) = 0;
  *(undefined4 *)(param_1 + 0x828) = 0;
  *(undefined4 *)(param_1 + 0x82c) = 0;
  *(undefined4 *)(param_1 + 0x830) = 0;
  *(undefined4 *)(param_1 + 0x834) = 0;
  *(undefined4 *)(param_1 + 0x838) = 0;
  *(undefined2 *)(*(int *)(param_1 + 4) + 8) = 0;
  *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) | 6;
  *(ushort *)(*(int *)(param_1 + 4) + 0x10) = *(ushort *)(*(int *)(param_1 + 4) + 0x10) & 0xff6e;
  *(undefined2 *)(*(int *)(param_1 + 4) + 0x24) = 0;
  *(undefined2 *)(*(int *)(param_1 + 4) + 8) = 0;
  **(ushort **)(param_1 + 4) = uVar2;
  *(char *)(*(int *)(param_1 + 4) + 4) = cVar1;
  if (param_2 < 0x54600) {
    *(undefined2 *)(*(int *)(param_1 + 4) + 0x28) = 0;
  }
  else {
    *(ushort *)(*(int *)(param_1 + 4) + 0x28) = *(ushort *)(*(int *)(param_1 + 4) + 0x28) | 0x81;
  }
  if ((param_5 & 0x80) != 0) {
    *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) | 1;
  }
  *(ushort *)(*(int *)(param_1 + 4) + 0x18) = *(ushort *)(*(int *)(param_1 + 4) + 0x18) & 0xfff9;
  *(ushort *)(*(int *)(param_1 + 4) + 8) = *(ushort *)(*(int *)(param_1 + 4) + 8) | 0xf8;
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

undefined4 scif_flush(int param_1)

{
  gic_disable_irq(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  gic_disable_irq(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  *(undefined2 *)(param_1 + 10) = 0;
  *(undefined2 *)(param_1 + 8) = 0;
  *(undefined2 *)(param_1 + 0x40e) = 0;
  *(undefined2 *)(param_1 + 0x40c) = 0;
  gic_enable_irq(*(undefined4 *)(*(int *)(param_1 + 0x814) + 8));
  gic_enable_irq(*(undefined4 *)(*(int *)(param_1 + 0x810) + 8));
  return 0;
}


// ===== scif_write @ 201632d8 (136 bytes)

/* copy into the 1 KB TX ring, enable TIE */

uint scif_write(int param_1,undefined1 *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = (uint)*(ushort *)(param_1 + 0x40e);
  uVar3 = (uint)*(ushort *)(param_1 + 0x40c);
  if (uVar2 < uVar3) {
    uVar3 = (uVar3 - uVar2) - 1;
  }
  else {
    uVar3 = 0x3ff - (uVar2 - uVar3);
  }
  uVar1 = param_3;
  if (uVar3 < param_3) {
    param_3 = 0;
  }
  else {
    for (; uVar1 != 0; uVar1 = uVar1 - 1) {
      *(undefined1 *)(param_1 + uVar2 + 0x410) = *param_2;
      uVar2 = uVar2 + 1 & 0x3ff;
      param_2 = param_2 + 1;
    }
    *(short *)(param_1 + 0x40e) = (short)uVar2;
    DataMemoryBarrier(2);
    *(ushort *)(*(int *)(param_1 + 4) + 8) = *(ushort *)(*(int *)(param_1 + 4) + 8) | 0x80;
  }
  return param_3;
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
  int iVar1;
  
  iVar1 = param_1 + param_2 * 800 + 0xa323;
  param_1 = param_1 + param_2 * 0x100;
  if (param_3 == 8) {
    FUN_201633a0(param_1,param_4,iVar1,param_5,0);
    return DAT_20473b78;
  }
  if (param_3 == 9) {
    FUN_201633a0(param_1 + 0x1e00,param_4,iVar1,param_5,0);
    return DAT_20474c64;
  }
  iVar1 = 0;
  do {
    iVar1 = iVar1 + 1;
  } while (iVar1 < 800);
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
  undefined4 uStack_20;
  int iStack_1c;
  int iStack_8;
  int iStack_4;
  
  iStack_1c = param_1 + 0xe;
  iStack_8 = param_1 + 4;
  uStack_20 = param_2;
  iStack_4 = iStack_1c;
  FUN_20155f72(&UNK_20428286,&uStack_20,&iStack_8,0x20155f99);
  FUN_20155f98(0,&uStack_20);
  return;
}


// ===== fwname_pattern_match @ 20163600 (84 bytes)

/* prefix + 4 chars + ".sfl", case-insensitive, exact length */

undefined4 fwname_pattern_match(int *param_1,int param_2,int param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  if (((*param_1 == param_3) && (iVar1 = FUN_2014e250(param_1[1],param_2,param_1[3]), iVar1 == 0))
     && (iVar1 = FUN_2014e250(param_1[2],param_1[4] + param_2,param_1[5]), iVar1 == 0)) {
    uVar2 = 1;
  }
  else {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== scif_has_flag @ 20163654 (16 bytes)

/* RX event flag bound? */

bool scif_has_flag(int param_1)

{
  return *(int *)(param_1 + 0x818) != 0;
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


// ===== FUN_201636cc @ 201636cc (44 bytes)

void FUN_201636cc(undefined1 *param_1,undefined1 *param_2)

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


// ===== FUN_2016385c @ 2016385c (8 bytes)

void FUN_2016385c(void)

{
  FUN_20155fde();
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

undefined4 FUN_20163874(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) && (iVar1 = strcmp(0x204286fc), iVar1 != 0))
  {
    return 0;
  }
  return 0x20428704;
}


// ===== FUN_201638a0 @ 201638a0 (34 bytes)

undefined4 FUN_201638a0(undefined4 param_1,char *param_2)

{
  int iVar1;
  
  if (((param_2 != (char *)0x0) && (*param_2 != '\0')) && (iVar1 = strcmp(0x2042880c), iVar1 != 0))
  {
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
  uVar8 = FUN_20164d54(param_6);
  FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = FUN_20164c90();
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
      uVar8 = FUN_20164d54(iVar4);
      FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = FUN_20164c90();
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
  uVar8 = FUN_20164d54(param_6);
  FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = FUN_20164c90();
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
      uVar8 = FUN_20164d54(iVar4);
      FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = FUN_20164c90();
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


// ===== FUN_20163ca4 @ 20163ca4 (160 bytes)

void FUN_20163ca4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
            FUN_20163b9c(param_1,iVar1,param_3,param_4,param_5,uVar3 - iVar1,iVar2);
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


// ===== FUN_20163d44 @ 20163d44 (40 bytes)

void FUN_20163d44(int param_1,undefined2 param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 2;
    iVar2 = iVar2 + 1;
    *(undefined2 *)(param_1 + iVar1 + 8) = param_2;
  } while (iVar2 < 0x40);
  *(int *)(param_1 + 4) = param_1 + 8;
  *(int *)(param_1 + 0x88) = param_1;
  return;
}


// ===== FUN_20163d6c @ 20163d6c (264 bytes)

void FUN_20163d6c(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
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
  uVar8 = FUN_20164d54(param_6);
  FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4,uVar9);
  iVar2 = FUN_20164c90();
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
      uVar8 = FUN_20164d54(iVar4);
      FUN_20164da8((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),param_3,param_4);
      iVar5 = FUN_20164c90();
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

