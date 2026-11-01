// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== IAP_FlexspiNorAutoConfig @ 0008000c (32 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* r6 = ROM API tree 0x1303F000 (FSL_ROM_API_BASE_ADDR); calls tree->flexspiNorDriver (+0x1C)
   ->get_config (+0x1C) with r0..r2 unchanged, and if it returns 0 tail-calls ->init (+4) with r0,r1
   [fact: 0x8000C-0x8002A]. Same calls in the same order as IAP_FlexspiNorAutoConfig in
   mcux-sdk@8a289764 devices/MIMXRT685S/drivers/fsl_iap.c (that version adds a 10000-count delay
   loop first) [inference]. No BL/B.W/literal reference anywhere in the image [fact: branch+literal
   scan] */

void IAP_FlexspiNorAutoConfig(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = (**(code **)(_DAT_1303f01c + 0x1c))();
  if (iVar1 == 0) {
                    /* WARNING: Could not recover jumptable at 0x00080028. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(_DAT_1303f01c + 4))(param_1,param_2);
    return;
  }
  return;
}


// ===== POWER_SetBiasConfig @ 00080030 (24 bytes)

/* if PMC+0x20 != 0x04040808 write it; if PMC SLEEPCTRL (+0x14) != 10 write 10 [fact: 0x80030].
   Identical to static POWER_SetBiasConfig in mcux-sdk@8a289764
   devices/MIMXRT685S/drivers/fsl_power.c (CORELVL 0xA = 0.7 V deep sleep) [inference]. Called from
   0x80354, 0x8041C (POWER_EnterSleep_mode1/2) and 0x805AA (POWER_EnterDeepSleep) [fact] */

void POWER_SetBiasConfig(void)

{
  int iVar1;
  
                    /* body-bias (RBB/FBB) voltage level and RBB ... [sfr] */
  iVar1 = PMC_BIASCFG;
  if (iVar1 != 0x4040808) {
    PMC_BIASCFG = 0x4040808;
  }
                    /* PMC controls used during deep sleep mode [sfr] */
  iVar1 = PMC_SLEEPCTRL;
  if (iVar1 != 10) {
    PMC_SLEEPCTRL = 10;
  }
  return;
}


// ===== delay @ 00080050 (14 bytes)

/* fsl_power.c busy loop (count iterations) [inference] */

void delay(int param_1)

{
  int i;
  
  for (i = 0; i != param_1; i = i + 1) {
  }
  return;
}


// ===== deinitXip @ 0008005e (48 bytes)

/* WARNING: Removing unreachable block (ram,0x0008006a) */
/* WARNING: Removing unreachable block (ram,0x0008006c) */
/* WARNING: Removing unreachable block (ram,0x00080074) */
/* WARNING: Removing unreachable block (ram,0x0008007c) */
/* fsl_power.c: if running XIP (PC in 0x08xxxxxx) wait FlexSPI idle, MDIS, PSCCTL0_CLR FlexSPI clock
   [inference] */

void deinitXip(void)

{
  return;
}


// ===== countPartitionSwitches @ 0008009c (68 bytes)

/* returns 1 if any memory powered in PDRUNCFG1..3 is powered down in PDSLEEPCFG1..3 (masks
   0x1F000FFF, 0x3FFFFFFF, 0x3FFFFFFF), else 0 [fact: 0x8009C]. Same expression and masks as static
   countPartitionSwitches in mcux-sdk@8a289764 fsl_power.c; only caller 0x8018E is
   POWER_CalculateSafetyCount, as in the SDK [inference] */

bool countPartitionSwitches(void)

{
  uint uVar1;
  uint uVar2;
  
                    /* Run configuration 1 [sfr] */
  uVar2 = SYSCTL0_PDRUNCFG1;
                    /* Sleep configuration 1 [sfr] */
  uVar1 = SYSCTL0_PDSLEEPCFG1;
  if (((uVar2 ^ 0x1f000fff) & uVar1 & 0x1f000fff) == 0) {
    uVar2 = SYSCTL0_PDRUNCFG2;
    uVar1 = SYSCTL0_PDSLEEPCFG2;
    if (((uVar2 ^ 0x3fffffff) & uVar1 & 0x3fffffff) == 0) {
                    /* Run configuration 3 [sfr] */
      uVar2 = SYSCTL0_PDRUNCFG3;
                    /* Sleep configuration 3 [sfr] */
      uVar1 = SYSCTL0_PDSLEEPCFG3;
      return ((uVar2 ^ 0x3fffffff) & uVar1 & 0x3fffffff) != 0;
    }
  }
  return true;
}


// ===== POWER_CalculateSafetyCount @ 000800e8 (424 bytes)

/* WARNING: Removing unreachable block (ram,0x0008022a) */
/* WARNING: Removing unreachable block (ram,0x00080232) */
/* WARNING: Removing unreachable block (ram,0x00080244) */
/* WARNING: Removing unreachable block (ram,0x00080246) */
/* Real entry (movw r1,#0x21A; ldr r2,=SYSCTL0) that falls into 0x800EE; fsl_power.c deep-sleep
   wake-up safety count from PDRUNCFG/PDSLEEPCFG [inference] */

uint POWER_CalculateSafetyCount(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined *puVar3;
  int iVar4;
  undefined *puVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  int iVar11;
  bool bVar12;
  uint pmc_sleepctrl;
  int sysctl0_pdruncfg0;
  
                    /* Sleep configuration 0 [sfr] */
  uVar9 = SYSCTL0_PDSLEEPCFG0;
  bVar12 = (uVar9 & 0x10017d0) == 0x10017d0;
  if (bVar12) {
    param_1 = 0x21a;
  }
  iVar6 = 9000;
  if (!bVar12) {
    param_1 = 0x4c;
    iVar6 = 0;
  }
  uVar9 = SYSCTL0_PDSLEEPCFG0;
                    /* PMC controls used during run mode [sfr] */
  uVar1 = PMC_RUNCTRL;
                    /* PMC controls used during deep sleep mode [sfr] */
  pmc_sleepctrl = PMC_SLEEPCTRL;
  iVar7 = (uVar1 & 0x3f) - (pmc_sleepctrl & 0x3f);
                    /* Run configuration 0 [sfr] */
  uVar1 = SYSCTL0_PDRUNCFG0;
  if ((uVar9 & 0x10) == 0) {
    iVar2 = 0x4c;
    iVar10 = 0;
  }
  else {
    iVar10 = 1000;
    iVar2 = 0xe1f;
  }
  iVar4 = 0xceb;
  if ((uVar1 & 0x10) == 0) {
    iVar4 = 0x4c;
  }
  iVar11 = SYSCTL0_PDSLEEPCFG0;
  if (iVar11 << 0x14 < 0) {
    uVar9 = SYSCTL0_PDSLEEPCFG0;
    if ((uVar9 & 0x1000) == 0) {
      iVar11 = 0x1a71;
      puVar5 = (undefined *)0x0;
    }
    else {
      iVar11 = 0x4c;
      puVar5 = (undefined *)0x0;
    }
  }
  else {
    iVar11 = 0x1cd;
    puVar5 = &DAT_00006590;
  }
  bVar12 = countPartitionSwitches();
                    /* Sleep configuration 1 [sfr] */
  iVar8 = SYSCTL0_PDSLEEPCFG1;
  if (iVar8 < 0) {
    iVar8 = 8000;
  }
  else {
    iVar8 = 1000;
  }
  sysctl0_pdruncfg0 = SYSCTL0_PDRUNCFG0;
  iVar6 = (iVar8 * (1 - (uint)bVar12) + (uint)bVar12 * 47000 + 1000) / 0xd +
          iVar11 + iVar7 * 600 + (iVar7 * 32000 + 1000U) / 0xd + iVar6 + param_1 + iVar10 + iVar2 +
                   iVar4 + 0x1f9;
  puVar3 = puVar5 + iVar6 + 0x4c;
  if ((sysctl0_pdruncfg0 << 0x14 < 0) &&
     ((iVar7 = SYSCTL0_PDSLEEPCFG0, iVar7 << 0x14 < 0 ||
      (iVar7 = SYSCTL0_PDWAKECFG, -1 < iVar7 << 0x1f)))) {
    iVar6 = SYSCTL0_PDRUNCFG0;
    if (iVar6 << 0x13 < 0) {
      iVar6 = SYSCTL0_PDSLEEPCFG0;
      if (iVar6 << 0x13 < 0) {
        uVar9 = 1000;
      }
      else {
        uVar1 = SYSCTL0_PDWAKECFG;
        uVar9 = 0x4c2c0;
        if ((uVar1 & 2) == 0) {
          uVar9 = 1000;
        }
      }
    }
    else {
      uVar9 = 0x4c2c0;
    }
  }
  else {
    uVar9 = 5000;
    puVar3 = puVar5 + iVar6 + 0x3d4c4;
  }
  uVar1 = SYSCTL0_PDRUNCFG0;
  if (((~uVar1 & 0x10017d0) == 0) &&
     ((iVar6 = SYSCTL0_PDSLEEPCFG0, iVar6 << 0x13 < 0 ||
      (iVar6 = SYSCTL0_PDWAKECFG, -1 < iVar6 << 0x1e)))) {
    iVar6 = uVar9 / 0xd + 0x298;
  }
  else {
    iVar6 = uVar9 / 0xd + 0x98;
  }
                    /* FFRO control 0 [sfr] */
  uVar9 = CLKCTL0_FFROCTL0;
  if ((uVar9 & 0xc0000) == 0) {
    iVar7 = 0xc;
  }
  else {
    iVar7 = 0xf;
  }
  return (iVar7 * (int)(puVar3 + iVar6) + 999U) / 1000;
}


// ===== initFlexSPI @ 000802a8 (126 bytes)

/* fsl_power.c: FlexSPI enable, SWRESET, wait DLL lock (STS2) [inference]. Entry is the ldr at
   0x802A8 before the push (GCC clone initFlexSPI.constprop.0, byte-identical) [fact: T24
   (src/ifdsp_m33/status.tsv)]; Ghidra started it at 0x802AA, entries_m33.tsv moves it (T24 round 2)
    */

void initFlexSPI(void)

{
  dword dVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
                    /* Module Control 0 [sfr] */
  uVar3 = FLEXSPI_MCR0;
  FLEXSPI_MCR0 = uVar3 & 0xfffffffd;
  uVar3 = FLEXSPI_MCR0;
  FLEXSPI_MCR0 = uVar3 | 1;
  do {
    iVar4 = FLEXSPI_MCR0;
  } while (iVar4 << 0x1f < 0);
  dVar1 = FLEXSPI_DLLCRA;
  if ((int)(dVar1 << 0x1f) < 0) {
    uVar3 = FLEXSPI_STS2;
    dVar1 = FLEXSPI_FLSHA1CR0;
    if ((dVar1 & 0x7fffff) == 0) {
      dVar1 = FLEXSPI_FLSHA2CR0;
      uVar5 = 0;
      if ((dVar1 & 0x7fffff) != 0) {
        uVar5 = 3;
      }
    }
    else {
      uVar5 = 3;
    }
                    /* Flash Control 0 [sfr] */
    uVar2 = FLEXSPI_FLSHB1CR0;
    if (((uVar2 & 0x7fffff) != 0) || (uVar2 = FLEXSPI_FLSHB2CR0, (uVar2 & 0x7fffff) != 0)) {
      uVar5 = uVar5 | 0x30000;
    }
    iVar4 = 10;
    do {
      while( true ) {
                    /* Status 2 [sfr] */
        uVar2 = FLEXSPI_STS2;
        if ((uVar5 & ~uVar2) == 0) {
          iVar4 = 100;
          do {
            iVar4 = iVar4 + -1;
          } while (iVar4 != 0);
          return;
        }
        if (uVar2 == uVar3) break;
        iVar4 = 10;
        uVar3 = uVar2;
      }
      iVar4 = iVar4 + -1;
    } while (iVar4 != 0);
  }
  return;
}


// ===== initXip @ 0008032c (24 bytes)

/* WARNING: Removing unreachable block (ram,0x00080338) */
/* fsl_power.c: re-enable FlexSPI clock and initFlexSPI after deep sleep (body merged by Ghidra)
   [inference] */

void initXip(void)

{
  return;
}


// ===== POWER_EnterRbb @ 0008034c (182 bytes)

/* byte-identical to POWER_EnterRbb of mcux-sdk MCUX_2.11.0 fsl_power.c [fact: T24
   (src/ifdsp_m33/status.tsv, aliases.tsv)]. Was POWER_EnterSleep_mode1 (T24 round 2) */

void POWER_EnterRbb(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int nvic_iser1;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar4 = POWER_SetBiasConfig(uVar3);
                    /* The SCR controls features of entry [sfr] */
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 | 4;
                    /* Interrupt Set Enable [sfr] */
  nvic_iser1 = NVIC_ISER1;
                    /* Run configuration 0 [sfr] */
  uVar2 = SYSCTL0_PDRUNCFG0;
                    /* Sleep configuration 0 [sfr] */
  SYSCTL0_PDSLEEPCFG0 = uVar2 & 0xfffff7fe | 1;
                    /* Run configuration 1 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG1;
                    /* Sleep configuration 1 [sfr] */
  SYSCTL0_PDSLEEPCFG1 = uVar3;
                    /* Run configuration 2 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG2;
                    /* Sleep configuration 2 [sfr] */
  SYSCTL0_PDSLEEPCFG2 = uVar3;
                    /* Run configuration 3 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG3;
                    /* Sleep configuration 3 [sfr] */
  SYSCTL0_PDSLEEPCFG3 = uVar3;
                    /* PD Wake Configuration [sfr] */
  SYSCTL0_PDWAKECFG = 1;
                    /* Automatic wakeup from deepsleep / deep powerdown ... [sfr] */
  PMC_AUTOWKUP = 0x800;
                    /* PMC control [sfr] */
  uVar2 = PMC_CTRL;
  PMC_CTRL = uVar2 & 0xefcfffff | 0x10000000;
                    /* Start enable 1 set [sfr] */
  SYSCTL0_STARTEN1_SET = 0x4000000;
  if (-1 < nvic_iser1 << 5) {
    NVIC_ISER1 = 0x4000000;
  }
  WaitForInterrupt();
  PMC_CTRL = uVar2;
                    /* Wakeup, interrupt, and reset flags [sfr] */
  PMC_FLAGS = 0x10000000;
                    /* Start enable 1 clear [sfr] */
  SYSCTL0_STARTEN1_CLR = 0x4000000;
  SYSCTL0_PDWAKECFG = 0;
                    /* Interrupt Clear Pending [sfr] */
  NVIC_ICPR1 = 0x4000000;
  if (-1 < nvic_iser1 << 5) {
                    /* Interrupt Clear Enable [sfr] */
    NVIC_ICER1 = 0x4000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 & 0xfffffffb;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}


// ===== POWER_EnterFbb @ 00080414 (182 bytes)

/* byte-identical to POWER_EnterFbb of mcux-sdk MCUX_2.11.0 fsl_power.c [fact: T24
   (src/ifdsp_m33/status.tsv, aliases.tsv)]. Was POWER_EnterSleep_mode2 (T24 round 2) */

void POWER_EnterFbb(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int nvic_iser1;
  
  uVar3 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar3 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar4 = POWER_SetBiasConfig(uVar3);
                    /* The SCR controls features of entry [sfr] */
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 | 4;
                    /* Interrupt Set Enable [sfr] */
  nvic_iser1 = NVIC_ISER1;
                    /* Run configuration 0 [sfr] */
  uVar2 = SYSCTL0_PDRUNCFG0;
                    /* Sleep configuration 0 [sfr] */
  SYSCTL0_PDSLEEPCFG0 = uVar2 & 0xffffeffe | 1;
                    /* Run configuration 1 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG1;
                    /* Sleep configuration 1 [sfr] */
  SYSCTL0_PDSLEEPCFG1 = uVar3;
                    /* Run configuration 2 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG2;
                    /* Sleep configuration 2 [sfr] */
  SYSCTL0_PDSLEEPCFG2 = uVar3;
                    /* Run configuration 3 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG3;
                    /* Sleep configuration 3 [sfr] */
  SYSCTL0_PDSLEEPCFG3 = uVar3;
                    /* PD Wake Configuration [sfr] */
  SYSCTL0_PDWAKECFG = 2;
                    /* Automatic wakeup from deepsleep / deep powerdown ... [sfr] */
  PMC_AUTOWKUP = 0x800;
                    /* PMC control [sfr] */
  uVar2 = PMC_CTRL;
  PMC_CTRL = uVar2 & 0xefcfffff | 0x10000000;
                    /* Start enable 1 set [sfr] */
  SYSCTL0_STARTEN1_SET = 0x4000000;
  if (-1 < nvic_iser1 << 5) {
    NVIC_ISER1 = 0x4000000;
  }
  WaitForInterrupt();
  PMC_CTRL = uVar2;
                    /* Wakeup, interrupt, and reset flags [sfr] */
  PMC_FLAGS = 0x10000000;
                    /* Start enable 1 clear [sfr] */
  SYSCTL0_STARTEN1_CLR = 0x4000000;
  SYSCTL0_PDWAKECFG = 0;
                    /* Interrupt Clear Pending [sfr] */
  NVIC_ICPR1 = 0x4000000;
  if (-1 < nvic_iser1 << 5) {
                    /* Interrupt Clear Enable [sfr] */
    NVIC_ICER1 = 0x4000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 & 0xfffffffb;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return;
}


// ===== POWER_EnterNbb @ 000804dc (174 bytes)

/* byte-identical to POWER_EnterNbb of mcux-sdk MCUX_2.11.0 fsl_power.c [fact: T24
   (src/ifdsp_m33/status.tsv, aliases.tsv)]. Was POWER_EnterSleep_mode3 (T24 round 2) */

uint POWER_EnterNbb(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  uint uVar4;
  int nvic_iser1;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
                    /* The SCR controls features of entry [sfr] */
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 | 4;
                    /* Interrupt Set Enable [sfr] */
  nvic_iser1 = NVIC_ISER1;
                    /* Run configuration 0 [sfr] */
  uVar2 = SYSCTL0_PDRUNCFG0;
                    /* Sleep configuration 0 [sfr] */
  SYSCTL0_PDSLEEPCFG0 = uVar2 | 0x1801;
                    /* Run configuration 1 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG1;
                    /* Sleep configuration 1 [sfr] */
  SYSCTL0_PDSLEEPCFG1 = uVar3;
                    /* Run configuration 2 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG2;
                    /* Sleep configuration 2 [sfr] */
  SYSCTL0_PDSLEEPCFG2 = uVar3;
                    /* Run configuration 3 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG3;
                    /* Sleep configuration 3 [sfr] */
  SYSCTL0_PDSLEEPCFG3 = uVar3;
                    /* PD Wake Configuration [sfr] */
  SYSCTL0_PDWAKECFG = 3;
                    /* Automatic wakeup from deepsleep / deep powerdown ... [sfr] */
  PMC_AUTOWKUP = 0x800;
                    /* PMC control [sfr] */
  uVar2 = PMC_CTRL;
  PMC_CTRL = uVar2 & 0xefcfffff | 0x10000000;
                    /* Start enable 1 set [sfr] */
  SYSCTL0_STARTEN1_SET = 0x4000000;
  if (-1 < nvic_iser1 << 5) {
    NVIC_ISER1 = 0x4000000;
  }
  WaitForInterrupt();
  PMC_CTRL = uVar2;
                    /* Wakeup, interrupt, and reset flags [sfr] */
  PMC_FLAGS = 0x10000000;
                    /* Start enable 1 clear [sfr] */
  SYSCTL0_STARTEN1_CLR = 0x4000000;
  SYSCTL0_PDWAKECFG = 0;
                    /* Interrupt Clear Pending [sfr] */
  NVIC_ICPR1 = 0x4000000;
  if (-1 < nvic_iser1 << 5) {
                    /* Interrupt Clear Enable [sfr] */
    NVIC_ICER1 = 0x4000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 & 0xfffffffb;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar4 & 1) == 1);
  }
  return uVar4;
}


// ===== POWER_EnterDeepSleep @ 0008059c (852 bytes)

void POWER_EnterDeepSleep(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint *puVar4;
  undefined4 uVar5;
  int iVar6;
  uint uVar7;
  uint extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  uint uVar8;
  uint extraout_r2;
  uint uVar9;
  uint uVar10;
  bool bVar11;
  uint uVar12;
  uint uVar13;
  bool bVar14;
  uint clkctl0_mainclkselb;
  undefined4 clkctl0_syscpuahbclkdiv;
  uint clkctl1_dspcpuclksela;
  uint clkctl1_dspcpuclkselb;
  
  uVar9 = 0;
  bVar11 = (bool)isCurrentModePrivileged();
  if (bVar11) {
    uVar9 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar4 = (uint *)POWER_SetBiasConfig();
                    /* The SCR controls features of entry [sfr] */
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 | 4;
                    /* main clock selection A [sfr] */
  uVar2 = CLKCTL0_MAINCLKSELA;
                    /* main clock selection B [sfr] */
  clkctl0_mainclkselb = CLKCTL0_MAINCLKSELB;
                    /* DSP clock selection A [sfr] */
  clkctl1_dspcpuclksela = CLKCTL1_DSPCPUCLKSELA;
                    /* DSP clock selection B [sfr] */
  clkctl1_dspcpuclkselb = CLKCTL1_DSPCPUCLKSELB;
                    /* system cpu AHB clock divider [sfr] */
  clkctl0_syscpuahbclkdiv = CLKCTL0_SYSCPUAHBCLKDIV;
                    /* Run configuration 0 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG0;
                    /* Sleep configuration 0 [sfr] */
  SYSCTL0_PDSLEEPCFG0 = uVar3 & ~*puVar4 & 0xfffffff9 | ~*puVar4 & 0x3effffd1;
                    /* Run configuration 1 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG1;
                    /* Sleep configuration 1 [sfr] */
  SYSCTL0_PDSLEEPCFG1 = (uVar3 | 0x9f000fff) & ~puVar4[1];
                    /* Run configuration 2 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG2;
                    /* Sleep configuration 2 [sfr] */
  SYSCTL0_PDSLEEPCFG2 = (uVar3 | 0x3fffffff) & ~puVar4[2];
                    /* Run configuration 3 [sfr] */
  uVar3 = SYSCTL0_PDRUNCFG3;
                    /* Sleep configuration 3 [sfr] */
  SYSCTL0_PDSLEEPCFG3 = (uVar3 | 0x3fffffff) & ~puVar4[3];
                    /* PMIC power mode select control configuration [sfr] */
  PMC_PMICCFG = 0x73;
  uVar3 = SYSCTL0_PDSLEEPCFG0;
  SYSCTL0_PDSLEEPCFG0 = uVar3 | 2;
  uVar3 = SYSCTL0_PDSLEEPCFG0;
  bVar11 = false;
  if ((uVar3 & 1) != 0) {
    iVar6 = SYSCTL0_DSPSTALL;
    if (iVar6 == 0) {
      bVar11 = true;
                    /* DSP stall [sfr] */
      SYSCTL0_DSPSTALL = 1;
    }
    else {
      bVar11 = false;
    }
  }
                    /* Wakeup, interrupt, and reset flags [sfr] */
  uVar5 = PMC_FLAGS;
  PMC_FLAGS = uVar5;
                    /* Memory Sequencer Control [sfr] */
  uVar3 = PMC_MEMSEQCTRL;
  PMC_MEMSEQCTRL = uVar3 | 0x3f;
                    /* PMC control [sfr] */
  uVar3 = PMC_CTRL;
  PMC_CTRL = uVar3 & 0xffcfffff;
  iVar6 = SYSCTL0_PDRUNCFG0;
  bVar14 = iVar6 << 0xf < 0;
  if (bVar14) {
                    /* Run configuration 0 clear [sfr] */
    SYSCTL0_PDRUNCFG0_CLR = 0x10000;
                    /* fsl_power.c busy loop [doc, inference] */
    delay(0x960);
  }
  iVar6 = SYSCTL0_PDSLEEPCFG0;
  if (iVar6 << 0xf < 0) {
    SYSCTL0_MAINCLKSAFETY = 0;
  }
  else {
    uVar5 = POWER_CalculateSafetyCount();
                    /* Main Clock Safety [sfr] */
    SYSCTL0_MAINCLKSAFETY = uVar5;
  }
  deinitXip();
  CLKCTL0_MAINCLKSELA = 0;
  CLKCTL0_MAINCLKSELB = 0;
  CLKCTL1_DSPCPUCLKSELA = 0;
  CLKCTL1_DSPCPUCLKSELB = 0;
  CLKCTL0_SYSCPUAHBCLKDIV = 0;
  do {
    iVar6 = CLKCTL0_SYSCPUAHBCLKDIV;
  } while (iVar6 < 0);
  uVar12 = 0x2002;
  uVar10 = SYSCTL0_PDRUNCFG0;
  uVar8 = SYSCTL0_PDSLEEPCFG0;
  uVar10 = uVar10 ^ uVar8;
  uVar8 = uVar10 & 0x60000;
  if (uVar8 == 0) {
    uVar13 = 0;
  }
  else {
    uVar13 = 0x2002;
  }
  uVar7 = uVar10 & 0x1e0000;
  if ((uVar10 & 0x180000) == 0) {
    if (uVar8 == 0) {
      uVar10 = 0;
      uVar12 = 0;
      goto LAB_00080716;
    }
    uVar12 = 0;
LAB_000806f8:
                    /* sys pll0 PFD [sfr] */
    uVar8 = CLKCTL0_SYSPLL0PFD;
    uVar8 = ~uVar8 & 0x80808080;
    if ((uVar10 & 0x180000) == 0) {
      uVar10 = 0;
      goto LAB_00080716;
    }
  }
  else if (uVar8 != 0) goto LAB_000806f8;
                    /* audio pll0 PFD [sfr] */
  uVar10 = CLKCTL1_AUDIOPLL0PFD;
  uVar10 = ~uVar10 & 0x80808080;
LAB_00080716:
  uVar1 = CLKCTL0_SYSPLL0PFD;
  CLKCTL0_SYSPLL0PFD = uVar1 | uVar8;
  uVar1 = CLKCTL1_AUDIOPLL0PFD;
  CLKCTL1_AUDIOPLL0PFD = uVar1 | uVar10;
                    /* system pll0 control0 [sfr] */
  uVar10 = CLKCTL0_SYSPLL0CTL0;
  CLKCTL0_SYSPLL0CTL0 = uVar10 | uVar13;
                    /* audio pll0 control0 [sfr] */
  uVar10 = CLKCTL1_AUDIOPLL0CTL0;
  CLKCTL1_AUDIOPLL0CTL0 = uVar10 | uVar12;
                    /* Run configuration 0 set [sfr] */
  SYSCTL0_PDRUNCFG0_SET = uVar7;
  WaitForInterrupt();
  uVar1 = SYSCTL0_PDRUNCFG0;
  uVar10 = SYSCTL0_PDSLEEPCFG0;
  if (((uVar1 ^ uVar10) & 0x2000) != 0) {
    uVar10 = CLKCTL0_FFROCTL0;
    if ((uVar10 & 0xc0000) == 0) {
      iVar6 = 3;
    }
    else {
      iVar6 = 4;
    }
    delay(DAT_00080a58 * iVar6);
    uVar7 = extraout_r1;
  }
  if (uVar7 != 0) {
    SYSCTL0_PDRUNCFG0_CLR = uVar7;
    uVar7 = CLKCTL0_SYSPLL0LOCKTIMEDIV2;
    uVar10 = CLKCTL0_FFROCTL0;
    if ((uVar10 & 0xc0000) == 0) {
      iVar6 = 3;
    }
    else {
      iVar6 = 4;
    }
    delay(iVar6 * ((uVar7 & 0xffff) >> 1));
    *(uint *)(extraout_r1_00 + 0x204) = *(uint *)(extraout_r1_00 + 0x204) & ~(uVar13 & 2);
    uVar10 = CLKCTL1_AUDIOPLL0CTL0;
    CLKCTL1_AUDIOPLL0CTL0 = uVar10 & ~(uVar12 & 2);
    if ((*(uint *)(extraout_r1_00 + 0x100) & 0xc0000) == 0) {
      iVar6 = 3;
    }
    else {
      iVar6 = 4;
    }
    delay(iVar6 * ((*(uint *)(extraout_r1_00 + 0x20c) & 0xffff) / 6));
    iVar6 = 3;
    *(uint *)(extraout_r1_01 + 0x204) = *(uint *)(extraout_r1_01 + 0x204) & ~(uVar13 & 0x2000);
    uVar10 = CLKCTL1_AUDIOPLL0CTL0;
    CLKCTL1_AUDIOPLL0CTL0 = uVar10 & ~(uVar12 & 0x2000);
    if ((*(uint *)(extraout_r1_01 + 0x100) & 0xc0000) != 0) {
      iVar6 = 4;
    }
    delay(iVar6 * ((*(uint *)(extraout_r1_01 + 0x20c) & 0xffff) / 3));
    if (uVar8 != 0) {
      *(uint *)(extraout_r1_02 + 0x218) = *(uint *)(extraout_r1_02 + 0x218) & ~uVar8;
      do {
      } while ((*(uint *)(extraout_r1_02 + 0x218) & 0x40404040) != uVar8 >> 1);
    }
    if (extraout_r2 != 0) {
      uVar8 = CLKCTL1_AUDIOPLL0PFD;
      CLKCTL1_AUDIOPLL0PFD = uVar8 & ~extraout_r2;
      do {
        uVar8 = CLKCTL1_AUDIOPLL0PFD;
      } while ((uVar8 & 0x40404040) != extraout_r2 >> 1);
    }
  }
  CLKCTL0_SYSCPUAHBCLKDIV = clkctl0_syscpuahbclkdiv;
  do {
    iVar6 = CLKCTL0_SYSCPUAHBCLKDIV;
  } while (iVar6 < 0);
  CLKCTL0_MAINCLKSELA = uVar2 & 3;
  CLKCTL0_MAINCLKSELB = clkctl0_mainclkselb & 3;
  CLKCTL1_DSPCPUCLKSELA = clkctl1_dspcpuclksela & 3;
  CLKCTL1_DSPCPUCLKSELB = clkctl1_dspcpuclkselb & 3;
  if (bVar14) {
    SYSCTL0_PDRUNCFG0_SET = 0x10000;
  }
                    /* re-enable FlexSPI clock and initFlexSPI after deep sleep [doc, inference] */
  initXip();
  PMC_CTRL = uVar3;
  if (bVar11) {
    uVar2 = SYSCTL0_DSPSTALL;
    SYSCTL0_DSPSTALL = uVar2 & 0xfffffffe;
  }
  uVar2 = SCB_SCR;
  SCB_SCR = uVar2 & 0xfffffffb;
  bVar11 = (bool)isCurrentModePrivileged();
  if (bVar11) {
    enableIRQinterrupts((uVar9 & 1) == 1);
  }
  return;
}


// ===== BOARD_DeinitXip @ 00080914 (26 bytes)

/* Wait FlexSPI STS0 ARBIDLE+SEQIDLE, MCR0 |= MDIS [inference] */

void BOARD_DeinitXip(uint *param_1)

{
  do {
    do {
    } while (-1 < (int)(param_1[0x38] << 0x1e));
  } while (-1 < (int)(param_1[0x38] << 0x1f));
  *param_1 = *param_1 | 2;
  return;
}


// ===== BOARD_InitXip @ 0008092e (114 bytes)

/* MCR0 &= ~MDIS, SWRESET, wait DLL lock if DLLCR0 enabled, 100 NOPs [inference] */

void BOARD_InitXip(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  
  *param_1 = *param_1 & 0xfffffffd;
  *param_1 = *param_1 | 1;
  do {
  } while ((int)(*param_1 << 0x1f) < 0);
  if ((int)(param_1[0x30] << 0x1f) < 0) {
    uVar1 = param_1[0x3a];
    if ((param_1[0x18] & 0x7fffff) == 0) {
      uVar4 = 0;
      if ((param_1[0x19] & 0x7fffff) != 0) {
        uVar4 = 3;
      }
    }
    else {
      uVar4 = 3;
    }
    if (((param_1[0x1a] & 0x7fffff) != 0) || ((param_1[0x1b] & 0x7fffff) != 0)) {
      uVar4 = uVar4 | 0x30000;
    }
    do {
      iVar3 = 10;
      uVar2 = uVar1;
      while( true ) {
        uVar1 = param_1[0x3a];
        if ((uVar4 & ~uVar1) == 0) {
          iVar3 = 100;
          do {
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          return;
        }
        if (uVar2 != uVar1) break;
        iVar3 = iVar3 + -1;
        uVar2 = uVar1;
        if (iVar3 == 0) {
          return;
        }
      }
    } while( true );
  }
  return;
}


// ===== BOARD_SetFlexspiClock @ 000809a0 (108 bytes)

/* WARNING: Removing unreachable block (ram,0x000809c8) */
/* WARNING: Removing unreachable block (ram,0x00080a00) */
/* Replaces CLOCK_SetDiv_0x620. board.c: if FLEXSPIFCLKSEL/DIV (CLKCTL0 0x620/0x624) differ:
   BOARD_DeinitXip, PSCCTL0_CLR FlexSPI, set sel/div, PSCCTL0_SET, BOARD_InitXip [inference] */

void BOARD_SetFlexspiClock(uint param_1,int param_2)

{
  uint uVar1;
  int clkctl0_flexspifclkdiv;
  
                    /* FlexSPI FCLK selection [sfr] */
  uVar1 = CLKCTL0_FLEXSPIFCLKSEL;
  if ((uVar1 != (param_1 & 7)) || (uVar1 = CLKCTL0_FLEXSPIFCLKDIV, (uVar1 & 0xff) != param_2 - 1U))
  {
                    /* clock clear 0 [sfr] */
    CLKCTL0_PSCCTL0_CLR = 0x10000;
    CLKCTL0_FLEXSPIFCLKSEL = param_1 & 7;
                    /* FlexSPI FCLK divider [sfr] */
    uVar1 = CLKCTL0_FLEXSPIFCLKDIV;
    CLKCTL0_FLEXSPIFCLKDIV = uVar1 | 0x20000000;
    CLKCTL0_FLEXSPIFCLKDIV = param_2 - 1U & 0xff;
    do {
      clkctl0_flexspifclkdiv = CLKCTL0_FLEXSPIFCLKDIV;
    } while (clkctl0_flexspifclkdiv < 0);
                    /* clock set 0 [sfr] */
    CLKCTL0_PSCCTL0_SET = 0x10000;
  }
  return;
}


// ===== OTFAD_Init @ 00080a18 (44 bytes)

/* true entry of FUN_00080A24: CR bits from config bytes +1 (<<3 FLDM), +2 (<<7 RRAE), +3 (<<31 GE);
   waits until FLEXSPI(config+4)->STS0 & 3 == 3, then base->CR (+0xC00) |= bits [fact: 0x80A18].
   Same as OTFAD_Init in mcux-sdk@8a289764 drivers/otfad/fsl_otfad.c (RT685 config: forceSVM,
   forceLDM, restrictedRegAccess, enableOTFAD, flexspiBaseAddr) [inference]. No reference in the
   image [fact: branch+literal scan] */

void OTFAD_Init(int param_1,int param_2)

{
  do {
  } while ((*(uint *)(*(int *)(param_2 + 4) + 0xe0) & 3) != 3);
  *(uint *)(param_1 + 0xc00) =
       *(uint *)(param_1 + 0xc00) |
       (uint)*(byte *)(param_2 + 2) << 7 | (uint)*(byte *)(param_2 + 1) << 3 |
       (uint)*(byte *)(param_2 + 3) << 0x1f;
  return;
}


// ===== OTFAD_Deinit @ 00080a44 (14 bytes)

/* base->CR (+0xC00) &= ~0x80000000 (GE) [fact: 0x80A44]; same as OTFAD_Deinit in mcux-sdk@8a289764
   fsl_otfad.c [inference]. No reference in the image [fact: branch+literal scan] */

void OTFAD_Deinit(int param_1)

{
  *(uint *)(param_1 + 0xc00) = *(uint *)(param_1 + 0xc00) & 0x7fffffff;
  return;
}


// ===== vRestoreContextOfFirstTask @ 00080a60 (30 bytes)

/* NEW: PSPLIM/CONTROL=2/PSP from pxCurrentTCB (0x88800), bx to task; reached from vPortSVCHandler_C
   [inference] */

void vRestoreContextOfFirstTask(void)

{
  bool bVar1;
  char cVar2;
  undefined4 *puVar3;
  
  puVar3 = (undefined4 *)*DAT_00088800;
  setProcStackPointerLimit(*puVar3);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setThreadModePrivileged(1);
    bVar1 = (bool)isThreadMode();
    if (bVar1) {
      cVar2 = isUsingMainStack();
      setStackMode(cVar2 == '\x01');
    }
  }
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(puVar3 + 10);
  }
  InstructionSynchronizationBarrier(0xf);
                    /* WARNING: Could not recover jumptable at 0x00080a7c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)puVar3[1])(puVar3 + 10,2);
  return;
}


// ===== vStartFirstTask @ 00080a90 (24 bytes)

void vStartFirstTask(void)

{
  bool bVar1;
  undefined4 *puVar2;
  
                    /* Vector Table Offset [sfr] */
  puVar2 = (undefined4 *)SCB_VTOR;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(*puVar2);
  }
  enableIRQinterrupts();
  enableFIQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  do {
                    /* svc 2 does not return: SVC_Handler -> vPortSVCHandler_C ->
                       vRestoreContextOfFirstTask starts the first task (data_m33.tsv noflow; the
                       loop only marks the end of the flow) */
    software_interrupt(2);
  } while( true );
}


// ===== PendSV_Handler @ 00080ac0 (68 bytes)

void PendSV_Handler(void)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  undefined4 unaff_r4;
  undefined4 unaff_r5;
  undefined4 unaff_r6;
  undefined4 unaff_r7;
  undefined4 unaff_r8;
  undefined4 unaff_r9;
  undefined4 unaff_r10;
  undefined4 unaff_r11;
  undefined4 unaff_lr;
  
  iVar2 = getProcessStackPointer();
  uVar4 = getProcessStackPointerLimit();
  *(undefined4 *)(iVar2 + -4) = unaff_r11;
  *(undefined4 *)(iVar2 + -8) = unaff_r10;
  *(undefined4 *)(iVar2 + -0xc) = unaff_r9;
  *(undefined4 *)(iVar2 + -0x10) = unaff_r8;
  *(undefined4 *)(iVar2 + -0x14) = unaff_r7;
  *(undefined4 *)(iVar2 + -0x18) = unaff_r6;
  *(undefined4 *)(iVar2 + -0x1c) = unaff_r5;
  *(undefined4 *)(iVar2 + -0x20) = unaff_r4;
  *(undefined4 *)(iVar2 + -0x24) = unaff_lr;
  *(undefined4 *)(iVar2 + -0x28) = uVar4;
  *DAT_00088800 = iVar2 + -0x28;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0x40);
  }
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  vTaskSwitchContext();
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setBasePriority(0);
  }
  puVar3 = (undefined4 *)*DAT_00088800;
  setProcStackPointerLimit(*puVar3);
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setProcessStackPointer(puVar3 + 10);
  }
                    /* WARNING: Could not recover jumptable at 0x00080b02. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*(code *)puVar3[1])(puVar3 + 10,DAT_00088800,*puVar3);
  return;
}


// ===== SVC_Handler @ 00080b20 (18 bytes)

void SVC_Handler(void)

{
  undefined4 uVar1;
  uint unaff_lr;
  
  if ((unaff_lr & 4) == 0) {
    uVar1 = getMainStackPointer();
  }
  else {
    uVar1 = getProcessStackPointer();
  }
  vPortSVCHandler_C(uVar1);
  return;
}


// ===== delay_us @ 00080b44 (32 bytes)

void delay_us(int param_1)

{
  int iVar1;
  uint i;
  
  iVar1 = CLOCK_GetFreq(0);
  for (i = 0; i != (uint)(param_1 * iVar1) / 1000000; i = i + 1) {
  }
  return;
}


// ===== aic3204_spi_write @ 00080b68 (100 bytes)

void aic3204_spi_write(int param_1,uint param_2)

{
  uint uVar1;
  int i;
  
  uVar1 = param_2 | param_1 << 9;
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
  GPIO_B1_7 = 0;
                    /* Busy loop of n × core_clock / 1e6 iterations [doc, inference] */
  delay_us(1);
  i = 0x10;
  do {
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
    GPIO_B2_29 = 1;
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
    if ((int)(uVar1 << 0x10) < 0) {
      GPIO_B1_1 = 1;
    }
    else {
      GPIO_B1_1 = 0;
    }
    delay_us(1);
    GPIO_B2_29 = 0;
    delay_us(1);
    uVar1 = (uVar1 & 0xffff) << 1;
    i = i + -1;
  } while (i != 0);
  delay_us(1);
  GPIO_B1_7 = 1;
  delay_us(10);
  return;
}


