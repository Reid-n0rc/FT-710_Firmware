// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== rtc_read_reg @ 20114268 (100 bytes)

/* cmd 0x86|reg: status 1/2, INT1/INT2 registers */

undefined4 rtc_read_reg(uint param_1)

{
  undefined4 uVar1;
  
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  rtc_delay(1);
  rtc_send_byte(param_1 | 0x86);
  uVar1 = rtc_recv_byte();
  rtc_delay(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  rtc_delay(1);
  return uVar1;
}


// ===== rtc_write_reg @ 201142cc (92 bytes)

/* cmd 0x06|reg + 1 data byte */

void rtc_write_reg(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  
  local_10._2_2_ = (undefined2)((uint)param_4 >> 0x10);
  local_10 = CONCAT22(local_10._2_2_,CONCAT11(param_2,param_1)) | 6;
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  rtc_delay(1);
  rtc_send_bytes(&local_10,2);
  rtc_delay(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  return;
}


// ===== rtc_port_idle @ 20114328 (24 bytes)

/* CK high, CS low */

void rtc_port_idle(void)

{
  DAT_fcfe3104 = 0x20002;
  DAT_fcfe3104 = 0x40000;
  return;
}


// ===== rtc_write_datetime_raw @ 20114340 (96 bytes)

/* cmd 0x26 + 7 BCD bytes */

void rtc_write_datetime_raw(undefined4 param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  rtc_delay(1);
  rtc_send_byte(0x26);
  rtc_send_bytes(param_1,7);
  rtc_delay(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  return;
}


// ===== rtc_write_time_raw @ 201143a0 (96 bytes)

/* cmd 0x66 + 3 BCD bytes */

void rtc_write_time_raw(int param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  rtc_delay(1);
  rtc_send_byte(0x66);
  rtc_send_bytes(param_1 + 4,3);
  rtc_delay(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  return;
}


// ===== rtc_read_datetime_raw @ 20114400 (108 bytes)

/* cmd 0xA6, 7 BCD bytes (hour bit 6 masked) */

void rtc_read_datetime_raw(int param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  rtc_delay(1);
  rtc_send_byte(0xa6);
  rtc_recv_bytes(param_1,7);
  rtc_delay(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
  return;
}


// ===== rtc_read_time_raw @ 2011446c (108 bytes)

/* cmd 0xE6 */

void rtc_read_time_raw(int param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  rtc_delay(1);
  rtc_send_byte(0xe6);
  rtc_recv_bytes(param_1 + 4,2);
  rtc_delay(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
  return;
}


// ===== rtc_minutes_of_day @ 201144d8 (80 bytes)

void rtc_minutes_of_day(short *param_1)

{
  undefined1 auStack_10 [4];
  byte local_c;
  byte local_b;
  
  rtc_read_time_raw(auStack_10);
  *param_1 = (local_b & 0xf) + (ushort)(local_b >> 4) * 2 + (ushort)(local_b >> 4) * 8 +
             ((local_c & 0xf) + (ushort)(local_c >> 4) * 10) * 0x3c;
  return;
}


// ===== rtc_get_date @ 20114528 (60 bytes)

/* (y, m, d) BCD */

void rtc_get_date(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  rtc_read_datetime_raw(&local_18);
  *param_1 = local_18;
  *param_2 = local_17;
  *param_3 = local_16;
  return;
}


// ===== rtc_set_date @ 20114564 (56 bytes)

void rtc_set_date(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  rtc_read_time_raw(&local_18);
  local_18 = param_1;
  local_17 = param_2;
  local_16 = param_3;
  rtc_write_datetime_raw(&local_18);
  return;
}


// ===== rtc_get_time @ 2011459c (60 bytes)

/* (h, m, s) BCD */

void rtc_get_time(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined1 auStack_18 [4];
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  rtc_read_datetime_raw(auStack_18);
  *param_1 = local_14;
  *param_2 = local_13;
  *param_3 = local_12;
  return;
}


// ===== rtc_set_time @ 201145d8 (48 bytes)

void rtc_set_time(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = (uint)CONCAT12(param_3,CONCAT11(param_2,param_1));
  local_10 = 0;
  rtc_write_time_raw(&local_10);
  return;
}


// ===== rtc_set_datetime @ 20114608 (80 bytes)

void rtc_set_datetime(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                     undefined1 param_5)

{
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  rtc_read_time_raw(&local_20);
  local_1b = param_5;
  local_1a = 0;
  local_20 = param_1;
  local_1f = param_2;
  local_1e = param_3;
  local_1c = param_4;
  rtc_write_datetime_raw(&local_20);
  return;
}


// ===== rtc_get_datetime @ 20114658 (92 bytes)

void rtc_get_datetime(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,
                     undefined1 *param_4,undefined1 *param_5,undefined1 *param_6)

{
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  rtc_read_datetime_raw(&local_28);
  *param_1 = local_28;
  *param_2 = local_27;
  *param_3 = local_26;
  *param_4 = local_24;
  *param_5 = local_23;
  *param_6 = local_22;
  return;
}


// ===== rtc_get_tm @ 201146b4 (196 bytes)

/* struct tm (year+100, mon-1); used by the FAT layer for time stamps */

void rtc_get_tm(int *param_1)

{
  byte local_10;
  byte local_f;
  byte local_e;
  byte local_c;
  byte local_b;
  byte local_a;
  
  rtc_read_datetime_raw(&local_10);
  *param_1 = (local_a & 0xf) + (uint)(local_a >> 4) * 10;
  param_1[1] = (local_b & 0xf) + (uint)(local_b >> 4) * 10;
  param_1[2] = (local_c & 0xf) + (uint)(local_c >> 4) * 10;
  param_1[3] = (local_e & 0xf) + (uint)(local_e >> 4) * 10;
  param_1[4] = (local_f & 0xf) + (uint)(local_f >> 4) * 10 + -1;
  param_1[5] = (local_10 & 0xf) + (uint)(local_10 >> 4) * 10 + 100;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


// ===== rtc_read_status @ 20114778 (60 bytes)

/* status1, status2, INT1, INT2 */

void rtc_read_status(undefined1 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = rtc_read_reg(0);
  *param_1 = uVar1;
  uVar1 = rtc_read_reg(0x40);
  param_1[1] = uVar1;
  uVar1 = rtc_read_reg(0x10);
  param_1[2] = uVar1;
  uVar1 = rtc_read_reg(0x50);
  param_1[3] = uVar1;
  return;
}


// ===== rtc_int_setup @ 201147b4 (32 bytes)

/* writes status2 = 1 and INT1 = 1 (from MAIN message 0x62) */

void rtc_int_setup(void)

{
  rtc_write_reg(0x40,1);
  rtc_write_reg(0x10,1);
  return;
}


// ===== rtc_init @ 201147d4 (88 bytes)

/* port idle, status1 = 2 (24 h), status2 = 0, creates the RTC mutex 0x20800368 */

void rtc_init(void)

{
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  rtc_port_idle();
  rtc_write_reg(0,2);
  rtc_write_reg(0x40,0);
  local_10 = 2;
  uStack_c = 0;
  local_8 = 0;
  DAT_20800368 = FUN_2014fd24(0,&local_10);
  return;
}


// ===== FUN_20114850 @ 20114850 (48 bytes)

int FUN_20114850(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== scif3_rxi_isr @ 20114884 (8 bytes)

void scif3_rxi_isr(void)

{
  iRam208da9fc = iRam208da9fc + 1;
  if ((*(ushort *)(iRam208da1e4 + 0x10) & 0xff9d) != 0) {
    iRam208daa08 = iRam208daa08 + 1;
  }
  if ((*(ushort *)(iRam208da1e4 + 0x10) & 2) != 0) {
    if (((uRam208da1ea < uRam208da1e8) || (0x3fe < (int)((uint)uRam208da1ea - (uint)uRam208da1e8)))
       && ((uRam208da1e8 <= uRam208da1ea || ((int)((uint)uRam208da1e8 - (uint)uRam208da1ea) < 2))))
    {
      *(ushort *)(iRam208da1e4 + 0x10) = *(ushort *)(iRam208da1e4 + 0x10) & 0xfffd;
      iRam208daa00 = iRam208daa00 + 1;
      iRam208daa04 = iRam208daa04 + 1;
      return;
    }
    *(undefined1 *)(uRam208da1ea + 0x208da1ec) = *(undefined1 *)(iRam208da1e4 + 0x14);
    DataMemoryBarrier(2);
    uRam208da1ea = uRam208da1ea + 1 & 0x3ff;
    *(ushort *)(iRam208da1e4 + 0x10) = *(ushort *)(iRam208da1e4 + 0x10) & 0xfffd;
    if (iRam208da9f8 != 0) {
      gic_disable_irq(*(undefined4 *)(iRam208da9f0 + 8));
    }
    itron_set_flg(iRam208da9f8,1);
    iRam208daa00 = iRam208daa00 + 1;
    FUN_20114850(0x208daa20);
    return;
  }
  iRam208daa0c = iRam208daa0c + 1;
  return;
}


// ===== scif3_txi_isr @ 2011488c (8 bytes)

void scif3_txi_isr(void)

{
  iRam208daa10 = iRam208daa10 + 1;
  if ((*(ushort *)(iRam208da1e4 + 0x10) & 0x20) == 0) {
    iRam208daa18 = iRam208daa18 + 1;
    return;
  }
  if (uRam208da5ec != uRam208da5ee) {
    *(undefined1 *)(iRam208da1e4 + 0xc) = *(undefined1 *)(uRam208da5ec + 0x208da5f0);
    DataMemoryBarrier(2);
    uRam208da5ec = uRam208da5ec + 1 & 0x3ff;
    *(ushort *)(iRam208da1e4 + 0x10) = *(ushort *)(iRam208da1e4 + 0x10) & 0xff9f;
    iRam208daa14 = iRam208daa14 + 1;
    FUN_20114850(0x208daa28);
    return;
  }
  *(ushort *)(iRam208da1e4 + 8) = *(ushort *)(iRam208da1e4 + 8) & 0xff7f;
  return;
}


// ===== scif4_rxi_isr @ 20114894 (8 bytes)

void scif4_rxi_isr(void)

{
  DAT_208db24c = DAT_208db24c + 1;
  if ((*(ushort *)(iRam208daa34 + 0x10) & 0xff9d) != 0) {
    iRam208db258 = iRam208db258 + 1;
  }
  if ((*(ushort *)(iRam208daa34 + 0x10) & 2) != 0) {
    if (((uRam208daa3a < uRam208daa38) || (0x3fe < (int)((uint)uRam208daa3a - (uint)uRam208daa38)))
       && ((uRam208daa38 <= uRam208daa3a || ((int)((uint)uRam208daa38 - (uint)uRam208daa3a) < 2))))
    {
      *(ushort *)(iRam208daa34 + 0x10) = *(ushort *)(iRam208daa34 + 0x10) & 0xfffd;
      iRam208db250 = iRam208db250 + 1;
      iRam208db254 = iRam208db254 + 1;
      return;
    }
    *(undefined1 *)(uRam208daa3a + 0x208daa3c) = *(undefined1 *)(iRam208daa34 + 0x14);
    DataMemoryBarrier(2);
    uRam208daa3a = uRam208daa3a + 1 & 0x3ff;
    *(ushort *)(iRam208daa34 + 0x10) = *(ushort *)(iRam208daa34 + 0x10) & 0xfffd;
    if (iRam208db248 != 0) {
      gic_disable_irq(*(undefined4 *)(iRam208db240 + 8));
    }
    itron_set_flg(iRam208db248,1);
    iRam208db250 = iRam208db250 + 1;
    FUN_20114850(0x208db270);
    return;
  }
  iRam208db25c = iRam208db25c + 1;
  return;
}


// ===== scif4_txi_isr @ 2011489c (8 bytes)

void scif4_txi_isr(void)

{
  iRam208db260 = iRam208db260 + 1;
  if ((*(ushort *)(iRam208daa34 + 0x10) & 0x20) == 0) {
    iRam208db268 = iRam208db268 + 1;
    return;
  }
  if (uRam208dae3c != uRam208dae3e) {
    *(undefined1 *)(iRam208daa34 + 0xc) = *(undefined1 *)(uRam208dae3c + 0x208dae40);
    DataMemoryBarrier(2);
    uRam208dae3c = uRam208dae3c + 1 & 0x3ff;
    *(ushort *)(iRam208daa34 + 0x10) = *(ushort *)(iRam208daa34 + 0x10) & 0xff9f;
    iRam208db264 = iRam208db264 + 1;
    FUN_20114850(0x208db278);
    return;
  }
  *(ushort *)(iRam208daa34 + 8) = *(ushort *)(iRam208daa34 + 8) & 0xff7f;
  return;
}


// ===== scif5_rxi_isr @ 201148a4 (8 bytes)

void scif5_rxi_isr(void)

{
  DAT_208dba9c = DAT_208dba9c + 1;
  if ((*(ushort *)(iRam208db284 + 0x10) & 0xff9d) != 0) {
    iRam208dbaa8 = iRam208dbaa8 + 1;
  }
  if ((*(ushort *)(iRam208db284 + 0x10) & 2) != 0) {
    if (((uRam208db28a < uRam208db288) || (0x3fe < (int)((uint)uRam208db28a - (uint)uRam208db288)))
       && ((uRam208db288 <= uRam208db28a || ((int)((uint)uRam208db288 - (uint)uRam208db28a) < 2))))
    {
      *(ushort *)(iRam208db284 + 0x10) = *(ushort *)(iRam208db284 + 0x10) & 0xfffd;
      iRam208dbaa0 = iRam208dbaa0 + 1;
      iRam208dbaa4 = iRam208dbaa4 + 1;
      return;
    }
    *(undefined1 *)(uRam208db28a + 0x208db28c) = *(undefined1 *)(iRam208db284 + 0x14);
    DataMemoryBarrier(2);
    uRam208db28a = uRam208db28a + 1 & 0x3ff;
    *(ushort *)(iRam208db284 + 0x10) = *(ushort *)(iRam208db284 + 0x10) & 0xfffd;
    if (iRam208dba98 != 0) {
      gic_disable_irq(*(undefined4 *)(iRam208dba90 + 8));
    }
    itron_set_flg(iRam208dba98,1);
    iRam208dbaa0 = iRam208dbaa0 + 1;
    FUN_20114850(0x208dbac0);
    return;
  }
  iRam208dbaac = iRam208dbaac + 1;
  return;
}


// ===== scif5_txi_isr @ 201148ac (8 bytes)

void scif5_txi_isr(void)

{
  iRam208dbab0 = iRam208dbab0 + 1;
  if ((*(ushort *)(iRam208db284 + 0x10) & 0x20) == 0) {
    iRam208dbab8 = iRam208dbab8 + 1;
    return;
  }
  if (uRam208db68c != uRam208db68e) {
    *(undefined1 *)(iRam208db284 + 0xc) = *(undefined1 *)(uRam208db68c + 0x208db690);
    DataMemoryBarrier(2);
    uRam208db68c = uRam208db68c + 1 & 0x3ff;
    *(ushort *)(iRam208db284 + 0x10) = *(ushort *)(iRam208db284 + 0x10) & 0xff9f;
    iRam208dbab4 = iRam208dbab4 + 1;
    FUN_20114850(0x208dbac8);
    return;
  }
  *(ushort *)(iRam208db284 + 8) = *(ushort *)(iRam208db284 + 8) & 0xff7f;
  return;
}


// ===== scif5_get @ 201148b4 (36 bytes)

/* UART object @0x208DB280 on SCIF5 (0xE8009800), MAIN link */

undefined * scif5_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208db280,&DAT_e8009800,&DAT_201657c8,&DAT_201657b4,param_1);
  return &DAT_208db280;
}


// ===== scif4_get @ 201148d8 (36 bytes)

/* UART object on SCIF4 (0xE8009000) */

undefined * scif4_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208daa30,&DAT_e8009000,&DAT_201657a0,&DAT_2016578c,param_1);
  return &DAT_208daa30;
}


// ===== scif3_get @ 201148fc (36 bytes)

/* UART object on SCIF3 (0xE8008800) */

undefined * scif3_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208da1e0,&DAT_e8008800,&DAT_20165778,&DAT_20165764,param_1);
  return &DAT_208da1e0;
}


// ===== FUN_20114920 @ 20114920 (12 bytes)

undefined4 FUN_20114920(void)

{
  return DAT_208dba9c;
}


// ===== FUN_2011492c @ 2011492c (12 bytes)

undefined4 FUN_2011492c(void)

{
  return DAT_208db24c;
}


// ===== FUN_2011493c @ 2011493c (28 bytes)

void FUN_2011493c(void)

{
  FUN_20163360();
  FUN_20163360(&DAT_208daa30);
  FUN_20163360(&DAT_208db280);
  return;
}


// ===== sfl_decode @ 2011497c (100 bytes)

/* byte-wise key subtraction, see docs/sfl-format.md */

uint sfl_decode(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + iVar2) = *(char *)(param_2 + iVar2) - BYTE_ARRAY_204286f8[uVar1 + 0x148];
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return param_1 % 0x2b;
}


// ===== sfl_encode @ 201149e0 (100 bytes)

/* inverse of sfl_decode (adds the 43-byte key) */

uint sfl_encode(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + iVar2) = *(char *)(param_2 + iVar2) + BYTE_ARRAY_204286f8[uVar1 + 0x148];
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return param_1 % 0x2b;
}


