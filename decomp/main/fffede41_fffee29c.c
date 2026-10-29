// FT-710_MAIN_V0112.bin — Ghidra decompile, 11 functions

// ===== FUN_fffede41 @ fffede41 (153 bytes)

ulonglong FUN_fffede41(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint uVar1;
  bool bVar2;
  bool bVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  if ((param_4 & 0xffff0000) == 0) {
    if (param_4 == 0) {
      if ((param_3 & 0xffff0000) == 0) {
        if (param_2 != 0) {
          uVar6 = param_2;
          if (param_3 != 0) {
            uVar6 = param_2 / param_3;
          }
          uVar8 = param_1 >> 0x10 | (param_2 - uVar6 * param_3) * 0x10000;
          uVar9 = uVar8;
          if (param_3 != 0) {
            uVar9 = uVar8 / param_3;
          }
          uVar8 = param_1 & 0xffff | (uVar8 - uVar9 * param_3) * 0x10000;
          if (param_3 != 0) {
            uVar8 = uVar8 / param_3;
          }
          return CONCAT44(uVar6,uVar8 | uVar9 << 0x10);
        }
        if (param_1 != 0) {
          if (param_3 != 0) {
            param_1 = param_1 / param_3;
          }
          return (ulonglong)param_1;
        }
        return 0;
      }
      iVar7 = 0x20;
      uVar6 = 0;
      param_4 = param_3;
    }
    else {
      param_4 = param_4 << 0x10 | param_3 >> 0x10;
      iVar7 = 0x10;
      uVar6 = param_3 << 0x10;
    }
  }
  else {
    iVar7 = 0;
    uVar6 = param_3;
  }
  uVar8 = 0;
  uVar9 = 0;
  if ((param_4 & 0x80000000) == 0) {
    do {
      if (param_2 <= param_4) break;
      iVar7 = iVar7 + 1;
      uVar5 = uVar6 >> 0x1f;
      uVar6 = uVar6 << 1;
      param_4 = param_4 << 1 | uVar5;
    } while (-1 < (int)param_4);
  }
  do {
    bVar3 = param_1 < uVar6;
    param_1 = param_1 - uVar6;
    uVar1 = (uint)bVar3;
    uVar5 = (param_2 - param_4) - uVar1;
    bVar3 = uVar1 != 0;
    if (param_2 <= param_4 && (param_2 != param_4 || bVar3)) {
      bVar2 = CARRY4(uVar6,param_1);
      param_1 = param_1 + uVar6;
      uVar5 = uVar5 + param_4 + (uint)bVar2;
    }
    uVar4 = uVar9 >> 0x1f;
    uVar9 = uVar9 << 1 | (uint)(param_2 > param_4 || param_2 == param_4 && (!bVar3 && uVar1 == 0));
    uVar8 = uVar8 << 1 | uVar4;
    uVar6 = uVar6 >> 1 | param_4 << 0x1f;
    iVar7 = iVar7 + -1;
    param_2 = uVar5;
    param_4 = param_4 >> 1;
  } while (-1 < iVar7);
  return CONCAT44(uVar8,uVar9);
}


// ===== _INITSCT @ fffededa (74 bytes)

/* WARNING: Removing unreachable block (ram,0xfffededa) */
/* WARNING: Removing unreachable block (ram,0xfffedf21) */
/* CC-RX section init: BTBL 0xFFF8E6C4..DC zero-fill, DTBL 0xFFF8E6A0..C4 copy ROM->RAM */

void _INITSCT(void)

