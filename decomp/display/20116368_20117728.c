// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== mainlink_stat_rx_resync @ 20116368 (20 bytes)

/* RX task resync counter (obj+0x38) */

undefined4 mainlink_stat_rx_resync(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_20450060 != 0) {
    uVar1 = *(undefined4 *)(DAT_20450060 + 0x38);
  }
  return uVar1;
}


// ===== mainlink_stat_nak_sent @ 2011637c (20 bytes)

/* RX task NAK counter (obj+0x48) */

undefined4 mainlink_stat_nak_sent(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_20450060 != 0) {
    uVar1 = *(undefined4 *)(DAT_20450060 + 0x48);
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
  int iVar4;
  uint uVar5;
  undefined4 unaff_r4;
  int *piVar6;
  uint uVar7;
  int iVar8;
  byte *pbVar9;
  undefined4 unaff_lr;
  bool bVar10;
  
  if ((DAT_2045004c == 0) || (0x40 < DAT_2045004c)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar8 = *(int *)(&DAT_208dbda4 + DAT_2045004c * 4);
  if (iVar8 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  for (pbVar9 = (byte *)(iVar8 + 9); uVar7 = (uint)*pbVar9, uVar7 == 0; pbVar9 = pbVar9 + 1) {
  }
  if (0xfd < uVar7) {
    *(uint *)(iVar8 + 4) = *(uint *)(iVar8 + 4) | 1;
    software_interrupt(0);
    return FUN_201567f4;
  }
  piVar6 = *(int **)(&DAT_208dbba0 + uVar7 * 4);
  uVar5 = (uint)*(byte *)((int)piVar6 + 7);
  bVar10 = uVar5 == uVar7;
  if (bVar10) {
    uVar5 = (uint)*(byte *)(iVar8 + 8);
  }
  if (!bVar10 || (uVar5 & 2) != 0) {
    bVar10 = false;
    uVar7 = *(uint *)(iVar8 + 4) | 1;
LAB_20150fa4:
    piVar6 = *(int **)(&DAT_208dbba0 + (uint)*pbVar9 * 4);
    bVar1 = *(byte *)((int)piVar6 + 7);
    uVar5 = (uint)*pbVar9;
    do {
      bVar2 = *(byte *)((int)piVar6 + 5);
      bVar3 = *(byte *)((int)piVar6 + 6);
      if ((bVar2 & 1) == 0) {
        if ((*(uint *)(*piVar6 + 8) & ~uVar7) == 0) goto LAB_2015109c;
      }
      else if ((*(uint *)(*piVar6 + 8) & uVar7) != 0) {
LAB_2015109c:
        **(uint **)(*piVar6 + 0xc) = uVar7;
        if ((bVar2 & 2) != 0) {
          FUN_20153ad4(piVar6,uVar5);
        }
        *(undefined1 *)((int)piVar6 + 5) = 0x10;
        if (*(char *)((int)piVar6 + 9) == '\0') {
          iVar4 = (int)(char)piVar6[1];
          if (iVar4 < DAT_208003df) {
            bVar10 = (bool)(bVar10 | iVar4 < DAT_208003df);
          }
          FUN_20153a38(&DAT_208dc18c + iVar4,piVar6,uVar5);
        }
        else {
          FUN_201539ec(piVar6,uVar5);
        }
        if ((bVar2 & 4) != 0) {
          *(undefined4 *)(iVar8 + 4) = 0;
          if (!bVar10) {
            software_interrupt(0);
            return FUN_201567f4;
          }
          software_interrupt(0);
          return FUN_2015655c;
        }
      }
      if (bVar1 == uVar5) goto LAB_2015116c;
      piVar6 = *(int **)(&DAT_208dbba0 + (uint)bVar3 * 4);
      uVar5 = (uint)bVar3;
    } while( true );
  }
  bVar1 = *(byte *)((int)piVar6 + 5);
  if ((bVar1 & 1) == 0) {
    uVar5 = *(uint *)(iVar8 + 4) | 1;
    if ((*(uint *)(*piVar6 + 8) & ~uVar5) != 0) goto LAB_20151030;
  }
  else {
    uVar5 = *(uint *)(iVar8 + 4) | 1;
    if ((*(uint *)(*piVar6 + 8) & uVar5) == 0) {
LAB_20151030:
      *(uint *)(iVar8 + 4) = uVar5;
      software_interrupt(0);
      return FUN_201567f4;
    }
  }
  **(uint **)(*piVar6 + 0xc) = uVar5;
  if ((bVar1 & 4) != 0) {
    uVar5 = 0;
  }
  *(uint *)(iVar8 + 4) = uVar5;
  if ((bVar1 & 2) != 0) {
    FUN_20153ad4(piVar6,uVar7);
  }
  *(undefined1 *)((int)piVar6 + 5) = 0x10;
  if (*(char *)((int)piVar6 + 9) == '\0') {
    iVar8 = piVar6[1];
    FUN_20153a38(&DAT_208dc18c + (char)iVar8,piVar6,uVar7,&DAT_208dc18c + (char)iVar8,unaff_r4,
                 unaff_lr);
    if ((int)DAT_208003df <= (int)(char)iVar8) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  FUN_201539ec();
  software_interrupt(0);
  return FUN_201567f4;
LAB_2015116c:
  do {
    pbVar9 = pbVar9 + 1;
  } while (*pbVar9 == 0);
  if (0xfd < *pbVar9) {
    *(uint *)(iVar8 + 4) = uVar7;
    if (!bVar10) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  goto LAB_20150fa4;
}


// ===== mainlink_init @ 201163a0 (300 bytes)

/* cmd_interval_sem / cmd_waiting_sem, binds SCIF5 */

void mainlink_init(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = os_create_sem_named(&DAT_20165860,"cmd_interval_sem");
  if (0 < iVar1) {
    DAT_20450054 = iVar1;
    FUN_201511e8();
  }
  iVar1 = itron_acre_tsk(0,&DAT_2016589c);
  periodic_wakeup_register(iVar1,3);
  if (0 < iVar1) {
    itron_sta_tsk(iVar1,0);
    iVar1 = os_create_sem_named(&DAT_20165870,"cmd_waiting_sem");
    if (0 < iVar1) {
      DAT_20450058 = iVar1;
      FUN_201511e8();
    }
    memclr(&DAT_2045fd40,0x103c0);
    DAT_20450060 = mainlink_obj_ctor(&DAT_2045fd40);
    iVar1 = itron_acre_tsk(0,&DAT_20165880);
    if ((0 < iVar1) && (iVar2 = itron_acre_flg(0,&DAT_201658b8), 0 < iVar2)) {
      *(int *)(DAT_20450060 + 0x14) = iVar2;
      uVar3 = scif5_get();
      *(undefined4 *)(DAT_20450060 + 0x10) = uVar3;
      itron_sta_tsk(iVar1);
      DAT_2045004c = itron_acre_flg(0,&DAT_201658f4);
      if ((0 < DAT_2045004c) &&
         (((iVar1 = itron_acre_tsk(0,&DAT_201658d8), 0 < iVar1 &&
           (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) &&
          (iVar1 = FUN_2014ec30(0,&DAT_201658c4), 0 < iVar1)))) {
        DAT_20450064 = iVar1;
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
  undefined4 uVar1;
  
  if (DAT_20450060 != 0) {
    if (param_1 == 0) {
      uVar1 = 0x4000;
    }
    else {
      uVar1 = 0x8000;
    }
    itron_set_flg(*(undefined4 *)(DAT_20450060 + 0x14),uVar1);
    if (param_1 == 0) {
      scif5_get(*(undefined4 *)(DAT_20450060 + 0x14));
      return;
    }
  }
  return;
}


// ===== mainlink_inject_rx @ 20116560 (148 bytes)

/* rename (was mainlink_send_cmd): builds a frame from the 0x2B-entry table length and posts it to
   the RX dispatcher mailbox, i.e. replays a frame locally; it does not transmit */

void mainlink_inject_rx(char *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = mainlink_disp_alloc(DAT_20450060 + 0x58);
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
    *(undefined2 *)(iVar1 + 4) = 0xaa;
    *(short *)(iVar1 + 6) = (short)iVar3;
    memcpy(iVar1 + 8,param_1);
    FUN_20162d3c(DAT_20450060 + 0x58,*(undefined4 *)(DAT_20450060 + 0x81f4),iVar1);
    return;
  }
  return;
}


// ===== mainlink_hello_poweron @ 201165f4 (108 bytes)

/* sends F0 every 5 ms (max 30) with the power-up key code until MAIN ACKs */

void mainlink_hello_poweron(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  key_task_pause();
  DAT_20450026 = 0;
  iVar1 = key_scan_first();
  if (iVar1 == 0) {
    if (DAT_208003a1 == '\0') {
      DAT_208003a1 = '\x01';
    }
    else {
      iVar1 = 0x10;
    }
  }
  DAT_20450028 = '\0';
  iVar2 = 0x1d;
  do {
    mainlink_send_hello(iVar1);
    itron_dly_tsk(5);
    if (DAT_20450028 != '\0') {
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
  memclr(&DAT_2045fb00,0x240);
  DAT_20450026 = 0;
  FUN_20163684(&DAT_2045006d);
  DAT_20450024 = 0;
  return;
}


// ===== mainlink_hello_key6 @ 2011668c (60 bytes)

/* same as mainlink_hello_poweron with key code 6 */

void mainlink_hello_key6(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0x1d;
  DAT_20450028 = '\0';
  do {
    mainlink_send_hello(6);
    itron_dly_tsk(5);
    if (DAT_20450028 != '\0') {
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

void usbhid_report_event(undefined4 param_1,int *param_2)

{
  if (*param_2 == 6) {
    usbkbd_report();
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

void periodic_wakeup_register(undefined4 param_1,int param_2)

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
    FUN_20156260((&DAT_208dbadc)[iVar2 * 4],(&DAT_208dbad8)[iVar2 * 4]);
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
  int iVar2;
  
  Ramfcfec400 = 31999;
  bVar1 = UNK_fcfec420;
  UNK_fcfec420 = bVar1 & 0xfd;
  UNK_fcfec420 = 1;
  iVar2 = itron_acre_isr(0,&DAT_20165954);
  if (iVar2 < 1) {
    return iVar2;
  }
  gic_enable_irq(0x87);
  bVar1 = DAT_fcfec414;
  DAT_fcfec414 = bVar1 | 1;
  return 0;
}


// ===== cli_exec_line @ 20116848 (392 bytes)

void cli_exec_line(char *param_1,undefined4 param_2,undefined4 param_3,char *param_4)

{
  char *pcVar1;
  uint uVar2;
  ushort *puVar3;
  bool bVar4;
  char cVar5;
  char *local_18;
  
  cVar5 = false;
  local_18 = param_4;
  uVar2 = FUN_20155122();
  bVar4 = uVar2 == 2;
  if (1 < uVar2) {
    bVar4 = *param_1 == 'b';
  }
  if ((bVar4) && (cVar5 = param_1[1] == ' ', (bool)cVar5)) {
LAB_201168a0:
    param_1 = param_1 + 2;
  }
  else {
    uVar2 = FUN_20155122(param_1);
    bVar4 = uVar2 == 2;
    if (1 < uVar2) {
      bVar4 = *param_1 == 'h';
    }
    if ((bVar4) && (param_1[1] == ' ')) {
      cVar5 = '\x02';
      goto LAB_201168a0;
    }
  }
  puVar3 = (ushort *)hex_parse(param_1,8,&local_18);
  pcVar1 = (char *)0x0;
  if (puVar3 != (ushort *)0x0) {
    pcVar1 = local_18;
  }
  if (puVar3 == (ushort *)0x0 || pcVar1 == (char *)0x0) {
    return;
  }
  if (*pcVar1 == ' ') {
    local_18 = pcVar1 + 1;
    DAT_2080038c = hex_parse(local_18,8,&local_18);
    if (cVar5 == '\x01') {
      DAT_20800388 = puVar3;
      *(byte *)puVar3 = (byte)DAT_2080038c;
      goto LAB_201169a8;
    }
    if (cVar5 == '\x02') {
      DAT_20800388 = puVar3;
      *puVar3 = (ushort)DAT_2080038c;
      goto LAB_20116980;
    }
    DAT_20800388 = puVar3;
    *(undefined4 *)puVar3 = DAT_2080038c;
  }
  else {
    if (*pcVar1 != '\0') {
      return;
    }
    DAT_20800388 = puVar3;
    if (cVar5 == '\x01') {
LAB_201169a8:
      kbd_led_status(2,7);
      itron_dly_tsk(10);
      kbd_led_status(0,7);
      DAT_20800390 = (uint)(byte)*puVar3;
      return;
    }
    if (cVar5 == '\x02') {
LAB_20116980:
      kbd_led_status(2,7);
      itron_dly_tsk(10);
      kbd_led_status(0,7);
      DAT_20800390 = (uint)*puVar3;
      return;
    }
  }
  kbd_led_status(7);
  itron_dly_tsk(10);
  kbd_led_status(0,7);
  DAT_20800390 = *(undefined4 *)puVar3;
  return;
}


// ===== cli_run_file @ 201169d0 (224 bytes)

undefined4 cli_run_file(undefined4 param_1)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  byte local_190 [252];
  undefined1 auStack_94 [4];
  undefined1 auStack_90 [64];
  undefined1 auStack_50 [64];
  
  uVar2 = FUN_20155122();
  if (3 < uVar2) {
    memcpy(auStack_90,param_1,0x40);
    iVar3 = FUN_2014e208(auStack_94 + uVar2,".txt");
    if (iVar3 == 0) {
      FUN_20155310(auStack_50,&DAT_20165984,0x40);
      FUN_2015515c(auStack_50,auStack_90);
      iVar3 = fs_fopen(auStack_50,&DWORD_20116b9c);
      if (iVar3 != 0) {
        while (iVar4 = FUN_20142390(local_190,0x100,iVar3), iVar4 != 0) {
          uVar2 = 0;
          do {
            bVar1 = local_190[uVar2];
            bVar5 = 0xc < bVar1;
            if (bVar1 != 0xd) {
              bVar5 = 9 < bVar1;
            }
            if (bVar1 != 0xd && bVar1 != 10) {
              uVar2 = uVar2 + 1;
              bVar5 = 0xff < uVar2;
            }
            else {
              local_190[uVar2] = 0;
            }
          } while (!bVar5);
          cli_exec_line(local_190);
        }
        FUN_20141ff0(iVar3);
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
  int iVar1;
  undefined4 in_r3;
  undefined4 uStack_14;
  
  uStack_14 = in_r3;
  while (iVar1 = itron_twai_flg(DAT_20800394,1,5,&uStack_14,0xffffffff), iVar1 == 0) {
    iVar1 = cli_run_file();
    if (iVar1 == 0) {
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

undefined8 cli_init(void)

{
  int iVar1;
  code *pcVar2;
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 uStack_8;
  
  local_10 = 2;
  uStack_c = 0;
  uStack_8 = 0;
  iVar1 = itron_acre_flg(0,&local_10);
  if (0 < iVar1) {
    DAT_20800394 = iVar1;
    iVar1 = itron_acre_tsk(0,&DAT_20165968);
    if ((0 < iVar1) && (iVar1 = itron_sta_tsk(iVar1,0), iVar1 == 0)) {
      pcVar2 = cli_line;
      goto LAB_20116b88;
    }
  }
  pcVar2 = (code *)0x0;
LAB_20116b88:
  return CONCAT44(local_10,pcVar2);
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

undefined8 FUN_20116bb0(undefined4 param_1,undefined4 param_2,int param_3)

{
  code *pcVar1;
  
  pcVar1 = (code *)&DAT_18000000;
  if (DAT_208dbb44 == 1) {
    pcVar1 = FUN_18400000;
  }
  else {
    if (DAT_208dbb44 == 2) {
      pcVar1 = FUN_18a00000;
    }
    else {
      param_3 = 0xbbbb;
    }
    if (DAT_208dbb44 != 2 && DAT_208dbb44 != param_3) {
      return CONCAT44(DAT_208dbb44,pcVar1);
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
  int unaff_r4;
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
  if (DAT_208dbb44 == 1) {
    pcVar2 = FUN_18400000;
  }
  else {
    if (DAT_208dbb44 != 2) {
      unaff_r4 = 0xbbbb;
    }
    else {
      pcVar2 = FUN_18a00000;
    }
    if (DAT_208dbb44 != 2 && DAT_208dbb44 != unaff_r4) {
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
  
  iVar1 = DAT_3fefb018;
  if (iVar1 == 0) {
    DAT_208dbb44 = 0;
    DAT_208dbb64 = 0x3e0000;
    DAT_208dbb68 = 0x400000;
    DAT_208dbb84 = 0x3f0000;
    DAT_208dbb88 = 0xa00000;
  }
  else {
    uVar2 = DAT_3fefb018;
    memcpy(&DAT_208dbb44,uVar2,0x60);
  }
  DAT_20800398 = DAT_208dbb44;
  return;
}


// ===== cpg_early_init @ 20116ccc (172 bytes)

/* Reset_Handler: PL310 power ctrl, FRQCR 0x0035, FRQCR2 1, SYSCR3 0x0F, STBCR2..12 */

void cpg_early_init(void)

{
  DAT_3fffff80 = 1;
  DAT_fcfe0010 = 0x35;
  DAT_fcfe0014 = 1;
  DAT_fcfe0408 = 0xf;
  DAT_fcfe0024 = 0x6a;
  DAT_fcfe0420 = 0;
  DAT_fcfe0424 = 0;
  DAT_fcfe0428 = 0;
  DAT_fcfe042c = 0;
  DAT_fcfe0430 = 0x24;
  DAT_fcfe0434 = 5;
  DAT_fcfe0438 = 0;
  DAT_fcfe043c = 0;
  DAT_fcfe0440 = 0xc0;
  DAT_fcfe0444 = 0xf0;
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


// ===== FUN_20116da0 @ 20116da0 (12 bytes)

void FUN_20116da0(undefined1 param_1)

{
  DAT_208003a4 = param_1;
  return;
}


// ===== FUN_20116dac @ 20116dac (12 bytes)

undefined1 FUN_20116dac(void)

{
  return DAT_208003a4;
}


// ===== hid_chain1_dispatch @ 20116db8 (60 bytes)

/* calls the 9 debug handlers at 0x208DC1BC */

void hid_chain1_dispatch(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  kbd_set_current();
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

void hid_chain0_dispatch(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  kbd_set_current();
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
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = gpio_read_bit(2,0);
  iVar3 = 0;
  do {
    itron_dly_tsk(10);
    iVar2 = gpio_read_bit(2,0);
    if (iVar2 != iVar1) {
      iVar3 = 0;
      iVar1 = iVar2;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return iVar1 != 0;
}


// ===== boot_mode_full @ 20116e84 (68 bytes)

/* returns 1 for the full application, 0 for the reduced (standby) start */

undefined1 boot_mode_full(void)

{
  int iVar1;
  
  iVar1 = key_scan_first();
  if (((iVar1 != 6) && (DAT_208003a4 == '\0')) && (DAT_208003a2 != '\0')) {
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
  r_vdc5_display_calibration(0,&local_30);
  local_18[0] = 2;
  local_20 = local_18;
  r_vdc5_start_process(0,3,&local_20);
  local_18[0] = 3;
  local_20 = local_18;
  r_vdc5_start_process(0,4,&local_20);
  r_vdc5_start_process(0,5,&local_20);
  DAT_208003a0 = 1;
  FUN_20116da0(1);
  key_matrix_press_check();
  if (DAT_208003a5 == '\0') {
    gpio_p7_9_11(1);
    gpio_p8_14(1);
    lcd_power(1);
    cpg_set_clock_profile(1);
    dimmer_init();
    backlight_enable(0);
    backlight_init();
    FUN_20107e9c();
    mouse_cursor_init();
    FUN_201385b4();
    FUN_2013b97c();
    FUN_2013b4cc();
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


// ===== FUN_20117030 @ 20117030 (152 bytes)

void FUN_20117030(void)

{
  int iVar1;
  
  DAT_208003a0 = 0;
  FUN_20116da0();
  led_set_one(0);
  led_set_mask(0);
  r_vdc5_stop_process(0,0xffffffff);
  iVar1 = gpio_read_bit(8,0xc);
  if (iVar1 == 0) {
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
  int iVar1;
  undefined4 uVar2;
  
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
  iVar1 = gpio_read_bit(8,0xc);
  DAT_208003a3 = iVar1 != 0;
  powon_init();
  key_init();
  DAT_208003a0 = boot_mode_full(DAT_208003a2,DAT_208003a3);
  cpg_set_clock_profile();
  gpio_rx_reset(1);
  if (DAT_208003a0 == '\0') {
    gpio_p8_14(0);
    mainlink_init();
    uVar2 = FUN_2014e710();
    periodic_wakeup_register(uVar2,0);
    iVar1 = periodic_wakeup_start();
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    DAT_208003a5 = 1;
    gpio_p8_14();
    FUN_20116da0(1);
    dimmer_init();
    backlight_enable(0);
    backlight_init();
    FUN_20107e9c();
    mouse_cursor_init();
    FUN_201385b4();
    FUN_2013b97c();
    FUN_2013b4cc();
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
    uVar2 = FUN_2014e710();
    periodic_wakeup_register(uVar2,0);
    iVar1 = periodic_wakeup_start();
    if (iVar1 != 0) {
      return;
    }
    touch_cal_init();
    audio_codec_init();
  }
  gui_start();
  return;
}


// ===== FUN_2011722c @ 2011722c (56 bytes)

void FUN_2011722c(void)

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


// ===== FUN_20117260 @ 20117260 (28 bytes)

bool FUN_20117260(void)

{
  int iVar1;
  
  iVar1 = gpio_read_bit(8,0xc);
  return iVar1 != 0;
}


// ===== FUN_2011727c @ 2011727c (12 bytes)

undefined1 FUN_2011727c(void)

{
  return DAT_208003a0;
}


// ===== FUN_20117288 @ 20117288 (12 bytes)

void FUN_20117288(undefined1 param_1)

{
  DAT_208003a0 = param_1;
  return;
}


// ===== main @ 20117294 (312 bytes)

/* called from __rt_entry; creates tasks then idles */

void main(void)

{
  int iVar1;
  uint uVar2;
  
  mmu_cache_enable();
  pinmux_init();
  gpio_p7_9_11(1);
  kernel_heap_init();
  iVar1 = itron_acre_tsk(0,&DAT_20165a44);
  if (iVar1 < 1) {
    return;
  }
  ostm_init();
  if (DAT_208003d4 != 0) {
    return;
  }
  DAT_208003db = '\0';
  DAT_208003cc = DAT_208003cc & 0xffffff7f;
  do {
    if (DAT_208003db == '\0') {
      DAT_208003dc = 0;
    }
    else {
      DAT_208003dc = DAT_208003de;
    }
    software_interrupt(0);
    DAT_208dc17c = 9;
    if (DAT_208003b0 != (code *)0x0) {
      (*DAT_208003b0)();
    }
    uVar2 = 0xffffffff;
    while (DAT_208003dd == '\0') {
      if (uVar2 != 0) {
        uVar2 = uVar2 - 1;
      }
    }
    DAT_208003d0 = ~uVar2;
    software_interrupt(0);
    do {
      DAT_208003c8 = DAT_208003c8 + 1;
      if (DAT_208003c8 == 0) {
        DAT_208003c4 = DAT_208003c4 + 1;
      }
      FUN_201540c4();
      FUN_20153788();
      FUN_20153620();
      DAT_208003dd = DAT_208003dd + -1;
    } while (DAT_208003dd != '\0');
  } while( true );
}


// ===== FUN_201172ec @ 201172ec (20 bytes)

undefined4 FUN_201172ec(void)

{
  return 0x20a00000;
}


// ===== gic_set_priority @ 20117300 (60 bytes)

/* GICD_IPRIORITYR byte = prio << 3 */

void gic_set_priority(uint param_1,int param_2)

{
  *(uint *)((int)&DAT_e8201400 + (param_1 & 0xfffffffc)) =
       *(uint *)((int)&DAT_e8201400 + (param_1 & 0xfffffffc)) & ~(0xff << ((param_1 & 3) << 3)) |
       param_2 << (param_1 & 3) * 8 + 3;
  return;
}


// ===== gic_init @ 2011733c (592 bytes)

/* distributor/CPU interface set-up, 587 handler slots = gic_default_handler */

undefined4 gic_init(void)

{
  int iVar1;
  
  DAT_e8202000 = 0;
  iVar1 = 0;
  do {
    (&DAT_e8201080)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x13);
  DAT_e8201c00 = 0xaaaaaaaa;
  DAT_e8201c04 = 0x55;
  DAT_e8201c08 = 0xfffd5555;
  DAT_e8201c0c = 0x555fffff;
  DAT_e8201c10 = 0x55555555;
  DAT_e8201c14 = 0x55555555;
  DAT_e8201c18 = 0x55555555;
  DAT_e8201c1c = 0x55555555;
  DAT_e8201c20 = 0x5555f555;
  DAT_e8201c24 = 0x55555555;
  DAT_e8201c28 = 0x55555555;
  DAT_e8201c2c = 0xf5555555;
  DAT_e8201c30 = 0xf555f555;
  DAT_e8201c34 = 0x5555f555;
  DAT_e8201c38 = 0x55555555;
  DAT_e8201c3c = 0x55555555;
  DAT_e8201c40 = 0x55555555;
  DAT_e8201c44 = 0xfd555555;
  DAT_e8201c48 = 0x55555557;
  DAT_e8201c4c = 0x55555555;
  DAT_e8201c50 = 0x55555555;
  DAT_e8201c54 = 0x5f555555;
  DAT_e8201c58 = 0xfd55555f;
  DAT_e8201c5c = 0x55555557;
  iVar1 = 0x18;
  do {
    (&DAT_e8201c00)[iVar1] = 0xffffffff;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 0x25);
  DAT_e8201400 = 0x60687078;
  DAT_e8201404 = 0x40485058;
  DAT_e8201408 = 0x20283038;
  DAT_e820140c = 0x81018;
  iVar1 = 0x20;
  do {
    (&DAT_e8201400)[iVar1 / 4] = 0xf8f8f8f8;
    iVar1 = iVar1 + 4;
  } while (iVar1 < 0x247);
  iVar1 = 0;
  do {
    (&DAT_e8201180)[(int)(iVar1 + ((uint)(iVar1 >> 0x1f) >> 0x1b)) >> 5] = 0xffffffff;
    iVar1 = iVar1 + 0x20;
  } while (iVar1 < 0x22b);
  iVar1 = 0x20;
  do {
    *(undefined4 *)(&UNK_e8201800 + (iVar1 / 4) * 4) = 0x1010101;
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
  DAT_e8202004 = 0xf8;
  DAT_e8202000 = 3;
  DAT_e8201000 = 1;
  DAT_20800408 = 0;
  return 0;
}


// ===== FUN_2011758c @ 2011758c (40 bytes)

undefined4 FUN_2011758c(code *param_1)

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

undefined4 isr_desc_check(int param_1)

{
  undefined4 uVar1;
  
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

void gic_install_isr_stub(undefined4 param_1,int param_2)

{
  FUN_20100f84(param_1,0x58);
  FUN_20101030(param_1,0x58);
  gic_set_priority(*(undefined4 *)(param_2 + 8),*(undefined4 *)(param_2 + 0x10));
  (&DAT_208dc1e0)[*(int *)(param_2 + 8)] = param_1;
  return;
}


// ===== gic_get_handler @ 2011761c (16 bytes)

undefined4 gic_get_handler(int param_1)

{
  return (&DAT_208dc1e0)[*(int *)(param_1 + 8)];
}


// ===== gic_def_inh @ 2011762c (136 bytes)

/* (intno, {attr, handler, prio}) direct handler, no stub */

undefined4 gic_def_inh(uint param_1,int param_2)

{
  undefined4 uVar1;
  
  if (0x24a < param_1) {
    return 0xffffffef;
  }
  if (param_2 == 0) {
    uVar1 = FUN_2015686c();
    (&DAT_208dc1e0)[param_1] = gic_default_handler;
    gic_set_priority(param_1,0x1f);
  }
  else {
    if (0x1f < *(uint *)(param_2 + 8)) {
      return 0xffffffef;
    }
    uVar1 = FUN_2015686c();
    (&DAT_208dc1e0)[param_1] = *(undefined4 *)(param_2 + 4);
    gic_set_priority(param_1,*(undefined4 *)(param_2 + 8));
  }
  FUN_2015688c(uVar1);
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
    uVar2 = DAT_e820200c;
    uVar2 = uVar2 & 0x3ff;
    if (uVar2 < 0x24b) {
      uVar1 = (&DAT_208dc1e0)[uVar2];
      (&DAT_208dcb8c)[uVar3] = uVar2;
      uVar2 = DAT_e8202004;
      (&DAT_208dcb0c)[uVar3] = uVar2 & 0xff;
      DAT_20800404 = DAT_20800404 + 1;
      uVar3 = DAT_e8202014;
      DAT_e8202004 = uVar3 & 0xff;
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
  DAT_e8202010 = (&DAT_208dcb8c)[DAT_20800404];
  DAT_e8202004 = (&DAT_208dcb0c)[DAT_20800404];
  return;
}

