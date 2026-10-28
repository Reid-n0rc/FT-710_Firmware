// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20115c74 @ 20115c74 (136 bytes)

void FUN_20115c74(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  char cVar3;
  int iVar4;
  
  iVar1 = FUN_20158630(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(undefined2 *)(iVar1 + 6) = 7;
  *(undefined1 *)(iVar1 + 8) = 0xe1;
  FUN_201636cc(iVar1 + 9,param_1);
  cVar3 = '\0';
  uVar2 = 0;
  do {
    iVar4 = iVar1 + uVar2;
    uVar2 = uVar2 + 1;
    cVar3 = cVar3 + *(char *)(iVar4 + 8);
  } while (uVar2 < 6);
  *(char *)((uint)*(ushort *)(iVar1 + 6) + iVar1 + 7) = cVar3;
  FUN_20158744(DAT_20450060 + 0x8218,iVar1);
  return;
}


// ===== FUN_20115cfc @ 20115cfc (608 bytes)

void FUN_20115cfc(void)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_2045f240 == '\x01') {
    FUN_201150f8(&DAT_20470100,8);
    DAT_20470100 = 0;
    DAT_20470104 = 0;
    DAT_2045f240 = 0;
    return;
  }
  if (DAT_2045f241 == '\x01') {
    FUN_201150f8(&DAT_20470108,4);
    DAT_20470108 = 0;
    DAT_2045f241 = 0;
    return;
  }
  if (DAT_2045f242 == '\x01') {
    FUN_201150f8(&DAT_2047010c,4);
    DAT_2047010c = 0;
    DAT_2045f242 = 0;
    return;
  }
  if (DAT_2045f243 == '\x01') {
    FUN_201150f8(&DAT_20470110,7);
    memclr(&DAT_20470110,7);
    DAT_2045f243 = 0;
    return;
  }
  if (DAT_2045f244 == '\x01') {
    uVar1 = DAT_2045002f + 1 & 0xff;
    uVar2 = uVar1 % 10;
    DAT_2045002f = (byte)uVar2;
    FUN_201150f8(uVar2 * 5 + 0x20470117,5,uVar1 * -0x33333333);
    uVar1 = (uint)DAT_2045002f;
    FUN_20163668(uVar1 * 5 + 0x20470117);
    if (DAT_2045002e == uVar1) {
      DAT_2045f244 = '\0';
    }
    return;
  }
  if (DAT_2045f245 == '\x01') {
    FUN_201150f8(&DAT_20470149,6);
    FUN_20163684(&DAT_20470149);
    DAT_2045f245 = 0;
    return;
  }
  if (DAT_2045f246 == '\x01') {
    FUN_201150f8(&DAT_2047014f,4);
    DAT_2047014f = 0;
    DAT_20470150 = 0;
    DAT_20470151 = 0;
    DAT_20470152 = 0;
    DAT_2045f246 = 0;
    return;
  }
  if (DAT_2045f247 != '\x01') {
    if (DAT_2045f248 == '\x01') {
      FUN_201150f8(&DAT_2047015c,9);
      FUN_201636b8(&DAT_2047015c);
      DAT_2045f248 = 0;
      return;
    }
    if (DAT_2045f249 != '\x01') {
      if (DAT_2045f24a != '\x01') {
        if (DAT_2045f24b == '\x01') {
          FUN_201150f8(&DAT_2047028d,6);
          FUN_20163684(&DAT_2047028d);
          DAT_2045f24b = '\0';
        }
        return;
      }
      FUN_201150f8(&DAT_20470187,0x106);
      FUN_20155274(&DAT_20470187,0x106);
      DAT_2045f24a = 0;
      return;
    }
    FUN_201150f8(&DAT_20470165,0x22);
    FUN_20155274(&DAT_20470165,0x22);
    DAT_2045f249 = 0;
    return;
  }
  FUN_201150f8(&DAT_20470153,9);
  FUN_20155274(&DAT_20470153,9);
  DAT_2045f247 = 0;
  return;
}


// ===== FUN_20115f5c @ 20115f5c (248 bytes)

