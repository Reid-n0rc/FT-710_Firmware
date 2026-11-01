// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== R_BSP_HardwareUnlock @ fff90885 (25 bytes)

/* (lock id): R_BSP_SoftwareUnlock on 0x1FFC4 + id*4 [fact: fff90885]; Renesas BSP name [inference]
    */

undefined1 R_BSP_HardwareUnlock(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = R_BSP_SoftwareUnlock(&DAT_0001ffc4 + param_1 * 4);
  return uVar1;
}


// ===== R_BSP_SoftwareInterruptOpen @ fff9089e (273 bytes)

/* (unit 0/1): takes hardware lock 0x72/0x73, clears and disables the software interrupt, empties
   its 9-entry task table 0x20318 + unit*0x6C, then enables it via R_BSP_SoftwareInterruptControl
   [fact: fff9089e]; Renesas BSP API name [inference] */

uint R_BSP_SoftwareInterruptOpen(int param_1)

{
  char cStack_12;
  byte bStack_11;
  uint local_10;
  char cStack_9;
  int local_4;
  
  local_10 = 0;
  local_4 = param_1;
  if (param_1 == 1) {
    cStack_9 = R_BSP_HardwareLock(0x73);
  }
  else if (param_1 == 0) {
    cStack_9 = R_BSP_HardwareLock(0x72);
  }
  else {
    local_10 = 3;
  }
  if (local_10 == 0) {
    if (cStack_9 == '\x01') {
      *(undefined4 *)(&DAT_00020310 + local_4 * 4) = 1;
      R_BSP_SoftwareInterruptControl(local_4,2,(char *)0x10000000);
      R_BSP_SoftwareInterruptControl(local_4,5,(char *)0x10000000);
      cStack_12 = '\x01';
      R_BSP_SoftwareInterruptControl(local_4,3,&cStack_12);
      (&DAT_00001432)[local_4] = 1;
      for (bStack_11 = 0; bStack_11 < 9; bStack_11 = bStack_11 + 1) {
        *(undefined4 *)(&DAT_00020318 + (uint)bStack_11 * 0xc + local_4 * 0x6c) = 0;
        *(undefined1 **)(local_4 * 0x6c + (uint)bStack_11 * 0xc + 0x2031c) = &LAB_fff910bc;
        *(undefined4 *)(local_4 * 0x6c + (uint)bStack_11 * 0xc + 0x20320) = 0x10000000;
      }
      (&DAT_0000142e)[local_4] = 0;
      (&DAT_00001430)[local_4] = 0;
      (&DAT_0000142c)[local_4] = 0;
      R_BSP_SoftwareInterruptControl(local_4,1,(char *)0x10000000);
    }
    else {
      local_10 = 1;
    }
  }
  return local_10;
}


// ===== R_BSP_SoftwareInterruptClose @ fff909af (231 bytes)

/* (unit): disables the software interrupt, empties the task table, releases hardware lock 0x72/0x73
   [fact: fff909af]; no caller in the export; Renesas BSP API name [inference] */

void R_BSP_SoftwareInterruptClose(int param_1)

{
  byte local_11;
  
  if (param_1 < 2) {
    R_BSP_SoftwareInterruptControl(param_1,2,(char *)0x10000000);
    R_BSP_SoftwareInterruptControl(param_1,5,(char *)0x10000000);
    for (local_11 = 0; local_11 < 9; local_11 = local_11 + 1) {
      *(undefined4 *)(&DAT_00020318 + (uint)local_11 * 0xc + param_1 * 0x6c) = 0;
      *(undefined1 **)(param_1 * 0x6c + (uint)local_11 * 0xc + 0x2031c) = &LAB_fff910bc;
      *(undefined4 *)(param_1 * 0x6c + (uint)local_11 * 0xc + 0x20320) = 0x10000000;
    }
    (&DAT_0000142e)[param_1] = 0;
    (&DAT_00001430)[param_1] = 0;
    (&DAT_0000142c)[param_1] = 0;
    (&DAT_00001432)[param_1] = 0;
    if (param_1 == 1) {
      R_BSP_HardwareUnlock(0x73);
    }
    else if (param_1 == 0) {
      R_BSP_HardwareUnlock(0x72);
    }
  }
  return;
}


// ===== R_BSP_SoftwareInterruptSetTask @ fff90a96 (272 bytes)

/* (unit, fn, arg, ...): queues fn in the next of 8 slots (counters 0x142C/0x142E) under the access
   lock; 6 = no function [fact] */

void R_BSP_SoftwareInterruptSetTask(int param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  undefined4 local_1c;
  undefined4 local_18;
  int local_10;
  undefined4 local_c;
  int local_8;
  undefined4 local_4;
  
  if (param_1 < 2) {
    local_1c = 0;
    local_10 = param_1;
    local_c = param_2;
    local_8 = param_3;
    local_4 = param_4;
    iVar2 = bsp_swint_get_access_control(param_1);
    if (iVar2 == 1) {
      if ((local_8 == 0x10000000) || (local_8 == 0)) {
        bVar1 = true;
      }
      else {
        bVar1 = false;
      }
      if (bVar1) {
        local_18 = 6;
      }
      else if ((byte)(&DAT_0000142c)[local_10] < 8) {
        if ((byte)(&DAT_0000142e)[local_10] < 8) {
          (&DAT_0000142e)[local_10] = (&DAT_0000142e)[local_10] + '\x01';
        }
        else {
          (&DAT_0000142e)[local_10] = 0;
        }
        (&DAT_0000142c)[local_10] = (&DAT_0000142c)[local_10] + '\x01';
        *(undefined4 *)
         (&DAT_00020318 + (uint)(byte)(&DAT_0000142e)[local_10] * 0xc + local_10 * 0x6c) = 1;
        *(int *)(local_10 * 0x6c + (uint)(byte)(&DAT_0000142e)[local_10] * 0xc + 0x2031c) = local_8;
        *(undefined4 *)(local_10 * 0x6c + (uint)(byte)(&DAT_0000142e)[local_10] * 0xc + 0x20320) =
             local_4;
        local_18 = 0;
      }
      else {
        local_18 = 9;
      }
      bsp_swint_release_access_control(local_10,&local_1c);
      R_BSP_SoftwareInterruptControl(local_10,4,(char *)0x10000000);
    }
  }
  return;
}


// ===== bsp_swint_get_interrupt_information @ fff90ba6 (144 bytes)

/* cmd 0: IPR (0x87303) & 0xF, IER bit, IR (0x8701A/B) bit and the nested flag 0x1432/3 into
   arg[0..3] [fact] */

void bsp_swint_get_interrupt_information(int param_1,byte *param_2)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = ICU_IPR003;
    *param_2 = bVar1 & 0xf;
    bVar1 = ICU_IER03;
    param_2[1] = bVar1 >> 2 & 1;
    bVar1 = ICU_IR026;
    param_2[2] = bVar1 & 1;
    param_2[3] = bRam00001433;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = ICU_IPR003;
  *param_2 = bVar1 & 0xf;
  bVar1 = ICU_IER03;
  param_2[1] = bVar1 >> 3 & 1;
  bVar1 = ICU_IR027;
  param_2[2] = bVar1 & 1;
  param_2[3] = DAT_00001432;
  return;
}


