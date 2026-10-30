// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== key_task_resume @ 20113d10 (16 bytes)

/* clears 0x20800217 */

void key_task_resume(void)

{
  DAT_20800217 = 0;
  return;
}


// ===== dimmer_pwm_init @ 20113d20 (76 bytes)

/* MTU2 ch0 PWM mode 1, P0/16, period 20000 (100 Hz), TIOC0A out */

void dimmer_pwm_init(void)

{
  byte bVar1;
  
  MTU2_TCR_0 = 0x22;
  MTU2_TCNT_0 = 0;
  MTU2_TGRA_0 = 19999;
  MTU2_TGRB_0 = 0;
  MTU2_TGRC_0 = 0;
  MTU2_TGRD_0 = 0;
  MTU2_TIORH_0 = 0x12;
  MTU2_TMDR_0 = 2;
  bVar1 = MTU2_TSTR;
  MTU2_TSTR = bVar1 | 1;
  return;
}


// ===== dimmer_set_pct @ 20113d6c (76 bytes)

/* NEW ENTRY; duty = pct*20000/100 -> TGRB_0 */

void dimmer_set_pct(int param_1)

{
  uint uVar1;
  int iVar2;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  uVar1 = div10_round(param_1 * 20000,param_1 * 20000 >> 0x1f);
  iVar2 = div10_round(uVar1,(int)uVar1 >> 0x1f);
  if (iVar2 == 20000) {
    iVar2 = 19999;
  }
  MTU2_TGRB_0 = (short)iVar2 + -1;
  return;
}


// ===== dimmer_set @ 20113db8 (8 bytes)

/* thunk: dimmer_set_pct */

void dimmer_set(uint param_1)

{
  dimmer_set_pct(param_1,1);
  return;
}


// ===== dimmer_init @ 20113dc0 (24 bytes)

/* dimmer_pwm_init + 60 % */

void dimmer_init(void)

{
  dimmer_pwm_init();
  dimmer_set_pct(0x3c,1);
  return;
}


// ===== FUN_20113de0 @ 20113de0 (24 bytes)

void FUN_20113de0(int param_1,undefined1 param_2)

{
  (&DAT_208d9c00)[param_1 * 5] = (char)param_1;
  (&DAT_208d9c01)[param_1 * 5] = param_2;
  return;
}


// ===== mouse_cursor_init @ 20113df8 (80 bytes)

void mouse_cursor_init(void)

{
  uint uVar1;
  
  __aeabi_memclr4(&DAT_208d9c40,0x5a0);
  DAT_20800330 = FUN_2015f040(&DAT_208d9c40);
  uVar1 = itron_acre_tsk(0,(byte *)&ctsk_mouse_cursor_56e4);
  if (0 < (int)uVar1) {
    itron_sta_tsk(uVar1,DAT_20800330);
    return;
  }
  return;
}


// ===== FUN_20113e48 @ 20113e48 (4 bytes)

void FUN_20113e48(void)

{
  return;
}


// ===== mouse_attach_post @ 20113e4c (84 bytes)

/* message type 1 to the mouse_cursor task */

void mouse_attach_post(void)

{
  int iVar1;
  
  iVar1 = FUN_2015fa40(DAT_20800330 + 4);
  *(undefined1 *)(iVar1 + 4) = 1;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  FUN_2015ff64(DAT_20800330 + 4,iVar1);
  return;
}


// ===== mouse_detach_post @ 20113ea0 (80 bytes)

/* message type 0 */

void mouse_detach_post(void)

{
  int iVar1;
  
  iVar1 = FUN_2015fa40(DAT_20800330 + 4);
  *(undefined1 *)(iVar1 + 4) = 0;
  *(undefined4 *)(iVar1 + 8) = 0;
  *(undefined4 *)(iVar1 + 0xc) = 0;
  *(undefined4 *)(iVar1 + 0x10) = 0;
  *(undefined4 *)(iVar1 + 0x14) = 0;
  *(undefined4 *)(iVar1 + 0x18) = 0;
  *(undefined4 *)(iVar1 + 0x1c) = 0;
  *(undefined4 *)(iVar1 + 0x20) = 0;
  *(undefined4 *)(iVar1 + 0x24) = 0;
  FUN_2015ff64(DAT_20800330 + 4,iVar1);
  return;
}


