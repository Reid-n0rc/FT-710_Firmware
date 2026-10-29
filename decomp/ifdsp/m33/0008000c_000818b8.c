// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== rom_api_1c_guarded_call @ 0008000c (32 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* Calls ROM API table *(0x1303F01C): if fn[7]() == 0 then fn[1](a,b); no callers [guess] */

void rom_api_1c_guarded_call(undefined4 param_1,undefined4 param_2)

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


// ===== power_set_deepsleep_pmc_cfg @ 00080030 (24 bytes)

/* PMC 0x40135020 = 0x04040808, PMC 0x40135014 = 10 if different; called by POWER_EnterDeepSleep
   [guess] */

void power_set_deepsleep_pmc_cfg(void)

{
  int iVar1;
  
  iVar1 = DAT_40135020;
  if (iVar1 != 0x4040808) {
    DAT_40135020 = 0x4040808;
  }
  iVar1 = DAT_40135014;
  if (iVar1 != 10) {
    DAT_40135014 = 10;
  }
  return;
}


// ===== delay @ 00080050 (14 bytes)

/* fsl_power.c busy loop (count iterations) [inference] */

void delay(int param_1)

{
  int iVar1;
  
  for (iVar1 = 0; iVar1 != param_1; iVar1 = iVar1 + 1) {
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


// ===== power_sram_pd_differs @ 0008009c (68 bytes)

/* Compares PDSLEEPCFG1..3 with PDRUNCFG1..3 (SYSCTL0 0x604..0x61C) [guess] */

bool power_sram_pd_differs(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = DAT_40002614;
  uVar1 = DAT_40002604;
  if (((uVar2 ^ 0x1f000fff) & uVar1 & 0x1f000fff) == 0) {
    uVar2 = DAT_40002618;
    uVar1 = DAT_40002608;
    if (((uVar2 ^ 0x3fffffff) & uVar1 & 0x3fffffff) == 0) {
      uVar2 = DAT_4000261c;
      uVar1 = DAT_4000260c;
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
  uint uVar3;
  int iVar4;
  int iVar5;
  undefined *puVar6;
  int iVar7;
  undefined *puVar8;
  int iVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  int iVar13;
  int iVar14;
  bool bVar15;
  
  uVar12 = DAT_40002600;
  bVar15 = (uVar12 & 0x10017d0) == 0x10017d0;
  if (bVar15) {
    param_1 = 0x21a;
  }
  iVar9 = 9000;
  if (!bVar15) {
    param_1 = 0x4c;
    iVar9 = 0;
  }
  uVar12 = DAT_40002600;
  uVar1 = DAT_40135010;
  uVar3 = DAT_40135014;
  iVar10 = (uVar1 & 0x3f) - (uVar3 & 0x3f);
  uVar1 = DAT_40002610;
  if ((uVar12 & 0x10) == 0) {
    iVar4 = 0x4c;
    iVar13 = 0;
  }
  else {
    iVar13 = 1000;
    iVar4 = 0xe1f;
  }
  iVar7 = 0xceb;
  if ((uVar1 & 0x10) == 0) {
    iVar7 = 0x4c;
  }
  iVar14 = DAT_40002600;
  if (iVar14 << 0x14 < 0) {
    uVar12 = DAT_40002600;
    if ((uVar12 & 0x1000) == 0) {
      iVar14 = 0x1a71;
      puVar8 = (undefined *)0x0;
    }
    else {
      iVar14 = 0x4c;
      puVar8 = (undefined *)0x0;
    }
  }
  else {
    iVar14 = 0x1cd;
    puVar8 = &DAT_00006590;
  }
  iVar5 = power_sram_pd_differs();
  iVar11 = DAT_40002604;
  if (iVar11 < 0) {
    iVar11 = 8000;
  }
  else {
    iVar11 = 1000;
  }
  iVar2 = DAT_40002610;
  iVar9 = (uint)(iVar11 * (1 - iVar5) + iVar5 * 47000 + 1000) / 0xd +
          iVar14 + iVar10 * 600 + (iVar10 * 32000 + 1000U) / 0xd + iVar9 + param_1 + iVar13 + iVar4
                   + iVar7 + 0x1f9;
  puVar6 = puVar8 + iVar9 + 0x4c;
  if ((iVar2 << 0x14 < 0) &&
     ((iVar10 = DAT_40002600, iVar10 << 0x14 < 0 || (iVar10 = DAT_40002660, -1 < iVar10 << 0x1f))))
  {
    iVar9 = DAT_40002610;
    if (iVar9 << 0x13 < 0) {
      iVar9 = DAT_40002600;
      if (iVar9 << 0x13 < 0) {
        uVar12 = 1000;
      }
      else {
        uVar1 = DAT_40002660;
        uVar12 = 0x4c2c0;
        if ((uVar1 & 2) == 0) {
          uVar12 = 1000;
        }
      }
    }
    else {
      uVar12 = 0x4c2c0;
    }
  }
  else {
    uVar12 = 5000;
    puVar6 = puVar8 + iVar9 + 0x3d4c4;
  }
  uVar1 = DAT_40002610;
  if (((~uVar1 & 0x10017d0) == 0) &&
     ((iVar9 = DAT_40002600, iVar9 << 0x13 < 0 || (iVar9 = DAT_40002660, -1 < iVar9 << 0x1e)))) {
    iVar9 = uVar12 / 0xd + 0x298;
  }
  else {
    iVar9 = uVar12 / 0xd + 0x98;
  }
  uVar12 = DAT_40001100;
  if ((uVar12 & 0xc0000) == 0) {
    iVar10 = 0xc;
  }
  else {
    iVar10 = 0xf;
  }
  return (iVar10 * (int)(puVar6 + iVar9) + 999U) / 1000;
}


// ===== initFlexSPI @ 000802aa (124 bytes)

/* fsl_power.c: FlexSPI enable, SWRESET, wait DLL lock (STS2) [inference] */

void initFlexSPI(void)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  uint *in_r3;
  uint uVar4;
  
  *in_r3 = *in_r3 & 0xfffffffd;
  *in_r3 = *in_r3 | 1;
  do {
  } while ((int)(*in_r3 << 0x1f) < 0);
  if ((int)(in_r3[0x30] << 0x1f) < 0) {
    uVar2 = in_r3[0x3a];
    if ((in_r3[0x18] & 0x7fffff) == 0) {
      uVar4 = 0;
      if ((in_r3[0x19] & 0x7fffff) != 0) {
        uVar4 = 3;
      }
    }
    else {
      uVar4 = 3;
    }
    uVar1 = DAT_40134068;
    if (((uVar1 & 0x7fffff) != 0) || (uVar1 = DAT_4013406c, (uVar1 & 0x7fffff) != 0)) {
      uVar4 = uVar4 | 0x30000;
    }
    iVar3 = 10;
    do {
      while( true ) {
        uVar1 = DAT_401340e8;
        if ((uVar4 & ~uVar1) == 0) {
          iVar3 = 100;
          do {
            iVar3 = iVar3 + -1;
          } while (iVar3 != 0);
          return;
        }
        if (uVar1 == uVar2) break;
        iVar3 = 10;
        uVar2 = uVar1;
      }
      iVar3 = iVar3 + -1;
    } while (iVar3 != 0);
  }
  return;
}


// ===== initXip @ 0008032c (26 bytes)

/* WARNING: Removing unreachable block (ram,0x000802a8) */
/* WARNING: Removing unreachable block (ram,0x000802bc) */
/* WARNING: Removing unreachable block (ram,0x000802c2) */
/* WARNING: Removing unreachable block (ram,0x000802ca) */
/* WARNING: Removing unreachable block (ram,0x00080314) */
/* WARNING: Removing unreachable block (ram,0x000802d6) */
/* WARNING: Removing unreachable block (ram,0x000802e0) */
/* WARNING: Removing unreachable block (ram,0x000802e2) */
/* WARNING: Removing unreachable block (ram,0x000802ec) */
/* WARNING: Removing unreachable block (ram,0x000802f4) */
/* WARNING: Removing unreachable block (ram,0x000802f8) */
/* WARNING: Removing unreachable block (ram,0x000802fc) */
/* WARNING: Removing unreachable block (ram,0x000802fe) */
/* WARNING: Removing unreachable block (ram,0x0008031c) */
/* WARNING: Removing unreachable block (ram,0x00080320) */
/* WARNING: Removing unreachable block (ram,0x00080324) */
/* WARNING: Removing unreachable block (ram,0x0008030a) */
/* WARNING: Removing unreachable block (ram,0x0008030e) */
/* WARNING: Removing unreachable block (ram,0x00080318) */
/* WARNING: Removing unreachable block (ram,0x00080312) */
/* fsl_power.c: re-enable FlexSPI clock and initFlexSPI after deep sleep (body merged by Ghidra)
   [inference] */

void initXip(void)

{
  return;
}


// ===== POWER_EnterSleep_mode1 @ 0008034c (182 bytes)

void POWER_EnterSleep_mode1(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar5 = power_set_deepsleep_pmc_cfg(uVar4);
  uVar2 = DAT_e000ed10;
  DAT_e000ed10 = uVar2 | 4;
  iVar3 = DAT_e000e104;
  uVar2 = DAT_40002610;
  DAT_40002600 = uVar2 & 0xfffff7fe | 1;
  uVar4 = DAT_40002614;
  DAT_40002604 = uVar4;
  uVar4 = DAT_40002618;
  DAT_40002608 = uVar4;
  uVar4 = DAT_4000261c;
  DAT_4000260c = uVar4;
  DAT_40002660 = 1;
  DAT_40135024 = 0x800;
  uVar2 = DAT_4013500c;
  DAT_4013500c = uVar2 & 0xefcfffff | 0x10000000;
  DAT_400026a4 = 0x4000000;
  if (-1 < iVar3 << 5) {
    DAT_e000e104 = 0x4000000;
  }
  WaitForInterrupt();
  DAT_4013500c = uVar2;
  DAT_40135008 = 0x10000000;
  DAT_400026c4 = 0x4000000;
  DAT_40002660 = 0;
  DAT_e000e284 = 0x4000000;
  if (-1 < iVar3 << 5) {
    DAT_e000e184 = 0x4000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  uVar2 = DAT_e000ed10;
  DAT_e000ed10 = uVar2 & 0xfffffffb;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar5 & 1) == 1);
  }
  return;
}


// ===== POWER_EnterSleep_mode2 @ 00080414 (182 bytes)

void POWER_EnterSleep_mode2(void)

{
  bool bVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  
  uVar4 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar4 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar5 = power_set_deepsleep_pmc_cfg(uVar4);
  uVar2 = DAT_e000ed10;
  DAT_e000ed10 = uVar2 | 4;
  iVar3 = DAT_e000e104;
  uVar2 = DAT_40002610;
  DAT_40002600 = uVar2 & 0xffffeffe | 1;
  uVar4 = DAT_40002614;
  DAT_40002604 = uVar4;
  uVar4 = DAT_40002618;
  DAT_40002608 = uVar4;
  uVar4 = DAT_4000261c;
  DAT_4000260c = uVar4;
  DAT_40002660 = 2;
  DAT_40135024 = 0x800;
  uVar2 = DAT_4013500c;
  DAT_4013500c = uVar2 & 0xefcfffff | 0x10000000;
  DAT_400026a4 = 0x4000000;
  if (-1 < iVar3 << 5) {
    DAT_e000e104 = 0x4000000;
  }
  WaitForInterrupt();
  DAT_4013500c = uVar2;
  DAT_40135008 = 0x10000000;
  DAT_400026c4 = 0x4000000;
  DAT_40002660 = 0;
  DAT_e000e284 = 0x4000000;
  if (-1 < iVar3 << 5) {
    DAT_e000e184 = 0x4000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  uVar2 = DAT_e000ed10;
  DAT_e000ed10 = uVar2 & 0xfffffffb;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar5 & 1) == 1);
  }
  return;
}


