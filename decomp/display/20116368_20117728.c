// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== mainlink_stat_rx_resync @ 20116368 (20 bytes)

/* RX task resync counter (obj+0x38) */

uint mainlink_stat_rx_resync(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (g_ml.link_obj != (byte *)0x0) {
    uVar1 = *(uint *)(g_ml.link_obj + 0x38);
  }
  return uVar1;
}


// ===== mainlink_stat_nak_sent @ 2011637c (20 bytes)

/* RX task NAK counter (obj+0x48) */

uint mainlink_stat_nak_sent(void)

{
  uint uVar1;
  
  uVar1 = 0;
  if (g_ml.link_obj != (byte *)0x0) {
    uVar1 = *(uint *)(g_ml.link_obj + 0x48);
  }
  return uVar1;
}


// ===== mainlink_ack_timeout_cyc @ 20116390 (16 bytes)

/* WARNING: Removing unreachable block (ram,0x20150f0c) */
/* cyclic handler: set_flg(0x2045004C, 1) wakes the retry task */

code * mainlink_ack_timeout_cyc(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  code *pcVar5;
  int iVar6;
  uint uVar7;
  uint *puVar8;
  uint *extraout_r2;
  undefined4 in_r3;
  knl_tcb *pkVar9;
  uint uVar10;
  knl_flg *pkVar11;
  byte *pbVar12;
  bool bVar13;
  
  if ((g_ml.retry_flg == 0) || (0x40 < g_ml.retry_flg)) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  pkVar11 = knl_flg_tab[g_ml.retry_flg];
  if (pkVar11 == (knl_flg *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  for (pbVar12 = pkVar11->wq; uVar10 = (uint)*pbVar12, uVar10 == 0; pbVar12 = pbVar12 + 1) {
  }
  if (0xfd < uVar10) {
    pkVar11->flgptn = pkVar11->flgptn | 1;
    software_interrupt(0);
    return knl_svc_return;
  }
  pkVar9 = knl_tsk_tab[uVar10];
  uVar7 = (uint)pkVar9->q_prev;
  bVar13 = uVar7 == uVar10;
  if (bVar13) {
    uVar7 = (uint)pkVar11->flgatr;
  }
  if (!bVar13 || (uVar7 & 2) != 0) {
    bVar13 = false;
    uVar10 = pkVar11->flgptn | 1;
LAB_20150fa4:
    pkVar9 = knl_tsk_tab[*pbVar12];
    bVar1 = pkVar9->q_prev;
    uVar7 = (uint)*pbVar12;
    do {
      bVar2 = pkVar9->state;
      bVar3 = pkVar9->q_next;
      uVar4 = *(uint *)(pkVar9->sp + 8);
      if ((bVar2 & 1) == 0) {
        if ((uVar4 & ~uVar10) == 0) goto LAB_2015109c;
      }
      else if ((uVar4 & uVar10) != 0) {
LAB_2015109c:
        **(uint **)(pkVar9->sp + 0xc) = uVar10;
        if ((bVar2 & 2) != 0) {
          knl_timeout_remove(pkVar9,uVar7);
        }
        pkVar9->state = 0x10;
        if (pkVar9->f_0x09_u8 == 0) {
          iVar6 = (int)pkVar9->pri;
          if (iVar6 < knl_sys.run_pri) {
            bVar13 = (bool)(bVar13 | iVar6 < knl_sys.run_pri);
          }
          knl_queue_move(knl_rdq + iVar6,pkVar9,uVar7);
        }
        else {
          knl_queue_remove(pkVar9,uVar7);
        }
        if ((bVar2 & 4) != 0) {
          pkVar11->flgptn = 0;
          if (!bVar13) {
            software_interrupt(0);
            return knl_svc_return;
          }
          software_interrupt(0);
          return knl_dispatch;
        }
      }
      if (bVar1 == uVar7) goto LAB_2015116c;
      pkVar9 = knl_tsk_tab[bVar3];
      uVar7 = (uint)bVar3;
    } while( true );
  }
  bVar1 = pkVar9->state;
  if ((bVar1 & 1) == 0) {
    uVar7 = pkVar11->flgptn | 1;
    if ((*(uint *)(pkVar9->sp + 8) & ~uVar7) != 0) goto LAB_20151030;
  }
  else {
    uVar7 = pkVar11->flgptn | 1;
    if ((*(uint *)(pkVar9->sp + 8) & uVar7) == 0) {
LAB_20151030:
      pkVar11->flgptn = uVar7;
      software_interrupt(0);
      return knl_svc_return;
    }
  }
  puVar8 = *(uint **)(pkVar9->sp + 0xc);
  *puVar8 = uVar7;
  if ((bVar1 & 4) != 0) {
    uVar7 = 0;
  }
  pkVar11->flgptn = uVar7;
  if ((bVar1 & 2) != 0) {
    knl_timeout_remove(pkVar9,uVar10);
    puVar8 = extraout_r2;
  }
  pkVar9->state = 0x10;
  if (pkVar9->f_0x09_u8 == 0) {
    pcVar5 = (code *)knl_make_ready(pkVar9,uVar10,puVar8,in_r3);
    return pcVar5;
  }
  pcVar5 = (code *)knl_release_suspended();
  return pcVar5;
LAB_2015116c:
  do {
    pbVar12 = pbVar12 + 1;
  } while (*pbVar12 == 0);
  if (0xfd < *pbVar12) {
    pkVar11->flgptn = uVar10;
    if (!bVar13) {
      software_interrupt(0);
      return knl_svc_return;
    }
    software_interrupt(0);
    return knl_dispatch;
  }
  goto LAB_20150fa4;
}


// ===== mainlink_init @ 201163a0 (300 bytes)

/* cmd_interval_sem / cmd_waiting_sem, binds SCIF5 */

void mainlink_init(void)

{
  byte *pbVar1;
  uint uVar2;
  uint uVar3;
  void *pvVar4;
  
  uVar2 = os_create_sem_named(&DAT_20165860,0x201164cc);
  if (0 < (int)uVar2) {
    g_ml.pace_sem = uVar2;
    itron_sig_sem();
  }
  uVar2 = itron_acre_tsk(0,(byte *)&ctsk_cmd_interval);
  periodic_wakeup_register(uVar2,3);
  if (0 < (int)uVar2) {
    itron_sta_tsk(uVar2,0);
    uVar2 = os_create_sem_named(&DAT_20165870,0x201164e8);
    if (0 < (int)uVar2) {
      g_ml.enc_sem = uVar2;
      itron_sig_sem();
    }
    __aeabi_memclr4(&DAT_2045fd40,0x103c0);
    g_ml.link_obj = (byte *)mainlink_obj_ctor(&DAT_2045fd40);
    uVar2 = itron_acre_tsk(0,(byte *)&ctsk_uart_5880);
    if ((0 < (int)uVar2) && (uVar3 = itron_acre_flg(0,(byte *)&cflg_mainlink_rx), 0 < (int)uVar3)) {
      *(uint *)(g_ml.link_obj + 0x14) = uVar3;
      pvVar4 = scif5_get(uVar3);
      pbVar1 = g_ml.link_obj;
      *(void **)(g_ml.link_obj + 0x10) = pvVar4;
      itron_sta_tsk(uVar2,(uint)pbVar1);
      g_ml.retry_flg = itron_acre_flg(0,(byte *)&cflg_mainlink_retry);
      if ((0 < (int)g_ml.retry_flg) &&
         (((uVar2 = itron_acre_tsk(0,(byte *)&ctsk_retry), 0 < (int)uVar2 &&
           (uVar2 = itron_sta_tsk(uVar2,0), uVar2 == 0)) &&
          (uVar2 = itron_acre_cyc(0,&DAT_201658c4), 0 < (int)uVar2)))) {
        g_ml.ack_tmo_cyc = uVar2;
      }
    }
  }
  return;
}


// ===== mainlink_rx_ctrl @ 20116518 (72 bytes)

/* set_flg 0x4000/0x8000 on the RX task flag (resets the parser); arg 0 also re-binds the SCIF5 ISR
   to it (used by the update code) */

void mainlink_rx_ctrl(int param_1)

{
  if ((g_ml.link_obj != (byte *)0x0) &&
     (itron_set_flg(*(undefined4 *)(g_ml.link_obj + 0x14)), param_1 == 0)) {
    scif5_get(*(uint *)(g_ml.link_obj + 0x14));
    return;
  }
  return;
}


// ===== mainlink_inject_rx @ 20116560 (148 bytes)

/* rename (was mainlink_send_cmd): builds a frame from the 0x2B-entry table length and posts it to
   the RX dispatcher mailbox, i.e. replays a frame locally; it does not transmit */

void mainlink_inject_rx(char *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = mainlink_disp_alloc((int)(g_ml.link_obj + 0x58));
  iVar3 = 0;
  uVar2 = 0;
  do {
    if (*param_1 == (&DAT_20450074)[uVar2 * 0xc]) {
      iVar3 = (ushort)(&DAT_20450076)[uVar2 * 6] + 2;
      break;
    }
    uVar2 = uVar2 + 1;
  } while (uVar2 < 0x2b);
  if (iVar3 != 0) {
    *(undefined2 *)(uVar1 + 4) = 0xaa;
    *(short *)(uVar1 + 6) = (short)iVar3;
    memcpy(uVar1 + 8,param_1);
    mainlink_disp_post(g_ml.link_obj + 0x58,uVar1);
    return;
  }
  return;
}


// ===== mainlink_hello_poweron @ 201165f4 (108 bytes)

/* sends F0 every 5 ms (max 30) with the power-up key code until MAIN ACKs */

void mainlink_hello_poweron(void)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  
  key_task_pause();
  g_ml.got60 = 0;
  bVar1 = key_scan_first();
  if (bVar1 == 0) {
    if (DAT_208003a1 == '\0') {
      DAT_208003a1 = '\x01';
    }
    else {
      bVar1 = 0x10;
    }
  }
  g_ml.hello_acked = 0;
  iVar2 = 0x1d;
  do {
    mainlink_send_hello(bVar1);
    itron_dly_tsk(5);
    if (g_ml.hello_acked != 0) {
      iVar2 = 0;
    }
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}


// ===== mainlink_clear_status @ 20116660 (44 bytes)

/* clears the 0x60 snapshot and the 0x24 settings copy */

void mainlink_clear_status(void)

{
  __aeabi_memclr4(&DAT_2045fb00,0x240);
  g_ml.got60 = 0;
  FUN_20163684(0x2045006d);
  g_ml.got24 = 0;
  return;
}


// ===== mainlink_hello_key6 @ 2011668c (60 bytes)

/* same as mainlink_hello_poweron with key code 6 */

void mainlink_hello_key6(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0x1d;
  g_ml.hello_acked = 0;
  do {
    mainlink_send_hello(6);
    itron_dly_tsk(5);
    if (g_ml.hello_acked != 0) {
      iVar1 = 0;
    }
    bVar2 = iVar1 != 0;
    iVar1 = iVar1 + -1;
  } while (bVar2);
  return;
}


// ===== usbhid_attach_event @ 201166cc (92 bytes)

/* usage 6 keyboard / 2 mouse attach, -1 detach */

void usbhid_attach_event(int param_1,int param_2)

{
  if (param_2 == 6) {
    usbkbd_attach();
  }
  else if (param_2 == 2) {
    mouse_attach_post();
  }
  else if (param_2 < 0) {
    if (*(int *)(&DAT_2080036c + param_1 * 4) == 6) {
      usbkbd_detach();
    }
    else if (*(int *)(&DAT_2080036c + param_1 * 4) == 2) {
      mouse_detach_post();
    }
  }
  *(int *)(&DAT_2080036c + param_1 * 4) = param_2;
  return;
}


// ===== usbhid_report_event @ 20116728 (56 bytes)

/* report -> usbkbd_report (6) or mouse_report_post (2) */

void usbhid_report_event(uint param_1,int *param_2)

{
  if (*param_2 == 6) {
    usbkbd_report(param_1,param_2);
  }
  else {
    if (*param_2 != 2) {
      return;
    }
    mouse_report_post(param_2);
  }
  DAT_20800487 = 1;
  return;
}


// ===== periodic_wakeup_register @ 20116768 (28 bytes)

/* (task, slot): slot n of 0x208DBAD0 {tskid, ?, period from 0x20800374[n], count} */

void periodic_wakeup_register(uint param_1,int param_2)

{
  (&DAT_208dbad0)[param_2 * 4] = param_1;
  (&DAT_208dbad8)[param_2 * 4] = *(undefined4 *)(&DAT_20800374 + param_2 * 4);
  return;
}


// ===== FUN_20116784 @ 20116784 (8 bytes)

void FUN_20116784(void)

{
  gic_disable_irq(0x87);
  return;
}


// ===== periodic_wakeup_isr @ 2011678c (76 bytes)

/* GIC 0x87, every 1 ms: per slot count++, at period wake the task (0x20152FAC) */

void periodic_wakeup_isr(void)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (&DAT_208dbadc)[iVar2 * 4];
    (&DAT_208dbadc)[iVar2 * 4] = iVar1 + 1;
    if ((&DAT_208dbad8)[iVar2 * 4] == iVar1 + 1) {
      itron_iwup_tsk((&DAT_208dbad0)[iVar2 * 4]);
    }
    __aeabi_uidivmod((&DAT_208dbadc)[iVar2 * 4],(&DAT_208dbad8)[iVar2 * 4]);
    iVar1 = iVar2 + 1;
    (&DAT_208dbadc)[iVar2 * 4] = extraout_r1;
    iVar2 = iVar1;
  } while (iVar1 < 5);
  return;
}


