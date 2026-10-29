// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== dmac9_rspi_tx_setup @ 20137910 (476 bytes)

/* arg 1 RSPI0 (0x121), 0 RSPI1 */

void dmac9_rspi_tx_setup(int param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = DAT_e8200468;
  DAT_e8200468 = uVar1 | 2;
  uVar1 = DAT_e8200468;
  DAT_e8200468 = uVar1 | 8;
  gic_disable_irq(0x32);
  DAT_20808a98 = 0;
  uVar1 = DAT_fcfe1010;
  DAT_fcfe1010 = uVar1 & 0xffff;
  uVar1 = DAT_fcfe1010;
  if (param_1 == 0) {
    uVar2 = 0x1250000;
  }
  else {
    uVar2 = 0x1210000;
  }
  DAT_fcfe1010 = uVar1 | uVar2;
  DAT_e820046c = 0;
  FUN_20157160(&DAT_e820046c,0,0x10,0xf0000);
  FUN_20157160(&DAT_e820046c,0,0xc,0xf000);
  FUN_20157160(&DAT_e820046c,1,0x15,0x200000);
  FUN_20157160(&DAT_e820046c,0,0x14,0x100000);
  FUN_20157160(&DAT_e820046c,0,0x1f,0x80000000);
  FUN_20157160(&DAT_e820046c,0,0x1c,0x10000000);
  FUN_20157160(&DAT_e820046c,1,0x1b,0x8000000);
  FUN_20157160(&DAT_e820046c,0,0x18,0x1000000);
  FUN_20157160(&DAT_e820046c,0,0x1e,0x40000000);
  FUN_20157160(&DAT_e820046c,0,0x1d,0x20000000);
  FUN_20157160(&DAT_e820046c,0,0x16,0x400000);
  FUN_20157160(&DAT_e820046c,2,8,0x700);
  FUN_20157160(&DAT_e820046c,1,6,0x40);
  FUN_20157160(&DAT_e820046c,1,5,0x20);
  FUN_20157160(&DAT_e820046c,0,4,0x10);
  FUN_20157160(&DAT_e820046c,0,3,8);
  FUN_20157160(&DAT_e820046c,1,0,7);
  DAT_e8200470 = 0;
  DAT_e8200474 = 0;
  gic_enable_irq(0x32);
  return;
}


// ===== dmac9_isr @ 20137aec (12 bytes)

/* stub -> [0x20808AAC] */

void dmac9_isr(void)