// ===== POWER_EnterSleep_mode3 @ 000804dc (174 bytes)

uint POWER_EnterSleep_mode3(void)

{
  bool bVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = 0;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    uVar5 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  uVar2 = DAT_e000ed10;
  DAT_e000ed10 = uVar2 | 4;
  iVar4 = DAT_e000e104;
  uVar2 = DAT_40002610;
  DAT_40002600 = uVar2 | 0x1801;
  uVar3 = DAT_40002614;
  DAT_40002604 = uVar3;
  uVar3 = DAT_40002618;
  DAT_40002608 = uVar3;
  uVar3 = DAT_4000261c;
  DAT_4000260c = uVar3;
  DAT_40002660 = 3;
  DAT_40135024 = 0x800;
  uVar2 = DAT_4013500c;
  DAT_4013500c = uVar2 & 0xefcfffff | 0x10000000;
  DAT_400026a4 = 0x4000000;
  if (-1 < iVar4 << 5) {
    DAT_e000e104 = 0x4000000;
  }
  WaitForInterrupt();
  DAT_4013500c = uVar2;
  DAT_40135008 = 0x10000000;
  DAT_400026c4 = 0x4000000;
  DAT_40002660 = 0;
  DAT_e000e284 = 0x4000000;
  if (-1 < iVar4 << 5) {
    DAT_e000e184 = 0x4000000;
    DataSynchronizationBarrier(0xf);
    InstructionSynchronizationBarrier(0xf);
  }
  uVar2 = DAT_e000ed10;
  DAT_e000ed10 = uVar2 & 0xfffffffb;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    enableIRQinterrupts((uVar5 & 1) == 1);
  }
  return uVar5;
}


