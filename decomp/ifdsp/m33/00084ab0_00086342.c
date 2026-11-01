// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== ipc_recv @ 00084ab0 (34 bytes)

void ipc_recv(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  rpmsg_queue_recv(DAT_00088b60,DAT_00088b5c,&DAT_00088b54,param_1,0x98,0,0xffffffff,param_4);
  return;
}


// ===== BOARD_DSP_Init @ 00084ad8 (114 bytes)

void BOARD_DSP_Init(void)

{
  undefined **local_2c;
  undefined *local_28;
  dword local_24;
  undefined *local_20;
  undefined4 local_1c;
  dword local_18;
  undefined *local_14;
  undefined *local_10;
  dword local_c;
  
  local_28 = &DAT_24000000;
  local_1c = 0x200000;
  local_10 = &DAT_20040000;
  local_2c = &dsp_image0_tcm;
  local_24 = 0x20644;
  local_20 = &dsp_image1_sram_text;
  local_18 = 0x383b4;
  local_14 = &dsp_image2_sram_data;
  local_c = 0x31e0;
  CLOCK_InitSysPfd(1,0xc);
  CLOCK_AttachClk(0x80002434);
  CLOCK_SetClkDiv(0x80000400,1);
  CLOCK_SetClkDiv(0x80000404,2);
                    /* DSP memory power-up and reset release [doc, inference] */
  DSP_Init();
  DSP_CopyImage(&local_2c);
  DSP_CopyImage(&local_20);
  DSP_CopyImage(&local_14);
                    /* DSP stall [sfr] */
  SYSCTL0_DSPSTALL = 0;
  return;
}


// ===== BOARD_InitPins_P0 @ 00084b78 (108 bytes)

void BOARD_InitPins_P0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
                    /* clock set 1 [sfr] */
  CLKCTL1_PSCCTL1_SET = 1;
  local_18 = param_1 & 0xffff0000;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  GPIO_PinInit(0x40100000,0,4,(char *)&local_18);
  local_14 = local_14 & 0xffff0000;
  GPIO_PinInit(0x40100000,0,5,(char *)&local_14);
  local_10 = local_10 & 0xffff0000;
  GPIO_PinInit(0x40100000,0,0x15,(char *)&local_10);
  local_c = local_c & 0xffff0000;
  GPIO_PinInit(0x40100000,0,0x16,(char *)&local_c);
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_21 = 0x40;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_22 = 0x40;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_4 = 0x40;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_5 = 0x40;
  return;
}


// ===== BOARD_InitPins_codec_spi @ 00084bec (150 bytes)

void BOARD_InitPins_codec_spi(void)

{
  char local_24 [4];
  char local_20 [4];
  char local_1c [4];
  char local_18 [4];
  char local_14 [4];
  
                    /* clock set 1 [sfr] */
  CLKCTL1_PSCCTL1_SET = 2;
  CLKCTL1_PSCCTL1_SET = 4;
  local_24[0] = '\x01';
  local_24[1] = 0;
  GPIO_PinInit(0x40100000,1,0,local_24);
  local_20[0] = '\x01';
  local_20[1] = 0;
  GPIO_PinInit(0x40100000,1,1,local_20);
  local_1c[0] = '\x01';
  local_1c[1] = '\x01';
  GPIO_PinInit(0x40100000,1,7,local_1c);
  local_18[0] = '\0';
  local_18[1] = 0;
  GPIO_PinInit(0x40100000,2,0x1c,local_18);
  local_14[0] = '\x01';
  local_14[1] = 0;
  GPIO_PinInit(0x40100000,2,0x1d,local_14);
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO1_0 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO1_1 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO1_7 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO2_28 = 0x40;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO2_29 = 0;
  return;
}


// ===== BOARD_InitPins_debug_gpio @ 00084c90 (164 bytes)

/* NEW (tail call from BOARD_InitPins). GPIO outputs low: PIO0_28/29/31 (TP2043/2046/2044),
   PIO2_4/5/6 (TP2007/2008/2009) [fact] */

void BOARD_InitPins_debug_gpio(void)

{
  char local_28 [4];
  char local_24 [4];
  char local_20 [4];
  char local_1c [4];
  char local_18 [4];
  char local_14 [4];
  
                    /* clock set 1 [sfr] */
  CLKCTL1_PSCCTL1_SET = 1;
  CLKCTL1_PSCCTL1_SET = 4;
  local_28[0] = '\x01';
  local_28[1] = 0;
  GPIO_PinInit(0x40100000,0,0x1c,local_28);
  local_24[0] = '\x01';
  local_24[1] = 0;
  GPIO_PinInit(0x40100000,0,0x1d,local_24);
  local_20[0] = '\x01';
  local_20[1] = 0;
  GPIO_PinInit(0x40100000,0,0x1f,local_20);
  local_1c[0] = '\x01';
  local_1c[1] = 0;
  GPIO_PinInit(0x40100000,2,4,local_1c);
  local_18[0] = '\x01';
  local_18[1] = 0;
  GPIO_PinInit(0x40100000,2,5,local_18);
  local_14[0] = '\x01';
  local_14[1] = 0;
  GPIO_PinInit(0x40100000,2,6,local_14);
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_28 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_29 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO0_31 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO2_4 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO2_5 = 0;
                    /* iop pad control for port0 to port5 [sfr] */
  IOPCTL_PIO2_6 = 0;
  return;
}


// ===== malloc @ 00084d3c (194 bytes)

/* Replaces redlib_malloc: Redlib heap malloc, free-list blocks tagged 0x10000000 (free) /
   0x20000000 (used), grows with _sbrk 0x85D48 [inference] */

int * malloc(int param_1)

{
  void *_sbrk_ret;
  int *piVar1;
  int iVar2;
  uint uVar3;
  int *piVar4;
  uint uVar5;
  int *piVar6;
  uint uVar7;
  
  if (param_1 != 0) {
    uVar7 = param_1 + 3U >> 2;
    piVar1 = DAT_00088b70;
    piVar6 = (int *)0x0;
    while (piVar4 = piVar1, piVar4 != (int *)0x0) {
      if (*piVar4 == 0x10000000) {
        while( true ) {
          uVar3 = piVar4[1];
          piVar1 = (int *)piVar4[2];
          if ((piVar1 == (int *)0x0) || (*piVar1 != 0x10000000)) break;
          piVar4[1] = piVar1[1] + uVar3 + 3;
          piVar4[2] = piVar1[2];
        }
        if (((int)uVar7 <= (int)uVar3) && ((int)uVar3 <= (int)(uVar7 + 3))) {
          *piVar4 = 0x20000000;
          return piVar4 + 3;
        }
        if (uVar7 + 10 < uVar3) {
          piVar4[1] = uVar7;
          piVar6 = piVar4 + 3;
          *piVar4 = 0x20000000;
          uVar5 = param_1 + 3U & 0xfffffffc;
          iVar2 = (int)piVar6 + uVar5;
          piVar4[2] = iVar2;
          *(undefined4 *)((int)piVar6 + uVar5) = 0x10000000;
          *(uint *)(iVar2 + 4) = (uVar3 - uVar7) + -3;
          *(int **)(iVar2 + 8) = piVar1;
          return piVar6;
        }
        if (piVar1 == (int *)0x0) {
          _sbrk_ret = _sbrk(param_1 + uVar3 * -4);
          if (_sbrk_ret == (void *)0xffffffff) {
            return (int *)0x0;
          }
          *piVar4 = 0x20000000;
          piVar4[1] = uVar7;
          return piVar4 + 3;
        }
      }
      piVar6 = piVar4;
      piVar1 = (int *)piVar4[2];
    }
    piVar1 = _sbrk(param_1 + 0xc);
    if (piVar1 != (int *)0xffffffff) {
      piVar1[2] = 0;
      *piVar1 = 0x20000000;
      piVar1[1] = uVar7;
      piVar4 = piVar1;
      if (piVar6 != (int *)0x0) {
        piVar6[2] = (int)piVar1;
        piVar4 = DAT_00088b70;
      }
      DAT_00088b70 = piVar4;
      return piVar1 + 3;
    }
  }
  return (int *)0x0;
}


// ===== _Csys_alloc @ 00084e04 (26 bytes)

/* Replaces _Csys_alloc_failed: malloc wrapper; on NULL writes "*** _Csys_alloc failed" via
   __sys_write and calls __sys_appexit (hang) [fact] */

int _Csys_alloc(uint param_1)

{
  int *malloc_ret;
  
  malloc_ret = malloc(param_1);
  if (malloc_ret == (int *)0x0) {
    __sys_write(0,"*** _Csys_alloc failed\n",0x17);
    __sys_appexit();
  }
  return (int)malloc_ret;
}


// ===== tolower @ 00084e24 (16 bytes)

byte tolower(int param_1)

{
  if ((int)((uint)ctype_table[param_1] << 0x1b) < 0) {
    param_1 = param_1 + 0x20;
  }
  return (byte)param_1;
}


