// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_18400000 @ 18400000 (1 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_18400000(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_18a00000 @ 18a00000 (1 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_18a00000(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== Reset_Handler @ 2010002c (84 bytes)

/* WARNING: Removing unreachable block (ram,0x2010005c) */
/* WARNING: Removing unreachable block (ram,0x20100068) */
/* WARNING: Removing unreachable block (ram,0x20100078) */
/* WARNING: Removing unreachable block (ram,0x20100080) */
/* WARNING: Removing unreachable block (ram,0x2010009c) */
/* WARNING: Removing unreachable block (ram,0x201000ac) */
/* WARNING: Removing unreachable block (ram,0x201000b8) */
/* WARNING: Removing unreachable block (ram,0x201000c8) */
/* vector 0; copies image to 0x20100000 if not running there */

void Reset_Handler(void)

{
  uint uVar1;
  undefined4 in_cr0;
  undefined4 in_cr12;
  
  FUN_20101088(0);
  FUN_20100d0c();
  cpg_early_init();
  FUN_20100d48();
  FUN_20100e24(vec_reset,0x400000);
  FUN_20100e24(&PTR_DAT_20800000,0x200000);
  FUN_20100d6c();
  coprocessor_moveto(0xf,0,0,0x20100000,in_cr12,in_cr0);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xffffdfff);
  __main(0xdf);
  return;
}


// ===== reset_in_ram @ 20100080 (216 bytes)

/* SPIBSC init, boot-bank select, copies rest of image */

void reset_in_ram(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  uint uVar1;
  byte *pbVar2;
  byte *pbVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  undefined4 uVar8;
  undefined4 uVar9;
  undefined4 uVar10;
  undefined4 uVar11;
  undefined4 in_cr0;
  undefined4 in_cr12;
  
  spibsc0_init();
  boot_select_bank();
  do {
    uVar4 = *param_2;
    uVar5 = param_2[1];
    uVar6 = param_2[2];
    uVar7 = param_2[3];
    uVar8 = param_2[4];
    uVar9 = param_2[5];
    uVar10 = param_2[6];
    uVar11 = param_2[7];
    param_2 = param_2 + 8;
    *param_3 = uVar4;
    param_3[1] = uVar5;
    param_3[2] = uVar6;
    param_3[3] = uVar7;
    param_3[4] = uVar8;
    param_3[5] = uVar9;
    param_3[6] = uVar10;
    param_3[7] = uVar11;
    param_3 = param_3 + 8;
  } while ((int)param_3 < 0x2042883f);
  pbVar3 = BYTE_ARRAY_204286f8 + 0x148;
  pbVar2 = BYTE_ARRAY_204286f8 + (0x148 - param_1);
  do {
    uVar4 = *(undefined4 *)pbVar2;
    uVar5 = *(undefined4 *)(pbVar2 + 4);
    uVar6 = *(undefined4 *)(pbVar2 + 8);
    uVar7 = *(undefined4 *)(pbVar2 + 0xc);
    uVar8 = *(undefined4 *)(pbVar2 + 0x10);
    uVar9 = *(undefined4 *)(pbVar2 + 0x14);
    uVar10 = *(undefined4 *)(pbVar2 + 0x18);
    uVar11 = *(undefined4 *)(pbVar2 + 0x1c);
    pbVar2 = pbVar2 + 0x20;
    *(undefined4 *)pbVar3 = uVar4;
    *(undefined4 *)(pbVar3 + 4) = uVar5;
    *(undefined4 *)(pbVar3 + 8) = uVar6;
    *(undefined4 *)(pbVar3 + 0xc) = uVar7;
    *(undefined4 *)(pbVar3 + 0x10) = uVar8;
    *(undefined4 *)(pbVar3 + 0x14) = uVar9;
    *(undefined4 *)(pbVar3 + 0x18) = uVar10;
    *(undefined4 *)(pbVar3 + 0x1c) = uVar11;
    pbVar3 = pbVar3 + 0x20;
  } while ((int)pbVar3 < 0x2043ffff);
  FUN_20100d48();
  FUN_20100e24(vec_reset,0x400000);
  FUN_20100e24(&PTR_DAT_20800000,0x200000);
  FUN_20100d6c();
  coprocessor_moveto(0xf,0,0,0x20100000,in_cr12,in_cr0);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xffffdfff);
  __main(0xdf);
  return;
}


// ===== SVC_Handler @ 20100194 (68 bytes)

/* WARNING: Removing unreachable block (ram,0x201001a8) */
/* WARNING: Removing unreachable block (ram,0x201001ac) */

undefined8 SVC_Handler(code *UNRECOVERED_JUMPTABLE,undefined4 param_2)

{
  int unaff_lr;
  undefined8 uVar1;
  
  if ((*(uint *)(unaff_lr + -4) & 0xffffff) != 0) {
    return CONCAT44(param_2,UNRECOVERED_JUMPTABLE);
  }
                    /* WARNING: Could not recover jumptable at 0x201001c0. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (*UNRECOVERED_JUMPTABLE)();
  return uVar1;
}


// ===== IRQ_Handler @ 201001d8 (68 bytes)

/* WARNING: Removing unreachable block (ram,0x201001e8) */
/* GIC dispatch via 0x201176b4 */

void IRQ_Handler(void)

{
  code *pcVar1;
  undefined8 uVar2;
  
  uVar2 = gic_dispatch();
  if ((int)uVar2 != 0) {
    pcVar1 = (code *)FUN_2015632c((int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
    (*pcVar1)();
    software_interrupt(0);
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== FIQ_Handler @ 2010021c (4 bytes)

void FIQ_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== Undef_Handler @ 20100220 (4 bytes)

void Undef_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== PAbort_Handler @ 20100224 (4 bytes)

void PAbort_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== DAbort_Handler @ 20100228 (4 bytes)

void DAbort_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== wdt_system_reset @ 20100268 (68 bytes)

/* WTCSR/WTCNT/WRCSR 0xFCFE0000 sequence: watchdog reset of the DISPLAY CPU */

void wdt_system_reset(void)

{
  DAT_fcfe0004 = 0xa500;
  DataMemoryBarrier(2);
  DAT_fcfe0004 = 0x5a5f;
  DAT_fcfe0002 = 0x5aff;
  DataMemoryBarrier(2);
  DAT_fcfe0000 = 0xa578;
  return;
}


// ===== gpio_cfg_mask @ 201002ac (156 bytes)

/* (Pn ptr, mask|value<<16, flag): bulk port-mode pin set-up */

void gpio_cfg_mask(ushort *param_1,uint param_2,int param_3)

{
  ushort uVar1;
  uint uVar2;
  ushort *puVar3;
  
  if (param_1 == (ushort *)0x0) {
    return;
  }
  uVar1 = (ushort)param_2;
  param_1[0x2000] = param_1[0x2000] & ~uVar1;
  param_1[0x2080] = param_1[0x2080] & ~uVar1;
  puVar3 = param_1 + 0x180;
  *puVar3 = *puVar3 | uVar1;
  param_1[0x200] = param_1[0x200] & ~uVar1;
  param_1[0x2100] = param_1[0x2100] & ~uVar1;
  if (param_2 >> 0x10 != 0) {
    *param_1 = *param_1 | uVar1;
  }
  *puVar3 = *puVar3 & ~uVar1;
  uVar2 = 0;
  if (param_3 != 0) {
    uVar2 = param_2 & 0xffff;
  }
  *(uint *)(param_1 + 0x80) = uVar2 | param_2 << 0x10;
  return;
}


// ===== system_reset_select @ 20100348 (88 bytes)

/* 1: WDT reset; 2: P0 pin set-up then WDT reset */

void system_reset_select(int param_1)

{
  if (param_1 == 1) {
    wdt_system_reset();
    return;
  }
  if (param_1 == 2) {
    gpio_cfg_mask(0,0x4000,1);
    gpio_cfg_mask(0,0x10,1);
    gpio_cfg_mask(&DAT_fcfe302c,0x10004,1);
    wdt_system_reset();
    return;
  }
  return;
}


// ===== gpio_cfg_reset @ 201003a0 (116 bytes)

/* (port,pin): PIBC/PBDC/PMC/PIPC = 0, PM = 1 */

void gpio_cfg_reset(int param_1,uint param_2)

{
  ushort uVar1;
  
  uVar1 = (ushort)(1 << (param_2 & 0xff));
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4000) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4000) & ~uVar1;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4100) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4100) & ~uVar1;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) | uVar1;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) & ~uVar1;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) & ~uVar1;
  return;
}


