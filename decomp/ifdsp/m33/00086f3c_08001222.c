// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== PINT_PinInterruptClrStatus @ 00086f3c (22 bytes)

/* NEW [inference] */

void PINT_PinInterruptClrStatus(uint *param_1,uint param_2)

{
  uint uVar1;
  
  uVar1 = 1 << (param_2 & 0xff);
  if (((*param_1 & uVar1) == 0) && ((uVar1 & param_1[9]) != 0)) {
    param_1[9] = uVar1;
  }
  return;
}


// ===== RESET_PeripheralReset @ 00086f52 (18 bytes)

/* byte-identical to RESET_PeripheralReset of mcux-sdk MCUX_2.11.0 fsl_reset.c (set, then
   RESET_ClearPeripheralReset 0x84504) [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)]. Was
   RESET_ClearPeripheralReset (T24 round 2) */

void RESET_PeripheralReset(uint peripheral)

{
  RESET_SetPeripheralReset();
  RESET_ClearPeripheralReset(peripheral);
  return;
}


// ===== SCTIMER_GetDefaultConfig @ 00086f64 (38 bytes)

void SCTIMER_GetDefaultConfig(void *ptr)

{
  memset(ptr,0,9);
  *(undefined1 *)ptr = 1;
  *(undefined1 *)((int)ptr + 1) = 0;
  *(undefined1 *)((int)ptr + 2) = 0;
  *(undefined1 *)((int)ptr + 3) = 0;
  *(undefined1 *)((int)ptr + 4) = 0;
  *(undefined1 *)((int)ptr + 5) = 0;
  *(undefined1 *)((int)ptr + 6) = 0;
  *(undefined1 *)((int)ptr + 7) = 0;
  *(undefined1 *)((int)ptr + 8) = 0xf;
  return;
}


// ===== SCTIMER_UpdatePwmDutycycle @ 00086f8a (98 bytes)

void SCTIMER_UpdatePwmDutycycle(int param_1,undefined4 param_2,uint param_3,int param_4)

{
  short sVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  ulonglong __aeabi_uldivmod_ret;
  
  iVar4 = param_1 + param_4 * 8;
  uVar5 = *(uint *)(iVar4 + 0x30c);
  uVar3 = *(uint *)(param_1 + ((*(uint *)(iVar4 + 0x304) & 0xf) + 0x40) * 4);
  if (param_3 == 100) {
    sVar1 = (short)uVar3;
    if (*(int *)(param_1 + 4) << 0x1b < 0) {
      uVar2 = sVar1 - 1;
    }
    else {
      uVar2 = sVar1 + 2;
    }
  }
  else {
    __aeabi_uldivmod_ret = __aeabi_uldivmod((ulonglong)param_3 * (ulonglong)uVar3,100);
    uVar2 = (ushort)__aeabi_uldivmod_ret;
  }
  iVar4 = param_1 + (uVar5 & 0xf) * 4;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 4;
  *(uint *)(iVar4 + 0x100) = (uint)uVar2;
  *(uint *)(iVar4 + 0x200) = (uint)uVar2;
  *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) & 0xfffffffb;
  return;
}


// ===== SEMA42_Lock @ 00086fec (28 bytes)

void SEMA42_Lock(int param_1,uint param_2,char param_3)

{
  char *pcVar1;
  
  pcVar1 = (char *)(param_1 + (param_2 ^ 3));
  while (*pcVar1 != (char)(param_3 + '\x01')) {
    do {
    } while (*pcVar1 != '\0');
    *pcVar1 = param_3 + '\x01';
  }
  return;
}


// ===== SEMA42_ResetGate @ 00087008 (36 bytes)

/* byte-identical to SEMA42_ResetGate of mcux-sdk MCUX_2.11.0 fsl_sema42.c [fact: T24
   (src/ifdsp_m33/status.tsv, aliases.tsv)]; SEMA42_ResetAllGates is the header inline that calls it
   with the reset-all gate number. Was SEMA42_ResetAllGates (T24 round 2) */

ushort SEMA42_ResetGate(int param_1,ushort param_2)

{
  ushort uVar1;
  
  uVar1 = *(ushort *)(param_1 + 0x42) & 0x3000;
  if ((*(ushort *)(param_1 + 0x42) & 0x3000) == 0) {
    *(undefined2 *)(param_1 + 0x42) = 0xe200;
    *(ushort *)(param_1 + 0x42) = param_2 | 0x1d00;
  }
  else {
    uVar1 = 0x641;
  }
  return uVar1;
}


// ===== USART_GetDefaultConfig @ 0008702c (34 bytes)

void USART_GetDefaultConfig(void *ptr)

{
  memset(ptr,0,0x14);
  *(undefined **)ptr = &DAT_0001c200;
  *(undefined4 *)((int)ptr + 4) = 0x10000;
  *(undefined4 *)((int)ptr + 8) = 0;
  *(undefined4 *)((int)ptr + 0xc) = 0;
  *(undefined1 *)((int)ptr + 0x10) = 0;
  return;
}


// ===== USART_SetBaudRate @ 0008704e (178 bytes)

/* OSR/BRG search, returns 0x1651 kStatus_USART_BaudrateNotSupport [inference] */

void * USART_SetBaudRate(uint *param_1,uint param_2,uint param_3)

