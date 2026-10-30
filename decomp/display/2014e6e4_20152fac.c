// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== os_create_dtq_named @ 2014e6e4 (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_dtq
   [inference] */

void os_create_dtq_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  itron_acre_dtq(0,&local_18);
  return;
}


// ===== knl_current_task_id @ 2014e710 (36 bytes)

/* Running task id 0x208DC18C, 0 when it is the idle task (0x201659D0 + 1); task_root [inference] */

byte knl_current_task_id(void)

{
  byte bVar1;
  
  bVar1 = knl_rdq[0];
  if (knl_rdq[0] == (byte)((char)DAT_201659d0 + 1U)) {
    bVar1 = 0;
  }
  return bVar1;
}


// ===== itron_act_tsk @ 2014e73c (292 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): TCB table 0x208DBBA0, id
   0 = self; dormant -> start like sta_tsk with exinf, else activation count +0x26 ++ (E_QOVR)
   [inference] */

code * itron_act_tsk(uint param_1)

{
  byte bVar1;
  t_ctsk *ptVar2;
  code *pcVar3;
  byte *pbVar4;
  uint uVar5;
  knl_tcb *pkVar6;
  uint uVar7;
  
  if (param_1 == 0) {
    param_1 = (uint)knl_rdq[0];
  }
  if (DAT_201659d0 < param_1) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  pkVar6 = knl_tsk_tab[param_1];
  if (pkVar6 == (knl_tcb *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (pkVar6->state == 0) {
    ptVar2 = pkVar6->ctsk;
    uVar7 = ptVar2->task;
    pbVar4 = pkVar6->stk + ptVar2->stksz;
    uVar5 = ptVar2->exinf;
    *(byte **)(pbVar4 + -0x18) = pbVar4;
    *(uint *)(pbVar4 + -0x48) = uVar5;
    uVar5 = knl_sys.task_cpsr;
    if ((uVar7 & 1) != 0) {
      uVar5 = knl_sys.task_cpsr | 0x20;
    }
    *(uint *)(pbVar4 + -0xc) = uVar5;
    uVar5 = FUN_201568b8();
    *(uint *)(pbVar4 + -0xc) = uVar5 | *(uint *)(pbVar4 + -0xc);
    *(code **)(pbVar4 + -0x14) = itron_ext_tsk;
    *(uint *)(pbVar4 + -4) = uVar7;
    pkVar6->sp = (uint)(pbVar4 + -0x48);
    pkVar6->f_0x08_u8 = 0;
    pkVar6->f_0x09_u8 = 0;
    pkVar6->f_0x20_u32 = 0;
    pkVar6->state = 0x10;
    pcVar3 = (code *)FUN_20154538(pkVar6,param_1);
    return pcVar3;
  }
  bVar1 = pkVar6->act_cnt + 1;
  pkVar6->act_cnt = bVar1;
  if (bVar1 == 0) {
    pkVar6->act_cnt = 0xff;
    software_interrupt(0);
    return (code *)0xffffffd5;
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== itron_chg_pri @ 2014e884 (736 bytes)

/* (tskid, tskpri): 0 = self / initial priority, pri < 9, requeues the TCB [fact]; T23d NORTi uITRON
   4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (tskid, tskpri <= 8, 0 = initial): E_OBJ
   dormant, E_ILUSE mutex ceiling, requeues ready/wait queues [inference] */

code * itron_chg_pri(uint param_1,uint param_2)

{
  int iVar1;
  sbyte sVar2;
  byte bVar3;
  int iVar4;
  byte bVar5;
  t_ctsk *ptVar6;
  uint uVar7;
  byte *pbVar8;
  int iVar9;
  int iVar10;
  knl_mtx *pkVar11;
  knl_tcb *tcb;
  bool bVar12;
  
  bVar12 = param_1 == 0;
  if (bVar12) {
    param_1 = (uint)knl_rdq[0];
  }
  if (param_2 < 9) {
    if ((param_1 <= DAT_201659d0) && (knl_sys.ctx_isr == 0 || !bVar12)) {
      software_interrupt(0);
      ptVar6 = (t_ctsk *)(knl_tsk_tab + param_1 + 1);
      tcb = knl_tsk_tab[param_1];
      if (tcb == (knl_tcb *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      bVar5 = tcb->state;
      if (bVar5 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      if (param_2 == 0) {
        ptVar6 = tcb->ctsk;
      }
      iVar10 = (int)tcb->mtx_held;
      if (param_2 == 0) {
        param_2 = ptVar6->itskpri;
      }
      if ((iVar10 == 0) && ((bVar5 & 0xfc) != 0x94)) {
        bVar12 = true;
      }
      else {
        bVar12 = false;
      }
      bVar3 = (byte)param_2;
      if (bVar12) {
LAB_2014e9e4:
        tcb->bpri = bVar3;
        sVar2 = tcb->pri;
        tcb->pri = bVar3;
        if (bVar5 == 0x10) {
          if (tcb->f_0x09_u8 == 0) {
            knl_queue_move(knl_rdq + param_2,tcb,param_1);
            uVar7 = (uint)knl_rdq[0];
            if (((uVar7 != param_1) || ((int)param_2 < (int)knl_sys.run_pri)) &&
               ((uVar7 == param_1 || ((int)knl_sys.run_pri < (int)param_2)))) {
              if ((uVar7 == param_1) && (knl_sys.f_0x30_u8 = bVar3, (char)bVar3 != 0)) {
                knl_sys.run_pri = bVar3;
              }
              software_interrupt(0);
              return knl_svc_return;
            }
            software_interrupt(0);
            return knl_dispatch;
          }
        }
        else if (0x4f < bVar5) {
          if (tcb->queue[1] != 0xfe) {
            knl_queue_move(tcb->queue + -((int)sVar2 - (int)(char)bVar3),tcb,param_1);
          }
          bVar5 = tcb->state & 0xfc;
          if (bVar5 == 0x94) {
            pkVar11 = knl_mtx_tab[*(int *)(tcb->sp + 4)];
            if (pkVar11->mtxatr == 2) {
              iVar10 = 1;
              for (pbVar8 = pkVar11->wq; *pbVar8 == 0; pbVar8 = pbVar8 + 1) {
                iVar10 = iVar10 + 1;
              }
              if (pkVar11->pri != iVar10) {
                FUN_20153f28(pkVar11->owner);
              }
            }
          }
          else if (bVar5 == 0x60) {
            iVar10 = FUN_20153dec(*(undefined4 *)(tcb->sp + 4));
            if (iVar10 != 0) {
              software_interrupt(0);
              return knl_dispatch;
            }
          }
          else if (((tcb->state & 0xf0) == 0xc0) &&
                  (iVar10 = FUN_20153b8c(*(undefined4 *)(tcb->sp + 4)), iVar10 != 0)) {
            software_interrupt(0);
            return knl_dispatch;
          }
        }
        software_interrupt(0);
        return knl_svc_return;
      }
      if ((int)param_2 < (int)tcb->pri) {
        iVar4 = 8;
        while (iVar10 != 0) {
          pkVar11 = knl_mtx_tab[iVar10];
          iVar9 = (int)pkVar11->pri;
          if ((pkVar11->mtxatr == 3) && ((int)param_2 < iVar9)) {
            software_interrupt(0);
            return (code *)0xffffffe4;
          }
          iVar10 = (int)pkVar11->prev_held;
          bVar12 = iVar9 != 0;
          iVar1 = 0;
          if (bVar12) {
            iVar1 = iVar4 - iVar9;
          }
          if ((bVar12 && iVar4 != iVar9) && iVar1 < 0 == (bVar12 && SBORROW4(iVar4,iVar9))) {
            iVar4 = iVar9;
          }
        }
        if ((int)param_2 <= iVar4) goto LAB_2014e9e4;
      }
      tcb->bpri = bVar3;
      software_interrupt(0);
      return knl_svc_return;
    }
    knl_sys.last_ercd = -0x12;
  }
  else {
    knl_sys.last_ercd = -0x11;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_clr_flg @ 2014eb94 (132 bytes)

/* (flgid 1..0x40, clrptn): flag table 0x208DBDA4; callers pass 0 or ~ptn [fact]; T23d NORTi uITRON
   4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): flag table 0x208DBDA4 (64): flgptn &=
   clrptn [inference] */

code * itron_clr_flg(uint param_1,uint param_2)

{
  knl_flg *pkVar1;
  
  if (param_2 == 0xffffffff) {
    knl_sys.last_ercd = 0;
  }
  else {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      pkVar1 = knl_flg_tab[param_1];
      if (pkVar1 == (knl_flg *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      pkVar1->flgptn = pkVar1->flgptn & param_2;
      software_interrupt(0);
      return knl_svc_return;
    }
    knl_sys.last_ercd = -0x12;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_acre_cyc @ 2014ec30 (424 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): object table 0x208DBF64,
   max id 8; 0x20-byte block, cycatr/exinf/cychdr/cyctim/cycphs, TA_STA starts it on timer queue
   0x208003C4; id 0 = auto (E_NOID) [inference] */

uint itron_acre_cyc(uint param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 local_28 [2];
  uint local_24;
  
  if (knl_sys.ctx_isr == 0) {
    if ((param_1 == 0) || ((param_1 != 0 && (param_1 < 9)))) {
      if (param_2 != (uint *)0x0) {
        uVar1 = *param_2;
        if ((uVar1 & 2) == 0) {
          uVar1 = uVar1 & 0xfffffffe;
        }
        else {
          uVar1 = uVar1 | 1;
        }
        software_interrupt(0);
        if (param_1 == 0) {
          param_1 = 8;
          iVar2 = DAT_208dbf84;
          while (uVar4 = param_1, iVar2 != 0) {
            param_1 = param_1 - 1;
            if (param_1 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
            iVar2 = *(int *)(&DAT_208dbf64 + param_1 * 4);
          }
        }
        else {
          if (*(int *)(&DAT_208dbf64 + param_1 * 4) != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
          uVar4 = 0;
        }
        iVar2 = knl_sys_alloc(0x20);
        if (iVar2 != 0) {
          *(int *)(&DAT_208dbf64 + param_1 * 4) = iVar2;
          *(undefined1 *)(iVar2 + 8) = 0;
          *(undefined1 *)(iVar2 + 9) = 0;
          local_28[0] = 0;
          *(undefined2 *)(iVar2 + 0x10) = 0;
          *(uint *)(iVar2 + 0x14) = param_2[3];
          local_24 = param_2[4];
          if (local_24 == 0) {
            local_24 = param_2[3];
          }
          *(uint *)(iVar2 + 0x1c) = param_2[2];
          uVar3 = param_2[1];
          *(uint *)(iVar2 + 0xc) = uVar1;
          *(uint *)(iVar2 + 0x18) = uVar3;
          if ((uVar1 & 6) != 0) {
            FUN_201543e4(local_28,0x208003c4,iVar2);
            FUN_20153720(&DAT_208dbf64,iVar2,param_1);
          }
          software_interrupt(0);
          return uVar4;
        }
        software_interrupt(0);
        knl_sys.last_ercd = -5;
        return 0xfffffffb;
      }
      knl_sys.last_ercd = 0xffffffef;
    }
    else {
      knl_sys.last_ercd = 0xffffffee;
    }
  }
  else {
    knl_sys.last_ercd = 0xffffffe7;
  }
  return knl_sys.last_ercd;
}


// ===== itron_acre_dtq @ 2014edf4 (496 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBFA4,
   max id 8; id 0 = auto (E_NOID); same table as tsnd_dtq/trcv_dtq [inference] */

uint itron_acre_dtq(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_28;
  
  uVar7 = 0;
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = -0x19;
    return 0xffffffe7;
  }
  if (8 < param_1) {
    knl_sys.last_ercd = -0x12;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 8;
    while (local_28 = param_1, *(int *)(&DAT_208dbfa4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbfa4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    local_28 = 0;
  }
  iVar9 = *(int *)(param_2 + 4);
  if ((*param_2 & 1) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 7;
  }
  iVar4 = iVar6 + 0x1c;
  if (iVar9 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_2 + 8);
    if (iVar5 == 0) {
      uVar7 = iVar6 + 0x1fU & 0xfffffffc;
      iVar4 = uVar7 + iVar9 * 4;
    }
  }
  iVar1 = knl_addr_in_image(param_2);
  if (iVar1 == 0) {
    uVar8 = iVar4 + 3U & 0xfffffffc;
    iVar4 = uVar8 + 0x10;
  }
  else {
    uVar8 = 0;
  }
  piVar2 = (int *)knl_sys_alloc(iVar4);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbfa4 + param_1 * 4) = piVar2;
  if (uVar8 == 0) {
    *piVar2 = (int)param_2;
  }
  else {
    *piVar2 = (int)piVar2 + uVar8;
    knl_memcpy((int)piVar2 + uVar8,param_2,0x10);
  }
  if (uVar7 != 0) {
    iVar5 = (int)piVar2 + uVar7;
  }
  piVar2[1] = iVar5;
  piVar2[2] = iVar5;
  piVar2[3] = iVar5;
  piVar2[4] = iVar5 + iVar9 * 4;
  *(short *)(piVar2 + 5) = (short)iVar9;
  *(undefined2 *)((int)piVar2 + 0x16) = 0;
  *(undefined1 *)(piVar2 + 6) = 0;
  *(undefined1 *)((int)piVar2 + 0x19) = 0xfe;
  iVar4 = 0;
  iVar9 = iVar4;
  if (-1 < iVar6) {
    do {
      iVar4 = iVar9 + 1;
      *(undefined1 *)((int)piVar2 + iVar9 + 0x1a) = 0;
      iVar9 = iVar4;
    } while (iVar4 <= iVar6);
    if (iVar6 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014efa4;
    }
  }
  uVar3 = 0xff;
LAB_2014efa4:
  *(undefined1 *)((int)piVar2 + iVar4 + 0x1a) = uVar3;
  software_interrupt(0);
  return local_28;
}


// ===== itron_acre_flg @ 2014effc (404 bytes)

uint itron_acre_flg(uint param_1,t_cflg *pk_cflg)

{
  uint uVar1;
  int iVar2;
  knl_flg *pkVar3;
  int iVar4;
  byte extraout_r1;
  byte extraout_r1_00;
  byte bVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = -0x19;
    return 0xffffffe7;
  }
  if (0x40 < param_1) {
    knl_sys.last_ercd = -0x12;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x40;
    while (uVar7 = param_1, knl_flg_tab[param_1] != (knl_flg *)0x0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (knl_flg_tab[param_1] != (knl_flg *)0x0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar7 = 0;
  }
  if ((pk_cflg->flgatr & 1) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 7;
  }
  iVar2 = knl_addr_in_image(pk_cflg);
  if (iVar2 == 0) {
    uVar8 = uVar6 + 0xf & 0xfffffffc;
    uVar1 = uVar8;
  }
  else {
    uVar8 = 0;
    uVar1 = uVar6;
  }
  pkVar3 = (knl_flg *)knl_sys_alloc(uVar1 + 0xc);
  if (pkVar3 == (knl_flg *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return 0xfffffffb;
  }
  knl_flg_tab[param_1] = pkVar3;
  if (uVar8 == 0) {
    pkVar3->cflg = pk_cflg;
    bVar5 = extraout_r1;
  }
  else {
    pkVar3->cflg = (t_cflg *)(pkVar3->wq + (uVar8 - 9));
    knl_memcpy((t_cflg *)(pkVar3->wq + (uVar8 - 9)),pk_cflg,0xc);
    bVar5 = extraout_r1_00;
  }
  if (-1 < (int)uVar6) {
    bVar5 = 0;
  }
  pkVar3->flgptn = pk_cflg->iflgptn;
  pkVar3->flgatr = (byte)pk_cflg->flgatr;
  iVar4 = 0;
  iVar2 = iVar4;
  if (-1 < (int)uVar6) {
    do {
      iVar4 = iVar2 + 1;
      pkVar3->wq[iVar2] = bVar5;
      iVar2 = iVar4;
    } while (iVar4 <= (int)uVar6);
    if (uVar6 == 0) {
      bVar5 = 0xfe;
      goto LAB_2014f130;
    }
  }
  bVar5 = 0xff;
LAB_2014f130:
  pkVar3->wq[iVar4] = bVar5;
  software_interrupt(0);
  return uVar7;
}


// ===== itron_acre_isr @ 2014f1a8 (536 bytes)

/* create an interrupt service routine object (auto-ID counts down from 0x40) [inference] */

uint itron_acre_isr(uint param_1,t_cisr *pk_cisr)

{
  int iVar1;
  uint uVar2;
  uint *puVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  if (knl_sys.ctx_isr == 0) {
    if (param_1 < 0x41) {
      uVar2 = isr_desc_check((int)pk_cisr);
      if (uVar2 == 0) {
        software_interrupt(0);
        if (param_1 == 0) {
          param_1 = 0x40;
          while (uVar2 = param_1, (&DAT_208dc044)[param_1] != 0) {
            param_1 = param_1 - 1;
            if (param_1 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
          }
        }
        else {
          uVar2 = 0;
          if ((&DAT_208dc044)[param_1] != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
        }
        puVar3 = (uint *)knl_sys_alloc(0x14);
        if (puVar3 != (uint *)0x0) {
          pcVar4 = (code *)gic_get_handler((int)pk_cisr);
          if (pcVar4 == gic_default_handler) {
            uVar5 = knl_sys_alloc(0x58);
            if (uVar5 == 0) {
              FUN_20154790(puVar3,0x14);
              software_interrupt(0);
              knl_sys.last_ercd = -5;
              return 0xfffffffb;
            }
            knl_memcpy(uVar5,gic_default_handler,0x58);
            *(uint **)(uVar5 + 0x4c) = puVar3;
            puVar3[3] = uVar5 + 0x4c;
            gic_install_isr_stub(uVar5,(int)pk_cisr);
          }
          else {
            uVar5 = gic_get_handler((int)pk_cisr);
            piVar7 = (int *)(uVar5 + 0x4c);
            iVar6 = *piVar7;
            if (iVar6 == 0) {
              *piVar7 = (int)puVar3;
              puVar3[3] = (uint)piVar7;
            }
            else {
              for (iVar1 = *(int *)(iVar6 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
                if (*(int *)(iVar1 + 0xc) != iVar6 + 8) {
                  FUN_20154790(puVar3,0x14);
                  software_interrupt(0);
                  knl_sys.last_ercd = -0x1c;
                  return 0xffffffe4;
                }
                iVar6 = iVar1;
              }
              *(int *)(iVar6 + 8) = (int)puVar3;
              puVar3[3] = (uint)(iVar6 + 8);
            }
          }
          *puVar3 = pk_cisr->isr;
          puVar3[1] = pk_cisr->exinf;
          puVar3[2] = 0;
          puVar3[4] = pk_cisr->intno;
          (&DAT_208dc044)[param_1] = puVar3;
          software_interrupt(0);
          return uVar2;
        }
        software_interrupt(0);
        knl_sys.last_ercd = -5;
        return 0xfffffffb;
      }
    }
    else {
      uVar2 = 0xffffffee;
    }
  }
  else {
    uVar2 = 0xffffffe7;
  }
  knl_sys.last_ercd = uVar2;
  return uVar2;
}


// ===== itron_acre_mbf @ 2014f3e4 (640 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBEC4,
   max id 8; allocates the buffer (E_NOMEM); same table as tsnd_mbf/trcv_mbf [inference] */

uint itron_acre_mbf(uint param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint local_30;
  uint local_2c;
  
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = -0x19;
    return 0xffffffe7;
  }
  uVar2 = 0;
  if (param_2[1] != 0) {
    uVar2 = param_2[2];
  }
  if (param_2[1] == 0 || 0xffff < uVar2) {
    knl_sys.last_ercd = -0x11;
    return 0xffffffef;
  }
  if (8 < param_1) {
    knl_sys.last_ercd = -0x12;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 8;
    while (local_2c = param_1, *(int *)(&DAT_208dbec4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbec4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    local_2c = 0;
  }
  if ((*param_2 & 1) == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = 7;
  }
  if ((*param_2 & 4) == 0) {
    iVar9 = 1;
  }
  else {
    iVar9 = 8;
  }
  iVar1 = iVar10 + 0x18;
  iVar8 = iVar1 + iVar9 + 1;
  iVar3 = knl_addr_in_image(param_2);
  if (iVar3 == 0) {
    uVar2 = iVar1 + iVar9 + 4U & 0xfffffffc;
    iVar8 = uVar2 + 0x14;
  }
  else {
    uVar2 = 0;
  }
  local_30 = param_2[3];
  uVar11 = param_2[2];
  if (((local_30 == 0) && (uVar11 != 0)) && (local_30 = FUN_20154720(uVar11), local_30 == 0)) {
    software_interrupt(0);
    knl_sys.last_ercd = -0x21;
    return 0xffffffdf;
  }
  piVar4 = (int *)knl_sys_alloc(iVar8);
  if (piVar4 == (int *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbec4 + param_1 * 4) = piVar4;
  if (uVar2 == 0) {
    *piVar4 = (int)param_2;
  }
  else {
    *piVar4 = (int)piVar4 + uVar2;
    knl_memcpy((int)piVar4 + uVar2,param_2,0x14);
  }
  if (uVar11 == 0) {
    local_30 = 0;
  }
  piVar4[1] = local_30;
  *(undefined2 *)(piVar4 + 2) = 0;
  *(undefined2 *)((int)piVar4 + 10) = 0;
  *(short *)(piVar4 + 3) = (short)uVar11;
  *(short *)((int)piVar4 + 0xe) = (short)uVar11;
  *(short *)(piVar4 + 4) = (short)param_2[1];
  iVar8 = 0;
  iVar3 = iVar8;
  if (-1 < iVar10) {
    do {
      iVar8 = iVar3 + 1;
      *(undefined1 *)((int)piVar4 + iVar3 + 0x13) = 0;
      iVar3 = iVar8;
    } while (iVar8 <= iVar10);
    if (iVar10 == 0) {
      uVar7 = 0xfe;
      goto LAB_2014f5f8;
    }
  }
  uVar7 = 0xff;
LAB_2014f5f8:
  *(undefined1 *)((int)piVar4 + iVar8 + 0x13) = uVar7;
  puVar5 = (undefined1 *)((int)piVar4 + iVar1);
  iVar10 = 0;
  *(char *)((int)piVar4 + 0x12) = (char)iVar1;
  puVar6 = puVar5;
  if (iVar9 != 0) {
    do {
      iVar10 = iVar10 + 1;
      puVar5 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar5;
    } while (iVar10 < iVar9);
  }
  if (iVar9 == 1) {
    uVar7 = 0xfe;
  }
  else {
    uVar7 = 0xff;
  }
  *puVar5 = uVar7;
  software_interrupt(0);
  return local_2c;
}


// ===== itron_acre_mbx @ 2014f67c (544 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBEA4,
   max id 8; same table as snd_mbx/trcv_mbx [inference] */

undefined4 * itron_acre_mbx(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *local_28;
  
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = (int)&DAT_ffffffe7;
    return (undefined4 *)&DAT_ffffffe7;
  }
  if (&SupervisorCall < param_1) {
    knl_sys.last_ercd = -0x12;
    return (undefined4 *)0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == (undefined4 *)0x0) {
    if (knl_sys.f_0x0c_u32 == 0) {
      software_interrupt(0);
      return (undefined4 *)0xffffffde;
    }
    iVar5 = *(int *)(&DAT_208dbea4 + knl_sys.f_0x0c_u32 * 4);
    param_1 = (undefined4 *)knl_sys.f_0x0c_u32;
    while (iVar5 != 0) {
      param_1 = (undefined4 *)((int)param_1 + -1);
      if (param_1 == (undefined4 *)0x0) {
        software_interrupt(0);
        return (undefined4 *)0xffffffde;
      }
      iVar5 = *(int *)(&DAT_208dbea4 + (int)param_1 * 4);
    }
    knl_sys.f_0x0c_u32 = (int)param_1 - 1;
    local_28 = param_1;
  }
  else {
    if (*(int *)(&DAT_208dbea4 + (int)param_1 * 4) != 0) {
      software_interrupt(0);
      return (undefined4 *)0xffffffd7;
    }
    local_28 = (undefined4 *)0x0;
  }
  if ((*param_2 & 1) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 7;
  }
  if ((*param_2 & 2) == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = param_2[1];
  }
  iVar8 = iVar5 + 0xc;
  if (param_2[2] == 0) {
    uVar6 = iVar5 + 0xfU & 0xfffffffc;
    iVar8 = uVar6 + uVar4 * 8;
  }
  else {
    uVar6 = 0;
  }
  iVar1 = knl_addr_in_image(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar8 + 3U & 0xfffffffc;
    iVar8 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)knl_sys_alloc(iVar8);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return (undefined4 *)0xfffffffb;
  }
  iVar1 = (int)param_1 * 4;
  if (uVar6 != 0) {
    param_1 = (undefined4 *)((int)piVar2 + uVar6);
  }
  *(int **)(&DAT_208dbea4 + iVar1) = piVar2;
  *(char *)(piVar2 + 1) = (char)uVar4;
  *(char *)((int)piVar2 + 5) = (char)iVar8;
  *(char *)((int)piVar2 + 6) = (char)uVar6;
  if (uVar6 == 0) {
    param_1 = (undefined4 *)param_2[2];
  }
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    knl_memcpy((int)piVar2 + uVar7,param_2,0x10);
  }
  iVar8 = 0;
  if (0 < (int)uVar4) {
    do {
      *param_1 = 0;
      iVar8 = iVar8 + 1;
      param_1[1] = 0;
      param_1 = param_1 + 2;
    } while (iVar8 < (int)uVar4);
  }
  iVar1 = 0;
  iVar8 = iVar1;
  if (-1 < iVar5) {
    do {
      iVar1 = iVar8 + 1;
      *(undefined1 *)((int)piVar2 + iVar8 + 7) = 0;
      iVar8 = iVar1;
    } while (iVar1 <= iVar5);
    if (iVar5 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014f830;
    }
  }
  uVar3 = 0xff;
LAB_2014f830:
  *(undefined1 *)((int)piVar2 + iVar1 + 7) = uVar3;
  software_interrupt(0);
  return local_28;
}


// ===== itron_acre_mpf @ 2014f8b8 (564 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBF24,
   max id 16; E_PAR on block count/size, E_NOMEM; same table as tget_mpf/rel_mpf [inference] */

uint itron_acre_mpf(uint mpfid,t_cmpf *pk_cmpf)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  knl_mpf *pkVar4;
  int iVar5;
  byte bVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = -0x19;
    return 0xffffffe7;
  }
  uVar2 = 0x10;
  if (0x10 < mpfid) {
    knl_sys.last_ercd = -0x12;
    return 0xffffffee;
  }
  uVar7 = pk_cmpf->blksz;
  if (uVar7 != 0) {
    uVar2 = pk_cmpf->blkcnt;
  }
  if (uVar7 == 0 || uVar2 == 0) {
    knl_sys.last_ercd = -0x11;
    return 0xffffffef;
  }
  uVar7 = uVar7 + 3 & 0xfffffffc;
  if (uVar7 < 4) {
    uVar7 = 4;
  }
  software_interrupt(0);
  if (mpfid == 0) {
    mpfid = 0x10;
    while (uVar10 = mpfid, knl_mpf_tab[mpfid] != (knl_mpf *)0x0) {
      mpfid = mpfid - 1;
      if (mpfid == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (knl_mpf_tab[mpfid] != (knl_mpf *)0x0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar10 = 0;
  }
  pbVar8 = pk_cmpf->mpf;
  if ((pbVar8 == (byte *)0x0) &&
     (pbVar8 = (byte *)FUN_20154720(uVar2 * uVar7), pbVar8 == (byte *)0x0)) {
    software_interrupt(0);
    knl_sys.last_ercd = -0x21;
    return 0xffffffdf;
  }
  if ((pk_cmpf->mpfatr & 1) == 0) {
    uVar9 = 0;
  }
  else {
    uVar9 = 7;
  }
  iVar3 = knl_addr_in_image(pk_cmpf);
  if (iVar3 == 0) {
    uVar11 = uVar9 + 0x17 & 0xfffffffc;
    uVar1 = uVar11;
  }
  else {
    uVar11 = 0;
    uVar1 = uVar9;
  }
  pkVar4 = (knl_mpf *)knl_sys_alloc(uVar1 + 0x14);
  if (pkVar4 == (knl_mpf *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return 0xfffffffb;
  }
  knl_mpf_tab[mpfid] = pkVar4;
  if (uVar11 == 0) {
    pkVar4->cmpf = pk_cmpf;
  }
  else {
    pkVar4->cmpf = (t_cmpf *)(pkVar4->wq + (uVar11 - 0x12));
    knl_memcpy((t_cmpf *)(pkVar4->wq + (uVar11 - 0x12)),pk_cmpf,0x14);
  }
  pkVar4->free_head = pbVar8;
  pkVar4->pool = pbVar8;
  pkVar4->pool_size = uVar2 * uVar7;
  pkVar4->fblkcnt = (ushort)pk_cmpf->blkcnt;
  uVar2 = pk_cmpf->blkcnt;
  while (uVar2 = uVar2 - 1, uVar2 != 0) {
    *(byte **)pbVar8 = pbVar8 + uVar7;
    pbVar8 = pbVar8 + uVar7;
  }
  pbVar8[0] = 0;
  pbVar8[1] = 0;
  pbVar8[2] = 0;
  pbVar8[3] = 0;
  iVar3 = 0;
  iVar5 = 0;
  if (-1 < (int)uVar9) {
    do {
      iVar3 = iVar5 + 1;
      pkVar4->wq[iVar5] = 0;
      iVar5 = iVar3;
    } while (iVar3 <= (int)uVar9);
    if (uVar9 == 0) {
      bVar6 = 0xfe;
      goto LAB_2014faac;
    }
  }
  bVar6 = 0xff;
LAB_2014faac:
  pkVar4->wq[iVar3] = bVar6;
  software_interrupt(0);
  return uVar10;
}


// ===== itron_acre_mpl @ 2014fb04 (520 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.800): object table 0x208DBF04,
   max id 8; pool memory from pk+8 or the kernel heap (E_NOMEM); id 0 = auto [inference] */

uint itron_acre_mpl(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 uVar3;
  knl_mpf *pkVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = -0x19;
    return 0xffffffe7;
  }
  if ((param_1 != 0) && ((param_1 == 0 || (8 < param_1)))) {
    knl_sys.last_ercd = -0x12;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 != 0) {
    if (*(int *)(&DAT_208dbf04 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar9 = 0;
  }
  else {
    param_1 = 8;
    pkVar4 = knl_mpf_tab[0];
    while (uVar9 = param_1, pkVar4 != (knl_mpf *)0x0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
      pkVar4 = *(knl_mpf **)(&DAT_208dbf04 + param_1 * 4);
    }
  }
  iVar8 = *(int *)(param_2 + 8);
  iVar10 = *(int *)(param_2 + 4);
  if ((iVar8 == 0) && (iVar8 = FUN_20154720(iVar10), iVar8 == 0)) {
    software_interrupt(0);
    knl_sys.last_ercd = -0x21;
    return 0xffffffdf;
  }
  if ((*param_2 & 1) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 7;
  }
  iVar5 = iVar6 + 0x14;
  iVar1 = knl_addr_in_image(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar6 + 0x17U & 0xfffffffc;
    iVar5 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)knl_sys_alloc(iVar5);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return 0xfffffffb;
  }
  FUN_201530e4(iVar8,iVar10);
  *(int **)(&DAT_208dbf04 + param_1 * 4) = piVar2;
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
    uVar3 = extraout_r1;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    knl_memcpy((int)piVar2 + uVar7,param_2,0x10);
    uVar3 = extraout_r1_00;
  }
  piVar2[1] = iVar8;
  piVar2[2] = iVar8;
  iVar8 = 0;
  if (-1 < iVar6) {
    uVar3 = 0;
  }
  piVar2[3] = iVar10;
  iVar10 = iVar8;
  if (-1 < iVar6) {
    do {
      iVar8 = iVar10 + 1;
      *(undefined1 *)((int)piVar2 + iVar10 + 0x10) = uVar3;
      iVar10 = iVar8;
    } while (iVar8 <= iVar6);
    if (iVar6 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014fccc;
    }
  }
  uVar3 = 0xff;
LAB_2014fccc:
  *(undefined1 *)((int)piVar2 + iVar8 + 0x10) = uVar3;
  software_interrupt(0);
  return uVar9;
}


// ===== itron_acre_mtx @ 2014fd24 (496 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBFC4,
   max id 32; E_RSATR, ceiling priority; same table as tloc_mtx/unl_mtx [inference] */

uint itron_acre_mtx(uint mtxid,t_cmtx *pk_cmtx)

{
  sbyte sVar1;
  int iVar2;
  byte bVar3;
  knl_mtx *pkVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  uVar7 = pk_cmtx->mtxatr;
  if (uVar7 == 3) {
    uVar8 = pk_cmtx->ceilpri;
  }
  else {
    uVar8 = 8;
  }
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = -0x19;
    return 0xffffffe7;
  }
  if (0x20 < mtxid) {
    knl_sys.last_ercd = -0x12;
    return 0xffffffee;
  }
  if (3 < (int)uVar7) {
    knl_sys.last_ercd = -0xb;
    return 0xfffffff5;
  }
  if ((uVar7 == 3) && ((uVar8 == 0 || (8 < uVar8)))) {
    knl_sys.last_ercd = -0x11;
    return 0xffffffef;
  }
  software_interrupt(0);
  if (mtxid == 0) {
    mtxid = 0x20;
    pkVar4 = DAT_208dc044;
    while (uVar9 = mtxid, pkVar4 != (knl_mtx *)0x0) {
      mtxid = mtxid - 1;
      if (mtxid == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
      pkVar4 = knl_mtx_tab[mtxid];
    }
  }
  else {
    if (knl_mtx_tab[mtxid] != (knl_mtx *)0x0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar9 = 0;
  }
  if (uVar7 == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 7;
  }
  iVar5 = iVar6 + 0x10;
  iVar2 = knl_addr_in_image(pk_cmtx);
  if (iVar2 == 0) {
    uVar10 = iVar6 + 0x13U & 0xfffffffc;
    iVar5 = uVar10 + 0xc;
  }
  else {
    uVar10 = 0;
  }
  pkVar4 = (knl_mtx *)knl_sys_alloc(iVar5);
  if (pkVar4 == (knl_mtx *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return 0xfffffffb;
  }
  knl_mtx_tab[mtxid] = pkVar4;
  if (uVar10 == 0) {
    pkVar4->cmtx = pk_cmtx;
  }
  else {
    pkVar4->cmtx = (t_cmtx *)(pkVar4->wq + (uVar10 - 0xc));
    knl_memcpy((t_cmtx *)(pkVar4->wq + (uVar10 - 0xc)),pk_cmtx,0xc);
  }
  if ((int)uVar7 < 2) {
    sVar1 = 0;
  }
  else {
    sVar1 = (sbyte)uVar8;
  }
  pkVar4->pri = sVar1;
  pkVar4->owner = 0;
  iVar5 = 0;
  pkVar4->prev_held = 0;
  pkVar4->mtxatr = uVar7;
  iVar2 = iVar5;
  if (-1 < iVar6) {
    do {
      iVar5 = iVar2 + 1;
      pkVar4->wq[iVar2] = 0;
      iVar2 = iVar5;
    } while (iVar5 <= iVar6);
    if (iVar6 == 0) {
      bVar3 = 0xfe;
      goto LAB_2014fe9c;
    }
  }
  bVar3 = 0xff;
LAB_2014fe9c:
  pkVar4->wq[iVar5] = bVar3;
  software_interrupt(0);
  return uVar9;
}


// ===== itron_acre_sem @ 2014ff2c (432 bytes)

uint itron_acre_sem(uint semid,t_csem *pk_csem)

{
  int iVar1;
  knl_sem *pkVar2;
  byte extraout_r1;
  byte extraout_r1_00;
  byte bVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (knl_sys.ctx_isr != 0) {
    knl_sys.last_ercd = -0x19;
    return 0xffffffe7;
  }
  if (0x40 < semid) {
    knl_sys.last_ercd = -0x12;
    return 0xffffffee;
  }
  if ((0xffff < pk_csem->maxsem) || (pk_csem->maxsem < pk_csem->isemcnt)) {
    knl_sys.last_ercd = -0x11;
    return 0xffffffef;
  }
  software_interrupt(0);
  if (semid == 0) {
    semid = 0x40;
    while (uVar6 = semid, knl_sem_tab[semid] != (knl_sem *)0x0) {
      semid = semid - 1;
      if (semid == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (knl_sem_tab[semid] != (knl_sem *)0x0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar6 = 0;
  }
  if ((pk_csem->sematr & 1) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 7;
  }
  iVar4 = iVar5 + 0xc;
  iVar1 = knl_addr_in_image(pk_csem);
  if (iVar1 == 0) {
    uVar7 = iVar5 + 0xfU & 0xfffffffc;
    iVar4 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  pkVar2 = (knl_sem *)knl_sys_alloc(iVar4);
  if (pkVar2 == (knl_sem *)0x0) {
    software_interrupt(0);
    knl_sys.last_ercd = -5;
    return 0xfffffffb;
  }
  knl_sem_tab[semid] = pkVar2;
  if (uVar7 == 0) {
    pkVar2->csem = pk_csem;
    bVar3 = extraout_r1;
  }
  else {
    pkVar2->csem = (t_csem *)(pkVar2->wq + (uVar7 - 8));
    knl_memcpy((t_csem *)(pkVar2->wq + (uVar7 - 8)),pk_csem,0x10);
    bVar3 = extraout_r1_00;
  }
  if (-1 < iVar5) {
    bVar3 = 0;
  }
  pkVar2->semcnt = (ushort)pk_csem->isemcnt;
  pkVar2->maxsem = (ushort)pk_csem->maxsem;
  iVar4 = 0;
  iVar1 = iVar4;
  if (-1 < iVar5) {
    do {
      iVar4 = iVar1 + 1;
      pkVar2->wq[iVar1] = bVar3;
      iVar1 = iVar4;
    } while (iVar4 <= iVar5);
    if (iVar5 == 0) {
      bVar3 = 0xfe;
      goto LAB_2015007c;
    }
  }
  bVar3 = 0xff;
LAB_2015007c:
  pkVar2->wq[iVar4] = bVar3;
  software_interrupt(0);
  return uVar6;
}


// ===== itron_acre_tsk @ 201500f4 (488 bytes)

/* create task, id 0 = auto-assign; TCB table 0x208DBBA0 */

uint itron_acre_tsk(uint param_1,t_ctsk *pk_ctsk)

{
  sbyte sVar1;
  int iVar2;
  knl_tcb *pkVar3;
  t_ctsk *ptVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  uint uVar9;
  
  if (knl_sys.ctx_isr == 0) {
    if (DAT_201659d0 < param_1) {
      knl_sys.last_ercd = 0xffffffee;
    }
    else {
      if (pk_ctsk->itskpri < 9) {
        software_interrupt(0);
        uVar5 = DAT_201659d0;
        if (param_1 == 0) {
          while (uVar7 = uVar5, knl_tsk_tab[uVar5] != (knl_tcb *)0x0) {
            uVar5 = uVar5 - 1;
            if (uVar5 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
          }
        }
        else {
          if (knl_tsk_tab[param_1] != (knl_tcb *)0x0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
          uVar5 = param_1;
          uVar7 = 0;
        }
        iVar2 = knl_addr_in_image(pk_ctsk);
        if (iVar2 == 0) {
          uVar8 = 0x44;
          iVar2 = 0x28;
        }
        else {
          uVar8 = 0x28;
          iVar2 = 0;
        }
        pkVar3 = (knl_tcb *)knl_sys_alloc(uVar8);
        if (pkVar3 == (knl_tcb *)0x0) {
          software_interrupt(0);
          knl_sys.last_ercd = -5;
          return 0xfffffffb;
        }
        puVar6 = (uint *)pk_ctsk->stk;
        uVar9 = pk_ctsk->stksz;
        if ((puVar6 == (uint *)0x0) && (puVar6 = (uint *)FUN_20154704(uVar9), puVar6 == (uint *)0x0)
           ) {
          FUN_20154790(pkVar3,uVar8);
          software_interrupt(0);
          knl_sys.last_ercd = -0x21;
          return 0xffffffdf;
        }
        knl_tsk_tab[uVar5] = pkVar3;
        pkVar3->state = 0;
        pkVar3->act_cnt = 0;
        pkVar3->mtx_held = 0;
        if (iVar2 == 0) {
          pkVar3->ctsk = pk_ctsk;
        }
        else {
          ptVar4 = (t_ctsk *)((int)&pkVar3->sp + iVar2);
          pkVar3->ctsk = ptVar4;
          knl_memcpy(ptVar4,pk_ctsk,0x1c);
        }
        sVar1 = (sbyte)pk_ctsk->itskpri;
        pkVar3->pri = sVar1;
        pkVar3->bpri = sVar1;
        pkVar3->stk = (byte *)puVar6;
        uVar9 = uVar9 - 0x48 >> 2;
        pkVar3->f_0x1c_u32 = 0;
        do {
          uVar9 = uVar9 - 1;
          *puVar6 = uVar5 << 0x18 | uVar5 << 0x10 | uVar5 << 8 | uVar5;
          puVar6 = puVar6 + 1;
        } while (uVar9 != 0);
        software_interrupt(0);
        if ((pk_ctsk->tskatr & 2) != 0) {
          itron_act_tsk(uVar5);
        }
        return uVar7;
      }
      knl_sys.last_ercd = 0xffffffef;
    }
  }
  else {
    knl_sys.last_ercd = 0xffffffe7;
  }
  return knl_sys.last_ercd;
}


// ===== itron_del_mpf @ 201502f4 (436 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.800): mpf table 0x208DBF24:
   releases waiting tasks with E_DLT, frees the block and the pool [inference] */

code * itron_del_mpf(uint param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  knl_tcb *tcb;
  int iVar4;
  byte *pbVar5;
  uint tskid;
  knl_mpf *pkVar6;
  
  bVar2 = false;
  if (knl_sys.ctx_isr == 0) {
    if ((param_1 != 0) && (param_1 < 0x11)) {
      software_interrupt(0);
      pkVar6 = knl_mpf_tab[param_1];
      if (pkVar6 == (knl_mpf *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (pkVar6->free_head == (byte *)0x0) {
        pbVar5 = pkVar6->wq;
        bVar1 = pkVar6->wq[0];
        while (tskid = (uint)bVar1, tskid < 0xfe) {
          while (tskid != 0) {
            tcb = knl_tsk_tab[tskid];
            *(undefined4 *)tcb->sp = 0xffffffcd;
            if ((tcb->state & 2) != 0) {
              knl_timeout_remove(tcb,tskid);
            }
            tcb->state = 0x10;
            if (tcb->f_0x09_u8 == 0) {
              FUN_20154508();
              bVar2 = (bool)(bVar2 | tcb->pri < knl_sys.run_pri);
            }
            else {
              knl_queue_remove(tcb,tskid);
            }
            tskid = (uint)*pbVar5;
          }
          pbVar5 = pbVar5 + 1;
          bVar1 = *pbVar5;
        }
      }
      if (pkVar6->cmpf->mpf == (byte *)0x0) {
        FUN_20154744(pkVar6->pool,pkVar6->pool_size);
      }
      iVar4 = 0x14;
      if (pkVar6->wq[1] < 0xfe) {
        iVar4 = 0x1b;
      }
      iVar3 = knl_addr_in_image(pkVar6->cmpf);
      if (iVar3 == 0) {
        iVar4 = (iVar4 + 3U & 0xfffffffc) + 0x14;
      }
      FUN_20154790(pkVar6,iVar4);
      knl_mpf_tab[param_1] = (knl_mpf *)0x0;
      if (bVar2) {
        software_interrupt(0);
        return knl_dispatch;
      }
      software_interrupt(0);
      return knl_svc_return;
    }
    knl_sys.last_ercd = -0x12;
  }
  else {
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_del_sem @ 201504d0 (384 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): sem table 0x208DBCA4:
   releases waiting tasks with E_DLT, frees the block [inference] */

code * itron_del_sem(uint param_1)

{
  bool bVar1;
  int iVar2;
  knl_tcb *tcb;
  int iVar3;
  uint tskid;
  byte *pbVar4;
  knl_sem *pkVar5;
  
  bVar1 = false;
  if (knl_sys.ctx_isr == 0) {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      pkVar5 = knl_sem_tab[param_1];
      if (pkVar5 == (knl_sem *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (pkVar5->semcnt == 0) {
        tskid = (uint)pkVar5->wq[0];
        pbVar4 = pkVar5->wq;
        do {
          while (tskid != 0) {
            tcb = knl_tsk_tab[tskid];
            *(undefined4 *)tcb->sp = 0xffffffcd;
            if ((tcb->state & 2) != 0) {
              knl_timeout_remove(tcb,tskid);
            }
            tcb->state = 0x10;
            if (tcb->f_0x09_u8 == 0) {
              FUN_20154508();
              bVar1 = (bool)(bVar1 | tcb->pri < knl_sys.run_pri);
            }
            else {
              knl_queue_remove(tcb,tskid);
            }
            tskid = (uint)*pbVar4;
          }
          pbVar4 = pbVar4 + 1;
          tskid = (uint)*pbVar4;
        } while (tskid < 0xfe);
      }
      iVar3 = 0xc;
      if (pkVar5->wq[1] < 0xfe) {
        iVar3 = 0x13;
      }
      iVar2 = knl_addr_in_image(pkVar5->csem);
      if (iVar2 == 0) {
        iVar3 = (iVar3 + 3U & 0xfffffffc) + 0x10;
      }
      FUN_20154790(pkVar5,iVar3);
      knl_sem_tab[param_1] = (knl_sem *)0x0;
      if (!bVar1) {
        software_interrupt(0);
        return knl_svc_return;
      }
      software_interrupt(0);
      return knl_dispatch;
    }
    knl_sys.last_ercd = -0x12;
  }
  else {
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_dis_dsp @ 20150678 (164 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): E_CTX in ISR/CPU-locked;
   sets the dispatch-disabled bits (|= 9) of 0x208003DB [inference] */

code * itron_dis_dsp(void)

{
  software_interrupt(0);
  if ((knl_sys.dsp_state & 1) == 0) {
    if ((knl_sys.ctx_isr != 0) || (knl_rdq[0] == (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      knl_sys.last_ercd = -0x19;
      return (code *)0xffffffe7;
    }
    knl_sys.dsp_state = knl_sys.dsp_state | 9;
  }
  else if (((byte)knl_sys.f_0x24_u32 & 0x80) != 0) {
    software_interrupt(0);
    knl_sys.last_ercd = -0x19;
    return (code *)0xffffffe7;
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== itron_dly_tsk @ 20150740 (172 bytes)

undefined4 itron_dly_tsk(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  knl_tcb *tcb;
  
  if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
    uVar2 = (uint)knl_rdq[0];
    if (uVar2 != ((byte)DAT_201659d0 + 1 & 0xff)) {
      tcb = knl_tsk_tab[uVar2];
      software_interrupt(0);
      if (param_1 != 0) {
        knl_timeout_add(param_1,tcb,knl_rdq[0]);
        tcb->state = 0x32;
        uVar1 = FUN_201545c8(tcb,uVar2);
        return uVar1;
      }
      software_interrupt(0);
      return 0;
    }
  }
  knl_sys.last_ercd = -0x19;
  return 0xffffffe7;
}


// ===== itron_ena_dsp @ 2015080c (184 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): clears the
   dispatch-disabled bits of 0x208003DB, dispatches when a switch is pending (0x208003D9)
   [inference] */

code * itron_ena_dsp(void)

{
  software_interrupt(0);
  if ((knl_sys.dsp_state & 1) != 0) {
    if ((knl_sys.ctx_isr != 0) || (knl_rdq[0] == (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      knl_sys.last_ercd = -0x19;
      return (code *)0xffffffe7;
    }
    if ((knl_sys.dsp_state & 0x10) == 0) {
      knl_sys.dsp_state = knl_sys.dsp_state & 0xf6;
      if ((knl_sys.dsp_state == 0) && (knl_sys.dsp_pending != 0)) {
        software_interrupt(0);
        return FUN_20156748;
      }
    }
    else {
      knl_sys.dsp_state = knl_sys.dsp_state & 0xf7;
    }
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== itron_ext_tsk @ 201508ec (264 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): current task: back to the
   initial priority, unlocks its mutexes, dormant or restarts when the activation count +0x26 > 0
   [inference] */

code * itron_ext_tsk(void)

{
  sbyte sVar1;
  byte bVar2;
  undefined4 *puVar3;
  knl_tcb *tcb;
  uint tskid;
  
  bVar2 = knl_sys.ctx_isr;
  if (knl_sys.ctx_isr == 0) {
    bVar2 = knl_sys.dsp_state;
  }
  if ((knl_sys.ctx_isr == 0 && bVar2 == 0) && (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) {
    software_interrupt(0);
    tskid = (uint)knl_rdq[0];
    tcb = knl_tsk_tab[tskid];
    sVar1 = (sbyte)tcb->ctsk->itskpri;
    tcb->pri = sVar1;
    tcb->bpri = sVar1;
    puVar3 = (undefined4 *)tcb->f_0x1c_u32;
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      *(undefined2 *)(puVar3 + 2) = 1;
      puVar3[1] = 0;
    }
    knl_queue_remove(tcb,tskid);
    if (tcb->mtx_held != 0) {
      FUN_20154930();
      tcb->mtx_held = 0;
    }
    if ((char)tcb->act_cnt < '\x01') {
      tcb->state = 0;
    }
    else {
      tcb->act_cnt = tcb->act_cnt - 1;
      FUN_20156860(tcb->stk + (tcb->ctsk->stksz - 0x48),tcb->ctsk->exinf,tcb,tskid);
    }
    software_interrupt(0);
    return FUN_2015677c;
  }
  knl_sys.last_ercd = -0x19;
  knl_sys.dsp_state = 0;
  return (code *)0x208003db;
}


// ===== FUN_201509f4 @ 201509f4 (148 bytes)

code * FUN_201509f4(undefined4 *param_1,undefined4 param_2,knl_tcb *param_3,byte param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_3->ctsk->task;
  param_1[0xc] = param_1 + 0x12;
  *param_1 = param_2;
  uVar1 = knl_sys.task_cpsr;
  if ((uVar2 & 1) != 0) {
    uVar1 = knl_sys.task_cpsr | 0x20;
  }
  param_1[0xf] = uVar1;
  uVar1 = FUN_201568b8();
  param_1[0xf] = uVar1 | param_1[0xf];
  param_1[0xd] = itron_ext_tsk;
  param_1[0x11] = uVar2;
  param_3->sp = (uint)param_1;
  param_3->f_0x08_u8 = 0;
  param_3->f_0x09_u8 = 0;
  param_3->f_0x20_u32 = 0;
  param_3->state = 0x10;
  FUN_201538d4(knl_rdq + param_3->bpri,param_3,param_4);
  software_interrupt(0);
  return FUN_2015677c;
}


// ===== itron_get_pri @ 20150aac (212 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (tskid, p_tskpri): id 0 =
   self, E_OBJ when dormant, *p = TCB+4 [inference] */

code * itron_get_pri(uint param_1,int *param_2)

{
  knl_tcb *pkVar1;
  bool bVar2;
  
  bVar2 = param_1 == 0;
  if (bVar2) {
    param_1 = (uint)knl_rdq[0];
  }
  if ((DAT_201659d0 < param_1) || (knl_sys.ctx_isr != 0 && bVar2)) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  if (knl_rdq[0] == param_1) {
    *param_2 = (int)knl_tsk_tab[knl_rdq[0]]->pri;
    return (code *)0x0;
  }
  software_interrupt(0);
  pkVar1 = knl_tsk_tab[param_1];
  if (pkVar1 != (knl_tcb *)0x0) {
    if (pkVar1->state != 0) {
      *param_2 = (int)pkVar1->pri;
      software_interrupt(0);
      return knl_svc_return;
    }
    software_interrupt(0);
    return (code *)0xffffffd7;
  }
  software_interrupt(0);
  return (code *)0xffffffd6;
}


// ===== itron_get_tid @ 20150ba0 (44 bytes)

/* (*p_tskid): current task ID [inference]; fs_task_ctx_get indexes 0x2091D0BC[1..0x100] with it
   [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (p_tskid):
   running task id or 0 (TSK_NONE) [inference] */

undefined4 itron_get_tid(uint *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)knl_rdq[0];
  if (uVar1 == ((byte)DAT_201659d0 + 1 & 0xff)) {
    uVar1 = 0;
  }
  *param_1 = uVar1;
  return 0;
}


// ===== itron_get_tim @ 20150bd4 (88 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (p_systim): SYSTIM {H
   utime, UW ltime} from 0x208003BC..C8 with carry [inference] */

code * itron_get_tim(short *param_1)

{
  short sVar1;
  uint uVar2;
  
  software_interrupt(0);
  uVar2 = knl_sys.tick_lo + knl_sys.tim_base_lo;
  *(uint *)(param_1 + 2) = uVar2;
  sVar1 = knl_sys.tim_base_hi + knl_sys.tick_hi;
  *param_1 = sVar1;
  if (uVar2 < knl_sys.tick_lo) {
    *param_1 = sVar1 + 1;
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== itron_loc_cpu @ 20150c3c (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): masks interrupts and sets
   the CPU-locked state 0x13/0x1B in 0x208003DB [inference] */

undefined4 itron_loc_cpu(void)

{
  software_interrupt(0);
  if ((knl_sys.dsp_state & 8) == 0) {
    knl_sys.dsp_state = 0x13;
  }
  else {
    knl_sys.dsp_state = 0x1b;
  }
  return 0;
}


// ===== itron_rel_mpf @ 20150c70 (320 bytes)

/* (mpfid, blk): returns a block to the pool; used by fs_work_free [inference]; T23d NORTi uITRON
   4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (mpfid, blk): mpf table 0x208DBF24, E_PAR
   if blk misaligned/outside the pool, hands the block to a waiter [inference] */

code * itron_rel_mpf(uint param_1,byte *param_2)

{
  byte bVar1;
  uint tskid;
  knl_mpf *pkVar2;
  code *pcVar3;
  byte *pbVar4;
  knl_tcb *tcb;
  
  if ((param_1 == 0) || (0x10 < param_1)) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  pkVar2 = knl_mpf_tab[param_1];
  if (pkVar2 == (knl_mpf *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (((((uint)param_2 & 3) == 0) && (pkVar2->pool <= param_2)) &&
     (param_2 < pkVar2->pool + pkVar2->pool_size)) {
    if (pkVar2->free_head == (byte *)0x0) {
      pbVar4 = pkVar2->wq;
      bVar1 = pkVar2->wq[0];
      while (tskid = (uint)bVar1, tskid < 0xfe) {
        if (tskid != 0) {
          tcb = knl_tsk_tab[tskid];
          **(undefined4 **)(tcb->sp + 0xc) = param_2;
          if ((tcb->state & 2) != 0) {
            knl_timeout_remove(tcb,tskid);
          }
          tcb->state = 0x10;
          if (tcb->f_0x09_u8 != 0) {
            pcVar3 = (code *)knl_release_suspended();
            return pcVar3;
          }
          pcVar3 = (code *)knl_make_ready(tcb,tskid);
          return pcVar3;
        }
        pbVar4 = pbVar4 + 1;
        bVar1 = *pbVar4;
      }
    }
    *(byte **)param_2 = pkVar2->free_head;
    pkVar2->free_head = param_2;
    pkVar2->fblkcnt = pkVar2->fblkcnt + 1;
    software_interrupt(0);
    return knl_svc_return;
  }
  software_interrupt(0);
  return (code *)0xffffffef;
}


// ===== itron_rot_rdq @ 20150dcc (276 bytes)

/* (tskpri): 0 = own priority, 1..8: rotates the ready queue 0x208DC18C[pri] and dispatches [fact];
   T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (tskpri <= 8, 0 = own
   priority): rotates the ready queue 0x208DC18C[pri], E_PAR [inference] */

code * itron_rot_rdq(uint param_1)

{
  knl_tcb *pkVar1;
  uint uVar2;
  byte *pbVar3;
  
  if (param_1 == 0) {
    if (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U)) {
      software_interrupt(0);
      uVar2 = (uint)knl_rdq[0];
      pkVar1 = knl_tsk_tab[uVar2];
      if ((int)pkVar1->bpri == (int)knl_sys.run_pri) {
        pbVar3 = pkVar1->queue;
      }
      else {
        pbVar3 = knl_rdq + pkVar1->bpri;
        uVar2 = (uint)*pbVar3;
        if (uVar2 == 0) {
          software_interrupt(0);
          return knl_svc_return;
        }
        pkVar1 = knl_tsk_tab[uVar2];
      }
      if (pkVar1->q_next == uVar2) {
        software_interrupt(0);
        return knl_svc_return;
      }
      *pbVar3 = pkVar1->q_next;
      software_interrupt(0);
      return knl_dispatch;
    }
  }
  else if (param_1 < 9) {
    software_interrupt(0);
    uVar2 = (uint)knl_rdq[param_1];
    if (((uVar2 != 0) && (knl_tsk_tab[uVar2]->q_next != uVar2)) &&
       (knl_rdq[param_1] = knl_tsk_tab[uVar2]->q_next, (int)param_1 <= (int)knl_sys.run_pri)) {
      software_interrupt(0);
      return knl_dispatch;
    }
    software_interrupt(0);
    return knl_svc_return;
  }
  knl_sys.last_ercd = -0x11;
  return (code *)0xffffffef;
}


// ===== itron_set_flg @ 20150f00 (704 bytes)

code * itron_set_flg(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint *extraout_r2;
  knl_tcb *pkVar8;
  uint uVar9;
  knl_flg *pkVar10;
  byte *pbVar11;
  bool bVar12;
  
  if (param_2 == 0) {
    knl_sys.last_ercd = 0;
  }
  else {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      pkVar10 = knl_flg_tab[param_1];
      if (pkVar10 == (knl_flg *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      for (pbVar11 = pkVar10->wq; uVar9 = (uint)*pbVar11, uVar9 == 0; pbVar11 = pbVar11 + 1) {
      }
      if (0xfd < uVar9) {
        pkVar10->flgptn = pkVar10->flgptn | param_2;
        software_interrupt(0);
        return knl_svc_return;
      }
      pkVar8 = knl_tsk_tab[uVar9];
      uVar6 = (uint)pkVar8->q_prev;
      bVar12 = uVar6 == uVar9;
      if (bVar12) {
        uVar6 = (uint)pkVar10->flgatr;
      }
      if (!bVar12 || (uVar6 & 2) != 0) {
        bVar12 = false;
        param_2 = param_2 | pkVar10->flgptn;
LAB_20150fa4:
        pkVar8 = knl_tsk_tab[*pbVar11];
        bVar1 = pkVar8->q_prev;
        uVar9 = (uint)*pbVar11;
        do {
          bVar2 = pkVar8->state;
          bVar3 = pkVar8->q_next;
          uVar6 = *(uint *)(pkVar8->sp + 8);
          if ((bVar2 & 1) == 0) {
            if ((uVar6 & ~param_2) == 0) goto LAB_2015109c;
          }
          else if ((uVar6 & param_2) != 0) {
LAB_2015109c:
            **(uint **)(pkVar8->sp + 0xc) = param_2;
            if ((bVar2 & 2) != 0) {
              knl_timeout_remove(pkVar8,uVar9);
            }
            pkVar8->state = 0x10;
            if (pkVar8->f_0x09_u8 == 0) {
              iVar5 = (int)pkVar8->pri;
              if (iVar5 < knl_sys.run_pri) {
                bVar12 = (bool)(bVar12 | iVar5 < knl_sys.run_pri);
              }
              knl_queue_move(knl_rdq + iVar5,pkVar8,uVar9);
            }
            else {
              knl_queue_remove(pkVar8,uVar9);
            }
            if ((bVar2 & 4) != 0) {
              pkVar10->flgptn = 0;
              if (!bVar12) {
                software_interrupt(0);
                return knl_svc_return;
              }
              software_interrupt(0);
              return knl_dispatch;
            }
          }
          if (bVar1 == uVar9) goto LAB_2015116c;
          pkVar8 = knl_tsk_tab[bVar3];
          uVar9 = (uint)bVar3;
        } while( true );
      }
      bVar1 = pkVar8->state;
      if ((bVar1 & 1) == 0) {
        param_2 = pkVar10->flgptn | param_2;
        if ((*(uint *)(pkVar8->sp + 8) & ~param_2) != 0) goto LAB_20151030;
      }
      else {
        param_2 = pkVar10->flgptn | param_2;
        if ((*(uint *)(pkVar8->sp + 8) & param_2) == 0) {
LAB_20151030:
          pkVar10->flgptn = param_2;
          software_interrupt(0);
          return knl_svc_return;
        }
      }
      puVar7 = *(uint **)(pkVar8->sp + 0xc);
      *puVar7 = param_2;
      if ((bVar1 & 4) != 0) {
        param_2 = 0;
      }
      pkVar10->flgptn = param_2;
      if ((bVar1 & 2) != 0) {
        knl_timeout_remove(pkVar8,uVar9);
        puVar7 = extraout_r2;
      }
      pkVar8->state = 0x10;
      if (pkVar8->f_0x09_u8 == 0) {
        pcVar4 = (code *)knl_make_ready(pkVar8,uVar9,puVar7,param_4);
        return pcVar4;
      }
      pcVar4 = (code *)knl_release_suspended();
      return pcVar4;
    }
    knl_sys.last_ercd = -0x12;
  }
  return (code *)knl_sys.last_ercd;
LAB_2015116c:
  do {
    pbVar11 = pbVar11 + 1;
  } while (*pbVar11 == 0);
  if (0xfd < *pbVar11) {
    pkVar10->flgptn = param_2;
    if (!bVar12) {
      software_interrupt(0);
      return knl_svc_return;
    }
    software_interrupt(0);
    return knl_dispatch;
  }
  goto LAB_20150fa4;
}


// ===== itron_sig_sem @ 201511e8 (260 bytes)

/* (semid 1..0x40): semaphore table 0x208DBCA4, E_ID / E_NOEXS, releases a waiting task or counts up
   [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): sem table
   0x208DBCA4 (64): wakes the first waiter or count++, E_QOVR at maxsem [inference] */

code * itron_sig_sem(uint param_1)

{
  ushort uVar1;
  knl_sem *pkVar2;
  code *pcVar3;
  byte *pbVar4;
  uint tskid;
  knl_tcb *tcb;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  pkVar2 = knl_sem_tab[param_1];
  if (pkVar2 == (knl_sem *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  uVar1 = pkVar2->semcnt;
  if (uVar1 == 0) {
    pbVar4 = pkVar2->wq;
    do {
      tskid = (uint)*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (tskid == 0);
    if (tskid < 0xfe) {
      tcb = knl_tsk_tab[tskid];
      if ((tcb->state & 2) != 0) {
        knl_timeout_remove(tcb,tskid);
      }
      tcb->state = 0x10;
      if (tcb->f_0x09_u8 != 0) {
        pcVar3 = (code *)knl_release_suspended();
        return pcVar3;
      }
      pcVar3 = (code *)knl_make_ready(tcb,tskid);
      return pcVar3;
    }
  }
  pkVar2->semcnt = uVar1 + 1;
  if (uVar1 == pkVar2->maxsem) {
    pkVar2->semcnt = pkVar2->maxsem;
    software_interrupt(0);
    return (code *)0xffffffd5;
  }
  software_interrupt(0);
  return knl_svc_return;
}


// ===== itron_tsnd_dtq @ 20151308 (484 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (dtqid, data, tmout): dtq
   table 0x208DBFA4, hands data to a receiver or the ring buffer, E_TMOUT on polling, waits
   otherwise [inference] */

code * itron_tsnd_dtq(uint param_1,uint param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  code *pcVar3;
  uint *puVar4;
  int iVar5;
  knl_tcb *pkVar6;
  uint uVar7;
  
  if ((param_1 == 0) || (8 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    software_interrupt(0);
    iVar5 = *(int *)(&DAT_208dbfa4 + param_1 * 4);
    if (iVar5 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    if ((*(short *)(iVar5 + 0x16) == 0) && (uVar7 = (uint)*(byte *)(iVar5 + 0x18), uVar7 != 0)) {
      pkVar6 = knl_tsk_tab[uVar7];
      **(uint **)(pkVar6->sp + 0xc) = param_2;
      if ((pkVar6->state & 2) != 0) {
        knl_timeout_remove(pkVar6,uVar7);
      }
      pkVar6->state = 0x10;
      if (pkVar6->f_0x09_u8 != 0) {
        pcVar3 = (code *)knl_release_suspended();
        return pcVar3;
      }
      pcVar3 = (code *)knl_make_ready(pkVar6,uVar7);
      return pcVar3;
    }
    if (*(short *)(iVar5 + 0x16) != *(short *)(iVar5 + 0x14)) {
      puVar4 = *(uint **)(iVar5 + 8) + 1;
      **(uint **)(iVar5 + 8) = param_2;
      *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + 1;
      if (*(uint **)(iVar5 + 0x10) <= puVar4) {
        puVar4 = *(uint **)(iVar5 + 4);
      }
      *(uint **)(iVar5 + 8) = puVar4;
      software_interrupt(0);
      return knl_svc_return;
    }
    if (param_3 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
       (uVar7 = (uint)knl_rdq[0], uVar7 != ((byte)DAT_201659d0 + 1 & 0xff))) {
      pkVar6 = knl_tsk_tab[uVar7];
      if (param_3 == -1) {
        bVar1 = 100;
      }
      else {
        knl_timeout_add(param_3,pkVar6,knl_rdq[0]);
        bVar1 = 0x66;
      }
      pkVar6->state = bVar1;
      iVar2 = iVar5 + 0x1a;
      if (*(byte *)(iVar5 + 0x1b) < 0xfe) {
        iVar2 = iVar2 + knl_sys.run_pri + -1;
      }
      knl_sys.wait_arg2 = param_2;
      knl_sys.wait_id = param_1;
      pcVar3 = (code *)knl_wait_enter(iVar2,pkVar6,uVar7);
      return pcVar3;
    }
    software_interrupt(0);
    knl_sys.last_ercd = -0x19;
  }
  return (code *)knl_sys.last_ercd;
}


// ===== itron_snd_mbx @ 20151520 (324 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (mbxid, pk_msg): mbx
   table 0x208DBEA4, priority queues by msgpri (E_PAR), or wakes a receiver [inference] */

code * itron_snd_mbx(uint param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  code *pcVar3;
  int *piVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  knl_tcb *tcb;
  bool bVar9;
  
  if ((param_1 == 0) || (8 < param_1)) {
    knl_sys.last_ercd = -0x12;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  puVar6 = *(undefined4 **)(&DAT_208dbea4 + param_1 * 4);
  if (puVar6 == (undefined4 *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  pbVar2 = (byte *)((int)puVar6 + 7);
  do {
    uVar8 = (uint)*pbVar2;
    pbVar2 = pbVar2 + 1;
  } while (uVar8 == 0);
  if (0xfd < uVar8) {
    uVar8 = (uint)*(byte *)((int)puVar6 + 6);
    if (uVar8 != 0) {
      piVar4 = (int *)(uVar8 + (int)puVar6);
    }
    else {
      piVar4 = (int *)*puVar6;
    }
    uVar7 = (uint)*(byte *)(puVar6 + 1);
    if (uVar8 == 0) {
      piVar4 = (int *)piVar4[2];
    }
    if (1 < uVar7) {
      iVar5 = param_2[1];
      bVar9 = SBORROW4(uVar7,iVar5);
      iVar1 = uVar7 - iVar5;
      if (iVar5 <= (int)uVar7) {
        bVar9 = SBORROW4(iVar5,1);
        iVar1 = iVar5 + -1;
      }
      if (iVar1 < 0 != bVar9) {
        software_interrupt(0);
        return (code *)0xffffffef;
      }
      piVar4 = piVar4 + iVar5 * 2 + -2;
    }
    if (*piVar4 == 0) {
      *piVar4 = (int)param_2;
    }
    else {
      *(undefined4 **)piVar4[1] = param_2;
    }
    piVar4[1] = (int)param_2;
    *param_2 = 0;
    software_interrupt(0);
    return knl_svc_return;
  }
  tcb = knl_tsk_tab[uVar8];
  **(undefined4 **)(tcb->sp + 0xc) = param_2;
  if ((tcb->state & 2) != 0) {
    knl_timeout_remove(tcb,uVar8);
  }
  tcb->state = 0x10;
  if (tcb->f_0x09_u8 == 0) {
    pcVar3 = (code *)knl_make_ready(tcb,uVar8);
    return pcVar3;
  }
  pcVar3 = (code *)knl_release_suspended();
  return pcVar3;
}


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
  knl_tcb *pkVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    knl_sys.last_ercd = 0xffffffd7;
  }
  else {
    if (param_1 <= DAT_201659d0) {
      software_interrupt(0);
      pkVar3 = knl_tsk_tab[param_1];
      if (pkVar3 == (knl_tcb *)0x0) {
        software_interrupt(0);
        return 0xffffffd6;
      }
      if (pkVar3->state == 0) {
        uVar4 = pkVar3->ctsk->task;
        pbVar1 = pkVar3->stk + pkVar3->ctsk->stksz;
        *(byte **)(pbVar1 + -0x18) = pbVar1;
        *(uint *)(pbVar1 + -0x48) = param_2;
        uVar2 = knl_sys.task_cpsr;
        if ((uVar4 & 1) != 0) {
          uVar2 = knl_sys.task_cpsr | 0x20;
        }
        *(uint *)(pbVar1 + -0xc) = uVar2;
        uVar2 = FUN_201568b8();
        *(uint *)(pbVar1 + -0xc) = uVar2 | *(uint *)(pbVar1 + -0xc);
        *(code **)(pbVar1 + -0x14) = itron_ext_tsk;
        *(uint *)(pbVar1 + -4) = uVar4;
        pkVar3->sp = (uint)(pbVar1 + -0x48);
        pkVar3->f_0x08_u8 = 0;
        pkVar3->f_0x09_u8 = 0;
        pkVar3->f_0x20_u32 = 0;
        pkVar3->state = 0x10;
        uVar2 = FUN_20154538(pkVar3,param_1);
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
  knl_tcb *pkVar1;
  code *pcVar2;
  byte bVar3;
  
  if ((((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
      (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) || (param_1 != 0)) {
    if (param_1 <= DAT_201659d0) {
      if (param_1 == 0) {
        param_1 = (uint)knl_rdq[0];
      }
      software_interrupt(0);
      pkVar1 = knl_tsk_tab[param_1];
      if (pkVar1 == (knl_tcb *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (pkVar1->state == 0) {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      bVar3 = pkVar1->f_0x09_u8 + 1;
      pkVar1->f_0x09_u8 = bVar3;
      if (bVar3 == 0) {
        pkVar1->f_0x09_u8 = 0xff;
        software_interrupt(0);
        return (code *)0xffffffd5;
      }
      if (bVar3 != 1 || pkVar1->state != 0x10) {
        software_interrupt(0);
        return knl_svc_return;
      }
      if ((uint)knl_rdq[0] == (param_1 & 0xff)) {
        if (knl_sys.ctx_isr == 0) {
          pcVar2 = (code *)FUN_201545c8(pkVar1,param_1);
          return pcVar2;
        }
        knl_sys.dsp_pending = 1;
      }
      pcVar2 = (code *)knl_release_suspended(pkVar1,param_1);
      return pcVar2;
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

code * itron_tget_mpf(uint param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  byte *pbVar2;
  code *pcVar3;
  knl_mpf *pkVar4;
  knl_tcb *tcb;
  uint uVar5;
  
  if ((param_1 == 0) || (0x10 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    software_interrupt(0);
    pkVar4 = knl_mpf_tab[param_1];
    if (pkVar4 == (knl_mpf *)0x0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    pbVar2 = pkVar4->free_head;
    if (pbVar2 != (byte *)0x0) {
      *param_2 = pbVar2;
      pkVar4->free_head = *(byte **)pbVar2;
      pkVar4->fblkcnt = pkVar4->fblkcnt - 1;
      software_interrupt(0);
      return knl_svc_return;
    }
    if (param_3 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar5 = (uint)knl_rdq[0];
      if (uVar5 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        tcb = knl_tsk_tab[uVar5];
        if (param_3 == -1) {
          bVar1 = 0xd0;
        }
        else {
          knl_timeout_add(param_3,tcb,knl_rdq[0]);
          bVar1 = 0xd2;
        }
        tcb->state = bVar1;
        pbVar2 = pkVar4->wq;
        if (pkVar4->wq[1] < 0xfe) {
          pbVar2 = pbVar2 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_arg2 = (uint)param_2;
        knl_sys.wait_id = param_1;
        pcVar3 = (code *)knl_wait_enter(pbVar2,tcb,uVar5);
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

code * itron_tloc_mtx(uint param_1,int param_2)

{
  short sVar1;
  sbyte sVar2;
  byte bVar3;
  byte *queue;
  code *pcVar4;
  knl_mtx *pkVar5;
  knl_tcb *tcb;
  int iVar6;
  int iVar7;
  uint tskid;
  
  if ((param_1 == 0) || (0x20 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
       (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      pkVar5 = knl_mtx_tab[param_1];
      if (pkVar5 == (knl_mtx *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      tskid = (uint)knl_rdq[0];
      if (pkVar5->owner == tskid) {
        software_interrupt(0);
      }
      else {
        iVar7 = pkVar5->mtxatr;
        sVar2 = pkVar5->pri;
        iVar6 = (int)sVar2;
        tcb = knl_tsk_tab[tskid];
        if ((iVar7 != 3) || (iVar6 <= tcb->bpri)) {
          if (pkVar5->owner != 0) {
            if (param_2 == 0) {
              software_interrupt(0);
              return (code *)0xffffffce;
            }
            if (param_2 == -1) {
              bVar3 = 0x94;
            }
            else {
              knl_timeout_add(param_2,tcb,knl_rdq[0]);
              bVar3 = 0x96;
            }
            tcb->state = bVar3;
            queue = pkVar5->wq;
            if (pkVar5->wq[1] < 0xfe) {
              queue = queue + knl_sys.run_pri + -1;
            }
            knl_sys.wait_id = param_1;
            knl_queue_move(queue,tcb,tskid);
            if ((iVar7 == 2) && (knl_sys.run_pri < iVar6)) {
              pkVar5->pri = knl_sys.run_pri;
              FUN_20153f28(pkVar5->owner);
            }
            software_interrupt(0);
            return FUN_201566f0;
          }
          pkVar5->owner = knl_rdq[0];
          sVar1 = tcb->mtx_held;
          tcb->mtx_held = (short)param_1;
          pkVar5->prev_held = sVar1;
          if (iVar7 == 2) {
            pkVar5->pri = tcb->pri;
          }
          else if ((iVar7 == 3) && (iVar6 < tcb->pri)) {
            tcb->pri = sVar2;
            pcVar4 = (code *)knl_wait_enter(knl_rdq + iVar6,tcb,tskid);
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

code * itron_trcv_dtq(uint param_1,undefined4 *param_2,int param_3)

{
  byte bVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  knl_tcb *pkVar7;
  
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
      if (param_3 == 0) {
        software_interrupt(0);
        return (code *)0xffffffce;
      }
      if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
         (uVar6 = (uint)knl_rdq[0], uVar6 != ((byte)DAT_201659d0 + 1 & 0xff))) {
        pkVar7 = knl_tsk_tab[uVar6];
        if (param_3 == -1) {
          bVar1 = 0xb4;
        }
        else {
          knl_timeout_add(param_3,pkVar7,knl_rdq[0]);
          bVar1 = 0xb6;
        }
        pkVar7->state = bVar1;
        knl_sys.wait_arg2 = (uint)param_2;
        knl_sys.wait_id = param_1;
        pcVar4 = (code *)knl_wait_enter(iVar5 + 0x18,pkVar7,uVar6);
        return pcVar4;
      }
      software_interrupt(0);
      knl_sys.last_ercd = -0x19;
      return (code *)0xffffffe7;
    }
    pkVar7 = knl_tsk_tab[uVar6];
    *param_2 = *(undefined4 *)(pkVar7->sp + 0xc);
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
    pkVar7 = knl_tsk_tab[uVar6];
    puVar2 = *(undefined4 **)(iVar5 + 8) + 1;
    **(undefined4 **)(iVar5 + 8) = *(undefined4 *)(pkVar7->sp + 0xc);
    *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + 1;
    if (*(undefined4 **)(iVar5 + 0x10) <= puVar2) {
      puVar2 = *(undefined4 **)(iVar5 + 4);
    }
    *(undefined4 **)(iVar5 + 8) = puVar2;
  }
  if ((pkVar7->state & 2) != 0) {
    knl_timeout_remove(pkVar7,uVar6);
  }
  pkVar7->state = 0x10;
  if (pkVar7->f_0x09_u8 != 0) {
    pcVar4 = (code *)knl_release_suspended();
    return pcVar4;
  }
  pcVar4 = (code *)knl_make_ready(pkVar7,uVar6);
  return pcVar4;
}


// ===== FUN_201520b0 @ 201520b0 (248 bytes)

uint FUN_201520b0(int param_1,undefined1 *param_2)

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

int itron_trcv_mbf(uint param_1,uint param_2,int param_3,undefined4 param_4)

{
  sbyte sVar1;
  byte bVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  knl_tcb *pkVar6;
  uint uVar7;
  
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
    iVar5 = FUN_201520b0(iVar5,param_2,param_3,param_4,param_1,param_2,param_3);
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
    uVar7 = (uint)*pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (uVar7 == 0);
  if (uVar7 < 0xfe) {
    pkVar6 = knl_tsk_tab[uVar7];
    iVar5 = *(int *)(pkVar6->sp + 8);
    if (iVar5 != 0) {
      knl_memcpy(param_2,*(undefined4 *)(pkVar6->sp + 0xc),iVar5);
    }
    if ((pkVar6->state & 2) != 0) {
      knl_timeout_remove(pkVar6,uVar7);
    }
    pkVar6->state = 0x10;
    if (pkVar6->f_0x09_u8 == 0) {
      sVar1 = pkVar6->pri;
      knl_queue_move(knl_rdq + sVar1,pkVar6,uVar7);
      if ((int)sVar1 < (int)knl_sys.run_pri) {
        software_interrupt(0);
        return iVar5;
      }
    }
    else {
      knl_queue_remove(pkVar6,uVar7);
    }
    software_interrupt(0);
    return iVar5;
  }
  if (param_3 == 0) {
    software_interrupt(0);
    return -0x32;
  }
  if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
     (uVar7 = (uint)knl_rdq[0], uVar7 != ((byte)DAT_201659d0 + 1 & 0xff))) {
    pkVar6 = knl_tsk_tab[uVar7];
    if (param_3 == -1) {
      bVar2 = 0xb0;
    }
    else {
      knl_timeout_add(param_3,pkVar6,knl_rdq[0]);
      bVar2 = 0xb2;
    }
    pkVar6->state = bVar2;
    iVar5 = (uint)*(byte *)(iVar5 + 0x12) + iVar5;
    if (*(byte *)(iVar5 + 1) < 0xfe) {
      iVar5 = iVar5 + knl_sys.run_pri + -1;
    }
    knl_sys.wait_arg2 = param_2;
    knl_sys.wait_id = param_1;
    iVar5 = knl_wait_enter(iVar5,pkVar6,uVar7);
    return iVar5;
  }
  software_interrupt(0);
  knl_sys.last_ercd = -0x19;
  return -0x19;
}


// ===== itron_trcv_mbx @ 20152434 (400 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (mbxid, ppk_msg, tmout):
   mbx table 0x208DBEA4, takes the first queued message, E_TMOUT [inference] */

code * itron_trcv_mbx(uint param_1,int *param_2,int param_3)

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
    if (param_3 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar7 = (uint)knl_rdq[0];
      if (uVar7 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        tcb = knl_tsk_tab[uVar7];
        if (param_3 == -1) {
          bVar1 = 0xa0;
        }
        else {
          knl_timeout_add(param_3,tcb,knl_rdq[0]);
          bVar1 = 0xa2;
        }
        tcb->state = bVar1;
        iVar5 = (int)piVar6 + 7;
        if (*(byte *)(piVar6 + 2) < 0xfe) {
          iVar5 = iVar5 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_arg2 = (uint)param_2;
        knl_sys.wait_id = param_1;
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

code * itron_tslp_tsk(int param_1)

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
      if (param_1 == 0) {
        software_interrupt(0);
        return (code *)0xffffffce;
      }
      if (param_1 == -1) {
        bVar1 = 0x20;
      }
      else {
        knl_timeout_add(param_1,tcb,knl_rdq[0]);
        bVar1 = 0x22;
      }
      tcb->state = bVar1;
      pcVar2 = (code *)FUN_201545c8(tcb,uVar3);
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

code * itron_tsnd_mbf(uint param_1,uint param_2,uint param_3,int param_4)

{
  byte bVar1;
  code *pcVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  knl_tcb *pkVar6;
  uint uVar7;
  
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
    uVar7 = (uint)*pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (uVar7 == 0);
  if (0xfd < uVar7) {
    if (param_3 != 0) {
      for (pbVar3 = (byte *)(iVar5 + 0x13); *pbVar3 == 0; pbVar3 = pbVar3 + 1) {
      }
      if ((0xfd < *pbVar3) &&
         (iVar4 = FUN_20153cd4(iVar5,param_2,param_3,param_4,param_1,param_2,param_3,param_4),
         iVar4 != 0)) {
        software_interrupt(0);
        return knl_svc_return;
      }
    }
    if (param_4 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar7 = (uint)knl_rdq[0];
      if (uVar7 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        pkVar6 = knl_tsk_tab[uVar7];
        if (param_4 == -1) {
          bVar1 = 0x60;
        }
        else {
          knl_timeout_add(param_4,pkVar6,knl_rdq[0]);
          bVar1 = 0x62;
        }
        pkVar6->state = bVar1;
        iVar4 = iVar5 + 0x13;
        if (*(byte *)(iVar5 + 0x14) < 0xfe) {
          iVar4 = iVar4 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_arg3 = param_3;
        knl_sys.wait_arg2 = param_2;
        knl_sys.wait_id = param_1;
        pcVar2 = (code *)knl_wait_enter(iVar4,pkVar6,uVar7);
        return pcVar2;
      }
    }
    software_interrupt(0);
    knl_sys.last_ercd = -0x19;
    return (code *)0xffffffe7;
  }
  pkVar6 = knl_tsk_tab[uVar7];
  if (param_3 != 0) {
    knl_memcpy(*(undefined4 *)(pkVar6->sp + 0xc),param_2,param_3);
  }
  *(uint *)pkVar6->sp = param_3;
  if ((pkVar6->state & 2) != 0) {
    knl_timeout_remove(pkVar6,uVar7);
  }
  pkVar6->state = 0x10;
  if (pkVar6->f_0x09_u8 == 0) {
    pcVar2 = (code *)knl_make_ready(pkVar6,uVar7);
    return pcVar2;
  }
  pcVar2 = (code *)knl_release_suspended();
  return pcVar2;
}


// ===== itron_twai_flg @ 20152988 (496 bytes)

void * itron_twai_flg(uint param_1,uint param_2,uint param_3,uint *param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  byte *pbVar3;
  void *pvVar4;
  knl_flg *pkVar5;
  knl_tcb *tcb;
  bool bVar6;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    if (((param_2 != 0) && ((param_3 & 0xfffffffa) == 0)) && (-3 < param_5)) {
      software_interrupt(0);
      pkVar5 = knl_flg_tab[param_1];
      if (pkVar5 == (knl_flg *)0x0) {
        software_interrupt(0);
        return (void *)0xffffffd6;
      }
      if (((pkVar5->flgatr & 2) == 0) && (pkVar5->wq[0] != 0)) {
        software_interrupt(0);
        return (void *)0xffffffe4;
      }
      uVar2 = pkVar5->flgptn;
      if ((param_3 & 1) == 0) {
        if ((param_2 & ~uVar2) != 0) goto LAB_20152a7c;
      }
      else if ((uVar2 & param_2) == 0) {
LAB_20152a7c:
        if (param_5 == 0) {
          software_interrupt(0);
          return (void *)0xffffffce;
        }
        if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
           (uVar2 = (uint)knl_rdq[0], uVar2 != ((byte)DAT_201659d0 + 1 & 0xff))) {
          tcb = knl_tsk_tab[uVar2];
          if (param_5 == -1) {
            bVar1 = pkVar5->flgatr & 4 | (byte)param_3 | 0x50;
          }
          else {
            knl_timeout_add(param_5,tcb,knl_rdq[0]);
            bVar1 = pkVar5->flgatr & 4 | (byte)param_3 | 0x52;
          }
          tcb->state = bVar1;
          pbVar3 = pkVar5->wq;
          if (pkVar5->wq[1] < 0xfe) {
            pbVar3 = pbVar3 + knl_sys.run_pri + -1;
          }
          knl_sys.wait_arg3 = param_2;
          knl_sys.wait_arg2 = (uint)param_4;
          knl_sys.wait_id = param_1;
          pvVar4 = (void *)knl_wait_enter(pbVar3,tcb,uVar2);
          return pvVar4;
        }
        software_interrupt(0);
        knl_sys.last_ercd = -0x19;
        return &DAT_ffffffe7;
      }
      bVar6 = (param_3 & 4) == 0;
      *param_4 = uVar2;
      if (bVar6) {
        uVar2 = (uint)pkVar5->flgatr;
      }
      if (!bVar6 || (uVar2 & 4) != 0) {
        pkVar5->flgptn = 0;
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

code * itron_twai_sem(uint param_1,int param_2)

{
  byte bVar1;
  byte *pbVar2;
  code *pcVar3;
  knl_sem *pkVar4;
  knl_tcb *tcb;
  uint uVar5;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    software_interrupt(0);
    pkVar4 = knl_sem_tab[param_1];
    if (pkVar4 == (knl_sem *)0x0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    if (pkVar4->semcnt != 0) {
      pkVar4->semcnt = pkVar4->semcnt - 1;
      software_interrupt(0);
      return knl_svc_return;
    }
    if (param_2 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if ((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) {
      uVar5 = (uint)knl_rdq[0];
      if (uVar5 != ((byte)DAT_201659d0 + 1 & 0xff)) {
        tcb = knl_tsk_tab[uVar5];
        if (param_2 == -1) {
          bVar1 = 0x90;
        }
        else {
          knl_timeout_add(param_2,tcb,knl_rdq[0]);
          bVar1 = 0x92;
        }
        tcb->state = bVar1;
        pbVar2 = pkVar4->wq;
        if (pkVar4->wq[1] < 0xfe) {
          pbVar2 = pbVar2 + knl_sys.run_pri + -1;
        }
        knl_sys.wait_id = param_1;
        pcVar3 = (code *)knl_wait_enter(pbVar2,tcb,uVar5);
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
  knl_mtx *pkVar8;
  knl_tcb *tcb;
  
  if ((param_1 == 0) || (0x20 < param_1)) {
    knl_sys.last_ercd = -0x12;
  }
  else {
    if (((knl_sys.ctx_isr == 0) && (knl_sys.dsp_state == 0)) &&
       (knl_rdq[0] != (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      pkVar8 = knl_mtx_tab[param_1];
      if (pkVar8 == (knl_mtx *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      tskid = (uint)knl_rdq[0];
      if (pkVar8->owner != tskid) {
        software_interrupt(0);
        return (code *)0xffffffe4;
      }
      sVar2 = pkVar8->pri;
      tcb = knl_tsk_tab[tskid];
      psVar4 = &tcb->mtx_held;
      iVar7 = (int)tcb->bpri;
      sVar1 = tcb->mtx_held;
      while (sVar1 != 0) {
        if ((int)*psVar4 == param_1) {
          *psVar4 = pkVar8->prev_held;
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
      iVar7 = FUN_201547d0(pkVar8,param_1);
      if (iVar7 != 0 || bVar3) {
        software_interrupt(0);
        return FUN_201566f0;
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