// ===== gpio_cfg_out_low @ 20100414 (68 bytes)

/* (port,pin): port mode, output, level 0 */

void gpio_cfg_out_low(int param_1,uint param_2)

{
  ushort uVar1;
  
  gpio_cfg_reset(param_1);
  uVar1 = (ushort)(1 << (param_2 & 0xff));
  *(ushort *)(&PTR_DAT_20800000)[param_1] = *(ushort *)(&PTR_DAT_20800000)[param_1] & ~uVar1;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) & ~uVar1;
  return;
}


// ===== gpio_early_init @ 20100458 (40 bytes)

/* from cpg_early_init: P7_11 (RZ_PWR_ON) output low */

void gpio_early_init(void)

{
  system_reset_select(0);
  DAT_2080001c = &DAT_fcfe301c;
  gpio_cfg_out_low(7,0xb);
  return;
}


// ===== gpio_p7_9_11 @ 20100480 (36 bytes)

/* P7_11 and P7_9 via PSR7 */

void gpio_p7_9_11(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 != 0) {
    uVar1 = 0x8000800;
  }
  else {
    uVar1 = 0x8000000;
  }
  DAT_fcfe311c = uVar1;
  if (param_1 != 0) {
    uVar1 = 0x2000200;
  }
  else {
    uVar1 = 0x2000000;
  }
  DAT_fcfe311c = uVar1;
  return;
}


// ===== gpio_set_alt_func @ 20100534 (292 bytes)

/* (port,pin,func 1..8): PFC/PFCE/PFCAE bits = func-1 */

void gpio_set_alt_func(int param_1,uint param_2,undefined4 param_3)

{
  ushort uVar1;
  ushort *puVar2;
  ushort uVar3;
  
  uVar1 = (ushort)(1 << (param_2 & 0xff));
  switch(param_3) {
  case 0:
    goto switchD_2010054c_default;
  case 1:
    break;
  case 2:
    break;
  case 3:
    break;
  case 4:
    break;
  case 5:
    goto LAB_2010058c;
  case 6:
    goto LAB_2010058c;
  case 7:
    goto LAB_2010058c;
  case 8:
LAB_2010058c:
    puVar2 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0xa00);
    uVar3 = *puVar2 | uVar1;
    goto LAB_2010059c;
  default:
    goto switchD_2010054c_default;
  }
  puVar2 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0xa00);
  uVar3 = *puVar2 & ~uVar1;
LAB_2010059c:
  *puVar2 = uVar3;
switchD_2010054c_default:
  switch(param_3) {
  case 0:
    goto switchD_201005a4_default;
  case 1:
    break;
  case 2:
    break;
  case 3:
    goto LAB_20100618;
  case 4:
    goto LAB_20100618;
  case 5:
    break;
  case 6:
    break;
  case 7:
    goto LAB_20100618;
  case 8:
LAB_20100618:
    puVar2 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0x600);
    uVar3 = *puVar2 | uVar1;
    goto LAB_201005d0;
  default:
    goto switchD_201005a4_default;
  }
  puVar2 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0x600);
  uVar3 = *puVar2 & ~uVar1;
LAB_201005d0:
  *puVar2 = uVar3;
switchD_201005a4_default:
  switch(param_3) {
  case 0:
    return;
  case 1:
    break;
  case 2:
    goto LAB_20100640;
  case 3:
    break;
  case 4:
    goto LAB_20100640;
  case 5:
    break;
  case 6:
    goto LAB_20100640;
  case 7:
    break;
  case 8:
LAB_20100640:
    puVar2 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0x500);
    uVar1 = uVar1 | *puVar2;
    goto LAB_20100650;
  default:
    return;
  }
  puVar2 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0x500);
  uVar1 = *puVar2 & ~uVar1;
LAB_20100650:
  *puVar2 = uVar1;
  return;
}


// ===== gpio_cfg_alt @ 20100658 (324 bytes)

/* (port,pin,func,mode): PMC=1, alt function; mode 0 PIPC, 1 in, 2 out, 3 bidir */

void gpio_cfg_alt(int param_1,uint param_2,undefined4 param_3,int param_4)

{
  ushort *puVar1;
  ushort uVar2;
  
  uVar2 = (ushort)(1 << (param_2 & 0xff));
  gpio_cfg_reset(param_1);
  gpio_set_alt_func(param_1,param_2,param_3);
  if (param_4 == 0) {
    *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) =
         *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) | uVar2;
    *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) =
         *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) | uVar2;
    return;
  }
  if (param_4 != 1) {
    if (param_4 == 2) {
      *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) =
           *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) & ~uVar2;
      *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) =
           *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) | uVar2;
      puVar1 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0x300);
      uVar2 = *puVar1 & ~uVar2;
    }
    else {
      if (param_4 != 3) {
        return;
      }
      *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4100) =
           *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4100) | uVar2;
      *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) =
           *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) | uVar2;
      puVar1 = (ushort *)((&PTR_DAT_20800000)[param_1] + 0x400);
      uVar2 = *puVar1 | uVar2;
    }
    *puVar1 = uVar2;
    return;
  }
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4200) & ~uVar2;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x400) | uVar2;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) | uVar2;
  return;
}