void FUN_20115f5c(void)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 auStack_28 [12];
  
  uVar3 = 8;
  FUN_20152bb0(DAT_20450058,0xffffffff);
  uVar1 = 0;
  do {
    if (((uint)DAT_2045002b & 1 << (uVar1 & 0xff)) != 0) {
      uVar3 = uVar1;
      if ((int)(&DAT_2045f224)[uVar1] < 2) {
        DAT_2045002b = DAT_2045002b & ~(byte)(1 << (uVar1 & 0xff));
      }
      break;
    }
    uVar1 = uVar1 + 1;
  } while ((int)uVar1 < 7);
  if (7 < (int)uVar3) {
    DAT_2045002b = 0;
    FUN_20163668(&DAT_2045f0c5 + (&DAT_2045f224)[uVar3] * 5 + uVar3 * 0x32);
    return;
  }
  FUN_201636cc(auStack_28);
  iVar4 = (&DAT_2045f224)[uVar3];
  iVar2 = 0;
  if (0 < iVar4) {
    do {
      FUN_201636cc(&DAT_2045f0c5 + iVar2 * 5 + uVar3 * 0x32,
                   &DAT_2045f0c5 + iVar2 * 5 + uVar3 * 0x32 + 5);
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  (&DAT_2045f224)[uVar3] = iVar4 + -1;
  FUN_201511e8(DAT_20450058);
  FUN_20115780(auStack_28);
  return;
}


// ===== FUN_2011606c @ 2011606c (72 bytes)

void FUN_2011606c(void)

{
  if (DAT_2045002a != '\0') {
    FUN_2014eb94(DAT_2045004c,0);
    FUN_20151878(DAT_20450064);
    DAT_2045002a = '\0';
    FUN_20115cfc();
    if (DAT_2045002b != '\0') {
      FUN_20115f5c();
    }
    DAT_2045002c = 0;
  }
  return;
}


// ===== FUN_201160b4 @ 201160b4 (140 bytes)

void FUN_201160b4(void)

{
  undefined4 uVar1;
  int iVar2;
  
  if (DAT_2045002a != '\0') {
    FUN_20151878(DAT_20450064);
    if (2 < DAT_2045002c) {
      if (DAT_20450029 != '\0') {
        uVar1 = FUN_201150ec();
        FUN_201309c0(0,uVar1);
        return;
      }
      FUN_20114df4();
      return;
    }
    iVar2 = FUN_201150ec();
    if (iVar2 == 0xe1) {
      FUN_20115c74(&DAT_20450068);
    }
    else {
      FUN_20115be0(&DAT_2045efc0,DAT_20450038);
    }
    FUN_20151680(DAT_20450064);
    DAT_2045002c = DAT_2045002c + 1;
  }
  return;
}


// ===== FUN_20116140 @ 20116140 (124 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_20116140(void)

{
  int iVar1;
  int iVar2;
  
  FUN_2014eb94(DAT_2045004c,0);
  FUN_20151878(DAT_20450064);
  DAT_2045002a = 0;
  iVar2 = 0;
  DAT_2045002b = 0;
  DAT_2045002c = 0;
  _DAT_2045f240 = 0;
  _DAT_2045f244 = 0;
  _DAT_2045f248 = 0;
  do {
    iVar1 = 0;
    do {
      FUN_20163668(&DAT_2045f0c5 + iVar1 * 5 + iVar2 * 0x32);
      iVar1 = iVar1 + 1;
    } while (iVar1 < 10);
    iVar2 = iVar2 + 1;
  } while (iVar2 < 7);
  return;
}


// ===== task_mainlink_retry @ 201161bc (232 bytes)

void task_mainlink_retry(void)

{
  int iVar1;
  undefined4 uVar2;
  int iStack_4;
  
  do {
    while( true ) {
      do {
        do {
          iVar1 = itron_twai_flg(DAT_2045004c,1,5,&iStack_4,0xffffffff);
          FUN_20151878(DAT_20450064);
        } while (iVar1 != 0);
      } while (iStack_4 != 1);
      if (DAT_2080049c == '\0') break;
      FUN_20116140();
    }
    if (DAT_2045002a == '\0') {
      FUN_2014eb94(DAT_2045004c,0);
    }
    else if (DAT_2045002c < 3) {
      iVar1 = FUN_201150ec();
      if (iVar1 == 0xe1) {
        FUN_20115c74(&DAT_20450068);
      }
      else {
        FUN_20115be0(&DAT_2045efc0,DAT_20450038);
      }
      FUN_20151680(DAT_20450064);
      DAT_2045002c = DAT_2045002c + 1;
    }
    else if (DAT_20450029 == '\0') {
      FUN_20114df4();
    }
    else {
      uVar2 = FUN_201150ec();
      FUN_201309c0(1,uVar2);
    }
  } while( true );
}


// ===== FUN_201162a4 @ 201162a4 (116 bytes)

void FUN_201162a4(undefined1 param_1)

{
  undefined4 local_10;
  undefined3 local_c;
  undefined1 local_9;
  undefined4 local_8;
  
  local_8 = 0;
  local_10 = 0x200801f0;
  _local_c = CONCAT13(param_1,0x290623);
  mainlink_queue_frame(&local_10,9);
  return;
}


// ===== FUN_20116334 @ 20116334 (52 bytes)

void FUN_20116334(undefined1 param_1)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = 0;
  local_10 = (uint)CONCAT11(param_1,0xf1);
  mainlink_queue_frame(&local_10,7);
  return;
}