// ===== mouse_report_post @ 20113ef0 (72 bytes)

/* message type 2 (32-byte report) */

void mouse_report_post(void *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_2015fa40(DAT_20800330 + 4);
  *(undefined1 *)(iVar1 + 4) = 2;
  uVar2 = *(undefined4 *)((int)param_1 + 4);
  uVar3 = *(undefined4 *)((int)param_1 + 8);
  uVar4 = *(undefined4 *)((int)param_1 + 0xc);
  *(undefined4 *)(iVar1 + 8) = *(undefined4 *)param_1;
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  *(undefined4 *)(iVar1 + 0x10) = uVar3;
  *(undefined4 *)(iVar1 + 0x14) = uVar4;
  uVar2 = *(undefined4 *)((int)param_1 + 0x14);
  uVar3 = *(undefined4 *)((int)param_1 + 0x18);
  uVar4 = *(undefined4 *)((int)param_1 + 0x1c);
  *(undefined4 *)(iVar1 + 0x18) = *(undefined4 *)((int)param_1 + 0x10);
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  *(undefined4 *)(iVar1 + 0x20) = uVar3;
  *(undefined4 *)(iVar1 + 0x24) = uVar4;
  FUN_2015ff64(DAT_20800330 + 4,iVar1);
  return;
}


// ===== mouse_cursor_set_pos @ 20113f38 (24 bytes)

void mouse_cursor_set_pos(uint param_1,uint param_2)

{
  mouse_cursor_move(DAT_20800330 + 4,(ushort)param_1,(ushort)param_2);
  return;
}


// ===== mouse_cursor_visible @ 20113f50 (24 bytes)

byte mouse_cursor_visible(void)

{
  return *(byte *)(DAT_20800330 + 0x594);
}


// ===== mouse_cursor_get_pos @ 20113f60 (84 bytes)

void mouse_cursor_get_pos(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = DAT_20800330;
  itron_twai_sem(*(undefined4 *)(DAT_20800330 + 0x59c),0xffffffff);
  *(undefined2 *)param_1 = *(undefined2 *)(iVar1 + 0x596);
  *(undefined2 *)param_2 = *(undefined2 *)(iVar1 + 0x598);
  itron_sig_sem(*(undefined4 *)(iVar1 + 0x59c));
  return;
}


// ===== task_powon @ 20113f88 (84 bytes)

/* waits for the P2_0 edge flag, passes the level to 0x201131A8 */

void task_powon(void)

{
  ushort uVar1;
  void *pvVar2;
  uint uStack_4;
  
  do {
    do {
      do {
        pvVar2 = itron_twai_flg(DAT_20800358,1,5,&uStack_4,-1);
      } while (pvVar2 != (void *)0x0);
    } while (uStack_4 != 1);
    uVar1 = PORT_PPR2;
    key_set_power_level(uVar1 & 1);
    gic_enable_irq(0x25);
  } while( true );
}


// ===== powon_isr @ 20113fdc (76 bytes)

/* GIC 0x25 (IRQ5): sets the powon event flag */

void powon_isr(void)

{
  ushort uVar1;
  
  gic_disable_irq(0x25);
  itron_set_flg(DAT_20800358,1);
  itron_iwup_tsk(DAT_2080035c);
  uVar1 = INTC_IRQRR;
  if ((uVar1 & 0x20) != 0) {
    uVar1 = INTC_IRQRR;
    INTC_IRQRR = uVar1 & 0xffdf;
  }
  return;
}


// ===== powon_init @ 20114028 (144 bytes)

/* IRQ 0x25 (P2_0 edge) + event flag + task "powon" */

void powon_init(void)

{
  ushort uVar1;
  uint uVar2;
  
  uVar1 = INTC_ICR1;
  INTC_ICR1 = uVar1 & 0xf3ff;
  uVar1 = INTC_ICR1;
  INTC_ICR1 = uVar1 | 0xc00;
  DAT_20800358 = itron_acre_flg(0,(byte *)&cflg_powon);
  if (0 < (int)DAT_20800358) {
    DAT_2080035c = itron_acre_tsk(0,(byte *)&ctsk_powon);
    if (((0 < (int)DAT_2080035c) && (uVar2 = itron_sta_tsk(DAT_2080035c,0), uVar2 == 0)) &&
       (uVar2 = itron_acre_isr(0,0x20165744), 0 < (int)uVar2)) {
      gic_enable_irq(0x25);
      return;
    }
  }
  return;
}