// ===== spibsc0_pins_init @ 2010079c (140 bytes)

/* P9_2..P9_7 alt 2 (QF_CLK/CSn/DAT0..3) */

void spibsc0_pins_init(void)

{
  PTR_DAT_20800024 = &DAT_fcfe3024;
  gpio_cfg_alt(9,2,2,0);
  gpio_cfg_alt(9,3,2,0);
  gpio_cfg_alt(9,4,2,0);
  gpio_cfg_alt(9,5,2,0);
  gpio_cfg_alt(9,6,2,0);
  gpio_cfg_alt(9,7,2,0);
  return;
}


// ===== spibsc0_init @ 20100828 (68 bytes)

/* writes SPIBSC0 regs 0x3FEFA0xx */

void spibsc0_init(void)

{
  uint uVar1;
  
  spibsc0_pins_init();
  DAT_3fefa008 = 1;
  DAT_3fefa010 = 0xeb0000;
  DAT_3fefa01c = 0x222c780;
  DAT_3fefa018 = 0xff000000;
  uVar1 = DAT_3fefa058;
  DAT_3fefa058 = uVar1 | 3;
  return;
}


// ===== gpio_cfg_out_high @ 20100838 (68 bytes)

/* (port,pin): port mode, output, level 1 */

void gpio_cfg_out_high(int param_1,uint param_2)

{
  ushort uVar1;
  
  gpio_cfg_reset(param_1);
  uVar1 = (ushort)(1 << (param_2 & 0xff));
  *(ushort *)(&PTR_DAT_20800000)[param_1] = *(ushort *)(&PTR_DAT_20800000)[param_1] | uVar1;
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x300) & ~uVar1;
  return;
}


// ===== gpio_cfg_input @ 2010087c (48 bytes)

/* (port,pin): port mode, input buffer on (PIBC) */

void gpio_cfg_input(int param_1,uint param_2)

{
  gpio_cfg_reset();
  *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4000) =
       *(ushort *)((&PTR_DAT_20800000)[param_1] + 0x4000) | (ushort)(1 << (param_2 & 0xff));
  return;
}


// ===== gpio_read_bit @ 201008ac (180 bytes)

/* (port, bit) -> PPRn bit (0xFCFE3200 + 4n) */

uint gpio_read_bit(undefined4 param_1,uint param_2)

{
  ushort uVar1;
  uint uVar2;
  
  switch(param_1) {
  case 0:
    uVar1 = DAT_fcfe3200;
    uVar2 = (uint)uVar1;
    break;
  case 1:
    uVar1 = DAT_fcfe3204;
    uVar2 = (uint)uVar1;
    break;
  case 2:
    uVar1 = DAT_fcfe3208;
    uVar2 = (uint)uVar1;
    break;
  case 3:
    uVar1 = DAT_fcfe320c;
    uVar2 = (uint)uVar1;
    break;
  case 4:
    uVar1 = DAT_fcfe3210;
    uVar2 = (uint)uVar1;
    break;
  case 5:
    uVar1 = DAT_fcfe3214;
    uVar2 = (uint)uVar1;
    break;
  case 6:
    uVar1 = DAT_fcfe3218;
    uVar2 = (uint)uVar1;
    break;
  case 7:
    uVar1 = DAT_fcfe321c;
    uVar2 = (uint)uVar1;
    break;
  case 8:
    uVar1 = DAT_fcfe3220;
    uVar2 = (uint)uVar1;
    break;
  case 9:
    uVar1 = DAT_fcfe3224;
    uVar2 = (uint)uVar1;
    break;
  case 10:
    uVar1 = DAT_fcfe3228;
    uVar2 = (uint)uVar1;
    break;
  case 0xb:
    uVar1 = DAT_fcfe322c;
    uVar2 = (uint)uVar1;
    break;
  default:
    return 0xffffffff;
  }
  return uVar2 & 1 << (param_2 & 0xff);
}


// ===== crc16_a001_table_init @ 20100990 (76 bytes)

/* table at 0x208D9560 */

void crc16_a001_table_init(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar2 = 0;
    uVar1 = uVar3;
    do {
      uVar2 = uVar2 + 1;
      if ((uVar1 & 1) == 0) {
        uVar1 = uVar1 >> 1;
      }
      else {
        uVar1 = uVar1 >> 1 ^ 0xa001;
      }
    } while (uVar2 < 8);
    (&DAT_208d9560)[uVar3] = uVar1 & 0xffff;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  return;
}


// ===== crc16_a001 @ 201009dc (56 bytes)

/* CRC-16 reflected 0xA001, init/xorout 0xFFFF */

uint crc16_a001(uint param_1,int param_2,byte *param_3)

{
  while (param_2 = param_2 + -1, -1 < param_2) {
    param_1 = ((&DAT_208d9560)[(*param_3 ^ param_1) & 0xff] ^ param_1 >> 8) & 0xffff;
    param_3 = param_3 + 1;
  }
  return param_1 ^ 0xffff;
}


// ===== crc32_make_table @ 20100a14 (72 bytes)

/* reflected poly 0xEDB88320 */

void crc32_make_table(void)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = 0;
  do {
    uVar2 = 0;
    uVar1 = uVar3;
    do {
      if ((uVar1 & 1) == 0) {
        uVar1 = uVar1 >> 1;
      }
      else {
        uVar1 = uVar1 >> 1 ^ 0xedb88320;
      }
      uVar2 = uVar2 + 1;
    } while (uVar2 < 8);
    (&DAT_208d9560)[uVar3] = uVar1;
    uVar3 = uVar3 + 1;
  } while (uVar3 < 0x100);
  return;
}


// ===== crc32_update @ 20100a5c (44 bytes)

void crc32_update(undefined4 param_1,int param_2)

{
  do {
    param_2 = param_2 + -1;
  } while (-1 < param_2);
  return;
}


// ===== FUN_20100a98 @ 20100a98 (36 bytes)

void FUN_20100a98(int param_1,undefined1 param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 1) {
    *(undefined1 *)(param_1 + uVar1) = param_2;
  }
  return;
}


// ===== boot_select_bank @ 20100abc (236 bytes)

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
/* first boot: checks 0x183E0000/0x183F0000 flags, jumps to 0x18400000 or 0x18A00000 */