{
                    /* WARNING: Could not recover jumptable at 0x20137af4. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20808aac)();
  return;
}


// ===== dmac10_register_isr @ 20137af8 (12 bytes)

void dmac10_register_isr(void)

{
  itron_acre_isr(0,&DAT_20420100);
  return;
}


// ===== dmac10_rspi_rx_setup @ 20137b04 (536 bytes)

/* arg 1 RSPI0 (0x122) */

void dmac10_rspi_rx_setup(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  uVar3 = 0;
  uVar1 = DAT_e82004a8;
  DAT_e82004a8 = uVar1 | 2;
  uVar1 = DAT_e82004a8;
  DAT_e82004a8 = uVar1 | 8;
  gic_disable_irq(0x33);
  DAT_20808a9c = 0;
  uVar1 = DAT_fcfe1014;
  DAT_fcfe1014 = uVar1 & 0xffff0000;
  uVar1 = DAT_fcfe1014;
  if (param_1 == 0) {
    uVar2 = 0x126;
  }
  else {
    uVar2 = 0x122;
  }
  DAT_fcfe1014 = uVar1 | uVar2;
  DAT_e82004ac = 0;
  FUN_20157160(&DAT_e82004ac,0,0x10,0xf0000,uVar3);
  FUN_20157160(&DAT_e82004ac,0,0xc,0xf000);
  FUN_20157160(&DAT_e82004ac,0,0x15,0x200000);
  FUN_20157160(&DAT_e82004ac,1,0x14,0x100000);
  FUN_20157160(&DAT_e82004ac,0,0x1f,0x80000000);
  FUN_20157160(&DAT_e82004ac,0,0x1c,0x10000000);
  FUN_20157160(&DAT_e82004ac,1,0x1b,0x8000000);
  FUN_20157160(&DAT_e82004ac,0,0x18,0x1000000);
  FUN_20157160(&DAT_e82004ac,0,0x1e,0x40000000);
  FUN_20157160(&DAT_e82004ac,0,0x1d,0x20000000);
  FUN_20157160(&DAT_e82004ac,0,0x16,0x400000);
  FUN_20157160(&DAT_e82004ac,2,8,0x700);
  FUN_20157160(&DAT_e82004ac,1,6,0x40);
  FUN_20157160(&DAT_e82004ac,1,5,0x20);
  FUN_20157160(&DAT_e82004ac,0,4,0x10);
  FUN_20157160(&DAT_e82004ac,0,3,8);
  FUN_20157160(&DAT_e82004ac,2,0,7);
  DAT_e82004b0 = 0;
  DAT_e82004b4 = 0;
  DAT_e8200480 = param_2;
  DAT_e8200484 = param_3;
  DAT_e8200488 = param_4;
  gic_enable_irq(0x33);
  FUN_20157160(&DAT_e82004a8,1,0);
  return;
}


// ===== dmac10_isr @ 20137d1c (12 bytes)

/* stub -> [0x20808AB0] */

void dmac10_isr(void)

{
                    /* WARNING: Could not recover jumptable at 0x20137d24. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  (*DAT_20808ab0)();
  return;
}


// ===== dmac3_enable @ 20137d50 (20 bytes)

void dmac3_enable(void)

{
  FUN_20157160(&DAT_e82000e8,1,0);
  return;
}


// ===== dmac3_disable @ 20137d64 (20 bytes)

/* writes 0 to SETEN (no-op?) */

void dmac3_disable(void)

{
  FUN_20157160(&DAT_e82000e8,0,0,1);
  return;
}


// ===== FUN_20137d78 @ 20137d78 (12 bytes)

void FUN_20137d78(undefined4 param_1)

{
  uRam20808aa0 = param_1;
  return;
}


// ===== dmac5_enable @ 20137d84 (20 bytes)

void dmac5_enable(void)

{
  FUN_20157160(&DAT_e8200168,1,0);
  return;
}


// ===== dmac5_disable @ 20137d98 (20 bytes)

void dmac5_disable(void)

{
  FUN_20157160(&DAT_e8200168,0,0,1);
  return;
}


// ===== dmac5_set_callback @ 20137dac (12 bytes)

void dmac5_set_callback(undefined4 param_1)

{
  DAT_20808aa8 = param_1;
  return;
}


// ===== dmac4_enable @ 20137db8 (20 bytes)

void dmac4_enable(void)

{
  FUN_20157160(&DAT_e8200128,1,0);
  return;
}


// ===== dmac4_disable @ 20137dcc (20 bytes)

void dmac4_disable(void)

{
  FUN_20157160(&DAT_e8200128,0,0,1);
  return;
}


// ===== dmac4_set_callback @ 20137de0 (12 bytes)

void dmac4_set_callback(undefined4 param_1)

{
  DAT_20808aa4 = param_1;
  return;
}


// ===== dmac9_stop @ 20137e00 (52 bytes)

/* CHCTRL.CLREN */

void dmac9_stop(void)

{
  FUN_20157160(&DAT_e8200468,0,0,1);
  FUN_20157160(&DAT_e8200468,1,1,2);
  return;
}


// ===== dmac9_set_callback @ 20137e34 (12 bytes)

void dmac9_set_callback(undefined4 param_1)

{
  DAT_20808aac = param_1;
  return;
}


// ===== dmac10_enable @ 20137e40 (20 bytes)

void dmac10_enable(void)

{
  FUN_20157160(&DAT_e82004a8,1,0);
  return;
}


// ===== dmac10_stop @ 20137e54 (52 bytes)

void dmac10_stop(void)

{
  FUN_20157160(&DAT_e82004a8,0,0,1);
  FUN_20157160(&DAT_e82004a8,1,1,2);
  return;
}


// ===== dmac10_set_callback @ 20137e88 (12 bytes)

void dmac10_set_callback(undefined4 param_1)

{
  DAT_20808ab0 = param_1;
  return;
}


// ===== FUN_20137eac @ 20137eac (256 bytes)

int FUN_20137eac(undefined4 param_1,int param_2,int param_3,int param_4,int param_5,int param_6,
                int param_7,int param_8,int param_9,int param_10)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  if (0 < DAT_20808ab4) {
    do {
      piVar2 = (int *)(&DAT_2090a3f8)[iVar1];
      if (((((((*piVar2 < 0) || (*piVar2 == param_2)) && ((piVar2[1] < 0 || (piVar2[1] == param_3)))
             ) && ((piVar2[2] < 0 || (piVar2[2] == param_4)))) &&
           ((piVar2[3] < 0 || (piVar2[3] == param_5)))) &&
          ((((piVar2[4] < 0 || (piVar2[4] == param_6)) &&
            ((piVar2[5] < 0 || (piVar2[5] == param_7)))) &&
           ((piVar2[6] < 0 || (piVar2[6] == param_8)))))) &&
         ((piVar2[7] < 0 || (piVar2[7] == param_9)))) {
        if (piVar2[8] < 0) {
          return iVar1;
        }
        if (piVar2[8] == param_10) {
          return iVar1;
        }
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < DAT_20808ab4);
  }
  return -1;
}


// ===== FUN_20137fac @ 20137fac (1124 bytes)

undefined4 FUN_20137fac(uint param_1,int param_2,undefined4 *param_3)

{
  char cVar1;
  char cVar2;
  char cVar3;
  byte bVar4;
  byte bVar5;
  byte bVar6;
  byte bVar7;
  short sVar8;
  short sVar9;
  int iVar10;
  int iVar11;
  uint uVar12;
  byte *pbVar13;
  code *pcVar14;
  int iVar15;
  undefined4 *puVar16;
  uint uVar17;
  uint uVar18;
  uint uVar19;
  int iVar20;
  uint unaff_r7;
  int iVar21;
  int iVar22;
  
  if (((param_1 < 2) && (0 < param_2)) && (param_2 < 2)) {
    iVar10 = param_1 * 0x904 + 0x2090a458 + param_2 * 0x904;
    iVar20 = iVar10 + -0x904;
    iVar11 = 1;
    do {
      iVar21 = iVar11 * 4;
      iVar11 = iVar11 + 1;
      *(undefined4 *)(iVar20 + iVar21 + 0x8d8) = 0;
    } while (iVar11 < 10);
    *(undefined4 **)(iVar10 + -0x2c) = param_3;
    *(uint *)(iVar10 + -0x8fc) = param_1;
    *(int *)(iVar10 + -0x8f4) = param_2;
    *(undefined1 *)(iVar10 + -0x8e4) = *(undefined1 *)((int)param_3 + 0x1a);
    *(undefined1 *)(iVar10 + -0x8e3) = *(undefined1 *)((int)param_3 + 0x1b);
    *(undefined1 *)(iVar10 + -0x8e2) = *(undefined1 *)(param_3 + 7);
    *(undefined2 *)(iVar10 + -0x8e0) = *(undefined2 *)((int)param_3 + 0x1e);
    *(undefined2 *)(iVar10 + -0x8de) = *(undefined2 *)(param_3 + 8);
    *(undefined2 *)(iVar10 + -0x8dc) = *(undefined2 *)((int)param_3 + 0x22);
    *(undefined1 *)(iVar10 + -0x8da) = *(undefined1 *)(param_3 + 9);
    *(undefined1 *)(iVar10 + -0x8d9) = *(undefined1 *)((int)param_3 + 0x25);
    *(undefined1 *)(iVar10 + -0x8d8) = *(undefined1 *)((int)param_3 + 0x26);
    memclr(iVar10 + -0xa4,0x78);
    *param_3 = 1;
    uVar12 = FUN_2013b3a8(param_3,iVar10 + -0x8b6,0x7ff);
    if (-1 < (int)uVar12) {
      uVar17 = 0xffffffff;
      if ((int)(uint)*(ushort *)(iVar10 + -0x8b4) < (int)uVar12) {
        uVar12 = (uint)*(ushort *)(iVar10 + -0x8b4);
      }
      uVar19 = uVar12;
      for (pbVar13 = (byte *)(iVar10 + -0x8b6); (byte *)(iVar20 + uVar12 + 0x4e) != pbVar13;
          pbVar13 = pbVar13 + uVar18) {
        uVar18 = (uint)*pbVar13;
        if (uVar18 == 0) {
          return 0xffffffff;
        }
        if ((int)uVar19 < (int)uVar18) {
          return 0xffffffff;
        }
        if ((pbVar13[1] == 2) && ((int)uVar17 < 0)) {
          uVar17 = (uint)pbVar13[5];
        }
        uVar19 = uVar19 - uVar18;
      }
      *(undefined1 *)(iVar20 + uVar12 + 0x4e) = 0;
      if (-1 < (int)uVar17) {
        FUN_2013b43c(param_3);
        iVar11 = 0;
        if (0 < DAT_20808ab4) {
          do {
            if ((&DAT_2090a428)[iVar11] == 0) {
              *(int *)(iVar10 + -0x900) = iVar11;
              *(undefined4 *)(iVar10 + -4) = *(undefined4 *)((&DAT_2090a3f8)[iVar11] + 0x24);
              (**(code **)((&DAT_2090a3f8)[iVar11] + 0x24))(param_1,param_2,iVar20);
              if (-1 < *(int *)(iVar10 + -0x900)) {
                return 0;
              }
            }
            iVar11 = iVar11 + 1;
          } while (iVar11 < DAT_20808ab4);
        }
        cVar1 = *(char *)(param_3 + 9);
        sVar8 = *(short *)((int)param_3 + 0x1e);
        sVar9 = *(short *)(param_3 + 8);
        cVar2 = *(char *)((int)param_3 + 0x25);
        cVar3 = *(char *)((int)param_3 + 0x26);
        iVar11 = FUN_20137eac(param_1,*(undefined1 *)((int)param_3 + 0x1a),
                              *(undefined1 *)((int)param_3 + 0x1b),*(undefined1 *)(param_3 + 7),
                              sVar8,sVar9,*(undefined2 *)((int)param_3 + 0x22),cVar1,cVar2,cVar3);
        if (-1 < iVar11) {
          pcVar14 = *(code **)((&DAT_2090a3f8)[iVar11] + 0x24);
          *(code **)(iVar10 + -4) = pcVar14;
          if (pcVar14 != (code *)0x0) {
            iVar11 = 1;
            iVar21 = 0;
            pbVar13 = (byte *)(iVar10 + -0x8b6);
            do {
              if ((int)uVar12 < 1) {
                *(int *)(iVar10 + -0x8e8) = iVar11;
                (*pcVar14)(param_1,param_2,iVar20);
                return 0;
              }
              uVar17 = (uint)*pbVar13;
              if (pbVar13[1] == 4) {
                unaff_r7 = (uint)pbVar13[2];
              }
              else if (pbVar13[1] == 5) {
                bVar4 = pbVar13[5];
                iVar22 = iVar21 + 1;
                bVar5 = pbVar13[4];
                bVar6 = pbVar13[3];
                bVar7 = pbVar13[6];
                iVar15 = iVar20 + iVar22 * 0xc;
                *(byte *)(iVar15 + 0x860) = pbVar13[2];
                *(byte *)(iVar15 + 0x861) = bVar6;
                *(uint *)(iVar15 + 0x864) = (uint)bVar5 + (uint)bVar4 * 0x100;
                *(uint *)(iVar15 + 0x868) = (uint)bVar7;
                if (cVar1 == '\b') {
                  if (((cVar2 != '\x06') || (cVar3 != 'P')) || ((~bVar6 & 3) != 0))
                  goto LAB_20138360;
                }
                else if ((cVar1 != '\x03') ||
                        (((((iVar11 != 2 && ((sVar8 != 0x1ea7 || sVar9 != 0x66 || (unaff_r7 == 1))))
                           && ((sVar8 != 0x25a7 || ((sVar9 != -0x59f || (unaff_r7 == 1)))))) &&
                          ((sVar8 != 0x45e || ((sVar9 != 0x7b2 || (unaff_r7 == 1)))))) &&
                         ((sVar8 != 0x56e || sVar9 != 0x134 || (unaff_r7 == 1)))))) {
LAB_20138360:
                  *(uint *)(iVar10 + -0xb4) = unaff_r7;
                  puVar16 = (undefined4 *)FUN_2013a90c(param_3,pbVar13);
                  if (puVar16 == (undefined4 *)0x0) {
                    iVar21 = 1;
                    if (1 < iVar11) {
                      do {
                        iVar15 = iVar20 + iVar21 * 4;
                        if (*(int *)(iVar15 + 0x8d8) != 0) {
                          FUN_2013ad24();
                          *(undefined4 *)(iVar15 + 0x8d8) = 0;
                        }
                        iVar21 = iVar21 + 1;
                      } while (iVar21 < iVar11);
                    }
                    *(undefined4 *)(iVar10 + -0x2c) = 0;
                    return 0xffffffff;
                  }
                  *puVar16 = 0;
                  iVar11 = iVar11 + 1;
                  *(undefined4 **)(iVar20 + iVar22 * 4 + 0x8d8) = puVar16;
                  iVar21 = iVar22;
                }
              }
              pbVar13 = pbVar13 + uVar17;
              uVar12 = uVar12 - uVar17;
            } while( true );
          }
        }
      }
    }
  }
  return 0xffffffff;
}


// ===== FUN_20138410 @ 20138410 (40 bytes)

undefined4 FUN_20138410(uint param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if ((((param_1 < 2) && (0 < param_2)) && (param_2 < 2)) && (param_3 != 0)) {
    iVar1 = param_1 * 0x904 + 0x2090a458 + param_2 * 0x904;
    if (*(code **)(iVar1 + -4) != (code *)0x0) {
      (**(code **)(iVar1 + -4))(param_1,param_2,0);
    }
    iVar4 = *(int *)(iVar1 + -0x8e8);
    if (*(int *)(*(int *)(param_3 + 8) + 0x48) == param_3) {
      FUN_2013ad24(*(int *)(param_3 + 8) + 0x40);
    }
    iVar2 = 1;
    if (1 < iVar4) {
      do {
        iVar3 = iVar1 + -0x904 + iVar2 * 4;
        if (*(int *)(iVar3 + 0x8d8) != 0) {
          FUN_2013ad24();
          *(undefined4 *)(iVar3 + 0x8d8) = 0;
        }
        iVar2 = iVar2 + 1;
      } while (iVar2 < iVar4);
    }
    *(undefined4 *)(iVar1 + -0x2c) = 0;
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20138438 @ 20138438 (156 bytes)

undefined4 FUN_20138438(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar1 = param_1 * 0x904 + 0x2090a458 + param_2 * 0x904;
  if (*(code **)(iVar1 + -4) != (code *)0x0) {
    (**(code **)(iVar1 + -4))(param_1,param_2,0);
  }
  iVar4 = *(int *)(iVar1 + -0x8e8);
  if (*(int *)(*(int *)(param_3 + 8) + 0x48) == param_3) {
    FUN_2013ad24(*(int *)(param_3 + 8) + 0x40);
  }
  iVar2 = 1;
  if (1 < iVar4) {
    do {
      iVar3 = iVar1 + -0x904 + iVar2 * 4;
      if (*(int *)(iVar3 + 0x8d8) != 0) {
        FUN_2013ad24();
        *(undefined4 *)(iVar3 + 0x8d8) = 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < iVar4);
  }
  *(undefined4 *)(iVar1 + -0x2c) = 0;
  return 0;
}


// ===== FUN_201384d4 @ 201384d4 (164 bytes)

undefined4 FUN_201384d4(int *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  
  iVar2 = DAT_20808ab4;
  if (DAT_20808ab4 < 0xc) {
    uVar4 = (uint)(-1 < *param_1);
    if (-1 < param_1[1]) {
      uVar4 = 1;
    }
    if (-1 < param_1[2]) {
      uVar4 = 1;
    }
    if (-1 < param_1[3]) {
      uVar4 = 1;
    }
    if (-1 < param_1[4]) {
      uVar4 = 1;
    }
    if (-1 < param_1[5]) {
      uVar4 = 1;
    }
    if (-1 < param_1[6]) {
      uVar4 = 1;
    }
    if (-1 < param_1[7]) {
      uVar4 = 1;
    }
    if (-1 < param_1[8]) {
      uVar4 = 1;
    }
    piVar1 = &DAT_2090a3f8 + DAT_20808ab4;
    DAT_20808ab4 = DAT_20808ab4 + 1;
    *piVar1 = (int)param_1;
    (&DAT_2090a428)[iVar2] = uVar4;
    uVar3 = 0;
  }
  else {
    uVar3 = 0xffffffff;
  }
  return uVar3;
}


// ===== FUN_2013857c @ 2013857c (40 bytes)

int FUN_2013857c(int param_1,int param_2)

{
  return param_1 * 0x904 + param_2 * 0x904 + 0x20909b54;
}


// ===== FUN_201385b4 @ 201385b4 (172 bytes)

undefined4 FUN_201385b4(void)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = 0;
  DAT_20808ab8 = 0;
  do {
    iVar2 = usbh_create_objects(iVar4,&DAT_2090b660 + iVar4 * 0x4d8);
    uVar1 = DAT_20808ab8;
    if (iVar2 < 0) {
      return 0xffffffff;
    }
    iVar2 = 1;
    do {
      iVar3 = iVar2 + 1;
      *(uint *)(&DAT_2090b660 + iVar4 * 0x4d8 + iVar2 * 0x70 + 0x88) =
           iVar4 * 0x8100 + iVar2 * 0x2040 + uVar1 + 0x20909fd0 & ~uVar1;
      iVar2 = iVar3;
    } while (iVar3 < 5);
    FUN_2014e73c((&DAT_2090b684)[iVar4 * 0x136]);
    FUN_2014e73c((&DAT_2090b688)[iVar4 * 0x136]);
    FUN_2013b2b4(iVar4);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 2);
  return 0;
}


// ===== FUN_20138660 @ 20138660 (8 bytes)

undefined4 FUN_20138660(void)

{
  return 0;
}


// ===== FUN_20138668 @ 20138668 (8 bytes)

undefined4 FUN_20138668(void)

{
  return 0;
}


// ===== FUN_20138670 @ 20138670 (36 bytes)

undefined4 FUN_20138670(int param_1)

{
  *(undefined2 *)(*(int *)(*(int *)(param_1 + 4) + 8) + (&DAT_20420144)[*(int *)(param_1 + 0xc)]) =
       0x100;
  return 0;
}


// ===== FUN_20138694 @ 20138694 (40 bytes)

uint FUN_20138694(undefined4 param_1,int *param_2)

{
  uint uVar1;
  
  if (*param_2 == 1) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0;
    if (param_2[6] != 0) {
      uVar1 = 0x80;
    }
    uVar1 = uVar1 | param_2[5];
  }
  return uVar1;
}


// ===== FUN_201386bc @ 201386bc (132 bytes)

undefined4 FUN_201386bc(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int extraout_r3;
  int iVar3;
  int iVar4;
  undefined4 extraout_r12;
  
  iVar3 = *(int *)(param_1 + 8);
  iVar4 = *(int *)(param_1 + 0xc);
  if (iVar3 != 0) {
    if (*(int *)(param_1 + 4) == 0) {
      return 0;
    }
    iVar2 = 1;
    do {
      iVar1 = iVar3 + iVar2 * 0x70;
      if ((((*(int *)(iVar1 + 0x50) != 0) && (*(int *)(iVar1 + 0x48) != 0)) &&
          (*(int *)(*(int *)(iVar1 + 0x48) + 0xc) == iVar4)) &&
         (iVar1 = FUN_20138694(0,iVar1 + 0x40), iVar2 = extraout_r3, iVar1 == param_2)) {
        return extraout_r12;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 10);
  }
  return 0;
}


// ===== FUN_20138740 @ 20138740 (52 bytes)

void FUN_20138740(int param_1,int param_2,ushort param_3)

{
  FUN_2013b54c();
  do {
  } while ((*(ushort *)(*(int *)(param_1 + 8) + param_2) & 0x27) != (param_3 & 0x27));
  return;
}


// ===== FUN_20138774 @ 20138774 (676 bytes)

int FUN_20138774(int param_1,int param_2,undefined1 *param_3,int param_4)

{
  undefined1 *puVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint local_3c [2];
  int iStack_34;
  int iStack_30;
  undefined1 *local_2c;
  int iStack_28;
  
  uVar2 = *(undefined4 *)(param_1 + 0x38);
  iVar5 = -0x3ec;
  uVar3 = *(undefined4 *)(param_1 + 100);
  iStack_34 = param_1;
  iStack_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  if (param_4 == 0) {
LAB_201388b0:
    if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
      *(undefined4 *)(param_1 + 0x58) = 1;
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
      *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) & 0xffef
      ;
      FUN_20152bb0(uVar2,0xffffffff);
      *(ushort *)(*(int *)(param_1 + 8) + 0x20) = *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xffd8
      ;
      FUN_20138740(param_1,0x20,0);
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
      FUN_201511e8(uVar2);
      FUN_2014eb94(uVar3,0);
      *(undefined4 *)(param_1 + 0x84) = 0;
      *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0x81;
      iVar4 = itron_twai_flg(uVar3,0x1b,1,local_3c,500);
      if (((iVar4 == 0) && ((local_3c[0] & 8) == 0 && (local_3c[0] & 0x10) == 0)) &&
         (((local_3c[0] & 2) != 0 || (iVar5 = param_4, (local_3c[0] & 1) != 0)))) goto LAB_20138994;
    }
  }
  else if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
    *(undefined4 *)(param_1 + 0x58) = 0;
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
    *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) | 0x110;
    FUN_20152bb0(uVar2,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
         *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0x100 | 0x20;
    FUN_20138740(param_1,0x20);
    puVar1 = local_2c;
    for (iVar4 = param_4; 0 < iVar4; iVar4 = iVar4 + -1) {
      *(undefined1 *)(*(int *)(param_1 + 8) + 0x17) = *puVar1;
      puVar1 = puVar1 + 1;
    }
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x8000;
    FUN_201511e8(uVar2);
    FUN_2014eb94(uVar3,0);
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0x81;
    iVar4 = itron_twai_flg(uVar3,0x1b,1,local_3c,500);
    if ((iVar4 == 0) && ((local_3c[0] & 8) == 0 && (local_3c[0] & 0x10) == 0)) {
      if ((local_3c[0] & 2) != 0) goto LAB_20138994;
      if ((local_3c[0] & 1) != 0) goto LAB_201388b0;
    }
  }
  iVar5 = -1;
LAB_20138994:
  *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
  if (iVar5 < 0) {
    iVar4 = 0;
    do {
      if ((*(ushort *)(*(int *)(param_1 + 8) + 0x60) & 0x20) == 0) break;
      itron_dly_tsk(5);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x32);
    FUN_20152bb0(uVar2,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
         *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xfff8 | 0x20;
    FUN_20138740(param_1,0x20);
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
    FUN_201511e8(uVar2);
  }
  return iVar5;
}


// ===== FUN_20138a18 @ 20138a18 (620 bytes)

int FUN_20138a18(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_28;
  
  uVar1 = *(undefined4 *)(param_1 + 0x38);
  uVar5 = *(undefined4 *)(param_1 + 100);
  if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
    *(undefined4 *)(param_1 + 0x58) = 1;
    *(undefined4 *)(param_1 + 0x78) = 0;
    *(undefined4 *)(param_1 + 0x70) = param_3;
    *(undefined4 *)(param_1 + 0x74) = param_4;
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
    *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) & 0xfeef;
    FUN_20152bb0(uVar1,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) = *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xffd8;
    FUN_20138740(param_1,0x20,0);
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
    FUN_201511e8(uVar1);
    FUN_2014eb94(uVar5,0);
    *(undefined4 *)(param_1 + 0x84) = 0;
    *(ushort *)(*(int *)(param_1 + 8) + 0x60) = *(ushort *)(*(int *)(param_1 + 8) + 0x60) | 0x81;
    iVar2 = itron_twai_flg(uVar5,0x1b,1,&local_28,500);
    if ((iVar2 == 0) && ((local_28 & 8) == 0 && (local_28 & 0x10) == 0)) {
      iVar2 = -0x3ec;
      if ((local_28 & 2) != 0) goto LAB_20138c04;
      if ((((local_28 & 1) != 0) && (iVar4 = *(int *)(param_1 + 0x78), *(int *)(param_2 + 4) != 0))
         && (*(int *)(param_2 + 0x30) == 0)) {
        *(undefined4 *)(param_1 + 0x58) = 0;
        *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
        *(ushort *)(*(int *)(param_1 + 8) + 0x5c) = *(ushort *)(*(int *)(param_1 + 8) + 0x5c) | 0x10
        ;
        FUN_20152bb0(uVar1,0xffffffff);
        *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
             *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0x100 | 0x20;
        FUN_20138740(param_1,0x20);
        *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0xc000;
        FUN_201511e8(uVar1);
        FUN_2014eb94(uVar5,0);
        *(undefined4 *)(param_1 + 0x84) = 0;
        *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0x81;
        iVar3 = itron_twai_flg(uVar5,0x1b,1,&local_28,500);
        if (((iVar3 == 0) && ((local_28 & 8) == 0 && (local_28 & 0x10) == 0)) &&
           (((local_28 & 2) != 0 || (iVar2 = iVar4, (local_28 & 1) != 0)))) goto LAB_20138c04;
      }
    }
  }
  iVar2 = -1;
LAB_20138c04:
  *(undefined2 *)(*(int *)(param_1 + 8) + 0x60) = 0;
  if (iVar2 < 0) {
    iVar4 = 0;
    do {
      if ((*(ushort *)(*(int *)(param_1 + 8) + 0x60) & 0x20) == 0) break;
      itron_dly_tsk(5);
      iVar4 = iVar4 + 1;
    } while (iVar4 < 0x32);
    FUN_20152bb0(uVar1,0xffffffff);
    *(ushort *)(*(int *)(param_1 + 8) + 0x20) =
         *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xfff8 | 0x20;
    FUN_20138740(param_1,0x20);
    *(undefined2 *)(*(int *)(param_1 + 8) + 0x22) = 0x4000;
    FUN_201511e8(uVar1);
  }
  return iVar2;
}