// ===== progress_set @ 201140d0 (12 bytes)

/* progress percent 0x20800364 */

void progress_set(uint param_1)

{
  DAT_20800364 = param_1;
  return;
}


// ===== progress_get @ 201140dc (12 bytes)

/* progress percent */

uint progress_get(void)

{
  return DAT_20800364;
}


// ===== progress_range_init @ 201140e8 (12 bytes)

/* {from, to} range */

void progress_range_init(void *param_1,uint param_2,uint param_3)

{
  *(uint *)param_1 = param_2;
  *(uint *)((int)param_1 + 4) = param_3;
  return;
}


// ===== progress_scale @ 201140f4 (84 bytes)

/* maps a fraction into the range */

uint progress_scale(int *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined2 *unaff_r4;
  int iVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  undefined8 uVar7;
  undefined8 uVar8;
  
  iVar3 = *param_1;
  uVar7 = __aeabi_i2d(param_1[1] - iVar3);
  uVar7 = __aeabi_dmul((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),param_3,param_4);
  uVar8 = __aeabi_i2d(iVar3);
  uVar7 = __aeabi_dadd((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
                       (int)((ulonglong)uVar7 >> 0x20));
  uVar1 = (uint)((ulonglong)uVar7 >> 0x20);
  iVar3 = ((uVar1 & 0x7fffffff) >> 0x14) - 0x400;
  bVar6 = SBORROW4(0x1e,iVar3);
  uVar2 = -iVar3 + 0x1e;
  bVar5 = uVar2 == 0;
  uVar4 = uVar2;
  if (!bVar5 && iVar3 < 0x1f) {
    bVar6 = SBORROW4(0x21,uVar2);
    uVar4 = 0x21 - uVar2;
    bVar5 = uVar2 == 0x21;
  }
  if (!bVar5 && (int)uVar4 < 0 == bVar6) {
    return ((uVar1 << 0xb | 0x80000000 | (uint)uVar7 >> 0x15) >> (uVar2 & 0xff) ^ (int)uVar1 >> 0x1f
           ) - ((int)uVar1 >> 0x1f);
  }
  if (0x10 < (int)uVar2) {
    return 0;
  }
  if (-iVar3 != -0x3ff) {
    return (int)uVar1 >> 0x20 ^ 0x7fffffff;
  }
  fp_nan_handler((uint)uVar7);
  do {
    *unaff_r4 = (short)unaff_r4;
  } while( true );
}


// ===== rtc_delay @ 20114144 (36 bytes)

/* ~20-loop spin */

void rtc_delay(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0x14;
  do {
    bVar2 = iVar1 != 0;
    iVar1 = iVar1 + -1;
  } while (bVar2);
  return;
}


// ===== rtc_send_byte @ 20114168 (88 bytes)

void rtc_send_byte(uint param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    PORT_PSR1 = 0x20000;
    if ((param_1 & 1) == 0) {
      PORT_PSR1 = 0x10000;
    }
    else {
      PORT_PSR1 = 0x10001;
    }
    rtc_delay();
    PORT_PSR1 = 0x20002;
    param_1 = param_1 >> 1;
    rtc_delay();
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}


// ===== rtc_send_bytes @ 201141c0 (36 bytes)

void rtc_send_bytes(void *param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    rtc_send_byte((uint)*(byte *)param_1);
    param_1 = (byte *)((int)param_1 + 1);
  }
  return;
}


// ===== rtc_recv_byte @ 201141e4 (96 bytes)

