// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== _Cflush_read @ 00087470 (64 bytes)

/* [guess] */

void _Cflush_read(undefined4 *param_1)

{
  param_1[3] = param_1[3] & 0xffffffdf;
  if (param_1[6] != param_1[10]) {
    _Cflush_write();
    param_1[3] = param_1[3] & 0xffffcfef | 0x10;
    param_1[6] = param_1[10];
    param_1[0xb] = param_1[4];
    *param_1 = param_1[4];
  }
  param_1[3] = param_1[3] & 0xffffbfbf;
  return;
}


// ===== fputc @ 000874b0 (320 bytes)

/* FILE output slow path, 19 callers (printf engine) [inference] */

uint fputc(byte param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  uVar3 = param_2[3];
  param_2[3] = uVar3 & 0xfff7ffff;
  if ((int)(uVar3 << 0x1a) < 0) {
    _Cflush_read(param_2);
  }
  uVar3 = param_2[3];
  if (((int)param_2[2] < -1) && (-1 < (int)(uVar3 << 0x16))) {
    param_2[2] = 0xfffffffe - param_2[2];
    pbVar4 = (byte *)*param_2;
    param_2[3] = uVar3 | 0x12000;
    *param_2 = (uint)(pbVar4 + 1);
    *pbVar4 = param_1;
LAB_000874ee:
    uVar3 = (uint)param_1;
  }
  else {
    if ((uVar3 & 0x108a) == 2) {
      if ((uVar3 & 0xa010) == 0x8000) {
        fseek(param_2,0);
        if ((int)(param_2[3] << 0x1a) < 0) {
          _Cflush_read(param_2);
        }
        uVar3 = param_2[3];
      }
      uVar5 = uVar3 | 0x12000;
      param_2[3] = uVar5;
      if ((uVar3 & 0xf00) == 0) {
        iVar1 = __sys_istty(param_2[5]);
        if ((iVar1 == 0) || (-1 < (int)(uVar3 << 0x15))) {
          uVar2 = _Csys_alloc(0x100);
          param_2[7] = 0x100;
          uVar5 = uVar3 | 0x12800;
          param_2[4] = uVar2;
          *param_2 = uVar2;
          param_2[3] = param_2[3] | uVar5;
        }
        else {
          param_2[4] = (uint)(param_2 + 9);
          *param_2 = (uint)(param_2 + 9);
          param_2[7] = 1;
          uVar5 = uVar3 | 0x12400;
          param_2[3] = uVar5;
        }
      }
      pbVar4 = (byte *)*param_2;
      pbVar6 = (byte *)param_2[4];
      if ((uVar5 & 0x900) == 0) {
        uVar3 = (uint)param_1;
        *param_2 = (uint)(pbVar4 + 1);
        *pbVar4 = param_1;
        if (*param_2 < param_2[0xb]) {
          iVar1 = param_2[0xb] - (int)pbVar6;
        }
        else {
          iVar1 = *param_2 - (int)pbVar6;
        }
        param_2[0xc] = param_2[7];
        if (((-1 < (int)(uVar5 << 0x15)) && (uVar3 != 10)) && (iVar1 < (int)param_2[7])) {
          return uVar3;
        }
        param_2[0xb] = (uint)pbVar6;
        *param_2 = (uint)pbVar6;
        param_2[2] = 0;
        iVar1 = _Cwrite_buffer(pbVar6,iVar1,param_2);
        if (iVar1 == 0) {
          return uVar3;
        }
      }
      else {
        if (pbVar4 < (byte *)param_2[0xb]) {
          iVar1 = (int)param_2[0xb] - (int)pbVar6;
        }
        else {
          iVar1 = (int)pbVar4 - (int)pbVar6;
        }
        if ((iVar1 == 0) || (iVar1 = _Cwrite_buffer(pbVar6,iVar1,param_2), iVar1 == 0)) {
          param_2[0xb] = (uint)(pbVar6 + 1);
          *param_2 = (uint)(pbVar6 + 1);
          param_2[2] = param_2[7] - 1;
          param_2[0xc] = param_2[7];
          *pbVar6 = param_1;
          goto LAB_000874ee;
        }
      }
    }
    else {
      param_2[2] = 0;
      param_2[3] = uVar3 | 0x80;
    }
    uVar3 = 0xffffffff;
  }
  return uVar3;
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


// ===== _Cflush_write @ 00087658 (82 bytes)

/* [guess] */

undefined4 _Cflush_write(uint *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  uVar4 = param_1[4];
  uVar3 = param_1[0xb];
  uVar1 = param_1[3];
  param_1[3] = uVar1 & 0xfff7ffff;
  if ((uVar1 & 0x82) == 2) {
    if ((uVar1 & 0x10000) == 0) {
      return 0;
    }
    uVar1 = *param_1;
    if (*param_1 < uVar3) {
      uVar1 = uVar3;
    }
    if ((uVar4 == uVar1) ||
       (iVar2 = _Cwrite_buffer(uVar4,uVar1 - uVar4,param_1,uVar3,param_4), iVar2 == 0)) {
      param_1[0xb] = uVar4;
      *param_1 = uVar4;
      param_1[2] = 0;
      param_1[3] = param_1[3] & 0xfffeffff;
      return 0;
    }
  }
  return 0xffffffff;
}


// ===== _Cfclose @ 000876aa (88 bytes)

/* [inference] */

undefined4 _Cfclose(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  undefined1 auStack_38 [36];
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if ((uVar1 & 3) == 0) {
    uVar2 = 0xffffffff;
  }
  else {
    if (-1 < (int)(uVar1 << 0x1c)) {
      uVar2 = *(undefined4 *)(param_1 + 0x10);
      uVar3 = *(undefined4 *)(param_1 + 0x14);
      fflush();
      __sys_close(uVar3);
      if ((int)(uVar1 << 0x14) < 0) {
        free(uVar2);
      }
      if ((uVar1 & 0xffc00000) == 0xad800000) {
        __sys_tmpnam(auStack_38,*(undefined4 *)(param_1 + 0x20),0x20);
        remove(auStack_38);
      }
    }
    memset(param_1,0,0x3c);
    uVar2 = 0;
  }
  return uVar2;
}


// ===== remove @ 00087702 (20 bytes)

/* Stub: strlen then return -1 [guess] */

void remove(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = strlen();
  __sys_readc(param_1,uVar1);
  return;
}


// ===== _Cfflush1 @ 00087716 (64 bytes)

/* [inference] */

undefined4 _Cfflush1(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = 0;
  if ((param_1[3] & 3U) != 0) {
    if (param_1[3] << 0x1a < 0) {
      iVar2 = param_1[10];
      _Cflush_read();
    }
    else {
      iVar2 = (*param_1 + param_1[6]) - param_1[4];
    }
    param_1[3] = param_1[3] & 0xffffcfff;
    uVar1 = _Cflush_write(param_1);
    fseek(param_1,iVar2,0);
  }
  return uVar1;
}


// ===== __aeabi_uldivmod @ 00087756 (252 bytes)

/* 64-bit unsigned divide (also reached by the flash veneer 0x08001618) [inference] */

undefined8 __aeabi_uldivmod(uint param_1,uint param_2,uint param_3,uint param_4)

{
  longlong lVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint extraout_r12;
  uint extraout_r12_00;
  bool bVar7;
  ulonglong uVar8;
  
  uVar6 = 0;
  if (param_4 == 0) {
    if (param_3 == 0) {
      return 0;
    }
    iVar2 = 0;
    if (param_3 <= param_2) {
      iVar2 = __udivmoddi_core(param_2,0);
    }
    uVar3 = __udivmoddi_core(param_1);
    uVar6 = extraout_r12;
  }
  else if ((int)param_4 < 0) {
    iVar2 = 0;
    uVar3 = (uint)(param_4 < param_2 || param_2 - param_4 < (uint)(param_3 <= param_1));
  }
  else {
    if (param_4 >> 0x10 == 0) {
      param_4 = param_4 << 0x10;
      uVar6 = 0x10;
    }
    if ((param_4 & 0xff000000) == 0) {
      param_4 = param_4 << 8;
      uVar6 = uVar6 + 8;
    }
    if ((param_4 & 0xf0000000) == 0) {
      param_4 = param_4 << 4;
      uVar6 = uVar6 + 4;
    }
    uVar3 = param_4 & 0xc0000000;
    if ((param_4 & 0xc0000000) == 0) {
      uVar6 = uVar6 + 2;
      param_4 = param_4 << 2;
      uVar3 = param_4;
    }
    if (-1 < (int)uVar3) {
      uVar6 = uVar6 + 1;
      param_4 = param_4 << 1;
    }
    uVar3 = 0x20 - uVar6;
    uVar8 = __udivmoddi_core(param_1 >> (uVar3 & 0xff) | param_2 << uVar6,param_2 >> (uVar3 & 0xff),
                             param_4 | param_3 >> (uVar3 & 0xff));
    uVar4 = (uint)(uVar8 >> 0x20);
    uVar3 = (uint)uVar8;
    lVar1 = (ulonglong)(param_3 << uVar6) * (uVar8 & 0xffffffff);
    uVar5 = (uint)((ulonglong)lVar1 >> 0x20);
    if (uVar4 <= uVar5 && (uint)((uint)lVar1 <= param_1 << uVar6) <= uVar4 - uVar5) {
      uVar3 = uVar3 - 1;
    }
    iVar2 = 0;
    uVar6 = extraout_r12_00;
  }
  if ((uVar6 & 0xc0000000) != 0) {
    if ((int)(uVar6 & 0xc0000000) < 0) {
      bVar7 = uVar3 != 0;
      uVar3 = -uVar3;
      iVar2 = -(uint)bVar7 - iVar2;
    }
    if ((uVar6 & 0x40000000) != 0) {
      return CONCAT44(iVar2,uVar3);
    }
    return CONCAT44(iVar2,uVar3);
  }
  return CONCAT44(iVar2,uVar3);
}


// ===== __udivmoddi_core @ 00087850 (122 bytes)

/* [guess] */

void __udivmoddi_core(uint param_1,uint param_2,uint param_3)

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


// ===== memcpy @ 000878cc (52 bytes)

void memcpy(undefined4 *param_1,undefined4 *param_2,uint param_3)

{
  bool bVar1;
  
  if (-1 < (int)(((uint)param_1 | (uint)param_2) << 0x1f)) {
    bVar1 = 3 < param_3;
    param_3 = param_3 - 4;
    do {
      if (bVar1) {
        *param_1 = *param_2;
        bVar1 = 3 < param_3;
        param_3 = param_3 - 4;
        param_1 = param_1 + 1;
        param_2 = param_2 + 1;
      }
    } while (bVar1);
    param_3 = param_3 + 4;
    if (param_3 == 0) {
      return;
    }
  }
  do {
    bVar1 = param_3 != 0;
    param_3 = param_3 - 1;
    if (bVar1) {
      *(undefined1 *)param_1 = *(undefined1 *)param_2;
      param_1 = (undefined4 *)((int)param_1 + 1);
      param_2 = (undefined4 *)((int)param_2 + 1);
    }
  } while (bVar1 && param_3 != 0);
  return;
}


// ===== memset @ 00087900 (50 bytes)

void memset(uint *param_1,uint param_2,uint param_3)

{
  bool bVar1;
  
  if (((uint)param_1 & 3) == 0) {
    param_2 = param_2 & 0xff | (param_2 & 0xff) << 8;
    param_2 = param_2 | param_2 << 0x10;
    bVar1 = 3 < param_3;
    param_3 = param_3 - 4;
    do {
      if (bVar1) {
        *param_1 = param_2;
        bVar1 = 3 < param_3;
        param_3 = param_3 - 4;
        param_1 = param_1 + 1;
      }
    } while (bVar1);
    param_3 = param_3 + 4;
  }
  while (bVar1 = param_3 != 0, param_3 = param_3 - 1, bVar1) {
    *(char *)param_1 = (char)param_2;
    param_1 = (uint *)((int)param_1 + 1);
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

undefined4 __sys_flen(void)

{
  return 0xffffffff;
}


// ===== __sys_istty @ 00087940 (6 bytes)

/* returns -1 [fact] */

undefined4 __sys_istty(void)

{
  return 0xffffffff;
}


// ===== __sys_readc @ 00087946 (6 bytes)

/* NEW: returns -1 [guess: name] */

undefined4 __sys_readc(void)

{
  return 0xffffffff;
}


// ===== __sys_seek @ 0008794c (6 bytes)

/* returns -1 [fact] */

undefined4 __sys_seek(void)

{
  return 0xffffffff;
}


// ===== __sys_tmpnam @ 00087952 (6 bytes)

/* returns -1 [guess: name] */

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
  undefined4 in_r3;
  dword *pdVar2;
  
  disableIRQinterrupts();
  DAT_e000ed08 = 0x8001000;
  bVar1 = (bool)isCurrentModePrivileged();
  if (bVar1) {
    setMainStackPointer(0x200000);
  }
  setMainStackPointerLimit(0x1ff000);
  SystemInit(&DAT_e000ed08,0x200000,0x1ff000,&vec___initial_sp,in_r3);
  for (pdVar2 = &__data_section_table; pdVar2 < &__bss_section_table;
      pdVar2 = (dword *)((int)pdVar2 + 0xc)) {
    data_init(*pdVar2,*(dword *)((int)pdVar2 + 4),*(dword *)((int)pdVar2 + 8));
  }
  for (; pdVar2 < ResetISR; pdVar2 = (dword *)((int)pdVar2 + 8)) {
    bss_init(*pdVar2,*(dword *)((int)pdVar2 + 4));
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


// ===== FUN_08001220 @ 08001220 (2 bytes)

void FUN_08001220(void)

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


// ===== bss_init @ 08001234 (16 bytes)

void bss_init(int param_1,uint param_2)

{
  uint uVar1;
  
  for (uVar1 = 0; uVar1 < param_2; uVar1 = uVar1 + 4) {
    *(undefined4 *)(uVar1 + param_1) = 0;
  }
  return;
}


// ===== WDT0_IRQHandler @ 08001244 (8 bytes)

void WDT0_IRQHandler(void)

{
  FUN_08001220();
  return;
}


// ===== DMA0_IRQHandler @ 0800124c (8 bytes)

void DMA0_IRQHandler(void)

{
  FUN_08001698();
  return;
}


// ===== GPIO_INTA_IRQHandler @ 08001254 (8 bytes)

void GPIO_INTA_IRQHandler(void)

{
  FUN_08001220();
  return;
}


// ===== GPIO_INTB_IRQHandler @ 0800125c (8 bytes)

void GPIO_INTB_IRQHandler(void)

{
  FUN_08001220();
  return;
}


// ===== PIN_INT0_IRQHandler @ 08001264 (8 bytes)

void PIN_INT0_IRQHandler(void)

{
  FUN_08001678();
  return;
}


// ===== PIN_INT1_IRQHandler @ 0800126c (8 bytes)

void PIN_INT1_IRQHandler(void)

{
  FUN_08001798();
  return;
}


// ===== PIN_INT2_IRQHandler @ 08001274 (8 bytes)

void PIN_INT2_IRQHandler(void)

{
  FUN_08001648();
  return;
}


// ===== PIN_INT3_IRQHandler @ 0800127c (8 bytes)

void PIN_INT3_IRQHandler(void)

{
  FUN_08001728();
  return;
}


// ===== UTICK0_IRQHandler @ 08001284 (8 bytes)

void UTICK0_IRQHandler(void)

{
  FUN_08001668();
  return;
}


// ===== MRT0_IRQHandler @ 0800128c (8 bytes)

void MRT0_IRQHandler(void)

{
  FUN_08001220();
  return;
}


// ===== CTIMER0_IRQHandler @ 08001294 (8 bytes)

void CTIMER0_IRQHandler(void)

{
  FUN_08001658();
  return;
}


// ===== CTIMER1_IRQHandler @ 0800129c (8 bytes)

void CTIMER1_IRQHandler(void)

{
  FUN_08001608();
  return;
}


// ===== SCT0_IRQHandler @ 080012a4 (8 bytes)

void SCT0_IRQHandler(void)

{
  FUN_080017f8();
  return;
}


// ===== CTIMER3_IRQHandler @ 080012ac (8 bytes)

void CTIMER3_IRQHandler(void)

{
  FUN_080016f8();
  return;
}


// ===== FLEXCOMM1_IRQHandler @ 080012b4 (8 bytes)

void FLEXCOMM1_IRQHandler(void)

{
  FUN_080016d8();
  return;
}


// ===== FLEXCOMM2_IRQHandler @ 080012bc (8 bytes)

void FLEXCOMM2_IRQHandler(void)

{
  FUN_080015d8();
  return;
}


// ===== FLEXCOMM3_IRQHandler @ 080012c4 (8 bytes)

void FLEXCOMM3_IRQHandler(void)

{
  FUN_080017e8();
  return;
}


// ===== FLEXCOMM4_IRQHandler @ 080012cc (8 bytes)

void FLEXCOMM4_IRQHandler(void)

{
  FUN_08001808();
  return;
}


// ===== FLEXCOMM5_IRQHandler @ 080012d4 (8 bytes)

void FLEXCOMM5_IRQHandler(void)

{
  FUN_080016e8();
  return;
}


// ===== FLEXCOMM14_IRQHandler @ 080012dc (8 bytes)

void FLEXCOMM14_IRQHandler(void)

{
  FUN_08001768();
  return;
}


// ===== FLEXCOMM15_IRQHandler @ 080012e4 (8 bytes)

void FLEXCOMM15_IRQHandler(void)

{
  FUN_080016a8();
  return;
}