{
  undefined1 *puVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined **ppuVar4;
  undefined **ppuVar5;
  
  ppuVar4 = &BTBL;
  while (ppuVar4 < RelocatableVectors) {
    puVar1 = *ppuVar4;
    ppuVar5 = ppuVar4 + 1;
    ppuVar4 = ppuVar4 + 2;
    if (puVar1 < *ppuVar5) {
      for (iVar3 = (int)*ppuVar5 - (int)puVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar1 = 0;
        puVar1 = puVar1 + 1;
      }
    }
  }
  ppuVar4 = &DTBL;
  while (ppuVar4 < &BTBL) {
    puVar1 = *ppuVar4;
    ppuVar5 = ppuVar4 + 1;
    puVar2 = ppuVar4[2];
    ppuVar4 = ppuVar4 + 3;
    if (puVar1 < *ppuVar5) {
      for (iVar3 = (int)*ppuVar5 - (int)puVar1; iVar3 != 0; iVar3 = iVar3 + -1) {
        *puVar2 = *puVar1;
        puVar2 = puVar2 + 1;
        puVar1 = puVar1 + 1;
      }
    }
  }
  return;
}


// ===== fflush @ fffedf24 (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffedfa4) */
/* WARNING: Removing unreachable block (ram,0xfffedf24) */
/* fflush(fp) (fp=0: all 20 slots at 0x1FF74), writes the pending buffer with write() [inference for
   the name] */

uint fflush(ushort *param_1)

{
  undefined4 uVar1;
  uint uVar2;
  void *pvVar3;
  int iVar4;
  undefined4 *puVar5;
  int iVar6;
  uint uVar7;
  
  if (param_1 == (ushort *)0x0) {
    puVar5 = &DAT_0001ff74;
    uVar7 = 0;
    for (iVar4 = 0; iVar4 < 0x14; iVar4 = iVar4 + 1) {
      if (((ushort *)*puVar5 != (ushort *)0x0) &&
         (uVar2 = fflush((ushort *)*puVar5), (int)uVar2 < 0)) {
        uVar7 = 0xffffffff;
      }
      puVar5 = puVar5 + 1;
    }
  }
  else {
    uVar7 = 0;
    if ((*param_1 & 0x2000) != 0) {
      iVar4 = *(int *)(param_1 + 2);
      iVar6 = 0;
      while( true ) {
        pvVar3 = (void *)(iVar6 + iVar4);
        if (*(void **)(param_1 + 6) <= pvVar3) break;
        uVar7 = write((int)*(char *)((int)param_1 + 3),pvVar3,
                      (int)*(void **)(param_1 + 6) - (int)pvVar3);
        if ((int)uVar7 < 1) {
          uVar1 = *(undefined4 *)(param_1 + 2);
          *(undefined4 *)(param_1 + 6) = uVar1;
          *(undefined4 *)(param_1 + 10) = uVar1;
          *(undefined4 *)(param_1 + 0x16) = uVar1;
          *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) | 2;
          return 0xffffffff;
        }
        iVar6 = iVar6 + uVar7;
      }
      uVar1 = *(undefined4 *)(param_1 + 2);
      uVar7 = 0;
      *(undefined4 *)(param_1 + 6) = uVar1;
      *(undefined4 *)(param_1 + 10) = uVar1;
      *(undefined4 *)(param_1 + 0x16) = uVar1;
      *(byte *)((int)param_1 + 1) = *(byte *)((int)param_1 + 1) & 0xdf;
    }
  }
  return uVar7;
}


// ===== _freopen_core @ fffedfa7 (214 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee07a) */
/* WARNING: Removing unreachable block (ram,0xfffedfa7) */
/* Parses the mode string ("r"/"w"/"a", "+", "b"), calls _fopen_open, sets up the FILE [inference
   for the name] */

ushort * _freopen_core(int param_1,char *param_2,ushort *param_3,int param_4)