// ===== stdio_init @ 00084e38 (94 bytes)

/* WARNING: Removing unreachable block (ram,0x00084e94) */

void stdio_init(void)

{
                    /* Opens fd with mode "r"/"w"/"a"[+][b] into a FILE [doc, inference] */
  _Cfdopen(0,"r",&DAT_00088b78);
  setvbuf(&DAT_00088b78,0,0x400,0x100);
  _Cfdopen(1,"w",&DAT_00088bb4);
  setvbuf(&DAT_00088bb4,0,0x400,0x100);
  _Cfdopen(2,"w",&DAT_00088bf0);
  setvbuf(&DAT_00088bf0,0,0x400,0x100);
  return;
}


// ===== vsnprintf_core @ 00084eb0 (2778 bytes)

uint vsnprintf_core(int *param_1,undefined4 param_2,uint param_3,int param_4,byte *param_5,
                   uint *param_6,code *param_7)

{
  byte bVar1;
  char cVar2;
  char *pcVar3;
  undefined1 uVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  int iVar8;
  uint uVar9;
  undefined1 *puVar10;
  int iVar11;
  uint *puVar12;
  int iVar13;
  uint uVar14;
  char *pcVar15;
  uint uVar16;
  uint uVar17;
  byte *pbVar18;
  int iVar19;
  undefined4 *puVar20;
  uint uVar21;
  int iVar22;
  uint uVar23;
  uint uVar24;
  bool bVar25;
  uint local_88;
  uint local_84;
  uint local_70;
  uint local_60;
  uint *local_5c;
  int local_58;
  int local_54;
  undefined4 local_50;
  undefined4 uStack_4c;
  char acStack_48 [36];
  
  local_88 = 0;
LAB_00084ec2:
  while( true ) {
    pbVar18 = param_5 + 1;
    bVar1 = *param_5;
    if (bVar1 == 0) {
      return local_88;
    }
    uVar5 = (int)local_88 >> 0x1f;
    if (bVar1 == 0x25) break;
    bVar25 = local_88 < param_3;
    local_88 = local_88 + 1;
    param_5 = pbVar18;
    if ((int)((uVar5 - param_4) - (uint)bVar25) < 0 !=
        (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)bVar25))) {
      iVar8 = param_1[2];
      param_1[2] = iVar8 + -1;
      if (iVar8 + -1 < 0) {
                    /* FILE output slow path, 19 callers [doc, inference] */
        fputc(bVar1,param_1);
      }
      else {
        pbVar18 = (byte *)*param_1;
        *param_1 = (int)(pbVar18 + 1);
        *pbVar18 = bVar1;
      }
    }
  }
  uVar23 = 0;
  while( true ) {
    while( true ) {
      while( true ) {
        while( true ) {
          param_5 = pbVar18 + 1;
          uVar16 = (uint)*pbVar18;
          if (uVar16 != 0x2b) break;
          uVar23 = uVar23 | 2;
          pbVar18 = param_5;
        }
        if (uVar16 < 0x2c) break;
        if (uVar16 == 0x2d) {
          uVar23 = uVar23 | 1;
          pbVar18 = param_5;
        }
        else {
          if (uVar16 != 0x30) goto LAB_00084f3a;
          uVar23 = uVar23 | 0x200;
          pbVar18 = param_5;
        }
      }
      if (uVar16 != 0x20) break;
      uVar23 = uVar23 | 4;
      pbVar18 = param_5;
    }
    if (uVar16 != 0x23) break;
    uVar23 = uVar23 | 8;
    pbVar18 = param_5;
  }
LAB_00084f3a:
  if (uVar16 == 0x2a) {
    uVar21 = *param_6;
    uVar16 = (uint)*param_5;
    if ((int)uVar21 < 0) {
      uVar21 = -uVar21;
      uVar23 = uVar23 ^ 1;
    }
    param_5 = pbVar18 + 2;
    param_6 = param_6 + 1;
  }
  else {
    uVar21 = 0;
    while ((uVar16 - 0x30 & 0xff) < 10) {
      uVar21 = uVar21 * 10 + (uVar16 - 0x30);
      uVar16 = (uint)*param_5;
      param_5 = param_5 + 1;
    }
  }
  uVar9 = uVar21 & ~((int)uVar21 >> 0x1f);
  puVar7 = param_6;
  if (uVar16 == 0x2e) {
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x2a) {
      puVar7 = param_6 + 1;
      uVar24 = *param_6;
      uVar16 = (uint)param_5[1];
      param_5 = param_5 + 2;
    }
    else {
      uVar24 = 0;
      while( true ) {
        param_5 = param_5 + 1;
        if (9 < (uVar16 - 0x30 & 0xff)) break;
        uVar24 = uVar24 * 10 + (uVar16 - 0x30);
        uVar16 = (uint)*param_5;
      }
    }
    if ((int)uVar24 < 0) goto LAB_00085002;
    uVar23 = uVar23 | 0x10;
  }
  else {
LAB_00085002:
    uVar24 = 0;
  }
  if (uVar16 == 0x6c) {
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x6c) {
      uVar16 = (uint)param_5[1];
      uVar23 = uVar23 | 0x60;
      param_5 = param_5 + 2;
    }
    else {
      param_5 = param_5 + 1;
      uVar23 = uVar23 | 0x20;
    }
  }
  if ((uVar16 == 0x4c) || (uVar16 == 0x71)) {
    bVar1 = *param_5;
    uVar23 = uVar23 | 0x60;
LAB_00084ffe:
    uVar16 = (uint)bVar1;
    param_5 = param_5 + 1;
  }
  else {
    if (uVar16 != 0x68) {
      if (uVar16 == 0x6a) {
        uVar23 = uVar23 | 0x40;
      }
      else if ((uVar16 != 0x7a) && (uVar16 != 0x74)) goto LAB_0008502a;
      bVar1 = *param_5;
      goto LAB_00084ffe;
    }
    uVar16 = (uint)*param_5;
    if (uVar16 == 0x68) {
      uVar16 = (uint)param_5[1];
      uVar23 = uVar23 | 0x100;
      param_5 = param_5 + 2;
    }
    else {
      param_5 = param_5 + 1;
      uVar23 = uVar23 | 0x80;
    }
  }
