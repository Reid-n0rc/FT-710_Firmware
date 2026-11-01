// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== platform_init_interrupt @ 000818d0 (54 bytes)

/* rename (was platform_interrupt_enable): env_register_isr, then on first use MU-A CR |= RIE1 (bit
   26), refcount 0x88710 */

undefined4 platform_init_interrupt(uint param_1,uint param_2)

{
  uint mua_cr;
  
  env_register_isr(param_1,param_2);
  env_lock_mutex(DAT_00088714);
  if (DAT_00088710 < 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_00088710 == 0) {
    mua_cr = MUA_CR;
    MUA_CR = mua_cr & 0xfff0ffff | 0x4000000;
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
    MU_SendMsg(0x40110000,1,param_1 << 0x10);
    env_unlock_mutex(DAT_00088714);
    return;
  }
  return;
}


// ===== xPortIsInsideInterrupt @ 00081944 (16 bytes)

bool xPortIsInsideInterrupt(void)

{
  uint scb_icsr;
  
  scb_icsr = SCB_ICSR;
  return (scb_icsr & 0x1ff) != 0;
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
    NVIC_ISER1 = 4;
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
    NVIC_ICER1 = 4;
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
  int env_create_mutex_ret;
  
  MU_Init();
  NVIC_IPR8._2_1_ = 0x60;
  NVIC_ISER1 = 4;
  env_create_mutex_ret = env_create_mutex(&DAT_00088714,1);
  return -(uint)(env_create_mutex_ret != 0);
}


// ===== env_init @ 000819e8 (106 bytes)

/* rename (was platform_init): first call creates binary sema 0x8871C, clears isr_table 0x88720,
   calls platform_init */

uint env_init(void)

