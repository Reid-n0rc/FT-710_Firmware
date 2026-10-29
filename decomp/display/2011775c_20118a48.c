// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== gic_enable_irq @ 2011775c (68 bytes)

/* enable one GIC interrupt ID */

undefined4 gic_enable_irq(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x24b) {
    FUN_2015686c();
    *(int *)(&DAT_e8201100 + (param_1 >> 5) * 4) = 1 << (param_1 & 0x1f);
    FUN_2015688c();
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffef;
  }
  return uVar1;
}


// ===== gic_disable_irq @ 201177a0 (68 bytes)

/* GICD_ICENABLER bit */

undefined4 gic_disable_irq(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x24b) {
    FUN_2015686c();
    (&DAT_e8201180)[param_1 >> 5] = 1 << (param_1 & 0x1f);
    FUN_2015688c();
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffef;
  }
  return uVar1;
}


// ===== ostm_init @ 201177e4 (84 bytes)

/* OSTM 0xFCFEC000 (system tick) */

int ostm_init(void)

{
  byte bVar1;
  int iVar2;
  
  DAT_fcfec000 = 319999;
  bVar1 = DAT_fcfec020;
  DAT_fcfec020 = bVar1 & 0xfd;
  DAT_fcfec020 = 1;
  iVar2 = itron_acre_isr(0,&DAT_20165a60);
  if (0 < iVar2) {
    gic_enable_irq(0x86);
    bVar1 = DAT_fcfec014;
    DAT_fcfec014 = bVar1 | 1;
    iVar2 = 0;
  }
  return iVar2;
}


// ===== ostm0_tick_isr @ 20117838 (92 bytes)

/* GIC 0x86: system time += 10000 us, kernel tick */

void ostm0_tick_isr(void)

{
  FUN_2015686c();
  DAT_20800408 = DAT_20800408 + 10000;
  FUN_2015688c();
  DAT_208dc17c = 0;
  DAT_208003dc = (char)DAT_201659d0 + '\x01';
  DAT_208003dd = DAT_208003dd + '\x01';
  return;
}


// ===== ostm_time_us @ 20117860 (148 bytes)

/* system time (us) interpolated from the OSTM0 counter */

undefined8 ostm_time_us(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  uVar1 = DAT_20800408;
  iVar3 = DAT_fcfec004;
  bVar2 = DAT_fcfec010;
  iVar3 = 320000 - iVar3;
  if ((bVar2 & 1) != 0) {
    uVar1 = DAT_e8205580;
    if ((uVar1 & 0x40) != 0) {
      iVar3 = DAT_fcfec004;
      iVar3 = 640000 - iVar3;
    }
    return CONCAT44(iVar3 * 0x333333a8,DAT_20800408 + ((uint)(iVar3 * 1000) / 320000) * 10);
  }
  DAT_20800408 = DAT_20800408 + 1;
  return CONCAT44(&DAT_20800408,uVar1 / 3);
}


// ===== delay_us @ 201178f4 (56 bytes)

/* busy-wait on ostm_time_us */

void delay_us(uint param_1)

{
  int iVar1;
  int iVar2;
  
  if ((int)param_1 < 0) {
    DAT_20800408 = 0;
    return;
  }
  iVar1 = ostm_time_us();
  do {
    iVar2 = ostm_time_us();
  } while ((uint)(iVar2 - iVar1) < param_1);
  return;
}


// ===== FUN_201179bc @ 201179bc (4 bytes)

void FUN_201179bc(void)

{
  return;
}


// ===== r_vdc5_initialize @ 201179c0 (168 bytes)

/* (ch, vdc5_init_t*, init_func, user_num) */

undefined4 r_vdc5_initialize(undefined4 param_1,int param_2,code *param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  FUN_2011d080();
  iVar1 = FUN_2011d830(param_1,4);
  if ((iVar1 == 0) || (*(int *)(param_2 + 4) == 0)) {
    FUN_2011d19c(param_1,param_2);
    if (param_3 != (code *)0x0) {
      (*param_3)(param_4);
    }
    FUN_201193ec(param_1,param_2);
    vdc5_int_callbacks_clear(param_1);
    FUN_2011d7d8(param_1,0,1);
    if (*(int *)(param_2 + 4) != 0) {
      FUN_2011d7d8(param_1,4,1);
    }
  }
  else {
    uVar2 = 0xd;
  }
  return uVar2;
}


// ===== FUN_20117ad4 @ 20117ad4 (56 bytes)