LAB_0008502a:
  param_6 = puVar7;
  if (0x78 < uVar16) goto switchD_000850fe_caseD_59;
  if (uVar16 < 0x58) {
    if (uVar16 == 0x41) {
switchD_000850fe_caseD_61:
      if ((uVar23 & 0x10) == 0) {
        uVar24 = 0xd;
        uVar23 = uVar23 | 0x10;
      }
switchD_000850fe_caseD_65:
      puVar20 = (undefined4 *)((int)puVar7 + 7U & 0xfffffff8);
      param_6 = puVar20 + 2;
      local_50 = *puVar20;
      uStack_4c = puVar20[1];
      uVar21 = 0;
      if ((uVar23 & 0x10) == 0) {
        uVar24 = 6;
      }
      uVar6 = 0;
      pcVar3 = (char *)0x0;
      local_5c = (uint *)0x0;
      uVar23 = uVar23 | 0x400;
      goto LAB_00085464;
    }
    if (uVar16 < 0x42) {
      if (uVar16 != 0) goto switchD_000850fe_caseD_59;
      param_5 = param_5 + -1;
      goto LAB_00084ec2;
    }
    if ((uVar16 & 0xfffffffd) == 0x45) goto switchD_000850fe_caseD_65;
switchD_000850fe_caseD_59:
    iVar8 = uVar9 - 1;
    if ((uVar23 & 1) == 0) {
      uVar24 = local_88;
      iVar19 = iVar8;
      if ((uVar23 & 0x200) == 0) {
        uVar4 = 0x20;
      }
      else {
        uVar4 = 0x30;
      }
      while (-1 < iVar19 + -1) {
        if ((int)((uVar5 - param_4) - (uint)(uVar24 < param_3)) < 0 !=
            (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)(uVar24 < param_3)))) {
          iVar22 = param_1[2];
          param_1[2] = iVar22 + -1;
          if (iVar22 + -1 < 0) {
            fputc(uVar4,param_1);
          }
          else {
            puVar10 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar10 + 1);
            *puVar10 = uVar4;
          }
        }
        uVar5 = uVar5 + (0xfffffffe < uVar24);
        uVar24 = uVar24 + 1;
        iVar19 = iVar19 + -1;
      }
      if ((int)uVar21 < 1) {
        iVar8 = 0;
      }
      iVar19 = 1 - uVar9;
      if ((int)uVar21 < 1) {
        iVar19 = 0;
      }
      local_88 = iVar8 + local_88;
      iVar8 = iVar19 + (uVar9 - 2);
    }
    uVar5 = local_88 + 1;
    iVar19 = (int)local_88 >> 0x1f;
    if ((int)((iVar19 - param_4) - (uint)(local_88 < param_3)) < 0 !=
        (SBORROW4(iVar19,param_4) != SBORROW4(iVar19 - param_4,(uint)(local_88 < param_3)))) {
      iVar19 = param_1[2];
      param_1[2] = iVar19 + -1;
      if (iVar19 + -1 < 0) {
        fputc(uVar16,param_1);
      }
      else {
        puVar10 = (undefined1 *)*param_1;
        *param_1 = (int)(puVar10 + 1);
        *puVar10 = (char)uVar16;
      }
    }
    local_88 = uVar5;
    if ((uVar23 & 1) != 0) {
      iVar19 = (int)uVar5 >> 0x1f;
      uVar23 = uVar5;
      iVar22 = iVar8;
      while (iVar22 = iVar22 + -1, -1 < iVar22) {
        if ((int)((iVar19 - param_4) - (uint)(uVar23 < param_3)) < 0 !=
            (SBORROW4(iVar19,param_4) != SBORROW4(iVar19 - param_4,(uint)(uVar23 < param_3)))) {
          iVar11 = param_1[2];
          param_1[2] = iVar11 + -1;
          if (iVar11 + -1 < 0) {
            fputc(0x20,param_1);
          }
          else {
            puVar10 = (undefined1 *)*param_1;
            *param_1 = (int)(puVar10 + 1);
            *puVar10 = 0x20;
          }
        }
        bVar25 = 0xfffffffe < uVar23;
        uVar23 = uVar23 + 1;
        iVar19 = iVar19 + (uint)bVar25;
      }
      if (-1 < iVar8) {
        local_88 = uVar5 + iVar8;
      }
    }
    goto LAB_00084ec2;
  }
  switch(uVar16) {
  case 0x58:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar7 + 1;
      uVar21 = *puVar7;
      uVar6 = 0;
    }
    else {
      puVar7 = (uint *)((int)puVar7 + 7U & 0xfffffff8);
      param_6 = puVar7 + 2;
      uVar21 = *puVar7;
      uVar6 = puVar7[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = (uint *)0x87e8f;
    if ((uVar23 & 8) == 0) {
      local_5c = (uint *)&DAT_00087cba;
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = "0123456789ABCDEF";
    break;
  default:
    goto switchD_000850fe_caseD_59;
  case 0x61:
    goto switchD_000850fe_caseD_61;
  case 99:
    param_6 = puVar7 + 1;
    uVar16 = *puVar7;
    goto switchD_000850fe_caseD_59;
  case 100:
  case 0x69:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar7 + 1;
      uVar21 = *puVar7;
      uVar6 = (int)uVar21 >> 0x1f;
    }
    else {
      puVar7 = (uint *)((int)puVar7 + 7U & 0xfffffff8);
      param_6 = puVar7 + 2;
      uVar21 = *puVar7;
      uVar6 = puVar7[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar6 = (int)(uVar21 << 0x18) >> 0x1f;
        uVar21 = (uint)(char)uVar21;
      }
    }
    else {
      uVar6 = (int)(uVar21 << 0x10) >> 0x1f;
      uVar21 = (uint)(short)uVar21;
    }
    if ((int)uVar6 < 0) {
      bVar25 = uVar21 != 0;
      uVar21 = -uVar21;
      local_5c = (uint *)&UNK_00087e95;
      uVar6 = -uVar6 - (uint)bVar25;
    }
    else {
      if ((uVar23 & 2) == 0) {
        local_5c = (uint *)0x87bff;
        uVar14 = uVar23 & 4;
        goto LAB_000854ea;
      }
      local_5c = (uint *)&UNK_00087e97;
    }
    goto LAB_00085596;
  case 0x65:
  case 0x66:
  case 0x67:
    goto switchD_000850fe_caseD_65;
  case 0x6e:
    puVar12 = (uint *)*puVar7;
    param_6 = puVar7 + 1;
    if ((uVar23 & 0x40) == 0) {
      if ((uVar23 & 0x20) == 0) {
        if ((uVar23 & 0x100) != 0) {
          *(char *)puVar12 = (char)local_88;
          goto LAB_00084ec2;
        }
        if ((uVar23 & 0x80) != 0) {
          *(short *)puVar12 = (short)local_88;
          goto LAB_00084ec2;
        }
      }
      *puVar12 = local_88;
      goto LAB_00084ec2;
    }
    *puVar12 = local_88;
    puVar12[1] = uVar5;
    goto LAB_00084ec2;
  case 0x6f:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar7 + 1;
      uVar21 = *puVar7;
      uVar6 = 0;
    }
    else {
      puVar7 = (uint *)((int)puVar7 + 7U & 0xfffffff8);
      param_6 = puVar7 + 2;
      uVar21 = *puVar7;
      uVar6 = puVar7[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = (uint *)0x87c62;
    uVar14 = uVar23 & 8;
LAB_000854ea:
    if (uVar14 == 0) {
      local_5c = (uint *)&DAT_00087cba;
    }
LAB_00085596:
    pcVar3 = (char *)0x0;
    if ((uVar23 & 0x10) != 0) {
      pcVar3 = (char *)0x0;
      uVar23 = uVar23 & 0xfffffdff;
    }
    break;
  case 0x70:
    uVar6 = 0;
    param_6 = puVar7 + 1;
    uVar21 = *puVar7;
    pcVar3 = "0123456789abcdef";
    local_5c = (uint *)0x87e92;
    break;
  case 0x73:
    goto switchD_000850fe_caseD_73;
  case 0x75:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar7 + 1;
      uVar21 = *puVar7;
      uVar6 = 0;
    }
    else {
      puVar7 = (uint *)((int)puVar7 + 7U & 0xfffffff8);
      param_6 = puVar7 + 2;
      uVar21 = *puVar7;
      uVar6 = puVar7[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = (char *)0x0;
    local_5c = (uint *)&DAT_00087cba;
    break;
  case 0x78:
    if ((uVar23 & 0x40) == 0) {
      param_6 = puVar7 + 1;
      uVar21 = *puVar7;
      uVar6 = 0;
    }
    else {
      puVar7 = (uint *)((int)puVar7 + 7U & 0xfffffff8);
      param_6 = puVar7 + 2;
      uVar21 = *puVar7;
      uVar6 = puVar7[1];
    }
    if ((uVar23 & 0x80) == 0) {
      if ((uVar23 & 0x100) != 0) {
        uVar21 = uVar21 & 0xff;
        uVar6 = 0;
      }
    }
    else {
      uVar6 = 0;
      uVar21 = uVar21 & 0xffff;
    }
    local_5c = (uint *)0x87e92;
    if ((uVar23 & 8) == 0) {
      local_5c = (uint *)&DAT_00087cba;
    }
    if ((uVar23 & 0x10) != 0) {
      uVar23 = uVar23 & 0xfffffdff;
    }
    pcVar3 = "0123456789abcdef";
  }
LAB_00085464:
  uVar14 = param_3 - local_88;
  local_58 = -1;
  local_54 = -1;
  iVar19 = (param_4 - uVar5) - (uint)(param_3 < local_88);
  iVar8 = 0;
  pcVar15 = acStack_48;
  do {
    iVar8 = iVar8 + 1;
    *pcVar15 = 'U';
    pcVar15 = pcVar15 + 1;
  } while (iVar8 != 0x20);
  local_60 = uVar24;
  if ((uVar23 & 0x410) == 0) {
    local_60 = 1;
  }
  pcVar15 = acStack_48;
  if (uVar16 < 0x6f) {
    if (uVar16 < 0x48) {
      if (0x40 < uVar16) {
        iVar8 = 0;
        if ((1 << (uVar16 - 0x41 & 0xff) & 0x51U) == 0) goto switchD_000855de_caseD_71;
switchD_000856e6_caseD_61:
        iVar8 = (*param_7)(uVar16,&local_50,acStack_48,uVar23,&local_5c,&local_60,&local_58,
                           &local_54);
        goto switchD_000855de_caseD_71;
      }
    }
    else {
      switch(uVar16) {
      case 0x58:
        iVar8 = 0;
        goto switchD_000855de_caseD_70;
      case 0x61:
      case 0x65:
      case 0x66:
      case 0x67:
        goto switchD_000856e6_caseD_61;
      case 100:
      case 0x69:
        goto switchD_000855de_caseD_75;
      }
    }
    iVar8 = 0;
  }
  else {
    iVar8 = 0;
    switch(uVar16) {
    case 0x6f:
      for (; uVar21 != 0 || uVar6 != 0; uVar21 = uVar21 >> 3 | uVar5) {
        uVar5 = uVar6 << 0x1d;
        iVar8 = iVar8 + 1;
        *pcVar15 = ((byte)uVar21 & 7) + 0x30;
        uVar6 = uVar6 >> 3;
        pcVar15 = pcVar15 + 1;
      }
      break;
    case 0x70:
    case 0x78:
switchD_000855de_caseD_70:
      for (; uVar21 != 0 || uVar6 != 0; uVar21 = uVar21 >> 4 | uVar5) {
        uVar5 = uVar6 << 0x1c;
        iVar8 = iVar8 + 1;
        *pcVar15 = pcVar3[uVar21 & 0xf];
        uVar6 = uVar6 >> 4;
        pcVar15 = pcVar15 + 1;
      }
      break;
    case 0x75:
switchD_000855de_caseD_75:
      iVar8 = 0;
      pcVar3 = acStack_48;
      for (; uVar21 != 0 || uVar6 != 0; uVar6 = uVar16 + (uVar5 >> 4) + (uint)CARRY4(uVar6,uVar24))
      {
        uVar5 = uVar21 >> 2 | uVar6 << 0x1e;
        uVar16 = uVar21 >> 1 | uVar6 << 0x1f;
        uVar24 = uVar16 + uVar5;
        uVar5 = (uVar6 >> 2) + (uVar6 >> 1) + (uint)CARRY4(uVar16,uVar5);
        uVar16 = uVar24 >> 4 | uVar5 * 0x10000000;
        uVar17 = uVar24 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 4) + (uint)CARRY4(uVar24,uVar16);
        uVar16 = uVar17 >> 8 | uVar5 * 0x1000000;
        uVar24 = uVar17 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 8) + (uint)CARRY4(uVar17,uVar16);
        uVar16 = uVar24 >> 0x10 | uVar5 * 0x10000;
        uVar17 = uVar24 + uVar16;
        uVar5 = uVar5 + (uVar5 >> 0x10) + (uint)CARRY4(uVar24,uVar16);
        uVar16 = uVar5 + CARRY4(uVar17,uVar5);
        uVar24 = uVar17 + uVar5 >> 3 | uVar16 * 0x20000000;
        uVar17 = (uint)((ulonglong)uVar24 * 10);
        uVar16 = uVar16 >> 3;
        uVar5 = ((uVar6 + (0xfffffff9 < uVar21)) -
                (uVar16 * 10 + (int)((ulonglong)uVar24 * 10 >> 0x20))) - (uint)(uVar21 + 6 < uVar17)
        ;
        uVar6 = (uVar21 + 6) - uVar17 >> 4 | uVar5 * 0x10000000;
        uVar17 = uVar6 + uVar24;
        *pcVar3 = (char)uVar21 + '0' + (char)uVar17 * -10;
        iVar8 = iVar8 + 1;
        uVar21 = uVar17;
        pcVar3 = pcVar3 + 1;
      }
    }
  }
switchD_000855de_caseD_71:
  if ((uVar23 & 0x400) == 0) {
    local_60 = local_60 - iVar8;
    if ((int)local_60 < 0) {
      local_60 = 0;
    }
  }
  else {
    local_60 = 0;
    if (0 < local_58) {
      local_60 = local_58 - 1;
    }
    if (0 < local_54) {
      local_60 = local_54 + -1 + local_60;
    }
  }
  iVar11 = iVar8 + local_60;
  iVar22 = strlen(local_5c);
  local_84 = (uVar9 - iVar11) - iVar22;
  if ((uVar23 & 0x201) == 0) {
    iVar22 = 0;
    for (uVar5 = 0; -1 < (int)((local_84 - 1) - uVar5); uVar5 = uVar5 + 1) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar5 < uVar14)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar5 < uVar14)))) {
        iVar11 = param_1[2];
        param_1[2] = iVar11 + -1;
        if (iVar11 + -1 < 0) {
          fputc(0x20,param_1);
        }
        else {
          puVar10 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar10 + 1);
          *puVar10 = 0x20;
        }
      }
      iVar22 = iVar22 + (uint)(0xfffffffe < uVar5);
    }
    uVar5 = local_84 & ~((int)local_84 >> 0x1f);
    local_84 = (local_84 - 1) - uVar5;
  }
  else {
    uVar5 = 0;
  }
  iVar22 = (int)uVar5 >> 0x1f;
  uVar16 = uVar5;
  while( true ) {
    puVar7 = (uint *)((int)local_5c + 1);
    cVar2 = (char)*local_5c;
    local_5c = puVar7;
    if (cVar2 == '\0') break;
    uVar5 = uVar5 + 1;
    if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar14)) < 0 !=
        (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar14)))) {
      iVar11 = param_1[2];
      param_1[2] = iVar11 + -1;
      if (iVar11 + -1 < 0) {
        fputc(cVar2,param_1);
      }
      else {
        pcVar3 = (char *)*param_1;
        *param_1 = (int)(pcVar3 + 1);
        *pcVar3 = cVar2;
      }
    }
    bVar25 = 0xfffffffe < uVar16;
    uVar16 = uVar16 + 1;
    iVar22 = iVar22 + (uint)bVar25;
  }
  if ((uVar23 & 1) == 0) {
    if ((uVar23 & 0x200) == 0) {
      uVar4 = 0x20;
    }
    else {
      uVar4 = 0x30;
    }
    iVar22 = (int)uVar5 >> 0x1f;
    local_70 = local_84;
    uVar16 = uVar5;
    while (local_70 = local_70 - 1, -1 < (int)local_70) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar14)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar14)))) {
        iVar11 = param_1[2];
        param_1[2] = iVar11 + -1;
        if (iVar11 + -1 < 0) {
          fputc(uVar4,param_1);
        }
        else {
          puVar10 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar10 + 1);
          *puVar10 = uVar4;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
    }
    uVar16 = local_84 & ~((int)local_84 >> 0x1f);
    local_84 = (local_84 - 1) - uVar16;
    uVar5 = uVar5 + uVar16;
  }
  iVar22 = 0;
  if ((uVar23 & 0x400) == 0) {
    iVar22 = (int)uVar5 >> 0x1f;
    uVar16 = uVar5;
    while (local_60 = local_60 - 1, -1 < (int)local_60) {
      uVar5 = uVar5 + 1;
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar14)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar14)))) {
        iVar11 = param_1[2];
        param_1[2] = iVar11 + -1;
        if (iVar11 + -1 < 0) {
          fputc(0x30,param_1);
        }
        else {
          puVar10 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar10 + 1);
          *puVar10 = 0x30;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
    }
    iVar22 = (int)uVar5 >> 0x1f;
    iVar11 = iVar8;
    uVar16 = uVar5;
    while (0 < iVar11) {
      if ((int)((iVar22 - iVar19) - (uint)(uVar16 < uVar14)) < 0 !=
          (SBORROW4(iVar22,iVar19) != SBORROW4(iVar22 - iVar19,(uint)(uVar16 < uVar14)))) {
        iVar13 = param_1[2];
        cVar2 = acStack_48[iVar11 + -1];
        param_1[2] = iVar13 + -1;
        if (iVar13 + -1 < 0) {
          fputc(cVar2,param_1);
        }
        else {
          pcVar3 = (char *)*param_1;
          *param_1 = (int)(pcVar3 + 1);
          *pcVar3 = cVar2;
        }
      }
      bVar25 = 0xfffffffe < uVar16;
      uVar16 = uVar16 + 1;
      iVar22 = iVar22 + (uint)bVar25;
      iVar11 = iVar11 + -1;
    }
    if (-1 < iVar8) {
      uVar5 = uVar5 + iVar8;
    }
  }
  else {
    for (; iVar22 < iVar8; iVar22 = iVar22 + 1) {
      cVar2 = acStack_48[iVar22];
      iVar11 = (int)uVar5 >> 0x1f;
      uVar16 = uVar5;
      if (cVar2 == '<') {
        while (local_58 = local_58 + -1, -1 < local_58) {
          if ((int)((iVar11 - iVar19) - (uint)(uVar5 < uVar14)) < 0 !=
              (SBORROW4(iVar11,iVar19) != SBORROW4(iVar11 - iVar19,(uint)(uVar5 < uVar14)))) {
            iVar13 = param_1[2];
            param_1[2] = iVar13 + -1;
            if (iVar13 + -1 < 0) {
              fputc(0x30,param_1);
            }
            else {
              puVar10 = (undefined1 *)*param_1;
              *param_1 = (int)(puVar10 + 1);
              *puVar10 = 0x30;
            }
          }
          bVar25 = 0xfffffffe < uVar5;
          uVar5 = uVar5 + 1;
          iVar11 = iVar11 + (uint)bVar25;
          uVar16 = uVar16 + 1;
        }
      }
      else if (cVar2 == '>') {
        while (local_54 = local_54 + -1, -1 < local_54) {
          if ((int)((iVar11 - iVar19) - (uint)(uVar5 < uVar14)) < 0 !=
              (SBORROW4(iVar11,iVar19) != SBORROW4(iVar11 - iVar19,(uint)(uVar5 < uVar14)))) {
            iVar13 = param_1[2];
            param_1[2] = iVar13 + -1;
            if (iVar13 + -1 < 0) {
              fputc(0x30,param_1);
            }
            else {
              puVar10 = (undefined1 *)*param_1;
              *param_1 = (int)(puVar10 + 1);
              *puVar10 = 0x30;
            }
          }
          bVar25 = 0xfffffffe < uVar5;
          uVar5 = uVar5 + 1;
          iVar11 = iVar11 + (uint)bVar25;
          uVar16 = uVar16 + 1;
        }
      }
      else {
        uVar16 = uVar5 + 1;
        if ((int)((iVar11 - iVar19) - (uint)(uVar5 < uVar14)) < 0 !=
            (SBORROW4(iVar11,iVar19) != SBORROW4(iVar11 - iVar19,(uint)(uVar5 < uVar14)))) {
          iVar11 = param_1[2];
          param_1[2] = iVar11 + -1;
          if (iVar11 + -1 < 0) {
            fputc(cVar2,param_1);
          }
          else {
            pcVar3 = (char *)*param_1;
            *param_1 = (int)(pcVar3 + 1);
            *pcVar3 = cVar2;
          }
        }
      }
      uVar5 = uVar16;
    }
  }
  if ((uVar23 & 1) != 0) {
    iVar8 = (int)uVar5 >> 0x1f;
    uVar23 = uVar5;
    uVar16 = local_84;
    while (uVar16 = uVar16 - 1, -1 < (int)uVar16) {
      if ((int)((iVar8 - iVar19) - (uint)(uVar23 < uVar14)) < 0 !=
          (SBORROW4(iVar8,iVar19) != SBORROW4(iVar8 - iVar19,(uint)(uVar23 < uVar14)))) {
        iVar22 = param_1[2];
        param_1[2] = iVar22 + -1;
        if (iVar22 + -1 < 0) {
          fputc(0x20,param_1);
        }
        else {
          puVar10 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar10 + 1);
          *puVar10 = 0x20;
        }
      }
      bVar25 = 0xfffffffe < uVar23;
      uVar23 = uVar23 + 1;
      iVar8 = iVar8 + (uint)bVar25;
    }
    if (-1 < (int)local_84) {
      uVar5 = uVar5 + local_84;
    }
  }
  local_88 = local_88 + uVar5;
  goto LAB_00084ec2;