{
  undefined **ppuVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint i;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  if (((param_1 == (uint *)0x0) || (param_2 == 0)) || (param_3 == 0)) {
    ppuVar1 = &Reset;
  }
  else {
    if ((int)(*param_1 << 0x14) < 0) {
      if ((*param_1 & 0x4000) != 0) {
        param_1[8] = param_3 / param_2 - 1;
      }
    }
    else {
      uVar4 = 0xffffffff;
      uVar5 = 0xf;
      uVar7 = 0xffffffff;
      i = 0xf;
      uVar6 = param_2 << 4;
      do {
        uVar3 = (param_3 * 10) / uVar6 - 5;
        if (uVar3 < 0xa0000) {
          uVar3 = uVar3 / 10;
          uVar2 = param_3 / (uVar3 * (i + 1) + i + 1);
          if (param_2 < uVar2) {
            uVar2 = uVar2 - param_2;
          }
          else {
            uVar2 = param_2 - uVar2;
          }
          if (uVar2 < uVar7) {
            uVar4 = uVar3;
            uVar5 = i;
            uVar7 = uVar2;
          }
        }
        i = i - 1;
        uVar6 = uVar6 - param_2;
      } while (i != 7);
      uVar7 = param_3 / (uVar5 * (uVar4 + 1) + uVar4 + 1);
      if (param_2 < uVar7) {
        uVar7 = uVar7 - param_2;
      }
      else {
        uVar7 = param_2 - uVar7;
      }
      if (((param_2 / 100) * 3 < uVar7) || (0xffff < uVar4)) {
        return &DAT_00001651;
      }
      param_1[10] = uVar5;
      param_1[8] = uVar4;
    }
    ppuVar1 = (undefined **)0x0;
  }
  return ppuVar1;
}


// ===== USART_Init @ 00087100 (306 bytes)

undefined ** USART_Init(uint *param_1,uint *param_2,uint param_3)

{
  byte bVar1;
  undefined **ppuVar2;
  undefined **USART_SetBaudRate_ret;
  uint uVar3;
  
  if (((param_1 == (uint *)0x0) || (param_2 == (uint *)0x0)) || (param_3 == 0)) {
    ppuVar2 = &Reset;
  }
  else {
    ppuVar2 = (undefined **)FLEXCOMM_Init((int)param_1,1);
    if (ppuVar2 == (undefined **)0x0) {
      if (*(char *)((int)param_2 + 9) != '\0') {
        param_1[0x380] = param_1[0x380] | 0x10001;
        param_1[0x382] = param_1[0x382] & 0xfffff0ff;
        param_1[0x382] = (*(byte *)((int)param_2 + 0xd) & 0xf) << 8 | param_1[0x382];
        param_1[0x382] = param_1[0x382] | 1;
      }
      if ((char)param_2[2] != '\0') {
        param_1[0x380] = param_1[0x380] | 0x20002;
        param_1[0x382] = param_1[0x382] & 0xfff0ffff;
        param_1[0x382] = (*(byte *)((int)param_2 + 0xe) & 0xf) << 0x10 | param_1[0x382];
        param_1[0x382] = param_1[0x382] | 2;
      }
      bVar1 = *(byte *)((int)param_2 + 0xb);
      uVar3 = *param_2;
      *param_1 = (uint)bVar1 << 7 | (uint)*(byte *)((int)param_2 + 7) << 0xf |
                 (*(byte *)((int)param_2 + 0xf) & 2) << 10 | (uint)(byte)param_2[3] << 9 |
                 ((byte)param_2[1] & 3) << 4 | (*(byte *)((int)param_2 + 5) & 1) << 6 |
                 (*(byte *)((int)param_2 + 6) & 3) << 2 | (*(byte *)((int)param_2 + 0xf) & 1) << 0xe
                 | ((byte)param_2[4] & 1) << 0xc | 1;
      if (bVar1 == 0) {
        USART_SetBaudRate_ret = USART_SetBaudRate(param_1,uVar3,param_3);
        if (USART_SetBaudRate_ret != (undefined **)0x0) {
          return USART_SetBaudRate_ret;
        }
      }
      else {
        if ((undefined *)((0x2580 / uVar3) * uVar3) != &DAT_00002580) {
          return (undefined **)&DAT_00001651;
        }
        param_1[8] = 0x2580 / uVar3;
      }
      if (*(char *)((int)param_2 + 10) == '\0') {
        uVar3 = param_1[1] & 0xfffffeff;
      }
      else {
        uVar3 = param_1[1] | 0x100;
      }
      param_1[1] = uVar3;
    }
  }
  return ppuVar2;
}


// ===== BOARD_InitDebugConsole @ 00087232 (2 bytes)

/* empty (bx lr), no callers [fact: 0x87232]; its address (0x87233, Thumb bit) is the literal at
   0x80A10 that BOARD_SetFlexspiClock masks with 0xE8000000 and compares with 0x08000000 before
   BOARD_DeinitXip/BOARD_InitXip [fact: 0x809BC..0x80A06], which is the BOARD_IS_XIP_FLEXSPI() test
   on &BOARD_InitDebugConsole in mcux-sdk@8a289764 boards/evkmimxrt685/board.c [inference]; the
   vendor built it empty */

void BOARD_InitDebugConsole(void)

{
  return;
}


// ===== BOARD_FlexspiClockSafeConfig @ 00087234 (8 bytes)

/* BOARD_SetFlexspiClock(3 = FFRO, /1) before the main clock switch [inference] */

void BOARD_FlexspiClockSafeConfig(void)

{
  BOARD_SetFlexspiClock(3,1);
  return;
}


// ===== BOARD_InitBootPeripherals @ 00087240 (2 bytes)

/* Was app_init_nop (T24 round 2): the empty function between clock_config.c and pin_mux.c in link
   order, called by main right after BOARD_InitBootClocks, the MCUXpresso Config Tools sequence
   [inference]. Body is only bx lr [fact: 0x87240]; one caller, app_main 0x81098, between
   BOARD_BootClockRUN and regfile_clear [fact]. Not BOARD_InitDebugConsole, which is the separate
   empty function at 0x87232 [fact: literal 0x80A10]. Open: which source function this was; would be
   settled by the vendor's source or link map */