// ===== FUN_20138c84 @ 20138c84 (108 bytes)

undefined4 FUN_20138c84(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 8) != 0)) {
    *(ushort *)
     (*(int *)(*(int *)(param_1 + 8) + 8) + *(int *)(&DAT_20420184 + *(int *)(param_1 + 0xc) * 4)) =
         (ushort)*(byte *)(param_1 + 0x15) << 8 |
         *(short *)(&DAT_20420114 + (uint)*(byte *)(param_1 + 0x18) * 2) << 6 |
         (ushort)*(byte *)(param_1 + 0x19) | (ushort)*(byte *)(param_1 + 0x14) << 0xb;
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20138cf0 @ 20138cf0 (504 bytes)

undefined4
FUN_20138cf0(undefined4 param_1,int param_2,byte *param_3,undefined4 param_4,undefined4 param_5)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  uint local_3c [2];
  undefined4 uStack_34;
  int iStack_30;
  byte *pbStack_2c;
  undefined4 local_28;
  
  iVar4 = 0;
  if (param_2 == 0) {
    uVar1 = 0xffffffff;
  }
  else {
    iVar3 = *(int *)(param_2 + 8);
    uVar5 = *(undefined4 *)(iVar3 + 0x4a8);
    uStack_34 = param_1;
    iStack_30 = param_2;
    pbStack_2c = param_3;
    local_28 = param_4;
    FUN_20152bb0(uVar5,0xffffffff);
    if ((*(int *)(param_2 + 4) != 0) && (*(int *)(param_2 + 0x30) == 0)) {
      *(undefined4 *)(iVar3 + 0x8c) = *(undefined4 *)(param_2 + 0x2c);
      *(undefined4 *)(iVar3 + 0x90) = *(undefined4 *)(param_2 + 0x30);
      *(int *)(iVar3 + 0x48) = param_2;
      FUN_20138c84(param_2);
      if ((*(char *)(param_2 + 0x16) == '\0') && (*(char *)(param_2 + 0x18) == '\x02')) {
        *(ushort *)(*(int *)(iVar3 + 8) + 0x3c) = *(ushort *)(*(int *)(iVar3 + 8) + 0x3c) | 0x100;
      }
      do {
        uVar1 = *(undefined4 *)(param_2 + 0x10);
        *(undefined4 *)(iVar3 + 0x6c) = uVar1;
        *(ushort *)(*(int *)(iVar3 + 8) + 0x5e) =
             (ushort)uVar1 | (ushort)*(byte *)(param_2 + 0xc) << 0xc;
        *(undefined2 *)(*(int *)(iVar3 + 8) + 0x54) = *(undefined2 *)param_3;
        *(undefined2 *)(*(int *)(iVar3 + 8) + 0x56) = *(undefined2 *)(param_3 + 2);
        *(undefined2 *)(*(int *)(iVar3 + 8) + 0x58) = *(undefined2 *)(param_3 + 4);
        *(undefined2 *)(*(int *)(iVar3 + 8) + 0x5a) = *(undefined2 *)(param_3 + 6);
        *(undefined2 *)(*(int *)(iVar3 + 8) + 0x5c) = 0;
        FUN_2014eb94(*(undefined4 *)(iVar3 + 0x1c),0xfffffffc);
        *(undefined2 *)(*(int *)(iVar3 + 8) + 0x60) = 0x4000;
        iVar2 = itron_twai_flg(*(undefined4 *)(iVar3 + 0x1c),3,1,local_3c,500);
        if (iVar2 != 0) {
          uVar1 = 0xffffffff;
          *(ushort *)(*(int *)(iVar3 + 8) + 0x60) = *(ushort *)(*(int *)(iVar3 + 8) + 0x60) | 0x800;
          goto LAB_20138ea8;
        }
        if ((local_3c[0] & 2) == 0) {
          if ((*param_3 & 0x80) == 0) {
            uVar1 = FUN_20138774(iVar3,param_2,local_28,param_5);
          }
          else {
            uVar1 = FUN_20138a18();
          }
          if ((((*param_3 & 0xe0) != 0) || (param_3[1] != 1)) ||
             ((iVar4 = FUN_201386bc(param_2,*(undefined2 *)(param_3 + 4)), iVar4 != 0 &&
              (iVar4 = FUN_20138670(), iVar4 == 0)))) goto LAB_20138ea8;
          break;
        }
        iVar4 = iVar4 + 1;
      } while (iVar4 < 3);
    }
    uVar1 = 0xffffffff;
LAB_20138ea8:
    if ((*(char *)(param_2 + 0x16) == '\0') && (*(char *)(param_2 + 0x18) == '\x02')) {
      *(ushort *)(*(int *)(iVar3 + 8) + 0x3c) = *(ushort *)(*(int *)(iVar3 + 8) + 0x3c) & 0xfeff;
    }
    *(undefined4 *)(iVar3 + 0x48) = 0;
    FUN_201511e8(uVar5);
  }
  return uVar1;
}


