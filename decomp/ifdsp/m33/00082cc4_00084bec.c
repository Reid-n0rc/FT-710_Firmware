// FT-710_IFDSP_V0101.bin — Ghidra decompile, 50 functions

// ===== FUN_00082cc4 @ 00082cc4 (70 bytes)

void FUN_00082cc4(int param_1,int param_2,undefined4 param_3,undefined4 param_4,undefined4 param_5)

{
  int iVar1;
  int local_20;
  int iStack_1c;
  int local_18;
  undefined4 uStack_14;
  
  uStack_14 = param_4;
  if (param_1 == 0) {
    local_20 = param_1;
    iStack_1c = param_2;
    local_18 = param_3;
    vPortRaiseBASEPRI();
    do {
                    /* WARNING: Do nothing block with infinite loop */
    } while( true );
  }
  if (DAT_00088920 != 0) {
    local_20 = param_2;
    iStack_1c = param_3;
    local_18 = param_1;
    if (param_2 < 6) {
      iVar1 = FUN_00082910();
      if (iVar1 != 2) {
        param_5 = 0;
      }
      xQueueGenericSend(DAT_00088920,&local_20,param_5);
    }
    else {
      xQueueGenericSendFromISR(DAT_00088920,&local_20,param_4,0);
    }
  }
  return;
}


// ===== FUN_00082d10 @ 00082d10 (146 bytes)

uint FUN_00082d10(undefined4 *param_1,undefined4 param_2,undefined4 param_3)

{
  int *piVar1;
  uint uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  
  uVar2 = FUN_00082494();
  if (uVar2 < DAT_0008891c) {
    while (piVar1 = DAT_000888f0, *DAT_000888ec != 0) {
      uVar6 = ((uint *)DAT_000888ec[3])[3];
      uVar7 = *(uint *)DAT_000888ec[3];
      FUN_00086778(uVar6 + 4);
      (**(code **)(uVar6 + 0x20))(uVar6);
      piVar1 = DAT_000888ec;
      if ((*(byte *)(uVar6 + 0x28) & 4) != 0) {
        uVar5 = *(int *)(uVar6 + 0x18) + uVar7;
        if (uVar7 < uVar5) {
          *(uint *)(uVar6 + 4) = uVar5;
          *(uint *)(uVar6 + 0x10) = uVar6;
          FUN_0008674a(piVar1,uVar6 + 4);
        }
        else {
          iVar3 = FUN_00082cc4(uVar6,0,uVar7,0,0,param_2,param_3);
          if (iVar3 == 0) {
            vPortRaiseBASEPRI();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
        }
      }
    }
    DAT_000888f0 = DAT_000888ec;
    uVar4 = 1;
    DAT_000888ec = piVar1;
  }
  else {
    uVar4 = 0;
  }
  *param_1 = uVar4;
  DAT_0008891c = uVar2;
  return uVar2;
}


// ===== prvTimerTask @ 00082db0 (384 bytes)

void prvTimerTask(void)

{
  uint uVar1;
  int iVar2;
  byte bVar3;
  bool bVar4;
  int iVar5;
  uint uVar6;
  undefined1 auStack_34 [4];
  int local_30;
  code *local_2c;
  int local_28;
  undefined4 local_24;
  
LAB_00082dba:
  iVar5 = *DAT_000888ec;
  if (iVar5 == 0) {
    uVar6 = 0;
  }
  else {
    uVar6 = *(uint *)DAT_000888ec[3];
  }
  vTaskSuspendAll();
  uVar1 = FUN_00082d10(&local_30);
  if (local_30 == 0) {
    if (iVar5 == 0) {
      bVar4 = *DAT_000888f0 == 0;
    }
    else {
      bVar4 = false;
      if (uVar6 <= uVar1) {
        xTaskResumeAll();
        iVar5 = *(int *)(DAT_000888ec[3] + 0xc);
        FUN_00086778(iVar5 + 4);
        if ((int)((uint)*(byte *)(iVar5 + 0x28) << 0x1d) < 0) {
          iVar2 = FUN_00082c44(iVar5,*(int *)(iVar5 + 0x18) + uVar6,uVar1,uVar6);
          if ((iVar2 != 0) && (iVar2 = FUN_00082cc4(iVar5,0,uVar6,0,0), iVar2 == 0)) {
            vPortRaiseBASEPRI();
            do {
                    /* WARNING: Do nothing block with infinite loop */
            } while( true );
          }
        }
        else {
          *(byte *)(iVar5 + 0x28) = *(byte *)(iVar5 + 0x28) & 0xfe;
        }
        (**(code **)(iVar5 + 0x20))(iVar5);
        goto switchD_00082e62_default;
      }
    }
    FUN_00086dd6(DAT_00088920,uVar6 - uVar1,bVar4);
    iVar5 = xTaskResumeAll();
    if (iVar5 == 0) {
      FUN_00086542();
    }
  }
  else {
    xTaskResumeAll();
  }
switchD_00082e62_default:
  do {
    iVar5 = xQueueReceive(DAT_00088920,&local_30,0);
    if (iVar5 == 0) goto LAB_00082dba;
    if ((-1 < local_30) || ((*local_2c)(local_28,local_24), -1 < local_30)) {
      iVar5 = local_28;
      if (*(int *)(local_28 + 0x14) != 0) {
        FUN_00086778(local_28 + 4);
      }
      iVar2 = FUN_00082d10(auStack_34);
      switch(local_30) {
      case 0:
      case 1:
      case 2:
      case 6:
      case 7:
        *(byte *)(iVar5 + 0x28) = *(byte *)(iVar5 + 0x28) | 1;
        iVar2 = FUN_00082c44(iVar5,local_2c + *(int *)(iVar5 + 0x18),iVar2);
        if (((iVar2 != 0) &&
            ((**(code **)(iVar5 + 0x20))(iVar5), (int)((uint)*(byte *)(iVar5 + 0x28) << 0x1d) < 0))
           && (iVar5 = FUN_00082cc4(iVar5,0,local_2c + *(int *)(iVar5 + 0x18),0,0), iVar5 == 0)) {
          vPortRaiseBASEPRI();
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        goto switchD_00082e62_default;
      case 3:
      case 8:
        bVar3 = *(byte *)(iVar5 + 0x28);
        break;
      case 4:
      case 9:
        *(byte *)(iVar5 + 0x28) = *(byte *)(iVar5 + 0x28) | 1;
        *(code **)(iVar5 + 0x18) = local_2c;
        if (local_2c == (code *)0x0) {
          vPortRaiseBASEPRI();
          do {
                    /* WARNING: Do nothing block with infinite loop */
          } while( true );
        }
        FUN_00082c44(iVar5,local_2c + iVar2,iVar2,iVar2);
        goto switchD_00082e62_default;
      case 5:
        bVar3 = *(byte *)(iVar5 + 0x28);
        if (-1 < (int)((uint)bVar3 << 0x1e)) {
          vPortFree(iVar5);
          goto switchD_00082e62_default;
        }
        break;
      default:
        goto switchD_00082e62_default;
      }
      *(byte *)(iVar5 + 0x28) = bVar3 & 0xfe;
    }
  } while( true );
}


// ===== FUN_00082f70 @ 00082f70 (18 bytes)

undefined4 FUN_00082f70(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_400011c0;
  uVar2 = 0;
  if ((uVar1 & 1) != 0) {
    uVar2 = 0x8000;
  }
  return uVar2;
}


// ===== FUN_00082f88 @ 00082f88 (30 bytes)

undefined4 FUN_00082f88(void)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = DAT_40001168;
  if (iVar1 == 0) {
    puVar2 = &DAT_00088930;
  }
  else {
    iVar1 = DAT_40001168;
    if (iVar1 != 1) {
      return 0;
    }
    puVar2 = &DAT_00088928;
  }
  return *puVar2;
}


// ===== FUN_00082fb4 @ 00082fb4 (28 bytes)

undefined4 FUN_00082fb4(void)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = DAT_40001100;
  if ((uVar1 & 0xc0000) != 0) {
    uVar2 = 60000000;
    if ((uVar1 & 0xc0000) != 0xc0000) {
      uVar2 = 0;
    }
    return uVar2;
  }
  return 48000000;
}


