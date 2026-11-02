// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== __extendsfdf2 @ 0022b96c (100 bytes)

/* float -> double (XCC soft double); first conversion in the powf / sqrtf wrappers [inference] */

longlong __extendsfdf2(void)

{
  uint in_aed0;
  uint uVar1;
  uint uVar2;
  int iVar3;
  
  uVar2 = in_aed0 >> 0x17 & 0xff;
  uVar1 = in_aed0 & 0x80000000;
  iVar3 = in_aed0 << 1;
  if (uVar2 == 0) {
    uVar2 = 0;
    if (iVar3 != 0) {
      uVar2 = iVar3 << 0x20 - (0x20 - (LZCOUNT(iVar3) - 8U & 0x1f));
      return CONCAT44((uVar2 >> 3) + (0x37f - (LZCOUNT(iVar3) - 8U)) * 0x100000 | uVar1,
                      uVar2 << 0x1d);
    }
  }
  else {
    if (uVar2 != 0xff) {
      return CONCAT44(((in_aed0 & 0x7fffffff) >> 3) + 0x38000000 | uVar1,in_aed0 << 0x1d);
    }
    uVar2 = 0x7ff00000;
    if ((in_aed0 & 0x7fffff) != 0) {
      uVar2 = 0x7ff80000;
    }
  }
  return (ulonglong)(uVar2 | uVar1) << 0x20;
}


// ===== FUN_0022b9e0 @ 0022b9e0 (35 bytes)

void FUN_0022b9e0(undefined4 param_1,undefined4 *param_2,undefined *param_3,code *param_4,
                 int param_5)

{
  if (param_2 != (undefined4 *)0x0) {
    DAT_002cd700 = *param_2;
  }
  PTR_DAT_00237ad0 = param_3;
  if (param_4 != (code *)0x0) {
    (*param_4)();
  }
  if (param_5 != 0) {
    FUN_0022e710(param_5);
  }
  return;
}


// ===== __errno @ 0022ba10 (10 bytes)

/* newlib errno.c: &_impure_ptr->_errno (0x237F00); 10 callers [inference] */

undefined * __errno(void)

{
  return PTR_DAT_00237f00;
}


// ===== exit @ 0022ba20 (32 bytes)

/* newlib exit.c: __call_exitprocs, then _exit [inference] */

undefined4 exit(undefined4 param_1)

{
  undefined4 uVar1;
  
  __call_exitprocs(param_1,0);
  if (DAT_00237b14 != (code *)0x0) {
    (*DAT_00237b14)();
  }
  _exit(param_1);
  uVar1 = _malloc_r(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== malloc @ 0022ba40 (20 bytes)

/* newlib malloc.c: _malloc_r(_impure_ptr); called by SDK_Malloc, env_allocate_memory [inference] */

undefined4 malloc(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _malloc_r(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== free @ 0022ba60 (17 bytes)

/* newlib malloc.c: _free_r(_impure_ptr) [inference] */

void free(undefined4 param_1)

{
  _free_r(PTR_DAT_00237f00,param_1);
  return;
}


// ===== _malloc_r @ 0022ba80 (1297 bytes)

/* newlib mallocr.c (dlmalloc): __malloc_lock / __malloc_unlock, sbrk [inference] */

undefined4 * _malloc_r(undefined4 *param_1,uint param_2)

{
  uint uVar1;
  undefined *puVar2;
  undefined4 *puVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  uint uVar7;
  undefined *puVar8;
  uint uVar9;
  uint uVar10;
  undefined4 *puVar11;
  int iVar12;
  undefined *puVar13;
  undefined4 *local_50;
  uint uStack_48;
  undefined *puStack_34;
  
  if (param_2 + 0x13 < 0x1f) {
    uVar1 = 0x10;
    if (0x10 < param_2) goto LAB_0022bad6;
  }
  else {
    uVar1 = param_2 + 0x13 & 0xfffffff0;
    if (((int)uVar1 < 0) || (uVar1 < param_2)) {
LAB_0022bad6:
      *param_1 = 0xc;
      return (undefined4 *)0x0;
    }
  }
                    /* XOS clib support [doc, inference] */
  __malloc_lock(param_1);
  puVar13 = PTR_PTR_00237f30;
  if (uVar1 < 0x1f8) {
    uStack_48 = uVar1 >> 3;
    puVar2 = (&PTR_DAT_00237f2c)[uStack_48 * 2];
    if (&DAT_00237f20 + uStack_48 * 8 != puVar2) {
      uVar1 = *(uint *)(puVar2 + 4);
      iVar6 = *(int *)(puVar2 + 8);
      iVar12 = *(int *)(puVar2 + 0xc);
      uVar4 = *(uint *)(puVar2 + (uVar1 & 0xfffffffc) + 4);
      *(int *)(iVar6 + 0xc) = iVar12;
      *(int *)(iVar12 + 8) = iVar6;
      *(uint *)(puVar2 + (uVar1 & 0xfffffffc) + 4) = uVar4 | 1;
      __malloc_unlock(param_1);
      return (undefined4 *)(puVar2 + 8);
    }
    uStack_48 = uStack_48 + 2;
  }
  else {
    uStack_48 = uVar1 >> 9;
    if (uStack_48 == 0) {
      uStack_48 = uVar1 >> 3;
    }
    else if (uStack_48 < 5) {
      uStack_48 = (uVar1 >> 6) + 0x38;
    }
    else if (uStack_48 < 0x15) {
      uStack_48 = uStack_48 + 0x5b;
    }
    else if (uStack_48 < 0x55) {
      uStack_48 = (uVar1 >> 0xc) + 0x6e;
    }
    else if (uStack_48 < 0x155) {
      uStack_48 = (uVar1 >> 0xf) + 0x77;
    }
    else if (uStack_48 < 0x555) {
      uStack_48 = (uVar1 >> 0x12) + 0x7c;
    }
    else {
      uStack_48 = 0x7e;
    }
    for (puVar2 = (&PTR_DAT_00237f2c)[uStack_48 * 2]; &DAT_00237f20 + uStack_48 * 8 != puVar2;
        puVar2 = *(undefined **)(puVar2 + 0xc)) {
      uVar4 = *(uint *)(puVar2 + 4) & 0xfffffffc;
      if (0xf < (int)(uVar4 - uVar1)) {
        uStack_48 = uStack_48 - 1;
        break;
      }
      if (-1 < (int)(uVar4 - uVar1)) {
        iVar12 = *(int *)(puVar2 + 8);
        iVar6 = *(int *)(puVar2 + 0xc);
        uVar1 = *(uint *)(puVar2 + uVar4 + 4);
        *(int *)(iVar12 + 0xc) = iVar6;
        *(int *)(iVar6 + 8) = iVar12;
        *(uint *)(puVar2 + uVar4 + 4) = uVar1 | 1;
        __malloc_unlock(param_1);
        return (undefined4 *)(puVar2 + 8);
      }
    }
    uStack_48 = uStack_48 + 1;
  }
  if ((undefined **)PTR_PTR_00237f30 != &PTR_DAT_00237f28) {
    uVar4 = *(uint *)(PTR_PTR_00237f30 + 4);
    uVar5 = uVar4 & 0xfffffffc;
    uVar9 = uVar5 - uVar1;
    if (0xf < (int)uVar9) {
      *(uint *)(PTR_PTR_00237f30 + 4) = uVar1 | 1;
      puVar2 = PTR_PTR_00237f30 + uVar1;
      PTR_PTR_00237f30 = puVar2;
      PTR_PTR_00237f34 = puVar2;
      *(uint *)(puVar2 + 4) = uVar9 | 1;
      *(undefined ***)(puVar2 + 8) = &PTR_DAT_00237f28;
      *(undefined ***)(puVar2 + 0xc) = &PTR_DAT_00237f28;
      *(uint *)(puVar2 + uVar9) = uVar9;
      __malloc_unlock(param_1);
      return (undefined4 *)(puVar13 + 8);
    }
    PTR_PTR_00237f34 = (undefined *)&PTR_DAT_00237f28;
    PTR_PTR_00237f30 = (undefined *)&PTR_DAT_00237f28;
    if (-1 < (int)uVar9) {
      *(uint *)(puVar13 + uVar5 + 4) = *(uint *)(puVar13 + uVar5 + 4) | 1;
                    /* XOS clib support [doc, inference] */
      __malloc_unlock(param_1);
      return (undefined4 *)(puVar13 + 8);
    }
    if (uVar5 < 0x200) {
      uVar4 = uVar4 >> 3;
      DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar4 >> 2 & 0x1fU));
      *(undefined **)(puVar13 + 0xc) = &DAT_00237f20 + uVar4 * 8;
      puVar2 = (&PTR_DAT_00237f28)[uVar4 * 2];
      *(undefined **)(puVar13 + 8) = puVar2;
      (&PTR_DAT_00237f28)[uVar4 * 2] = puVar13;
      *(undefined **)(puVar2 + 0xc) = puVar13;
    }
    else {
      uVar9 = uVar4 >> 9;
      if (uVar9 == 0) {
        uVar9 = uVar4 >> 3;
      }
      else if (uVar9 < 5) {
        uVar9 = (uVar4 >> 6) + 0x38;
      }
      else if (uVar9 < 0x15) {
        uVar9 = uVar9 + 0x5b;
      }
      else if (uVar9 < 0x55) {
        uVar9 = (uVar4 >> 0xc) + 0x6e;
      }
      else if (uVar9 < 0x155) {
        uVar9 = (uVar4 >> 0xf) + 0x77;
      }
      else if (uVar9 < 0x555) {
        uVar9 = (uVar4 >> 0x12) + 0x7c;
      }
      else {
        uVar9 = 0x7e;
      }
      puVar8 = &DAT_00237f20 + uVar9 * 8;
      puVar2 = (&PTR_DAT_00237f28)[uVar9 * 2];
      if (puVar8 == puVar2) {
        DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar9 >> 2 & 0x1fU));
      }
      else {
        uVar4 = *(uint *)(puVar2 + 4);
        while ((uVar5 < (uVar4 & 0xfffffffc) &&
               (puVar2 = *(undefined **)(puVar2 + 8), puVar8 != puVar2))) {
          uVar4 = *(uint *)(puVar2 + 4);
        }
        puVar8 = *(undefined **)(puVar2 + 0xc);
      }
      *(undefined **)(puVar13 + 0xc) = puVar8;
      *(undefined **)(puVar13 + 8) = puVar2;
      *(undefined **)(puVar8 + 8) = puVar13;
      *(undefined **)(puVar2 + 0xc) = puVar13;
    }
  }
  puVar13 = PTR_DAT_00237f28;
  uVar4 = uStack_48 + 3;
  if (-1 < (int)uStack_48) {
    uVar4 = uStack_48;
  }
  uVar4 = 1 << 0x20 - (0x20 - ((int)uVar4 >> 2 & 0x1fU));
  if (uVar4 <= DAT_00237f24) {
    uVar5 = DAT_00237f24;
    if ((uVar4 & DAT_00237f24) == 0) {
      iVar6 = 0;
      while (uVar4 = uVar4 << 1, (uVar4 & DAT_00237f24) == 0) {
        iVar6 = iVar6 + 1;
      }
      uStack_48 = iVar6 * 4 + (uStack_48 & 0xfffffffc) + 4;
    }
    do {
      uVar9 = uStack_48;
      puVar11 = (undefined4 *)(&DAT_00237f20 + uStack_48 * 8);
      do {
        for (puVar3 = (undefined4 *)puVar11[3]; puVar3 != puVar11; puVar3 = (undefined4 *)puVar3[3])
        {
          uVar7 = puVar3[1] & 0xfffffffc;
          uVar10 = uVar7 - uVar1;
          if (0xf < (int)uVar10) {
            iVar6 = puVar3[2];
            iVar12 = puVar3[3];
            puVar3[1] = uVar1 | 1;
            *(int *)(iVar6 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar6;
            puVar13 = (undefined *)(uVar1 + (int)puVar3);
            PTR_PTR_00237f30 = puVar13;
            PTR_PTR_00237f34 = puVar13;
            *(uint *)(puVar13 + 4) = uVar10 | 1;
            *(undefined ***)(puVar13 + 8) = &PTR_DAT_00237f28;
            *(undefined ***)(puVar13 + 0xc) = &PTR_DAT_00237f28;
            *(uint *)((int)puVar3 + uVar7) = uVar10;
            __malloc_unlock(param_1);
            return puVar3 + 2;
          }
          if (-1 < (int)uVar10) {
            iVar6 = puVar3[2];
            iVar12 = puVar3[3];
            *(uint *)((int)puVar3 + uVar7 + 4) = *(uint *)((int)puVar3 + uVar7 + 4) | 1;
            *(int *)(iVar6 + 0xc) = iVar12;
            *(int *)(iVar12 + 8) = iVar6;
            __malloc_unlock(param_1);
            return puVar3 + 2;
          }
        }
        puVar3 = puVar11 + 2;
        if ((int)uVar9 < 0x3f) {
          puVar3 = puVar11 + 4;
          uVar9 = uVar9 + 1;
        }
        uVar9 = uVar9 + 1;
        puVar11 = puVar3;
        local_50 = (undefined4 *)(&DAT_00237f20 + uStack_48 * 8);
      } while ((uVar9 & 3) != 0);
      do {
        uVar7 = uStack_48 & 3;
        puVar11 = local_50 + -2;
        uStack_48 = uStack_48 - 1;
        if (uVar7 == 0) {
          uVar5 = uVar5 & (uVar4 ^ 0xffffffff);
          DAT_00237f24 = uVar5;
          break;
        }
        puVar3 = (undefined4 *)*local_50;
        local_50 = puVar11;
      } while (puVar3 == puVar11);
      uVar4 = uVar4 << 1;
      if ((uVar5 < uVar4) || (uVar4 == 0)) break;
      iVar6 = 0;
      for (; (uVar4 & uVar5) == 0; uVar4 = uVar4 << 1) {
        iVar6 = iVar6 + 1;
      }
      uStack_48 = iVar6 * 4 + uVar9;
    } while( true );
  }
  uVar4 = *(uint *)(PTR_DAT_00237f28 + 4) & 0xfffffffc;
  uVar5 = uVar4 - uVar1;
  if ((uVar1 <= uVar4) && (puStack_34 = PTR_DAT_00237f28, 0xf < (int)uVar5)) goto LAB_0022bdf6;
  puVar2 = PTR_DAT_00237f28 + uVar4;
  uVar5 = DAT_002cd708 + uVar1 + 0x10;
  if (DAT_00237f10 != (undefined *)0xffffffff) {
    uVar5 = DAT_002cd708 + uVar1 + 0x100f & 0xfffff000;
  }
                    /* heap break 0x2CD6D8 [doc, inference] */
  puStack_34 = (undefined *)_sbrk_r(param_1);
  puVar8 = DAT_002cd738;
  if ((puStack_34 == (undefined *)0xffffffff) ||
     ((puStack_34 < puVar2 && (puVar13 != &DAT_00237f20)))) {
LAB_0022bdd3:
    DAT_002cd738 = puVar8;
    uVar4 = *(uint *)(PTR_DAT_00237f28 + 4);
    puStack_34 = PTR_DAT_00237f28;
  }
  else {
    DAT_002cd70c = DAT_002cd70c + uVar5;
    if ((puStack_34 == puVar2) && (((uint)puVar2 & 0xfff) == 0)) {
      *(uint *)(PTR_DAT_00237f28 + 4) = uVar4 + uVar5 | 1;
LAB_0022bdc0:
      DAT_002cd734 = (undefined *)
                     ((uint)(DAT_002cd70c < DAT_002cd734) * (int)DAT_002cd734 +
                     (uint)(DAT_002cd70c >= DAT_002cd734) * (int)DAT_002cd70c);
      puVar8 = DAT_002cd70c;
      if (DAT_002cd70c < DAT_002cd738) {
        puVar8 = DAT_002cd738;
      }
      goto LAB_0022bdd3;
    }
    puVar8 = puStack_34;
    if (DAT_00237f10 != (undefined *)0xffffffff) {
      DAT_002cd70c = puStack_34 + ((int)DAT_002cd70c - (int)puVar2);
      puVar8 = DAT_00237f10;
    }
    DAT_00237f10 = puVar8;
    uVar9 = (uint)(puStack_34 + 8) & 0xf;
    if (uVar9 == 0) {
      iVar6 = 0;
    }
    else {
      iVar6 = 0x10 - uVar9;
      puStack_34 = puStack_34 + (0x10 - uVar9);
    }
    iVar6 = (iVar6 - ((uint)(puStack_34 + uVar5) & 0xfff)) + 0x1000;
    puVar2 = (undefined *)_sbrk_r(param_1);
    if (puVar2 == (undefined *)0xffffffff) {
      iVar6 = 0;
      puVar2 = puStack_34;
    }
    DAT_002cd70c = DAT_002cd70c + iVar6;
    PTR_DAT_00237f28 = puStack_34;
    *(uint *)(puStack_34 + 4) = (uint)(puVar2 + (iVar6 - (int)puStack_34)) | 1;
    if (puVar13 == &DAT_00237f20) goto LAB_0022bdc0;
    if (0xf < uVar4) {
      uVar4 = uVar4 - 0xc & 0xfffffff0;
      *(uint *)(puVar13 + 4) = uVar4 | *(uint *)(puVar13 + 4) & 1;
      *(undefined4 *)(puVar13 + uVar4 + 4) = 5;
      *(undefined4 *)(puVar13 + uVar4 + 8) = 5;
      if (0xf < uVar4) {
        _free_r(param_1,puVar13 + 8);
      }
      goto LAB_0022bdc0;
    }
    *(undefined4 *)(puStack_34 + 4) = 1;
    uVar4 = 0;
  }
  uVar5 = (uVar4 & 0xfffffffc) - uVar1;
  if (((uVar4 & 0xfffffffc) < uVar1) || ((int)uVar5 < 0x10)) {
    __malloc_unlock(param_1);
    return (undefined4 *)0x0;
  }
LAB_0022bdf6:
  *(uint *)(puStack_34 + 4) = uVar1 | 1;
  PTR_DAT_00237f28 = puStack_34 + uVar1;
  *(uint *)(PTR_DAT_00237f28 + 4) = uVar5 | 1;
  __malloc_unlock(param_1);
  return (undefined4 *)(puStack_34 + 8);
}


// ===== _printf_r @ 0022bfb0 (49 bytes)

/* newlib printf.c: _vfprintf_r(ptr, stdout of ptr) [inference] */

undefined4 _printf_r(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _vfprintf_r(param_1,*(undefined4 *)(param_1 + 8),param_2);
  return uVar1;
}


// ===== printf @ 0022bff0 (55 bytes)

/* newlib printf.c: _impure_ptr; called by virtqueue_dump [inference] */

undefined4 printf(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = _vfprintf_r(PTR_DAT_00237f00,*(undefined4 *)(PTR_DAT_00237f00 + 8),param_1);
  return uVar1;
}


// ===== srand @ 0022c030 (20 bytes)

/* newlib rand.c: _impure_ptr->_new._reent._rand_next [inference] */

void srand(undefined4 param_1)

{
  undefined *puVar1;
  
  puVar1 = PTR_DAT_00237f00;
  *(undefined4 *)(PTR_DAT_00237f00 + 0xa8) = param_1;
  *(undefined4 *)(puVar1 + 0xac) = 0;
  return;
}


// ===== rand @ 0022c050 (75 bytes)

/* newlib rand.c: LCG multiplier 6364136223846793005 (0x5851F42D4C957F2D) [fact for the constant] */

uint rand(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  
  puVar1 = PTR_DAT_00237f00;
  uVar2 = *(uint *)(PTR_DAT_00237f00 + 0xa8);
  uVar3 = uVar2 * 0x4c957f2d + 1;
  uVar4 = (int)((ulonglong)uVar2 * 0x4c957f2d >> 0x20) + uVar2 * 0x5851f42d +
          *(int *)(PTR_DAT_00237f00 + 0xac) * 0x4c957f2d;
  if (uVar3 < uVar2 * 0x4c957f2d) {
    *(uint *)(PTR_DAT_00237f00 + 0xa8) = uVar3;
    *(uint *)(puVar1 + 0xac) = uVar4 + 1;
    return uVar4 + 1 & 0x7fffffff;
  }
  *(uint *)(PTR_DAT_00237f00 + 0xa8) = uVar3;
  *(uint *)(puVar1 + 0xac) = uVar4;
  return uVar4 & 0x7fffffff;
}


// ===== cleanup_glue @ 0022c0a0 (30 bytes)

/* newlib reent.c static, recursive, frees the glue chain [inference] */

void cleanup_glue(undefined4 param_1,int *param_2)

{
  if (*param_2 != 0) {
    cleanup_glue(param_1);
  }
  _free_r(param_1,param_2);
  return;
}


// ===== _reclaim_reent @ 0022c0c0 (140 bytes)

/* newlib reent.c: frees the per-thread buffers; called from the XOS clib thread cleanup [inference]
    */

void _reclaim_reent(undefined *param_1)

{
  int *piVar1;
  int iVar2;
  int iVar3;
  int *piVar4;
  
  if (PTR_DAT_00237f00 != param_1) {
    iVar3 = *(int *)(param_1 + 0x4c);
    if (iVar3 != 0) {
      iVar2 = 0;
      do {
        piVar1 = *(int **)(iVar3 + iVar2);
        if (*(int **)(iVar3 + iVar2) != (int *)0x0) {
          do {
            piVar4 = (int *)*piVar1;
            _free_r(param_1,piVar1);
            piVar1 = piVar4;
          } while (piVar4 != (int *)0x0);
          iVar3 = *(int *)(param_1 + 0x4c);
        }
        iVar2 = iVar2 + 4;
      } while (iVar2 != 0x80);
      _free_r(param_1);
    }
    if (*(int *)(param_1 + 0x40) != 0) {
      _free_r(param_1);
    }
    if (*(int *)(param_1 + 0x148) != 0) {
      piVar1 = (int *)*(int *)(param_1 + 0x148);
      while ((int *)(param_1 + 0x14c) != piVar1) {
        iVar3 = *piVar1;
        _free_r(param_1,piVar1);
        piVar1 = (int *)iVar3;
      }
    }
    if (*(int *)(param_1 + 0x54) != 0) {
      _free_r(param_1);
    }
    if ((*(int *)(param_1 + 0x38) != 0) &&
       ((**(code **)(param_1 + 0x3c))(param_1), *(int *)(param_1 + 0x2e0) != 0)) {
                    /* newlib reent.c static, recursive, frees the glue chain [doc, inference] */
      cleanup_glue(param_1);
    }
  }
  return;
}


// ===== _wrapup_reent @ 0022c150 (56 bytes)

/* newlib reent.c: runs atexit functions and __cleanup [inference] */

void _wrapup_reent(undefined *param_1)

{
  int iVar1;
  int *piVar2;
  
  if (param_1 == (undefined *)0x0) {
    param_1 = PTR_DAT_00237f00;
  }
  for (piVar2 = *(int **)(param_1 + 0x148); piVar2 != (int *)0x0; piVar2 = (int *)*piVar2) {
    iVar1 = (int)(piVar2 + piVar2[1]);
    if (0 < piVar2[1]) {
      do {
        (**(code **)(iVar1 + 4))();
        iVar1 = iVar1 + -4;
      } while ((int *)iVar1 != piVar2);
    }
  }
  if (*(code **)(param_1 + 0x3c) != (code *)0x0) {
    (**(code **)(param_1 + 0x3c))(param_1);
  }
  return;
}


// ===== strcmp @ 0022c190 (328 bytes)

/* WARNING: Removing unreachable block (ram,0x0022c1e1) */
/* newlib strcmp (word-at-a-time, 0x40404040 hack); called by env_strcmp and _setlocale_r
   [inference] */

longlong strcmp(uint *param_1,uint *param_2)

{
  int unaff_retaddr;
  uint *puVar1;
  uint uVar2;
  uint uVar3;
  uint uVar4;
  uint *puVar5;
  
  uVar3 = (uint)(byte)*param_1;
  uVar4 = (uint)(byte)*param_2;
  puVar5 = param_2;
  if (uVar3 != uVar4) {
LAB_0022c1f7:
    return CONCAT44(puVar5,uVar3 - uVar4);
  }
  puVar1 = param_1;
  if ((((uint)param_1 | (uint)param_2) & 3) != 0) {
    if ((((uint)param_1 ^ (uint)param_2) & 3) != 0) {
      uVar3 = (uint)(byte)*param_1;
      uVar4 = (uint)(byte)*param_2;
      if (uVar3 == uVar4) {
        puVar5 = (uint *)((int)param_2 + 1);
      }
      goto LAB_0022c1f7;
    }
    puVar1 = (uint *)((int)param_1 + 1);
    if (uVar3 == 0) goto LAB_0022c28d;
    puVar5 = (uint *)((int)param_2 + 1);
    if (((uint)puVar1 & 3) != 0) {
      uVar3 = (uint)*(byte *)puVar1;
      uVar4 = (uint)*(byte *)puVar5;
      puVar1 = (uint *)((int)param_1 + 2);
      if (uVar3 != uVar4) goto LAB_0022c1f7;
      if (uVar3 == 0) goto LAB_0022c28d;
      puVar5 = (uint *)((int)param_2 + 2);
      if (((uint)puVar1 & 3) != 0) {
        uVar3 = (uint)*(byte *)puVar1;
        uVar4 = (uint)*(byte *)puVar5;
        puVar1 = (uint *)((int)param_1 + 3);
        if (uVar3 != uVar4) goto LAB_0022c1f7;
        if (uVar3 == 0) goto LAB_0022c28d;
        puVar5 = (uint *)((int)param_2 + 3);
      }
    }
  }
  while( true ) {
    if (unaff_retaddr == 1) {
      isync();
    }
    uVar3 = *puVar1;
    uVar4 = *puVar5;
    if (uVar3 != uVar4) goto LAB_0022c291;
    if ((~(uVar3 | uVar3 << 1) & 0x40404040) != 0) goto LAB_0022c24d;
    uVar3 = puVar1[1];
    uVar4 = puVar5[1];
    if (uVar3 != uVar4) goto LAB_0022c291;
    if ((~(uVar3 | uVar3 << 1) & 0x40404040) != 0) break;
    puVar1 = puVar1 + 2;
    puVar5 = puVar5 + 2;
  }
  puVar1 = puVar1 + 1;
  puVar5 = puVar5 + 1;
LAB_0022c24d:
  if ((((uVar3 & 0xff) != 0) && ((uVar3 & (uint)&DAT_0000ff00) != 0)) && ((uVar3 & 0xff0000) != 0))
  {
    while ((uVar3 & 0xff000000) != 0) {
      puVar5 = puVar5 + 1;
      puVar1 = puVar1 + 1;
      if (unaff_retaddr == 1) {
        isync();
      }
      uVar3 = *puVar1;
      uVar4 = *puVar5;
      if (uVar3 != uVar4) goto LAB_0022c291;
      if ((((uVar3 & 0xff) == 0) || ((uVar3 & (uint)&DAT_0000ff00) == 0)) ||
         ((uVar3 & 0xff0000) == 0)) break;
    }
  }
LAB_0022c28d:
  return ZEXT48(puVar5) << 0x20;
LAB_0022c291:
  uVar2 = uVar3 ^ uVar4;
  if ((uVar2 & 0xff) != 0) {
    return CONCAT44(puVar5,(uVar3 & 0xff) - (uVar4 & 0xff));
  }
  if ((uVar3 & 0xff) != 0) {
    if ((uVar2 & (uint)&DAT_0000ff00) != 0) {
      return CONCAT44(puVar5,(uVar3 >> 8 & 0xff) - (uVar4 >> 8 & 0xff));
    }
    if ((uVar3 & (uint)&DAT_0000ff00) != 0) {
      if ((uVar2 & 0xff0000) != 0) {
        return CONCAT44(puVar5,(uVar3 >> 0x10 & 0xff) - (uVar4 >> 0x10 & 0xff));
      }
      if ((uVar3 & 0xff0000) != 0) {
        return CONCAT44(puVar5,(uVar3 >> 0x18) - (uVar4 >> 0x18));
      }
    }
  }
  goto LAB_0022c28d;
}


// ===== strncmp @ 0022c2e0 (148 bytes)

/* newlib strncmp (0xFEFEFEFF / 0x80808080); called by env_strncmp [inference] */

int strncmp(uint *param_1,uint *param_2,uint param_3)

{
  uint uVar1;
  uint uVar2;
  
  if (param_3 == 0) {
    return 0;
  }
  if ((((((uint)param_2 | (uint)param_1) & 3) == 0) && (3 < param_3)) &&
     (uVar1 = *param_1, *param_2 == uVar1)) {
    do {
      param_3 = param_3 - 4;
      if (param_3 == 0) {
        return 0;
      }
      param_1 = param_1 + 1;
      param_2 = param_2 + 1;
      if ((uVar1 + 0xfefefeff & (uVar1 ^ 0xffffffff) & 0x80808080) != 0) {
        return 0;
      }
    } while ((3 < param_3) && (uVar1 = *param_1, *param_2 == uVar1));
  }
  uVar1 = (uint)(byte)*param_1;
  uVar2 = (uint)(byte)*param_2;
  if ((param_3 != 0) && (uVar1 == uVar2)) {
    do {
      param_3 = param_3 - 1;
      if (param_3 == 0) {
        return 0;
      }
      param_1 = (uint *)((int)param_1 + 1);
      if (uVar1 == 0) {
        return 0;
      }
      param_2 = (uint *)((int)param_2 + 1);
      if (param_3 == 0) {
        return (uint)*(byte *)param_1 - (uint)*(byte *)param_2;
      }
      uVar1 = (uint)*(byte *)param_1;
      uVar2 = (uint)*(byte *)param_2;
    } while (uVar2 == uVar1);
  }
  return uVar1 - uVar2;
}


// ===== strncpy @ 0022c3bc (175 bytes)

/* WARNING: Possible PIC construction at 0x0022c3db: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0022c49c: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0022c476: Changing call to branch */
/* WARNING: Possible PIC construction at 0x0022c3b7: Changing call to branch */
/* WARNING: Removing unreachable block (ram,0x0022c476) */
/* WARNING: Removing unreachable block (ram,0x0022c49c) */
/* WARNING: Removing unreachable block (ram,0x0022c3db) */
/* WARNING: Removing unreachable block (ram,0x0022c3b7) */
/* WARNING: Removing unreachable block (ram,0x0022c445) */
/* WARNING: Removing unreachable block (ram,0x0022c4a5) */
/* newlib strncpy; called by env_strncpy [inference] */

void strncpy(uint *param_1,uint *param_2,int param_3)

{
  char cVar1;
  uint *puVar2;
  uint uVar3;
  uint *puVar4;
  int iVar5;
  
  if (param_3 == 0) {
    return;
  }
  puVar2 = param_1;
  if (((uint)param_2 & 1) != 0) {
    uVar3 = *param_2;
    iVar5 = param_3 + -1;
    *(char *)param_1 = (char)uVar3;
    param_2 = (uint *)((int)param_2 + 1);
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)param_1 + 1);
    param_3 = iVar5;
    puVar2 = puVar4;
    if ((char)uVar3 == '\0') goto SUB_0022c3e0;
  }
  iVar5 = param_3;
  puVar4 = puVar2;
  if (((uint)param_2 & 2) != 0) {
    uVar3 = *param_2;
    iVar5 = param_3 + -1;
    *(char *)puVar2 = (char)uVar3;
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar2 + 1);
    if ((char)uVar3 == '\0') goto SUB_0022c3e0;
    cVar1 = *(char *)((int)param_2 + 1);
    iVar5 = param_3 + -2;
    *(char *)puVar4 = cVar1;
    param_2 = (uint *)((int)param_2 + 2);
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar2 + 2);
    if (cVar1 == '\0') goto SUB_0022c3e0;
  }
  if ((((uint)puVar4 & 3) != 0) || (iVar5 < 5)) {
    *(char *)puVar4 = (char)*param_2;
    if (iVar5 != 1) {
      func_0x0022c3e0(param_1,(char *)((int)param_2 + 1));
      return;
    }
    return;
  }
  uVar3 = *param_2;
  if ((uVar3 & 0xff) == 0) {
    *(char *)puVar4 = (char)uVar3;
    iVar5 = iVar5 + -1;
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  else {
    if ((uVar3 & (uint)&DAT_0000ff00) == 0) {
      *(short *)puVar4 = (short)uVar3;
      func_0x0022c3e0(param_1,param_2 + 1,iVar5 + -2);
      return;
    }
    if ((uVar3 & 0xff0000) == 0) {
      *(short *)puVar4 = (short)uVar3;
      *(char *)((int)puVar4 + 2) = '\0';
      iVar5 = iVar5 + -3;
      puVar4 = (uint *)((int)puVar4 + 3);
    }
    else {
      *puVar4 = uVar3;
      iVar5 = iVar5 + -4;
      puVar4 = puVar4 + 1;
      if ((uVar3 & 0xff000000) != 0) {
        func_0x0022c3e0(param_1,param_2 + 1);
        return;
      }
    }
  }
SUB_0022c3e0:
  if (((uint)puVar4 & 1) != 0) {
    *(char *)puVar4 = '\0';
    iVar5 = iVar5 + -1;
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar4 + 1);
  }
  if (((uint)puVar4 & 2) != 0) {
    *(char *)puVar4 = '\0';
    if (iVar5 == 1) {
      return;
    }
    *(char *)((int)puVar4 + 1) = '\0';
    iVar5 = iVar5 + -2;
    if (iVar5 == 0) {
      return;
    }
    puVar4 = (uint *)((int)puVar4 + 2);
  }
  if (3 < iVar5) {
    if (iVar5 >> 2 == 1) {
      isync();
    }
    *puVar4 = 0;
    puVar4 = puVar4 + 1;
    iVar5 = iVar5 + (iVar5 >> 2) * -4;
    if (iVar5 == 0) {
      return;
    }
  }
  do {
    *(char *)puVar4 = '\0';
    iVar5 = iVar5 + -1;
    puVar4 = (uint *)((int)puVar4 + 1);
  } while (iVar5 != 0);
  return;
}