// ===== bsp_swint_enable_interrupt @ fff90c36 (32 bytes)

/* cmd 1: R_BSP_InterruptRequestEnable(0x1B unit 0 / 0x1A unit 1) [fact] */

void bsp_swint_enable_interrupt(int param_1)

{
  if (param_1 == 1) {
    R_BSP_InterruptRequestEnable(0x1a);
    return;
  }
  if (param_1 != 0) {
    return;
  }
  R_BSP_InterruptRequestEnable(0x1b);
  return;
}


// ===== bsp_swint_disable_interrupt @ fff90c56 (32 bytes)

/* cmd 2: R_BSP_InterruptRequestDisable(0x1B / 0x1A) [fact] */

void bsp_swint_disable_interrupt(int param_1)

{
  if (param_1 == 1) {
    R_BSP_InterruptRequestDisable(0x1a);
    return;
  }
  if (param_1 != 0) {
    return;
  }
  R_BSP_InterruptRequestDisable(0x1b);
  return;
}


// ===== bsp_swint_set_interrupt_priority @ fff90c76 (171 bytes)

/* cmd 3: priority < 16 written to the IPR with the IER bit saved and cleared around it [fact] */

uint bsp_swint_set_interrupt_priority(int param_1,byte *param_2)

{
  byte bVar1;
  undefined1 auStack_1c [7];
  byte bStack_15;
  byte *local_14;
  uint local_10;
  byte *local_8;
  int local_4;
  
  if (*param_2 < 0x10) {
    local_14 = param_2;
    local_8 = param_2;
    local_4 = param_1;
    R_BSP_InterruptControl(0x5e,6,auStack_1c);
    if (local_4 == 1) {
      bVar1 = ICU_IER03;
      bStack_15 = bVar1 >> 2 & 1;
      R_BSP_InterruptRequestDisable(0x1a);
      bVar1 = ICU_IPR003;
      ICU_IPR003 = bVar1 & 0xf0 | *local_14 & 0xf;
      if (bStack_15 == 1) {
        R_BSP_InterruptRequestEnable(0x1a);
      }
    }
    else if (local_4 == 0) {
      bVar1 = ICU_IER03;
      bStack_15 = bVar1 >> 3 & 1;
      R_BSP_InterruptRequestDisable(0x1b);
      bVar1 = ICU_IPR003;
      ICU_IPR003 = bVar1 & 0xf0 | *local_14 & 0xf;
      if (bStack_15 == 1) {
        R_BSP_InterruptRequestEnable(0x1b);
      }
    }
    R_BSP_InterruptControl(0x5e,5,auStack_1c);
    local_10 = 0;
  }
  else {
    local_10 = 4;
  }
  return local_10;
}


// ===== bsp_swint_set_interrupt_request @ fff90d21 (33 bytes)

/* cmd 4: ICU SWINTR / SWINT2R (0x872E0 / 0x872E1) |= 1 [fact] */

void bsp_swint_set_interrupt_request(int param_1)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = ICU_SWINT2R;
    ICU_SWINT2R = bVar1 | 1;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = ICU_SWINTR;
  ICU_SWINTR = bVar1 | 1;
  return;
}


// ===== bsp_swint_clear_interrupt_request @ fff90d42 (33 bytes)

/* cmd 5: IR027 / IR026 (0x8701B / 0x8701A) &= ~1 [fact] */

void bsp_swint_clear_interrupt_request(int param_1)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = ICU_IR026;
    ICU_IR026 = bVar1 & 0xfe;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = ICU_IR027;
  ICU_IR027 = bVar1 & 0xfe;
  return;
}


// ===== bsp_swint_enable_nested_interrupt @ fff90d63 (17 bytes)

/* cmd 6: nested flag 0x1432[unit] = 1 [fact] */

void bsp_swint_enable_nested_interrupt(int param_1)

{
  (&DAT_00001432)[param_1] = 1;
  return;
}


// ===== bsp_swint_disable_nested_interrupt @ fff90d74 (17 bytes)

/* cmd 7: nested flag 0x1432[unit] = 0 [fact] */

void bsp_swint_disable_nested_interrupt(int param_1)

{
  (&DAT_00001432)[param_1] = 0;
  return;
}


// ===== bsp_swint_clear_task @ fff90d85 (183 bytes)

/* cmd 8: removes one of the 9 task slots (0x20318 + 0xC*i + 0x6C*unit) unless it is running (status
   2) [fact] */

uint bsp_swint_clear_task(int param_1,byte *param_2)

{
  int iVar1;
  undefined4 local_18;
  byte *pbStack_14;
  uint uStack_10;
  byte *local_8;
  int local_4;
  
  local_18 = 0;
  local_8 = param_2;
  local_4 = param_1;
  iVar1 = bsp_swint_get_access_control(param_1,&local_18);
  if (iVar1 == 1) {
    pbStack_14 = local_8;
    if (*local_8 < 9) {
      if (*(int *)(&DAT_00020318 + (uint)*local_8 * 0xc + local_4 * 0x6c) == 2) {
        uStack_10 = 8;
      }
      else {
        *(undefined4 *)(&DAT_00020318 + (uint)*local_8 * 0xc + local_4 * 0x6c) = 0;
        *(undefined1 **)(local_4 * 0x6c + (uint)*local_8 * 0xc + 0x2031c) = &LAB_fff910bc;
        *(undefined4 *)(local_4 * 0x6c + (uint)*local_8 * 0xc + 0x20320) = 0x10000000;
        uStack_10 = 0;
      }
    }
    else {
      uStack_10 = 7;
    }
    bsp_swint_release_access_control(local_4,&local_18);
    R_BSP_SoftwareInterruptControl(local_4,4,(char *)0x10000000);
  }
  else {
    uStack_10 = 10;
  }
  return uStack_10;
}


// ===== bsp_swint_clear_all_task @ fff90e3c (244 bytes)

/* cmd 9: resets all 9 slots to a dummy task and the queue counters 0x142C/0x142E/0x1430 [fact] */

uint bsp_swint_clear_all_task(int param_1)