switchD_000850fe_caseD_73:
  param_6 = puVar7 + 1;
  pcVar3 = (char *)*puVar7;
  if ((uint *)pcVar3 == (uint *)0x0) {
    pcVar3 = "(null)";
  }
  local_84 = strlen((uint *)pcVar3);
  if (((uVar23 & 0x10) != 0) && ((int)uVar24 <= (int)local_84)) {
    local_84 = uVar24;
  }
  uVar9 = uVar9 - local_84;
  if ((uVar23 & 1) == 0) {
    uVar16 = local_88;
    uVar21 = uVar9;
    if ((uVar23 & 0x200) == 0) {
      uVar4 = 0x20;
    }
    else {
      uVar4 = 0x30;
    }
    while (-1 < (int)(uVar21 - 1)) {
      if ((int)((uVar5 - param_4) - (uint)(uVar16 < param_3)) < 0 !=
          (SBORROW4(uVar5,param_4) != SBORROW4(uVar5 - param_4,(uint)(uVar16 < param_3)))) {
        iVar8 = param_1[2];
        param_1[2] = iVar8 + -1;
        if (iVar8 + -1 < 0) {
          fputc(uVar4,param_1);
        }
        else {
          puVar10 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar10 + 1);
          *puVar10 = uVar4;
        }
      }
      uVar5 = uVar5 + (0xfffffffe < uVar16);
      uVar16 = uVar16 + 1;
      uVar21 = uVar21 - 1;
    }
    uVar5 = uVar9 & ~((int)uVar9 >> 0x1f);
    local_88 = local_88 + uVar5;
    uVar9 = (uVar9 - 1) - uVar5;
  }
  iVar8 = (int)local_88 >> 0x1f;
  uVar5 = local_88;
  for (iVar19 = 0; iVar19 < (int)local_84; iVar19 = iVar19 + 1) {
    if ((int)((iVar8 - param_4) - (uint)(uVar5 < param_3)) < 0 !=
        (SBORROW4(iVar8,param_4) != SBORROW4(iVar8 - param_4,(uint)(uVar5 < param_3)))) {
      iVar22 = param_1[2];
      param_1[2] = iVar22 + -1;
      if (iVar22 + -1 < 0) {
        fputc(*(undefined1 *)((int)pcVar3 + iVar19),param_1);
      }
      else {
        puVar10 = (undefined1 *)*param_1;
        *param_1 = (int)(puVar10 + 1);
        *puVar10 = *(undefined1 *)((int)pcVar3 + iVar19);
      }
    }
    bVar25 = 0xfffffffe < uVar5;
    uVar5 = uVar5 + 1;
    iVar8 = iVar8 + (uint)bVar25;
  }
  if (-1 < (int)local_84) {
    local_88 = local_88 + local_84;
  }
  if ((uVar23 & 1) != 0) {
    iVar8 = (int)local_88 >> 0x1f;
    uVar5 = local_88;
    uVar23 = uVar9;
    while (uVar23 = uVar23 - 1, -1 < (int)uVar23) {
      if ((int)((iVar8 - param_4) - (uint)(uVar5 < param_3)) < 0 !=
          (SBORROW4(iVar8,param_4) != SBORROW4(iVar8 - param_4,(uint)(uVar5 < param_3)))) {
        iVar19 = param_1[2];
        param_1[2] = iVar19 + -1;
        if (iVar19 + -1 < 0) {
          fputc(0x20,param_1);
        }
        else {
          puVar10 = (undefined1 *)*param_1;
          *param_1 = (int)(puVar10 + 1);
          *puVar10 = 0x20;
        }
      }
      bVar25 = 0xfffffffe < uVar5;
      uVar5 = uVar5 + 1;
      iVar8 = iVar8 + (uint)bVar25;
    }
    if (-1 < (int)uVar9) {
      local_88 = local_88 + uVar9;
    }
  }
  goto LAB_00084ec2;
}