// ===== __sbprintf @ 0022c4d0 (175 bytes)

/* newlib vfprintf.c: unbuffered-stream helper (vfprintf into a stack buffer, fflush) [inference] */

int __sbprintf(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4,
              undefined4 param_5,undefined4 param_6)

{
  int iVar1;
  int iVar2;
  undefined1 *apuStack_4b0 [2];
  undefined4 uStack_4a8;
  ushort uStack_4a4;
  undefined2 uStack_4a2;
  undefined1 *puStack_4a0;
  undefined4 uStack_49c;
  undefined4 uStack_498;
  undefined4 uStack_494;
  undefined4 uStack_48c;
  undefined4 uStack_44c;
  undefined1 auStack_440 [1036];
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  
  uStack_4a8 = 0x400;
  uStack_49c = 0x400;
  apuStack_4b0[0] = auStack_440;
  uStack_494 = *(undefined4 *)(param_2 + 0x1c);
  uStack_4a2 = *(undefined2 *)(param_2 + 0xe);
  uStack_4a4 = *(ushort *)(param_2 + 0xc) & 0xfffd;
  uStack_48c = *(undefined4 *)(param_2 + 0x24);
  uStack_44c = *(undefined4 *)(param_2 + 100);
  uStack_498 = 0;
  puStack_4a0 = apuStack_4b0[0];
  uStack_34 = param_4;
  uStack_30 = param_5;
  uStack_2c = param_6;
  iVar1 = _vfprintf_r(param_1,apuStack_4b0,param_3,param_4,param_5,param_6);
  if ((-1 < iVar1) && (iVar2 = _fflush_r(param_1,apuStack_4b0), iVar2 != 0)) {
    iVar1 = -1;
  }
  if (((uint)(int)(short)uStack_4a4 >> 6 & 1) != 0) {
    *(ushort *)(param_2 + 0xc) = *(ushort *)(param_2 + 0xc) | 0x40;
    return iVar1;
  }
  return iVar1;
}


// ===== vfprintf @ 0022c590 (31 bytes)

/* newlib vfprintf.c: _vfprintf_r(_impure_ptr) [inference] */

undefined4
vfprintf(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
        undefined4 param_5)

{
  undefined4 uVar1;
  
  uVar1 = _vfprintf_r(PTR_DAT_00237f00,param_1,param_2,param_3,param_4,param_5);
  return uVar1;
}


// ===== _vfprintf_r @ 0022c5b0 (8131 bytes)

/* WARNING: Removing unreachable block (ram,0x0022cf03) */
/* WARNING: Removing unreachable block (ram,0x0022dc42) */
/* WARNING: Removing unreachable block (ram,0x0022ddc8) */
/* WARNING: Removing unreachable block (ram,0x0022d1f8) */
/* WARNING: Removing unreachable block (ram,0x0022d308) */
/* WARNING: Removing unreachable block (ram,0x0022e1d5) */
/* WARNING: Removing unreachable block (ram,0x0022e149) */
/* WARNING: Removing unreachable block (ram,0x0022e104) */
/* WARNING: Removing unreachable block (ram,0x0022cfd6) */
/* WARNING: Removing unreachable block (ram,0x0022dc06) */
/* WARNING: Removing unreachable block (ram,0x0022e222) */
/* WARNING: Removing unreachable block (ram,0x0022e4cf) */
/* WARNING: Removing unreachable block (ram,0x0022d49e) */
/* WARNING: Removing unreachable block (ram,0x0022e245) */
/* WARNING: Removing unreachable block (ram,0x0022e233) */
/* WARNING: Removing unreachable block (ram,0x0022dc12) */
/* WARNING: Removing unreachable block (ram,0x0022e5ef) */
/* WARNING: Removing unreachable block (ram,0x0022e5f7) */
/* WARNING: Removing unreachable block (ram,0x0022e4e1) */
/* WARNING: Type propagation algorithm not settling */
/* newlib vfprintf.c (8,320 bytes): __sinit, __swsetup_r, __sprint_r, _dtoa_r, _localeconv_r, strlen
   [inference] */

char * _vfprintf_r(int param_1,int param_2,byte *param_3,int param_4,int param_5,int param_6)