// ===== periodic_wakeup_start @ 201167d8 (92 bytes)

/* OSTM1 1 ms compare (31999), ISR on GIC ID 0x87 */

int periodic_wakeup_start(void)

{
  byte bVar1;
  uint uVar2;
  
  OSTM_OSTM1CMP = 31999;
  bVar1 = OSTM_OSTM1CTL;
  OSTM_OSTM1CTL = bVar1 & 0xfd;
  OSTM_OSTM1CTL = 1;
  uVar2 = itron_acre_isr(0,0x20165954);
  if ((int)uVar2 < 1) {
    return uVar2;
  }
  gic_enable_irq(0x87);
  bVar1 = OSTM_OSTM1TS;
  OSTM_OSTM1TS = bVar1 | 1;
  return 0;
}


// ===== cli_exec_line @ 20116848 (392 bytes)

void cli_exec_line(byte *param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  byte *pbVar1;
  ushort uVar2;
  uint uVar3;
  bool bVar5;
  char cVar6;
  byte *local_18;
  uint *puVar4;
  
  cVar6 = false;
  local_18 = param_4;
  uVar3 = strlen();
  bVar5 = uVar3 == 2;
  if (1 < uVar3) {
    bVar5 = *param_1 == 0x62;
  }
  if ((bVar5) && (cVar6 = param_1[1] == 0x20, (bool)cVar6)) {
LAB_201168a0:
    param_1 = param_1 + 2;
  }
  else {
    uVar3 = strlen(param_1);
    bVar5 = uVar3 == 2;
    if (1 < uVar3) {
      bVar5 = *param_1 == 0x68;
    }
    if ((bVar5) && (param_1[1] == 0x20)) {
      cVar6 = '\x02';
      goto LAB_201168a0;
    }
  }
  uVar2 = hex_parse(param_1,8,&local_18);
  puVar4 = (uint *)(uint)uVar2;
  pbVar1 = (byte *)0x0;
  if (puVar4 != (uint *)0x0) {
    pbVar1 = local_18;
  }
  if (puVar4 == (uint *)0x0 || pbVar1 == (byte *)0x0) {
    return;
  }
  if (*pbVar1 == 0x20) {
    local_18 = pbVar1 + 1;
    uVar2 = hex_parse(local_18,8,&local_18);
    DAT_2080038c = (uint)uVar2;
    if (cVar6 == '\x01') {
      DAT_20800388 = puVar4;
      *(byte *)puVar4 = (byte)uVar2;
      goto LAB_201169a8;
    }
    if (cVar6 == '\x02') {
      DAT_20800388 = puVar4;
      *(ushort *)puVar4 = uVar2;
      goto LAB_20116980;
    }
    DAT_20800388 = puVar4;
    *puVar4 = DAT_2080038c;
  }
  else {
    if (*pbVar1 != 0) {
      return;
    }
    DAT_20800388 = puVar4;
    if (cVar6 == '\x01') {
LAB_201169a8:
      kbd_led_status(2,7);
      itron_dly_tsk(10);
      kbd_led_status(0,7);
      DAT_20800390 = (uint)(byte)*puVar4;
      return;
    }
    if (cVar6 == '\x02') {
LAB_20116980:
      kbd_led_status(2,7);
      itron_dly_tsk(10);
      kbd_led_status(0,7);
      DAT_20800390 = (uint)(ushort)*puVar4;
      return;
    }
  }
  kbd_led_status(7,7);
  itron_dly_tsk(10);
  kbd_led_status(0,7);
  DAT_20800390 = *puVar4;
  return;
}


