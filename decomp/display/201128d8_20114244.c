// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== adc_hysteresis @ 201128d8 (28 bytes)

/* keep the old value unless it moved by more than 7 */

int adc_hysteresis(int param_1,int param_2,int param_3)

{
  if (0xe < (param_2 - param_1) + 7U) {
    param_3 = param_1;
  }
  return param_3;
}


// ===== task_ad_renc @ 201128f4 (120 bytes)

void task_ad_renc(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_20 [32];
  
  uVar3 = 0;
  FUN_20155274(&DAT_208d9a08,0x20);
  FUN_20155274(&DAT_208d99c8,0x20);
  do {
    do {
      FUN_201525f8(0xffffffff);
      adc_read_all(auStack_20);
      uVar1 = auStack_20._0_4_;
      adc_read_all(auStack_20);
      (&DAT_208d9a08)[uVar3] = (short)uVar1;
      (&DAT_208d99c8)[uVar3] = (short)auStack_20._4_4_;
      uVar2 = uVar3 + 1;
      uVar3 = uVar2 & 0x1f;
    } while ((int)uVar2 <= (int)DAT_208001f4);
    DAT_208001f4 = uVar2;
  } while( true );
}


// ===== pot_detect @ 2011296c (360 bytes)

/* AN0/AN1 averages -> 8-bit pot values (ids 5/4) after 2 changed polls */

void pot_detect(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  
  uVar4 = adc_ring_average(&DAT_208d9a08);
  FUN_20164888((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
  uVar1 = FUN_20164cf0();
  uVar4 = adc_ring_average(&DAT_208d99c8);
  FUN_20164888((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
  uVar2 = FUN_20164cf0();
  uVar3 = adc_hysteresis(uVar1,DAT_208001ea,DAT_208001ee);
  DAT_208001f0 = adc_hysteresis(uVar2,DAT_208001ec,DAT_208001f0);
  DAT_2080020e = uVar1 >> 4;
  DAT_20800208 = uVar2 >> 4;
  DAT_208001ea = uVar1;
  DAT_208001ec = uVar2;
  DAT_208001ee = uVar3;
  if ((DAT_20800208 != DAT_2080020a) &&
     (DAT_208001e5 = DAT_208001e5 + '\x01', DAT_208001e5 == '\x02')) {
    if ((DAT_208001e7 != '\0') && (renc_rec_set(4,(int)(char)DAT_20800208), DAT_20800495 != '\0')) {
      mainlink_renc_event(&DAT_208d99b8);
    }
    DAT_208001e7 = '\x01';
    DAT_2080020a = DAT_20800208;
    DAT_208001e5 = '\0';
  }
  if ((DAT_2080020e != DAT_20800210) &&
     (DAT_208001e6 = DAT_208001e6 + '\x01', DAT_208001e6 == '\x02')) {
    if ((DAT_208001e8 != '\0') && (renc_rec_set(5,(int)(char)DAT_2080020e), DAT_20800495 != '\0')) {
      mainlink_renc_event(&DAT_208d99bd);
    }
    DAT_208001e8 = '\x01';
    DAT_20800210 = DAT_2080020e;
    DAT_208001e6 = '\0';
  }
  return;
}


// ===== task_detect_renc @ 20112ad4 (24 bytes)

void task_detect_renc(void)

{
  do {
    FUN_201525f8(0xffffffff);
    pot_detect();
    renc_poll_mtu1();
    renc_poll_mtu2();
  } while( true );
}


// ===== renc_mtu2_init @ 20112aec (84 bytes)

/* MTU2 ch1 phase-count mode 1, ch2 mode 4, start CST1/CST2 */

void renc_mtu2_init(void)

{
  byte bVar1;
  
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 & 0xfd;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 & 0xfb;
  DAT_fcff0381 = 4;
  DAT_fcff0386 = 0;
  DAT_fcff0001 = 7;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 4;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 2;
  return;
}


// ===== renc_irq4_isr @ 20112b40 (120 bytes)

/* IRQ4 (both edges): P3_3 vs P3_5 -> +-1, encoder id 3 */

void renc_irq4_isr(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  char cVar4;
  undefined4 extraout_r2;
  
  gic_disable_irq(0x24);
  uVar1 = DAT_fcfe320c;
  uVar2 = DAT_fcfe320c;
  if ((uVar1 & 0xf) >> 3 == (uVar2 & 0x3f) >> 5) {
    cVar4 = -1;
  }
  else {
    cVar4 = '\x01';
  }
  DAT_208001e4 = DAT_208001e4 + cVar4;
  renc_rec_set(3);
  uVar1 = DAT_fcfef804;
  if ((uVar1 & 0x10) != 0) {
    uVar1 = DAT_fcfef804;
    DAT_fcfef804 = uVar1 & 0xffef;
  }
  uVar3 = DAT_fcfef804;
  itron_set_flg(DAT_208001f8,1,extraout_r2,uVar3);
  return;
}


// ===== renc_init @ 20112bb8 (268 bytes)

/* tasks "renc", "ad renc", "detect renc" */

void renc_init(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_r2;
  undefined8 uVar5;
  undefined2 uVar7;
  undefined4 uVar6;
  
  FUN_201637d8(&DAT_20800208,0xff,param_3,param_4,param_4);
  uVar7 = (undefined2)((uint)param_4 >> 0x10);
  FUN_201637d8(&DAT_2080020e,0xff);
  DAT_208001f8 = itron_acre_flg(0,&DAT_201655e8);
  if (((0 < DAT_208001f8) && (iVar3 = itron_acre_tsk(0,&DAT_201655cc), 0 < iVar3)) &&
     (iVar3 = itron_sta_tsk(iVar3,0), iVar3 == 0)) {
    renc_mtu2_init();
    iVar3 = itron_acre_tsk(0,&DAT_20165594);
    if ((0 < iVar3) && (iVar4 = itron_sta_tsk(iVar3,0), iVar4 == 0)) {
      periodic_wakeup_register(iVar3,1);
      iVar3 = itron_acre_tsk(0,&DAT_201655b0);
      if ((0 < iVar3) && (iVar4 = itron_sta_tsk(iVar3,0), iVar4 == 0)) {
        periodic_wakeup_register(iVar3,2);
        uVar1 = DAT_fcfef802;
        DAT_fcfef802 = uVar1 & 0xfcff;
        uVar2 = DAT_fcfef802;
        uVar6 = CONCAT22(uVar7,uVar2);
        uVar1 = DAT_fcfef802;
        DAT_fcfef802 = uVar1 | 0x300;
        uVar5 = itron_acre_isr(0,&DAT_20165580);
        if (0 < (int)uVar5) {
          gic_enable_irq(0x24,(int)((ulonglong)uVar5 >> 0x20),extraout_r2,uVar6);
          return;
        }
      }
    }
  }
  return;
}


// ===== pot_resend_all @ 20112cc4 (136 bytes)

/* re-send pot ids 4/5 when the GUI link comes up */

void pot_resend_all(void)

{
  int iVar1;
  
  iVar1 = FUN_201309b4();
  if (iVar1 == 0) {
    if ((DAT_208001e7 != '\0') || (DAT_208001e5 == '\x01')) {
      renc_rec_set(4,(int)(char)DAT_20800208);
      mainlink_renc_event(&DAT_208d99b8);
    }
    if ((DAT_208001e8 != '\0') || (DAT_208001e6 == '\x01')) {
      renc_rec_set(5,(int)(char)DAT_2080020e);
      mainlink_renc_event(&DAT_208d99bd);
      return;
    }
  }
  return;
}


// ===== hid_usage_to_ascii @ 20112da4 (184 bytes)

/* HID usage -> ASCII for the debug line editor (lowercase, JIS '=' on Shift+'-') */

int hid_usage_to_ascii(undefined4 param_1,int param_2,uint param_3)

{
  int iVar1;
  
  if (param_2 - 0x1eU < 9) {
    return param_2 + 0x13;
  }
  if (param_2 != 0x27) {
    if (param_2 - 4U < 0x1a) {
      return param_2 + 0x5d;
    }
    if (param_2 - 0x59U < 9) {
      return param_2 + -0x30;
    }
    if (param_2 != 0x62) {
      if (param_2 == 0x87) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x5c;
        }
        else {
          iVar1 = 0x5f;
        }
        return iVar1;
      }
      if (param_2 == 0x2d) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2d;
        }
        else {
          iVar1 = 0x3d;
        }
        return iVar1;
      }
      if (param_2 == 0x37) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2e;
        }
        else {
          iVar1 = 0x3e;
        }
        return iVar1;
      }
      if (param_2 == 0x38) {
        if ((param_3 & 0x22) == 0) {
          iVar1 = 0x2f;
        }
        else {
          iVar1 = 0x3f;
        }
        return iVar1;
      }
      if (param_2 == 0x2c) {
        iVar1 = 0x20;
      }
      else {
        iVar1 = -1;
      }
      return iVar1;
    }
  }
  return 0x30;
}