{
  bool bVar1;
  char cVar2;
  char cVar3;
  char **ppcVar4;
  undefined4 uVar5;
  char *pcVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  char *pcVar10;
  char *pcVar11;
  undefined4 uVar12;
  undefined4 uVar13;
  int iVar14;
  int iVar15;
  uint uVar16;
  undefined4 uVar17;
  undefined **ppuVar18;
  char *pcVar19;
  char *pcVar20;
  char *pcVar21;
  uint uVar22;
  int iVar23;
  int iVar24;
  char *pcVar25;
  char *pcVar26;
  int iVar27;
  int iVar28;
  uint uVar29;
  int iVar30;
  int iVar31;
  int iVar32;
  char cVar33;
  int *piVar34;
  int iVar35;
  char *pcVar36;
  int iVar37;
  undefined **ppuVar38;
  int iVar39;
  int iVar40;
  char *pcVar41;
  uint uVar42;
  int *piVar43;
  byte *pbVar44;
  int iVar45;
  undefined4 uVar46;
  byte bVar47;
  char *pcVar48;
  char *pcVar49;
  uint uVar50;
  uint uVar51;
  uint uVar52;
  uint uVar53;
  undefined **ppuVar54;
  int iVar55;
  char *pcVar56;
  char *pcVar57;
  longlong lVar58;
  int local_1b0 [16];
  int *piStack_170;
  int iStack_16c;
  int iStack_168;
  undefined1 auStack_160 [39];
  char cStack_139;
  undefined *apuStack_138 [3];
  char cStack_129;
  char acStack_128 [4];
  char acStack_124 [4];
  undefined1 uStack_120;
  undefined1 uStack_11f;
  byte abStack_11e [6];
  undefined4 uStack_118;
  uint uStack_114;
  char *pcStack_110;
  undefined1 auStack_10c [4];
  char *pcStack_108;
  char *pcStack_104;
  int iStack_100;
  int iStack_fc;
  int iStack_f8;
  int iStack_f4;
  uint uStack_f0;
  undefined4 uStack_ec;
  char *pcStack_e8;
  uint uStack_e4;
  undefined **ppuStack_e0;
  int iStack_dc;
  char *pcStack_d8;
  char *pcStack_d4;
  char *pcStack_d0;
  char *pcStack_cc;
  undefined **ppuStack_c8;
  int iStack_c4;
  undefined4 uStack_c0;
  undefined4 uStack_bc;
  int iStack_b8;
  char *pcStack_b4;
  int iStack_b0;
  uint uStack_ac;
  uint uStack_a8;
  undefined4 uStack_a4;
  undefined **ppuStack_a0;
  int iStack_9c;
  uint uStack_98;
  uint uStack_94;
  undefined **ppuStack_90;
  char *pcStack_8c;
  char *pcStack_88;
  char *pcStack_84;
  char *pcStack_80;
  char *pcStack_7c;
  char *pcStack_78;
  uint uStack_74;
  uint uStack_70;
  int iStack_6c;
  int iStack_68;
  char *pcStack_64;
  char *pcStack_60;
  int iStack_58;
  int iStack_54;
  uint uStack_50;
  byte *pbStack_4c;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  
  iStack_6c = param_1;
  iStack_68 = param_2;
  iStack_34 = param_4;
  iStack_30 = param_5;
  iStack_2c = param_6;
  piVar34 = (int *)_localeconv_r(param_1);
  iVar37 = *piVar34;
  iStack_b0 = strlen(iVar37);
  uStack_a8 = 0;
  uStack_a4 = 0;
  if ((iStack_6c != 0) && (*(int *)(iStack_6c + 0x38) == 0)) {
    __sinit(iStack_6c);
  }
  uVar42 = (uint)*(short *)(iStack_68 + 0xc);
  if ((uVar42 >> 0xd & 1) == 0) {
    uVar42 = uVar42 | (uint)&DAT_00002000;
    *(short *)(iStack_68 + 0xc) = (short)uVar42;
    *(uint *)(iStack_68 + 100) = *(uint *)(iStack_68 + 100) & 0xffffdfff;
  }
  if (((uVar42 >> 3 & 1) == 0) || (*(int *)(iStack_68 + 0x10) == 0)) {
    iVar35 = __swsetup_r(iStack_6c,iStack_68);
    if (iVar35 != 0) {
      return (char *)0xffffffff;
    }
    uVar42 = (uint)*(short *)(iStack_68 + 0xc);
  }
  iStack_f8 = iVar37;
  iStack_fc = param_5;
  iStack_100 = param_4;
  if ((uVar42 & 0x1a) == 10) {
    if (-1 < *(short *)(iStack_68 + 0xe)) {
      pcVar48 = (char *)__sbprintf(iStack_6c,iStack_68,param_3,iStack_34,iStack_30,iStack_2c);
      return pcVar48;
    }
  }
  iStack_b8 = param_6;
  iStack_168 = 0;
  iStack_16c = 0;
  piVar34 = local_1b0;
  pcStack_78 = (char *)0x0;
  iStack_c4 = 0;
  pcStack_80 = (char *)0xffffffff;
  uStack_bc = 0;
  iStack_9c = 0;
  uStack_c0 = 0;
  ppuStack_a0 = apuStack_138;
  ppuStack_c8 = (undefined **)&cStack_139;
  pcStack_cc = &cStack_129;
  pcStack_d4 = acStack_124;
  pcStack_d0 = acStack_128 + 2;
  piStack_170 = piVar34;
LAB_0022c6a7:
  iVar37 = 0;
  if (*param_3 != 0) {
    if (*param_3 != 0x25) {
      do {
        iVar37 = iVar37 + 1;
        pbVar44 = param_3 + iVar37;
        bVar47 = *pbVar44;
        if (bVar47 == 0) break;
      } while (bVar47 != 0x25);
      if (iVar37 != 0) {
        *piVar34 = (int)param_3;
        piVar34[1] = iVar37;
        iStack_168 = iStack_168 + iVar37;
        iStack_16c = iStack_16c + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          pbStack_4c = pbVar44;
          iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          if (iVar35 != 0) goto LAB_0022c8a9;
          piVar34 = local_1b0;
          pbVar44 = pbStack_4c;
        }
        pcStack_78 = pcStack_78 + iVar37;
        bVar47 = *pbVar44;
      }
      param_3 = pbVar44;
      if (bVar47 == 0) goto LAB_0022cc3b;
    }
    param_3 = param_3 + 1;
    uVar42 = 0;
    abStack_11e[0] = 0;
    pcStack_7c = (char *)0x0;
    uStack_74 = 0;
    pcVar48 = (char *)0xffffffff;
LAB_0022c718:
    uStack_70 = (uint)*param_3;
    param_3 = param_3 + 1;
LAB_0022c721:
    iVar37 = iStack_16c;
    iVar35 = iStack_168;
    switch(uStack_70) {
    case 0x20:
      goto switchD_0022c735_caseD_20;
    default:
      if (uStack_70 == 0) break;
      abStack_11e[0] = 0;
      pcStack_84 = (char *)0x1;
      ppuStack_90 = (undefined **)auStack_160;
      auStack_160[0] = (char)uStack_70;
LAB_0022c755:
      uVar42 = (uint)abStack_11e[0];
LAB_0022c758:
      pcStack_b4 = (char *)0x0;
      pcStack_8c = (char *)0x0;
      goto LAB_0022c763;
    case 0x23:
      uStack_74 = uStack_74 | 1;
      goto LAB_0022c718;
    case 0x2a:
      iVar35 = iStack_b8 + 4;
      iStack_b8 = iVar35;
      iVar37 = iStack_fc;
      if ((0x18 < iVar35) && (iStack_b8 = 0x24, iVar37 = iStack_100, 0x1c < iVar35)) {
        iStack_b8 = iVar35;
      }
      pcStack_7c = *(char **)(iStack_b8 + iVar37 + -4);
      if (-1 < (int)pcStack_7c) goto LAB_0022c718;
      pcStack_7c = (char *)-(int)pcStack_7c;
    case 0x2d:
      uStack_74 = uStack_74 | 4;
      goto LAB_0022c718;
    case 0x2b:
      uVar42 = 0x2b;
      abStack_11e[0] = 0x2b;
      goto LAB_0022c718;
    case 0x2e:
      uStack_70 = (uint)*param_3;
      param_3 = param_3 + 1;
      if (uStack_70 == 0x2a) {
        iVar35 = iStack_b8 + 4;
        iStack_b8 = iVar35;
        iVar37 = iStack_fc;
        if ((0x18 < iVar35) && (iStack_b8 = 0x24, iVar37 = iStack_100, 0x1c < iVar35)) {
          iStack_b8 = iVar35;
        }
        iVar37 = *(int *)(iStack_b8 + iVar37 + -4);
        pcVar48 = (char *)((uint)((int)pcStack_80 < iVar37) * iVar37 +
                          (uint)((int)pcStack_80 >= iVar37) * (int)pcStack_80);
        goto LAB_0022c718;
      }
      iVar37 = 0;
      if (uStack_70 - 0x30 < 10) {
        iVar35 = 0;
        do {
          pbVar44 = param_3 + iVar37;
          iVar35 = iVar35 * 10 + uStack_70;
          iVar37 = iVar37 + 1;
          uStack_70 = (uint)*pbVar44;
          iVar35 = iVar35 + -0x30;
        } while (*pbVar44 - 0x30 < 10);
      }
      else {
        iVar35 = 0;
      }
      param_3 = param_3 + iVar37;
      pcVar48 = (char *)((uint)(iVar35 < (int)pcStack_80) * (int)pcStack_80 +
                        (uint)(iVar35 >= (int)pcStack_80) * iVar35);
      goto LAB_0022c721;
    case 0x30:
      uStack_74 = uStack_74 | 0x80;
      goto LAB_0022c718;
    case 0x31:
    case 0x32:
    case 0x33:
    case 0x34:
    case 0x35:
    case 0x36:
    case 0x37:
    case 0x38:
    case 0x39:
      goto switchD_0022c735_caseD_31;
    case 0x44:
      uStack_74 = uStack_74 | 0x10;
      goto switchD_0022c735_caseD_64;
    case 0x45:
    case 0x47:
    case 0x65:
    case 0x66:
    case 0x67:
      uVar42 = iStack_b8 + 7U & 0xfffffff8;
      iVar37 = uVar42 + 8;
      iStack_b8 = iVar37;
      if ((uStack_74 >> 3 & 1) == 0) {
        iVar35 = iStack_fc;
        if ((0x10 < (int)uVar42) && (iStack_b8 = 0x28, iVar35 = iStack_100, 0x18 < (int)uVar42)) {
          iStack_b8 = iVar37;
        }
        uStack_a8 = *(uint *)(iStack_b8 + iVar35 + -4);
        uStack_a4 = *(undefined4 *)(iStack_b8 + iVar35 + -8);
      }
      else {
        iVar35 = iStack_fc;
        if ((0x10 < (int)uVar42) && (iStack_b8 = 0x28, iVar35 = iStack_100, 0x18 < (int)uVar42)) {
          iStack_b8 = iVar37;
        }
        uStack_a8 = *(uint *)(iStack_b8 + iVar35 + -4);
        uStack_a4 = *(undefined4 *)(iStack_b8 + iVar35 + -8);
      }
      uVar5 = uStack_a4;
      uStack_e4 = uStack_a8;
      pcStack_64 = pcVar48;
      iVar37 = FUN_00230d10();
      if (iVar37 == 1) {
        iVar37 = FUN_0022b838(uVar5,uStack_e4,uStack_bc,uStack_c0);
        uVar42 = (uint)abStack_11e[0];
        if (iVar37 < 0) {
          uVar42 = 0x2d;
        }
        abStack_11e[0] = (byte)uVar42;
        if ((int)uStack_70 < 0x48) {
          ppuStack_90 = &PTR_DAT_00206424;
        }
        else {
          ppuStack_90 = (undefined **)0x206428;
        }
        pcStack_84 = (char *)0x3;
        uStack_74 = uStack_74 & 0xffffff7f;
        goto LAB_0022c758;
      }
      iVar37 = FUN_00230d10(uVar5,uStack_e4);
      if (iVar37 == 0) {
        if ((int)uStack_70 < 0x48) {
          ppuStack_90 = (undefined **)0x20642c;
        }
        else {
          ppuStack_90 = (undefined **)0x206430;
        }
        pcStack_84 = (char *)0x3;
        uStack_74 = uStack_74 & 0xffffff7f;
        goto LAB_0022c755;
      }
      pcStack_d8 = pcStack_64;
      if (pcStack_64 == (char *)0xffffffff) {
        pcStack_104 = (char *)0x6;
      }
      else {
        pcStack_104 = pcStack_64;
        if (((uStack_70 == 0x67) || (uStack_70 == 0x47)) && (pcStack_64 == (char *)0x0)) {
          pcStack_104 = (char *)0x1;
        }
      }
      uStack_118 = uVar5;
      uStack_114 = uStack_e4;
      uStack_f0 = uStack_e4;
      uStack_74 = uStack_74 | 0x100;
      if ((int)uStack_e4 < 0) {
        iStack_f4 = 0x2d;
        uStack_f0 = uStack_e4 ^ 0x80000000;
      }
      else {
        iStack_f4 = 0;
      }
      uStack_ec = uVar5;
      pcStack_e8 = pcStack_104;
      if ((uStack_70 == 0x66) || (uStack_70 == 0x46)) {
        uVar46 = 3;
      }
      else {
        if ((uStack_70 == 0x65) || (uStack_70 == 0x45)) {
          pcStack_e8 = pcStack_104 + 1;
        }
        uVar46 = 2;
      }
      ppuStack_e0 = (undefined **)
                    _dtoa_r(iStack_6c,pcStack_104,uVar5,uStack_f0,uVar46,pcStack_e8,&pcStack_110,
                            auStack_10c,&pcStack_108);
      if (((uStack_70 == 0x67) || (uStack_70 == 0x47)) && ((uStack_74 & 1) == 0)) {
        iStack_9c = (int)pcStack_108 - (int)ppuStack_e0;
        ppuVar54 = ppuStack_e0;
        uVar5 = uStack_118;
        uVar51 = uStack_114;
        pcVar36 = pcStack_108;
        pcVar48 = pcStack_104;
        iVar37 = iStack_100;
        iVar35 = iStack_fc;
        iVar55 = iStack_f8;
        iVar45 = iStack_f4;
        uVar50 = uStack_f0;
        uVar46 = uStack_ec;
        pcVar6 = pcStack_e8;
        uVar52 = uStack_e4;
        iVar7 = iStack_dc;
        pcVar8 = pcStack_d8;
        pcVar9 = pcStack_d4;
        pcVar10 = pcStack_d0;
        pcVar11 = pcStack_cc;
        ppuVar38 = ppuStack_c8;
        uVar12 = uStack_c0;
        uVar13 = uStack_bc;
        iVar14 = iStack_b8;
        iVar15 = iStack_b0;
        uVar53 = uStack_ac;
        uVar16 = uStack_a8;
        uVar17 = uStack_a4;
        ppuVar18 = ppuStack_a0;
        pcVar19 = pcStack_80;
        pcVar20 = pcStack_7c;
        pcVar21 = pcStack_78;
        uVar22 = uStack_74;
        iVar23 = iStack_6c;
        iVar24 = iStack_68;
        pcVar25 = pcStack_64;
        pcVar26 = pcStack_60;
        iVar27 = iStack_58;
        iVar28 = iStack_54;
        uVar29 = uStack_50;
        pbVar44 = pbStack_4c;
        iVar30 = iStack_34;
        iVar31 = iStack_30;
        iVar32 = iStack_2c;
      }
      else {
        pcVar48 = (char *)((int)ppuStack_e0 + (int)pcStack_e8);
        if ((uStack_70 == 0x66) || (uStack_70 == 0x46)) {
          pcStack_60 = pcVar48;
          if ((*(char *)ppuStack_e0 == '0') &&
             (iVar37 = FUN_0022b874(uStack_ec,uStack_f0,uStack_bc,uStack_c0), iVar37 != 0)) {
            pcStack_110 = (char *)(1 - (int)pcStack_e8);
          }
          pcVar48 = pcStack_60 + (int)pcStack_110;
        }
        iVar37 = FUN_0022b874(uStack_ec,uStack_f0,uStack_bc,uStack_c0);
        pcVar36 = pcStack_108;
        if (iVar37 == 0) {
          pcVar36 = pcVar48;
        }
        pcStack_108 = pcVar36;
        while (pcVar36 < pcVar48) {
          *pcVar36 = '0';
          pcVar36 = pcVar36 + 1;
          pcStack_108 = pcVar36;
        }
        iStack_9c = (int)pcVar36 - (int)ppuStack_e0;
        ppuVar54 = ppuStack_e0;
        uVar5 = uStack_118;
        uVar51 = uStack_114;
        pcVar48 = pcStack_104;
        iVar37 = iStack_100;
        iVar35 = iStack_fc;
        iVar55 = iStack_f8;
        iVar45 = iStack_f4;
        uVar50 = uStack_f0;
        uVar46 = uStack_ec;
        pcVar6 = pcStack_e8;
        uVar52 = uStack_e4;
        iVar7 = iStack_dc;
        pcVar8 = pcStack_d8;
        pcVar9 = pcStack_d4;
        pcVar10 = pcStack_d0;
        pcVar11 = pcStack_cc;
        ppuVar38 = ppuStack_c8;
        uVar12 = uStack_c0;
        uVar13 = uStack_bc;
        iVar14 = iStack_b8;
        iVar15 = iStack_b0;
        uVar53 = uStack_ac;
        uVar16 = uStack_a8;
        uVar17 = uStack_a4;
        ppuVar18 = ppuStack_a0;
        pcVar19 = pcStack_80;
        pcVar20 = pcStack_7c;
        pcVar21 = pcStack_78;
        uVar22 = uStack_74;
        iVar23 = iStack_6c;
        iVar24 = iStack_68;
        pcVar25 = pcStack_64;
        pcVar26 = pcStack_60;
        iVar27 = iStack_58;
        iVar28 = iStack_54;
        uVar29 = uStack_50;
        pbVar44 = pbStack_4c;
        iVar30 = iStack_34;
        iVar31 = iStack_30;
        iVar32 = iStack_2c;
      }
      if ((uStack_70 == 0x67) || (iVar39 = iStack_9c, uStack_70 == 0x47)) {
        if (((int)pcStack_110 < -3) || ((int)pcVar48 < (int)pcStack_110)) {
          uStack_70 = uStack_70 - 2;
          iVar39 = iStack_9c;
          goto joined_r0x0022db91;
        }
        uStack_70 = 0x67;
        if (iStack_9c <= (int)pcStack_110) goto LAB_0022dba6;
LAB_0022dbc3:
        if ((int)pcStack_110 < 1) {
          iVar39 = 2 - (int)pcStack_110;
        }
        else {
          iVar39 = 1;
        }
        pcStack_84 = (char *)(iVar39 + iStack_9c);
LAB_0022dbd0:
        pcStack_b4 = pcStack_110;
      }
      else {
joined_r0x0022db91:
        iStack_9c = iVar39;
        if (0x65 < (int)uStack_70) {
          if (uStack_70 == 0x66) {
            if ((int)pcStack_110 < 1) {
              if ((pcVar48 == (char *)0x0) && ((uVar22 & 1) == 0)) {
                pcStack_84 = (char *)0x1;
              }
              else {
                pcStack_84 = (char *)((int)pcVar48 + 2);
              }
            }
            else {
              pcStack_84 = pcStack_110;
              if ((pcVar48 != (char *)0x0) || ((uVar22 & 1) != 0)) {
                pcStack_84 = (char *)((int)pcVar48 + (int)pcStack_110) + 1;
              }
            }
          }
          else {
            if ((int)pcStack_110 < iVar39) goto LAB_0022dbc3;
LAB_0022dba6:
            pcStack_84 = pcStack_110;
            if ((uVar22 & 1) != 0) {
              pcStack_84 = (char *)((int)pcStack_110 + 1);
            }
          }
          goto LAB_0022dbd0;
        }
        acStack_128[0] = (char)uStack_70;
        pcVar56 = (char *)((int)pcStack_110 + -1);
        pcStack_110 = pcVar56;
        if ((int)pcVar56 < 0) {
          acStack_128[1] = 0x2d;
          pcVar56 = (char *)-(int)pcVar56;
        }
        else {
          acStack_128[1] = 0x2b;
        }
        pcVar57 = pcVar11;
        if ((int)pcVar56 < 10) {
          acStack_128[3] = (char)pcVar56 + '0';
          acStack_128[2] = '0';
          pcVar56 = pcVar9;
        }
        else {
          do {
            pcVar49 = pcVar57;
            iVar40 = (int)pcVar56 % 10;
            pcVar56 = (char *)((int)pcVar56 / 10);
            pcVar57 = pcVar49 + -1;
            *pcVar57 = (char)iVar40 + '0';
          } while (9 < (int)pcVar56);
          pcVar49[-2] = (char)pcVar56 + '0';
          if (pcVar49 + -2 < pcVar11) {
            pcVar41 = acStack_128;
            bVar1 = ((uint)(acStack_128 + -(int)pcVar57) & 7) != 0;
            pcVar56 = pcVar57;
            if (bVar1) {
              pcVar41 = acStack_128 + 1;
              acStack_128[2] = pcVar49[-2];
              pcVar56 = pcVar49;
            }
            uVar42 = (uint)bVar1;
            if ((uint)(acStack_128 + -(int)pcVar57) >> 3 != 0) {
              cVar33 = pcVar56[1];
              cVar2 = pcVar56[2];
              pcVar41[3] = *pcVar56;
              cVar3 = pcVar56[3];
              pcVar41[4] = cVar33;
              cVar33 = pcVar56[4];
              pcVar41[5] = cVar2;
              cVar2 = pcVar56[5];
              pcVar41[6] = cVar3;
              cVar3 = pcVar56[6];
              pcVar41[7] = cVar33;
              uVar42 = uVar42 + 8;
              pcVar41[8] = cVar2;
              cVar33 = pcVar56[-1];
              pcVar41[9] = cVar3;
              pcVar41[2] = cVar33;
            }
          }
          else {
            uVar42 = 0;
          }
          pcVar56 = (char *)((int)pcVar10 + uVar42);
        }
        iStack_c4 = (int)pcVar56 - (int)acStack_128;
        pcStack_84 = (char *)(((int)pcVar56 - (int)acStack_128) + iVar39);
        if ((1 < iVar39) || ((uVar22 & 1) != 0)) {
          pcStack_84 = pcStack_84 + 1;
        }
        pcStack_b4 = (char *)0x0;
      }
      uVar42 = (uint)abStack_11e[0];
      ppuStack_90 = ppuVar54;
      pcStack_8c = (char *)0x0;
      if (iVar45 != 0) {
        uVar42 = 0x2d;
      }
      abStack_11e[0] = (byte)uVar42;
      uStack_118 = uVar5;
      uStack_114 = uVar51;
      pcStack_108 = pcVar36;
      pcStack_104 = pcVar48;
      iStack_100 = iVar37;
      iStack_fc = iVar35;
      iStack_f8 = iVar55;
      iStack_f4 = iVar45;
      uStack_f0 = uVar50;
      uStack_ec = uVar46;
      pcStack_e8 = pcVar6;
      uStack_e4 = uVar52;
      ppuStack_e0 = ppuVar54;
      iStack_dc = iVar7;
      pcStack_d8 = pcVar8;
      pcStack_d4 = pcVar9;
      pcStack_d0 = pcVar10;
      pcStack_cc = pcVar11;
      ppuStack_c8 = ppuVar38;
      uStack_c0 = uVar12;
      uStack_bc = uVar13;
      iStack_b8 = iVar14;
      iStack_b0 = iVar15;
      uStack_ac = uVar53;
      uStack_a8 = uVar16;
      uStack_a4 = uVar17;
      ppuStack_a0 = ppuVar18;
      pcStack_80 = pcVar19;
      pcStack_7c = pcVar20;
      pcStack_78 = pcVar21;
      uStack_74 = uVar22;
      iStack_6c = iVar23;
      iStack_68 = iVar24;
      pcStack_64 = pcVar25;
      pcStack_60 = pcVar26;
      iStack_58 = iVar27;
      iStack_54 = iVar28;
      uStack_50 = uVar29;
      pbStack_4c = pbVar44;
      iStack_34 = iVar30;
      iStack_30 = iVar31;
      iStack_2c = iVar32;
      goto LAB_0022c763;
    case 0x4c:
      uStack_74 = uStack_74 | 8;
      goto LAB_0022c718;
    case 0x4f:
      uStack_74 = uStack_74 | 0x10;
    case 0x6f:
      if ((uStack_74 >> 5 & 1) == 0) {
        if ((uStack_74 >> 4 & 1) == 0) {
          if ((uStack_74 >> 6 & 1) == 0) {
            iVar45 = iStack_b8 + 4;
            iStack_b8 = iVar45;
            iVar55 = iStack_fc;
            if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
              iStack_b8 = iVar45;
            }
            uVar42 = *(uint *)(iStack_b8 + iVar55 + -4);
            uVar51 = 0;
          }
          else {
            iVar45 = iStack_b8 + 4;
            iStack_b8 = iVar45;
            iVar55 = iStack_fc;
            if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
              iStack_b8 = iVar45;
            }
            uVar42 = (uint)*(ushort *)(iStack_b8 + iVar55 + -4);
            uVar51 = 0;
          }
        }
        else {
          iVar45 = iStack_b8 + 4;
          iStack_b8 = iVar45;
          iVar55 = iStack_fc;
          if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
            iStack_b8 = iVar45;
          }
          uVar42 = *(uint *)(iStack_b8 + iVar55 + -4);
          uVar51 = 0;
        }
      }
      else {
        uVar42 = iStack_b8 + 7U & 0xfffffff8;
        iStack_b8 = uVar42 + 8;
        iVar55 = iStack_fc;
        if ((0x10 < (int)uVar42) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar42)) {
          iStack_b8 = uVar42 + 8;
        }
        uVar51 = *(uint *)(iStack_b8 + iVar55 + -4);
        uVar42 = *(uint *)(iStack_b8 + iVar55 + -8);
      }
      abStack_11e[0] = 0;
      uVar50 = uStack_74;
      if (-1 < (int)pcVar48) {
        uVar50 = uStack_74 & 0xffffff7f;
      }
      uStack_74 = uVar50;
      if ((uVar42 == 0 && uVar51 == 0) && (pcVar48 == (char *)0x0)) {
        ppuStack_90 = ppuStack_a0;
        uStack_98 = uVar50 & 0x84;
        uStack_94 = 0;
        if ((uVar50 & 1) == 0) {
          pcStack_84 = (char *)0x0;
          pcStack_8c = pcVar48;
          pcStack_88 = (char *)0x0;
joined_r0x0022dc21:
          pcStack_88 = (char *)0x0;
          uStack_94 = 0;
          pcStack_84 = (char *)0x0;
          ppuStack_90 = ppuStack_a0;
          pcVar36 = pcStack_7c;
          if ((uStack_74 & 0x84) == 0) goto joined_r0x0022e60f;
          goto LAB_0022d210;
        }
        pcStack_84 = (char *)0x1;
        pcStack_8c = pcVar48;
        cStack_139 = '0';
        ppuStack_90 = ppuStack_c8;
        pcStack_88 = (char *)0x1;
        if ((uVar50 & 0x84) != 0) goto LAB_0022d210;
        pcVar36 = pcStack_7c + -1;
joined_r0x0022d31d:
        uStack_94 = 0;
        pcStack_84 = (char *)0x1;
        ppuStack_90 = ppuStack_c8;
      }
      else {
        pcStack_8c = pcVar48;
        ppuVar54 = ppuStack_a0;
        do {
          ppuVar38 = ppuVar54;
          uVar52 = uVar42 & 7;
          ppuVar54 = (undefined **)((int)ppuVar38 + -1);
          uVar53 = uVar51 >> 3;
          uVar42 = (uint)(CONCAT44(uVar51,uVar42) >> 3);
          iVar55 = uVar52 + 0x30;
          *(char *)ppuVar54 = (char)iVar55;
          uVar51 = uVar53;
        } while (uVar42 != 0 || uVar53 != 0);
        ppuStack_90 = ppuVar54;
        if (((uVar50 & 1) != 0) && (iVar55 != 0x30)) {
          ppuStack_90 = (undefined **)((int)ppuVar38 + -2);
          *(char *)ppuStack_90 = '0';
        }
        pcStack_84 = (char *)((int)apuStack_138 - (int)ppuStack_90);
        pcStack_88 = pcStack_84;
        if ((int)pcStack_84 < (int)pcVar48) {
          pcStack_88 = pcVar48;
        }
        uStack_94 = 0;
        uStack_98 = uVar50 & 0x84;
        if ((uVar50 & 0x84) != 0) {
LAB_0022d210:
          abStack_11e[0] = 0;
          pcStack_b4 = (char *)0x0;
          pcStack_8c = pcVar48;
          goto LAB_0022c821;
        }
joined_r0x0022e1fc:
        pcVar36 = pcStack_7c + -(int)pcStack_88;
      }
