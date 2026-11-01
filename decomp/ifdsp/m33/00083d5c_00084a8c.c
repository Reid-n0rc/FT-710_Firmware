// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== DMA_IRQHandle @ 00083d5c (176 bytes)

/* NEW. fsl_dma.c channel interrupt dispatcher (33 channels); unused (DMA IRQs never enabled by the
   M33) [inference] */

void DMA_IRQHandle(void *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  undefined4 *puVar2;
  uint uVar3;
  int *piVar4;
  int i;
  code *pcVar5;
  
  uVar1 = DMA_GetInstance(param_1);
  i = 0;
  piVar4 = (int *)(&DAT_00088948 + uVar1 * 0x84);
  do {
    puVar2 = (undefined4 *)*piVar4;
    if (puVar2 != (undefined4 *)0x0) {
      uVar1 = (uint)(*(byte *)(puVar2 + 3) >> 5);
      uVar3 = *(byte *)(puVar2 + 3) & 0x1f;
      if ((int)((*(uint *)(puVar2[2] + 0x58 + uVar1 * 4) >> uVar3) << 0x1f) < 0) {
        pcVar5 = (code *)*puVar2;
        *(int *)(puVar2[2] + 0x58 + uVar1 * 4) = 1 << uVar3;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(puVar2,puVar2[1],1,0,param_4);
        }
      }
      if ((int)((*(uint *)(puVar2[2] + 0x60 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) >> uVar3) <<
               0x1f) < 0) {
        pcVar5 = (code *)*puVar2;
        *(int *)(puVar2[2] + 0x60 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) = 1 << uVar3;
        if (pcVar5 != (code *)0x0) {
          (*pcVar5)(puVar2,puVar2[1],1);
        }
      }
      if ((int)((*(uint *)(puVar2[2] + 0x40 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) >> uVar3) <<
               0x1f) < 0) {
        *(int *)(puVar2[2] + 0x40 + (uint)(*(byte *)(puVar2 + 3) >> 5) * 4) = 1 << uVar3;
        if ((code *)*puVar2 != (code *)0x0) {
          (*(code *)*puVar2)(puVar2,puVar2[1],0,2);
        }
      }
    }
    i = i + 1;
    piVar4 = piVar4 + 1;
  } while (i != 0x21);
  return;
}


// ===== DMA0_DriverIRQHandler @ 00083e10 (6 bytes)

/* IRQ1 -> DMA_IRQHandle(DMA0) [fact: vector] */

void DMA0_DriverIRQHandler(void)

{
                    /* fsl_dma.c channel interrupt dispatcher [doc, inference] */
  DMA_IRQHandle(&DMA0_CTRL);
  return;
}


// ===== DMA1_DriverIRQHandler @ 00083e1c (6 bytes)

/* IRQ54 [fact: vector] */

void DMA1_DriverIRQHandler(void)

{
                    /* fsl_dma.c channel interrupt dispatcher [doc, inference] */
  DMA_IRQHandle(&DMA1_CTRL);
  return;
}


// ===== DMIC0_DriverIRQHandler @ 00083e28 (10 bytes)

/* IRQ25 [fact: vector] */

void DMIC0_DriverIRQHandler(void)

{
  if (DAT_00088a50 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083e2e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_00088a50)();
    return;
  }
  return;
}


// ===== HWVAD0_DriverIRQHandler @ 00083e38 (10 bytes)

/* IRQ29 [fact: vector] */

void HWVAD0_DriverIRQHandler(void)

{
  if (DAT_00088a54 != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x00083e3e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_00088a54)();
    return;
  }
  return;
}


// ===== DSP_Init @ 00083e48 (82 bytes)

/* fsl_dsp.c: if PDRUNCFG1 DSP cache/TCM bits set, clear them (PDRUNCFG1_CLR), POWER_ApplyPD,
   release DSP reset [inference] */

void DSP_Init(void)

{
  int rstctl0_prstctl0;
  uint sysctl0_pdruncfg1;
  
                    /* Run configuration 1 [sfr] */
  sysctl0_pdruncfg1 = SYSCTL0_PDRUNCFG1;
  if ((sysctl0_pdruncfg1 & 0xf000000) != 0) {
                    /* Run configuration 1 clear [sfr] */
    SYSCTL0_PDRUNCFG1_CLR = 0x4000000;
    SYSCTL0_PDRUNCFG1_CLR = 0x8000000;
    SYSCTL0_PDRUNCFG1_CLR = 0x1000000;
    SYSCTL0_PDRUNCFG1_CLR = 0x2000000;
    POWER_ApplyPD();
    RESET_PeripheralReset(1);
    return;
  }
  rstctl0_prstctl0 = RSTCTL0_PRSTCTL0;
  if (rstctl0_prstctl0 << 0x1e < 0) {
    RESET_ClearPeripheralReset(1);
    return;
  }
  return;
}


