// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0021ab50 @ 0021ab50 (7 bytes)

void FUN_0021ab50(void)

{
  return;
}


// ===== FUN_0021ab58 @ 0021ab58 (7 bytes)

void FUN_0021ab58(void)

{
  return;
}


// ===== FUN_0021ab60 @ 0021ab60 (7 bytes)

void FUN_0021ab60(void)

{
  return;
}


// ===== FUN_0021ab68 @ 0021ab68 (12 bytes)

undefined4 FUN_0021ab68(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021adbc(param_1);
  return uVar1;
}


// ===== FUN_0021ab74 @ 0021ab74 (12 bytes)

undefined4 FUN_0021ab74(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021adc4(param_1);
  return uVar1;
}


// ===== FUN_0021ab80 @ 0021ab80 (11 bytes)

undefined4 FUN_0021ab80(undefined4 param_1)

{
  *(undefined4 *)param_1 = param_1;
  return 0;
}


// ===== FUN_0021ab8c @ 0021ab8c (5 bytes)

void FUN_0021ab8c(void)

{
  return;
}


// ===== env_lock_mutex @ 0021ab94 (5 bytes)

/* [inference: paired with env_unlock_mutex around MU-B CR access] */

void env_lock_mutex(void)

{
  return;
}


// ===== env_unlock_mutex @ 0021ab9c (5 bytes)

/* [inference] */

void env_unlock_mutex(void)

{
  return;
}


// ===== FUN_0021aba4 @ 0021aba4 (10 bytes)

void FUN_0021aba4(undefined4 param_1)

{
  platform_time_delay(param_1);
  return;
}


// ===== env_register_isr @ 0021abb0 (19 bytes)

/* isr_table entry store [inference] */

void env_register_isr(uint param_1,undefined4 param_2)