void boot_select_bank(void)

{
  bool bVar1;
  int iVar2;
  bool bVar3;
  
  bVar3 = false;
  bVar1 = false;
  iVar2 = DAT_3fefb018;
  if (iVar2 == 0) {
    DAT_3fefb018 = 0x20000000;
    FUN_20100a98(0x20000000,0,0x60);
    _DAT_20000000 = 0xbbbb;
    uRam20000004 = 0x100;
    uRam20000008 = 1;
    uRam20000020 = 0x3e0000;
    uRam20000024 = 0x400000;
    uRam20000040 = 0x3f0000;
    uRam20000044 = 0xa00000;
    if (DAT_183e0000 == 0x11111111) {
      bVar3 = DAT_183e0004 != 0;
    }
    else if (DAT_183f0000 == 0x11111111) {
      if (DAT_183f0004 == 0) {
        bVar1 = false;
      }
      else {
        bVar1 = true;
      }
    }
    if (bVar3) {
      if (!bVar1) {
        _DAT_20000000 = 1;
        FUN_18400000();
      }
    }
    else if (bVar1) {
      _DAT_20000000 = 2;
      FUN_18a00000();
    }
    uRam20000008 = 3;
    return;
  }
  return;
}


// ===== __main @ 20100bc0 (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20100bda) */
/* WARNING: Removing unreachable block (ram,0x20100bec) */

void __main(void)