undefined4 FUN_20117ad4(undefined4 param_1,undefined4 param_2)

{
  FUN_2011d1f4();
  FUN_201197c0(param_1,param_2);
  FUN_2011d7d8(param_1,1);
  return 0;
}


// ===== r_vdc5_sync_control @ 20117b0c (156 bytes)

/* (ch, vdc5_sync_ctrl_t*): total raster, H/V sync windows */

undefined4 r_vdc5_sync_control(uint param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    if (*param_2 == '\0') {
      uVar2 = param_1;
      if (param_2[1] != '\0') {
        uVar2 = (uint)(param_1 == 0);
      }
      iVar1 = FUN_2011d830(uVar2,1);
      if (iVar1 != 1) {
        return 0xb;
      }
    }
    FUN_2011d248(param_1,param_2);
    FUN_20119990(param_1,param_2);
    FUN_2011d7d8(param_1,2,1);
  }
  else {
    uVar3 = 9;
  }
  return uVar3;
}


// ===== r_vdc5_display_output @ 20117ba8 (108 bytes)

/* (ch, vdc5_output_t*): TCON pins, panel output */

undefined4 r_vdc5_display_output(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      FUN_2011d2b4(param_1,param_2);
      FUN_20119e60(param_1,param_2);
      FUN_2011d7d8(param_1,3,1);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== FUN_20117c14 @ 20117c14 (80 bytes)

undefined4 FUN_20117c14(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,0);
  if (iVar1 == 1) {
    iVar1 = FUN_2011d830(param_1,2);
    if (iVar1 == 1) {
      r_vdc5_callback_isr(param_1,param_2);
    }
    else {
      uVar2 = 10;
    }
  }
  else {
    uVar2 = 9;
  }
  return uVar2;
}


// ===== FUN_20117c64 @ 20117c64 (24 bytes)

uint FUN_20117c64(uint param_1)

{
  if ((1 < param_1) && (param_1 != 2)) {
    param_1 = 3;
  }
  return param_1;
}


// ===== FUN_20117c7c @ 20117c7c (176 bytes)

undefined4 FUN_20117c7c(int param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = FUN_20117c64(param_2);
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 != 0) {
    return 0xe;
  }
  iVar2 = param_1;
  if (param_2 != 0) {
    if (param_2 != 1) goto LAB_20117cf4;
    if (param_1 == 0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 0;
    }
  }
  iVar2 = FUN_2011d830(iVar2,1);
  if (iVar2 != 1) {
    return 0xb;
  }
LAB_20117cf4:
  FUN_2011d374(param_1,uVar1,param_3);
  vdc5_config(param_1,uVar1,param_3);
  FUN_2011d7f0(param_1,param_2,1);
  return 0;
}


// ===== FUN_20117d2c @ 20117d2c (96 bytes)

