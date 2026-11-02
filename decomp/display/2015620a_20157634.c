// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== exit @ 2015620a (18 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.800): called by __rt_entry with main()s result
   (blx main; bl exit) [inference] */

uint exit(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  uint uVar2;
  int extraout_r3;
  
  __rt_lib_shutdown();
  iVar1 = _sys_exit(param_1,param_2);
  *(short *)(iVar1 + 0x1c) = (short)iVar1;
  *(short *)(extraout_r3 + 0x20) = (short)iVar1;
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  DataSynchronizationBarrier(0xf);
  coproc_moveto_Invalidate_Entire_Instruction(0);
  coproc_moveto_Instruction_cache(0,6);
  InstructionSynchronizationBarrier(0xf);
  uVar2 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar2 & 0xfffffffd);
  uVar2 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar2 & 0xffffeffa);
  return uVar2 & 0xffffeffa;
}


// ===== __default_signal_display @ 2015621c (50 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.800): writes a newline, the message and the
   extra string with _ttywrch [inference] */

undefined8 __default_signal_display(char *param_1,char *param_2)

{
  char cVar1;
  
  cVar1 = '\n';
  for (; (_ttywrch(cVar1), param_1 != (char *)0x0 && (cVar1 = *param_1, cVar1 != '\0'));
      param_1 = param_1 + 1) {
  }
  for (; (param_2 != (char *)0x0 && (*param_2 != '\0')); param_2 = param_2 + 1) {
    _ttywrch();
  }
  software_interrupt(0xab);
  return CONCAT44(&stack0xfffffff8,3);
}


// ===== _ttywrch @ 2015624e (14 bytes)

/* T23d armcc C library RVCT/ARM Compiler 5 (idiom 0.800): semihosting SYS_WRITEC (r0=3, svc 0xAB)
   of one character [inference] */

undefined8 _ttywrch(void)

{
  undefined1 local_8 [4];
  
  software_interrupt(0xab);
  return CONCAT44(local_8,3);
}


// ===== __aeabi_uidivmod @ 20156260 (48 bytes)

/* Unsigned 32-bit divide returning quotient and remainder (r0:r1): shift-subtract that joins the
   shared loop at 0x201554DC [fact]; the 71-caller divide [fact]; T23d armcc C library RVCT/ARM
   Compiler 5 (idiom 0.950): movs r2,#0 then the rsbs r3,r1,r0,lsr #n ladder jumping into the shared
   unsigned body of 0x20155480; alias __aeabi_uidiv [inference] */