{
  __scatterload();
  __rt_entry();
                    /* WARNING: Could not recover jumptable at 0x20100bf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __decompress(0x2042886c,0x20450000,0x290);
  return;
}


// ===== __scatterload @ 20100bc8 (44 bytes)

/* WARNING: Removing unreachable block (ram,0x20100bda) */
/* WARNING: Removing unreachable block (ram,0x20100bec) */

void __scatterload(void)

{
                    /* WARNING: Could not recover jumptable at 0x20100bf2. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  __decompress(0x2042886c,0x20450000,0x290);
  return;
}


// ===== __decompress @ 20100bfc (100 bytes)

/* armcc LZ decompressor for RW regions */

void __decompress(byte *param_1,byte *param_2,int param_3)

{
  byte bVar1;
  int iVar2;
  byte *pbVar3;
  byte *pbVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  byte *pbVar8;
  uint uVar9;
  
  bVar1 = *param_1;
  pbVar4 = param_2 + param_3;
  while( true ) {
    uVar5 = (uint)bVar1;
    uVar7 = uVar5 & 3;
    pbVar3 = param_1 + 1;
    if ((bVar1 & 3) == 0) {
      pbVar3 = param_1 + 2;
      uVar7 = (uint)param_1[1];
    }
    uVar9 = (int)uVar5 >> 4;
    param_1 = pbVar3;
    if (uVar9 == 0) {
      param_1 = pbVar3 + 1;
      uVar9 = (uint)*pbVar3;
    }
    while (uVar7 = uVar7 - 1, uVar7 != 0) {
      *param_2 = *param_1;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
    if (uVar9 != 0) {
      pbVar3 = param_1 + 1;
      bVar1 = *param_1;
      if ((uVar5 & 0xc) == 0xc) {
        param_1 = param_1 + 2;
        iVar2 = (uint)*pbVar3 * -0x100;
      }
      else {
        iVar2 = (uVar5 & 0xc) * -0x40;
        param_1 = pbVar3;
      }
      iVar6 = uVar9 + 1;
      pbVar3 = param_2;
      pbVar8 = param_2 + (iVar2 - (uint)bVar1);
      do {
        iVar6 = iVar6 + -1;
        param_2 = pbVar3 + 1;
        *pbVar3 = *pbVar8;
        pbVar3 = param_2;
        pbVar8 = pbVar8 + 1;
      } while (-1 < iVar6);
    }
    if (pbVar4 <= param_2) break;
    bVar1 = *param_1;
  }
  return;
}


// ===== __scatterload_zeroinit @ 20100c60 (28 bytes)

void __scatterload_zeroinit(undefined4 param_1,undefined4 *param_2,uint param_3)

{
  uint uVar1;
  
  do {
    uVar1 = param_3;
    param_3 = uVar1 - 0x10;
    if (0xf < uVar1) {
      *param_2 = 0;
      param_2[1] = 0;
      param_2[2] = 0;
      param_2[3] = 0;
      param_2 = param_2 + 4;
    }
  } while (0xf < uVar1 && param_3 != 0);
  if ((param_3 & 8) != 0) {
    *param_2 = 0;
    param_2[1] = 0;
    param_2 = param_2 + 2;
  }
  if ((int)(uVar1 * 0x20000000) < 0) {
    *param_2 = 0;
  }
  return;
}


// ===== FUN_20100c7c @ 20100c7c (1176 bytes)

/* WARNING: Removing unreachable block (ram,0x20155d76) */
/* WARNING: Removing unreachable block (ram,0x20155dd4) */
/* WARNING: Removing unreachable block (ram,0x20155dd6) */
/* WARNING: Removing unreachable block (ram,0x20155de2) */
/* WARNING: Removing unreachable block (ram,0x20155dde) */
/* WARNING: Removing unreachable block (ram,0x20155de4) */
/* WARNING: Removing unreachable block (ram,0x20155dfe) */
/* WARNING: Removing unreachable block (ram,0x20155e02) */
/* WARNING: Removing unreachable block (ram,0x20155e04) */
/* WARNING: Removing unreachable block (ram,0x20155e06) */
/* WARNING: Removing unreachable block (ram,0x20155e0a) */
/* WARNING: Removing unreachable block (ram,0x20155e24) */
/* WARNING: Removing unreachable block (ram,0x20155e14) */
/* WARNING: Removing unreachable block (ram,0x20155e18) */
/* WARNING: Removing unreachable block (ram,0x20155e28) */
/* WARNING: Removing unreachable block (ram,0x20155e32) */
/* WARNING: Removing unreachable block (ram,0x20155e38) */
/* WARNING: Removing unreachable block (ram,0x20155e2c) */
/* WARNING: Removing unreachable block (ram,0x20155e3a) */
/* WARNING: Removing unreachable block (ram,0x20155d70) */
/* WARNING: Removing unreachable block (ram,0x20154b8c) */
/* WARNING: Removing unreachable block (ram,0x20154ba2) */
/* WARNING: Removing unreachable block (ram,0x20154bae) */
/* WARNING: Removing unreachable block (ram,0x20154bb2) */
/* WARNING: Removing unreachable block (ram,0x20154baa) */
/* WARNING: Removing unreachable block (ram,0x20154b94) */
/* WARNING: Removing unreachable block (ram,0x20154bb4) */
/* WARNING: Removing unreachable block (ram,0x20155d78) */
/* WARNING: Removing unreachable block (ram,0x20155d84) */
/* WARNING: Removing unreachable block (ram,0x20155d80) */
/* WARNING: Removing unreachable block (ram,0x20155d86) */
/* WARNING: Removing unreachable block (ram,0x20155e1e) */
/* WARNING: Removing unreachable block (ram,0x20155e44) */
/* WARNING: Removing unreachable block (ram,0x20155e64) */
/* WARNING: Removing unreachable block (ram,0x20155e72) */
/* WARNING: Removing unreachable block (ram,0x20155e8a) */
/* WARNING: Removing unreachable block (ram,0x20155e94) */
/* WARNING: Removing unreachable block (ram,0x20155e7c) */
/* WARNING: Removing unreachable block (ram,0x20155e9a) */
/* WARNING: Removing unreachable block (ram,0x20155eaa) */
/* WARNING: Removing unreachable block (ram,0x20155ea6) */
/* WARNING: Removing unreachable block (ram,0x20155eac) */

undefined4 FUN_20100c7c(uint *param_1,uint param_2,uint *param_3)

{
  undefined1 uVar1;
  uint uVar2;
  undefined4 *puVar3;
  uint *puVar4;
  char extraout_r2;
  char *pcVar5;
  undefined4 uVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  undefined1 *puVar11;
  undefined1 *puVar12;
  undefined8 uVar13;
  longlong lVar14;
  undefined1 local_64 [32];
  int local_44;
  undefined4 local_40;
  int local_3c;
  int local_38;
  int local_34;
  int iStack_30;
  undefined1 local_25;
  
  if (param_2 == 0x66) {
    puVar3 = (undefined4 *)((uint)((int)param_3 + 7) & 0xfffffff8);
    local_40 = *puVar3;
    local_3c = puVar3[1];
    iVar8 = FUN_20163808();
    if (local_3c < 0) {
      local_44 = 0x2d;
    }
    else if ((int)(*param_1 << 0x1e) < 0) {
      local_44 = 0x2b;
    }
    else {
      local_44 = (*param_1 & 4) << 3;
    }
    if ((iVar8 == 3) || (6 < iVar8)) {
      FUN_20156020(param_1,0x66,iVar8,local_44);
    }
    else {
      if ((int)((uint)(byte)*param_1 << 0x1a) < 0) {
        uVar2 = param_1[7];
      }
      else {
        uVar2 = 6;
      }
      FUN_20155b5c(&local_38,local_64,&local_40,uVar2,1);
      iVar7 = 0;
      iVar8 = local_34;
      if (iStack_30 == 0) {
        iVar8 = local_38 + uVar2 + 1;
      }
      iVar10 = uVar2 - iVar8;
      if (-1 < iVar10) {
        iVar8 = uVar2 + 1;
        iVar7 = -1 - iVar10;
      }
      iVar10 = iVar8 - uVar2;
      if ((-1 < (int)((uint)(byte)*param_1 << 0x1c)) && (iVar8 <= iVar10)) {
        iVar10 = -1;
      }
      puVar11 = &local_25;
      local_25 = 0;
      local_25 = 0;
      puVar12 = &local_25 + -(int)puVar11;
      param_1[6] = (param_1[6] - (int)(puVar12 + (uint)(local_44 != 0) + iVar8 + (iVar10 >> 0x1f)))
                   - 1;
      if (-1 < (int)((uint)(byte)*param_1 << 0x1b)) {
        FUN_20154a64(param_1);
      }
      if (local_44 != 0) {
        (*(code *)param_1[1])(local_44,param_1[2]);
        param_1[8] = param_1[8] + 1;
      }
      if ((int)((uint)(byte)*param_1 << 0x1b) < 0) {
        FUN_20154a64(param_1);
      }
      while (iVar9 = iVar8 + -1, 0 < iVar8) {
        if ((iVar7 < 0) || (local_34 <= iVar7)) {
          uVar1 = 0x30;
        }
        else {
          uVar1 = local_64[iVar7];
        }
        (*(code *)param_1[1])(uVar1,param_1[2]);
        param_1[8] = param_1[8] + 1;
        iVar7 = iVar7 + 1;
        iVar10 = iVar10 + -1;
        iVar8 = iVar9;
        if (iVar10 == 0) {
          iVar9 = FUN_201556d0();
          (*(code *)param_1[1])
                    (*(undefined1 *)((int)*(int **)(iVar9 + 0xc) + **(int **)(iVar9 + 0xc)),
                     param_1[2]);
          param_1[8] = param_1[8] + 1;
        }
      }
      while (0 < (int)puVar12) {
        (*(code *)param_1[1])(*puVar11,param_1[2]);
        param_1[8] = param_1[8] + 1;
        puVar11 = puVar11 + 1;
        puVar12 = puVar12 + -1;
      }
      FUN_20154a90(param_1);
    }
    return 3;
  }
  if ((*param_1 >> 7 & 1) != 0) {
    param_2 = param_2 | 0x80;
  }
  if ((param_2 != 100) && (param_2 != 0x75)) {
    if (param_2 == 0x78) {
      uVar2 = *param_3;
      if ((int)((uint)(ushort)*param_1 << 0x14) < 0) {
        pcVar5 = "0123456789ABCDEF@0X";
      }
      else {
        pcVar5 = "0123456789abcdef@0x";
      }
      iVar8 = 0;
      for (; uVar2 != 0; uVar2 = uVar2 >> 4) {
        *(char *)((int)param_1 + iVar8 + 0x24) = pcVar5[uVar2 & 0xf];
        iVar8 = iVar8 + 1;
      }
      iVar7 = 0;
      if (((int)((uint)(byte)*param_1 << 0x1c) < 0) && (iVar8 != 0)) {
        iVar7 = 2;
        pcVar5 = pcVar5 + 0x11;
      }
    }
    else {
      if (param_2 != 0xf5) {
        if (param_2 == 99) {
          puVar4 = param_1 + 9;
          *(byte *)puVar4 = (byte)*param_3;
          *(byte *)((int)param_1 + 0x25) = 0;
          uVar6 = 1;
        }
        else {
          if (param_2 != 0x73) {
            return 0;
          }
          puVar4 = (uint *)*param_3;
          uVar6 = 0xffffffff;
        }
        if (param_1[5] == 0) {
          FUN_20154ab2(param_1,puVar4,uVar6);
        }
        return 1;
      }
      lVar14 = *(longlong *)((uint)((int)param_3 + 7) & 0xfffffff8);
      pcVar5 = "";
      iVar7 = 0;
      iVar8 = 0;
      while (lVar14 != 0) {
        lVar14 = FUN_20155a10();
        *(byte *)((int)param_1 + iVar8 + 0x24) = extraout_r2 + 0x30;
        iVar8 = iVar8 + 1;
      }
    }
    goto LAB_20155aa8;
  }
  iVar7 = 0;
  uVar2 = *param_3;
  pcVar5 = "";
  puVar4 = param_1;
  if (param_2 != 0x75) {
    if ((int)uVar2 < 0) {
      uVar2 = -uVar2;
      pcVar5 = "-";
    }
    else {
      puVar4 = (uint *)*param_1;
      if ((int)puVar4 << 0x1e < 0) {
        pcVar5 = "+";
      }
      else {
        puVar4 = (uint *)((int)puVar4 << 0x1d);
        if (-1 < (int)puVar4) goto LAB_20154b3e;
        pcVar5 = " ";
      }
    }
    iVar7 = 1;
  }
LAB_20154b3e:
  iVar8 = 0;
  while (uVar2 != 0) {
    uVar13 = FUN_20155fec(uVar2,puVar4);
    puVar4 = (uint *)((int)((ulonglong)uVar13 >> 0x20) + 0x30);
    *(byte *)((int)param_1 + iVar8 + 0x24) = (byte)puVar4;
    iVar8 = iVar8 + 1;
    uVar2 = (uint)uVar13;
  }
LAB_20155aa8:
  if ((int)(*param_1 << 0x1a) < 0) {
    uVar2 = param_1[7];
    *param_1 = *param_1 & 0xffffffef;
  }
  else {
    uVar2 = 1;
  }
  if (iVar8 < (int)uVar2) {
    iVar10 = uVar2 - iVar8;
  }
  else {
    iVar10 = 0;
  }
  param_1[6] = param_1[6] - (iVar10 + iVar8 + iVar7);
  if (-1 < (int)((uint)(byte)*param_1 << 0x1b)) {
    FUN_20154a64(param_1);
  }
  for (iVar9 = 0; iVar9 < iVar7; iVar9 = iVar9 + 1) {
    (*(code *)param_1[1])(pcVar5[iVar9],param_1[2]);
    param_1[8] = param_1[8] + 1;
  }
  if ((int)((uint)(byte)*param_1 << 0x1b) < 0) {
    FUN_20154a64(param_1);
  }
  while (0 < iVar10) {
    (*(code *)param_1[1])(0x30,param_1[2]);
    param_1[8] = param_1[8] + 1;
    iVar10 = iVar10 + -1;
  }
  while (0 < iVar8) {
    (*(code *)param_1[1])(*(byte *)((int)param_1 + iVar8 + 0x23),param_1[2]);
    param_1[8] = param_1[8] + 1;
    iVar8 = iVar8 + -1;
  }
  FUN_20154a90(param_1);
  if ((int)((uint)(byte)*param_1 << 0x18) < 0) {
    uVar6 = 2;
  }
  else {
    uVar6 = 1;
  }
  return uVar6;
}


// ===== FUN_20100cb4 @ 20100cb4 (36 bytes)

undefined8 FUN_20100cb4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  iVar1 = FUN_201556d0();
  iVar2 = FUN_20163874(0,0);
  *(int *)(iVar1 + 4) = iVar2 + 1;
  uVar3 = FUN_201638a0(0,0);
  *(undefined4 *)(iVar1 + 0xc) = uVar3;
  FUN_201556ac();
  return CONCAT44(param_2,param_1);
}


// ===== FUN_20100cd8 @ 20100cd8 (4 bytes)

void FUN_20100cd8(void)

{
  return;
}


// ===== __rt_entry @ 20100cdc (48 bytes)

uint __rt_entry(void)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 extraout_r2;
  int extraout_r3;
  undefined8 uVar4;
  
  uVar1 = FUN_201561c0();
  FUN_20100cb4(uVar1,extraout_r2);
  main();
  uVar4 = FUN_2015620a();
  FUN_20100cd8();
  iVar2 = FUN_201561b4((int)uVar4,(int)((ulonglong)uVar4 >> 0x20));
  *(short *)(iVar2 + 0x1c) = (short)iVar2;
  *(short *)(extraout_r3 + 0x20) = (short)iVar2;
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  DataSynchronizationBarrier(0xf);
  coproc_moveto_Invalidate_Entire_Instruction(0);
  coproc_moveto_Instruction_cache(0,6);
  InstructionSynchronizationBarrier(0xf);
  uVar3 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar3 & 0xfffffffd);
  uVar3 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar3 & 0xffffeffa);
  return uVar3 & 0xffffeffa;
}