undefined4 FUN_20117d2c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = FUN_20117c64(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d920(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011d3f0(param_1,uVar1,param_3);
    FUN_2011a6c8(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== vdc5_layer_to_gr @ 20117d8c (72 bytes)

/* layer id 3..8 -> graphics index 0..5 */

undefined4 vdc5_layer_to_gr(undefined4 param_1)

{
  switch(param_1) {
  case 3:
    return 0;
  case 4:
    return 1;
  case 5:
    return 2;
  case 6:
    return 3;
  case 7:
    return 4;
  case 8:
    return 5;
  default:
    return 6;
  }
}


// ===== r_vdc5_read_data_control @ 20117dec (112 bytes)

/* (ch, layer, vdc5_read_t*): frame buffer, stride, format, window */

undefined4 r_vdc5_read_data_control(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    FUN_2011d438(param_1,uVar1,param_3);
    FUN_2011af34(param_1,uVar1,param_3);
    FUN_2011d7f0(param_1,param_2,1);
  }
  else {
    uVar3 = 0xe;
  }
  return uVar3;
}


// ===== r_vdc5_change_read_process @ 20117e5c (96 bytes)

/* (ch, layer, {base,...}): new frame-buffer address */

undefined4 r_vdc5_change_read_process(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d920(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011d514(param_1,uVar1,param_3);
    FUN_2011b498(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== r_vdc5_start_process @ 20117ebc (68 bytes)

/* (ch, layer, &disp_sel): show a layer (2 current, 3 blend) */

undefined4 r_vdc5_start_process(undefined4 param_1,int param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 == -1) || (iVar1 = FUN_2011d8e8(), iVar1 != 0)) {
    FUN_2011b8b8(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xe;
  }
  return uVar2;
}


// ===== r_vdc5_stop_process @ 20117f00 (60 bytes)

/* (ch, layer): hide a layer */

undefined4 r_vdc5_stop_process(undefined4 param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  if ((param_2 == -1) || (iVar1 = FUN_2011d920(), iVar1 != 0)) {
    FUN_2011b988(param_1,param_2);
  }
  else {
    uVar2 = 0xe;
  }
  return uVar2;
}


// ===== FUN_20117f88 @ 20117f88 (64 bytes)

undefined4 FUN_20117f88(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,1);
  if (iVar1 == 1) {
    FUN_2011bb84(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}


// ===== FUN_20117fc8 @ 20117fc8 (140 bytes)

undefined4 FUN_20117fc8(uint param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*param_2 == '\0') {
    iVar1 = FUN_2011d84c(param_1,0);
    if (iVar1 != 0) goto LAB_2011801c;
    uVar3 = 1;
    uVar2 = (uint)(param_1 == 0);
LAB_2011804c:
    iVar1 = FUN_2011d84c(uVar2,uVar3);
  }
  else {
    if (*param_2 == '\x01') {
      uVar3 = 3;
      uVar2 = param_1;
      goto LAB_2011804c;
    }
    iVar1 = FUN_2011d84c(param_1,4);
  }
  if (iVar1 == 0) {
    return 0xe;
  }
LAB_2011801c:
  FUN_2011bc8c(param_1,param_2);
  return 0;
}


// ===== FUN_20118054 @ 20118054 (140 bytes)

undefined4
FUN_20118054(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5
            ,undefined4 param_6,undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 4;
  }
  iVar1 = FUN_2011d84c(param_1,uVar2);
  if (iVar1 == 0) {
    uVar3 = 0xe;
  }
  else {
    iVar1 = FUN_2011d6fc(param_1,param_2 != 0);
    if (iVar1 == 0) {
      uVar3 = 8;
    }
    else {
      FUN_2011bf00(param_1,param_2,param_3,param_4,param_5,param_6,param_7);
    }
  }
  return uVar3;
}


// ===== FUN_201180e0 @ 201180e0 (108 bytes)

undefined4 FUN_201180e0(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  if (param_2 == 0) {
    uVar2 = 3;
  }
  else {
    uVar2 = 4;
  }
  iVar1 = FUN_2011d84c(param_1,uVar2);
  if (iVar1 == 0) {
    uVar3 = 0xe;
  }
  else {
    iVar1 = FUN_2011d6fc(param_1,param_2 != 0);
    if (iVar1 == 0) {
      uVar3 = 8;
    }
    else {
      FUN_2011bfc4(param_1,param_2,param_3,param_4);
    }
  }
  return uVar3;
}


// ===== FUN_2011814c @ 2011814c (80 bytes)

undefined4 FUN_2011814c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011c068(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== r_vdc5_alpha_blending_rect @ 2011819c (120 bytes)

/* (ch, layer, on, {rect, alpha, ...}): alpha window / fades */

undefined4
r_vdc5_alpha_blending_rect(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  if (param_2 != 7) {
    iVar2 = FUN_2011d84c(param_1,param_2);
    if (iVar2 == 0) {
      return 0xe;
    }
    iVar2 = FUN_2011d6fc(param_1,uVar1);
    if (iVar2 == 1) {
      return 8;
    }
  }
  FUN_2011c22c(param_1,uVar1,param_3,param_4);
  return 0;
}


// ===== r_vdc5_chromakey @ 20118214 (112 bytes)

/* (ch, layer, on, {ck_color, rep_color, rep_alpha}); used with color 0 = transparent */

undefined4
r_vdc5_chromakey(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    iVar2 = FUN_2011d6fc(param_1,uVar1);
    if (iVar2 == 1) {
      uVar3 = 8;
    }
    else {
      FUN_2011c4d4(param_1,uVar1,param_3,param_4);
    }
  }
  return uVar3;
}


// ===== FUN_20118284 @ 20118284 (80 bytes)

undefined4 FUN_20118284(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = FUN_2011d84c(param_1,param_2);
  if (iVar2 == 0) {
    uVar3 = 0xe;
  }
  else {
    FUN_2011c5e4(param_1,uVar1,param_3);
  }
  return uVar3;
}


// ===== r_vdc5_display_calibration @ 201182d4 (56 bytes)

/* (ch, vdc5_disp_calibration_t*): used for the LCD contrast setting */

undefined4 r_vdc5_display_calibration(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,3);
  if (iVar1 == 1) {
    FUN_2011c6ec(param_1,param_2);
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}


// ===== FUN_2011830c @ 2011830c (64 bytes)

undefined4 FUN_2011830c(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = FUN_2011d830(param_1,3);
  if (iVar1 == 1) {
    FUN_2011c950(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}


// ===== FUN_2011834c @ 2011834c (24 bytes)

undefined * FUN_2011834c(int param_1,int param_2)

{
  return (&PTR_FUN_20165a74)[param_1 * 0x17 + param_2];
}


// ===== vdc5_int_callbacks_clear @ 20118364 (76 bytes)

/* clears the 23 per-channel interrupt callbacks */

void vdc5_int_callbacks_clear(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    (&DAT_208dcc0c)[param_1 * 0x17 + iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x17);
  *(undefined4 *)(&DAT_20166a3c)[param_1 * 8] = 0;
  *(undefined4 *)(&DAT_20166a40)[param_1 * 8] = 0;
  *(undefined4 *)(&DAT_20166a44)[param_1 * 8] = 0;
  return;
}


// ===== r_vdc5_callback_isr @ 201183b0 (408 bytes)

/* (ch, {type, callback, line}): enable one VDC5 interrupt */

void r_vdc5_callback_isr(int param_1,byte *param_2)

{
  byte bVar1;
  uint *puVar2;
  uint *puVar3;
  uint uVar4;
  uint uVar5;
  
  uVar5 = (uint)*param_2;
  if (uVar5 < 8) {
    puVar3 = (uint *)(&DAT_20166a30)[param_1 * 8];
    puVar2 = (uint *)(&DAT_20166a3c)[param_1 * 8];
  }
  else if (uVar5 < 0x10) {
    puVar3 = (uint *)(&DAT_20166a34)[param_1 * 8];
    puVar2 = (uint *)(&DAT_20166a40)[param_1 * 8];
  }
  else {
    puVar3 = (uint *)(&DAT_20166a38)[param_1 * 8];
    puVar2 = (uint *)(&DAT_20166a44)[param_1 * 8];
  }
  uVar4 = *(uint *)(&DAT_20165b2c + uVar5 * 4);
  (&DAT_208dcc0c)[param_1 * 0x17 + uVar5] = *(undefined4 *)(param_2 + 4);
  if (*(int *)(param_2 + 4) == 0) {
    *puVar2 = *puVar2 & ~uVar4;
    *puVar3 = *puVar2;
    return;
  }
  if ((*puVar2 & uVar4) == 0) {
    *puVar2 = *puVar2 | uVar4;
    *puVar3 = *puVar2;
  }
  bVar1 = *param_2;
  if (bVar1 == 3) {
    puVar2 = *(uint **)(&DAT_20166418 + param_1 * 0x210);
    puVar3 = *(uint **)(&DAT_201663c8 + param_1 * 0x210);
    *puVar2 = *puVar2 & 0xfffff800;
    *puVar2 = (uint)*(ushort *)(param_2 + 8) | *puVar2;
    *puVar3 = *puVar3 | 0x10;
    return;
  }
  if (bVar1 == 9) {
    puVar2 = *(uint **)(&DAT_20165ce0 + param_1 * 0x228);
    *(undefined2 *)(&PTR_DAT_20165d08)[param_1 * 0x8a] = *(undefined2 *)(param_2 + 8);
    *puVar2 = *puVar2 | 1;
    return;
  }
  if (bVar1 != 0x10) {
    if (bVar1 == 0x13) {
      puVar2 = (uint *)(&PTR_DAT_201664c8)[param_1 * 0x84];
      puVar3 = (uint *)(&PTR_DAT_20166478)[param_1 * 0x84];
      *puVar2 = *puVar2 & 0xfffff800;
      *puVar2 = (uint)*(ushort *)(param_2 + 8) | *puVar2;
      *puVar3 = *puVar3 | 0x10;
    }
    return;
  }
  puVar2 = *(uint **)(&DAT_20165d98 + param_1 * 0x228);
  *(undefined2 *)(&PTR_DAT_20165dc0)[param_1 * 0x8a] = *(undefined2 *)(param_2 + 8);
  *puVar2 = *puVar2 | 1;
  return;
}


// ===== FUN_20118548 @ 20118548 (80 bytes)

void FUN_20118548(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 1) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 1) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xfffffffe;
    if (DAT_208dcc0c != (code *)0x0) {
      (*DAT_208dcc0c)(0);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_20118598 @ 20118598 (80 bytes)

void FUN_20118598(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x10) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x10) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xffffffef;
    if (DAT_208dcc10 != (code *)0x0) {
      (*DAT_208dcc10)(1);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_201185e8 @ 201185e8 (80 bytes)

void FUN_201185e8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x100) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x100) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xfffffeff;
    if (DAT_208dcc14 != (code *)0x0) {
      (*DAT_208dcc14)(2);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_20118638 @ 20118638 (80 bytes)

void FUN_20118638(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x1000) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x1000) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xffffefff;
    if (DAT_208dcc18 != (code *)0x0) {
      (*DAT_208dcc18)(3);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_20118688 @ 20118688 (80 bytes)

void FUN_20118688(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x10000) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x10000) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xfffeffff;
    if (DAT_208dcc1c != (code *)0x0) {
      (*DAT_208dcc1c)(4);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_201186d8 @ 201186d8 (80 bytes)

void FUN_201186d8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x100000) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x100000) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xffefffff;
    if (DAT_208dcc20 != (code *)0x0) {
      (*DAT_208dcc20)(5);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_20118728 @ 20118728 (80 bytes)

void FUN_20118728(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x1000000) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x1000000) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xfeffffff;
    if (DAT_208dcc24 != (code *)0x0) {
      (*DAT_208dcc24)(6);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_20118778 @ 20118778 (80 bytes)

void FUN_20118778(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a8c;
  if (((uVar2 & 0x10000000) != 0) && (uVar1 = DAT_fcff7a80, (uVar1 & 0x10000000) != 0)) {
    DAT_fcff7a80 = uVar2 & 0xefffffff;
    if (DAT_208dcc28 != (code *)0x0) {
      (*DAT_208dcc28)(7);
    }
    DAT_fcff7a80 = uVar2;
  }
  return;
}


// ===== FUN_201187c8 @ 201187c8 (80 bytes)

void FUN_201187c8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 1) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 1) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xfffffffe;
    if (DAT_208dcc2c != (code *)0x0) {
      (*DAT_208dcc2c)(8);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_20118818 @ 20118818 (80 bytes)

void FUN_20118818(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 0x10) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 0x10) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xffffffef;
    if (DAT_208dcc30 != (code *)0x0) {
      (*DAT_208dcc30)(9);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_20118868 @ 20118868 (80 bytes)

void FUN_20118868(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 0x100) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 0x100) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xfffffeff;
    if (DAT_208dcc34 != (code *)0x0) {
      (*DAT_208dcc34)(10);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_201188b8 @ 201188b8 (80 bytes)

void FUN_201188b8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 0x1000) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 0x1000) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xffffefff;
    if (DAT_208dcc38 != (code *)0x0) {
      (*DAT_208dcc38)(0xb);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_20118908 @ 20118908 (80 bytes)

void FUN_20118908(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 0x10000) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 0x10000) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xfffeffff;
    if (DAT_208dcc3c != (code *)0x0) {
      (*DAT_208dcc3c)(0xc);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_20118958 @ 20118958 (80 bytes)

void FUN_20118958(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 0x100000) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 0x100000) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xffefffff;
    if (DAT_208dcc40 != (code *)0x0) {
      (*DAT_208dcc40)(0xd);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_201189a8 @ 201189a8 (80 bytes)

void FUN_201189a8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 0x1000000) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 0x1000000) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xfeffffff;
    if (DAT_208dcc44 != (code *)0x0) {
      (*DAT_208dcc44)(0xe);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_201189f8 @ 201189f8 (80 bytes)

void FUN_201189f8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a90;
  if (((uVar2 & 0x10000000) != 0) && (uVar1 = DAT_fcff7a84, (uVar1 & 0x10000000) != 0)) {
    DAT_fcff7a84 = uVar2 & 0xefffffff;
    if (DAT_208dcc48 != (code *)0x0) {
      (*DAT_208dcc48)(0xf);
    }
    DAT_fcff7a84 = uVar2;
  }
  return;
}


// ===== FUN_20118a48 @ 20118a48 (80 bytes)

void FUN_20118a48(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_fcff7a94;
  if (((uVar2 & 1) != 0) && (uVar1 = DAT_fcff7a88, (uVar1 & 1) != 0)) {
    DAT_fcff7a88 = uVar2 & 0xfffffffe;
    if (DAT_208dcc4c != (code *)0x0) {
      (*DAT_208dcc4c)(0x10);
    }
    DAT_fcff7a88 = uVar2;
  }
  return;
}