{
  int iVar1;
  undefined4 local_14;
  byte bStack_d;
  uint uStack_c;
  int local_4;
  
  local_14 = 0;
  local_4 = param_1;
  iVar1 = bsp_swint_get_access_control(param_1,&local_14);
  if (iVar1 == 1) {
    uStack_c = 0;
    for (bStack_d = 0; bStack_d < 9; bStack_d = bStack_d + 1) {
      if (*(int *)(&DAT_00020318 + (uint)bStack_d * 0xc + local_4 * 0x6c) == 2) {
        uStack_c = 8;
        break;
      }
    }
    if (uStack_c == 0) {
      for (bStack_d = 0; bStack_d < 9; bStack_d = bStack_d + 1) {
        *(undefined4 *)(&DAT_00020318 + (uint)bStack_d * 0xc + local_4 * 0x6c) = 0;
        *(undefined1 **)(local_4 * 0x6c + (uint)bStack_d * 0xc + 0x2031c) = &LAB_fff910bc;
        *(undefined4 *)(local_4 * 0x6c + (uint)bStack_d * 0xc + 0x20320) = 0x10000000;
      }
      (&DAT_0000142e)[local_4] = 0;
      (&DAT_00001430)[local_4] = 0;
      (&DAT_0000142c)[local_4] = 0;
      bsp_swint_release_access_control(local_4,&local_14);
    }
    else {
      bsp_swint_release_access_control(local_4,&local_14);
      R_BSP_SoftwareInterruptControl(local_4,4,(char *)0x10000000);
    }
  }
  else {
    uStack_c = 10;
  }
  return uStack_c;
}


// ===== bsp_swint_get_all_task_status @ fff90f30 (107 bytes)

/* cmd 10: copies the 9 {status, function, argument} slots to arg [fact] */

void bsp_swint_get_all_task_status(int param_1,undefined4 *param_2)

{
  undefined4 *local_10;
  byte local_9;
  
  local_10 = param_2;
  for (local_9 = 0; local_9 < 9; local_9 = local_9 + 1) {
    *local_10 = *(undefined4 *)(&DAT_00020318 + (uint)local_9 * 0xc + param_1 * 0x6c);
    local_10[1] = *(undefined4 *)(param_1 * 0x6c + (uint)local_9 * 0xc + 0x2031c);
    local_10[2] = *(undefined4 *)(param_1 * 0x6c + (uint)local_9 * 0xc + 0x20320);
    local_10 = local_10 + 3;
  }
  return;
}


// ===== R_BSP_SoftwareInterruptControl @ fff90f9b (190 bytes)

/* (unit 0/1, cmd 0..12, arg): switch over the bsp_swint_* helpers; unit 0 = SWINT (vector 27), 1 =
   SWINT2 (vector 26); 3 = bad unit, 5 = bad cmd [fact]; the Renesas BSP software-interrupt API with
   the same command order [inference] */

uint R_BSP_SoftwareInterruptControl(int param_1,uint param_2,char *param_3)

{
  uint local_14;
  
  if (param_1 < 2) {
    local_14 = 0;
    switch(param_2) {
    case 0:
      bsp_swint_get_interrupt_information(param_1,param_3);
      break;
    case 1:
      bsp_swint_enable_interrupt(param_1);
      break;
    case 2:
      bsp_swint_disable_interrupt(param_1);
      break;
    case 3:
      local_14 = bsp_swint_set_interrupt_priority(param_1,(byte *)param_3);
      break;
    case 4:
      bsp_swint_set_interrupt_request(param_1);
      break;
    case 5:
      bsp_swint_clear_interrupt_request(param_1);
      break;
    case 6:
      bsp_swint_enable_nested_interrupt(param_1);
      break;
    case 7:
      bsp_swint_disable_nested_interrupt(param_1);
      break;
    case 8:
      local_14 = bsp_swint_clear_task(param_1,(byte *)param_3);
      break;
    case 9:
      local_14 = bsp_swint_clear_all_task(param_1);
      break;
    case 10:
      bsp_swint_get_all_task_status(param_1,param_3);
      break;
    case 0xb:
      *param_3 = (&DAT_0000142c)[param_1];
      break;
    case 0xc:
      *param_3 = '\b' - (&DAT_0000142c)[param_1];
      break;
    default:
      local_14 = 5;
    }
  }
  else {
    local_14 = 3;
  }
  return local_14;
}


// ===== bsp_swint_get_access_control @ fff91059 (46 bytes)

/* Exchanges the access word 0x20310[unit] with *arg; true when the lock was free (1) [fact] */

bool bsp_swint_get_access_control(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = *param_2;
  *param_2 = *(int *)(&DAT_00020310 + param_1 * 4);
  *(int *)(&DAT_00020310 + param_1 * 4) = iVar1;
  return *param_2 == 1;
}


// ===== bsp_swint_release_access_control @ fff91087 (53 bytes)

/* Exchanges back into 0x20310[unit]; true when it now holds 1 [fact] */

bool bsp_swint_release_access_control(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  uVar1 = *param_2;
  *param_2 = *(undefined4 *)(&DAT_00020310 + param_1 * 4);
  *(undefined4 *)(&DAT_00020310 + param_1 * 4) = uVar1;
  return *(int *)(&DAT_00020310 + param_1 * 4) == 1;
}


// ===== bsp_swint_execute_task @ fff910c3 (327 bytes)

/* Runs the queued tasks of a unit in ring order (status 1 -> 2 -> fn(arg)), optional nesting via
   FUN_fff8fd84 [fact]; called from the SWINT ISRs [inference] */

void bsp_swint_execute_task(int param_1)