byte rtc_recv_byte(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  rtc_dt_input();
  iVar3 = 0;
  do {
    uVar2 = uVar2 >> 1;
    PORT_PSR1 = 0x20000;
    rtc_delay();
    uVar1 = PORT_PPR1;
    PORT_PSR1 = 0x20002;
    if ((uVar1 & 1) != 0) {
      uVar2 = uVar2 | 0x80;
    }
    rtc_delay();
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  rtc_dt_output();
  return (byte)uVar2;
}


// ===== rtc_recv_bytes @ 20114244 (36 bytes)

void rtc_recv_bytes(void *param_1,int param_2)

{
  byte bVar1;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    bVar1 = rtc_recv_byte();
    *(byte *)param_1 = bVar1;
    param_1 = (byte *)((int)param_1 + 1);
  }
  return;
}


// ===== rtc_read_reg @ 20114268 (100 bytes)

/* cmd 0x86|reg: status 1/2, INT1/INT2 registers */

byte rtc_read_reg(uint param_1)

{
  byte bVar1;
  
  itron_tloc_mtx(DAT_20800368,0xffffffff);
  PORT_PSR1 = 0x40004;
  rtc_delay();
  rtc_send_byte(param_1 | 0x86);
  bVar1 = rtc_recv_byte();
  rtc_delay();
  PORT_PSR1 = 0x40000;
  itron_unl_mtx(DAT_20800368);
  rtc_delay();
  return bVar1;
}


// ===== rtc_write_reg @ 201142cc (92 bytes)

/* cmd 0x06|reg + 1 data byte */

void rtc_write_reg(undefined1 param_1,undefined1 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 local_10;
  
  local_10._2_2_ = (undefined2)((uint)param_4 >> 0x10);
  local_10 = CONCAT22(local_10._2_2_,CONCAT11(param_2,param_1)) | 6;
  itron_tloc_mtx(DAT_20800368,0xffffffff);
  PORT_PSR1 = 0x40004;
  rtc_delay();
  rtc_send_bytes(&local_10,2);
  rtc_delay();
  PORT_PSR1 = 0x40000;
  itron_unl_mtx(DAT_20800368);
  return;
}


// ===== rtc_port_idle @ 20114328 (24 bytes)

/* CK high, CS low */

void rtc_port_idle(void)

{
  PORT_PSR1 = 0x20002;
  PORT_PSR1 = 0x40000;
  return;
}


// ===== rtc_write_datetime_raw @ 20114340 (96 bytes)

/* cmd 0x26 + 7 BCD bytes */

void rtc_write_datetime_raw(uint param_1)

{
  itron_tloc_mtx(DAT_20800368,0xffffffff);
  PORT_PSR1 = 0x40004;
  rtc_delay();
  rtc_send_byte(0x26);
  rtc_send_bytes((void *)param_1,7);
  rtc_delay();
  PORT_PSR1 = 0x40000;
  itron_unl_mtx(DAT_20800368);
  return;
}


// ===== rtc_write_time_raw @ 201143a0 (96 bytes)

/* cmd 0x66 + 3 BCD bytes */

void rtc_write_time_raw(int param_1)

{
  itron_tloc_mtx(DAT_20800368,0xffffffff);
  PORT_PSR1 = 0x40004;
  rtc_delay();
  rtc_send_byte(0x66);
  rtc_send_bytes((void *)(param_1 + 4),3);
  rtc_delay();
  PORT_PSR1 = 0x40000;
  itron_unl_mtx(DAT_20800368);
  return;
}


// ===== rtc_read_datetime_raw @ 20114400 (108 bytes)

/* cmd 0xA6, 7 BCD bytes (hour bit 6 masked) */

void rtc_read_datetime_raw(int param_1)

{
  itron_tloc_mtx(DAT_20800368,0xffffffff);
  PORT_PSR1 = 0x40004;
  rtc_delay();
  rtc_send_byte(0xa6);
  rtc_recv_bytes((void *)param_1,7);
  rtc_delay();
  PORT_PSR1 = 0x40000;
  itron_unl_mtx(DAT_20800368);
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
  return;
}


// ===== rtc_read_time_raw @ 2011446c (108 bytes)

/* cmd 0xE6 */

void rtc_read_time_raw(int param_1)

{
  itron_tloc_mtx(DAT_20800368,0xffffffff);
  PORT_PSR1 = 0x40004;
  rtc_delay();
  rtc_send_byte(0xe6);
  rtc_recv_bytes((void *)(param_1 + 4),2);
  rtc_delay();
  PORT_PSR1 = 0x40000;
  itron_unl_mtx(DAT_20800368);
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
  return;
}