{
  char cVar1;
  undefined4 uVar2;
  ushort *puVar3;
  undefined1 *puVar4;
  ushort uVar5;
  int iVar7;
  int in_stack_0000000c;
  ushort uVar6;
  
  if (param_3 != (ushort *)0x0) {
    uVar6 = param_3[1];
    puVar4 = &DAT_fff8e644;
    uVar5 = *param_3;
    puVar3 = param_3;
    for (iVar7 = 0x48; iVar7 != 0; iVar7 = iVar7 + -1) {
      *(undefined1 *)puVar3 = *puVar4;
      puVar3 = (ushort *)((int)puVar3 + 1);
      puVar4 = puVar4 + 1;
    }
    *(char *)(param_3 + 1) = (char)uVar6;
    puVar3 = param_3 + 0x22;
    *(ushort **)(param_3 + 2) = puVar3;
    *(ushort **)(param_3 + 6) = puVar3;
    *(ushort **)(param_3 + 8) = puVar3;
    *(ushort **)(param_3 + 0x14) = puVar3;
    *(ushort **)(param_3 + 10) = puVar3;
    *(ushort **)(param_3 + 0x16) = puVar3;
    *(ushort **)(param_3 + 0xc) = puVar3;
    *(ushort **)(param_3 + 0xe) = param_3 + 0x12;
    cVar1 = *param_2;
    if (cVar1 == 'r') {
      uVar6 = 1;
    }
    else if (cVar1 == 'w') {
      uVar6 = 0x1a;
    }
    else {
      uVar6 = 0x16;
      if (cVar1 != 'a') {
        uVar6 = 0;
      }
    }
    uVar5 = uVar6 | uVar5 & 0x80;
    *param_3 = uVar5;
    if ((uVar6 & 3) == 0) {
      fclose(param_3);
      DAT_00025d1c = 0x16;
    }
    else {
      while( true ) {
        param_2 = param_2 + 1;
        cVar1 = *param_2;
        if ((cVar1 != 'b') && (cVar1 != '+')) break;
        if (cVar1 == 'b') {
          if ((uVar5 & 0x20) != 0) break;
          uVar5 = uVar5 | 0x20;
        }
        else {
          if ((uVar5 & 3) == 3) break;
          uVar5 = uVar5 | 3;
        }
        *param_3 = uVar5;
      }
      if (param_1 == 0) {
        if (-1 < param_4) {
          *(char *)((int)param_3 + 3) = (char)param_4;
          return param_3;
        }
      }
      else {
        if (in_stack_0000000c != 0) {
          uVar5 = uVar5 | 0x40;
        }
        iVar7 = _fopen_open(param_1,uVar5,in_stack_0000000c == 0x55);
        *(char *)((int)param_3 + 3) = (char)iVar7;
        if (-1 < iVar7) {
          return param_3;
        }
      }
      uVar2 = DAT_00025d1c;
      fclose(param_3);
      DAT_00025d1c = uVar2;
    }
  }
  return (ushort *)0x0;
}


// ===== _file_alloc @ fffee07d (69 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee07d) */
/* WARNING: Removing unreachable block (ram,0xfffee0bf) */
/* Takes a free FILE from the 20 slots at 0x1FF74 or mallocs a new 0x48-byte one; no callers (fopen
   not linked) [inference for the name] */

short * _file_alloc(void)

{
  short *psVar1;
  uint uVar2;
  undefined4 *puVar3;
  
  puVar3 = &DAT_0001ff74;
  uVar2 = 0;
  while( true ) {
    if (0x13 < uVar2) {
      return (short *)0x0;
    }
    psVar1 = (short *)*puVar3;
    if (psVar1 == (short *)0x0) break;
    if (*psVar1 == 0) {
      *psVar1 = -0x81;
      return psVar1;
    }
    puVar3 = puVar3 + 1;
    uVar2 = uVar2 + 1;
  }
  psVar1 = (short *)malloc(0x48);
  if (psVar1 == (short *)0x0) {
    return (short *)0x0;
  }
  *puVar3 = psVar1;
  *(char *)(psVar1 + 1) = (char)uVar2;
  *psVar1 = 0x80;
  return psVar1;
}


// ===== _file_release @ fffee0c2 (73 bytes)

/* Resets a static FILE (std streams) or drops a malloc'ed one from the slot table and frees it
   [inference for the name] */