{
  uint uVar1;
  
  vTaskSuspendAll();
  if (DAT_00088718 < 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_00088718 = DAT_00088718 + 1;
  if (DAT_00088718 == 1) {
    DAT_0008871c = (int *)xQueueGenericCreate(1,0,3);
    memset(&DAT_00088720,0,0x80);
    xTaskResumeAll();
    uVar1 = platform_init();
    xQueueGenericSend((int)DAT_0008871c,0,0,0);
  }
  else {
    xTaskResumeAll();
    uVar1 = xQueueSemaphoreTake(DAT_0008871c,-1);
    if (uVar1 == 1) {
      xQueueGenericSend((int)DAT_0008871c,0,0,0);
    }
    uVar1 = 0;
  }
  return uVar1;
}


// ===== env_register_isr @ 00081a60 (14 bytes)

/* rename (was platform_register_isr): isr_table[vector] = vq (32 entries at 0x88720) */

void env_register_isr(uint param_1,uint param_2)

{
  if (0x1f < param_1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(uint *)(&DAT_00088720 + param_1 * 4) = param_2;
  return;
}


// ===== rpmsg_queue_recv @ 00081a88 (104 bytes)

undefined4
rpmsg_queue_recv(void *rpmsg_lite_dev,uint param_2,undefined4 *param_3,void *param_4,uint param_5,
                uint *param_6,uint param_7)

{
  bool env_get_queue_ret;
  int rpmsg_queue_nocopy_free_ret;
  undefined4 uVar1;
  undefined4 local_24;
  void *local_20;
  uint local_1c;
  
  local_24 = 0;
  local_20 = (void *)0x0;
  local_1c = 0;
  if (((rpmsg_lite_dev != (void *)0x0) && (param_2 != 0)) && (param_4 != (void *)0x0)) {
    env_get_queue_ret = env_get_queue(param_2,(uint)&local_24,param_7);
    if (!env_get_queue_ret) {
      return 0xffffec72;
    }
    if (param_3 != (undefined4 *)0x0) {
      *param_3 = local_24;
    }
    if (param_6 != (uint *)0x0) {
      *param_6 = local_1c;
    }
    if (param_5 < local_1c) {
      uVar1 = 0xffffec76;
    }
    else {
      memcpy(param_4,local_20,local_1c);
      uVar1 = 0;
    }
    rpmsg_queue_nocopy_free_ret = rpmsg_queue_nocopy_free(rpmsg_lite_dev,local_20);
    if (rpmsg_queue_nocopy_free_ret == 0) {
      return uVar1;
    }
  }
  return 0xffffec75;
}


// ===== rpmsg_lite_send @ 00081afc (218 bytes)

undefined4
rpmsg_lite_send(int param_1,undefined4 *param_2,undefined4 param_3,void *param_4,uint param_5,
               uint param_6)

{
  undefined4 *puVar1;
  uint i;
  undefined4 uVar2;
  undefined4 uStack_30;
  undefined4 *local_2c;
  undefined4 uStack_28;
  
  if (param_2 != (undefined4 *)0x0) {
    if (0x1f0 < param_5) {
      return 0xffffec76;
    }
    uVar2 = *param_2;
    if ((param_1 != 0) && (param_4 != (void *)0x0)) {
      if (*(int *)(param_1 + 0x10) != 1) {
        return 0xffffec71;
      }
      uStack_30 = param_1;
      local_2c = param_2;
      uStack_28 = param_3;
      env_lock_mutex(*(uint *)(param_1 + 0xc));
      puVar1 = (undefined4 *)
               (**(code **)(*(int *)(param_1 + 0x20) + 4))
                         (*(undefined4 *)(param_1 + 4),&local_2c,(int)&uStack_30 + 2);
      env_unlock_mutex(*(uint *)(param_1 + 0xc));
      if (puVar1 == (undefined4 *)0x0) {
        if (param_6 == 0) {
          return 0xffffec77;
        }
        i = 0;
        do {
          vTaskDelay(1);
          env_lock_mutex(*(uint *)(param_1 + 0xc));
          puVar1 = (undefined4 *)
                   (**(code **)(*(int *)(param_1 + 0x20) + 4))
                             (*(undefined4 *)(param_1 + 4),&local_2c,(int)&uStack_30 + 2);
          i = i + 1;
          env_unlock_mutex(*(uint *)(param_1 + 0xc));
          if (param_6 <= i) {
            if (puVar1 == (undefined4 *)0x0) {
              return 0xffffec77;
            }
            break;
          }
        } while (puVar1 == (undefined4 *)0x0);
      }
      puVar1[1] = param_3;
      *puVar1 = uVar2;
      *(short *)(puVar1 + 3) = (short)param_5;
      *(undefined1 *)((int)puVar1 + 0xe) = 0;
      *(undefined1 *)((int)puVar1 + 0xf) = 0;
      memcpy(puVar1 + 4,param_4,param_5);
      env_lock_mutex(*(uint *)(param_1 + 0xc));
      (*(code *)**(undefined4 **)(param_1 + 0x20))
                (*(undefined4 *)(param_1 + 4),puVar1,local_2c,uStack_30._2_2_);
      virtqueue_kick(*(int *)(param_1 + 4));
      env_unlock_mutex(*(uint *)(param_1 + 0xc));
      return 0;
    }
  }
  return 0xffffec75;
}


// ===== rpmsg_queue_nocopy_free @ 00081be8 (60 bytes)

int rpmsg_queue_nocopy_free(void *rpmsg_lite_dev,void *data)

{
  uint virtqueue_get_buffer_length_ret;
  int iVar1;
  code *pcVar2;
  
  if ((rpmsg_lite_dev == (void *)0x0) || (data == (void *)0x0)) {
    iVar1 = -0x138b;
  }
  else {
    env_lock_mutex(*(uint *)((int)rpmsg_lite_dev + 0xc));
    iVar1 = *(int *)rpmsg_lite_dev;
    pcVar2 = *(code **)(*(int *)((int)rpmsg_lite_dev + 0x20) + 0xc);
    virtqueue_get_buffer_length_ret =
         virtqueue_get_buffer_length(iVar1,(uint)*(ushort *)((int)data + -6));
    (*pcVar2)(iVar1,(int)data + -0x10,virtqueue_get_buffer_length_ret,
              *(undefined2 *)((int)data + -6));
    env_unlock_mutex(*(uint *)((int)rpmsg_lite_dev + 0xc));
    iVar1 = 0;
  }
  return iVar1;
}


// ===== rpmsg_lite_master_init @ 00081c28 (428 bytes)

int * rpmsg_lite_master_init(uint param_1,uint param_2,int param_3)

{
  int *pvPortMalloc_ret;
  uint uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  uint local_4c [2];
  char *local_44 [2];
  int local_3c [4];
  undefined2 local_2c;
  
  uVar3 = param_2 - 0x800;
  uVar1 = uVar3;
  if ((param_2 & 3) != 0) {
    uVar1 = uVar3 & 0xfffffffc;
  }
  if ((((0x7ff < uVar1) && (param_3 == 0)) && (param_1 != 0)) &&
     (pvPortMalloc_ret = (int *)pvPortMalloc(0x24), pvPortMalloc_ret != (int *)0x0)) {
    memset(pvPortMalloc_ret,0,0x24);
    uVar1 = env_init();
    if (uVar1 == 0) {
      pvPortMalloc_ret[6] = uVar3 >> 9;
      pvPortMalloc_ret[7] = uVar3 >> 9;
      iVar4 = 0;
      piVar5 = local_3c;
      iVar2 = 0;
      uVar1 = param_1 + 0x800;
      if ((param_1 & 3) != 0) {
        uVar1 = (uVar1 & 0xfffffffc) + 4;
      }
      pvPortMalloc_ret[5] = uVar1;
      local_44[0] = "rx_vq";
      local_44[1] = "tx_vq";
      local_4c[0] = 0x86259;
      local_4c[1] = 0x8621f;
      pvPortMalloc_ret[8] = (int)&PTR_vq_tx_master_1_000879ac;
      piVar6 = piVar5;
      while( true ) {
        local_3c[2] = iVar2 + param_1;
        local_3c[3] = 0x10;
        local_2c = 2;
        memset(local_3c[2],0,0x4e);
        uVar1 = virtqueue_create((ushort)iVar4,(uint)local_44[iVar4],local_3c + 2,local_4c[iVar4],
                                 0x8622b,piVar6);
        if (uVar1 != 0) break;
        vq_ring_init(*piVar6);
        virtqueue_disable_cb(*piVar6);
        iVar2 = 0x400;
        *(int **)(*piVar6 + 100) = pvPortMalloc_ret;
        if (iVar4 != 0) {
          iVar2 = env_create_mutex(pvPortMalloc_ret + 3,iVar4);
          if (iVar2 == 0) {
            pvPortMalloc_ret[1] = local_3c[1];
            *pvPortMalloc_ret = local_3c[0];
            iVar2 = 0;
            do {
              for (uVar1 = 0;
                  (uVar1 < *(ushort *)(*piVar5 + 0x52) && (uVar1 < (uint)pvPortMalloc_ret[7]));
                  uVar1 = uVar1 + 1) {
                iVar4 = pvPortMalloc_ret[6];
                if (iVar4 == 0) {
LAB_00081d36:
                  do {
                    /* WARNING: Do nothing block with infinite loop */
                  } while( true );
                }
                uVar3 = pvPortMalloc_ret[5] + (pvPortMalloc_ret[7] - iVar4) * 0x200;
                pvPortMalloc_ret[6] = iVar4 + -1;
                if (uVar3 == 0) goto LAB_00081d36;
                memset(uVar3,0,0x200);
                iVar4 = *piVar5;
                if (iVar4 == *pvPortMalloc_ret) {
                  uVar3 = virtqueue_fill_avail_buffers(iVar4,uVar3,0x200);
LAB_00081d56:
                  if (uVar3 != 0) {
                    vQueueDelete(pvPortMalloc_ret[3]);
                    goto LAB_00081c74;
                  }
                }
                else if (iVar4 == pvPortMalloc_ret[1]) {
                  uVar3 = virtqueue_fill_used_buffers(iVar4,uVar3,0x200);
                  goto LAB_00081d56;
                }
              }
              piVar5 = piVar5 + 1;
              if (iVar2 != 0) {
                platform_init_interrupt(*(undefined2 *)(*pvPortMalloc_ret + 0x50));
                platform_init_interrupt(*(undefined2 *)(pvPortMalloc_ret[1] + 0x50));
                platform_interrupt_disable();
                platform_interrupt_disable();
                pvPortMalloc_ret[4] = iVar2;
                platform_interrupt_enable();
                platform_interrupt_enable();
                virtqueue_kick(*pvPortMalloc_ret);
                return pvPortMalloc_ret;
              }
              iVar2 = 1;
            } while( true );
          }
          break;
        }
        iVar4 = 1;
        piVar6 = piVar6 + 1;
      }
    }
LAB_00081c74:
    env_free_memory((int)pvPortMalloc_ret);
  }
  return (int *)0x0;
}


// ===== virtqueue_create @ 00081dec (142 bytes)

uint virtqueue_create(ushort param_1,uint param_2,int *param_3,uint param_4,uint param_5,
                     int *param_6)

{
  ushort uVar1;
  uint *pvPortMalloc_ret;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint local_24;
  
  local_24 = 0;
  pvPortMalloc_ret = (uint *)pvPortMalloc(0x68);
  if (pvPortMalloc_ret == (uint *)0x0) {
    local_24 = 0xfffff444;
  }
  else {
    memset(pvPortMalloc_ret,0,0x68);
    strncpy(pvPortMalloc_ret,(uint *)param_2,0x20);
    uVar1 = *(ushort *)(param_3 + 2);
    uVar2 = (uint)uVar1;
    uVar3 = param_3[1];
    pvPortMalloc_ret[0xd] = param_5;
    uVar4 = *param_3;
    *(ushort *)(pvPortMalloc_ret + 0x14) = param_1;
    pvPortMalloc_ret[0x10] = uVar2;
    pvPortMalloc_ret[0x11] = uVar4;
    pvPortMalloc_ret[0xb] = uVar4;
    uVar4 = uVar4 + uVar2 * 0x10;
    pvPortMalloc_ret[0xc] = param_4;
    pvPortMalloc_ret[0x12] = uVar4;
    pvPortMalloc_ret[9] = uVar3;
    pvPortMalloc_ret[0x13] = uVar4 + (uVar2 + 4) * 2 + -4 + (uVar3 - 1) & -uVar3;
    *(ushort *)((int)pvPortMalloc_ret + 0x52) = uVar1;
    pvPortMalloc_ret[10] = ((uVar3 - 1) + uVar2 * 0x10 + (uVar2 + 4) * 2 & -uVar3) + uVar2 * 8 + 0xe
    ;
    *param_6 = (int)pvPortMalloc_ret;
  }
  return local_24;
}


// ===== prvInsertBlockIntoFreeList @ 00081e80 (62 bytes)

void prvInsertBlockIntoFreeList(void *param_1)

{
  int *piVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_000887b8;
  do {
    puVar2 = puVar3;
    puVar3 = (undefined4 *)*puVar2;
  } while (puVar3 < param_1);
  if (param_1 == (void *)((int)puVar2 + puVar2[1])) {
    puVar2[1] = *(int *)((int)param_1 + 4) + puVar2[1];
    param_1 = puVar2;
  }
  if ((puVar3 == (undefined4 *)((int)param_1 + *(int *)((int)param_1 + 4))) &&
     (puVar3 != DAT_000887a0)) {
    piVar1 = puVar3 + 1;
    puVar3 = (undefined4 *)*puVar3;
    *(int *)((int)param_1 + 4) = *piVar1 + *(int *)((int)param_1 + 4);
  }
  *(undefined4 **)param_1 = puVar3;
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
  undefined *puVar5;
  uint uVar6;
  int *piVar7;
  undefined *puVar8;
  int *piVar9;
  int iVar10;
  
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
    uVar6 = 0;
    if (param_1 == 0) goto LAB_00081f9a;
    puVar8 = (undefined *)(param_1 + 8);
    if ((param_1 & 7) != 0) {
      puVar8 = (undefined *)(((uint)puVar8 & 0xfffffff8) + 8);
    }
    if ((puVar8 != (undefined *)0x0) && (puVar8 <= DAT_000887a8)) {
      piVar3 = (int *)&DAT_000887b8;
      piVar4 = DAT_000887b8;
      do {
        piVar9 = piVar4;
        piVar7 = piVar3;
        if (puVar8 <= (undefined *)piVar9[1]) break;
        piVar3 = piVar9;
        piVar4 = (int *)*piVar9;
      } while ((int *)*piVar9 != (int *)0x0);
      if (DAT_000887a0 != piVar9) {
        uVar6 = piVar9[1] - (int)puVar8;
        iVar10 = *piVar7;
        *piVar7 = *piVar9;
        if (0x10 < uVar6) {
          puVar5 = (undefined *)((int)piVar9 + (int)puVar8);
          if (((uint)puVar5 & 7) != 0) {
            ulSetInterruptMask();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
          *(uint *)(puVar5 + 4) = uVar6;
          piVar9[1] = (int)puVar8;
          prvInsertBlockIntoFreeList(puVar5);
        }
        puVar8 = DAT_000887ac;
        DAT_000887a8 = puVar2 + -piVar9[1];
        *piVar9 = 0;
        DAT_000887b0 = DAT_000887b0 + 1;
        if (DAT_000887a8 < puVar8) {
          DAT_000887ac = DAT_000887a8;
        }
        uVar6 = iVar10 + 8;
        piVar9[1] = uVar1 | piVar9[1];
        goto LAB_00081f9a;
      }
    }
  }
  uVar6 = 0;
LAB_00081f9a:
  xTaskResumeAll();
  if ((uVar6 & 7) != 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar6;
}


// ===== vPortFree @ 00081fd4 (86 bytes)

void vPortFree(int param_1)

{
  if (param_1 == 0) {
    return;
  }
  if ((*(uint *)(param_1 + -4) & DAT_000887a4) == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (*(int *)(param_1 + -8) != 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(uint *)(param_1 + -4) = *(uint *)(param_1 + -4) & ~DAT_000887a4;
  vTaskSuspendAll();
  DAT_000887a8 = *(int *)(param_1 + -4) + DAT_000887a8;
  prvInsertBlockIntoFreeList((void *)(param_1 + -8));
  DAT_000887b4 = DAT_000887b4 + 1;
  xTaskResumeAll();
  return;
}


// ===== prvTaskExitError @ 00082038 (36 bytes)

/* WARNING: Removing unreachable block (ram,0x00082056) */

void prvTaskExitError(void)

{
  if (DAT_00087ebc == -1) {
    ulSetInterruptMask();
    do {
    } while( true );
  }
  ulSetInterruptMask();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== vPortSetupTimerInterrupt @ 00082060 (32 bytes)

void vPortSetupTimerInterrupt(void)

{
  SysTick_CTRL = 0;
  SysTick_VAL = 0;
  SysTick_LOAD = DAT_00087ec0 / 1000 - 1;
  SysTick_CTRL = 7;
  return;
}


// ===== vPortEnterCritical @ 00082084 (24 bytes)

void vPortEnterCritical(void)

{
  ulSetInterruptMask();
  DAT_00087ebc = DAT_00087ebc + 1;
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== vPortExitCritical @ 000820a0 (34 bytes)

void vPortExitCritical(void)

{
  if (DAT_00087ebc == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  DAT_00087ebc = DAT_00087ebc + -1;
  if (DAT_00087ebc == 0) {
    vClearInterruptMask(0);
    return;
  }
  return;
}


// ===== pxPortInitialiseStack @ 000820c8 (106 bytes)

void * pxPortInitialiseStack(int param_1,uint param_2,uint param_3,uint param_4)

{
  *(uint *)(param_1 + -8) = param_3;
  *(undefined4 *)(param_1 + -4) = 0x1000000;
  *(undefined4 *)(param_1 + -0xc) = 0x82039;
  *(undefined4 *)(param_1 + -0x14) = 0x3030303;
  *(undefined4 *)(param_1 + -0x10) = 0x12121212;
  *(uint *)(param_1 + -0x20) = param_4;
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
  *(uint *)(param_1 + -0x48) = param_2;
  return (uint *)(param_1 + -0x48);
}


// ===== xEventGroupSetBitsFromISR @ 00082174 (46 bytes)

uint xEventGroupSetBitsFromISR(uint param_1,uint param_2,uint param_3)

{
  uint xQueueGenericSendFromISR_ret;
  undefined4 local_18;
  undefined1 *puStack_14;
  uint local_10;
  uint uStack_c;
  
  local_18 = 0xfffffffe;
  puStack_14 = &LAB_00086712_1;
  local_10 = param_1;
  uStack_c = param_2;
  xQueueGenericSendFromISR_ret =
       xQueueGenericSendFromISR(DAT_00088920,(int)&local_18,(void *)param_3,0);
  return xQueueGenericSendFromISR_ret;
}


// ===== vQueueAddToRegistry @ 00082184 (32 bytes)

void vQueueAddToRegistry(uint param_1,uint param_2)

{
  int i;
  
  i = 0;
  do {
    if ((&DAT_000887c0)[i * 2] == 0) {
      (&DAT_000887c0)[i * 2] = param_2;
      (&DAT_000887c4)[i * 2] = param_1;
      return;
    }
    i = i + 1;
  } while (i != 8);
  return;
}


// ===== vQueueUnregisterQueue @ 000821a8 (34 bytes)

void vQueueUnregisterQueue(int param_1)

{
  int i;
  
  i = 0;
  do {
    if ((&DAT_000887c4)[i * 2] == param_1) {
      (&DAT_000887c0)[i * 2] = 0;
      (&DAT_000887c4)[i * 2] = 0;
      return;
    }
    i = i + 1;
  } while (i != 8);
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
    vListInsertEnd((int *)&DAT_000888d0,DAT_00088800 + 4);
    return;
  }
  uVar2 = uVar1 + param_1;
  *(uint *)(DAT_00088800 + 4) = uVar2;
  if (CARRY4(uVar1,param_1)) {
    vListInsert(DAT_00088808,(uint *)(DAT_00088800 + 4));
    return;
  }
  vListInsert(DAT_00088804,(uint *)(DAT_00088800 + 4));
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

uint xTaskCreate(uint param_1,int param_2,int param_3,uint param_4,uint param_5,int *param_6)

{
  char cVar1;
  uint uVar2;
  undefined4 *pvPortMalloc_ret;
  void *pxPortInitialiseStack_ret;
  char *pcVar3;
  char *pcVar4;
  int i;
  uint uVar5;
  undefined4 *puVar6;
  
  uVar5 = param_3 * 4;
  uVar2 = pvPortMalloc(uVar5);
  if (uVar2 != 0) {
    pvPortMalloc_ret = (undefined4 *)pvPortMalloc(0x70);
    if (pvPortMalloc_ret != (undefined4 *)0x0) {
      pvPortMalloc_ret[0xc] = uVar2;
      memset(uVar2,0xa5,uVar5);
      uVar2 = (uVar5 - 4) + pvPortMalloc_ret[0xc] & 0xfffffff8;
      pvPortMalloc_ret[0x10] = uVar2;
      if (param_2 == 0) {
        *(undefined1 *)(pvPortMalloc_ret + 0xd) = 0;
      }
      else {
        pcVar4 = (char *)(param_2 + -1);
        pcVar3 = (char *)(pvPortMalloc_ret + 0xd);
        do {
          pcVar4 = pcVar4 + 1;
          cVar1 = *pcVar4;
          *pcVar3 = cVar1;
          if (cVar1 == '\0') break;
          pcVar3 = pcVar3 + 1;
        } while (pcVar4 != (char *)(param_2 + 9));
        *(undefined1 *)((int)pvPortMalloc_ret + 0x3d) = 0;
      }
      if (3 < param_5) {
        param_5 = 4;
      }
      pvPortMalloc_ret[0xb] = param_5;
      pvPortMalloc_ret[0x13] = param_5;
      pvPortMalloc_ret[0x14] = 0;
      vListInitialiseItem((int)(pvPortMalloc_ret + 1));
      vListInitialiseItem((int)(pvPortMalloc_ret + 6));
      pvPortMalloc_ret[0x1a] = 0;
      pvPortMalloc_ret[0x15] = 0;
      pvPortMalloc_ret[0x16] = 0;
      pvPortMalloc_ret[0x17] = 0;
      pvPortMalloc_ret[0x18] = 0;
      pvPortMalloc_ret[4] = pvPortMalloc_ret;
      pvPortMalloc_ret[6] = 5 - param_5;
      pvPortMalloc_ret[9] = pvPortMalloc_ret;
      pvPortMalloc_ret[0x19] = 0;
      *(undefined1 *)(pvPortMalloc_ret + 0x1b) = 0;
      pxPortInitialiseStack_ret = pxPortInitialiseStack(uVar2,pvPortMalloc_ret[0xc],param_1,param_4)
      ;
      *pvPortMalloc_ret = pxPortInitialiseStack_ret;
      if (param_6 != (int *)0x0) {
        *param_6 = (int)pvPortMalloc_ret;
      }
      vPortEnterCritical();
      DAT_00088870 = DAT_00088870 + 1;
      if (DAT_00088800 == (undefined4 *)0x0) {
        DAT_00088800 = pvPortMalloc_ret;
        if (DAT_00088870 == 1) {
          puVar6 = &DAT_0008880c;
          i = 0;
          do {
            i = i + 1;
            vListInitialise(puVar6);
            puVar6 = puVar6 + 5;
          } while (i != 5);
          vListInitialise(&DAT_00088880);
          vListInitialise(&DAT_00088894);
          vListInitialise(&DAT_000888b8);
          vListInitialise(&DAT_000888d0);
          DAT_00088804 = &DAT_00088880;
          DAT_00088808 = &DAT_00088894;
        }
      }
      else if ((DAT_000888cc == 0) && ((uint)DAT_00088800[0xb] <= (uint)pvPortMalloc_ret[0xb])) {
        DAT_00088800 = pvPortMalloc_ret;
      }
      DAT_00088878 = DAT_00088878 + 1;
      pvPortMalloc_ret[0x11] = DAT_00088878;
      uVar2 = pvPortMalloc_ret[0xb];
      if (DAT_0008887c < uVar2) {
        DAT_0008887c = uVar2;
      }
      vListInsertEnd(&DAT_0008880c + uVar2 * 5,(int)(pvPortMalloc_ret + 1));
      vPortExitCritical();
      if ((DAT_000888cc != 0) && ((uint)DAT_00088800[0xb] < (uint)pvPortMalloc_ret[0xb])) {
        vPortYield();
      }
      return 1;
    }
    vPortFree(uVar2);
  }
  return 0xffffffff;
}


// ===== vTaskStartScheduler @ 00082418 (138 bytes)

uint vTaskStartScheduler(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = xTaskCreate(0x821d1,0x8001834,0x80,0,0,(int *)&DAT_000888a8);
  if ((uVar2 == 1) && (uVar2 = xTimerCreateTimerTask(), uVar2 == 1)) {
    ulSetInterruptMask();
    DAT_000888ac = 0xffffffff;
    DAT_000888e4 = 0;
    uVar1 = SCB_SHPR3;
    SCB_SHPR3 = uVar1 | 0xff0000;
    uVar1 = SCB_SHPR3;
    SCB_SHPR3 = uVar1 | 0xff000000;
    DAT_000888cc = uVar2;
    vPortSetupTimerInterrupt();
    DAT_00087ebc = 0;
    vStartFirstTask();
    vTaskSwitchContext();
    prvTaskExitError();
    return 0;
  }
  if (uVar2 == 0xffffffff) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return uVar2;
}


// ===== vTaskSuspendAll @ 00082484 (10 bytes)

void vTaskSuspendAll(void)

{
  DAT_00088874 = DAT_00088874 + 1;
  return;
}


// ===== xTaskGetTickCount @ 00082494 (6 bytes)

/* xTickCount 0x888E4 [inference] */

uint xTaskGetTickCount(void)

{
  return DAT_000888e4;
}


// ===== xTaskIncrementTick @ 000824a0 (202 bytes)

/* [inference] */

uint xTaskIncrementTick(void)

{
  int *piVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  piVar1 = DAT_00088804;
  if (DAT_00088874 == 0) {
    uVar5 = DAT_000888e4 + 1;
    DAT_000888e4 = uVar5;
    if (uVar5 == 0) {
      if (*DAT_00088804 != 0) {
        ulSetInterruptMask();
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

uint xTaskResumeAll(void)

{
  uint uVar1;
  int iVar2;
  
  if (DAT_00088874 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortEnterCritical();
  DAT_00088874 = DAT_00088874 + -1;
  if ((DAT_00088874 == 0) && (DAT_00088870 != 0)) {
    iVar2 = 0;
    while (DAT_000888b8 != 0) {
      iVar2 = *(int *)(DAT_000888c4 + 0xc);
      uxListRemove(iVar2 + 0x18);
      uxListRemove(iVar2 + 4);
      uVar1 = *(uint *)(iVar2 + 0x2c);
      if (DAT_0008887c < uVar1) {
        DAT_0008887c = uVar1;
      }
      vListInsertEnd(&DAT_0008880c + uVar1 * 5,iVar2 + 4);
      if (*(uint *)(DAT_00088800 + 0x2c) <= *(uint *)(iVar2 + 0x2c)) {
        DAT_000888e8 = 1;
      }
    }
    if (iVar2 != 0) {
      prvResetNextTaskUnblockTime();
    }
    iVar2 = DAT_000888b4;
    if (DAT_000888b4 != 0) {
      do {
        uVar1 = xTaskIncrementTick();
        if (uVar1 != 0) {
          DAT_000888e8 = 1;
        }
        iVar2 = iVar2 + -1;
      } while (iVar2 != 0);
      DAT_000888b4 = 0;
    }
    if (DAT_000888e8 != 0) {
      vPortYield();
      uVar1 = 1;
      goto LAB_000825b6;
    }
  }
  uVar1 = 0;
LAB_000825b6:
  vPortExitCritical();
  return uVar1;
}


// ===== vTaskDelay @ 00082664 (42 bytes)

void vTaskDelay(int param_1)

{
  uint xTaskResumeAll_ret;
  undefined8 uVar1;
  
  if (param_1 != 0) {
    if (DAT_00088874 != 0) {
      ulSetInterruptMask();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    uVar1 = vTaskSuspendAll();
    prvAddCurrentTaskToDelayedList((uint)uVar1,(int)((ulonglong)uVar1 >> 0x20));
    xTaskResumeAll_ret = xTaskResumeAll();
    if (xTaskResumeAll_ret != 0) {
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
    for (iVar1 = DAT_0008887c; iVar2 = iVar1 * 0x14, (&DAT_0008880c)[iVar1 * 5] == 0;
        iVar1 = iVar1 + -1) {
      if (iVar1 == 0) {
        ulSetInterruptMask();
        do {
                    /* WARNING: Do nothing block with infinite loop */
        } while( true );
      }
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

void vTaskPlaceOnEventList(int param_1,uint param_2)

{
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vListInsert((int *)param_1,(uint *)(DAT_00088800 + 0x18));
  prvAddCurrentTaskToDelayedList(param_2,1);
  return;
}


// ===== vTaskPlaceOnUnorderedEventList @ 00082728 (54 bytes)

/* [inference] */

void vTaskPlaceOnUnorderedEventList(int param_1,uint param_2,uint param_3)

{
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_00088874 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(uint *)(DAT_00088800 + 0x18) = param_2 | 0x80000000;
  vListInsertEnd((int *)param_1,DAT_00088800 + 0x18);
  prvAddCurrentTaskToDelayedList(param_3,1);
  return;
}


// ===== vTaskPlaceOnEventListRestricted @ 00082768 (46 bytes)

/* [inference] */

void vTaskPlaceOnEventListRestricted(int param_1,uint param_2,int param_3)

{
  if (param_1 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vListInsertEnd((int *)param_1,DAT_00088800 + 0x18);
  if (param_3 != 0) {
    param_2 = 0xffffffff;
  }
  prvAddCurrentTaskToDelayedList(param_2,param_3);
  return;
}


// ===== xTaskRemoveFromEventList @ 0008279c (100 bytes)

/* [inference] */

uint xTaskRemoveFromEventList(int param_1)

{
  bool bVar1;
  int *piVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = *(int *)(*(int *)(param_1 + 0xc) + 0xc);
  if (iVar5 == 0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar3 = iVar5 + 0x18;
  uxListRemove(iVar3);
  if (DAT_00088874 == 0) {
    iVar3 = iVar5 + 4;
    uxListRemove(iVar3);
    uVar4 = *(uint *)(iVar5 + 0x2c);
    if (DAT_0008887c < uVar4) {
      DAT_0008887c = uVar4;
    }
    piVar2 = &DAT_0008880c + uVar4 * 5;
  }
  else {
    piVar2 = &DAT_000888b8;
  }
  vListInsertEnd(piVar2,iVar3);
  bVar1 = *(uint *)(DAT_00088800 + 0x2c) < *(uint *)(iVar5 + 0x2c);
  if (bVar1) {
    DAT_000888e8 = 1;
  }
  return (uint)bVar1;
}


// ===== vTaskRemoveFromUnorderedEventList @ 00082818 (94 bytes)

/* [inference] */

void vTaskRemoveFromUnorderedEventList(uint *param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (DAT_00088874 == 0) {
    ulSetInterruptMask();
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
  ulSetInterruptMask();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== vTaskInternalSetTimeOutState @ 0008288c (14 bytes)

/* [inference] */

void vTaskInternalSetTimeOutState(void *param_1)

{
  *(undefined4 *)param_1 = DAT_000888b0;
  *(undefined4 *)((int)param_1 + 4) = DAT_000888e4;
  return;
}


// ===== xTaskCheckForTimeOut @ 000828a4 (88 bytes)

/* [inference] */

uint xTaskCheckForTimeOut(int *param_1,uint *param_2)

{
  uint uVar1;
  uint uVar2;
  
  if (param_1 == (int *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (param_2 == (uint *)0x0) {
    ulSetInterruptMask();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  vPortEnterCritical();
  uVar2 = *param_2;
  if (uVar2 == 0xffffffff) {
LAB_000828ea:
    uVar2 = 0;
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
    uVar2 = 1;
  }
  vPortExitCritical();
  return uVar2;
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

uint xTaskGetSchedulerState(void)

{
  uint uVar1;
  
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
  
  bVar3 = false;
  if (param_1 != 0) {
    if (*(uint *)(param_1 + 0x2c) < *(uint *)(DAT_00088800 + 0x2c)) {
      if (-1 < *(int *)(param_1 + 0x18)) {
        *(int *)(param_1 + 0x18) = 5 - *(int *)(DAT_00088800 + 0x2c);
      }
      if (*(undefined4 **)(param_1 + 0x14) == &DAT_0008880c + *(uint *)(param_1 + 0x2c) * 5) {
        uxListRemove(param_1 + 4);
        uVar1 = DAT_0008887c;
        uVar2 = *(uint *)(DAT_00088800 + 0x2c);
        *(uint *)(param_1 + 0x2c) = uVar2;
        if (uVar1 < uVar2) {
          DAT_0008887c = uVar2;
        }
        vListInsertEnd(&DAT_0008880c + uVar2 * 5,param_1 + 4);
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

uint xTaskPriorityDisinherit(int param_1)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  
  iVar3 = DAT_00088800;
  if (param_1 != 0) {
    if (DAT_00088800 != param_1) {
      ulSetInterruptMask();
      do {
                    /* WARNING: Do nothing block with infinite loop */
      } while( true );
    }
    if (*(int *)(DAT_00088800 + 0x50) == 0) {
      ulSetInterruptMask();
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
      ulSetInterruptMask();
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
        ulSetInterruptMask();
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

uint uxTaskResetEventItemValue(void)

{
  uint uVar1;
  
  uVar1 = *(uint *)(DAT_00088800 + 0x18);
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

int ulTaskNotifyTake(int param_1,uint param_2)

{
  int iVar1;
  int iVar2;
  
  vPortEnterCritical();
  if ((*(int *)(DAT_00088800 + 0x68) == 0) &&
     (*(undefined1 *)(DAT_00088800 + 0x6c) = 1, param_2 != 0)) {
    prvAddCurrentTaskToDelayedList(param_2,1);
    vPortYield();
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