joined_r0x0022e60f:
      abStack_11e[0] = 0;
      if ((int)pcVar36 < 1) goto LAB_0022d210;
LAB_0022d132:
      pcStack_b4 = (char *)0x0;
      pcStack_8c = pcVar48;
      goto joined_r0x0022c79d;
    case 0x55:
      uStack_74 = uStack_74 | 0x10;
    case 0x75:
      if ((uStack_74 >> 5 & 1) == 0) {
        if ((uStack_74 >> 4 & 1) == 0) {
          if ((uStack_74 >> 6 & 1) == 0) {
            iVar45 = iStack_b8 + 4;
            iStack_b8 = iVar45;
            iVar55 = iStack_fc;
            if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
              iStack_b8 = iVar45;
            }
            uStack_ac = *(uint *)(iStack_b8 + iVar55 + -4);
            uVar51 = 0;
          }
          else {
            iVar45 = iStack_b8 + 4;
            iStack_b8 = iVar45;
            iVar55 = iStack_fc;
            if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
              iStack_b8 = iVar45;
            }
            uStack_ac = (uint)*(ushort *)(iStack_b8 + iVar55 + -4);
            uVar51 = 0;
          }
        }
        else {
          iVar45 = iStack_b8 + 4;
          iStack_b8 = iVar45;
          iVar55 = iStack_fc;
          if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
            iStack_b8 = iVar45;
          }
          uStack_ac = *(uint *)(iStack_b8 + iVar55 + -4);
          uVar51 = 0;
        }
      }
      else {
        uVar42 = iStack_b8 + 7U & 0xfffffff8;
        iStack_b8 = uVar42 + 8;
        iVar55 = iStack_fc;
        if ((0x10 < (int)uVar42) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar42)) {
          iStack_b8 = uVar42 + 8;
        }
        uVar51 = *(uint *)(iStack_b8 + iVar55 + -4);
        uStack_ac = *(uint *)(iStack_b8 + iVar55 + -8);
      }
      pcStack_d8 = pcVar48;
      ppuStack_90 = ppuStack_a0;
      if (-1 < (int)pcVar48) {
        uStack_74 = uStack_74 & 0xffffff7f;
      }
      uVar42 = 0;
      abStack_11e[0] = 0;
      if ((uStack_ac == 0 && uVar51 == 0) && (pcVar48 == (char *)0x0)) {
        pcStack_8c = pcVar48;
        pcStack_84 = (char *)0x0;
        uStack_94 = 0;
        pcStack_88 = (char *)0x0;
        uStack_98 = uStack_74 & 0x84;
        goto joined_r0x0022dc21;
      }
      pcStack_8c = pcVar48;
      bVar1 = false;
      if ((uVar51 == 0) && (uStack_ac < 10)) {
        bVar1 = true;
      }
      if (!bVar1) goto LAB_0022d787;
      ppuStack_90 = ppuStack_c8;
      pcStack_84 = (char *)0x1;
      pcStack_88 = (char *)0x1;
      if (1 < (int)pcVar48) {
        pcStack_88 = pcVar48;
      }
      uStack_94 = 0;
      cStack_139 = (char)uStack_ac + '0';
      uStack_98 = uStack_74 & 0x84;
      if ((uStack_74 & 0x84) == 0) {
        pcVar36 = pcStack_7c + -(int)pcStack_88;
        goto joined_r0x0022d31d;
      }
      goto LAB_0022d210;
    case 0x58:
      pcVar36 = "0123456789ABCDEF";
      goto LAB_0022ce0a;
    case 99:
      iVar45 = iStack_b8 + 4;
      iStack_b8 = iVar45;
      iVar55 = iStack_fc;
      if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
        iStack_b8 = iVar45;
      }
      pcStack_84 = (char *)0x1;
      uStack_94 = 0;
      uStack_98 = uStack_74 & 0x84;
      auStack_160[0] = (undefined1)*(undefined4 *)(iStack_b8 + iVar55 + -4);
      pcStack_88 = (char *)0x1;
      abStack_11e[0] = 0;
      if (((uStack_74 & 0x84) == 0) && (pcVar36 = pcStack_7c + -1, 0 < (int)pcVar36)) {
        ppuStack_90 = (undefined **)auStack_160;
        pcStack_b4 = (char *)0x0;
        pcStack_8c = (char *)0x0;
        goto joined_r0x0022c79d;
      }
      ppuStack_90 = (undefined **)auStack_160;
      pcStack_b4 = (char *)0x0;
      pcStack_8c = (char *)0x0;
      goto LAB_0022c821;
    case 100:
    case 0x69:
      goto switchD_0022c735_caseD_64;
    case 0x68:
      uStack_74 = uStack_74 | 0x40;
      goto LAB_0022c718;
    case 0x6c:
      if (*param_3 == 0x6c) {
        uStack_74 = uStack_74 | 0x20;
        param_3 = param_3 + 1;
      }
      else {
        uStack_74 = uStack_74 | 0x10;
      }
      goto LAB_0022c718;
    case 0x6e:
      if ((uStack_74 >> 5 & 1) == 0) {
        if ((uStack_74 >> 4 & 1) == 0) {
          if ((uStack_74 >> 6 & 1) == 0) {
            iVar35 = iStack_b8 + 4;
            iStack_b8 = iVar35;
            iVar37 = iStack_fc;
            if ((0x18 < iVar35) && (iStack_b8 = 0x24, iVar37 = iStack_100, 0x1c < iVar35)) {
              iStack_b8 = iVar35;
            }
            **(int **)(iStack_b8 + iVar37 + -4) = (int)pcStack_78;
          }
          else {
            iVar35 = iStack_b8 + 4;
            iStack_b8 = iVar35;
            iVar37 = iStack_fc;
            if ((0x18 < iVar35) && (iStack_b8 = 0x24, iVar37 = iStack_100, 0x1c < iVar35)) {
              iStack_b8 = iVar35;
            }
            **(undefined2 **)(iStack_b8 + iVar37 + -4) = (short)pcStack_78;
          }
        }
        else {
          iVar35 = iStack_b8 + 4;
          iStack_b8 = iVar35;
          iVar37 = iStack_fc;
          if ((0x18 < iVar35) && (iStack_b8 = 0x24, iVar37 = iStack_100, 0x1c < iVar35)) {
            iStack_b8 = iVar35;
          }
          **(int **)(iStack_b8 + iVar37 + -4) = (int)pcStack_78;
        }
      }
      else {
        iVar35 = iStack_b8 + 4;
        iStack_b8 = iVar35;
        iVar37 = iStack_fc;
        if ((0x18 < iVar35) && (iStack_b8 = 0x24, iVar37 = iStack_100, 0x1c < iVar35)) {
          iStack_b8 = iVar35;
        }
        piVar43 = *(int **)(iStack_b8 + iVar37 + -4);
        *piVar43 = (int)pcStack_78;
        piVar43[1] = (int)pcStack_78 >> 0x1f;
      }
      goto LAB_0022c6a7;
    case 0x70:
      iVar45 = iStack_b8 + 4;
      iStack_b8 = iVar45;
      iVar55 = iStack_fc;
      if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
        iStack_b8 = iVar45;
      }
      ppuStack_90 = ppuStack_a0;
      uVar42 = *(uint *)(iStack_b8 + iVar55 + -4);
      uStack_120 = 0x30;
      uVar51 = uStack_74;
      if (-1 < (int)pcVar48) {
        uVar51 = uStack_74 & 0xffffff7f;
      }
      uStack_74 = uVar51 | 2;
      uStack_11f = 0x78;
      abStack_11e[0] = 0;
      uVar50 = 0;
      if ((uVar42 != 0) || (pcVar48 != (char *)0x0)) {
        pcVar36 = "0123456789abcdef";
        uStack_70 = 0x78;
        goto LAB_0022d0af;
      }
      pcStack_8c = pcVar48;
      pcStack_84 = (char *)0x0;
      uStack_94 = 2;
      pcStack_88 = (char *)0x2;
      uStack_98 = uVar51 & 0x84;
      if (((uVar51 & 0x84) == 0) && (pcVar36 = pcStack_7c + -2, 0 < (int)pcVar36)) {
        uStack_70 = 0x78;
        pcStack_b4 = (char *)0x0;
        goto joined_r0x0022c79d;
      }
      uStack_70 = 0x78;
      pcStack_b4 = (char *)0x0;
      goto LAB_0022c821;
    case 0x71:
      uStack_74 = uStack_74 | 0x20;
      goto LAB_0022c718;
    case 0x73:
      iVar45 = iStack_b8 + 4;
      iStack_b8 = iVar45;
      iVar55 = iStack_fc;
      if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
        iStack_b8 = iVar45;
      }
      ppuStack_90 = *(undefined ***)(iStack_b8 + iVar55 + -4);
      abStack_11e[0] = 0;
      if (ppuStack_90 != (undefined **)0x0) {
        if ((int)pcVar48 < 0) {
          pcStack_d8 = pcVar48;
          pcStack_84 = (char *)strlen(ppuStack_90);
        }
        else {
          pcStack_d8 = pcVar48;
          iVar37 = memchr(ppuStack_90,0,pcVar48);
          iVar35 = iVar37 - (int)ppuStack_90;
          pcStack_84 = (char *)((uint)((int)pcStack_d8 < iVar35) * (int)pcStack_d8 +
                               (uint)((int)pcStack_d8 >= iVar35) * iVar35);
          if (iVar37 == 0) {
            pcStack_84 = pcStack_d8;
          }
        }
        pcStack_b4 = (char *)0x0;
        pcStack_8c = (char *)0x0;
        uVar42 = (uint)abStack_11e[0];
        goto LAB_0022c763;
      }
      if ((char *)0x6 < pcVar48) {
        pcVar48 = (char *)0x6;
      }
      pcStack_84 = pcVar48;
      if ((int)pcVar48 < 0) {
        pcVar48 = (char *)0x0;
      }
      uStack_94 = 0;
      uStack_98 = uStack_74 & 0x84;
      pcStack_88 = pcVar48;
      if (((uStack_74 & 0x84) == 0) && (pcVar36 = pcStack_7c + -(int)pcVar48, 0 < (int)pcVar36)) {
        ppuStack_90 = (undefined **)0x206448;
        pcStack_b4 = (char *)0x0;
        pcStack_8c = (char *)0x0;
        goto joined_r0x0022c79d;
      }
      ppuStack_90 = (undefined **)0x206448;
      pcStack_b4 = (char *)0x0;
      pcStack_8c = (char *)0x0;
      goto LAB_0022c821;
    case 0x78:
      pcVar36 = "0123456789abcdef";
LAB_0022ce0a:
      if ((uStack_74 >> 5 & 1) == 0) {
        if ((uStack_74 >> 4 & 1) == 0) {
          if ((uStack_74 >> 6 & 1) == 0) {
            iVar45 = iStack_b8 + 4;
            iStack_b8 = iVar45;
            iVar55 = iStack_fc;
            if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
              iStack_b8 = iVar45;
            }
            uVar42 = *(uint *)(iStack_b8 + iVar55 + -4);
            uVar50 = 0;
          }
          else {
            iVar45 = iStack_b8 + 4;
            iStack_b8 = iVar45;
            iVar55 = iStack_fc;
            if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
              iStack_b8 = iVar45;
            }
            uVar42 = (uint)*(ushort *)(iStack_b8 + iVar55 + -4);
            uVar50 = 0;
          }
        }
        else {
          iVar45 = iStack_b8 + 4;
          iStack_b8 = iVar45;
          iVar55 = iStack_fc;
          if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
            iStack_b8 = iVar45;
          }
          uVar42 = *(uint *)(iStack_b8 + iVar55 + -4);
          uVar50 = 0;
        }
      }
      else {
        uVar42 = iStack_b8 + 7U & 0xfffffff8;
        iStack_b8 = uVar42 + 8;
        iVar55 = iStack_fc;
        if ((0x10 < (int)uVar42) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar42)) {
          iStack_b8 = uVar42 + 8;
        }
        uVar50 = *(uint *)(iStack_b8 + iVar55 + -4);
        uVar42 = *(uint *)(iStack_b8 + iVar55 + -8);
      }
      if (((uStack_74 & 1) != 0) && (uVar42 != 0 || uVar50 != 0)) {
        uStack_120 = 0x30;
        uStack_11f = (char)uStack_70;
        uStack_74 = uStack_74 | 2;
      }
      abStack_11e[0] = 0;
      if (-1 < (int)pcVar48) {
        uStack_74 = uStack_74 & 0xffffff7f;
      }
      ppuStack_90 = ppuStack_a0;
      if ((uVar42 == 0 && uVar50 == 0) && (pcVar48 == (char *)0x0)) {
        pcStack_8c = pcVar48;
        pcStack_84 = (char *)0x0;
        uStack_94 = uStack_74 & 2;
        uStack_98 = uStack_74 & 0x84;
        pcStack_88 = (char *)0x0;
        if ((uStack_74 & 2) != 0) {
          pcStack_88 = (char *)0x2;
        }
      }
      else {
LAB_0022d0af:
        abStack_11e[0] = 0;
        ppuVar54 = ppuStack_a0;
        do {
          uVar51 = uVar42 & 0xf;
          ppuVar54 = (undefined **)((int)ppuVar54 + -1);
          uVar52 = uVar50 >> 4;
          uVar42 = (uint)(CONCAT44(uVar50,uVar42) >> 4);
          *(char *)ppuVar54 = pcVar36[uVar51];
          uVar50 = uVar52;
        } while (uVar42 != 0 || uVar52 != 0);
        ppuStack_90 = ppuVar54;
        pcStack_8c = pcVar48;
        pcStack_84 = (char *)((int)apuStack_138 - (int)ppuVar54);
        pcStack_88 = pcStack_84;
        if ((int)pcStack_84 < (int)pcVar48) {
          pcStack_88 = pcVar48;
        }
        uStack_94 = uStack_74 & 2;
        uStack_98 = uStack_74 & 0x84;
        if ((uStack_74 & 2) != 0) {
          pcStack_88 = pcStack_88 + 2;
        }
      }
      if ((uStack_74 & 0x84) == 0) goto joined_r0x0022e1fc;
      goto LAB_0022d210;
    }
  }
LAB_0022cc3b:
  if (iStack_168 != 0) {
    __sprint_r(iStack_6c,iStack_68,&piStack_170);
    ppcVar4 = &pcStack_80;
    if ((*(ushort *)(iStack_68 + 0xc) & 0x40) == 0) {
      ppcVar4 = &pcStack_78;
    }
    return *ppcVar4;
  }
LAB_0022c8a9:
  ppcVar4 = &pcStack_80;
  if ((*(ushort *)(iStack_68 + 0xc) & 0x40) == 0) {
    ppcVar4 = &pcStack_78;
  }
  return *ppcVar4;
switchD_0022c735_caseD_64:
  if ((uStack_74 >> 5 & 1) == 0) {
    if ((uStack_74 >> 4 & 1) == 0) {
      if ((uStack_74 >> 6 & 1) == 0) {
        iVar45 = iStack_b8 + 4;
        iStack_b8 = iVar45;
        iVar55 = iStack_fc;
        if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
          iStack_b8 = iVar45;
        }
        uVar50 = *(uint *)(iStack_b8 + iVar55 + -4);
        uVar51 = (int)uVar50 >> 0x1f;
      }
      else {
        iVar45 = iStack_b8 + 4;
        iStack_b8 = iVar45;
        iVar55 = iStack_fc;
        if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
          iStack_b8 = iVar45;
        }
        uVar50 = (uint)*(short *)(iStack_b8 + iVar55 + -4);
        uVar51 = (int)uVar50 >> 0x1f;
      }
    }
    else {
      iVar45 = iStack_b8 + 4;
      iStack_b8 = iVar45;
      iVar55 = iStack_fc;
      if ((0x18 < iVar45) && (iStack_b8 = 0x24, iVar55 = iStack_100, 0x1c < iVar45)) {
        iStack_b8 = iVar45;
      }
      uVar50 = *(uint *)(iStack_b8 + iVar55 + -4);
      uVar51 = (int)uVar50 >> 0x1f;
    }
  }
  else {
    uVar51 = iStack_b8 + 7U & 0xfffffff8;
    iStack_b8 = uVar51 + 8;
    iVar55 = iStack_fc;
    if ((0x10 < (int)uVar51) && (iStack_b8 = 0x28, iVar55 = iStack_100, 0x18 < (int)uVar51)) {
      iStack_b8 = uVar51 + 8;
    }
    uVar51 = *(uint *)(iStack_b8 + iVar55 + -4);
    uVar50 = *(uint *)(iStack_b8 + iVar55 + -8);
  }
  pcStack_d8 = pcVar48;
  uStack_ac = uVar50;
  if (-1 < (int)pcVar48) {
    uStack_74 = uStack_74 & 0xffffff7f;
  }
  if (((int)uVar51 < 1) && (uVar51 != 0)) {
    uStack_ac = -uVar50;
    uVar51 = uVar51 ^ 0xffffffff;
    if (uVar50 == 0) {
      uVar51 = uVar51 + 1;
    }
    ppuStack_90 = ppuStack_a0;
    uVar42 = 0x2d;
    abStack_11e[0] = 0x2d;
    if (uStack_ac == 0 && uVar51 == 0) {
      if (pcVar48 == (char *)0x0) {
        pcStack_8c = pcVar48;
        pcStack_84 = (char *)0x0;
        uStack_94 = 0;
        uStack_98 = uStack_74 & 0x84;
        pcStack_88 = (char *)0x1;
        if ((uStack_74 & 0x84) == 0) {
          pcVar36 = pcStack_7c + -1;
joined_r0x0022e4f6:
          uStack_94 = 0;
          if (0 < (int)pcVar36) goto LAB_0022d132;
        }
      }
      else {
        bVar1 = false;
        if ((uVar51 == 0) && (uStack_ac < 10)) {
          bVar1 = true;
        }
        if (!bVar1) goto LAB_0022d787;
        pcStack_8c = pcVar48;
        ppuStack_90 = ppuStack_c8;
        pcStack_84 = (char *)0x1;
        uStack_94 = 0;
        cStack_139 = (char)uStack_ac + '0';
        pcVar36 = (char *)0x1;
        if (1 < (int)pcVar48) {
          pcVar36 = pcVar48;
        }
        uStack_98 = uStack_74 & 0x84;
        pcStack_88 = pcVar36 + 1;
        if ((uStack_74 & 0x84) == 0) {
          pcVar36 = pcStack_7c + -(int)(pcVar36 + 1);
          goto joined_r0x0022e4f6;
        }
      }
    }
    else {
      bVar1 = false;
      if ((uVar51 == 0) && (uStack_ac < 10)) {
        bVar1 = true;
      }
      if (!bVar1) goto LAB_0022d787;
      pcStack_8c = pcVar48;
      ppuStack_90 = ppuStack_c8;
      pcStack_84 = (char *)0x1;
      uStack_94 = 0;
      cStack_139 = (char)uStack_ac + '0';
      pcVar36 = (char *)0x1;
      if (1 < (int)pcVar48) {
        pcVar36 = pcVar48;
      }
      uStack_98 = uStack_74 & 0x84;
      pcStack_88 = pcVar36 + 1;
      if ((uStack_74 & 0x84) == 0) {
        pcVar36 = pcStack_7c + -(int)(pcVar36 + 1);
        goto joined_r0x0022e4f6;
      }
    }
    uStack_94 = 0;
    pcStack_b4 = (char *)0x0;
    pcStack_8c = pcVar48;
    goto LAB_0022c7fa;
  }
  ppuStack_90 = ppuStack_a0;
  if ((uVar50 != 0 || uVar51 != 0) || (pcVar48 != (char *)0x0)) {
    bVar1 = false;
    if ((uVar51 == 0) && (uVar50 < 10)) {
      bVar1 = true;
    }
    if (bVar1) {
      cStack_139 = (char)uVar50 + '0';
      ppuStack_90 = ppuStack_c8;
    }
    else {
LAB_0022d787:
      ppuStack_90 = ppuStack_a0;
      pcStack_d8 = pcVar48;
      uStack_50 = uVar42;
      do {
        ppuStack_90 = (undefined **)((int)ppuStack_90 + -1);
        cVar33 = FUN_00236540(uStack_ac,uVar51,10,0);
        *(char *)ppuStack_90 = cVar33 + '0';
        lVar58 = __udivdi3(uStack_ac,uVar51,10,0);
        uVar51 = (uint)((ulonglong)lVar58 >> 0x20);
        uStack_ac = (uint)lVar58;
        uVar42 = uStack_50;
      } while (lVar58 != 0);
    }
  }
  pcStack_8c = pcStack_d8;
  pcStack_b4 = (char *)0x0;
  pcStack_84 = (char *)((int)apuStack_138 - (int)ppuStack_90);
LAB_0022c763:
  pcStack_88 = pcStack_84;
  if ((int)pcStack_84 < (int)pcStack_8c) {
    pcStack_88 = pcStack_8c;
  }
  if (uVar42 != 0) {
    pcStack_88 = pcStack_88 + 1;
  }
  uStack_94 = uStack_74 & 2;
  uStack_98 = uStack_74 & 0x84;
  if ((uStack_74 & 2) != 0) {
    pcStack_88 = pcStack_88 + 2;
  }
  if (((uStack_74 & 0x84) != 0) ||
     (pcVar36 = pcStack_7c + -(int)pcStack_88, iVar37 = iStack_16c, iVar35 = iStack_168,
     (int)pcVar36 < 1)) goto LAB_0022c7f8;