// ===== sprintf @ 00085a9c (102 bytes)

/* variadic (push {r1-r3}) with (buffer, format, ...) and no length [fact: 0x85A9C]. Was siprintf
   (T24 round 2) */

undefined4 sprintf(undefined1 *param_1)

{
  undefined4 uVar1;
  undefined1 *local_54 [2];
  int local_4c;
  undefined4 local_48;
  
  memset(local_54,0,0x3c);
  local_48 = 10;
  local_4c = 0x7fffffff;
  local_54[0] = param_1;
  uVar1 = vsnprintf_core(local_54);
  local_4c = local_4c + -1;
  if (local_4c < 0) {
                    /* FILE output slow path, 19 callers [doc, inference] */
    fputc(0,local_54);
  }
  else {
    *local_54[0] = 0;
  }
  return uVar1;
}


// ===== snprintf @ 00085b08 (114 bytes)

undefined4 snprintf(undefined1 *param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  undefined1 local_5c [4];
  undefined4 *local_58;
  undefined1 *local_54 [2];
  int local_4c;
  undefined4 local_48;
  undefined4 uStack_4;
  
  if (param_1 == (undefined1 *)0x0) {
    if (param_2 != 0) {
      return 0xffffffff;
    }
    param_1 = local_5c;
  }
  local_58 = &uStack_4;
  uStack_4 = param_4;
  memset(local_54,0,0x3c);
  local_48 = 10;
  local_4c = 0x7fffffff;
  local_54[0] = param_1;
  uVar1 = vsnprintf_core(local_54);
  local_4c = local_4c + -1;
  if (local_4c < 0) {
                    /* FILE output slow path, 19 callers [doc, inference] */
    fputc(0,local_54);
  }
  else {
    *local_54[0] = 0;
  }
  return uVar1;
}


// ===== vsprintf @ 00085b80 (88 bytes)

/* (buffer, format, va_list): console_printf and uart0_printf pass the address of their variadic
   arguments [fact: 0x8138C, 0x80F0C]. Was sprintf (T24 round 2) */

int vsprintf(char *buf,char *format,void *ap)

{
  int iVar1;
  char *local_4c [2];
  int local_44;
  undefined4 local_40;
  
  memset(local_4c,0,0x3c);
  local_40 = 10;
  local_44 = 0x7fffffff;
  local_4c[0] = buf;
  iVar1 = vsnprintf_core(local_4c);
  local_44 = local_44 + -1;
  if (local_44 < 0) {
                    /* FILE output slow path, 19 callers [doc, inference] */
    fputc(0,local_4c);
  }
  else {
    *local_4c[0] = '\0';
  }
  return iVar1;
}


// ===== _Cdigit_value @ 00085bdc (44 bytes)

/* ctype-table digit value for strtoul [inference] */