// ===== FUN_20138f00 @ 20138f00 (20 bytes)

void FUN_20138f00(void)

{
  FUN_20138cf0();
  return;
}


// ===== FUN_20138f1c @ 20138f1c (28 bytes)

longlong FUN_20138f1c(int param_1,int param_2,uint param_3)

{
  *(undefined2 *)(*(int *)(param_1 + 8) + param_2) = 0;
  return (ulonglong)param_3 << 0x20;
}


// ===== FUN_20138f30 @ 20138f30 (40 bytes)

undefined4 FUN_20138f30(int param_1,undefined4 *param_2)

{
  undefined4 uVar1;
  
  if (param_1 == 0) {
    uVar1 = 0x18;
  }
  else {
    if (param_1 != 1) {
      return 0xffffffff;
    }
    uVar1 = 0x1c;
  }
  *param_2 = uVar1;
  return 0;
}


// ===== FUN_20138f58 @ 20138f58 (132 bytes)

undefined4 FUN_20138f58(int param_1,undefined2 *param_2,uint param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = *(int *)(param_1 + 8);
  uVar2 = param_3;
  if ((~(uint)param_2 & 1) != 0) {
    uVar2 = param_3 & 1;
    for (iVar1 = (int)param_3 / 2; 0 < iVar1; iVar1 = iVar1 + -1) {
      *(undefined2 *)(iVar3 + 0x16) = *param_2;
      param_2 = param_2 + 1;
    }
  }
  *(ushort *)(*(int *)(param_1 + 8) + 0x20) = *(ushort *)(*(int *)(param_1 + 8) + 0x20) & 0xf3ff;
  for (; 0 < (int)uVar2; uVar2 = uVar2 - 1) {
    *(undefined1 *)(iVar3 + 0x17) = *(undefined1 *)param_2;
    param_2 = (undefined2 *)((int)param_2 + 1);
  }
  return 0;
}