joined_r0x0022c79d:
  do {
    if ((int)pcVar36 < 0x11) goto LAB_0022c7d8;
    piVar34[1] = 0x10;
    *piVar34 = (int)&PTR_DAT_00205e90;
    iStack_168 = iVar35 + 0x10;
    iStack_16c = iVar37 + 1;
    piVar34 = piVar34 + 2;
    if (7 < iStack_16c) {
      iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
      if (iVar37 != 0) goto LAB_0022c8a9;
      piVar34 = local_1b0;
    }
    pcVar36 = pcVar36 + -0x10;
    iVar37 = iStack_16c;
    iVar35 = iStack_168;
  } while( true );
switchD_0022c735_caseD_31:
  pcStack_7c = (char *)0x0;
  do {
    bVar47 = *param_3;
    iVar37 = (int)pcStack_7c * 10 + uStack_70;
    uStack_70 = (uint)bVar47;
    pcStack_7c = (char *)(iVar37 - 0x30);
    param_3 = param_3 + 1;
  } while (bVar47 - 0x30 < 10);
  goto LAB_0022c721;
LAB_0022c7d8:
  piVar34[1] = (int)pcVar36;
  *piVar34 = (int)&PTR_DAT_00205e90;
  iStack_168 = iVar35 + (int)pcVar36;
  iStack_16c = iVar37 + 1;
  piVar34 = piVar34 + 2;
  if (7 < iStack_16c) {
    iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
    if (iVar37 != 0) goto LAB_0022c8a9;
    piVar34 = local_1b0;
  }
  uVar42 = (uint)abStack_11e[0];
LAB_0022c7f8:
  if (uVar42 != 0) {
LAB_0022c7fa:
    piVar34[1] = 1;
    *piVar34 = (int)abStack_11e;
    iStack_168 = iStack_168 + 1;
    iStack_16c = iStack_16c + 1;
    piVar34 = piVar34 + 2;
    if (7 < iStack_16c) {
      iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
      if (iVar37 != 0) goto LAB_0022c8a9;
      piVar34 = local_1b0;
    }
  }
LAB_0022c821:
  if (uStack_94 != 0) {
    piVar34[1] = 2;
    *piVar34 = (int)&uStack_120;
    iStack_168 = iStack_168 + 2;
    iStack_16c = iStack_16c + 1;
    piVar34 = piVar34 + 2;
    if (7 < iStack_16c) {
      iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
      if (iVar37 != 0) goto LAB_0022c8a9;
      piVar34 = local_1b0;
    }
  }
  if ((uStack_98 == 0x80) &&
     (iVar37 = (int)pcStack_7c - (int)pcStack_88, iVar35 = iStack_16c, iVar55 = iStack_168,
     0 < iVar37)) {
    for (; 0x10 < iVar37; iVar37 = iVar37 + -0x10) {
      piVar34[1] = 0x10;
      *piVar34 = (int)&DAT_00205e80;
      iStack_168 = iVar55 + 0x10;
      iStack_16c = iVar35 + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
        if (iVar35 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
      iVar35 = iStack_16c;
      iVar55 = iStack_168;
    }
    piVar34[1] = iVar37;
    *piVar34 = (int)&DAT_00205e80;
    iStack_168 = iVar55 + iVar37;
    iStack_16c = iVar35 + 1;
    piVar34 = piVar34 + 2;
    if (7 < iStack_16c) {
      iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
      if (iVar37 != 0) goto LAB_0022c8a9;
      piVar34 = local_1b0;
    }
  }
  iVar37 = (int)pcStack_8c - (int)pcStack_84;
  iVar35 = iStack_16c;
  iVar55 = iStack_168;
  if (0 < iVar37) {
    for (; 0x10 < iVar37; iVar37 = iVar37 + -0x10) {
      piVar34[1] = 0x10;
      *piVar34 = (int)&DAT_00205e80;
      iStack_168 = iVar55 + 0x10;
      iStack_16c = iVar35 + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
        if (iVar35 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
      iVar35 = iStack_16c;
      iVar55 = iStack_168;
    }
    piVar34[1] = iVar37;
    *piVar34 = (int)&DAT_00205e80;
    iStack_168 = iVar55 + iVar37;
    iStack_16c = iVar35 + 1;
    piVar34 = piVar34 + 2;
    if (7 < iStack_16c) {
      iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
      if (iVar37 != 0) goto LAB_0022c8a9;
      piVar34 = local_1b0;
    }
  }
  pcVar48 = pcStack_84;
  if ((uStack_74 >> 8 & 1) == 0) {
    piVar34[1] = (int)pcStack_84;
    *piVar34 = (int)ppuStack_90;
    iStack_168 = iStack_168 + (int)pcVar48;
    iStack_16c = iStack_16c + 1;
    piVar34 = piVar34 + 2;
    if (7 < iStack_16c) {
      iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
      goto joined_r0x0022e356;
    }
  }
  else if ((int)uStack_70 < 0x66) {
    if ((iStack_9c < 2) && ((uStack_74 & 1) == 0)) {
      piVar34[1] = 1;
      *piVar34 = (int)ppuStack_90;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
joined_r0x0022dd7d:
        if (iVar37 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
    }
    else {
      piVar34[1] = 1;
      ppuVar54 = ppuStack_90;
      *piVar34 = (int)ppuStack_90;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
        if (iVar37 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
      iVar37 = iStack_b0;
      *piVar34 = iStack_f8;
      piVar34[1] = iVar37;
      iStack_168 = iStack_168 + iVar37;
      iStack_16c = iStack_16c + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
        if (iVar37 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
      iStack_dc = iStack_9c + -1;
      iVar35 = FUN_0022b874(uStack_a4,uStack_a8,uStack_bc,uStack_c0);
      iVar37 = iStack_9c;
      if (iVar35 == 0) {
        if (1 < iStack_9c) {
          iVar37 = iStack_dc;
          if (0x11 < iStack_9c) {
            do {
              piVar34[1] = 0x10;
              *piVar34 = (int)&DAT_00205e80;
              iStack_168 = iStack_168 + 0x10;
              iStack_16c = iStack_16c + 1;
              piVar34 = piVar34 + 2;
              if (7 < iStack_16c) {
                iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
                if (iVar35 != 0) goto LAB_0022c8a9;
                piVar34 = local_1b0;
              }
              iVar37 = iVar37 + -0x10;
            } while (0x10 < iVar37);
          }
          piVar34[1] = iVar37;
          *piVar34 = (int)&DAT_00205e80;
          iStack_168 = iStack_168 + iVar37;
          iStack_16c = iStack_16c + 1;
          piVar34 = piVar34 + 2;
          if (7 < iStack_16c) {
            iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
            goto joined_r0x0022dd7d;
          }
        }
      }
      else {
        piVar34[1] = iStack_dc;
        *piVar34 = (int)((int)ppuVar54 + 1);
        iStack_16c = iStack_16c + 1;
        iStack_168 = iStack_168 + iVar37 + -1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          goto joined_r0x0022dd7d;
        }
      }
    }
    iVar37 = iStack_c4;
    piVar34[1] = iStack_c4;
    *piVar34 = (int)acStack_128;
    iStack_168 = iStack_168 + iVar37;
    iStack_16c = iStack_16c + 1;
    piVar34 = piVar34 + 2;
    if (7 < iStack_16c) {
      iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
joined_r0x0022e356:
      if (iVar37 != 0) goto LAB_0022c8a9;
      piVar34 = local_1b0;
    }
  }
  else {
    iVar37 = FUN_0022b874(uStack_a4,uStack_a8,uStack_bc,uStack_c0);
    if (iVar37 == 0) {
      piVar34[1] = 1;
      *piVar34 = (int)&DAT_00206464;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
        if (iVar37 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
      iVar37 = iStack_b0;
      if (((int)pcStack_110 < iStack_9c) || ((uStack_74 & 1) != 0)) {
        *piVar34 = iStack_f8;
        piVar34[1] = iVar37;
        iStack_168 = iStack_168 + iVar37;
        iStack_16c = iStack_16c + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          if (iVar37 != 0) goto LAB_0022c8a9;
          piVar34 = local_1b0;
        }
        iVar37 = iStack_9c + -1;
        if (1 < iStack_9c) {
          if (0x11 < iStack_9c) {
            do {
              piVar34[1] = 0x10;
              *piVar34 = (int)&DAT_00205e80;
              iStack_168 = iStack_168 + 0x10;
              iStack_16c = iStack_16c + 1;
              piVar34 = piVar34 + 2;
              if (7 < iStack_16c) {
                iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
                if (iVar35 != 0) goto LAB_0022c8a9;
                piVar34 = local_1b0;
              }
              iVar37 = iVar37 + -0x10;
            } while (0x10 < iVar37);
          }
          piVar34[1] = iVar37;
          *piVar34 = (int)&DAT_00205e80;
          iStack_168 = iStack_168 + iVar37;
          iStack_16c = iStack_16c + 1;
          piVar34 = piVar34 + 2;
          if (7 < iStack_16c) {
            iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
            goto joined_r0x0022e356;
          }
        }
      }
    }
    else if ((int)pcStack_110 < 1) {
      piVar34[1] = 1;
      *piVar34 = (int)&DAT_00206464;
      iStack_168 = iStack_168 + 1;
      iStack_16c = iStack_16c + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
        if (iVar37 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
      iVar37 = iStack_b0;
      if (((pcStack_110 != (char *)0x0) || (iStack_9c != 0)) || ((uStack_74 & 1) != 0)) {
        *piVar34 = iStack_f8;
        piVar34[1] = iVar37;
        iStack_168 = iStack_168 + iVar37;
        iStack_16c = iStack_16c + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          if (iVar37 != 0) goto LAB_0022c8a9;
          piVar34 = local_1b0;
        }
        iVar37 = -(int)pcStack_110;
        iVar35 = iStack_16c;
        iVar55 = iStack_168;
        if (0 < iVar37) {
          for (; 0x10 < iVar37; iVar37 = iVar37 + -0x10) {
            piVar34[1] = 0x10;
            *piVar34 = (int)&DAT_00205e80;
            iStack_168 = iVar55 + 0x10;
            iStack_16c = iVar35 + 1;
            piVar34 = piVar34 + 2;
            if (7 < iStack_16c) {
              iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
              if (iVar35 != 0) goto LAB_0022c8a9;
              piVar34 = local_1b0;
            }
            iVar35 = iStack_16c;
            iVar55 = iStack_168;
          }
          piVar34[1] = iVar37;
          *piVar34 = (int)&DAT_00205e80;
          iStack_168 = iVar55 + iVar37;
          iStack_16c = iVar35 + 1;
          piVar34 = piVar34 + 2;
          if (7 < iStack_16c) {
            iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
            if (iVar37 != 0) goto LAB_0022c8a9;
            piVar34 = local_1b0;
          }
        }
        iVar37 = iStack_9c;
        piVar34[1] = iStack_9c;
        *piVar34 = (int)ppuStack_90;
        iStack_168 = iStack_168 + iVar37;
        iStack_16c = iStack_16c + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          goto joined_r0x0022e356;
        }
      }
    }
    else {
      iVar37 = (uint)((int)pcStack_b4 < iStack_9c) * (int)pcStack_b4 +
               (uint)((int)pcStack_b4 >= iStack_9c) * iStack_9c;
      if (0 < iVar37) {
        iStack_54 = iVar37;
        piVar34[1] = iVar37;
        *piVar34 = (int)ppuStack_90;
        iStack_168 = iStack_168 + iVar37;
        iStack_16c = iStack_16c + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          if (iVar37 != 0) goto LAB_0022c8a9;
          piVar34 = local_1b0;
          iVar37 = iStack_54;
        }
      }
      iVar37 = (int)pcStack_b4 - (uint)(-1 < iVar37) * iVar37;
      iVar35 = iStack_16c;
      iVar55 = iStack_168;
      if (0 < iVar37) {
        for (; 0x10 < iVar37; iVar37 = iVar37 + -0x10) {
          piVar34[1] = 0x10;
          *piVar34 = (int)&DAT_00205e80;
          iStack_168 = iVar55 + 0x10;
          iStack_16c = iVar35 + 1;
          piVar34 = piVar34 + 2;
          if (7 < iStack_16c) {
            iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
            if (iVar35 != 0) goto LAB_0022c8a9;
            piVar34 = local_1b0;
          }
          iVar35 = iStack_16c;
          iVar55 = iStack_168;
        }
        piVar34[1] = iVar37;
        *piVar34 = (int)&DAT_00205e80;
        iStack_168 = iVar55 + iVar37;
        iStack_16c = iVar35 + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          if (iVar37 != 0) goto LAB_0022c8a9;
          piVar34 = local_1b0;
        }
      }
      ppuVar54 = ppuStack_90;
      iVar37 = iStack_b0;
      ppuStack_90 = (undefined **)((int)ppuStack_90 + (int)pcStack_b4);
      if (((int)pcStack_110 < iStack_9c) || ((uStack_74 & 1) != 0)) {
        *piVar34 = iStack_f8;
        piVar34[1] = iVar37;
        iStack_168 = iStack_168 + iVar37;
        iStack_16c = iStack_16c + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          if (iVar37 != 0) goto LAB_0022c8a9;
          piVar34 = local_1b0;
        }
      }
      iVar37 = iStack_9c - (int)pcStack_110;
      pcVar48 = (char *)((int)ppuVar54 + (iStack_9c - (int)ppuStack_90));
      iVar35 = (uint)(iVar37 < (int)pcVar48) * iVar37 +
               (uint)(iVar37 >= (int)pcVar48) * (int)pcVar48;
      if (0 < iVar35) {
        iStack_58 = iVar35;
        *piVar34 = (int)ppuStack_90;
        piVar34[1] = iVar35;
        iStack_168 = iStack_168 + iVar35;
        iStack_16c = iStack_16c + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          if (iVar37 != 0) goto LAB_0022c8a9;
          piVar34 = local_1b0;
          iVar35 = iStack_58;
        }
        iVar37 = iStack_9c - (int)pcStack_110;
      }
      iVar37 = iVar37 - (uint)(-1 < iVar35) * iVar35;
      iVar35 = iStack_16c;
      iVar55 = iStack_168;
      if (0 < iVar37) {
        for (; 0x10 < iVar37; iVar37 = iVar37 + -0x10) {
          piVar34[1] = 0x10;
          *piVar34 = (int)&DAT_00205e80;
          iStack_168 = iVar55 + 0x10;
          iStack_16c = iVar35 + 1;
          piVar34 = piVar34 + 2;
          if (7 < iStack_16c) {
            iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
            if (iVar35 != 0) goto LAB_0022c8a9;
            piVar34 = local_1b0;
          }
          iVar35 = iStack_16c;
          iVar55 = iStack_168;
        }
        piVar34[1] = iVar37;
        *piVar34 = (int)&DAT_00205e80;
        iStack_168 = iVar55 + iVar37;
        iStack_16c = iVar35 + 1;
        piVar34 = piVar34 + 2;
        if (7 < iStack_16c) {
          iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
          goto joined_r0x0022e356;
        }
      }
    }
  }
  if (((uStack_74 & 4) != 0) &&
     (iVar37 = (int)pcStack_7c - (int)pcStack_88, iVar35 = iStack_16c, iVar55 = iStack_168,
     0 < iVar37)) {
    for (; 0x10 < iVar37; iVar37 = iVar37 + -0x10) {
      piVar34[1] = 0x10;
      *piVar34 = (int)&PTR_DAT_00205e90;
      iStack_168 = iVar55 + 0x10;
      iStack_16c = iVar35 + 1;
      piVar34 = piVar34 + 2;
      if (7 < iStack_16c) {
        iVar35 = __sprint_r(iStack_6c,iStack_68,&piStack_170);
        if (iVar35 != 0) goto LAB_0022c8a9;
        piVar34 = local_1b0;
      }
      iVar35 = iStack_16c;
      iVar55 = iStack_168;
    }
    piVar34[1] = iVar37;
    *piVar34 = (int)&PTR_DAT_00205e90;
    iStack_168 = iVar55 + iVar37;
    iStack_16c = iVar35 + 1;
    if ((7 < iStack_16c) && (iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170), iVar37 != 0))
    goto LAB_0022c8a9;
  }
  pcVar48 = pcStack_88;
  if ((int)pcStack_88 < (int)pcStack_7c) {
    pcVar48 = pcStack_7c;
  }
  pcStack_78 = pcStack_78 + (int)pcVar48;
  if ((iStack_168 != 0) && (iVar37 = __sprint_r(iStack_6c,iStack_68,&piStack_170), iVar37 != 0))
  goto LAB_0022c8a9;
  iStack_16c = 0;
  piVar34 = local_1b0;
  goto LAB_0022c6a7;
switchD_0022c735_caseD_20:
  if (uVar42 == 0) {
    uVar42 = 0x20;
  }
  abStack_11e[0] = (byte)uVar42;
  goto LAB_0022c718;
}


// ===== __swsetup_r @ 0022e630 (214 bytes)

/* newlib wsetup.c: __sinit, __smakebuf_r, _free_r [inference] */

undefined4 __swsetup_r(undefined4 *param_1,int *param_2)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  if ((PTR_DAT_00237f00 != (undefined *)0x0) && (*(int *)(PTR_DAT_00237f00 + 0x38) == 0)) {
    __sinit();
  }
  uVar1 = *(ushort *)(param_2 + 3);
  uVar3 = (uint)(short)uVar1;
  iVar4 = param_2[4];
  if ((uVar3 >> 3 & 1) == 0) {
    if ((uVar3 >> 4 & 1) == 0) {
      *param_1 = 9;
      *(ushort *)(param_2 + 3) = uVar1 | 0x40;
      return 0xffffffff;
    }
    if ((uVar3 & 4) == 0) {
      iVar4 = param_2[4];
    }
    else {
      if ((int *)param_2[0xc] != (int *)0x0) {
        if ((int *)param_2[0xc] != param_2 + 0x10) {
          _free_r(param_1);
          uVar3 = (uint)(short)param_2[3];
        }
        param_2[0xc] = 0;
      }
      param_2[1] = 0;
      iVar4 = param_2[4];
      *param_2 = iVar4;
      uVar3 = uVar3 & 0xffffffdb;
      *(short *)(param_2 + 3) = (short)uVar3;
    }
    uVar3 = uVar3 | 8;
    *(short *)(param_2 + 3) = (short)uVar3;
  }
  if ((iVar4 == 0) && (((uVar3 & 0x200) == 0 || ((uVar3 & 0x80) != 0)))) {
    __smakebuf_r(param_1,param_2);
    uVar3 = (uint)(short)param_2[3];
    iVar4 = param_2[4];
  }
  if ((uVar3 & 1) == 0) {
    iVar2 = 0;
    if ((uVar3 >> 1 & 1) == 0) {
      iVar2 = param_2[5];
    }
    param_2[2] = iVar2;
  }
  else {
    param_2[2] = 0;
    param_2[6] = -param_2[5];
  }
  if ((iVar4 == 0) && ((uVar3 & 0x80) != 0)) {
    *(ushort *)(param_2 + 3) = (ushort)uVar3 | 0x40;
    return 0xffffffff;
  }
  return 0;
}


// ===== FUN_0022e710 @ 0022e710 (48 bytes)

undefined4 FUN_0022e710(undefined4 param_1)

{
  undefined *puVar1;
  int iVar2;
  
  puVar1 = *(undefined **)(PTR_DAT_00237f00 + 0x148);
  if (puVar1 == (undefined *)0x0) {
    puVar1 = PTR_DAT_00237f00 + 0x14c;
    *(undefined **)(PTR_DAT_00237f00 + 0x148) = puVar1;
  }
  iVar2 = *(int *)(puVar1 + 4);
  if (0x1f < iVar2) {
    return 0xffffffff;
  }
  *(int *)(puVar1 + 4) = iVar2 + 1;
  *(undefined4 *)(puVar1 + iVar2 * 4 + 8) = param_1;
  return 0;
}


// ===== __call_exitprocs @ 0022e740 (204 bytes)

/* newlib __call_atexit.c: callx through the atexit list, free (weak reference 0x22BA60) [inference]
    */

void __call_exitprocs(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  uint uVar3;
  undefined4 *puVar4;
  uint uVar5;
  code *pcVar6;
  int iVar7;
  
LAB_0022e749:
  puVar4 = DAT_00237c20;
  puVar2 = &DAT_00237c20;
  do {
    puVar1 = puVar2;
    puVar2 = puVar4;
    if (puVar2 == (undefined4 *)0x0) {
      return;
    }
    uVar3 = puVar2[1] - 1;
    puVar4 = puVar2 + uVar3;
    if (-1 < (int)uVar3) {
      do {
        if ((param_2 == 0) || ((puVar2 != (undefined4 *)0xffffff78 && (puVar4[0x42] == param_2)))) {
          pcVar6 = (code *)puVar4[2];
          if (puVar2[1] - 1 == uVar3) {
            puVar2[1] = puVar2[1] - 1;
          }
          else {
            puVar4[2] = 0;
          }
          if (pcVar6 != (code *)0x0) {
            iVar7 = puVar2[1];
            if ((puVar2 == (undefined4 *)0xffffff78) ||
               (uVar5 = 1 << 0x20 - (0x20 - (uVar3 & 0x1f)), (uVar5 & puVar2[0x62]) == 0)) {
              (*pcVar6)();
            }
            else if ((uVar5 & puVar2[99]) == 0) {
              (*pcVar6)(param_1);
            }
            else {
              (*pcVar6)(puVar4[0x22]);
            }
            if ((puVar2[1] != iVar7) || ((undefined4 *)*puVar1 != puVar2)) goto LAB_0022e749;
          }
        }
        uVar3 = uVar3 - 1;
        puVar4 = puVar4 + -1;
      } while (uVar3 != 0xffffffff);
    }
    puVar4 = (undefined4 *)*puVar2;
    if ((puVar2[1] == 0) && (puVar4 != (undefined4 *)0x0)) {
      *puVar1 = puVar4;
      free(puVar2);
      puVar4 = (undefined4 *)*puVar1;
      puVar2 = puVar1;
    }
  } while( true );
}


// ===== quorem @ 0022e810 (372 bytes)

/* newlib dtoa.c static; calls __mcmp [inference] */