// ===== POWER_EnterDeepSleep @ 0008059c (852 bytes)

void POWER_EnterDeepSleep(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint *puVar8;
  undefined4 uVar9;
  int iVar10;
  uint uVar11;
  uint extraout_r1;
  int extraout_r1_00;
  int extraout_r1_01;
  int extraout_r1_02;
  uint uVar12;
  uint extraout_r2;
  uint uVar13;
  uint uVar14;
  bool bVar15;
  uint uVar16;
  uint uVar17;
  bool bVar18;
  
  uVar13 = 0;
  bVar15 = (bool)isCurrentModePrivileged();
  if (bVar15) {
    uVar13 = isIRQinterruptsEnabled();
  }
  disableIRQinterrupts();
  puVar8 = (uint *)power_set_deepsleep_pmc_cfg();
  uVar3 = DAT_e000ed10;
  DAT_e000ed10 = uVar3 | 4;
  uVar3 = DAT_40001430;
  uVar4 = DAT_40001434;
  uVar6 = DAT_40021430;
  uVar7 = DAT_40021434;
  uVar2 = DAT_40001400;
  uVar5 = DAT_40002610;
  DAT_40002600 = uVar5 & ~*puVar8 & 0xfffffff9 | ~*puVar8 & 0x3effffd1;
  uVar5 = DAT_40002614;
  DAT_40002604 = (uVar5 | 0x9f000fff) & ~puVar8[1];
  uVar5 = DAT_40002618;
  DAT_40002608 = (uVar5 | 0x3fffffff) & ~puVar8[2];
  uVar5 = DAT_4000261c;
  DAT_4000260c = (uVar5 | 0x3fffffff) & ~puVar8[3];
  DAT_40135028 = 0x73;
  uVar5 = DAT_40002600;
  DAT_40002600 = uVar5 | 2;
  uVar5 = DAT_40002600;
  bVar15 = false;
  if ((uVar5 & 1) != 0) {
    iVar10 = DAT_4000200c;
    if (iVar10 == 0) {
      bVar15 = true;
      DAT_4000200c = 1;
    }
    else {
      bVar15 = false;
    }
  }
  uVar9 = DAT_40135008;
  DAT_40135008 = uVar9;
  uVar5 = DAT_40135030;
  DAT_40135030 = uVar5 | 0x3f;
  uVar5 = DAT_4013500c;
  DAT_4013500c = uVar5 & 0xffcfffff;
  iVar10 = DAT_40002610;
  bVar18 = iVar10 << 0xf < 0;
  if (bVar18) {
    DAT_40002630 = 0x10000;
    delay(0x960);
  }
  iVar10 = DAT_40002600;
  if (iVar10 << 0xf < 0) {
    DAT_40002710 = 0;
  }
  else {
    uVar9 = POWER_CalculateSafetyCount();
    DAT_40002710 = uVar9;
  }
  deinitXip();
  DAT_40001430 = 0;
  DAT_40001434 = 0;
  DAT_40021430 = 0;
  DAT_40021434 = 0;
  DAT_40001400 = 0;
  do {
    iVar10 = DAT_40001400;
  } while (iVar10 < 0);
  uVar16 = 0x2002;
  uVar14 = DAT_40002610;
  uVar12 = DAT_40002600;
  uVar14 = uVar14 ^ uVar12;
  uVar12 = uVar14 & 0x60000;
  if (uVar12 == 0) {
    uVar17 = 0;
  }
  else {
    uVar17 = 0x2002;
  }
  uVar11 = uVar14 & 0x1e0000;
  if ((uVar14 & 0x180000) == 0) {
    if (uVar12 == 0) {
      uVar14 = 0;
      uVar16 = 0;
      goto LAB_00080716;
    }
    uVar16 = 0;
LAB_000806f8:
    uVar12 = DAT_40001218;
    uVar12 = ~uVar12 & 0x80808080;
    if ((uVar14 & 0x180000) == 0) {
      uVar14 = 0;
      goto LAB_00080716;
    }
  }
  else if (uVar12 != 0) goto LAB_000806f8;
  uVar14 = DAT_40021218;
  uVar14 = ~uVar14 & 0x80808080;
LAB_00080716:
  uVar1 = DAT_40001218;
  DAT_40001218 = uVar1 | uVar12;
  uVar1 = DAT_40021218;
  DAT_40021218 = uVar1 | uVar14;
  uVar14 = DAT_40001204;
  DAT_40001204 = uVar14 | uVar17;
  uVar14 = DAT_40021204;
  DAT_40021204 = uVar14 | uVar16;
  DAT_40002620 = uVar11;
  WaitForInterrupt();
  uVar1 = DAT_40002610;
  uVar14 = DAT_40002600;
  if (((uVar1 ^ uVar14) & 0x2000) != 0) {
    uVar14 = DAT_40001100;
    if ((uVar14 & 0xc0000) == 0) {
      iVar10 = 3;
    }
    else {
      iVar10 = 4;
    }
    delay(DAT_00080a58 * iVar10);
    uVar11 = extraout_r1;
  }
  if (uVar11 != 0) {
    DAT_40002630 = uVar11;
    uVar11 = DAT_4000120c;
    uVar14 = DAT_40001100;
    if ((uVar14 & 0xc0000) == 0) {
      iVar10 = 3;
    }
    else {
      iVar10 = 4;
    }
    delay(iVar10 * ((uVar11 & 0xffff) >> 1));
    *(uint *)(extraout_r1_00 + 0x204) = *(uint *)(extraout_r1_00 + 0x204) & ~(uVar17 & 2);
    uVar14 = DAT_40021204;
    DAT_40021204 = uVar14 & ~(uVar16 & 2);
    if ((*(uint *)(extraout_r1_00 + 0x100) & 0xc0000) == 0) {
      iVar10 = 3;
    }
    else {
      iVar10 = 4;
    }
    delay(iVar10 * ((*(uint *)(extraout_r1_00 + 0x20c) & 0xffff) / 6));
    iVar10 = 3;
    *(uint *)(extraout_r1_01 + 0x204) = *(uint *)(extraout_r1_01 + 0x204) & ~(uVar17 & 0x2000);
    uVar14 = DAT_40021204;
    DAT_40021204 = uVar14 & ~(uVar16 & 0x2000);
    if ((*(uint *)(extraout_r1_01 + 0x100) & 0xc0000) != 0) {
      iVar10 = 4;
    }
    delay(iVar10 * ((*(uint *)(extraout_r1_01 + 0x20c) & 0xffff) / 3));
    if (uVar12 != 0) {
      *(uint *)(extraout_r1_02 + 0x218) = *(uint *)(extraout_r1_02 + 0x218) & ~uVar12;
      do {
      } while ((*(uint *)(extraout_r1_02 + 0x218) & 0x40404040) != uVar12 >> 1);
    }
    if (extraout_r2 != 0) {
      uVar12 = DAT_40021218;
      DAT_40021218 = uVar12 & ~extraout_r2;
      do {
        uVar12 = DAT_40021218;
      } while ((uVar12 & 0x40404040) != extraout_r2 >> 1);
    }
  }
  DAT_40001400 = uVar2;
  do {
    iVar10 = DAT_40001400;
  } while (iVar10 < 0);
  DAT_40001430 = uVar3 & 3;
  DAT_40001434 = uVar4 & 3;
  DAT_40021430 = uVar6 & 3;
  DAT_40021434 = uVar7 & 3;
  if (bVar18) {
    DAT_40002620 = 0x10000;
  }
  initXip();
  DAT_4013500c = uVar5;
  if (bVar15) {
    uVar3 = DAT_4000200c;
    DAT_4000200c = uVar3 & 0xfffffffe;
  }
  uVar3 = DAT_e000ed10;
  DAT_e000ed10 = uVar3 & 0xfffffffb;
  bVar15 = (bool)isCurrentModePrivileged();
  if (bVar15) {
    enableIRQinterrupts((uVar13 & 1) == 1);
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
  int iVar2;
  
  uVar1 = DAT_40001620;
  if ((uVar1 != (param_1 & 7)) || (uVar1 = DAT_40001624, (uVar1 & 0xff) != param_2 - 1U)) {
    DAT_40001070 = 0x10000;
    DAT_40001620 = param_1 & 7;
    uVar1 = DAT_40001624;
    DAT_40001624 = uVar1 | 0x20000000;
    DAT_40001624 = param_2 - 1U & 0xff;
    do {
      iVar2 = DAT_40001624;
    } while (iVar2 < 0);
    DAT_40001040 = 0x10000;
  }
  return;
}


// ===== OTFAD_Init @ 00080a18 (44 bytes)

/* NEW true entry of FUN_00080A24: waits FlexSPI idle, base+0xC00 (OTFAD CR) |= cfg bits | GE;
   unused [guess] */

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

/* NEW: OTFAD CR &= ~GE; unused [guess] */

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


// ===== vStartFirstTask @ 00080a90 (32 bytes)

/* WARNING: Control flow encountered bad instruction data */

void vStartFirstTask(void)

{
  bool bVar1;
  undefined4 *puVar2;
  
  puVar2 = (undefined4 *)DAT_e000ed08;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(*puVar2);
  }
  enableIRQinterrupts();
  enableFIQinterrupts();
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  software_interrupt(2);
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
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
  vTaskSwitchContext(0x40);
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
  uint uVar2;
  
  iVar1 = CLOCK_GetFreq(0);
  for (uVar2 = 0; uVar2 != (uint)(param_1 * iVar1) / 1000000; uVar2 = uVar2 + 1) {
  }
  return;
}