// ===== FUN_20138fdc @ 20138fdc (672 bytes)

/* WARNING: Removing unreachable block (ram,0x201390f0) */

int FUN_20138fdc(int param_1,uint param_2,uint param_3,int param_4)

{
  undefined4 uVar1;
  undefined4 uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  uint local_44;
  undefined1 local_40 [4];
  int local_3c;
  int iStack_34;
  uint uStack_30;
  uint local_2c;
  int iStack_28;
  
  if (param_2 == 0) {
    iVar5 = 2;
  }
  else {
    iVar5 = *(int *)(param_1 + 0x3c);
  }
  uVar1 = *(undefined4 *)(param_1 + iVar5 * 4 + 0x30);
  iVar4 = *(int *)(&DAT_2042016c + iVar5 * 4);
  iVar7 = *(int *)(&DAT_20420178 + iVar5 * 4);
  iVar6 = (&DAT_20420144)[param_2];
  local_3c = param_1 + param_2 * 0x70;
  uVar2 = *(undefined4 *)(local_3c + 100);
  iStack_34 = param_1;
  uStack_30 = param_2;
  local_2c = param_3;
  iStack_28 = param_4;
  FUN_20152bb0(uVar1,0xffffffff);
  param_2 = param_2 & 0xffff;
  if ((local_2c & 1) == 0) {
    param_2 = param_2 | 0x400;
  }
  if (iVar5 != 2 && param_4 != 0) {
    param_2 = param_2 | 0x1000;
  }
  *(ushort *)(*(int *)(param_1 + 8) + iVar4) =
       *(ushort *)(*(int *)(param_1 + 8) + iVar4) & 0x100 | (ushort)param_2;
  FUN_20138740(param_1,iVar4,param_2);
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 0;
  if (param_4 == 0) {
    *(undefined2 *)(*(int *)(param_1 + 8) + iVar7) = 0xc000;
  }
  else {
    if (iVar5 == 2) {
      FUN_20138f58(param_1,local_2c,param_4);
    }
    else {
      FUN_20138f30(iVar5,local_40);
    }
    *(undefined2 *)(*(int *)(param_1 + 8) + iVar7) = 0x8000;
  }
  if (iVar5 != 2 && param_4 != 0) {
    *(ushort *)(*(int *)(param_1 + 8) + iVar4) = *(ushort *)(*(int *)(param_1 + 8) + iVar4) & 0xeff8
    ;
  }
  FUN_201511e8(uVar1);
  FUN_2014eb94(uVar2,0);
  *(undefined4 *)(local_3c + 0x84) = 0;
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 1;
  iVar3 = itron_twai_flg(uVar2,0x1b,1,&local_44,500);
  iVar5 = 0;
  if (iVar3 != 0) {
    iVar5 = -1;
  }
  if ((local_44 & 8) != 0) {
    iVar5 = -1;
  }
  if ((local_44 & 0x10) != 0) {
    iVar5 = -1;
  }
  if ((local_44 & 2) != 0) {
    iVar5 = -0x3ec;
  }
  if ((local_44 & 1) == 0 && iVar5 == 0) {
    iVar5 = -1;
  }
  else if (iVar5 == 0) {
    return 0;
  }
  FUN_20152bb0(uVar1,0xffffffff);
  *(ushort *)(*(int *)(param_1 + 8) + iVar4) =
       *(ushort *)(*(int *)(param_1 + 8) + iVar4) & 0x100 | (ushort)param_2;
  FUN_20138740(param_1,iVar4,param_2);
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 0;
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar7) = 0x4000;
  *(ushort *)(*(int *)(param_1 + 8) + iVar4) = *(ushort *)(*(int *)(param_1 + 8) + iVar4) & 0x100;
  FUN_201511e8(uVar1);
  iVar4 = 0;
  do {
    if ((*(ushort *)(*(int *)(param_1 + 8) + iVar6) & 0x20) == 0) break;
    itron_dly_tsk(5);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x32);
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 0x200;
  *(undefined2 *)(*(int *)(param_1 + 8) + iVar6) = 0;
  return iVar5;
}