// ===== aic3204_init @ 00080bd0 (72 bytes)

void aic3204_init(void)

{
  int i;
  byte *pbVar1;
  
  i = 0;
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
  GPIO_B1_0 = 0;
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
  GPIO_B1_7 = 0;
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
  GPIO_B2_29 = 0;
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
  GPIO_B1_1 = 0;
                    /* Busy loop of n × core_clock / 1e6 iterations [doc, inference] */
  delay_us(20000);
  GPIO_B1_0 = 1;
  delay_us(20000);
  pbVar1 = &DAT_00087a1c;
  do {
                    /* 16-bit word reg<<9 | val [doc] */
    aic3204_spi_write((uint)*pbVar1,(uint)pbVar1[1]);
    i = i + 1;
    delay_us((uint)*(ushort *)(pbVar1 + 2));
    pbVar1 = pbVar1 + 4;
  } while (i != 0x43);
  return;
}


// ===== regfile_clear @ 00080c20 (12 bytes)

void regfile_clear(void)

{
  memset(&DAT_20070000,0,0x10000);
  return;
}


// ===== regfile_read @ 00080c30 (22 bytes)

ushort regfile_read(int param_1)

{
  ushort uVar1;
  
  if (&DAT_20070000 + param_1 * 2 < (ushort *)0x20080000) {
    uVar1 = *(ushort *)(&DAT_20070000 + param_1 * 2);
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== regfile_write @ 00080c4c (40 bytes)

void regfile_write(int param_1,ushort param_2)

{
  if ((&DAT_20070000 + param_1 * 2 < (ushort *)0x20080000) &&
     (*(ushort *)(&DAT_20070000 + param_1 * 2) = param_2, param_1 == 10)) {
                    /* Page 1, R55 = 0x10 [doc] */
    aic3204_select_right_input((param_2 & 0xf) != 1);
    return;
  }
  return;
}


// ===== regfile_set_bits @ 00080c78 (40 bytes)

void regfile_set_bits(int param_1,ushort param_2)

{
  ushort *puVar1;
  
  puVar1 = (ushort *)(&DAT_20070000 + param_1 * 2);
  if (puVar1 < (ushort *)0x20080000) {
    vPortEnterCritical();
    *puVar1 = param_2 | *puVar1;
    vPortExitCritical();
    return;
  }
  return;
}


// ===== uart0_write @ 00080ca4 (94 bytes)

int uart0_write(int param_1,int param_2)

{
  undefined1 *puVar1;
  int iVar2;
  int usart0_fifointenset;
  
  if (DAT_000886d4 < 0x400) {
    vPortEnterCritical();
    iVar2 = 0;
    do {
      puVar1 = (undefined1 *)(param_1 + iVar2);
      iVar2 = iVar2 + 1;
      (&DAT_000882d4)[DAT_000886d8] = *puVar1;
      DAT_000886d8 = DAT_000886d8 + 1 & 0x3ff;
      DAT_000886d4 = DAT_000886d4 + 1;
      if (param_2 == iVar2) break;
    } while (DAT_000886d4 < 0x400);
                    /* FIFO interrupt enable set (enable) and read [sfr] */
    usart0_fifointenset = USART0_FIFOINTENSET;
    if (-1 < usart0_fifointenset << 0x1d) {
      USART0_FIFOINTENSET = 0xf;
    }
    vPortExitCritical();
  }
  else {
    iVar2 = 0;
  }
  return iVar2;
}


// ===== uart0_init @ 00080d0c (86 bytes)

void uart0_init(void)

{
  uint CLOCK_GetFlexCommClkFreq_ret;
  byte local_20 [4];
  undefined *local_1c [2];
  undefined2 local_14;
  
  local_20[0] = 0;
  local_20[1] = 1;
  local_20[2] = 0xff;
  local_20[3] = 0;
                    /* FRGnCLKSEL/FRGnCTL for FC0..7, 14, 15 [doc, inference] */
  CLOCK_SetFRGClock(local_20);
  CLOCK_AttachClk(0x80004508);
  USART_GetDefaultConfig(local_1c);
  local_1c[0] = &DAT_0001c200;
  local_14 = 0x101;
  CLOCK_GetFlexCommClkFreq_ret = CLOCK_GetFlexCommClkFreq(0);
  USART_Init(&USART0_CFG,local_1c,CLOCK_GetFlexCommClkFreq_ret);
  DAT_00087ec4 = xEventGroupCreate();
                    /* FIFO interrupt enable set (enable) and read [sfr] */
  USART0_FIFOINTENSET = 10;
                    /* Interrupt Set Enable [sfr] */
  NVIC_ISER0 = 0x4000;
  return;
}


// ===== CommandTask @ 00080d78 (152 bytes)

void CommandTask(void)

{
  byte bVar1;
  uint xEventGroupWaitBits_ret;
  
  console_init();
  vPortEnterCritical();
  DAT_000882d0 = 0;
  DAT_000882cc = 0;
  DAT_000882c8 = 0;
  vPortExitCritical();
  vPortEnterCritical();
  DAT_000886dc = 0;
  DAT_000886d8 = 0;
  DAT_000886d4 = 0;
  vPortExitCritical();
  uart0_init();
                    /* Byte pin registers for all port 0 and 1 GPIO pins [sfr] */
  GPIO_B2_5 = 1;
  do {
    do {
      xEventGroupWaitBits_ret = xEventGroupWaitBits(DAT_00087ec4,1,1,0,-1);
    } while (-1 < (int)(xEventGroupWaitBits_ret << 0x1f));
    while ((DAT_000886d4 < 0x400 && (DAT_000882c8 != 0))) {
      vPortEnterCritical();
      bVar1 = (&DAT_00087ec8)[DAT_000882d0];
      DAT_000882d0 = DAT_000882d0 + 1 & 0x3ff;
      DAT_000882c8 = DAT_000882c8 + -1;
      vPortExitCritical();
                    /* Line editor, tokenizer and both command interpreters [doc] */
      console_rx_char((uint)bVar1);
    }
  } while( true );
}


// ===== create_CommandTask @ 00080e20 (38 bytes)

void create_CommandTask(void)

{
  void *get_task_handles_ret;
  uint xTaskCreate_ret;
  
  get_task_handles_ret = get_task_handles();
  xTaskCreate_ret =
       xTaskCreate(0x80d79,0x87b4c,0x1800,(uint)get_task_handles_ret,1,get_task_handles_ret);
  if (xTaskCreate_ret != 1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== FLEXCOMM0_IRQHandler @ 00080e50 (172 bytes)

void FLEXCOMM0_IRQHandler(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  byte *pbVar1;
  undefined4 uVar2;
  uint xEventGroupSetBitsFromISR_ret;
  uint local_14;
  undefined4 uStack_10;
  uint usart0_fifostat;
  
                    /* FIFO status [sfr] */
  usart0_fifostat = USART0_FIFOSTAT;
  if ((usart0_fifostat & 0x42) != 0) {
    local_14 = usart0_fifostat & 2;
    if (local_14 == 0) {
      if (DAT_000882c8 < 0x400) {
                    /* FIFO read data [sfr] */
        uVar2 = USART0_FIFORD;
        DAT_000882c8 = DAT_000882c8 + 1;
        (&DAT_00087ec8)[DAT_000882cc] = (char)uVar2;
        DAT_000882cc = DAT_000882cc + 1 & 0x3ff;
        uStack_10 = param_3;
        xEventGroupSetBitsFromISR_ret = xEventGroupSetBitsFromISR(DAT_00087ec4,1,(uint)&local_14);
        if ((xEventGroupSetBitsFromISR_ret != 0) && (local_14 != 0)) {
                    /* Interrupt Control and State [sfr] */
          SCB_ICSR = 0x10000000;
        }
      }
    }
    else {
      uVar2 = USART0_FIFORD;
      USART0_FIFOSTAT = 2;
    }
  }
  if ((usart0_fifostat & 0x21) != 0) {
    if (DAT_000886d4 != 0) {
      pbVar1 = &DAT_000882d4 + DAT_000886dc;
      DAT_000886dc = DAT_000886dc + 1 & 0x3ff;
      DAT_000886d4 = DAT_000886d4 + -1;
      USART0_FIFOWR = (uint)*pbVar1;
      if (DAT_000886d4 != 0) {
        return;
      }
    }
                    /* FIFO interrupt enable clear (disable) and read [sfr] */
    USART0_FIFOINTENCLR = 5;
  }
  return;
}


// ===== uart0_printf @ 00080f0c (44 bytes)

/* NEW (entries_m33.tsv): byte-identical to uart0_printf of src/ifdsp_m33/app/uart.c (recreated)
   [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)]; vsprintf into 0x88C2C, then uart0_write
   [fact: 0x80F0C] (T24 round 2) */

void uart0_printf(char *format)

{
  int strlen_ret;
  undefined1 auStack_c [12];
  
  vsprintf(&DAT_00088c2c,format,auStack_c);
  strlen_ret = strlen((uint *)&DAT_00088c2c);
                    /* Copy bytes into the TX ring [doc] */
  uart0_write(&DAT_00088c2c,strlen_ret);
  return;
}


// ===== uart0_tx_pending @ 00080f3c (14 bytes)

bool uart0_tx_pending(void)

{
  return DAT_000886d4 != 0;
}


// ===== IpcSendTask @ 00080f50 (42 bytes)

void IpcSendTask(void)

{
  int iVar1;
  undefined1 auStack_a0 [156];
  
  do {
    do {
      iVar1 = xQueueReceive(DAT_000886e0,auStack_a0,0xffffffff);
    } while (iVar1 != 1);
    ipc_send((uint)auStack_a0);
    ulTaskNotifyTake(1,0xffffffff);
  } while( true );
}


// ===== create_IpcTasks @ 00080f80 (82 bytes)

void create_IpcTasks(void)

{
  void *get_task_handles_ret;
  uint uVar1;
  
  DAT_000886e0 = xQueueGenericCreate(8,0x98,0);
  get_task_handles_ret = get_task_handles();
  uVar1 = xTaskCreate(0x85fc7,0x87b5d,0x1800,(uint)get_task_handles_ret,2,
                      (int *)((int)get_task_handles_ret + 8));
  if (uVar1 != 1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  uVar1 = xTaskCreate(0x80f51,0x87b69,0x1800,(uint)get_task_handles_ret,2,
                      (int *)((int)get_task_handles_ret + 4));
  if (uVar1 != 1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== ipc_print_dsp_reply @ 00080fe8 (86 bytes)

void ipc_print_dsp_reply(int param_1)

{
  char cVar1;
  char *pcVar2;
  
  cVar1 = *(char *)(param_1 + 8);
  if (cVar1 == '\x01') {
    if (*(char *)(param_1 + 0xc) == '\0') {
      if (*(int *)(param_1 + 0x14) == 0) {
        if (*(int *)(param_1 + 0x18) == 0) {
          pcVar2 = "\r\nMute off\r\n>> ";
        }
        else {
          pcVar2 = "\r\nMute on\r\n>> ";
        }
        goto LAB_00080ffa;
      }
      pcVar2 = "\r\nMute error (%d)\r\n>> ";
    }
    else {
      pcVar2 = "\r\nIncoming unknown message category %d\r\n>> ";
    }
  }
  else {
    if (cVar1 != '\x03') {
      if (cVar1 != '\0') {
        return;
      }
      if (*(char *)(param_1 + 0xc) != '\0') {
        uart0_printf("Incoming unknown message command %d from category %d\r\n");
        return;
      }
      pcVar2 = "Component versions from DSP:\r\n";
LAB_00080ffa:
                    /* formats into 0x88C2C [doc] */
      uart0_printf(pcVar2);
      return;
    }
    if (*(char *)(param_1 + 0xc) == '\0') {
      if (*(int *)(param_1 + 0x14) == 0) {
        pcVar2 = "DSP Version %04X\r\n>> ";
      }
      else {
        pcVar2 = "DSP Version error (%d)\r\n>> ";
      }
    }
    else {
      pcVar2 = "Incoming unknown message category %d\r\n>> ";
    }
  }
  uart0_printf(pcVar2);
  return;
}


// ===== get_task_handles @ 00081064 (4 bytes)

void * get_task_handles(void)

{
  return &DAT_000886e4;
}


// ===== main @ 0008106c (218 bytes)

/* the application main: __main 0x872AE tail-calls it after stdio_init [fact: 0x872B8]; recreated as
   main() in src/ifdsp_m33/app/main.c, byte-identical [fact: T24 (src/ifdsp_m33/status.tsv,
   aliases.tsv)]. Was app_main (T24 round 2) */

undefined4 main(void)

{
  uint uVar1;
  
  memset(&DAT_000886e4,0,0xc);
  GPIO_PortInit(&GPIO_B0_0,0);
  GPIO_PortInit(&GPIO_B0_0,1);
  GPIO_PortInit(&GPIO_B0_0,2);
  BOARD_InitBootPins();
  BOARD_InitBootClocks();
  BOARD_InitBootPeripherals();
  regfile_clear();
                    /* clock set 2 [sfr] */
  CLKCTL1_PSCCTL2_SET = 0x80000000;
  INPUTMUX_AttachSignal(0x40026000,1,0x14000015);
  RESET_PeripheralReset(0x41d);
  RESET_PeripheralReset(0x41c);
                    /* Reset P1_0 low 20 ms, high 20 ms [doc] */
  aic3204_init();
  sct0_pwm_init();
  ipc_init();
                    /* DSP clocks, DSP_Init, image copy, DSPSTALL = 0 [doc] */
  BOARD_DSP_Init();
  SEMA42_Init();
  SEMA42_ResetGate(&SEMA42_GATE3,0x40);
  MU_SetFlags(0x40110000,1);
  do {
    uVar1 = MUA_SR;
  } while ((uVar1 & 7) != 1);
  SEMA42_Lock(0x40112000,0,'\x01');
  MU_SetFlags(0x40110000,2);
                    /* Semphores2 Gate n [sfr] */
  SEMA42_GATE0 = 0;
  do {
    uVar1 = MUA_SR;
  } while ((uVar1 & 7) != 3);
                    /* Store if reg < 0x8000 [doc] */
  regfile_write(0,0x101);
  regfile_write(0x4000,1);
                    /* word[reg] |= v in a critical section [doc] */
  regfile_set_bits(1,1);
  create_IpcTasks();
  sct0_pwm_start();
  create_CommandTask();
  vTaskStartScheduler();
  return 0;
}


// ===== sct0_pwm_callback @ 00081164 (108 bytes)

void sct0_pwm_callback(void)

{
  ushort uVar1;
  undefined4 in_r3;
  uint uVar2;
  uint sct0_conflag;
  uint sct0_evflag;
  
  DAT_000886f4 = DAT_000886f4 + 1;
  if (399 < DAT_000886f4) {
    DAT_000886f4 = 0;
                    /* reg < 0x8000 ? word[reg] [doc] */
    uVar1 = regfile_read(0x4005);
    if (uVar1 == 0) {
      uVar1 = 1;
    }
    if (0x62 < uVar1) {
      uVar1 = 99;
    }
    DAT_00088d2c = (undefined1)uVar1;
    SCTIMER_UpdatePwmDutycycle(&SCT0_CONFIG,0,DAT_00088d2c,DAT_000886f0,in_r3);
  }
                    /* SCT event flag [sfr] */
  sct0_evflag = SCT0_EVFLAG;
                    /* SCT conflict flag [sfr] */
  sct0_conflag = SCT0_CONFLAG;
  uVar2 = 1 << (DAT_000886f0 & 0xff);
  if (((sct0_conflag & 0xc0000000 | sct0_evflag & 0xffff) & uVar2) != 0) {
    SCT0_EVFLAG = uVar2 & 0xffff;
    SCT0_CONFLAG = uVar2 & 0xc0000000;
  }
  return;
}


// ===== sct0_pwm_init @ 000811e0 (110 bytes)

void sct0_pwm_init(void)

{
  uint uVar1;
  byte local_28 [4];
  undefined1 auStack_24 [16];
  
  uVar1 = CLOCK_GetFreq(1);
  SCTIMER_GetDefaultConfig(auStack_24);
  SCTIMER_Init(&SCT0_CONFIG,auStack_24);
  DAT_00088d2c = 1;
  DAT_000886f0 = 0;
  local_28[0] = 0;
  local_28[2] = 1;
  local_28[1] = 1;
  uVar1 = SCTIMER_SetupPwm(0x40146000,local_28,1,20000,uVar1,&DAT_000886f0);
  if (uVar1 != 1) {
                    /* SCT event interrupt enable [sfr] */
    uVar1 = SCT0_EVEN;
    SCT0_EVEN = 1 << (DAT_000886f0 & 0xff) | uVar1;
    SCTIMER_SetCallback(&SCT0_CONFIG,0x81165);
                    /* Interrupt Set Enable [sfr] */
    NVIC_ISER0 = 0x1000;
  }
  return;
}


// ===== sct0_pwm_start @ 00081264 (12 bytes)

/* 12 bytes, no arguments: SCT0->CTRL &= ~HALT_L [fact: 0x81264]; the SDK SCTIMER_StartTimer is a
   static inline taking (base, counter), so this is an application wrapper [inference: fsl_sctimer.h
   MCUX_2.11.0]. Was SCTIMER_StartTimer (T24 round 2) */

void sct0_pwm_start(void)

{
  uint sct0_ctrl;
  
                    /* SCT control [sfr] */
  sct0_ctrl = SCT0_CTRL;
  SCT0_CTRL = sct0_ctrl & 0xfffffffb;
  return;
}


// ===== console_cmd_i @ 00081274 (60 bytes)

void console_cmd_i(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 2) {
    iVar1 = strcmp(*(uint **)(param_1 + 4),(uint *)"db00");
    if (iVar1 == 0) {
      DAT_00088d2d = 0;
      DAT_00088d2e = 0;
    }
    else {
      iVar1 = strcmp(*(uint **)(param_1 + 4),(uint *)"db01");
      if (iVar1 == 0) {
        DAT_00088d2d = 1;
        DAT_00088d2e = 1;
        console_puts((uint)"\r\n>> ");
        return;
      }
    }
  }
  return;
}


// ===== console_cmd_w @ 000812c4 (50 bytes)

void console_cmd_w(int param_1,int param_2)

{
  ushort strtoul_ret;
  ushort strtoul_ret_2;
  
  if (param_2 == 3) {
    strtoul_ret = strtoul(*(byte **)(param_1 + 4),(byte *)0x0,0x10);
    strtoul_ret_2 = strtoul(*(byte **)(param_1 + 8),(byte *)0x0,0x10);
                    /* Store if reg < 0x8000 [doc] */
    regfile_write((uint)strtoul_ret,strtoul_ret_2);
    console_puts(0x87bfb);
    return;
  }
  return;
}


// ===== console_cmd_d @ 000812fc (128 bytes)

void console_cmd_d(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  bool uart0_tx_pending_ret;
  ushort uVar1;
  uint uVar2;
  int i;
  uint uVar3;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  iStack_28 = param_1;
  iStack_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (param_2 == 2) {
    uVar1 = strtoul(*(byte **)(param_1 + 4),(byte *)0x0,0x10);
    uVar2 = (uint)uVar1;
    uVar3 = uVar2 + 0x40;
    do {
      snprintf(&iStack_28,0x10,"\r\n %04X :",uVar2);
      console_puts((uint)&iStack_28);
      i = 0;
      do {
                    /* reg < 0x8000 ? word[reg] [doc] */
        uVar1 = regfile_read(uVar2 + i & 0xffff);
        snprintf(&iStack_28,0x10," %04X",uVar1);
        console_puts((uint)&iStack_28);
        uart0_tx_pending_ret = uart0_tx_pending();
        if (uart0_tx_pending_ret) {
          vTaskDelay(1);
        }
        i = i + 1;
      } while (i != 8);
      uVar2 = uVar2 + 8 & 0xffff;
    } while ((uVar3 & 0xffff) != uVar2);
    console_puts((uint)"\r\n>> ");
    return;
  }
  console_puts((uint)"\r\n?\r\n>> ");
  return;
}


// ===== console_printf @ 0008138c (36 bytes)

/* vsprintf into 0x88DF0 then console_puts; tail-called by console_cmd_r */

void console_printf(char *format,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  vsprintf(&DAT_00088df0,format,&uStack_c);
  console_puts(0x88df0);
  return;
}


// ===== console_cmd_r @ 000813b4 (48 bytes)

void console_cmd_r(int param_1,int param_2)

{
  ushort strtoul_ret;
  ushort regfile_read_ret;
  
  if (param_2 == 2) {
    strtoul_ret = strtoul(*(byte **)(param_1 + 4),(byte *)0x0,0x10);
                    /* reg < 0x8000 ? word[reg] [doc] */
    regfile_read_ret = regfile_read((uint)strtoul_ret);
                    /* vsprintf into 0x88DF0 [doc] */
    console_printf("\r\nr %04X %04X\r\n>> ",strtoul_ret,regfile_read_ret);
    return;
  }
  console_puts(0x87c79);
  return;
}


// ===== console_init @ 000813ec (44 bytes)

void console_init(void)

{
  DAT_000886f8 = &DAT_00088d2f;
  DAT_000886fc = &DAT_00088d3f;
  DAT_00088704 = &DAT_00088d5f;
  DAT_00088700 = &DAT_00088d4f;
  DAT_00088def = 0;
  DAT_00088708 = 0;
  DAT_00088d2e = 1;
  DAT_00088d2d = 1;
  return;
}


// ===== console_rx_char @ 00081430 (1058 bytes)

void console_rx_char(int param_1)

{
  char cVar1;
  byte bVar2;
  bool bVar3;
  ushort uVar4;
  ushort strtoul_ret;
  char *pcVar5;
  int iVar6;
  byte *pbVar7;
  int iVar8;
  uint uVar9;
  byte *pbVar10;
  int i;
  uint *puVar11;
  uint uVar12;
  int iVar13;
  uint uVar14;
  int *piVar15;
  byte *pbVar16;
  byte local_41;
  undefined1 auStack_40 [4];
  char local_3c;
  char local_38 [4];
  char local_34;
  undefined1 auStack_33 [15];
  
  local_41 = (byte)param_1;
  if (param_1 - 0x20U < 0x5f) {
LAB_000814ac:
    if (DAT_00088d2e != '\0') {
                    /* Echo the character (echo flag 0x88D2E) [fact: control-link.md] */
      uart0_write(&local_41,1);
    }
    if (DAT_00088def != '\0') {
      if (DAT_00088def != '\x01') {
        return;
      }
                    /* CR/LF (mask 0x2401): end of line, tokenize and run [fact: control-link.md] */
      if ((local_41 < 0xe) && ((~(0x2401U >> (uint)local_41) & 1) == 0)) {
        (&DAT_00088d6f)[DAT_00088708] = 0;
        memset(&DAT_00088d2f,0,0x40);
        iVar6 = strlen((uint *)&DAT_00088d6f);
        pbVar7 = &DAT_00088d70 + iVar6;
        pbVar16 = &DAT_00088d6f;
        do {
          pbVar10 = pbVar16;
          if (pbVar10 == pbVar7) {
            DAT_00088708 = 0;
            DAT_00088def = 0;
            return;
          }
                    /* Split at whitespace: up to 4 tokens of 15 chars [fact: control-link.md] */
          uVar12 = ctype_table[*pbVar10] & 1;
          pbVar16 = pbVar10 + 1;
        } while ((ctype_table[*pbVar10] & 1) != 0);
        uVar14 = uVar12;
        if (pbVar10 < pbVar7) {
          do {
            bVar2 = *pbVar10;
            if (((ctype_table[bVar2] & 1) != 0) || (bVar2 == 0)) {
              while( true ) {
                if (pbVar7 == pbVar10) goto LAB_00081626;
                uVar9 = (uint)*pbVar10;
                pbVar16 = pbVar10 + 1;
                uVar12 = ctype_table[uVar9] & 1;
                if ((ctype_table[uVar9] & 1) == 0) break;
                pbVar10 = pbVar16;
                if ((uVar9 < 0xe) && ((int)((0x2401U >> uVar9) << 0x1f) < 0)) goto LAB_00081596;
              }
              if (uVar9 == 0) {
LAB_00081596:
                iVar6 = 0;
                iVar13 = uVar14 + 1;
                piVar15 = (int *)&DAT_000886f8;
                do {
                  iVar8 = strlen((uint *)*piVar15);
                  if (DAT_00088d2d != '\0') {
                    for (i = 0; i < iVar8; i = i + 1) {
                    /* Interactive mode: lower-case every token [fact: control-link.md] */
                      bVar2 = tolower((uint)*(byte *)(*piVar15 + i));
                      *(byte *)(*piVar15 + i) = bVar2;
                    }
                  }
                  puVar11 = (uint *)*piVar15;
                  iVar8 = strlen(puVar11);
                  if (iVar8 != 0) {
                    while (iVar8 = iVar8 + -1, -1 < iVar8) {
                      if ((int)((uint)ctype_table[*(byte *)((int)puVar11 + iVar8)] << 0x1f) < 0) {
                        *(undefined1 *)((int)puVar11 + iVar8) = 0;
                      }
                    }
                  }
                  cVar1 = DAT_00088d2d;
                  puVar11 = DAT_000886f8;
                  iVar6 = iVar6 + 1;
                  piVar15 = piVar15 + 1;
                } while (iVar6 != iVar13);
                if (DAT_00088d2d == '\0') {
                  pbVar16 = (byte *)((int)DAT_000886f8 + 1);
                  bVar2 = (byte)*DAT_000886f8;
                    /* Machine mode: the rest of argv[0] must be hex [fact: control-link.md] */
                  uVar12 = is_hex_string(pbVar16);
                  if (uVar12 != 0) {
                    iVar6 = strlen(puVar11);
                    if (iVar6 == 7) {
                    /* 7-char frame: checksum of the first 5 chars [fact: control-link.md] */
                      bVar3 = frame_checksum_ok((char *)puVar11,5);
                      if (bVar3) {
                        memcpy(auStack_40,pbVar16,4);
                        local_3c = cVar1;
                        uVar4 = strtoul(auStack_40,(byte *)0x0,0x10);
                        uVar12 = (uint)uVar4;
                        if (bVar2 == 100) {
LAB_00081778:
                          uVar14 = uVar12 + 0x40;
                          do {
                    /* d: dump 64 words, 8 per line [fact: control-link.md] */
                            snprintf(local_38,0x10,"\r\n%04X :",uVar12);
                            console_puts((uint)local_38);
                            iVar6 = 0;
                            do {
                              uVar4 = regfile_read(uVar12 + iVar6 & 0xffff);
                              snprintf(local_38,0x10," %04X",uVar4);
                              console_puts((uint)local_38);
                              bVar3 = uart0_tx_pending();
                              if (bVar3) {
                    /* Pace the dump to the UART [fact: control-link.md] */
                                vTaskDelay(1);
                              }
                              iVar6 = iVar6 + 1;
                            } while (iVar6 != 8);
                            uVar12 = uVar12 + 8 & 0xffff;
                          } while ((uVar14 & 0xffff) != uVar12);
                          pcVar5 = "\r\n";
                          goto LAB_00081772;
                        }
                        if (bVar2 < 0x65) {
                          if (bVar2 != 0x49) {
                            if (bVar2 == 0x52) goto LAB_0008172a;
                            if (bVar2 != 0x44) goto LAB_00081716;
                            goto LAB_00081778;
                          }
                        }
                        else if (bVar2 != 0x69) {
                          if (bVar2 != 0x72) goto LAB_00081716;
LAB_0008172a:
                    /* r: read reply "r" + value + sum, no CR [fact: control-link.md] */
                          uVar4 = regfile_read(uVar12);
                          local_38[0] = 0x72;
                          sprintf(local_38 + 1,"%04X",uVar4);
                          sprintf(auStack_33,"%02X",
                                  local_34 + local_38[3] + local_38[2] + local_38[1] + local_38[0]);
                          pcVar5 = local_38;
                          goto LAB_00081772;
                        }
                    /* i DB00 / DB01: machine or interactive mode [fact: control-link.md] */
                        iVar6 = strncmp((uint *)auStack_40,(uint *)"db",2);
                        if ((iVar6 == 0) ||
                           (iVar6 = strncmp((uint *)auStack_40,(uint *)"DB",2), iVar6 == 0)) {
                          iVar6 = strncmp((uint *)(auStack_40 + 2),(uint *)0x87c61,2);
                          if (iVar6 == 0) {
                            DAT_00088d2d = '\0';
                            DAT_00088d2e = DAT_00088d2d;
                          }
                          else {
                            iVar6 = strncmp((uint *)(auStack_40 + 2),(uint *)0x87c66,2);
                            if (iVar6 == 0) {
                              DAT_00088d2d = '\x01';
                              DAT_00088d2e = '\x01';
                            }
                          }
                        }
                        goto LAB_00081716;
                      }
LAB_00081828:
                      pcVar5 = "?";
                    }
                    else {
                    /* 11-char w frame with a good checksum, else ? [fact: control-link.md] */
                      if ((iVar6 != 0xb) || (bVar3 = frame_checksum_ok((char *)puVar11,9), !bVar3))
                      goto LAB_00081828;
                      memcpy(auStack_40,pbVar16,4);
                      local_3c = cVar1;
                      uVar4 = strtoul(auStack_40,(byte *)0x0,0x10);
                      memcpy(auStack_40,(void *)((int)puVar11 + 5),4);
                      strtoul_ret = strtoul(auStack_40,(byte *)0x0,0x10);
                      if ((bVar2 & 0xdf) != 0x57) goto LAB_00081716;
                    /* w: write the register, reply ACK 0x06 [fact: control-link.md] */
                      regfile_write((uint)uVar4,strtoul_ret);
                      pcVar5 = "\x06";
                    }
LAB_00081772:
                    console_puts((uint)pcVar5);
                  }
LAB_00081716:
                  if (iVar13 != 4) {
                    DAT_00088708 = 0;
                    DAT_00088def = 0;
                    return;
                  }
                }
                else {
                  pcVar5 = "r";
                  iVar6 = 0;
                  do {
                    /* Interactive: look argv[0] up in table 0x8795C [fact: control-link.md] */
                    iVar8 = strcmp(DAT_000886f8,(uint *)pcVar5);
                    if (iVar8 == 0) {
                      (*(code *)(&DAT_0008796c)[iVar6 * 5])(&DAT_000886f8,iVar13);
                      DAT_00088708 = 0;
                      DAT_00088def = 0;
                      return;
                    }
                    iVar6 = iVar6 + 1;
                    pcVar5 = (char *)((int)pcVar5 + 0x14);
                  } while (iVar6 != 4);
                }
                if (DAT_00088d2d == '\0') {
                  DAT_00088708 = 0;
                  DAT_00088def = 0;
                  return;
                }
                    /* Unknown command or too many tokens: ? [fact: control-link.md] */
                pcVar5 = "\r\n?\r\n>> ";
                goto LAB_00081676;
              }
              uVar14 = uVar14 + 1;
              if (uVar14 != 4) goto LAB_00081584;
              break;
            }
            (&DAT_00088d2f)[uVar12 + uVar14 * 0x10] = bVar2;
            uVar12 = uVar12 + 1;
            if (uVar12 == 0xf) break;
            pbVar10 = pbVar10 + 1;
LAB_00081584:
          } while (pbVar7 != pbVar10);
LAB_00081626:
          if (DAT_00088d2d != '\0') {
            pcVar5 = "\r\n?\r\n>> ";
LAB_00081676:
            console_puts((uint)pcVar5);
          }
        }
      }
      else {
        (&DAT_00088d6f)[DAT_00088708] = local_41;
        if (DAT_00088708 + 1 < 0x80) {
          DAT_00088708 = DAT_00088708 + 1;
          return;
        }
      }
      DAT_00088708 = 0;
      DAT_00088def = 0;
      return;
    }
    if (-1 < (int)((uint)ctype_table[local_41] << 0x1f)) {
      DAT_00088708 = 1;
      DAT_00088d6f = local_41;
      DAT_00088def = 1;
      return;
    }
    if (local_41 != 0xd) {
      return;
    }
  }
  else {
    if (param_1 == 0) {
      return;
    }
    if (param_1 == 3) {
      if (DAT_00088d2e == '\0') {
        return;
      }
      console_puts(0x87bfb);
      if (DAT_00088d2e == '\0') {
        return;
      }
      pcVar5 = "\r\nCtrl+C\r\n>> ";
      goto LAB_0008145a;
    }
    if ((param_1 == 8) || (param_1 == 0x7f)) {
      if (DAT_00088708 < 1) {
        return;
      }
      DAT_00088708 = DAT_00088708 + -1;
      if (DAT_00088708 == 0) {
        DAT_00088def = '\0';
      }
      if (DAT_00088d2e != '\0') {
        local_38[0] = '\b';
        local_38[1] = ' ';
        local_38[2] = 8;
        uart0_write(local_38,3);
        return;
      }
      return;
    }
    if (param_1 != 0x1b) goto LAB_000814ac;
  }
  if (DAT_00088d2e == '\0') {
    return;
  }
  pcVar5 = "\r\n>> ";
LAB_0008145a:
  console_puts((uint)pcVar5);
  return;
}