// ===== cli_run_file @ 201169d0 (224 bytes)

uint cli_run_file(uint param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  bool bVar5;
  byte local_190 [252];
  undefined1 auStack_94 [4];
  undefined1 auStack_90 [64];
  undefined1 auStack_50 [64];
  
  uVar2 = strlen();
  if (3 < uVar2) {
    memcpy(auStack_90,param_1,0x40);
    iVar3 = strcasecmp(auStack_94 + uVar2,".txt");
    if (iVar3 == 0) {
      __aeabi_memcpy4(auStack_50,&DAT_20165984,0x40);
      strcat(auStack_50,auStack_90);
      uVar2 = fs_fopen((uint)auStack_50,0x20116b9c);
      if (uVar2 != 0) {
        while (iVar3 = fs_fgets(local_190,0x100,uVar2), iVar3 != 0) {
          uVar4 = 0;
          do {
            bVar1 = local_190[uVar4];
            bVar5 = 0xc < bVar1;
            if (bVar1 != 0xd) {
              bVar5 = 9 < bVar1;
            }
            if (bVar1 != 0xd && bVar1 != 10) {
              uVar4 = uVar4 + 1;
              bVar5 = 0xff < uVar4;
            }
            else {
              local_190[uVar4] = 0;
            }
          } while (!bVar5);
          cli_exec_line(local_190);
        }
        fs_fclose(uVar2);
        return 1;
      }
    }
  }
  return 0;
}


// ===== task_cli @ 20116ab0 (80 bytes)

/* memory monitor: "ADDR", "ADDR VAL", "b ADDR VAL", "h ADDR VAL", or NAME.txt = run I:\NAME.txt */

void task_cli(void)

{
  void *pvVar1;
  uint uVar2;
  uint in_r3;
  uint uStack_14;
  
  uStack_14 = in_r3;
  while (pvVar1 = itron_twai_flg(DAT_20800394,1,5,&uStack_14,-1), pvVar1 == (void *)0x0) {
    uVar2 = cli_run_file(0x208dbb24);
    if (uVar2 == 0) {
      cli_exec_line(&DAT_208dbb24);
    }
  }
  return;
}


// ===== cli_line @ 20116b00 (48 bytes)

void cli_line(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = hid_line_edit(&DAT_208dbb20,param_1,param_2);
  if (iVar1 == 0) {
    return;
  }
  itron_set_flg(DAT_20800394,1);
  return;
}


// ===== cli_init @ 20116b30 (92 bytes)

/* event flag + task "cli"; returns cli_line */

uint cli_init(void)

{
  uint uVar1;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  uVar1 = itron_acre_flg(0,(byte *)&local_10);
  if (((0 < (int)uVar1) &&
      (DAT_20800394 = uVar1, uVar1 = itron_acre_tsk(0,(byte *)&ctsk_cli), 0 < (int)uVar1)) &&
     (uVar1 = itron_sta_tsk(uVar1,0), uVar1 == 0)) {
    return 0x20116b00;
  }
  return 0;
}


// ===== FUN_20116bb0 @ 20116bb0 (76 bytes)