// ===== FUN_20100d0c @ 20100d0c (60 bytes)

uint FUN_20100d0c(void)

{
  uint uVar1;
  
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  DataSynchronizationBarrier(0xf);
  coproc_moveto_Invalidate_Entire_Instruction(0);
  coproc_moveto_Instruction_cache(0,6);
  InstructionSynchronizationBarrier(0xf);
  uVar1 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar1 & 0xfffffffd);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0xffffeffa);
  return uVar1 & 0xffffeffa;
}


// ===== FUN_20100d48 @ 20100d48 (36 bytes)

void FUN_20100d48(void)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  
  iVar1 = 0x10c02;
  piVar2 = &DAT_2044c000;
  for (iVar3 = 0x1000; iVar3 != 0; iVar3 = iVar3 + -1) {
    *piVar2 = iVar1;
    iVar1 = iVar1 + 0x100000;
    piVar2 = piVar2 + 1;
  }
  return;
}


// ===== FUN_20100d6c @ 20100d6c (84 bytes)

ulonglong FUN_20100d6c(void)

{
  uint uVar1;
  
  coproc_moveto_Translation_table_base_0(0x2044c001);
  coproc_moveto_Translation_table_control(0);
  coproc_moveto_Domain_Access_Control(0x55555555);
  uVar1 = coproc_movefrom_Control();
  coproc_moveto_Control(uVar1 & 0x7be77c7f | 0xc5187d);
  uVar1 = coproc_movefrom_Auxiliary_Control();
  coproc_moveto_Auxiliary_Control(uVar1 | 2);
  return CONCAT44(0xc50078,uVar1) | 2;
}


// ===== FUN_20100e24 @ 20100e24 (104 bytes)

void FUN_20100e24(uint param_1,int param_2)

