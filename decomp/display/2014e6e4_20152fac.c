// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== os_create_dtq_named @ 2014e6e4 (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (wrapper 0.850): same wrapper around itron_acre_dtq
   [inference] */

void os_create_dtq_named(undefined4 *param_1,undefined4 param_2)

{
  undefined4 local_18;
  undefined4 uStack_14;
  undefined4 local_10;
  undefined4 uStack_c;
  
  local_18 = *param_1;
  uStack_14 = param_1[1];
  local_10 = param_1[2];
  uStack_c = param_2;
  itron_acre_dtq(0,&local_18);
  return;
}


// ===== FUN_2014e710 @ 2014e710 (36 bytes)

char FUN_2014e710(void)

{
  char cVar1;
  
  cVar1 = DAT_208dc18c;
  if (DAT_208dc18c == (char)((char)DAT_201659d0 + '\x01')) {
    cVar1 = '\0';
  }
  return cVar1;
}


// ===== itron_act_tsk @ 2014e73c (292 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): TCB table 0x208DBBA0, id
   0 = self; dormant -> start like sta_tsk with exinf, else activation count +0x26 ++ (E_QOVR)
   [inference] */

code * itron_act_tsk(uint param_1)

{
  char cVar1;
  int iVar2;
  uint uVar3;
  code *pcVar4;
  int iVar5;
  undefined4 uVar6;
  int *piVar7;
  uint uVar8;
  
  if (param_1 == 0) {
    param_1 = (uint)DAT_208dc18c;
  }
  if (DAT_201659d0 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  piVar7 = *(int **)(&DAT_208dbba0 + param_1 * 4);
  if (piVar7 == (int *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (*(char *)((int)piVar7 + 5) == '\0') {
    iVar2 = piVar7[6];
    uVar8 = *(uint *)(iVar2 + 8);
    iVar5 = piVar7[5] + *(int *)(iVar2 + 0x10);
    uVar6 = *(undefined4 *)(iVar2 + 4);
    *(int *)(iVar5 + -0x18) = iVar5;
    *(undefined4 *)(iVar5 + -0x48) = uVar6;
    uVar3 = DAT_208003ac;
    if ((uVar8 & 1) != 0) {
      uVar3 = DAT_208003ac | 0x20;
    }
    *(uint *)(iVar5 + -0xc) = uVar3;
    uVar3 = FUN_201568b8();
    *(uint *)(iVar5 + -0xc) = uVar3 | *(uint *)(iVar5 + -0xc);
    *(code **)(iVar5 + -0x14) = itron_ext_tsk;
    *(uint *)(iVar5 + -4) = uVar8;
    *piVar7 = iVar5 + -0x48;
    *(undefined1 *)(piVar7 + 2) = 0;
    *(undefined1 *)((int)piVar7 + 9) = 0;
    piVar7[8] = 0;
    *(undefined1 *)((int)piVar7 + 5) = 0x10;
    pcVar4 = (code *)FUN_20154538(piVar7,param_1);
    return pcVar4;
  }
  cVar1 = *(char *)((int)piVar7 + 0x26) + '\x01';
  *(char *)((int)piVar7 + 0x26) = cVar1;
  if (cVar1 == '\0') {
    *(undefined1 *)((int)piVar7 + 0x26) = 0xff;
    software_interrupt(0);
    return (code *)0xffffffd5;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== itron_chg_pri @ 2014e884 (736 bytes)

/* (tskid, tskpri): 0 = self / initial priority, pri < 9, requeues the TCB [fact]; T23d NORTi uITRON
   4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (tskid, tskpri <= 8, 0 = initial): E_OBJ
   dormant, E_ILUSE mutex ceiling, requeues ready/wait queues [inference] */

code * itron_chg_pri(uint param_1,uint param_2)

{
  int iVar1;
  char cVar2;
  byte bVar3;
  undefined4 *puVar4;
  uint uVar5;
  char *pcVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  int *piVar10;
  bool bVar11;
  
  bVar11 = param_1 == 0;
  if (bVar11) {
    param_1 = (uint)DAT_208dc18c;
  }
  if (param_2 < 9) {
    if ((param_1 <= DAT_201659d0) && (DAT_208003da == '\0' || !bVar11)) {
      software_interrupt(0);
      puVar4 = &DAT_208dbba4 + param_1;
      piVar10 = *(int **)(&DAT_208dbba0 + param_1 * 4);
      if (piVar10 == (int *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      bVar3 = *(byte *)((int)piVar10 + 5);
      if (bVar3 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      if (param_2 == 0) {
        puVar4 = (undefined4 *)piVar10[6];
      }
      iVar9 = (int)(short)piVar10[9];
      if (param_2 == 0) {
        param_2 = puVar4[3];
      }
      if ((iVar9 == 0) && ((bVar3 & 0xfc) != 0x94)) {
        bVar11 = true;
      }
      else {
        bVar11 = false;
      }
      cVar2 = (char)param_2;
      if (bVar11) {
LAB_2014e9e4:
        *(char *)((int)piVar10 + 0x27) = cVar2;
        iVar9 = piVar10[1];
        *(char *)(piVar10 + 1) = cVar2;
        if (bVar3 == 0x10) {
          if (*(char *)((int)piVar10 + 9) == '\0') {
            FUN_20153a38(&DAT_208dc18c + param_2,piVar10,param_1);
            uVar5 = (uint)DAT_208dc18c;
            if (((uVar5 != param_1) || ((int)param_2 < (int)DAT_208003df)) &&
               ((uVar5 == param_1 || ((int)DAT_208003df < (int)param_2)))) {
              if ((uVar5 == param_1) && (DAT_208003d8 = cVar2, cVar2 != 0)) {
                DAT_208003df = cVar2;
              }
              software_interrupt(0);
              return FUN_201567f4;
            }
            software_interrupt(0);
            return FUN_2015655c;
          }
        }
        else if (0x4f < bVar3) {
          if (*(char *)(piVar10[4] + 1) != -2) {
            FUN_20153a38(piVar10[4] - ((int)(char)iVar9 - (int)cVar2),piVar10,param_1);
          }
          bVar3 = *(byte *)((int)piVar10 + 5) & 0xfc;
          if (bVar3 == 0x94) {
            iVar9 = *(int *)(&DAT_208dbfc4 + *(int *)(*piVar10 + 4) * 4);
            if (*(int *)(iVar9 + 4) == 2) {
              iVar8 = 1;
              for (pcVar6 = (char *)(iVar9 + 0xc); *pcVar6 == '\0'; pcVar6 = pcVar6 + 1) {
                iVar8 = iVar8 + 1;
              }
              if (*(char *)(iVar9 + 0xb) != iVar8) {
                FUN_20153f28(*(undefined1 *)(iVar9 + 10));
              }
            }
          }
          else if (bVar3 == 0x60) {
            iVar9 = FUN_20153dec(*(undefined4 *)(*piVar10 + 4));
            if (iVar9 != 0) {
              software_interrupt(0);
              return FUN_2015655c;
            }
          }
          else if (((*(byte *)((int)piVar10 + 5) & 0xf0) == 0xc0) &&
                  (iVar9 = FUN_20153b8c(*(undefined4 *)(*piVar10 + 4)), iVar9 != 0)) {
            software_interrupt(0);
            return FUN_2015655c;
          }
        }
        software_interrupt(0);
        return FUN_201567f4;
      }
      if ((int)param_2 < (int)(char)piVar10[1]) {
        iVar8 = 8;
        while (iVar9 != 0) {
          iVar9 = *(int *)(&DAT_208dbfc4 + iVar9 * 4);
          iVar7 = (int)*(char *)(iVar9 + 0xb);
          if ((*(int *)(iVar9 + 4) == 3) && ((int)param_2 < iVar7)) {
            software_interrupt(0);
            return (code *)0xffffffe4;
          }
          iVar9 = (int)*(short *)(iVar9 + 8);
          bVar11 = iVar7 != 0;
          iVar1 = 0;
          if (bVar11) {
            iVar1 = iVar8 - iVar7;
          }
          if ((bVar11 && iVar8 != iVar7) && iVar1 < 0 == (bVar11 && SBORROW4(iVar8,iVar7))) {
            iVar8 = iVar7;
          }
        }
        if ((int)param_2 <= iVar8) goto LAB_2014e9e4;
      }
      *(char *)((int)piVar10 + 0x27) = cVar2;
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    DAT_208003d4 = (code *)0xffffffef;
  }
  return DAT_208003d4;
}


// ===== itron_clr_flg @ 2014eb94 (132 bytes)

/* (flgid 1..0x40, clrptn): flag table 0x208DBDA4; callers pass 0 or ~ptn [fact]; T23d NORTi uITRON
   4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): flag table 0x208DBDA4 (64): flgptn &=
   clrptn [inference] */

code * itron_clr_flg(uint param_1,uint param_2)

{
  int iVar1;
  
  if (param_2 == 0xffffffff) {
    DAT_208003d4 = (code *)0x0;
  }
  else {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      iVar1 = *(int *)(&DAT_208dbda4 + param_1 * 4);
      if (iVar1 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      *(uint *)(iVar1 + 4) = *(uint *)(iVar1 + 4) & param_2;
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  return DAT_208003d4;
}


// ===== itron_acre_cyc @ 2014ec30 (424 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): object table 0x208DBF64,
   max id 8; 0x20-byte block, cycatr/exinf/cychdr/cyctim/cycphs, TA_STA starts it on timer queue
   0x208003C4; id 0 = auto (E_NOID) [inference] */

uint itron_acre_cyc(uint param_1,uint *param_2)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined2 local_28 [2];
  uint local_24;
  
  if (DAT_208003da == '\0') {
    if ((param_1 == 0) || ((param_1 != 0 && (param_1 < 9)))) {
      if (param_2 != (uint *)0x0) {
        uVar1 = *param_2;
        if ((uVar1 & 2) == 0) {
          uVar1 = uVar1 & 0xfffffffe;
        }
        else {
          uVar1 = uVar1 | 1;
        }
        software_interrupt(0);
        if (param_1 == 0) {
          param_1 = 8;
          iVar2 = DAT_208dbf84;
          while (uVar4 = param_1, iVar2 != 0) {
            param_1 = param_1 - 1;
            if (param_1 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
            iVar2 = *(int *)(&DAT_208dbf64 + param_1 * 4);
          }
        }
        else {
          if (*(int *)(&DAT_208dbf64 + param_1 * 4) != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
          uVar4 = 0;
        }
        iVar2 = FUN_2015476c(0x20);
        if (iVar2 != 0) {
          *(int *)(&DAT_208dbf64 + param_1 * 4) = iVar2;
          *(undefined1 *)(iVar2 + 8) = 0;
          *(undefined1 *)(iVar2 + 9) = 0;
          local_28[0] = 0;
          *(undefined2 *)(iVar2 + 0x10) = 0;
          *(uint *)(iVar2 + 0x14) = param_2[3];
          local_24 = param_2[4];
          if (local_24 == 0) {
            local_24 = param_2[3];
          }
          *(uint *)(iVar2 + 0x1c) = param_2[2];
          uVar3 = param_2[1];
          *(uint *)(iVar2 + 0xc) = uVar1;
          *(uint *)(iVar2 + 0x18) = uVar3;
          if ((uVar1 & 6) != 0) {
            FUN_201543e4(local_28,&DAT_208003c4,iVar2);
            FUN_20153720(&DAT_208dbf64,iVar2,param_1);
          }
          software_interrupt(0);
          return uVar4;
        }
        software_interrupt(0);
        DAT_208003d4 = 0xfffffffb;
        return 0xfffffffb;
      }
      DAT_208003d4 = 0xffffffef;
    }
    else {
      DAT_208003d4 = 0xffffffee;
    }
  }
  else {
    DAT_208003d4 = 0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_acre_dtq @ 2014edf4 (496 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBFA4,
   max id 8; id 0 = auto (E_NOID); same table as tsnd_dtq/trcv_dtq [inference] */

uint itron_acre_dtq(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  uint local_28;
  
  uVar7 = 0;
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (8 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 8;
    while (local_28 = param_1, *(int *)(&DAT_208dbfa4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbfa4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    local_28 = 0;
  }
  iVar9 = *(int *)(param_2 + 4);
  if ((*param_2 & 1) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 7;
  }
  iVar4 = iVar6 + 0x1c;
  if (iVar9 == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = *(int *)(param_2 + 8);
    if (iVar5 == 0) {
      uVar7 = iVar6 + 0x1fU & 0xfffffffc;
      iVar4 = uVar7 + iVar9 * 4;
    }
  }
  iVar1 = knl_addr_in_image(param_2);
  if (iVar1 == 0) {
    uVar8 = iVar4 + 3U & 0xfffffffc;
    iVar4 = uVar8 + 0x10;
  }
  else {
    uVar8 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar4);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbfa4 + param_1 * 4) = piVar2;
  if (uVar8 == 0) {
    *piVar2 = (int)param_2;
  }
  else {
    *piVar2 = (int)piVar2 + uVar8;
    knl_memcpy((int)piVar2 + uVar8,param_2,0x10);
  }
  if (uVar7 != 0) {
    iVar5 = (int)piVar2 + uVar7;
  }
  piVar2[1] = iVar5;
  piVar2[2] = iVar5;
  piVar2[3] = iVar5;
  piVar2[4] = iVar5 + iVar9 * 4;
  *(short *)(piVar2 + 5) = (short)iVar9;
  *(undefined2 *)((int)piVar2 + 0x16) = 0;
  *(undefined1 *)(piVar2 + 6) = 0;
  *(undefined1 *)((int)piVar2 + 0x19) = 0xfe;
  iVar4 = 0;
  iVar9 = iVar4;
  if (-1 < iVar6) {
    do {
      iVar4 = iVar9 + 1;
      *(undefined1 *)((int)piVar2 + iVar9 + 0x1a) = 0;
      iVar9 = iVar4;
    } while (iVar4 <= iVar6);
    if (iVar6 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014efa4;
    }
  }
  uVar3 = 0xff;
LAB_2014efa4:
  *(undefined1 *)((int)piVar2 + iVar4 + 0x1a) = uVar3;
  software_interrupt(0);
  return local_28;
}


// ===== itron_acre_flg @ 2014effc (404 bytes)

uint itron_acre_flg(uint param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (0x40 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x40;
    while (uVar7 = param_1, *(int *)(&DAT_208dbda4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbda4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar7 = 0;
  }
  if ((*param_2 & 1) == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = 7;
  }
  iVar2 = knl_addr_in_image(param_2);
  if (iVar2 == 0) {
    uVar8 = uVar6 + 0xf & 0xfffffffc;
    uVar1 = uVar8;
  }
  else {
    uVar8 = 0;
    uVar1 = uVar6;
  }
  piVar3 = (int *)FUN_2015476c(uVar1 + 0xc);
  if (piVar3 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbda4 + param_1 * 4) = piVar3;
  if (uVar8 == 0) {
    *piVar3 = (int)param_2;
    uVar5 = extraout_r1;
  }
  else {
    *piVar3 = (int)piVar3 + uVar8;
    knl_memcpy((int)piVar3 + uVar8,param_2,0xc);
    uVar5 = extraout_r1_00;
  }
  if (-1 < (int)uVar6) {
    uVar5 = 0;
  }
  piVar3[1] = *(int *)(param_2 + 4);
  *(byte *)(piVar3 + 2) = *param_2;
  iVar4 = 0;
  iVar2 = iVar4;
  if (-1 < (int)uVar6) {
    do {
      iVar4 = iVar2 + 1;
      *(undefined1 *)((int)piVar3 + iVar2 + 9) = uVar5;
      iVar2 = iVar4;
    } while (iVar4 <= (int)uVar6);
    if (uVar6 == 0) {
      uVar5 = 0xfe;
      goto LAB_2014f130;
    }
  }
  uVar5 = 0xff;
LAB_2014f130:
  *(undefined1 *)((int)piVar3 + iVar4 + 9) = uVar5;
  software_interrupt(0);
  return uVar7;
}


// ===== itron_acre_isr @ 2014f1a8 (536 bytes)

/* create an interrupt service routine object (auto-ID counts down from 0x40) [inference] */

uint itron_acre_isr(uint param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  undefined4 *puVar3;
  code *pcVar4;
  uint uVar5;
  int iVar6;
  int *piVar7;
  
  if (DAT_208003da == '\0') {
    if (param_1 < 0x41) {
      uVar2 = isr_desc_check(param_2);
      if (uVar2 == 0) {
        software_interrupt(0);
        if (param_1 == 0) {
          param_1 = 0x40;
          while (uVar2 = param_1, (&DAT_208dc044)[param_1] != 0) {
            param_1 = param_1 - 1;
            if (param_1 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
          }
        }
        else {
          uVar2 = 0;
          if ((&DAT_208dc044)[param_1] != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
        }
        puVar3 = (undefined4 *)FUN_2015476c(0x14);
        if (puVar3 != (undefined4 *)0x0) {
          pcVar4 = (code *)gic_get_handler(param_2);
          if (pcVar4 == gic_default_handler) {
            uVar5 = FUN_2015476c(0x58);
            if (uVar5 == 0) {
              FUN_20154790(puVar3,0x14);
              software_interrupt(0);
              DAT_208003d4 = 0xfffffffb;
              return 0xfffffffb;
            }
            knl_memcpy(uVar5,gic_default_handler,0x58);
            *(undefined4 **)(uVar5 + 0x4c) = puVar3;
            puVar3[3] = uVar5 + 0x4c;
            gic_install_isr_stub(uVar5,param_2);
          }
          else {
            uVar5 = gic_get_handler(param_2);
            piVar7 = (int *)(uVar5 + 0x4c);
            iVar6 = *piVar7;
            if (iVar6 == 0) {
              *piVar7 = (int)puVar3;
              puVar3[3] = piVar7;
            }
            else {
              for (iVar1 = *(int *)(iVar6 + 8); iVar1 != 0; iVar1 = *(int *)(iVar1 + 8)) {
                if (*(int *)(iVar1 + 0xc) != iVar6 + 8) {
                  FUN_20154790(puVar3,0x14);
                  software_interrupt(0);
                  DAT_208003d4 = 0xffffffe4;
                  return 0xffffffe4;
                }
                iVar6 = iVar1;
              }
              *(int *)(iVar6 + 8) = (int)puVar3;
              puVar3[3] = (int *)(iVar6 + 8);
            }
          }
          *puVar3 = *(undefined4 *)(param_2 + 0xc);
          puVar3[1] = *(undefined4 *)(param_2 + 4);
          puVar3[2] = 0;
          puVar3[4] = *(undefined4 *)(param_2 + 8);
          (&DAT_208dc044)[param_1] = puVar3;
          software_interrupt(0);
          return uVar2;
        }
        software_interrupt(0);
        DAT_208003d4 = 0xfffffffb;
        return 0xfffffffb;
      }
    }
    else {
      uVar2 = 0xffffffee;
    }
  }
  else {
    uVar2 = 0xffffffe7;
  }
  DAT_208003d4 = uVar2;
  return uVar2;
}


// ===== itron_acre_mbf @ 2014f3e4 (640 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBEC4,
   max id 8; allocates the buffer (E_NOMEM); same table as tsnd_mbf/trcv_mbf [inference] */

uint itron_acre_mbf(uint param_1,uint *param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  int *piVar4;
  undefined1 *puVar5;
  undefined1 *puVar6;
  undefined1 uVar7;
  int iVar8;
  int iVar9;
  int iVar10;
  uint uVar11;
  uint local_30;
  uint local_2c;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  uVar2 = 0;
  if (param_2[1] != 0) {
    uVar2 = param_2[2];
  }
  if (param_2[1] == 0 || 0xffff < uVar2) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  if (8 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 8;
    while (local_2c = param_1, *(int *)(&DAT_208dbec4 + param_1 * 4) != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if (*(int *)(&DAT_208dbec4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    local_2c = 0;
  }
  if ((*param_2 & 1) == 0) {
    iVar10 = 0;
  }
  else {
    iVar10 = 7;
  }
  if ((*param_2 & 4) == 0) {
    iVar9 = 1;
  }
  else {
    iVar9 = 8;
  }
  iVar1 = iVar10 + 0x18;
  iVar8 = iVar1 + iVar9 + 1;
  iVar3 = knl_addr_in_image(param_2);
  if (iVar3 == 0) {
    uVar2 = iVar1 + iVar9 + 4U & 0xfffffffc;
    iVar8 = uVar2 + 0x14;
  }
  else {
    uVar2 = 0;
  }
  local_30 = param_2[3];
  uVar11 = param_2[2];
  if (((local_30 == 0) && (uVar11 != 0)) && (local_30 = FUN_20154720(uVar11), local_30 == 0)) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffdf;
    return 0xffffffdf;
  }
  piVar4 = (int *)FUN_2015476c(iVar8);
  if (piVar4 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbec4 + param_1 * 4) = piVar4;
  if (uVar2 == 0) {
    *piVar4 = (int)param_2;
  }
  else {
    *piVar4 = (int)piVar4 + uVar2;
    knl_memcpy((int)piVar4 + uVar2,param_2,0x14);
  }
  if (uVar11 == 0) {
    local_30 = 0;
  }
  piVar4[1] = local_30;
  *(undefined2 *)(piVar4 + 2) = 0;
  *(undefined2 *)((int)piVar4 + 10) = 0;
  *(short *)(piVar4 + 3) = (short)uVar11;
  *(short *)((int)piVar4 + 0xe) = (short)uVar11;
  *(short *)(piVar4 + 4) = (short)param_2[1];
  iVar8 = 0;
  iVar3 = iVar8;
  if (-1 < iVar10) {
    do {
      iVar8 = iVar3 + 1;
      *(undefined1 *)((int)piVar4 + iVar3 + 0x13) = 0;
      iVar3 = iVar8;
    } while (iVar8 <= iVar10);
    if (iVar10 == 0) {
      uVar7 = 0xfe;
      goto LAB_2014f5f8;
    }
  }
  uVar7 = 0xff;
LAB_2014f5f8:
  *(undefined1 *)((int)piVar4 + iVar8 + 0x13) = uVar7;
  puVar5 = (undefined1 *)((int)piVar4 + iVar1);
  iVar10 = 0;
  *(char *)((int)piVar4 + 0x12) = (char)iVar1;
  puVar6 = puVar5;
  if (iVar9 != 0) {
    do {
      iVar10 = iVar10 + 1;
      puVar5 = puVar6 + 1;
      *puVar6 = 0;
      puVar6 = puVar5;
    } while (iVar10 < iVar9);
  }
  if (iVar9 == 1) {
    uVar7 = 0xfe;
  }
  else {
    uVar7 = 0xff;
  }
  *puVar5 = uVar7;
  software_interrupt(0);
  return local_2c;
}


// ===== itron_acre_mbx @ 2014f67c (544 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBEA4,
   max id 8; same table as snd_mbx/trcv_mbx [inference] */

undefined4 * itron_acre_mbx(undefined4 *param_1,uint *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  int iVar8;
  undefined4 *local_28;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = &DAT_ffffffe7;
    return (undefined4 *)&DAT_ffffffe7;
  }
  if (&SupervisorCall < param_1) {
    DAT_208003d4 = (undefined1 *)0xffffffee;
    return (undefined4 *)0xffffffee;
  }
  software_interrupt(0);
  if (param_1 == (undefined4 *)0x0) {
    if (DAT_208003b4 == (undefined4 *)0x0) {
      software_interrupt(0);
      return (undefined4 *)0xffffffde;
    }
    iVar5 = *(int *)(&DAT_208dbea4 + (int)DAT_208003b4 * 4);
    param_1 = DAT_208003b4;
    while (iVar5 != 0) {
      param_1 = (undefined4 *)((int)param_1 + -1);
      if (param_1 == (undefined4 *)0x0) {
        software_interrupt(0);
        return (undefined4 *)0xffffffde;
      }
      iVar5 = *(int *)(&DAT_208dbea4 + (int)param_1 * 4);
    }
    DAT_208003b4 = (undefined4 *)((int)param_1 + -1);
    local_28 = param_1;
  }
  else {
    if (*(int *)(&DAT_208dbea4 + (int)param_1 * 4) != 0) {
      software_interrupt(0);
      return (undefined4 *)0xffffffd7;
    }
    local_28 = (undefined4 *)0x0;
  }
  if ((*param_2 & 1) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 7;
  }
  if ((*param_2 & 2) == 0) {
    uVar4 = 1;
  }
  else {
    uVar4 = param_2[1];
  }
  iVar8 = iVar5 + 0xc;
  if (param_2[2] == 0) {
    uVar6 = iVar5 + 0xfU & 0xfffffffc;
    iVar8 = uVar6 + uVar4 * 8;
  }
  else {
    uVar6 = 0;
  }
  iVar1 = knl_addr_in_image(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar8 + 3U & 0xfffffffc;
    iVar8 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar8);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = (undefined1 *)0xfffffffb;
    return (undefined4 *)0xfffffffb;
  }
  iVar1 = (int)param_1 * 4;
  if (uVar6 != 0) {
    param_1 = (undefined4 *)((int)piVar2 + uVar6);
  }
  *(int **)(&DAT_208dbea4 + iVar1) = piVar2;
  *(char *)(piVar2 + 1) = (char)uVar4;
  *(char *)((int)piVar2 + 5) = (char)iVar8;
  *(char *)((int)piVar2 + 6) = (char)uVar6;
  if (uVar6 == 0) {
    param_1 = (undefined4 *)param_2[2];
  }
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    knl_memcpy((int)piVar2 + uVar7,param_2,0x10);
  }
  iVar8 = 0;
  if (0 < (int)uVar4) {
    do {
      *param_1 = 0;
      iVar8 = iVar8 + 1;
      param_1[1] = 0;
      param_1 = param_1 + 2;
    } while (iVar8 < (int)uVar4);
  }
  iVar1 = 0;
  iVar8 = iVar1;
  if (-1 < iVar5) {
    do {
      iVar1 = iVar8 + 1;
      *(undefined1 *)((int)piVar2 + iVar8 + 7) = 0;
      iVar8 = iVar1;
    } while (iVar1 <= iVar5);
    if (iVar5 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014f830;
    }
  }
  uVar3 = 0xff;
LAB_2014f830:
  *(undefined1 *)((int)piVar2 + iVar1 + 7) = uVar3;
  software_interrupt(0);
  return local_28;
}


// ===== itron_acre_mpf @ 2014f8b8 (564 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBF24,
   max id 16; E_PAR on block count/size, E_NOMEM; same table as tget_mpf/rel_mpf [inference] */

uint itron_acre_mpf(uint param_1,byte *param_2)

{
  uint uVar1;
  int iVar2;
  int *piVar3;
  undefined1 uVar4;
  int iVar5;
  undefined4 *puVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint uVar10;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  iVar2 = 0x10;
  if (0x10 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  iVar5 = *(int *)(param_2 + 8);
  if (iVar5 != 0) {
    iVar2 = *(int *)(param_2 + 4);
  }
  if (iVar5 == 0 || iVar2 == 0) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  uVar8 = iVar5 + 3U & 0xfffffffc;
  if (uVar8 < 4) {
    uVar8 = 4;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x10;
    while (uVar9 = param_1, (&DAT_208dbf24)[param_1] != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if ((&DAT_208dbf24)[param_1] != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar9 = 0;
  }
  puVar6 = *(undefined4 **)(param_2 + 0xc);
  if ((puVar6 == (undefined4 *)0x0) &&
     (puVar6 = (undefined4 *)FUN_20154720(iVar2 * uVar8), puVar6 == (undefined4 *)0x0)) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffdf;
    return 0xffffffdf;
  }
  if ((*param_2 & 1) == 0) {
    uVar7 = 0;
  }
  else {
    uVar7 = 7;
  }
  iVar5 = knl_addr_in_image(param_2);
  if (iVar5 == 0) {
    uVar10 = uVar7 + 0x17 & 0xfffffffc;
    uVar1 = uVar10;
  }
  else {
    uVar10 = 0;
    uVar1 = uVar7;
  }
  piVar3 = (int *)FUN_2015476c(uVar1 + 0x14);
  if (piVar3 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  (&DAT_208dbf24)[param_1] = piVar3;
  if (uVar10 == 0) {
    *piVar3 = (int)param_2;
  }
  else {
    *piVar3 = (int)piVar3 + uVar10;
    knl_memcpy((int)piVar3 + uVar10,param_2,0x14);
  }
  piVar3[1] = (int)puVar6;
  piVar3[2] = (int)puVar6;
  piVar3[3] = iVar2 * uVar8;
  *(undefined2 *)(piVar3 + 4) = *(undefined2 *)(param_2 + 4);
  iVar2 = *(int *)(param_2 + 4);
  while (iVar2 = iVar2 + -1, iVar2 != 0) {
    *puVar6 = (undefined4 *)((int)puVar6 + uVar8);
    puVar6 = (undefined4 *)((int)puVar6 + uVar8);
  }
  *puVar6 = 0;
  iVar2 = 0;
  iVar5 = 0;
  if (-1 < (int)uVar7) {
    do {
      iVar2 = iVar5 + 1;
      *(undefined1 *)((int)piVar3 + iVar5 + 0x12) = 0;
      iVar5 = iVar2;
    } while (iVar2 <= (int)uVar7);
    if (uVar7 == 0) {
      uVar4 = 0xfe;
      goto LAB_2014faac;
    }
  }
  uVar4 = 0xff;
LAB_2014faac:
  *(undefined1 *)((int)piVar3 + iVar2 + 0x12) = uVar4;
  software_interrupt(0);
  return uVar9;
}


// ===== itron_acre_mpl @ 2014fb04 (520 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.800): object table 0x208DBF04,
   max id 8; pool memory from pk+8 or the kernel heap (E_NOMEM); id 0 = auto [inference] */

uint itron_acre_mpl(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  int iVar9;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if ((param_1 != 0) && ((param_1 == 0 || (8 < param_1)))) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  software_interrupt(0);
  if (param_1 != 0) {
    if (*(int *)(&DAT_208dbf04 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar8 = 0;
  }
  else {
    param_1 = 8;
    iVar4 = DAT_208dbf24;
    while (uVar8 = param_1, iVar4 != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
      iVar4 = *(int *)(&DAT_208dbf04 + param_1 * 4);
    }
  }
  iVar4 = *(int *)(param_2 + 8);
  iVar9 = *(int *)(param_2 + 4);
  if ((iVar4 == 0) && (iVar4 = FUN_20154720(iVar9), iVar4 == 0)) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffdf;
    return 0xffffffdf;
  }
  if ((*param_2 & 1) == 0) {
    iVar6 = 0;
  }
  else {
    iVar6 = 7;
  }
  iVar5 = iVar6 + 0x14;
  iVar1 = knl_addr_in_image(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar6 + 0x17U & 0xfffffffc;
    iVar5 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar5);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  FUN_201530e4(iVar4,iVar9);
  *(int **)(&DAT_208dbf04 + param_1 * 4) = piVar2;
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
    uVar3 = extraout_r1;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    knl_memcpy((int)piVar2 + uVar7,param_2,0x10);
    uVar3 = extraout_r1_00;
  }
  piVar2[1] = iVar4;
  piVar2[2] = iVar4;
  iVar4 = 0;
  if (-1 < iVar6) {
    uVar3 = 0;
  }
  piVar2[3] = iVar9;
  iVar9 = iVar4;
  if (-1 < iVar6) {
    do {
      iVar4 = iVar9 + 1;
      *(undefined1 *)((int)piVar2 + iVar9 + 0x10) = uVar3;
      iVar9 = iVar4;
    } while (iVar4 <= iVar6);
    if (iVar6 == 0) {
      uVar3 = 0xfe;
      goto LAB_2014fccc;
    }
  }
  uVar3 = 0xff;
LAB_2014fccc:
  *(undefined1 *)((int)piVar2 + iVar4 + 0x10) = uVar3;
  software_interrupt(0);
  return uVar8;
}


// ===== itron_acre_mtx @ 2014fd24 (496 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): object table 0x208DBFC4,
   max id 32; E_RSATR, ceiling priority; same table as tloc_mtx/unl_mtx [inference] */

uint itron_acre_mtx(uint param_1,int *param_2)

{
  undefined1 uVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  
  iVar6 = *param_2;
  if (iVar6 == 3) {
    uVar7 = param_2[1];
  }
  else {
    uVar7 = 8;
  }
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (0x20 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  if (3 < iVar6) {
    DAT_208003d4 = 0xfffffff5;
    return 0xfffffff5;
  }
  if ((iVar6 == 3) && ((uVar7 == 0 || (8 < uVar7)))) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x20;
    iVar4 = DAT_208dc044;
    while (uVar8 = param_1, iVar4 != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
      iVar4 = *(int *)(&DAT_208dbfc4 + param_1 * 4);
    }
  }
  else {
    if (*(int *)(&DAT_208dbfc4 + param_1 * 4) != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar8 = 0;
  }
  if (iVar6 == 0) {
    iVar4 = 0;
  }
  else {
    iVar4 = 7;
  }
  iVar5 = iVar4 + 0x10;
  iVar2 = knl_addr_in_image(param_2);
  if (iVar2 == 0) {
    uVar9 = iVar4 + 0x13U & 0xfffffffc;
    iVar5 = uVar9 + 0xc;
  }
  else {
    uVar9 = 0;
  }
  piVar3 = (int *)FUN_2015476c(iVar5);
  if (piVar3 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  *(int **)(&DAT_208dbfc4 + param_1 * 4) = piVar3;
  if (uVar9 == 0) {
    *piVar3 = (int)param_2;
  }
  else {
    *piVar3 = (int)piVar3 + uVar9;
    knl_memcpy((int)piVar3 + uVar9,param_2,0xc);
  }
  if (iVar6 < 2) {
    uVar1 = 0;
  }
  else {
    uVar1 = (undefined1)uVar7;
  }
  *(undefined1 *)((int)piVar3 + 0xb) = uVar1;
  *(undefined1 *)((int)piVar3 + 10) = 0;
  iVar2 = 0;
  *(undefined2 *)(piVar3 + 2) = 0;
  piVar3[1] = iVar6;
  iVar6 = iVar2;
  if (-1 < iVar4) {
    do {
      iVar2 = iVar6 + 1;
      *(undefined1 *)((int)piVar3 + iVar6 + 0xc) = 0;
      iVar6 = iVar2;
    } while (iVar2 <= iVar4);
    if (iVar4 == 0) {
      uVar1 = 0xfe;
      goto LAB_2014fe9c;
    }
  }
  uVar1 = 0xff;
LAB_2014fe9c:
  *(undefined1 *)((int)piVar3 + iVar2 + 0xc) = uVar1;
  software_interrupt(0);
  return uVar8;
}


// ===== itron_acre_sem @ 2014ff2c (432 bytes)

uint itron_acre_sem(uint param_1,byte *param_2)

{
  int iVar1;
  int *piVar2;
  undefined1 extraout_r1;
  undefined1 extraout_r1_00;
  undefined1 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  uint uVar7;
  
  if (DAT_208003da != '\0') {
    DAT_208003d4 = 0xffffffe7;
    return 0xffffffe7;
  }
  if (0x40 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return 0xffffffee;
  }
  if ((0xffff < *(uint *)(param_2 + 8)) || (*(uint *)(param_2 + 8) < *(uint *)(param_2 + 4))) {
    DAT_208003d4 = 0xffffffef;
    return 0xffffffef;
  }
  software_interrupt(0);
  if (param_1 == 0) {
    param_1 = 0x40;
    while (uVar6 = param_1, (&DAT_208dbca4)[param_1] != 0) {
      param_1 = param_1 - 1;
      if (param_1 == 0) {
        software_interrupt(0);
        return 0xffffffde;
      }
    }
  }
  else {
    if ((&DAT_208dbca4)[param_1] != 0) {
      software_interrupt(0);
      return 0xffffffd7;
    }
    uVar6 = 0;
  }
  if ((*param_2 & 1) == 0) {
    iVar5 = 0;
  }
  else {
    iVar5 = 7;
  }
  iVar4 = iVar5 + 0xc;
  iVar1 = knl_addr_in_image(param_2);
  if (iVar1 == 0) {
    uVar7 = iVar5 + 0xfU & 0xfffffffc;
    iVar4 = uVar7 + 0x10;
  }
  else {
    uVar7 = 0;
  }
  piVar2 = (int *)FUN_2015476c(iVar4);
  if (piVar2 == (int *)0x0) {
    software_interrupt(0);
    DAT_208003d4 = 0xfffffffb;
    return 0xfffffffb;
  }
  (&DAT_208dbca4)[param_1] = piVar2;
  if (uVar7 == 0) {
    *piVar2 = (int)param_2;
    uVar3 = extraout_r1;
  }
  else {
    *piVar2 = (int)piVar2 + uVar7;
    knl_memcpy((int)piVar2 + uVar7,param_2,0x10);
    uVar3 = extraout_r1_00;
  }
  if (-1 < iVar5) {
    uVar3 = 0;
  }
  *(undefined2 *)(piVar2 + 1) = *(undefined2 *)(param_2 + 4);
  *(undefined2 *)((int)piVar2 + 6) = *(undefined2 *)(param_2 + 8);
  iVar4 = 0;
  iVar1 = iVar4;
  if (-1 < iVar5) {
    do {
      iVar4 = iVar1 + 1;
      *(undefined1 *)((int)piVar2 + iVar1 + 8) = uVar3;
      iVar1 = iVar4;
    } while (iVar4 <= iVar5);
    if (iVar5 == 0) {
      uVar3 = 0xfe;
      goto LAB_2015007c;
    }
  }
  uVar3 = 0xff;
LAB_2015007c:
  *(undefined1 *)((int)piVar2 + iVar4 + 8) = uVar3;
  software_interrupt(0);
  return uVar6;
}


// ===== itron_acre_tsk @ 201500f4 (488 bytes)

/* create task, id 0 = auto-assign; TCB table 0x208DBBA0 */

uint itron_acre_tsk(uint param_1,byte *param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  undefined4 uVar8;
  int iVar9;
  
  if (DAT_208003da == '\0') {
    if (DAT_201659d0 < param_1) {
      DAT_208003d4 = 0xffffffee;
    }
    else {
      if (*(int *)(param_2 + 0xc) < 9) {
        software_interrupt(0);
        uVar5 = DAT_201659d0;
        if (param_1 == 0) {
          while (uVar7 = uVar5, *(int *)(&DAT_208dbba0 + uVar5 * 4) != 0) {
            uVar5 = uVar5 - 1;
            if (uVar5 == 0) {
              software_interrupt(0);
              return 0xffffffde;
            }
          }
        }
        else {
          if (*(int *)(&DAT_208dbba0 + param_1 * 4) != 0) {
            software_interrupt(0);
            return 0xffffffd7;
          }
          uVar5 = param_1;
          uVar7 = 0;
        }
        iVar2 = knl_addr_in_image(param_2);
        if (iVar2 == 0) {
          uVar8 = 0x44;
          iVar2 = 0x28;
        }
        else {
          uVar8 = 0x28;
          iVar2 = 0;
        }
        iVar3 = FUN_2015476c(uVar8);
        if (iVar3 == 0) {
          software_interrupt(0);
          DAT_208003d4 = 0xfffffffb;
          return 0xfffffffb;
        }
        puVar6 = *(uint **)(param_2 + 0x14);
        iVar9 = *(int *)(param_2 + 0x10);
        if ((puVar6 == (uint *)0x0) && (puVar6 = (uint *)FUN_20154704(iVar9), puVar6 == (uint *)0x0)
           ) {
          FUN_20154790(iVar3,uVar8);
          software_interrupt(0);
          DAT_208003d4 = 0xffffffdf;
          return 0xffffffdf;
        }
        *(int *)(&DAT_208dbba0 + uVar5 * 4) = iVar3;
        *(undefined1 *)(iVar3 + 5) = 0;
        *(undefined1 *)(iVar3 + 0x26) = 0;
        *(undefined2 *)(iVar3 + 0x24) = 0;
        if (iVar2 == 0) {
          *(byte **)(iVar3 + 0x18) = param_2;
        }
        else {
          *(int *)(iVar3 + 0x18) = iVar3 + iVar2;
          knl_memcpy(iVar3 + iVar2,param_2,0x1c);
        }
        bVar1 = param_2[0xc];
        *(byte *)(iVar3 + 4) = bVar1;
        *(byte *)(iVar3 + 0x27) = bVar1;
        *(uint **)(iVar3 + 0x14) = puVar6;
        uVar4 = iVar9 - 0x48U >> 2;
        *(undefined4 *)(iVar3 + 0x1c) = 0;
        do {
          uVar4 = uVar4 - 1;
          *puVar6 = uVar5 << 0x18 | uVar5 << 0x10 | uVar5 << 8 | uVar5;
          puVar6 = puVar6 + 1;
        } while (uVar4 != 0);
        software_interrupt(0);
        if ((*param_2 & 2) != 0) {
          itron_act_tsk(uVar5);
        }
        return uVar7;
      }
      DAT_208003d4 = 0xffffffef;
    }
  }
  else {
    DAT_208003d4 = 0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_del_mpf @ 201502f4 (436 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.800): mpf table 0x208DBF24:
   releases waiting tasks with E_DLT, frees the block and the pool [inference] */

code * itron_del_mpf(uint param_1)

{
  byte bVar1;
  bool bVar2;
  int iVar3;
  undefined4 *puVar4;
  int iVar5;
  byte *pbVar6;
  uint uVar7;
  int *piVar8;
  
  bVar2 = false;
  if (DAT_208003da == '\0') {
    if ((param_1 != 0) && (param_1 < 0x11)) {
      software_interrupt(0);
      piVar8 = (int *)(&DAT_208dbf24)[param_1];
      if (piVar8 == (int *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (piVar8[1] == 0) {
        pbVar6 = (byte *)((int)piVar8 + 0x12);
        bVar1 = *(byte *)((int)piVar8 + 0x12);
        while (uVar7 = (uint)bVar1, uVar7 < 0xfe) {
          while (uVar7 != 0) {
            puVar4 = *(undefined4 **)(&DAT_208dbba0 + uVar7 * 4);
            *(undefined4 *)*puVar4 = 0xffffffcd;
            if ((*(byte *)((int)puVar4 + 5) & 2) != 0) {
              knl_timeout_remove(puVar4,uVar7);
            }
            *(undefined1 *)((int)puVar4 + 5) = 0x10;
            if (*(char *)((int)puVar4 + 9) == '\0') {
              FUN_20154508(puVar4,uVar7);
              bVar2 = (bool)(bVar2 | *(char *)(puVar4 + 1) < DAT_208003df);
            }
            else {
              FUN_201539ec();
            }
            uVar7 = (uint)*pbVar6;
          }
          pbVar6 = pbVar6 + 1;
          bVar1 = *pbVar6;
        }
      }
      if (*(int *)(*piVar8 + 0xc) == 0) {
        FUN_20154744(piVar8[2],piVar8[3]);
      }
      iVar5 = 0x14;
      if (*(byte *)((int)piVar8 + 0x13) < 0xfe) {
        iVar5 = 0x1b;
      }
      iVar3 = knl_addr_in_image(*piVar8);
      if (iVar3 == 0) {
        iVar5 = (iVar5 + 3U & 0xfffffffc) + 0x14;
      }
      FUN_20154790(piVar8,iVar5);
      (&DAT_208dbf24)[param_1] = 0;
      if (bVar2) {
        software_interrupt(0);
        return FUN_2015655c;
      }
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_del_sem @ 201504d0 (384 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): sem table 0x208DBCA4:
   releases waiting tasks with E_DLT, frees the block [inference] */

code * itron_del_sem(uint param_1)

{
  bool bVar1;
  int iVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  byte *pbVar6;
  undefined4 *puVar7;
  
  bVar1 = false;
  if (DAT_208003da == '\0') {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      puVar7 = (undefined4 *)(&DAT_208dbca4)[param_1];
      if (puVar7 == (undefined4 *)0x0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (*(short *)(puVar7 + 1) == 0) {
        uVar5 = (uint)*(byte *)(puVar7 + 2);
        pbVar6 = (byte *)(puVar7 + 2);
        do {
          while (uVar5 != 0) {
            puVar3 = *(undefined4 **)(&DAT_208dbba0 + uVar5 * 4);
            *(undefined4 *)*puVar3 = 0xffffffcd;
            if ((*(byte *)((int)puVar3 + 5) & 2) != 0) {
              knl_timeout_remove(puVar3,uVar5);
            }
            *(undefined1 *)((int)puVar3 + 5) = 0x10;
            if (*(char *)((int)puVar3 + 9) == '\0') {
              FUN_20154508(puVar3,uVar5);
              bVar1 = (bool)(bVar1 | *(char *)(puVar3 + 1) < DAT_208003df);
            }
            else {
              FUN_201539ec();
            }
            uVar5 = (uint)*pbVar6;
          }
          pbVar6 = pbVar6 + 1;
          uVar5 = (uint)*pbVar6;
        } while (uVar5 < 0xfe);
      }
      iVar4 = 0xc;
      if (*(byte *)((int)puVar7 + 9) < 0xfe) {
        iVar4 = 0x13;
      }
      iVar2 = knl_addr_in_image(*puVar7);
      if (iVar2 == 0) {
        iVar4 = (iVar4 + 3U & 0xfffffffc) + 0x10;
      }
      FUN_20154790(puVar7,iVar4);
      (&DAT_208dbca4)[param_1] = 0;
      if (!bVar1) {
        software_interrupt(0);
        return FUN_201567f4;
      }
      software_interrupt(0);
      return FUN_2015655c;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_dis_dsp @ 20150678 (164 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): E_CTX in ISR/CPU-locked;
   sets the dispatch-disabled bits (|= 9) of 0x208003DB [inference] */

code * itron_dis_dsp(void)

{
  software_interrupt(0);
  if ((DAT_208003db & 1) == 0) {
    if ((DAT_208003da != '\0') || (DAT_208dc18c == (char)((char)DAT_201659d0 + '\x01'))) {
      software_interrupt(0);
      DAT_208003d4 = 0xffffffe7;
      return (code *)0xffffffe7;
    }
    DAT_208003db = DAT_208003db | 9;
  }
  else if (((byte)DAT_208003cc & 0x80) != 0) {
    software_interrupt(0);
    DAT_208003d4 = 0xffffffe7;
    return (code *)0xffffffe7;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== itron_dly_tsk @ 20150740 (172 bytes)

undefined4 itron_dly_tsk(int param_1)

{
  undefined4 uVar1;
  uint uVar2;
  int iVar3;
  
  if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
     (uVar2 = (uint)DAT_208dc18c, uVar2 != ((byte)DAT_201659d0 + 1 & 0xff))) {
    iVar3 = *(int *)(&DAT_208dbba0 + uVar2 * 4);
    software_interrupt(0);
    if (param_1 != 0) {
      knl_timeout_add(param_1,iVar3,uVar2);
      *(undefined1 *)(iVar3 + 5) = 0x32;
      uVar1 = FUN_201545c8(iVar3,uVar2);
      return uVar1;
    }
    software_interrupt(0);
    return 0;
  }
  DAT_208003d4 = 0xffffffe7;
  return 0xffffffe7;
}


// ===== itron_ena_dsp @ 2015080c (184 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): clears the
   dispatch-disabled bits of 0x208003DB, dispatches when a switch is pending (0x208003D9)
   [inference] */

code * itron_ena_dsp(void)

{
  software_interrupt(0);
  if ((DAT_208003db & 1) != 0) {
    if ((DAT_208003da != '\0') || (DAT_208dc18c == (char)((char)DAT_201659d0 + '\x01'))) {
      software_interrupt(0);
      DAT_208003d4 = 0xffffffe7;
      return (code *)0xffffffe7;
    }
    if ((DAT_208003db & 0x10) == 0) {
      DAT_208003db = DAT_208003db & 0xf6;
      if ((DAT_208003db == 0) && (DAT_208003d9 != '\0')) {
        software_interrupt(0);
        return FUN_20156748;
      }
    }
    else {
      DAT_208003db = DAT_208003db & 0xf7;
    }
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== itron_ext_tsk @ 201508ec (264 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): current task: back to the
   initial priority, unlocks its mutexes, dormant or restarts when the activation count +0x26 > 0
   [inference] */

code * itron_ext_tsk(void)

{
  undefined1 uVar1;
  char cVar2;
  undefined4 *puVar3;
  int iVar4;
  uint uVar5;
  
  cVar2 = DAT_208003da;
  if (DAT_208003da == '\0') {
    cVar2 = DAT_208003db;
  }
  if ((DAT_208003da == '\0' && cVar2 == '\0') && (DAT_208dc18c != (byte)((char)DAT_201659d0 + 1U)))
  {
    software_interrupt(0);
    uVar5 = (uint)DAT_208dc18c;
    iVar4 = *(int *)(&DAT_208dbba0 + uVar5 * 4);
    uVar1 = *(undefined1 *)(*(int *)(iVar4 + 0x18) + 0xc);
    *(undefined1 *)(iVar4 + 4) = uVar1;
    *(undefined1 *)(iVar4 + 0x27) = uVar1;
    puVar3 = *(undefined4 **)(iVar4 + 0x1c);
    if (puVar3 != (undefined4 *)0x0) {
      *puVar3 = 0;
      *(undefined2 *)(puVar3 + 2) = 1;
      puVar3[1] = 0;
    }
    FUN_201539ec(iVar4,uVar5);
    if (*(short *)(iVar4 + 0x24) != 0) {
      FUN_20154930();
      *(undefined2 *)(iVar4 + 0x24) = 0;
    }
    if (*(char *)(iVar4 + 0x26) < '\x01') {
      *(undefined1 *)(iVar4 + 5) = 0;
    }
    else {
      *(char *)(iVar4 + 0x26) = *(char *)(iVar4 + 0x26) + -1;
      FUN_20156860(*(int *)(iVar4 + 0x14) + *(int *)(*(int *)(iVar4 + 0x18) + 0x10) + -0x48,
                   *(undefined4 *)(*(int *)(iVar4 + 0x18) + 4),iVar4,uVar5);
    }
    software_interrupt(0);
    return FUN_2015677c;
  }
  DAT_208003d4 = 0xffffffe7;
  DAT_208003db = 0;
  return (code *)&DAT_208003db;
}


// ===== FUN_201509f4 @ 201509f4 (148 bytes)

code * FUN_201509f4(undefined4 *param_1,undefined4 param_2,int *param_3,undefined4 param_4)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = *(uint *)(param_3[6] + 8);
  param_1[0xc] = param_1 + 0x12;
  *param_1 = param_2;
  uVar1 = DAT_208003ac;
  if ((uVar2 & 1) != 0) {
    uVar1 = DAT_208003ac | 0x20;
  }
  param_1[0xf] = uVar1;
  uVar1 = FUN_201568b8();
  param_1[0xf] = uVar1 | param_1[0xf];
  param_1[0xd] = itron_ext_tsk;
  param_1[0x11] = uVar2;
  *param_3 = (int)param_1;
  *(undefined1 *)(param_3 + 2) = 0;
  *(undefined1 *)((int)param_3 + 9) = 0;
  param_3[8] = 0;
  *(undefined1 *)((int)param_3 + 5) = 0x10;
  FUN_201538d4(&DAT_208dc18c + *(char *)((int)param_3 + 0x27),param_3,param_4);
  software_interrupt(0);
  return FUN_2015677c;
}


// ===== itron_get_pri @ 20150aac (212 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (tskid, p_tskpri): id 0 =
   self, E_OBJ when dormant, *p = TCB+4 [inference] */

code * itron_get_pri(uint param_1,int *param_2)

{
  int iVar1;
  bool bVar2;
  
  bVar2 = param_1 == 0;
  if (bVar2) {
    param_1 = (uint)DAT_208dc18c;
  }
  if ((DAT_201659d0 < param_1) || (DAT_208003da != '\0' && bVar2)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  if (DAT_208dc18c == param_1) {
    *param_2 = (int)*(char *)(*(int *)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4) + 4);
    return (code *)0x0;
  }
  software_interrupt(0);
  iVar1 = *(int *)(&DAT_208dbba0 + param_1 * 4);
  if (iVar1 != 0) {
    if (*(char *)(iVar1 + 5) != '\0') {
      *param_2 = (int)*(char *)(iVar1 + 4);
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return (code *)0xffffffd7;
  }
  software_interrupt(0);
  return (code *)0xffffffd6;
}


// ===== itron_get_tid @ 20150ba0 (44 bytes)

/* (*p_tskid): current task ID [inference]; fs_task_ctx_get indexes 0x2091D0BC[1..0x100] with it
   [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (p_tskid):
   running task id or 0 (TSK_NONE) [inference] */

undefined4 itron_get_tid(uint *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)DAT_208dc18c;
  if (uVar1 == ((byte)DAT_201659d0 + 1 & 0xff)) {
    uVar1 = 0;
  }
  *param_1 = uVar1;
  return 0;
}


// ===== itron_get_tim @ 20150bd4 (88 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (p_systim): SYSTIM {H
   utime, UW ltime} from 0x208003BC..C8 with carry [inference] */

code * itron_get_tim(short *param_1)

{
  short sVar1;
  uint uVar2;
  
  software_interrupt(0);
  uVar2 = DAT_208003c8 + DAT_208003c0;
  *(uint *)(param_1 + 2) = uVar2;
  sVar1 = DAT_208003bc + DAT_208003c4;
  *param_1 = sVar1;
  if (uVar2 < DAT_208003c8) {
    *param_1 = sVar1 + 1;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== itron_loc_cpu @ 20150c3c (44 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): masks interrupts and sets
   the CPU-locked state 0x13/0x1B in 0x208003DB [inference] */

undefined4 itron_loc_cpu(void)

{
  software_interrupt(0);
  if ((DAT_208003db & 8) == 0) {
    DAT_208003db = 0x13;
  }
  else {
    DAT_208003db = 0x1b;
  }
  return 0;
}


// ===== itron_rel_mpf @ 20150c70 (320 bytes)

/* (mpfid, blk): returns a block to the pool; used by fs_work_free [inference]; T23d NORTi uITRON
   4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (mpfid, blk): mpf table 0x208DBF24, E_PAR
   if blk misaligned/outside the pool, hands the block to a waiter [inference] */

code * itron_rel_mpf(uint param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  code *pcVar4;
  byte *pbVar5;
  int *piVar6;
  
  if ((param_1 == 0) || (0x10 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar3 = (&DAT_208dbf24)[param_1];
  if (iVar3 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (((((uint)param_2 & 3) == 0) && (*(int **)(iVar3 + 8) <= param_2)) &&
     (param_2 < (int *)((int)*(int **)(iVar3 + 8) + *(int *)(iVar3 + 0xc)))) {
    if (*(int *)(iVar3 + 4) == 0) {
      pbVar5 = (byte *)(iVar3 + 0x12);
      bVar1 = *(byte *)(iVar3 + 0x12);
      while (uVar2 = (uint)bVar1, uVar2 < 0xfe) {
        if (uVar2 != 0) {
          piVar6 = *(int **)(&DAT_208dbba0 + uVar2 * 4);
          **(uint **)(*piVar6 + 0xc) = (uint)param_2;
          if ((*(byte *)((int)piVar6 + 5) & 2) != 0) {
            knl_timeout_remove(piVar6,uVar2);
          }
          *(undefined1 *)((int)piVar6 + 5) = 0x10;
          if (*(char *)((int)piVar6 + 9) != '\0') {
            pcVar4 = (code *)FUN_20154524();
            return pcVar4;
          }
          pcVar4 = (code *)FUN_20154580(piVar6,uVar2);
          return pcVar4;
        }
        pbVar5 = pbVar5 + 1;
        bVar1 = *pbVar5;
      }
    }
    *param_2 = *(int *)(iVar3 + 4);
    *(int **)(iVar3 + 4) = param_2;
    *(short *)(iVar3 + 0x10) = *(short *)(iVar3 + 0x10) + 1;
    software_interrupt(0);
    return FUN_201567f4;
  }
  software_interrupt(0);
  return (code *)0xffffffef;
}


// ===== itron_rot_rdq @ 20150dcc (276 bytes)

/* (tskpri): 0 = own priority, 1..8: rotates the ready queue 0x208DC18C[pri] and dispatches [fact];
   T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (tskpri <= 8, 0 = own
   priority): rotates the ready queue 0x208DC18C[pri], E_PAR [inference] */

code * itron_rot_rdq(uint param_1)

{
  int iVar1;
  uint uVar2;
  byte *pbVar3;
  
  if (param_1 == 0) {
    if (DAT_208dc18c != (byte)((char)DAT_201659d0 + 1U)) {
      software_interrupt(0);
      uVar2 = (uint)DAT_208dc18c;
      iVar1 = *(int *)(&DAT_208dbba0 + uVar2 * 4);
      if ((int)*(char *)(iVar1 + 0x27) == (int)DAT_208003df) {
        pbVar3 = *(byte **)(iVar1 + 0x10);
      }
      else {
        pbVar3 = &DAT_208dc18c + *(char *)(iVar1 + 0x27);
        uVar2 = (uint)*pbVar3;
        if (uVar2 == 0) {
          software_interrupt(0);
          return FUN_201567f4;
        }
        iVar1 = *(int *)(&DAT_208dbba0 + uVar2 * 4);
      }
      if (*(byte *)(iVar1 + 6) == uVar2) {
        software_interrupt(0);
        return FUN_201567f4;
      }
      *pbVar3 = *(byte *)(iVar1 + 6);
      software_interrupt(0);
      return FUN_2015655c;
    }
  }
  else if (param_1 < 9) {
    software_interrupt(0);
    uVar2 = (uint)(&DAT_208dc18c)[param_1];
    if (((uVar2 != 0) && (*(byte *)(*(int *)(&DAT_208dbba0 + uVar2 * 4) + 6) != uVar2)) &&
       ((&DAT_208dc18c)[param_1] = *(byte *)(*(int *)(&DAT_208dbba0 + uVar2 * 4) + 6),
       (int)param_1 <= (int)DAT_208003df)) {
      software_interrupt(0);
      return FUN_2015655c;
    }
    software_interrupt(0);
    return FUN_201567f4;
  }
  DAT_208003d4 = 0xffffffef;
  return (code *)0xffffffef;
}


// ===== itron_set_flg @ 20150f00 (704 bytes)

code * itron_set_flg(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  byte bVar1;
  byte bVar2;
  byte bVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  uint *puVar7;
  uint *extraout_r2;
  int *piVar8;
  uint uVar9;
  int iVar10;
  byte *pbVar11;
  bool bVar12;
  
  if (param_2 == 0) {
    DAT_208003d4 = (code *)0x0;
  }
  else {
    if ((param_1 != 0) && (param_1 < 0x41)) {
      software_interrupt(0);
      iVar10 = *(int *)(&DAT_208dbda4 + param_1 * 4);
      if (iVar10 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      for (pbVar11 = (byte *)(iVar10 + 9); uVar9 = (uint)*pbVar11, uVar9 == 0; pbVar11 = pbVar11 + 1
          ) {
      }
      if (0xfd < uVar9) {
        *(uint *)(iVar10 + 4) = *(uint *)(iVar10 + 4) | param_2;
        software_interrupt(0);
        return FUN_201567f4;
      }
      piVar8 = *(int **)(&DAT_208dbba0 + uVar9 * 4);
      uVar6 = (uint)*(byte *)((int)piVar8 + 7);
      bVar12 = uVar6 == uVar9;
      if (bVar12) {
        uVar6 = (uint)*(byte *)(iVar10 + 8);
      }
      if (!bVar12 || (uVar6 & 2) != 0) {
        bVar12 = false;
        param_2 = param_2 | *(uint *)(iVar10 + 4);
LAB_20150fa4:
        piVar8 = *(int **)(&DAT_208dbba0 + (uint)*pbVar11 * 4);
        bVar1 = *(byte *)((int)piVar8 + 7);
        uVar9 = (uint)*pbVar11;
        do {
          bVar2 = *(byte *)((int)piVar8 + 5);
          bVar3 = *(byte *)((int)piVar8 + 6);
          if ((bVar2 & 1) == 0) {
            if ((*(uint *)(*piVar8 + 8) & ~param_2) == 0) goto LAB_2015109c;
          }
          else if ((*(uint *)(*piVar8 + 8) & param_2) != 0) {
LAB_2015109c:
            **(uint **)(*piVar8 + 0xc) = param_2;
            if ((bVar2 & 2) != 0) {
              knl_timeout_remove(piVar8,uVar9);
            }
            *(undefined1 *)((int)piVar8 + 5) = 0x10;
            if (*(char *)((int)piVar8 + 9) == '\0') {
              iVar5 = (int)(char)piVar8[1];
              if (iVar5 < DAT_208003df) {
                bVar12 = (bool)(bVar12 | iVar5 < DAT_208003df);
              }
              FUN_20153a38(&DAT_208dc18c + iVar5,piVar8,uVar9);
            }
            else {
              FUN_201539ec(piVar8,uVar9);
            }
            if ((bVar2 & 4) != 0) {
              *(undefined4 *)(iVar10 + 4) = 0;
              if (!bVar12) {
                software_interrupt(0);
                return FUN_201567f4;
              }
              software_interrupt(0);
              return FUN_2015655c;
            }
          }
          if (bVar1 == uVar9) goto LAB_2015116c;
          piVar8 = *(int **)(&DAT_208dbba0 + (uint)bVar3 * 4);
          uVar9 = (uint)bVar3;
        } while( true );
      }
      bVar1 = *(byte *)((int)piVar8 + 5);
      if ((bVar1 & 1) == 0) {
        param_2 = *(uint *)(iVar10 + 4) | param_2;
        if ((*(uint *)(*piVar8 + 8) & ~param_2) != 0) goto LAB_20151030;
      }
      else {
        param_2 = *(uint *)(iVar10 + 4) | param_2;
        if ((*(uint *)(*piVar8 + 8) & param_2) == 0) {
LAB_20151030:
          *(uint *)(iVar10 + 4) = param_2;
          software_interrupt(0);
          return FUN_201567f4;
        }
      }
      puVar7 = *(uint **)(*piVar8 + 0xc);
      *puVar7 = param_2;
      if ((bVar1 & 4) != 0) {
        param_2 = 0;
      }
      *(uint *)(iVar10 + 4) = param_2;
      if ((bVar1 & 2) != 0) {
        knl_timeout_remove(piVar8,uVar9);
        puVar7 = extraout_r2;
      }
      *(undefined1 *)((int)piVar8 + 5) = 0x10;
      if (*(char *)((int)piVar8 + 9) == '\0') {
        pcVar4 = (code *)FUN_20154580(piVar8,uVar9,puVar7,param_4);
        return pcVar4;
      }
      pcVar4 = (code *)FUN_20154524();
      return pcVar4;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  return DAT_208003d4;
LAB_2015116c:
  do {
    pbVar11 = pbVar11 + 1;
  } while (*pbVar11 == 0);
  if (0xfd < *pbVar11) {
    *(uint *)(iVar10 + 4) = param_2;
    if (!bVar12) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    software_interrupt(0);
    return FUN_2015655c;
  }
  goto LAB_20150fa4;
}


// ===== itron_sig_sem @ 201511e8 (260 bytes)

/* (semid 1..0x40): semaphore table 0x208DBCA4, E_ID / E_NOEXS, releases a waiting task or counts up
   [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): sem table
   0x208DBCA4 (64): wakes the first waiter or count++, E_QOVR at maxsem [inference] */

code * itron_sig_sem(uint param_1)

{
  short sVar1;
  int iVar2;
  code *pcVar3;
  byte *pbVar4;
  uint uVar5;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar2 = (&DAT_208dbca4)[param_1];
  if (iVar2 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  sVar1 = *(short *)(iVar2 + 4);
  if (sVar1 == 0) {
    pbVar4 = (byte *)(iVar2 + 8);
    do {
      uVar5 = (uint)*pbVar4;
      pbVar4 = pbVar4 + 1;
    } while (uVar5 == 0);
    if (uVar5 < 0xfe) {
      iVar2 = *(int *)(&DAT_208dbba0 + uVar5 * 4);
      if ((*(byte *)(iVar2 + 5) & 2) != 0) {
        knl_timeout_remove(iVar2,uVar5);
      }
      *(undefined1 *)(iVar2 + 5) = 0x10;
      if (*(char *)(iVar2 + 9) != '\0') {
        pcVar3 = (code *)FUN_20154524();
        return pcVar3;
      }
      pcVar3 = (code *)FUN_20154580(iVar2,uVar5);
      return pcVar3;
    }
  }
  *(short *)(iVar2 + 4) = sVar1 + 1;
  if (sVar1 == *(short *)(iVar2 + 6)) {
    *(short *)(iVar2 + 4) = *(short *)(iVar2 + 6);
    software_interrupt(0);
    return (code *)0xffffffd5;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== itron_tsnd_dtq @ 20151308 (484 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (dtqid, data, tmout): dtq
   table 0x208DBFA4, hands data to a receiver or the ring buffer, E_TMOUT on polling, waits
   otherwise [inference] */

code * itron_tsnd_dtq(uint param_1,undefined4 param_2,int param_3)

{
  undefined1 uVar1;
  int iVar2;
  code *pcVar3;
  undefined4 *puVar4;
  int iVar5;
  int *piVar6;
  int iVar7;
  uint uVar8;
  
  if ((param_1 == 0) || (8 < param_1)) {
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    software_interrupt(0);
    iVar5 = *(int *)(&DAT_208dbfa4 + param_1 * 4);
    if (iVar5 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    if ((*(short *)(iVar5 + 0x16) == 0) && (uVar8 = (uint)*(byte *)(iVar5 + 0x18), uVar8 != 0)) {
      piVar6 = *(int **)(&DAT_208dbba0 + uVar8 * 4);
      **(undefined4 **)(*piVar6 + 0xc) = param_2;
      if ((*(byte *)((int)piVar6 + 5) & 2) != 0) {
        knl_timeout_remove(piVar6,uVar8);
      }
      *(undefined1 *)((int)piVar6 + 5) = 0x10;
      if (*(char *)((int)piVar6 + 9) != '\0') {
        pcVar3 = (code *)FUN_20154524();
        return pcVar3;
      }
      pcVar3 = (code *)FUN_20154580(piVar6,uVar8);
      return pcVar3;
    }
    if (*(short *)(iVar5 + 0x16) != *(short *)(iVar5 + 0x14)) {
      puVar4 = *(undefined4 **)(iVar5 + 8) + 1;
      **(undefined4 **)(iVar5 + 8) = param_2;
      *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + 1;
      if (*(undefined4 **)(iVar5 + 0x10) <= puVar4) {
        puVar4 = *(undefined4 **)(iVar5 + 4);
      }
      *(undefined4 **)(iVar5 + 8) = puVar4;
      software_interrupt(0);
      return FUN_201567f4;
    }
    if (param_3 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
       (uVar8 = (uint)DAT_208dc18c, uVar8 != ((byte)DAT_201659d0 + 1 & 0xff))) {
      iVar7 = *(int *)(&DAT_208dbba0 + uVar8 * 4);
      if (param_3 == -1) {
        uVar1 = 100;
      }
      else {
        knl_timeout_add(param_3,iVar7,uVar8);
        uVar1 = 0x66;
      }
      *(undefined1 *)(iVar7 + 5) = uVar1;
      iVar2 = iVar5 + 0x1a;
      if (*(byte *)(iVar5 + 0x1b) < 0xfe) {
        iVar2 = iVar2 + DAT_208003df + -1;
      }
      DAT_208003e8 = param_2;
      DAT_208003ec = param_1;
      pcVar3 = (code *)FUN_201545dc(iVar2,iVar7,uVar8);
      return pcVar3;
    }
    software_interrupt(0);
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_snd_mbx @ 20151520 (324 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (mbxid, pk_msg): mbx
   table 0x208DBEA4, priority queues by msgpri (E_PAR), or wakes a receiver [inference] */

code * itron_snd_mbx(uint param_1,undefined4 *param_2)

{
  int iVar1;
  byte *pbVar2;
  code *pcVar3;
  int iVar4;
  undefined4 *puVar5;
  uint uVar6;
  uint uVar7;
  int *piVar8;
  bool bVar9;
  
  if ((param_1 == 0) || (8 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  puVar5 = *(undefined4 **)(&DAT_208dbea4 + param_1 * 4);
  if (puVar5 == (undefined4 *)0x0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  pbVar2 = (byte *)((int)puVar5 + 7);
  do {
    uVar7 = (uint)*pbVar2;
    pbVar2 = pbVar2 + 1;
  } while (uVar7 == 0);
  if (0xfd < uVar7) {
    uVar7 = (uint)*(byte *)((int)puVar5 + 6);
    if (uVar7 != 0) {
      piVar8 = (int *)(uVar7 + (int)puVar5);
    }
    else {
      piVar8 = (int *)*puVar5;
    }
    uVar6 = (uint)*(byte *)(puVar5 + 1);
    if (uVar7 == 0) {
      piVar8 = (int *)piVar8[2];
    }
    if (1 < uVar6) {
      iVar4 = param_2[1];
      bVar9 = SBORROW4(uVar6,iVar4);
      iVar1 = uVar6 - iVar4;
      if (iVar4 <= (int)uVar6) {
        bVar9 = SBORROW4(iVar4,1);
        iVar1 = iVar4 + -1;
      }
      if (iVar1 < 0 != bVar9) {
        software_interrupt(0);
        return (code *)0xffffffef;
      }
      piVar8 = piVar8 + iVar4 * 2 + -2;
    }
    if (*piVar8 == 0) {
      *piVar8 = (int)param_2;
    }
    else {
      *(undefined4 **)piVar8[1] = param_2;
    }
    piVar8[1] = (int)param_2;
    *param_2 = 0;
    software_interrupt(0);
    return FUN_201567f4;
  }
  piVar8 = *(int **)(&DAT_208dbba0 + uVar7 * 4);
  **(undefined4 **)(*piVar8 + 0xc) = param_2;
  if ((*(byte *)((int)piVar8 + 5) & 2) != 0) {
    knl_timeout_remove(piVar8,uVar7);
  }
  *(undefined1 *)((int)piVar8 + 5) = 0x10;
  if (*(char *)((int)piVar8 + 9) == '\0') {
    pcVar3 = (code *)FUN_20154580(piVar8,uVar7);
    return pcVar3;
  }
  pcVar3 = (code *)FUN_20154524();
  return pcVar3;
}


// ===== itron_sta_cyc @ 20151680 (204 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): cyc table 0x208DBF64:
   (re)inserts the handler into timer queue 0x208003C4, sets TCYC_STA [inference] */

code * itron_sta_cyc(uint param_1)

{
  uint uVar1;
  int iVar2;
  
  if ((param_1 != 0) && (param_1 < 9)) {
    software_interrupt(0);
    iVar2 = *(int *)(&DAT_208dbf64 + param_1 * 4);
    if (iVar2 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    uVar1 = *(uint *)(iVar2 + 0xc);
    if ((uVar1 & 4) == 0) {
      if ((uVar1 & 1) != 0) {
        FUN_201535b4(&DAT_208dbf64,iVar2,param_1);
        *(undefined1 *)(iVar2 + 8) = 0;
        *(undefined1 *)(iVar2 + 9) = 0;
      }
      FUN_201543e4(iVar2 + 0x10,&DAT_208003c4,iVar2);
      FUN_20153720(&DAT_208dbf64,iVar2,param_1);
      *(uint *)(iVar2 + 0xc) = *(uint *)(iVar2 + 0xc) | 1;
    }
    else {
      *(uint *)(iVar2 + 0xc) = uVar1 | 1;
    }
    software_interrupt(0);
    return FUN_201567f4;
  }
  DAT_208003d4 = 0xffffffee;
  return (code *)0xffffffee;
}


// ===== itron_sta_tsk @ 20151768 (244 bytes)

uint itron_sta_tsk(uint param_1,uint param_2)

{
  int iVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  
  if (param_1 == 0) {
    DAT_208003d4 = 0xffffffd7;
  }
  else {
    if (param_1 <= DAT_201659d0) {
      software_interrupt(0);
      piVar3 = *(int **)(&DAT_208dbba0 + param_1 * 4);
      if (piVar3 == (int *)0x0) {
        software_interrupt(0);
        return 0xffffffd6;
      }
      if (*(char *)((int)piVar3 + 5) == '\0') {
        uVar4 = *(uint *)(piVar3[6] + 8);
        iVar1 = piVar3[5] + *(int *)(piVar3[6] + 0x10);
        *(int *)(iVar1 + -0x18) = iVar1;
        *(uint *)(iVar1 + -0x48) = param_2;
        uVar2 = DAT_208003ac;
        if ((uVar4 & 1) != 0) {
          uVar2 = DAT_208003ac | 0x20;
        }
        *(uint *)(iVar1 + -0xc) = uVar2;
        uVar2 = FUN_201568b8();
        *(uint *)(iVar1 + -0xc) = uVar2 | *(uint *)(iVar1 + -0xc);
        *(code **)(iVar1 + -0x14) = itron_ext_tsk;
        *(uint *)(iVar1 + -4) = uVar4;
        *piVar3 = iVar1 + -0x48;
        *(undefined1 *)(piVar3 + 2) = 0;
        *(undefined1 *)((int)piVar3 + 9) = 0;
        piVar3[8] = 0;
        *(undefined1 *)((int)piVar3 + 5) = 0x10;
        uVar2 = FUN_20154538(piVar3,param_1);
        return uVar2;
      }
      software_interrupt(0);
      return 0xffffffd7;
    }
    DAT_208003d4 = 0xffffffee;
  }
  return DAT_208003d4;
}


// ===== itron_stp_cyc @ 20151878 (164 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): cyc table 0x208DBF64:
   removes it from the timer queue, clears TCYC_STA [inference] */

code * itron_stp_cyc(uint param_1)

{
  int iVar1;
  
  if ((param_1 != 0) && (param_1 < 9)) {
    software_interrupt(0);
    iVar1 = *(int *)(&DAT_208dbf64 + param_1 * 4);
    if (iVar1 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    if ((*(uint *)(iVar1 + 0xc) & 1) != 0) {
      if ((*(uint *)(iVar1 + 0xc) & 4) == 0) {
        FUN_201535b4(&DAT_208dbf64,iVar1,param_1);
        *(undefined1 *)(iVar1 + 8) = 0;
        *(undefined1 *)(iVar1 + 9) = 0;
      }
      *(uint *)(iVar1 + 0xc) = *(uint *)(iVar1 + 0xc) & 0xfffffffe;
    }
    software_interrupt(0);
    return FUN_201567f4;
  }
  DAT_208003d4 = 0xffffffef;
  return (code *)0xffffffef;
}


// ===== itron_sus_tsk @ 20151934 (328 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): id 0 = self, E_OBJ
   dormant, suspend count TCB+9 ++ (E_QOVR at 255), E_CTX for self with dispatch disabled
   [inference] */

code * itron_sus_tsk(uint param_1)

{
  int iVar1;
  code *pcVar2;
  char cVar3;
  
  if ((((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
      (DAT_208dc18c != (byte)((char)DAT_201659d0 + 1U))) || (param_1 != 0)) {
    if (param_1 <= DAT_201659d0) {
      if (param_1 == 0) {
        param_1 = (uint)DAT_208dc18c;
      }
      software_interrupt(0);
      iVar1 = *(int *)(&DAT_208dbba0 + param_1 * 4);
      if (iVar1 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if (*(char *)(iVar1 + 5) == '\0') {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      cVar3 = *(char *)(iVar1 + 9) + '\x01';
      *(char *)(iVar1 + 9) = cVar3;
      if (cVar3 == '\0') {
        *(undefined1 *)(iVar1 + 9) = 0xff;
        software_interrupt(0);
        return (code *)0xffffffd5;
      }
      if (cVar3 != '\x01' || *(char *)(iVar1 + 5) != '\x10') {
        software_interrupt(0);
        return FUN_201567f4;
      }
      if ((uint)DAT_208dc18c == (param_1 & 0xff)) {
        if (DAT_208003da == '\0') {
          pcVar2 = (code *)FUN_201545c8(iVar1,param_1);
          return pcVar2;
        }
        DAT_208003d9 = 1;
      }
      pcVar2 = (code *)FUN_20154524(iVar1,param_1);
      return pcVar2;
    }
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_tget_mpf @ 20151aa4 (356 bytes)

/* (mpfid 1..0x10, *p_blk, tmout): takes a block from the free list of pool table 0x208DBF24 or
   waits; E_TMOUT for tmout 0 [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO)
   (uitron_api_shape 0.950): (mpfid, p_blk, tmout): mpf table 0x208DBF24, pops the free list,
   E_TMOUT polling, waits otherwise [inference] */

code * itron_tget_mpf(uint param_1,int *param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  int iVar3;
  code *pcVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  
  if ((param_1 == 0) || (0x10 < param_1)) {
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    software_interrupt(0);
    iVar5 = (&DAT_208dbf24)[param_1];
    if (iVar5 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    puVar2 = *(undefined4 **)(iVar5 + 4);
    if (puVar2 != (undefined4 *)0x0) {
      *param_2 = (int)puVar2;
      *(undefined4 *)(iVar5 + 4) = *puVar2;
      *(short *)(iVar5 + 0x10) = *(short *)(iVar5 + 0x10) + -1;
      software_interrupt(0);
      return FUN_201567f4;
    }
    if (param_3 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
       (uVar7 = (uint)DAT_208dc18c, uVar7 != ((byte)DAT_201659d0 + 1 & 0xff))) {
      iVar6 = *(int *)(&DAT_208dbba0 + uVar7 * 4);
      if (param_3 == -1) {
        uVar1 = 0xd0;
      }
      else {
        knl_timeout_add(param_3,iVar6,uVar7);
        uVar1 = 0xd2;
      }
      *(undefined1 *)(iVar6 + 5) = uVar1;
      iVar3 = iVar5 + 0x12;
      if (*(byte *)(iVar5 + 0x13) < 0xfe) {
        iVar3 = iVar3 + DAT_208003df + -1;
      }
      DAT_208003e8 = param_2;
      DAT_208003ec = param_1;
      pcVar4 = (code *)FUN_201545dc(iVar3,iVar6,uVar7);
      return pcVar4;
    }
    software_interrupt(0);
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_tloc_mtx @ 20151c3c (504 bytes)

/* (mtxid 1..0x20, tmout): table 0x208DBFC4, E_ILUSE, E_TMOUT [fact]; the RTC I2C lock (rtc_read_* /
   rtc_write_*) [fact]; T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900):
   (mtxid, tmout): mtx table 0x208DBFC4 (32), owner +10, ceiling/inherit, E_ILUSE, E_TMOUT
   [inference] */

code * itron_tloc_mtx(uint param_1,int param_2)

{
  undefined2 uVar1;
  char cVar2;
  undefined1 uVar3;
  int iVar4;
  code *pcVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  uint uVar10;
  
  if ((param_1 == 0) || (0x20 < param_1)) {
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
       (DAT_208dc18c != (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      iVar6 = *(int *)(&DAT_208dbfc4 + param_1 * 4);
      if (iVar6 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      uVar10 = (uint)DAT_208dc18c;
      if (*(byte *)(iVar6 + 10) == uVar10) {
        software_interrupt(0);
      }
      else {
        iVar9 = *(int *)(iVar6 + 4);
        cVar2 = *(char *)(iVar6 + 0xb);
        iVar8 = (int)cVar2;
        iVar7 = *(int *)(&DAT_208dbba0 + uVar10 * 4);
        if ((iVar9 != 3) || (iVar8 <= *(char *)(iVar7 + 0x27))) {
          if (*(byte *)(iVar6 + 10) != 0) {
            if (param_2 == 0) {
              software_interrupt(0);
              return (code *)0xffffffce;
            }
            if (param_2 == -1) {
              uVar3 = 0x94;
            }
            else {
              knl_timeout_add(param_2,iVar7,uVar10);
              uVar3 = 0x96;
            }
            *(undefined1 *)(iVar7 + 5) = uVar3;
            iVar4 = iVar6 + 0xc;
            if (*(byte *)(iVar6 + 0xd) < 0xfe) {
              iVar4 = iVar4 + DAT_208003df + -1;
            }
            DAT_208003ec = param_1;
            FUN_20153a38(iVar4,iVar7,uVar10);
            if ((iVar9 == 2) && (DAT_208003df < iVar8)) {
              *(char *)(iVar6 + 0xb) = DAT_208003df;
              FUN_20153f28(*(undefined1 *)(iVar6 + 10));
            }
            software_interrupt(0);
            return FUN_201566f0;
          }
          *(byte *)(iVar6 + 10) = DAT_208dc18c;
          uVar1 = *(undefined2 *)(iVar7 + 0x24);
          *(short *)(iVar7 + 0x24) = (short)param_1;
          *(undefined2 *)(iVar6 + 8) = uVar1;
          if (iVar9 == 2) {
            *(undefined1 *)(iVar6 + 0xb) = *(undefined1 *)(iVar7 + 4);
          }
          else if ((iVar9 == 3) && (iVar8 < *(char *)(iVar7 + 4))) {
            *(char *)(iVar7 + 4) = cVar2;
            pcVar5 = (code *)FUN_201545dc(&DAT_208dc18c + iVar8,iVar7,uVar10);
            return pcVar5;
          }
          software_interrupt(0);
          return FUN_201567f4;
        }
        software_interrupt(0);
      }
      return (code *)0xffffffe4;
    }
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_trcv_dtq @ 20151e68 (536 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (dtqid, p_data, tmout):
   dtq table 0x208DBFA4, takes from the ring buffer or a sender, E_TMOUT [inference] */

code * itron_trcv_dtq(uint param_1,undefined4 *param_2,int param_3)

{
  undefined1 uVar1;
  undefined4 *puVar2;
  byte *pbVar3;
  code *pcVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  int iVar8;
  
  if ((param_1 == 0) || (8 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar5 = *(int *)(&DAT_208dbfa4 + param_1 * 4);
  if (iVar5 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (*(short *)(iVar5 + 0x16) == 0) {
    pbVar3 = (byte *)(iVar5 + 0x1a);
    do {
      uVar6 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (uVar6 == 0);
    if (0xfd < uVar6) {
      if (param_3 == 0) {
        software_interrupt(0);
        return (code *)0xffffffce;
      }
      if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
         (uVar6 = (uint)DAT_208dc18c, uVar6 != ((byte)DAT_201659d0 + 1 & 0xff))) {
        iVar8 = *(int *)(&DAT_208dbba0 + uVar6 * 4);
        if (param_3 == -1) {
          uVar1 = 0xb4;
        }
        else {
          knl_timeout_add(param_3,iVar8,uVar6);
          uVar1 = 0xb6;
        }
        *(undefined1 *)(iVar8 + 5) = uVar1;
        DAT_208003e8 = param_2;
        DAT_208003ec = param_1;
        pcVar4 = (code *)FUN_201545dc(iVar5 + 0x18,iVar8,uVar6);
        return pcVar4;
      }
      software_interrupt(0);
      DAT_208003d4 = 0xffffffe7;
      return (code *)0xffffffe7;
    }
    piVar7 = *(int **)(&DAT_208dbba0 + uVar6 * 4);
    *param_2 = *(undefined4 *)(*piVar7 + 0xc);
  }
  else {
    puVar2 = *(undefined4 **)(iVar5 + 0xc) + 1;
    *param_2 = **(undefined4 **)(iVar5 + 0xc);
    *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + -1;
    if (*(undefined4 **)(iVar5 + 0x10) <= puVar2) {
      puVar2 = *(undefined4 **)(iVar5 + 4);
    }
    *(undefined4 **)(iVar5 + 0xc) = puVar2;
    pbVar3 = (byte *)(iVar5 + 0x1a);
    do {
      uVar6 = (uint)*pbVar3;
      pbVar3 = pbVar3 + 1;
    } while (uVar6 == 0);
    if (0xfd < uVar6) {
      software_interrupt(0);
      return FUN_201567f4;
    }
    piVar7 = *(int **)(&DAT_208dbba0 + uVar6 * 4);
    puVar2 = *(undefined4 **)(iVar5 + 8) + 1;
    **(undefined4 **)(iVar5 + 8) = *(undefined4 *)(*piVar7 + 0xc);
    *(short *)(iVar5 + 0x16) = *(short *)(iVar5 + 0x16) + 1;
    if (*(undefined4 **)(iVar5 + 0x10) <= puVar2) {
      puVar2 = *(undefined4 **)(iVar5 + 4);
    }
    *(undefined4 **)(iVar5 + 8) = puVar2;
  }
  if ((*(byte *)((int)piVar7 + 5) & 2) != 0) {
    knl_timeout_remove(piVar7,uVar6);
  }
  *(undefined1 *)((int)piVar7 + 5) = 0x10;
  if (*(char *)((int)piVar7 + 9) != '\0') {
    pcVar4 = (code *)FUN_20154524();
    return pcVar4;
  }
  pcVar4 = (code *)FUN_20154580(piVar7,uVar6);
  return pcVar4;
}


// ===== FUN_201520b0 @ 201520b0 (248 bytes)

uint FUN_201520b0(int param_1,undefined1 *param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  uint uVar3;
  uint uVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  
  uVar3 = (uint)*(ushort *)(param_1 + 10);
  iVar7 = *(int *)(param_1 + 4);
  if (*(short *)(param_1 + 0x10) == 1) {
    *param_2 = *(undefined1 *)(iVar7 + uVar3);
    *(short *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + 1;
    uVar3 = uVar3 + 1;
    if (uVar3 == *(ushort *)(param_1 + 0xc)) {
      uVar3 = 0;
    }
    *(short *)(param_1 + 10) = (short)uVar3;
    return 1;
  }
  uVar4 = uVar3 + 1;
  uVar9 = (uint)*(ushort *)(param_1 + 0xc);
  if (uVar9 == uVar4) {
    uVar4 = 0;
  }
  uVar5 = uVar4 + 1;
  if (uVar9 == uVar5) {
    uVar5 = 0;
  }
  uVar1 = CONCAT11(*(undefined1 *)(iVar7 + uVar4),*(undefined1 *)(iVar7 + uVar3));
  uVar8 = (uint)uVar1;
  uVar3 = (uint)CONCAT11(*(undefined1 *)(iVar7 + uVar4),*(undefined1 *)(iVar7 + uVar3));
  *(ushort *)(param_1 + 0xe) = *(short *)(param_1 + 0xe) + uVar1 + 2;
  if (uVar9 <= uVar3 + uVar5) {
    iVar6 = uVar9 - uVar5;
    uVar8 = uVar3 - iVar6 & 0xffff;
    puVar2 = (undefined1 *)(iVar7 + uVar5);
    for (; iVar6 != 0; iVar6 = iVar6 + -1) {
      *param_2 = *puVar2;
      puVar2 = puVar2 + 1;
      param_2 = param_2 + 1;
    }
    uVar5 = 0;
  }
  *(short *)(param_1 + 10) = (short)uVar5 + (short)uVar8;
  puVar2 = (undefined1 *)(*(int *)(param_1 + 4) + uVar5);
  for (; uVar8 != 0; uVar8 = uVar8 - 1) {
    *param_2 = *puVar2;
    puVar2 = puVar2 + 1;
    param_2 = param_2 + 1;
  }
  return uVar3;
}


// ===== itron_trcv_mbf @ 201521a8 (600 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): (mbfid, msg, tmout): mbf
   table 0x208DBEC4, copies a message out of the ring (0x201520B0), returns its size [inference] */

int itron_trcv_mbf(uint param_1,undefined4 param_2,int param_3,undefined4 param_4)

{
  undefined1 uVar1;
  byte *pbVar2;
  int iVar3;
  int *piVar4;
  uint uVar5;
  int iVar6;
  
  if ((param_1 == 0) || (8 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return -0x12;
  }
  software_interrupt(0);
  iVar3 = *(int *)(&DAT_208dbec4 + param_1 * 4);
  if (iVar3 == 0) {
    software_interrupt(0);
    return -0x2a;
  }
  if (*(short *)(iVar3 + 0xc) != *(short *)(iVar3 + 0xe)) {
    iVar3 = FUN_201520b0(iVar3,param_2,param_3,param_4,param_1,param_2,param_3);
    iVar6 = FUN_20153dec(param_1);
    if (iVar6 == 0) {
      software_interrupt(0);
    }
    else {
      software_interrupt(0);
    }
    return iVar3;
  }
  pbVar2 = (byte *)(iVar3 + 0x13);
  do {
    uVar5 = (uint)*pbVar2;
    pbVar2 = pbVar2 + 1;
  } while (uVar5 == 0);
  if (uVar5 < 0xfe) {
    piVar4 = *(int **)(&DAT_208dbba0 + uVar5 * 4);
    iVar3 = *(int *)(*piVar4 + 8);
    if (iVar3 != 0) {
      knl_memcpy(param_2,*(undefined4 *)(*piVar4 + 0xc),iVar3);
    }
    if ((*(byte *)((int)piVar4 + 5) & 2) != 0) {
      knl_timeout_remove(piVar4,uVar5);
    }
    *(undefined1 *)((int)piVar4 + 5) = 0x10;
    if (*(char *)((int)piVar4 + 9) == '\0') {
      iVar6 = piVar4[1];
      FUN_20153a38(&DAT_208dc18c + (char)iVar6,piVar4,uVar5);
      if ((int)(char)iVar6 < (int)DAT_208003df) {
        software_interrupt(0);
        return iVar3;
      }
    }
    else {
      FUN_201539ec(piVar4,uVar5);
    }
    software_interrupt(0);
    return iVar3;
  }
  if (param_3 == 0) {
    software_interrupt(0);
    return -0x32;
  }
  if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
     (uVar5 = (uint)DAT_208dc18c, uVar5 != ((byte)DAT_201659d0 + 1 & 0xff))) {
    iVar6 = *(int *)(&DAT_208dbba0 + uVar5 * 4);
    if (param_3 == -1) {
      uVar1 = 0xb0;
    }
    else {
      knl_timeout_add(param_3,iVar6,uVar5);
      uVar1 = 0xb2;
    }
    *(undefined1 *)(iVar6 + 5) = uVar1;
    iVar3 = (uint)*(byte *)(iVar3 + 0x12) + iVar3;
    if (*(byte *)(iVar3 + 1) < 0xfe) {
      iVar3 = iVar3 + DAT_208003df + -1;
    }
    DAT_208003e8 = param_2;
    DAT_208003ec = param_1;
    iVar3 = FUN_201545dc(iVar3,iVar6,uVar5);
    return iVar3;
  }
  software_interrupt(0);
  DAT_208003d4 = 0xffffffe7;
  return -0x19;
}


// ===== itron_trcv_mbx @ 20152434 (400 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.900): (mbxid, ppk_msg, tmout):
   mbx table 0x208DBEA4, takes the first queued message, E_TMOUT [inference] */

code * itron_trcv_mbx(uint param_1,int *param_2,int param_3)

{
  undefined1 uVar1;
  int *piVar2;
  int iVar3;
  code *pcVar4;
  int *piVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  
  if ((param_1 == 0) || (8 < param_1)) {
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    software_interrupt(0);
    piVar7 = *(int **)(&DAT_208dbea4 + param_1 * 4);
    if (piVar7 == (int *)0x0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    iVar6 = 0;
    if (*(byte *)((int)piVar7 + 6) == 0) {
      piVar2 = *(int **)(*piVar7 + 8);
    }
    else {
      piVar2 = (int *)((uint)*(byte *)((int)piVar7 + 6) + (int)piVar7);
    }
    if (*(byte *)(piVar7 + 1) != 0) {
      do {
        piVar5 = (int *)*piVar2;
        if (piVar5 != (int *)0x0) {
          *piVar2 = *piVar5;
          *param_2 = (int)piVar5;
          software_interrupt(0);
          return FUN_201567f4;
        }
        iVar6 = iVar6 + 1;
        piVar2 = piVar2 + 2;
      } while (iVar6 < (int)(uint)*(byte *)(piVar7 + 1));
    }
    if (param_3 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
       (uVar8 = (uint)DAT_208dc18c, uVar8 != ((byte)DAT_201659d0 + 1 & 0xff))) {
      iVar6 = *(int *)(&DAT_208dbba0 + uVar8 * 4);
      if (param_3 == -1) {
        uVar1 = 0xa0;
      }
      else {
        knl_timeout_add(param_3,iVar6,uVar8);
        uVar1 = 0xa2;
      }
      *(undefined1 *)(iVar6 + 5) = uVar1;
      iVar3 = (int)piVar7 + 7;
      if (*(byte *)(piVar7 + 2) < 0xfe) {
        iVar3 = iVar3 + DAT_208003df + -1;
      }
      DAT_208003e8 = param_2;
      DAT_208003ec = param_1;
      pcVar4 = (code *)FUN_201545dc(iVar3,iVar6,uVar8);
      return pcVar4;
    }
    software_interrupt(0);
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_tslp_tsk @ 201525f8 (216 bytes)

/* (tmout): E_CTX in a non-task context; consumes a wake-up count or waits (TMO_FEVR -1 at 40 call
   sites, 10 ms at 12) [fact]; the wake-up wait of the periodic tasks (gui.md) [fact]; T23d NORTi
   uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.950): (tmout): wakeup count TCB+8 -- or
   waits (state 0x20/0x22), E_TMOUT when polling, E_CTX [inference] */

code * itron_tslp_tsk(int param_1)

{
  undefined1 uVar1;
  code *pcVar2;
  int iVar3;
  uint uVar4;
  
  if (((DAT_208003da != '\0') || (DAT_208003db != '\0')) ||
     (uVar4 = (uint)DAT_208dc18c, uVar4 == ((byte)DAT_201659d0 + 1 & 0xff))) {
    DAT_208003d4 = 0xffffffe7;
    return (code *)0xffffffe7;
  }
  iVar3 = *(int *)(&DAT_208dbba0 + uVar4 * 4);
  software_interrupt(0);
  if (*(char *)(iVar3 + 8) != '\0') {
    *(char *)(iVar3 + 8) = *(char *)(iVar3 + 8) + -1;
    software_interrupt(0);
    return FUN_201567f4;
  }
  if (param_1 == 0) {
    software_interrupt(0);
    return (code *)0xffffffce;
  }
  if (param_1 == -1) {
    uVar1 = 0x20;
  }
  else {
    knl_timeout_add(param_1,iVar3,uVar4);
    uVar1 = 0x22;
  }
  *(undefined1 *)(iVar3 + 5) = uVar1;
  pcVar2 = (code *)FUN_201545c8(iVar3,uVar4);
  return pcVar2;
}


// ===== itron_tsnd_mbf @ 201526f4 (604 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): (mbfid, msg, msgsz,
   tmout): mbf table 0x208DBEC4, E_PAR when msgsz > maxmsz, copies to a receiver or the ring
   [inference] */

code * itron_tsnd_mbf(uint param_1,undefined4 param_2,uint param_3,int param_4)

{
  undefined1 uVar1;
  code *pcVar2;
  byte *pbVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  
  if ((param_1 == 0) || (8 < param_1)) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar6 = *(int *)(&DAT_208dbec4 + param_1 * 4);
  if (iVar6 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  if (*(ushort *)(iVar6 + 0x10) < param_3) {
    software_interrupt(0);
    return (code *)0xffffffef;
  }
  pbVar3 = (byte *)((uint)*(byte *)(iVar6 + 0x12) + iVar6);
  do {
    uVar8 = (uint)*pbVar3;
    pbVar3 = pbVar3 + 1;
  } while (uVar8 == 0);
  if (uVar8 < 0xfe) {
    piVar7 = *(int **)(&DAT_208dbba0 + uVar8 * 4);
    if (param_3 != 0) {
      knl_memcpy(*(undefined4 *)(*piVar7 + 0xc),param_2,param_3);
    }
    *(uint *)*piVar7 = param_3;
    if ((*(byte *)((int)piVar7 + 5) & 2) != 0) {
      knl_timeout_remove(piVar7,uVar8);
    }
    *(undefined1 *)((int)piVar7 + 5) = 0x10;
    if (*(char *)((int)piVar7 + 9) == '\0') {
      pcVar2 = (code *)FUN_20154580(piVar7,uVar8);
      return pcVar2;
    }
    pcVar2 = (code *)FUN_20154524();
    return pcVar2;
  }
  if (param_3 != 0) {
    for (pbVar3 = (byte *)(iVar6 + 0x13); *pbVar3 == 0; pbVar3 = pbVar3 + 1) {
    }
    if ((0xfd < *pbVar3) &&
       (iVar4 = FUN_20153cd4(iVar6,param_2,param_3,param_4,param_1,param_2,param_3,param_4),
       iVar4 != 0)) {
      software_interrupt(0);
      return FUN_201567f4;
    }
  }
  if (param_4 == 0) {
    software_interrupt(0);
    return (code *)0xffffffce;
  }
  if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
     (uVar8 = (uint)DAT_208dc18c, uVar8 != ((byte)DAT_201659d0 + 1 & 0xff))) {
    iVar4 = *(int *)(&DAT_208dbba0 + uVar8 * 4);
    if (param_4 == -1) {
      uVar1 = 0x60;
    }
    else {
      knl_timeout_add(param_4,iVar4,uVar8);
      uVar1 = 0x62;
    }
    *(undefined1 *)(iVar4 + 5) = uVar1;
    iVar5 = iVar6 + 0x13;
    if (*(byte *)(iVar6 + 0x14) < 0xfe) {
      iVar5 = iVar5 + DAT_208003df + -1;
    }
    DAT_208003e4 = param_3;
    DAT_208003e8 = param_2;
    DAT_208003ec = param_1;
    pcVar2 = (code *)FUN_201545dc(iVar5,iVar4,uVar8);
    return pcVar2;
  }
  software_interrupt(0);
  DAT_208003d4 = 0xffffffe7;
  return (code *)0xffffffe7;
}


// ===== itron_twai_flg @ 20152988 (496 bytes)

void * itron_twai_flg(uint param_1,uint param_2,uint param_3,uint *param_4,int param_5)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  void *pvVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    DAT_208003d4 = (void *)0xffffffee;
  }
  else {
    if (((param_2 != 0) && ((param_3 & 0xfffffffa) == 0)) && (-3 < param_5)) {
      software_interrupt(0);
      iVar5 = *(int *)(&DAT_208dbda4 + param_1 * 4);
      if (iVar5 == 0) {
        software_interrupt(0);
        return (void *)0xffffffd6;
      }
      if (((*(byte *)(iVar5 + 8) & 2) == 0) && (*(char *)(iVar5 + 9) != '\0')) {
        software_interrupt(0);
        return (void *)0xffffffe4;
      }
      uVar2 = *(uint *)(iVar5 + 4);
      if ((param_3 & 1) == 0) {
        if ((param_2 & ~uVar2) != 0) goto LAB_20152a7c;
      }
      else if ((uVar2 & param_2) == 0) {
LAB_20152a7c:
        if (param_5 == 0) {
          software_interrupt(0);
          return (void *)0xffffffce;
        }
        if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
           (uVar2 = (uint)DAT_208dc18c, uVar2 != ((byte)DAT_201659d0 + 1 & 0xff))) {
          iVar6 = *(int *)(&DAT_208dbba0 + uVar2 * 4);
          if (param_5 == -1) {
            bVar1 = *(byte *)(iVar5 + 8) & 4 | (byte)param_3 | 0x50;
          }
          else {
            knl_timeout_add(param_5,iVar6,uVar2);
            bVar1 = *(byte *)(iVar5 + 8) & 4 | (byte)param_3 | 0x52;
          }
          *(byte *)(iVar6 + 5) = bVar1;
          iVar3 = iVar5 + 9;
          if (*(byte *)(iVar5 + 10) < 0xfe) {
            iVar3 = iVar3 + DAT_208003df + -1;
          }
          DAT_208003e4 = param_2;
          DAT_208003e8 = param_4;
          DAT_208003ec = param_1;
          pvVar4 = (void *)FUN_201545dc(iVar3,iVar6,uVar2);
          return pvVar4;
        }
        software_interrupt(0);
        DAT_208003d4 = (void *)0xffffffe7;
        return &DAT_ffffffe7;
      }
      bVar7 = (param_3 & 4) == 0;
      *param_4 = uVar2;
      if (bVar7) {
        uVar2 = (uint)*(byte *)(iVar5 + 8);
      }
      if (!bVar7 || (uVar2 & 4) != 0) {
        *(undefined4 *)(iVar5 + 4) = 0;
      }
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (void *)0xffffffef;
  }
  return DAT_208003d4;
}


// ===== itron_twai_sem @ 20152bb0 (328 bytes)

/* (semid, tmout): semaphore table 0x208DBCA4, E_CTX, waits with time-out (300, 1000 or TMO_FEVR)
   [fact]; paired with itron_sig_sem around the FS and link code [fact]; T23d NORTi uITRON 4.0 NORTi
   Version 4 (MiSPO) (uitron_api_shape 0.950): (semid, tmout): sem table 0x208DBCA4, count-- or
   waits (state 0x90/0x92), E_TMOUT [inference] */

code * itron_twai_sem(uint param_1,int param_2)

{
  undefined1 uVar1;
  int iVar2;
  code *pcVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  
  if ((param_1 == 0) || (0x40 < param_1)) {
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    software_interrupt(0);
    iVar4 = (&DAT_208dbca4)[param_1];
    if (iVar4 == 0) {
      software_interrupt(0);
      return (code *)0xffffffd6;
    }
    if (*(short *)(iVar4 + 4) != 0) {
      *(short *)(iVar4 + 4) = *(short *)(iVar4 + 4) + -1;
      software_interrupt(0);
      return FUN_201567f4;
    }
    if (param_2 == 0) {
      software_interrupt(0);
      return (code *)0xffffffce;
    }
    if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
       (uVar6 = (uint)DAT_208dc18c, uVar6 != ((byte)DAT_201659d0 + 1 & 0xff))) {
      iVar5 = *(int *)(&DAT_208dbba0 + uVar6 * 4);
      if (param_2 == -1) {
        uVar1 = 0x90;
      }
      else {
        knl_timeout_add(param_2,iVar5,uVar6);
        uVar1 = 0x92;
      }
      *(undefined1 *)(iVar5 + 5) = uVar1;
      iVar2 = iVar4 + 8;
      if (*(byte *)(iVar4 + 9) < 0xfe) {
        iVar2 = iVar2 + DAT_208003df + -1;
      }
      DAT_208003ec = param_1;
      pcVar3 = (code *)FUN_201545dc(iVar2,iVar5,uVar6);
      return pcVar3;
    }
    software_interrupt(0);
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_unl_cpu @ 20152d28 (164 bytes)

/* T23d NORTi uITRON 4.0 NORTi Version 4 (MiSPO) (uitron_api_shape 0.850): clears the CPU-locked
   state of 0x208003DB and dispatches when pending [inference] */

code * itron_unl_cpu(void)

{
  software_interrupt(0);
  DAT_208003cc = DAT_208003cc & 0xffffff3f;
  if ((DAT_208003db & 8) == 0) {
    DAT_208003db = 0;
    if (((DAT_208003da == '\0') && (DAT_208dc18c != (char)((char)DAT_201659d0 + '\x01'))) &&
       ((DAT_208003d9 != '\0' || (DAT_208003dc != '\0')))) {
      software_interrupt(0);
      return FUN_20156748;
    }
  }
  else {
    DAT_208003db = 9;
  }
  software_interrupt(0);
  return FUN_201567f4;
}


// ===== itron_unl_mtx @ 20152df4 (392 bytes)

/* (mtxid 1..0x20): table 0x208DBFC4, E_ILUSE when not the owner [fact]; T23d NORTi uITRON 4.0 NORTi
   Version 4 (MiSPO) (uitron_api_shape 0.900): (mtxid): mtx table 0x208DBFC4, E_ILUSE when not the
   owner, restores the priority, passes it to a waiter [inference] */

code * itron_unl_mtx(uint param_1)

{
  short sVar1;
  char cVar2;
  bool bVar3;
  short *psVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  
  if ((param_1 == 0) || (0x20 < param_1)) {
    DAT_208003d4 = (code *)0xffffffee;
  }
  else {
    if (((DAT_208003da == '\0') && (DAT_208003db == '\0')) &&
       (DAT_208dc18c != (byte)((char)DAT_201659d0 + 1U))) {
      software_interrupt(0);
      iVar8 = *(int *)(&DAT_208dbfc4 + param_1 * 4);
      if (iVar8 == 0) {
        software_interrupt(0);
        return (code *)0xffffffd6;
      }
      if ((uint)*(byte *)(iVar8 + 10) != (uint)DAT_208dc18c) {
        software_interrupt(0);
        return (code *)0xffffffe4;
      }
      cVar2 = *(char *)(iVar8 + 0xb);
      iVar9 = *(int *)(&DAT_208dbba0 + (uint)DAT_208dc18c * 4);
      psVar4 = (short *)(iVar9 + 0x24);
      iVar7 = (int)*(char *)(iVar9 + 0x27);
      sVar1 = *(short *)(iVar9 + 0x24);
      while (sVar1 != 0) {
        if ((int)*psVar4 == param_1) {
          *psVar4 = *(short *)(iVar8 + 8);
          if (cVar2 == '\0') break;
        }
        else {
          iVar6 = (int)*(char *)(*(int *)(&DAT_208dbfc4 + *psVar4 * 4) + 0xb);
          iVar5 = iVar6;
          if (iVar6 != 0) {
            iVar5 = iVar6 - iVar7;
          }
          if (iVar5 < 0 != (iVar6 != 0 && SBORROW4(iVar6,iVar7))) {
            iVar7 = iVar6;
          }
          psVar4 = (short *)(*(int *)(&DAT_208dbfc4 + *psVar4 * 4) + 8);
        }
        sVar1 = *psVar4;
      }
      if (*(char *)(iVar9 + 4) == iVar7) {
        bVar3 = false;
      }
      else {
        FUN_20153a38(&DAT_208dc18c + iVar7,iVar9);
        iVar5 = (int)DAT_208003df;
        *(char *)(iVar9 + 4) = (char)iVar7;
        if (iVar5 < iVar7) {
          bVar3 = true;
        }
        else {
          bVar3 = false;
        }
      }
      iVar8 = FUN_201547d0(iVar8,param_1);
      if (iVar8 != 0 || bVar3) {
        software_interrupt(0);
        return FUN_201566f0;
      }
      software_interrupt(0);
      return FUN_201567f4;
    }
    DAT_208003d4 = (code *)0xffffffe7;
  }
  return DAT_208003d4;
}


// ===== itron_iwup_tsk @ 20152fac (284 bytes)

/* [inference from use in an ISR] */

code * itron_iwup_tsk(uint param_1)

{
  char cVar1;
  code *pcVar2;
  int iVar3;
  
  if (param_1 == 0) {
    param_1 = (uint)DAT_208dc18c;
  }
  if (DAT_201659d0 < param_1) {
    DAT_208003d4 = 0xffffffee;
    return (code *)0xffffffee;
  }
  software_interrupt(0);
  iVar3 = *(int *)(&DAT_208dbba0 + param_1 * 4);
  if (iVar3 == 0) {
    software_interrupt(0);
    return (code *)0xffffffd6;
  }
  cVar1 = *(char *)(iVar3 + 5);
  if (cVar1 == '\"') {
    *(undefined1 *)(iVar3 + 5) = 0x10;
    knl_timeout_remove(iVar3,param_1);
    if (*(char *)(iVar3 + 9) != '\0') {
      software_interrupt(0);
      return FUN_201567f4;
    }
  }
  else {
    if (cVar1 != ' ') {
      if (cVar1 == '\0') {
        software_interrupt(0);
        return (code *)0xffffffd7;
      }
      cVar1 = *(char *)(iVar3 + 8) + '\x01';
      *(char *)(iVar3 + 8) = cVar1;
      if (cVar1 == '\0') {
        *(undefined1 *)(iVar3 + 8) = 0xff;
        software_interrupt(0);
        return (code *)0xffffffd5;
      }
      software_interrupt(0);
      return FUN_201567f4;
    }
    *(undefined1 *)(iVar3 + 5) = 0x10;
    if (*(char *)(iVar3 + 9) != '\0') {
      software_interrupt(0);
      return FUN_201567f4;
    }
  }
  pcVar2 = (code *)FUN_20154538(iVar3,param_1);
  return pcVar2;
}