/* WARNING: Removing unreachable block (ram,0x20155380) */
/* WARNING: Removing unreachable block (ram,0x20155378) */
/* WARNING: Removing unreachable block (ram,0x2015524c) */
/* WARNING: Removing unreachable block (ram,0x20155240) */
/* WARNING: Removing unreachable block (ram,0x20155190) */
/* WARNING: Removing unreachable block (ram,0x2015519c) */
/* WARNING: Removing unreachable block (ram,0x201551a0) */
/* WARNING: Removing unreachable block (ram,0x201551a4) */
/* WARNING: Removing unreachable block (ram,0x201551a8) */
/* WARNING: Removing unreachable block (ram,0x201551ac) */
/* WARNING: Removing unreachable block (ram,0x201551b0) */
/* WARNING: Removing unreachable block (ram,0x20155188) */
/* WARNING: Removing unreachable block (ram,0x201551b4) */
/* WARNING: Removing unreachable block (ram,0x20155310) */
/* WARNING: Removing unreachable block (ram,0x2015531c) */
/* WARNING: Removing unreachable block (ram,0x20155324) */
/* WARNING: Removing unreachable block (ram,0x2015533c) */
/* WARNING: Removing unreachable block (ram,0x2015534c) */
/* WARNING: Removing unreachable block (ram,0x20155350) */
/* WARNING: Removing unreachable block (ram,0x20155358) */
/* WARNING: Removing unreachable block (ram,0x20155360) */
/* WARNING: Removing unreachable block (ram,0x20155368) */
/* WARNING: Removing unreachable block (ram,0x20155370) */
/* WARNING: Removing unreachable block (ram,0x201551bc) */
/* WARNING: Removing unreachable block (ram,0x201551c4) */
/* WARNING: Removing unreachable block (ram,0x201551f4) */
/* WARNING: Removing unreachable block (ram,0x2015520c) */
/* WARNING: Removing unreachable block (ram,0x201551d0) */
/* WARNING: Removing unreachable block (ram,0x20155214) */
/* WARNING: Removing unreachable block (ram,0x2015522c) */
/* WARNING: Removing unreachable block (ram,0x201551d4) */
/* WARNING: Removing unreachable block (ram,0x201551ec) */
/* WARNING: Removing unreachable block (ram,0x20155238) */
/* WARNING: Removing unreachable block (ram,0x20155244) */
/* WARNING: Removing unreachable block (ram,0x20155374) */
/* WARNING: Removing unreachable block (ram,0x2015537c) */
/* WARNING: Removing unreachable block (ram,0x20155384) */
/* WARNING: Removing unreachable block (ram,0x20155388) */

undefined8 FUN_20116bb0(undefined4 param_1,undefined4 param_2,uint param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)&DAT_18000000;
  if (g_bootinfo.bank == 1) {
    pcVar1 = FUN_18400000;
  }
  else {
    if (g_bootinfo.bank == 2) {
      pcVar1 = FUN_18a00000;
    }
    else {
      param_3 = 0xbbbb;
    }
    if (g_bootinfo.bank != 2 && g_bootinfo.bank != param_3) {
      return CONCAT44(g_bootinfo.bank,pcVar1);
    }
  }
  return CONCAT44(pcVar1 + 0x328840,BYTE_ARRAY_204286f8 + 0x148);
}


// ===== FUN_20116bfc @ 20116bfc (80 bytes)

undefined8 FUN_20116bfc(code *param_1,uint param_2)