{
  uint uVar1;
  uint *puVar2;
  
  uVar1 = param_1 >> 0x14;
  puVar2 = &DAT_2044c000 + uVar1;
  for (; uVar1 != param_2 + param_1 + 0xfffff >> 0x14; uVar1 = uVar1 + 1) {
    *puVar2 = *puVar2 & 0xfffe73f3 | 0xc0c;
    puVar2 = puVar2 + 1;
  }
  coproc_moveto_Invalidate_unified_TLB_unlocked(0);
  DataSynchronizationBarrier(0xf);
  coproc_moveto_Instruction_cache(0,6);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== FUN_20100f84 @ 20100f84 (84 bytes)

void FUN_20100f84(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    coproc_moveto_Invalidate_Entire_Instruction(param_1);
  }
  else {
    uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
    iVar1 = 0x10 << (uVar2 & 7);
    uVar2 = param_2 + param_1;
    param_1 = param_1 & ~(iVar1 - 1U);
    do {
      coproc_moveto_Invalidate_Instruction_Cache_by_MVA(param_1);
      param_1 = param_1 + iVar1;
    } while (param_1 < uVar2);
  }
  coproc_moveto_Instruction_cache(param_1,6);
  DataSynchronizationBarrier(0xf);
  InstructionSynchronizationBarrier(0xf);
  return;
}


// ===== FUN_2010101c @ 2010101c (20 bytes)

undefined4 FUN_2010101c(undefined4 param_1)

{
  FUN_201010e0(2);
  return param_1;
}


// ===== FUN_20101030 @ 20101030 (88 bytes)

uint FUN_20101030(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
    iVar1 = 0x10 << (uVar2 & 7);
    uVar2 = param_1 & ~(iVar1 - 1U);
    do {
      coproc_moveto_Clean_Data_Cache_by_MVA(uVar2);
      uVar2 = uVar2 + iVar1;
    } while (uVar2 < param_2 + param_1);
    DataSynchronizationBarrier(0xf);
    return uVar2;
  }
  FUN_201010e0(1);
  return param_1;
}


// ===== FUN_20101088 @ 20101088 (88 bytes)

uint FUN_20101088(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 in_cr0;
  
  if ((param_1 != 0) && (param_2 != 0)) {
    uVar2 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
    iVar1 = 0x10 << (uVar2 & 7);
    uVar2 = param_1 & ~(iVar1 - 1U);
    do {
      coproc_moveto_Invalidate_Entire_Data_by_MVA(uVar2);
      uVar2 = uVar2 + iVar1;
    } while (uVar2 < param_2 + param_1);
    DataSynchronizationBarrier(0xf);
    return uVar2;
  }
  FUN_201010e0(0);
  return param_1;
}


// ===== FUN_201010e0 @ 201010e0 (164 bytes)

longlong FUN_201010e0(int param_1,uint param_2)

{
  bool bVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  undefined4 in_cr0;
  undefined4 in_cr7;
  undefined4 in_cr14;
  
  uVar2 = coprocessor_movefromRt(0xf,1,1,in_cr0,in_cr0);
  if ((uVar2 & 0x7000000) != 0) {
    uVar7 = 0;
    do {
      param_2 = uVar2 >> (uVar7 + (uVar7 >> 1) & 0xff) & 7;
      if (param_2 != 1) {
        if (param_2 == 0) goto LAB_20101178;
        coprocessor_moveto(0xf,2,0,uVar7,in_cr0,in_cr0);
        InstructionSynchronizationBarrier(0xf);
        uVar3 = coprocessor_movefromRt(0xf,1,0,in_cr0,in_cr0);
        uVar4 = uVar3 >> 3 & 0x3ff;
        uVar5 = uVar3 >> 0xd & 0x7fff;
        do {
          uVar6 = uVar4;
          do {
            param_2 = uVar7 | uVar5 << (uVar3 & 7) + 4 | uVar6 << LZCOUNT(uVar4);
            if (param_1 < 1) {
              coproc_moveto_Invalidate_Entire_Data_by_Index(param_2);
            }
            if (param_1 == 1) {
              coproc_moveto_Clean_Data_Cache_by_Index(param_2);
            }
            if (1 < param_1) {
              coprocessor_moveto(0xf,0,2,param_2,in_cr7,in_cr14);
            }
            bVar1 = 0 < (int)uVar6;
            uVar6 = uVar6 - 1;
          } while (bVar1);
          bVar1 = 0 < (int)uVar5;
          uVar5 = uVar5 - 1;
        } while (bVar1);
      }
      uVar7 = uVar7 + 2;
    } while ((int)uVar7 < (int)((uVar2 & 0x7000000) >> 0x17));
    DataSynchronizationBarrier(0xf);
  }
LAB_20101178:
  coprocessor_moveto(0xf,2,0,0,in_cr0,in_cr0);
  return (ulonglong)param_2 << 0x20;
}


// ===== pinmux_init @ 20101190 (2512 bytes)

/* PFC setup of every port pin (2.5 KB of calls) */

void pinmux_init(void)

