// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== platform_init_interrupt @ 000818d0 (54 bytes)

/* rename (was platform_interrupt_enable): env_register_isr, then on first use MU-A CR |= RIE1 (bit
   26), refcount 0x88710 */

undefined4 platform_init_interrupt(void)

{
  uint uVar1;
  
  env_register_isr();
  env_lock_mutex(DAT_00088714);
  if (DAT_00088710 < 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_00088710 == 0) {
    uVar1 = DAT_40110064;
    DAT_40110064 = uVar1 & 0xfff0ffff | 0x4000000;
  }
  DAT_00088710 = DAT_00088710 + 1;
  env_unlock_mutex(DAT_00088714);
  return 0;
}


// ===== platform_notify @ 00081914 (38 bytes)

/* create: if vector<2: lock platform_lock, MU_SendMsg(MUA, 1, vector<<16), unlock */

void platform_notify(uint param_1)

{
  if (param_1 >> 1 == 0) {
    env_lock_mutex(DAT_00088714);
    MU_SendMsg(&DAT_40110000,1,param_1 << 0x10);
    env_unlock_mutex(DAT_00088714);
    return;
  }
  return;
}


// ===== xPortIsInsideInterrupt @ 00081944 (16 bytes)

bool xPortIsInsideInterrupt(void)

{
  uint uVar1;
  
  uVar1 = DAT_e000ed04;
  return (uVar1 & 0x1ff) != 0;
}


// ===== platform_interrupt_enable @ 00081958 (30 bytes)

/* rename (was env_enable_interrupt; env wrapper inlined): disable_counter 0x8870C--, at 0 NVIC
   ISER1=4 (MU_A) */

void platform_interrupt_enable(void)