longlong __aeabi_uidivmod(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  bool bVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  
  iVar3 = 0;
  uVar1 = param_2;
  if (param_2 <= param_1 >> 2) {
    if (param_2 <= param_1 >> 5) {
      if (param_2 <= param_1 >> 8) {
        if (param_1 >> 0xc < param_2) goto LAB_2015550c;
        if (param_1 >> 0x10 < param_2) goto LAB_201554dc;
        uVar1 = param_2 << 8;
        iVar3 = -0x1000000;
        if (uVar1 <= param_1 >> 0x10) {
          iVar3 = -0x10000;
          uVar1 = param_2 << 0x10;
        }
        if (param_1 >> 0xc < uVar1) goto LAB_2015550c;
        bVar4 = false;
        if (uVar1 == 0) {
          return (ulonglong)param_1 << 0x20;
        }
        do {
          if (bVar4) {
            uVar1 = uVar1 >> 8;
          }
LAB_201554dc:
          bVar4 = uVar1 <= param_1 >> 0xf;
          if (bVar4) {
            param_1 = param_1 + uVar1 * -0x8000;
          }
          bVar5 = uVar1 <= param_1 >> 0xe;
          if (bVar5) {
            param_1 = param_1 + uVar1 * -0x4000;
          }
          bVar6 = uVar1 <= param_1 >> 0xd;
          if (bVar6) {
            param_1 = param_1 + uVar1 * -0x2000;
          }
          bVar7 = uVar1 <= param_1 >> 0xc;
          if (bVar7) {
            param_1 = param_1 + uVar1 * -0x1000;
          }
          iVar3 = (((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6) * 2 +
                  (uint)bVar7;
LAB_2015550c:
          bVar4 = uVar1 <= param_1 >> 0xb;
          if (bVar4) {
            param_1 = param_1 + uVar1 * -0x800;
          }
          bVar5 = uVar1 <= param_1 >> 10;
          if (bVar5) {
            param_1 = param_1 + uVar1 * -0x400;
          }
          bVar6 = uVar1 <= param_1 >> 9;
          if (bVar6) {
            param_1 = param_1 + uVar1 * -0x200;
          }
          uVar2 = ((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6;
          bVar5 = uVar1 <= param_1 >> 8;
          if (bVar5) {
            param_1 = param_1 + uVar1 * -0x100;
          }
          iVar3 = uVar2 * 2 + (uint)bVar5;
          bVar4 = true;
        } while (CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar5));
      }
      bVar4 = uVar1 <= param_1 >> 7;
      if (bVar4) {
        param_1 = param_1 + uVar1 * -0x80;
      }
      bVar5 = uVar1 <= param_1 >> 6;
      if (bVar5) {
        param_1 = param_1 + uVar1 * -0x40;
      }
      bVar6 = uVar1 <= param_1 >> 5;
      if (bVar6) {
        param_1 = param_1 + uVar1 * -0x20;
      }
      iVar3 = ((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6;
    }
    bVar4 = uVar1 <= param_1 >> 4;
    if (bVar4) {
      param_1 = param_1 + uVar1 * -0x10;
    }
    bVar5 = uVar1 <= param_1 >> 3;
    if (bVar5) {
      param_1 = param_1 + uVar1 * -8;
    }
    bVar6 = uVar1 <= param_1 >> 2;
    if (bVar6) {
      param_1 = param_1 + uVar1 * -4;
    }
    iVar3 = ((iVar3 * 2 + (uint)bVar4) * 2 + (uint)bVar5) * 2 + (uint)bVar6;
  }
  bVar4 = uVar1 <= param_1 >> 1;
  if (bVar4) {
    param_1 = param_1 + uVar1 * -2;
  }
  uVar2 = param_1 - uVar1;
  if (uVar1 > param_1) {
    uVar2 = param_1;
  }
  return CONCAT44(uVar2,(iVar3 * 2 + (uint)bVar4) * 2 + (uint)(uVar1 <= param_1));
}


// ===== kernel_heap_init @ 201562b4 (92 bytes)

/* heap/kernel memory up to 0x20980000 */

void kernel_heap_init(void)

{
  uint gic_init_ret;
  
  gic_init_ret = gic_init();
  if (gic_init_ret == 0) {
    knl_sys.task_cpsr = 0;
    knl_sys.f_0x00_u32 = 0;
                    /* Kernel start-up called by kernel_heap_init [doc] */
    knl_sys_init(&DAT_20980000,&stack0xfffffff8);
  }
  return;
}


// ===== FUN_20156310 @ 20156310 (28 bytes)

ulonglong FUN_20156310(void)

{
  byte *pbVar1;
  bool bVar2;
  undefined4 in_stack_00000000;
  undefined1 auStack_60 [52];
  undefined1 auStack_10 [4];
  
  pbVar1 = auStack_10;
  bVar2 = knl_sys.ctx_isr == 0;
  knl_sys.ctx_isr = knl_sys.ctx_isr - 1;
  if (bVar2) {
    knl_tsk_tab[knl_rdq[0]]->sp = (uint)auStack_60;
    pbVar1 = knl_sys.isr_area;
  }
  return CONCAT44(pbVar1,in_stack_00000000) & 0xfffffff8ffffffff;
}


// ===== knl_irq_enter @ 2015632c (192 bytes)

/* IRQ_Handler entry helper: decrements the interrupt nesting count knl_sys.ctx_isr; on the
   outermost interrupt saves the running task's SP into its TCB and switches to the interrupt stack
   knl_sys.isr_area [fact] */

ulonglong knl_irq_enter(undefined4 param_1)

{
  byte *pbVar1;
  bool bVar2;
  undefined1 auStack_58 [52];
  undefined1 auStack_8 [4];
  
  pbVar1 = auStack_8;
  bVar2 = knl_sys.ctx_isr == 0;
  knl_sys.ctx_isr = knl_sys.ctx_isr - 1;
  if (bVar2) {
    knl_tsk_tab[knl_rdq[0]]->sp = (uint)auStack_58;
    pbVar1 = knl_sys.isr_area;
  }
  return CONCAT44(pbVar1,param_1) & 0xfffffff8ffffffff;
}


// ===== knl_irq_exit @ 201563ec (368 bytes)

/* Interrupt exit: svc 0, gic_irq_exit, increments the nesting count; when back at task level with
   dispatch allowed and a higher task ready (knl_rdq), saves r4-r11 of the running task and returns
   the new task's context, else the old one [fact] */

undefined8 knl_irq_exit(void)

{
  uint uVar1;
  knl_tcb *p_knl_tcb;
  byte *pbVar2;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  uint uVar3;
  int in_stack_00000010;
  uint in_stack_00000014;
  
  software_interrupt(0);
                    /* pops nesting stack, EOIR + PMR restore [doc, inference] */
  gic_irq_exit();
  knl_sys.ctx_isr = knl_sys.ctx_isr + 1;
  if (knl_sys.ctx_isr != 0) {
    return *(undefined8 *)(in_stack_00000010 + 8);
  }
  pbVar2 = knl_rdq;
  uVar1 = (uint)knl_sys.f_0x30_u8;
  if ((uVar1 != 0) && (-1 < (int)(8 - uVar1))) {
    knl_sys.f_0x36_u8 = knl_rdq[0];
  }
  if (((in_stack_00000014 & 0xc0) == 0) && (uVar1 != 0)) {
    uVar1 = (uint)knl_sys.f_0x34_u8;
    if (uVar1 == 0) {
      if ((knl_sys.dsp_state != 0) || (knl_sys.dsp_pending == 0)) goto LAB_201564f8;
      knl_sys.dsp_pending = 0;
      do {
        pbVar2 = pbVar2 + 1;
        uVar1 = (uint)*pbVar2;
      } while (uVar1 == 0);
    }
    if (uVar1 != knl_rdq[0]) {
      uVar3 = knl_tsk_tab[knl_rdq[0]]->sp;
      *(undefined4 *)(uVar3 + 0x2c) = unaff_r11;
      *(undefined4 *)(uVar3 + 0x28) = unaff_r10;
      *(undefined4 *)(uVar3 + 0x24) = unaff_r9;
      *(undefined4 *)(uVar3 + 0x20) = unaff_r8;
      *(undefined4 *)(uVar3 + 0x1c) = unaff_r7;
      *(undefined4 *)(uVar3 + 0x18) = unaff_r6;
      *(undefined4 *)(uVar3 + 0x14) = unaff_r5;
      *(undefined4 *)(uVar3 + 0x10) = unaff_r4;
      knl_rdq[0] = (byte)uVar1;
      p_knl_tcb = knl_tsk_tab[uVar1];
      goto LAB_2015650c;
    }
  }
LAB_201564f8:
  p_knl_tcb = knl_tsk_tab[knl_rdq[0]];
LAB_2015650c:
  knl_sys.f_0x30_u8 = p_knl_tcb->pri;
  if (knl_sys.f_0x30_u8 != 0) {
    knl_sys.run_pri = knl_sys.f_0x30_u8;
  }
  return *(undefined8 *)p_knl_tcb->sp;
}


// ===== knl_dispatch @ 2015655c (404 bytes)

/* Scheduler: if dispatch is enabled (0x208003D8, not CPU-locked 0x208003CC bit 7) picks the first
   non-empty ready queue 0x208DC18C.. and switches the saved context of the TCBs [fact] */

longlong knl_dispatch(void)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint in_stack_00000004;
  undefined1 auStack_38 [16];
  
  knl_sys.dsp_pending = 1;
  if (((((knl_sys.f_0x24_u32 & 0x80) == 0) && (knl_sys.ctx_isr == 0)) && (knl_sys.dsp_state == 0))
     && (knl_sys.f_0x30_u8 != 0)) {
    uVar2 = (uint)knl_sys.f_0x34_u8;
    pbVar3 = knl_rdq;
    knl_sys.f_0x34_u8 = 0;
    uVar1 = (uint)knl_rdq[0];
    if (uVar2 == 0) {
      knl_sys.dsp_pending = 0;
      do {
        pbVar3 = pbVar3 + 1;
        uVar2 = (uint)*pbVar3;
      } while (uVar2 == 0);
    }
    knl_rdq[0] = (byte)uVar2;
    if (uVar1 != uVar2) {
      knl_tsk_tab[uVar1]->sp = (uint)auStack_38;
      knl_sys.f_0x30_u8 = knl_tsk_tab[knl_rdq[0]]->pri;
      if (knl_sys.f_0x30_u8 != 0) {
        knl_sys.run_pri = knl_sys.f_0x30_u8;
      }
      return *(longlong *)knl_tsk_tab[knl_rdq[0]]->sp;
    }
    knl_sys.f_0x30_u8 = knl_tsk_tab[uVar1]->pri;
    if (knl_sys.f_0x30_u8 != 0) {
      knl_sys.run_pri = knl_sys.f_0x30_u8;
    }
  }
  return (ulonglong)(in_stack_00000004 & 0xffffff3f | knl_sys.f_0x24_u32) << 0x20;
}


// ===== knl_resched @ 201566f0 (88 bytes)

/* Dispatcher tail of the blocking service calls: picks the highest ready queue (knl_rdq), saves the
   running SP into its TCB and returns the new task's context (boot-rtos.md knl_wait_enter) [fact]
    */

longlong knl_resched(void)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint in_stack_00000004;
  undefined1 auStack_38 [16];
  
  knl_sys.dsp_pending = 1;
  uVar2 = (uint)knl_sys.f_0x34_u8;
  pbVar3 = knl_rdq;
  knl_sys.f_0x34_u8 = 0;
  uVar1 = (uint)knl_rdq[0];
  if (uVar2 == 0) {
    knl_sys.dsp_pending = 0;
    do {
      pbVar3 = pbVar3 + 1;
      uVar2 = (uint)*pbVar3;
    } while (uVar2 == 0);
  }
  knl_rdq[0] = (byte)uVar2;
  if (uVar1 == uVar2) {
    knl_sys.f_0x30_u8 = knl_tsk_tab[uVar1]->pri;
    if (knl_sys.f_0x30_u8 != 0) {
      knl_sys.run_pri = knl_sys.f_0x30_u8;
    }
    knl_sys.f_0x34_u8 = 0;
    return (ulonglong)(in_stack_00000004 & 0xffffff3f | knl_sys.f_0x24_u32) << 0x20;
  }
  knl_tsk_tab[uVar1]->sp = (uint)auStack_38;
  knl_sys.f_0x30_u8 = knl_tsk_tab[knl_rdq[0]]->pri;
  if (knl_sys.f_0x30_u8 != 0) {
    knl_sys.run_pri = knl_sys.f_0x30_u8;
  }
  return *(longlong *)knl_tsk_tab[knl_rdq[0]]->sp;
}


// ===== FUN_20156748 @ 20156748 (52 bytes)

longlong FUN_20156748(void)

{
  uint uVar1;
  uint uVar2;
  byte *pbVar3;
  uint in_stack_00000004;
  undefined1 auStack_38 [16];
  
  uVar2 = (uint)knl_sys.f_0x34_u8;
  pbVar3 = knl_rdq;
  knl_sys.f_0x34_u8 = 0;
  uVar1 = (uint)knl_rdq[0];
  if (uVar2 == 0) {
    knl_sys.dsp_pending = 0;
    do {
      pbVar3 = pbVar3 + 1;
      uVar2 = (uint)*pbVar3;
    } while (uVar2 == 0);
  }
  knl_rdq[0] = (byte)uVar2;
  if (uVar1 == uVar2) {
    knl_sys.f_0x30_u8 = knl_tsk_tab[uVar1]->pri;
    if (knl_sys.f_0x30_u8 != 0) {
      knl_sys.run_pri = knl_sys.f_0x30_u8;
    }
    return (ulonglong)(in_stack_00000004 & 0xffffff3f | knl_sys.f_0x24_u32) << 0x20;
  }
  knl_tsk_tab[uVar1]->sp = (uint)auStack_38;
  knl_sys.f_0x30_u8 = knl_tsk_tab[knl_rdq[0]]->pri;
  if (knl_sys.f_0x30_u8 != 0) {
    knl_sys.run_pri = knl_sys.f_0x30_u8;
  }
  return *(longlong *)knl_tsk_tab[knl_rdq[0]]->sp;
}


// ===== FUN_2015677c @ 2015677c (84 bytes)

undefined8 FUN_2015677c(void)

{
  byte *pbVar1;
  
  pbVar1 = knl_rdq;
  do {
    pbVar1 = pbVar1 + 1;
    knl_rdq[0] = *pbVar1;
  } while (knl_rdq[0] == 0);
  knl_sys.f_0x30_u8 = knl_tsk_tab[knl_rdq[0]]->pri;
  if (knl_sys.f_0x30_u8 != 0) {
    knl_sys.run_pri = knl_sys.f_0x30_u8;
  }
  return *(undefined8 *)knl_tsk_tab[knl_rdq[0]]->sp;
}


// ===== FUN_201567d0 @ 201567d0 (4 bytes)

void FUN_201567d0(void)

{
  return;
}


// ===== FUN_201567d4 @ 201567d4 (32 bytes)

uint FUN_201567d4(void)

{
  uint in_stack_00000004;
  
  knl_sys.f_0x24_u32 = in_stack_00000004 & 0xc0;
  return in_stack_00000004 & 0xffffff3f | 0x80;
}


// ===== knl_svc_return @ 201567f4 (32 bytes)

/* Returns from a service call with the saved PSR bits restored (0x208003CC | spsr & ~0xC0) [fact];
   the no-dispatch exit of the itron_* calls [inference] */

longlong knl_svc_return(void)

{
  uint in_stack_00000004;
  
  return (ulonglong)(knl_sys.f_0x24_u32 | in_stack_00000004 & 0xffffff3f) << 0x20;
}


// ===== FUN_20156814 @ 20156814 (28 bytes)

void FUN_20156814(void)

{
  return;
}


// ===== FUN_20156830 @ 20156830 (48 bytes)

undefined8 FUN_20156830(void)

{
  char in_NG;
  char in_ZR;
  char in_CY;
  char in_OV;
  byte in_Q;
  undefined4 in_stack_00000004;
  
  return CONCAT44(in_stack_00000004,
                  (uint)(byte)(in_NG << 4 | in_ZR << 3 | in_CY << 2 | in_OV << 1 | in_Q) << 0x1b);
}


// ===== FUN_20156860 @ 20156860 (12 bytes)

code * FUN_20156860(undefined4 *param_1,undefined4 param_2,knl_tcb *tcb,byte tskid)

{
  uint uVar1;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  uint uVar2;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  
  param_1[-1] = FUN_201509f4;
  param_1[-2] = unaff_r8;
  param_1[-3] = unaff_r7;
  param_1[-4] = unaff_r6;
  param_1[-5] = unaff_r5;
  param_1[-6] = unaff_r4;
  uVar2 = tcb->ctsk->task;
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
  tcb->sp = (uint)param_1;
  tcb->f_0x08_u8 = 0;
  tcb->f_0x09_u8 = 0;
  tcb->f_0x20_u32 = 0;
  tcb->state = 0x10;
  FUN_201538d4(knl_rdq + tcb->bpri,tcb,tskid);
  software_interrupt(0);
  return FUN_2015677c;
}


// ===== knl_int_disable @ 2015686c (12 bytes)

/* Service call return that sets the I bit in the saved PSR (0x20156878); gic_enable_irq /
   gic_disable_irq / gic_def_inh wrap their register writes with it [inference] */

code * knl_int_disable(void)

{
  software_interrupt(0);
  return knl_psr_set_i;
}


// ===== knl_psr_set_i @ 20156878 (20 bytes)

/* Service-call return helper: saved PSR with bit 7 (I) set (boot-rtos.md knl_int_disable) [fact] */

ulonglong knl_psr_set_i(void)

{
  undefined4 in_stack_00000004;
  
  return CONCAT44(in_stack_00000004,in_stack_00000004) & 0xffffffff000000c0 | 0x8000000000;
}


// ===== knl_int_restore @ 2015688c (16 bytes)

/* Service call return through 0x2015689C, which clears the I/F bits again [inference] */

undefined8 knl_int_restore(undefined4 param_1)

{
  software_interrupt(0);
  return CONCAT44(param_1,knl_psr_clear_if);
}


// ===== knl_psr_clear_if @ 2015689c (20 bytes)

/* Service-call return helper: saved PSR with the I and F bits cleared (boot-rtos.md
   knl_int_restore) [fact] */

uint knl_psr_clear_if(void)

{
  uint in_stack_00000004;
  
  return in_stack_00000004 & 0xffffff3f;
}


// ===== FUN_201568b0 @ 201568b0 (4 bytes)

void FUN_201568b0(void)

{
  return;
}


// ===== FUN_201568b4 @ 201568b4 (4 bytes)

void FUN_201568b4(void)

{
  return;
}


// ===== FUN_201568b8 @ 201568b8 (12 bytes)

code * FUN_201568b8(void)

{
  software_interrupt(0);
  return FUN_201568c4;
}


// ===== FUN_201568c4 @ 201568c4 (28 bytes)

undefined8 FUN_201568c4(void)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 in_stack_00000004;
  
  uVar1 = coproc_movefrom_Control();
  if ((uVar1 & 0x2000000) == 0) {
    uVar2 = 0;
  }
  else {
    uVar2 = 0x200;
  }
  return CONCAT44(in_stack_00000004,uVar2);
}


// ===== gic_default_handler @ 201568e0 (76 bytes)

/* WARNING: Removing unreachable block (ram,0x20156900) */
/* WARNING: Removing unreachable block (ram,0x201568ec) */
/* WARNING: Removing unreachable block (ram,0x20156924) */
/* unregistered interrupt IDs */

undefined8 gic_default_handler(undefined4 param_1,undefined4 param_2)

{
  return CONCAT44(param_2,param_1);
}


// ===== FUN_201569c0 @ 201569c0 (228 bytes)

undefined8 FUN_201569c0(uint param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  
  iVar5 = param_1 << 1;
  uVar4 = param_2 << 0xb;
  uVar2 = param_1 << 0xb | param_2 >> 0x15;
  uVar1 = (param_1 & 0x7fffffff) >> 0x13;
  if (iVar5 != 0 || param_2 != 0) {
    uVar1 = uVar1 + 0x7800;
  }
  uVar1 = (uint)((param_1 & 0x80000000) != 0) << 0x1f | uVar1 >> 1;
  if (iVar5 != 0 || param_2 != 0) {
    uVar2 = uVar2 | 0x80000000;
  }
  if (iVar5 >> 0x15 != 0) {
    if (iVar5 >> 0x15 == -1) {
      uVar1 = uVar1 | 0x40000000;
    }
    return CONCAT44(uVar2,uVar1);
  }
  if ((uVar2 & 0x80000000) == 0) {
    return CONCAT44(uVar2,uVar1);
  }
  uVar3 = uVar2 & 0x7fffffff;
  if (uVar3 == 0) {
    if ((param_2 & 0x1fffff) >> 5 == 0) {
      uVar4 = param_2 << 0x1b;
      iVar5 = 0x10;
    }
    else {
      iVar5 = 0;
    }
    if (uVar4 >> 0x18 == 0) {
      uVar4 = uVar4 << 8;
      iVar5 = iVar5 + 8;
    }
    if (uVar4 >> 0x1c == 0) {
      uVar4 = uVar4 << 4;
      iVar5 = iVar5 + 4;
    }
    if (uVar4 >> 0x1e == 0) {
      uVar4 = uVar4 << 2;
      iVar5 = iVar5 + 2;
    }
    if (-1 < (int)uVar4) {
      uVar4 = uVar4 << 1;
      iVar5 = iVar5 + 1;
    }
    return CONCAT44(uVar4,(uVar1 - 0x1f) - iVar5);
  }
  if (uVar3 >> 0x10 == 0) {
    uVar3 = uVar2 << 0x10;
    iVar5 = 0x10;
  }
  else {
    iVar5 = 0;
  }
  if (uVar3 >> 0x18 == 0) {
    uVar3 = uVar3 << 8;
    iVar5 = iVar5 + 8;
  }
  if (uVar3 >> 0x1c == 0) {
    uVar3 = uVar3 << 4;
    iVar5 = iVar5 + 4;
  }
  if (uVar3 >> 0x1e == 0) {
    uVar3 = uVar3 << 2;
    iVar5 = iVar5 + 2;
  }
  if (-1 < (int)uVar3) {
    uVar3 = uVar3 << 1;
    iVar5 = iVar5 + 1;
  }
  return CONCAT44(uVar3 | uVar4 >> (0x20U - iVar5 & 0xff),(uVar1 - iVar5) + 1);
}


// ===== FUN_20156aa4 @ 20156aa4 (696 bytes)

ulonglong FUN_20156aa4(uint param_1,uint param_2,uint param_3,uint param_4)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  uint uVar20;
  uint uVar21;
  uint uVar22;
  bool bVar23;
  bool bVar24;
  bool bVar25;
  bool bVar26;
  bool bVar27;
  
  param_1 = param_1 ^ param_4;
  uVar2 = param_1 & 0x80000000;
  uVar17 = unaff_r5 >> 0x10;
  uVar8 = unaff_r4 >> 0x10;
  uVar22 = unaff_r5 & ~(uVar17 << 0x10);
  uVar16 = unaff_r4 & ~(uVar8 << 0x10);
  uVar10 = (uint)*(byte *)((unaff_r4 >> 0x18) + 0x20156cdc);
  uVar3 = (uint)((param_2 & 1) != 0) << 0x1f | param_3 >> 1;
  iVar11 = ((0x800000 - (uVar8 * uVar10 + uVar10)) * uVar10 >> 0x13) + 2;
  uVar18 = 0x20000000 - ((unaff_r4 >> 0xd) * iVar11 + iVar11);
  uVar10 = uVar18 >> 0x10;
  uVar10 = uVar10 * iVar11 + ((uVar18 & ~(uVar10 << 0x10)) * iVar11 >> 0x10) >> 6;
  if ((param_3 & 1) == 0) {
    uVar2 = 0;
  }
  if ((param_3 & 1) != 0) {
    uVar2 = 0x80000000;
  }
  uVar19 = uVar10 * (param_2 >> 0x10) >> 0x10;
  uVar4 = uVar3 - uVar19 * uVar17;
  uVar18 = uVar19 * uVar22;
  bVar23 = uVar18 * 0x10000 <= uVar2;
  uVar2 = uVar2 + uVar18 * -0x10000;
  uVar18 = uVar18 >> 0x10;
  bVar1 = uVar4 - uVar18 < (uint)bVar23;
  bVar24 = uVar18 < uVar4 || bVar1;
  uVar5 = (uVar4 - uVar18) - (uint)!bVar23;
  uVar12 = uVar19 * uVar16;
  if (uVar18 < uVar4 || bVar1) {
    bVar24 = uVar12 * 0x10000 <= uVar5;
  }
  uVar5 = uVar5 + uVar12 * -0x10000;
  uVar18 = ((((param_2 >> 1) - uVar8 * uVar19) - (uint)(uVar3 < uVar19 * uVar17)) - (uVar12 >> 0x10)
           ) - (uint)!bVar24;
  uVar20 = uVar10 * (uVar18 >> 2) >> 0x10;
  uVar3 = uVar20 * uVar17;
  bVar23 = uVar3 * 0x80000 <= uVar2;
  uVar2 = uVar2 + uVar3 * -0x80000;
  uVar3 = uVar3 >> 0xd;
  bVar1 = uVar5 - uVar3 < (uint)bVar23;
  bVar24 = uVar3 < uVar5 || bVar1;
  uVar4 = (uVar5 - uVar3) - (uint)!bVar23;
  uVar12 = uVar8 * uVar20;
  if (uVar3 < uVar5 || bVar1) {
    bVar24 = uVar12 * 0x80000 <= uVar4;
  }
  uVar4 = uVar4 + uVar12 * -0x80000;
  uVar5 = uVar20 * uVar22;
  bVar25 = uVar5 * 8 <= uVar2;
  uVar3 = uVar5 >> 0x1d;
  bVar1 = uVar4 - uVar3 < (uint)bVar25;
  bVar23 = uVar3 < uVar4 || bVar1;
  uVar6 = (uVar4 - uVar3) - (uint)!bVar25;
  uVar13 = uVar20 * uVar16;
  if (uVar3 < uVar4 || bVar1) {
    bVar23 = uVar13 * 8 <= uVar6;
  }
  uVar6 = uVar6 + uVar13 * -8;
  uVar3 = ((((uVar18 - (uVar12 >> 0xd)) - (uint)!bVar24) - (uVar13 >> 0x1d)) - (uint)!bVar23) *
          0x4000000 | uVar6 >> 6;
  uVar13 = uVar10 * (uVar3 >> 0xf);
  uVar18 = uVar6 * 0x4000000 | uVar2 + uVar5 * -8 >> 6;
  uVar5 = uVar5 * -0x20000000;
  uVar21 = uVar13 >> 0x10;
  uVar4 = uVar18 - uVar21 * uVar17;
  uVar2 = uVar21 * uVar22;
  bVar23 = uVar2 * 0x10000 <= uVar5;
  uVar5 = uVar5 + uVar2 * -0x10000;
  uVar2 = uVar2 >> 0x10;
  bVar1 = uVar4 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar4 || bVar1;
  uVar12 = (uVar4 - uVar2) - (uint)!bVar23;
  uVar6 = uVar21 * uVar16;
  if (uVar2 < uVar4 || bVar1) {
    bVar24 = uVar6 * 0x10000 <= uVar12;
  }
  uVar12 = uVar12 + uVar6 * -0x10000;
  uVar3 = (((uVar3 - uVar8 * uVar21) - (uint)(uVar18 < uVar21 * uVar17)) - (uVar6 >> 0x10)) -
          (uint)!bVar24;
  uVar6 = uVar10 * (uVar3 >> 2) >> 0x10;
  uVar2 = uVar6 * uVar17;
  bVar23 = uVar2 * 0x80000 <= uVar5;
  uVar5 = uVar5 + uVar2 * -0x80000;
  uVar2 = uVar2 >> 0xd;
  bVar1 = uVar12 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar12 || bVar1;
  uVar18 = (uVar12 - uVar2) - (uint)!bVar23;
  uVar4 = uVar8 * uVar6;
  if (uVar2 < uVar12 || bVar1) {
    bVar24 = uVar4 * 0x80000 <= uVar18;
  }
  uVar18 = uVar18 + uVar4 * -0x80000;
  uVar12 = uVar6 * uVar22;
  bVar25 = uVar12 * 8 <= uVar5;
  uVar2 = uVar12 >> 0x1d;
  bVar1 = uVar18 - uVar2 < (uint)bVar25;
  bVar23 = uVar2 < uVar18 || bVar1;
  uVar7 = (uVar18 - uVar2) - (uint)!bVar25;
  uVar14 = uVar6 * uVar16;
  if (uVar2 < uVar18 || bVar1) {
    bVar23 = uVar14 * 8 <= uVar7;
  }
  uVar7 = uVar7 + uVar14 * -8;
  uVar9 = uVar21 * 0x400000 + uVar6 * 0x200;
  uVar18 = ((((uVar3 - (uVar4 >> 0xd)) - (uint)!bVar24) - (uVar14 >> 0x1d)) - (uint)!bVar23) *
           0x4000000 | uVar7 >> 6;
  uVar4 = uVar7 * 0x4000000 | uVar5 + uVar12 * -8 >> 6;
  uVar10 = uVar10 * (uVar18 >> 0xf);
  uVar12 = uVar12 * -0x20000000;
  uVar14 = uVar10 >> 0x10;
  uVar5 = uVar4 - uVar14 * uVar17;
  uVar3 = uVar14 * uVar22;
  bVar23 = uVar3 * 0x10000 <= uVar12;
  uVar2 = uVar3 >> 0x10;
  bVar1 = uVar5 - uVar2 < (uint)bVar23;
  bVar24 = uVar2 < uVar5 || bVar1;
  uVar7 = (uVar5 - uVar2) - (uint)!bVar23;
  uVar15 = uVar14 * uVar16;
  if (uVar2 < uVar5 || bVar1) {
    bVar24 = uVar15 * 0x10000 <= uVar7;
  }
  uVar7 = uVar7 + uVar15 * -0x10000;
  uVar10 = uVar10 >> 0x14;
  uVar5 = uVar9 + uVar10;
  uVar4 = ((((uVar18 - uVar8 * uVar14) - (uint)(uVar4 < uVar14 * uVar17)) - (uVar15 >> 0x10)) -
          (uint)!bVar24) * 0x4000 | uVar7 >> 0x12;
  uVar2 = uVar7 * 0x4000 | uVar12 + uVar3 * -0x10000 >> 0x12;
  uVar18 = uVar3 * -0x40000000;
  uVar14 = uVar14 << 0x1c;
  uVar16 = uVar16 | uVar8 << 0x10;
  uVar22 = uVar22 | uVar17 << 0x10;
  bVar1 = uVar4 - uVar16 < (uint)(uVar22 <= uVar2);
  uVar8 = uVar4;
  if (uVar16 < uVar4 || bVar1) {
    uVar8 = (uVar4 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  uVar3 = uVar3 * -0x80000000;
  bVar23 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)CARRY4(uVar18,uVar18));
  uVar2 = uVar2 * 2 + (uint)CARRY4(uVar18,uVar18);
  bVar24 = CARRY4(uVar8 * 2,(uint)bVar23);
  bVar25 = CARRY4(uVar8,uVar8) || bVar24;
  uVar17 = uVar8 * 2 + (uint)bVar23;
  bVar23 = bVar25 < (uVar16 < uVar17 || uVar17 - uVar16 < (uint)(uVar22 <= uVar2));
  if ((CARRY4(uVar8,uVar8) || bVar24) || bVar23) {
    uVar17 = (uVar17 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  bVar26 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)CARRY4(uVar3,uVar3));
  uVar2 = uVar2 * 2 + (uint)CARRY4(uVar3,uVar3);
  bVar24 = CARRY4(uVar17 * 2,(uint)bVar26);
  bVar27 = CARRY4(uVar17,uVar17) || bVar24;
  uVar3 = uVar17 * 2 + (uint)bVar26;
  bVar26 = bVar27 < (uVar16 < uVar3 || uVar3 - uVar16 < (uint)(uVar22 <= uVar2));
  if ((CARRY4(uVar17,uVar17) || bVar24) || bVar26) {
    uVar3 = (uVar3 - uVar16) - (uint)(uVar22 > uVar2);
    uVar2 = uVar2 - uVar22;
  }
  if (uVar3 != 0 || uVar2 != 0) {
    uVar14 = uVar14 | 1;
  }
  uVar2 = (((uint)(uVar16 < uVar4 || bVar1) * 2 + (uint)(bVar25 || bVar23)) * 2 +
          (uint)(bVar27 || bVar26)) * 0x10000000;
  uVar3 = uVar5 + CARRY4(uVar14,uVar2);
  iVar11 = uVar19 * 0x10000 + uVar20 * 8 + (uVar13 >> 0x1a) +
           (uint)CARRY4(uVar21 * 0x400000,uVar6 * 0x200) + (uint)CARRY4(uVar9,uVar10) +
           (uint)CARRY4(uVar5,(uint)CARRY4(uVar14,uVar2));
  if (-1 < iVar11) {
    return CONCAT44(iVar11 * 2 +
                    (uint)(CARRY4(uVar3,uVar3) ||
                          CARRY4(uVar3 * 2,(uint)CARRY4(uVar14 + uVar2,uVar14 + uVar2))),param_1) &
           0xffffffff80000000;
  }
  return CONCAT44(iVar11,param_1) & 0xffffffff80000000;
}


// ===== FUN_20156ddc @ 20156ddc (198 bytes)

undefined8 FUN_20156ddc(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint unaff_r6;
  int unaff_r11;
  bool bVar3;
  
  if ((int)param_4 < 0) {
    unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
    if ((int)param_4 < -0x3f) {
      unaff_r6 = (unaff_r6 | param_3 | (unaff_r6 | param_3) << 0x10) >> 0x10 | param_2;
      if ((int)param_4 < -0x40) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10;
      }
      param_4 = 0;
      param_3 = 0;
      param_2 = 0;
    }
    else {
      uVar2 = param_4;
      if ((int)param_4 < -0x1f) {
        unaff_r6 = unaff_r6 | param_3;
        uVar2 = param_4 + 0x20;
        param_2 = 0;
        param_3 = param_2;
      }
      uVar1 = -uVar2;
      param_4 = 0;
      if (uVar1 != 0) {
        unaff_r6 = (unaff_r6 | unaff_r6 << 0x10) >> 0x10 | param_3 << (uVar2 + 0x20 & 0xff);
        uVar2 = param_2 << (uVar2 + 0x20 & 0xff);
        param_2 = param_2 >> (uVar1 & 0xff);
        param_4 = 0;
        param_3 = param_3 >> (uVar1 & 0xff) | uVar2;
      }
    }
  }
  if (((unaff_r6 & 0x7fffffff) != 0) || ((unaff_r6 & 0x80000000) != 0)) {
    bVar3 = unaff_r11 != -1 && 0xfffffffe < param_3;
    if (unaff_r11 != -1 && 0xfffffffe < param_3) {
      bVar3 = 0xfffffffe < param_2;
      param_2 = param_2 + 1;
    }
    if (bVar3 != false) {
      param_2 = 0x80000000;
    }
    param_4 = param_4 + bVar3;
  }
  return CONCAT44(param_2,param_4 | param_1 & 0x80000000);
}