// ===== hid_line_edit @ 20112e5c (216 bytes)

/* HID-usage line editor: 0x28/0x58 Enter, 0x29 Esc, 0x2A Backspace, max 31 chars */

int * hid_line_edit(int *param_1,undefined4 param_2,int param_3)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint *extraout_r3;
  
  iVar3 = 0;
  for (iVar2 = 0; (iVar2 < *(int *)(param_3 + 8) && (*(char *)(param_3 + iVar2 + 0xc) != '\0'));
      iVar2 = iVar2 + 1) {
    iVar3 = iVar3 + 1;
  }
  if (1 < iVar3) {
    return (int *)0x0;
  }
  cVar1 = *(char *)(param_3 + 0xc);
  if (cVar1 == '\0' && *(char *)(param_3 + 5) == '\0') {
    return (int *)0x0;
  }
  iVar2 = 0;
  if (cVar1 != '(' && cVar1 != 'X') {
    if (cVar1 != ')') {
      if (cVar1 != '*') {
        iVar2 = hid_usage_to_ascii(param_1);
        if (iVar2 < 0) {
          return (int *)0x0;
        }
        uVar4 = *extraout_r3;
        if (0x1e < uVar4) {
          return (int *)0x0;
        }
        *extraout_r3 = uVar4 + 1;
        *(char *)((int)extraout_r3 + uVar4 + 4) = (char)iVar2;
        return (int *)0x0;
      }
      if (*param_1 < 1) {
        return (int *)0x0;
      }
      iVar2 = *param_1 + -1;
    }
    *param_1 = iVar2;
    return (int *)0x0;
  }
  *(undefined1 *)((int)param_1 + *param_1 + 4) = 0;
  *param_1 = 0;
  return param_1 + 1;
}