void _file_release(ushort *param_1)

{
  ushort *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  
  if ((*param_1 & 0x80) == 0) {
    puVar1 = param_1 + 0x22;
    *(undefined1 *)((int)param_1 + 3) = 0xff;
    *(ushort **)(param_1 + 2) = puVar1;
    *(ushort **)(param_1 + 6) = puVar1;
    *(ushort **)(param_1 + 8) = puVar1;
    *(ushort **)(param_1 + 0x14) = puVar1;
    *(ushort **)(param_1 + 10) = puVar1;
    *(ushort **)(param_1 + 0x16) = puVar1;
    *(ushort **)(param_1 + 0xc) = puVar1;
    *param_1 = 0;
    *(ushort **)(param_1 + 0xe) = param_1 + 0x12;
    return;
  }
  uVar3 = 0;
  puVar2 = &DAT_0001ff74;
  do {
    if (0x13 < uVar3) {
LAB_fffee106:
      free();
      return;
    }
    if (param_1 == (ushort *)*puVar2) {
      *puVar2 = 0;
      goto LAB_fffee106;
    }
    puVar2 = puVar2 + 1;
    uVar3 = uVar3 + 1;
  } while( true );
}


// ===== free @ fffee10b (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee18b) */
/* free(p): 8-byte header (size, next), inserts into the address-ordered free list at 0x25E5C and
   merges neighbours [inference for the name] */

int * free(int *param_1)

{
  uint uVar1;
  uint *puVar2;
  uint *puVar3;
  uint *puVar4;
  uint *puVar5;
  
  if (param_1 != (int *)0x0) {
    puVar3 = (uint *)(param_1 + -2);
    uVar1 = *puVar3;
    if ((7 < uVar1) && ((uVar1 & 7) == 0)) {
      if ((DAT_00025e5c == (uint *)0x0) || (puVar3 < DAT_00025e5c)) {
        param_1[-1] = (int)DAT_00025e5c;
        puVar4 = puVar3;
        DAT_00025e5c = puVar3;
      }
      else {
        puVar5 = (uint *)&DAT_00025e5c;
        do {
          puVar4 = (uint *)*puVar5;
          puVar2 = (uint *)puVar4[1];
          puVar5 = puVar4 + 1;
          if (puVar3 <= puVar2) break;
        } while (puVar2 != (uint *)0x0);
        puVar5 = (uint *)(*puVar4 + (int)puVar4);
        if (puVar3 < puVar5) {
          return param_1;
        }
        if (puVar5 == puVar3) {
          *puVar4 = uVar1 + *puVar4;
        }
        else {
          if ((puVar2 != (uint *)0x0) && (puVar2 < (uint *)((int)param_1 + (uVar1 - 8)))) {
            return param_1;
          }
          param_1[-1] = (int)puVar2;
          puVar4[1] = (uint)puVar3;
          puVar4 = puVar3;
        }
      }
      param_1 = (int *)puVar4[1];
      if ((param_1 != (int *)0x0) && ((int *)((int)puVar4 + *puVar4) == param_1)) {
        DAT_00025e58 = 0;
        param_1 = (int *)puVar4[1];
        *puVar4 = *puVar4 + *param_1;
        puVar4[1] = param_1[1];
      }
    }
  }
  return param_1;
}


// ===== _fopen_open @ fffee18e (48 bytes)

/* Maps the parsed mode bits to open() flags (perm 0666, or 0600 for exclusive) and calls open
   [inference for the name] */

int _fopen_open(undefined4 param_1,uint param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(BYTE_ARRAY_fff8e648 + (param_2 & 3) * 4 + 0x44);
  if ((param_2 & 4) != 0) {
    uVar3 = uVar3 | 0x20;
  }
  if ((param_2 & 8) != 0) {
    uVar3 = uVar3 | 0x10;
  }
  if ((param_2 & 0x10) != 0) {
    uVar3 = uVar3 | 8;
  }
  uVar2 = 0x1b6;
  if (param_3 != 0) {
    uVar2 = 0x180;
  }
  cVar1 = open(param_1,uVar3,uVar2);
  return (int)cVar1;
}