void BOARD_InitBootPeripherals(void)

{
  return;
}


// ===== BOARD_InitPins_flexcomm @ 00087242 (42 bytes)

/* IOPCTL: PIO0_1/2 FC0 USART, PIO0_7..10 FC1 SPI, PIO1_10 MCLK, PIO2_2 SCT0_OUT0, PIO2_30 CLKIN
   [fact] */

void BOARD_InitPins_flexcomm(void)

{
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_1 = 1;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_10 = 1;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_2 = 0x41;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_7 = 0x41;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_8 = 0x41;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_9 = 0x41;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO1_10 = 0x101;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO2_2 = 2;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO2_30 = 0x45;
  return;
}


// ===== BOARD_InitPins_i2s @ 0008726c (40 bytes)

/* IOPCTL: PIO0_14..16 FC2 (SCK input inverted), PIO0_23 FC3 data in, PIO0_30 FC4 data in, PIO1_3..5
   FC5 [fact] */

void BOARD_InitPins_i2s(void)

{
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_14 = 0x941;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_15 = 0x141;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_16 = 0x101;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_23 = 0x141;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_30 = 0x141;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO1_3 = 0x141;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO1_4 = 0x141;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO1_5 = 0x101;
  return;
}


// ===== BOARD_InitBootPins @ 00087294 (26 bytes)

/* calls the five pin groups [fact: 0x87294]; main calls it right before BOARD_InitBootClocks
   0x8723C and BOARD_InitBootPeripherals 0x87240, the MCUXpresso Config Tools boot sequence
   [inference]. Was BOARD_InitPins (T24 round 2) */

void BOARD_InitBootPins(void)

{
  BOARD_InitPins_flexcomm();
  BOARD_InitPins_P0();
  BOARD_InitPins_codec_spi();
  BOARD_InitPins_i2s();
  BOARD_InitPins_debug_gpio();
  return;
}


// ===== __main @ 000872ae (14 bytes)

/* Redlib C entry: stdio_init 0x84E38, then tail-jump to main 0x8106C [fact: 0x872AE]; ResetISR
   reaches it through call_main, as the MCUXpresso startup calls __main [fact: startup_mimxrt685s.c
   MCUX_2.9.0 byte-identical, T24 (src/ifdsp_m33/status.tsv, aliases.tsv)]. Was main (T24 round 2)
    */

void __main(void)

{
  stdio_init();
                    /* SEMA42 init/reset, flags 1 [doc] */
  main();
  return;
}


// ===== free @ 000872c4 (48 bytes)

/* Marks block 0x10000000 and merges free successors [inference] */

void free(int param_1)

{
  int *piVar1;
  
  if (param_1 != 0) {
    *(undefined4 *)(param_1 + -0xc) = 0x10000000;
    while ((piVar1 = *(int **)(param_1 + -4), piVar1 != (int *)0x0 && (*piVar1 == 0x10000000))) {
      *(int *)(param_1 + -8) = *(int *)(param_1 + -8) + 3 + piVar1[1];
      *(int *)(param_1 + -4) = piVar1[2];
    }
  }
  return;
}


// ===== setvbuf @ 000872f8 (62 bytes)

/* _IOFBF 0x100 / _IOLBF 0x200 / _IONBF 0x400 [inference] */

undefined4 setvbuf(int *param_1,int *param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_1[3] & 3U) == 0) {
LAB_00087312:
    uVar1 = 1;
  }
  else {
    if (param_3 == 0x200) {
LAB_0008732a:
      if (0xfffffe < param_4 - 1U) goto LAB_00087312;
    }
    else {
      if (param_3 != 0x400) {
        if (param_3 != 0x100) goto LAB_00087312;
        goto LAB_0008732a;
      }
      param_4 = 1;
      param_2 = param_1 + 9;
    }
    param_1[4] = (int)param_2;
    *param_1 = (int)param_2;
    param_1[7] = param_4;
    param_1[3] = param_3 | param_1[3];
    uVar1 = 0;
  }
  return uVar1;
}


// ===== strcmp @ 00087336 (68 bytes)

int strcmp(uint *param_1,uint *param_2)

{
  uint *puVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  uVar5 = ((uint)param_1 | (uint)param_2) & 3;
  puVar3 = param_1;
  puVar4 = param_2;
  for (; puVar2 = param_2, puVar1 = param_1, uVar5 == 0;
      uVar5 = uVar5 + 0xfefefeff & ~uVar5 & 0x80808080) {
    uVar5 = *puVar2;
    puVar3 = puVar1;
    puVar4 = puVar2;
    if (uVar5 != *puVar1) break;
    param_1 = puVar1 + 1;
    param_2 = puVar2 + 1;
  }
  do {
    uVar5 = (uint)(byte)*puVar3;
    if (uVar5 != (byte)*puVar4) {
      return uVar5 - (byte)*puVar4;
    }
    puVar3 = (uint *)((int)puVar3 + 1);
    puVar4 = (uint *)((int)puVar4 + 1);
  } while (uVar5 != 0);
  return 0;
}


// ===== strlen @ 0008737a (72 bytes)

