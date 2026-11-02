// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== itron_sta_cyc @ 20151680 (204 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): cyc table 0x208DBF64:
   (re)inserts the handler into timer queue 0x208003C4, sets TCYC_STA [inference] */

code * itron_sta_cyc(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 < 9)) {
    software_interrupt(0);
    iVar2 = *(int *)(&DAT_208dbf64 + param_1 * 4);
    if (iVar2 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    uVar1 = *(uint *)(iVar2 + 0xc);
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 1) != 0) {
        FUN_201535b4(&DAT_208dbf64,iVar2,param_1);
        *(undefined1 *)(iVar2 + 8) = 0;
        *(undefined1 *)(iVar2 + 9) = 0;
      }
      FUN_201543e4(iVar2 + 0x10,0x208003c4,iVar2);
      FUN_20153720(&DAT_208dbf64,iVar2,param_1);
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 1;
    }
    else {
      *(uint *)(iVar2 + 0xc) = uVar1 | 1;
    }
    software_interrupt(0);
    return knl_svc_return;
  }
  knl_sys.last_ercd = -0x12;
  return (code *)0xffffffee;
}


// ===== itron_sta_tsk @ 20151768 (244 bytes)

uint itron_sta_tsk(uint param_1,uint param_2)

{
  byte *pbVar1;
  uint uVar2;
  knl_tcb *p_knl_tcb;
  uint uVar3;
  
  if (param_1 == 0) {
    knl_sys.last_ercd = 0xffffffd7;
  }
  else {
    if (param_1 <= DAT_201659d0) {
      software_interrupt(0);
      p_knl_tcb = knl_tsk_tab[param_1];
      if (p_knl_tcb == (knl_tcb *)0x0) {
        software_interrupt(0);
        return 0xffffffd6;
      }
      if (p_knl_tcb->state == 0) {
        uVar3 = p_knl_tcb->ctsk->task;
        pbVar1 = p_knl_tcb->stk + p_knl_tcb->ctsk->stksz;
        *(byte **)(pbVar1 + -0x18) = pbVar1;
        *(uint *)(pbVar1 + -0x48) = param_2;
        uVar2 = knl_sys.task_cpsr;
        if ((uVar3 & 1) != 0) {
          uVar2 = knl_sys.task_cpsr | 0x20;
        }
        *(uint *)(pbVar1 + -0xc) = uVar2;
        uVar2 = FUN_201568b8();
        *(uint *)(pbVar1 + -0xc) = uVar2 | *(uint *)(pbVar1 + -0xc);
        *(code **)(pbVar1 + -0x14) = itron_ext_tsk;
        *(uint *)(pbVar1 + -4) = uVar3;
        p_knl_tcb->sp = (uint)(pbVar1 + -0x48);
        p_knl_tcb->f_0x08_u8 = 0;
        p_knl_tcb->f_0x09_u8 = 0;
        p_knl_tcb->f_0x20_u32 = 0;
        p_knl_tcb->state = 0x10;
        uVar2 = FUN_20154538(p_knl_tcb,param_1);
        return uVar2;
      }
      software_interrupt(0);
      return 0xffffffd7;
    }
    knl_sys.last_ercd = 0xffffffee;
  }
  return knl_sys.last_ercd;
}


// ===== itron_stp_cyc @ 20151878 (164 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): cyc table 0x208DBF64:
   removes it from the timer queue, clears TCYC_STA [inference] */

code * itron_stp_cyc(uint param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_1 < 9)) {
    software_interrupt(0);
    iVar1 = *(int *)(&DAT_208dbf64 + param_1 * 4);
    if (iVar1 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    if ((*(uint *)(iVar1 + 0xc) & 1) != 0) {
      if ((*(uint *)(iVar1 + 0xc) & 4) == 0) {
        FUN_201535b4(&DAT_208dbf64,iVar1,param_1);
        *(undefined1 *)(iVar1 + 8) = 0;
        *(undefined1 *)(iVar1 + 9) = 0;
      }
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe;
    }
    software_interrupt(0);
    return knl_svc_return;
  }
  knl_sys.last_ercd = -0x11;
  return (code *)0xffffffef;
}


// ===== itron_sus_tsk @ 20151934 (328 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): id 0 = self, E_OBJ
   dormant, suspend count TCB+9 ++ (E_QOVR at 255), E_CTX for self with dispatch disabled
   [inference] */

code * itron_sus_tsk(uint param_1)