// ===== aic3204_spi_write @ 00080b68 (100 bytes)

void aic3204_spi_write(int param_1,uint param_2)

{
  int iVar1;
  
  param_2 = param_2 | param_1 << 9;
  DAT_40100027 = 0;
  delay_us(1);
  iVar1 = 0x10;
  do {
    DAT_4010005d = 1;
    if ((int)(param_2 << 0x10) < 0) {
      DAT_40100021 = 1;
    }
    else {
      DAT_40100021 = 0;
    }
    delay_us(1);
    DAT_4010005d = 0;
    delay_us(1);
    param_2 = (param_2 & 0xffff) << 1;
    iVar1 = iVar1 + -1;
  } while (iVar1 != 0);
  delay_us(1);
  DAT_40100027 = 1;
  delay_us(10);
  return;
}


// ===== aic3204_init @ 00080bd0 (72 bytes)

void aic3204_init(void)

{
  int iVar1;
  undefined1 *puVar2;
  
  iVar1 = 0;
  DAT_40100020 = 0;
  DAT_40100027 = 0;
  DAT_4010005d = 0;
  DAT_40100021 = 0;
  delay_us(&DAT_00004e20);
  DAT_40100020 = 1;
  delay_us(&DAT_00004e20);
  puVar2 = &DAT_00087a1c;
  do {
    aic3204_spi_write(*puVar2,puVar2[1]);
    iVar1 = iVar1 + 1;
    delay_us(*(undefined2 *)(puVar2 + 2));
    puVar2 = puVar2 + 4;
  } while (iVar1 != 0x43);
  return;
}


// ===== regfile_clear @ 00080c20 (12 bytes)

void regfile_clear(void)