// ===== rtc_minutes_of_day @ 201144d8 (80 bytes)

void rtc_minutes_of_day(short *param_1)

{
  undefined1 auStack_10 [4];
  byte local_c;
  byte local_b;
  
  rtc_read_time_raw((int)auStack_10);
  *param_1 = (local_b & 0xf) + (ushort)(local_b >> 4) * 2 + (ushort)(local_b >> 4) * 8 +
             ((local_c & 0xf) + (ushort)(local_c >> 4) * 10) * 0x3c;
  return;
}


// ===== rtc_get_date @ 20114528 (60 bytes)

/* (y, m, d) BCD */

void rtc_get_date(void *param_1,void *param_2,void *param_3)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  rtc_read_datetime_raw((int)&local_18);
  *(undefined1 *)param_1 = local_18;
  *(undefined1 *)param_2 = local_17;
  *(undefined1 *)param_3 = local_16;
  return;
}


// ===== rtc_set_date @ 20114564 (56 bytes)

void rtc_set_date(byte param_1,byte param_2,byte param_3)

{
  byte local_18;
  byte local_17;
  byte local_16;
  
  rtc_read_time_raw((int)&local_18);
  local_18 = param_1;
  local_17 = param_2;
  local_16 = param_3;
  rtc_write_datetime_raw((uint)&local_18);
  return;
}


// ===== rtc_get_time @ 2011459c (60 bytes)

/* (h, m, s) BCD */

void rtc_get_time(void *param_1,void *param_2,void *param_3)

{
  undefined1 auStack_18 [4];
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  rtc_read_datetime_raw((int)auStack_18);
  *(undefined1 *)param_1 = local_14;
  *(undefined1 *)param_2 = local_13;
  *(undefined1 *)param_3 = local_12;
  return;
}


// ===== rtc_set_time @ 201145d8 (48 bytes)

void rtc_set_time(byte param_1,byte param_2,byte param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = (uint)CONCAT12(param_3,CONCAT11(param_2,param_1));
  local_10 = 0;
  rtc_write_time_raw((int)&local_10);
  return;
}


// ===== rtc_set_datetime @ 20114608 (80 bytes)

void rtc_set_datetime(byte param_1,byte param_2,byte param_3,byte param_4,byte param_5)

{
  byte local_20;
  byte local_1f;
  byte local_1e;
  byte local_1c;
  byte local_1b;
  undefined1 local_1a;
  
  rtc_read_time_raw((int)&local_20);
  local_1b = param_5;
  local_1a = 0;
  local_20 = param_1;
  local_1f = param_2;
  local_1e = param_3;
  local_1c = param_4;
  rtc_write_datetime_raw((uint)&local_20);
  return;
}


// ===== rtc_get_datetime @ 20114658 (92 bytes)

void rtc_get_datetime(void *param_1,void *param_2,void *param_3,void *param_4,void *param_5,
                     void *param_6)