int _Cdigit_value(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = (uint)ctype_table[param_1];
  if ((int)(uVar2 << 0x1a) < 0) {
    iVar1 = param_1 + -0x30;
  }
  else if ((int)(uVar2 << 0x1c) < 0) {
    iVar1 = param_1 + -0x57;
  }
  else if ((int)(uVar2 << 0x1b) < 0) {
    iVar1 = param_1 + -0x37;
  }
  else {
    iVar1 = -1;
  }
  if (param_2 <= iVar1) {
    iVar1 = -1;
  }
  return iVar1;
}


// ===== _strtoul_core @ 00085c0c (172 bytes)

/* Base detection (0x / 0), overflow -> errno 34 (0x88B74) [inference] */

uint _strtoul_core(byte *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  bool bVar2;
  uint uVar3;
  int _Cdigit_value_ret;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  uint uVar7;
  
  pbVar5 = param_1;
  do {
    pbVar4 = pbVar5;
    pbVar5 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
    if (uVar3 == 0) goto LAB_00085c30;
  } while ((int)((uint)ctype_table[uVar3] << 0x1f) < 0);
  if (uVar3 == 0x30) {
    uVar3 = (uint)*pbVar5;
    pbVar5 = pbVar4 + 2;
    if ((uVar3 & 0xdf) == 0x58) {
      if ((param_3 & 0xffffffef) == 0) {
        param_3 = 0x10;
        uVar3 = (uint)pbVar4[2];
        pbVar5 = pbVar4 + 3;
        bVar2 = false;
      }
      else {
        bVar2 = true;
      }
    }
    else {
      bVar2 = true;
      if (param_3 == 0) {
        param_3 = 8;
      }
    }
  }
  else {
LAB_00085c30:
    if (param_3 == 0) {
      param_3 = 10;
      bVar2 = false;
    }
    else {
      bVar2 = false;
    }
  }
  uVar6 = 0;
  uVar7 = 0;
  bVar1 = false;
                    /* ctype-table digit value for strtoul [doc, inference] */
  while (_Cdigit_value_ret = _Cdigit_value(uVar3,param_3), -1 < _Cdigit_value_ret) {
    uVar6 = uVar6 * param_3 + _Cdigit_value_ret;
    uVar7 = uVar7 * param_3 + (uVar6 >> 0x10);
    if (0xffff < uVar7) {
      bVar1 = true;
    }
    bVar2 = true;
    uVar3 = (uint)*pbVar5;
    uVar6 = uVar6 & 0xffff;
    pbVar5 = pbVar5 + 1;
  }
  if (bVar2) {
    param_1 = pbVar5 + -1;
  }
  *param_2 = param_1;
  if (bVar1) {
    uVar6 = 0xffffffff;
    DAT_00088b74 = 0x22;
  }
  else {
    uVar6 = uVar6 | uVar7 << 0x10;
  }
  return uVar6;
}


// ===== strtoul @ 00085cc0 (128 bytes)

ushort strtoul(byte *param_1,byte *param_2,uint param_3)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  byte *pbVar5;
  uint uVar6;
  byte *local_24;
  uint uStack_20;
  
  iVar1 = DAT_00088b74;
  pbVar5 = param_1;
  do {
    pbVar4 = pbVar5;
    pbVar5 = pbVar4 + 1;
    uVar3 = (uint)*pbVar4;
    if (uVar3 == 0) {
      uVar6 = 0;
      pbVar5 = pbVar4;
      goto LAB_00085cfa;
    }
    uVar6 = ctype_table[uVar3] & 1;
  } while ((ctype_table[uVar3] & 1) != 0);
  if (uVar3 != 0x2b) {
    if (uVar3 == 0x2d) {
      uVar6 = 0x200;
    }
    else {
      uVar6 = 0;
      pbVar5 = pbVar4;
    }
  }
LAB_00085cfa:
  DAT_00088b74 = 0;
  local_24 = param_2;
  uStack_20 = param_3;
  iVar2 = _strtoul_core(pbVar5,&local_24,param_3,0,param_1);
  if (param_2 != (byte *)0x0) {
    if (local_24 != pbVar5) {
      param_1 = local_24;
    }
    *(byte **)param_2 = param_1;
  }
  if ((DAT_00088b74 != 0x22) && (DAT_00088b74 = iVar1, uVar6 != 0)) {
    if (iVar2 < 0) {
      iVar2 = -1;
      DAT_00088b74 = 0x22;
    }
    else {
      iVar2 = -iVar2;
    }
  }
  return (ushort)iVar2;
}


// ===== _sbrk @ 00085d48 (48 bytes)

/* Heap 0xA1EF8..0xA2EF8 (4 KB), errno 12 on overflow [fact: addresses] */

void * _sbrk(int param_1)

{
  bool __check_heap_overflow_ret;
  undefined *puVar1;
  undefined *puVar2;
  
  if (DAT_00088b6c == (undefined *)0x0) {
    DAT_00088b6c = &DAT_000a1ef8;
  }
  puVar2 = DAT_00088b6c;
  puVar1 = DAT_00088b6c + (param_1 + 3U & 0xfffffffc);
                    /* new_end >= 0xA2EF8 [doc] */
  __check_heap_overflow_ret = __check_heap_overflow(puVar1);
  if (__check_heap_overflow_ret) {
    puVar2 = (undefined *)0xffffffff;
    DAT_00088b74 = 0xc;
    puVar1 = DAT_00088b6c;
  }
  DAT_00088b6c = puVar1;
  return puVar2;
}


// ===== _Cwrite_buffer @ 00085d84 (102 bytes)

/* Flush FILE buffer through __sys_write [inference] */

uint _Cwrite_buffer(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar2 = *(uint *)(param_3 + 0xc);
  uVar3 = *(undefined4 *)(param_3 + 0x14);
  if ((int)(uVar2 << 0xb) < 0) {
    uVar1 = __sys_flen();
    uVar2 = uVar2 | 0x10;
    *(uint *)(param_3 + 0x18) = uVar1;
  }
  if ((uVar2 & 0x20010) != 0) {
    uVar1 = __sys_seek();
    if ((int)uVar1 < 0) goto LAB_00085db4;
    *(uint *)(param_3 + 0xc) = uVar2 & 0xfffdffef;
  }
  uVar2 = __sys_write(uVar3,param_1,param_2);
  *(uint *)(param_3 + 0x18) = (param_2 - (uVar2 & 0x7fffffff)) + *(int *)(param_3 + 0x18);
  if (uVar2 == 0) {
    return 0;
  }
LAB_00085db4:
  *(uint *)(param_3 + 0xc) = *(uint *)(param_3 + 0xc) | 0x80;
  return 0xffffffff;
}


// ===== fflush @ 00085df0 (50 bytes)

/* NULL -> all three streams at 0x88B78 (0x3C bytes each) [inference] */

uint fflush(int *param_1)

{
  uint _Cfflush1_ret;
  int i;
  uint uVar1;
  int *piVar2;
  
  if (param_1 == (int *)0x0) {
    piVar2 = (int *)&DAT_00088b78;
    uVar1 = 0;
    for (i = 0; i < 3; i = i + 1) {
      _Cfflush1_ret = _Cfflush1(piVar2);
      if (_Cfflush1_ret != 0) {
        uVar1 = 0xffffffff;
      }
      piVar2 = piVar2 + 0xf;
    }
    return uVar1;
  }
  uVar1 = _Cfflush1(param_1);
  return uVar1;
}


// ===== fseek @ 00085e2c (252 bytes)

/* [inference] */

undefined4 fseek(uint *param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  bool bVar6;
  
  uVar5 = param_1[3];
  if (((uVar5 & 0x100003) == 0) || (uVar1 = __sys_istty(), uVar1 != 0)) {
    return 2;
  }
  if (param_3 == 1) {
    iVar4 = ftell((int *)param_1);
    param_2 = param_2 + iVar4;
  }
  else if (param_3 == 2) {
    uVar1 = __sys_flen();
    if ((int)uVar1 < 0) {
      param_1[3] = param_1[3] | 0x80;
      return 1;
    }
    uVar3 = *param_1;
    if (uVar3 < param_1[0xb]) {
      uVar3 = param_1[0xb];
    }
    uVar3 = (param_1[6] + uVar3) - param_1[4];
    if (((int)(param_1[3] << 0x1a) < 0) && ((int)uVar3 < (int)param_1[10])) {
      uVar3 = param_1[10];
    }
    if ((int)uVar3 < (int)uVar1) {
      uVar3 = uVar1;
    }
    param_2 = param_2 + uVar3;
  }
  else if (param_3 != 0) {
    return 2;
  }
  if ((int)param_2 < 0) {
    return 2;
  }
  if ((int)(uVar5 << 0x12) < 0) {
    if (param_1[0xb] < *param_1) {
      param_1[0xb] = *param_1;
    }
  }
  uVar1 = param_1[6];
  if ((int)uVar1 <= (int)param_2) {
    uVar3 = *param_1;
    if (*param_1 < param_1[0xb]) {
      uVar3 = param_1[0xb];
    }
    uVar2 = param_1[4];
    if (((int)param_2 <= (int)((uVar3 + uVar1) - uVar2)) &&
       ((int)param_2 < (int)(uVar1 + param_1[0xc]))) {
      iVar4 = param_2 - uVar1;
      if ((int)(uVar5 << 0x1e) < 0) {
        param_1[2] = iVar4 - param_1[0xc];
      }
      bVar6 = (int)(uVar5 << 0x1f) < 0;
      if (bVar6) {
        uVar3 = iVar4 - (uVar3 - uVar2);
      }
      if (bVar6) {
        param_1[1] = uVar3;
      }
      *param_1 = iVar4 + uVar2;
      uVar5 = uVar5 & 0xffffffdf;
      goto LAB_00085eaa;
    }
  }
  param_1[1] = 0;
  param_1[2] = 0;
  uVar5 = uVar5 | 0x20;
  param_1[10] = param_2;
LAB_00085eaa:
  param_1[3] = uVar5 & 0xfff7cfbf;
  return 0;
}