// ===== FUN_20116368 @ 20116368 (20 bytes)

undefined4 FUN_20116368(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_20450060 != 0) {
    uVar1 = *(undefined4 *)(DAT_20450060 + 0x38);
  }
  return uVar1;
}


// ===== FUN_2011637c @ 2011637c (20 bytes)

undefined4 FUN_2011637c(void)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if (DAT_20450060 != 0) {
    uVar1 = *(undefined4 *)(DAT_20450060 + 0x48);
  }
  return uVar1;
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
  taskmon_register(iVar1,3);
  if (0 < iVar1) {
    itron_sta_tsk(iVar1,0);
    iVar1 = os_create_sem_named(&DAT_20165870,"cmd_waiting_sem");
    if (0 < iVar1) {
      DAT_20450058 = iVar1;
      FUN_201511e8();
    }
    memclr(&DAT_2045fd40,0x103c0);
    DAT_20450060 = FUN_20158c10(&DAT_2045fd40);
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


// ===== FUN_20116518 @ 20116518 (72 bytes)

void FUN_20116518(int param_1)

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


// ===== mainlink_send_cmd @ 20116560 (472 bytes)

/* looks up the 0x2B-entry command table at 0x20450074 */

void mainlink_send_cmd(char *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar1 = FUN_2016003c(DAT_20450060 + 0x58);
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


// ===== FUN_201165f4 @ 201165f4 (108 bytes)

void FUN_201165f4(void)

{
  int iVar1;
  int iVar2;
  bool bVar3;
  
  FUN_20113d00();
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
    FUN_201162a4(iVar1);
    itron_dly_tsk(5);
    if (DAT_20450028 != '\0') {
      iVar2 = 0;
    }
    bVar3 = iVar2 != 0;
    iVar2 = iVar2 + -1;
  } while (bVar3);
  return;
}


// ===== FUN_20116660 @ 20116660 (44 bytes)

void FUN_20116660(void)

{
  memclr(&DAT_2045fb00,0x240);
  DAT_20450026 = 0;
  FUN_20163684(&DAT_2045006d);
  DAT_20450024 = 0;
  return;
}


// ===== FUN_2011668c @ 2011668c (60 bytes)

void FUN_2011668c(void)

{
  int iVar1;
  bool bVar2;
  
  iVar1 = 0x1d;
  DAT_20450028 = '\0';
  do {
    FUN_201162a4(6);
    itron_dly_tsk(5);
    if (DAT_20450028 != '\0') {
      iVar1 = 0;
    }
    bVar2 = iVar1 != 0;
    iVar1 = iVar1 + -1;
  } while (bVar2);
  return;
}


// ===== FUN_201166cc @ 201166cc (92 bytes)

void FUN_201166cc(int param_1,int param_2)

{
  if (param_2 == 6) {
    FUN_20106e0c();
  }
  else if (param_2 == 2) {
    FUN_20113e4c();
  }
  else if (param_2 < 0) {
    if (*(int *)(&DAT_2080036c + param_1 * 4) == 6) {
      FUN_20106eb4();
    }
    else if (*(int *)(&DAT_2080036c + param_1 * 4) == 2) {
      FUN_20113ea0();
    }
  }
  *(int *)(&DAT_2080036c + param_1 * 4) = param_2;
  return;
}


// ===== FUN_20116728 @ 20116728 (56 bytes)

void FUN_20116728(undefined4 param_1,int *param_2)

{
  if (*param_2 == 6) {
    usbkbd_report();
  }
  else {
    if (*param_2 != 2) {
      return;
    }
    FUN_20113ef0(param_2);
  }
  DAT_20800487 = 1;
  return;
}


// ===== taskmon_register @ 20116768 (28 bytes)

/* slot n of the task-monitor table 0x208DBAD0 */

void taskmon_register(undefined4 param_1,int param_2)

{
  (&DAT_208dbad0)[param_2 * 4] = param_1;
  (&DAT_208dbad8)[param_2 * 4] = *(undefined4 *)(&DAT_20800374 + param_2 * 4);
  return;
}


// ===== FUN_20116784 @ 20116784 (8 bytes)

void FUN_20116784(void)

{
  FUN_201177a0(0x87);
  return;
}


// ===== FUN_2011678c @ 2011678c (76 bytes)

void FUN_2011678c(void)

{
  int iVar1;
  undefined4 extraout_r1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (&DAT_208dbadc)[iVar2 * 4];
    (&DAT_208dbadc)[iVar2 * 4] = iVar1 + 1;
    if ((&DAT_208dbad8)[iVar2 * 4] == iVar1 + 1) {
      FUN_20152fac((&DAT_208dbad0)[iVar2 * 4]);
    }
    FUN_20156260((&DAT_208dbadc)[iVar2 * 4],(&DAT_208dbad8)[iVar2 * 4]);
    iVar1 = iVar2 + 1;
    (&DAT_208dbadc)[iVar2 * 4] = extraout_r1;
    iVar2 = iVar1;
  } while (iVar1 < 5);
  return;
}