// ===== FLEXCOMM_GetInstance @ 00083ea0 (22 bytes)

/* Search of 10 FLEXCOMM bases at 0x879D0 [fact] */

uint FLEXCOMM_GetInstance(int param_1)

{
  uint i;
  int *piVar1;
  
  i = 0;
  piVar1 = &DAT_000879d0;
  do {
    if (*piVar1 == param_1) {
      return i;
    }
    i = i + 1;
    piVar1 = piVar1 + 1;
  } while (i != 10);
  return 10;
}


// ===== FLEXCOMM_Init @ 00083ebc (180 bytes)

/* Clock enable + reset release from table 0x87B28, PSELID (base+0xFF8) [inference] */

uint FLEXCOMM_Init(int param_1,uint param_2)

{
  ushort uVar1;
  uint FLEXCOMM_GetInstance_ret;
  dword *pdVar2;
  uint uVar3;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(param_1);
  uVar1 = *(ushort *)(&DAT_00087b28 + FLEXCOMM_GetInstance_ret * 2);
  uVar3 = (uint)uVar1;
  switch(uVar1 >> 8) {
  case 0:
    pdVar2 = &CLKCTL0_BASE;
    break;
  case 1:
    uVar3 = (uint)(byte)uVar1;
    pdVar2 = &CLKCTL0_BASE;
    goto LAB_00083f2a;
  case 2:
    pdVar2 = &CLKCTL0_BASE;
    goto LAB_00083f38;
  case 3:
    pdVar2 = &CLKCTL1_BASE;
    break;
  case 4:
    uVar3 = uVar3 & 0xff;
    pdVar2 = &CLKCTL1_BASE;
LAB_00083f2a:
    pdVar2[0x11] = 1 << uVar3;
    goto switchD_00083ed2_default;
  case 5:
    pdVar2 = &CLKCTL1_BASE;
LAB_00083f38:
    pdVar2[0x12] = 1 << (uVar3 & 0xff);
  default:
    goto switchD_00083ed2_default;
  }
  pdVar2[0x10] = 1 << (uVar3 & 0xff);
switchD_00083ed2_default:
  RESET_PeripheralReset((uint)*(ushort *)(&DAT_00087b28 + FLEXCOMM_GetInstance_ret * 2));
  if (param_2 == 0) {
LAB_00083f04:
    if ((*(int *)(param_1 + 0xff8) << 0x1c < 0) && ((*(uint *)(param_1 + 0xff8) & 7) != param_2)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
      *(uint *)(param_1 + 0xff8) = param_2;
    }
  }
  else {
    if (param_2 < 5) {
      uVar3 = *(uint *)(param_1 + 0xff8) >> (param_2 + 3 & 0xff) & 1;
LAB_00083f02:
      if (uVar3 != 0) goto LAB_00083f04;
    }
    else if (param_2 == 5) {
      uVar3 = *(uint *)(param_1 + 0xff8) & 0x80;
      goto LAB_00083f02;
    }
    uVar3 = 3;
  }
  return uVar3;
}


// ===== FLEXCOMM1_DriverIRQHandler @ 00083f88 (32 bytes)

/* IRQ15, generic fsl_flexcomm handler [fact: vector] */

void FLEXCOMM1_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40107000);
                    /* WARNING: Could not recover jumptable at 0x00083fa6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM2_DriverIRQHandler @ 00083fb8 (32 bytes)

/* IRQ16 [fact: vector] */

void FLEXCOMM2_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40108000);
                    /* WARNING: Could not recover jumptable at 0x00083fd6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM3_DriverIRQHandler @ 00083fe8 (32 bytes)

/* IRQ17 [fact: vector] */

void FLEXCOMM3_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40109000);
                    /* WARNING: Could not recover jumptable at 0x00084006. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM4_DriverIRQHandler @ 00084018 (32 bytes)

/* IRQ18 [fact: vector] */

void FLEXCOMM4_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40122000);
                    /* WARNING: Could not recover jumptable at 0x00084036. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM5_DriverIRQHandler @ 00084048 (32 bytes)

/* IRQ19 [fact: vector] */

void FLEXCOMM5_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40123000);
                    /* WARNING: Could not recover jumptable at 0x00084066. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM6_DriverIRQHandler @ 00084078 (32 bytes)

/* IRQ43 [fact: vector] */

void FLEXCOMM6_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40124000);
                    /* WARNING: Could not recover jumptable at 0x00084096. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM7_DriverIRQHandler @ 000840a8 (32 bytes)

/* IRQ44 [fact: vector] */

void FLEXCOMM7_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40125000);
                    /* WARNING: Could not recover jumptable at 0x000840c6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM14_DriverIRQHandler @ 000840d8 (32 bytes)

/* IRQ20 [fact: vector] */