uint quorem(int param_1,int param_2)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  uint *puVar7;
  uint uVar8;
  uint *puVar9;
  int iVar10;
  uint *puVar11;
  uint *puVar12;
  uint *puVar13;
  
  if (*(int *)(param_1 + 0x10) < *(int *)(param_2 + 0x10)) {
    return 0;
  }
  iVar4 = *(int *)(param_2 + 0x10) + -1;
  iVar3 = iVar4 * 4 + param_2;
  iVar10 = iVar4 * 4 + param_1;
  puVar11 = (uint *)(param_1 + 0x14);
  puVar12 = (uint *)(param_2 + 0x14);
  uVar2 = *(uint *)(iVar10 + 0x14) / (*(int *)(iVar3 + 0x14) + 1U);
  puVar13 = (uint *)(iVar3 + 0x14);
  if (uVar2 != 0) {
    uVar5 = 0;
    iVar3 = 0;
    puVar9 = puVar11;
    puVar7 = puVar12;
    do {
      uVar5 = uVar5 + uVar2 * (*puVar7 & 0xffff);
      uVar6 = (uVar5 >> 0x10) + uVar2 * (*puVar7 >> 0x10);
      uVar8 = iVar3 + ((*puVar9 & 0xffff) - (uVar5 & 0xffff));
      iVar3 = ((int)uVar8 >> 0x10) + ((*puVar9 >> 0x10) - (uVar6 & 0xffff));
      puVar7 = puVar7 + 1;
      uVar5 = uVar6 >> 0x10;
      *puVar9 = iVar3 * 0x10000 | uVar8 & 0xffff;
      iVar3 = iVar3 >> 0x10;
      puVar9 = puVar9 + 1;
    } while (puVar7 <= puVar13);
    if (*(int *)(iVar10 + 0x14) == 0) {
      iVar3 = 0;
      if ((puVar11 < (uint *)(iVar10 + 0x10U)) && (*(int *)(iVar10 + 0x10) == 0)) {
        puVar9 = (uint *)(iVar10 + 0xc);
        do {
          iVar3 = iVar3 + 1;
          if (puVar9 <= puVar11) break;
          piVar1 = (int *)(iVar10 + 0xc);
          puVar9 = puVar9 + -1;
          iVar10 = iVar10 + -4;
        } while (*piVar1 == 0);
      }
      iVar4 = iVar4 - iVar3;
      *(int *)(param_1 + 0x10) = iVar4;
    }
  }
  iVar10 = __mcmp(param_1,param_2);
  if (-1 < iVar10) {
    uVar2 = uVar2 + 1;
    iVar10 = 0;
    puVar9 = puVar11;
    do {
      uVar5 = iVar10 + ((*puVar9 & 0xffff) - (*puVar12 & 0xffff));
      iVar10 = ((int)uVar5 >> 0x10) + ((*puVar9 >> 0x10) - (*puVar12 >> 0x10));
      puVar12 = puVar12 + 1;
      *puVar9 = iVar10 * 0x10000 | uVar5 & 0xffff;
      iVar10 = iVar10 >> 0x10;
      puVar9 = puVar9 + 1;
    } while (puVar12 <= puVar13);
    iVar10 = iVar4 * 4 + param_1;
    if (*(int *)(iVar10 + 0x14) == 0) {
      iVar3 = 0;
      if ((puVar11 < (uint *)(iVar10 + 0x10U)) && (*(int *)(iVar10 + 0x10) == 0)) {
        puVar12 = (uint *)(iVar10 + 0xc);
        do {
          iVar3 = iVar3 + 1;
          if (puVar12 <= puVar11) break;
          piVar1 = (int *)(iVar10 + 0xc);
          puVar12 = puVar12 + -1;
          iVar10 = iVar10 + -4;
        } while (*piVar1 == 0);
      }
      *(int *)(param_1 + 0x10) = iVar4 - iVar3;
      return uVar2;
    }
  }
  return uVar2;
}


// ===== _dtoa_r @ 0022e990 (4063 bytes)

/* newlib dtoa.c (4,208 bytes): 14 of 15 distinctive constants of newlib's _dtoa_r, 9999 (0x270F)
   [fact for the constants] */

char * _dtoa_r(int param_1,undefined4 param_2,uint param_3,uint param_4,int param_5,uint param_6,
              int *param_7,undefined4 *param_8,undefined4 *param_9)