{
  if (0xb < param_1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(&DAT_002390a0 + param_1 * 4) = param_2;
  return;
}


// ===== FUN_0021abc4 @ 0021abc4 (22 bytes)

void FUN_0021abc4(uint param_1)

{
  if (0xb < param_1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(&DAT_002390a0 + param_1 * 4) = 0;
  return;
}


// ===== FUN_0021abdc @ 0021abdc (10 bytes)

void FUN_0021abdc(undefined4 param_1)

{
  FUN_0021ad6c(param_1);
  return;
}


// ===== FUN_0021abe8 @ 0021abe8 (10 bytes)

void FUN_0021abe8(undefined4 param_1)

{
  FUN_0021ad88(param_1);
  return;
}


// ===== FUN_0021abf4 @ 0021abf4 (20 bytes)

void FUN_0021abf4(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  FUN_0021ada4(param_2,param_1,param_3,param_4);
  return;
}


// ===== FUN_0021ac08 @ 0021ac08 (11 bytes)

void FUN_0021ac08(void)

{
  FUN_0021adac();
  FUN_0021adb4();
  return;
}


// ===== env_isr @ 0021ac14 (22 bytes)

/* isr_table[vector] -> virtqueue_notification */

void env_isr(uint param_1)

{
  if (param_1 < 0xc) {
    FUN_0021bd24(*(undefined4 *)(&DAT_002390a0 + param_1 * 4));
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== MU_B_IRQHandler @ 0021ac30 (37 bytes)

/* rpmsg platform ISR: if MU-B SR RF1 (bit 26): env_isr(RR1 >> 16) */

void MU_B_IRQHandler(void)

{
  uint uVar1;
  
  memw();
  uVar1 = DAT_40111060;
  if ((uVar1 & 0x4000000) == 0) {
    return;
  }
  memw();
  uVar1 = DAT_40111044;
  env_isr(uVar1 >> 0x10 & 1 | 2);
  return;
}


// ===== platform_init_interrupt @ 0021ac58 (89 bytes)

/* env_register_isr, first use: MU-B CR |= RIE1, xos_register_interrupt_handler(MU_B_IRQHandler) */

undefined4 platform_init_interrupt(undefined4 param_1,undefined4 param_2)

{
  uint uVar1;
  
  env_register_isr(param_1,param_2);
  env_lock_mutex(DAT_002390d0);
  if (-1 < DAT_002390d4) {
    if (DAT_002390d4 == 0) {
      memw();
      uVar1 = DAT_40111064;
      memw();
      DAT_40111064 = uVar1 & 0xfff0fff7 | 0x4000000;
      xos_register_interrupt_handler(6,MU_B_IRQHandler,0);
    }
    DAT_002390d4 = DAT_002390d4 + 1;
    env_unlock_mutex(DAT_002390d0);
    return 0;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== platform_deinit_interrupt @ 0021acb4 (79 bytes)

/* last use: MU-B CR &= ~RIE1, unregister handler */

undefined4 platform_deinit_interrupt(undefined4 param_1)

{
  uint uVar1;
  bool bVar2;
  
  env_lock_mutex(DAT_002390d0);
  bVar2 = 0 < DAT_002390d4;
  DAT_002390d4 = DAT_002390d4 + -1;
  if (bVar2) {
    if (DAT_002390d4 == 0) {
      memw();
      uVar1 = DAT_40111064;
      memw();
      DAT_40111064 = uVar1 & 0xfbf0fff7;
      xos_register_interrupt_handler(6,0,0);
    }
    FUN_0021abc4(param_1);
    env_unlock_mutex(DAT_002390d0);
    return 0;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== platform_notify @ 0021ad04 (60 bytes)

/* wait MU-B SR TE1 (bit 22), TR1 = vector << 16 */

void platform_notify(uint param_1)

{
  uint uVar1;
  
  if (param_1 >> 1 == 1) {
    env_lock_mutex(DAT_002390d0);
    memw();
    uVar1 = DAT_40111060;
    while ((uVar1 & 0x400000) == 0) {
      memw();
      uVar1 = DAT_40111060;
    }
    memw();
    DAT_40111024 = param_1 << 0x10;
    env_unlock_mutex(DAT_002390d0);
    return;
  }
  return;
}


// ===== platform_time_delay @ 0021ad44 (32 bytes)

/* busy-wait on CCOUNT (0x1F40 cycles per unit) */

void platform_time_delay(int param_1)

{
  int iVar1;
  int iVar2;
  undefined4 in_CCOUNT;
  
  iVar1 = rsr_ccount(in_CCOUNT);
  param_1 = param_1 * (int)&DAT_00001f40;
  do {
    iVar2 = rsr_ccount(in_CCOUNT);
    param_1 = param_1 + (iVar1 - iVar2);
  } while (param_1 != 0);
  return;
}


// ===== FUN_0021ad64 @ 0021ad64 (7 bytes)

undefined4 FUN_0021ad64(void)

{
  return 0;
}


// ===== FUN_0021ad6c @ 0021ad6c (27 bytes)

void FUN_0021ad6c(void)

{
  if (0 < DAT_002390d8) {
    xos_interrupt_enable(6);
    DAT_002390d8 = DAT_002390d8 + -1;
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0021ad88 @ 0021ad88 (27 bytes)

void FUN_0021ad88(void)

{
  if (-1 < DAT_002390d8) {
    FUN_002267e0(6);
    DAT_002390d8 = DAT_002390d8 + 1;
    return;
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_0021ada4 @ 0021ada4 (5 bytes)

void FUN_0021ada4(void)

{
  return;
}


// ===== FUN_0021adac @ 0021adac (5 bytes)

void FUN_0021adac(void)

{
  return;
}


// ===== FUN_0021adb4 @ 0021adb4 (5 bytes)

void FUN_0021adb4(void)

{
  return;
}


// ===== FUN_0021adbc @ 0021adbc (5 bytes)

void FUN_0021adbc(void)

{
  return;
}


// ===== FUN_0021adc4 @ 0021adc4 (5 bytes)

void FUN_0021adc4(void)

{
  return;
}


// ===== FUN_0021adcc @ 0021adcc (23 bytes)

undefined4 FUN_0021adcc(void)

{
  int iVar1;
  undefined4 uVar2;
  
  iVar1 = FUN_0021ab80(&DAT_002390d0,1);
  uVar2 = 0xffffffff;
  if (iVar1 == 0) {
    uVar2 = 0;
  }
  return uVar2;
}


// ===== FUN_0021ade4 @ 0021ade4 (18 bytes)

void FUN_0021ade4(void)

{
  FUN_0021ab8c(DAT_002390d0);
  DAT_002390d0 = 0;
  return;
}


// ===== FUN_0021ae00 @ 0021ae00 (207 bytes)

void FUN_0021ae00(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  int iVar3;
  int *piVar4;
  int *piVar5;
  undefined4 local_30;
  undefined2 auStack_2c [22];
  
  puVar1 = *(undefined4 **)(param_1 + 100);
  if (puVar1 == (undefined4 *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  puVar2 = (undefined4 *)(**(code **)(puVar1[8] + 8))(*puVar1,&local_30,auStack_2c);
  do {
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    piVar4 = (int *)puVar1[2];
    if (piVar4 != (int *)0x0) {
      do {
        piVar5 = (int *)*piVar4;
        if (*piVar5 == puVar2[1]) {
          if ((piVar4 != (int *)0x0) &&
             (iVar3 = (*(code *)piVar5[1])(puVar2 + 4,*(undefined2 *)(puVar2 + 3),*puVar2,piVar5[2])
             , iVar3 == 1)) {
            *(char *)((int)puVar2 + 10) = (char)auStack_2c[0];
            *(char *)((int)puVar2 + 0xb) = (char)((ushort)auStack_2c[0] >> 8);
            goto LAB_0021ae71;
          }
          break;
        }
        piVar4 = (int *)piVar4[2];
      } while (piVar4 != (int *)0x0);
    }
    (**(code **)(puVar1[8] + 0xc))(*puVar1,puVar2,local_30,auStack_2c[0]);
LAB_0021ae71:
    puVar2 = (undefined4 *)(**(code **)(puVar1[8] + 8))(*puVar1,&local_30,auStack_2c);
  } while( true );
}


// ===== FUN_0021aed4 @ 0021aed4 (19 bytes)

void FUN_0021aed4(int param_1)

{
  if (*(int *)(param_1 + 100) == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(*(int *)(param_1 + 100) + 0x10) = 1;
  return;
}


// ===== FUN_0021aee8 @ 0021aee8 (21 bytes)

void FUN_0021aee8(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0021baa8(param_1,param_4,param_3);
  if (iVar1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== FUN_0021af00 @ 0021af00 (18 bytes)

undefined4 FUN_0021af00(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021ba54(param_1,param_3,param_2);
  return uVar1;
}


// ===== FUN_0021af14 @ 0021af14 (18 bytes)

undefined4 FUN_0021af14(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021ba54(param_1,param_3,param_2);
  return uVar1;
}


// ===== FUN_0021af28 @ 0021af28 (21 bytes)

void FUN_0021af28(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0021baa8(param_1,param_4,param_3);
  if (iVar1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== FUN_0021af40 @ 0021af40 (19 bytes)

void FUN_0021af40(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0021b8e8(param_1,param_4);
  if (iVar1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== FUN_0021af54 @ 0021af54 (18 bytes)

undefined4 FUN_0021af54(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021b9b4(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_0021af68 @ 0021af68 (18 bytes)

undefined4 FUN_0021af68(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  uVar1 = FUN_0021b9b4(param_1,param_2,param_3);
  return uVar1;
}


// ===== FUN_0021af7c @ 0021af7c (19 bytes)

void FUN_0021af7c(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = FUN_0021b8e8(param_1,param_4);
  if (iVar1 != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== FUN_0021af90 @ 0021af90 (11 bytes)

void FUN_0021af90(int param_1)

{
  platform_notify(*(undefined2 *)(param_1 + 0x50));
  return;
}


// ===== rpmsg_lite_create_ept @ 0021af9c (149 bytes)

/* called by Thread_Ipc (callback ipc_ept_rx_cb) and rpmsg_ns_bind */

int * rpmsg_lite_create_ept(int param_1,int param_2,int param_3,int param_4,int *param_5)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  undefined4 *puVar4;
  
  if (param_1 == 0) {
    return (int *)0x0;
  }
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  puVar4 = *(undefined4 **)(param_1 + 8);
  if (param_2 == -1) {
    iVar3 = 1;
    while (iVar1 = iVar3, puVar2 = puVar4, puVar4 != (undefined4 *)0x0) {
      while (*(int *)*puVar2 != iVar3) {
        puVar2 = (undefined4 *)puVar2[2];
        if (puVar2 == (undefined4 *)0x0) goto LAB_0021aff6;
      }
      if ((puVar2 == (undefined4 *)0x0) || (iVar3 = iVar3 + 1, iVar1 = param_2, iVar3 == -1)) break;
    }
LAB_0021aff6:
    param_2 = iVar1;
    if (iVar1 == -1) {
      env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
      return (int *)0x0;
    }
  }
  else {
    for (; puVar4 != (undefined4 *)0x0; puVar4 = (undefined4 *)puVar4[2]) {
      if (*(int *)*puVar4 == param_2) {
        if (puVar4 != (undefined4 *)0x0) {
          env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
          return (int *)0x0;
        }
        break;
      }
    }
  }
  if (param_5 != (int *)0x0) {
    FUN_0021aafc(param_5,0,0x10);
    *param_5 = param_2;
    param_5[1] = param_3;
    param_5[2] = param_4;
    param_5[4] = (int)param_5;
    FUN_00235370(param_1 + 8,param_5 + 4);
    env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
    return param_5;
  }
  env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
  return (int *)0x0;
}


// ===== FUN_0021b034 @ 0021b034 (63 bytes)

undefined4 FUN_0021b034(int param_1,int *param_2)

{
  undefined4 *puVar1;
  
  if ((param_1 == 0) || (param_2 == (int *)0x0)) {
    return 0xffffec75;
  }
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  puVar1 = *(undefined4 **)(param_1 + 8);
  if (puVar1 != (undefined4 *)0x0) {
    do {
      if (*(int *)*puVar1 == *param_2) {
        if (puVar1 != (undefined4 *)0x0) {
          FUN_00235398(param_1 + 8);
          env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
          return 0;
        }
        break;
      }
      puVar1 = (undefined4 *)puVar1[2];
    } while (puVar1 != (undefined4 *)0x0);
  }
  env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
  return 0xffffec75;
}


// ===== rpmsg_lite_is_link_up @ 0021b078 (13 bytes)

/* returns rl->link_state (+0x10) */

undefined4 rpmsg_lite_is_link_up(int param_1)

{
  if (param_1 != 0) {
    return *(undefined4 *)(param_1 + 0x10);
  }
  return 0;
}


// ===== rpmsg_lite_send @ 0021b088 (259 bytes)

/* called by handle_srtm_msg and rpmsg_ns_announce */

undefined4
rpmsg_lite_send(int param_1,undefined4 *param_2,undefined4 param_3,int param_4,uint param_5,
               uint param_6)

{
  undefined1 *puVar1;
  uint uVar2;
  undefined4 uStack_30;
  undefined2 auStack_2c [2];
  undefined4 uStack_28;
  undefined1 *puStack_24;
  
  if (param_2 == (undefined4 *)0x0) {
    return 0xffffec75;
  }
  if (0x1f0 < param_5) {
    return 0xffffec76;
  }
  uStack_28 = *param_2;
  if ((param_1 == 0) || (param_4 == 0)) {
    return 0xffffec75;
  }
  if (*(int *)(param_1 + 0x10) != 1) {
    return 0xffffec71;
  }
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  puVar1 = (undefined1 *)
           (**(code **)(*(int *)(param_1 + 0x20) + 4))
                     (*(undefined4 *)(param_1 + 4),&uStack_30,auStack_2c);
  env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
  if (puVar1 == (undefined1 *)0x0) {
    if (param_6 == 0) {
      return 0xffffec77;
    }
    uVar2 = 0;
    do {
      FUN_0021aba4(1);
      env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
      puStack_24 = (undefined1 *)
                   (**(code **)(*(int *)(param_1 + 0x20) + 4))
                             (*(undefined4 *)(param_1 + 4),&uStack_30,auStack_2c);
      env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
      uVar2 = uVar2 + 1;
      puVar1 = puStack_24;
      if (param_6 <= uVar2) {
        if (puStack_24 == (undefined1 *)0x0) {
          return 0xffffec77;
        }
        break;
      }
    } while (puStack_24 == (undefined1 *)0x0);
  }
  puVar1[0xc] = (char)param_5;
  puVar1[4] = (char)param_3;
  *puVar1 = (char)uStack_28;
  puVar1[0xe] = 0;
  puVar1[0xf] = 0;
  puVar1[0xd] = (char)(param_5 >> 8);
  puVar1[5] = (char)((uint)param_3 >> 8);
  puVar1[6] = (char)((uint)param_3 >> 0x10);
  puVar1[7] = (char)((uint)param_3 >> 0x18);
  puVar1[1] = (char)((uint)uStack_28 >> 8);
  puVar1[2] = (char)((uint)uStack_28 >> 0x10);
  puVar1[3] = (char)((uint)uStack_28 >> 0x18);
  FUN_0021ab0c(puVar1 + 0x10,param_4,param_5);
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  (*(code *)**(undefined4 **)(param_1 + 0x20))
            (*(undefined4 *)(param_1 + 4),puVar1,uStack_30,auStack_2c[0]);
  FUN_0021bb84(*(undefined4 *)(param_1 + 4));
  env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
  return 0;
}


// ===== FUN_0021b190 @ 0021b190 (166 bytes)

int FUN_0021b190(int param_1,int *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  undefined1 auStack_30 [48];
  
  if (param_2 == (int *)0x0) {
    return 0;
  }
  if (*(int *)(param_1 + 0x10) != 1) {
    *param_2 = 0;
    return 0;
  }
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  iVar1 = (**(code **)(*(int *)(param_1 + 0x20) + 4))
                    (*(undefined4 *)(param_1 + 4),param_2,auStack_30);
  env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
  if (iVar1 != 0) {
    uVar4 = ae_l16ui_n(auStack_30,0);
    iVar3 = *param_2;
    *(char *)(iVar1 + 10) = (char)uVar4;
    *(char *)(iVar1 + 0xb) = (char)((uint)uVar4 >> 8);
    *param_2 = iVar3 + -0x10;
    return iVar1 + 0x10;
  }
  uVar2 = 0;
  if (param_3 == 0) {
LAB_0021b230:
    *param_2 = 0;
    return 0;
  }
  do {
    FUN_0021aba4(1);
    env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
    iVar1 = (**(code **)(*(int *)(param_1 + 0x20) + 4))
                      (*(undefined4 *)(param_1 + 4),param_2,auStack_30);
    env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
    uVar2 = uVar2 + 1;
    if (param_3 <= uVar2) {
      if (iVar1 == 0) goto LAB_0021b230;
      break;
    }
  } while (iVar1 == 0);
  uVar4 = ae_l16ui_n(auStack_30,0);
  iVar3 = *param_2;
  *(char *)(iVar1 + 10) = (char)uVar4;
  *(char *)(iVar1 + 0xb) = (char)((uint)uVar4 >> 8);
  *param_2 = iVar3 + -0x10;
  return iVar1 + 0x10;
}


// ===== FUN_0021b238 @ 0021b238 (188 bytes)

undefined4 FUN_0021b238(int param_1,undefined4 *param_2,undefined4 param_3,int param_4,uint param_5)

{
  undefined4 uVar1;
  
  if ((param_2 == (undefined4 *)0x0) || (param_4 == 0)) {
    return 0xffffec75;
  }
  if (0x1f0 < param_5) {
    return 0xffffec76;
  }
  if (*(int *)(param_1 + 0x10) != 1) {
    return 0xffffec71;
  }
  uVar1 = *param_2;
  *(char *)(param_4 + -0xc) = (char)param_3;
  *(char *)(param_4 + -0xb) = (char)((uint)param_3 >> 8);
  *(char *)(param_4 + -10) = (char)((uint)param_3 >> 0x10);
  *(char *)(param_4 + -9) = (char)((uint)param_3 >> 0x18);
  *(undefined1 *)(param_4 + -0x10) = (char)uVar1;
  *(char *)(param_4 + -0xe) = (char)((uint)uVar1 >> 0x10);
  *(char *)(param_4 + -0xf) = (char)((uint)uVar1 >> 8);
  *(char *)(param_4 + -0xd) = (char)((uint)uVar1 >> 0x18);
  *(char *)(param_4 + -3) = (char)(param_5 >> 8);
  *(char *)(param_4 + -4) = (char)param_5;
  *(undefined1 *)(param_4 + -2) = 0;
  *(undefined1 *)(param_4 + -1) = 0;
  env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
  uVar1 = FUN_0021ba14(*(undefined4 *)(param_1 + 4),*(undefined2 *)(param_4 + -6));
  (*(code *)**(undefined4 **)(param_1 + 0x20))
            (*(undefined4 *)(param_1 + 4),(undefined1 *)(param_4 + -0x10),uVar1,
             *(undefined2 *)(param_4 + -6));
  FUN_0021bb84(*(undefined4 *)(param_1 + 4));
  env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
  return 0;
}


// ===== FUN_0021b2f8 @ 0021b2f8 (81 bytes)

undefined4 FUN_0021b2f8(undefined4 *param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != (undefined4 *)0x0) && (param_2 != 0)) {
    env_lock_mutex(param_1[3]);
    uVar1 = FUN_0021ba14(*param_1,*(undefined2 *)(param_2 + -6));
    (**(code **)(param_1[8] + 0xc))(*param_1,param_2 + -0x10,uVar1,*(undefined2 *)(param_2 + -6));
    env_unlock_mutex(param_1[3]);
    return 0;
  }
  return 0xffffec75;
}