// ===== ftell @ 00085f2c (64 bytes)

/* [inference] */

int ftell(int *param_1)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = param_1[3];
  if ((uVar2 & 3) == 0) {
    DAT_00088b74 = 0x21;
    return -1;
  }
  if ((int)(uVar2 << 0xc) < 0) {
    if ((uVar2 & 0x20) == 0) {
      iVar1 = (*param_1 + param_1[6]) - param_1[4];
    }
    else {
      iVar1 = param_1[10];
    }
    return iVar1 + -1;
  }
  if ((uVar2 & 0x20) != 0) {
    return param_1[10];
  }
  return (*param_1 + param_1[6]) - param_1[4];
}


// ===== __check_heap_overflow @ 00085f70 (18 bytes)

/* WARNING: Removing unreachable block (ram,0x00085f7e) */
/* new_end >= 0xA2EF8 [fact] */

bool __check_heap_overflow(void *param_1)

{
  return &DAT_000a2ef8 <= param_1;
}


// ===== aic3204_select_right_input @ 00085f88 (38 bytes)

/* codec P1 R55 = 0x10 (arg 1, IN2R) or 0x40 (arg 0, IN1R); called by regfile_write for reg 10 */

void aic3204_select_right_input(int param_1)

{
  uint uVar1;
  
  if (param_1 == 1) {
    uVar1 = 0x10;
  }
  else {
    uVar1 = 0x40;
  }
                    /* 16-bit word reg<<9 | val [doc] */
  aic3204_spi_write(0,1);
  aic3204_spi_write(0x37,uVar1);
  aic3204_spi_write(0,0);
  return;
}


// ===== console_puts @ 00085fae (20 bytes)

void console_puts(uint param_1)

{
  int strlen_ret;
  
  strlen_ret = strlen((uint *)param_1);
                    /* Copy bytes into the TX ring [doc] */
  uart0_write(param_1,strlen_ret);
  return;
}


// ===== IpcRecvTask @ 00085fc6 (36 bytes)

void IpcRecvTask(int param_1)

{
  undefined1 auStack_a0 [152];
  
  do {
    do {
      ipc_recv(auStack_a0);
                    /* category/command text on the console [doc] */
      ipc_print_dsp_reply(auStack_a0);
    } while (*(int *)(param_1 + 4) == 0);
    xTaskGenericNotify(*(int *)(param_1 + 4),0,2);
  } while( true );
}


// ===== HardFault_Handler @ 00085fea (42 bytes)

void HardFault_Handler(void)

{
  undefined4 *puVar1;
  uint unaff_lr;
  
  if ((unaff_lr & 4) == 0) {
    puVar1 = (undefined4 *)getMainStackPointer();
  }
  else {
    puVar1 = (undefined4 *)getProcessStackPointer();
  }
  if (*(short *)puVar1[6] != -0x4155) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  puVar1[6] = (short *)puVar1[6] + 1;
  *puVar1 = 0x20;
  return;
}


// ===== is_hex_string @ 00086014 (48 bytes)

uint is_hex_string(byte *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  
  puVar2 = (uint *)param_1;
  do {
    uVar1 = strlen(puVar2);
    if (uVar1 <= (uint)((int)puVar2 - (int)param_1)) {
      return 1;
    }
    puVar3 = (uint *)((int)puVar2 + 1);
    uVar1 = *puVar2;
    puVar2 = puVar3;
  } while (((byte)uVar1 - 0x30 < 10) || (((byte)uVar1 & 0xffffffdf) - 0x41 < 6));
  return 0;
}


// ===== frame_checksum_ok @ 00086044 (38 bytes)

bool frame_checksum_ok(char *param_1,int param_2)

{
  ushort strtoul_ret;
  byte *pbVar1;
  char cVar2;
  
  cVar2 = '\0';
  pbVar1 = (byte *)(param_1 + param_2);
  for (; (byte *)param_1 != pbVar1; param_1 = param_1 + 1) {
    cVar2 = cVar2 + *param_1;
  }
  strtoul_ret = strtoul((byte *)param_1,(byte *)0x0,0x10);
  return (char)strtoul_ret == cVar2;
}


// ===== platform_vatopa @ 0008606a (2 bytes)

/* bx lr; env_map_vatopa 0x86098 is b.w here [fact]; byte-identical to platform_vatopa of rpmsg-lite
   v3.1.0 imxrt600_m33/rpmsg_platform.c [fact: T24 (src/ifdsp_m33/status.tsv, aliases.tsv)]. Was
   env_map_vatopa (T24 round 2) */

uint platform_vatopa(void *address)

{
  return (uint)address;
}


// ===== platform_patova @ 0008606c (2 bytes)

/* NEW (entries_m33.tsv): byte-identical to platform_patova of rpmsg-lite v3.1.0
   rpmsg_lite/porting/platform/imxrt600_m33/rpmsg_platform.c [fact: T24 (src/ifdsp_m33/status.tsv,
   aliases.tsv)]; bx lr; env_map_patova 0x8609C is b.w here [fact: 0x8606C] (T24 round 2) */

void * platform_patova(uint address)

{
  return (void *)address;
}


// ===== env_free_memory @ 00086072 (8 bytes)

void env_free_memory(int param_1)

{
  if (param_1 != 0) {
    vPortFree(param_1);
    return;
  }
  return;
}


// ===== env_mb @ 00086086 (6 bytes)

/* DSB [inference] */