{
  if (DAT_0008870c < 1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  disableIRQinterrupts();
  DAT_0008870c = DAT_0008870c + -1;
  if (DAT_0008870c == 0) {
    DAT_e000e104 = 4;
  }
  enableIRQinterrupts();
  return;
}


// ===== platform_interrupt_disable @ 00081980 (42 bytes)

/* rename (was env_disable_interrupt; env wrapper inlined): at 0 NVIC ICER1=4, disable_counter++ */

void platform_interrupt_disable(void)

{
  if (DAT_0008870c < 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  disableIRQinterrupts();
  if (DAT_0008870c == 0) {
    DAT_e000e184 = 4;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  DAT_0008870c = DAT_0008870c + 1;
  enableIRQinterrupts();
  return;
}


// ===== platform_init @ 000819b4 (38 bytes)

/* rename (was platform_init_interrupt): MU_Init(MUA), NVIC IPR[34]=0x60, ISER1 bit2 (MU_A IRQ 34),
   create platform_lock 0x88714 */

int platform_init(void)

{
  int iVar1;
  undefined4 in_r3;
  
  MU_Init(&DAT_40110000);
  DAT_e000e422 = 0x60;
  DAT_e000e104 = 4;
  iVar1 = env_create_mutex(&DAT_00088714,1,4,&DAT_e000e100,in_r3);
  return -(uint)(iVar1 != 0);
}


// ===== env_init @ 000819e8 (106 bytes)

/* rename (was platform_init): first call creates binary sema 0x8871C, clears isr_table 0x88720,
   calls platform_init */

undefined4 env_init(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined4 in_r3;
  
  vTaskSuspendAll();
  if (DAT_00088718 < 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_00088718 = DAT_00088718 + 1;
  if (DAT_00088718 == 1) {
    DAT_0008871c = xQueueGenericCreate(1,0,3);
    memset(&DAT_00088720,0,0x80);
    xTaskResumeAll();
    uVar1 = platform_init();
    xQueueGenericSend(DAT_0008871c,0,0);
  }
  else {
    xTaskResumeAll();
    iVar2 = xQueueSemaphoreTake(DAT_0008871c,0xffffffff);
    if (iVar2 == 1) {
      xQueueGenericSend(DAT_0008871c,0,0,0,in_r3);
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== env_register_isr @ 00081a60 (14 bytes)

/* rename (was platform_register_isr): isr_table[vector] = vq (32 entries at 0x88720) */

void env_register_isr(uint param_1,undefined4 param_2)

{
  if (0x1f < param_1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(&DAT_00088720 + param_1 * 4) = param_2;
  return;
}


// ===== rpmsg_queue_recv @ 00081a88 (104 bytes)

undefined4
rpmsg_queue_recv(int param_1,int param_2,undefined4 *param_3,int param_4,uint param_5,uint *param_6,
                undefined4 param_7)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 local_24;
  undefined4 local_20;
  uint local_1c;
  
  local_24 = 0;
  local_20 = 0;
  local_1c = 0;
  if (((param_1 != 0) && (param_2 != 0)) && (param_4 != 0)) {
    iVar1 = env_get_queue(param_2,&local_24,param_7,0,param_1);
    if (iVar1 == 0) {
      return 0xffffec72;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_24;
    }
    if (param_6 != (uint *)0x0) {
      *param_6 = local_1c;
    }
    if (param_5 < local_1c) {
      uVar2 = 0xffffec76;
    }
    else {
      memcpy(param_4,local_20);
      uVar2 = 0;
    }
    iVar1 = rpmsg_queue_nocopy_free(param_1,local_20);
    if (iVar1 == 0) {
      return uVar2;
    }
  }
  return 0xffffec75;
}


// ===== rpmsg_lite_send @ 00081afc (218 bytes)

undefined4
rpmsg_lite_send(int param_1,undefined4 *param_2,undefined4 param_3,int param_4,uint param_5,
               uint param_6)

{
  undefined4 *puVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined4 uStack_30;
  undefined4 *local_2c;
  undefined4 uStack_28;
  
  if (param_2 != (undefined4 *)0x0) {
    if (0x1f0 < param_5) {
      return 0xffffec76;
    }
    uVar3 = *param_2;
    if ((param_1 != 0) && (param_4 != 0)) {
      if (*(int *)(param_1 + 0x10) != 1) {
        return 0xffffec71;
      }
      uStack_30 = param_1;
      local_2c = param_2;
      uStack_28 = param_3;
      env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
      puVar1 = (undefined4 *)
               (**(code **)(*(int *)(param_1 + 0x20) + 4))
                         (*(undefined4 *)(param_1 + 4),&local_2c,(int)&uStack_30 + 2);
      env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
      if (puVar1 == (undefined4 *)0x0) {
        if (param_6 == 0) {
          return 0xffffec77;
        }
        uVar2 = 0;
        do {
          vTaskDelay(1);
          env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
          puVar1 = (undefined4 *)
                   (**(code **)(*(int *)(param_1 + 0x20) + 4))
                             (*(undefined4 *)(param_1 + 4),&local_2c,(int)&uStack_30 + 2);
          uVar2 = uVar2 + 1;
          env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
          if (param_6 <= uVar2) {
            if (puVar1 == (undefined4 *)0x0) {
              return 0xffffec77;
            }
            break;
          }
        } while (puVar1 == (undefined4 *)0x0);
      }
      puVar1[1] = param_3;
      *puVar1 = uVar3;
      *(short *)(puVar1 + 3) = (short)param_5;
      *(undefined1 *)((int)puVar1 + 0xe) = 0;
      *(undefined1 *)((int)puVar1 + 0xf) = 0;
      memcpy(puVar1 + 4,param_4,param_5);
      env_lock_mutex(*(undefined4 *)(param_1 + 0xc));
      (*(code *)**(undefined4 **)(param_1 + 0x20))
                (*(undefined4 *)(param_1 + 4),puVar1,local_2c,uStack_30._2_2_);
      virtqueue_kick(*(undefined4 *)(param_1 + 4));
      env_unlock_mutex(*(undefined4 *)(param_1 + 0xc));
      return 0;
    }
  }
  return 0xffffec75;
}


// ===== rpmsg_queue_nocopy_free @ 00081be8 (60 bytes)

undefined4
rpmsg_queue_nocopy_free(undefined4 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  code *pcVar3;
  
  if ((param_1 == (undefined4 *)0x0) || (param_2 == 0)) {
    uVar1 = 0xffffec75;
  }
  else {
    env_lock_mutex(param_1[3]);
    uVar2 = *param_1;
    pcVar3 = *(code **)(param_1[8] + 0xc);
    uVar1 = virtqueue_get_buffer_length(uVar2,*(undefined2 *)(param_2 + -6));
    (*pcVar3)(uVar2,param_2 + -0x10,uVar1,*(undefined2 *)(param_2 + -6),param_4);
    env_unlock_mutex(param_1[3]);
    uVar1 = 0;
  }
  return uVar1;
}


// ===== rpmsg_lite_master_init @ 00081c28 (428 bytes)

int * rpmsg_lite_master_init(uint param_1,uint param_2,int param_3)

{
  int *piVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  int *piVar8;
  char *local_4c [4];
  int local_3c [4];
  undefined2 local_2c;
  
  uVar4 = param_2 - 0x800;
  uVar3 = uVar4;
  if ((param_2 & 3) != 0) {
    uVar3 = uVar4 & 0xfffffffc;
  }
  if ((((0x7ff < uVar3) && (param_3 == 0)) && (param_1 != 0)) &&
     (piVar1 = (int *)pvPortMalloc(0x24), piVar1 != (int *)0x0)) {
    memset(piVar1,0,0x24);
    iVar2 = env_init();
    if (iVar2 == 0) {
      piVar1[6] = uVar4 >> 9;
      piVar1[7] = uVar4 >> 9;
      iVar5 = 0;
      piVar7 = local_3c;
      iVar2 = 0;
      uVar3 = param_1 + 0x800;
      if ((param_1 & 3) != 0) {
        uVar3 = (uVar3 & 0xfffffffc) + 4;
      }
      piVar1[5] = uVar3;
      local_4c[2] = "rx_vq";
      local_4c[3] = "tx_vq";
      local_4c[0] = (char *)0x86259;
      local_4c[1] = (char *)0x8621f;
      piVar1[8] = (int)&PTR_vq_tx_master_1_000879ac;
      piVar8 = piVar7;
      while( true ) {
        local_3c[2] = iVar2 + param_1;
        local_3c[3] = 0x10;
        local_2c = 2;
        memset(local_3c[2],0,0x4e);
        iVar2 = virtqueue_create(iVar5,local_4c[iVar5 + 2],local_3c + 2,local_4c[iVar5],0x8622b,
                                 piVar8);
        if (iVar2 != 0) break;
        vq_ring_init(*piVar8);
        virtqueue_disable_cb(*piVar8);
        iVar2 = 0x400;
        *(int **)(*piVar8 + 100) = piVar1;
        if (iVar5 != 0) {
          iVar2 = env_create_mutex(piVar1 + 3,iVar5);
          if (iVar2 == 0) {
            piVar1[1] = local_3c[1];
            *piVar1 = local_3c[0];
            iVar2 = 0;
            do {
              for (uVar3 = 0; (uVar3 < *(ushort *)(*piVar7 + 0x52) && (uVar3 < (uint)piVar1[7]));
                  uVar3 = uVar3 + 1) {
                iVar5 = piVar1[6];
                if (iVar5 == 0) {
LAB_00081d36:
                  do {
                    /* WARNING: Do nothing block with infinite loop */
                  } while( true );
                }
                iVar6 = piVar1[5] + (piVar1[7] - iVar5) * 0x200;
                piVar1[6] = iVar5 + -1;
                if (iVar6 == 0) goto LAB_00081d36;
                memset(iVar6,0,0x200);
                iVar5 = *piVar7;
                if (iVar5 == *piVar1) {
                  iVar5 = virtqueue_fill_avail_buffers(iVar5,iVar6,0x200);
LAB_00081d56:
                  if (iVar5 != 0) {
                    vQueueDelete(piVar1[3]);
                    goto LAB_00081c74;
                  }
                }
                else if (iVar5 == piVar1[1]) {
                  iVar5 = virtqueue_fill_used_buffers(iVar5,iVar6,0x200);
                  goto LAB_00081d56;
                }
              }
              piVar7 = piVar7 + 1;
              if (iVar2 != 0) {
                platform_init_interrupt(*(undefined2 *)(*piVar1 + 0x50));
                platform_init_interrupt(*(undefined2 *)(piVar1[1] + 0x50));
                platform_interrupt_disable(*(undefined2 *)(*piVar1 + 0x50));
                platform_interrupt_disable(*(undefined2 *)(piVar1[1] + 0x50));
                piVar1[4] = iVar2;
                platform_interrupt_enable(*(undefined2 *)(*piVar1 + 0x50));
                platform_interrupt_enable(*(undefined2 *)(piVar1[1] + 0x50));
                virtqueue_kick(*piVar1);
                return piVar1;
              }
              iVar2 = 1;
            } while( true );
          }
          break;
        }
        iVar5 = 1;
        piVar8 = piVar8 + 1;
      }
    }
LAB_00081c74:
    env_free_memory(piVar1);
  }
  return (int *)0x0;
}


// ===== virtqueue_create @ 00081dec (142 bytes)

undefined4
virtqueue_create(undefined2 param_1,undefined4 param_2,int *param_3,undefined4 param_4,
                undefined4 param_5,int *param_6)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined4 local_24;
  
  local_24 = 0;
  iVar2 = pvPortMalloc(0x68);
  if (iVar2 == 0) {
    local_24 = 0xfffff444;
  }
  else {
    memset(iVar2,0,0x68);
    strncpy(iVar2,param_2,0x20);
    uVar1 = *(ushort *)(param_3 + 2);
    uVar3 = (uint)uVar1;
    iVar4 = param_3[1];
    *(undefined4 *)(iVar2 + 0x34) = param_5;
    iVar5 = *param_3;
    *(undefined2 *)(iVar2 + 0x50) = param_1;
    *(uint *)(iVar2 + 0x40) = uVar3;
    *(int *)(iVar2 + 0x44) = iVar5;
    *(int *)(iVar2 + 0x2c) = iVar5;
    iVar5 = iVar5 + uVar3 * 0x10;
    *(undefined4 *)(iVar2 + 0x30) = param_4;
    *(int *)(iVar2 + 0x48) = iVar5;
    *(int *)(iVar2 + 0x24) = iVar4;
    *(uint *)(iVar2 + 0x4c) = iVar5 + (uVar3 + 4) * 2 + -4 + iVar4 + -1 & -iVar4;
    *(ushort *)(iVar2 + 0x52) = uVar1;
    *(uint *)(iVar2 + 0x28) =
         (iVar4 + -1 + uVar3 * 0x10 + (uVar3 + 4) * 2 & -iVar4) + uVar3 * 8 + 0xe;
    *param_6 = iVar2;
  }
  return local_24;
}


// ===== prvInsertBlockIntoFreeList @ 00081e80 (62 bytes)

void prvInsertBlockIntoFreeList(undefined4 *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_000887b8;
  do {
    puVar2 = puVar3;
    puVar3 = (undefined4 *)*puVar2;
  } while (puVar3 < param_1);
  if (param_1 == (undefined4 *)((int)puVar2 + puVar2[1])) {
    puVar2[1] = param_1[1] + puVar2[1];
    param_1 = puVar2;
  }
  if ((puVar3 == (undefined4 *)((int)param_1 + param_1[1])) && (puVar3 != DAT_000887a0)) {
    piVar1 = puVar3 + 1;
    puVar3 = (undefined4 *)*puVar3;
    param_1[1] = *piVar1 + param_1[1];
  }
  *param_1 = puVar3;
  if (param_1 != puVar2) {
    *puVar2 = param_1;
  }
  return;
}


// ===== pvPortMalloc @ 00081ec8 (234 bytes)

/* WARNING: Removing unreachable block (ram,0x00081ee4) */
/* WARNING: Removing unreachable block (ram,0x00081ee6) */

uint pvPortMalloc(uint param_1)

{
  uint uVar1;
  undefined *puVar2;
  int *piVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  undefined *puVar7;
  int *piVar8;
  int iVar9;
  
  vTaskSuspendAll();
  if (DAT_000887a0 == (int *)0x0) {
    DAT_000887b8 = (int *)&DAT_00088ef0;
    DAT_000887bc = 0;
    DAT_000a1ee8 = 0;
    DAT_000a1eec = 0;
    DAT_000887a8 = &DAT_00018ff8;
    DAT_00088ef0 = &DAT_000a1ee8;
    DAT_00088ef4 = &DAT_00018ff8;
    DAT_000887a0 = &DAT_000a1ee8;
    DAT_000887a4 = 0x80000000;
    DAT_000887ac = DAT_000887a8;
  }
  puVar2 = DAT_000887a8;
  uVar1 = DAT_000887a4;
  if ((DAT_000887a4 & param_1) == 0) {
    uVar5 = 0;
    if (param_1 == 0) goto LAB_00081f9a;
    puVar7 = (undefined *)(param_1 + 8);
    if ((param_1 & 7) != 0) {
      puVar7 = (undefined *)(((uint)puVar7 & 0xfffffff8) + 8);
    }
    if ((puVar7 != (undefined *)0x0) && (puVar7 <= DAT_000887a8)) {
      piVar3 = (int *)&DAT_000887b8;
      piVar4 = DAT_000887b8;
      do {
        piVar8 = piVar4;
        piVar6 = piVar3;
        if (puVar7 <= (undefined *)piVar8[1]) break;
        piVar3 = piVar8;
        piVar4 = (int *)*piVar8;
      } while ((int *)*piVar8 != (int *)0x0);
      if (DAT_000887a0 != piVar8) {
        uVar5 = piVar8[1] - (int)puVar7;
        iVar9 = *piVar6;
        *piVar6 = *piVar8;
        if (0x10 < uVar5) {
          if (((uint)((int)piVar8 + (int)puVar7) & 7) != 0) {
            vPortRaiseBASEPRI();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *(uint *)((undefined *)((int)piVar8 + (int)puVar7) + 4) = uVar5;
          piVar8[1] = (int)puVar7;
          prvInsertBlockIntoFreeList();
        }
        puVar7 = DAT_000887ac;
        DAT_000887a8 = puVar2 + -piVar8[1];
        *piVar8 = 0;
        DAT_000887b0 = DAT_000887b0 + 1;
        if (DAT_000887a8 < puVar7) {
          DAT_000887ac = DAT_000887a8;
        }
        uVar5 = iVar9 + 8;
        piVar8[1] = uVar1 | piVar8[1];
        goto LAB_00081f9a;
      }
    }
  }
  uVar5 = 0;
LAB_00081f9a:
  xTaskResumeAll();
  if ((uVar5 & 7) != 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar5;
}


// ===== vPortFree @ 00081fd4 (86 bytes)

void vPortFree(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if ((*(uint *)(param_1 + -4) & DAT_000887a4) == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (*(int *)(param_1 + -8) != 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(uint *)(param_1 + -4) = *(uint *)(param_1 + -4) & ~DAT_000887a4;
  vTaskSuspendAll();
  DAT_000887a8 = *(int *)(param_1 + -4) + DAT_000887a8;
  prvInsertBlockIntoFreeList(param_1 + -8);
  DAT_000887b4 = DAT_000887b4 + 1;
  xTaskResumeAll();
  return;
}


// ===== prvTaskExitError @ 00082038 (36 bytes)

/* WARNING: Removing unreachable block (ram,0x00082056) */

void prvTaskExitError(void)

{
  if (DAT_00087ebc == -1) {
    vPortRaiseBASEPRI();
    do {
    } while( true );
  }
  vPortRaiseBASEPRI();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== vPortSetupTimerInterrupt @ 00082060 (32 bytes)

void vPortSetupTimerInterrupt(void)

{
  DAT_e000e010 = 0;
  DAT_e000e018 = 0;
  DAT_e000e014 = DAT_00087ec0 / 1000 - 1;
  DAT_e000e010 = 7;
  return;
}


// ===== vPortEnterCritical @ 00082084 (24 bytes)

void vPortEnterCritical(void)

{
  vPortRaiseBASEPRI();
  DAT_00087ebc = DAT_00087ebc + 1;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== vPortExitCritical @ 000820a0 (34 bytes)

void vPortExitCritical(void)

{
  if (DAT_00087ebc == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_00087ebc = DAT_00087ebc + -1;
  if (DAT_00087ebc == 0) {
    vPortClearBASEPRI();
    return;
  }
  return;
}


// ===== pxPortInitialiseStack @ 000820c8 (106 bytes)

undefined4 *
pxPortInitialiseStack(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *(undefined4 *)(param_1 + -8) = param_3;
  *(undefined4 *)(param_1 + -4) = 0x1000000;
  *(undefined4 *)(param_1 + -0xc) = 0x82039;
  *(undefined4 *)(param_1 + -0x14) = 0x3030303;
  *(undefined4 *)(param_1 + -0x10) = 0x12121212;
  *(undefined4 *)(param_1 + -0x20) = param_4;
  *(undefined4 *)(param_1 + -0x1c) = 0x1010101;
  *(undefined4 *)(param_1 + -0x18) = 0x2020202;
  *(undefined4 *)(param_1 + -0x28) = 0x10101010;
  *(undefined4 *)(param_1 + -0x24) = 0x11111111;
  *(undefined4 *)(param_1 + -0x30) = 0x8080808;
  *(undefined4 *)(param_1 + -0x2c) = 0x9090909;
  *(undefined4 *)(param_1 + -0x38) = 0x6060606;
  *(undefined4 *)(param_1 + -0x34) = 0x7070707;
  *(undefined4 *)(param_1 + -0x40) = 0x4040404;
  *(undefined4 *)(param_1 + -0x3c) = 0x5050505;
  *(undefined4 *)(param_1 + -0x44) = 0xfffffffd;
  *(undefined4 *)(param_1 + -0x48) = param_2;
  return (undefined4 *)(param_1 + -0x48);
}


// ===== xEventGroupSetBitsFromISR @ 00082174 (46 bytes)

void xEventGroupSetBitsFromISR(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 local_18;
  undefined1 *puStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = 0xfffffffe;
  puStack_14 = &LAB_00086712_1;
  local_10 = param_1;
  uStack_c = param_2;
  xQueueGenericSendFromISR(DAT_00088920,&local_18,param_3,0);
  return;
}


// ===== vQueueAddToRegistry @ 00082184 (32 bytes)

void vQueueAddToRegistry(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_000887c0)[iVar1 * 2] == 0) {
      (&DAT_000887c0)[iVar1 * 2] = param_2;
      (&DAT_000887c4)[iVar1 * 2] = param_1;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 8);
  return;
}


// ===== vQueueUnregisterQueue @ 000821a8 (34 bytes)

void vQueueUnregisterQueue(int param_1)

{
  int iVar1;
  
  iVar1 = 0;
  do {
    if ((&DAT_000887c4)[iVar1 * 2] == param_1) {
      (&DAT_000887c0)[iVar1 * 2] = 0;
      (&DAT_000887c4)[iVar1 * 2] = 0;
      return;
    }
    iVar1 = iVar1 + 1;
  } while (iVar1 != 8);
  return;
}


// ===== prvIdleTask @ 000821d0 (16 bytes)

/* NEW: "IDLE" task entry (vTaskStartScheduler, stack 0x80 words, prio 0) [fact] */

void prvIdleTask(void)

{
  do {
    do {
    } while (DAT_0008880c < 2);
    vPortYield();
  } while( true );
}


// ===== prvAddCurrentTaskToDelayedList @ 000821e4 (88 bytes)

void prvAddCurrentTaskToDelayedList(uint param_1,int param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_000888e4;
  uxListRemove(DAT_00088800 + 4);
  if ((param_1 == 0xffffffff) && (param_2 != 0)) {
    vListInsertEnd(&DAT_000888d0,DAT_00088800 + 4);
    return;
  }
  uVar2 = uVar1 + param_1;
  *(uint *)(DAT_00088800 + 4) = uVar2;
  if (CARRY4(uVar1,param_1)) {
    vListInsert(DAT_00088808,DAT_00088800 + 4);
    return;
  }
  vListInsert(DAT_00088804,DAT_00088800 + 4);
  if (uVar2 < DAT_000888ac) {
    DAT_000888ac = uVar2;
  }
  return;
}


// ===== prvResetNextTaskUnblockTime @ 00082254 (28 bytes)

/* xNextTaskUnblockTime 0x888AC [inference] */

void prvResetNextTaskUnblockTime(void)

{
  if (*DAT_00088804 == 0) {
    DAT_000888ac = 0xffffffff;
  }
  else {
    DAT_000888ac = *(undefined4 *)(*(int *)(DAT_00088804[3] + 0xc) + 4);
  }
  return;
}


// ===== xTaskCreate @ 00082278 (366 bytes)

undefined4
xTaskCreate(undefined4 param_1,int param_2,int param_3,undefined4 param_4,uint param_5,int *param_6)

{
  char cVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  char *pcVar5;
  char *pcVar6;
  uint uVar7;
  undefined4 *puVar8;
  
  param_3 = param_3 * 4;
  iVar2 = pvPortMalloc(param_3);
  if (iVar2 != 0) {
    puVar3 = (undefined4 *)pvPortMalloc(0x70);
    if (puVar3 != (undefined4 *)0x0) {
      puVar3[0xc] = iVar2;
      memset(iVar2,0xa5,param_3);
      uVar7 = param_3 + -4 + puVar3[0xc] & 0xfffffff8;
      puVar3[0x10] = uVar7;
      if (param_2 == 0) {
        *(undefined1 *)(puVar3 + 0xd) = 0;
      }
      else {
        pcVar6 = (char *)(param_2 + -1);
        pcVar5 = (char *)(puVar3 + 0xd);
        do {
          pcVar6 = pcVar6 + 1;
          cVar1 = *pcVar6;
          *pcVar5 = cVar1;
          if (cVar1 == '\0') break;
          pcVar5 = pcVar5 + 1;
        } while (pcVar6 != (char *)(param_2 + 9));
        *(undefined1 *)((int)puVar3 + 0x3d) = 0;
      }
      if (3 < param_5) {
        param_5 = 4;
      }
      puVar3[0xb] = param_5;
      puVar3[0x13] = param_5;
      puVar3[0x14] = 0;
      vListInitialiseItem(puVar3 + 1);
      vListInitialiseItem(puVar3 + 6);
      puVar3[0x1a] = 0;
      puVar3[0x15] = 0;
      puVar3[0x16] = 0;
      puVar3[0x17] = 0;
      puVar3[0x18] = 0;
      puVar3[4] = puVar3;
      puVar3[6] = 5 - param_5;
      puVar3[9] = puVar3;
      puVar3[0x19] = 0;
      *(undefined1 *)(puVar3 + 0x1b) = 0;
      uVar4 = pxPortInitialiseStack(uVar7,puVar3[0xc],param_1,param_4);
      *puVar3 = uVar4;
      if (param_6 != (int *)0x0) {
        *param_6 = (int)puVar3;
      }
      vPortEnterCritical();
      DAT_00088870 = DAT_00088870 + 1;
      if (DAT_00088800 == (undefined4 *)0x0) {
        DAT_00088800 = puVar3;
        if (DAT_00088870 == 1) {
          puVar8 = &DAT_0008880c;
          iVar2 = 0;
          do {
            iVar2 = iVar2 + 1;
            vListInitialise(puVar8);
            puVar8 = puVar8 + 5;
          } while (iVar2 != 5);
          vListInitialise(&DAT_00088880);
          vListInitialise(&DAT_00088894);
          vListInitialise(&DAT_000888b8);
          vListInitialise(&DAT_000888d0);
          DAT_00088804 = &DAT_00088880;
          DAT_00088808 = &DAT_00088894;
        }
      }
      else if ((DAT_000888cc == 0) && ((uint)DAT_00088800[0xb] <= (uint)puVar3[0xb])) {
        DAT_00088800 = puVar3;
      }
      DAT_00088878 = DAT_00088878 + 1;
      puVar3[0x11] = DAT_00088878;
      uVar7 = puVar3[0xb];
      if (DAT_0008887c < uVar7) {
        DAT_0008887c = uVar7;
      }
      vListInsertEnd(&DAT_0008880c + uVar7 * 5,puVar3 + 1);
      vPortExitCritical();
      if ((DAT_000888cc != 0) && ((uint)DAT_00088800[0xb] < (uint)puVar3[0xb])) {
        vPortYield();
      }
      return 1;
    }
    vPortFree(iVar2);
  }
  return 0xffffffff;
}


// ===== vTaskStartScheduler @ 00082418 (138 bytes)

int vTaskStartScheduler(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = xTaskCreate(0x821d1,"IDLE",0x80,0,0,&DAT_000888a8,param_3);
  if ((iVar2 == 1) && (iVar2 = xTimerCreateTimerTask(), iVar2 == 1)) {
    vPortRaiseBASEPRI();
    DAT_000888ac = 0xffffffff;
    DAT_000888e4 = 0;
    uVar1 = DAT_e000ed20;
    DAT_e000ed20 = uVar1 | 0xff0000;
    uVar1 = DAT_e000ed20;
    DAT_e000ed20 = uVar1 | 0xff000000;
    DAT_000888cc = iVar2;
    vPortSetupTimerInterrupt();
    DAT_00087ebc = 0;
    vStartFirstTask();
    vTaskSwitchContext();
    prvTaskExitError();
    return 0;
  }
  if (iVar2 == -1) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return iVar2;
}


// ===== vTaskSuspendAll @ 00082484 (10 bytes)

void vTaskSuspendAll(void)

{
  DAT_00088874 = DAT_00088874 + 1;
  return;
}


// ===== xTaskGetTickCount @ 00082494 (6 bytes)

/* xTickCount 0x888E4 [inference] */

undefined4 xTaskGetTickCount(void)

{
  return DAT_000888e4;
}


// ===== xTaskIncrementTick @ 000824a0 (202 bytes)

/* [inference] */

undefined4 xTaskIncrementTick(void)

{
  int *piVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  piVar1 = DAT_00088804;
  if (DAT_00088874 == 0) {
    uVar5 = DAT_000888e4 + 1;
    DAT_000888e4 = uVar5;
    if (uVar5 == 0) {
      if (*DAT_00088804 != 0) {
        vPortRaiseBASEPRI();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      DAT_00088804 = DAT_00088808;
      DAT_00088808 = piVar1;
      DAT_000888b0 = DAT_000888b0 + 1;
      prvResetNextTaskUnblockTime();
    }
    uVar3 = 0;
    uVar2 = DAT_000888ac;
    if (DAT_000888ac <= uVar5) {
      while (*DAT_00088804 != 0) {
        iVar4 = *(int *)(DAT_00088804[3] + 0xc);
        uVar2 = *(uint *)(iVar4 + 4);
        if (uVar5 < *(uint *)(iVar4 + 4)) goto LAB_000824e4;
        uxListRemove(iVar4 + 4);
        if (*(int *)(iVar4 + 0x28) != 0) {
          uxListRemove(iVar4 + 0x18);
        }
        uVar2 = *(uint *)(iVar4 + 0x2c);
        if (DAT_0008887c < uVar2) {
          DAT_0008887c = uVar2;
        }
        vListInsertEnd(&DAT_0008880c + uVar2 * 5,iVar4 + 4);
        if (*(uint *)(DAT_00088800 + 0x2c) <= *(uint *)(iVar4 + 0x2c)) {
          uVar3 = 1;
        }
      }
      uVar2 = 0xffffffff;
    }
LAB_000824e4:
    DAT_000888ac = uVar2;
    if (DAT_000888e8 != 0) {
      uVar3 = 1;
    }
  }
  else {
    uVar3 = 0;
    DAT_000888b4 = DAT_000888b4 + 1;
  }
  return uVar3;
}


// ===== xTaskResumeAll @ 00082598 (170 bytes)

undefined4 xTaskResumeAll(void)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  
  if (DAT_00088874 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortEnterCritical();
  DAT_00088874 = DAT_00088874 + -1;
  if ((DAT_00088874 == 0) && (DAT_00088870 != 0)) {
    iVar4 = 0;
    while (DAT_000888b8 != 0) {
      iVar4 = *(int *)(DAT_000888c4 + 0xc);
      uxListRemove(iVar4 + 0x18);
      uxListRemove(iVar4 + 4);
      uVar2 = *(uint *)(iVar4 + 0x2c);
      if (DAT_0008887c < uVar2) {
        DAT_0008887c = uVar2;
      }
      vListInsertEnd(&DAT_0008880c + uVar2 * 5,iVar4 + 4);
      if (*(uint *)(DAT_00088800 + 0x2c) <= *(uint *)(iVar4 + 0x2c)) {
        DAT_000888e8 = 1;
      }
    }
    if (iVar4 != 0) {
      prvResetNextTaskUnblockTime();
    }
    iVar4 = DAT_000888b4;
    if (DAT_000888b4 != 0) {
      do {
        iVar1 = xTaskIncrementTick();
        if (iVar1 != 0) {
          DAT_000888e8 = 1;
        }
        iVar4 = iVar4 + -1;
      } while (iVar4 != 0);
      DAT_000888b4 = 0;
    }
    if (DAT_000888e8 != 0) {
      vPortYield();
      uVar3 = 1;
      goto LAB_000825b6;
    }
  }
  uVar3 = 0;
LAB_000825b6:
  vPortExitCritical();
  return uVar3;
}


// ===== vTaskDelay @ 00082664 (42 bytes)

void vTaskDelay(int param_1)

{
  int iVar1;
  
  if (param_1 != 0) {
    if (DAT_00088874 != 0) {
      vPortRaiseBASEPRI();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    vTaskSuspendAll();
    prvAddCurrentTaskToDelayedList();
    iVar1 = xTaskResumeAll();
    if (iVar1 != 0) {
      return;
    }
  }
  vPortYield();
  return;
}


// ===== vTaskSwitchContext @ 00082694 (86 bytes)

void vTaskSwitchContext(void)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  if (DAT_00088874 == 0) {
    DAT_000888e8 = DAT_00088874;
    iVar1 = DAT_0008887c;
    while( true ) {
      iVar2 = iVar1 * 0x14;
      if ((&DAT_0008880c)[iVar1 * 5] != 0) break;
      if (iVar1 == 0) {
        vPortRaiseBASEPRI();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      iVar1 = iVar1 + -1;
    }
    iVar4 = *(int *)(*(int *)(&DAT_00088810 + iVar2) + 4);
    iVar3 = iVar2 + 0x88814;
    bVar5 = iVar4 == iVar3;
    if (bVar5) {
      iVar3 = *(int *)(iVar4 + 4);
    }
    *(int *)(&DAT_00088810 + iVar2) = iVar4;
    if (bVar5) {
      *(int *)(&DAT_00088810 + iVar2) = iVar3;
    }
    DAT_00088800 = *(undefined4 *)(*(int *)(&DAT_00088810 + iVar1 * 0x14) + 0xc);
    DAT_0008887c = iVar1;
  }
  else {
    DAT_000888e8 = 1;
  }
  return;
}


// ===== vTaskPlaceOnEventList @ 00082700 (34 bytes)

/* [inference] */

void vTaskPlaceOnEventList(int param_1,undefined4 param_2)

{
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vListInsert(param_1,DAT_00088800 + 0x18);
  prvAddCurrentTaskToDelayedList(param_2,1);
  return;
}


// ===== vTaskPlaceOnUnorderedEventList @ 00082728 (54 bytes)

/* [inference] */

void vTaskPlaceOnUnorderedEventList(int param_1,uint param_2,undefined4 param_3)

{
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_00088874 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(uint *)(DAT_00088800 + 0x18) = param_2 | 0x80000000;
  vListInsertEnd(param_1,DAT_00088800 + 0x18);
  prvAddCurrentTaskToDelayedList(param_3,1);
  return;
}


// ===== vTaskPlaceOnEventListRestricted @ 00082768 (46 bytes)

/* [inference] */

void vTaskPlaceOnEventListRestricted(int param_1,undefined4 param_2,int param_3)

{
  if (param_1 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vListInsertEnd(param_1,DAT_00088800 + 0x18);
  if (param_3 != 0) {
    param_2 = 0xffffffff;
  }
  prvAddCurrentTaskToDelayedList(param_2,param_3);
  return;
}


// ===== xTaskRemoveFromEventList @ 0008279c (100 bytes)

/* [inference] */

void xTaskRemoveFromEventList(int param_1)

{
  undefined4 *puVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = *(int *)(*(int *)(param_1 + 0xc) + 0xc);
  if (iVar4 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar2 = iVar4 + 0x18;
  uxListRemove(iVar2);
  if (DAT_00088874 == 0) {
    iVar2 = iVar4 + 4;
    uxListRemove(iVar2);
    uVar3 = *(uint *)(iVar4 + 0x2c);
    if (DAT_0008887c < uVar3) {
      DAT_0008887c = uVar3;
    }
    puVar1 = &DAT_0008880c + uVar3 * 5;
  }
  else {
    puVar1 = &DAT_000888b8;
  }
  vListInsertEnd(puVar1,iVar2);
  if (*(uint *)(DAT_00088800 + 0x2c) < *(uint *)(iVar4 + 0x2c)) {
    DAT_000888e8 = 1;
  }
  return;
}


// ===== vTaskRemoveFromUnorderedEventList @ 00082818 (94 bytes)

/* [inference] */

void vTaskRemoveFromUnorderedEventList(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_00088874 == 0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar2 = param_1[3];
  *param_1 = param_2 | 0x80000000;
  if (uVar2 != 0) {
    uxListRemove();
    uxListRemove(uVar2 + 4);
    uVar1 = *(uint *)(uVar2 + 0x2c);
    if (DAT_0008887c < uVar1) {
      DAT_0008887c = uVar1;
    }
    vListInsertEnd(&DAT_0008880c + uVar1 * 5,uVar2 + 4);
    if (*(uint *)(DAT_00088800 + 0x2c) < *(uint *)(uVar2 + 0x2c)) {
      DAT_000888e8 = 1;
    }
    return;
  }
  vPortRaiseBASEPRI();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== vTaskInternalSetTimeOutState @ 0008288c (14 bytes)

/* [inference] */

void vTaskInternalSetTimeOutState(undefined4 *param_1)

{
  *param_1 = DAT_000888b0;
  param_1[1] = DAT_000888e4;
  return;
}


// ===== xTaskCheckForTimeOut @ 000828a4 (88 bytes)

/* [inference] */

undefined4 xTaskCheckForTimeOut(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  if (param_1 == (int *)0x0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == (uint *)0x0) {
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortEnterCritical();
  uVar2 = *param_2;
  if (uVar2 == 0xffffffff) {
LAB_000828ea:
    uVar3 = 0;
  }
  else {
    uVar1 = param_1[1];
    if ((*param_1 == DAT_000888b0) || (DAT_000888e4 < uVar1)) {
      if (DAT_000888e4 - uVar1 < uVar2) {
        *param_2 = (uVar2 - DAT_000888e4) + uVar1;
        vTaskInternalSetTimeOutState(param_1);
        goto LAB_000828ea;
      }
      *param_2 = 0;
    }
    uVar3 = 1;
  }
  vPortExitCritical();
  return uVar3;
}


// ===== vTaskMissedYield @ 00082904 (8 bytes)

/* xYieldPending 0x888E8 [inference] */

void vTaskMissedYield(void)

{
  DAT_000888e8 = 1;
  return;
}


// ===== xTaskGetSchedulerState @ 00082910 (24 bytes)

/* [inference] */

undefined4 xTaskGetSchedulerState(void)

{
  undefined4 uVar1;
  
  if (DAT_000888cc == 0) {
    return 1;
  }
  if (DAT_00088874 == 0) {
    uVar1 = 2;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== xTaskPriorityInherit @ 00082930 (118 bytes)

/* [inference] */

bool xTaskPriorityInherit(int param_1)

{
  uint uVar1;
  uint uVar2;
  bool bVar3;
  int iVar4;
  
  bVar3 = false;
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x2c) < *(uint *)(DAT_00088800 + 0x2c)) {
      if (-1 < *(int *)(param_1 + 0x18)) {
        *(int *)(param_1 + 0x18) = 5 - *(int *)(DAT_00088800 + 0x2c);
      }
      if (*(undefined4 **)(param_1 + 0x14) == &DAT_0008880c + *(uint *)(param_1 + 0x2c) * 5) {
        iVar4 = param_1;
        uxListRemove(param_1 + 4);
        uVar1 = DAT_0008887c;
        uVar2 = *(uint *)(DAT_00088800 + 0x2c);
        *(uint *)(param_1 + 0x2c) = uVar2;
        if (uVar1 < uVar2) {
          DAT_0008887c = uVar2;
        }
        vListInsertEnd(&DAT_0008880c + uVar2 * 5,param_1 + 4,&DAT_0008887c,uVar2,iVar4);
      }
      else {
        *(undefined4 *)(param_1 + 0x2c) = *(undefined4 *)(DAT_00088800 + 0x2c);
      }
      bVar3 = true;
    }
    else {
      bVar3 = *(uint *)(param_1 + 0x4c) < *(uint *)(DAT_00088800 + 0x2c);
    }
  }
  return bVar3;
}


// ===== xTaskPriorityDisinherit @ 000829b4 (100 bytes)

/* [inference] */

undefined4 xTaskPriorityDisinherit(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = DAT_00088800;
  if (param_1 != 0) {
    if (DAT_00088800 != param_1) {
      vPortRaiseBASEPRI();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (*(int *)(DAT_00088800 + 0x50) == 0) {
      vPortRaiseBASEPRI();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    piVar1 = (int *)(DAT_00088800 + 0x2c);
    piVar2 = (int *)(DAT_00088800 + 0x4c);
    iVar4 = *(int *)(DAT_00088800 + 0x50) + -1;
    *(int *)(DAT_00088800 + 0x50) = iVar4;
    if ((*piVar1 != *piVar2) && (iVar4 == 0)) {
      uxListRemove(iVar3 + 4);
      uVar5 = *(uint *)(iVar3 + 0x4c);
      *(uint *)(iVar3 + 0x18) = 5 - uVar5;
      *(uint *)(iVar3 + 0x2c) = uVar5;
      if (DAT_0008887c < uVar5) {
        DAT_0008887c = uVar5;
      }
      vListInsertEnd(&DAT_0008880c + uVar5 * 5,iVar3 + 4);
      return 1;
    }
  }
  return 0;
}


// ===== vTaskPriorityDisinheritAfterTimeout @ 00082a24 (126 bytes)

/* [inference] */

void vTaskPriorityDisinheritAfterTimeout(int param_1,uint param_2)

{
  uint uVar1;
  
  if (param_1 != 0) {
    if (*(int *)(param_1 + 0x50) == 0) {
      vPortRaiseBASEPRI();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (param_2 < *(uint *)(param_1 + 0x4c)) {
      param_2 = *(uint *)(param_1 + 0x4c);
    }
    uVar1 = *(uint *)(param_1 + 0x2c);
    if ((uVar1 != param_2) && (*(int *)(param_1 + 0x50) == 1)) {
      if (DAT_00088800 == param_1) {
        vPortRaiseBASEPRI();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
      *(uint *)(param_1 + 0x2c) = param_2;
      if (-1 < *(int *)(param_1 + 0x18)) {
        *(uint *)(param_1 + 0x18) = 5 - param_2;
      }
      if (*(undefined4 **)(param_1 + 0x14) == &DAT_0008880c + uVar1 * 5) {
        uxListRemove(param_1 + 4);
        uVar1 = *(uint *)(param_1 + 0x2c);
        if (DAT_0008887c < uVar1) {
          DAT_0008887c = uVar1;
        }
        vListInsertEnd(&DAT_0008880c + uVar1 * 5,param_1 + 4);
        return;
      }
    }
  }
  return;
}


// ===== uxTaskResetEventItemValue @ 00082ab0 (20 bytes)

/* [inference] */

undefined4 uxTaskResetEventItemValue(void)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(DAT_00088800 + 0x18);
  *(int *)(DAT_00088800 + 0x18) = 5 - *(int *)(DAT_00088800 + 0x2c);
  return uVar1;
}


// ===== pvTaskIncrementMutexHeldCount @ 00082ac8 (18 bytes)

/* [inference] */

int pvTaskIncrementMutexHeldCount(void)

{
  if (DAT_00088800 != 0) {
    *(int *)(DAT_00088800 + 0x50) = *(int *)(DAT_00088800 + 0x50) + 1;
  }
  return DAT_00088800;
}


// ===== ulTaskNotifyTake @ 00082ae0 (80 bytes)

int ulTaskNotifyTake(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  vPortEnterCritical();
  if (*(int *)(DAT_00088800 + 0x68) == 0) {
    *(undefined1 *)(DAT_00088800 + 0x6c) = 1;
    if (param_2 != 0) {
      prvAddCurrentTaskToDelayedList(param_2);
      vPortYield();
    }
  }
  vPortExitCritical();
  vPortEnterCritical();
  iVar2 = *(int *)(DAT_00088800 + 0x68);
  if (iVar2 != 0) {
    if (param_1 == 0) {
      iVar1 = iVar2 + -1;
    }
    else {
      iVar1 = 0;
    }
    *(int *)(DAT_00088800 + 0x68) = iVar1;
  }
  *(undefined1 *)(DAT_00088800 + 0x6c) = 0;
  vPortExitCritical();
  return iVar2;
}

