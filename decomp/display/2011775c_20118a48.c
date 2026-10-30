// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== gic_enable_irq @ 2011775c (68 bytes)

/* enable one GIC interrupt ID */

undefined4 gic_enable_irq(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 0x24b) {
    knl_int_disable();
    (&INTC_ICDISER0)[param_1 >> 5] = 1 << (param_1 & 0x1f);
    knl_int_restore();
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
    knl_int_disable();
    (&INTC_ICDICER0)[param_1 >> 5] = 1 << (param_1 & 0x1f);
    knl_int_restore();
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffef;
  }
  return uVar1;
}


// ===== ostm_init @ 201177e4 (84 bytes)

/* OSTM 0xFCFEC000 (system tick) */

uint ostm_init(void)

{
  byte bVar1;
  uint uVar2;
  
  OSTM_OSTM0CMP = 319999;
  bVar1 = OSTM_OSTM0CTL;
  OSTM_OSTM0CTL = bVar1 & 0xfd;
  OSTM_OSTM0CTL = 1;
  uVar2 = itron_acre_isr(0,&cisr_ostm0_tick_isr);
  if (0 < (int)uVar2) {
    gic_enable_irq(0x86);
    bVar1 = OSTM_OSTM0TS;
    OSTM_OSTM0TS = bVar1 | 1;
    uVar2 = 0;
  }
  return uVar2;
}


// ===== ostm0_tick_isr @ 20117838 (92 bytes)

/* GIC 0x86: system time += 10000 us, kernel tick */

void ostm0_tick_isr(void)

{
  knl_int_disable();
  DAT_20800408 = DAT_20800408 + 10000;
  knl_int_restore();
  DAT_208dc17c = 0;
  knl_sys.f_0x34_u8 = (char)DAT_201659d0 + 1;
  knl_sys.tick_pending = knl_sys.tick_pending + 1;
  return;
}


// ===== ostm_time_us @ 20117860 (148 bytes)

/* system time (us) interpolated from the OSTM0 counter */

uint ostm_time_us(void)

{
  uint uVar1;
  byte bVar2;
  int iVar3;
  
  uVar1 = DAT_20800408;
  iVar3 = OSTM_OSTM0CNT;
  bVar2 = OSTM_OSTM0TE;
  iVar3 = 320000 - iVar3;
  if ((bVar2 & 1) != 0) {
    uVar1 = DAT_e8205580;
    if ((uVar1 & 0x40) != 0) {
      iVar3 = OSTM_OSTM0CNT;
      iVar3 = 640000 - iVar3;
    }
    return DAT_20800408 + ((uint)(iVar3 * 1000) / 320000) * 10;
  }
  DAT_20800408 = DAT_20800408 + 1;
  return uVar1 / 3;
}


// ===== delay_us @ 201178f4 (56 bytes)

/* busy-wait on ostm_time_us */

void delay_us(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  if ((int)param_1 < 0) {
    DAT_20800408 = 0;
    return;
  }
  uVar1 = ostm_time_us();
  do {
    uVar2 = ostm_time_us();
  } while (uVar2 - uVar1 < param_1);
  return;
}


// ===== FUN_201179bc @ 201179bc (4 bytes)

void FUN_201179bc(void)

{
  return;
}


// ===== r_vdc5_initialize @ 201179c0 (168 bytes)

/* (ch, vdc5_init_t*, init_func, user_num) */

uint r_vdc5_initialize(uint param_1,int param_2,void *param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = 0;
  FUN_2011d080();
  iVar1 = vdc5_shrd_get_state(param_1,4);
  if ((iVar1 == 0) || (*(int *)(param_2 + 4) == 0)) {
    FUN_2011d19c(param_1,param_2);
    if (param_3 != (void *)0x0) {
      (*param_3)(param_4);
    }
    FUN_201193ec(param_1,param_2);
    vdc5_int_callbacks_clear(param_1);
    vdc5_shrd_set_state(param_1,0,1);
    if (*(int *)(param_2 + 4) != 0) {
      vdc5_shrd_set_state(param_1,4,1);
    }
  }
  else {
    uVar2 = 0xd;
  }
  return uVar2;
}