{
  memset(&DAT_20070000,0,0x10000);
  return;
}


// ===== regfile_read @ 00080c30 (22 bytes)

undefined2 regfile_read(int param_1)

{
  undefined2 uVar1;
  
  if (&DAT_20070000 + param_1 * 2 < (undefined2 *)0x20080000) {
    uVar1 = *(undefined2 *)(&DAT_20070000 + param_1 * 2);
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
  int iVar3;
  
  if (DAT_000886d4 < 0x400) {
    vPortEnterCritical();
    iVar3 = 0;
    do {
      puVar1 = (undefined1 *)(param_1 + iVar3);
      iVar3 = iVar3 + 1;
      (&DAT_000882d4)[DAT_000886d8] = *puVar1;
      DAT_000886d8 = DAT_000886d8 + 1 & 0x3ff;
      DAT_000886d4 = DAT_000886d4 + 1;
      if (param_2 == iVar3) break;
    } while (DAT_000886d4 < 0x400);
    iVar2 = DAT_40106e10;
    if (-1 < iVar2 << 0x1d) {
      DAT_40106e10 = 0xf;
    }
    vPortExitCritical();
  }
  else {
    iVar3 = 0;
  }
  return iVar3;
}


// ===== uart0_init @ 00080d0c (86 bytes)

void uart0_init(void)

{
  undefined4 uVar1;
  undefined4 local_20;
  undefined *local_1c [2];
  undefined2 local_14;
  
  local_20 = 0xff0100;
  CLOCK_SetFRGClock(&local_20);
  CLOCK_AttachClk(0x80004508);
  USART_GetDefaultConfig(local_1c);
  local_1c[0] = &DAT_0001c200;
  local_14 = 0x101;
  uVar1 = CLOCK_GetFlexCommClkFreq(0);
  USART_Init(&DAT_40106000,local_1c,uVar1);
  DAT_00087ec4 = xEventGroupCreate();
  DAT_40106e10 = 10;
  DAT_e000e100 = 0x4000;
  return;
}


// ===== CommandTask @ 00080d78 (152 bytes)

void CommandTask(void)

{
  undefined1 uVar1;
  int iVar2;
  
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
  DAT_40100045 = 1;
  do {
    do {
      iVar2 = xEventGroupWaitBits(DAT_00087ec4,1,1,0,0xffffffff);
    } while (-1 < iVar2 << 0x1f);
    while ((DAT_000886d4 < 0x400 && (DAT_000882c8 != 0))) {
      vPortEnterCritical();
      uVar1 = (&DAT_00087ec8)[DAT_000882d0];
      DAT_000882d0 = DAT_000882d0 + 1 & 0x3ff;
      DAT_000882c8 = DAT_000882c8 + -1;
      vPortExitCritical();
      console_rx_char(uVar1);
    }
  } while( true );
}


// ===== create_CommandTask @ 00080e20 (38 bytes)

void create_CommandTask(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = get_task_handles();
  iVar2 = xTaskCreate(0x80d79,"Command Task",0x1800,uVar1,1,uVar1,param_3);
  if (iVar2 != 1) {
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
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  uint local_14;
  undefined4 uStack_10;
  
  uVar2 = DAT_40106e04;
  if ((uVar2 & 0x42) != 0) {
    local_14 = uVar2 & 2;
    if (local_14 == 0) {
      if (DAT_000882c8 < 0x400) {
        uVar3 = DAT_40106e30;
        DAT_000882c8 = DAT_000882c8 + 1;
        (&DAT_00087ec8)[DAT_000882cc] = (char)uVar3;
        DAT_000882cc = DAT_000882cc + 1 & 0x3ff;
        uStack_10 = param_3;
        iVar4 = xEventGroupSetBitsFromISR(DAT_00087ec4,1,&local_14,&DAT_00087ec4,param_1);
        if ((iVar4 != 0) && (local_14 != 0)) {
          DAT_e000ed04 = 0x10000000;
        }
      }
    }
    else {
      uVar3 = DAT_40106e30;
      DAT_40106e04 = 2;
    }
  }
  if ((uVar2 & 0x21) != 0) {
    if (DAT_000886d4 != 0) {
      pbVar1 = &DAT_000882d4 + DAT_000886dc;
      DAT_000886dc = DAT_000886dc + 1 & 0x3ff;
      DAT_000886d4 = DAT_000886d4 + -1;
      DAT_40106e20 = (uint)*pbVar1;
      if (DAT_000886d4 != 0) {
        return;
      }
    }
    DAT_40106e14 = 5;
  }
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
    ipc_send(auStack_a0);
    ulTaskNotifyTake(1,0xffffffff);
  } while( true );
}


// ===== create_IpcTasks @ 00080f80 (82 bytes)

void create_IpcTasks(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  int iVar2;
  
  DAT_000886e0 = xQueueGenericCreate(8,0x98,0,param_4,param_1,param_2,param_3);
  iVar1 = get_task_handles();
  iVar2 = xTaskCreate(0x85fc7,"IpcRecvTask",0x1800,iVar1,2,iVar1 + 8);
  if (iVar2 != 1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  iVar1 = xTaskCreate(0x80f51,"IpcSendTask",0x1800,iVar1,2,iVar1 + 4);
  if (iVar1 != 1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== ipc_print_dsp_reply @ 00080fe8 (130 bytes)

void ipc_print_dsp_reply(int param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  char *pcVar2;
  uint uStack_c;
  uint uStack_8;
  uint uStack_4;
  
  uStack_8 = (uint)*(byte *)(param_1 + 8);
  uStack_c = uStack_8;
  if (uStack_8 == 1) {
    param_4 = (uint)*(byte *)(param_1 + 0xc);
    if (param_4 == 0) {
      uStack_c = *(uint *)(param_1 + 0x14);
      if (uStack_c == 0) {
        param_4 = *(uint *)(param_1 + 0x18);
        if (param_4 == 0) {
          pcVar2 = "\r\nMute off\r\n>> ";
        }
        else {
          pcVar2 = "\r\nMute on\r\n>> ";
        }
      }
      else {
        pcVar2 = "\r\nMute error (%d)\r\n>> ";
      }
    }
    else {
      pcVar2 = "\r\nIncoming unknown message category %d\r\n>> ";
    }
  }
  else if (uStack_8 == 3) {
    param_4 = (uint)*(byte *)(param_1 + 0xc);
    if (param_4 == 0) {
      if (*(uint *)(param_1 + 0x14) == 0) {
        pcVar2 = "DSP Version %04X\r\n>> ";
        uStack_c = *(uint *)(param_1 + 0x18);
      }
      else {
        pcVar2 = "DSP Version error (%d)\r\n>> ";
        uStack_c = *(uint *)(param_1 + 0x14);
      }
    }
    else {
      pcVar2 = "Incoming unknown message category %d\r\n>> ";
    }
  }
  else {
    if (uStack_8 != 0) {
      return;
    }
    uStack_c = (uint)*(byte *)(param_1 + 0xc);
    if (uStack_c == 0) {
      pcVar2 = "Component versions from DSP:\r\n";
    }
    else {
      pcVar2 = "Incoming unknown message command %d from category %d\r\n";
    }
  }
  uStack_4 = param_4;
  sprintf(&DAT_00088c2c,pcVar2,&uStack_c,param_4,pcVar2,&uStack_c);
  uVar1 = strlen(&DAT_00088c2c);
  uart0_write(&DAT_00088c2c,uVar1);
  return;
}


// ===== get_task_handles @ 00081064 (4 bytes)

undefined * get_task_handles(void)

{
  return &DAT_000886e4;
}


// ===== app_main @ 0008106c (218 bytes)

undefined4 app_main(void)

{
  uint uVar1;
  
  memset(&DAT_000886e4,0,0xc);
  GPIO_PortInit(&DAT_40100000,0);
  GPIO_PortInit(&DAT_40100000,1);
  GPIO_PortInit(&DAT_40100000,2);
  BOARD_InitPins();
  BOARD_BootClockRUN();
  BOARD_InitDebugConsole();
  regfile_clear();
  DAT_40021048 = 0x80000000;
  INPUTMUX_AttachSignal(&DAT_40026000,1,0x14000015);
  RESET_ClearPeripheralReset(0x41d);
  RESET_ClearPeripheralReset(0x41c);
  aic3204_init();
  sct0_pwm_init();
  ipc_init();
  BOARD_DSP_Init();
  SEMA42_Init(&DAT_40112000);
  SEMA42_ResetAllGates(&DAT_40112000,0x40);
  MU_SetFlags(&DAT_40110000,1);
  do {
    uVar1 = DAT_40110060;
  } while ((uVar1 & 7) != 1);
  SEMA42_Lock(&DAT_40112000,0);
  MU_SetFlags(&DAT_40110000,2);
  DAT_40112003 = 0;
  do {
    uVar1 = DAT_40110060;
  } while ((uVar1 & 7) != 3);
  regfile_write(0,0x101);
  regfile_write(0x4000,1);
  regfile_set_bits(1);
  create_IpcTasks();
  SCTIMER_StartTimer();
  create_CommandTask();
  vTaskStartScheduler();
  return 0;
}


// ===== sct0_pwm_callback @ 00081164 (108 bytes)

void sct0_pwm_callback(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 in_r3;
  uint uVar3;
  
  DAT_000886f4 = DAT_000886f4 + 1;
  if (399 < DAT_000886f4) {
    DAT_000886f4 = 0;
    uVar2 = regfile_read(&DAT_00004005);
    if (uVar2 == 0) {
      uVar2 = 1;
    }
    uVar2 = uVar2 & 0xffff;
    if (0x62 < uVar2) {
      uVar2 = 99;
    }
    DAT_00088d2c = (undefined1)uVar2;
    SCTIMER_UpdatePwmDutycycle(&DAT_40146000,0,uVar2 & 0xff,DAT_000886f0,in_r3);
  }
  uVar2 = DAT_401460f4;
  uVar1 = DAT_401460fc;
  uVar3 = 1 << (DAT_000886f0 & 0xff);
  if (((uVar1 & 0xc0000000 | uVar2 & 0xffff) & uVar3) != 0) {
    DAT_401460f4 = uVar3 & 0xffff;
    DAT_401460fc = uVar3 & 0xc0000000;
  }
  return;
}


// ===== sct0_pwm_init @ 000811e0 (110 bytes)

void sct0_pwm_init(void)

{
  uint uVar1;
  undefined4 uVar2;
  int iVar3;
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 auStack_24 [16];
  
  uVar2 = CLOCK_GetFreq(1);
  SCTIMER_GetDefaultConfig(auStack_24);
  SCTIMER_Init(&DAT_40146000,auStack_24);
  DAT_00088d2c = 1;
  DAT_000886f0 = 0;
  local_28 = 0;
  local_26 = 1;
  local_27 = 1;
  iVar3 = SCTIMER_SetupPwm(&DAT_40146000,&local_28,1,&DAT_00004e20,uVar2,&DAT_000886f0);
  if (iVar3 != 1) {
    uVar1 = DAT_401460f0;
    DAT_401460f0 = 1 << (DAT_000886f0 & 0xff) | uVar1;
    SCTIMER_SetCallback(&DAT_40146000,0x81165);
    DAT_e000e100 = 0x1000;
  }
  return;
}


// ===== SCTIMER_StartTimer @ 00081264 (12 bytes)

void SCTIMER_StartTimer(void)

{
  uint uVar1;
  
  uVar1 = DAT_40146004;
  DAT_40146004 = uVar1 & 0xfffffffb;
  return;
}


// ===== console_cmd_i @ 00081274 (60 bytes)

void console_cmd_i(int param_1,int param_2)

{
  int iVar1;
  
  if (param_2 == 2) {
    iVar1 = strcmp(*(undefined4 *)(param_1 + 4),"db00");
    if (iVar1 == 0) {
      DAT_00088d2d = 0;
      DAT_00088d2e = 0;
    }
    else {
      iVar1 = strcmp(*(undefined4 *)(param_1 + 4),"db01");
      if (iVar1 == 0) {
        DAT_00088d2d = 1;
        DAT_00088d2e = 1;
        console_puts("\r\n>> ");
        return;
      }
    }
  }
  return;
}


// ===== console_cmd_w @ 000812c4 (50 bytes)

void console_cmd_w(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined2 uVar2;
  
  if (param_2 == 3) {
    uVar1 = strtoul(*(undefined4 *)(param_1 + 4),0,0x10);
    uVar2 = strtoul(*(undefined4 *)(param_1 + 8),0,0x10);
    regfile_write(uVar1,uVar2);
    console_puts("\r\n>> ");
    return;
  }
  return;
}


// ===== console_cmd_d @ 000812fc (128 bytes)

void console_cmd_d(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  ushort uVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  int iStack_28;
  int iStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  iStack_28 = param_1;
  iStack_24 = param_2;
  uStack_20 = param_3;
  uStack_1c = param_4;
  if (param_2 == 2) {
    uVar1 = strtoul(*(undefined4 *)(param_1 + 4),0,0x10);
    uVar4 = (uint)uVar1;
    uVar6 = uVar4 + 0x40;
    do {
      snprintf(&iStack_28,0x10,"\r\n %04X :",uVar4);
      console_puts(&iStack_28);
      iVar5 = 0;
      do {
        uVar2 = regfile_read(uVar4 + iVar5 & 0xffff);
        snprintf(&iStack_28,0x10," %04X",uVar2);
        console_puts(&iStack_28);
        iVar3 = uart0_tx_pending();
        if (iVar3 != 0) {
          vTaskDelay(1);
        }
        iVar5 = iVar5 + 1;
      } while (iVar5 != 8);
      uVar4 = uVar4 + 8 & 0xffff;
    } while ((uVar6 & 0xffff) != uVar4);
    console_puts("\r\n>> ");
    return;
  }
  console_puts("\r\n?\r\n>> ");
  return;
}


// ===== console_printf @ 0008138c (36 bytes)

/* vsprintf into 0x88DF0 then console_puts; tail-called by console_cmd_r */

void console_printf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uStack_c;
  undefined4 uStack_8;
  undefined4 uStack_4;
  
  uStack_c = param_2;
  uStack_8 = param_3;
  uStack_4 = param_4;
  sprintf(&DAT_00088df0,param_1,&uStack_c,param_4,param_1,&uStack_c);
  console_puts(&DAT_00088df0);
  return;
}


// ===== console_cmd_r @ 000813b4 (48 bytes)

void console_cmd_r(int param_1,int param_2)

{
  undefined2 uVar1;
  undefined4 uVar2;
  
  if (param_2 == 2) {
    uVar1 = strtoul(*(undefined4 *)(param_1 + 4),0,0x10);
    uVar2 = regfile_read(uVar1);
    console_printf("\r\nr %04X %04X\r\n>> ",uVar1,uVar2);
    return;
  }
  console_puts("\r\n?\r\n>> ");
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
  byte bVar1;
  char cVar2;
  undefined1 uVar3;
  ushort uVar4;
  undefined2 uVar5;
  undefined2 uVar6;
  char *pcVar7;
  int iVar8;
  byte *pbVar9;
  int iVar10;
  undefined4 uVar11;
  uint uVar12;
  byte *pbVar13;
  int iVar14;
  uint uVar15;
  int iVar16;
  uint uVar17;
  int *piVar18;
  byte *pbVar19;
  byte local_41;
  undefined1 auStack_40 [2];
  undefined1 auStack_3e [2];
  char local_3c;
  char local_38 [4];
  char local_34;
  undefined1 auStack_33 [15];
  
  local_41 = (byte)param_1;
  if (param_1 - 0x20U < 0x5f) {
LAB_000814ac:
    if (DAT_00088d2e != '\0') {
      uart0_write(&local_41,1);
    }
    if (DAT_00088def != '\0') {
      if (DAT_00088def != '\x01') {
        return;
      }
      if ((local_41 < 0xe) && ((~(0x2401U >> (uint)local_41) & 1) == 0)) {
        (&DAT_00088d6f)[DAT_00088708] = 0;
        memset(&DAT_00088d2f,0,0x40);
        iVar8 = strlen(&DAT_00088d6f);
        pbVar9 = &DAT_00088d70 + iVar8;
        pbVar19 = &DAT_00088d6f;
        do {
          pbVar13 = pbVar19;
          if (pbVar13 == pbVar9) {
            DAT_00088708 = 0;
            DAT_00088def = 0;
            return;
          }
          uVar15 = ctype_table[*pbVar13] & 1;
          pbVar19 = pbVar13 + 1;
        } while ((ctype_table[*pbVar13] & 1) != 0);
        uVar17 = uVar15;
        if (pbVar13 < pbVar9) {
          do {
            bVar1 = *pbVar13;
            if (((ctype_table[bVar1] & 1) != 0) || (bVar1 == 0)) {
              while( true ) {
                if (pbVar9 == pbVar13) goto LAB_00081626;
                uVar12 = (uint)*pbVar13;
                pbVar19 = pbVar13 + 1;
                uVar15 = ctype_table[uVar12] & 1;
                if ((ctype_table[uVar12] & 1) == 0) break;
                pbVar13 = pbVar19;
                if ((uVar12 < 0xe) && ((int)((0x2401U >> uVar12) << 0x1f) < 0)) goto LAB_00081596;
              }
              if (uVar12 == 0) {
LAB_00081596:
                iVar8 = 0;
                iVar16 = uVar17 + 1;
                piVar18 = (int *)&DAT_000886f8;
                do {
                  iVar10 = strlen(*piVar18);
                  if (DAT_00088d2d != '\0') {
                    for (iVar14 = 0; iVar14 < iVar10; iVar14 = iVar14 + 1) {
                      uVar3 = tolower(*(undefined1 *)(*piVar18 + iVar14));
                      *(undefined1 *)(*piVar18 + iVar14) = uVar3;
                    }
                  }
                  iVar14 = *piVar18;
                  iVar10 = strlen(iVar14);
                  if (iVar10 != 0) {
                    while (iVar10 = iVar10 + -1, -1 < iVar10) {
                      if ((int)((uint)ctype_table[*(byte *)(iVar14 + iVar10)] << 0x1f) < 0) {
                        *(undefined1 *)(iVar14 + iVar10) = 0;
                      }
                    }
                  }
                  cVar2 = DAT_00088d2d;
                  pbVar19 = DAT_000886f8;
                  iVar8 = iVar8 + 1;
                  piVar18 = piVar18 + 1;
                } while (iVar8 != iVar16);
                if (DAT_00088d2d == '\0') {
                  pbVar9 = DAT_000886f8 + 1;
                  bVar1 = *DAT_000886f8;
                  iVar8 = is_hex_string(pbVar9);
                  if (iVar8 != 0) {
                    iVar8 = strlen(pbVar19);
                    if (iVar8 == 7) {
                      iVar8 = frame_checksum_ok(pbVar19,5);
                      if (iVar8 != 0) {
                        memcpy(auStack_40,pbVar9,4);
                        local_3c = cVar2;
                        uVar4 = strtoul(auStack_40,0);
                        uVar15 = (uint)uVar4;
                        if (bVar1 == 100) {
LAB_00081778:
                          uVar17 = uVar15 + 0x40;
                          do {
                            snprintf(local_38,0x10,"\r\n%04X :",uVar15);
                            console_puts(local_38);
                            iVar8 = 0;
                            do {
                              uVar11 = regfile_read(uVar15 + iVar8 & 0xffff);
                              snprintf(local_38,0x10," %04X",uVar11);
                              console_puts(local_38);
                              iVar10 = uart0_tx_pending();
                              if (iVar10 != 0) {
                                vTaskDelay(1);
                              }
                              iVar8 = iVar8 + 1;
                            } while (iVar8 != 8);
                            uVar15 = uVar15 + 8 & 0xffff;
                          } while ((uVar17 & 0xffff) != uVar15);
                          pcVar7 = "\r\n";
                          goto LAB_00081772;
                        }
                        if (bVar1 < 0x65) {
                          if (bVar1 != 0x49) {
                            if (bVar1 == 0x52) goto LAB_0008172a;
                            if (bVar1 != 0x44) goto LAB_00081716;
                            goto LAB_00081778;
                          }
                        }
                        else if (bVar1 != 0x69) {
                          if (bVar1 != 0x72) goto LAB_00081716;
LAB_0008172a:
                          uVar11 = regfile_read(uVar15);
                          local_38[0] = 0x72;
                          siprintf(local_38 + 1,"%04X",uVar11);
                          siprintf(auStack_33,"%02X",
                                   local_34 + local_38[3] + local_38[2] + local_38[1] + local_38[0])
                          ;
                          pcVar7 = local_38;
                          goto LAB_00081772;
                        }
                        iVar8 = strncmp(auStack_40,"db",2);
                        if ((iVar8 == 0) || (iVar8 = strncmp(auStack_40,"DB",2), iVar8 == 0)) {
                          iVar8 = strncmp(auStack_3e,"00",2);
                          if (iVar8 == 0) {
                            DAT_00088d2d = '\0';
                            DAT_00088d2e = DAT_00088d2d;
                          }
                          else {
                            iVar8 = strncmp(auStack_3e,"01",2);
                            if (iVar8 == 0) {
                              DAT_00088d2d = '\x01';
                              DAT_00088d2e = '\x01';
                            }
                          }
                        }
                        goto LAB_00081716;
                      }
LAB_00081828:
                      pcVar7 = "?";
                    }
                    else {
                      if ((iVar8 != 0xb) || (iVar8 = frame_checksum_ok(pbVar19,9), iVar8 == 0))
                      goto LAB_00081828;
                      memcpy(auStack_40,pbVar9,4);
                      local_3c = cVar2;
                      uVar5 = strtoul(auStack_40,0);
                      memcpy(auStack_40,pbVar19 + 5,4);
                      uVar6 = strtoul(auStack_40,0);
                      if ((bVar1 & 0xdf) != 0x57) goto LAB_00081716;
                      regfile_write(uVar5,uVar6);
                      pcVar7 = "\x06";
                    }
LAB_00081772:
                    console_puts(pcVar7);
                  }
LAB_00081716:
                  if (iVar16 != 4) {
                    DAT_00088708 = 0;
                    DAT_00088def = 0;
                    return;
                  }
                }
                else {
                  pcVar7 = "r";
                  iVar8 = 0;
                  do {
                    iVar10 = strcmp(DAT_000886f8,pcVar7);
                    if (iVar10 == 0) {
                      (*(code *)(&DAT_0008796c)[iVar8 * 5])(&DAT_000886f8,iVar16);
                      DAT_00088708 = 0;
                      DAT_00088def = 0;
                      return;
                    }
                    iVar8 = iVar8 + 1;
                    pcVar7 = pcVar7 + 0x14;
                  } while (iVar8 != 4);
                }
                if (DAT_00088d2d == '\0') {
                  DAT_00088708 = 0;
                  DAT_00088def = 0;
                  return;
                }
                pcVar7 = "\r\n?\r\n>> ";
                goto LAB_00081676;
              }
              uVar17 = uVar17 + 1;
              if (uVar17 != 4) goto LAB_00081584;
              break;
            }
            (&DAT_00088d2f)[uVar15 + uVar17 * 0x10] = bVar1;
            uVar15 = uVar15 + 1;
            if (uVar15 == 0xf) break;
            pbVar13 = pbVar13 + 1;
LAB_00081584:
          } while (pbVar9 != pbVar13);
LAB_00081626:
          if (DAT_00088d2d != '\0') {
            pcVar7 = "\r\n?\r\n>> ";
LAB_00081676:
            console_puts(pcVar7);
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
      console_puts("\r\n>> ");
      if (DAT_00088d2e == '\0') {
        return;
      }
      pcVar7 = "\r\nCtrl+C\r\n>> ";
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
  pcVar7 = "\r\n>> ";
LAB_0008145a:
  console_puts(pcVar7);
  return;
}


// ===== MU_A_IRQHandler @ 000818b8 (46 bytes)

void MU_A_IRQHandler(void)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  iVar1 = DAT_40110060;
  if (-1 < iVar1 << 5) {
    return;
  }
  iVar1 = DAT_40110044;
  iVar1 = (iVar1 << 0xf) >> 0x1f;
  if (0x1f < (uint)-iVar1) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if ((*(int *)(&DAT_00088720 + iVar1 * -4) != 0) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(*(int *)(&DAT_00088720 + iVar1 * -4) + 0x30),
     UNRECOVERED_JUMPTABLE != (code *)0x0)) {
                    /* WARNING: Could not recover jumptable at 0x0008653e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (*UNRECOVERED_JUMPTABLE)();
    return;
  }
  return;
}

