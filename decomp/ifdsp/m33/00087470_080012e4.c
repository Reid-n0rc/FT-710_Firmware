// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== file_clear_flag20 @ 00087470 (64 bytes)

/* FILE flags (+0xC) &= ~0x20; if +0x18 != +0x28: call file_flush_write_buffer, flags = (flags &
   ~0x3010) | 0x10, +0x18 = +0x28, +0x2C = +0 = buffer (+0x10); then flags &= ~0x4040 [fact:
   0x87470]. Callers fputc (x2) and _Cfflush1 call it only when flag 0x20 is set [fact]. Open: the
   Redlib name and the meaning of flag 0x20; would be settled by Redlib source or symbols */

void file_clear_flag20(void *param_1)

{
  *(uint *)((int)param_1 + 0xc) = *(uint *)((int)param_1 + 0xc) & 0xffffffdf;
  if (*(int *)((int)param_1 + 0x18) != *(int *)((int)param_1 + 0x28)) {
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
  uint uVar1;
  int iVar2;
  uint uVar3;
  byte *pbVar4;
  uint uVar5;
  byte *pbVar6;
  
  uVar3 = param_2[3];
  param_2[3] = uVar3 & 0xfff7ffff;
  if ((int)(uVar3 << 0x1a) < 0) {
    file_clear_flag20(param_2);
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
          file_clear_flag20(param_2);
        }
        uVar3 = param_2[3];
      }
      uVar5 = uVar3 | 0x12000;
      param_2[3] = uVar5;
      if ((uVar3 & 0xf00) == 0) {
        uVar5 = __sys_istty();
        if ((uVar5 == 0) || (-1 < (int)(uVar3 << 0x15))) {
          uVar1 = _Csys_alloc(0x100);
          param_2[7] = 0x100;
          uVar5 = uVar3 | 0x12800;
          param_2[4] = uVar1;
          *param_2 = uVar1;
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
          iVar2 = param_2[0xb] - (int)pbVar6;
        }
        else {
          iVar2 = *param_2 - (int)pbVar6;
        }
        param_2[0xc] = param_2[7];
        if (((-1 < (int)(uVar5 << 0x15)) && (uVar3 != 10)) && (iVar2 < (int)param_2[7])) {
          return uVar3;
        }
        param_2[0xb] = (uint)pbVar6;
        *param_2 = (uint)pbVar6;
        param_2[2] = 0;
        uVar5 = _Cwrite_buffer((uint)pbVar6,iVar2,(int)param_2);
        if (uVar5 == 0) {
          return uVar3;
        }
      }
      else {
        if (pbVar4 < (byte *)param_2[0xb]) {
          iVar2 = (int)param_2[0xb] - (int)pbVar6;
        }
        else {
          iVar2 = (int)pbVar4 - (int)pbVar6;
        }
        if ((iVar2 == 0) || (uVar3 = _Cwrite_buffer((uint)pbVar6,iVar2,(int)param_2), uVar3 == 0)) {
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

undefined4 _Cfclose(int param_1)

{
  uint uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined1 auStack_38 [36];
  
  uVar1 = *(uint *)(param_1 + 0xc);
  if ((uVar1 & 3) == 0) {
    uVar3 = 0xffffffff;
  }
  else {
    if (-1 < (int)(uVar1 << 0x1c)) {
      iVar2 = *(int *)(param_1 + 0x10);
      uVar3 = *(undefined4 *)(param_1 + 0x14);
      fflush();
      __sys_close(uVar3);
      if ((int)(uVar1 << 0x14) < 0) {
        free(iVar2);
      }
      if ((uVar1 & 0xffc00000) == 0xad800000) {
        __sys_tmpnam(auStack_38,*(undefined4 *)(param_1 + 0x20),0x20);
        remove((uint)auStack_38);
      }
    }
    memset(param_1,0,0x3c);
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
  int iVar1;
  
  iVar1 = strlen((uint *)param_1);
  __sys_remove(param_1,iVar1);
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


// ===== memcpy @ 000878cc (52 bytes)

void memcpy(void *param_1,void *param_2,uint param_3)

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


// ===== DefaultHandler @ 08001220 (2 bytes)

/* T23d MCUXpresso startup (idiom 0.900): the 25 weak IRQ handlers without a driver call it
   [inference] */

void DefaultHandler(void)

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
  DefaultHandler();
  return;
}


// ===== DMA0_IRQHandler @ 0800124c (8 bytes)

void DMA0_IRQHandler(void)

{
  __DMA0_DriverIRQHandler_veneer();
  return;
}


// ===== GPIO_INTA_IRQHandler @ 08001254 (8 bytes)

void GPIO_INTA_IRQHandler(void)

{
  DefaultHandler();
  return;
}


// ===== GPIO_INTB_IRQHandler @ 0800125c (8 bytes)

void GPIO_INTB_IRQHandler(void)

{
  DefaultHandler();
  return;
}


// ===== PIN_INT0_IRQHandler @ 08001264 (8 bytes)

void PIN_INT0_IRQHandler(void)

{
  __PIN_INT0_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT1_IRQHandler @ 0800126c (8 bytes)

void PIN_INT1_IRQHandler(void)

{
  __PIN_INT1_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT2_IRQHandler @ 08001274 (8 bytes)

void PIN_INT2_IRQHandler(void)

{
  __PIN_INT2_DriverIRQHandler_veneer();
  return;
}


// ===== PIN_INT3_IRQHandler @ 0800127c (8 bytes)

void PIN_INT3_IRQHandler(void)

{
  __PIN_INT3_DriverIRQHandler_veneer();
  return;
}


// ===== UTICK0_IRQHandler @ 08001284 (8 bytes)

void UTICK0_IRQHandler(void)

{
  __UTICK0_DriverIRQHandler_veneer();
  return;
}


// ===== MRT0_IRQHandler @ 0800128c (8 bytes)

void MRT0_IRQHandler(void)

{
  DefaultHandler();
  return;
}


// ===== CTIMER0_IRQHandler @ 08001294 (8 bytes)

void CTIMER0_IRQHandler(void)

{
  __CTIMER0_DriverIRQHandler_veneer();
  return;
}


// ===== CTIMER1_IRQHandler @ 0800129c (8 bytes)

void CTIMER1_IRQHandler(void)

{
  __CTIMER1_DriverIRQHandler_veneer();
  return;
}


// ===== SCT0_IRQHandler @ 080012a4 (8 bytes)

void SCT0_IRQHandler(void)

{
  __SCT0_DriverIRQHandler_veneer();
  return;
}


// ===== CTIMER3_IRQHandler @ 080012ac (8 bytes)

void CTIMER3_IRQHandler(void)

{
  __CTIMER3_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM1_IRQHandler @ 080012b4 (8 bytes)

void FLEXCOMM1_IRQHandler(void)

{
  __FLEXCOMM1_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM2_IRQHandler @ 080012bc (8 bytes)

void FLEXCOMM2_IRQHandler(void)

{
  __FLEXCOMM2_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM3_IRQHandler @ 080012c4 (8 bytes)

void FLEXCOMM3_IRQHandler(void)

{
  __FLEXCOMM3_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM4_IRQHandler @ 080012cc (8 bytes)

void FLEXCOMM4_IRQHandler(void)

{
  __FLEXCOMM4_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM5_IRQHandler @ 080012d4 (8 bytes)

void FLEXCOMM5_IRQHandler(void)

{
  __FLEXCOMM5_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM14_IRQHandler @ 080012dc (8 bytes)

void FLEXCOMM14_IRQHandler(void)

{
  __FLEXCOMM14_DriverIRQHandler_veneer();
  return;
}


// ===== FLEXCOMM15_IRQHandler @ 080012e4 (8 bytes)

void FLEXCOMM15_IRQHandler(void)

{
  __FLEXCOMM15_DriverIRQHandler_veneer();
  return;
}