{
  code *pcVar1;
  code *pcVar2;
  code *pcVar3;
  code cVar4;
  undefined2 uVar5;
  code *pcVar6;
  undefined4 uVar7;
  uint unaff_r4;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 uVar12;
  code cVar13;
  uint in_r12;
  uint uVar14;
  undefined4 uVar15;
  undefined4 uVar16;
  bool bVar17;
  bool bVar18;
  
  pcVar2 = (code *)&DAT_18000000;
  if (g_bootinfo.bank == 1) {
    pcVar2 = FUN_18400000;
  }
  else {
    if (g_bootinfo.bank != 2) {
      unaff_r4 = 0xbbbb;
    }
    else {
      pcVar2 = FUN_18a00000;
    }
    if (g_bootinfo.bank != 2 && g_bootinfo.bank != unaff_r4) {
      return CONCAT44(pcVar2,param_1);
    }
  }
  pcVar6 = param_1 + -0x20100000;
  pcVar2 = pcVar2 + (int)pcVar6;
  if (3 < param_2) {
    uVar14 = (uint)param_1 & 3;
    in_r12 = uVar14;
    if (uVar14 != 0) {
      cVar4 = *pcVar2;
      pcVar6 = pcVar2 + 1;
      if (uVar14 < 3) {
        pcVar6 = pcVar2 + 2;
        in_r12 = (uint)(byte)pcVar2[1];
      }
      *param_1 = cVar4;
      pcVar2 = pcVar6;
      if (uVar14 < 2) {
        pcVar2 = pcVar6 + 1;
        cVar4 = *pcVar6;
      }
      pcVar6 = param_1 + 1;
      if (uVar14 < 3) {
        pcVar6 = param_1 + 2;
        param_1[1] = SUB41(in_r12,0);
      }
      param_2 = (param_2 + uVar14) - 4;
      param_1 = pcVar6;
      if (uVar14 < 2) {
        param_1 = pcVar6 + 1;
        *pcVar6 = cVar4;
      }
    }
    pcVar6 = (code *)((uint)pcVar2 & 3);
    if (pcVar6 == (code *)0x0) {
      uVar14 = param_2 - 0x20;
      uVar7 = 0;
      if (0x1f < param_2) {
        for (; 0x7f < uVar14; uVar14 = uVar14 - 0x20) {
          HintPreloadData(pcVar2 + 0x80);
          uVar7 = *(undefined4 *)pcVar2;
          uVar8 = *(undefined4 *)(pcVar2 + 4);
          uVar9 = *(undefined4 *)(pcVar2 + 8);
          uVar10 = *(undefined4 *)(pcVar2 + 0xc);
          uVar11 = *(undefined4 *)(pcVar2 + 0x10);
          uVar12 = *(undefined4 *)(pcVar2 + 0x14);
          uVar15 = *(undefined4 *)(pcVar2 + 0x18);
          uVar16 = *(undefined4 *)(pcVar2 + 0x1c);
          pcVar2 = pcVar2 + 0x20;
          *(undefined4 *)param_1 = uVar7;
          *(undefined4 *)(param_1 + 4) = uVar8;
          *(undefined4 *)(param_1 + 8) = uVar9;
          *(undefined4 *)(param_1 + 0xc) = uVar10;
          *(undefined4 *)(param_1 + 0x10) = uVar11;
          *(undefined4 *)(param_1 + 0x14) = uVar12;
          *(undefined4 *)(param_1 + 0x18) = uVar15;
          *(undefined4 *)(param_1 + 0x1c) = uVar16;
          param_1 = param_1 + 0x20;
        }
        do {
          uVar7 = *(undefined4 *)pcVar2;
          uVar8 = *(undefined4 *)(pcVar2 + 4);
          uVar9 = *(undefined4 *)(pcVar2 + 8);
          uVar10 = *(undefined4 *)(pcVar2 + 0xc);
          uVar11 = *(undefined4 *)(pcVar2 + 0x10);
          uVar12 = *(undefined4 *)(pcVar2 + 0x14);
          uVar15 = *(undefined4 *)(pcVar2 + 0x18);
          uVar16 = *(undefined4 *)(pcVar2 + 0x1c);
          pcVar2 = pcVar2 + 0x20;
          bVar17 = 0x1f < uVar14;
          uVar14 = uVar14 - 0x20;
          *(undefined4 *)param_1 = uVar7;
          *(undefined4 *)(param_1 + 4) = uVar8;
          *(undefined4 *)(param_1 + 8) = uVar9;
          *(undefined4 *)(param_1 + 0xc) = uVar10;
          *(undefined4 *)(param_1 + 0x10) = uVar11;
          *(undefined4 *)(param_1 + 0x14) = uVar12;
          *(undefined4 *)(param_1 + 0x18) = uVar15;
          *(undefined4 *)(param_1 + 0x1c) = uVar16;
          param_1 = param_1 + 0x20;
        } while (bVar17);
      }
      if ((bool)((byte)(uVar14 >> 4) & 1)) {
        uVar7 = *(undefined4 *)pcVar2;
        uVar8 = *(undefined4 *)(pcVar2 + 4);
        uVar9 = *(undefined4 *)(pcVar2 + 8);
        uVar10 = *(undefined4 *)(pcVar2 + 0xc);
        pcVar2 = pcVar2 + 0x10;
        *(undefined4 *)param_1 = uVar7;
        *(undefined4 *)(param_1 + 4) = uVar8;
        *(undefined4 *)(param_1 + 8) = uVar9;
        *(undefined4 *)(param_1 + 0xc) = uVar10;
        param_1 = param_1 + 0x10;
      }
      if ((int)(uVar14 << 0x1c) < 0) {
        uVar7 = *(undefined4 *)pcVar2;
        uVar8 = *(undefined4 *)(pcVar2 + 4);
        pcVar2 = pcVar2 + 8;
        *(undefined4 *)param_1 = uVar7;
        *(undefined4 *)(param_1 + 4) = uVar8;
        param_1 = param_1 + 8;
      }
      pcVar1 = param_1;
      pcVar6 = pcVar2;
      if ((bool)((byte)(uVar14 >> 2) & 1)) {
        pcVar6 = pcVar2 + 4;
        uVar7 = *(undefined4 *)pcVar2;
        pcVar1 = param_1 + 4;
        *(undefined4 *)param_1 = uVar7;
      }
      uVar5 = (undefined2)uVar7;
      if ((uVar14 & 3) != 0) {
        bVar18 = (bool)((byte)(uVar14 >> 1) & 1);
        uVar14 = uVar14 << 0x1f;
        bVar17 = (int)uVar14 < 0;
        pcVar2 = pcVar6;
        if (bVar18) {
          pcVar2 = pcVar6 + 2;
          uVar5 = *(undefined2 *)pcVar6;
        }
        pcVar6 = pcVar2;
        if (bVar17) {
          pcVar6 = pcVar2 + 1;
          uVar14 = (uint)(byte)*pcVar2;
        }
        pcVar2 = pcVar1;
        if (bVar18) {
          pcVar2 = pcVar1 + 2;
          *(undefined2 *)pcVar1 = uVar5;
        }
        pcVar1 = pcVar2;
        if (bVar17) {
          pcVar1 = pcVar2 + 1;
          *pcVar2 = SUB41(uVar14,0);
        }
        return CONCAT44(pcVar6,pcVar1);
      }
      return CONCAT44(pcVar6,pcVar1);
    }
    bVar17 = 3 < param_2;
    param_2 = param_2 - 4;
    if (bVar17) {
      pcVar2 = pcVar2 + -(int)pcVar6;
      in_r12 = *(uint *)pcVar2;
      pcVar1 = param_1;
      if (pcVar6 == (code *)0x2) {
        do {
          pcVar3 = pcVar2;
          uVar14 = in_r12 >> 0x10;
          pcVar2 = pcVar3 + 4;
          in_r12 = *(uint *)pcVar2;
          bVar17 = 3 < param_2;
          param_2 = param_2 - 4;
          pcVar6 = (code *)(uVar14 | in_r12 << 0x10);
          param_1 = pcVar1 + 4;
          *(code **)pcVar1 = pcVar6;
          pcVar1 = param_1;
        } while (bVar17);
        pcVar2 = pcVar3 + 6;
      }
      else if (pcVar6 < (code *)0x3) {
        do {
          pcVar3 = pcVar2;
          uVar14 = in_r12 >> 8;
          pcVar2 = pcVar3 + 4;
          in_r12 = *(uint *)pcVar2;
          bVar17 = 3 < param_2;
          param_2 = param_2 - 4;
          pcVar6 = (code *)(uVar14 | in_r12 << 0x18);
          param_1 = pcVar1 + 4;
          *(code **)pcVar1 = pcVar6;
          pcVar1 = param_1;
        } while (bVar17);
        pcVar2 = pcVar3 + 5;
      }
      else {
        do {
          pcVar3 = pcVar2;
          uVar14 = in_r12 >> 0x18;
          pcVar2 = pcVar3 + 4;
          in_r12 = *(uint *)pcVar2;
          bVar17 = 3 < param_2;
          param_2 = param_2 - 4;
          pcVar6 = (code *)(uVar14 | in_r12 << 8);
          param_1 = pcVar1 + 4;
          *(code **)pcVar1 = pcVar6;
          pcVar1 = param_1;
        } while (bVar17);
        pcVar2 = pcVar3 + 7;
      }
    }
  }
  cVar13 = SUB41(in_r12,0);
  cVar4 = SUB41(pcVar6,0);
  bVar18 = (bool)((byte)(param_2 >> 1) & 1);
  param_2 = param_2 << 0x1f;
  bVar17 = (int)param_2 < 0;
  if (bVar18) {
    pcVar6 = pcVar2 + 1;
    cVar4 = *pcVar2;
    pcVar2 = pcVar2 + 2;
    cVar13 = *pcVar6;
  }
  pcVar6 = pcVar2;
  if (bVar17) {
    pcVar6 = pcVar2 + 1;
    param_2 = (uint)(byte)*pcVar2;
  }
  if (bVar18) {
    pcVar2 = param_1 + 1;
    *param_1 = cVar4;
    param_1 = param_1 + 2;
    *pcVar2 = cVar13;
  }
  pcVar2 = param_1;
  if (bVar17) {
    pcVar2 = param_1 + 1;
    *param_1 = SUB41(param_2,0);
  }
  return CONCAT44(pcVar6,pcVar2);
}


// ===== bootinfo_load @ 20116c4c (100 bytes)

/* copies the 0x60-byte boot-info block (pointer in SPIBSC1 reg 0x3FEFB018) or builds defaults */

