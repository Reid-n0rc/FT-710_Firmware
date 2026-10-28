// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== qmb_boot_init @ fff94cab (196 bytes)

/* Boot: re-validates QMB recall state (0x9DBE/0x9DBF==5) and saves the QMB block if needed */

void qmb_boot_init(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  
  bVar1 = false;
  bVar2 = false;
  PTR_DAT_00025d38[0xb8] = 0xff;
  PTR_DAT_00025d38[0xb9] = 0xff;
  FUN_fffc3501();
  if (DAT_00009dbe == '\x05') {
    bVar2 = true;
    iVar3 = FUN_fff94fd5(0);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (DAT_00009dbf == '\x05') {
    bVar2 = true;
    iVar3 = FUN_fff94fd5(1);
    if (iVar3 == 0) {
      bVar1 = true;
    }
  }
  if (bVar1) {
    FUN_fffc4a8e();
  }
  if (bVar2) {
    eeprom_save_qmb();
  }
  FUN_fff950fb();
  PTR_DAT_00025d38[0x40b] = 1;
  freq_cache_update();
  PTR_DAT_00025d38[0x72] = 0;
  PTR_DAT_00025d38[0x71] = 1;
  PTR_DAT_00025d38[0x484] = DAT_00009dc7;
  PTR_DAT_00025d38[0x485] = DAT_00009dc8;
  return;
}


// ===== displink_task @ fff94d6f (614 bytes)

/* DISPLAY link task (main_loop and power-off loop): rx validate/dispatch, ACK/NAK, gap 2 / ACK-wait
   30 units, scheduler, 3 retries */

void displink_task(void)

{
  bool bVar1;
  bool bVar2;
  char cVar3;
  ushort uVar4;
  int iVar5;
  char *pcVar6;
  char *pcVar7;
  char *pcVar8;
  uint uVar9;
  
  freq_cache_update();
  FUN_fffc8b55();
  FUN_fffcf45c();
  FUN_fff9513c();
  iVar5 = displink_rx_ready();
  if (iVar5 == 1) {
    bVar1 = false;
    pcVar6 = (char *)displink_rx_buf();
    uVar4 = displink_rx_len_of(*pcVar6);
    pcVar7 = &DAT_0000198f;
    pcVar8 = pcVar6;
    for (uVar9 = (uint)uVar4; uVar9 != 0; uVar9 = uVar9 - 1) {
      *pcVar7 = *pcVar8;
      pcVar7 = pcVar7 + 1;
      pcVar8 = pcVar8 + 1;
    }
    displink_rx_rearm();
    if (uVar4 == 0) {
      DAT_0001b3cd = '\x01';
      bVar1 = true;
    }
    else {
      if ((*pcVar6 == '\x06') || (*pcVar6 == '\x15')) {
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
      if ((bVar2) && (iVar5 = displink_check_sum(&DAT_0000198f,uVar4), iVar5 == 0)) {
        DAT_0001b3cd = '\x01';
        bVar1 = true;
      }
    }
    if (!bVar1) {
      displink_rx_dispatch(&DAT_0000198f);
    }
  }
  if ((PTR_DAT_00025d38[0x401] == '\x01') && (iVar5 = swtimer_expired(0x2b), iVar5 == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d38[0x401] = 0;
    PTR_DAT_00025d38[0x400] = 1;
  }
  if (DAT_0001b3d2 == '\x01') {
    iVar5 = sci1_tx_end();
    if (iVar5 == 0) {
      return;
    }
    DAT_0001b3d2 = '\0';
    DAT_0001b3d3 = '\x01';
    swtimer_start(0x3b,2);
  }
  if ((DAT_0001b3d3 == '\x01') && (iVar5 = swtimer_expired(0x3b), iVar5 == 1)) {
    DAT_0001b3d3 = '\0';
  }
  if (DAT_0001b3d5 == '\x01') {
    DAT_0001b3d5 = '\0';
    DAT_0001b3d4 = '\x01';
    swtimer_start(0x3c,0x1e);
  }
  if (DAT_0001b3d3 != '\x01') {
    if (DAT_0001b3d4 == '\0') {
      if (DAT_0001b3cc == '\x01') {
        DAT_0001b3cc = '\0';
        displink_send_ack();
      }
      else if (DAT_0001b3cd == '\x01') {
        DAT_0001b3cd = '\0';
        displink_send_nak();
      }
      else {
        displink_tx_poll();
        if (DAT_0001b3d2 == '\x01') {
          DAT_0001b3d5 = '\x01';
        }
      }
    }
    else {
      iVar5 = swtimer_expired(0x3c);
      if (iVar5 == 1) {
        DAT_0001b3d4 = '\0';
        displink_tx_poll();
        if (DAT_0001b3d2 == '\x01') {
          DAT_0001b3d5 = '\x01';
        }
      }
      else if (DAT_0001b3cc == '\x01') {
        DAT_0001b3cc = '\0';
        displink_send_ack();
      }
      else if (DAT_0001b3cd == '\x01') {
        DAT_0001b3cd = '\0';
        displink_send_nak();
      }
    }
    iVar5 = FUN_fffc911e();
    if (iVar5 == 0) {
      cVar3 = FUN_fff9ccd3();
      if (cVar3 == '\0') {
        PTR_DAT_00025d38[0x6a] = 1;
        PTR_DAT_00025d38[0x6b] = 1;
      }
      else {
        PTR_DAT_00025d38[0x6a] = 0;
        PTR_DAT_00025d38[0x6b] = 0;
      }
      swtimer_start(0x4a,100);
      FUN_fffc912d(1);
      return;
    }
  }
  return;
}


// ===== FUN_fff94fd5 @ fff94fd5 (294 bytes)

undefined1 FUN_fff94fd5(uint param_1)

{
  byte bVar1;
  byte *local_c;
  char *local_8;
  
  if (param_1 == 0) {
    local_8 = &DAT_0000901f;
    local_c = &DAT_00009020;
  }
  else {
    local_8 = &DAT_00009021;
    local_c = &DAT_00009022;
  }
  if (10 < DAT_00009014) {
    DAT_00009014 = 10;
  }
  if (*local_c == 0) {
    *local_8 = '\x01';
    if (DAT_00009ac0 == '\0') {
      if (DAT_00009014 < 6) {
        *local_c = DAT_00009014 - *local_8;
      }
      else {
        *local_c = 4;
      }
    }
    else {
      *local_c = DAT_00009014 - *local_8;
    }
  }
  else {
    bVar1 = *local_c + *local_8;
    if (DAT_00009ac0 == '\0') {
      *local_c = *local_c - 1;
      if (bVar1 < 6) {
        *local_8 = bVar1 - *local_c;
      }
      else {
        if (4 < *local_c) {
          *local_c = 0;
          return 0;
        }
        *local_8 = '\x05' - *local_c;
      }
    }
    else {
      *local_c = *local_c - 1;
      *local_8 = bVar1 - *local_c;
    }
  }
  FUN_fffc31a7(param_1 & 0xff,1);
  FUN_fffc334c(param_1 & 0xff);
  return 1;
}


// ===== FUN_fff950fb @ fff950fb (65 bytes)

void FUN_fff950fb(void)

{
  DAT_0000198b = DAT_0000901f;
  DAT_0000198c = DAT_00009020;
  DAT_0000198d = DAT_00009021;
  DAT_0000198e = DAT_00009022;
  return;
}


// ===== FUN_fff9513c @ fff9513c (195 bytes)

void FUN_fff9513c(void)

{
  if (DAT_0000198b != DAT_0000901f) {
    DAT_0000198b = DAT_0000901f;
  }
  if (DAT_0000198c != DAT_00009020) {
    DAT_0000198c = DAT_00009020;
  }
  if (DAT_0000198d != DAT_00009021) {
    DAT_0000198d = DAT_00009021;
  }
  if (DAT_0000198e != DAT_00009022) {
    DAT_0000198e = DAT_00009022;
  }
  if (PTR_DAT_00025d38[0x47f] != '\0') {
    eeprom_save_qmb_slot(PTR_DAT_00025d38[0x47f] + -1);
    PTR_DAT_00025d38[0x47f] = 0;
    return;
  }
  return;
}


// ===== displink_tx_poll @ fff951ff (120 bytes)

/* Next frame (scheduler) or resend; after 3 retries drop, link down if hello */

void displink_tx_poll(void)

{
  if (PTR_DAT_00025d38[0x98] == '\x01') {
    if (DAT_0001b3ce == '\0') {
      displink_tx_schedule();
      return;
    }
    DAT_0001b3cf = DAT_0001b3cf + 1;
    if (DAT_0001b3cf < 4) {
      displink_tx_resend();
      return;
    }
    DAT_0001b3cf = '\0';
    DAT_0001b3ce = '\0';
    if (DAT_0001b3d1 == '\x01') {
      DAT_0001b3d1 = 0;
      DAT_0001b3d0 = 0;
      PTR_DAT_00025d38[0x98] = 0;
      return;
    }
  }
  return;
}


// ===== displink_rx_len_of @ fff95277 (186 bytes)

/* Frame length by type for received frames (0 = unknown -> NAK) */

undefined2 displink_rx_len_of(char param_1)

{
  undefined2 local_6;
  
  if ((param_1 == '\x06') || (param_1 == '\x15')) {
    local_6 = 1;
  }
  else if (param_1 == -0x3d) {
    local_6 = 0x23;
  }
  else if (param_1 == -0x3c) {
    local_6 = 0x107;
  }
  else if (param_1 == -0x3b) {
    local_6 = 7;
  }
  else if (param_1 == -0x20) {
    local_6 = 6;
  }
  else if (param_1 == -0x1f) {
    local_6 = 7;
  }
  else if (param_1 == -0x1e) {
    local_6 = 7;
  }
  else if (param_1 == -0x1d) {
    local_6 = 9;
  }
  else if (param_1 == -0x1c) {
    local_6 = 5;
  }
  else if (param_1 == -0x1b) {
    local_6 = 5;
  }
  else if (param_1 == -0x1a) {
    local_6 = 5;
  }
  else if (param_1 == -0x19) {
    local_6 = 10;
  }
  else if (param_1 == -0x18) {
    local_6 = 10;
  }
  else if (param_1 == -3) {
    local_6 = 0xb;
  }
  else if (param_1 == -0xf) {
    local_6 = 8;
  }
  else if (param_1 == -0x10) {
    local_6 = 10;
  }
  else {
    local_6 = 0;
  }
  return local_6;
}


// ===== displink_rx_dispatch @ fff95331 (237 bytes)

/* Switch on received type; APO reset for all but 06/15/E3 */

void displink_rx_dispatch(char *param_1)

{
  char cVar1;
  
  cVar1 = *param_1;
  if (cVar1 == -0xf) {
    displink_rx_F1_sys(param_1);
  }
  else if (cVar1 == '\x15') {
    displink_rx_nak();
  }
  else if (cVar1 == -0x4d) {
    FUN_fff95ec9();
  }
  else if (cVar1 == -0x3d) {
    displink_rx_C3(param_1);
  }
  else if (cVar1 == -0x3c) {
    displink_rx_C4_C5(param_1);
  }
  else if (cVar1 == -0x3b) {
    displink_rx_C4_C5(param_1);
  }
  else if (cVar1 == -0x20) {
    displink_rx_E0_key(param_1);
  }
  else if (cVar1 == -0x1f) {
    displink_rx_E1_encoder(param_1);
  }
  else if (cVar1 == -0x1e) {
    displink_rx_E2(param_1);
  }
  else if (cVar1 == -0x1d) {
    displink_rx_E3_clock(param_1);
  }
  else if (cVar1 == -0x1c) {
    displink_rx_E4();
    PTR_DAT_00025d38[0x82] = 0;
  }
  else if (cVar1 == -0x1b) {
    displink_rx_E5();
  }
  else if (cVar1 == -0x1a) {
    displink_rx_E6_beep(param_1);
  }
  else if (cVar1 == -0x19) {
    displink_rx_E7(param_1);
  }
  else if (cVar1 == -0x18) {
    displink_rx_E8(param_1);
  }
  else if (cVar1 == -0x10) {
    displink_rx_F0_hello(param_1);
  }
  else if (cVar1 == '\x06') {
    displink_rx_ack();
  }
  cVar1 = *param_1;
  if (((cVar1 != '\x06') && (cVar1 != '\x15')) && (cVar1 != -0x1d)) {
    cat_apo_reset();
    return;
  }
  return;
}


// ===== displink_rx_ack @ fff9541e (75 bytes)

/* ACK: clear outstanding; after the hello reply sets +0x400 (send 0x24) */

void displink_rx_ack(void)

{
  if (DAT_0001b3ce == '\x01') {
    DAT_0001b3ce = '\0';
    DAT_0001b3cf = 0;
    if (DAT_0001b3d1 == '\x01') {
      DAT_0001b3d1 = 0;
      DAT_0001b3d0 = 0;
      PTR_DAT_00025d38[0x400] = 1;
      return;
    }
  }
  return;
}


// ===== displink_rx_nak @ fff95469 (1 bytes)

/* NAK: no action */

void displink_rx_nak(void)

{
  return;
}


// ===== displink_rx_F0_hello @ fff9546a (892 bytes)

/* F0: DISPLAY version/date, boot code b7 (1 reset, 2, 4 numeric mode, 5, 6 link down, 7 destination
   swap, 0x10 warm), link up, power on (+0x36) */

void displink_rx_F0_hello(int param_1)

{
  char cVar1;
  bool bVar2;
  byte bVar3;
  short sVar4;
  
  DAT_000019bb = 0;
  DAT_000019b7 = 0;
  DAT_000019b3 = 0;
  DAT_000019af = 0;
  DAT_000019ab = 0;
  DAT_000019a7 = 0;
  DAT_000019a3 = 0;
  DAT_0000199f = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._0_1_ = 0x56;
  bVar3 = *(byte *)(param_1 + 1) >> 4;
  if ((bVar3 < 10) || (0xf < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar3 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._1_1_ = bVar3 + 0x30;
  }
  bVar3 = *(byte *)(param_1 + 1) & 0xf;
  if ((bVar3 < 10) || (0xf < bVar3)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar3 + 0x37;
  }
  else {
                    /* WARNING: Ignoring partial resolution of indirect */
    DAT_0000199f._2_1_ = bVar3 + 0x30;
  }
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._3_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._0_1_ = *(byte *)(param_1 + 2) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._1_1_ = *(byte *)(param_1 + 2) & 0x3f | 0x30;
  FUN_fff94bfd(&DAT_0000199f);
  DAT_000019bb = 0;
  DAT_000019b7 = 0;
  DAT_000019b3 = 0;
  DAT_000019af = 0;
  DAT_000019ab = 0;
  DAT_000019a7 = 0;
  DAT_000019a3 = 0;
  DAT_0000199f = 0;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._0_1_ = *(byte *)(param_1 + 4) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._1_1_ = *(byte *)(param_1 + 4) & 0x3f | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._2_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_0000199f._3_1_ = *(byte *)(param_1 + 5) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._0_1_ = *(byte *)(param_1 + 5) & 0x3f | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._1_1_ = 0x2d;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._2_1_ = *(byte *)(param_1 + 6) >> 4 | 0x30;
                    /* WARNING: Ignoring partial resolution of indirect */
  DAT_000019a3._3_1_ = *(byte *)(param_1 + 6) & 0x3f | 0x30;
  FUN_fff94c1b(&DAT_0000199f);
  PTR_DAT_00025d38[0x9b] = *(undefined1 *)(param_1 + 7);
  PTR_DAT_00025d38[0x98] = 1;
  DAT_0001b3cc = 1;
  DAT_0001b3d0 = 1;
  PTR_DAT_00025d38[0x36] = 1;
  cVar1 = PTR_DAT_00025d38[0x9b];
  if (cVar1 == '\x10') {
    if (DAT_00009dc5 == '\0') {
      PTR_DAT_00025d38[0x36] = 0;
      return;
    }
  }
  else {
    if (cVar1 == '\x02') {
      PTR_DAT_00025d38[0xba] = 1;
      FUN_fffbb567();
      return;
    }
    if (cVar1 == '\x04') {
      PTR_DAT_00025d38[0x437] = 1;
      PTR_DAT_00025d38[0x34] = 0;
      return;
    }
    if (cVar1 == '\x05') {
      if (DAT_00004760 == '\0') {
        DAT_00004760 = 1;
        return;
      }
      DAT_00004760 = '\0';
      if (4 < DAT_00009a36) {
        DAT_00009a36 = 1;
        return;
      }
    }
    else {
      if (cVar1 == '\x06') {
        PTR_DAT_00025d38[0x98] = 0;
        DAT_0001b3d0 = 0;
        return;
      }
      if (cVar1 == '\a') {
        sVar4 = dest_code_get();
        if ((sVar4 == -0x567d) || (sVar4 == -0x4a59)) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          dest_code_set(&DAT_0000d950);
        }
        else {
          if ((sVar4 == -0x26b0) || (sVar4 == -0x5b3b)) {
            bVar2 = true;
          }
          else {
            bVar2 = false;
          }
          if (bVar2) {
            dest_code_set(&DAT_0000a983);
          }
        }
        dest_jumper_apply();
        return;
      }
      if (cVar1 == '\x01') {
        settings_defaults(0);
        DAT_00020b45 = 1;
        dest_jumper_apply();
        return;
      }
    }
  }
  return;
}


// ===== displink_rx_F1_sys @ fff957e6 (67 bytes)

/* F1 sub: 01 SDR bridge, 02 DSP ISP tunnel, 03 CAT disable (0x20B46), 83 nop */

void displink_rx_F1_sys(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 != -0x7d) {
    if (cVar1 == '\x02') {
      dsp_isp_request();
      return;
    }
    if (cVar1 != '\x03') {
      if (cVar1 == '\x01') {
        sdr_bridge_request();
        return;
      }
      DAT_0001b3cd = 1;
      return;
    }
    DAT_00020b46 = 1;
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E0_key @ fff95829 (98 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9582f) */
/* E0 key/touch event -> key_event_filter -> mailbox +0x9C..+0xA0 */

void displink_rx_E0_key(int param_1)

{
  byte bVar1;
  int iVar2;
  undefined2 uVar3;
  
  uVar3 = CONCAT11(*(undefined1 *)(param_1 + 2),*(undefined1 *)(param_1 + 3));
  bVar1 = *(byte *)(param_1 + 1);
  DAT_0001b3cc = 1;
  iVar2 = key_event_filter(uVar3,bVar1);
  if (iVar2 != 0) {
    PTR_DAT_00025d38[0x9c] = bVar1 >> 4;
    PTR_DAT_00025d38[0x9d] = bVar1 & 0xf;
    *(undefined2 *)(PTR_DAT_00025d38 + 0x9e) = uVar3;
    PTR_DAT_00025d38[0xa0] = 1;
    return;
  }
  return;
}


// ===== displink_rx_E1_encoder @ fff9588b (473 bytes)

/* E1 encoder id/step -> main dial / knobs / +0xA3/+0xA4 */

void displink_rx_E1_encoder(int param_1)

{
  char cVar1;
  bool bVar2;
  int iVar3;
  
  if (PTR_DAT_00025d38[0x80] == '\x01') {
    DAT_0001b3cc = 1;
    return;
  }
  PTR_DAT_00025d38[0xa1] = *(undefined1 *)(param_1 + 1);
  if ((PTR_DAT_00025d38[0xa1] == '\x06') && (PTR_DAT_00025d38[0x70] == '\x01')) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if ((bVar2) && (PTR_DAT_00025d38[0xa1] = 3, PTR_DAT_00025d38[0x74] == '\0')) {
    *(byte *)(param_1 + 2) = ~*(byte *)(param_1 + 2) + 1;
  }
  cVar1 = PTR_DAT_00025d38[0xa1];
  if (cVar1 != '\x01') {
    if (cVar1 == '\x02') {
      iVar3 = key_event_filter(0xff1,0);
      if (iVar3 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      enc2_step((int)*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x03') {
      iVar3 = key_event_filter(0xff2,0);
      if (iVar3 == 0) {
        DAT_0001b3cc = 1;
        return;
      }
      enc3_step((int)*(char *)(param_1 + 2));
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x04') {
      if (PTR_DAT_00025d38[0x93] == '\x01') {
        if ((PTR_DAT_00025d38[0x3fd] == '\x01') || (PTR_DAT_00025d38[0x3fd] == '\x02')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if ((bVar2) || (PTR_DAT_00025d38[0x3fd] == '\x03')) {
          bVar2 = true;
        }
        else {
          bVar2 = false;
        }
        if (bVar2) {
          DAT_0001b3cc = 1;
          return;
        }
      }
      if (PTR_DAT_00025d38[0x437] != '\0') {
        FUN_fffc89ef(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      FUN_fffc523a(0,0);
      iVar3 = FUN_fffc519d(0,1);
      if (iVar3 != 1) {
        DAT_0001b3cc = 1;
        return;
      }
      PTR_DAT_00025d38[0xa3] = *(undefined1 *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 == '\x05') {
      if (PTR_DAT_00025d38[0x437] != '\0') {
        FUN_fffc8a90(*(undefined1 *)(param_1 + 2));
        DAT_0001b3cc = 1;
        return;
      }
      PTR_DAT_00025d38[0xa4] = *(undefined1 *)(param_1 + 2);
      DAT_0001b3cc = 1;
      return;
    }
    if (cVar1 != '\x06') {
      DAT_0001b3cc = 1;
      return;
    }
  }
  iVar3 = key_event_filter(0xff0,0);
  if (iVar3 != 0) {
    PTR_DAT_00025d38[0xa2] = *(undefined1 *)(param_1 + 2);
    if (PTR_DAT_00025d38[0x437] == '\0') {
      enc_main_dial(PTR_DAT_00025d38[0xa2]);
    }
    else {
      ui_numentry_step();
    }
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== ui_numentry_step @ fff95a64 (106 bytes)

/* Signed step on counter 0x25D3C (0..99999999) */

void ui_numentry_step(byte param_1)

{
  if (0x80 < param_1) {
    if ((byte)(~param_1 + 1) < DAT_00025d3c) {
      DAT_00025d3c = DAT_00025d3c - (byte)(~param_1 + 1);
      return;
    }
    DAT_00025d3c = 0;
    return;
  }
  if (DAT_00025d3c + param_1 < 99999999) {
    DAT_00025d3c = DAT_00025d3c + param_1;
    return;
  }
  DAT_00025d3c = 99999999;
  return;
}


// ===== ui_numentry_to_bcd @ fff95ace (294 bytes)

/* WARNING: Removing unreachable block (ram,0xfff95b7f) */
/* WARNING: Removing unreachable block (ram,0xfff95b76) */
/* WARNING: Removing unreachable block (ram,0xfff95b50) */
/* WARNING: Removing unreachable block (ram,0xfff95ae5) */
/* WARNING: Removing unreachable block (ram,0xfff95ada) */
/* WARNING: Removing unreachable block (ram,0xfff95b02) */
/* WARNING: Removing unreachable block (ram,0xfff95b2a) */
/* WARNING: Removing unreachable block (ram,0xfff95b34) */
/* WARNING: Removing unreachable block (ram,0xfff95b9a) */
/* WARNING: Removing unreachable block (ram,0xfff95bbe) */
/* WARNING: Removing unreachable block (ram,0xfff95bc6) */
/* 0x25D3C -> BCD at +0x7C..+0x7F */

void ui_numentry_to_bcd(void)

{
  char cVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = DAT_00025d3c;
  cVar1 = (char)(DAT_00025d3c / 10000000);
  PTR_DAT_00025d38[0x7c] = cVar1 << 4;
  uVar3 = uVar3 - (byte)(cVar1 * -0x80);
  bVar2 = (byte)(uVar3 / 1000000);
  PTR_DAT_00025d38[0x7c] = PTR_DAT_00025d38[0x7c] | bVar2;
  uVar3 = uVar3 - (byte)(bVar2 * '@');
  cVar1 = (char)(uVar3 / 100000);
  PTR_DAT_00025d38[0x7d] = cVar1 << 4;
  uVar3 = uVar3 - (byte)(cVar1 * -0x60);
  bVar2 = (byte)(uVar3 / 10000);
  PTR_DAT_00025d38[0x7d] = PTR_DAT_00025d38[0x7d] | bVar2;
  uVar3 = uVar3 - (byte)(bVar2 * '\x10');
  cVar1 = (char)(uVar3 / 1000);
  PTR_DAT_00025d38[0x7e] = cVar1 << 4;
  uVar3 = uVar3 - (byte)(cVar1 * -0x18);
  bVar2 = (byte)(uVar3 / 100);
  PTR_DAT_00025d38[0x7e] = PTR_DAT_00025d38[0x7e] | bVar2;
  uVar3 = uVar3 - (byte)(bVar2 * 'd');
  cVar1 = (char)(uVar3 / 10);
  PTR_DAT_00025d38[0x7f] = cVar1 << 4;
  PTR_DAT_00025d38[0x7f] = PTR_DAT_00025d38[0x7f] | (char)uVar3 + cVar1 * -10;
  return;
}


// ===== displink_rx_E2 @ fff95bf4 (118 bytes)

/* E2: +0xA5..+0xA7 on/off state */

void displink_rx_E2(int param_1)

{
  if (PTR_DAT_00025d38[0xa5] == '\0') {
    PTR_DAT_00025d38[0xa5] = 1;
    if (*(char *)(param_1 + 1) == '\0') {
      PTR_DAT_00025d38[0xa6] = 0;
      PTR_DAT_00025d38[0xa7] = 0;
    }
    else {
      PTR_DAT_00025d38[0xa6] = 1;
      PTR_DAT_00025d38[0xa7] = 1;
    }
  }
  else if (*(char *)(param_1 + 1) == '\0') {
    PTR_DAT_00025d38[0xa6] = 0;
  }
  else {
    PTR_DAT_00025d38[0xa6] = 1;
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E4 @ fff95c6a (10 bytes)

/* E4: answer to 0x7B (clears +0x82, set by caller) */

void displink_rx_E4(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E5 @ fff95c74 (22 bytes)

/* E5: clears +0x80 */

void displink_rx_E5(void)

{
  PTR_DAT_00025d38[0x80] = 0;
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E6_beep @ fff95c8a (50 bytes)

/* E6: beep_request(b1+1) */

void displink_rx_E6_beep(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == '\x02') {
    beep_request(3);
  }
  else if (cVar1 == '\x01') {
    beep_request(2);
  }
  else if (cVar1 == '\0') {
    beep_request(1);
  }
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E7 @ fff95cbc (241 bytes)

/* E7: result code in +0x488 */

void displink_rx_E7(int param_1)

{
  char cVar1;
  
  cVar1 = *(char *)(param_1 + 1);
  if (cVar1 == -1) {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xac] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 5;
    beep_stop();
    return;
  }
  if (cVar1 == '\x01') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xab] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 4;
      return;
    }
  }
  else if (cVar1 == '\0') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xaa] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x488) = 1;
    return;
  }
  return;
}


// ===== displink_rx_E8 @ fff95dad (184 bytes)

/* E8: result code in +0x48C */

void displink_rx_E8(int param_1)

{
  if (*(char *)(param_1 + 1) == -1) {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xac] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 5;
    beep_stop();
    return;
  }
  if (*(char *)(param_1 + 1) == '\x01') {
    PTR_DAT_00025d38[0xa8] = *(undefined1 *)(param_1 + 1);
    PTR_DAT_00025d38[0xab] = *(undefined1 *)(param_1 + 5);
    DAT_0001b3cc = 1;
    if (*(char *)(param_1 + 5) == '\0') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 2;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x01') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 3;
      return;
    }
    if (*(char *)(param_1 + 5) == '\x02') {
      *(undefined4 *)(PTR_DAT_00025d38 + 0x48c) = 4;
      return;
    }
  }
  return;
}


// ===== displink_rx_C3 @ fff95e65 (50 bytes)

/* C3 reply (to 0x43): payload -> +0x2ED, +0x3F6=1 */

void displink_rx_C3(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_0001b3cc = 1;
  PTR_DAT_00025d38[0x3f6] = 1;
  puVar1 = PTR_DAT_00025d38 + 0x2ed;
  for (iVar2 = 0x109; param_1 = param_1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ===== displink_rx_C4_C5 @ fff95e97 (50 bytes)

/* C4/C5 replies (to 0x45/0x44): payload -> +0x2ED, +0x3F6=1 */

void displink_rx_C4_C5(undefined1 *param_1)

{
  undefined1 *puVar1;
  int iVar2;
  
  DAT_0001b3cc = 1;
  PTR_DAT_00025d38[0x3f6] = 1;
  puVar1 = PTR_DAT_00025d38 + 0x2ed;
  for (iVar2 = 0x109; param_1 = param_1 + 1, iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar1 = *param_1;
    puVar1 = puVar1 + 1;
  }
  return;
}


// ===== FUN_fff95ec9 @ fff95ec9 (10 bytes)

void FUN_fff95ec9(void)

{
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_rx_E3_clock @ fff95ed3 (83 bytes)

/* E3: 5 bytes -> +0xAD..+0xB1 (DISPLAY RTC date/time [inference]) */

void displink_rx_E3_clock(int param_1)

{
  PTR_DAT_00025d38[0xad] = *(undefined1 *)(param_1 + 1);
  PTR_DAT_00025d38[0xae] = *(undefined1 *)(param_1 + 2);
  PTR_DAT_00025d38[0xaf] = *(undefined1 *)(param_1 + 3);
  PTR_DAT_00025d38[0xb0] = *(undefined1 *)(param_1 + 4);
  PTR_DAT_00025d38[0xb1] = *(undefined1 *)(param_1 + 5);
  DAT_0001b3cc = 1;
  return;
}


// ===== displink_send_ack @ fff95f26 (25 bytes)

/* send 0x06 */

void displink_send_ack(void)

{
  undefined1 local_1;
  
  local_1 = 6;
  displink_uart_send(&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_send_nak @ fff95f3f (25 bytes)

/* send 0x15 */

void displink_send_nak(void)

{
  undefined1 local_1;
  
  local_1 = 0x15;
  displink_uart_send(&local_1,1);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_tx_schedule @ fff95f58 (689 bytes)

/* MAIN->DISPLAY frame scheduler (priority list in display-link.md) */

void displink_tx_schedule(void)

{
  bool bVar1;
  int iVar2;
  
  if (DAT_0001b3d0 == '\x01') {
    displink_tx_60_hello();
    return;
  }
  if (PTR_DAT_00025d38[0xb7] == '\x01') {
    displink_tx_64();
    return;
  }
  if ((PTR_DAT_00025d38[0x400] == '\x01') && (PTR_DAT_00025d38[0x93] != '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    PTR_DAT_00025d38[0x400] = 0;
    displink_tx_24();
    return;
  }
  if (PTR_DAT_00025d38[0x447] == '\x01') {
    power_down_save();
    return;
  }
  if (PTR_DAT_00025d38[0xba] != '\0') {
    if ((PTR_DAT_00025d38[0x1c0] == '\x01') || (PTR_DAT_00025d38[0x1c1] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (!bVar1) {
      displink_tx_62();
      return;
    }
    displink_tx_30_31();
    return;
  }
  if (PTR_DAT_00025d38[0x81] == '\x01') {
    PTR_DAT_00025d38[0x81] = 0;
    displink_tx_7C();
    return;
  }
  if (PTR_DAT_00025d38[0x80] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x83] == '\x01') {
    PTR_DAT_00025d38[0x83] = 0;
    displink_tx_7B();
    return;
  }
  if (PTR_DAT_00025d38[0x82] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x85] == '\x01') {
    PTR_DAT_00025d38[0x85] = 0;
    displink_tx_7A();
    return;
  }
  if (PTR_DAT_00025d38[0x84] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x86] == '\x01') {
    displink_tx_70();
    return;
  }
  if (PTR_DAT_00025d38[0x87] == '\x01') {
    displink_tx_req();
    return;
  }
  if (PTR_DAT_00025d38[0x88] != '\0') {
    if (PTR_DAT_00025d38[0x90] != '\x01') {
      return;
    }
    displink_tx_50();
    return;
  }
  if (PTR_DAT_00025d38[0x89] == '\x01') {
    displink_tx_23();
    return;
  }
  if (PTR_DAT_00025d38[0x8a] == '\x01') {
    FUN_fff98e58();
    return;
  }
  if (PTR_DAT_00025d38[0x8b] == '\x01') {
    FUN_fff98e77();
    return;
  }
  if (PTR_DAT_00025d38[0x8c] == '\x01') {
    displink_tx_30_31();
    return;
  }
  if (PTR_DAT_00025d38[0x8d] == '\x01') {
    displink_tx_65_clock();
    return;
  }
  if (PTR_DAT_00025d38[0x99] == '\x01') {
    displink_tx_34();
    return;
  }
  if (PTR_DAT_00025d38[0x9a] == '\x01') {
    return;
  }
  if (PTR_DAT_00025d38[0x8f] == '\0') {
    if ((PTR_DAT_00025d38[0x1c0] == '\x01') || (PTR_DAT_00025d38[0x1c1] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff96124;
    }
  }
  bVar1 = false;
LAB_fff96124:
  if (bVar1) {
    displink_tx_30_31();
    return;
  }
  if (PTR_DAT_00025d38[0x90] == '\x01') {
    displink_tx_50();
    return;
  }
  if (PTR_DAT_00025d38[0x93] == '\x01') {
    displink_tx_3A();
    return;
  }
  if (PTR_DAT_00025d38[0x94] == '\x01') {
    displink_tx_39();
    return;
  }
  if (PTR_DAT_00025d38[0x91] == '\x01') {
    displink_tx_3F();
    return;
  }
  if (PTR_DAT_00025d38[0x95] == '\x01') {
    iVar2 = swtimer_expired(0x29);
    if (iVar2 != 1) {
      return;
    }
    swtimer_start(0x29,100);
    displink_tx_40();
    return;
  }
  if (PTR_DAT_00025d38[0x96] == '\x01') {
    displink_tx_37();
    return;
  }
  if (PTR_DAT_00025d38[0x97] != '\x01') {
    displink_tx_20_status();
    return;
  }
  displink_tx_41();
  return;
}


// ===== displink_tx_resend @ fff96209 (28 bytes)

/* resend frame 0x1456 (len 0x1B628) */

void displink_tx_resend(void)

{
  displink_uart_send(&DAT_00001456,DAT_0001b628);
  DAT_0001b3d2 = 1;
  return;
}


// ===== displink_tx_60_hello @ fff96225 (28 bytes)

/* 0x60 hello reply (0xB6 bytes) */

void displink_tx_60_hello(void)

{
  DAT_0001b3d1 = 1;
  displink_build_60();
  DAT_0001b628 = 0xb6;
  displink_tx_start(0xb6);
  return;
}


// ===== displink_build_60 @ fff96241 (532 bytes)

/* WARNING: Unable to track spacebase fully for stack */
/* WARNING: Removing unreachable block (ram,0xfff96241) */
/* WARNING: Removing unreachable block (ram,0xfff96452) */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* versions (MAIN/DISPLAY/DSP/SDR) + status block */

undefined1 * displink_build_60(void)

{
  undefined1 uVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  int iVar7;
  
  mem_zero(0xb5,&DAT_00001456);
  DAT_00001456 = 0x60;
  puVar4 = (undefined4 *)ver_main();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001457 = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_00001458 = cVar2 << 4 | bVar3;
  puVar4 = (undefined4 *)ver_display();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001459 = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_0000145a = cVar2 << 4 | bVar3;
  puVar4 = (undefined4 *)ver_dsp();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_0000145b = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_0000145c = cVar2 << 4 | bVar3;
  puVar4 = (undefined4 *)ver_sdr();
  _DAT_000019c3 = *(undefined2 *)(puVar4 + 1);
  DAT_000019bf._1_1_ = (undefined1)((uint)*puVar4 >> 8);
  uVar1 = DAT_000019bf._1_1_;
  DAT_000019bf = *puVar4;
  cVar2 = hex2nib(uVar1);
  bVar3 = hex2nib(DAT_000019bf._2_1_);
  DAT_00001461 = cVar2 << 4 | bVar3;
  cVar2 = hex2nib(DAT_000019c3);
  bVar3 = hex2nib(DAT_000019c4);
  DAT_00001462 = cVar2 << 4 | bVar3;
  if ((*(short *)(PTR_DAT_00025d38 + 0x32) == 0) && (DAT_00004660 != '\0')) {
    *(undefined2 *)(PTR_DAT_00025d38 + 0x32) = 0xdb;
  }
  DAT_00001463 = (undefined1)((ushort)*(undefined2 *)(PTR_DAT_00025d38 + 0x32) >> 8);
  DAT_00001464 = (undefined1)*(undefined2 *)(PTR_DAT_00025d38 + 0x32);
  *(undefined2 *)(PTR_DAT_00025d38 + 0x32) = 0;
  displink_build_status();
  puVar6 = &DAT_000016a1;
  puVar5 = &DAT_00001465;
  for (iVar7 = 0x97; iVar7 != 0; iVar7 = iVar7 + -1) {
    *puVar5 = *puVar6;
    puVar5 = puVar5 + 1;
    puVar6 = puVar6 + 1;
  }
  DAT_000014fc = DAT_00009b0d;
  DAT_00001505 = DAT_00009b09;
  DAT_00001501 = DAT_00009b05;
  DAT_000014fd = DAT_00009b01;
  DAT_00001509 = DAT_00009dc5;
  return puVar5;
}


// ===== displink_build_status @ fff96455 (2367 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96d91) */
/* WARNING: Removing unreachable block (ram,0xfff96bd9) */
/* WARNING: Removing unreachable block (ram,0xfff96645) */
/* WARNING: Removing unreachable block (ram,0xfff96c0b) */
/* WARNING: Removing unreachable block (ram,0xfff96cbc) */
/* WARNING: Removing unreachable block (ram,0xfff96d02) */
/* 0x97-byte status block at 0x16A1 (used by 0x20 and 0x60) */

undefined4 displink_build_status(void)

{
  undefined1 uVar1;
  bool bVar2;
  short sVar3;
  int iVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  bool local_a;
  byte local_9;
  short sStack_8;
  
  local_a = DAT_00009dbd == '\0';
  if (local_a) {
    DAT_00020874 = &DAT_00009d09;
    PTR_DAT_00025d38[0x40e] = 0;
  }
  else {
    DAT_00020874 = &DAT_00009d63;
    PTR_DAT_00025d38[0x40e] = 1;
  }
  local_a = !local_a;
  DAT_000016a1 = DAT_00009c37;
  DAT_000016a2 = FUN_fff96dde();
  uRam000016a3 = FUN_fff96f3e();
  DAT_000016a4 = FUN_fff96fb7();
  uRam000016a5 = FUN_fff9700b();
  uRam000016a6 = FUN_fff97049();
  uRam000016a7 = FUN_fff97075();
  DAT_000016a8 = FUN_fff970b8();
  uRam000016a9 = FUN_fff97105();
  uRam000016aa = FUN_fff9716f(DAT_00020874);
  bRam000016ab = DAT_00009c5b & 7;
  uRam000016ac = FUN_fff971fc(DAT_00020874);
  uRam000016ad = FUN_fff9728c(DAT_00020874);
  uRam000016ae = FUN_fff97430();
  uRam000016af = FUN_fff97567();
  uRam000016b0 = FUN_fff976d2();
  uRam000016b1 = FUN_fff9770b(local_a);
  iVar4 = FUN_fffc4f8f();
  if (iVar4 == 0) {
    bRam000016b2 = DAT_00009c5a << 4 | DAT_00009be8 & 0xf;
  }
  else {
    bRam000016b2 = DAT_00009be8 & 0x5f | 0x50;
  }
  FUN_fff977b3(0x16b3,DAT_00020874);
  local_9 = *DAT_00020874 & 0xf;
  if ((local_9 == 3) || (local_9 == 2)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff9782b();
  }
  FUN_fff978eb(0x16b9,DAT_00020874);
  if (DAT_00009ad5 < '\0') {
    bRam000016b9 = bRam000016b9 | 0x80;
  }
  FUN_fff9795f(0x16bb,DAT_00020874);
  FUN_fff979d3(0x16bd,DAT_00020874);
  FUN_fff97a44(0x16bf,DAT_00020874);
  uRam000016c1 = DAT_00009c5f;
  cRam000016c2 = DAT_00009c04 + '\x1e';
  uRam000016c3 = FUN_fff97abc(DAT_00020874);
  uRam000016c4 = FUN_fff97b7b();
  FUN_fff97ba6();
  uRam000016cb = 0xff;
  if (PTR_DAT_00025d38[0x483] == '\x01') {
    uRam000016cc = 0x2d;
  }
  else {
    uRam000016cc = FUN_fff97c74();
  }
  DAT_0001b62a = 0x2d;
  bRam000016cd = DAT_00009d09 & 0xf;
  DAT_0001b62e = 0x2e;
  uRam000016ce = FUN_fff97cf7(0);
  bRam000016cf = local_9;
  uRam000016d0 = FUN_fff97e1d(0);
  if (PTR_DAT_00025d38[0x437] == '\0') {
    DAT_000019c9 = 0;
    DAT_000019c5 = 0;
    FUN_fff982aa(0,&DAT_000019c5);
    uRam000016d5 = DAT_000019c9;
    uRam000016d1 = DAT_000019c5;
  }
  else {
    ui_numentry_to_bcd();
    local_9 = 5;
    puVar6 = PTR_DAT_00025d38 + 0x7b;
    puVar5 = (undefined1 *)0x16d1;
    for (iVar4 = 5; iVar4 != 0; iVar4 = iVar4 + -1) {
      *puVar5 = *puVar6;
      puVar5 = puVar5 + 1;
      puVar6 = puVar6 + 1;
    }
  }
  uRam000016de = DAT_00009d5f;
  uRam000016da = DAT_00009d5b;
  uRam000016d6 = DAT_00009d57;
  uRam000016e2 = PTR_DAT_00025d38[0x425];
  uRam000016e3 = DAT_00009d51;
  uRam000016e4 = DAT_00009d52;
  DAT_0001b62c = 0x46;
  bRam000016e6 = DAT_00009d63 & 0xf;
  DAT_0001b630 = 0x47;
  uRam000016e7 = FUN_fff97cf7(1);
  bRam000016e8 = local_9;
  uRam000016e9 = FUN_fff97e1d(1);
  DAT_000019c9 = 0;
  DAT_000019c5 = 0;
  FUN_fff982aa(1,&DAT_000019c5);
  uRam000016ee = DAT_000019c9;
  uRam000016ea = DAT_000019c5;
  uRam000016f7 = DAT_00009db9;
  uRam000016f3 = DAT_00009db5;
  uRam000016ef = DAT_00009db1;
  uRam000016fb = PTR_DAT_00025d38[0x426];
  uRam000016fc = DAT_00009dab;
  uRam000016fd = DAT_00009dac;
  if (DAT_00009dbd == '\x01') {
    DAT_00020878 = &DAT_000016a0 + DAT_0001b62a;
    DAT_0002087c = &DAT_000016a0 + DAT_0001b62c;
    for (sStack_8 = DAT_0001b62c - DAT_0001b62a; sStack_8 != 0; sStack_8 = sStack_8 + -1) {
      uVar1 = *DAT_00020878;
      *DAT_00020878 = *DAT_0002087c;
      *DAT_0002087c = uVar1;
      DAT_00020878 = DAT_00020878 + 1;
      DAT_0002087c = DAT_0002087c + 1;
    }
  }
  if (DAT_00009c5e == '\x01') {
    (&DAT_000016a0)[DAT_0001b62e] = 9;
    (&DAT_000016a0)[DAT_0001b630] = 10;
  }
  uRam000016ff = FUN_fff9849e();
  uRam00001700 = FUN_fff98526(DAT_00020874);
  uRam00001707 = 0;
  bRam00001708 = DAT_00009a8d & 3 | DAT_00009a8c << 7;
  cRam00001709 = (DAT_00009a79 & 3) << 4;
  uRam0000170a = DAT_00009c03;
  uRam0000170b = 0;
  uRam0000170c = 0;
  uRam0000170d = 0;
  uRam0000170e = 0;
  uRam0000170f = 0;
  uRam00001710 = 0;
  bRam00001711 = DAT_00009c3c & 7 | (DAT_00009c39 & 3) << 5 | 0x18;
  sVar3 = CONCAT11(DAT_00009a7a,DAT_00009a7b) * 10;
  uRam00001713 = (undefined1)((ushort)sVar3 >> 8);
  uRam00001714 = (undefined1)sVar3;
  disp_put_op_freq(0x1715);
  disp_put_tx_freq(0x1719);
  disp_put_dial_freq(0x171d);
  disp_put_scope_start(0x1721);
  return 0x98;
}


// ===== FUN_fff96d94 @ fff96d94 (74 bytes)

char FUN_fff96d94(byte param_1)

{
  byte bVar1;
  byte local_3;
  
  local_3 = DAT_00009014;
  if ((DAT_00009ac0 == '\0') && (4 < DAT_00009014)) {
    local_3 = 5;
  }
  bVar1 = param_1;
  if (param_1 < local_3) {
    bVar1 = local_3;
  }
  local_3 = bVar1;
  local_3 = local_3 - param_1;
  if (local_3 == '\0') {
    local_3 = '\x01';
  }
  return local_3;
}


// ===== FUN_fff96dde @ fff96dde (352 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96f1f) */
/* WARNING: Removing unreachable block (ram,0xfff96f22) */
/* WARNING: Removing unreachable block (ram,0xfff96f21) */
/* WARNING: Removing unreachable block (ram,0xfff96e46) */
/* WARNING: Removing unreachable block (ram,0xfff96e4a) */
/* WARNING: Removing unreachable block (ram,0xfff96e57) */
/* WARNING: Removing unreachable block (ram,0xfff96e56) */
/* WARNING: Removing unreachable block (ram,0xfff96e6a) */
/* WARNING: Removing unreachable block (ram,0xfff96e69) */
/* WARNING: Removing unreachable block (ram,0xfff96e48) */
/* WARNING: Removing unreachable block (ram,0xfff96e83) */
/* WARNING: Removing unreachable block (ram,0xfff96e82) */
/* WARNING: Removing unreachable block (ram,0xfff96e96) */
/* WARNING: Removing unreachable block (ram,0xfff96e95) */

undefined1 FUN_fff96dde(void)

{
  undefined1 local_2;
  
  if (DAT_00009c35 == '\0') {
    uRam00000000 = 1;
  }
  if (DAT_00009c36 == '\0') {
    if (DAT_00009c35 == '\0') {
      if (PTR_DAT_00025d38[0x67] == '\0') {
        uRam00000000 = 1;
        if (DAT_00009c38 == '\0') {
          local_2 = 3;
        }
        else if (DAT_00009c38 == '\x01') {
          local_2 = 4;
        }
        else {
          local_2 = 5;
        }
      }
      else if (DAT_00009c38 == '\0') {
        local_2 = 9;
      }
      else if (DAT_00009c38 == '\x01') {
        local_2 = 10;
      }
      else {
        local_2 = 0xb;
      }
    }
    else if (DAT_00009c38 == '\0') {
      local_2 = 3;
    }
    else if (DAT_00009c38 == '\x01') {
      local_2 = 4;
    }
    else {
      local_2 = 5;
    }
  }
  else if (DAT_00009c35 == '\0') {
    if (PTR_DAT_00025d38[0x67] == '\0') {
      uRam00000000 = 1;
      local_2 = 0;
    }
    else {
      local_2 = 2;
    }
  }
  else {
    local_2 = 0;
  }
  return local_2;
}


// ===== FUN_fff96f3e @ fff96f3e (121 bytes)

/* WARNING: Removing unreachable block (ram,0xfff96f69) */

byte FUN_fff96f3e(void)

{
  char local_3;
  byte local_2;
  
  local_2 = DAT_00009dbd;
  if (PTR_DAT_00025d38[0x405] == '\x01') {
    if (DAT_00009dbd == '\0') {
      local_2 = '\x01';
    }
    else {
      local_2 = '\0';
    }
  }
  local_2 = local_2 << 7;
  if (DAT_00009dbd == '\0') {
    local_3 = PTR_DAT_00025d38[0x425];
  }
  else {
    local_3 = PTR_DAT_00025d38[0x426];
  }
  if (DAT_00009c5e == '\x01') {
    local_2 = local_2 | 0x20;
  }
  else if (local_3 == '\0') {
    local_2 = local_2 | 0x10;
  }
  else {
    local_2 = local_2 | 0x40;
  }
  return local_2;
}


// ===== FUN_fff96fb7 @ fff96fb7 (84 bytes)

undefined1 FUN_fff96fb7(void)

{
  bool bVar1;
  undefined1 local_2;
  
  local_2 = 0;
  if ((PTR_DAT_00025d38[0x96] == '\x01') || (PTR_DAT_00025d38[0x97] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (PTR_DAT_00025d38[0x95] == '\x01')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_2 = 0x20;
  }
  return local_2;
}


// ===== FUN_fff9700b @ fff9700b (62 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97017) */
/* WARNING: Removing unreachable block (ram,0xfff97028) */

byte FUN_fff9700b(void)

{
  return DAT_00009c5e | (DAT_00009c3d & 1) << 5 | (DAT_00009dc6 & 1) << 6;
}


// ===== FUN_fff97049 @ fff97049 (44 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97055) */
/* WARNING: Removing unreachable block (ram,0xfff97063) */

byte FUN_fff97049(void)

{
  return (DAT_00009b17 & 1) << 6 | DAT_00009b16 << 7;
}


// ===== FUN_fff97075 @ fff97075 (67 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97082) */
/* WARNING: Removing unreachable block (ram,0xfff97091) */
/* WARNING: Removing unreachable block (ram,0xfff970a6) */

byte FUN_fff97075(void)

{
  return (PTR_DAT_00025d38[0x69] & 3) << 4 |
         (PTR_DAT_00025d38[0x68] & 1) << 6 | PTR_DAT_00025d38[0x67] << 7;
}


// ===== FUN_fff970b8 @ fff970b8 (77 bytes)

byte FUN_fff970b8(void)

{
  byte local_3;
  char local_2;
  
  local_3 = PTR_DAT_00025d38[0x34];
  if (PTR_DAT_00025d38[0x437] == '\0') {
    local_2 = DAT_00009b10;
  }
  else {
    local_2 = PTR_DAT_00025d38[0x480];
  }
  if (local_2 == '\0') {
    local_3 = local_3 & 0xf0;
  }
  return local_3;
}


// ===== FUN_fff97105 @ fff97105 (106 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97135) */
/* WARNING: Removing unreachable block (ram,0xfff97111) */
/* WARNING: Removing unreachable block (ram,0xfff97120) */
/* WARNING: Removing unreachable block (ram,0xfff9714a) */
/* WARNING: Removing unreachable block (ram,0xfff9715e) */

byte FUN_fff97105(void)

{
  return (DAT_00009c5c & 1) << 3 |
         (PTR_DAT_00025d38[0x6c] & 1) << 4 |
         (PTR_DAT_00025d38[0x6b] & 1) << 5 | (PTR_DAT_00025d38[0x6a] & 1) << 6 | DAT_00009be7 << 7;
}


// ===== FUN_fff9716f @ fff9716f (141 bytes)

byte FUN_fff9716f(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = (uint)(*param_1 & 0xf);
  if (uVar1 != 0xe) {
    if (uVar1 - 4 < 2) {
      local_6 = DAT_00009a4b | 0x80;
      goto LAB_fff971e9;
    }
    if (1 < uVar1 - 8) {
      if (uVar1 < 2) {
        local_6 = DAT_00009a36 | 0x80;
      }
      else {
        local_6 = 0;
      }
      goto LAB_fff971e9;
    }
  }
  local_6 = DAT_00009a73 | 0x80;
LAB_fff971e9:
  if ((local_6 & 0x7f) == 6) {
    local_6 = local_6 & 0x7f;
  }
  return local_6;
}


// ===== FUN_fff971fc @ fff971fc (144 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97257) */
/* WARNING: Removing unreachable block (ram,0xfff97270) */

byte FUN_fff971fc(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_7;
  char cStack_6;
  
  bVar2 = FUN_fff9921f();
  bVar3 = *param_1 & 0xf;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    cStack_6 = '\x02';
  }
  else if ((bVar2 & 0x80) == 0) {
    cStack_6 = '\0';
  }
  else {
    cStack_6 = '\x01';
  }
  if ((param_1[5] & 3) == 0) {
    bStack_7 = 0;
  }
  else {
    bStack_7 = (param_1[5] & 3) - 1;
  }
  return param_1[3] & 3 | (bStack_7 & 3) << 2 | cStack_6 << 4;
}


// ===== FUN_fff9728c @ fff9728c (304 bytes)

byte FUN_fff9728c(byte *param_1)

{
  bool bVar1;
  byte bVar2;
  byte bVar3;
  byte bStack_9;
  byte local_6;
  
  local_6 = 0;
  bVar3 = *param_1 & 0xf;
  if (DAT_00009aa4 == '\x01') {
    if ((bVar3 == 3) || (bVar3 == 2)) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      bVar1 = true;
      goto LAB_fff972c7;
    }
  }
  bVar1 = false;
LAB_fff972c7:
  if (bVar1) {
    local_6 = 0x80;
  }
  if ((bVar3 == 3) || (bVar3 == 2)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && ((param_1[0x14] & 0x20) != 0)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | 0x40;
  }
  bVar2 = FUN_fff973bc(param_1);
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x40) >> 1);
  }
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (bVar3 != 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (bVar3 != 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_6 = local_6 | (byte)((bVar2 & 0x80) >> 3);
  }
  bVar3 = FUN_fff9921f(param_1);
  if ((bVar3 & 0x40) == 0) {
    bStack_9 = 0;
  }
  else {
    bStack_9 = (bVar3 >> 4 & 3) + 1;
  }
  return local_6 | bStack_9;
}


// ===== FUN_fff973bc @ fff973bc (116 bytes)

byte FUN_fff973bc(byte *param_1)

{
  uint uVar1;
  byte local_6;
  
  uVar1 = *param_1 & 0xf;
  if (uVar1 == 0xe) {
LAB_fff97422:
    local_6 = param_1[0x28];
  }
  else {
    if (uVar1 - 2 < 2) {
      return param_1[0x14];
    }
    if (uVar1 - 4 < 2) {
      return param_1[0x32];
    }
    if (1 < uVar1 - 6) {
      if (uVar1 - 8 < 2) goto LAB_fff97422;
      if (1 < uVar1 - 10) {
        if (uVar1 - 0xc < 2) {
          return param_1[0x1e];
        }
        if ((*param_1 & 0xf) != 0 && uVar1 != 1) {
          return 0;
        }
        return param_1[10];
      }
    }
    local_6 = param_1[0x3c];
  }
  return local_6;
}


// ===== FUN_fff97430 @ fff97430 (251 bytes)

/* WARNING: Removing unreachable block (ram,0xfff97487) */
/* WARNING: Removing unreachable block (ram,0xfff97454) */
/* WARNING: Removing unreachable block (ram,0xfff974b0) */
/* WARNING: Removing unreachable block (ram,0xfff974ce) */

byte FUN_fff97430(void)

{
  bool bVar1;
  char cVar2;
  byte bVar3;
  byte bVar4;
  byte *pbVar5;
  int iVar6;
  int iVar7;
  char *pcVar8;
  byte bStack_a;
  char cStack_9;
  
  pbVar5 = (byte *)vfo_rec_ptr(1);
  bVar3 = *pbVar5 & 0xf;
  iVar6 = FUN_fff9752b(pbVar5);
  iVar7 = FUN_fffc3e3c(pbVar5);
  if ((iVar7 == 0) || (DAT_00009c02 != '\x01')) {
    cVar2 = '\0';
  }
  else {
    cVar2 = '\x01';
  }
  pcVar8 = (char *)FUN_fff99669();
  if (pcVar8 == (char *)0x0) {
    cStack_9 = '\0';
  }
  else if (*pcVar8 == '\0') {
    cStack_9 = '\0';
  }
  else {
    cStack_9 = '\x01';
  }
  bVar4 = FUN_fff973bc(pbVar5);
  bStack_a = ((bVar4 & 2) != 0) << 2 | cStack_9 << 4 | cVar2 << 5 | (iVar6 != 0) << 6;
  if ((bVar3 == 6) || (bVar3 == 7)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 10)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) || (bVar3 == 0xb)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    bStack_a = bStack_a | (pbVar5[2] >> 2 & 3) + 1;
  }
  return bStack_a;
}


// ===== FUN_fff9752b @ fff9752b (60 bytes)

undefined1 FUN_fff9752b(byte *param_1)

{
  bool bVar1;
  undefined1 local_7;
  
  local_7 = 0;
  if (((*param_1 & 0xf) == 0) || ((*param_1 & 0xf) == 1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if ((bVar1) && (DAT_00009bf1 != '\0')) {
    local_7 = 1;
  }
  return local_7;
}


// ===== FUN_fff97567 @ fff97567 (363 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9769f) */
/* WARNING: Removing unreachable block (ram,0xfff976ae) */

byte FUN_fff97567(void)

{
  bool bVar1;
  char local_3;
  
  if ((PTR_DAT_00025d38[0x1c9] == '\x01') || (PTR_DAT_00025d38[0x78] == '\x02')) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    local_3 = '\x01';
  }
  else {
    if ((PTR_DAT_00025d38[0x417] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\x01')) {
      bVar1 = true;
    }
    else {
      bVar1 = false;
    }
    if (bVar1) {
      local_3 = '\x01';
    }
    else {
      if ((PTR_DAT_00025d38[0x417] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\0')) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_3 = '\0';
      }
      else {
        if ((PTR_DAT_00025d38[0x1cc] == '\x01') || (PTR_DAT_00025d38[0x1cd] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if ((bVar1) || (PTR_DAT_00025d38[0x78] == '\x01')) {
          bVar1 = true;
        }
        else {
          bVar1 = false;
        }
        if (bVar1) {
          local_3 = '\x02';
        }
        else {
          if ((PTR_DAT_00025d38[0x92] == '\x01') && (PTR_DAT_00025d38[0x1bc] == '\x01')) {
            bVar1 = true;
          }
          else {
            bVar1 = false;
          }
          if (bVar1) {
            local_3 = '\x03';
          }
          else {
            local_3 = '\0';
          }
        }
      }
    }
  }
  return PTR_DAT_00025d38[0x6e] & 3 | (PTR_DAT_00025d38[0x6d] & 3) << 3 | local_3 << 6;
}


// ===== FUN_fff976d2 @ fff976d2 (57 bytes)

/* WARNING: Removing unreachable block (ram,0xfff976ee) */

byte FUN_fff976d2(void)

{
  int iVar1;
  byte bStack_2;
  
  iVar1 = swtimer_expired(0x2a);
  if (iVar1 == 0) {
    bStack_2 = 0x40;
  }
  else {
    bStack_2 = PTR_DAT_00025d38[0x6f] << 4;
  }
  return DAT_00009be6 & 7 | bStack_2;
}