// ===== taskmon_start @ 201167d8 (92 bytes)

/* OSTM1 1 ms compare, IRQ 0x87, cyclic handler */

int taskmon_start(void)

{
  byte bVar1;
  int iVar2;
  
  Ramfcfec400 = 31999;
  bVar1 = UNK_fcfec420;
  UNK_fcfec420 = bVar1 & 0xfd;
  UNK_fcfec420 = 1;
  iVar2 = FUN_2014f1a8(0,&DAT_20165954);
  if (iVar2 < 1) {
    return iVar2;
  }
  FUN_2011775c(0x87);
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
  puVar3 = (ushort *)FUN_201112b4(param_1,8,&local_18);
  pcVar1 = (char *)0x0;
  if (puVar3 != (ushort *)0x0) {
    pcVar1 = local_18;
  }
  if (puVar3 == (ushort *)0x0 || pcVar1 == (char *)0x0) {
    return;
  }
  if (*pcVar1 == ' ') {
    local_18 = pcVar1 + 1;
    DAT_2080038c = FUN_201112b4(local_18,8,&local_18);
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
      FUN_20111224(2,7);
      itron_dly_tsk(10);
      FUN_20111224(0,7);
      DAT_20800390 = (uint)(byte)*puVar3;
      return;
    }
    if (cVar5 == '\x02') {
LAB_20116980:
      FUN_20111224(2,7);
      itron_dly_tsk(10);
      FUN_20111224(0,7);
      DAT_20800390 = (uint)*puVar3;
      return;
    }
  }
  FUN_20111224(7);
  itron_dly_tsk(10);
  FUN_20111224(0,7);
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
    iVar3 = FUN_2014e208(auStack_94 + uVar2,&DAT_20116b90);
    if (iVar3 == 0) {
      FUN_20155310(auStack_50,&DAT_20165984,0x40);
      FUN_2015515c(auStack_50,auStack_90);
      iVar3 = fs_fopen(auStack_50,&DAT_20116b9c);
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


// ===== FUN_20116ccc @ 20116ccc (172 bytes)

void FUN_20116ccc(void)

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
  FUN_20100458();
  gpio_rx_reset(0);
  return;
}


// ===== FUN_20116d84 @ 20116d84 (28 bytes)