// ===== FUN_2013927c @ 2013927c (180 bytes)

int FUN_2013927c(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  
  iVar6 = *(int *)(param_1 + 4);
  iVar5 = *(int *)(param_1 + 0xc);
  iVar4 = *(int *)(*(int *)(iVar6 + 0x4d4) + iVar5 * 4 + -4);
  if ((*(int *)(*(int *)(param_1 + 8) + 4) == 0) || (*(int *)(*(int *)(param_1 + 8) + 0x30) != 0)) {
    return -1;
  }
  iVar1 = param_3;
  if (param_3 == 0) {
    iVar4 = FUN_20138fdc(iVar6,iVar5,0);
    if (iVar4 != 0) {
      return -1;
    }
  }
  else {
    for (; 0 < iVar1; iVar1 = iVar1 - iVar3) {
      iVar3 = iVar4;
      if (iVar1 <= iVar4) {
        iVar3 = iVar1;
      }
      iVar2 = FUN_20138fdc(iVar6,iVar5,param_2,iVar3);
      if (iVar2 != 0) {
        return iVar2;
      }
      param_2 = param_2 + iVar3;
    }
  }
  return param_3;
}


// ===== FUN_20139330 @ 20139330 (20 bytes)

undefined4 FUN_20139330(uint param_1)