// ===== r_vdc5_terminate @ 20117ad4 (56 bytes)

/* (ch, quit_func): driver shutdown of a channel, then state 0 = 1 again [inference: between
   initialize and sync_control in the API order] */

undefined4 r_vdc5_terminate(undefined4 param_1,undefined4 param_2)

{
  FUN_2011d1f4();
  FUN_201197c0(param_1,param_2);
  vdc5_shrd_set_state(param_1,1);
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
  iVar1 = vdc5_shrd_get_state(param_1,0);
  if (iVar1 == 1) {
    if (*param_2 == '\0') {
      uVar2 = param_1;
      if (param_2[1] != '\0') {
        uVar2 = (uint)(param_1 == 0);
      }
      iVar1 = vdc5_shrd_get_state(uVar2,1);
      if (iVar1 != 1) {
        return 0xb;
      }
    }
    FUN_2011d248(param_1,param_2);
    FUN_20119990(param_1,param_2);
    vdc5_shrd_set_state(param_1,2,1);
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
  iVar1 = vdc5_shrd_get_state(param_1,0);
  if (iVar1 == 1) {
    iVar1 = vdc5_shrd_get_state(param_1,2);
    if (iVar1 == 1) {
      FUN_2011d2b4(param_1,param_2);
      FUN_20119e60(param_1,param_2);
      vdc5_shrd_set_state(param_1,3,1);
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


// ===== r_vdc5_callback_isr_checked @ 20117c14 (80 bytes)

/* Checks channel states 0 and 2 (errors 9/10) and calls r_vdc5_callback_isr [fact]; the public
   R_VDC5_CallbackISR [inference] */

undefined4 r_vdc5_callback_isr_checked(int param_1,byte *param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = vdc5_shrd_get_state(param_1,0);
  if (iVar1 == 1) {
    iVar1 = vdc5_shrd_get_state(param_1,2);
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


// ===== vdc5_layer_to_wr @ 20117c64 (24 bytes)

/* Layer id 0/1/2 (write layers) unchanged, other ids to 3 [fact] */

uint vdc5_layer_to_wr(uint param_1)

{
  if ((1 < param_1) && (param_1 != 2)) {
    param_1 = 3;
  }
  return param_1;
}


// ===== r_vdc5_write_data_control @ 20117c7c (176 bytes)

/* (ch, layer 0..2, param): checks resources (error 14/11), writes the scaler write registers
   (vdc5_config) and marks the resource [inference: API order, write-layer ids] */

undefined4 r_vdc5_write_data_control(int param_1,int param_2,ushort *param_3)

{
  int iVar1;
  int iVar2;
  
  iVar1 = vdc5_layer_to_wr(param_2);
  iVar2 = r_vdc5_shrd_get_resource(param_1,param_2);
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
  iVar2 = vdc5_shrd_get_state(iVar2,1);
  if (iVar2 != 1) {
    return 0xb;
  }
LAB_20117cf4:
  FUN_2011d374(param_1,iVar1,param_3);
  vdc5_config(param_1,iVar1,param_3);
  vdc5_shrd_set_resource(param_1,param_2,1);
  return 0;
}


// ===== r_vdc5_change_write_process @ 20117d2c (96 bytes)

/* (ch, layer, param): needs a busy write resource (error 14) [inference] */

undefined4 r_vdc5_change_write_process(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_wr(param_2);
  uVar3 = 0;
  iVar2 = vdc5_shrd_res_busy(param_1,param_2);
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

uint vdc5_layer_to_gr(uint param_1)

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

uint r_vdc5_read_data_control(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = r_vdc5_shrd_get_resource(param_1,param_2);
  if (iVar2 == 0) {
    FUN_2011d438(param_1,uVar1,param_3);
    FUN_2011af34(param_1,uVar1,param_3);
    vdc5_shrd_set_resource(param_1,param_2,1);
  }
  else {
    uVar3 = 0xe;
  }
  return uVar3;
}


// ===== r_vdc5_change_read_process @ 20117e5c (96 bytes)

/* (ch, layer, {base,...}): new frame-buffer address */

undefined4 r_vdc5_change_read_process(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = vdc5_shrd_res_busy(param_1,param_2);
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

byte r_vdc5_start_process(uint param_1,int param_2,uint param_3)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  if ((param_2 == -1) || (iVar1 = vdc5_shrd_res_idle(), iVar1 != 0)) {
    FUN_2011b8b8(param_1,param_2,param_3);
  }
  else {
    bVar2 = 0xe;
  }
  return bVar2;
}


// ===== r_vdc5_stop_process @ 20117f00 (60 bytes)

/* (ch, layer): hide a layer */

byte r_vdc5_stop_process(uint param_1,int param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  if ((param_2 == -1) || (iVar1 = vdc5_shrd_res_busy(), iVar1 != 0)) {
    FUN_2011b988(param_1,param_2);
  }
  else {
    bVar2 = 0xe;
  }
  return bVar2;
}


// ===== r_vdc5_video_noise_reduction @ 20117f88 (64 bytes)

/* (ch, on, param): needs state 1 (error 11) [inference: API order] */

undefined4 r_vdc5_video_noise_reduction(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = vdc5_shrd_get_state(param_1,1);
  if (iVar1 == 1) {
    FUN_2011bb84(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xb;
  }
  return uVar2;
}


// ===== r_vdc5_image_color_matrix @ 20117fc8 (140 bytes)

/* (ch, {module 0/1/2, ...}): resource check by module, then the matrix registers [inference] */

undefined4 r_vdc5_image_color_matrix(uint param_1,char *param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (*param_2 == '\0') {
    iVar1 = r_vdc5_shrd_get_resource(param_1,0);
    if (iVar1 != 0) goto LAB_2011801c;
    uVar3 = 1;
    uVar2 = (uint)(param_1 == 0);
LAB_2011804c:
    iVar1 = r_vdc5_shrd_get_resource(uVar2,uVar3);
  }
  else {
    if (*param_2 == '\x01') {
      uVar3 = 3;
      uVar2 = param_1;
      goto LAB_2011804c;
    }
    iVar1 = r_vdc5_shrd_get_resource(param_1,4);
  }
  if (iVar1 == 0) {
    return 0xe;
  }
LAB_2011801c:
  FUN_2011bc8c(param_1,param_2);
  return 0;
}


// ===== r_vdc5_image_enhancement @ 20118054 (140 bytes)

/* (ch, imgimprv id 0/1, sharpness, area): resource 3 or 4 (error 14/8) [inference] */

undefined4
r_vdc5_image_enhancement
          (undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5,
          undefined4 param_6,undefined4 param_7)

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
  iVar1 = r_vdc5_shrd_get_resource(param_1,uVar2);
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


// ===== r_vdc5_image_black_stretch @ 201180e0 (108 bytes)

/* (ch, imgimprv id, param): resource 3 or 4 [inference] */

undefined4
r_vdc5_image_black_stretch(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

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
  iVar1 = r_vdc5_shrd_get_resource(param_1,uVar2);
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


// ===== r_vdc5_alpha_blending @ 2011814c (80 bytes)

/* (ch, layer, param): graphics index from vdc5_layer_to_gr, resource check (error 14) [inference]
    */

undefined4 r_vdc5_alpha_blending(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = r_vdc5_shrd_get_resource(param_1,param_2);
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

uint r_vdc5_alpha_blending_rect(uint param_1,int param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  if (param_2 != 7) {
    iVar2 = r_vdc5_shrd_get_resource(param_1,param_2);
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

uint r_vdc5_chromakey(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = r_vdc5_shrd_get_resource(param_1,param_2);
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


// ===== r_vdc5_clut @ 20118284 (80 bytes)

/* (ch, layer, param): same checks, CLUT write [inference: API order after chromakey] */

undefined4 r_vdc5_clut(undefined4 param_1,uint param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  
  uVar1 = vdc5_layer_to_gr(param_2);
  uVar3 = 0;
  iVar2 = r_vdc5_shrd_get_resource(param_1,param_2);
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

byte r_vdc5_display_calibration(uint param_1,uint param_2)

{
  int iVar1;
  byte bVar2;
  
  bVar2 = 0;
  iVar1 = vdc5_shrd_get_state(param_1,3);
  if (iVar1 == 1) {
    FUN_2011c6ec(param_1,param_2);
  }
  else {
    bVar2 = 0xc;
  }
  return bVar2;
}


// ===== r_vdc5_gamma_correction @ 2011830c (64 bytes)

/* (ch, on, param): needs state 3 (error 12) [inference: API order after display_calibration] */

undefined4 r_vdc5_gamma_correction(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  undefined4 uVar2;
  
  uVar2 = 0;
  iVar1 = vdc5_shrd_get_state(param_1,3);
  if (iVar1 == 1) {
    FUN_2011c950(param_1,param_2,param_3);
  }
  else {
    uVar2 = 0xc;
  }
  return uVar2;
}


// ===== r_vdc5_get_isr @ 2011834c (24 bytes)

/* (ch, type): ISR pointer from table 0x20165A74, 23 per channel (the vdc5_chN_isr_* handlers) [fact
   for the table; inference for the API name] */

undefined * r_vdc5_get_isr(int param_1,int param_2)

{
  return (&PTR_vdc5_ch0_isr_s0_vi_vsync_20165a74)[param_1 * 0x17 + param_2];
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
    *(undefined2 *)(&PTR_VDC50_SC0_SCL0_INT_20165d08)[param_1 * 0x8a] = *(undefined2 *)(param_2 + 8)
    ;
    *puVar2 = *puVar2 | 1;
    return;
  }
  if (bVar1 != 0x10) {
    if (bVar1 == 0x13) {
      puVar2 = (uint *)(&PTR_VDC50_GR_OIR_CLUT_201664c8)[param_1 * 0x84];
      puVar3 = (uint *)(&PTR_VDC50_GR_OIR_UPDATE_20166478)[param_1 * 0x84];
      *puVar2 = *puVar2 & 0xfffff800;
      *puVar2 = (uint)*(ushort *)(param_2 + 8) | *puVar2;
      *puVar3 = *puVar3 | 0x10;
    }
    return;
  }
  puVar2 = *(uint **)(&DAT_20165d98 + param_1 * 0x228);
  *(undefined2 *)(&PTR_VDC50_SC1_SCL0_INT_20165dc0)[param_1 * 0x8a] = *(undefined2 *)(param_2 + 8);
  *puVar2 = *puVar2 | 1;
  return;
}


// ===== vdc5_ch0_isr_s0_vi_vsync @ 20118548 (80 bytes)

/* VDC5 ch0 interrupt 0: enabled in VDC50_SYSCNT_INT4 bit 0 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC0C with type 0 [fact]; type = VDC5_INT_TYPE_S0_VI_VSYNC
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s0_vi_vsync(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 1) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 1) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xfffffffe;
    if (DAT_208dcc0c != (code *)0x0) {
      (*DAT_208dcc0c)(0);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s0_lo_vsync @ 20118598 (80 bytes)

/* VDC5 ch0 interrupt 1: enabled in VDC50_SYSCNT_INT4 bit 4 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC10 with type 1 [fact]; type = VDC5_INT_TYPE_S0_LO_VSYNC
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s0_lo_vsync(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 0x10) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 0x10) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xffffffef;
    if (DAT_208dcc10 != (code *)0x0) {
      (*DAT_208dcc10)(1);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s0_vsyncerr @ 201185e8 (80 bytes)

/* VDC5 ch0 interrupt 2: enabled in VDC50_SYSCNT_INT4 bit 8 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC14 with type 2 [fact]; type = VDC5_INT_TYPE_S0_VSYNCERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s0_vsyncerr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 0x100) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 0x100) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xfffffeff;
    if (DAT_208dcc14 != (code *)0x0) {
      (*DAT_208dcc14)(2);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_gr3_vline @ 20118638 (80 bytes)

/* VDC5 ch0 interrupt 3: enabled in VDC50_SYSCNT_INT4 bit 12 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC18 with type 3 [fact]; type = VDC5_INT_TYPE_GR3_VLINE of
   the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_gr3_vline(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 0x1000) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 0x1000) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xffffefff;
    if (DAT_208dcc18 != (code *)0x0) {
      (*DAT_208dcc18)(3);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s0_vfield @ 20118688 (80 bytes)

/* VDC5 ch0 interrupt 4: enabled in VDC50_SYSCNT_INT4 bit 16 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC1C with type 4 [fact]; type = VDC5_INT_TYPE_S0_VFIELD of
   the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s0_vfield(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 0x10000) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 0x10000) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xfffeffff;
    if (DAT_208dcc1c != (code *)0x0) {
      (*DAT_208dcc1c)(4);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_iv1_vbuferr @ 201186d8 (80 bytes)

/* VDC5 ch0 interrupt 5: enabled in VDC50_SYSCNT_INT4 bit 20 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC20 with type 5 [fact]; type = VDC5_INT_TYPE_IV1_VBUFERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_iv1_vbuferr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 0x100000) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 0x100000) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xffefffff;
    if (DAT_208dcc20 != (code *)0x0) {
      (*DAT_208dcc20)(5);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_iv3_vbuferr @ 20118728 (80 bytes)

/* VDC5 ch0 interrupt 6: enabled in VDC50_SYSCNT_INT4 bit 24 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC24 with type 6 [fact]; type = VDC5_INT_TYPE_IV3_VBUFERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_iv3_vbuferr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 0x1000000) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 0x1000000) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xfeffffff;
    if (DAT_208dcc24 != (code *)0x0) {
      (*DAT_208dcc24)(6);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_iv5_vbuferr @ 20118778 (80 bytes)

/* VDC5 ch0 interrupt 7: enabled in VDC50_SYSCNT_INT4 bit 28 and pending in SYSCNT_INT1: clears the
   status bit, calls callback slot 0x208DCC28 with type 7 [fact]; type = VDC5_INT_TYPE_IV5_VBUFERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_iv5_vbuferr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT4;
  if (((uVar2 & 0x10000000) != 0) && (uVar1 = VDC50_SYSCNT_INT1, (uVar1 & 0x10000000) != 0)) {
    VDC50_SYSCNT_INT1 = uVar2 & 0xefffffff;
    if (DAT_208dcc28 != (code *)0x0) {
      (*DAT_208dcc28)(7);
    }
    VDC50_SYSCNT_INT1 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_iv6_vbuferr @ 201187c8 (80 bytes)

/* VDC5 ch0 interrupt 8: enabled in VDC50_SYSCNT_INT5 bit 0 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC2C with type 8 [fact]; type = VDC5_INT_TYPE_IV6_VBUFERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_iv6_vbuferr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 1) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 1) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xfffffffe;
    if (DAT_208dcc2c != (code *)0x0) {
      (*DAT_208dcc2c)(8);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s0_wline @ 20118818 (80 bytes)

/* VDC5 ch0 interrupt 9: enabled in VDC50_SYSCNT_INT5 bit 4 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC30 with type 9 [fact]; type = VDC5_INT_TYPE_S0_WLINE of
   the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s0_wline(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 0x10) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 0x10) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xffffffef;
    if (DAT_208dcc30 != (code *)0x0) {
      (*DAT_208dcc30)(9);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s1_vi_vsync @ 20118868 (80 bytes)

/* VDC5 ch0 interrupt 10: enabled in VDC50_SYSCNT_INT5 bit 8 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC34 with type 10 [fact]; type = VDC5_INT_TYPE_S1_VI_VSYNC
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s1_vi_vsync(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 0x100) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 0x100) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xfffffeff;
    if (DAT_208dcc34 != (code *)0x0) {
      (*DAT_208dcc34)(10);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s1_lo_vsync @ 201188b8 (80 bytes)

/* VDC5 ch0 interrupt 11: enabled in VDC50_SYSCNT_INT5 bit 12 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC38 with type 11 [fact]; type = VDC5_INT_TYPE_S1_LO_VSYNC
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s1_lo_vsync(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 0x1000) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 0x1000) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xffffefff;
    if (DAT_208dcc38 != (code *)0x0) {
      (*DAT_208dcc38)(0xb);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s1_vsyncerr @ 20118908 (80 bytes)

/* VDC5 ch0 interrupt 12: enabled in VDC50_SYSCNT_INT5 bit 16 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC3C with type 12 [fact]; type = VDC5_INT_TYPE_S1_VSYNCERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s1_vsyncerr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 0x10000) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 0x10000) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xfffeffff;
    if (DAT_208dcc3c != (code *)0x0) {
      (*DAT_208dcc3c)(0xc);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s1_vfield @ 20118958 (80 bytes)

/* VDC5 ch0 interrupt 13: enabled in VDC50_SYSCNT_INT5 bit 20 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC40 with type 13 [fact]; type = VDC5_INT_TYPE_S1_VFIELD of
   the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s1_vfield(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 0x100000) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 0x100000) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xffefffff;
    if (DAT_208dcc40 != (code *)0x0) {
      (*DAT_208dcc40)(0xd);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_iv2_vbuferr @ 201189a8 (80 bytes)

/* VDC5 ch0 interrupt 14: enabled in VDC50_SYSCNT_INT5 bit 24 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC44 with type 14 [fact]; type = VDC5_INT_TYPE_IV2_VBUFERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_iv2_vbuferr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 0x1000000) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 0x1000000) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xfeffffff;
    if (DAT_208dcc44 != (code *)0x0) {
      (*DAT_208dcc44)(0xe);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_iv4_vbuferr @ 201189f8 (80 bytes)

/* VDC5 ch0 interrupt 15: enabled in VDC50_SYSCNT_INT5 bit 28 and pending in SYSCNT_INT2: clears the
   status bit, calls callback slot 0x208DCC48 with type 15 [fact]; type = VDC5_INT_TYPE_IV4_VBUFERR
   of the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_iv4_vbuferr(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT5;
  if (((uVar2 & 0x10000000) != 0) && (uVar1 = VDC50_SYSCNT_INT2, (uVar1 & 0x10000000) != 0)) {
    VDC50_SYSCNT_INT2 = uVar2 & 0xefffffff;
    if (DAT_208dcc48 != (code *)0x0) {
      (*DAT_208dcc48)(0xf);
    }
    VDC50_SYSCNT_INT2 = uVar2;
  }
  return;
}


// ===== vdc5_ch0_isr_s1_wline @ 20118a48 (80 bytes)

/* VDC5 ch0 interrupt 16: enabled in VDC50_SYSCNT_INT6 bit 0 and pending in SYSCNT_INT3: clears the
   status bit, calls callback slot 0x208DCC4C with type 16 [fact]; type = VDC5_INT_TYPE_S1_WLINE of
   the Renesas r_vdc5 enum, 0x20118638 = ch0 GR3_VLINE as in gui.md [inference] */

void vdc5_ch0_isr_s1_wline(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = VDC50_SYSCNT_INT6;
  if (((uVar2 & 1) != 0) && (uVar1 = VDC50_SYSCNT_INT3, (uVar1 & 1) != 0)) {
    VDC50_SYSCNT_INT3 = uVar2 & 0xfffffffe;
    if (DAT_208dcc4c != (code *)0x0) {
      (*DAT_208dcc4c)(0x10);
    }
    VDC50_SYSCNT_INT3 = uVar2;
  }
  return;
}