// ===== key_held_list_update @ 20112f3c (164 bytes)

/* replace old code by new in the 4-entry held-key list 0x2080023C (0 = add/remove) */

void key_held_list_update(uint param_1,uint param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  
  bVar1 = true;
  iVar3 = 0;
  if (param_2 == 0) {
    do {
      if ((ushort)(&DAT_2080023c)[iVar3] == param_1) {
        (&DAT_2080023c)[iVar3] = 0;
        return;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    return;
  }
  iVar3 = 0;
  do {
    if ((ushort)(&DAT_2080023c)[iVar3] == param_1) {
      iVar2 = 0;
      do {
        if ((ushort)(&DAT_2080023c)[iVar2] == param_2) {
          bVar1 = false;
          goto LAB_20112fcc;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < 4);
      if (bVar1) {
        (&DAT_2080023c)[iVar3] = (ushort)param_2;
      }
    }
LAB_20112fcc:
    iVar3 = iVar3 + 1;
    if (3 < iVar3) {
      return;
    }
  } while( true );
}


// ===== key_combo_match @ 20112fe0 (200 bytes)

/* boot key combination n (table 0x20165678, 3 codes each) held? 2 or 3 keys */

bool key_combo_match(int param_1)

{
  int iVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  bool bVar6;
  
  bVar6 = false;
  iVar3 = 0;
  switch(param_1) {
  default:
    iVar5 = 4;
    break;
  case 1:
  case 3:
  case 4:
  case 5:
  case 7:
    iVar5 = 3;
  }
  iVar4 = 0;
  if (iVar5 != 0) {
    iVar1 = param_1 * 6;
    do {
      sVar2 = (&DAT_2080023c)[iVar4];
      if (sVar2 == 0) break;
      if ((sVar2 == *(short *)(&DAT_20165678 + iVar1)) ||
         (sVar2 == *(short *)(&DAT_2016567a + iVar1))) {
        iVar3 = iVar3 + 1;
      }
      if ((param_1 == 2 || param_1 == 6) && (sVar2 == *(short *)(&DAT_2016567c + iVar1))) {
        iVar3 = iVar3 + 1;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < iVar5);
  }
  if (((param_1 == 2 || param_1 == 6) ||
      (bVar6 = iVar3 == 2, (param_1 == 0 || param_1 == 2) || param_1 == 6)) && (iVar3 == 3)) {
    bVar6 = true;
  }
  return bVar6;
}


// ===== key_scan_first @ 201130c8 (60 bytes)

/* first of 8 key lines that reads active (0..7) */

byte key_scan_first(void)

{
  byte bVar1;
  int iVar2;
  
  bVar1 = 0;
  do {
    iVar2 = key_combo_match(bVar1);
    if (iVar2 != 0) {
      return bVar1;
    }
    bVar1 = bVar1 + 1;
  } while (bVar1 < 8);
  return 0;
}


// ===== key_matrix_press_check @ 20113104 (164 bytes)

/* matrix press pass (subset of task_key) */

void key_matrix_press_check(void)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar2 = 0;
    do {
      uVar1 = (&DAT_20165626)[iVar3 * 4 + iVar2];
      if (((&DAT_208d9a60)[iVar3 * 4 + iVar2] == 1) && ((&DAT_208d9b10)[iVar3 * 4 + iVar2] == 0)) {
        if (DAT_20800214 != '\0') {
          DAT_20800214 = '\0';
          (&DAT_208d9b68)[iVar3 * 4 + iVar2] = (&DAT_208d9b68)[iVar3 * 4 + iVar2] + 1;
          (&DAT_208d9ab8)[iVar3 * 4 + iVar2] = 1;
        }
        key_held_list_update(0,uVar1);
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 4);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 4);
  return;
}


// ===== key_set_power_level @ 201131a8 (12 bytes)

/* powon task stores the P2_0 level as direct key 0 (0x300 LOCK/PWR) */

void key_set_power_level(undefined4 param_1)

{
  DAT_208d9af8 = param_1;
  return;
}


// ===== adc_key_level @ 201131b4 (52 bytes)

/* 8-bit ADC value -> level 0..5 (count of thresholds below it) */

void adc_key_level(uint param_1,int param_2)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  iVar2 = 0;
  do {
    if (param_1 < *(ushort *)(param_2 + uVar1 * 2)) {
      return;
    }
    iVar2 = iVar2 + 1;
    uVar1 = uVar1 + 1 & 0xff;
  } while (iVar2 < 5);
  return;
}


// ===== gpio_read_port_bit @ 201131e8 (136 bytes)

/* read PPRn bit for ports 2,3,7,8,9,10 */

undefined4 gpio_read_port_bit(undefined4 param_1,uint param_2)

{
  uint uVar1;
  ushort uVar2;
  
  uVar1 = 1 << (param_2 & 0xff);
  switch(param_1) {
  case 2:
    uVar2 = DAT_fcfe3208;
    break;
  case 3:
    uVar2 = DAT_fcfe320c;
    break;
  default:
    goto switchD_20113204_caseD_4;
  case 7:
    uVar2 = DAT_fcfe321c;
    break;
  case 8:
    uVar2 = DAT_fcfe3220;
    break;
  case 9:
    uVar2 = DAT_fcfe3224;
    break;
  case 10:
    uVar2 = DAT_fcfe3228;
    if ((uVar2 & uVar1) != 0) {
      return 1;
    }
    return 0;
  }
  if ((uVar2 & uVar1) != 0) {
    return 1;
  }
switchD_20113204_caseD_4:
  return 0;
}


// ===== mainlink_send_key @ 20113294 (512 bytes)

/* E0 key event from the key task (or E4/E5 to leave a MAIN-driven screen) */

void mainlink_send_key(undefined4 param_1,undefined1 param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  undefined4 local_20;
  undefined4 uStack_1c;
  undefined4 local_18;
  
  puVar2 = &local_20;
  uStack_1c = 0;
  local_20 = CONCAT13((char)param_1,CONCAT12((char)((uint)param_1 >> 8),CONCAT11(param_2,0xe0)));
  iVar1 = FUN_20116dac();
  if (iVar1 == 0) goto LAB_20113460;
  if (DAT_20800495 == '\0') {
    if (local_20._1_1_ == '\0') {
      if (local_20._2_1_ != '\x03') goto LAB_20113460;
LAB_2011343c:
      if (local_20._3_1_ != '\x0f') goto LAB_20113460;
    }
    else {
      if (local_20._2_1_ != '\x03') goto LAB_20113460;
      if (local_20._3_1_ != '\0') goto LAB_2011343c;
    }
    iVar1 = mainlink_got_frame60();
    if (iVar1 == 0) goto LAB_20113460;
    uVar3 = 5;
  }
  else {
    if ((DAT_208f0b2a != '{') || (DAT_208f0b2b == '\0')) {
      if ((DAT_2080049f == '\0') || (DAT_20450034 == '|')) {
        if (DAT_20800219 == '\0') {
          if (local_20._1_1_ == '\0') {
            if ((local_20._2_1_ == '\x03') && (local_20._3_1_ == '\0')) {
              if (DAT_20800216 == '\0') {
                return;
              }
              DAT_20800216 = '\0';
            }
          }
          else if ((local_20._2_1_ == '\x03') && (local_20._3_1_ == '\0')) {
            DAT_20800216 = '\x01';
          }
        }
        else {
          if (local_20._1_1_ != '\x02') {
            DAT_20800219 = 0;
            return;
          }
          DAT_20800219 = '\x01';
          if (local_20._2_1_ != '\x03') {
            DAT_20800219 = 1;
            return;
          }
          if (local_20._3_1_ != '\0') {
            DAT_20800219 = 1;
            return;
          }
        }
        mainlink_queue_frame(&local_20,5);
      }
      else {
        local_18 = 0xe5;
        mainlink_queue_frame(&local_18,4);
        DAT_2080049f = '\0';
        DAT_20800219 = '\x01';
      }
      goto LAB_20113460;
    }
    local_18 = CONCAT31(local_18._1_3_,0xe4);
    if (DAT_20800218 == '\0') goto LAB_20113460;
    uVar3 = 4;
    DAT_20800218 = '\0';
    DAT_20800488 = 1;
    puVar2 = &local_18;
  }
  mainlink_queue_frame(puVar2,uVar3);
LAB_20113460:
  if (((local_20._1_1_ == '\x02') && (local_20._2_1_ == '\x03')) && (local_20._3_1_ == '\0')) {
    DAT_20800216 = 0;
    FUN_2011722c();
    return;
  }
  return;
}


// ===== key_matrix_drive_col @ 201134d0 (80 bytes)

/* drive one of P8_1/P8_2/P8_7/P8_8 low, the other three high */

void key_matrix_drive_col(int param_1)

{
  int iVar1;
  undefined4 local_20 [4];
  
  iVar1 = 0;
  local_20[0] = 1;
  local_20[1] = 2;
  local_20[2] = 7;
  local_20[3] = 8;
  do {
    if (iVar1 == param_1) {
      gpio_cfg_out_low();
    }
    else {
      gpio_cfg_out_high(8,local_20[iVar1]);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 4);
  return;
}


// ===== key_sample_all @ 20113558 (188 bytes)

/* sample 5 direct keys, PTT, 4x4 matrix, ADC AN3/AN4 */

void key_sample_all(void)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined1 auStack_38 [12];
  int local_2c;
  int local_28;
  
  iVar2 = 1;
  do {
    uVar1 = gpio_read_port_bit(*(undefined4 *)(&DAT_208002a4 + iVar2 * 0x10),
                               *(undefined4 *)(iVar2 * 0x10 + 0x208002a8));
    (&DAT_208d9af8)[iVar2] = uVar1;
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  DAT_20800230 = gpio_read_port_bit(DAT_20800304,DAT_20800308);
  iVar2 = 0;
  do {
    key_matrix_drive_col(iVar2);
    iVar3 = 0;
    do {
      uVar1 = gpio_read_port_bit((&DAT_20800244)[iVar3 * 6],(&DAT_20800248)[iVar3 * 6]);
      iVar4 = iVar3 + 1;
      (&DAT_208d9b10)[iVar3 * 4 + iVar2] = uVar1;
      iVar3 = iVar4;
    } while (iVar4 < 4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  adc_read_all(auStack_38);
  DAT_2080021e = (undefined2)((uint)(local_2c << 0xc) >> 0x10);
  adc_read_all(auStack_38);
  DAT_20800220 = (short)((uint)(local_28 << 0xc) >> 0x10);
  return;
}


// ===== key_debounce_all @ 20113614 (540 bytes)

/* 3 equal samples -> changed flags; ADC pair -> code index 0x2080021A */

void key_debounce_all(void)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  
  iVar2 = 0;
  do {
    if ((0 < (int)(&DAT_208d9ba8)[iVar2]) && ((&DAT_208002ac)[iVar2 * 4] == (&DAT_208d9af8)[iVar2]))
    {
      (&DAT_208d9ba8)[iVar2] = (&DAT_208d9ba8)[iVar2] + 1;
    }
    if ((&DAT_208002ac)[iVar2 * 4] == (&DAT_208d9af8)[iVar2]) {
      if (2 < (int)(&DAT_208d9ba8)[iVar2]) {
        (&DAT_208d9a48)[iVar2] = 1;
        (&DAT_208d9ba8)[iVar2] = 0;
      }
    }
    else {
      (&DAT_208d9ba8)[iVar2] = 1;
      (&DAT_208002ac)[iVar2 * 4] = (&DAT_208d9af8)[iVar2];
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 6);
  if ((0 < DAT_20800238) && (DAT_2080030c == DAT_20800230)) {
    DAT_20800238 = DAT_20800238 + 1;
  }
  if (DAT_2080030c == DAT_20800230) {
    if (2 < DAT_20800238) {
      DAT_20800228 = 1;
      DAT_20800238 = 0;
    }
  }
  else {
    DAT_20800238 = 1;
    DAT_2080030c = DAT_20800230;
  }
  iVar2 = 0;
  do {
    iVar3 = 0;
    do {
      iVar6 = (&DAT_208d9bc0)[iVar2 * 4 + iVar3];
      if ((0 < iVar6) &&
         ((&DAT_208d9b10)[iVar2 * 4 + iVar3] == (&DAT_20800244)[iVar2 * 6 + iVar3 + 2])) {
        (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = iVar6 + 1;
      }
      iVar6 = (&DAT_208d9b10)[iVar2 * 4 + iVar3];
      if (iVar6 == (&DAT_20800244)[iVar2 * 6 + iVar3 + 2]) {
        if (2 < (int)(&DAT_208d9bc0)[iVar2 * 4 + iVar3]) {
          (&DAT_208d9a60)[iVar2 * 4 + iVar3] = 1;
          (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = 0;
        }
      }
      else {
        (&DAT_208d9bc0)[iVar2 * 4 + iVar3] = 1;
        (&DAT_20800244)[iVar2 * 6 + iVar3 + 2] = iVar6;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 4);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 4);
  uVar4 = adc_key_level((undefined1)DAT_2080021e,&DAT_20800314);
  uVar5 = adc_key_level((undefined1)DAT_20800220,&DAT_2080031e);
  iVar2 = 0;
  while (((byte)(&DAT_201655f4)[iVar2 * 2] != uVar4 || ((byte)(&DAT_201655f5)[iVar2 * 2] != uVar5)))
  {
    iVar2 = iVar2 + 1;
    if (0x18 < iVar2) {
      uVar4 = 0;
LAB_20113520:
      if (DAT_2080021b == uVar4) {
        bVar1 = (byte)uVar4;
        if (DAT_2080021c != '\x02') {
          DAT_2080021c = DAT_2080021c + '\x01';
          bVar1 = DAT_2080021a;
        }
      }
      else {
        DAT_2080021c = '\0';
        bVar1 = DAT_2080021a;
        DAT_2080021b = (byte)uVar4;
      }
      DAT_2080021a = bVar1;
      return;
    }
  }
  uVar4 = iVar2 + 1U & 0xff;
  goto LAB_20113520;
}


// ===== task_key @ 201137f8 (1140 bytes)

void task_key(void)

{
  short sVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  do {
    do {
      FUN_201525f8(0xffffffff);
    } while (DAT_20800217 != '\0');
    if ((DAT_208f0b2a == '{') && (DAT_208f0b2b != '\0')) {
      DAT_20800218 = 1;
    }
    key_sample_all();
    key_debounce_all();
    if (DAT_20800228 == 1) {
      if (DAT_20800230 == 0) {
        if (DAT_20800215 != '\0') {
          mainlink_send_key(DAT_20800310,1);
          DAT_20800215 = '\0';
          DAT_20800234 = DAT_20800234 + 1;
          DAT_2080022c = 1;
        }
      }
      else {
        mainlink_send_key(DAT_20800310,0);
        DAT_20800215 = '\x01';
        DAT_20800234 = 0;
        DAT_2080022c = 0;
      }
      DAT_20800228 = 0;
    }
    if (DAT_2080022c == 1) {
      if (DAT_20800234 < 1000) {
        DAT_20800234 = DAT_20800234 + 1;
        goto LAB_201138dc;
      }
LAB_201138e4:
      mainlink_send_key(DAT_20800310,2);
      DAT_20800234 = 0;
      DAT_2080022c = 0;
    }
    else {
LAB_201138dc:
      if (999 < DAT_20800234) goto LAB_201138e4;
    }
    iVar4 = 0;
    do {
      if ((&DAT_208d9a48)[iVar4] == 1) {
        if ((&DAT_208d9af8)[iVar4] == 0) {
          if ((DAT_20800214 != '\0') && (iVar2 = mouse_middle_is_func(), iVar2 == 0)) {
            mainlink_send_key((&DAT_208002b0)[iVar4 * 8],1);
            DAT_20800214 = '\0';
            (&DAT_208d9b50)[iVar4] = (&DAT_208d9b50)[iVar4] + 1;
            (&DAT_208d9aa0)[iVar4] = 1;
          }
          key_held_list_update(0,(&DAT_208002b0)[iVar4 * 8]);
        }
        else {
          if ((DAT_2080023c == (&DAT_208002b0)[iVar4 * 8]) && (DAT_20800214 == '\0')) {
            mainlink_send_key((&DAT_208002b0)[iVar4 * 8],0);
            DAT_20800214 = '\x01';
          }
          key_held_list_update((&DAT_208002b0)[iVar4 * 8],0);
          (&DAT_208d9b50)[iVar4] = 0;
          (&DAT_208d9aa0)[iVar4] = 0;
        }
        (&DAT_208d9a48)[iVar4] = 0;
      }
      iVar2 = (&DAT_208d9b50)[iVar4];
      if ((&DAT_208d9aa0)[iVar4] == 1) {
        if (iVar2 < 1000) {
          iVar2 = iVar2 + 1;
          (&DAT_208d9b50)[iVar4] = iVar2;
          goto LAB_201139f0;
        }
LAB_201139f8:
        mainlink_send_key((&DAT_208002b0)[iVar4 * 8],2);
        (&DAT_208d9b50)[iVar4] = 0;
        (&DAT_208d9aa0)[iVar4] = 0;
      }
      else {
LAB_201139f0:
        if (999 < iVar2) goto LAB_201139f8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 6);
    iVar4 = FUN_20116dac();
    if ((iVar4 != 0) || (DAT_2080049b != '\0')) {
      iVar4 = 0;
      do {
        iVar2 = 0;
        do {
          sVar1 = (&DAT_20165626)[iVar4 * 4 + iVar2];
          if ((&DAT_208d9a60)[iVar4 * 4 + iVar2] == 1) {
            if ((&DAT_208d9b10)[iVar4 * 4 + iVar2] == 0) {
              if (DAT_20800214 != '\0') {
                mainlink_send_key(sVar1,1);
                DAT_20800214 = '\0';
                (&DAT_208d9b68)[iVar4 * 4 + iVar2] = (&DAT_208d9b68)[iVar4 * 4 + iVar2] + 1;
                (&DAT_208d9ab8)[iVar4 * 4 + iVar2] = 1;
              }
              key_held_list_update(0,sVar1);
            }
            else {
              if (DAT_2080023c == sVar1) {
                mainlink_send_key(sVar1,0);
                DAT_20800214 = '\x01';
              }
              key_held_list_update(sVar1,0);
              (&DAT_208d9b68)[iVar4 * 4 + iVar2] = 0;
              (&DAT_208d9ab8)[iVar4 * 4 + iVar2] = 0;
            }
            (&DAT_208d9a60)[iVar4 * 4 + iVar2] = 0;
          }
          iVar3 = (&DAT_208d9b68)[iVar4 * 4 + iVar2];
          if ((&DAT_208d9ab8)[iVar4 * 4 + iVar2] == 1) {
            if (iVar3 < 1000) {
              iVar3 = iVar3 + 1;
              (&DAT_208d9b68)[iVar4 * 4 + iVar2] = iVar3;
              goto LAB_20113b38;
            }
LAB_20113b40:
            mainlink_send_key(sVar1,2);
            (&DAT_208d9b68)[iVar4 * 4 + iVar2] = 0;
            (&DAT_208d9ab8)[iVar4 * 4 + iVar2] = 0;
          }
          else {
LAB_20113b38:
            if (999 < iVar3) goto LAB_20113b40;
          }
          iVar2 = iVar2 + 1;
        } while (iVar2 < 4);
        iVar4 = iVar4 + 1;
      } while (iVar4 < 4);
      if (DAT_2080021a != 0) {
        if ((DAT_2080023c == (&DAT_20165644)[DAT_2080021a]) && (DAT_2080021c == '\0')) {
          mainlink_send_key((&DAT_20165644)[DAT_2080021a],0);
          DAT_20800214 = '\x01';
          key_held_list_update((&DAT_20165644)[DAT_2080021a],0);
          DAT_2080021a = 0;
          DAT_20800224 = 0;
        }
        if (DAT_2080021c == '\x02') {
          if ((DAT_20800214 != '\0') && (DAT_20800224 == 0)) {
            mainlink_send_key((&DAT_20165644)[DAT_2080021a],1);
            DAT_20800214 = '\0';
            key_held_list_update(0,(&DAT_20165644)[DAT_2080021a]);
          }
          if ((DAT_2080023c == (&DAT_20165644)[DAT_2080021a]) && (DAT_20800224 < 1000)) {
            DAT_20800224 = DAT_20800224 + 1;
          }
          if (DAT_20800224 == 1000) {
            mainlink_send_key((&DAT_20165644)[DAT_2080021a],2);
            DAT_20800224 = DAT_20800224 + 1;
          }
        }
      }
    }
  } while( true );
}


// ===== key_func_is_held @ 20113c6c (24 bytes)

/* direct key 3 (0x30F FUNC) is in its hold phase */

bool key_func_is_held(void)

{
  return DAT_208d9aac == 1;
}


// ===== key_init @ 20113c84 (68 bytes)

/* creates task "key" */

void key_init(void)

{
  int iVar1;
  int iVar2;
  
  key_set_power_level(1);
  iVar1 = itron_acre_tsk(0,&DAT_201656a8);
  if ((0 < iVar1) && (iVar2 = itron_sta_tsk(iVar1,0), iVar2 == 0)) {
    periodic_wakeup_register(iVar1,4);
    return;
  }
  return;
}


// ===== key_task_pause @ 20113d00 (16 bytes)

/* sets 0x20800217: task_key skips scans */

void key_task_pause(void)

{
  DAT_20800217 = 1;
  return;
}


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
  
  DAT_fcff0300 = 0x22;
  DAT_fcff0306 = 0;
  DAT_fcff0308 = 19999;
  DAT_fcff030a = 0;
  DAT_fcff030c = 0;
  DAT_fcff030e = 0;
  DAT_fcff0302 = 0x12;
  DAT_fcff0301 = 2;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 1;
  return;
}


// ===== dimmer_set_pct @ 20113d6c (76 bytes)

/* NEW ENTRY; duty = pct*20000/100 -> TGRB_0 */

void dimmer_set_pct(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = div10_round(param_1 * 20000,param_1 * 20000 >> 0x1f);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 20000) {
    iVar1 = 19999;
  }
  DAT_fcff030a = (short)iVar1 + -1;
  return;
}


// ===== dimmer_set @ 20113db8 (8 bytes)

/* thunk: dimmer_set_pct */

void dimmer_set(int param_1)

{
  int iVar1;
  
  if (param_1 < 0) {
    param_1 = 0;
  }
  else if (99 < param_1) {
    param_1 = 100;
  }
  iVar1 = div10_round(param_1 * 20000,param_1 * 20000 >> 0x1f);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 20000) {
    iVar1 = 19999;
  }
  DAT_fcff030a = (short)iVar1 + -1;
  return;
}


// ===== dimmer_init @ 20113dc0 (24 bytes)

/* WARNING: Removing unreachable block (ram,0x20113d74) */
/* WARNING: Removing unreachable block (ram,0x20113d80) */
/* dimmer_pwm_init + 60 % */

void dimmer_init(void)

{
  int iVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r3;
  undefined4 unaff_r4;
  undefined4 unaff_lr;
  
  dimmer_pwm_init();
  iVar1 = div10_round(1200000,0,extraout_r2,extraout_r3,unaff_r4,unaff_lr);
  iVar1 = div10_round(iVar1,iVar1 >> 0x1f);
  if (iVar1 == 20000) {
    iVar1 = 19999;
  }
  DAT_fcff030a = (short)iVar1 + -1;
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
  int iVar1;
  
  memclr(&DAT_208d9c40,0x5a0);
  DAT_20800330 = FUN_2015f040(&DAT_208d9c40);
  iVar1 = itron_acre_tsk(0,&DAT_201656e4);
  if (0 < iVar1) {
    itron_sta_tsk(iVar1,DAT_20800330);
    return;
  }
  return;
}


// ===== mouse_attach_post @ 20113e4c (96 bytes)

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
  FUN_20162d3c(DAT_20800330 + 4,*(undefined4 *)(DAT_20800330 + 0x590),iVar1);
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
  FUN_20162d3c(DAT_20800330 + 4,*(undefined4 *)(DAT_20800330 + 0x590),iVar1);
  return;
}


// ===== mouse_report_post @ 20113ef0 (72 bytes)

/* message type 2 (32-byte report) */

void mouse_report_post(undefined4 *param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined4 uVar4;
  
  iVar1 = FUN_2015fa40(DAT_20800330 + 4);
  *(undefined1 *)(iVar1 + 4) = 2;
  uVar2 = param_1[1];
  uVar3 = param_1[2];
  uVar4 = param_1[3];
  *(undefined4 *)(iVar1 + 8) = *param_1;
  *(undefined4 *)(iVar1 + 0xc) = uVar2;
  *(undefined4 *)(iVar1 + 0x10) = uVar3;
  *(undefined4 *)(iVar1 + 0x14) = uVar4;
  uVar2 = param_1[5];
  uVar3 = param_1[6];
  uVar4 = param_1[7];
  *(undefined4 *)(iVar1 + 0x18) = param_1[4];
  *(undefined4 *)(iVar1 + 0x1c) = uVar2;
  *(undefined4 *)(iVar1 + 0x20) = uVar3;
  *(undefined4 *)(iVar1 + 0x24) = uVar4;
  FUN_20162d3c(DAT_20800330 + 4,*(undefined4 *)(DAT_20800330 + 0x590),iVar1);
  return;
}


// ===== mouse_cursor_set_pos @ 20113f38 (24 bytes)

void mouse_cursor_set_pos(undefined4 param_1,undefined4 param_2)

{
  mouse_cursor_move(DAT_20800330 + 4,param_1,param_2);
  return;
}


// ===== mouse_cursor_visible @ 20113f50 (24 bytes)

undefined1 mouse_cursor_visible(void)

{
  return *(undefined1 *)(DAT_20800330 + 0x594);
}


// ===== mouse_cursor_get_pos @ 20113f60 (84 bytes)

void mouse_cursor_get_pos(undefined2 *param_1,undefined2 *param_2)

{
  int iVar1;
  
  iVar1 = DAT_20800330;
  FUN_20152bb0(*(undefined4 *)(DAT_20800330 + 0x59c),0xffffffff);
  *param_1 = *(undefined2 *)(iVar1 + 0x596);
  *param_2 = *(undefined2 *)(iVar1 + 0x598);
  FUN_201511e8(*(undefined4 *)(iVar1 + 0x59c));
  return;
}


// ===== task_powon @ 20113f88 (84 bytes)

/* waits for the P2_0 edge flag, passes the level to 0x201131A8 */

void task_powon(void)

{
  ushort uVar1;
  int iVar2;
  int iStack_4;
  
  do {
    do {
      do {
        iVar2 = itron_twai_flg(DAT_20800358,1,5,&iStack_4,0xffffffff);
      } while (iVar2 != 0);
    } while (iStack_4 != 1);
    uVar1 = DAT_fcfe3208;
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
  uVar1 = DAT_fcfef804;
  if ((uVar1 & 0x20) != 0) {
    uVar1 = DAT_fcfef804;
    DAT_fcfef804 = uVar1 & 0xffdf;
  }
  return;
}


// ===== powon_init @ 20114028 (144 bytes)

/* IRQ 0x25 (P2_0 edge) + event flag + task "powon" */

void powon_init(void)

{
  ushort uVar1;
  undefined2 uVar2;
  int iVar3;
  undefined4 extraout_r2;
  undefined8 uVar4;
  
  uVar1 = DAT_fcfef802;
  DAT_fcfef802 = uVar1 & 0xf3ff;
  uVar2 = DAT_fcfef802;
  uVar1 = DAT_fcfef802;
  DAT_fcfef802 = uVar1 | 0xc00;
  DAT_20800358 = itron_acre_flg(0,&DAT_20165738);
  if (0 < DAT_20800358) {
    DAT_2080035c = itron_acre_tsk(0,&DAT_2016571c);
    if (((0 < DAT_2080035c) && (iVar3 = itron_sta_tsk(DAT_2080035c,0), iVar3 == 0)) &&
       (uVar4 = itron_acre_isr(0,&DAT_20165744), 0 < (int)uVar4)) {
      gic_enable_irq(0x25,(int)((ulonglong)uVar4 >> 0x20),extraout_r2,uVar2);
      return;
    }
  }
  return;
}


// ===== progress_set @ 201140d0 (12 bytes)

/* progress percent 0x20800364 */

void progress_set(undefined4 param_1)

{
  DAT_20800364 = param_1;
  return;
}


// ===== progress_get @ 201140dc (12 bytes)

/* progress percent */

undefined4 progress_get(void)

{
  return DAT_20800364;
}


// ===== progress_range_init @ 201140e8 (12 bytes)

/* {from, to} range */

void progress_range_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  *param_1 = param_2;
  param_1[1] = param_3;
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
  uVar7 = FUN_20164d54(param_1[1] - iVar3);
  uVar7 = FUN_20164da8((int)uVar7,(int)((ulonglong)uVar7 >> 0x20),param_3,param_4);
  uVar8 = FUN_20164d54(iVar3);
  uVar7 = FUN_20164888((int)uVar8,(int)((ulonglong)uVar8 >> 0x20),(int)uVar7,
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
  FUN_20164efc((uint)uVar7);
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
    DAT_fcfe3104 = 0x20000;
    if ((param_1 & 1) == 0) {
      DAT_fcfe3104 = 0x10000;
    }
    else {
      DAT_fcfe3104 = 0x10001;
    }
    rtc_delay(1);
    DAT_fcfe3104 = 0x20002;
    param_1 = param_1 >> 1;
    rtc_delay(1);
    iVar1 = iVar1 + 1;
  } while (iVar1 < 8);
  return;
}


// ===== rtc_send_bytes @ 201141c0 (36 bytes)

void rtc_send_bytes(undefined1 *param_1,int param_2)

{
  for (; param_2 != 0; param_2 = param_2 + -1) {
    rtc_send_byte(*param_1);
    param_1 = param_1 + 1;
  }
  return;
}


// ===== rtc_recv_byte @ 201141e4 (96 bytes)

uint rtc_recv_byte(void)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = 0;
  rtc_dt_input();
  iVar3 = 0;
  do {
    uVar2 = uVar2 >> 1;
    DAT_fcfe3104 = 0x20000;
    rtc_delay(1);
    uVar1 = DAT_fcfe3204;
    DAT_fcfe3104 = 0x20002;
    if ((uVar1 & 1) != 0) {
      uVar2 = uVar2 | 0x80;
    }
    rtc_delay(1);
    iVar3 = iVar3 + 1;
  } while (iVar3 < 8);
  rtc_dt_output();
  return uVar2;
}


// ===== rtc_recv_bytes @ 20114244 (36 bytes)

void rtc_recv_bytes(undefined1 *param_1,int param_2)

{
  undefined1 uVar1;
  
  for (; param_2 != 0; param_2 = param_2 + -1) {
    uVar1 = rtc_recv_byte();
    *param_1 = uVar1;
    param_1 = param_1 + 1;
  }
  return;
}