void FLEXCOMM14_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40126000);
                    /* WARNING: Could not recover jumptable at 0x000840f6. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXCOMM15_DriverIRQHandler @ 00084108 (32 bytes)

/* IRQ21 [fact: vector] */

void FLEXCOMM15_DriverIRQHandler(void)

{
  uint FLEXCOMM_GetInstance_ret;
  
  FLEXCOMM_GetInstance_ret = FLEXCOMM_GetInstance(0x40127000);
                    /* WARNING: Could not recover jumptable at 0x00084126. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(&DAT_00088a80 + FLEXCOMM_GetInstance_ret * 4))
            ((&DAT_000879d0)[FLEXCOMM_GetInstance_ret],
             *(undefined4 *)(&DAT_00088a58 + FLEXCOMM_GetInstance_ret * 4));
  return;
}


// ===== FLEXSPI_DriverIRQHandler @ 00084138 (12 bytes)

/* IRQ42 [fact: vector] */

void FLEXSPI_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x00084142. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088aac)(&FLEXSPI_MCR0,DAT_00088aa8);
  return;
}


// ===== CLOCK_EnableClock @ 00084150 (86 bytes)

/* PSCCTLn_SET from (reg << 8 | bit) [inference] */

void CLOCK_EnableClock(uint param_1)

{
  dword *pdVar1;
  
  switch(param_1 >> 8) {
  case 0:
    pdVar1 = &CLKCTL0_BASE;
    goto LAB_00084168;
  case 1:
    pdVar1 = &CLKCTL0_BASE;
    goto LAB_00084176;
  case 2:
    pdVar1 = &CLKCTL0_BASE;
    break;
  case 3:
    pdVar1 = &CLKCTL1_BASE;
LAB_00084168:
    pdVar1[0x10] = 1 << (param_1 & 0xff);
    return;
  case 4:
    pdVar1 = &CLKCTL1_BASE;
LAB_00084176:
    pdVar1[0x11] = 1 << (param_1 & 0xff);
    return;
  case 5:
    pdVar1 = &CLKCTL1_BASE;
    break;
  default:
    goto switchD_00084156_default;
  }
  pdVar1[0x12] = 1 << (param_1 & 0xff);
switchD_00084156_default:
  return;
}


// ===== GPIO_PortInit @ 000841b4 (26 bytes)

void GPIO_PortInit(undefined4 param_1,int param_2)

{
  int extraout_r1;
  
  CLOCK_EnableClock(*(undefined2 *)(&DAT_00087b3c + param_2 * 2));
  RESET_PeripheralReset((uint)*(ushort *)(&DAT_00087b3c + extraout_r1 * 2));
  return;
}


// ===== GPIO_PinInit @ 000841d8 (74 bytes)

void GPIO_PinInit(int param_1,int param_2,uint param_3,char *param_4)

{
  int extraout_r1;
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  CLOCK_EnableClock(*(undefined2 *)(&DAT_00087b3c + param_2 * 2));
  uVar2 = 1 << (param_3 & 0xff);
  if (*param_4 == '\0') {
    puVar3 = (uint *)(param_1 + extraout_r1 * 4 + 0x2000);
    uVar2 = *puVar3 & ~uVar2;
  }
  else {
    if (param_4[1] == '\0') {
      iVar1 = extraout_r1 + 0x8a0;
    }
    else {
      iVar1 = extraout_r1 + 0x880;
    }
    *(uint *)(param_1 + iVar1 * 4) = uVar2;
    puVar3 = (uint *)(param_1 + extraout_r1 * 4 + 0x2000);
    uVar2 = uVar2 | *puVar3;
  }
  *puVar3 = uVar2;
  return;
}


// ===== HASHCRYPT_DriverIRQHandler @ 00084228 (80 bytes)

/* IRQ59, base 0x40158000 [fact: vector] */

void HASHCRYPT_DriverIRQHandler(void)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  int hashcrypt_status;
  
  iVar1 = DAT_00088ab0;
                    /* Indicates status of Hash peripheral [sfr] */
  hashcrypt_status = HASHCRYPT_STATUS;
  if (hashcrypt_status << 0x1d < 0) {
    uVar2 = 1;
  }
  else {
    uVar4 = *(uint *)(DAT_00088ab0 + 0x4c);
    if (uVar4 != 0) {
      uVar3 = 0x7ff;
      if (uVar4 < 0x800) {
        uVar3 = uVar4;
      }
      *(uint *)(DAT_00088ab0 + 0x4c) = uVar4 - uVar3;
                    /* Setup Master to access memory (if available) [sfr] */
      HASHCRYPT_MEMCTRL = uVar3 << 0x10 | 1;
      return;
    }
                    /* Write 1 to clear interrupts [sfr] */
    HASHCRYPT_INTENCLR = 6;
    HASHCRYPT_MEMCTRL = 0;
                    /* n = 5 if ctx byte +0x44 == 1 [doc, inference] */
    hashcrypt_save_running_hash(0x40158000,DAT_00088ab0);
    uVar2 = 0;
  }
  if (*(code **)(iVar1 + 0x50) == (code *)0x0) {
    return;
  }
                    /* WARNING: Could not recover jumptable at 0x00084272. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (**(code **)(iVar1 + 0x50))(&HASHCRYPT_CTRL,iVar1,uVar2,*(undefined4 *)(iVar1 + 0x54));
  return;
}


// ===== I3C0_DriverIRQHandler @ 00084280 (52 bytes)

/* IRQ49, base 0x40036000 [fact: vector] */