void bootinfo_load(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = SPIBSC_DROPR_1;
  if (iVar1 == 0) {
    g_bootinfo.bank = 0;
    g_bootinfo.bank1_flag = 0x3e0000;
    g_bootinfo.bank1_image = 0x400000;
    g_bootinfo.bank2_flag = 0x3f0000;
    g_bootinfo.bank2_image = 0xa00000;
  }
  else {
    uVar2 = SPIBSC_DROPR_1;
    memcpy(&g_bootinfo,uVar2,0x60);
  }
  DAT_20800398 = g_bootinfo.bank;
  return;
}


// ===== cpg_early_init @ 20116ccc (172 bytes)

/* Reset_Handler: PL310 power ctrl, FRQCR 0x0035, FRQCR2 1, SYSCR3 0x0F, STBCR2..12 */

void cpg_early_init(void)

{
  L2C_REG15_POWER_CTRL = 1;
  CPG_FRQCR = 0x35;
  CPG_FRQCR2 = 1;
  CPG_SYSCR3 = 0xf;
  CPG_STBCR2 = 0x6a;
  CPG_STBCR3 = 0;
  CPG_STBCR4 = 0;
  CPG_STBCR5 = 0;
  CPG_STBCR6 = 0;
  CPG_STBCR7 = 0x24;
  CPG_STBCR8 = 5;
  CPG_STBCR9 = 0;
  CPG_STBCR10 = 0;
  CPG_STBCR11 = 0xc0;
  CPG_STBCR12 = 0xf0;
  gpio_early_init();
  gpio_rx_reset(0);
  return;
}


// ===== mmu_cache_enable @ 20116d84 (28 bytes)

/* SCTLR |= M|C|W bits (0xD) after setting TTBR/DACR */

undefined4 mmu_cache_enable(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 in_cr9;
  undefined4 in_cr12;
  undefined4 in_cr13;
  
  coprocessor_moveto(0xf,0,1,0x80000000,in_cr9,in_cr12);
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr12);
  coprocessor_moveto(0xf,0,0,uVar1 | 0xd,in_cr9,in_cr12);
  uVar2 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar2;
}


// ===== full_mode_set @ 20116da0 (12 bytes)

/* (v): 0x208003A4 = v (boot-rtos.md: force flag) [fact] */

void full_mode_set(undefined1 param_1)

{
  DAT_208003a4 = param_1;
  return;
}


// ===== full_mode_get @ 20116dac (12 bytes)

/* Returns the full-mode flag 0x208003A4 (input.md: matrix and ADC keys scanned only while set)
   [fact] */

undefined1 full_mode_get(void)

{
  return DAT_208003a4;
}


// ===== hid_chain1_dispatch @ 20116db8 (60 bytes)

/* calls the 9 debug handlers at 0x208DC1BC */