// ===== sfl_stream_init @ 20114a44 (32 bytes)

void sfl_stream_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = param_4;
  param_1[4] = 0;
  param_1[1] = param_3;
  *(undefined1 *)(param_1 + 5) = 0;
  return;
}


// ===== sfl_crc @ 20114a64 (112 bytes)

/* salted CRC-32 over the file */

uint sfl_crc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_110 [256];
  undefined4 local_10;
  
  uVar3 = 0xffffffff;
  local_10 = 0x139eeca6;
  crc32_make_table();
  while (iVar1 = fs_fread(auStack_110,1,0x100,param_1), iVar1 != 0) {
    uVar3 = crc32_update(uVar3,iVar1,auStack_110);
  }
  uVar2 = crc32_update(uVar3,4,&local_10);
  return ~uVar2;
}


// ===== sfl_stream_getc @ 20114ae0 (92 bytes)

/* one decoded byte */

uint sfl_stream_getc(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint local_c;
  
  if (0 < *(int *)(param_1 + 0x10)) {
    if (*(int *)(param_1 + 8) < *(int *)(param_1 + 0x10)) {
      local_c = CONCAT31((int3)((uint)param_4 >> 8),
                         *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)));
      uVar1 = sfl_decode(*(undefined1 *)(param_1 + 0x14),&local_c,1);
      *(undefined1 *)(param_1 + 0x14) = uVar1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      local_c = local_c & 0xff;
    }
    else {
      local_c = 0xffffffff;
    }
    return local_c;
  }
  return 0xffffffff;
}