// ===== FUN_20156ea2 @ 20156ea2 (40 bytes)

void FUN_20156ea2(int *param_1,int *param_2)

{
  if ((param_1[1] & ~(*param_1 << 1)) < 0 && (param_2[1] & ~(*param_2 << 1)) < 0) {
    FUN_20156aa4(*param_1,param_1[1],param_1[2]);
    FUN_20156ddc();
  }
  return;
}


// ===== FUN_20156eca @ 20156eca (40 bytes)

void FUN_20156eca(uint *param_1,uint *param_2)

{
  if ((*param_1 & 0x40000000) == 0 && (*param_2 & 0x40000000) == 0) {
    FUN_20156ef2(*param_1,param_1[1],param_1[2]);
    FUN_20156ddc();
  }
  return;
}


// ===== FUN_20156ef2 @ 20156ef2 (580 bytes)

ulonglong FUN_20156ef2(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint unaff_r4;
  uint unaff_r5;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  uint uVar10;
  uint uVar11;
  uint uVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  bool bVar19;
  
  param_1 = param_1 ^ param_4;
  if (param_3 == 0) {
    if (unaff_r5 == 0) {
      uVar5 = unaff_r4 >> 0x10;
      uVar6 = param_2 >> 0x10;
      uVar14 = unaff_r4 & ~(uVar5 << 0x10);
      param_2 = param_2 & ~(uVar6 << 0x10);
      uVar7 = uVar14 * uVar6;
      uVar14 = param_2 * uVar14;
      param_2 = uVar5 * param_2;
      uVar3 = uVar7 * 0x10000;
      uVar1 = uVar14 + uVar3;
      uVar2 = param_2 * 0x10000;
      uVar4 = uVar1 + uVar2;
      iVar8 = uVar5 * uVar6 + (uVar7 >> 0x10) + (uint)CARRY4(uVar14,uVar3) +
              (param_2 >> 0x10) + (uint)CARRY4(uVar1,uVar2);
      if (-1 < iVar8) {
        return CONCAT44(iVar8 * 2 + (uint)CARRY4(uVar4,uVar4),param_1) & 0xffffffff80000000;
      }
      return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
    }
    uVar4 = param_2 >> 0x10;
    uVar12 = unaff_r4 >> 0x10;
    param_2 = param_2 & ~(uVar4 << 0x10);
    uVar15 = unaff_r4 & ~(uVar12 << 0x10);
    uVar5 = uVar15 * param_2;
    uVar15 = uVar4 * uVar15;
    uVar3 = param_2 * uVar12 * 0x10000;
    uVar6 = uVar5 + uVar3;
    uVar13 = unaff_r5 >> 0x10;
    uVar2 = uVar15 * 0x10000;
    uVar7 = uVar6 + uVar2;
    uVar16 = unaff_r5 & ~(uVar13 << 0x10);
    uVar9 = uVar16 * param_2;
    uVar16 = uVar4 * uVar16;
    uVar14 = param_2 * uVar13 * 0x10000;
    uVar10 = uVar9 + uVar14;
    uVar1 = uVar16 * 0x10000;
    uVar11 = uVar10 + uVar1;
    uVar14 = uVar4 * uVar13 + (param_2 * uVar13 >> 0x10) + (uint)CARRY4(uVar9,uVar14) +
             (uVar16 >> 0x10) + (uint)CARRY4(uVar10,uVar1);
    uVar1 = uVar14 + uVar7;
    iVar8 = uVar4 * uVar12 + (param_2 * uVar12 >> 0x10) + (uint)CARRY4(uVar5,uVar3) +
            (uVar15 >> 0x10) + (uint)CARRY4(uVar6,uVar2) + (uint)CARRY4(uVar14,uVar7);
    if (-1 < iVar8) {
      return CONCAT44(iVar8 * 2 +
                      (uint)(CARRY4(uVar1,uVar1) || CARRY4(uVar1 * 2,(uint)CARRY4(uVar11,uVar11))),
                      param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
  }
  if (unaff_r5 == 0) {
    uVar7 = unaff_r4 >> 0x10;
    uVar13 = param_2 >> 0x10;
    uVar9 = unaff_r4 & ~(uVar7 << 0x10);
    param_2 = param_2 & ~(uVar13 << 0x10);
    uVar4 = param_2 * uVar9;
    param_2 = uVar7 * param_2;
    uVar3 = uVar9 * uVar13 * 0x10000;
    uVar5 = uVar4 + uVar3;
    uVar15 = param_3 >> 0x10;
    uVar2 = param_2 * 0x10000;
    uVar6 = uVar5 + uVar2;
    param_3 = param_3 & ~(uVar15 << 0x10);
    uVar10 = param_3 * uVar9;
    param_3 = uVar7 * param_3;
    uVar14 = uVar9 * uVar15 * 0x10000;
    uVar11 = uVar10 + uVar14;
    uVar1 = param_3 * 0x10000;
    uVar12 = uVar11 + uVar1;
    uVar1 = uVar7 * uVar15 + (uVar9 * uVar15 >> 0x10) + (uint)CARRY4(uVar10,uVar14) +
            (param_3 >> 0x10) + (uint)CARRY4(uVar11,uVar1);
    uVar14 = uVar1 + uVar6;
    iVar8 = uVar7 * uVar13 + (uVar9 * uVar13 >> 0x10) + (uint)CARRY4(uVar4,uVar3) +
            (param_2 >> 0x10) + (uint)CARRY4(uVar5,uVar2) + (uint)CARRY4(uVar1,uVar6);
    if (-1 < iVar8) {
      return CONCAT44(iVar8 * 2 +
                      (uint)(CARRY4(uVar14,uVar14) || CARRY4(uVar14 * 2,(uint)CARRY4(uVar12,uVar12))
                            ),param_1) & 0xffffffff80000000;
    }
    return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
  }
  uVar1 = param_2 >> 0x10;
  uVar4 = unaff_r4 >> 0x10;
  uVar11 = param_2 & ~(uVar1 << 0x10);
  uVar9 = unaff_r4 & ~(uVar4 << 0x10);
  uVar5 = uVar11 * uVar4;
  uVar11 = uVar9 * uVar11;
  uVar9 = uVar1 * uVar9;
  uVar3 = uVar5 * 0x10000;
  uVar12 = uVar11 + uVar3;
  uVar15 = param_3 >> 0x10;
  uVar2 = uVar9 * 0x10000;
  uVar13 = uVar12 + uVar2;
  uVar6 = unaff_r5 >> 0x10;
  uVar16 = param_3 & ~(uVar15 << 0x10);
  uVar10 = unaff_r5 & ~(uVar6 << 0x10);
  uVar7 = uVar16 * uVar6;
  uVar16 = uVar10 * uVar16;
  uVar10 = uVar15 * uVar10;
  uVar14 = uVar7 * 0x10000;
  uVar17 = uVar16 + uVar14;
  uVar7 = uVar15 * uVar6 + (uVar7 >> 0x10) + (uint)CARRY4(uVar16,uVar14);
  iVar8 = 0;
  uVar14 = uVar10 * 0x10000;
  uVar15 = uVar17 + uVar14;
  uVar6 = uVar7 + (uVar10 >> 0x10) + (uint)CARRY4(uVar17,uVar14);
  uVar14 = uVar13 + uVar6;
  uVar2 = uVar1 * uVar4 + (uVar5 >> 0x10) + (uint)CARRY4(uVar11,uVar3) +
          (uVar9 >> 0x10) + (uint)CARRY4(uVar12,uVar2) + (uint)CARRY4(uVar13,uVar6);
  uVar4 = uVar14 + uVar15;
  uVar1 = uVar14 + uVar2 + CARRY4(uVar14,uVar15);
  bVar19 = param_3 <= param_2;
  param_2 = param_2 - param_3;
  bVar18 = param_2 == 0;
  uVar3 = 0;
  if (!bVar19) {
    uVar3 = 0xffffffff;
    iVar8 = unaff_r4 - unaff_r5;
  }
  if (!bVar18) {
    bVar19 = unaff_r4 <= unaff_r5;
    uVar7 = unaff_r5 - unaff_r4;
    bVar18 = uVar7 == 0;
  }
  if (bVar18) {
    uVar3 = 0;
  }
  if (!bVar19) {
    uVar3 = ~uVar3;
    iVar8 = iVar8 - param_2;
  }
  uVar9 = param_2 >> 0x10;
  param_2 = param_2 & ~(uVar9 << 0x10);
  uVar12 = uVar7 >> 0x10;
  uVar7 = uVar7 & ~(uVar12 << 0x10);
  uVar13 = param_2 * uVar12;
  param_2 = uVar7 * param_2;
  uVar7 = uVar9 * uVar7;
  uVar5 = uVar13 * 0x10000;
  uVar10 = param_2 + uVar5;
  uVar6 = uVar7 * 0x10000;
  uVar11 = uVar10 + uVar6;
  uVar5 = uVar9 * uVar12 + iVar8 + (uVar13 >> 0x10) + (uint)CARRY4(param_2,uVar5) +
          (uVar7 >> 0x10) + (uint)CARRY4(uVar10,uVar6);
  uVar6 = uVar1 + uVar5 + CARRY4(uVar4,uVar11);
  iVar8 = uVar3 + uVar2 + (CARRY4(uVar14,uVar2) ||
                          CARRY4(uVar14 + uVar2,(uint)CARRY4(uVar14,uVar15))) +
          (uint)(CARRY4(uVar1,uVar5) || CARRY4(uVar1 + uVar5,(uint)CARRY4(uVar4,uVar11)));
  uVar3 = uVar4 + uVar11 | (uVar15 | uVar15 * 4) >> 2;
  if (-1 < iVar8) {
    return CONCAT44(iVar8 * 2 +
                    (uint)(CARRY4(uVar6,uVar6) || CARRY4(uVar6 * 2,(uint)CARRY4(uVar3,uVar3))),
                    param_1) & 0xffffffff80000000;
  }
  return CONCAT44(iVar8,param_1) & 0xffffffff80000000;
}


// ===== reg_rmw8 @ 20157138 (20 bytes)

/* (reg, val, shift, mask): *reg = *reg & ~mask | val << shift, 8-bit [fact] */

void reg_rmw8(byte *param_1,int param_2,uint param_3,byte param_4)

{
  *param_1 = *param_1 & ~param_4 | (byte)(param_2 << (param_3 & 0xff));
  return;
}


// ===== reg_rmw16 @ 2015714c (20 bytes)

/* 16-bit read-modify-write, same arguments (spi-links.md) [fact] */

void reg_rmw16(ushort *param_1,int param_2,uint param_3,ushort param_4)

{
  *param_1 = *param_1 & ~param_4 | (ushort)(param_2 << (param_3 & 0xff));
  return;
}


// ===== reg_rmw32 @ 20157160 (20 bytes)

/* 32-bit read-modify-write, same arguments [fact] */

void reg_rmw32(uint *param_1,int param_2,uint param_3,uint param_4)

{
  *param_1 = *param_1 & ~param_4 | param_2 << (param_3 & 0xff);
  return;
}


// ===== reg_read8 @ 20157174 (16 bytes)

/* (reg, shift, mask): (*reg & mask) >> shift, 8-bit [fact] */

byte reg_read8(byte *param_1,uint param_2,uint param_3)

{
  return (byte)((*param_1 & param_3) >> (param_2 & 0xff));
}


// ===== reg_read16 @ 20157184 (16 bytes)

/* 16-bit field read (spi-links.md) [fact] */

uint reg_read16(ushort *param_1,uint param_2,uint param_3)

{
  return (*param_1 & param_3) >> (param_2 & 0xff);
}


// ===== FUN_20157194 @ 20157194 (16 bytes)

uint FUN_20157194(uint *param_1,uint param_2,uint param_3)

{
  return (*param_1 & param_3) >> (param_2 & 0xff);
}


// ===== mutex_lock @ 201571a4 (12 bytes)

/* itron_tloc_mtx(*obj, TMO_FEVR) [fact] */

void mutex_lock(undefined4 *param_1)

{
  itron_tloc_mtx(*param_1,0xffffffff);
  return;
}


// ===== mutex_unlock @ 201571b0 (8 bytes)

/* itron_unl_mtx(*obj) [fact] */

void mutex_unlock(undefined4 *param_1)

{
  itron_unl_mtx(*param_1);
  return;
}


// ===== mutex_guard_ctor @ 201571b8 (28 bytes)

/* Scoped lock: stores the mutex id, locks it when the flag is set [fact]; used by usbkbd_* and the
   TX pools [fact] */

undefined4 * mutex_guard_ctor(undefined4 *param_1,undefined4 param_2,int param_3)

{
  *param_1 = param_2;
  if (param_3 != 0) {
    mutex_lock();
  }
  return param_1;
}


// ===== mutex_guard_dtor @ 201571d4 (20 bytes)

/* Scoped lock destructor: mutex_unlock [fact] */

undefined4 mutex_guard_dtor(undefined4 param_1)

{
  mutex_unlock();
  return param_1;
}


// ===== afscope_obj_clear @ 201571e8 (36 bytes)

/* (obj 0x208DCE3C): clears 0x13178 bytes of history at +0xB60 and resets the ring index +0x13CD8
   [fact] */

void afscope_obj_clear(int param_1)

{
  __aeabi_memclr4(param_1 + 0xb60,0x13178);
  FUN_2016437c(param_1 + 0x13cd8);
  return;
}


// ===== copy_inverted_words @ 20157214 (36 bytes)

/* (this, dst, src, n): n/4 words dst = ~src; used to read the AF-FFT record [fact] */

void copy_inverted_words(undefined4 param_1,uint *param_2,uint *param_3,uint param_4)

{
  for (param_4 = param_4 >> 2; param_4 != 0; param_4 = param_4 - 1) {
    *param_2 = ~*param_3;
    param_3 = param_3 + 1;
    param_2 = param_2 + 1;
  }
  return;
}


// ===== FUN_201572f8 @ 201572f8 (12 bytes)

void FUN_201572f8(int param_1)

{
  *(undefined1 *)(param_1 + 0xb59) = 0;
  afscope_obj_clear();
  return;
}


// ===== FUN_201574e8 @ 201574e8 (92 bytes)

undefined4 FUN_201574e8(int param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  int i;
  undefined1 auStack_1a0 [200];
  byte local_d8 [204];
  
                    /* n/4 words dst = ~src [doc] */
  copy_inverted_words(param_1,auStack_1a0,param_1 + 0x900,200);
  FUN_20134084(local_d8,auStack_1a0);
  i = 0;
  do {
    *(undefined1 *)(param_4 + i) = *(undefined1 *)((uint)local_d8[i] + param_1 + 0x400);
    i = i + 1;
  } while (i < 200);
  return 0x2c;
}


// ===== FUN_201575f8 @ 201575f8 (12 bytes)

void FUN_201575f8(int param_1)

{
  *(undefined1 *)(param_1 + 0xb59) = 0;
  afscope_obj_clear();
  return;
}


// ===== FUN_20157604 @ 20157604 (40 bytes)

void FUN_20157604(int param_1)

{
  *(undefined4 *)(param_1 + 0x13cd8) = 0;
  *(int *)(param_1 + 0xb5c) = param_1 + 0x900;
  return;
}


// ===== FUN_20157634 @ 20157634 (188 bytes)

void FUN_20157634(int param_1,int param_2,byte *param_3)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint n;
  ulonglong __aeabi_idivmod_ret;
  
  iVar3 = 0;
  do {
    *(undefined1 *)(param_1 + iVar3) = 0;
    iVar3 = iVar3 + 1;
  } while (iVar3 < 0x100);
  uVar4 = (uint)*param_3;
  n = param_2 * 10000;
  uVar2 = (uint)param_3[1];
  if (uVar4 <= uVar2) {
    do {
      bVar1 = *param_3;
      __aeabi_idivmod_ret = __aeabi_idivmod(n,(uVar2 - bVar1) + 1);
      iVar3 = (int)__aeabi_idivmod_ret * ((uVar4 - bVar1) + 1) + 0x26ac;
      *(char *)(param_1 + uVar4) =
           ((char)(iVar3 / 10000) + (char)(iVar3 >> 0x1f)) -
           (char)((longlong)iVar3 * 0x68db8bad >> 0x3f);
      uVar4 = uVar4 + 1;
      uVar2 = (uint)param_3[1];
    } while ((int)uVar4 <= (int)uVar2);
  }
  uVar2 = uVar2 + 1;
  if (uVar2 < 0x100) {
    do {
      *(char *)(param_1 + uVar2) =
           ((char)((int)n / 10000) + (char)((int)n >> 0x1f)) -
           (char)((longlong)(int)n * 0x68db8bad >> 0x3f);
      uVar2 = uVar2 + 1;
    } while ((int)uVar2 < 0x100);
  }
  return;
}