int strlen(uint *param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  
  puVar1 = param_1;
  do {
    if (((uint)puVar1 & 3) == 0) goto LAB_00087384;
    puVar2 = (uint *)((int)puVar1 + 1);
    uVar3 = *puVar1;
    puVar1 = puVar2;
  } while ((char)uVar3 != '\0');
LAB_000873b6:
  return (int)puVar2 - ((int)param_1 + 1);
LAB_00087384:
  do {
    puVar4 = puVar1;
    puVar2 = puVar4 + 1;
    uVar3 = *puVar4;
    puVar1 = puVar2;
  } while ((uVar3 + 0xfefefeff & ~uVar3 & 0x80808080) == 0);
  if ((uVar3 & 0xff) == 0) {
    puVar2 = (uint *)((int)puVar4 + 1);
  }
  else if ((uVar3 & 0xff00) == 0) {
    puVar2 = (uint *)((int)puVar4 + 2);
  }
  else if ((uVar3 & 0xff0000) == 0) {
    puVar2 = (uint *)((int)puVar4 + 3);
  }
  goto LAB_000873b6;
}


// ===== strncmp @ 000873c2 (86 bytes)

int strncmp(uint *param_1,uint *param_2,uint param_3)

{
  uint *puVar1;
  uint uVar2;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar2 = *param_2;
      if ((uVar2 != *param_1) || ((uVar2 + 0xfefefeff & ~uVar2 & 0x80808080) != 0)) break;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  }
  puVar1 = param_1;
  while( true ) {
    if (puVar1 == (uint *)(param_3 + (int)param_1)) {
      return 0;
    }
    uVar2 = (uint)(byte)*puVar1;
    if (uVar2 != (byte)*param_2) break;
    puVar1 = (uint *)((int)puVar1 + 1);
    param_2 = (uint *)((int)param_2 + 1);
    if (uVar2 == 0) {
      return 0;
    }
  }
  return uVar2 - (byte)*param_2;
}


// ===== strncpy @ 00087418 (88 bytes)

/* [inference] */

void strncpy(uint *param_1,uint *param_2,uint param_3)

{
  char cVar1;
  char *pcVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  
  if ((((uint)param_1 | (uint)param_2) & 3) == 0) {
    for (; 3 < param_3; param_3 = param_3 - 4) {
      uVar5 = *param_2;
      if ((uVar5 + 0xfefefeff & ~uVar5 & 0x80808080) != 0) break;
      *param_1 = uVar5;
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
    }
  }
  pcVar2 = (char *)((int)param_2 + -1);
  do {
    param_3 = param_3 - 1;
    if (param_3 == 0xffffffff) {
      return;
    }
    pcVar2 = pcVar2 + 1;
    cVar1 = *pcVar2;
    puVar4 = (uint *)((int)param_1 + 1);
    *(char *)param_1 = cVar1;
    param_1 = puVar4;
  } while (cVar1 != '\0');
  puVar3 = (uint *)(param_3 + (int)puVar4);
  for (; puVar4 != puVar3; puVar4 = (uint *)((int)puVar4 + 1)) {
    *(char *)puVar4 = '\0';
  }
  return;
}


// ===== file_clear_flag20 @ 00087470 (64 bytes)

/* FILE flags (+0xC) &= ~0x20; if +0x18 != +0x28: call file_flush_write_buffer, flags = (flags &
   ~0x3010) | 0x10, +0x18 = +0x28, +0x2C = +0 = buffer (+0x10); then flags &= ~0x4040 [fact:
   0x87470]. Callers fputc (x2) and _Cfflush1 call it only when flag 0x20 is set [fact]. Open: the
   Redlib name and the meaning of flag 0x20; would be settled by Redlib source or symbols */

void file_clear_flag20(void *param_1)

{
  *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) & 0xffffffdf;
  if (*(int *)((int)param_1 + 0x18) != *(int *)((int)param_1 + 0x28)) {
                    /* clears flag 0x80000 [doc] */
    file_flush_write_buffer();
    *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) & 0xffffcfef | 0x10;
    *(undefined4 *)((int)param_1 + 0x18) = *(undefined4 *)((int)param_1 + 0x28);
    *(undefined4 *)((int)param_1 + 0x2c) = *(undefined4 *)((int)param_1 + 0x10);
    *(undefined4 *)param_1 = *(undefined4 *)((int)param_1 + 0x10);
  }
  *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) & 0xffffbfbf;
  return;
}


// ===== fputc @ 000874b0 (320 bytes)

/* FILE output slow path, 19 callers (printf engine) [inference] */

uint fputc(byte param_1,uint *param_2)