{
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  rtc_read_datetime_raw((int)&local_28);
  *(undefined1 *)param_1 = local_28;
  *(undefined1 *)param_2 = local_27;
  *(undefined1 *)param_3 = local_26;
  *(undefined1 *)param_4 = local_24;
  *(undefined1 *)param_5 = local_23;
  *(undefined1 *)param_6 = local_22;
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
  
  rtc_read_datetime_raw((int)&local_10);
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

void rtc_read_status(byte *param_1)

{
  byte bVar1;
  
  bVar1 = rtc_read_reg(0);
  *param_1 = bVar1;
  bVar1 = rtc_read_reg(0x40);
  param_1[1] = bVar1;
  bVar1 = rtc_read_reg(0x10);
  param_1[2] = bVar1;
  bVar1 = rtc_read_reg(0x50);
  param_1[3] = bVar1;
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
  t_cmtx local_10;
  
  rtc_port_idle();
  rtc_write_reg(0,2);
  rtc_write_reg(0x40,0);
  local_10.mtxatr = 2;
  local_10.ceilpri = 0;
  local_10.name = (char *)0x0;
  DAT_20800368 = itron_acre_mtx(0,&local_10);
  return;
}


// ===== FUN_20114848 @ 20114848 (8 bytes)

undefined4 FUN_20114848(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
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
  scif3_uart.rxi_count = scif3_uart.rxi_count + 1;
  if (((scif3_uart.regs)->scfsr & 0xff9d) != 0) {
    scif3_uart.rx_errors = scif3_uart.rx_errors + 1;
  }
  if (((scif3_uart.regs)->scfsr & 2) != 0) {
    if (((scif3_uart.rx_wr < scif3_uart.rx_rd) ||
        (0x3fe < (int)((uint)scif3_uart.rx_wr - (uint)scif3_uart.rx_rd))) &&
       ((scif3_uart.rx_rd <= scif3_uart.rx_wr ||
        ((int)((uint)scif3_uart.rx_rd - (uint)scif3_uart.rx_wr) < 2)))) {
      (scif3_uart.regs)->scfsr = (scif3_uart.regs)->scfsr & 0xfffd;
      scif3_uart.rx_count = scif3_uart.rx_count + 1;
      scif3_uart.rx_overflow = scif3_uart.rx_overflow + 1;
      return;
    }
    scif3_uart.rx_buf[scif3_uart.rx_wr] = (scif3_uart.regs)->scfrdr;
    DataMemoryBarrier(2);
    scif3_uart.rx_wr = scif3_uart.rx_wr + 1 & 0x3ff;
    (scif3_uart.regs)->scfsr = (scif3_uart.regs)->scfsr & 0xfffd;
    if (scif3_uart.rx_flg != 0) {
      gic_disable_irq((scif3_uart.rxi_isr)->intno);
    }
    itron_set_flg(scif3_uart.rx_flg,1);
    scif3_uart.rx_count = scif3_uart.rx_count + 1;
    thunk_FUN_20114850(0x208daa20);
    return;
  }
  scif3_uart.rxi_no_data = scif3_uart.rxi_no_data + 1;
  return;
}


// ===== scif3_txi_isr @ 2011488c (8 bytes)

void scif3_txi_isr(void)

{
  scif_txi_isr(&scif3_uart);
  return;
}


// ===== scif4_rxi_isr @ 20114894 (8 bytes)

void scif4_rxi_isr(void)

{
  scif4_uart.rxi_count = scif4_uart.rxi_count + 1;
  if (((scif4_uart.regs)->scfsr & 0xff9d) != 0) {
    scif4_uart.rx_errors = scif4_uart.rx_errors + 1;
  }
  if (((scif4_uart.regs)->scfsr & 2) != 0) {
    if (((scif4_uart.rx_wr < scif4_uart.rx_rd) ||
        (0x3fe < (int)((uint)scif4_uart.rx_wr - (uint)scif4_uart.rx_rd))) &&
       ((scif4_uart.rx_rd <= scif4_uart.rx_wr ||
        ((int)((uint)scif4_uart.rx_rd - (uint)scif4_uart.rx_wr) < 2)))) {
      (scif4_uart.regs)->scfsr = (scif4_uart.regs)->scfsr & 0xfffd;
      scif4_uart.rx_count = scif4_uart.rx_count + 1;
      scif4_uart.rx_overflow = scif4_uart.rx_overflow + 1;
      return;
    }
    scif4_uart.rx_buf[scif4_uart.rx_wr] = (scif4_uart.regs)->scfrdr;
    DataMemoryBarrier(2);
    scif4_uart.rx_wr = scif4_uart.rx_wr + 1 & 0x3ff;
    (scif4_uart.regs)->scfsr = (scif4_uart.regs)->scfsr & 0xfffd;
    if (scif4_uart.rx_flg != 0) {
      gic_disable_irq((scif4_uart.rxi_isr)->intno);
    }
    itron_set_flg(scif4_uart.rx_flg,1);
    scif4_uart.rx_count = scif4_uart.rx_count + 1;
    thunk_FUN_20114850(0x208db270);
    return;
  }
  scif4_uart.rxi_no_data = scif4_uart.rxi_no_data + 1;
  return;
}


// ===== scif4_txi_isr @ 2011489c (8 bytes)

void scif4_txi_isr(void)

{
  scif_txi_isr(&scif4_uart);
  return;
}