{
  char *pcVar1;
  undefined8 uVar2;
  char *pcVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 *puVar6;
  uint uVar7;
  undefined4 uVar8;
  char cVar9;
  uint uVar10;
  int iVar11;
  char cVar12;
  int iVar13;
  uint uVar14;
  undefined4 uVar15;
  int iVar16;
  bool bVar17;
  undefined8 uVar18;
  undefined8 uVar19;
  int iStack_118;
  int iStack_114;
  uint uStack_110;
  uint uStack_10c;
  undefined4 uStack_108;
  uint uStack_104;
  undefined4 uStack_100;
  int iStack_fc;
  int iStack_f8;
  int iStack_f4;
  undefined4 uStack_f0;
  uint uStack_ec;
  int iStack_e8;
  undefined4 uStack_e4;
  int *piStack_e0;
  undefined4 uStack_dc;
  undefined4 uStack_d8;
  undefined4 uStack_d4;
  int iStack_d0;
  uint uStack_cc;
  undefined4 uStack_c8;
  uint uStack_c4;
  int iStack_c0;
  int iStack_bc;
  int iStack_b8;
  undefined4 uStack_b4;
  int iStack_b0;
  int iStack_ac;
  undefined4 uStack_a8;
  uint uStack_a4;
  uint uStack_a0;
  uint uStack_9c;
  uint uStack_98;
  uint uStack_94;
  int iStack_90;
  int iStack_8c;
  undefined4 uStack_88;
  undefined4 uStack_84;
  undefined4 uStack_80;
  undefined4 uStack_7c;
  uint uStack_78;
  int iStack_74;
  int iStack_70;
  int iStack_6c;
  uint uStack_68;
  char *pcStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  uint uStack_58;
  uint uStack_54;
  uint uStack_50;
  uint uStack_4c;
  uint uStack_48;
  undefined4 uStack_44;
  uint uStack_40;
  uint uStack_3c;
  char *pcStack_38;
  int iStack_34;
  int iStack_30;
  int iStack_2c;
  int iStack_28;
  
  iVar13 = *(int *)(param_1 + 0x40);
  uStack_48 = param_6;
  if (iVar13 != 0) {
    uVar10 = *(uint *)(param_1 + 0x44);
    *(uint *)(iVar13 + 4) = uVar10;
    *(int *)(iVar13 + 8) = 1 << 0x20 - (0x20 - (uVar10 & 0x1f));
    _Bfree(param_1);
    *(undefined4 *)(param_1 + 0x40) = 0;
  }
  if ((int)param_4 < 0) {
    *param_8 = 1;
    param_4 = param_4 & 0x7fffffff;
  }
  else {
    *param_8 = 0;
  }
  if ((~param_4 & 0x7ff00000) == 0) {
    *param_7 = (int)&DAT_0000270f;
    if ((param_3 == 0) && ((param_4 & (uint)&DAT_000fffff) == 0)) {
      pcVar3 = "Infinity";
    }
    else {
      pcVar3 = "NaN";
    }
    if (param_9 != (undefined4 *)0x0) {
      iVar13 = 3;
      if (pcVar3[3] != '\0') {
        iVar13 = 8;
      }
      *param_9 = pcVar3 + iVar13;
      return pcVar3;
    }
    return pcVar3;
  }
  piStack_e0 = param_7;
  uStack_60 = 0;
  uStack_5c = 0;
  uVar10 = param_3;
  uVar7 = param_4;
  uStack_58 = param_4;
  uStack_54 = param_3;
  uVar18 = FUN_0022b874(param_3,param_4);
  if ((int)uVar18 == 0) {
    *piStack_e0 = 1;
    if (param_9 != (undefined4 *)0x0) {
      *param_9 = &DAT_00206465;
      return "0";
    }
    return "0";
  }
  uStack_94 = param_4;
  uStack_f0 = __d2b(param_1,(int)((ulonglong)uVar18 >> 0x20),uStack_54,uStack_58,&iStack_118,
                    &iStack_114);
  iStack_70 = iStack_114;
  uVar14 = param_4 >> 0x14 & 0x7ff;
  uStack_44 = uStack_f0;
  if (uVar14 == 0) {
    iVar13 = iStack_118 + iStack_114;
    if (iVar13 < -0x411) {
      uVar14 = uVar10 << 0x20 - (0x20 - (-iVar13 - 0x412U & 0x1f));
    }
    else {
      uVar14 = uVar10 >> (iVar13 + 0x412U & 0x1f) |
               param_4 << 0x20 - (0x20 - (-iVar13 - 0x3f2U & 0x1f));
    }
                    /* XCC soft double [doc, inference] */
    uVar18 = __floatunsidf(uVar14);
    uStack_110 = (uint)uVar18;
    uVar14 = iVar13 - 1;
    uStack_10c = (int)((ulonglong)uVar18 >> 0x20) + 0xfe100000;
    iStack_e8 = 1;
  }
  else {
    uStack_110 = uStack_54;
    iStack_e8 = 0;
    uStack_10c = uStack_58 & (uint)&DAT_000fffff | 0x3ff00000;
    uVar14 = uVar14 - 0x3ff;
  }
                    /* XCC soft double [doc, inference] */
  uVar18 = __floatsidf(uVar14);
                    /* XCC soft double [doc, inference] */
  uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0x509f79fb,0x3fd34413);
  uStack_88 = (undefined4)((ulonglong)uVar18 >> 0x20);
                    /* XCC soft double using the HiFi4 f64 assist ops [doc, inference] */
  uVar19 = __adddf3(0,0xbff80000,uStack_110,uStack_10c);
  uVar19 = __muldf3((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x636f4361,0x3fd287a7);
  uVar19 = __adddf3((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),0x8b60c8b3,0x3fc68a28);
  uVar18 = __adddf3((int)uVar18,uStack_88,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
  uStack_84 = (undefined4)((ulonglong)uVar18 >> 0x20);
  uStack_3c = FUN_00233600();
  iVar13 = FUN_0022b838((int)uVar18,uStack_84,uStack_5c,uStack_60);
  if (iVar13 < 0) {
    uVar19 = __floatsidf(uStack_3c);
    iVar13 = FUN_0022b874((int)uVar19,(int)((ulonglong)uVar19 >> 0x20),(int)uVar18,uStack_84);
    if (iVar13 != 0) {
      uStack_3c = uStack_3c - 1;
    }
  }
  if (((int)uStack_3c < 0) || (0x16 < (int)uStack_3c)) {
    iStack_8c = 1;
  }
  else {
    iVar13 = FUN_0022b838(uStack_54,uStack_58,*(undefined4 *)(&DAT_00206010 + uStack_3c * 8),
                          *(undefined4 *)(&DAT_00206014 + uStack_3c * 8));
    iStack_8c = 0;
    if (iVar13 < 0) {
      uStack_3c = uStack_3c - 1;
    }
  }
  if ((int)(iStack_70 - uVar14) < 1) {
    iStack_90 = (uVar14 - iStack_70) + 1;
    iVar13 = 0;
  }
  else {
    iVar13 = (iStack_70 - uVar14) + -1;
    iStack_90 = 0;
  }
  if ((int)uStack_3c < 0) {
    iStack_74 = -uStack_3c;
    uStack_78 = 0;
    iStack_90 = iStack_90 - uStack_3c;
  }
  else {
    uStack_78 = uStack_3c;
    iStack_74 = 0;
    iVar13 = uStack_3c + iVar13;
  }
  if ((param_5 < 0) || (9 < param_5)) {
    uStack_9c = 1;
    param_5 = 0;
LAB_0022eb80:
    *(undefined4 *)(param_1 + 0x44) = 0;
    iStack_6c = 1;
    uStack_a0 = 0xffffffff;
    uStack_50 = 0xffffffff;
    uStack_48 = 0;
    iVar16 = 0;
  }
  else {
    bVar17 = param_5 < 6;
    if (!bVar17) {
      param_5 = param_5 + -4;
    }
    uStack_9c = (uint)bVar17;
    if ((param_5 == 0) || (param_5 == 1)) goto LAB_0022eb80;
    if (param_5 == 2) {
      iStack_6c = 0;
LAB_0022f7c0:
      uStack_a0 = (1 < (int)uStack_48) * uStack_48 + (uint)(1 >= (int)uStack_48);
      uVar14 = uStack_a0;
      uStack_50 = uStack_a0;
      uStack_48 = uStack_a0;
    }
    else {
      if (param_5 == 4) {
        iStack_6c = 1;
        goto LAB_0022f7c0;
      }
      if (param_5 == 3) {
        iStack_6c = 0;
LAB_0022f81b:
        uStack_a0 = uStack_3c + uStack_48;
        uStack_50 = uStack_a0 + 1;
        uVar14 = 1;
        if (1 < (int)uStack_50) {
          uVar14 = uStack_50;
        }
      }
      else {
        if (param_5 == 5) {
          iStack_6c = 1;
          goto LAB_0022f81b;
        }
        iStack_6c = 1;
        uStack_a0 = 0xffffffff;
        uStack_50 = 0xffffffff;
      }
    }
    *(undefined4 *)(param_1 + 0x44) = 0;
    iVar16 = 0;
    iStack_2c = iVar13;
    if (0x17 < uVar14) {
      iVar4 = 4;
      iVar16 = 0;
      do {
        iVar16 = iVar16 + 1;
        iVar4 = iVar4 * 2;
        *(int *)(param_1 + 0x44) = iVar16;
      } while (iVar4 + 0x14U <= uVar14);
    }
  }
  uStack_a4 = uStack_3c;
  pcStack_64 = (char *)_Balloc(param_1,iVar16);
  uVar18 = CONCAT44(uStack_94,param_3);
  uVar19 = CONCAT44(uStack_94,param_3);
  *(char **)(param_1 + 0x40) = pcStack_64;
  uStack_4c = uStack_50;
  uStack_80 = 0x40240000;
  uStack_7c = 0;
  if ((((int)uStack_50 < 0) || (0xe < (int)uStack_50)) || (uStack_9c == 0)) {
LAB_0022eca8:
    pcStack_38 = pcStack_64;
    uStack_50 = uStack_4c;
    if ((-1 < iStack_118) && (uStack_40 = param_3, (int)uStack_a4 < 0xf)) {
      uVar8 = *(undefined4 *)(&DAT_00206014 + uStack_a4 * 8);
      uVar15 = *(undefined4 *)(&DAT_00206010 + uStack_a4 * 8);
      if ((-1 < (int)uStack_48) || (0 < (int)uStack_4c)) {
        uVar7 = 1;
        uVar10 = uStack_94;
        do {
          __divdf3(uStack_40,uVar10,uVar15,uVar8);
          uStack_68 = FUN_00233600();
          uVar18 = __floatsidf();
          uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar15,uVar8);
          uVar18 = __subdf3(uStack_40,uVar10,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          uVar5 = (undefined4)((ulonglong)uVar18 >> 0x20);
          uStack_40 = (uint)uVar18;
          *pcStack_38 = (char)uStack_68 + '0';
          pcStack_38 = pcStack_38 + 1;
          if (uStack_4c == uVar7) {
            uVar18 = __muldf3(uStack_40,uVar5,0,&RSTCTL0_SYSRSTSTAT);
            uVar5 = (undefined4)((ulonglong)uVar18 >> 0x20);
            iVar13 = FUN_0022b838(uVar15,uVar8,(int)uVar18,uVar5);
            if ((iVar13 < 0) ||
               ((iVar13 = FUN_0022b874(uVar15,uVar8,(int)uVar18,uVar5), iVar13 == 0 &&
                ((uStack_68 & 1) != 0)))) goto LAB_0022f415;
            break;
          }
          uVar18 = __muldf3(uStack_40,uVar5,uStack_7c,uStack_80);
          uVar10 = (uint)((ulonglong)uVar18 >> 0x20);
          uStack_40 = (uint)uVar18;
          iVar13 = FUN_0022b874(uStack_40,uVar10,uStack_5c,uStack_60);
          uVar7 = uVar7 + 1;
        } while (iVar13 != 0);
        goto LAB_0022f134;
      }
      if (-1 < (int)uStack_4c) {
        uVar18 = __muldf3(0,&DAT_40140000,uVar15,uVar8);
        iVar13 = FUN_0022b848(uStack_54,uStack_58,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
        if (0 < iVar13) goto LAB_0022f5fa;
      }
LAB_0022f771:
      iVar4 = 0;
      iVar13 = 0;
LAB_0022f777:
      pcStack_38 = pcStack_64;
      uStack_3c = -uStack_48 - 1;
      goto LAB_0022f789;
    }
    iStack_ac = iStack_74;
    if (iStack_6c == 0) {
      iVar4 = 0;
      iVar16 = iStack_90;
    }
    else {
      if (param_5 < 2) {
        if (iStack_e8 == 0) {
          uVar14 = 0x36 - iStack_114;
        }
        else {
          uVar14 = iStack_118 + 0x433;
        }
        iStack_d0 = iStack_90;
      }
      else {
        if (iStack_74 < (int)(uStack_4c - 1)) {
          uStack_78 = uStack_78 + (uStack_4c - iStack_74) + -1;
          iStack_ac = 0;
          iStack_74 = uStack_4c - 1;
        }
        else {
          iStack_ac = (iStack_74 - uStack_4c) + 1;
        }
        iStack_d0 = iStack_90;
        uVar14 = uStack_4c;
        if ((int)uStack_4c < 0) {
          iStack_d0 = iStack_90 - uStack_4c;
          uVar14 = 0;
        }
      }
      iVar13 = iVar13 + uVar14;
      iStack_90 = iStack_90 + uVar14;
      iVar4 = __i2b(param_1,1);
      iVar16 = iStack_d0;
    }
    if ((0 < iVar16) && (0 < iVar13)) {
      iVar11 = (uint)(iVar13 < iVar16) * iVar13 + (uint)(iVar13 >= iVar16) * iVar16;
      iVar16 = iVar16 - iVar11;
      iStack_90 = iStack_90 - iVar11;
      iVar13 = iVar13 - iVar11;
    }
    if (0 < iStack_74) {
      if (iStack_6c == 0) {
        uStack_44 = __pow5mult(param_1,uStack_f0,iStack_74);
      }
      else {
        if (0 < iStack_ac) {
          iVar4 = __pow5mult(param_1,iVar4,iStack_ac);
          uStack_c8 = __multiply(param_1,iVar4,uStack_f0);
          _Bfree(param_1,uStack_f0);
          uStack_44 = uStack_c8;
        }
        if (iStack_74 != iStack_ac) {
          uStack_44 = __pow5mult(param_1,uStack_44);
        }
      }
    }
    iStack_bc = __i2b(param_1,1);
    if (0 < (int)uStack_78) {
      iStack_bc = __pow5mult(param_1,iStack_bc,uStack_78);
    }
    if ((((param_5 < 2) && (uVar10 == 0)) && ((uVar7 & (uint)&DAT_000fffff) == 0)) &&
       ((uVar7 & 0x7ff00000) != 0)) {
      iStack_b8 = 1;
      iStack_90 = iStack_90 + 1;
      iVar11 = iVar13 + 1;
    }
    else {
      iStack_b8 = 0;
      iVar11 = iVar13;
    }
    iStack_2c = iVar13;
    if (uStack_78 == 0) {
      iVar13 = 1;
    }
    else {
      iVar13 = __hi0bits(*(undefined4 *)(*(int *)(iStack_bc + 0x10) * 4 + iStack_bc + 0x10));
      iVar13 = 0x20 - iVar13;
    }
    uVar7 = iVar13 + iVar11 & 0x1f;
    iVar13 = 0;
    if (uVar7 != 0) {
      iVar13 = 0x20 - uVar7;
    }
    if (iVar13 < 5) {
      iStack_d0 = iVar16;
      if (iVar13 < 4) {
        iVar13 = iVar13 + 0x1c;
        iStack_90 = iStack_90 + iVar13;
        iStack_d0 = iVar16 + iVar13;
        iVar11 = iVar11 + iVar13;
      }
    }
    else {
      iVar13 = iVar13 + -4;
      iStack_90 = iStack_90 + iVar13;
      iVar11 = iVar11 + iVar13;
      iStack_d0 = iVar16 + iVar13;
    }
    if (0 < iStack_90) {
      uStack_44 = __lshift(param_1,uStack_44,iStack_90);
    }
    if (0 < iVar11) {
      iStack_bc = __lshift(param_1,iStack_bc,iVar11);
    }
    iVar13 = iStack_bc;
    if ((iStack_8c != 0) && (iVar16 = __mcmp(uStack_44,iStack_bc), iVar16 < 0)) {
      uStack_3c = uStack_a4 - 1;
      uStack_44 = __multadd(param_1,uStack_44,10,0);
      if (iStack_6c != 0) {
        iVar4 = __multadd(param_1,iVar4,10,0);
      }
      uStack_50 = uStack_a0;
    }
    if (((int)uStack_50 < 1) && (2 < param_5)) {
      if (-1 < (int)uStack_50) {
        iVar13 = __multadd(param_1,iVar13,5,0);
        iVar16 = __mcmp(uStack_44,iVar13);
        if (0 < iVar16) goto LAB_0022f5aa;
      }
      goto LAB_0022f777;
    }
    if (iStack_6c != 0) {
      if (0 < iStack_d0) {
        iVar4 = __lshift(param_1,iVar4,iStack_d0);
      }
      iStack_b0 = iVar4;
      if (iStack_b8 != 0) {
        iVar16 = _Balloc(param_1,*(undefined4 *)(iVar4 + 4));
        memcpy(iVar16 + 0xc,iVar4 + 0xc,*(int *)(iVar4 + 0x10) * 4 + 8);
        iVar4 = __lshift(param_1,iVar16,1);
      }
      uStack_cc = uVar10 & 1;
      uVar10 = 1;
      do {
                    /* newlib dtoa.c static [doc, inference] */
        iVar16 = quorem(uStack_44,iVar13);
        uStack_ec = iVar16 + 0x30;
        uStack_c4 = uStack_ec;
        iStack_f4 = __mcmp(uStack_44,iStack_b0);
        iVar16 = __mdiff(param_1,iVar13,iVar4);
        if (*(int *)(iVar16 + 0xc) == 0) {
          iStack_f8 = iVar16;
          iStack_fc = __mcmp(uStack_44,iVar16);
          iVar16 = iStack_f8;
        }
        else {
          iStack_fc = 1;
        }
        _Bfree(param_1,iVar16);
        iVar16 = iStack_b0;
        cVar12 = (char)uStack_ec;
        if (((iStack_fc == 0) && (param_5 == 0)) && (uStack_cc == 0)) {
          if (uStack_ec != 0x39) {
            cVar9 = cVar12 + '\x01';
            if (iStack_f4 < 1) {
              cVar9 = cVar12;
            }
            *pcStack_38 = cVar9;
            pcStack_38 = pcStack_38 + 1;
            goto LAB_0022f112;
          }
LAB_0022f7fd:
          *pcStack_38 = '9';
          pcStack_38 = pcStack_38 + 1;
          goto LAB_0022f739;
        }
        if ((iStack_f4 < 0) || (((iStack_f4 == 0 && (param_5 == 0)) && (uStack_cc == 0)))) {
          if (0 < iStack_fc) {
            uStack_44 = __lshift(param_1,uStack_44,1);
            iVar11 = __mcmp(uStack_44,iVar13);
            if (((0 < iVar11) || ((iVar11 == 0 && ((uStack_ec & 1) != 0)))) &&
               (uStack_c4 = uStack_ec + 1, uStack_c4 == 0x3a)) goto LAB_0022f7fd;
          }
          *pcStack_38 = (char)uStack_c4;
          pcStack_38 = pcStack_38 + 1;
          goto LAB_0022f112;
        }
        if (0 < iStack_fc) {
          if (uStack_ec == 0x39) goto LAB_0022f7fd;
          *pcStack_38 = cVar12 + '\x01';
          pcStack_38 = pcStack_38 + 1;
          goto LAB_0022f112;
        }
        *pcStack_38 = cVar12;
        pcStack_38 = pcStack_38 + 1;
        if (uStack_50 == uVar10) goto LAB_0022f715;
        uStack_44 = __multadd(param_1,uStack_44,10,0);
        if (iVar4 == iStack_b0) {
          iVar4 = __multadd(param_1,iVar4,10,0);
          iStack_b0 = iVar4;
        }
        else {
          iStack_b0 = __multadd(param_1,iStack_b0,10,0);
          iVar4 = __multadd(param_1,iVar4,10,0);
        }
        uVar10 = uVar10 + 1;
      } while( true );
    }
    iVar16 = 1;
    while( true ) {
      iVar11 = quorem(uStack_44,iVar13);
      uStack_c4 = iVar11 + 0x30;
      *pcStack_38 = (char)uStack_c4;
      pcStack_38 = pcStack_38 + 1;
      if ((int)uStack_50 <= iVar16) break;
      uStack_44 = __multadd(param_1,uStack_44,10,0);
      iVar16 = iVar16 + 1;
    }
    iStack_b0 = 0;
LAB_0022f715:
    uStack_44 = __lshift(param_1,uStack_44,1);
    iVar16 = iStack_b0;
    iVar11 = __mcmp(uStack_44,iVar13);
    if ((iVar11 < 1) && ((iVar11 != 0 || ((uStack_c4 & 1) == 0)))) {
      pcVar3 = pcStack_38 + -0x80;
      cVar12 = pcStack_38[-1];
      while (cVar12 == '0') {
        pcVar1 = pcVar3 + 0x7e;
        pcStack_38 = pcStack_38 + -1;
        pcVar3 = pcVar3 + -1;
        cVar12 = *pcVar1;
      }
    }
    else {
LAB_0022f739:
      cVar12 = pcStack_38[-1];
      pcStack_38 = pcStack_38 + -1;
      while (cVar12 == '9') {
        if (pcStack_64 == pcStack_38) {
          *pcStack_38 = '1';
          pcStack_38 = pcStack_38 + 1;
          uStack_3c = uStack_3c + 1;
          goto LAB_0022f112;
        }
        cVar12 = pcStack_38[-1];
        pcStack_38 = pcStack_38 + -1;
      }
      *pcStack_38 = cVar12 + '\x01';
      pcStack_38 = pcStack_38 + 1;
    }
  }
  else {
    uStack_40 = param_3;
    pcStack_38 = pcStack_64;
    iStack_28 = param_5;
    if ((int)uStack_a4 < 1) {
      uVar10 = -uStack_a4;
      iStack_2c = iVar13;
      if (uVar10 != 0) {
        iVar16 = (uVar10 & 0xf) * 8;
        uVar18 = __muldf3(*(undefined4 *)(&DAT_00206010 + iVar16),
                          *(undefined4 *)(&DAT_00206014 + iVar16),uStack_54,uStack_58);
        uStack_94 = (uint)((ulonglong)uVar18 >> 0x20);
        uVar10 = (int)uVar10 >> 4;
        if (uVar10 != 0) {
          puVar6 = &DAT_00206110;
          iStack_34 = 2;
          do {
            if ((uVar10 & 1) != 0) {
              uVar18 = __muldf3(*puVar6,puVar6[1],(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
              iStack_34 = iStack_34 + 1;
            }
            uVar10 = (int)uVar10 >> 1;
            puVar6 = puVar6 + 2;
            iVar13 = iStack_2c;
          } while (uVar10 != 0);
          goto LAB_0022f184;
        }
      }
      iStack_34 = 2;
      iVar13 = iStack_2c;
    }
    else {
      uVar10 = (int)uStack_a4 >> 4;
      uVar2 = *(undefined8 *)(&DAT_00206010 + (uStack_a4 & 0xf) * 8);
      uVar18 = *(undefined8 *)(&DAT_00206010 + (uStack_a4 & 0xf) * 8);
      if ((uStack_a4 >> 8 & 1) == 0) {
        iStack_34 = 2;
        iStack_2c = iVar13;
      }
      else {
        uVar10 = uStack_a4 >> 4 & 0xf;
        iStack_2c = iVar13;
        uVar19 = __divdf3(uStack_54,uStack_58,0x7f73bf3c,0x75154fdd);
        iStack_34 = 3;
      }
      if (uVar10 != 0) {
        puVar6 = &DAT_00206110;
        do {
          uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
          uStack_40 = (uint)uVar19;
          if ((uVar10 & 1) != 0) {
            uVar18 = __muldf3(*puVar6,puVar6[1],(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
            uVar19 = CONCAT44(uStack_94,uStack_40);
            iStack_34 = iStack_34 + 1;
          }
          uVar10 = (int)uVar10 >> 1;
          puVar6 = puVar6 + 2;
          uVar2 = uVar18;
        } while (uVar10 != 0);
      }
      iVar13 = iStack_2c;
      uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
      uStack_40 = (uint)uVar19;
                    /* XCC soft double [doc, inference] */
      uVar18 = __divdf3(uStack_40,uStack_94,(int)uVar2,(int)((ulonglong)uVar2 >> 0x20));
      param_5 = iStack_28;
    }
LAB_0022f184:
    uStack_94 = (uint)((ulonglong)uVar18 >> 0x20);
    uVar8 = (undefined4)uVar18;
    uStack_b4 = 0x3ff00000;
    if (iStack_8c != 0) {
      iVar16 = FUN_0022b838(uVar8,uStack_94,0,0x3ff00000);
      uVar18 = CONCAT44(uStack_94,uVar8);
      if ((-1 < iVar16) || (uVar18 = CONCAT44(uStack_94,uVar8), (int)uStack_4c < 1))
      goto LAB_0022f201;
      iVar16 = 1;
      uVar18 = CONCAT44(uStack_94,uVar8);
      if (0 < (int)uStack_a0) {
        iStack_30 = 0;
        iVar16 = 0;
        uVar18 = CONCAT44(uStack_94,uVar8);
        if (0 < (int)uStack_a0) {
          uStack_50 = uStack_a0;
          uVar18 = __muldf3(uVar8,uStack_94,uStack_7c,uStack_80);
          iStack_34 = iStack_34 + 1;
          uStack_3c = uStack_a4 - 1;
          iVar16 = iStack_30;
        }
      }
      if (iVar16 == 0) goto LAB_0022f201;
LAB_0022ec8d:
      uStack_3c = uStack_a4;
      uStack_94 = uStack_58;
      param_3 = uStack_54;
      uVar10 = uStack_54;
      uVar7 = uStack_58;
      goto LAB_0022eca8;
    }
LAB_0022f201:
    uStack_94 = (uint)((ulonglong)uVar18 >> 0x20);
    uVar15 = (undefined4)uVar18;
    uVar18 = __floatsidf(iStack_34);
    uVar18 = __muldf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar15,uStack_94);
    uStack_e4 = 0;
    uVar18 = __adddf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),0,0x401c0000);
    uVar8 = (undefined4)uVar18;
    uStack_104 = (int)((ulonglong)uVar18 >> 0x20) + 0xfcc00000;
    uStack_108 = uVar8;
    uStack_98 = uStack_104;
    if (uStack_50 != 0) {
      if (iStack_6c != 0) {
        uVar18 = __divdf3(0,0x3fe00000);
                    /* XCC soft double [doc, inference] */
        uVar18 = __subdf3((int)uVar18,(int)((ulonglong)uVar18 >> 0x20),uVar8,uStack_98);
        uVar19 = CONCAT44(uStack_94,uVar15);
        iVar16 = 0;
        while( true ) {
          uStack_94 = (uint)((ulonglong)uVar19 >> 0x20);
          uStack_98 = (uint)((ulonglong)uVar18 >> 0x20);
          uStack_a8 = (undefined4)uVar18;
          iStack_c0 = FUN_00233600((int)uVar19,uStack_94);
          uVar18 = __floatsidf();
          uVar18 = __subdf3((int)uVar19,uStack_94,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          uStack_94 = (uint)((ulonglong)uVar18 >> 0x20);
          uVar8 = (undefined4)uVar18;
          *pcStack_38 = (char)(iStack_c0 + 0x30);
          pcStack_38 = pcStack_38 + 1;
          iVar4 = FUN_0022b838(uVar8,uStack_94,uStack_a8,uStack_98,pcStack_38,iStack_c0 + 0x30,
                               uVar18);
          if (iVar4 < 0) break;
          uVar18 = __subdf3(uStack_e4,uStack_b4,uVar8,uStack_94);
          iVar4 = FUN_0022b858(uStack_a8,uStack_98,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
          if (0 < iVar4) goto LAB_0022f415;
          iVar16 = iVar16 + 1;
          if ((int)uStack_50 <= iVar16) goto LAB_0022ec8d;
          uVar18 = __muldf3(uStack_a8,uStack_98,uStack_7c,uStack_80);
          uStack_98 = (uint)((ulonglong)uVar18 >> 0x20);
          uStack_a8 = (undefined4)uVar18;
          uVar19 = __muldf3(uVar8,uStack_94,uStack_7c,uStack_80);
          uVar18 = CONCAT44(uStack_98,uStack_a8);
        }
        goto LAB_0022f134;
      }
      uStack_d8 = 0x3fe00000;
      uStack_dc = 0;
      uVar19 = __muldf3(*(undefined4 *)(&UNK_00206008 + uStack_50 * 8),
                        *(undefined4 *)(&UNK_0020600c + uStack_50 * 8),uVar8,uStack_104);
      uVar18 = CONCAT44(uStack_94,uVar15);
      uVar10 = 1;
      while( true ) {
        uStack_98 = (uint)((ulonglong)uVar19 >> 0x20);
        uStack_a8 = (undefined4)uVar19;
        uStack_94 = (uint)((ulonglong)uVar18 >> 0x20);
        uStack_d4 = FUN_00233600((int)uVar18,uStack_94);
        uVar19 = __floatsidf();
        uVar18 = __subdf3((int)uVar18,uStack_94,(int)uVar19,(int)((ulonglong)uVar19 >> 0x20));
        uStack_94 = (uint)((ulonglong)uVar18 >> 0x20);
        uStack_40 = (uint)uVar18;
        *pcStack_38 = (char)uStack_d4 + '0';
        pcStack_38 = pcStack_38 + 1;
        if (uStack_50 == uVar10) break;
        uVar18 = __muldf3(uStack_40,uStack_94,uStack_7c,uStack_80);
        uVar19 = CONCAT44(uStack_98,uStack_a8);
        uVar10 = uVar10 + 1;
      }
      uVar18 = __adddf3(uStack_a8,uStack_98,uStack_dc,uStack_d8);
      iVar16 = FUN_0022b858(uStack_40,uStack_94,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
      if (0 < iVar16) {
LAB_0022f415:
        cVar12 = pcStack_38[-1];
        pcStack_38 = pcStack_38 + -1;
        while (cVar12 == '9') {
          if (pcStack_64 == pcStack_38) {
            *pcStack_38 = '0';
            uStack_3c = uStack_3c + 1;
            cVar12 = '0';
            break;
          }
          cVar12 = pcStack_38[-1];
          pcStack_38 = pcStack_38 + -1;
        }
        *pcStack_38 = cVar12 + '\x01';
        pcStack_38 = pcStack_38 + 1;
        goto LAB_0022f134;
      }
      uVar18 = __subdf3(uStack_dc,uStack_d8,uStack_a8,uStack_98);
      iVar16 = FUN_0022b838(uStack_40,uStack_94,(int)uVar18,(int)((ulonglong)uVar18 >> 0x20));
      if (iVar16 < 0) {
        pcVar3 = pcStack_38 + -0x80;
        cVar12 = pcStack_38[-1];
        while (cVar12 == '0') {
          pcVar1 = pcVar3 + 0x7e;
          pcStack_38 = pcStack_38 + -1;
          pcVar3 = pcVar3 + -1;
          cVar12 = *pcVar1;
        }
        goto LAB_0022f134;
      }
      goto LAB_0022ec8d;
    }
    uVar18 = __adddf3(uVar15,uStack_94,0,0xc0140000);
    uStack_100 = (undefined4)((ulonglong)uVar18 >> 0x20);
    iVar16 = FUN_0022b838(uVar8,uStack_98,(int)uVar18,uStack_100);
    if (-1 < iVar16) {
      iVar16 = FUN_0022b838((int)uVar18,uStack_100,uVar8,uStack_98 ^ 0x80000000);
      if (-1 < iVar16) goto LAB_0022ec8d;
      goto LAB_0022f771;
    }
LAB_0022f5fa:
    iVar13 = 0;
    iVar4 = 0;
LAB_0022f5aa:
    *pcStack_64 = '1';
    uStack_3c = uStack_3c + 1;
    pcStack_38 = pcStack_64 + 1;
LAB_0022f789:
    iVar16 = 0;
  }
LAB_0022f112:
  _Bfree(param_1,iVar13);
  if (iVar4 != 0) {
    if ((iVar16 != 0) && (iVar4 != iVar16)) {
      _Bfree(param_1,iVar16);
    }
    _Bfree(param_1,iVar4);
  }
LAB_0022f134:
  _Bfree(param_1,uStack_44);
  *pcStack_38 = '\0';
  *piStack_e0 = uStack_3c + 1;
  if (param_9 != (undefined4 *)0x0) {
    *param_9 = pcStack_38;
    return pcStack_64;
  }
  return pcStack_64;
}


// ===== __sflush_r @ 0022fa00 (373 bytes)

/* newlib fflush.c [inference] */

undefined4 __sflush_r(int *param_1,int *param_2)

{
  ushort uVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  
  uVar1 = *(ushort *)(param_2 + 3);
  iVar5 = param_2[4];
  iVar6 = *param_2;
  if (((uint)(int)(short)uVar1 >> 3 & 1) == 0) {
    *(ushort *)(param_2 + 3) = uVar1 | 0x800;
    if (((0 < param_2[1]) || (0 < param_2[0xf])) &&
       (pcVar4 = (code *)param_2[10], pcVar4 != (code *)0x0)) {
      uVar2 = (uint)(short)param_2[3];
      iVar5 = *param_1;
      *param_1 = 0;
      if ((uVar2 >> 0xc & 1) == 0) {
        iVar6 = (*pcVar4)(param_1,param_2[7],0,1);
        if ((iVar6 == -1) && (iVar3 = *param_1, iVar3 != 0)) {
          if ((iVar3 != 0x1d) && (iVar3 != 0x16)) {
            *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
            return 0xffffffff;
          }
          *param_1 = iVar5;
          return 0;
        }
        uVar2 = (uint)(short)param_2[3];
      }
      else {
        iVar6 = param_2[0x14];
      }
      if ((uVar2 & 4) != 0) {
        iVar6 = iVar6 - param_2[1];
        if (param_2[0xc] != 0) {
          iVar6 = iVar6 - param_2[0xf];
        }
      }
      iVar6 = (*(code *)param_2[10])(param_1,param_2[7],iVar6,0);
      if (((iVar6 == -1) && (iVar3 = *param_1, iVar3 != 0)) && ((iVar3 != 0x1d && (iVar3 != 0x16))))
      {
LAB_0022fb05:
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x40;
        return 0xffffffff;
      }
      uVar1 = *(ushort *)(param_2 + 3);
      param_2[1] = 0;
      *param_2 = param_2[4];
      *(ushort *)(param_2 + 3) = uVar1 & 0xf7ff;
      piVar7 = (int *)param_2[0xc];
      if ((((uint)(int)(short)uVar1 >> 0xc & 1) != 0) && ((iVar6 != -1 || (*param_1 == 0)))) {
        param_2[0x14] = iVar6;
      }
      *param_1 = iVar5;
      if (piVar7 != (int *)0x0) {
        if (piVar7 == param_2 + 0x10) {
          param_2[0xc] = 0;
          return 0;
        }
        _free_r(param_1);
        param_2[0xc] = 0;
        return 0;
      }
    }
  }
  else if (iVar5 != 0) {
    *param_2 = iVar5;
    iVar6 = iVar6 - iVar5;
    iVar3 = 0;
    if (((int)(short)uVar1 & 3U) == 0) {
      iVar3 = param_2[5];
    }
    param_2[2] = iVar3;
    while (0 < iVar6) {
      iVar3 = (*(code *)param_2[9])(param_1,param_2[7],iVar5,iVar6);
      iVar6 = iVar6 - iVar3;
      if (iVar3 < 1) goto LAB_0022fb05;
      iVar5 = iVar5 + iVar3;
    }
  }
  return 0;
}


// ===== _fflush_r @ 0022fb80 (39 bytes)

/* newlib fflush.c: __sinit, __sflush_r; 6 callers [inference] */

undefined4 _fflush_r(int param_1,int param_2)

{
  undefined4 uVar1;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x38) == 0)) {
    __sinit(param_1);
  }
  if (*(short *)(param_2 + 0xc) == 0) {
    return 0;
  }
  uVar1 = __sflush_r(param_1,param_2);
  return uVar1;
}


// ===== fflush @ 0022fbb0 (40 bytes)

/* newlib fflush.c: _fwalk_reent(_GLOBAL_REENT, _fflush_r) when fp is NULL [inference] */

undefined4 fflush(int param_1)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = _fwalk_reent(&DAT_00237ad8,_fflush_r);
    return uVar1;
  }
  uVar1 = _fflush_r(PTR_DAT_00237f00,param_1);
  return uVar1;
}


// ===== __sfmoreglue @ 0022fbe0 (51 bytes)

/* newlib findfp.c: _malloc_r, memset [inference] */

undefined4 * __sfmoreglue(undefined4 param_1,int param_2)

{
  undefined4 *puVar1;
  
  puVar1 = (undefined4 *)_malloc_r(param_1,param_2 * 0x68 + 0xc);
  if (puVar1 == (undefined4 *)0x0) {
    return (undefined4 *)0x0;
  }
  puVar1[1] = param_2;
  *puVar1 = 0;
  puVar1[2] = puVar1 + 3;
  memset(puVar1 + 3,0,param_2 * 0x68);
  return puVar1;
}


// ===== __sfp @ 0022fc20 (170 bytes)

/* newlib findfp.c: lock, __sfmoreglue, memset [inference] */

undefined4 * __sfp(undefined4 *param_1)

{
  undefined4 *puVar1;
  int iVar2;
  undefined4 *puVar3;
  
  __sfp_lock_acquire();
  if (DAT_00237b10 == 0) {
    __sinit();
  }
  puVar3 = &DAT_00237db8;
  do {
    puVar1 = puVar3;
    iVar2 = puVar1[1];
    puVar3 = (undefined4 *)puVar1[2];
    if (-1 < iVar2 + -1) {
      if (iVar2 == 1) {
        isync();
      }
      if ((0 < iVar2) && (*(short *)(puVar3 + 3) == 0)) {
        *(undefined2 *)((int)puVar3 + 0xe) = 0xffff;
        *(undefined2 *)(puVar3 + 3) = 1;
        puVar3[0x19] = 0;
        __sfp_lock_release();
        *puVar3 = 0;
        puVar3[2] = 0;
        puVar3[1] = 0;
        puVar3[4] = 0;
        puVar3[5] = 0;
        puVar3[6] = 0;
        memset(puVar3 + 0x17,0,8);
        puVar3[0xc] = 0;
        puVar3[0xd] = 0;
        puVar3[0x11] = 0;
        puVar3[0x12] = 0;
        return puVar3;
      }
    }
    puVar3 = (undefined4 *)*puVar1;
    if ((undefined4 *)*puVar1 == (undefined4 *)0x0) {
      puVar3 = (undefined4 *)__sfmoreglue(param_1,4);
      *puVar1 = puVar3;
      if (puVar3 == (undefined4 *)0x0) {
        __sfp_lock_release();
        *param_1 = 0xc;
        return (undefined4 *)0x0;
      }
    }
  } while( true );
}


// ===== _cleanup_r @ 0022fce0 (14 bytes)

/* newlib findfp.c: _fwalk(ptr, _fclose_r) [inference] */

void _cleanup_r(undefined4 param_1)

{
  _fwalk(param_1,&LAB_002325d0);
  return;
}


// ===== _cleanup @ 0022fcf0 (13 bytes)

/* newlib findfp.c: _cleanup_r(_GLOBAL_REENT) [inference] */

void _cleanup(void)

{
  _cleanup_r(&DAT_00237ad8);
  return;
}


// ===== __sinit @ 0022fd00 (263 bytes)

/* newlib findfp.c: installs __sread/__swrite/__sseek/__sclose (0x230D80..0x230E40) on stdin/out/err
   [fact for the pointers] */

void __sinit(int param_1)

{
  undefined4 *puVar1;
  undefined4 *puVar2;
  
  __sinit_lock_acquire();
  if (*(int *)(param_1 + 0x38) != 0) {
    __sinit_lock_release();
    return;
  }
  puVar1 = *(undefined4 **)(param_1 + 4);
  *(undefined4 *)(param_1 + 0x38) = 1;
  *(undefined4 *)(param_1 + 0x2e0) = 0;
  *(code **)(param_1 + 0x3c) = _cleanup_r;
  *(undefined4 *)(param_1 + 0x2e4) = 3;
  *(int *)(param_1 + 0x2e8) = param_1 + 0x2ec;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[0x19] = 0;
  *(undefined2 *)((int)puVar1 + 0xe) = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  *(undefined2 *)(puVar1 + 3) = 4;
  puVar1[6] = 0;
  memset(puVar1 + 0x17,0,8);
  puVar1[7] = puVar1;
  puVar1[8] = __sread;
  puVar1[9] = __swrite;
  puVar2 = *(undefined4 **)(param_1 + 8);
  puVar1[10] = __sseek;
  puVar1[0xb] = __sclose;
  *(undefined2 *)((int)puVar2 + 0xe) = 1;
  *puVar2 = 0;
  puVar2[1] = 0;
  puVar2[2] = 0;
  puVar2[0x19] = 0;
  puVar2[4] = 0;
  puVar2[5] = 0;
  *(undefined2 *)(puVar2 + 3) = 9;
  puVar2[6] = 0;
  memset(puVar2 + 0x17,0,8);
  puVar2[7] = puVar2;
  puVar2[9] = __swrite;
  puVar2[8] = __sread;
  puVar1 = *(undefined4 **)(param_1 + 0xc);
  puVar2[10] = __sseek;
  puVar2[0xb] = __sclose;
  *puVar1 = 0;
  puVar1[1] = 0;
  puVar1[2] = 0;
  puVar1[0x19] = 0;
  puVar1[4] = 0;
  puVar1[5] = 0;
  puVar1[6] = 0;
  *(undefined2 *)(puVar1 + 3) = 10;
  *(undefined2 *)((int)puVar1 + 0xe) = 2;
  memset(puVar1 + 0x17,0,8);
  puVar1[0xb] = __sclose;
  puVar1[10] = __sseek;
  puVar1[9] = __swrite;
  puVar1[7] = puVar1;
  puVar1[8] = __sread;
  *(undefined4 *)(param_1 + 0x38) = 1;
  __sinit_lock_release();
  return;
}


// ===== __fp_lock_all @ 0022fe10 (19 bytes)

/* newlib findfp.c: _fwalk(_impure_ptr, __fp_lock 0x235F80) [inference] */

void __fp_lock_all(void)

{
  __sfp_lock_acquire();
  _fwalk(PTR_DAT_00237f00,&LAB_00235f80);
  return;
}


// ===== __fp_unlock_all @ 0022fe30 (19 bytes)

/* newlib findfp.c: _fwalk(_impure_ptr, __fp_unlock 0x235F90) [inference] */

void __fp_unlock_all(void)

{
  _fwalk(PTR_DAT_00237f00,&LAB_00235f90);
  __sfp_lock_release();
  return;
}


// ===== _free_r @ 0022fe50 (564 bytes)

/* newlib mallocr.c: __malloc_lock, _malloc_trim_r [inference] */

void _free_r(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined *puVar4;
  uint uVar5;
  undefined **ppuVar6;
  int *piVar7;
  int *piVar8;
  uint uVar9;
  uint uVar10;
  undefined *puVar11;
  
  if (param_2 == 0) {
    return;
  }
                    /* XOS clib support [doc, inference] */
  __malloc_lock(param_1);
  uVar5 = *(uint *)(param_2 + -4);
  uVar9 = uVar5 & 0xfffffffe;
  piVar7 = (int *)(uVar9 + param_2);
  piVar8 = (int *)(param_2 + -8);
  uVar10 = piVar7[-1] & 0xfffffffc;
  if ((int *)PTR_DAT_00237f28 == piVar7 + -2) {
    puVar11 = (undefined *)(uVar9 + uVar10);
    if ((uVar5 & 1) == 0) {
      iVar1 = *piVar8;
      piVar8 = (int *)((int)piVar8 - iVar1);
      iVar2 = piVar8[2];
      iVar3 = piVar8[3];
      *(int *)(iVar2 + 0xc) = iVar3;
      *(int *)(iVar3 + 8) = iVar2;
      puVar11 = puVar11 + iVar1;
    }
    piVar8[1] = (uint)puVar11 | 1;
    PTR_DAT_00237f28 = (undefined *)piVar8;
    if (PTR_DAT_00237f14 <= puVar11) {
      _malloc_trim_r(param_1,DAT_002cd708);
    }
                    /* XOS clib support [doc, inference] */
    __malloc_unlock(param_1);
    return;
  }
  piVar7[-1] = uVar10;
  if ((uVar5 & 1) == 0) {
    iVar1 = *piVar8;
    piVar8 = (int *)((int)piVar8 - iVar1);
    ppuVar6 = (undefined **)piVar8[2];
    uVar9 = uVar9 + iVar1;
    puVar11 = (undefined *)piVar8[3];
    if (ppuVar6 == &PTR_DAT_00237f28) {
      if ((*(uint *)((int)piVar7 + (uVar10 - 4)) & 1) == 0) {
        iVar2 = *piVar7;
        iVar1 = piVar7[1];
        *(int *)(iVar2 + 0xc) = iVar1;
        uVar9 = uVar9 + uVar10;
        *(int *)(iVar1 + 8) = iVar2;
        piVar8[1] = uVar9 | 1;
        *(uint *)(uVar9 + (int)piVar8) = uVar9;
      }
      else {
        piVar8[1] = uVar9 | 1;
        *(uint *)((int)piVar8 + uVar9) = uVar9;
      }
      goto LAB_0022feea;
    }
    uVar5 = *(uint *)((int)piVar7 + (uVar10 - 4));
    ppuVar6[3] = puVar11;
    *(undefined ***)(puVar11 + 8) = ppuVar6;
    if ((uVar5 & 1) == 0) {
      ppuVar6 = (undefined **)*piVar7;
      uVar9 = uVar9 + uVar10;
      if (ppuVar6 == &PTR_DAT_00237f28) goto LAB_00230050;
      puVar11 = (undefined *)piVar7[1];
      ppuVar6[3] = puVar11;
      *(undefined ***)(puVar11 + 8) = ppuVar6;
      piVar8[1] = uVar9 | 1;
      *(uint *)(uVar9 + (int)piVar8) = uVar9;
    }
    else {
      piVar8[1] = uVar9 | 1;
      *(uint *)((int)piVar8 + uVar9) = uVar9;
    }
  }
  else if ((*(uint *)((int)piVar7 + (uVar10 - 4)) & 1) == 0) {
    ppuVar6 = (undefined **)*piVar7;
    uVar9 = uVar9 + uVar10;
    if (ppuVar6 == &PTR_DAT_00237f28) {
LAB_00230050:
      PTR_PTR_00237f30 = (undefined *)piVar8;
      PTR_PTR_00237f34 = (undefined *)piVar8;
      piVar8[3] = (int)&PTR_DAT_00237f28;
      piVar8[2] = (int)&PTR_DAT_00237f28;
      piVar8[1] = uVar9 | 1;
      *(uint *)((int)piVar8 + uVar9) = uVar9;
      goto LAB_0022feea;
    }
    puVar11 = (undefined *)piVar7[1];
    ppuVar6[3] = puVar11;
    *(undefined ***)(puVar11 + 8) = ppuVar6;
    *(uint *)(param_2 + -4) = uVar9 | 1;
    *(uint *)(uVar9 + (int)piVar8) = uVar9;
  }
  else {
    *(uint *)(param_2 + -4) = uVar9 | 1;
    *(uint *)(uVar9 + (int)piVar8) = uVar9;
  }
  uVar5 = uVar9 >> 9;
  if (uVar9 < 0x200) {
    uVar9 = uVar9 >> 3;
    DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar9 >> 2 & 0x1fU));
    piVar8[3] = (int)(&DAT_00237f20 + uVar9 * 8);
    puVar11 = (&PTR_DAT_00237f28)[uVar9 * 2];
    piVar8[2] = (int)puVar11;
    (&PTR_DAT_00237f28)[uVar9 * 2] = (undefined *)piVar8;
    *(int **)(puVar11 + 0xc) = piVar8;
  }
  else {
    if (uVar5 == 0) {
      uVar5 = uVar9 >> 3;
    }
    else if (uVar5 < 5) {
      uVar5 = (uVar9 >> 6) + 0x38;
    }
    else if (uVar5 < 0x15) {
      uVar5 = uVar5 + 0x5b;
    }
    else if (uVar5 < 0x55) {
      uVar5 = (uVar9 >> 0xc) + 0x6e;
    }
    else if (uVar5 < 0x155) {
      uVar5 = (uVar9 >> 0xf) + 0x77;
    }
    else if (uVar5 < 0x555) {
      uVar5 = (uVar9 >> 0x12) + 0x7c;
    }
    else {
      uVar5 = 0x7e;
    }
    puVar4 = &DAT_00237f20 + uVar5 * 8;
    puVar11 = (&PTR_DAT_00237f28)[uVar5 * 2];
    if (puVar4 == puVar11) {
      DAT_00237f24 = DAT_00237f24 | 1 << 0x20 - (0x20 - ((int)uVar5 >> 2 & 0x1fU));
    }
    else {
      uVar5 = *(uint *)(puVar11 + 4);
      while ((uVar9 < (uVar5 & 0xfffffffc) &&
             (puVar11 = *(undefined **)(puVar11 + 8), puVar4 != puVar11))) {
        uVar5 = *(uint *)(puVar11 + 4);
      }
      puVar4 = *(undefined **)(puVar11 + 0xc);
    }
    piVar8[2] = (int)puVar11;
    piVar8[3] = (int)puVar4;
    *(int **)(puVar4 + 8) = piVar8;
    *(int **)(puVar11 + 0xc) = piVar8;
  }