{
  uint _Csys_alloc_ret;
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  uint uVar4;
  byte *pbVar5;
  
  uVar2 = param_2[3];
  param_2[3] = uVar2 & 0xfff7ffff;
  if ((int)(uVar2 << 0x1a) < 0) {
    file_clear_flag20(param_2);
  }
  uVar2 = param_2[3];
  if (((int)param_2[2] < -1) && (-1 < (int)(uVar2 << 0x16))) {
    param_2[2] = 0xfffffffe - param_2[2];
    pbVar3 = (byte *)*param_2;
    param_2[3] = uVar2 | 0x12000;
    *param_2 = (uint)(pbVar3 + 1);
    *pbVar3 = param_1;
LAB_000874ee:
    uVar2 = (uint)param_1;
  }
  else {
    if ((uVar2 & 0x108a) == 2) {
      if ((uVar2 & 0xa010) == 0x8000) {
        fseek(param_2,0);
        if ((int)(param_2[3] << 0x1a) < 0) {
          file_clear_flag20(param_2);
        }
        uVar2 = param_2[3];
      }
      uVar4 = uVar2 | 0x12000;
      param_2[3] = uVar4;
      if ((uVar2 & 0xf00) == 0) {
        uVar4 = __sys_istty();
        if ((uVar4 == 0) || (-1 < (int)(uVar2 << 0x15))) {
          _Csys_alloc_ret = _Csys_alloc(0x100);
          param_2[7] = 0x100;
          uVar4 = uVar2 | 0x12800;
          param_2[4] = _Csys_alloc_ret;
          *param_2 = _Csys_alloc_ret;
          param_2[3] = param_2[3] | uVar4;
        }
        else {
          param_2[4] = (uint)(param_2 + 9);
          *param_2 = (uint)(param_2 + 9);
          param_2[7] = 1;
          uVar4 = uVar2 | 0x12400;
          param_2[3] = uVar4;
        }
      }
      pbVar3 = (byte *)*param_2;
      pbVar5 = (byte *)param_2[4];
      if ((uVar4 & 0x900) == 0) {
        uVar2 = (uint)param_1;
        *param_2 = (uint)(pbVar3 + 1);
        *pbVar3 = param_1;
        if (*param_2 < param_2[0xb]) {
          iVar1 = param_2[0xb] - (int)pbVar5;
        }
        else {
          iVar1 = *param_2 - (int)pbVar5;
        }
        param_2[0xc] = param_2[7];
        if (((-1 < (int)(uVar4 << 0x15)) && (uVar2 != 10)) && (iVar1 < (int)param_2[7])) {
          return uVar2;
        }
        param_2[0xb] = (uint)pbVar5;
        *param_2 = (uint)pbVar5;
        param_2[2] = 0;
        uVar4 = _Cwrite_buffer((uint)pbVar5,iVar1,(int)param_2);
        if (uVar4 == 0) {
          return uVar2;
        }
      }
      else {
        if (pbVar3 < (byte *)param_2[0xb]) {
          iVar1 = (int)param_2[0xb] - (int)pbVar5;
        }
        else {
          iVar1 = (int)pbVar3 - (int)pbVar5;
        }
        if ((iVar1 == 0) || (uVar2 = _Cwrite_buffer((uint)pbVar5,iVar1,(int)param_2), uVar2 == 0)) {
          param_2[0xb] = (uint)(pbVar5 + 1);
          *param_2 = (uint)(pbVar5 + 1);
          param_2[2] = param_2[7] - 1;
          param_2[0xc] = param_2[7];
          *pbVar5 = param_1;
          goto LAB_000874ee;
        }
      }
    }
    else {
      param_2[2] = 0;
      param_2[3] = uVar2 | 0x80;
    }
    uVar2 = 0xffffffff;
  }
  return uVar2;
}


// ===== _Cfdopen @ 000875f0 (104 bytes)

/* Opens fd with mode "r"/"w"/"a"[+][b] into a FILE (used by stdio_init) [inference] */

int _Cfdopen(undefined4 param_1,char *param_2,int param_3)

{
  char cVar1;
  undefined *puVar2;
  uint uVar3;
  
  _Cfclose(param_3);
  cVar1 = *param_2;
  if (cVar1 == 'r') {
    uVar3 = 0;
    puVar2 = (undefined *)0x1;
  }
  else if (cVar1 == 'w') {
    uVar3 = 4;
    puVar2 = (undefined *)0x2;
  }
  else {
    if (cVar1 != 'a') {
      return 0;
    }
    uVar3 = 8;
    puVar2 = &DAT_00008002;
  }
  while( true ) {
    while( true ) {
      param_2 = param_2 + 1;
      if (*param_2 != '+') break;
      puVar2 = (undefined *)((uint)puVar2 | 3);
      uVar3 = uVar3 | 2;
    }
    if (*param_2 != 'b') break;
    puVar2 = (undefined *)((uint)puVar2 | 4);
    uVar3 = uVar3 | 1;
  }
  *(undefined **)(param_3 + 0xc) = puVar2;
  *(undefined4 *)(param_3 + 0x14) = param_1;
  if ((int)(uVar3 << 0x1c) < 0) {
    fseek(param_3,0,2);
  }
  return param_3;
}


// ===== file_flush_write_buffer @ 00087658 (82 bytes)

/* clears flag 0x80000; if (flags & 0x82) == 2 and flag 0x10000 set, writes buffer (+0x10) ..
   max(ptr, +0x2C) with _Cwrite_buffer, then resets the pointers and clears 0x10000; returns 0, or
   -1 on error / wrong mode [fact: 0x87658]. Redlib's own name unknown */