{
  code *pcVar1;
  int iVar2;
  undefined4 local_8;
  int local_4;
  
  local_8 = 0;
  local_4 = param_1;
  iVar2 = bsp_swint_get_access_control(param_1,&local_8);
  if (iVar2 == 1) {
    bsp_swint_release_access_control(local_4,&local_8);
    if ((&DAT_00001432)[local_4] == '\x01') {
      FUN_fff8fd84();
    }
    local_8 = 0;
    bsp_swint_get_access_control(local_4,&local_8);
    while( true ) {
      if ((&DAT_0000142c)[local_4] == '\0') break;
      if ((byte)(&DAT_00001430)[local_4] < 8) {
        (&DAT_00001430)[local_4] = (&DAT_00001430)[local_4] + '\x01';
      }
      else {
        (&DAT_00001430)[local_4] = 0;
      }
      if (*(int *)(&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c) == 1
         ) {
        *(undefined4 *)(&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c)
             = 2;
        bsp_swint_release_access_control(local_4,&local_8);
        iVar2 = (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c;
        pcVar1 = *(code **)(&DAT_00020318 + iVar2 + 4);
        (*pcVar1)(*(undefined4 *)(&DAT_00020318 + iVar2 + 8),pcVar1);
        local_8 = 0;
        bsp_swint_get_access_control(local_4,&local_8);
        if (*(int *)(&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c) ==
            2) {
          *(undefined4 *)
           (&DAT_00020318 + (uint)(byte)(&DAT_00001430)[local_4] * 0xc + local_4 * 0x6c) = 3;
        }
      }
      if ((&DAT_0000142c)[local_4] != '\0') {
        (&DAT_0000142c)[local_4] = (&DAT_0000142c)[local_4] + -1;
      }
    }
    bsp_swint_release_access_control(local_4,&local_8);
    return;
  }
  return;
}


// ===== vec027_ICU_SWINT @ fff9120a (15 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91213) */
/* WARNING: Removing unreachable block (ram,0xfff9120a) */
/* WARNING: Removing unreachable block (ram,0xfff9120c) */
/* WARNING: Removing unreachable block (ram,0xfff91215) */

undefined4 vec027_ICU_SWINT(undefined4 param_1)

{
  bsp_swint_execute_task(0);
  return param_1;
}


// ===== vec026_ICU_SWINT2 @ fff91219 (15 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91222) */
/* WARNING: Removing unreachable block (ram,0xfff91219) */
/* WARNING: Removing unreachable block (ram,0xfff9121b) */
/* WARNING: Removing unreachable block (ram,0xfff91224) */

undefined4 vec026_ICU_SWINT2(undefined4 param_1)

{
  bsp_swint_execute_task(1);
  return param_1;
}


// ===== FUN_fff91228 @ fff91228 (32 bytes)

undefined4 FUN_fff91228(undefined4 param_1)

{
  uint in_PSW;
  
  if ((in_PSW & 0x100000) != 0) {
    return param_1;
  }
  return param_1;
}


// ===== FUN_fff91248 @ fff91248 (4 bytes)

void FUN_fff91248(void)

{
  return;
}


// ===== get_bpsw @ fff9124c (19 bytes)

/* CC-RX intrinsic: return BPSW in R1 (SUB #8,SP; save via [SP]; RTSD #8); no callers [inference for
   the name] */

uint get_bpsw(void)

{
  uint in_BPSW;
  
  return in_BPSW;
}


// ===== FUN_fff9125f @ fff9125f (4 bytes)

void FUN_fff9125f(void)

{
  return;
}


// ===== get_bpc @ fff91263 (19 bytes)

/* CC-RX intrinsic: return BPC in R1 (SUB #8,SP; save via [SP]; RTSD #8); no callers [inference for
   the name] */

uint get_bpc(void)

{
  uint in_BPC;
  
  return in_BPC;
}


// ===== FUN_fff91276 @ fff91276 (4 bytes)

void FUN_fff91276(void)

{
  return;
}


// ===== get_extb @ fff9127a (19 bytes)

/* CC-RX intrinsic: return EXTB in R1 (SUB #8,SP; save via [SP]; RTSD #8); no callers [inference for
   the name] */

uint get_extb(void)

{
  uint in_EXTB;
  
  return in_EXTB;
}


// ===== FUN_fff9128d @ fff9128d (4 bytes)

void FUN_fff9128d(void)

{
  return;
}


// ===== FUN_fff91291 @ fff91291 (4 bytes)

void FUN_fff91291(void)

{
  return;
}


// ===== get_acc_hi @ fff91295 (19 bytes)

/* CC-RX intrinsic: return ACC bits 63..32 (MVFACHI #0,A0) in R1 (SUB #8,SP; save via [SP]; RTSD
   #8); no callers [inference for the name] */

uint get_acc_hi(void)

{
  undefined8 in_ACC;
  
  return (uint)((ulonglong)in_ACC >> 0x20);
}


// ===== get_acc_mi @ fff912a8 (19 bytes)

/* CC-RX intrinsic: return ACC bits 47..16 (MVFACMI #0,A0) in R1 (SUB #8,SP; save via [SP]; RTSD
   #8); no callers [inference for the name] */

uint get_acc_mi(void)

{
  undefined8 in_ACC;
  
  return (uint)((ulonglong)in_ACC >> 0x10);
}


// ===== FUN_fff912bb @ fff912bb (4 bytes)

void FUN_fff912bb(byte *param_1,byte param_2)

{
  *param_1 = *param_1 | '\x01' << (param_2 & 7);
  return;
}


// ===== FUN_fff912bf @ fff912bf (4 bytes)

void FUN_fff912bf(byte *param_1,byte param_2)

{
  *param_1 = *param_1 & ~('\x01' << (param_2 & 7));
  return;
}


// ===== FUN_fff912c3 @ fff912c3 (4 bytes)

void FUN_fff912c3(byte *param_1,byte param_2)

{
  *param_1 = *param_1 ^ '\x01' << (param_2 & 7);
  return;
}


// ===== sbrk @ fff912c7 (60 bytes)

/* lowsrc sbrk(size): advances the heap pointer at 0x25D34 if the new end is <= 0x207F4; only caller
   heap_getmem [inference for the name] */

void sbrk(int param_1)

{
  if (PTR_DAT_00025d34 + param_1 <= &DAT_000207f4) {
    PTR_DAT_00025d34 = PTR_DAT_00025d34 + param_1;
  }
  return;
}


// ===== get_iclk_freq_hz @ fff91303 (212 bytes)

/* ICLK in Hz from SCKCR3 CKSEL (PLL: HOCO 16/18/20 MHz or 24 MHz main, PLLCR divider and
   multiplier; HOCO; LOCO 240 kHz; sub 32768 Hz; main 24 MHz) >> SCKCR.ICK [fact: fff91303] */

uint get_iclk_freq_hz(void)

{
  ushort uVar1;
  short sVar2;
  byte bVar3;
  uint uVar4;
  uint local_1c [5];
  undefined *local_8;
  
  local_1c[0] = 16000000;
  local_1c[1] = 18000000;
  local_1c[2] = 20000000;
  uVar1 = SYSTEM_SCKCR3;
  bVar3 = (byte)(uVar1 >> 8) & 7;
  if (bVar3 == 4) {
    sVar2 = SYSTEM_PLLCR;
    local_1c[4] = ((uint)(int)sVar2 >> 8 & 0x3f) * 10 + 10 >> 1;
    local_1c[3] = 24000000;
    sVar2 = SYSTEM_PLLCR;
    if (((uint)(int)sVar2 >> 4 & 1) == 1) {
      bVar3 = SYSTEM_HOCOCR2;
      local_1c[3] = local_1c[bVar3 & 3];
    }
    uVar1 = SYSTEM_PLLCR;
    uVar4 = (uVar1 & 3) * 10 + 10;
    if (uVar4 != 0) {
      local_1c[3] = local_1c[3] / uVar4;
    }
    local_8 = (undefined *)(local_1c[3] * local_1c[4]);
  }
  else if (bVar3 == 1) {
    bVar3 = SYSTEM_HOCOCR2;
    local_8 = (undefined *)local_1c[bVar3 & 3];
  }
  else if (bVar3 == 2) {
    local_8 = (undefined *)0x16e3600;
  }
  else if (bVar3 == 3) {
    local_8 = (undefined *)0x8000;
  }
  else if ((uVar1 & 0x700) == 0) {
    local_8 = &DAT_0003a980;
  }
  else {
    local_8 = (undefined *)0x16e3600;
  }
  uVar4 = SYSTEM_SCKCR;
  return (uint)local_8 >> ((uVar4 & 0xfffffff) >> 0x18);
}


// ===== hw_init_clock @ fff913d7 (4 bytes)

/* Called first from PowerON_Reset; writes SYSTEM regs (PRCR 0x803FE=0xA50B ...) [inference:
   clock/system setup] */

void hw_init_clock(void)

{
  mcu_clock_setup();
  return;
}


// ===== mcu_clock_setup @ fff913db (186 bytes)

/* PRCR unlock, clock_source_select, SCKCR = 0x21C21222, SCKCR2 = 0x11, SCKCR3 = 0x400 (PLL), LOCO
   off, R_BSP_SoftwareDelay(25 us), PRCR lock [fact: fff913db]; only caller hw_init_clock; BSP name
   [inference] */

byte mcu_clock_setup(void)

{
  undefined4 uVar1;
  undefined2 uVar2;
  byte bVar3;
  
  SYSTEM_PRCR = 0xa50b;
  clock_source_select();
  SYSTEM_SCKCR = 0x21c21222;
  uVar1 = SYSTEM_SCKCR;
  SYSTEM_SCKCR2 = 0x11;
  uVar2 = SYSTEM_SCKCR2;
  SYSTEM_SCKCR3 = 0x400;
  uVar2 = SYSTEM_SCKCR3;
  SYSTEM_LOCOCR = 1;
  bVar3 = R_BSP_SoftwareDelay(0x19,1000000);
  SYSTEM_PRCR = 0xa500;
  return bVar3;
}


// ===== clock_source_select @ fff91495 (371 bytes)

/* Oscillator set-up: MOFCR, HOCO power, main oscillator wait MOSCWTCR = 0x53 and start, sub-clock /
   RTC RCR3/RCR4 on cold reset, PLLCR = 0x1300 class and PLL start, ROMWT = 2 [fact: fff91495];
   matches the Renesas BSP mcu_clocks.c function [inference] */

void clock_source_select(void)

{
  ushort uVar1;
  undefined1 uVar2;
  byte bVar3;
  char cVar4;
  byte local_1;
  
  bVar3 = SYSTEM_MOFCR;
  SYSTEM_MOFCR = bVar3 & 0xfe;
  bVar3 = SYSTEM_MOFCR;
  SYSTEM_MOFCR = bVar3 & 0xbf;
  bVar3 = SYSTEM_HOCOCR;
  if ((bVar3 & 1) == 1) {
    SYSTEM_HOCOPCR = 1;
  }
  else {
    do {
      bVar3 = SYSTEM_OSCOVFSR;
    } while ((bVar3 & 8) == 0);
  }
  bVar3 = SYSTEM_MOFCR;
  SYSTEM_MOFCR = bVar3 & 0xcf;
  SYSTEM_MOSCWTCR = 0x53;
  SYSTEM_MOSCCR = 0;
  uVar2 = SYSTEM_MOSCCR;
  do {
    bVar3 = SYSTEM_OSCOVFSR;
  } while ((bVar3 & 1) == 0);
  bVar3 = SYSTEM_RSTSR1;
  if ((bVar3 & 1) == 0) {
    bVar3 = RTC_RCR4;
    RTC_RCR4 = bVar3 & 0xfe;
    for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
      uVar2 = RTC_RCR4;
    }
    uVar2 = RTC_RCR4;
    bVar3 = RTC_RCR3;
    RTC_RCR3 = bVar3 & 0xfe;
    for (local_1 = 0; local_1 < 4; local_1 = local_1 + 1) {
      uVar2 = RTC_RCR3;
    }
    uVar2 = RTC_RCR3;
    SYSTEM_SOSCCR = 1;
    uVar2 = SYSTEM_SOSCCR;
    do {
      bVar3 = SYSTEM_OSCOVFSR;
    } while ((bVar3 & 2) != 0);
  }
  else {
    SYSTEM_SOSCCR = 1;
    uVar2 = SYSTEM_SOSCCR;
    do {
      bVar3 = SYSTEM_OSCOVFSR;
    } while ((bVar3 & 2) != 0);
  }
  uVar1 = SYSTEM_PLLCR;
  SYSTEM_PLLCR = uVar1 & 0xfffc;
  uVar1 = SYSTEM_PLLCR;
  SYSTEM_PLLCR = uVar1 & 0xffef;
  uVar1 = SYSTEM_PLLCR;
  SYSTEM_PLLCR = uVar1 & 0xd3ff | 0x1300;
  SYSTEM_PLLCR2 = 0;
  do {
    bVar3 = SYSTEM_OSCOVFSR;
  } while ((bVar3 & 4) == 0);
  SYSTEM_ROMWT = 2;
  cVar4 = SYSTEM_ROMWT;
  if (cVar4 != '\x02') {
    return;
  }
  return;
}