undefined4 FUN_20116d84(void)

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
  
  FUN_20111218();
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
  
  FUN_20111218();
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
  FUN_201182d4(0,&local_30);
  local_18[0] = 2;
  local_20 = local_18;
  FUN_20117ebc(0,3,&local_20);
  local_18[0] = 3;
  local_20 = local_18;
  FUN_20117ebc(0,4,&local_20);
  FUN_20117ebc(0,5,&local_20);
  DAT_208003a0 = 1;
  FUN_20116da0(1);
  FUN_20113104();
  if (DAT_208003a5 == '\0') {
    FUN_20100480(1);
    gpio_p8_14(1);
    FUN_20101c10(1);
    cpg_set_clock_profile(1);
    FUN_20113dc0();
    FUN_20101b60(0);
    FUN_201026e8();
    FUN_20107e9c();
    mouse_cursor_init();
    FUN_201385b4();
    FUN_2013b97c();
    FUN_2013b4cc();
    FUN_2011115c();
    DAT_208dc1c0 = uptest_init();
    DAT_208dc1c8 = cli_init();
    touch_init();
    DAT_208dc1d0 = keycode_init();
    DAT_208dc1dc = FUN_2010a8f8();
    renc_init();
    FUN_20133440();
    DAT_208dc1d8 = FUN_20110da8();
    spi_slave_init();
    fwupdate_init();
    sdmenu_init();
    DAT_208003a5 = '\x01';
    FUN_20102f34();
    audio_codec_init();
    DAT_208003a0 = 1;
  }
  else {
    FUN_20100480(1);
    gpio_p8_14(1);
    FUN_20101c10(1);
  }
  return;
}


// ===== FUN_20117030 @ 20117030 (152 bytes)

void FUN_20117030(void)

{
  int iVar1;
  
  DAT_208003a0 = 0;
  FUN_20116da0();
  FUN_20101fa4(0);
  FUN_20102040(0);
  FUN_20117f00(0,0xffffffff);
  iVar1 = gpio_read_bit(8,0xc);
  if (iVar1 == 0) {
    FUN_20116784();
    FUN_20113d00();
    itron_dly_tsk(100);
    FUN_20101f8c(0);
    gpio_rx_reset(0);
    FUN_20101cbc(1);
  }
  else {
    FUN_20101b60(0);
    FUN_20101c10(0);
  }
  FUN_20100480(0);
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
  FUN_201147d4();
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
    taskmon_register(uVar2,0);
    iVar1 = taskmon_start();
    if (iVar1 != 0) {
      return;
    }
  }
  else {
    DAT_208003a5 = 1;
    gpio_p8_14();
    FUN_20116da0(1);
    FUN_20113dc0();
    FUN_20101b60(0);
    FUN_201026e8();
    FUN_20107e9c();
    mouse_cursor_init();
    FUN_201385b4();
    FUN_2013b97c();
    FUN_2013b4cc();
    FUN_2011115c();
    DAT_208dc1c0 = uptest_init();
    DAT_208dc1c8 = cli_init();
    touch_init();
    DAT_208dc1d0 = keycode_init();
    DAT_208dc1dc = FUN_2010a8f8();
    mainlink_init();
    renc_init();
    FUN_20133440();
    DAT_208dc1d8 = FUN_20110da8();
    spi_slave_init();
    fwupdate_init();
    sdmenu_init();
    uVar2 = FUN_2014e710();
    taskmon_register(uVar2,0);
    iVar1 = taskmon_start();
    if (iVar1 != 0) {
      return;
    }
    FUN_20102f34();
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
  
  FUN_20116d84();
  FUN_20101190();
  FUN_20100480(1);
  FUN_201562b4();
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


// ===== FUN_20117300 @ 20117300 (60 bytes)

void FUN_20117300(uint param_1,int param_2)

{
  *(uint *)((int)&DAT_e8201400 + (param_1 & 0xfffffffc)) =
       *(uint *)((int)&DAT_e8201400 + (param_1 & 0xfffffffc)) & ~(0xff << ((param_1 & 3) << 3)) |
       param_2 << (param_1 & 3) * 8 + 3;
  return;
}


// ===== FUN_2011733c @ 2011733c (592 bytes)

undefined4 FUN_2011733c(void)

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
    (&DAT_208dc1e0)[iVar1] = FUN_201568e0;
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


// ===== FUN_201175b4 @ 201175b4 (40 bytes)

undefined4 FUN_201175b4(int param_1)

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