// ===== sfl_stream_gets @ 20114b3c (192 bytes)

/* line read with decode */

int sfl_stream_gets(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3[3] == 0) {
    iVar2 = FUN_20142390(param_1,param_2,*param_3);
    return iVar2;
  }
  if (0 < param_2) {
    iVar2 = 0;
    if (0 < param_2 + -1) {
      do {
        iVar1 = sfl_stream_getc(param_3);
        if (iVar1 == -1) {
          iVar1 = fs_fread(param_3[1],1,param_3[3],*param_3);
          if (iVar1 == 0) break;
          param_3[4] = iVar1;
          param_3[2] = 0;
        }
        else {
          *(char *)(param_1 + iVar2) = (char)iVar1;
          iVar2 = iVar2 + 1;
          if (iVar1 == 10) break;
        }
      } while (iVar2 < param_2 + -1);
    }
    *(undefined1 *)(param_1 + iVar2) = 0;
    if ((iVar2 != 0) || (param_2 < 2)) {
      return param_1;
    }
  }
  return 0;
}


// ===== sfl_stream_read @ 20114bfc (72 bytes)

/* fread + decode */

int sfl_stream_read(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = fs_fread();
  if ((iVar2 != 0) && (*(int *)(param_4 + 0xc) != 0)) {
    uVar1 = sfl_decode(*(undefined1 *)(param_4 + 0x14),param_1,iVar2);
    *(undefined1 *)(param_4 + 0x14) = uVar1;
  }
  return iVar2;
}