{
  knl_tcb *p_knl_tcb;
  code *pcVar1;
  byte bVar2;
  
  if ((((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
      (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) || (param_1 != 0)) {
    if (param_1 <= DAT_201659d0) {
      if (param_1 == 0) {
        param_1 = (uint)knl_rdq[0];
      }
      software_interrupt(0);
      p_knl_tcb = knl_tsk_tab[param_1];
      if (p_knl_tcb == (knl_tcb *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (p_knl_tcb->state == 0) {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      bVar2 = p_knl_tcb->f_0x09_u8 + 1;
      p_knl_tcb->f_0x09_u8 = bVar2;
      if (bVar2 == 0) {
        p_knl_tcb->f_0x09_u8 = 0xff;
        software_interrupt(0);
        return (code *)0xffffffd5;
      }
      if (bVar2 != 1 || p_knl_tcb->state != 0x10) {
        software_interrupt(0);
        return knl_svc_return;
      }
      if ((uint)knl_rdq[0] == (param_1 & 0xff)) {
        if (knl_sys.ctx_isr == 0) {
                    /* removes the running task from its ready queue [doc] */
          pcVar1 = (code *)knl_wait_self(p_knl_tcb,param_1);
          return pcVar1;
        }
        knl_sys.dsp_pending = 1;
      }
      pcVar1 = (code *)knl_release_suspended(p_knl_tcb,param_1);
      return pcVar1;
    }
    knl_sys.last_ercd = -0x12;
  }
  else {
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_tget_mpf @ 20151aa4 (356 bytes)

/* (mpfid 1..0x10, *p_blk, tmout): takes a block from the free list of pool table 0x208DBF24 or
   waits; E_TMOUT for tmout 0 [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO)
   (uitron_api_shape 0.950): (mpfid, p_blk, tmout): mpf table 0x208DBF24, pops the free list,
   E_TMOUT polling, waits otherwise [inference] */

code * itron_tget_mpf(uint param_1,undefined4 *param_2,int tmout)

{
  byte bVar1;
  byte *pbVar2;
  code *pcVar3;
  knl_mpf *p_knl_mpf;
  knl_tcb *tcb;
  uint uVar4;
  
  if ((param_1 == 0) || (0x10 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    software_interrupt(0);
    p_knl_mpf = knl_mpf_tab[param_1];
    if (p_knl_mpf == (knl_mpf *)0x0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    pbVar2 = p_knl_mpf->free_head;
    if (pbVar2 != (byte *)0x0) {
      *param_2 = pbVar2;
      p_knl_mpf->free_head = *(byte **)pbVar2;
      p_knl_mpf->fblkcnt = p_knl_mpf->fblkcnt - 1;
      software_interrupt(0);
      return knl_svc_return;
    }
    if (tmout == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar4 = (uint)knl_rdq[0];
      if (uVar4 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        tcb = knl_tsk_tab[uVar4];
        if (tmout == -1) {
          bVar1 = 0xd0;
        }
        else {
          knl_timeout_add(tmout,tcb,knl_rdq[0]);
          bVar1 = 0xd2;
        }
        tcb->state = bVar1;
        pbVar2 = p_knl_mpf->wq;
        if (p_knl_mpf->wq[1] < 0xfe) {
          pbVar2 = pbVar2 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_arg2 = (uint)param_2;
        knl_sys.wait_id = param_1;
                    /* Moves the running task into an object's wait queue [doc] */
        pcVar3 = (code *)knl_wait_enter(pbVar2,tcb,uVar4);
        return pcVar3;
      }
    }
    software_interrupt(0);
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_tloc_mtx @ 20151c3c (504 bytes)

/* (mtxid 1..0x20, tmout): table 0x208DBFC4, E_ILUSE, E_TMOUT [fact]; the RTC I2C lock (rtc_read_* /
   rtc_write_*) [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900):
   (mtxid, tmout): mtx table 0x208DBFC4 (32), owner +10, ceiling/inherit, E_ILUSE, E_TMOUT
   [inference] */

code * itron_tloc_mtx(uint param_1,int tmout)

{
  short sVar1;
  sbyte sVar2;
  byte bVar3;
  byte *queue;
  code *pcVar4;
  knl_mtx *p_knl_mtx;
  knl_tcb *tcb;
  int iVar5;
  int iVar6;
  uint tskid;
  
  if ((param_1 == 0) || (0x20 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
       (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      p_knl_mtx = knl_mtx_tab[param_1];
      if (p_knl_mtx == (knl_mtx *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      tskid = (uint)knl_rdq[0];
      if (p_knl_mtx->owner == tskid) {
        software_interrupt(0);
      }
      else {
        iVar6 = p_knl_mtx->mtxatr;
        sVar2 = p_knl_mtx->pri;
        iVar5 = (int)sVar2;
        tcb = knl_tsk_tab[tskid];
        if ((iVar6 != 3) || (iVar5 <= tcb->bpri)) {
          if (p_knl_mtx->owner != 0) {
            if (tmout == 0) {
              software_interrupt(0);
              return (code *)0xffffffce;
            }
            if (tmout == -1) {
              bVar3 = 0x94;
            }
            else {
              knl_timeout_add(tmout,tcb,knl_rdq[0]);
              bVar3 = 0x96;
            }
            tcb->state = bVar3;
            queue = p_knl_mtx->wq;
            if (p_knl_mtx->wq[1] < 0xfe) {
              queue = queue + knl_sys.run_pri + -1;
            }
            knl_sys.wait_id = param_1;
            knl_queue_move(queue,tcb,tskid);
            if ((iVar6 == 2) && (knl_sys.run_pri < iVar5)) {
              p_knl_mtx->pri = knl_sys.run_pri;
              FUN_20153f28(p_knl_mtx->owner);
            }
            software_interrupt(0);
            return knl_resched;
          }
          p_knl_mtx->owner = knl_rdq[0];
          sVar1 = tcb->mtx_held;
          tcb->mtx_held = (short)param_1;
          p_knl_mtx->prev_held = sVar1;
          if (iVar6 == 2) {
            p_knl_mtx->pri = tcb->pri;
          }
          else if ((iVar6 == 3) && (iVar5 < tcb->pri)) {
            tcb->pri = sVar2;
                    /* Moves the running task into an object's wait queue [doc] */
            pcVar4 = (code *)knl_wait_enter(knl_rdq + iVar5,tcb,tskid);
            return pcVar4;
          }
          software_interrupt(0);
          return knl_svc_return;
        }
        software_interrupt(0);
      }
      return (code *)0xffffffe4;
    }
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_trcv_dtq @ 20151e68 (536 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (dtqid, p_data, tmout):
   dtq table 0x208DBFA4, takes from the ring buffer or a sender, E_TMOUT [inference] */

code * itron_trcv_dtq(uint param_1,undefined4 *param_2,int tmout)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  knl_tcb *p_knl_tcb;
  
  if ((param_1 == 0) || (8 < param_1)) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar5 = *(int *)(&DAT_208dbfa4 + param_1 * 4);
  if (iVar5 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (*(short *)(iVar5 + 0x16) == 0) {
    pbVar3 = (byte *)(iVar5 + 0x1a);
    do {
      uVar6 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (uVar6 == 0);
    if (0xfd < uVar6) {
      if (tmout == 0) {
        software_interrupt(0);
        return (code *)0xffffffce;
      }
      if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
         (uVar6 = (uint)knl_rdq[0], uVar6 != ((byte)DAT_201659d0 + 1 & 0xff))) {
        p_knl_tcb = knl_tsk_tab[uVar6];
        if (tmout == -1) {
          bVar1 = 0xb4;
        }
        else {
          knl_timeout_add(tmout,p_knl_tcb,knl_rdq[0]);
          bVar1 = 0xb6;
        }
        p_knl_tcb->state = bVar1;
        knl_sys.wait_arg2 = (uint)param_2;
        knl_sys.wait_id = param_1;
                    /* Moves the running task into an object's wait queue [doc] */
        pcVar4 = (code *)knl_wait_enter(iVar5 + 0x18,p_knl_tcb,uVar6);
        return pcVar4;
      }
      software_interrupt(0);
      knl_sys.last_ercd = -0x19;
      return (code *)0xffffffe7;
    }
    p_knl_tcb = knl_tsk_tab[uVar6];
    *param_2 = *(undefined4 *)(p_knl_tcb->sp + 0xc);
  }
  else {
    puVar2 = *(undefined4 **)(iVar5 + 0xc) + 1;
    *param_2 = **(undefined4 **)(iVar5 + 0xc);
    *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + -1;
    if (*(undefined4 **)(iVar5 + 0x10) <= puVar2) {
      puVar2 = *(undefined4 **)(iVar5 + 4);
    }
    *(undefined4 **)(iVar5 + 0xc) = puVar2;
    pbVar3 = (byte *)(iVar5 + 0x1a);
    do {
      uVar6 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (uVar6 == 0);
    if (0xfd < uVar6) {
      software_interrupt(0);
      return knl_svc_return;
    }
    p_knl_tcb = knl_tsk_tab[uVar6];
    puVar2 = *(undefined4 **)(iVar5 + 8) + 1;
    **(undefined4 **)(iVar5 + 8) = *(undefined4 *)(p_knl_tcb->sp + 0xc);
    *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + 1;
    if (*(undefined4 **)(iVar5 + 0x10) <= puVar2) {
      puVar2 = *(undefined4 **)(iVar5 + 4);
    }
    *(undefined4 **)(iVar5 + 8) = puVar2;
  }
  if ((p_knl_tcb->state & 2) != 0) {
                    /* unlinks the TCB from its timer-wheel slot [doc] */
    knl_timeout_remove(p_knl_tcb,uVar6);
  }
  p_knl_tcb->state = 0x10;
  if (p_knl_tcb->f_0x09_u8 != 0) {
    pcVar4 = (code *)knl_release_suspended();
    return pcVar4;
  }
                    /* Appends the TCB to ready queue 0x208DC18C + priority [doc] */
  pcVar4 = (code *)knl_make_ready(p_knl_tcb,uVar6);
  return pcVar4;
}


// ===== knl_mbf_get @ 201520b0 (248 bytes)

/* (mbf, buf): copies the next message out of the message-buffer ring (16-bit length prefix, wrap at
   the ring size) and returns its size; itron_trcv_mbf calls it (boot-rtos.md) [fact] */

uint knl_mbf_get(int param_1,undefined1 *param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = (uint)*(ushort *)(param_1 + 10);
  iVar7 = *(int *)(param_1 + 4);
  if (*(short *)(param_1 + 0x10) == 1) {
    *param_2 = *(undefined1 *)(iVar7 + uVar3);
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
    uVar3 = uVar3 + 1;
    if (uVar3 == *(ushort *)(param_1 + 0xc)) {
      uVar3 = 0;
    }
    *(short *)(param_1 + 10) = (short)uVar3;
    return 1;
  }
  uVar4 = uVar3 + 1;
  uVar9 = (uint)*(ushort *)(param_1 + 0xc);
  if (uVar9 == uVar4) {
    uVar4 = 0;
  }
  uVar5 = uVar4 + 1;
  if (uVar9 == uVar5) {
    uVar5 = 0;
  }
  uVar1 = CONCAT11(*(undefined1 *)(iVar7 + uVar4),*(undefined1 *)(iVar7 + uVar3));
  uVar8 = (uint)uVar1;
  uVar3 = (uint)CONCAT11(*(undefined1 *)(iVar7 + uVar4),*(undefined1 *)(iVar7 + uVar3));
  *(ushort *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + uVar1 + 2;
  if (uVar9 <= uVar3 + uVar5) {
    iVar6 = uVar9 - uVar5;
    uVar8 = uVar3 - iVar6 & 0xffff;
    puVar2 = (undefined1 *)(iVar7 + uVar5);
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    uVar5 = 0;
  }
  *(short *)(param_1 + 10) = (short)uVar5 + (short)uVar8;
  puVar2 = (undefined1 *)(*(int *)(param_1 + 4) + uVar5);
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return uVar3;
}


// ===== itron_trcv_mbf @ 201521a8 (600 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): (mbfid, msg, tmout): mbf
   table 0x208DBEC4, copies a message out of the ring (0x201520B0), returns its size [inference] */

int itron_trcv_mbf(uint param_1,uint param_2,int tmout,undefined4 param_4)

{
  sbyte sVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  knl_tcb *p_knl_tcb;
  uint uVar6;
  
  if ((param_1 == 0) || (8 < param_1)) {
    knl_sys.last_ercd = -0x12;
    return -0x12;
  }
  software_interrupt(0);
  iVar5 = *(int *)(&DAT_208dbec4 + param_1 * 4);
  if (iVar5 == 0) {
    software_interrupt(0);
    return -0x2a;
  }
  if (*(short *)(iVar5 + 0xc) != *(short *)(iVar5 + 0xe)) {
                    /* copies the next message out of the message-buffer ring [doc] */
    iVar5 = knl_mbf_get(iVar5,param_2,tmout,param_4,param_1,param_2,tmout);
    iVar4 = FUN_20153dec(param_1);
    if (iVar4 == 0) {
      software_interrupt(0);
    }
    else {
      software_interrupt(0);
    }
    return iVar5;
  }
  pbVar3 = (byte *)(iVar5 + 0x13);
  do {
    uVar6 = (uint)*pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (uVar6 == 0);
  if (uVar6 < 0xfe) {
    p_knl_tcb = knl_tsk_tab[uVar6];
    iVar5 = *(int *)(p_knl_tcb->sp + 8);
    if (iVar5 != 0) {
      knl_memcpy(param_2,*(undefined4 *)(p_knl_tcb->sp + 0xc),iVar5);
    }
    if ((p_knl_tcb->state & 2) != 0) {
                    /* unlinks the TCB from its timer-wheel slot [doc] */
      knl_timeout_remove(p_knl_tcb,uVar6);
    }
    p_knl_tcb->state = 0x10;
    if (p_knl_tcb->f_0x09_u8 == 0) {
      sVar1 = p_knl_tcb->pri;
      knl_queue_move(knl_rdq + sVar1,p_knl_tcb,uVar6);
      if ((int)sVar1 < (int)knl_sys.run_pri) {
        software_interrupt(0);
        return iVar5;
      }
    }
    else {
      knl_queue_remove(p_knl_tcb,uVar6);
    }
    software_interrupt(0);
    return iVar5;
  }
  if (tmout == 0) {
    software_interrupt(0);
    return -0x32;
  }
  if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
     (uVar6 = (uint)knl_rdq[0], uVar6 != ((byte)DAT_201659d0 + 1 & 0xff))) {
    p_knl_tcb = knl_tsk_tab[uVar6];
    if (tmout == -1) {
      bVar2 = 0xb0;
    }
    else {
      knl_timeout_add(tmout,p_knl_tcb,knl_rdq[0]);
      bVar2 = 0xb2;
    }
    p_knl_tcb->state = bVar2;
    iVar5 = (uint)*(byte *)(iVar5 + 0x12) + iVar5;
    if (*(byte *)(iVar5 + 1) < 0xfe) {
      iVar5 = iVar5 + knl_sys.run_pri + -1;
    }
    knl_sys.wait_arg2 = param_2;
    knl_sys.wait_id = param_1;
                    /* Moves the running task into an object's wait queue [doc] */
    iVar5 = knl_wait_enter(iVar5,p_knl_tcb,uVar6);
    return iVar5;
  }
  software_interrupt(0);
  knl_sys.last_ercd = -0x19;
  return -0x19;
}


// ===== itron_trcv_mbx @ 20152434 (400 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (mbxid, ppk_msg, tmout):
   mbx table 0x208DBEA4, takes the first queued message, E_TMOUT [inference] */

code * itron_trcv_mbx(uint param_1,int *param_2,int tmout)

{
  byte bVar1;
  int *piVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  int *piVar6;
  knl_tcb *tcb;
  uint uVar7;
  
  if ((param_1 == 0) || (8 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    software_interrupt(0);
    piVar6 = *(int **)(&DAT_208dbea4 + param_1 * 4);
    if (piVar6 == (int *)0x0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    iVar5 = 0;
    if (*(byte *)((int)piVar6 + 6) == 0) {
      piVar2 = *(int **)(*piVar6 + 8);
    }
    else {
      piVar2 = (int *)((uint)*(byte *)((int)piVar6 + 6) + (int)piVar6);
    }
    if (*(byte *)(piVar6 + 1) != 0) {
      do {
        piVar4 = (int *)*piVar2;
        if (piVar4 != (int *)0x0) {
          *piVar2 = *piVar4;
          *param_2 = (int)piVar4;
          software_interrupt(0);
          return knl_svc_return;
        }
        iVar5 = iVar5 + 1;
        piVar2 = piVar2 + 2;
      } while (iVar5 < (int)(uint)*(byte *)(piVar6 + 1));
    }
    if (tmout == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar7 = (uint)knl_rdq[0];
      if (uVar7 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        tcb = knl_tsk_tab[uVar7];
        if (tmout == -1) {
          bVar1 = 0xa0;
        }
        else {
          knl_timeout_add(tmout,tcb,knl_rdq[0]);
          bVar1 = 0xa2;
        }
        tcb->state = bVar1;
        iVar5 = (int)piVar6 + 7;
        if (*(byte *)(piVar6 + 2) < 0xfe) {
          iVar5 = iVar5 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_arg2 = (uint)param_2;
        knl_sys.wait_id = param_1;
                    /* Moves the running task into an object's wait queue [doc] */
        pcVar3 = (code *)knl_wait_enter(iVar5,tcb,uVar7);
        return pcVar3;
      }
    }
    software_interrupt(0);
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_tslp_tsk @ 201525f8 (216 bytes)

/* (tmout): E_CTX in a non-task context; consumes a wake-up count or waits (TMO_FEVR -1 at 40 call
   sites, 10 ms at 12) [fact]; the wake-up wait of the periodic tasks (gui.md) [fact]; T23d NORTi
   uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (tmout): wakeup count TCB+8 -- or
   waits (state 0x20/0x22), E_TMOUT when polling, E_CTX [inference] */

code * itron_tslp_tsk(int tmout)

{
  byte bVar1;
  code *pcVar2;
  knl_tcb *tcb;
  uint uVar3;
  
  if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
    uVar3 = (uint)knl_rdq[0];
    if (uVar3 != ((byte)DAT_201659d0 + 1 & 0xff)) {
      tcb = knl_tsk_tab[uVar3];
      software_interrupt(0);
      if (tcb->f_0x08_u8 != 0) {
        tcb->f_0x08_u8 = tcb->f_0x08_u8 - 1;
        software_interrupt(0);
        return knl_svc_return;
      }
      if (tmout == 0) {
        software_interrupt(0);
        return (code *)0xffffffce;
      }
      if (tmout == -1) {
        bVar1 = 0x20;
      }
      else {
        knl_timeout_add(tmout,tcb,knl_rdq[0]);
        bVar1 = 0x22;
      }
      tcb->state = bVar1;
                    /* removes the running task from its ready queue [doc] */
      pcVar2 = (code *)knl_wait_self(tcb,uVar3);
      return pcVar2;
    }
  }
  knl_sys.last_ercd = -0x19;
  return (code *)0xffffffe7;
}


// ===== itron_tsnd_mbf @ 201526f4 (604 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): (mbfid, msg, msgsz,
   tmout): mbf table 0x208DBEC4, E_PAR when msgsz > maxmsz, copies to a receiver or the ring
   [inference] */

code * itron_tsnd_mbf(uint param_1,uint param_2,uint param_3,int tmout)

{
  byte bVar1;
  code *pcVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  knl_tcb *p_knl_tcb;
  uint uVar6;
  
  if ((param_1 == 0) || (8 < param_1)) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar5 = *(int *)(&DAT_208dbec4 + param_1 * 4);
  if (iVar5 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (*(ushort *)(iVar5 + 0x10) < param_3) {
    software_interrupt(0);
    return (code *)0xffffffef;
  }
  pbVar3 = (byte *)((uint)*(byte *)(iVar5 + 0x12) + iVar5);
  do {
    uVar6 = (uint)*pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (uVar6 == 0);
  if (0xfd < uVar6) {
    if (param_3 != 0) {
      for (pbVar3 = (byte *)(iVar5 + 0x13); *pbVar3 == 0; pbVar3 = pbVar3 + 1) {
      }
                    /* puts a message into the message-buffer ring [doc] */
      if ((0xfd < *pbVar3) &&
         (iVar4 = knl_mbf_put(iVar5,param_2,param_3,tmout,param_1,param_2,param_3,tmout), iVar4 != 0
         )) {
        software_interrupt(0);
        return knl_svc_return;
      }
    }
    if (tmout == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar6 = (uint)knl_rdq[0];
      if (uVar6 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        p_knl_tcb = knl_tsk_tab[uVar6];
        if (tmout == -1) {
          bVar1 = 0x60;
        }
        else {
          knl_timeout_add(tmout,p_knl_tcb,knl_rdq[0]);
          bVar1 = 0x62;
        }
        p_knl_tcb->state = bVar1;
        iVar4 = iVar5 + 0x13;
        if (*(byte *)(iVar5 + 0x14) < 0xfe) {
          iVar4 = iVar4 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_arg3 = param_3;
        knl_sys.wait_arg2 = param_2;
        knl_sys.wait_id = param_1;
                    /* Moves the running task into an object's wait queue [doc] */
        pcVar2 = (code *)knl_wait_enter(iVar4,p_knl_tcb,uVar6);
        return pcVar2;
      }
    }
    software_interrupt(0);
    knl_sys.last_ercd = -0x19;
    return (code *)0xffffffe7;
  }
  p_knl_tcb = knl_tsk_tab[uVar6];
  if (param_3 != 0) {
    knl_memcpy(*(undefined4 *)(p_knl_tcb->sp + 0xc),param_2,param_3);
  }
  *(uint *)p_knl_tcb->sp = param_3;
  if ((p_knl_tcb->state & 2) != 0) {
                    /* unlinks the TCB from its timer-wheel slot [doc] */
    knl_timeout_remove(p_knl_tcb,uVar6);
  }
  p_knl_tcb->state = 0x10;
  if (p_knl_tcb->f_0x09_u8 == 0) {
                    /* Appends the TCB to ready queue 0x208DC18C + priority [doc] */
    pcVar2 = (code *)knl_make_ready(p_knl_tcb,uVar6);
    return pcVar2;
  }
  pcVar2 = (code *)knl_release_suspended();
  return pcVar2;
}


// ===== itron_twai_flg @ 20152988 (496 bytes)

void * itron_twai_flg(uint param_1,uint param_2,uint param_3,uint *param_4,int tmout)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  void *pvVar4;
  knl_flg *p_knl_flg;
  knl_tcb *tcb;
  bool bVar5;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    if (((param_2 != 0) && ((param_3 & 0xfffffffa) == 0)) && (-3 < tmout)) {
      software_interrupt(0);
      p_knl_flg = knl_flg_tab[param_1];
      if (p_knl_flg == (knl_flg *)0x0) {
        software_interrupt(0);
        return (void *)0xffffffd6;
      }
      if (((p_knl_flg->flgatr & 2) == 0) && (p_knl_flg->wq[0] != 0)) {
        software_interrupt(0);
        return (void *)0xffffffe4;
      }
      uVar2 = p_knl_flg->flgptn;
      if ((param_3 & 1) == 0) {
        if ((param_2 & ~uVar2) != 0) goto LAB_20152a7c;
      }
      else if ((uVar2 & param_2) == 0) {
LAB_20152a7c:
        if (tmout == 0) {
          software_interrupt(0);
          return (void *)0xffffffce;
        }
        if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
           (uVar2 = (uint)knl_rdq[0], uVar2 != ((byte)DAT_201659d0 + 1 & 0xff))) {
          tcb = knl_tsk_tab[uVar2];
          if (tmout == -1) {
            bVar1 = p_knl_flg->flgatr & 4 | (byte)param_3 | 0x50;
          }
          else {
            knl_timeout_add(tmout,tcb,knl_rdq[0]);
            bVar1 = p_knl_flg->flgatr & 4 | (byte)param_3 | 0x52;
          }
          tcb->state = bVar1;
          pbVar3 = p_knl_flg->wq;
          if (p_knl_flg->wq[1] < 0xfe) {
            pbVar3 = pbVar3 + knl_sys.run_pri + -1;
          }
          knl_sys.wait_arg3 = param_2;
          knl_sys.wait_arg2 = (uint)param_4;
          knl_sys.wait_id = param_1;
                    /* Moves the running task into an object's wait queue [doc] */
          pvVar4 = (void *)knl_wait_enter(pbVar3,tcb,uVar2);
          return pvVar4;
        }
        software_interrupt(0);
        knl_sys.last_ercd = -0x19;
        return &DAT_ffffffe7;
      }
      bVar5 = (param_3 & 4) == 0;
      *param_4 = uVar2;
      if (bVar5) {
        uVar2 = (uint)p_knl_flg->flgatr;
      }
      if (!bVar5 || (uVar2 & 4) != 0) {
        p_knl_flg->flgptn = 0;
      }
      software_interrupt(0);
      return knl_svc_return;
    }
    knl_sys.last_ercd = -0x11;
  }
  return (void *)knl_sys.last_ercd;
}


// ===== itron_twai_sem @ 20152bb0 (328 bytes)

/* (semid, tmout): semaphore table 0x208DBCA4, E_CTX, waits with time-out (300, 1000 or TMO_FEVR)
   [fact]; paired with itron_sig_sem around the FS and link code [fact]; T23d NORTi uITRON 4.0 NORTi
   Version 4 (MiSPO) (uitron_api_shape 0.950): (semid, tmout): sem table 0x208DBCA4, count-- or
   waits (state 0x90/0x92), E_TMOUT [inference] */

code * itron_twai_sem(uint param_1,int tmout)

{
  byte bVar1;
  byte *pbVar2;
  code *pcVar3;
  knl_sem *p_knl_sem;
  knl_tcb *tcb;
  uint uVar4;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    software_interrupt(0);
    p_knl_sem = knl_sem_tab[param_1];
    if (p_knl_sem == (knl_sem *)0x0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    if (p_knl_sem->semcnt != 0) {
      p_knl_sem->semcnt = p_knl_sem->semcnt - 1;
      software_interrupt(0);
      return knl_svc_return;
    }
    if (tmout == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar4 = (uint)knl_rdq[0];
      if (uVar4 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        tcb = knl_tsk_tab[uVar4];
        if (tmout == -1) {
          bVar1 = 0x90;
        }
        else {
          knl_timeout_add(tmout,tcb,knl_rdq[0]);
          bVar1 = 0x92;
        }
        tcb->state = bVar1;
        pbVar2 = p_knl_sem->wq;
        if (p_knl_sem->wq[1] < 0xfe) {
          pbVar2 = pbVar2 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_id = param_1;
                    /* Moves the running task into an object's wait queue [doc] */
        pcVar3 = (code *)knl_wait_enter(pbVar2,tcb,uVar4);
        return pcVar3;
      }
    }
    software_interrupt(0);
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_unl_cpu @ 20152d28 (164 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): clears the CPU-locked
   state of 0x208003DB and dispatches when pending [inference] */

code * itron_unl_cpu(void)

{
  software_interrupt(0);
  knl_sys.f_0x24_u32 = knl_sys.f_0x24_u32 & 0xffffff3f;
  if ((knl_sys.dsp_state & 8) == 0) {
    knl_sys.dsp_state = 0;
    if (((knl_sys.ctx_isr == 0) && (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) &&
       ((knl_sys.dsp_pending != 0 || (knl_sys.f_0x34_u8 != 0)))) {
      software_interrupt(0);
      return FUN_20156748;
    }
  }
  else {
    knl_sys.dsp_state = 9;
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== itron_unl_mtx @ 20152df4 (392 bytes)

/* (mtxid 1..0x20): table 0x208DBFC4, E_ILUSE when not the owner [fact]; T23d NORTi uITRON 4.0 NORTi
   Version 4 (MiSPO) (uitron_api_shape 0.900): (mtxid): mtx table 0x208DBFC4, E_ILUSE when not the
   owner, restores the priority, passes it to a waiter [inference] */

code * itron_unl_mtx(uint param_1)

{
  short sVar1;
  sbyte sVar2;
  bool bVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  uint tskid;
  int iVar7;
  knl_mtx *p_knl_mtx;
  knl_tcb *tcb;
  
  if ((param_1 == 0) || (0x20 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
       (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      p_knl_mtx = knl_mtx_tab[param_1];
      if (p_knl_mtx == (knl_mtx *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      tskid = (uint)knl_rdq[0];
      if (p_knl_mtx->owner != tskid) {
        software_interrupt(0);
        return (code *)0xffffffe4;
      }
      sVar2 = p_knl_mtx->pri;
      tcb = knl_tsk_tab[tskid];
      psVar4 = &tcb->mtx_held;
      iVar7 = (int)tcb->bpri;
      sVar1 = tcb->mtx_held;
      while (sVar1 != 0) {
        if ((int)*psVar4 == param_1) {
          *psVar4 = p_knl_mtx->prev_held;
          if (sVar2 == 0) break;
        }
        else {
          iVar6 = (int)knl_mtx_tab[*psVar4]->pri;
          iVar5 = iVar6;
          if (iVar6 != 0) {
            iVar5 = iVar6 - iVar7;
          }
          if (iVar5 < 0 != (iVar6 != 0 && SBORROW4(iVar6,iVar7))) {
            iVar7 = iVar6;
          }
          psVar4 = &knl_mtx_tab[*psVar4]->prev_held;
        }
        sVar1 = *psVar4;
      }
      if (tcb->pri == iVar7) {
        bVar3 = false;
      }
      else {
        knl_queue_move(knl_rdq + iVar7,tcb,tskid);
        iVar5 = (int)knl_sys.run_pri;
        tcb->pri = (sbyte)iVar7;
        if (iVar5 < iVar7) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
      }
      iVar7 = FUN_201547d0(p_knl_mtx,param_1);
      if (iVar7 != 0 || bVar3) {
        software_interrupt(0);
        return knl_resched;
      }
      software_interrupt(0);
      return knl_svc_return;
    }
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_iwup_tsk @ 20152fac (284 bytes)

/* [inference from use in an ISR] */

code * itron_iwup_tsk(uint param_1)

{
  byte bVar1;
  code *pcVar2;
  knl_tcb *tcb;
  
  if (param_1 == 0) {
    param_1 = (uint)knl_rdq[0];
  }
  if (DAT_201659d0 < param_1) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  tcb = knl_tsk_tab[param_1];
  if (tcb == (knl_tcb *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  bVar1 = tcb->state;
  if (bVar1 == 0x22) {
    tcb->state = 0x10;
                    /* unlinks the TCB from its timer-wheel slot [doc] */
    knl_timeout_remove(tcb,param_1);
    if (tcb->f_0x09_u8 != 0) {
      software_interrupt(0);
      return knl_svc_return;
    }
  }
  else {
    if (bVar1 != 0x20) {
      if (bVar1 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      bVar1 = tcb->f_0x08_u8 + 1;
      tcb->f_0x08_u8 = bVar1;
      if (bVar1 == 0) {
        tcb->f_0x08_u8 = 0xff;
        software_interrupt(0);
        return (code *)0xffffffd5;
      }
      software_interrupt(0);
      return knl_svc_return;
    }
    tcb->state = 0x10;
    if (tcb->f_0x09_u8 != 0) {
      software_interrupt(0);
      return knl_svc_return;
    }
  }
  pcVar2 = (code *)FUN_20154538(tcb,param_1);
  return pcVar2;
}


// ===== FUN_201530e4 @ 201530e4 (24 bytes)

undefined4 FUN_201530e4(undefined4 *param_1,uint param_2)

{
  param_1[1] = param_2 & 0xfffffff8;
  *param_1 = 0;
  return 0;
}


// ===== knl_sys_init @ 201530fc (1208 bytes)

/* WARNING: Removing unreachable block (ram,0x20153124) */
/* WARNING: Removing unreachable block (ram,0x20153188) */
/* WARNING: Removing unreachable block (ram,0x201531b0) */
/* Kernel start-up called by kernel_heap_init: sets the NORTi system variables 0x208003A8..
   (structs_display.h knl_sys: all set by knl_sys_init) and ends with svc 0 [fact] */

undefined4 knl_sys_init(uint *param_1,int param_2)

{
  int iVar1;
  int iVar2;
  byte *pbVar3;
  int iVar4;
  bool bVar5;
  
  software_interrupt(0);
  pbVar3 = (byte *)(param_2 + -0x400);
  iVar1 = 0x400;
  bVar5 = true;
  knl_sys.isr_area = pbVar3;
  while (bVar5) {
    iVar1 = iVar1 + -1;
    bVar5 = iVar1 != 0;
    pbVar3 = pbVar3 + -1;
    *pbVar3 = 0;
  }
  knl_sys.heap = param_1;
  param_1[1] = (int)pbVar3 - (int)param_1 & 0xfffffff8;
  *param_1 = 0;
  knl_sys.f_0x50_u32 = 0;
  knl_sys.f_0x4c_u32 = 0;
  knl_sys.tick_hi = 0;
  knl_sys.tim_base_hi = 0;
  knl_sys.tick_lo = 0;
  knl_sys.tim_base_lo = 0;
  knl_sys.f_0x28_u32 = 0;
  knl_sys.f_0x30_u8 = 0;
  knl_sys.last_ercd = 0;
  knl_sys.dsp_pending = 0;
  knl_sys.ctx_isr = 0;
  knl_sys.f_0x34_u8 = 0;
  knl_sys.tick_pending = 0;
  knl_sys.f_0x36_u8 = 0;
  knl_sys.run_pri = 9;
  knl_sys.f_0x10_u32 = 0;
  knl_sys.idle_hook = 0;
  DAT_208dc174 = 0;
  iVar4 = DAT_201659d0 + 1;
  iVar1 = 1;
  if (0 < iVar4) {
    do {
      iVar2 = iVar1 + 1;
      knl_tsk_tab[iVar1] = (knl_tcb *)0x0;
      iVar1 = iVar2;
    } while (iVar2 <= iVar4);
  }
  iVar1 = 1;
  do {
    iVar4 = iVar1 + 1;
    knl_sem_tab[iVar1] = (knl_sem *)0x0;
    iVar1 = iVar4;
  } while (iVar4 < 0x41);
  iVar1 = 1;
  do {
    iVar4 = iVar1 + 1;
    knl_flg_tab[iVar1] = (knl_flg *)0x0;
    iVar1 = iVar4;
  } while (iVar4 < 0x41);
  iVar1 = 1;
  do {
    iVar4 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(&DAT_208dbea4 + iVar4) = 0;
  } while (iVar1 < 9);
  iVar1 = 1;
  do {
    iVar4 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(&DAT_208dbec4 + iVar4) = 0;
  } while (iVar1 < 9);
  iVar1 = 1;
  do {
    iVar4 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(iVar4 + 0x208dbee4) = 0;
  } while (iVar1 < 9);
  iVar1 = 1;
  do {
    iVar4 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(&DAT_208dbf04 + iVar4) = 0;
  } while (iVar1 < 9);
  iVar1 = 1;
  do {
    iVar4 = iVar1 + 1;
    knl_mpf_tab[iVar1] = (knl_mpf *)0x0;
    iVar1 = iVar4;
  } while (iVar4 < 0x11);
  iVar1 = 1;
  do {
    iVar4 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(&DAT_208dbfa4 + iVar4) = 0;
  } while (iVar1 < 9);
  iVar1 = 1;
  do {
    iVar4 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(&DAT_208dbf64 + iVar4) = 0;
  } while (iVar1 < 9);
  iVar1 = 1;
  do {
    iVar4 = iVar1 + 1;
    (&DAT_208dbf84)[iVar1] = 0;
    iVar1 = iVar4;
  } while (iVar4 < 9);
  iVar1 = 1;
  do {
    iVar4 = iVar1 + 1;
    knl_mtx_tab[iVar1] = (knl_mtx *)0x0;
    iVar1 = iVar4;
  } while (iVar4 < 0x21);
  iVar1 = 1;
  do {
    iVar4 = iVar1 + 1;
    (&DAT_208dc044)[iVar1] = 0;
    iVar1 = iVar4;
  } while (iVar4 < 0x41);
  iVar1 = 1;
  do {
    iVar4 = iVar1 * 4;
    iVar1 = iVar1 + 1;
    *(undefined4 *)(iVar4 + 0x208dc144) = 0;
  } while (iVar1 < 9);
  iVar1 = 1;
  do {
    knl_rdq[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 10);
  iVar1 = 0;
  do {
    (&DAT_20800400)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  iVar1 = 0;
  do {
    (&DAT_20800401)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  iVar1 = 0;
  do {
    (&DAT_20800402)[iVar1] = 0;
    iVar1 = iVar1 + 1;
  } while (iVar1 < 1);
  knl_sys.dsp_state = 1;
  knl_sys.tmo_mask = 0;
  knl_sys.tmo_mask_1 = 0;
  knl_sys.tmo_mask_2 = 0;
  iVar1 = DAT_201659d0 + 1;
  knl_sys.f_0x0c_u32 = 8;
  knl_tsk_tab[iVar1] = (knl_tcb *)&DAT_208dc178;
  knl_rdq[9] = (byte)iVar1;
  knl_rdq[0] = knl_rdq[9];
  return 0;
}


// ===== FUN_201535b4 @ 201535b4 (108 bytes)

void FUN_201535b4(undefined *param_1,int param_2,uint param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  
  if (param_1 == &DAT_208dbf64) {
    pbVar3 = &knl_sys.tmo_mask_1;
  }
  else {
    pbVar3 = &knl_sys.tmo_mask_2;
  }
  if (param_1 == &DAT_208dbf64) {
    puVar4 = &DAT_20800401;
  }
  else {
    puVar4 = &DAT_20800402;
  }
  pbVar3 = puVar4 + (*(uint *)(param_2 + 4) & (uint)*pbVar3);
  bVar1 = *(byte *)(param_2 + 9);
  if (bVar1 == param_3) {
    *pbVar3 = 0;
  }
  else {
    bVar2 = *(byte *)(param_2 + 8);
    if ((uint)*pbVar3 == (param_3 & 0xff)) {
      *pbVar3 = bVar2;
    }
    *(byte *)(*(int *)(param_1 + (uint)bVar2 * 4) + 9) = bVar1;
    *(byte *)(*(int *)(param_1 + (uint)bVar1 * 4) + 8) = bVar2;
  }
  return;
}


// ===== knl_tick_table_dbf84 @ 20153620 (256 bytes)

/* WARNING: Removing unreachable block (ram,0x20153688) */
/* WARNING: Removing unreachable block (ram,0x2015369c) */
/* Per tick: the same wheel walk for the objects of table 0x208DBF84 (wheel slots 0x20800402, mask
   tmo_mask_2) [fact]; which uITRON object kind the table holds is open (it sits between the cyc
   table 0x208DBF64 and the dtq table 0x208DBFA4) */

void knl_tick_table_dbf84(void)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  uint uVar4;
  byte *pbVar5;
  uint uVar6;
  short *psVar7;
  uint uVar8;
  bool bVar9;
  uint knl_sys_tick_lo_val;
  
  knl_sys_tick_lo_val = knl_sys.tick_lo;
  uVar8 = (uint)(short)knl_sys.tick_hi;
  uVar3 = knl_sys.tmo_mask_2 & knl_sys.tick_lo;
  bVar1 = (&DAT_20800402)[uVar3];
  do {
    uVar4 = (uint)bVar1;
    if (uVar4 == 0) {
      return;
    }
    psVar7 = (short *)(&DAT_208dbf84)[uVar4];
    pbVar5 = (byte *)((int)psVar7 + 9);
    while( true ) {
      uVar6 = *(uint *)(psVar7 + 2);
      bVar9 = uVar6 == knl_sys_tick_lo_val;
      if (bVar9) {
        uVar6 = (uint)*psVar7;
      }
      if (bVar9 && uVar6 == uVar8) break;
      if (uVar4 == *pbVar5) {
        return;
      }
      uVar4 = (uint)*(byte *)(psVar7 + 4);
      psVar7 = (short *)(&DAT_208dbf84)[uVar4];
    }
    bVar1 = *(byte *)((int)psVar7 + 9);
    pbVar5 = &DAT_20800402 + (*(uint *)(psVar7 + 2) & (uint)knl_sys.tmo_mask_2);
    if (bVar1 == uVar4) {
      *pbVar5 = 0;
    }
    else {
      bVar2 = *(byte *)(psVar7 + 4);
      if (*pbVar5 == uVar4) {
        *pbVar5 = bVar2;
      }
      *(byte *)((&DAT_208dbf84)[bVar2] + 9) = bVar1;
      *(byte *)((&DAT_208dbf84)[bVar1] + 8) = bVar2;
    }
    *(undefined1 *)(psVar7 + 4) = 0;
    *(undefined1 *)((int)psVar7 + 9) = 0;
    software_interrupt(0);
    (**(code **)(psVar7 + 8))(*(undefined4 *)(psVar7 + 6));
    software_interrupt(0);
    bVar1 = (&DAT_20800402)[uVar3];
  } while( true );
}


// ===== FUN_20153720 @ 20153720 (104 bytes)

void FUN_20153720(undefined *param_1,int param_2,byte param_3)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  undefined1 *puVar4;
  
  if (param_1 == &DAT_208dbf64) {
    pbVar3 = &knl_sys.tmo_mask_1;
  }
  else {
    pbVar3 = &knl_sys.tmo_mask_2;
  }
  if (param_1 == &DAT_208dbf64) {
    puVar4 = &DAT_20800401;
  }
  else {
    puVar4 = &DAT_20800402;
  }
  bVar1 = puVar4[*(uint *)(param_2 + 4) & (uint)*pbVar3];
  if (bVar1 == 0) {
    puVar4[*(uint *)(param_2 + 4) & (uint)*pbVar3] = param_3;
    *(byte *)(param_2 + 8) = param_3;
    *(byte *)(param_2 + 9) = param_3;
    return;
  }
  *(byte *)(param_2 + 8) = bVar1;
  bVar2 = *(byte *)(*(int *)(param_1 + (uint)bVar1 * 4) + 9);
  *(byte *)(*(int *)(param_1 + (uint)bVar1 * 4) + 9) = param_3;
  *(byte *)(param_2 + 9) = bVar2;
  *(byte *)(*(int *)(param_1 + (uint)bVar2 * 4) + 8) = param_3;
  return;
}


// ===== knl_tick_cyclic @ 20153788 (332 bytes)

/* Per tick: walks the cyclic-handler wheel slot 0x20800401[tick_lo & tmo_mask_1] of the cyc table
   0x208DBF64 (itron_acre_cyc), re-arms each due handler by its period and runs it [fact for the
   wheel walk and the re-arm] */

void knl_tick_cyclic(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  byte *pbVar7;
  short *psVar8;
  uint uVar9;
  bool bVar10;
  ushort knl_sys_tick_hi_val;
  uint knl_sys_tick_lo_val;
  
  knl_sys_tick_lo_val = knl_sys.tick_lo;
  knl_sys_tick_hi_val = knl_sys.tick_hi;
  uVar9 = (uint)(short)knl_sys.tick_hi;
  uVar4 = knl_sys.tmo_mask_1 & knl_sys.tick_lo;
  do {
    uVar5 = (uint)(byte)(&DAT_20800401)[uVar4];
    if (uVar5 == 0) {
      return;
    }
    psVar8 = *(short **)(&DAT_208dbf64 + uVar5 * 4);
    pbVar7 = (byte *)((int)psVar8 + 9);
    while( true ) {
      uVar6 = *(uint *)(psVar8 + 2);
      bVar10 = uVar6 == knl_sys_tick_lo_val;
      if (bVar10) {
        uVar6 = (uint)*psVar8;
      }
      if (bVar10 && uVar6 == uVar9) break;
      if (uVar5 == *pbVar7) {
        return;
      }
      uVar5 = (uint)*(byte *)(psVar8 + 4);
      psVar8 = *(short **)(&DAT_208dbf64 + uVar5 * 4);
    }
    bVar1 = *(byte *)((int)psVar8 + 9);
    pbVar7 = &DAT_20800401 + (*(uint *)(psVar8 + 2) & (uint)knl_sys.tmo_mask_1);
    if (bVar1 == uVar5) {
      *pbVar7 = 0;
    }
    else {
      bVar2 = *(byte *)(psVar8 + 4);
      if (*pbVar7 == uVar5) {
        *pbVar7 = bVar2;
      }
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar2 * 4) + 9) = bVar1;
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar1 * 4) + 8) = bVar2;
    }
    uVar6 = *(uint *)(psVar8 + 10) + knl_sys_tick_lo_val;
    *(uint *)(psVar8 + 2) = uVar6;
    *psVar8 = psVar8[8] + knl_sys_tick_hi_val;
    if (uVar6 < *(uint *)(psVar8 + 10)) {
      *psVar8 = psVar8[8] + knl_sys_tick_hi_val + 1;
    }
    bVar1 = (&DAT_20800401)[knl_sys.tmo_mask_1 & uVar6];
    bVar2 = (byte)uVar5;
    if (bVar1 == 0) {
      (&DAT_20800401)[knl_sys.tmo_mask_1 & uVar6] = bVar2;
      *(byte *)(psVar8 + 4) = bVar2;
      *(byte *)((int)psVar8 + 9) = bVar2;
    }
    else {
      *(byte *)(psVar8 + 4) = bVar1;
      bVar3 = *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar1 * 4) + 9);
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar1 * 4) + 9) = bVar2;
      *(byte *)((int)psVar8 + 9) = bVar3;
      *(byte *)(*(int *)(&DAT_208dbf64 + (uint)bVar3 * 4) + 8) = bVar2;
    }
    software_interrupt(0);
    if ((*(byte *)(psVar8 + 6) & 1) != 0) {
      (**(code **)(psVar8 + 0xe))(*(undefined4 *)(psVar8 + 0xc));
    }
    software_interrupt(0);
  } while( true );
}


// ===== FUN_201538d4 @ 201538d4 (80 bytes)

void FUN_201538d4(byte *queue,knl_tcb *tcb,byte tskid)

{
  byte bVar1;
  byte bVar2;
  
  tcb->queue = queue;
  bVar1 = *queue;
  if (bVar1 != 0) {
    tcb->q_next = bVar1;
    bVar2 = knl_tsk_tab[bVar1]->q_prev;
    knl_tsk_tab[bVar1]->q_prev = tskid;
    tcb->q_prev = bVar2;
    knl_tsk_tab[bVar2]->q_next = tskid;
    return;
  }
  *queue = tskid;
  tcb->q_next = tskid;
  tcb->q_prev = tskid;
  return;
}


// ===== knl_queue_remove @ 201539ec (76 bytes)

/* Unlinks TCB param_1 (id param_2) from its ring (+6/+7 links, head at +0x10), the first half of
   knl_queue_move [fact] */

void knl_queue_remove(knl_tcb *tcb,uint tskid)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  bVar1 = tcb->q_prev;
  pbVar3 = tcb->queue;
  if (bVar1 == tskid) {
    *pbVar3 = 0;
  }
  else {
    bVar2 = tcb->q_next;
    if ((uint)*pbVar3 == (tskid & 0xff)) {
      *pbVar3 = bVar2;
    }
    knl_tsk_tab[bVar2]->q_prev = bVar1;
    knl_tsk_tab[bVar1]->q_next = bVar2;
  }
  return;
}


// ===== knl_queue_move @ 20153a38 (156 bytes)

/* Unlinks TCB param_2 (id param_3) from the id-linked ring it is in (+6 prev / +7 next, head byte
   at +0x10) and appends it to ring head param_1; TCB table 0x208DBBA0 [fact]; used by the wait and
   ready paths of itron_* [inference] */

void knl_queue_move(byte *queue,knl_tcb *tcb,uint tskid)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  byte *pbVar4;
  
  bVar1 = tcb->q_prev;
  pbVar4 = tcb->queue;
  if (bVar1 == tskid) {
    *pbVar4 = 0;
  }
  else {
    bVar2 = tcb->q_next;
    if (*pbVar4 == tskid) {
      *pbVar4 = bVar2;
    }
    knl_tsk_tab[bVar2]->q_prev = bVar1;
    knl_tsk_tab[bVar1]->q_next = bVar2;
  }
  bVar2 = (byte)tskid;
  tcb->queue = queue;
  bVar1 = *queue;
  if (bVar1 == 0) {
    *queue = bVar2;
    tcb->q_next = bVar2;
    tcb->q_prev = bVar2;
    return;
  }
  tcb->q_next = bVar1;
  bVar3 = knl_tsk_tab[bVar1]->q_prev;
  knl_tsk_tab[bVar1]->q_prev = bVar2;
  tcb->q_prev = bVar3;
  knl_tsk_tab[bVar3]->q_next = bVar2;
  return;
}


// ===== knl_timeout_remove @ 20153ad4 (96 bytes)

/* (tcb, tskid): unlinks the TCB from its timer-wheel slot [fact] */

void knl_timeout_remove(knl_tcb *tcb,uint tskid)

{
  byte bVar1;
  byte bVar2;
  byte *pbVar3;
  
  pbVar3 = &DAT_20800400 + (tcb->tmo_due & (uint)knl_sys.tmo_mask);
  bVar1 = tcb->tmo_prev;
  if (bVar1 == tskid) {
    *pbVar3 = 0;
  }
  else {
    bVar2 = tcb->tmo_next;
    if ((uint)*pbVar3 == (tskid & 0xff)) {
      *pbVar3 = bVar2;
    }
    knl_tsk_tab[bVar2]->tmo_prev = bVar1;
    knl_tsk_tab[bVar1]->tmo_next = bVar2;
  }
  return;
}


// ===== knl_freelist_alloc @ 20153b34 (88 bytes)

/* First-fit allocator on a free list {next, size}: rounds the size up to 8, splits or unlinks the
   block [fact] */

void knl_freelist_alloc(undefined4 *param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  int iVar4;
  
  uVar3 = param_2 + 7U & 0xfffffff8;
  if (uVar3 != 0) {
    puVar1 = (undefined4 *)*param_1;
    do {
      puVar2 = param_1;
      param_1 = puVar1;
      if (param_1 == (undefined4 *)0x0) {
        return;
      }
      puVar1 = (undefined4 *)*param_1;
    } while ((uint)param_1[1] < uVar3);
    iVar4 = param_1[1] - uVar3;
    if (iVar4 == 0) {
      *puVar2 = puVar1;
    }
    else {
      param_1 = (undefined4 *)(uVar3 + (int)param_1);
      *puVar2 = param_1;
      *param_1 = puVar1;
      param_1[1] = iVar4;
    }
  }
  return;
}


// ===== FUN_20153b8c @ 20153b8c (328 bytes)

byte FUN_20153b8c(int param_1)

{
  byte bVar1;
  byte bVar2;
  int *piVar3;
  byte *pbVar4;
  knl_tcb *tcb;
  uint tskid;
  byte *pbVar5;
  byte bVar6;
  int iVar7;
  int iVar8;
  
  bVar6 = 0;
  iVar8 = *(int *)(&DAT_208dbf04 + param_1 * 4);
  pbVar5 = (byte *)(iVar8 + 0x10);
  bVar1 = *(byte *)(iVar8 + 0x10);
  do {
    tskid = (uint)bVar1;
    if (0xfd < tskid) {
      return bVar6;
    }
    while (tskid != 0) {
      tcb = knl_tsk_tab[tskid];
      iVar7 = *(int *)(tcb->sp + 8) + 8;
                    /* First-fit allocator on a free list {next, size} [doc] */
      piVar3 = (int *)knl_freelist_alloc(iVar8 + 4,iVar7);
      if (piVar3 == (int *)0x0) {
        return bVar6;
      }
      *piVar3 = iVar7;
      **(int **)(tcb->sp + 0xc) = (int)(piVar3 + 2);
      if ((tcb->state & 2) != 0) {
        pbVar4 = &DAT_20800400 + (tcb->tmo_due & (uint)knl_sys.tmo_mask);
        bVar1 = tcb->tmo_prev;
        if (bVar1 == tskid) {
          *pbVar4 = 0;
        }
        else {
          bVar2 = tcb->tmo_next;
          if (*pbVar4 == tskid) {
            *pbVar4 = bVar2;
          }
          knl_tsk_tab[bVar2]->tmo_prev = bVar1;
          knl_tsk_tab[bVar1]->tmo_next = bVar2;
        }
      }
      tcb->state = 0x10;
      if (tcb->f_0x09_u8 == 0) {
        iVar7 = (int)tcb->pri;
        if (iVar7 < knl_sys.run_pri) {
          bVar6 = bVar6 | iVar7 < knl_sys.run_pri;
        }
        knl_queue_move(knl_rdq + iVar7,tcb,tskid);
      }
      else {
        knl_queue_remove(tcb,tskid);
      }
      tskid = (uint)*pbVar5;
    }
    pbVar5 = pbVar5 + 1;
    bVar1 = *pbVar5;
  } while( true );
}


// ===== knl_mbf_put @ 20153cd4 (280 bytes)

/* (mbf, msg, size): puts a message into the message-buffer ring: one byte when the maximum message
   size is 1, else a 16-bit length and the bytes with wrap-around; 0 when there is no room [fact] */

undefined4 knl_mbf_put(int param_1,undefined1 *param_2,uint param_3)

{
  ushort uVar1;
  ushort uVar2;
  undefined1 *puVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  uVar1 = *(ushort *)(param_1 + 0xe);
  if (*(short *)(param_1 + 0x10) == 1) {
    if (uVar1 != 0) {
      *(ushort *)(param_1 + 0xe) = uVar1 - 1;
      uVar1 = *(ushort *)(param_1 + 8);
      *(undefined1 *)(*(int *)(param_1 + 4) + (uint)uVar1) = *param_2;
      uVar6 = uVar1 + 1;
      if (uVar6 == *(ushort *)(param_1 + 0xc)) {
        uVar6 = 0;
      }
      *(short *)(param_1 + 8) = (short)uVar6;
      return 1;
    }
  }
  else if (param_3 + 2 <= (uint)uVar1) {
    uVar6 = param_3 & 0xffff;
    uVar2 = *(ushort *)(param_1 + 8);
    *(ushort *)(param_1 + 0xe) = (uVar1 - (short)param_3) + -2;
    *(char *)(*(int *)(param_1 + 4) + (uint)uVar2) = (char)uVar6;
    uVar4 = uVar2 + 1;
    if (*(ushort *)(param_1 + 0xc) == uVar4) {
      uVar4 = 0;
    }
    *(char *)(*(int *)(param_1 + 4) + uVar4) = (char)(uVar6 >> 8);
    uVar4 = uVar4 + 1;
    uVar7 = (uint)*(ushort *)(param_1 + 0xc);
    if (uVar7 == uVar4) {
      uVar4 = 0;
    }
    if (uVar7 <= uVar6 + uVar4) {
      iVar5 = uVar7 - uVar4;
      uVar6 = uVar6 - iVar5 & 0xffff;
      puVar3 = (undefined1 *)(*(int *)(param_1 + 4) + uVar4);
      for (; iVar5 != 0; iVar5 = iVar5 + -1) {
        *puVar3 = *param_2;
        puVar3 = puVar3 + 1;
        param_2 = param_2 + 1;
      }
      uVar4 = 0;
    }
    *(short *)(param_1 + 8) = (short)uVar4 + (short)uVar6;
    puVar3 = (undefined1 *)(*(int *)(param_1 + 4) + uVar4);
    for (; uVar6 != 0; uVar6 = uVar6 - 1) {
      *puVar3 = *param_2;
      puVar3 = puVar3 + 1;
      param_2 = param_2 + 1;
    }
    return 1;
  }
  return 0;
}


// ===== FUN_20153dec @ 20153dec (316 bytes)

byte FUN_20153dec(int param_1)

{
  byte bVar1;
  byte bVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  knl_tcb *tcb;
  uint tskid;
  byte *pbVar6;
  byte bVar7;
  
  bVar7 = 0;
  iVar3 = *(int *)(&DAT_208dbec4 + param_1 * 4);
  pbVar6 = (byte *)(iVar3 + 0x13);
  do {
    tskid = (uint)*pbVar6;
    if (tskid != 0) {
      if (0xfd < tskid) {
        return bVar7;
      }
      do {
        tcb = knl_tsk_tab[tskid];
        if (*(int *)(tcb->sp + 8) == 0) {
          return bVar7;
        }
                    /* puts a message into the message-buffer ring [doc] */
        iVar4 = knl_mbf_put(iVar3,*(undefined4 *)(tcb->sp + 0xc));
        if (iVar4 == 0) {
          return bVar7;
        }
        if ((tcb->state & 2) != 0) {
          bVar1 = tcb->tmo_prev;
          pbVar5 = &DAT_20800400 + (tcb->tmo_due & (uint)knl_sys.tmo_mask);
          if (bVar1 == tskid) {
            *pbVar5 = 0;
          }
          else {
            bVar2 = tcb->tmo_next;
            if (*pbVar5 == tskid) {
              *pbVar5 = bVar2;
            }
            knl_tsk_tab[bVar2]->tmo_prev = bVar1;
            knl_tsk_tab[bVar1]->tmo_next = bVar2;
          }
        }
        tcb->state = 0x10;
        if (tcb->f_0x09_u8 == 0) {
          iVar4 = (int)tcb->pri;
          if (iVar4 < knl_sys.run_pri) {
            bVar7 = bVar7 | iVar4 < knl_sys.run_pri;
          }
          knl_queue_move(knl_rdq + iVar4,tcb,tskid);
        }
        else {
          knl_queue_remove(tcb,tskid);
        }
        tskid = (uint)*pbVar6;
      } while (tskid != 0);
    }
    pbVar6 = pbVar6 + 1;
  } while( true );
}


// ===== FUN_20153f28 @ 20153f28 (412 bytes)

void FUN_20153f28(uint param_1)

{
  sbyte sVar1;
  int iVar2;
  int iVar3;
  byte *pbVar4;
  knl_mtx *p_knl_mtx;
  knl_tcb *tcb;
  
  tcb = knl_tsk_tab[param_1];
  while( true ) {
    iVar2 = (int)tcb->mtx_held;
    iVar3 = (int)tcb->bpri;
    do {
      p_knl_mtx = knl_mtx_tab[iVar2];
      if (p_knl_mtx->mtxatr == 2) {
        iVar2 = 1;
        for (pbVar4 = p_knl_mtx->wq; *pbVar4 == 0; pbVar4 = pbVar4 + 1) {
          iVar2 = iVar2 + 1;
        }
        if (iVar2 < iVar3) {
          iVar3 = iVar2;
        }
        p_knl_mtx->pri = (sbyte)iVar2;
      }
      else if ((p_knl_mtx->mtxatr == 3) && (p_knl_mtx->pri < iVar3)) {
        iVar3 = (int)p_knl_mtx->pri;
      }
      iVar2 = (int)p_knl_mtx->prev_held;
    } while (iVar2 != 0);
    sVar1 = tcb->pri;
    if (sVar1 == iVar3) {
      return;
    }
    tcb->pri = (sbyte)iVar3;
    if (tcb->state == 0x10) {
      if (tcb->f_0x09_u8 != 0) {
        return;
      }
      knl_queue_move(knl_rdq + iVar3,tcb,param_1);
    }
    if (tcb->state < 0x50) {
      return;
    }
    if (tcb->queue[1] != 0xfe) {
      knl_queue_move(tcb->queue + -((int)sVar1 - (int)(sbyte)iVar3),tcb,param_1);
    }
    if ((tcb->state & 0xfc) != 0x94) {
      if ((tcb->state & 0xfc) == 0x60) {
        FUN_20153dec(*(undefined4 *)(tcb->sp + 4));
        return;
      }
      if ((tcb->state & 0xf0) != 0xc0) {
        return;
      }
      FUN_20153b8c(*(undefined4 *)(tcb->sp + 4));
      return;
    }
    p_knl_mtx = knl_mtx_tab[*(int *)(tcb->sp + 4)];
    if (p_knl_mtx->mtxatr != 2) {
      return;
    }
    iVar3 = 1;
    for (pbVar4 = p_knl_mtx->wq; *pbVar4 == 0; pbVar4 = pbVar4 + 1) {
      iVar3 = iVar3 + 1;
    }
    if (p_knl_mtx->pri == iVar3) break;
    param_1 = (uint)p_knl_mtx->owner;
    p_knl_mtx->pri = (sbyte)iVar3;
    tcb = knl_tsk_tab[param_1];
  }
  return;
}


// ===== knl_tick_task_timeouts @ 201540c4 (492 bytes)

/* Per tick: walks the task time-out wheel slot 0x20800400[tick_lo & tmo_mask], unlinks every TCB
   whose tmo_due is now and releases it (with E_TMOUT; mutex waits adjust the owner's priority)
   [fact for the wheel walk] */

code * knl_tick_task_timeouts(void)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  knl_mtx *p_knl_mtx;
  uint uVar5;
  byte *pbVar6;
  knl_tcb *tcb;
  code *tskid;
  uint knl_sys_tick_lo_val;
  
  knl_sys_tick_lo_val = knl_sys.tick_lo;
  pcVar4 = (code *)0x208003e0;
  uVar5 = knl_sys.tick_lo & knl_sys.tmo_mask;
  do {
    tskid = (code *)(uint)(byte)(&DAT_20800400)[uVar5];
    if (tskid == (code *)0x0) {
      return pcVar4;
    }
    tcb = knl_tsk_tab[(int)tskid];
    pbVar6 = &tcb->tmo_prev;
    while (tcb->tmo_due != knl_sys_tick_lo_val) {
      if (tskid == (code *)(uint)*pbVar6) {
        return (code *)(uint)*pbVar6;
      }
      tskid = (code *)(uint)tcb->tmo_next;
      tcb = knl_tsk_tab[(int)tskid];
    }
    pbVar6 = &DAT_20800400 + (tcb->tmo_due & (uint)knl_sys.tmo_mask);
    bVar1 = tcb->tmo_prev;
    if ((code *)(uint)bVar1 == tskid) {
      *pbVar6 = 0;
    }
    else {
      bVar2 = tcb->tmo_next;
      if ((code *)(uint)*pbVar6 == tskid) {
        *pbVar6 = bVar2;
      }
      knl_tsk_tab[bVar2]->tmo_prev = bVar1;
      knl_tsk_tab[(int)(uint)bVar1]->tmo_next = bVar2;
    }
    bVar1 = tcb->state;
    tcb->state = 0x10;
    if ((bVar1 & 0xf0) == 0x30) {
      *(undefined4 *)tcb->sp = 0;
    }
    else {
      *(undefined4 *)tcb->sp = 0xffffffce;
      if (0x4f < bVar1) {
        knl_queue_remove(tcb,(uint)tskid);
        if ((bVar1 & 0xfc) == 0x94) {
          p_knl_mtx = knl_mtx_tab[*(int *)(tcb->sp + 4)];
          if ((p_knl_mtx->mtxatr == 2) && (tcb->pri <= p_knl_mtx->pri)) {
            FUN_20153f28(p_knl_mtx->owner);
          }
        }
        else if ((bVar1 & 0xfc) == 0x60) {
          FUN_20153dec(*(undefined4 *)(tcb->sp + 4));
        }
        else if ((bVar1 & 0xf0) == 0xc0) {
          FUN_20153b8c(*(undefined4 *)(tcb->sp + 4));
        }
      }
    }
    if (tcb->f_0x09_u8 == 0) {
      if ((int)tcb->pri < (int)knl_sys.run_pri) {
        knl_sys.dsp_pending = 1;
      }
      pbVar6 = knl_rdq + tcb->pri;
      tcb->queue = pbVar6;
      bVar1 = *pbVar6;
      bVar2 = (byte)tskid;
      if (bVar1 == 0) {
        *pbVar6 = bVar2;
        tcb->q_next = bVar2;
        tcb->q_prev = bVar2;
      }
      else {
        tcb->q_next = bVar1;
        bVar3 = knl_tsk_tab[bVar1]->q_prev;
        knl_tsk_tab[bVar1]->q_prev = bVar2;
        tcb->q_prev = bVar3;
        knl_tsk_tab[bVar3]->q_next = bVar2;
      }
    }
    pcVar4 = FUN_20156830;
    software_interrupt(0);
  } while( true );
}


// ===== FUN_201543e4 @ 201543e4 (56 bytes)

void FUN_201543e4(short *param_1,short *param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  int iVar3;
  int iVar4;
  
  iVar3 = *(int *)(param_1 + 2);
  iVar4 = *(int *)(param_2 + 2);
  *(int *)(param_3 + 2) = iVar3 + iVar4;
  sVar1 = *param_1;
  sVar2 = *param_2;
  *param_3 = sVar2 + sVar1;
  if ((uint)(iVar3 + iVar4) < *(uint *)(param_1 + 2)) {
    *param_3 = sVar2 + sVar1 + 1;
  }
  return;
}


// ===== FUN_2015441c @ 2015441c (124 bytes)

void FUN_2015441c(short *param_1,short *param_2,short *param_3)

{
  short sVar1;
  short sVar2;
  
  sVar1 = *param_2;
  sVar2 = *param_1;
  if (sVar1 <= sVar2) {
    *param_3 = 0;
  }
  if (sVar1 < sVar2) {
    param_3[2] = 0;
    param_3[3] = 0;
  }
  if (sVar2 < sVar1) {
    *param_3 = sVar1 - sVar2;
    if (*(uint *)(param_2 + 2) < *(uint *)(param_1 + 2)) {
      *param_3 = (sVar1 - sVar2) + -1;
    }
    *(int *)(param_3 + 2) = *(int *)(param_2 + 2) - *(int *)(param_1 + 2);
  }
  else if (sVar1 == sVar2) {
    if (*(uint *)(param_2 + 2) < *(uint *)(param_1 + 2)) {
      param_3[2] = 0;
      param_3[3] = 0;
    }
    else {
      *(uint *)(param_3 + 2) = *(uint *)(param_2 + 2) - *(uint *)(param_1 + 2);
    }
    return;
  }
  return;
}


// ===== knl_timeout_add @ 20154498 (112 bytes)

/* (tmout, tcb, tskid): due time = tmout + system time 0x208003C8, links the TCB into the timer
   wheel 0x20800400 (mask 0x208003E0) [fact] */

void knl_timeout_add(int tmout,knl_tcb *tcb,byte tskid)

{
  byte bVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = tmout + knl_sys.tick_lo;
  tcb->tmo_due = uVar3;
  bVar1 = (&DAT_20800400)[uVar3 & knl_sys.tmo_mask];
  if (bVar1 != 0) {
    tcb->tmo_next = bVar1;
    bVar2 = knl_tsk_tab[bVar1]->tmo_prev;
    knl_tsk_tab[bVar1]->tmo_prev = tskid;
    tcb->tmo_prev = bVar2;
    knl_tsk_tab[bVar2]->tmo_next = tskid;
    return;
  }
  (&DAT_20800400)[uVar3 & knl_sys.tmo_mask] = tskid;
  tcb->tmo_next = tskid;
  tcb->tmo_prev = tskid;
  return;
}


// ===== knl_ready_requeue @ 20154508 (28 bytes)

/* (tcb, id): knl_queue_move into the ready queue of the task's priority; itron_del_mpf / del_sem
   use it for released waiters [fact] */

void knl_ready_requeue(knl_tcb *tcb,uint tskid)

{
  knl_queue_move(knl_rdq + tcb->pri,tcb,tskid);
  return;
}


// ===== knl_release_suspended @ 20154524 (20 bytes)

/* Unlinks the woken task from the wait queue and returns without dispatch; itron_sig_sem takes this
   path when TCB +9 (suspend count) is non-zero [fact] */

code * knl_release_suspended(knl_tcb *tcb,uint tskid)

{
  knl_queue_remove(tcb,tskid);
  software_interrupt(0);
  return knl_svc_return;
}


// ===== FUN_20154538 @ 20154538 (72 bytes)

code * FUN_20154538(knl_tcb *tcb,byte tskid)

{
  sbyte sVar1;
  
  sVar1 = tcb->pri;
  FUN_201538d4(knl_rdq + sVar1,tcb,tskid);
  if ((int)sVar1 < (int)knl_sys.run_pri) {
    software_interrupt(0);
    return knl_dispatch;
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== knl_make_ready @ 20154580 (72 bytes)

/* Appends the TCB to ready queue 0x208DC18C + priority (TCB +4) and returns the dispatcher
   0x2015655C if it beats the running priority 0x208003DF, else the plain return 0x201567F4 [fact];
   called by itron_sig_sem/set_flg/snd_mbx when a waiter is released [inference] */

code * knl_make_ready(knl_tcb *tcb,uint tskid)

{
  sbyte sVar1;
  
  sVar1 = tcb->pri;
  knl_queue_move(knl_rdq + sVar1,tcb,tskid);
  if ((int)sVar1 < (int)knl_sys.run_pri) {
    software_interrupt(0);
    return knl_dispatch;
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== knl_wait_self @ 201545c8 (20 bytes)

/* (tcb, id): removes the running task from its ready queue (knl_queue_remove), svc 0 and continues
   at knl_resched; the tail of itron_dly_tsk, sus_tsk and tslp_tsk [fact] */

code * knl_wait_self(knl_tcb *tcb,uint tskid)

{
  knl_queue_remove(tcb,tskid);
  software_interrupt(0);
  return knl_resched;
}


// ===== knl_wait_enter @ 201545dc (20 bytes)

/* Moves the running task into an object's wait queue (knl_queue_move) and returns through
   0x201566F0; the tail of every blocking itron_t* call (twai_sem, twai_flg, trcv_*, tsnd_*,
   tget_mpf, tloc_mtx) [fact for callers, inference for the role] */

code * knl_wait_enter(byte *queue,knl_tcb *tcb,uint tskid)

{
  knl_queue_move(queue,tcb,tskid);
  software_interrupt(0);
  return knl_resched;
}


// ===== knl_memcpy @ 201545f0 (28 bytes)

/* Byte copy used by the acre_* calls to copy the creation packet [fact] */

void knl_memcpy(undefined1 *param_1,undefined1 *param_2,int param_3)

{
  for (; param_3 != 0; param_3 = param_3 + -1) {
    *param_1 = *param_2;
    param_2 = param_2 + 1;
    param_1 = param_1 + 1;
  }
  return;
}


// ===== knl_freelist_free @ 2015460c (176 bytes)

/* (list, block, size): returns a block to an address-ordered free list {next, size}, merging with
   the neighbours; -17 when it overlaps a free block [fact]; the counterpart of knl_freelist_alloc
    */

undefined4 knl_freelist_free(undefined4 *param_1,undefined4 *param_2,int param_3)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  uint uVar4;
  
  uVar4 = param_3 + 7U & 0xfffffff8;
  iVar2 = 0;
  puVar3 = (undefined4 *)*param_1;
  do {
    if (puVar3 == (undefined4 *)0x0) {
LAB_2015463c:
      if ((undefined4 *)((int)param_1 + iVar2) == param_2) {
        uVar4 = uVar4 + iVar2;
        param_2 = param_1;
      }
      else {
        *param_1 = param_2;
      }
      if (puVar3 == (undefined4 *)0x0) {
        *param_2 = 0;
      }
      else {
        if ((undefined4 *)((int)param_2 + uVar4) == puVar3) {
          *param_2 = *puVar3;
          param_2[1] = puVar3[1] + uVar4;
          return 0;
        }
        *param_2 = puVar3;
      }
      param_2[1] = uVar4;
      return 0;
    }
    if (param_2 < puVar3) {
      if (puVar3 < (undefined4 *)((int)param_2 + uVar4)) {
        return 0xffffffef;
      }
      goto LAB_2015463c;
    }
    iVar2 = puVar3[1];
    puVar1 = (undefined4 *)((int)puVar3 + iVar2);
    param_1 = puVar3;
    puVar3 = (undefined4 *)*puVar3;
    if (param_2 < puVar1) {
      return 0xffffffef;
    }
  } while( true );
}


// ===== FUN_201546bc @ 201546bc (72 bytes)

uint FUN_201546bc(uint *param_1,int *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  uVar3 = 0;
  iVar2 = 0;
  for (; param_1 != (uint *)0x0; param_1 = (uint *)(*param_1 & 0xfffffffe)) {
    if ((*param_1 & 1) == 0) {
      uVar1 = param_1[1];
    }
    else {
      uVar1 = 8;
    }
    iVar2 = iVar2 + uVar1;
    if (uVar3 < uVar1) {
      uVar3 = uVar1;
    }
  }
  *param_2 = iVar2;
  return uVar3;
}


// ===== knl_stack_alloc @ 20154704 (12 bytes)

/* knl_freelist_alloc on the system pool 0x208003FC; itron_acre_tsk takes the task stack with it
   [fact] */

void knl_stack_alloc(undefined4 param_1)

{
                    /* First-fit allocator on a free list {next, size} [doc] */
  knl_freelist_alloc(0x208003fc,param_1);
  return;
}


// ===== knl_sys_free_a @ 20154710 (16 bytes)

/* knl_freelist_free on the system pool 0x208003FC (no caller in the image) [fact] */

void knl_sys_free_a(undefined4 param_1,undefined4 param_2)

{
  knl_freelist_free(0x208003fc,param_1,param_2);
  return;
}


// ===== knl_pool_alloc @ 20154720 (36 bytes)

/* WARNING: Removing unreachable block (ram,0x20154734) */
/* knl_freelist_alloc on the system pool 0x208003FC for the buffers of itron_acre_mbf / acre_mpf /
   acre_mpl [fact] */

void knl_pool_alloc(undefined4 param_1)

{
                    /* First-fit allocator on a free list {next, size} [doc] */
  knl_freelist_alloc(0x208003fc,param_1);
  return;
}


// ===== knl_pool_free @ 20154744 (40 bytes)

/* WARNING: Removing unreachable block (ram,0x2015475c) */
/* knl_freelist_free on the system pool 0x208003FC; itron_del_mpf frees the pool memory with it
   [fact] */

void knl_pool_free(undefined4 param_1,undefined4 param_2)

{
  knl_freelist_free(0x208003fc,param_1,param_2);
  return;
}


// ===== knl_sys_alloc @ 2015476c (36 bytes)

/* WARNING: Removing unreachable block (ram,0x20154780) */
/* knl_freelist_alloc on the kernel's system pool 0x208003FC; the 11 itron_acre_* calls get their
   control blocks here [fact] */

void knl_sys_alloc(undefined4 param_1)

{
                    /* First-fit allocator on a free list {next, size} [doc] */
  knl_freelist_alloc(0x208003fc,param_1);
  return;
}