undefined4 file_flush_write_buffer(uint *param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = param_1[4];
  uVar1 = param_1[3];
  param_1[3] = uVar1 & 0xfff7ffff;
  if ((uVar1 & 0x82) == 2) {
    if ((uVar1 & 0x10000) == 0) {
      return 0;
    }
    uVar1 = *param_1;
    if (*param_1 < param_1[0xb]) {
      uVar1 = param_1[0xb];
    }
    if ((uVar2 == uVar1) || (uVar1 = _Cwrite_buffer(uVar2,uVar1 - uVar2,(int)param_1), uVar1 == 0))
    {
      param_1[0xb] = uVar2;
      *param_1 = uVar2;
      param_1[2] = 0;
      param_1[3] = param_1[3] & 0xfffeffff;
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== _Cfclose @ 000876aa (88 bytes)

/* [inference] */

undefined4 _Cfclose(void *ptr)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_38 [36];
  
  uVar1 = *(uint *)((int)ptr + 0xc);
  if ((uVar1 & 3) == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    if (-1 < (int)(uVar1 << 0x1c)) {
      iVar2 = *(int *)((int)ptr + 0x10);
      uVar3 = *(undefined4 *)((int)ptr + 0x14);
      fflush();
      __sys_close(uVar3);
      if ((int)(uVar1 << 0x14) < 0) {
                    /* Marks block 0x10000000 and merges free successors [doc, inference] */
        free(iVar2);
      }
      if ((uVar1 & 0xffc00000) == 0xad800000) {
        __sys_tmpnam(auStack_38,*(undefined4 *)((int)ptr + 0x20),0x20);
        remove((uint)auStack_38);
      }
    }
    memset(ptr,0,0x3c);
    uVar3 = 0;
  }
  return uVar3;
}


// ===== remove @ 00087702 (20 bytes)

/* strlen(name), then tail-calls __sys_remove(name, len) which returns -1 [fact: 0x87702]. Only
   caller _Cfclose 0x876E8, on a FILE whose flags top bits are 0xAD8, with a name just built by
   __sys_tmpnam: the C rule that closing a tmpfile() deletes it [inference] */

void remove(uint param_1)

{
  int strlen_ret;
  
  strlen_ret = strlen((uint *)param_1);
  __sys_remove(param_1,strlen_ret);
  return;
}


// ===== _Cfflush1 @ 00087716 (64 bytes)

/* [inference] */

uint _Cfflush1(int *param_1)

{
  uint uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((param_1[3] & 3U) != 0) {
    if (param_1[3] << 0x1a < 0) {
      iVar2 = param_1[10];
      file_clear_flag20(param_1);
    }
    else {
      iVar2 = (*param_1 + param_1[6]) - param_1[4];
    }
    param_1[3] = param_1[3] & 0xffffcfff;
                    /* clears flag 0x80000 [doc] */
    uVar1 = file_flush_write_buffer(param_1);
    fseek(param_1,iVar2,0);
  }
  return uVar1;
}


// ===== __aeabi_uldivmod @ 00087756 (252 bytes)

/* 64-bit unsigned divide (also reached by the flash veneer 0x08001618) [inference] */

ulonglong __aeabi_uldivmod(ulonglong n,ulonglong d)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint extraout_r12;
  uint extraout_r12_00;
  uint uVar8;
  bool bVar9;
  ulonglong uVar10;
  
  uVar4 = (uint)(d >> 0x20);
  uVar6 = (uint)d;
  uVar5 = (uint)(n >> 0x20);
  uVar2 = (uint)n;
  uVar7 = 0;
  if (uVar4 == 0) {
    if (uVar6 == 0) {
      return 0;
    }
    iVar3 = 0;
    if (uVar6 <= uVar5) {
                    /* shift-and-subtract division of the 64-bit r1:r0 by r2 [doc] */
      iVar3 = udiv64by32_helper(uVar5,0);
      n = n & 0xffffffff;
    }
    uVar4 = udiv64by32_helper((int)n);
    uVar7 = extraout_r12;
  }
  else if ((longlong)d < 0) {
    iVar3 = 0;
    uVar4 = (uint)(uVar4 < uVar5 || uVar5 - uVar4 < (uint)(uVar6 <= uVar2));
  }
  else {
    if (uVar4 >> 0x10 == 0) {
      uVar4 = uVar4 << 0x10;
      uVar7 = 0x10;
    }
    if ((uVar4 & 0xff000000) == 0) {
      uVar4 = uVar4 << 8;
      uVar7 = uVar7 + 8;
    }
    if ((uVar4 & 0xf0000000) == 0) {
      uVar4 = uVar4 << 4;
      uVar7 = uVar7 + 4;
    }
    uVar8 = uVar4 & 0xc0000000;
    if ((uVar4 & 0xc0000000) == 0) {
      uVar7 = uVar7 + 2;
      uVar4 = uVar4 << 2;
      uVar8 = uVar4;
    }
    if (-1 < (int)uVar8) {
      uVar7 = uVar7 + 1;
      uVar4 = uVar4 << 1;
    }
    uVar8 = 0x20 - uVar7;
    uVar10 = udiv64by32_helper(uVar2 >> (uVar8 & 0xff) | uVar5 << uVar7,uVar5 >> (uVar8 & 0xff),
                               uVar4 | uVar6 >> (uVar8 & 0xff));
    uVar5 = (uint)(uVar10 >> 0x20);
    uVar4 = (uint)uVar10;
    lVar1 = (ulonglong)(uVar6 << uVar7) * (uVar10 & 0xffffffff);
    uVar6 = (uint)((ulonglong)lVar1 >> 0x20);
    if (uVar5 <= uVar6 && (uint)((uint)lVar1 <= uVar2 << uVar7) <= uVar5 - uVar6) {
      uVar4 = uVar4 - 1;
    }
    iVar3 = 0;
    uVar7 = extraout_r12_00;
  }
  if ((uVar7 & 0xc0000000) != 0) {
    if ((int)(uVar7 & 0xc0000000) < 0) {
      bVar9 = uVar4 != 0;
      uVar4 = -uVar4;
      iVar3 = -(uint)bVar9 - iVar3;
    }
    if ((uVar7 & 0x40000000) != 0) {
      return CONCAT44(iVar3,uVar4);
    }
    return CONCAT44(iVar3,uVar4);
  }
  return CONCAT44(iVar3,uVar4);
}


// ===== udiv64by32_helper @ 00087850 (122 bytes)

/* shift-and-subtract division of the 64-bit r1:r0 by r2 (byte steps while r1 < r2>>8, then bit
   steps) [fact: 0x87850]; the 3 call sites are all in __aeabi_uldivmod [fact]. Library's own name
   unknown */

void udiv64by32_helper(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  bool bVar5;
  bool bVar6;
  bool bVar7;
  bool bVar8;
  
  uVar4 = 4;
  if (param_2 < param_3 >> 8) {
    do {
      param_2 = param_2 << 8 | param_1 >> 0x18;
      param_1 = param_1 << 8;
      uVar4 = uVar4 - 1;
      if (uVar4 == 0) {
        return;
      }
    } while (param_2 < param_3 >> 8);
  }
  bVar5 = CARRY4(param_1,param_1);
  param_1 = param_1 * 2;
  do {
    bVar8 = CARRY4(param_2 * 2,(uint)bVar5);
    bVar6 = CARRY4(param_2,param_2) || bVar8;
    uVar2 = param_2 * 2 + (uint)bVar5;
    if (!CARRY4(param_2,param_2) && !bVar8) {
      bVar6 = param_3 <= uVar2;
    }
    if (bVar6 != false) {
      uVar2 = uVar2 - param_3;
    }
    bVar7 = CARRY4(param_1,param_1) || CARRY4(param_1 * 2,(uint)bVar6);
    uVar1 = param_1 * 2 + (uint)bVar6;
    bVar5 = CARRY4(uVar2 * 2,(uint)bVar7);
    bVar8 = CARRY4(uVar2,uVar2) || bVar5;
    uVar3 = uVar2 * 2 + (uint)bVar7;
    if (!CARRY4(uVar2,uVar2) && !bVar5) {
      bVar8 = param_3 <= uVar3;
    }
    if (bVar8 != false) {
      uVar3 = uVar3 - param_3;
    }
    bVar6 = CARRY4(uVar1,uVar1) || CARRY4(uVar1 * 2,(uint)bVar8);
    uVar2 = uVar1 * 2 + (uint)bVar8;
    bVar5 = CARRY4(uVar3 * 2,(uint)bVar6);
    bVar8 = CARRY4(uVar3,uVar3) || bVar5;
    uVar1 = uVar3 * 2 + (uint)bVar6;
    if (!CARRY4(uVar3,uVar3) && !bVar5) {
      bVar8 = param_3 <= uVar1;
    }
    if (bVar8 != false) {
      uVar1 = uVar1 - param_3;
    }
    bVar6 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar8);
    uVar2 = uVar2 * 2 + (uint)bVar8;
    bVar5 = CARRY4(uVar1 * 2,(uint)bVar6);
    bVar8 = CARRY4(uVar1,uVar1) || bVar5;
    uVar3 = uVar1 * 2 + (uint)bVar6;
    if (!CARRY4(uVar1,uVar1) && !bVar5) {
      bVar8 = param_3 <= uVar3;
    }
    if (bVar8 != false) {
      uVar3 = uVar3 - param_3;
    }
    bVar6 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar8);
    uVar2 = uVar2 * 2 + (uint)bVar8;
    bVar5 = CARRY4(uVar3 * 2,(uint)bVar6);
    bVar8 = CARRY4(uVar3,uVar3) || bVar5;
    uVar1 = uVar3 * 2 + (uint)bVar6;
    if (!CARRY4(uVar3,uVar3) && !bVar5) {
      bVar8 = param_3 <= uVar1;
    }
    if (bVar8 != false) {
      uVar1 = uVar1 - param_3;
    }
    bVar6 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar8);
    uVar2 = uVar2 * 2 + (uint)bVar8;
    bVar5 = CARRY4(uVar1 * 2,(uint)bVar6);
    bVar8 = CARRY4(uVar1,uVar1) || bVar5;
    uVar3 = uVar1 * 2 + (uint)bVar6;
    if (!CARRY4(uVar1,uVar1) && !bVar5) {
      bVar8 = param_3 <= uVar3;
    }
    if (bVar8 != false) {
      uVar3 = uVar3 - param_3;
    }
    bVar6 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar8);
    uVar2 = uVar2 * 2 + (uint)bVar8;
    bVar5 = CARRY4(uVar3 * 2,(uint)bVar6);
    bVar8 = CARRY4(uVar3,uVar3) || bVar5;
    uVar1 = uVar3 * 2 + (uint)bVar6;
    if (!CARRY4(uVar3,uVar3) && !bVar5) {
      bVar8 = param_3 <= uVar1;
    }
    if (bVar8 != false) {
      uVar1 = uVar1 - param_3;
    }
    bVar6 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar8);
    uVar2 = uVar2 * 2 + (uint)bVar8;
    bVar5 = CARRY4(uVar1 * 2,(uint)bVar6);
    bVar8 = CARRY4(uVar1,uVar1) || bVar5;
    param_2 = uVar1 * 2 + (uint)bVar6;
    if (!CARRY4(uVar1,uVar1) && !bVar5) {
      bVar8 = param_3 <= param_2;
    }
    if (bVar8 != false) {
      param_2 = param_2 - param_3;
    }
    bVar5 = CARRY4(uVar2,uVar2) || CARRY4(uVar2 * 2,(uint)bVar8);
    param_1 = uVar2 * 2 + (uint)bVar8;
    uVar4 = uVar4 - 1;
  } while ((uVar4 & 0xf) != 0);
  return;
}