void hid_chain1_dispatch(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  kbd_set_current(param_1);
  iVar1 = 0;
  do {
    if ((code *)(&DAT_208dc1bc)[iVar1] != (code *)0x0) {
      (*(code *)(&DAT_208dc1bc)[iVar1])(param_1,param_2);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}


// ===== hid_chain0_dispatch @ 20116df4 (60 bytes)

/* calls the 9 handlers at 0x208DC198 (none registered in V01-08) */

void hid_chain0_dispatch(uint param_1,undefined4 param_2)

{
  int iVar1;
  
  kbd_set_current(param_1);
  iVar1 = 0;
  do {
    if ((code *)(&DAT_208dc198)[iVar1] != (code *)0x0) {
      (*(code *)(&DAT_208dc198)[iVar1])(param_1,param_2);
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 < 9);
  return;
}


// ===== gpio_p2_0_debounced @ 20116e30 (84 bytes)

/* reads P2_0 until 3 equal samples 10 ms apart */

bool gpio_p2_0_debounced(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar1 = gpio_read_bit(2,0);
  iVar3 = 0;
  do {
    itron_dly_tsk(10);
    uVar2 = gpio_read_bit(2,0);
    if (uVar2 != uVar1) {
      iVar3 = 0;
      uVar1 = uVar2;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return uVar1 != 0;
}


// ===== boot_mode_full @ 20116e84 (68 bytes)

/* returns 1 for the full application, 0 for the reduced (standby) start */

byte boot_mode_full(void)

{
  byte bVar1;
  
  bVar1 = key_scan_first();
  if (((bVar1 != 6) && (DAT_208003a4 == '\0')) && (DAT_208003a2 != '\0')) {
    return 0;
  }
  return 1;
}


// ===== power_on_full_init @ 20116ec8 (360 bytes)

/* standby -> full start: same init list as task_root full branch, run once (flag 0x208003A5) */

void power_on_full_init(void)

{
  undefined4 local_30;
  undefined4 local_2c;
  undefined1 *local_28;
  undefined4 local_24;
  undefined1 *local_20;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  undefined1 local_18 [8];
  
  local_30 = 0;
  local_2c = 0;
  local_24 = 0;
  local_1a = 0x80;
  local_1c = 0x80;
  local_1b = 0x80;
  local_28 = &local_1c;
  r_vdc5_display_calibration(0,(uint)&local_30);
  local_18[0] = 2;
  local_20 = local_18;
  r_vdc5_start_process(0,3,(uint)&local_20);
  local_18[0] = 3;
  local_20 = local_18;
  r_vdc5_start_process(0,4,(uint)&local_20);
  r_vdc5_start_process(0,5,(uint)&local_20);
  DAT_208003a0 = 1;
  full_mode_set(1);
  key_matrix_press_check();
  if (DAT_208003a5 == '\0') {
    gpio_p7_9_11(1);
    gpio_p8_14(1);
    lcd_power(1);
    cpg_set_clock_profile(1);
    dimmer_init();
    backlight_enable(0);
    backlight_init();
    usbkbd_init();
    mouse_cursor_init();
    usbh_ports_init();
    usbh_hid_class_init();
    usbh_hw_init();
    adc_start_scan();
    DAT_208dc1c0 = uptest_init();
    DAT_208dc1c8 = cli_init();
    touch_init();
    DAT_208dc1d0 = keycode_init();
    DAT_208dc1dc = kbdtest_init();
    renc_init();
    link_ss_irq_init();
    DAT_208dc1d8 = sdr_debug_init();
    spi_slave_init();
    fwupdate_init();
    sdmenu_init();
    DAT_208003a5 = '\x01';
    touch_cal_init();
    audio_codec_init();
    DAT_208003a0 = 1;
  }
  else {
    gpio_p7_9_11(1);
    gpio_p8_14(1);
    lcd_power(1);
  }
  return;
}


// ===== display_power_down @ 20117030 (152 bytes)

/* Radio off from the GUI side: clears the radio-on flag 0x208003A0, calls full_mode_set, LEDs off,
   stops the VDC5 layers; with P8_12 low it also pauses the key task and resets the FT4222, RX and
   QF lines, else switches the backlight and LCD power off; finally P7_9/P7_11 and P8_14 low [fact]
    */

void display_power_down(void)

{
  uint uVar1;
  
  DAT_208003a0 = 0;
  full_mode_set();
  led_set_one(0,0);
  led_set_mask(0);
  r_vdc5_stop_process(0,-1);
  uVar1 = gpio_read_bit(8,0xc);
  if (uVar1 == 0) {
    FUN_20116784();
    key_task_pause();
    itron_dly_tsk(100);
    gpio_ft4222_reset(0);
    gpio_rx_reset(0);
    gpio_qf_reset(1);
  }
  else {
    backlight_enable(0);
    lcd_power(0);
  }
  gpio_p7_9_11(0);
  gpio_p8_14(0);
  return;
}


// ===== task_root @ 201170c8 (356 bytes)

/* root task (pri 8), created by main; runs the whole init sequence */

void task_root(void)

{
  uint uVar1;
  int iVar2;
  
  DAT_20800110 = hid_chain0_dispatch;
  DAT_20800114 = hid_chain1_dispatch;
  bootinfo_load();
  fb_clear_all();
  rtc_init();
  sd_fs_init();
  DAT_208dc1bc = fwdbg_init();
  loader_selfinstall();
  DAT_208003a1 = gpio_p2_0_debounced();
  DAT_208003a2 = DAT_208003a1;
  uVar1 = gpio_read_bit(8,0xc);
  DAT_208003a3 = uVar1 != 0;
  powon_init();
  key_init();
  DAT_208003a0 = boot_mode_full();
  cpg_set_clock_profile((uint)DAT_208003a0);
  gpio_rx_reset(1);
  if (DAT_208003a0 == 0) {
    gpio_p8_14(0);
    mainlink_init();
    uVar1 = knl_current_task_id();
    periodic_wakeup_register(uVar1,0);
    iVar2 = periodic_wakeup_start();
    if (iVar2 != 0) {
      return;
    }
  }
  else {
    DAT_208003a5 = 1;
    gpio_p8_14(1);
    full_mode_set(1);
    dimmer_init();
    backlight_enable(0);
    backlight_init();
    usbkbd_init();
    mouse_cursor_init();
    usbh_ports_init();
    usbh_hid_class_init();
    usbh_hw_init();
    adc_start_scan();
    DAT_208dc1c0 = uptest_init();
    DAT_208dc1c8 = cli_init();
    touch_init();
    DAT_208dc1d0 = keycode_init();
    DAT_208dc1dc = kbdtest_init();
    mainlink_init();
    renc_init();
    link_ss_irq_init();
    DAT_208dc1d8 = sdr_debug_init();
    spi_slave_init();
    fwupdate_init();
    sdmenu_init();
    uVar1 = knl_current_task_id();
    periodic_wakeup_register(uVar1,0);
    iVar2 = periodic_wakeup_start();
    if (iVar2 != 0) {
      return;
    }
    touch_cal_init();
    audio_codec_init();
  }
  gui_start();
  return;
}


// ===== power_key_on @ 2011722c (56 bytes)

/* Power key: in standby sets 0x208003A0 = 1 (full mode) and clears 0x208003A1, else sets 0x20800493
   (input.md) [fact] */

void power_key_on(void)

{
  if (DAT_208003a0 != '\0') {
    DAT_20800493 = 1;
    return;
  }
  DAT_208003a1 = 0;
  DAT_208003a0 = 1;
  return;
}


// ===== FUN_20117254 @ 20117254 (12 bytes)

undefined1 FUN_20117254(void)

{
  return DAT_208003a2;
}


// ===== gpio_p8_12_high @ 20117260 (28 bytes)

/* Returns 1 when P8_12 reads high (gpio_read_bit(8, 12)); display_power_down branches on the same
   pin [fact] */

bool gpio_p8_12_high(void)

{
  uint uVar1;
  
  uVar1 = gpio_read_bit(8,0xc);
  return uVar1 != 0;
}


// ===== radio_on_flag_get @ 2011727c (12 bytes)

/* Returns the radio-on flag 0x208003A0 (radio_on_flag_set); mainlink_wait_status, gui_main_loop and
   task_mainlink_dispatch read it [fact] */

undefined1 radio_on_flag_get(void)

{
  return DAT_208003a0;
}


// ===== radio_on_flag_set @ 20117288 (12 bytes)

/* (v): 0x208003A0 = v; task_mainlink_dispatch sets 1 for CAT PS1 (mainlink.md 0x60) [fact] */

void radio_on_flag_set(undefined1 param_1)

{
  DAT_208003a0 = param_1;
  return;
}


// ===== main @ 20117294 (312 bytes)

/* called from __rt_entry; creates tasks then idles */

void main(void)

{
  uint uVar1;
  
  mmu_cache_enable();
  pinmux_init();
  gpio_p7_9_11(1);
  kernel_heap_init();
  uVar1 = itron_acre_tsk(0,(byte *)&ctsk_root);
  if ((int)uVar1 < 1) {
    return;
  }
  ostm_init();
  if (knl_sys.last_ercd != 0) {
    return;
  }
  knl_sys.dsp_state = 0;
  knl_sys.f_0x24_u32 = knl_sys.f_0x24_u32 & 0xffffff7f;
  do {
    if (knl_sys.dsp_state == 0) {
      knl_sys.f_0x34_u8 = 0;
    }
    else {
      knl_sys.f_0x34_u8 = knl_sys.f_0x36_u8;
    }
    software_interrupt(0);
    DAT_208dc17c = 9;
    if (knl_sys.idle_hook != 0) {
      (*(code *)knl_sys.idle_hook)();
    }
    uVar1 = 0xffffffff;
    while (knl_sys.tick_pending == 0) {
      if (uVar1 != 0) {
        uVar1 = uVar1 - 1;
      }
    }
    knl_sys.f_0x28_u32 = ~uVar1;
    software_interrupt(0);
    do {
      knl_sys.tick_lo = knl_sys.tick_lo + 1;
      if (knl_sys.tick_lo == 0) {
        knl_sys.tick_hi = knl_sys.tick_hi + 1;
      }
      knl_tick_task_timeouts();
      knl_tick_cyclic();
      knl_tick_table_dbf84();
      knl_sys.tick_pending = knl_sys.tick_pending - 1;
    } while (knl_sys.tick_pending != 0);
  } while( true );
}


// ===== __user_initial_stackheap @ 201172ec (20 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.850): retarget hook: r0 = heap base (two
   literals), r2 = r3; called by __user_setup_stackheap [inference] */

undefined4 __user_initial_stackheap(void)

{
  return 0x20a00000;
}


// ===== gic_set_priority @ 20117300 (60 bytes)

/* GICD_IPRIORITYR byte = prio << 3 */

void gic_set_priority(uint param_1,int param_2)

{
  *(uint *)((int)&INTC_ICDIPR0 + (param_1 & 0xfffffffc)) =
       *(uint *)((int)&INTC_ICDIPR0 + (param_1 & 0xfffffffc)) & ~(0xff << ((param_1 & 3) << 3)) |
       param_2 << (param_1 & 3) * 8 + 3;
  return;
}


// ===== gic_init @ 2011733c (592 bytes)

/* distributor/CPU interface set-up, 587 handler slots = gic_default_handler */

uint gic_init(void)

{
  int iVar1;
  
  INTC_ICCICR = 0;
  iVar1 = 0;
  do {
    (&INTC_ICDISR0)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x13);
  INTC_ICDICFR0 = 0xaaaaaaaa;
  INTC_ICDICFR1 = 0x55;
  INTC_ICDICFR2 = 0xfffd5555;
  INTC_ICDICFR3 = 0x555fffff;
  INTC_ICDICFR4 = 0x55555555;
  INTC_ICDICFR5 = 0x55555555;
  INTC_ICDICFR6 = 0x55555555;
  INTC_ICDICFR7 = 0x55555555;
  INTC_ICDICFR8 = 0x5555f555;
  INTC_ICDICFR9 = 0x55555555;
  INTC_ICDICFR10 = 0x55555555;
  INTC_ICDICFR11 = 0xf5555555;
  INTC_ICDICFR12 = 0xf555f555;
  INTC_ICDICFR13 = 0x5555f555;
  INTC_ICDICFR14 = 0x55555555;
  INTC_ICDICFR15 = 0x55555555;
  INTC_ICDICFR16 = 0x55555555;
  INTC_ICDICFR17 = 0xfd555555;
  INTC_ICDICFR18 = 0x55555557;
  INTC_ICDICFR19 = 0x55555555;
  INTC_ICDICFR20 = 0x55555555;
  INTC_ICDICFR21 = 0x5f555555;
  INTC_ICDICFR22 = 0xfd55555f;
  INTC_ICDICFR23 = 0x55555557;
  iVar1 = 0x18;
  do {
    (&INTC_ICDICFR0)[iVar1] = 0xffffffff;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x25);
  INTC_ICDIPR0 = 0x60687078;
  INTC_ICDIPR1 = 0x40485058;
  INTC_ICDIPR2 = 0x20283038;
  INTC_ICDIPR3 = 0x81018;
  iVar1 = 0x20;
  do {
    (&INTC_ICDIPR0)[iVar1 / 4] = 0xf8f8f8f8;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x247);
  iVar1 = 0;
  do {
    (&INTC_ICDICER0)[(int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x1b)) >> 5] = 0xffffffff;
    iVar1 = iVar1 + 0x20;
  } while (iVar1 < 0x22b);
  iVar1 = 0x20;
  do {
    (&INTC_ICDIPTR0)[iVar1 / 4] = 0x1010101;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x247);
  iVar1 = 0;
  do {
    (&DAT_208dc1e0)[iVar1] = gic_default_handler;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x24b);
  iVar1 = 0;
  do {
    (&DAT_208dcb0c)[iVar1] = 0;
    (&DAT_208dcb8c)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x20);
  DAT_20800404 = 0;
  INTC_ICCPMR = 0xf8;
  INTC_ICCICR = 3;
  INTC_ICDDCR = 1;
  DAT_20800408 = 0;
  return 0;
}


// ===== knl_addr_in_image @ 2011758c (40 bytes)

/* 1 if p is within __main .. 0x20428834 (the code and rodata image) [fact]; check of entry/name
   pointers in acre_* [inference] */

undefined4 knl_addr_in_image(code *param_1)

{
  undefined4 uVar1;
  
  if ((param_1 < __main) || ((code *)0x20428834 < param_1)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 1;
  }
  return uVar1;
}


// ===== isr_desc_check @ 201175b4 (40 bytes)

/* intno < 0x24B, prio < 0x20 */

uint isr_desc_check(int param_1)

{
  uint uVar1;
  
  if ((*(uint *)(param_1 + 8) < 0x24b) && (*(uint *)(param_1 + 0x10) < 0x20)) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffef;
  }
  return uVar1;
}


// ===== gic_install_isr_stub @ 201175dc (64 bytes)

/* copies a 0x58-byte ISR stub, sets priority and handler slot */

void gic_install_isr_stub(uint param_1,int param_2)

{
  FUN_20100f84(param_1,0x58);
  dcache_clean_range(param_1,0x58);
  gic_set_priority(*(uint *)(param_2 + 8),*(int *)(param_2 + 0x10));
  (&DAT_208dc1e0)[*(int *)(param_2 + 8)] = param_1;
  return;
}


// ===== gic_get_handler @ 2011761c (16 bytes)

uint gic_get_handler(int param_1)

{
  return (&DAT_208dc1e0)[*(int *)(param_1 + 8)];
}


// ===== gic_def_inh @ 2011762c (136 bytes)

/* (intno, {attr, handler, prio}) direct handler, no stub */

uint gic_def_inh(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (0x24a < param_1) {
    return 0xffffffef;
  }
  if (param_2 == 0) {
    uVar1 = knl_int_disable();
    (&DAT_208dc1e0)[param_1] = gic_default_handler;
    gic_set_priority(param_1,0x1f);
  }
  else {
    if (0x1f < *(uint *)(param_2 + 8)) {
      return 0xffffffef;
    }
    uVar1 = knl_int_disable();
    (&DAT_208dc1e0)[param_1] = *(undefined4 *)(param_2 + 4);
    gic_set_priority(param_1,*(int *)(param_2 + 8));
  }
  knl_int_restore(uVar1);
  return 0;
}


// ===== gic_dispatch @ 201176b4 (116 bytes)

/* IRQ_Handler -> handler table 0x208DC1E0 */

undefined4 gic_dispatch(void)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = (uint)DAT_20800404;
  if (uVar3 < 0x20) {
    uVar2 = INTC_ICCIAR;
    uVar2 = uVar2 & 0x3ff;
    if (uVar2 < 0x24b) {
      uVar1 = (&DAT_208dc1e0)[uVar2];
      (&DAT_208dcb8c)[uVar3] = uVar2;
      uVar2 = INTC_ICCPMR;
      (&DAT_208dcb0c)[uVar3] = uVar2 & 0xff;
      DAT_20800404 = DAT_20800404 + 1;
      uVar3 = INTC_ICCRPR;
      INTC_ICCPMR = uVar3 & 0xff;
      return uVar1;
    }
  }
  return 0;
}


// ===== gic_irq_exit @ 20117728 (52 bytes)

/* pops nesting stack, EOIR + PMR restore */

void gic_irq_exit(void)

{
  DAT_20800404 = DAT_20800404 - 1;
  INTC_ICCEOIR = (&DAT_208dcb8c)[DAT_20800404];
  INTC_ICCPMR = (&DAT_208dcb0c)[DAT_20800404];
  return;
}