// ===== _heap_find @ fffee1be (123 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee1be) */
/* WARNING: Removing unreachable block (ram,0xfffee236) */
/* First-fit search of the free list at 0x25E5C (from the rover 0x25E58); grows the heap via
   heap_getmem in >= 1 KB steps; the 244 bytes T05 saw as undefined data (#78) [inference for the
   name] */

uint * _heap_find(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  uint uVar4;
  
  do {
    puVar2 = DAT_00025e58;
    if (DAT_00025e58 == (uint *)0x0) {
      puVar2 = &DAT_00025e5c;
      while (puVar1 = (uint *)*puVar2, puVar1 != (uint *)0x0) {
        if (param_1 <= *puVar1) {
          return puVar2;
        }
        puVar2 = puVar1 + 1;
      }
    }
    else {
      while (puVar1 = (uint *)*puVar2, puVar1 != (uint *)0x0) {
        if (param_1 <= *puVar1) {
          return puVar2;
        }
        puVar2 = puVar1 + 1;
      }
      puVar2 = &DAT_00025e5c;
      while (puVar1 = (uint *)*puVar2, puVar1 != (uint *)*DAT_00025e58) {
        if (param_1 <= *puVar1) {
          return puVar2;
        }
        puVar2 = puVar1 + 1;
      }
    }
    uVar4 = 0x400;
    while( true ) {
      uVar3 = param_1;
      if (param_1 <= uVar4) {
        uVar3 = uVar4;
      }
      puVar2 = (uint *)heap_getmem(uVar3);
      if (puVar2 != (uint *)0x0) break;
      if (uVar3 == param_1) {
        return (uint *)0x0;
      }
      uVar4 = uVar3 >> 1;
    }
    *puVar2 = uVar3;
    free();
  } while( true );
}


// ===== malloc @ fffee239 (99 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee299) */
/* malloc(n): size (n+15)&~7, minimum 8, splits the block from _heap_find; only caller _file_alloc
   (unreferenced), so dead code [inference for the name] */

uint * malloc(uint param_1)

{
  uint *puVar1;
  uint *puVar2;
  uint uVar3;
  
  uVar3 = param_1 + 0xf & 0xfffffff8;
  if ((param_1 < uVar3) && (param_1 != 0)) {
    if (uVar3 < 8) {
      uVar3 = 8;
    }
    puVar2 = (uint *)_heap_find(uVar3);
    if (puVar2 != (uint *)0x0) {
      puVar1 = (uint *)*puVar2;
      if (*puVar1 - 8 < uVar3) {
        *puVar2 = puVar1[1];
      }
      else {
        *puVar2 = uVar3 + (int)puVar1;
        *(uint *)(uVar3 + (int)puVar1 + 4) = puVar1[1];
        *(uint *)*puVar2 = *puVar1 - uVar3;
        *puVar1 = uVar3;
      }
      uVar3 = *puVar2;
      if ((uVar3 == 0) || (DAT_00025e58 = uVar3 + 4, *(int *)(uVar3 + 4) == 0)) {
        DAT_00025e58 = 0;
      }
      return puVar1 + 2;
    }
  }
  return (uint *)0x0;
}


// ===== heap_getmem @ fffee29c (27 bytes)

/* sbrk wrapper: returns 0 for size < 1 or when sbrk fails [inference for the name] */

int heap_getmem(int param_1)

{
  bool bVar1;
  
  if (param_1 < 1) {
    bVar1 = false;
  }
  else {
    param_1 = sbrk();
    bVar1 = false;
    if (param_1 != -1) {
      bVar1 = true;
    }
  }
  if (!bVar1) {
    param_1 = 0;
  }
  return param_1;
}