// ===== memcpy_body @ 000878cc (52 bytes)

/* the copy loop that memcpy 0x872BC branches to [fact: 0x872BC b.w 0x878CC]. Was memcpy (T24 round
   2). Open: Redlib's own symbol for it; would be settled by the symbol table of the Redlib archive
   of an MCUXpresso IDE install */

void memcpy_body(void *param_1,void *param_2,uint param_3)

{
  uint uVar1;
  bool bVar2;
  
  if (-1 < (int)(((uint)param_1 | (uint)param_2) << 0x1f)) {
    bVar2 = 3 < param_3;
    uVar1 = param_3 - 4;
    do {
      if (bVar2) {
        *(undefined4 *)param_1 = *(undefined4 *)param_2;
        bVar2 = 3 < uVar1;
        uVar1 = uVar1 - 4;
        param_1 = (undefined4 *)((int)param_1 + 4);
        param_2 = (undefined4 *)((int)param_2 + 4);
      }
    } while (bVar2);
    param_3 = uVar1 + 4;
    if (param_3 == 0) {
      return;
    }
  }
  do {
    bVar2 = param_3 != 0;
    param_3 = param_3 - 1;
    if (bVar2) {
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
  } while (bVar2 && param_3 != 0);
  return;
}


// ===== memset_body @ 00087900 (50 bytes)

/* the fill loop that memset 0x872C0 branches to [fact: 0x872C0 b.w 0x87900]. Was memset (T24 round
   2). Open: Redlib's own symbol for it; would be settled by the symbol table of the Redlib archive
   of an MCUXpresso IDE install */

void memset_body(void *ptr,int value,uint size)

{
  uint uVar1;
  bool bVar2;
  
  if (((uint)ptr & 3) == 0) {
    uVar1 = value & 0xffU | (value & 0xffU) << 8;
    value = uVar1 | uVar1 << 0x10;
    bVar2 = 3 < size;
    uVar1 = size - 4;
    do {
      if (bVar2) {
        *(int *)ptr = value;
        bVar2 = 3 < uVar1;
        uVar1 = uVar1 - 4;
        ptr = (uint *)((int)ptr + 4);
      }
    } while (bVar2);
    size = uVar1 + 4;
  }
  while (bVar2 = size != 0, size = size - 1, bVar2) {
    *(char *)ptr = (char)value;
    ptr = (uint *)((int)ptr + 1);
  }
  return;
}


// ===== __sys_appexit @ 00087932 (2 bytes)

/* b . (hang) [fact] */

void __sys_appexit(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== __sys_close @ 00087934 (6 bytes)

/* returns -1 (no host) [fact] */

undefined4 __sys_close(void)

{
  return 0xffffffff;
}


// ===== __sys_flen @ 0008793a (6 bytes)

/* returns -1 [fact] */

uint __sys_flen(void)

{
  return 0xffffffff;
}


// ===== __sys_istty @ 00087940 (6 bytes)

/* returns -1 [fact] */

uint __sys_istty(void)

{
  return 0xffffffff;
}


// ===== __sys_remove @ 00087946 (6 bytes)

/* returns -1 [fact]. Only caller is remove (b.w at 0x87712) with r0 = path, r1 = strlen(path)
   [fact], which is the SYS_REMOVE (0x0E) argument pair (path, length) in the ARM semihosting spec
   (ARM-software/abi-aa@36203f2c semihosting.rst); SYS_READC takes no argument [inference] */

undefined4 __sys_remove(void)

{
  return 0xffffffff;
}


// ===== __sys_seek @ 0008794c (6 bytes)

/* returns -1 [fact] */

uint __sys_seek(void)

{
  return 0xffffffff;
}


// ===== __sys_tmpnam @ 00087952 (6 bytes)

/* returns -1 [fact]. Only caller _Cfclose 0x876E2 passes (stack buffer, FILE+0x20, 0x20) [fact] =
   SYS_TMPNAM (0x0D) fields (buffer, target id, buffer length) in the ARM semihosting spec
   (ARM-software/abi-aa@36203f2c semihosting.rst) [inference] */

undefined4 __sys_tmpnam(void)

{
  return 0xffffffff;
}


// ===== __sys_write @ 00087958 (4 bytes)

/* returns len (nothing written: stdio goes nowhere) [fact] */

undefined4 __sys_write(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  return param_3;
}


// ===== ResetISR @ 080011a8 (76 bytes)

void ResetISR(void)

{
  bool bVar1;
  dword *pdVar2;
  
  disableIRQinterrupts();
                    /* Vector Table Offset [sfr] */
  SCB_VTOR = 0x8001000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x200000);
  }
  setMainStackPointerLimit(0x1ff000);
  SystemInit();
  for (pdVar2 = &__data_section_table; pdVar2 < &__bss_section_table;
      pdVar2 = (dword *)((int)pdVar2 + 0xc)) {
    data_init(*pdVar2,*(dword *)((int)pdVar2 + 4),*(uint *)((int)pdVar2 + 8));
  }
  for (; pdVar2 < ResetISR; pdVar2 = (dword *)((int)pdVar2 + 8)) {
    bss_init(*pdVar2,*(uint *)((int)pdVar2 + 4));
  }
  enableIRQinterrupts();
  call_main();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== NMI_Handler @ 0800120c (2 bytes)

void NMI_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== MemManage_Handler @ 08001210 (2 bytes)

void MemManage_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== BusFault_Handler @ 08001212 (2 bytes)

void BusFault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== UsageFault_Handler @ 08001214 (2 bytes)

void UsageFault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== SecureFault_Handler @ 08001216 (2 bytes)

void SecureFault_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== DebugMon_Handler @ 0800121a (2 bytes)

void DebugMon_Handler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== IntDefaultHandler @ 08001220 (2 bytes)

/* b . ; the 25 weak IRQ handlers without a driver call it; byte-identical to IntDefaultHandler of
   mcux-sdk MCUX_2.9.0 mcuxpresso/startup_mimxrt685s.c [fact: T24 (src/ifdsp_m33/status.tsv,
   aliases.tsv)]. Was DefaultHandler (T23d; T24 round 2) */

void IntDefaultHandler(void)

{
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== data_init @ 08001222 (18 bytes)

void data_init(int param_1,int param_2,uint param_3)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_3; uVar1 = uVar1 + 4) {
    *(undefined4 *)(uVar1 + param_2) = *(undefined4 *)(uVar1 + param_1);
  }
  return;
}