// ===== FUN_00082fdc @ 00082fdc (82 bytes)

uint FUN_00082fdc(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = DAT_40001200;
  uVar5 = uVar5 & 7;
  if (uVar5 == 1) {
    uVar3 = FUN_00082f88();
  }
  else if (uVar5 == 2) {
    uVar3 = FUN_00082fb4();
    uVar3 = uVar3 >> 1;
  }
  else {
    uVar3 = 16000000;
    if (uVar5 != 0) {
      uVar3 = 0;
    }
  }
  uVar5 = DAT_40001204;
  if ((uVar5 & 1) == 0) {
    uVar1 = DAT_40001210;
    uVar2 = DAT_40001214;
    uVar5 = DAT_40001204;
    iVar4 = FUN_00087756((int)((ulonglong)uVar3 * (ulonglong)uVar1),
                         (int)((ulonglong)uVar3 * (ulonglong)uVar1 >> 0x20),uVar2);
    uVar3 = iVar4 + uVar3 * ((uVar5 & 0xffffff) >> 0x10);
  }
  return uVar3;
}


// ===== FUN_00083038 @ 00083038 (88 bytes)

uint FUN_00083038(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = FUN_00082fdc();
  iVar1 = DAT_40001204;
  if (-1 < iVar1 << 0x1f) {
    switch(param_1) {
    case 0:
      uVar3 = DAT_40001218;
      uVar3 = uVar3 & 0x3f;
      break;
    case 1:
      uVar3 = DAT_40001218;
      uVar3 = (uVar3 & 0x3fff) >> 8;
      break;
    case 2:
      uVar3 = DAT_40001218;
      uVar3 = (uVar3 & 0x3fffff) >> 0x10;
      break;
    case 3:
      uVar3 = DAT_40001218;
      uVar3 = (uVar3 & 0x3fffffff) >> 0x18;
      break;
    default:
      return 0;
    }
    uVar2 = FUN_00087756((int)((ulonglong)uVar2 * 0x12),(int)((ulonglong)uVar2 * 0x12 >> 0x20),uVar3
                         ,0);
  }
  return uVar2;
}


// ===== FUN_00083098 @ 00083098 (24 bytes)