// ===== FUN_fff91608 @ fff91608 (164 bytes)

void FUN_fff91608(void)

{
  byte bVar1;
  undefined1 uVar2;
  
  bVar1 = PORT0_PDR;
  PORT0_PDR = bVar1 | 0x50;
  bVar1 = PORT1_PDR;
  PORT1_PDR = bVar1 | 3;
  uVar2 = PORT2_PDR;
  PORT2_PDR = uVar2;
  uVar2 = PORT3_PDR;
  PORT3_PDR = uVar2;
  uVar2 = PORT4_PDR;
  PORT4_PDR = uVar2;
  bVar1 = PORT5_PDR;
  PORT5_PDR = bVar1 | 0x80;
  uVar2 = PORT6_PDR;
  PORT6_PDR = uVar2;
  uVar2 = PORT7_PDR;
  PORT7_PDR = uVar2;
  bVar1 = PORT8_PDR;
  PORT8_PDR = bVar1 | 0x30;
  bVar1 = PORT9_PDR;
  PORT9_PDR = bVar1 | 0xf0;
  uVar2 = PORTA_PDR;
  PORTA_PDR = uVar2;
  uVar2 = PORTB_PDR;
  PORTB_PDR = uVar2;
  uVar2 = PORTC_PDR;
  PORTC_PDR = uVar2;
  uVar2 = PORTD_PDR;
  PORTD_PDR = uVar2;
  uVar2 = PORTE_PDR;
  PORTE_PDR = uVar2;
  bVar1 = PORTF_PDR;
  PORTF_PDR = bVar1 | 0xdf;
  uVar2 = PORTG_PDR;
  PORTG_PDR = 0xff;
  bVar1 = PORTJ_PDR;
  PORTJ_PDR = bVar1 | 0xd7;
  return;
}


// ===== FUN_fff916ac @ fff916ac (158 bytes)

uint FUN_fff916ac(int param_1,char param_2)