LAB_0022feea:
  __malloc_unlock(param_1);
  return;
}


// ===== _malloc_trim_r @ 00230090 (197 bytes)

/* newlib mallocr.c: sbrk(0), sbrk(-extra) [inference] */

undefined4 _malloc_trim_r(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
                    /* XOS clib support [doc, inference] */
  __malloc_lock(param_1);
  uVar4 = *(uint *)(PTR_DAT_00237f28 + 4) & 0xfffffffc;
  uVar3 = (uVar4 - param_2) + 0xfef & 0xfffff000;
  if ((int)(uVar3 - 0x1000) < 0x1000) {
    __malloc_unlock(param_1);
    return 0;
  }
                    /* heap break 0x2CD6D8 [doc, inference] */
  puVar1 = (undefined *)_sbrk_r(param_1,0);
  if (puVar1 != PTR_DAT_00237f28 + uVar4) {
                    /* XOS clib support [doc, inference] */
    __malloc_unlock(param_1);
    return 0;
  }
  iVar2 = _sbrk_r(param_1,(int)&DAT_00001000 - uVar3);
  if (iVar2 == -1) {
    iVar2 = _sbrk_r(param_1,0);
    if (0xf < iVar2 - (int)PTR_DAT_00237f28) {
      DAT_002cd70c = iVar2 - DAT_00237f10;
      *(uint *)(PTR_DAT_00237f28 + 4) = iVar2 - (int)PTR_DAT_00237f28 | 1;
    }
    __malloc_unlock(param_1);
    return 0;
  }
  *(uint *)(PTR_DAT_00237f28 + 4) = uVar4 - (uVar3 - 0x1000) | 1;
  DAT_002cd70c = (DAT_002cd70c - uVar3) + 0x1000;
  __malloc_unlock(param_1);
  return 1;
}


// ===== _setlocale_r @ 00230160 (52 bytes)

/* newlib locale.c: compares with "C", "POSIX" (0x206478), "" [inference] */

undefined * _setlocale_r(undefined4 param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  
  if (((param_3 != 0) && (iVar1 = strcmp(param_3,"POSIX"), iVar1 != 0)) &&
     (iVar1 = strcmp(param_3,&DAT_00206410), iVar1 != 0)) {
    iVar1 = strcmp(param_3,"");
    if (iVar1 != 0) {
      return (undefined *)0x0;
    }
  }
  return &DAT_00206410;
}


// ===== FUN_002301a0 @ 002301a0 (8 bytes)

char * FUN_002301a0(void)

{
  return s_ASCII_00238370;
}


// ===== __locale_mb_cur_max @ 002301b0 (10 bytes)

/* newlib locale.c: current locale 0x238330 [inference] */

undefined4 __locale_mb_cur_max(void)

{
  return DAT_00238330;
}


// ===== FUN_002301c0 @ 002301c0 (8 bytes)

char * FUN_002301c0(void)

{
  return s_ASCII_00238390;
}


// ===== FUN_002301d0 @ 002301d0 (10 bytes)

undefined4 FUN_002301d0(void)

{
  return DAT_002cd73c;
}


// ===== _localeconv_r @ 002301e0 (8 bytes)

/* newlib localeconv.c: lconv 0x238334; used by _vfprintf_r [inference] */

undefined ** _localeconv_r(void)

{
  return &PTR_DAT_00238334;
}


// ===== setlocale @ 002301f0 (24 bytes)

/* newlib locale.c: _setlocale_r(_impure_ptr) [inference] */

undefined4 setlocale(undefined4 param_1,undefined4 param_2)

{
  undefined4 uVar1;
  
  uVar1 = _setlocale_r(PTR_DAT_00237f00,param_1,param_2);
  return uVar1;
}


// ===== localeconv @ 00230210 (18 bytes)

/* newlib localeconv.c [inference] */

undefined4 localeconv(void)

{
  undefined4 uVar1;
  
  uVar1 = _localeconv_r(PTR_DAT_00237f00);
  return uVar1;
}


// ===== __smakebuf_r @ 00230230 (260 bytes)

/* newlib makebuf.c: __swhatbuf_r, _malloc_r; 0x800 / 0xF000 st_mode masks [inference] */

void __smakebuf_r(int param_1,int *param_2)

{
  bool bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_60 [4];
  uint uStack_5c;
  
  uVar4 = (uint)(short)param_2[3];
  if ((uVar4 >> 1 & 1) != 0) {
    param_2[5] = 1;
    *param_2 = (int)param_2 + 0x43;
    param_2[4] = (int)param_2 + 0x43;
    return;
  }
  if (-1 < *(short *)((int)param_2 + 0xe)) {
    iVar2 = FUN_00233200(param_1,(int)*(short *)((int)param_2 + 0xe),auStack_60);
    if (-1 < iVar2) {
      bVar1 = (uStack_5c & (uint)&DAT_0000f000) == 0x2000;
      if (((uStack_5c & (uint)&DAT_0000f000) == 0x8000) && ((code *)param_2[10] == __sseek)) {
        param_2[0x13] = 0x400;
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x400;
      }
      else {
        *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x800;
      }
      iVar2 = 0x400;
      goto LAB_00230290;
    }
    uVar4 = (uint)(short)param_2[3];
  }
  bVar1 = false;
  *(ushort *)(param_2 + 3) = (ushort)uVar4 | 0x800;
  iVar2 = 0x400;
  if ((uVar4 & 0x80) != 0) {
    iVar2 = 0x40;
  }
LAB_00230290:
  iVar3 = _malloc_r(param_1,iVar2);
  if (iVar3 == 0) {
    if (((uint)(int)(short)*(ushort *)(param_2 + 3) >> 9 & 1) == 0) {
      param_2[5] = 1;
      *param_2 = (int)param_2 + 0x43;
      param_2[4] = (int)param_2 + 0x43;
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 2;
      return;
    }
  }
  else {
    *(code **)(param_1 + 0x3c) = _cleanup_r;
    *param_2 = iVar3;
    param_2[4] = iVar3;
    param_2[5] = iVar2;
    *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 0x80;
    if ((bVar1) && (iVar2 = __swhatbuf_r(param_1,(int)*(short *)((int)param_2 + 0xe)), iVar2 != 0))
    {
      *(ushort *)(param_2 + 3) = *(ushort *)(param_2 + 3) | 1;
      return;
    }
  }
  return;
}


// ===== memchr @ 00230340 (139 bytes)

/* newlib memchr; called by _vfprintf_r, _vfiprintf_r and __sfvwrite_r [inference] */

uint * memchr(uint *param_1,char param_2,uint param_3)

{
  uint uVar1;
  
  while( true ) {
    if (((uint)param_1 & 3) == 0) {
      if (3 < param_3) {
        if (param_3 >> 2 == 1) {
          isync();
        }
        if ((param_3 >> 2 != 0) &&
           (uVar1 = *param_1 ^ CONCAT22(CONCAT11(param_2,param_2),CONCAT11(param_2,param_2)),
           (uVar1 + 0xfefefeff & (uVar1 ^ 0xffffffff) & 0x80808080) == 0)) {
          param_1 = param_1 + 1;
          param_3 = param_3 - 4;
        }
      }
      if (param_3 == 0) {
        return (uint *)0x0;
      }
      if (param_3 == 1) {
        isync();
      }
      if ((param_3 != 0) && ((char)*param_1 == param_2)) {
        return param_1;
      }
      return (uint *)0x0;
    }
    param_3 = param_3 - 1;
    if (param_3 == 0xffffffff) {
      return (uint *)0x0;
    }
    if ((char)*param_1 == param_2) break;
    param_1 = (uint *)((int)param_1 + 1);
  }
  return param_1;
}


// ===== _Balloc @ 002303d0 (98 bytes)

/* newlib mprec.c: freelist, _calloc_r; 8 callers in dtoa [inference] */

int * _Balloc(int param_1,uint param_2)

{
  int *piVar1;
  int *piVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 0x4c);
  if (iVar3 == 0) {
    iVar3 = _calloc_r(param_1,4,0x21);
    *(int *)(param_1 + 0x4c) = iVar3;
    if (iVar3 == 0) {
      return (int *)0x0;
    }
  }
  piVar2 = (int *)(param_2 * 4 + iVar3);
  piVar1 = (int *)*piVar2;
  if (piVar1 == (int *)0x0) {
    iVar3 = 1 << 0x20 - (0x20 - (param_2 & 0x1f));
                    /* _malloc_r then memset [doc, inference] */
    piVar1 = (int *)_calloc_r(param_1,1,iVar3 * 4 + 0x14);
    if (piVar1 == (int *)0x0) {
      return (int *)0x0;
    }
    piVar1[1] = param_2;
    piVar1[2] = iVar3;
    piVar1[4] = 0;
    piVar1[3] = 0;
    return piVar1;
  }
  *piVar2 = *piVar1;
  piVar1[4] = 0;
  piVar1[3] = 0;
  return piVar1;
}


// ===== __multadd @ 00230440 (159 bytes)

/* newlib mprec.c: _Balloc, Bcopy (memcpy), _Bfree [inference] */

int __multadd(undefined4 param_1,int param_2,int param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  
  iVar1 = *(int *)(param_2 + 0x10);
  iVar4 = iVar1;
  if (iVar1 < 1) {
    iVar4 = 1;
  }
  if ((0 < iVar4) && ((iVar4 == 1 || (0 < iVar4)))) {
    uVar3 = param_4 + param_3 * (*(uint *)(param_2 + 0x14) & 0xffff);
    uVar2 = (uVar3 >> 0x10) + param_3 * (*(uint *)(param_2 + 0x14) >> 0x10);
    param_4 = uVar2 >> 0x10;
    *(uint *)(param_2 + 0x14) = (uVar3 & 0xffff) + uVar2 * 0x10000;
  }
  if (param_4 != 0) {
    if (*(int *)(param_2 + 8) <= iVar1) {
      iVar4 = _Balloc(param_1,*(int *)(param_2 + 4) + 1);
      memcpy(iVar4 + 0xc,param_2 + 0xc,*(int *)(param_2 + 0x10) * 4 + 8);
      _Bfree(param_1,param_2);
      *(uint *)(iVar4 + iVar1 * 4 + 0x14) = param_4;
      *(int *)(iVar4 + 0x10) = iVar1 + 1;
      return iVar4;
    }
    *(uint *)(iVar1 * 4 + param_2 + 0x14) = param_4;
    *(int *)(param_2 + 0x10) = iVar1 + 1;
    return param_2;
  }
  return param_2;
}


// ===== __s2b @ 002304f0 (159 bytes)

/* newlib mprec.c: __multadd [inference] */

int __s2b(undefined4 param_1,int param_2,int param_3,int param_4,undefined4 param_5)

{
  byte *pbVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  byte *pbVar5;
  
  iVar4 = (param_4 + 8) / 9;
  if (iVar4 < 2) {
    iVar3 = 0;
  }
  else {
    iVar3 = 0;
    iVar2 = 1;
    do {
      iVar2 = iVar2 << 1;
      iVar3 = iVar3 + 1;
    } while (iVar2 < iVar4);
  }
  iVar4 = _Balloc(param_1,iVar3);
  *(undefined4 *)(iVar4 + 0x14) = param_5;
  *(undefined4 *)(iVar4 + 0x10) = 1;
  if (param_3 < 10) {
    pbVar5 = (byte *)(param_2 + 10);
    iVar3 = 9;
  }
  else {
    iVar2 = param_3 + -9;
    if (iVar2 < 1) {
      iVar2 = 1;
    }
    iVar3 = param_2 + 0x12;
    do {
      iVar4 = __multadd(param_1,iVar4,10,*(byte *)(iVar3 + -9) - 0x30);
      iVar3 = iVar3 + 1;
    } while (iVar3 < param_3 + param_2 + 9);
    iVar3 = iVar2 + 9;
    pbVar5 = (byte *)(param_2 + 9 + iVar2 + 1);
  }
  if (iVar3 < param_4) {
    pbVar1 = pbVar5 + (param_4 - iVar3);
    do {
      iVar4 = __multadd(param_1,iVar4,10,*pbVar5 - 0x30);
      pbVar5 = pbVar5 + 1;
    } while (pbVar5 != pbVar1);
  }
  return iVar4;
}