{
  undefined4 uVar1;
  
  uVar1 = 0;
  if ((param_1 & DAT_20808ab8) != 0) {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_20139344 @ 20139344 (144 bytes)

int FUN_20139344(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar3 = 0;
  iVar1 = FUN_20139330(param_2);
  iVar2 = 0;
  if (iVar1 != 0) {
    iVar2 = param_3;
  }
  if (iVar1 == 0 || param_3 == 0) {
    iVar3 = FUN_2013927c(param_1,param_2,param_3);
  }
  else if (-1 < iVar2) {
    do {
      iVar2 = param_3;
      if (0x2000 < param_3) {
        iVar2 = 0x2000;
      }
      memcpy(*(undefined4 *)(param_1 + 0x48),param_2 + iVar3,iVar2);
      iVar2 = FUN_2013927c(param_1,*(undefined4 *)(param_1 + 0x48),iVar2);
      if (iVar2 < 0) {
        return iVar2;
      }
      param_3 = param_3 - iVar2;
      iVar3 = iVar3 + iVar2;
    } while (0 < param_3);
  }
  return iVar3;
}


// ===== FUN_201393d4 @ 201393d4 (444 bytes)

int FUN_201393d4(int param_1,undefined4 param_2,int param_3)

{
  undefined2 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 uVar7;
  uint local_24;
  
  iVar3 = *(int *)(param_1 + 4);
  iVar2 = *(int *)(param_1 + 0xc);
  iVar6 = *(int *)(&DAT_2042012c + iVar2 * 4);
  iVar4 = iVar3 + iVar2 * 0x70;
  iVar5 = (&DAT_20420144)[iVar2];
  uVar7 = *(undefined4 *)(iVar4 + 100);
  if ((*(int *)(*(int *)(param_1 + 8) + 4) == 0) || (*(int *)(*(int *)(param_1 + 8) + 0x30) != 0)) {
    return -1;
  }
  if (*(int *)(param_1 + 0x1c) == 0) {
    if (3 < iVar2 - 1U) {
      return -1;
    }
    *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(&DAT_20420118 + iVar2 * 4)) =
         *(ushort *)(*(int *)(iVar3 + 8) + *(int *)(&DAT_20420118 + iVar2 * 4)) | 0x100;
    uVar1 = __aeabi_uidivmod(param_3 + *(int *)(param_1 + 0x2c) + -1);
    *(undefined2 *)(*(int *)(iVar3 + 8) + iVar6) = uVar1;
  }
  *(int *)(iVar4 + 0x74) = param_3;
  *(undefined4 *)(iVar4 + 0x78) = 0;
  *(undefined4 *)(iVar4 + 0x70) = param_2;
  FUN_2014eb94(uVar7,0);
  *(undefined4 *)(iVar4 + 0x84) = 0;
  *(undefined2 *)(*(int *)(iVar3 + 8) + iVar5) = 1;
  iVar2 = itron_twai_flg(uVar7,0x1b,1,&local_24,0xffffffff);
  if ((iVar2 == 0) && ((local_24 & 8) == 0 && (local_24 & 0x10) == 0)) {
    if ((local_24 & 2) != 0) {
      iVar2 = -0x3ec;
      goto LAB_2013950c;
    }
    if ((local_24 & 1) != 0) {
      iVar2 = *(int *)(iVar4 + 0x78);
      if (-1 < iVar2) {
        return iVar2;
      }
      goto LAB_2013950c;
    }
  }
  iVar2 = -1;
LAB_2013950c:
  *(undefined2 *)(*(int *)(iVar3 + 8) + iVar5) = 0;
  FUN_20152bb0(*(undefined4 *)(iVar3 + 0x38),0xffffffff);
  *(ushort *)(*(int *)(iVar3 + 8) + 0x20) = *(ushort *)(*(int *)(iVar3 + 8) + 0x20) & 0x100;
  FUN_20138740(iVar3,0x20,0);
  FUN_201511e8(*(undefined4 *)(iVar3 + 0x38));
  iVar4 = 0;
  do {
    if ((*(ushort *)(*(int *)(iVar3 + 8) + iVar5) & 0x20) == 0) break;
    itron_dly_tsk(5);
    iVar4 = iVar4 + 1;
  } while (iVar4 < 0x32);
  *(undefined2 *)(*(int *)(iVar3 + 8) + iVar5) = 0x200;
  *(undefined2 *)(*(int *)(iVar3 + 8) + iVar5) = 0;
  return iVar2;
}


// ===== FUN_20139590 @ 20139590 (148 bytes)

int FUN_20139590(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  bool bVar5;
  
  iVar4 = 0;
  iVar2 = FUN_20139330(param_2);
  if (iVar2 == 0) {
    iVar4 = FUN_201393d4(param_1,param_2,param_3);
  }
  else if (0 < param_3) {
    do {
      iVar2 = param_3;
      if (0x2000 < param_3) {
        iVar2 = 0x2000;
      }
      iVar3 = FUN_201393d4(param_1,*(undefined4 *)(param_1 + 0x48),iVar2);
      if (iVar3 < 0) {
        return iVar3;
      }
      memcpy(param_2 + iVar4,*(undefined4 *)(param_1 + 0x48),iVar3);
      bVar5 = iVar3 == iVar2;
      param_3 = param_3 - iVar3;
      iVar1 = iVar3 - iVar2;
      if (iVar3 >= iVar2) {
        bVar5 = param_3 == 0;
        iVar1 = param_3;
      }
      iVar4 = iVar4 + iVar3;
    } while (!bVar5 && iVar1 < 0 == (iVar3 < iVar2 && SBORROW4(iVar3,iVar2)));
  }
  return iVar4;
}


// ===== FUN_20139624 @ 20139624 (48 bytes)

void FUN_20139624(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  if (param_2 == 0) {
    return;
  }
  if (*(int *)(param_2 + 0x18) == 0) {
    FUN_20139344(param_2,param_3,param_4);
    return;
  }
  FUN_20139590();
  return;
}


// ===== FUN_20139654 @ 20139654 (4 bytes)

void FUN_20139654(void)

{
  FUN_20139624();
  return;
}


// ===== FUN_20139658 @ 20139658 (84 bytes)

void FUN_20139658(int param_1,int param_2)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = iVar2 * 0x70 + param_1 * 0x4d8;
    if ((*(int *)(&DAT_2090b660 + iVar1 + 0x50) != 0) &&
       (*(int *)(&DAT_2090b660 + iVar1 + 0x8c) == param_2)) {
      *(undefined4 *)(&DAT_2090b660 + iVar1 + 0x90) = 1;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 10);
  return;
}


// ===== FUN_201396ac @ 201396ac (4 bytes)

void FUN_201396ac(void)

{
  return;
}