{
  byte bVar1;
  uint local_14;
  
  local_14 = 0;
  if (param_1 == 2) {
    if (param_2 == '\x01') {
      bVar1 = ICU_NMIER;
      ICU_NMIER = bVar1 | 1;
    }
    else {
      local_14 = 3;
    }
  }
  else if (param_1 != 3) {
    if (param_1 == 0xb) {
      if (param_2 == '\x01') {
        bVar1 = ICU_IR016;
        ICU_IR016 = bVar1 & 0xfe;
        bVar1 = ICU_IPR000;
        ICU_IPR000 = bVar1 | 0xf;
        R_BSP_InterruptRequestEnable(0x10);
        bVar1 = BSC_BEREN;
        BSC_BEREN = bVar1 | 1;
        bVar1 = BSC_BEREN;
        BSC_BEREN = bVar1 | 2;
      }
      else {
        R_BSP_InterruptRequestDisable(0x10);
        bVar1 = BSC_BEREN;
        BSC_BEREN = bVar1 & 0xfe;
        bVar1 = BSC_BEREN;
        BSC_BEREN = bVar1 & 0xfd;
      }
    }
    else {
      local_14 = 3;
    }
  }
  return local_14;
}


// ===== vec110_GROUPBL0 @ fff9174a (884 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91ab2) */
/* WARNING: Removing unreachable block (ram,0xfff91aba) */
/* WARNING: Removing unreachable block (ram,0xfff91ab8) */
/* WARNING: Removing unreachable block (ram,0xfff9174a) */
/* WARNING: Removing unreachable block (ram,0xfff9174c) */
/* WARNING: Removing unreachable block (ram,0xfff91ab4) */