void I3C0_DriverIRQHandler(void)

{
  uint i3c_mconfig;
  int i3c_sconfig;
  
                    /* Master Configuration [sfr] */
  i3c_mconfig = I3C_MCONFIG;
  if (((i3c_mconfig & 3) == 1) && (DAT_00088ab8 != (code *)0x0)) {
    (*DAT_00088ab8)(&I3C_MCONFIG,DAT_00088ab4);
  }
                    /* Slave Configuration [sfr] */
  i3c_sconfig = I3C_SCONFIG;
  if ((i3c_sconfig << 0x1f < 0) && (DAT_00088ac0 != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x000842b0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*DAT_00088ac0)(&I3C_MCONFIG,DAT_00088abc);
    return;
  }
  return;
}


// ===== MU_Init @ 000842c8 (10 bytes)

void MU_Init(void)

{
                    /* clock set 1 [sfr] */
  CLKCTL1_PSCCTL1_SET = 0x10000000;
  return;
}


// ===== OS_EVENT_DriverIRQHandler @ 000842d8 (12 bytes)

/* IRQ41, OSTIMER 0x40113000 [fact: vector] */

void OS_EVENT_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x000842e2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088ac8)(&OSTIMER0_EVTIMERL,DAT_00088ac4);
  return;
}


// ===== PIN_INT0_DriverIRQHandler @ 000842f0 (40 bytes)

/* IRQ4, PINT 0x40025000 [fact: vector] */

void PIN_INT0_DriverIRQHandler(void)