// ===== FUN_20114c44 @ 20114c44 (92 bytes)

void FUN_20114c44(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  
  if (param_4[3] != 0) {
    uVar1 = sfl_encode(*(undefined1 *)(param_4 + 5),param_1,param_2 * param_3);
    *(undefined1 *)(param_4 + 5) = uVar1;
    fs_fwrite(param_1,param_2,param_3,*param_4);
    return;
  }
  fs_fwrite(param_1,param_2,param_3,*param_4);
  return;
}


// ===== sfl_read_header @ 20114ca0 (336 bytes)

/* reads the 0x40-byte header block */

undefined4 sfl_read_header(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_118 [64];
  undefined1 local_d8;
  undefined1 *local_18;
  int local_14;
  
  local_18 = auStack_118;
  iVar3 = 0;
  do {
    iVar1 = fs_fread(auStack_118,1,0x40,param_1);
    if (iVar1 == 0) {
      return 1;
    }
    if ((param_2 != 0) && (iVar3 == 3)) {
      memcpy(param_2,auStack_118,0x40);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  local_d8 = 0;
  iVar3 = FUN_20155122(auStack_118);
  if (iVar3 == 0x40) {
    iVar3 = sfl_crc(param_1);
    fs_fseek(param_1,0);
    iVar1 = 0;
    do {
      iVar2 = fs_fread(auStack_118,1,0x40,param_1);
      if (iVar2 == 0) {
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    iVar1 = FUN_20142390(auStack_118,0x100,param_1);
    if ((((iVar1 != 0) && (iVar1 = FUN_2014e320(local_18,&DAT_20114df0,&local_18), iVar1 != 0)) &&
        (iVar1 = FUN_2014e320(local_18,&DAT_20114df0,&local_18), iVar1 != 0)) &&
       (((iVar1 = FUN_2014e320(local_18,&DAT_20114df0,&local_18), iVar1 != 0 &&
         (iVar2 = hex_parse(iVar1,8,&local_14), local_14 != iVar1)) && (iVar2 == iVar3)))) {
      return 0;
    }
  }
  return 1;
}


// ===== system_reboot @ 20114df4 (148 bytes)

/* FS off, LCD/LVDS off, MAIN reset pulse, flash reset, wdt_system_reset */

void system_reboot(void)

{
  FUN_2014e884(0,1);
  gpio_p2_4_5_clear();
  backlight_enable(0);
  lvds_pins_enable(0);
  gpio_rx_update_off(1);
  itron_dly_tsk(5);
  itron_dly_tsk(0x96);
  gpio_rx_update_off(0);
  gpio_p7_9_11(1);
  itron_dly_tsk(4);
  gpio_rx_update(0);
  gpio_rx_reset(1);
  itron_dly_tsk(1);
  gpio_p8_5(1);
  gpio_rx_reset(0);
  itron_dly_tsk(0xe);
  gpio_qf_reset(1);
  wdt_system_reset();
  return;
}


// ===== uart4_send @ 20114e88 (84 bytes)

/* used by task_keycode, FUN_20130c90, FUN_20131638 */

void uart4_send(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = uart4_tx_alloc(DAT_20450020 + 0x938);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(short *)(iVar1 + 6) = (short)param_2;
  memcpy(iVar1 + 8,param_1,param_2);
  uart4_tx_post(DAT_20450020 + 0x938,iVar1);
  return;
}


// ===== uart4_wait_ready @ 20114edc (112 bytes)

/* waits for 0x2045001C; no caller */

undefined4 uart4_wait_ready(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 100;
  while( true ) {
    if (DAT_2045001c != '\0') {
      return 1;
    }
    if ((param_1 != 0) && (iVar1 = iVar1 + -1, iVar1 == 0)) break;
    itron_dly_tsk(1);
    if (((byte)DAT_20808a84 & 1) != 0) {
      return 1;
    }
  }
  DAT_2045001d = 1;
  return 0;
}


// ===== uart4_link_init @ 20114f4c (120 bytes)

/* creates the SCIF4 object 0x2045D4E0 and task "uart4"; no caller */

void uart4_link_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  memclr(&DAT_2045d4e0,0x1ae0);
  DAT_20450020 = uart4_obj_ctor(&DAT_2045d4e0);
  iVar1 = itron_acre_tsk(0,&DAT_201657dc);
  if ((0 < iVar1) && (iVar2 = itron_acre_flg(0,&DAT_201657f8), 0 < iVar2)) {
    *(int *)(DAT_20450020 + 0x14) = iVar2;
    uVar3 = scif4_get();
    *(undefined4 *)(DAT_20450020 + 0x10) = uVar3;
    itron_sta_tsk(iVar1);
    return;
  }
  return;
}


// ===== mainlink_get_last_frame @ 20115000 (12 bytes)

/* copy of the newest MAIN frame (0x2045F8C0, 0x240 B) */

void mainlink_get_last_frame(undefined4 param_1)

{
  memcpy(param_1,&DAT_2045f8c0,0x240);
  return;
}


// ===== mainlink_get_frame60 @ 2011500c (12 bytes)

/* copy of the newest 0x60 frame (0x2045FB00) */

void mainlink_get_frame60(undefined4 param_1)

{
  memcpy(param_1,&DAT_2045fb00,0x240);
  return;
}


// ===== mainlink_got_frame60 @ 20115018 (12 bytes)

/* flag 0x20450026 */

undefined1 mainlink_got_frame60(void)

{
  return DAT_20450026;
}


// ===== mainlink_get_settings24 @ 20115024 (24 bytes)

/* copies the 0x24 frame tail (0x2045006D) and returns flag 0x20450024 */

undefined1 mainlink_get_settings24(undefined4 param_1)

{
  FUN_201636f8(param_1,&DAT_2045006d);
  return DAT_20450024;
}


// ===== mainlink_got_esc @ 20115060 (12 bytes)

/* flag 0x2045005C, set by a 0x1B frame */

undefined4 mainlink_got_esc(void)

{
  return DAT_2045005c;
}


// ===== mainlink_last_frame_differs @ 2011506c (32 bytes)

bool mainlink_last_frame_differs(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_2015507c(&DAT_2045f8c0,param_1,0x240);
  return iVar1 != 0;
}