void env_mb(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== env_rmb @ 0008608c (6 bytes)

/* DSB [inference] */

void env_rmb(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== env_wmb @ 00086092 (6 bytes)

/* DSB [inference] */

void env_wmb(void)

{
  DataSynchronizationBarrier(0xf);
  return;
}


// ===== env_create_mutex @ 000860a0 (32 bytes)

int env_create_mutex(int *param_1,int param_2)

{
  uint xQueueCreateCountingSemaphore_ret;
  int iVar1;
  
  if (param_2 < 0xb) {
    xQueueCreateCountingSemaphore_ret = xQueueCreateCountingSemaphore(10,param_2);
    *param_1 = xQueueCreateCountingSemaphore_ret;
    iVar1 = -(uint)(xQueueCreateCountingSemaphore_ret == 0);
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}


// ===== env_lock_mutex @ 000860c4 (26 bytes)

void env_lock_mutex(uint param_1)

{
  bool xPortIsInsideInterrupt_ret;
  
  xPortIsInsideInterrupt_ret = platform_in_isr();
  if (!xPortIsInsideInterrupt_ret) {
    xQueueSemaphoreTake((int *)param_1,-1);
    return;
  }
  return;
}


// ===== env_unlock_mutex @ 000860de (28 bytes)

void env_unlock_mutex(uint param_1)

{
  bool xPortIsInsideInterrupt_ret;
  
  xPortIsInsideInterrupt_ret = platform_in_isr();
  if (!xPortIsInsideInterrupt_ret) {
    xQueueGenericSend(param_1,0,0,0);
    return;
  }
  return;
}


// ===== env_create_queue @ 00086106 (26 bytes)

/* [inference] */

int env_create_queue(int *param_1,uint param_2,uint param_3)

{
  int xQueueGenericCreate_ret;
  
  xQueueGenericCreate_ret = xQueueGenericCreate(param_2,param_3,0);
  *param_1 = xQueueGenericCreate_ret;
  return -(uint)(xQueueGenericCreate_ret == 0);
}


// ===== env_put_queue @ 00086120 (78 bytes)

/* Queue send, ISR-aware [inference] */

bool env_put_queue(uint param_1,uint param_2,uint param_3)

{
  bool xPortIsInsideInterrupt_ret;
  uint uVar1;
  bool bVar2;
  int local_14 [2];
  
  bVar2 = false;
  local_14[0] = 0;
  xPortIsInsideInterrupt_ret = platform_in_isr();
  if (xPortIsInsideInterrupt_ret) {
    uVar1 = xQueueGenericSendFromISR(param_1,param_2,local_14,0);
    if ((uVar1 == 1) && (bVar2 = true, local_14[0] != 0)) {
                    /* Interrupt Control and State [sfr] */
      SCB_ICSR = 0x10000000;
    }
  }
  else {
    uVar1 = xQueueGenericSend(param_1,param_2,param_3,0);
    bVar2 = uVar1 == 1;
  }
  return bVar2;
}


// ===== env_get_queue @ 0008616e (74 bytes)

/* Queue receive, ISR-aware [inference] */

bool env_get_queue(uint param_1,uint param_2,uint param_3)

{
  bool xPortIsInsideInterrupt_ret;
  uint xQueueReceiveFromISR_ret;
  int iVar1;
  bool bVar2;
  int local_14 [2];
  
  bVar2 = false;
  local_14[0] = 0;
  xPortIsInsideInterrupt_ret = platform_in_isr();
  if (xPortIsInsideInterrupt_ret) {
    xQueueReceiveFromISR_ret = xQueueReceiveFromISR(param_1,param_2,local_14);
    if ((xQueueReceiveFromISR_ret == 1) && (bVar2 = true, local_14[0] != 0)) {
                    /* Interrupt Control and State [sfr] */
      SCB_ICSR = 0x10000000;
    }
  }
  else {
    iVar1 = xQueueReceive(param_1,param_2,param_3);
    bVar2 = iVar1 == 1;
  }
  return bVar2;
}


// ===== rpmsg_queue_rx_cb @ 000861b8 (34 bytes)

/* create: endpoint callback of ept 0x28; env_put_queue(q, {src, data, len}); returns RL_HOLD (1) */

bool rpmsg_queue_rx_cb(undefined4 param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  bool env_put_queue_ret;
  undefined4 local_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  if (param_4 == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  local_14 = param_3;
  local_10 = param_1;
  uStack_c = param_2;
  env_put_queue_ret = env_put_queue(param_4,(uint)&local_14,0);
  return env_put_queue_ret;
}


// ===== rpmsg_queue_create @ 000861da (38 bytes)

int rpmsg_queue_create(int *param_1,undefined4 param_2,undefined4 param_3)

{
  int env_create_queue_ret;
  int local_c;
  undefined4 uStack_8;
  
  local_c = 0;
  if ((param_1 == (int *)0x0) ||
     (uStack_8 = param_3,
     env_create_queue_ret = env_create_queue(&local_c,(uint)*(ushort *)(*param_1 + 0x52),0xc),
     env_create_queue_ret != 0)) {
    local_c = 0;
  }
  return local_c;
}


// ===== add_to_list @ 00086200 (30 bytes)

/* rpmsg_lite endpoint list [inference] */

void add_to_list(int *param_1,int param_2)

{
  if (param_2 != 0) {
    if (*param_1 != 0) {
      *(int *)(param_2 + 8) = *param_1;
      *(undefined4 *)(param_2 + 0xc) = 0;
      *(int *)(*param_1 + 0xc) = param_2;
      *param_1 = param_2;
      return;
    }
    *param_1 = param_2;
    *(undefined4 *)(param_2 + 8) = 0;
    *(undefined4 *)(*param_1 + 0xc) = 0;
  }
  return;
}


// ===== rpmsg_lite_tx_callback @ 0008621e (12 bytes)

/* create: tx_vq callback, sets rl->link_state = 1 */

void rpmsg_lite_tx_callback(int param_1)

{
  if (*(int *)(param_1 + 100) == 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  *(undefined4 *)(*(int *)(param_1 + 100) + 0x10) = 1;
  return;
}


// ===== virtqueue_notify @ 0008622a (8 bytes)

/* create: vq notify hook, platform_notify(vq->vq_queue_index) */

void virtqueue_notify(int param_1)

{
                    /* MU-A TR1 = vector << 16 under platform_lock [doc] */
  platform_notify(*(undefined2 *)(param_1 + 0x50));
  return;
}


// ===== vq_tx_master @ 00086232 (14 bytes)

/* create: master_vq_ops[0] (table 0x879AC): virtqueue_add_buffer, assert on error */

void vq_tx_master(void *rvq,void *buffer,uint len,ushort idx)

{
  uint virtqueue_add_buffer_ret;
  
  virtqueue_add_buffer_ret = virtqueue_add_buffer((uint)rvq,(uint)idx);
  if (virtqueue_add_buffer_ret != 0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  return;
}


// ===== rpmsg_lite_get_endpoint_from_addr @ 00086248 (16 bytes)

/* [inference] */

void rpmsg_lite_get_endpoint_from_addr(undefined4 *param_1,int param_2)

{
  for (; (param_1 != (undefined4 *)0x0 && (*(int *)*param_1 != param_2));
      param_1 = (undefined4 *)param_1[2]) {
  }
  return;
}


// ===== rpmsg_lite_rx_callback @ 00086258 (86 bytes)

/* Virtqueue rx callback, dispatches to endpoint callbacks [inference] */

void rpmsg_lite_rx_callback(int param_1,undefined4 param_2)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  undefined4 uStack_18;
  undefined4 local_14;
  
  puVar4 = *(undefined4 **)(param_1 + 100);
  uStack_18 = param_1;
  local_14 = param_2;
  if (puVar4 == (undefined4 *)0x0) {
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  while (puVar3 = (undefined4 *)(**(code **)(puVar4[8] + 8))(*puVar4,&local_14,(int)&uStack_18 + 2),
        puVar3 != (undefined4 *)0x0) {
    piVar1 = (int *)rpmsg_lite_get_endpoint_from_addr(puVar4[2],puVar3[1]);
    if ((piVar1 == (int *)0x0) ||
       (iVar2 = (**(code **)(*piVar1 + 4))
                          (puVar3 + 4,*(undefined2 *)(puVar3 + 3),*puVar3,
                           *(undefined4 *)(*piVar1 + 8)), iVar2 != 1)) {
      (**(code **)(puVar4[8] + 0xc))(*puVar4,puVar3,local_14,uStack_18._2_2_);
    }
    else {
      *(undefined2 *)((int)puVar3 + 10) = uStack_18._2_2_;
    }
  }
  return;
}


// ===== rpmsg_lite_create_ept @ 000862b2 (144 bytes)

int * rpmsg_lite_create_ept(int param_1,int param_2,int param_3,int param_4)

{
  int iVar1;
  int *pvPortMalloc_ret;
  undefined4 *pvPortMalloc_ret_2;
  undefined4 uVar2;
  undefined4 extraout_r2;
  bool bVar3;
  
  if (param_1 == 0) {
    return (int *)0x0;
  }
  env_lock_mutex(*(uint *)(param_1 + 0xc));
  if (param_2 == -1) {
    uVar2 = *(undefined4 *)(param_1 + 8);
    param_2 = 1;
    do {
      iVar1 = rpmsg_lite_get_endpoint_from_addr(uVar2,param_2);
      if (iVar1 == 0) goto LAB_000862fa;
      bVar3 = param_2 != -2;
      uVar2 = extraout_r2;
      param_2 = param_2 + 1;
    } while (bVar3);
  }
  else {
    iVar1 = rpmsg_lite_get_endpoint_from_addr(*(undefined4 *)(param_1 + 8),param_2);
    if (iVar1 == 0) {
LAB_000862fa:
      pvPortMalloc_ret = env_allocate_memory(0x10);
      if (pvPortMalloc_ret != (int *)0x0) {
        pvPortMalloc_ret_2 = env_allocate_memory(0x10);
        if (pvPortMalloc_ret_2 == (undefined4 *)0x0) {
          env_free_memory((int)pvPortMalloc_ret);
          goto LAB_000862e0;
        }
        env_memset(pvPortMalloc_ret,0,0x10);
        *pvPortMalloc_ret = param_2;
        pvPortMalloc_ret[1] = param_3;
        pvPortMalloc_ret[2] = param_4;
        *pvPortMalloc_ret_2 = pvPortMalloc_ret;
        add_to_list((int *)(param_1 + 8),(int)pvPortMalloc_ret_2);
      }
      env_unlock_mutex(*(uint *)(param_1 + 0xc));
      return pvPortMalloc_ret;
    }
  }
LAB_000862e0:
  env_unlock_mutex(*(uint *)(param_1 + 0xc));
  return (int *)0x0;
}


// ===== vq_ring_update_avail @ 00086342 (46 bytes)

/* [inference] */

void vq_ring_update_avail(int param_1,ushort param_2)

{
  *(ushort *)
   (*(int *)(param_1 + 0x48) +
    (*(ushort *)(param_1 + 0x52) - 1 & (uint)*(ushort *)(*(int *)(param_1 + 0x48) + 2)) * 2 + 4) =
       param_2;
  env_wmb();
  *(short *)(*(int *)(param_1 + 0x48) + 2) = *(short *)(*(int *)(param_1 + 0x48) + 2) + 1;
  *(short *)(param_1 + 0x56) = *(short *)(param_1 + 0x56) + 1;
  return;
}