{
  undefined4 uVar1;
  uint pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  if (DAT_00088acc != (code *)0x0) {
    (*DAT_00088acc)(0,uVar1);
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if ((pint_isel & 1) == 0) {
    PINT_PinInterruptClrStatus();
    return;
  }
  return;
}


// ===== PIN_INT1_DriverIRQHandler @ 00084320 (40 bytes)

/* IRQ5 [fact: vector] */

void PIN_INT1_DriverIRQHandler(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 in_r3;
  int pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  uVar2 = extraout_r2;
  if (DAT_00088ad0 != (code *)0x0) {
    (*DAT_00088ad0)(1,uVar1);
    uVar2 = extraout_r2_00;
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if (-1 < pint_isel << 0x1e) {
    PINT_PinInterruptClrStatus(&PINT_ISEL,1,uVar2,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT2_DriverIRQHandler @ 00084350 (40 bytes)

/* IRQ6 [fact: vector] */

void PIN_INT2_DriverIRQHandler(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 in_r3;
  int pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  uVar2 = extraout_r2;
  if (DAT_00088ad4 != (code *)0x0) {
    (*DAT_00088ad4)(2,uVar1);
    uVar2 = extraout_r2_00;
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if (-1 < pint_isel << 0x1d) {
    PINT_PinInterruptClrStatus(&PINT_ISEL,2,uVar2,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT3_DriverIRQHandler @ 00084380 (40 bytes)

/* IRQ7 [fact: vector] */

void PIN_INT3_DriverIRQHandler(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 in_r3;
  int pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  uVar2 = extraout_r2;
  if (DAT_00088ad8 != (code *)0x0) {
    (*DAT_00088ad8)(3,uVar1);
    uVar2 = extraout_r2_00;
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if (-1 < pint_isel << 0x1c) {
    PINT_PinInterruptClrStatus(&PINT_ISEL,3,uVar2,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT4_DriverIRQHandler @ 000843b0 (40 bytes)

/* IRQ35 [fact: vector] */

void PIN_INT4_DriverIRQHandler(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 in_r3;
  int pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  uVar2 = extraout_r2;
  if (DAT_00088adc != (code *)0x0) {
    (*DAT_00088adc)(4,uVar1);
    uVar2 = extraout_r2_00;
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if (-1 < pint_isel << 0x1b) {
    PINT_PinInterruptClrStatus(&PINT_ISEL,4,uVar2,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT5_DriverIRQHandler @ 000843e0 (40 bytes)

/* IRQ36 [fact: vector] */

void PIN_INT5_DriverIRQHandler(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 in_r3;
  int pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  uVar2 = extraout_r2;
  if (DAT_00088ae0 != (code *)0x0) {
    (*DAT_00088ae0)(5,uVar1);
    uVar2 = extraout_r2_00;
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if (-1 < pint_isel << 0x1a) {
    PINT_PinInterruptClrStatus(&PINT_ISEL,5,uVar2,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT6_DriverIRQHandler @ 00084410 (40 bytes)

/* IRQ37 [fact: vector] */

void PIN_INT6_DriverIRQHandler(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 in_r3;
  int pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  uVar2 = extraout_r2;
  if (DAT_00088ae4 != (code *)0x0) {
    (*DAT_00088ae4)(6,uVar1);
    uVar2 = extraout_r2_00;
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if (-1 < pint_isel << 0x19) {
    PINT_PinInterruptClrStatus(&PINT_ISEL,6,uVar2,in_r3);
    return;
  }
  return;
}


// ===== PIN_INT7_DriverIRQHandler @ 00084440 (40 bytes)

/* IRQ38 [fact: vector] */

void PIN_INT7_DriverIRQHandler(void)

{
  undefined4 uVar1;
  undefined4 extraout_r2;
  undefined4 extraout_r2_00;
  undefined4 uVar2;
  undefined4 in_r3;
  int pint_isel;
  
  uVar1 = PINT_PatternMatchResetDetectLogic(&PINT_ISEL);
  uVar2 = extraout_r2;
  if (DAT_00088ae8 != (code *)0x0) {
    (*DAT_00088ae8)(7,uVar1);
    uVar2 = extraout_r2_00;
  }
                    /* Pin Interrupt Mode [sfr] */
  pint_isel = PINT_ISEL;
  if (-1 < pint_isel << 0x18) {
    PINT_PinInterruptClrStatus(&PINT_ISEL,7,uVar2,in_r3);
    return;
  }
  return;
}


// ===== POWER_ApplyPD @ 00084470 (24 bytes)

/* Wait PMC STATUS busy, PMC CTRL |= APPLYCFG, wait [inference] */

void POWER_ApplyPD(void)

{
  int iVar1;
  uint pmc_ctrl;
  
  do {
    iVar1 = PMC_STATUS;
  } while (iVar1 << 0x1f < 0);
                    /* PMC control [sfr] */
  pmc_ctrl = PMC_CTRL;
  PMC_CTRL = pmc_ctrl | 1;
  do {
    iVar1 = PMC_STATUS;
  } while (iVar1 << 0x1f < 0);
  return;
}


// ===== POWER_UpdateOscSettlingTime @ 0008448c (6 bytes)

/* Stores osc settling time (us) at 0x80A58, read by POWER_EnterDeepSleep [inference] */

void POWER_UpdateOscSettlingTime(uint param_1)

{
  DAT_00080a58 = param_1;
  return;
}


// ===== RESET_SetPeripheralReset @ 00084498 (96 bytes)

/* PRSTCTLn_SET and wait [inference] */

void RESET_SetPeripheralReset(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_1 & 0xff);
  switch(param_1 >> 8) {
  case 0:
                    /* peripheral reset set 0 [sfr] */
    RSTCTL0_PRSTCTL0_SET = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL0;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 1:
                    /* peripheral reset set 1 [sfr] */
    RSTCTL0_PRSTCTL1_SET = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL1;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 2:
                    /* peripheral reset set 2 [sfr] */
    RSTCTL0_PRSTCTL2_SET = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL2;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 3:
                    /* peripheral reset set 0 [sfr] */
    RSTCTL1_PRSTCTL0_SET = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL0;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 4:
                    /* peripheral reset set 1 [sfr] */
    RSTCTL1_PRSTCTL1_SET = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL1;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 5:
                    /* peripheral reset set 2 [sfr] */
    RSTCTL1_PRSTCTL2_SET = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL2;
    } while ((uVar1 & uVar2) == 0);
  }
  return;
}


// ===== RESET_ClearPeripheralReset @ 00084504 (108 bytes)

/* NEW (entries_m33.tsv): byte-identical to RESET_ClearPeripheralReset of mcux-sdk MCUX_2.11.0
   devices/MIMXRT685S/drivers/fsl_reset.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)];
   DSP_Init and RESET_PeripheralReset call it [fact: 0x84504] (T24 round 2) */

void RESET_ClearPeripheralReset(uint peripheral)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1 << (peripheral & 0xff);
  switch(peripheral >> 8) {
  case 0:
                    /* peripheral reset clear 0 [sfr] */
    RSTCTL0_PRSTCTL0_CLR = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL0;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 1:
                    /* peripheral reset clear 1 [sfr] */
    RSTCTL0_PRSTCTL1_CLR = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL1;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 2:
                    /* peripheral reset clear 2 [sfr] */
    RSTCTL0_PRSTCTL2_CLR = uVar2;
    do {
      uVar1 = RSTCTL0_PRSTCTL2;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 3:
                    /* peripheral reset clear 0 [sfr] */
    RSTCTL1_PRSTCTL0_CLR = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL0;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 4:
                    /* peripheral reset clear 1 [sfr] */
    RSTCTL1_PRSTCTL1_CLR = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL1;
    } while ((uVar2 & ~uVar1) == 0);
    return;
  case 5:
                    /* peripheral reset clear 2 [sfr] */
    RSTCTL1_PRSTCTL2_CLR = uVar2;
    do {
      uVar1 = RSTCTL1_PRSTCTL2;
    } while ((uVar2 & ~uVar1) == 0);
  }
  return;
}


// ===== SCTIMER_EventHandleIRQ @ 0008457c (48 bytes)

/* NEW (entries_m33.tsv): byte-identical to SCTIMER_EventHandleIRQ of mcux-sdk MCUX_2.11.0
   drivers/sctimer/fsl_sctimer.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)] (T24 round 2)
    */

void SCTIMER_EventHandleIRQ(void *base)

{
  uint uVar1;
  int i;
  uint uVar2;
  
  i = 0;
                    /* SCT event flag [sfr] */
  uVar1 = SCT0_EVFLAG;
                    /* SCT event interrupt enable [sfr] */
  uVar2 = SCT0_EVEN;
  uVar2 = uVar2 & uVar1;
  do {
    if (((int)(uVar1 << 0x1f) < 0) && ((code *)(&DAT_00088afc)[i] != (code *)0x0)) {
      base = (void *)(*(code *)(&DAT_00088afc)[i])(base);
    }
    uVar1 = uVar1 >> 1;
  } while ((uVar1 != 0) && (i = i + 1, i != 0x10));
  SCT0_EVFLAG = uVar2;
  return;
}


// ===== SCTIMER_Init @ 000845b4 (154 bytes)

undefined4 SCTIMER_Init(uint *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int i;
  
                    /* clock set 0 [sfr] */
  CLKCTL0_PSCCTL0_SET = 0x1000000;
  RESET_PeripheralReset(0x18);
  bVar1 = *param_2;
  *param_1 = (param_2[2] & 0xf) << 3 | (param_2[1] & 3) << 1 | (uint)bVar1 | (param_2[8] & 0xf) << 9
  ;
  param_1[1] = (uint)param_2[5] << 5 | (uint)param_2[3] << 4 | 4;
  param_1[1] = param_1[1] | 8;
  if (bVar1 == 0) {
    param_1[1] = (uint)param_2[6] << 0x15 | (uint)param_2[4] << 0x14 | param_1[1] | 0x40000;
    param_1[1] = param_1[1] | 0x80000;
  }
  param_1[0x14] = (uint)param_2[7];
  i = 0;
  DAT_00088aec = 0;
  DAT_00088af8 = 0;
  DAT_00088af0 = 0;
  DAT_00088af4 = 0;
  puVar2 = &DAT_00088afc;
  do {
    i = i + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (i != 0x10);
  DAT_00088b3c = 0x8457d;
  return 0;
}


// ===== SCTIMER_CreateAndScheduleEvent @ 00084670 (250 bytes)

/* Used by SCTIMER_SetupPwm; s_currentEvent/Match at 0x88AEC.. [inference] */

byte SCTIMER_CreateAndScheduleEvent
               (int *param_1,uint param_2,int param_3,uint param_4,char param_5,uint *param_6)

{
  undefined2 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = DAT_00088af4;
  uVar4 = DAT_00088af0;
  if (0xf < DAT_00088aec) {
    return 1;
  }
  uVar5 = (param_2 & 0x3fff) >> 0xc;
  if (uVar5 == 2) {
    param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | (param_4 & 0xf) << 6;
  }
  else {
    if ((uVar5 == 0) || (uVar5 == 3)) {
      param_2 = param_2 | (param_4 & 0xf) << 6;
    }
    uVar1 = (undefined2)param_3;
    if (param_5 == '\x01') {
      if (*param_1 << 0x1f < 0) {
        return 1;
      }
      if (0xf < DAT_00088af0) {
        return 1;
      }
      *(undefined2 *)(param_1 + DAT_00088af0 + 0x40) = uVar1;
      *(undefined2 *)(param_1 + DAT_00088af0 + 0x80) = uVar1;
      uVar4 = param_2 | DAT_00088af0;
      DAT_00088af0 = DAT_00088af0 + 1;
      param_1[(DAT_00088aec + 0x60) * 2 + 1] = uVar4;
    }
    else {
      if (param_5 == '\x02') {
        if ((*param_1 << 0x1f < 0) || (piVar3 = (int *)&DAT_00088af4, 0xf < DAT_00088af4)) {
          return 1;
        }
        uVar4 = DAT_00088af4 | param_2;
        *(undefined2 *)((int)param_1 + DAT_00088af4 * 4 + 0x102) = uVar1;
        *(undefined2 *)((int)param_1 + uVar2 * 4 + 0x202) = uVar1;
        param_1[(DAT_00088aec + 0x60) * 2 + 1] = uVar4 | 0x10;
        uVar4 = uVar2;
      }
      else {
        if (param_5 != '\x04') {
          return 1;
        }
        if (-1 < *param_1 << 0x1f) {
          return 1;
        }
        piVar3 = (int *)&DAT_00088af0;
        if (0xf < DAT_00088af0) {
          return 1;
        }
        param_1[DAT_00088af0 + 0x40] = param_3;
        param_1[uVar4 + 0x80] = param_3;
        param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | uVar4;
      }
      *piVar3 = uVar4 + 1;
    }
  }
  param_1[(DAT_00088aec + 0x60) * 2] = 1 << (DAT_00088af8 & 0xff);
  *param_6 = DAT_00088aec;
  DAT_00088aec = DAT_00088aec + 1;
  return 0;
}


// ===== SCTIMER_SetupPwm @ 0008477c (344 bytes)

uint SCTIMER_SetupPwm(int param_1,byte *param_2,int param_3,uint param_4,uint param_5,uint *param_6)

{
  byte SCTIMER_CreateAndScheduleEvent_ret;
  byte SCTIMER_CreateAndScheduleEvent_ret_2;
  int iVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  ulonglong __aeabi_uldivmod_ret;
  uint local_28;
  uint local_24 [2];
  
  local_28 = 0;
  local_24[0] = 0;
  if (0x10 < DAT_00088aec + 2U) {
    return 1;
  }
  uVar2 = param_5 / (((*(uint *)(param_1 + 4) & 0x1fff) >> 5) + 1);
  if (param_3 == 1) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
  }
  else if (param_3 == 0) {
    uVar2 = uVar2 / param_4 - 1;
    goto LAB_000847cc;
  }
  uVar2 = uVar2 / (param_4 << 1);
LAB_000847cc:
  if (param_2[2] < 100) {
    __aeabi_uldivmod_ret = __aeabi_uldivmod((ulonglong)(uint)param_2[2] * (ulonglong)uVar2,100);
    iVar1 = (int)__aeabi_uldivmod_ret;
  }
  else if (param_3 == 0) {
    iVar1 = uVar2 + 2;
  }
  else {
    iVar1 = uVar2 - 1;
  }
  SCTIMER_CreateAndScheduleEvent_ret =
       SCTIMER_CreateAndScheduleEvent((int *)param_1,0x1000,uVar2,0,'\x04',&local_28);
  SCTIMER_CreateAndScheduleEvent_ret_2 =
       SCTIMER_CreateAndScheduleEvent((int *)param_1,0x1000,iVar1,0,'\x04',local_24);
  if (SCTIMER_CreateAndScheduleEvent_ret_2 != 0 || SCTIMER_CreateAndScheduleEvent_ret != 0) {
    return 1;
  }
  uVar4 = 1 << (local_28 & 0xff);
  *(uint *)(param_1 + 8) = uVar4 & 0xffff | *(uint *)(param_1 + 8);
  *param_6 = local_28;
  uVar2 = (uint)*param_2;
  uVar3 = 1 << (local_24[0] & 0xff);
  if (param_2[1] == 1) {
    iVar1 = uVar2 * 8 + param_1;
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & ~(1 << uVar2);
    if (param_3 == 0) {
      *(uint *)(iVar1 + 0x500) = uVar4 | *(uint *)(iVar1 + 0x500);
      *(uint *)(iVar1 + 0x504) = uVar3 | *(uint *)(iVar1 + 0x504);
      return 0;
    }
    *(uint *)(iVar1 + 0x504) = uVar3 | *(uint *)(iVar1 + 0x504);
    uVar2 = 1 << (uVar2 << 1 & 0xff) | *(uint *)(param_1 + 0x54) & ~(3 << (uVar2 << 1 & 0xff));
  }
  else {
    iVar1 = uVar2 * 8 + param_1;
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 1 << uVar2;
    if (param_3 == 0) {
      *(uint *)(iVar1 + 0x504) = uVar4 | *(uint *)(iVar1 + 0x504);
      *(uint *)(iVar1 + 0x500) = uVar3 | *(uint *)(iVar1 + 0x500);
      return 0;
    }
    *(uint *)(iVar1 + 0x500) = uVar3 | *(uint *)(iVar1 + 0x500);
    uVar2 = 1 << (uVar2 << 1 & 0xff) | *(uint *)(param_1 + 0x54) & ~(3 << (uVar2 << 1 & 0xff));
  }
  *(uint *)(param_1 + 0x54) = uVar2;
  return 0;
}


// ===== SCTIMER_SetCallback @ 000848d8 (8 bytes)

void SCTIMER_SetCallback(undefined4 param_1,undefined4 param_2,int param_3)

{
  (&DAT_00088afc)[param_3] = param_2;
  return;
}


// ===== SCT0_DriverIRQHandler @ 000848e4 (8 bytes)

/* IRQ12: calls the callback at 0x88B3C with SCT0 (sct0_pwm_callback); the only active one of these
   [fact] */

void SCT0_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x000848ea. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b3c)(&SCT0_CONFIG);
  return;
}


// ===== SEMA42_Init @ 000848f4 (10 bytes)

void SEMA42_Init(void)

{
                    /* clock set 1 [sfr] */
  CLKCTL1_PSCCTL1_SET = 0x20000000;
  return;
}


// ===== USDHC0_DriverIRQHandler @ 00084904 (12 bytes)

/* IRQ45 [fact: vector] */

void USDHC0_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x0008490e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b48)(&USDHC0_DS_ADDR,DAT_00088b40);
  return;
}


// ===== USDHC1_DriverIRQHandler @ 0008491c (12 bytes)

/* IRQ46 [fact: vector] */

void USDHC1_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x00084926. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b48)(&USDHC1_DS_ADDR,DAT_00088b44);
  return;
}


// ===== UTICK0_DriverIRQHandler @ 00084934 (12 bytes)

/* IRQ8 [fact: vector] */

void UTICK0_DriverIRQHandler(void)

{
                    /* WARNING: Could not recover jumptable at 0x0008493e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_00088b50)(&UTICK0_CTRL,DAT_00088b4c);
  return;
}


// ===== BOARD_BootClockRUN @ 0008494c (204 bytes)

void BOARD_BootClockRUN(void)

{
  uint clkctl1_audiopll0ctl0;
  
                    /* Run configuration 0 clear [sfr] */
  SYSCTL0_PDRUNCFG0_CLR = 0x4000;
  SYSCTL0_PDRUNCFG0_CLR = 0x10000;
  CLOCK_EnableFfroClk(0);
  SYSCTL0_PDRUNCFG0_CLR = 0x8000;
  CLOCK_EnableSfroClk();
  BOARD_FlexspiClockSafeConfig();
  CLOCK_AttachClk(0x4343430);
  SYSCTL0_PDRUNCFG0_CLR = 0x2000;
  POWER_UpdateOscSettlingTime(0x104);
  CLOCK_EnableSysOscClk(1,1,0x104);
  DAT_00088930 = 24000000;
  DAT_00088928 = 0x1194000;
                    /* system oscillator bypass [sfr] */
  CLKCTL0_SYSOSCBYPASS = 1;
  CLOCK_InitSysPll(&DAT_00087a08);
  CLOCK_InitSysPfd(0,0xc);
  CLOCK_InitSysPfd(2,0x18);
  CLOCK_InitAudioPll(&DAT_000879f8);
                    /* audio pll0 control0 [sfr] */
  clkctl1_audiopll0ctl0 = CLKCTL1_AUDIOPLL0CTL0;
  CLKCTL1_AUDIOPLL0CTL0 = clkctl1_audiopll0ctl0 | 1;
  CLOCK_InitAudioPfd(0,0x1a);
  CLOCK_SetClkDiv(0x400,3);
  CLOCK_AttachClk(0x2434);
  CLOCK_SetClkDiv(0x80000240,1);
  CLOCK_SetClkDiv(0x500,2);
  CLOCK_SetClkDiv(0x800006fc,0xc);
  BOARD_SetFlexspiClock(1,6);
  DAT_00087ec0 = 198000000;
  return;
}


// ===== ipc_init @ 00084a50 (46 bytes)

void ipc_init(void)

{
  DAT_00088b60 = rpmsg_lite_master_init(0x20020000,0x20000,0);
  DAT_00088b5c = rpmsg_queue_create();
  DAT_00088b58 = rpmsg_lite_create_ept((int)DAT_00088b60,0x28,0x861b9,DAT_00088b5c);
  DAT_00088b54 = 0x1e;
  return;
}


// ===== ipc_send @ 00084a8c (30 bytes)

void ipc_send(uint param_1)

{
                    /* blocking send with 1-tick retry [doc] */
  rpmsg_lite_send(DAT_00088b60,DAT_00088b58,DAT_00088b54,param_1,0x98,0xffffffff);
  return;
}