uint FUN_00083098(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = FUN_00083038(0);
  uVar1 = DAT_40001240;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== FUN_000830b4 @ 000830b4 (24 bytes)

uint FUN_000830b4(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = FUN_00083038(2);
  uVar1 = DAT_40001248;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== FUN_000830d0 @ 000830d0 (24 bytes)

uint FUN_000830d0(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = FUN_00083038(3);
  uVar1 = DAT_4000124c;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== FUN_000830ec @ 000830ec (82 bytes)

uint FUN_000830ec(void)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  
  uVar5 = DAT_40021200;
  uVar5 = uVar5 & 7;
  if (uVar5 == 1) {
    uVar3 = FUN_00082f88();
  }
  else if (uVar5 == 2) {
    uVar3 = FUN_00082fb4();
    uVar3 = uVar3 >> 1;
  }
  else {
    uVar3 = 16000000;
    if (uVar5 != 0) {
      uVar3 = 0;
    }
  }
  uVar5 = DAT_40021204;
  if ((uVar5 & 1) == 0) {
    uVar1 = DAT_40021210;
    uVar2 = DAT_40021214;
    uVar5 = DAT_40021204;
    iVar4 = FUN_00087756((int)((ulonglong)uVar3 * (ulonglong)uVar1),
                         (int)((ulonglong)uVar3 * (ulonglong)uVar1 >> 0x20),uVar2);
    uVar3 = iVar4 + uVar3 * ((uVar5 & 0xffffff) >> 0x10);
  }
  return uVar3;
}


// ===== FUN_00083148 @ 00083148 (88 bytes)

uint FUN_00083148(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = FUN_000830ec();
  iVar1 = DAT_40021204;
  if (-1 < iVar1 << 0x1f) {
    switch(param_1) {
    case 0:
      uVar3 = DAT_40021218;
      uVar3 = uVar3 & 0x3f;
      break;
    case 1:
      uVar3 = DAT_40021218;
      uVar3 = (uVar3 & 0x3fff) >> 8;
      break;
    case 2:
      uVar3 = DAT_40021218;
      uVar3 = (uVar3 & 0x3fffff) >> 0x10;
      break;
    case 3:
      uVar3 = DAT_40021218;
      uVar3 = (uVar3 & 0x3fffffff) >> 0x18;
      break;
    default:
      return 0;
    }
    uVar2 = FUN_00087756((int)((ulonglong)uVar2 * 0x12),(int)((ulonglong)uVar2 * 0x12 >> 0x20),uVar3
                         ,0);
  }
  return uVar2;
}


// ===== FUN_000831a8 @ 000831a8 (24 bytes)

uint FUN_000831a8(void)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = FUN_00083148(0);
  uVar1 = DAT_40021240;
  return uVar2 / ((uVar1 & 0xff) + 1);
}


// ===== FUN_000831c4 @ 000831c4 (92 bytes)

undefined * FUN_000831c4(void)

{
  undefined *puVar1;
  uint uVar2;
  
  uVar2 = DAT_40001434;
  uVar2 = uVar2 & 3;
  if (uVar2 == 2) {
    puVar1 = (undefined *)FUN_00083098();
    return puVar1;
  }
  if (uVar2 == 3) {
    puVar1 = (undefined *)FUN_00082f70();
    return puVar1;
  }
  if (uVar2 == 1) {
    puVar1 = (undefined *)0xf42400;
  }
  else {
    uVar2 = DAT_40001430;
    uVar2 = uVar2 & 3;
    if (uVar2 == 2) {
      puVar1 = &DAT_000f4240;
    }
    else {
      if (uVar2 == 3) {
        puVar1 = (undefined *)FUN_00082fb4();
        return puVar1;
      }
      if (uVar2 == 1) {
        puVar1 = (undefined *)FUN_00082f88();
        return puVar1;
      }
      uVar2 = FUN_00082fb4();
      puVar1 = (undefined *)(uVar2 >> 2);
    }
  }
  return puVar1;
}


// ===== FUN_0008322c @ 0008322c (106 bytes)

undefined * FUN_0008322c(void)

{
  undefined *puVar1;
  uint uVar2;
  uint uVar3;
  
  uVar3 = DAT_40021434;
  uVar3 = uVar3 & 3;
  if (uVar3 == 2) {
    uVar2 = FUN_00083038(1);
    uVar3 = DAT_40001244;
    puVar1 = (undefined *)(uVar2 / ((uVar3 & 0xff) + 1));
  }
  else {
    if (uVar3 == 3) {
      puVar1 = (undefined *)FUN_00082f70();
      return puVar1;
    }
    if (uVar3 == 1) {
      puVar1 = (undefined *)FUN_00083098();
      return puVar1;
    }
    uVar3 = DAT_40021430;
    uVar3 = uVar3 & 3;
    if (uVar3 == 2) {
      puVar1 = &DAT_000f4240;
    }
    else {
      if (uVar3 != 3) {
        if (uVar3 != 1) {
          puVar1 = (undefined *)FUN_00082fb4();
          return puVar1;
        }
        puVar1 = (undefined *)FUN_00082f88();
        return puVar1;
      }
      puVar1 = (undefined *)0xf42400;
    }
  }
  return puVar1;
}


// ===== CLOCK_GetFlexCommClkFreq @ 00083470 (238 bytes)

undefined4 CLOCK_GetFlexCommClkFreq(uint param_1)

{
  longlong lVar1;
  uint uVar2;
  int iVar3;
  uint uVar4;
  undefined4 uVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  
  if (param_1 < 8) {
    uVar5 = *(undefined4 *)(&DAT_40021508 + param_1 * 0x20);
  }
  else if (param_1 == 0xe) {
    uVar5 = DAT_400216c8;
  }
  else {
    if (param_1 != 0xf) {
      return 16000000;
    }
    uVar5 = DAT_400216e8;
  }
  switch(uVar5) {
  case 0:
    return 16000000;
  case 1:
    uVar5 = FUN_00082fb4();
    return uVar5;
  case 2:
    uVar5 = FUN_000831a8();
    return uVar5;
  case 3:
    return DAT_0008892c;
  case 4:
    break;
  default:
    return 0;
  }
  if (param_1 < 8) {
    iVar3 = param_1 * 0x20;
    bVar6 = (byte)*(undefined4 *)(&DAT_40021504 + iVar3);
    uVar4 = *(uint *)(&DAT_40021500 + iVar3) & 7;
    uVar8 = (*(uint *)(&DAT_40021504 + iVar3) & 0xffff) >> 8;
LAB_000833e4:
    uVar7 = (uint)bVar6;
    switch(uVar4) {
    case 0:
      goto switchD_000833ea_caseD_0;
    case 1:
      uVar2 = DAT_400216fc;
      uVar4 = FUN_00083098();
      uVar4 = uVar4 / ((uVar2 & 0xff) + 1);
      break;
    case 2:
      uVar4 = 16000000;
      break;
    case 3:
      uVar4 = FUN_00082fb4();
      break;
    default:
      uVar4 = 0;
    }
  }
  else {
    if (param_1 == 0xe) {
      uVar4 = DAT_400216c0;
      uVar8 = DAT_400216c4;
      uVar4 = uVar4 & 7;
      uVar5 = DAT_400216c4;
      bVar6 = (byte)uVar5;
      uVar8 = (uVar8 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    if (param_1 == 0xf) {
      uVar4 = DAT_400216e0;
      uVar8 = DAT_400216e4;
      uVar4 = uVar4 & 7;
      uVar5 = DAT_400216e4;
      bVar6 = (byte)uVar5;
      uVar8 = (uVar8 & 0xffff) >> 8;
      goto LAB_000833e4;
    }
    uVar8 = 0;
    uVar7 = 0;
switchD_000833ea_caseD_0:
    uVar4 = FUN_000831c4();
  }
  lVar1 = (ulonglong)(uVar7 + 1) * (ulonglong)uVar4;
  uVar5 = FUN_00087756((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),uVar7 + uVar8 + 1,0);
  return uVar5;
}


// ===== CLOCK_GetFreq @ 000837a8 (214 bytes)

/* WARNING: Removing unreachable block (ram,0x000835a6) */

undefined *
CLOCK_GetFreq(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  bool bVar2;
  uint uVar3;
  uint uVar4;
  undefined *puVar5;
  undefined4 uVar6;
  uint *puVar7;
  uint *puVar8;
  
  switch(param_1) {
  case 0:
  case 1:
    uVar4 = FUN_000831c4();
    puVar5 = &DAT_40001000;
    goto LAB_000837d4;
  case 2:
    iVar1 = DAT_40021740;
    if (iVar1 == 0) {
      uVar4 = FUN_00082fb4();
    }
    else {
      iVar1 = DAT_40021740;
      if (iVar1 == 1) {
        uVar4 = FUN_000831a8();
      }
      else {
        uVar4 = 0;
      }
    }
    uVar3 = DAT_40021744;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 3:
    uVar4 = DAT_40021764;
    puVar5 = (undefined *)(uVar4 & 7);
    switch(puVar5) {
    case (undefined *)0x0:
      uVar4 = DAT_40021760;
      switch(uVar4 & 7) {
      case 0:
        puVar5 = (undefined *)0xf42400;
        break;
      case 1:
        puVar5 = (undefined *)FUN_00082f88();
        break;
      case 2:
        puVar5 = &DAT_000f4240;
        break;
      case 3:
        puVar5 = (undefined *)FUN_00082fb4();
        break;
      case 4:
        puVar5 = (undefined *)FUN_000831c4();
        break;
      case 6:
        puVar5 = (undefined *)FUN_0008322c();
      }
      break;
    case (undefined *)0x1:
      puVar5 = (undefined *)FUN_00083098();
      break;
    case (undefined *)0x2:
      puVar5 = (undefined *)FUN_000830b4();
      break;
    case (undefined *)0x3:
      uVar3 = FUN_00083038(1);
      uVar4 = DAT_40001244;
      puVar5 = (undefined *)(uVar3 / ((uVar4 & 0xff) + 1));
      break;
    case (undefined *)0x4:
      puVar5 = (undefined *)FUN_000830d0();
      break;
    case (undefined *)0x5:
      puVar5 = (undefined *)FUN_000831a8();
      break;
    case (undefined *)0x6:
      puVar5 = (undefined *)FUN_00082f70();
      break;
    default:
      puVar5 = (undefined *)0x0;
    }
    uVar4 = DAT_40021768;
    return (undefined *)((uint)puVar5 / ((uVar4 & 0xff) + 1));
  case 4:
    uVar4 = DAT_400016d4;
    puVar5 = (undefined *)(uVar4 & 7);
    switch(puVar5) {
    case (undefined *)0x0:
      uVar4 = DAT_400016d0;
      switch(uVar4 & 7) {
      case 0:
        puVar5 = (undefined *)0xf42400;
        break;
      case 1:
        puVar5 = (undefined *)FUN_00082f88();
        break;
      case 2:
        puVar5 = &DAT_000f4240;
        break;
      case 3:
        puVar5 = (undefined *)FUN_00082fb4();
      }
      break;
    case (undefined *)0x1:
      puVar5 = (undefined *)FUN_00083098();
      break;
    default:
      puVar5 = (undefined *)0x0;
      break;
    case (undefined *)0x3:
      puVar5 = (undefined *)FUN_000830b4();
      break;
    case (undefined *)0x5:
      puVar5 = (undefined *)FUN_000830d0();
    }
    uVar4 = DAT_400016d8;
    return (undefined *)((uint)puVar5 / ((uVar4 & 0xff) + 1));
  case 5:
    uVar4 = DAT_40001620;
    switch(uVar4 & 7) {
    case 0:
      uVar4 = FUN_000831c4();
      break;
    case 1:
      uVar4 = FUN_00083098();
      break;
    case 2:
      uVar4 = FUN_000830b4();
      break;
    case 3:
      uVar4 = FUN_00082fb4();
      break;
    case 4:
      uVar4 = FUN_000830d0();
      break;
    default:
      uVar4 = 0;
    }
    uVar3 = DAT_40001624;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 6:
    uVar4 = DAT_40001640;
    switch(uVar4 & 7) {
    case 0:
      uVar4 = FUN_000831c4();
      break;
    case 1:
      uVar4 = FUN_00083098();
      break;
    case 2:
      uVar4 = FUN_000830b4();
      break;
    case 3:
      uVar4 = FUN_00082fb4();
      break;
    case 4:
      uVar4 = FUN_000830d0();
      break;
    case 5:
      uVar4 = FUN_000831a8();
      break;
    default:
      uVar4 = 0;
    }
    uVar3 = DAT_40001644;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 7:
    uVar4 = DAT_40001720;
    if ((uVar4 & 7) == 0) {
      return &DAT_000f4240;
    }
    puVar5 = (undefined *)FUN_000831c4();
    return puVar5;
  case 8:
    uVar4 = DAT_400217a0;
    if ((uVar4 & 7) != 0) {
      puVar5 = (undefined *)FUN_000831c4();
      return puVar5;
    }
    return &DAT_000f4240;
  case 9:
    uVar6 = DAT_40001760;
    switch(uVar6) {
    case 0:
      uVar3 = FUN_000831c4();
      uVar4 = DAT_40001764;
      puVar5 = (undefined *)(uVar3 / ((uVar4 & 0xff) + 1));
      break;
    case 1:
      puVar5 = &DAT_000f4240;
      break;
    case 2:
      puVar5 = (undefined *)FUN_00082f70();
      return puVar5;
    case 3:
      puVar5 = (undefined *)0xf42400;
      break;
    default:
      puVar5 = (undefined *)0x0;
    }
    return puVar5;
  case 10:
    bVar2 = false;
    goto LAB_00083830;
  case 0xb:
    bVar2 = true;
LAB_00083830:
    puVar8 = (uint *)&DAT_40001684;
    if (bVar2) {
      puVar8 = &DAT_40001694;
    }
    puVar7 = &DAT_40001680;
    if (bVar2) {
      puVar7 = &DAT_40001690;
    }
    switch(*puVar7 & 7) {
    case 0:
      uVar4 = FUN_000831c4();
      break;
    case 1:
      uVar4 = FUN_00083098();
      break;
    case 2:
      uVar4 = FUN_000830b4();
      break;
    case 3:
      uVar4 = FUN_00082fb4();
      break;
    case 4:
      uVar4 = FUN_000830d0();
      break;
    default:
      uVar4 = 0;
    }
    return (undefined *)(uVar4 / ((*puVar8 & 0xff) + 1));
  case 0xc:
    uVar4 = DAT_40021780;
    if ((uVar4 & 7) == 0) {
      uVar4 = FUN_000831c4();
    }
    else if ((uVar4 & 7) == 1) {
      uVar4 = FUN_00082fb4();
    }
    else {
      uVar4 = 0;
    }
    uVar3 = DAT_40021790;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 0xd:
    iVar1 = DAT_40001660;
    if (iVar1 == 0) {
      uVar4 = FUN_00082f88();
    }
    else {
      iVar1 = DAT_40001660;
      if (iVar1 == 1) {
        uVar4 = FUN_000831c4();
      }
      else {
        uVar4 = 0;
      }
    }
    uVar3 = DAT_40001664;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 0xe:
    uVar4 = DAT_40021700;
    switch(uVar4 & 7) {
    case 0:
      puVar5 = (undefined *)0xf42400;
      break;
    case 1:
      puVar5 = (undefined *)FUN_00082fb4();
      break;
    case 2:
      puVar5 = (undefined *)FUN_000831a8();
      break;
    case 3:
      puVar5 = DAT_0008892c;
      break;
    case 4:
      puVar5 = &DAT_000f4240;
      break;
    case 5:
      uVar4 = DAT_40001730;
      if ((uVar4 & 7) == 0) {
        puVar5 = (undefined *)FUN_00082f70();
      }
      else {
        uVar4 = DAT_40001734;
        puVar5 = (undefined *)(1000000 / ((uVar4 & 0xff) + 1));
      }
      break;
    default:
      puVar5 = (undefined *)0x0;
    }
    uVar4 = DAT_40021704;
    return (undefined *)((uint)puVar5 / ((uVar4 & 0xff) + 1));
  case 0xf:
    uVar4 = FUN_0008322c();
    puVar5 = &DAT_40021000;
LAB_000837d4:
    return (undefined *)(uVar4 / ((*(uint *)(puVar5 + 0x400) & 0xff) + 1));
  case 0x10:
    uVar4 = DAT_400217c0;
    switch(uVar4 & 7) {
    case 0:
      uVar4 = FUN_000831c4();
      break;
    case 1:
      uVar4 = 16000000;
      break;
    case 2:
      uVar4 = FUN_00082fb4();
      break;
    case 3:
      uVar4 = FUN_000830b4();
      break;
    case 4:
      uVar4 = FUN_000830d0();
      break;
    default:
      uVar4 = 0;
    }
    uVar3 = DAT_400217c4;
    return (undefined *)(uVar4 / ((uVar3 & 0xff) + 1));
  case 0x11:
    uVar6 = 0;
    break;
  case 0x12:
    uVar6 = 1;
    break;
  case 0x13:
    uVar6 = 2;
    break;
  case 0x14:
    uVar6 = 3;
    break;
  case 0x15:
    uVar6 = 4;
    break;
  case 0x16:
    uVar6 = 5;
    break;
  case 0x17:
    uVar6 = 6;
    break;
  case 0x18:
    uVar6 = 7;
    break;
  case 0x19:
    uVar6 = 0xe;
    break;
  case 0x1a:
    uVar6 = 0xf;
    break;
  default:
    return (undefined *)0x0;
  }
  puVar5 = (undefined *)CLOCK_GetFlexCommClkFreq(uVar6,param_2,param_3,param_4);
  return puVar5;
}


// ===== FUN_000838a8 @ 000838a8 (70 bytes)

void FUN_000838a8(byte *param_1)

{
  uint uVar1;
  
  uVar1 = (uint)*param_1;
  if (uVar1 < 8) {
    *(uint *)(&DAT_40021500 + uVar1 * 0x20) = (uint)param_1[1];
    *(uint *)(&DAT_40021504 + uVar1 * 0x20) = (uint)*(ushort *)(param_1 + 2);
    return;
  }
  if (uVar1 == 0xe) {
    DAT_400216c0 = (uint)param_1[1];
    DAT_400216c4 = (uint)*(ushort *)(param_1 + 2);
    return;
  }
  if (uVar1 == 0xf) {
    DAT_400216e0 = (uint)param_1[1];
    DAT_400216e4 = (uint)*(ushort *)(param_1 + 2);
  }
  return;
}


// ===== FUN_000838f4 @ 000838f4 (170 bytes)

void FUN_000838f4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint local_20;
  uint local_1c;
  uint local_18;
  undefined4 local_14 [2];
  
  local_20 = 0;
  local_1c = 0;
  local_18 = 0;
  local_14[0] = 0;
  uVar3 = DAT_40001104;
  DAT_40001104 = uVar3 | 1;
  uVar1 = FUN_000831c4();
  uVar3 = DAT_40001400;
  (*(code *)0x13009ff9)(uVar1 / ((uVar3 & 0xff) + 1));
  if (param_1 == 0) {
    (*(code *)0x1300a057)(0x30);
    (*(code *)0x1300a057)(0x31,&local_1c);
    uVar2 = 0x32;
  }
  else {
    (*(code *)0x1300a057)(0x33,&local_20);
    (*(code *)0x1300a057)(0x34,&local_1c);
    uVar2 = 0x35;
  }
  (*(code *)0x1300a057)(uVar2,&local_18);
  (*(code *)0x1300a057)(0xc,local_14);
  (*(code *)0x1300a047)();
  if (param_1 == 0) {
    uVar3 = 0;
  }
  else {
    uVar3 = 0xc0000;
  }
  DAT_40001100 = (local_1c & 0x3f) << 5 | (local_18 & 0x7f) << 0xb | local_20 & 0x1f | uVar3;
  uVar3 = DAT_40001104;
  DAT_40001104 = uVar3 & 0xfffffffe;
  FUN_00083cc4(local_14[0],300000000);
  return;
}


// ===== FUN_000839b4 @ 000839b4 (56 bytes)

void FUN_000839b4(undefined4 param_1)

{
  uint uVar1;
  uint uVar2;
  undefined4 extraout_r2;
  undefined4 local_c;
  
  local_c = 0;
  uVar2 = FUN_000831c4();
  uVar1 = DAT_40001400;
  (*(code *)0x13009ff9)(uVar2 / ((uVar1 & 0xff) + 1));
  (*(code *)0x1300a057)(0xd,&local_c,extraout_r2,0x1300a057,param_1);
  (*(code *)0x1300a047)();
  FUN_00083cc4(local_c,300000000);
  return;
}


// ===== FUN_000839fc @ 000839fc (242 bytes)

void FUN_000839fc(byte *param_1)

{
  uint uVar1;
  
  DAT_40002620 = 0x60000;
  DAT_40001200 = (uint)*param_1;
  DAT_40001210 = *(undefined4 *)(param_1 + 4);
  DAT_40001214 = *(undefined4 *)(param_1 + 8);
  switch(param_1[0xc]) {
  case 0:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x100000;
    break;
  case 1:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x110000;
    break;
  case 2:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x120000;
    break;
  case 3:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x130000;
    break;
  case 4:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x140000;
    break;
  case 5:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x150000;
    break;
  case 6:
    uVar1 = DAT_40001204;
    uVar1 = uVar1 & 0xff00ffff | 0x160000;
    break;
  default:
    goto switchD_00083a22_default;
  }
  DAT_40001204 = uVar1;
switchD_00083a22_default:
  uVar1 = DAT_40001204;
  DAT_40001204 = uVar1 & 0xfffffffd;
  DAT_40002630 = 0x60000;
  uVar1 = DAT_4000120c;
  FUN_00083cc4((uVar1 & 0xffff) >> 1,300000000);
  uVar1 = DAT_40001204;
  DAT_40001204 = uVar1 | 0x2000;
  uVar1 = DAT_4000120c;
  FUN_00083cc4((uVar1 & 0xffff) / 6,300000000);
  uVar1 = DAT_40001204;
  DAT_40001204 = uVar1 & 0xffffdfff;
  uVar1 = DAT_4000120c;
  FUN_00083cc4((uVar1 & 0xffff) / 3,300000000);
  return;
}


// ===== FUN_00083b04 @ 00083b04 (66 bytes)

void FUN_00083b04(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << 3;
  uVar2 = DAT_40001218;
  uVar2 = uVar2 & ~(0xbf << (uVar1 & 0xff));
  DAT_40001218 = 0x80 << (uVar1 & 0xff) | uVar2;
  DAT_40001218 = (param_2 & 0x3f) << (uVar1 & 0xff) | uVar2;
  uVar2 = 0x40 << (uVar1 & 0xff);
  do {
    uVar1 = DAT_40001218;
  } while ((uVar1 & uVar2) == 0);
  uVar1 = DAT_40001218;
  DAT_40001218 = uVar2 | uVar1;
  return;
}


// ===== FUN_00083b4c @ 00083b4c (242 bytes)

void FUN_00083b4c(byte *param_1)

{
  uint uVar1;
  
  DAT_40002620 = 0x180000;
  DAT_40021200 = (uint)*param_1;
  DAT_40021210 = *(undefined4 *)(param_1 + 4);
  DAT_40021214 = *(undefined4 *)(param_1 + 8);
  switch(param_1[0xc]) {
  case 0:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x100000;
    break;
  case 1:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x110000;
    break;
  case 2:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x120000;
    break;
  case 3:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x130000;
    break;
  case 4:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x140000;
    break;
  case 5:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x150000;
    break;
  case 6:
    uVar1 = DAT_40021204;
    uVar1 = uVar1 & 0xff00ffff | 0x160000;
    break;
  default:
    goto switchD_00083b72_default;
  }
  DAT_40021204 = uVar1;
switchD_00083b72_default:
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 & 0xfffffffd;
  DAT_40002630 = 0x180000;
  uVar1 = DAT_4002120c;
  FUN_00083cc4((uVar1 & 0xffff) >> 1,300000000);
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 | 0x2000;
  uVar1 = DAT_4002120c;
  FUN_00083cc4((uVar1 & 0xffff) / 6,300000000);
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 & 0xffffdfff;
  uVar1 = DAT_4002120c;
  FUN_00083cc4((uVar1 & 0xffff) / 3,300000000);
  return;
}


// ===== FUN_00083c54 @ 00083c54 (66 bytes)

void FUN_00083c54(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  
  uVar1 = param_1 << 3;
  uVar2 = DAT_40021218;
  uVar2 = uVar2 & ~(0xbf << (uVar1 & 0xff));
  DAT_40021218 = 0x80 << (uVar1 & 0xff) | uVar2;
  DAT_40021218 = (param_2 & 0x3f) << (uVar1 & 0xff) | uVar2;
  uVar2 = 0x40 << (uVar1 & 0xff);
  do {
    uVar1 = DAT_40021218;
  } while ((uVar1 & uVar2) == 0);
  uVar1 = DAT_40021218;
  DAT_40021218 = uVar2 | uVar1;
  return;
}


// ===== FUN_00083c9c @ 00083c9c (32 bytes)

void FUN_00083c9c(int param_1,uint param_2,undefined4 param_3)

{
  if (param_1 != 0) {
    DAT_40001160 = param_2;
    DAT_40001168 = 0;
    FUN_00083cc4(param_3,300000000);
    return;
  }
  DAT_40001160 = param_2 | 2;
  return;
}


// ===== FUN_00083cc4 @ 00083cc4 (28 bytes)

void FUN_00083cc4(uint param_1,uint param_2,undefined4 param_3,undefined4 param_4)

{
  int iVar1;
  
  if (param_1 != 0) {
    iVar1 = FUN_00087756((int)((ulonglong)param_1 * (ulonglong)param_2),
                         (int)((ulonglong)param_1 * (ulonglong)param_2 >> 0x20),&DAT_003d0900,0,
                         param_4);
    do {
      iVar1 = iVar1 + -1;
    } while (iVar1 != 0);
  }
  return;
}


// ===== FUN_00083d40 @ 00083d40 (24 bytes)

undefined4 FUN_00083d40(undefined *param_1)

{
  undefined4 uVar1;
  
  if (param_1 == &DAT_40104000) {
    return 0;
  }
  if (param_1 == &DAT_40105000) {
    uVar1 = 1;
  }
  else {
    uVar1 = 2;
  }
  return uVar1;
}


// ===== FUN_00083e48 @ 00083e48 (190 bytes)

/* WARNING: Removing unreachable block (ram,0x00084574) */

void FUN_00083e48(void)

{
  int iVar1;
  uint uVar2;
  
  uVar2 = DAT_40002614;
  if ((uVar2 & 0xf000000) != 0) {
    DAT_40002634 = 0x4000000;
    DAT_40002634 = 0x8000000;
    DAT_40002634 = 0x1000000;
    DAT_40002634 = 0x2000000;
    FUN_00084470();
    RESET_ClearPeripheralReset(1);
    return;
  }
  iVar1 = DAT_40000010;
  if (iVar1 << 0x1e < 0) {
    DAT_40000070 = 2;
    do {
      uVar2 = DAT_40000010;
    } while ((~uVar2 & 2) == 0);
    return;
  }
  return;
}


// ===== FUN_00083ea0 @ 00083ea0 (22 bytes)

void FUN_00083ea0(int param_1)

{
  int iVar1;
  int *piVar2;
  
  iVar1 = 0;
  piVar2 = &DAT_000879d0;
  do {
    if (*piVar2 == param_1) {
      return;
    }
    iVar1 = iVar1 + 1;
    piVar2 = piVar2 + 1;
  } while (iVar1 != 10);
  return;
}


// ===== FUN_00083ebc @ 00083ebc (180 bytes)

undefined4 FUN_00083ebc(int param_1,uint param_2)

{
  ushort uVar1;
  int iVar2;
  undefined4 uVar3;
  undefined *puVar4;
  uint uVar5;
  
  iVar2 = FUN_00083ea0();
  uVar1 = *(ushort *)(&DAT_00087b28 + iVar2 * 2);
  uVar5 = (uint)uVar1;
  switch(uVar1 >> 8) {
  case 0:
    puVar4 = &DAT_40001000;
    break;
  case 1:
    uVar5 = (uint)(byte)uVar1;
    puVar4 = &DAT_40001000;
    goto LAB_00083f2a;
  case 2:
    puVar4 = &DAT_40001000;
    goto LAB_00083f38;
  case 3:
    puVar4 = &DAT_40021000;
    break;
  case 4:
    uVar5 = uVar5 & 0xff;
    puVar4 = &DAT_40021000;
LAB_00083f2a:
    *(int *)(puVar4 + 0x44) = 1 << uVar5;
    goto switchD_00083ed2_default;
  case 5:
    puVar4 = &DAT_40021000;
LAB_00083f38:
    *(int *)(puVar4 + 0x48) = 1 << (uVar5 & 0xff);
  default:
    goto switchD_00083ed2_default;
  }
  *(int *)(puVar4 + 0x40) = 1 << (uVar5 & 0xff);
switchD_00083ed2_default:
  RESET_ClearPeripheralReset(*(undefined2 *)(&DAT_00087b28 + iVar2 * 2));
  if (param_2 == 0) {
LAB_00083f04:
    if ((*(int *)(param_1 + 0xff8) << 0x1c < 0) && ((*(uint *)(param_1 + 0xff8) & 7) != param_2)) {
      uVar3 = 1;
    }
    else {
      uVar3 = 0;
      *(uint *)(param_1 + 0xff8) = param_2;
    }
  }
  else {
    if (param_2 < 5) {
      uVar5 = *(uint *)(param_1 + 0xff8) >> (param_2 + 3 & 0xff) & 1;
LAB_00083f02:
      if (uVar5 != 0) goto LAB_00083f04;
    }
    else if (param_2 == 5) {
      uVar5 = *(uint *)(param_1 + 0xff8) & 0x80;
      goto LAB_00083f02;
    }
    uVar3 = 3;
  }
  return uVar3;
}


// ===== FUN_00084150 @ 00084150 (86 bytes)

void FUN_00084150(uint param_1)

{
  undefined *puVar1;
  
  switch(param_1 >> 8) {
  case 0:
    puVar1 = &DAT_40001000;
    goto LAB_00084168;
  case 1:
    puVar1 = &DAT_40001000;
    goto LAB_00084176;
  case 2:
    puVar1 = &DAT_40001000;
    break;
  case 3:
    puVar1 = &DAT_40021000;
LAB_00084168:
    *(int *)(puVar1 + 0x40) = 1 << (param_1 & 0xff);
    return;
  case 4:
    puVar1 = &DAT_40021000;
LAB_00084176:
    *(int *)(puVar1 + 0x44) = 1 << (param_1 & 0xff);
    return;
  case 5:
    puVar1 = &DAT_40021000;
    break;
  default:
    goto switchD_00084156_default;
  }
  *(int *)(puVar1 + 0x48) = 1 << (param_1 & 0xff);
switchD_00084156_default:
  return;
}


// ===== GPIO_PortInit @ 000841b4 (26 bytes)

void GPIO_PortInit(undefined4 param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  int extraout_r1;
  undefined4 extraout_r2;
  
  FUN_00084150(*(undefined2 *)(&DAT_00087b3c + param_2 * 2));
  RESET_ClearPeripheralReset
            (*(undefined2 *)(&DAT_00087b3c + extraout_r1 * 2),extraout_r1,extraout_r2,param_4);
  return;
}


// ===== GPIO_PinInit @ 000841d8 (74 bytes)

void GPIO_PinInit(int param_1,int param_2,uint param_3,char *param_4)

{
  int extraout_r1;
  int iVar1;
  uint uVar2;
  uint *puVar3;
  
  FUN_00084150(*(undefined2 *)(&DAT_00087b3c + param_2 * 2));
  uVar2 = 1 << (param_3 & 0xff);
  if (*param_4 == '\0') {
    puVar3 = (uint *)(param_1 + extraout_r1 * 4 + 0x2000);
    uVar2 = *puVar3 & ~uVar2;
  }
  else {
    if (param_4[1] == '\0') {
      iVar1 = extraout_r1 + 0x8a0;
    }
    else {
      iVar1 = extraout_r1 + 0x880;
    }
    *(uint *)(param_1 + iVar1 * 4) = uVar2;
    puVar3 = (uint *)(param_1 + extraout_r1 * 4 + 0x2000);
    uVar2 = uVar2 | *puVar3;
  }
  *puVar3 = uVar2;
  return;
}


// ===== MU_Init @ 000842c8 (10 bytes)

void MU_Init(void)

{
  DAT_40021044 = 0x10000000;
  return;
}


// ===== FUN_00084470 @ 00084470 (24 bytes)

void FUN_00084470(void)

{
  int iVar1;
  uint uVar2;
  
  do {
    iVar1 = DAT_40135004;
  } while (iVar1 << 0x1f < 0);
  uVar2 = DAT_4013500c;
  DAT_4013500c = uVar2 | 1;
  do {
    iVar1 = DAT_40135004;
  } while (iVar1 << 0x1f < 0);
  return;
}


// ===== FUN_0008448c @ 0008448c (6 bytes)

void FUN_0008448c(undefined4 param_1)

{
  DAT_00080a58 = param_1;
  return;
}


// ===== FUN_00084498 @ 00084498 (96 bytes)

void FUN_00084498(uint param_1)

{
  uint uVar1;
  uint uVar2;
  
  uVar2 = 1 << (param_1 & 0xff);
  switch(param_1 >> 8) {
  case 0:
    DAT_40000040 = uVar2;
    do {
      uVar1 = DAT_40000010;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 1:
    DAT_40000044 = uVar2;
    do {
      uVar1 = DAT_40000014;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 2:
    DAT_40000048 = uVar2;
    do {
      uVar1 = DAT_40000018;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 3:
    DAT_40020040 = uVar2;
    do {
      uVar1 = DAT_40020010;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 4:
    DAT_40020044 = uVar2;
    do {
      uVar1 = DAT_40020014;
    } while ((uVar1 & uVar2) == 0);
    return;
  case 5:
    DAT_40020048 = uVar2;
    do {
      uVar1 = DAT_40020018;
    } while ((uVar1 & uVar2) == 0);
  }
  return;
}


// ===== SCTIMER_Init @ 000845b4 (154 bytes)

undefined4 SCTIMER_Init(uint *param_1,byte *param_2)

{
  byte bVar1;
  undefined4 *puVar2;
  int iVar3;
  
  DAT_40001040 = 0x1000000;
  RESET_ClearPeripheralReset(0x18);
  bVar1 = *param_2;
  *param_1 = (param_2[2] & 0xf) << 3 | (param_2[1] & 3) << 1 | (uint)bVar1 | (param_2[8] & 0xf) << 9
  ;
  param_1[1] = (uint)param_2[5] << 5 | (uint)param_2[3] << 4 | 4;
  param_1[1] = param_1[1] | 8;
  if (bVar1 == 0) {
    param_1[1] = (uint)param_2[6] << 0x15 | (uint)param_2[4] << 0x14 | param_1[1] | 0x40000;
    param_1[1] = param_1[1] | 0x80000;
  }
  param_1[0x14] = (uint)param_2[7];
  iVar3 = 0;
  DAT_00088aec = 0;
  DAT_00088af8 = 0;
  DAT_00088af0 = 0;
  DAT_00088af4 = 0;
  puVar2 = &DAT_00088afc;
  do {
    iVar3 = iVar3 + 1;
    *puVar2 = 0;
    puVar2 = puVar2 + 1;
  } while (iVar3 != 0x10);
  DAT_00088b3c = &LAB_0008457c_1;
  return 0;
}


// ===== FUN_00084670 @ 00084670 (250 bytes)

undefined1
FUN_00084670(int *param_1,uint param_2,int param_3,uint param_4,char param_5,uint *param_6)

{
  undefined2 uVar1;
  uint uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  
  uVar2 = DAT_00088af4;
  uVar4 = DAT_00088af0;
  if (0xf < DAT_00088aec) {
    return 1;
  }
  uVar5 = (param_2 & 0x3fff) >> 0xc;
  if (uVar5 == 2) {
    param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | (param_4 & 0xf) << 6;
  }
  else {
    if ((uVar5 == 0) || (uVar5 == 3)) {
      param_2 = param_2 | (param_4 & 0xf) << 6;
    }
    uVar1 = (undefined2)param_3;
    if (param_5 == '\x01') {
      if (*param_1 << 0x1f < 0) {
        return 1;
      }
      if (0xf < DAT_00088af0) {
        return 1;
      }
      *(undefined2 *)(param_1 + DAT_00088af0 + 0x40) = uVar1;
      *(undefined2 *)(param_1 + DAT_00088af0 + 0x80) = uVar1;
      param_2 = param_2 | DAT_00088af0;
      DAT_00088af0 = DAT_00088af0 + 1;
      param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2;
    }
    else {
      if (param_5 == '\x02') {
        if ((*param_1 << 0x1f < 0) || (piVar3 = (int *)&DAT_00088af4, 0xf < DAT_00088af4)) {
          return 1;
        }
        param_2 = DAT_00088af4 | param_2;
        *(undefined2 *)((int)param_1 + DAT_00088af4 * 4 + 0x102) = uVar1;
        *(undefined2 *)((int)param_1 + uVar2 * 4 + 0x202) = uVar1;
        param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | 0x10;
        uVar4 = uVar2;
      }
      else {
        if (param_5 != '\x04') {
          return 1;
        }
        if (-1 < *param_1 << 0x1f) {
          return 1;
        }
        piVar3 = (int *)&DAT_00088af0;
        if (0xf < DAT_00088af0) {
          return 1;
        }
        param_1[DAT_00088af0 + 0x40] = param_3;
        param_1[uVar4 + 0x80] = param_3;
        param_1[(DAT_00088aec + 0x60) * 2 + 1] = param_2 | uVar4;
      }
      *piVar3 = uVar4 + 1;
    }
  }
  param_1[(DAT_00088aec + 0x60) * 2] = 1 << (DAT_00088af8 & 0xff);
  *param_6 = DAT_00088aec;
  DAT_00088aec = DAT_00088aec + 1;
  return 0;
}


// ===== SCTIMER_SetupPwm @ 0008477c (344 bytes)

undefined4
SCTIMER_SetupPwm(int param_1,byte *param_2,int param_3,uint param_4,uint param_5,uint *param_6)

{
  longlong lVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  uint uVar6;
  uint local_28;
  uint local_24 [2];
  
  local_28 = 0;
  local_24[0] = 0;
  if (0x10 < DAT_00088aec + 2U) {
    return 1;
  }
  param_5 = param_5 / (((*(uint *)(param_1 + 4) & 0x1fff) >> 5) + 1);
  if (param_3 == 1) {
    *(uint *)(param_1 + 4) = *(uint *)(param_1 + 4) | 0x10;
  }
  else if (param_3 == 0) {
    param_5 = param_5 / param_4 - 1;
    goto LAB_000847cc;
  }
  param_5 = param_5 / (param_4 << 1);
LAB_000847cc:
  if (param_2[2] < 100) {
    lVar1 = (ulonglong)(uint)param_2[2] * (ulonglong)param_5;
    iVar2 = FUN_00087756((int)lVar1,(int)((ulonglong)lVar1 >> 0x20),100,0);
  }
  else if (param_3 == 0) {
    iVar2 = param_5 + 2;
  }
  else {
    iVar2 = param_5 - 1;
  }
  iVar3 = FUN_00084670(param_1,0x1000,param_5,0,4,&local_28);
  iVar2 = FUN_00084670(param_1,0x1000,iVar2,0,4,local_24);
  if (iVar2 != 0 || iVar3 != 0) {
    return 1;
  }
  uVar6 = 1 << (local_28 & 0xff);
  *(uint *)(param_1 + 8) = uVar6 & 0xffff | *(uint *)(param_1 + 8);
  *param_6 = local_28;
  uVar4 = (uint)*param_2;
  uVar5 = 1 << (local_24[0] & 0xff);
  if (param_2[1] == 1) {
    iVar2 = uVar4 * 8 + param_1;
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) & ~(1 << uVar4);
    if (param_3 == 0) {
      *(uint *)(iVar2 + 0x500) = uVar6 | *(uint *)(iVar2 + 0x500);
      *(uint *)(iVar2 + 0x504) = uVar5 | *(uint *)(iVar2 + 0x504);
      return 0;
    }
    *(uint *)(iVar2 + 0x504) = uVar5 | *(uint *)(iVar2 + 0x504);
    uVar4 = 1 << (uVar4 << 1 & 0xff) | *(uint *)(param_1 + 0x54) & ~(3 << (uVar4 << 1 & 0xff));
  }
  else {
    iVar2 = uVar4 * 8 + param_1;
    *(uint *)(param_1 + 0x50) = *(uint *)(param_1 + 0x50) | 1 << uVar4;
    if (param_3 == 0) {
      *(uint *)(iVar2 + 0x504) = uVar6 | *(uint *)(iVar2 + 0x504);
      *(uint *)(iVar2 + 0x500) = uVar5 | *(uint *)(iVar2 + 0x500);
      return 0;
    }
    *(uint *)(iVar2 + 0x500) = uVar5 | *(uint *)(iVar2 + 0x500);
    uVar4 = 1 << (uVar4 << 1 & 0xff) | *(uint *)(param_1 + 0x54) & ~(3 << (uVar4 << 1 & 0xff));
  }
  *(uint *)(param_1 + 0x54) = uVar4;
  return 0;
}


// ===== SCTIMER_SetCallback @ 000848d8 (8 bytes)

void SCTIMER_SetCallback(undefined4 param_1,undefined4 param_2,int param_3)

{
  (&DAT_00088afc)[param_3] = param_2;
  return;
}


// ===== SEMA42_Init @ 000848f4 (10 bytes)

void SEMA42_Init(void)

{
  DAT_40021044 = 0x20000000;
  return;
}


// ===== BOARD_BootClockRUN @ 0008494c (204 bytes)

void BOARD_BootClockRUN(void)

{
  uint uVar1;
  
  DAT_40002630 = 0x4000;
  DAT_40002630 = 0x10000;
  FUN_000838f4(0);
  DAT_40002630 = 0x8000;
  FUN_000839b4();
  FUN_00087234();
  CLOCK_AttachClk(0x4343430);
  DAT_40002630 = 0x2000;
  FUN_0008448c(0x104);
  FUN_00083c9c(1,1,0x104);
  DAT_00088930 = 24000000;
  DAT_00088928 = 0x1194000;
  DAT_40001168 = 1;
  FUN_000839fc(&DAT_00087a08);
  FUN_00083b04(0,0xc);
  FUN_00083b04(2,0x18);
  FUN_00083b4c(&DAT_000879f8);
  uVar1 = DAT_40021204;
  DAT_40021204 = uVar1 | 1;
  FUN_00083c54(0,0x1a);
  CLOCK_SetClkDiv(0x400,3);
  CLOCK_AttachClk(&DAT_00002434);
  CLOCK_SetClkDiv(0x80000240,1);
  CLOCK_SetClkDiv(0x500,2);
  CLOCK_SetClkDiv(0x800006fc,0xc);
  CLOCK_SetDiv_0x620(1,6);
  DAT_00087ec0 = 198000000;
  return;
}


// ===== ipc_init @ 00084a50 (46 bytes)

void ipc_init(void)

{
  DAT_00088b60 = rpmsg_lite_master_init(&DAT_20020000,0x20000,0);
  DAT_00088b5c = rpmsg_queue_create();
  DAT_00088b58 = rpmsg_lite_create_ept(DAT_00088b60,0x28,&LAB_000861b8_1,DAT_00088b5c);
  DAT_00088b54 = 0x1e;
  return;
}


// ===== ipc_send @ 00084a8c (30 bytes)

void ipc_send(undefined4 param_1)

{
  rpmsg_lite_send(DAT_00088b60,DAT_00088b58,DAT_00088b54,param_1,0x98,0xffffffff);
  return;
}


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
  FUN_00083b04(1,0xc);
  CLOCK_AttachClk(0x80002434);
  CLOCK_SetClkDiv(0x80000400,1);
  CLOCK_SetClkDiv(0x80000404,2);
  FUN_00083e48();
  DSP_CopyImage(&local_2c);
  DSP_CopyImage(&local_20);
  DSP_CopyImage(&local_14);
  DAT_4000200c = 0;
  return;
}


// ===== BOARD_InitPins_P0 @ 00084b78 (108 bytes)

void BOARD_InitPins_P0(uint param_1,uint param_2,uint param_3,uint param_4)

{
  uint local_18;
  uint local_14;
  uint local_10;
  uint local_c;
  
  DAT_40021044 = 1;
  local_18 = param_1 & 0xffff0000;
  local_14 = param_2;
  local_10 = param_3;
  local_c = param_4;
  GPIO_PinInit(&DAT_40100000,0,4,&local_18);
  local_14 = local_14 & 0xffff0000;
  GPIO_PinInit(&DAT_40100000,0,5,&local_14);
  local_10 = local_10 & 0xffff0000;
  GPIO_PinInit(&DAT_40100000,0,0x15,&local_10);
  local_c = local_c & 0xffff0000;
  GPIO_PinInit(&DAT_40100000,0,0x16,&local_c);
  DAT_40004054 = 0x40;
  DAT_40004058 = 0x40;
  DAT_40004010 = 0x40;
  DAT_40004014 = 0x40;
  return;
}


// ===== BOARD_InitPins_codec_spi @ 00084bec (150 bytes)

void BOARD_InitPins_codec_spi(void)

{
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_20;
  undefined1 local_1f;
  undefined2 local_1c [2];
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_14;
  undefined1 local_13;
  
  DAT_40021044 = 2;
  DAT_40021044 = 4;
  local_24 = 1;
  local_23 = 0;
  GPIO_PinInit(&DAT_40100000,1,0,&local_24);
  local_20 = 1;
  local_1f = 0;
  GPIO_PinInit(&DAT_40100000,1,1,&local_20);
  local_1c[0] = 0x101;
  GPIO_PinInit(&DAT_40100000,1,7,local_1c);
  local_18 = 0;
  local_17 = 0;
  GPIO_PinInit(&DAT_40100000,2,0x1c,&local_18);
  local_14 = 1;
  local_13 = 0;
  GPIO_PinInit(&DAT_40100000,2,0x1d,&local_14);
  DAT_40004080 = 0;
  DAT_40004084 = 0;
  DAT_4000409c = 0;
  DAT_40004170 = 0x40;
  DAT_40004174 = 0;
  return;
}