undefined4 vec110_GROUPBL0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x1e < 0) {
    R_BSP_InterruptControl(0x15,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x1f < 0) {
    R_BSP_InterruptControl(0x14,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x1c < 0) {
    R_BSP_InterruptControl(0x17,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x1d < 0) {
    R_BSP_InterruptControl(0x16,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x1a < 0) {
    R_BSP_InterruptControl(0x19,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x1b < 0) {
    R_BSP_InterruptControl(0x18,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x18 < 0) {
    R_BSP_InterruptControl(0x1b,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x19 < 0) {
    R_BSP_InterruptControl(0x1a,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x1d,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x1c,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x14 < 0) {
    R_BSP_InterruptControl(0x1f,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x15 < 0) {
    R_BSP_InterruptControl(0x1e,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x12 < 0) {
    R_BSP_InterruptControl(0x21,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x13 < 0) {
    R_BSP_InterruptControl(0x20,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x10 < 0) {
    R_BSP_InterruptControl(0x23,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0x11 < 0) {
    R_BSP_InterruptControl(0x22,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0xe < 0) {
    R_BSP_InterruptControl(0x25,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0xf < 0) {
    R_BSP_InterruptControl(0x24,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0xd < 0) {
    R_BSP_InterruptControl(0x26,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0xc < 0) {
    R_BSP_InterruptControl(0x27,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 0xb < 0) {
    R_BSP_InterruptControl(0x28,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 10 < 0) {
    R_BSP_InterruptControl(0x29,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 7 < 0) {
    R_BSP_InterruptControl(0x2a,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 5 < 0) {
    R_BSP_InterruptControl(0x2b,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 4 < 0) {
    R_BSP_InterruptControl(0x2c,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 3 < 0) {
    R_BSP_InterruptControl(0x2d,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 2 < 0) {
    R_BSP_InterruptControl(0x2e,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 < 0) {
    R_BSP_InterruptControl(0x30,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL0;
  if (iVar1 << 1 < 0) {
    R_BSP_InterruptControl(0x2f,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec111_GROUPBL1 @ fff91abe (736 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91d92) */
/* WARNING: Removing unreachable block (ram,0xfff91d9a) */
/* WARNING: Removing unreachable block (ram,0xfff91d98) */
/* WARNING: Removing unreachable block (ram,0xfff91abe) */
/* WARNING: Removing unreachable block (ram,0xfff91ac0) */
/* WARNING: Removing unreachable block (ram,0xfff91d94) */

undefined4 vec111_GROUPBL1(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x1c < 0) {
    R_BSP_InterruptControl(0x32,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x1b < 0) {
    R_BSP_InterruptControl(0x33,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x1a < 0) {
    R_BSP_InterruptControl(0x34,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x19 < 0) {
    R_BSP_InterruptControl(0x35,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x18 < 0) {
    R_BSP_InterruptControl(0x36,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x37,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x38,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x15 < 0) {
    R_BSP_InterruptControl(0x39,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x14 < 0) {
    R_BSP_InterruptControl(0x3a,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x13 < 0) {
    R_BSP_InterruptControl(0x3b,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x11 < 0) {
    R_BSP_InterruptControl(0x3d,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x12 < 0) {
    R_BSP_InterruptControl(0x3c,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0xf < 0) {
    R_BSP_InterruptControl(0x3f,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0x10 < 0) {
    R_BSP_InterruptControl(0x3e,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 0xb < 0) {
    R_BSP_InterruptControl(0x40,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 10 < 0) {
    R_BSP_InterruptControl(0x41,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 9 < 0) {
    R_BSP_InterruptControl(0x42,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 8 < 0) {
    R_BSP_InterruptControl(0x43,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 6 < 0) {
    R_BSP_InterruptControl(0x45,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 7 < 0) {
    R_BSP_InterruptControl(0x44,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 4 < 0) {
    R_BSP_InterruptControl(0x47,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 5 < 0) {
    R_BSP_InterruptControl(0x46,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 2 < 0) {
    R_BSP_InterruptControl(0x49,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBL1;
  if (iVar1 << 3 < 0) {
    R_BSP_InterruptControl(0x48,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec107_GROUPBL2 @ fff91d9e (46 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91dc0) */
/* WARNING: Removing unreachable block (ram,0xfff91dc8) */
/* WARNING: Removing unreachable block (ram,0xfff91dc6) */
/* WARNING: Removing unreachable block (ram,0xfff91d9e) */
/* WARNING: Removing unreachable block (ram,0xfff91da0) */
/* WARNING: Removing unreachable block (ram,0xfff91dc2) */

undefined4 vec107_GROUPBL2(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ICU_GRPBL2;
  if (iVar1 << 0x1f < 0) {
    R_BSP_InterruptControl(0x4b,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec112_GROUPAL0 @ fff91dcc (316 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91efc) */
/* WARNING: Removing unreachable block (ram,0xfff91f04) */
/* WARNING: Removing unreachable block (ram,0xfff91f02) */
/* WARNING: Removing unreachable block (ram,0xfff91dcc) */
/* WARNING: Removing unreachable block (ram,0xfff91dce) */
/* WARNING: Removing unreachable block (ram,0xfff91efe) */

undefined4 vec112_GROUPAL0(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x4e,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x4d,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0x12 < 0) {
    R_BSP_InterruptControl(0x50,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0x13 < 0) {
    R_BSP_InterruptControl(0x4f,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0xe < 0) {
    R_BSP_InterruptControl(0x52,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0xf < 0) {
    R_BSP_InterruptControl(0x51,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0xc < 0) {
    R_BSP_InterruptControl(0x54,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0xd < 0) {
    R_BSP_InterruptControl(0x53,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 10 < 0) {
    R_BSP_InterruptControl(0x56,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL0;
  if (iVar1 << 0xb < 0) {
    R_BSP_InterruptControl(0x55,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec113_GROUPAL1 @ fff91f08 (166 bytes)

/* WARNING: Removing unreachable block (ram,0xfff91fa2) */
/* WARNING: Removing unreachable block (ram,0xfff91faa) */
/* WARNING: Removing unreachable block (ram,0xfff91fa8) */
/* WARNING: Removing unreachable block (ram,0xfff91f08) */
/* WARNING: Removing unreachable block (ram,0xfff91f0a) */
/* WARNING: Removing unreachable block (ram,0xfff91fa4) */

undefined4 vec113_GROUPAL1(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = ICU_GRPAL1;
  if (iVar1 << 0x1b < 0) {
    R_BSP_InterruptControl(0x58,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL1;
  if (iVar1 << 0x16 < 0) {
    R_BSP_InterruptControl(0x5a,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL1;
  if (iVar1 << 0x15 < 0) {
    R_BSP_InterruptControl(0x5b,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL1;
  if (iVar1 << 0x17 < 0) {
    R_BSP_InterruptControl(0x59,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPAL1;
  if (iVar1 << 0x14 < 0) {
    R_BSP_InterruptControl(0x5c,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== vec106_GROUPBE0 @ fff91fae (102 bytes)

/* WARNING: Removing unreachable block (ram,0xfff92008) */
/* WARNING: Removing unreachable block (ram,0xfff92010) */
/* WARNING: Removing unreachable block (ram,0xfff9200e) */
/* WARNING: Removing unreachable block (ram,0xfff91fae) */
/* WARNING: Removing unreachable block (ram,0xfff91fb0) */
/* WARNING: Removing unreachable block (ram,0xfff9200a) */

undefined4 vec106_GROUPBE0(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  
  iVar1 = ICU_GRPBE0;
  if (iVar1 << 0x1f < 0) {
    uVar2 = ICU_GCRBE0;
    ICU_GCRBE0 = uVar2 | 1;
    R_BSP_InterruptControl(0x11,0,(void *)0x10000000);
  }
  iVar1 = ICU_GRPBE0;
  if (iVar1 << 0x1e < 0) {
    uVar2 = ICU_GCRBE0;
    ICU_GCRBE0 = uVar2 | 2;
    R_BSP_InterruptControl(0x12,0,(void *)0x10000000);
    return param_1;
  }
  return param_1;
}


// ===== icu_select_init @ fff92014 (1121 bytes)

/* Writes ICU SLIBXR128.. selectable interrupt sources (130<-0x0F TPU0, 138<-0x18 TPU2, 142<-0x1C
   TPU3, 144<-0x14 TPU1, 186<-0x40 S12ADI0, 189<-0x44 S12ADI1) */

void icu_select_init(void)

{
  ICU_SLIBXR128 = 1;
  ICU_SLIBXR129 = 2;
  ICU_SLIBR146 = 3;
  ICU_SLIBR147 = 4;
  ICU_SLIBR148 = 5;
  ICU_SLIBR149 = 6;
  ICU_SLIBR150 = 7;
  ICU_SLIBR151 = 8;
  ICU_SLIBR152 = 9;
  ICU_SLIBR153 = 10;
  ICU_SLIBR154 = 0xb;
  ICU_SLIBR155 = 0xc;
  ICU_SLIBR156 = 0xd;
  ICU_SLIBR157 = 0xe;
  ICU_SLIBXR130 = 0xf;
  ICU_SLIBXR131 = 0x10;
  ICU_SLIBXR132 = 0x11;
  ICU_SLIBXR133 = 0x12;
  ICU_SLIBXR134 = 0x13;
  ICU_SLIBR144 = 0x14;
  ICU_SLIBXR135 = 0x15;
  ICU_SLIBXR136 = 0x16;
  ICU_SLIBXR137 = 0x17;
  ICU_SLIBXR138 = 0x18;
  ICU_SLIBXR139 = 0x19;
  ICU_SLIBXR140 = 0x1a;
  ICU_SLIBXR141 = 0x1b;
  ICU_SLIBXR142 = 0x1c;
  ICU_SLIBXR143 = 0x1d;
  ICU_SLIBR145 = 0x1e;
  ICU_SLIBR158 = 0x1f;
  ICU_SLIBR159 = 0x20;
  ICU_SLIBR160 = 0x21;
  ICU_SLIBR161 = 0x22;
  ICU_SLIBR162 = 0x23;
  ICU_SLIBR163 = 0x24;
  ICU_SLIBR164 = 0x25;
  ICU_SLIBR165 = 0x26;
  ICU_SLIBR166 = 0x27;
  ICU_SLIBR167 = 0x28;
  ICU_SLIBR168 = 0x29;
  ICU_SLIBR169 = 0x2a;
  ICU_SLIBR170 = 0x2b;
  ICU_SLIBR171 = 0x2c;
  ICU_SLIBR172 = 0x2d;
  ICU_SLIBR173 = 0x2e;
  ICU_SLIBR174 = 0x2f;
  ICU_SLIBR175 = 0x30;
  ICU_SLIBR176 = 0x31;
  ICU_SLIBR177 = 0x32;
  ICU_SLIBR178 = 0x33;
  ICU_SLIBR179 = 0x34;
  ICU_SLIBR180 = 0x35;
  ICU_SLIBR181 = 0x36;
  ICU_SLIBR182 = 0x37;
  ICU_SLIBR183 = 0x38;
  ICU_SLIBR184 = 0x39;
  ICU_SLIBR185 = 0x3e;
  ICU_SLIBR186 = 0x40;
  ICU_SLIBR187 = 0x41;
  ICU_SLIBR188 = 0x42;
  ICU_SLIBR189 = 0x44;
  ICU_SLIBR190 = 0x45;
  ICU_SLIBR191 = 0x46;
  ICU_SLIBR192 = 0x4c;
  ICU_SLIBR193 = 0x4f;
  ICU_SLIBR194 = 0x50;
  ICU_SLIBR195 = 0x55;
  ICU_SLIBR196 = 0x56;
  ICU_SLIBR197 = 0x57;
  ICU_SLIBR198 = 0x58;
  ICU_SLIBR199 = 0x59;
  ICU_SLIBR200 = 0x5a;
  ICU_SLIBR201 = 0x5b;
  ICU_SLIBR202 = 0x5c;
  ICU_SLIBR203 = 0x5d;
  ICU_SLIBR204 = 0x5e;
  ICU_SLIBR205 = 0x5f;
  ICU_SLIAR209 = 1;
  ICU_SLIAR210 = 2;
  ICU_SLIAR211 = 3;
  ICU_SLIAR212 = 4;
  ICU_SLIAR213 = 5;
  ICU_SLIAR214 = 6;
  ICU_SLIAR215 = 7;
  ICU_SLIAR208 = 8;
  ICU_SLIAR216 = 9;
  ICU_SLIAR217 = 10;
  ICU_SLIAR218 = 0xb;
  ICU_SLIAR219 = 0xc;
  ICU_SLIAR220 = 0xd;
  ICU_SLIAR221 = 0xe;
  ICU_SLIAR222 = 0xf;
  ICU_SLIAR223 = 0x10;
  ICU_SLIAR224 = 0x11;
  ICU_SLIAR225 = 0x12;
  ICU_SLIAR226 = 0x13;
  ICU_SLIAR227 = 0x14;
  ICU_SLIAR228 = 0x15;
  ICU_SLIAR229 = 0x16;
  ICU_SLIAR230 = 0x17;
  ICU_SLIAR231 = 0x18;
  ICU_SLIAR232 = 0x19;
  ICU_SLIAR233 = 0x1b;
  ICU_SLIAR234 = 0x1c;
  ICU_SLIAR235 = 0x1d;
  ICU_SLIAR236 = 0x1e;
  ICU_SLIAR237 = 0x1f;
  ICU_SLIAR238 = 0x20;
  ICU_SLIAR239 = 0x21;
  ICU_SLIAR240 = 0x22;
  ICU_SLIAR241 = 0x23;
  ICU_SLIAR242 = 0x24;
  ICU_SLIAR243 = 0x25;
  ICU_SLIAR244 = 0x26;
  ICU_SLIAR245 = 0x27;
  ICU_SLIAR246 = 0x29;
  ICU_SLIAR247 = 0x2a;
  ICU_SLIAR248 = 0x2b;
  ICU_SLIAR249 = 0x2c;
  ICU_SLIAR250 = 0x2d;
  ICU_SLIAR251 = 0x58;
  ICU_SLIAR252 = 0x59;
  return;
}


// ===== mpc_pin_functions_init @ fff92475 (820 bytes)

/* MPC pin functions inside RegisterProtectDisable/Enable(3): ASEL (PFS = 0x80, input) for P41..P43,
   P45..P47, PD0, PD1, P91, P93, P03; PSEL 0x0A/0x0B (SCI) for P00, P01, P12, P13, P23, P25..P27,
   P30, P32, P33, P90, P92, PB0, PB1, PC2, PC3 [fact: fff92475]; no caller in the export */

void mpc_pin_functions_init(void)

{
  byte bVar1;
  
  R_BSP_RegisterProtectDisable(3);
  MPC_P41PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xfd;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xfd;
  MPC_P42PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xfb;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xfb;
  MPC_P43PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xf7;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xf7;
  MPC_P45PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xdf;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xdf;
  MPC_P46PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0xbf;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0xbf;
  MPC_P47PFS = 0x80;
  bVar1 = PORT4_PMR;
  PORT4_PMR = bVar1 & 0x7f;
  bVar1 = PORT4_PDR;
  PORT4_PDR = bVar1 & 0x7f;
  MPC_PD0PFS = 0x80;
  bVar1 = PORTD_PMR;
  PORTD_PMR = bVar1 & 0xfe;
  bVar1 = PORTD_PDR;
  PORTD_PDR = bVar1 & 0xfe;
  MPC_PD1PFS = 0x80;
  bVar1 = PORTD_PMR;
  PORTD_PMR = bVar1 & 0xfd;
  bVar1 = PORTD_PDR;
  PORTD_PDR = bVar1 & 0xfd;
  MPC_P91PFS = 0x80;
  bVar1 = PORT9_PMR;
  PORT9_PMR = bVar1 & 0xfd;
  bVar1 = PORT9_PDR;
  PORT9_PDR = bVar1 & 0xfd;
  MPC_P93PFS = 0x80;
  bVar1 = PORT9_PMR;
  PORT9_PMR = bVar1 & 0xf7;
  bVar1 = PORT9_PDR;
  PORT9_PDR = bVar1 & 0xf7;
  MPC_P03PFS = 0x80;
  bVar1 = PORT0_PMR;
  PORT0_PMR = bVar1 & 0xf7;
  bVar1 = PORT0_PDR;
  PORT0_PDR = bVar1 & 0xf7;
  MPC_P27PFS = 1;
  bVar1 = PORT2_PMR;
  PORT2_PMR = bVar1 | 0x80;
  MPC_P33PFS = 0xb;
  bVar1 = PORT3_PMR;
  PORT3_PMR = bVar1 | 8;
  MPC_P30PFS = 10;
  bVar1 = PORT3_PMR;
  PORT3_PMR = bVar1 | 1;
  MPC_P12PFS = 10;
  bVar1 = PORT1_PMR;
  PORT1_PMR = bVar1 | 4;
  MPC_P25PFS = 10;
  bVar1 = PORT2_PMR;
  PORT2_PMR = bVar1 | 0x20;
  MPC_PB0PFS = 10;
  bVar1 = PORTB_PMR;
  PORTB_PMR = bVar1 | 1;
  MPC_PC2PFS = 10;
  bVar1 = PORTC_PMR;
  PORTC_PMR = bVar1 | 4;
  MPC_P92PFS = 10;
  bVar1 = PORT9_PMR;
  PORT9_PMR = bVar1 | 4;
  MPC_P01PFS = 10;
  bVar1 = PORT0_PMR;
  PORT0_PMR = bVar1 | 2;
  MPC_P00PFS = 10;
  bVar1 = PORT0_PMR;
  PORT0_PMR = bVar1 | 1;
  bVar1 = PORT3_PODR;
  PORT3_PODR = bVar1 | 4;
  MPC_P32PFS = 0xb;
  bVar1 = PORT3_PDR;
  PORT3_PDR = bVar1 | 4;
  bVar1 = PORT2_PODR;
  PORT2_PODR = bVar1 | 0x40;
  MPC_P26PFS = 10;
  bVar1 = PORT2_PDR;
  PORT2_PDR = bVar1 | 0x40;
  bVar1 = PORT1_PODR;
  PORT1_PODR = bVar1 | 8;
  MPC_P13PFS = 10;
  bVar1 = PORT1_PDR;
  PORT1_PDR = bVar1 | 8;
  bVar1 = PORT2_PODR;
  PORT2_PODR = bVar1 | 8;
  MPC_P23PFS = 10;
  bVar1 = PORT2_PDR;
  PORT2_PDR = bVar1 | 8;
  bVar1 = PORTB_PODR;
  PORTB_PODR = bVar1 | 2;
  MPC_PB1PFS = 10;
  bVar1 = PORTB_PDR;
  PORTB_PDR = bVar1 | 2;
  bVar1 = PORTC_PODR;
  PORTC_PODR = bVar1 | 8;
  MPC_PC3PFS = 10;
  bVar1 = PORTC_PDR;
  PORTC_PDR = bVar1 | 8;
  bVar1 = PORT9_PODR;
  PORT9_PODR = bVar1 | 1;
  MPC_P90PFS = 10;
  bVar1 = PORT9_PDR;
  PORT9_PDR = bVar1 | 1;
  R_BSP_RegisterProtectEnable(3);
  return;
}