{
  gpio_cfg_input(0);
  gpio_cfg_input(0,1);
  gpio_cfg_out_low(0,2);
  gpio_cfg_out_low(0,3);
  gpio_cfg_input(0,4);
  gpio_cfg_input(0,5);
  gpio_cfg_out_low(1,0);
  gpio_cfg_out_low(1);
  gpio_cfg_out_low(1,2);
  gpio_cfg_alt(1,3,4,0);
  gpio_cfg_alt(1,4,1,3);
  gpio_cfg_alt(1,5,1,3);
  gpio_cfg_input(1,6);
  gpio_cfg_input(1,7);
  gpio_cfg_alt(1,8,1,0);
  gpio_cfg_alt(1,9,1,0);
  gpio_cfg_input(1,10);
  gpio_cfg_alt(1,0xb,1,0);
  gpio_cfg_alt(1,0xc,1,0);
  gpio_cfg_input(1,0xd);
  gpio_cfg_alt(1,0xe,1,0);
  gpio_cfg_input(1,0xf);
  gpio_cfg_alt(2,0,6);
  gpio_cfg_input(2,1);
  gpio_cfg_input(2);
  gpio_cfg_input(2,3);
  gpio_cfg_input(2,4);
  gpio_cfg_input(2,5);
  gpio_cfg_input(2,6);
  gpio_cfg_out_low(2,7);
  gpio_cfg_alt(2,8,8,0);
  gpio_cfg_alt(2,9,8,0);
  gpio_cfg_alt(2,10,8,0);
  gpio_cfg_alt(2,0xb,8,0);
  gpio_cfg_alt(2,0xc,2,0);
  gpio_cfg_alt(2,0xd,2,0);
  gpio_cfg_alt(2,0xe,2,0);
  gpio_cfg_alt(2,0xf,2,0);
  gpio_cfg_input(3,0);
  gpio_cfg_alt(3,1,3,0);
  gpio_cfg_input(3,2);
  gpio_cfg_alt(3,3,3,0);
  gpio_cfg_alt(3,4,1,0);
  gpio_cfg_input(3,5);
  gpio_cfg_input(3,6);
  gpio_cfg_input(3,7);
  gpio_cfg_alt(3,8,1,0);
  gpio_cfg_alt(3,9,1,0);
  gpio_cfg_alt(3,10,1,0);
  gpio_cfg_alt(3,0xb,1,0);
  gpio_cfg_alt(3,0xc,1,0);
  gpio_cfg_alt(3,0xd,1,0);
  gpio_cfg_alt(3,0xe,1,0);
  gpio_cfg_alt(3,0xf,1,0);
  gpio_cfg_alt(4,0,1);
  gpio_cfg_alt(4,1,1,0);
  gpio_cfg_input(4,2);
  gpio_cfg_out_low(4,3);
  gpio_cfg_input(4);
  gpio_cfg_input(4,5);
  gpio_cfg_out_low(4,6);
  gpio_cfg_alt(4,7,3,2);
  gpio_cfg_alt(4,8,1,0);
  gpio_cfg_alt(4,9,1,0);
  gpio_cfg_alt(4,10,1,0);
  gpio_cfg_alt(4,0xb,1,0);
  gpio_cfg_alt(4,0xc,1,0);
  gpio_cfg_alt(4,0xd,1,0);
  gpio_cfg_alt(4,0xe,1,0);
  gpio_cfg_alt(4,0xf,1,0);
  gpio_cfg_out_low(5,8);
  gpio_cfg_out_low(5,9);
  gpio_cfg_input(5,10);
  gpio_cfg_input(6,0);
  gpio_cfg_input(6,1);
  gpio_cfg_alt(6,2,7,0);
  gpio_cfg_alt(6,3,7,0);
  gpio_cfg_out_low(6,4);
  gpio_cfg_out_low(6,5);
  gpio_cfg_alt(6,6,5,0);
  gpio_cfg_alt(6,7,5,0);
  gpio_cfg_out_low(6,8);
  gpio_cfg_out_low(6,9);
  gpio_cfg_out_low(6,10);
  gpio_cfg_out_low(6,0xb);
  gpio_cfg_out_low(6,0xc);
  gpio_cfg_out_low(6,0xd);
  gpio_cfg_out_low(6,0xe);
  gpio_cfg_input(6,0xf);
  gpio_cfg_input(7,0);
  gpio_cfg_input(7,1);
  gpio_cfg_input(7,2);
  gpio_cfg_input(7,3);
  gpio_cfg_input(7,4);
  gpio_cfg_input(7,5);
  gpio_cfg_input(7,6);
  gpio_cfg_input(7);
  gpio_cfg_input(7,8);
  gpio_cfg_out_low(7,9);
  gpio_cfg_out_low(7,10);
  gpio_cfg_out_low(7,0xc);
  gpio_cfg_input(7,0xd);
  gpio_cfg_input(7,0xe);
  gpio_cfg_input(7,0xf);
  gpio_cfg_input(8,0);
  gpio_cfg_out_low(8,1);
  gpio_cfg_out_low(8,2);
  gpio_cfg_alt(8,3,3,0);
  gpio_cfg_alt(8,4,3,0);
  gpio_cfg_alt(8,5,3,0);
  gpio_cfg_alt(8,6,3,0);
  gpio_cfg_out_low(8,7);
  gpio_cfg_out_low(8);
  gpio_cfg_input(8,9);
  gpio_cfg_out_low(8,10);
  gpio_cfg_input(8,0xb);
  gpio_cfg_input(8,0xc);
  gpio_cfg_input(8,0xd);
  gpio_cfg_out_low(8,0xe);
  gpio_cfg_input(8,0xf);
  gpio_cfg_alt(9,0,4);
  gpio_cfg_input(9,1);
  gpio_cfg_alt(9,2,2,0);
  gpio_cfg_alt(9,3,2,0);
  gpio_cfg_alt(9,4,2,0);
  gpio_cfg_alt(9,5,2,0);
  gpio_cfg_alt(9,6,2,0);
  gpio_cfg_alt(9,7,2,0);
  gpio_cfg_alt(10,0,2);
  gpio_cfg_alt(10,1,2,0);
  gpio_cfg_input(10,2);
  gpio_cfg_alt(10,3,2,0);
  gpio_cfg_alt(10,4,2);
  gpio_cfg_input(10,5);
  gpio_cfg_input(10,6);
  gpio_cfg_input(10,7);
  gpio_cfg_alt(10,8,5,0);
  gpio_cfg_alt(10,9,5,0);
  gpio_cfg_alt(10,10,5,0);
  gpio_cfg_alt(10,0xb,5,0);
  gpio_cfg_alt(10,0xc,5,0);
  gpio_cfg_alt(10,0xd,5,0);
  gpio_cfg_out_low(10,0xe);
  gpio_cfg_input(10,0xf);
  gpio_cfg_input(0xb,0);
  gpio_cfg_input(0xb,1);
  gpio_cfg_out_high(0xb,2);
  gpio_cfg_input(0xb,3);
  gpio_cfg_alt(0xb,4,2,0);
  gpio_cfg_alt(0xb,5,2,0);
  gpio_cfg_alt(0xb,6,2,0);
  gpio_cfg_alt(0xb,7,2,0);
  gpio_cfg_alt(0xb,8,2,0);
  gpio_cfg_alt(0xb,9,2,0);
  gpio_cfg_alt(0xb,10,2,0);
  gpio_cfg_alt(0xb,0xb,2,0);
  gpio_cfg_input(0xb,0xc);
  gpio_cfg_input(0xb,0xd);
  gpio_cfg_input(0xb,0xe);
  gpio_cfg_alt(0xb,0xf,5,0);
  return;
}


// ===== backlight_enable @ 20101b60 (68 bytes)

/* P4_7 BLPWM alt3 (MTU2 out) + P10_4 level, or input */

void backlight_enable(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    gpio_cfg_input(4,7);
    uVar1 = 0x100000;
  }
  else {
    gpio_cfg_alt(4,7,3,2);
    uVar1 = 0x100010;
  }
  DAT_fcfe3128 = uVar1;
  return;
}


// ===== gpio_p8_14 @ 20101ba4 (24 bytes)

/* P8_14 via PSR8 */

void gpio_p8_14(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x40000000;
  }
  else {
    uVar1 = 0x40004000;
  }
  DAT_fcfe3120 = uVar1;
  return;
}

