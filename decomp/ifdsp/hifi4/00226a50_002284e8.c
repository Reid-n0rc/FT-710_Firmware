// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== xos_msgq_create @ 00226a50 (82 bytes)

/* called by Thread_Ipc and the other thread creators [inference] */

undefined4 xos_msgq_create(int param_1,int param_2,uint param_3,uint param_4)

{
  undefined4 uVar1;
  undefined2 uVar2;
  
  if (((param_1 == 0) || (param_2 == 0)) || ((param_3 & 3) != 0)) {
    uVar1 = 0xffff0001;
  }
  else {
    ae_s16i_n(param_4,param_1,0);
    *(uint *)(param_1 + 4) = param_3;
    *(short *)(param_1 + 2) = (short)param_2;
    *(int *)(param_1 + 0x1c) = param_1 + 0x18;
    *(int *)(param_1 + 0x10) = param_1 + 0xc;
    uVar1 = 0;
    *(undefined2 *)(param_1 + 8) = 0;
    *(undefined2 *)(param_1 + 10) = 0;
    *(undefined4 *)(param_1 + 0xc) = 0;
    uVar2 = 1;
    *(undefined4 *)(param_1 + 0x18) = 0;
    if ((param_4 & 1) != 0) {
      uVar2 = 2;
    }
    *(undefined2 *)(param_1 + 0x14) = uVar2;
    *(undefined2 *)(param_1 + 0x20) = uVar2;
  }
  return uVar1;
}


// ===== FUN_00226aa4 @ 00226aa4 (147 bytes)

undefined4 FUN_00226aa4(ushort *param_1)

{
  undefined6 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  uint uVar5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar6;
  undefined1 in_st_PSUM;
  undefined1 uVar7;
  undefined1 in_st_PSWOE;
  undefined1 uVar8;
  undefined1 in_st_PSEXCM;
  undefined1 uVar9;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar10;
  undefined1 in_st_PSOWB;
  undefined1 uVar11;
  undefined8 uVar12;
  
  if (param_1 != (ushort *)0x0) {
    uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
    uVar8 = (undefined1)uVar1;
    uVar10 = (undefined1)((uint6)uVar1 >> 8);
    uVar11 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar9 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar6 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    FUN_00227f3c();
    if (*(int *)(param_1 + 6) != 0) {
      while (iVar2 = FUN_002274c8(param_1 + 6), iVar2 != 0) {
        FUN_00227a24(iVar2,"msgq",0xffff000e);
      }
    }
    uVar4 = 0;
    if (*(int *)(param_1 + 0xc) != 0) {
      while( true ) {
        uVar12 = FUN_002274c8(param_1 + 0xc);
        uVar4 = (undefined4)((ulonglong)uVar12 >> 0x20);
        if ((int)uVar12 == 0) break;
        FUN_00227a24((int)uVar12,"msgq",0xffff000e);
      }
    }
    param_1[5] = 0;
    param_1[4] = 0;
    param_1[1] = 0;
    ae_s16i_n((uint)*param_1 | (uint)&DAT_00008002,param_1,0);
    uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
    uVar5 = uVar5 & 0xfffffff0 | uVar3 & 0xf;
    wsr_ps(uVar5);
    rsync();
    FUN_00227f58(0,uVar4,uVar5,uVar3 & 0xf,&DAT_00008002);
    return 0;
  }
  return 0xffff0001;
}


// ===== xos_msgq_put @ 00226b38 (138 bytes)

/* called from ipc_ept_rx_cb [inference] */

int xos_msgq_put(int param_1,int param_2)

{
  undefined6 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar4;
  undefined1 in_st_PSUM;
  undefined1 uVar5;
  undefined1 in_st_PSWOE;
  undefined1 uVar6;
  undefined1 in_st_PSEXCM;
  undefined1 uVar7;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar8;
  undefined1 in_st_PSOWB;
  undefined1 uVar9;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return -0xffff;
  }
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
  uVar6 = (undefined1)uVar1;
  uVar8 = (undefined1)((uint6)uVar1 >> 8);
  uVar9 = (undefined1)((uint6)uVar1 >> 0x10);
  uVar5 = (undefined1)((uint6)uVar1 >> 0x18);
  uVar7 = (undefined1)((uint6)uVar1 >> 0x20);
  uVar4 = (undefined1)((uint6)uVar1 >> 0x28);
  rsync();
  iVar2 = FUN_00226f70(param_1,param_2,uVar3 & 0xf);
  uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
  if (((uVar3 & 0x20) != 0) && (iVar2 != 0)) {
    if (iVar2 == -0xfff4) {
      do {
        uVar3 = ae_l16ui_n(param_1,0);
        uVar3 = uVar3 & 1;
        if (uVar3 == 0) {
          uVar3 = 1;
        }
        iVar2 = FUN_0022795c("msgq",param_1 + 0x18,0,uVar3);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
        uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
        uVar6 = (undefined1)uVar1;
        uVar8 = (undefined1)((uint6)uVar1 >> 8);
        uVar9 = (undefined1)((uint6)uVar1 >> 0x10);
        uVar5 = (undefined1)((uint6)uVar1 >> 0x18);
        uVar7 = (undefined1)((uint6)uVar1 >> 0x20);
        uVar4 = (undefined1)((uint6)uVar1 >> 0x28);
        rsync();
        iVar2 = FUN_00226f70(param_1,param_2,uVar3 & 0xf);
      } while (iVar2 == -0xfff4);
    }
    return iVar2;
  }
  return iVar2;
}


// ===== FUN_00226bc4 @ 00226bc4 (293 bytes)

int FUN_00226bc4(int param_1,int param_2,int param_3,int param_4)

{
  undefined6 uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int extraout_a3;
  uint uVar5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar6;
  undefined1 in_st_PSUM;
  undefined1 uVar7;
  undefined1 in_st_PSWOE;
  undefined1 uVar8;
  undefined1 in_st_PSEXCM;
  undefined1 uVar9;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar10;
  undefined1 in_st_PSOWB;
  undefined1 uVar11;
  int iVar12;
  undefined8 uVar13;
  undefined1 auStack_60 [48];
  int iStack_30;
  uint uStack_2c;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar4 = -0xffff;
  }
  else {
    uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar5 & 0xfffffff0 | 2);
    uVar8 = (undefined1)uVar1;
    uVar10 = (undefined1)((uint6)uVar1 >> 8);
    uVar11 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar9 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar6 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    iVar4 = FUN_00226f70(param_1,param_2,uVar5 & 0xf);
    uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
    if (((uVar5 >> 5 & 1) != 0) && (iVar4 != 0)) {
      bVar2 = false;
      iVar12 = param_1 + 0x18;
      if (iVar4 == -0xfff4) {
        bVar2 = false;
        iStack_30 = iVar12;
        do {
          uStack_2c = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
          uVar1 = wsr_ps(uStack_2c & 0xfffffff0 | 2);
          uVar8 = (undefined1)uVar1;
          uVar10 = (undefined1)((uint6)uVar1 >> 8);
          uVar11 = (undefined1)((uint6)uVar1 >> 0x10);
          uVar7 = (undefined1)((uint6)uVar1 >> 0x18);
          uVar9 = (undefined1)((uint6)uVar1 >> 0x20);
          uVar6 = (undefined1)((uint6)uVar1 >> 0x28);
          rsync();
          if (!bVar2) {
            FUN_002354c0(auStack_60);
            bVar2 = true;
            iVar12 = extraout_a3;
          }
          bVar3 = false;
          if ((param_4 != 0) || (param_3 != 0)) {
            bVar3 = true;
          }
          if ((bVar3) &&
             (iVar4 = FUN_002283e0(auStack_60,iVar12,param_3,param_4,0,FUN_00226f58,DAT_00237858),
             iVar4 != 0)) {
            uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
            wsr_ps(uVar5 & 0xfffffff0 | uStack_2c & 0xf);
            rsync();
            break;
          }
          uVar5 = ae_l16ui_n(param_1,0);
          uVar5 = uVar5 & 1;
          if (uVar5 == 0) {
            uVar5 = 1;
          }
          iVar4 = FUN_0022795c("msgq",iStack_30,0,uVar5);
          if (iVar4 != 0) {
            uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
            wsr_ps(uVar5 & 0xfffffff0 | uStack_2c & 0xf);
            rsync();
            break;
          }
          uVar13 = FUN_00226f70(param_1,param_2,uStack_2c & 0xf);
          iVar12 = (int)((ulonglong)uVar13 >> 0x20);
          iVar4 = (int)uVar13;
        } while (iVar4 == -0xfff4);
      }
      if (bVar2) {
        FUN_002284e8(auStack_60);
      }
    }
  }
  return iVar4;
}


// ===== xos_msgq_get @ 00226cec (141 bytes)

/* Thread_Ipc main loop [inference] */

int xos_msgq_get(int param_1,int param_2)

{
  undefined6 uVar1;
  int iVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar4;
  undefined1 in_st_PSUM;
  undefined1 uVar5;
  undefined1 in_st_PSWOE;
  undefined1 uVar6;
  undefined1 in_st_PSEXCM;
  undefined1 uVar7;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar8;
  undefined1 in_st_PSOWB;
  undefined1 uVar9;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    return -0xffff;
  }
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
  uVar6 = (undefined1)uVar1;
  uVar8 = (undefined1)((uint6)uVar1 >> 8);
  uVar9 = (undefined1)((uint6)uVar1 >> 0x10);
  uVar5 = (undefined1)((uint6)uVar1 >> 0x18);
  uVar7 = (undefined1)((uint6)uVar1 >> 0x20);
  uVar4 = (undefined1)((uint6)uVar1 >> 0x28);
  rsync();
  iVar2 = FUN_00226eb0(param_1,param_2,uVar3 & 0xf);
  uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
  if (((uVar3 & 0x20) != 0) && (iVar2 != 0)) {
    if (iVar2 == -0xfff3) {
      do {
        uVar3 = ae_l16ui_n(param_1,0);
        uVar3 = uVar3 & 1;
        if (uVar3 == 0) {
          uVar3 = 1;
        }
        iVar2 = FUN_0022795c("msgq",param_1 + 0xc,0,uVar3);
        if (iVar2 != 0) {
          return iVar2;
        }
        uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
        uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
        uVar6 = (undefined1)uVar1;
        uVar8 = (undefined1)((uint6)uVar1 >> 8);
        uVar9 = (undefined1)((uint6)uVar1 >> 0x10);
        uVar5 = (undefined1)((uint6)uVar1 >> 0x18);
        uVar7 = (undefined1)((uint6)uVar1 >> 0x20);
        uVar4 = (undefined1)((uint6)uVar1 >> 0x28);
        rsync();
        iVar2 = FUN_00226eb0(param_1,param_2,uVar3 & 0xf);
      } while (iVar2 == -0xfff3);
    }
    return iVar2;
  }
  return iVar2;
}


// ===== FUN_00226d7c @ 00226d7c (295 bytes)

int FUN_00226d7c(int param_1,int param_2,int param_3,int param_4)

{
  undefined6 uVar1;
  bool bVar2;
  bool bVar3;
  int iVar4;
  int extraout_a3;
  uint uVar5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar6;
  undefined1 in_st_PSUM;
  undefined1 uVar7;
  undefined1 in_st_PSWOE;
  undefined1 uVar8;
  undefined1 in_st_PSEXCM;
  undefined1 uVar9;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar10;
  undefined1 in_st_PSOWB;
  undefined1 uVar11;
  int iVar12;
  undefined8 uVar13;
  undefined1 auStack_60 [48];
  int iStack_30;
  uint uStack_2c;
  
  if ((param_1 == 0) || (param_2 == 0)) {
    iVar4 = -0xffff;
  }
  else {
    uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar5 & 0xfffffff0 | 2);
    uVar8 = (undefined1)uVar1;
    uVar10 = (undefined1)((uint6)uVar1 >> 8);
    uVar11 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar9 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar6 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    iVar4 = FUN_00226eb0(param_1,param_2,uVar5 & 0xf);
    uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
    if (((uVar5 >> 5 & 1) != 0) && (iVar4 != 0)) {
      bVar2 = false;
      iVar12 = param_1 + 0xc;
      if (iVar4 == -0xfff3) {
        bVar2 = false;
        iStack_30 = iVar12;
        do {
          uStack_2c = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
          uVar1 = wsr_ps(uStack_2c & 0xfffffff0 | 2);
          uVar8 = (undefined1)uVar1;
          uVar10 = (undefined1)((uint6)uVar1 >> 8);
          uVar11 = (undefined1)((uint6)uVar1 >> 0x10);
          uVar7 = (undefined1)((uint6)uVar1 >> 0x18);
          uVar9 = (undefined1)((uint6)uVar1 >> 0x20);
          uVar6 = (undefined1)((uint6)uVar1 >> 0x28);
          rsync();
          if (!bVar2) {
            FUN_002354c0(auStack_60);
            bVar2 = true;
            iVar12 = extraout_a3;
          }
          bVar3 = false;
          if ((param_4 != 0) || (param_3 != 0)) {
            bVar3 = true;
          }
          if ((bVar3) &&
             (iVar4 = FUN_002283e0(auStack_60,iVar12,param_3,param_4,0,FUN_00226f58,DAT_00237858),
             iVar4 != 0)) {
            uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
            wsr_ps(uVar5 & 0xfffffff0 | uStack_2c & 0xf);
            rsync();
            break;
          }
          uVar5 = ae_l16ui_n(param_1,0);
          uVar5 = uVar5 & 1;
          if (uVar5 == 0) {
            uVar5 = 1;
          }
          iVar4 = FUN_0022795c("msgq",iStack_30,0,uVar5);
          if (iVar4 != 0) {
            uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
            wsr_ps(uVar5 & 0xfffffff0 | uStack_2c & 0xf);
            rsync();
            break;
          }
          uVar13 = FUN_00226eb0(param_1,param_2,uStack_2c & 0xf);
          iVar12 = (int)((ulonglong)uVar13 >> 0x20);
          iVar4 = (int)uVar13;
        } while (iVar4 == -0xfff3);
      }
      if (bVar2) {
        FUN_002284e8(auStack_60);
      }
    }
  }
  return iVar4;
}


// ===== FUN_00226eb0 @ 00226eb0 (166 bytes)

undefined8 FUN_00226eb0(ushort *param_1,undefined4 *param_2,uint param_3)

{
  ushort uVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar4;
  uint uVar5;
  
  uVar4 = (uint)param_1[5];
  if ((param_1[4] == uVar4) && ((*param_1 & 2) == 0)) {
    uVar2 = 0xffff000d;
  }
  else {
    uVar3 = uVar4 * *(uint *)(param_1 + 2);
    uVar1 = param_1[1];
    uVar5 = *(uint *)(param_1 + 2) >> 2;
    if (((uVar5 != 0) && (uVar4 = (uint)param_1[5], uVar5 != 0)) && ((uVar5 == 1 || (uVar5 != 0))))
    {
      *param_2 = *(undefined4 *)((int)param_1 + (uVar3 & 0xfffffffc) + 0x24);
      param_2 = param_2 + 1;
    }
    uVar4 = ae_zext16(uVar4 + 1);
    param_1[5] = (ushort)uVar4;
    if (uVar1 <= uVar4) {
      param_1[5] = 0;
    }
    ae_s16i_n(*param_1 & 0xfffffffd,param_1,0);
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar2 = FUN_002274c8(param_1 + 0xc);
      FUN_00227a24(uVar2,"msgq",0);
    }
    uVar2 = 0;
  }
  uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar4 & 0xfffffff0 | param_3 & 0xf);
  rsync();
  return CONCAT44(param_2,uVar2);
}


// ===== FUN_00226f58 @ 00226f58 (20 bytes)

void FUN_00226f58(undefined4 param_1)

{
  FUN_00227a24(param_1,"msgq",0xffff0018);
  return;
}


// ===== FUN_00226f70 @ 00226f70 (154 bytes)

undefined8 FUN_00226f70(int param_1,undefined4 *param_2,uint param_3)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar3;
  
  uVar2 = ae_l16ui_n(param_1,0);
  uVar3 = (uint)*(ushort *)(param_1 + 8);
  if ((uVar2 >> 1 & 1) == 0) {
    uVar2 = *(uint *)(param_1 + 4) >> 2;
    if (uVar2 != 0) {
      if ((uVar2 != 0) && ((uVar2 == 1 || (uVar2 != 0)))) {
        uVar1 = *param_2;
        param_2 = param_2 + 1;
        *(undefined4 *)(param_1 + (uVar3 * *(uint *)(param_1 + 4) & 0xfffffffc) + 0x24) = uVar1;
      }
      uVar3 = (uint)*(ushort *)(param_1 + 8);
    }
    uVar2 = ae_zext16(uVar3 + 1);
    *(short *)(param_1 + 8) = (short)uVar2;
    if (*(ushort *)(param_1 + 2) <= uVar2) {
      *(undefined2 *)(param_1 + 8) = 0;
      uVar2 = 0;
    }
    if (*(ushort *)(param_1 + 10) == uVar2) {
      uVar2 = ae_l16ui_n(param_1,0);
      ae_s16i_n(uVar2 | 2,param_1,0);
    }
    if (*(int *)(param_1 + 0xc) != 0) {
      uVar1 = FUN_002274c8(param_1 + 0xc);
      FUN_00227a24(uVar1,"msgq",0);
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffff000c;
  }
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  wsr_ps(uVar2 & 0xfffffff0 | param_3 & 0xf);
  rsync();
  return CONCAT44(param_2,uVar1);
}


// ===== FUN_0022700c @ 0022700c (73 bytes)

undefined4 FUN_0022700c(undefined4 *param_1,uint param_2,int param_3)

{
  if (((param_1 != (undefined4 *)0x0) && (-1 < param_3)) && (param_3 < 0x10)) {
    *param_1 = 0;
    param_1[5] = 0;
    param_1[1] = 0;
    param_1[2] = param_1 + 1;
    param_1[4] = param_2 | 8;
    if (0 < param_3) {
      param_1[4] = param_2 | 0xc;
    }
    *(char *)(param_1 + 7) = (char)param_3;
    param_1[6] = 0;
    *(undefined2 *)(param_1 + 3) = 1;
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00227058 @ 00227058 (122 bytes)

undefined4 FUN_00227058(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  iVar1 = DAT_00237858;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar2 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  if (param_1 != (int *)0x0) {
    FUN_00227f3c();
    iVar3 = *param_1;
    if (iVar3 != 0) {
      if (iVar3 != iVar1) {
        FUN_00227f58();
        return 0xffff0005;
      }
      if (iVar3 != 0) {
        FUN_00227ff0(iVar1,param_1);
      }
    }
    *(undefined1 *)(param_1 + 7) = 0;
    param_1[6] = 0;
    if (param_1[1] != 0) {
      while (iVar1 = FUN_002274c8(param_1 + 1), iVar1 != 0) {
        FUN_00227a24(iVar1,"mutex",0xffff0007);
      }
    }
    param_1[5] = 0;
    param_1[4] = 0;
    param_1[1] = 0;
    param_1[2] = 0;
    *param_1 = 0;
    FUN_00227f58();
    return 0;
  }
  return 0xffff0001;
}


// ===== xos_mutex_lock @ 002270d4 (143 bytes)

/* around the reply rpmsg_lite_send [inference] */

int xos_mutex_lock(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar3 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  if (param_1 == (int *)0x0) {
    iVar2 = -0xffff;
  }
  else {
    iVar2 = 0;
    do {
      iVar1 = DAT_00237858;
      FUN_00227f3c();
      iVar4 = *param_1;
      if (iVar4 == 0) {
        *param_1 = iVar1;
        param_1[5] = 1;
        FUN_00227f88(iVar1,param_1);
        break;
      }
      if (iVar4 == iVar1) {
        param_1[5] = param_1[5] + 1;
        break;
      }
      if (*(char *)(iVar4 + 0x33) < *(char *)(iVar1 + 0x33)) {
        FUN_00228054(iVar4,param_1);
      }
      uVar3 = param_1[4] & 1;
      if (uVar3 == 0) {
        uVar3 = 1;
      }
      iVar2 = FUN_0022795c("mutex",param_1 + 1,0,uVar3);
    } while (iVar2 == 0);
    FUN_00227f58();
  }
  return iVar2;
}


// ===== FUN_00227168 @ 00227168 (197 bytes)

int FUN_00227168(int *param_1,undefined4 param_2,int param_3,int param_4)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  undefined4 extraout_a3;
  undefined4 extraout_a3_00;
  uint uVar5;
  undefined4 uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined1 auStack_60 [48];
  int *piStack_30;
  
  uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar5 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  bVar1 = false;
  if (param_1 == (int *)0x0) {
    iVar4 = -0xffff;
  }
  else {
    piStack_30 = param_1 + 1;
    iVar4 = 0;
    do {
      iVar3 = DAT_00237858;
      FUN_00227f3c();
      if (*param_1 == 0) {
        *param_1 = iVar3;
        param_1[5] = 1;
        FUN_00227f88(iVar3,param_1);
        break;
      }
      if (*param_1 == iVar3) {
        param_1[5] = param_1[5] + 1;
        break;
      }
      uVar6 = extraout_a3;
      if (!bVar1) {
        FUN_002354c0(auStack_60);
        bVar1 = true;
        uVar6 = extraout_a3_00;
      }
      bVar2 = false;
      if ((param_4 != 0) || (param_3 != 0)) {
        bVar2 = true;
      }
      if ((bVar2) &&
         (iVar4 = FUN_002283e0(auStack_60,uVar6,param_3,param_4,0,FUN_002272ec,DAT_00237858),
         iVar4 != 0)) break;
      uVar5 = param_1[4] & 1;
      if (uVar5 == 0) {
        uVar5 = 1;
      }
      iVar4 = FUN_0022795c("mutex",piStack_30,0,uVar5);
    } while (iVar4 == 0);
    if (bVar1) {
      FUN_002284e8(auStack_60);
    }
    FUN_00227f58();
  }
  return iVar4;
}


// ===== xos_mutex_unlock @ 00227230 (95 bytes)

/* [inference] */

undefined4 xos_mutex_unlock(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar3 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  if (param_1 == (int *)0x0) {
    return 0xffff0001;
  }
  FUN_00227f3c();
  iVar1 = DAT_00237858;
  if (*param_1 == DAT_00237858) {
    iVar4 = param_1[5];
    param_1[5] = iVar4 + -1;
    if (iVar4 + -1 == 0) {
      if (iVar1 != 0) {
        FUN_00227ff0(iVar1,param_1);
      }
      iVar1 = FUN_002274c8(param_1 + 1);
      if (iVar1 != 0) {
        FUN_00227a24(iVar1,"mutex",0);
      }
      *param_1 = 0;
    }
    uVar2 = 0;
  }
  else {
    uVar2 = 0xffff0005;
  }
  FUN_00227f58();
  return uVar2;
}


// ===== FUN_00227294 @ 00227294 (84 bytes)

undefined4 FUN_00227294(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  iVar1 = DAT_00237858;
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar3 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  if (param_1 == (int *)0x0) {
    return 0xffff0001;
  }
  FUN_00227f3c();
  if (*param_1 == 0) {
    *param_1 = iVar1;
    param_1[5] = 1;
    FUN_00227f88(iVar1,param_1);
  }
  else {
    if (*param_1 != iVar1) {
      uVar2 = 0xffff0004;
      goto LAB_002272d7;
    }
    param_1[5] = param_1[5] + 1;
  }
  uVar2 = 0;
LAB_002272d7:
  FUN_00227f58();
  return uVar2;
}


// ===== FUN_002272ec @ 002272ec (20 bytes)

void FUN_002272ec(undefined4 param_1)

{
  FUN_00227a24(param_1,"mutex",0xffff0018);
  return;
}


// ===== FUN_00227300 @ 00227300 (89 bytes)

undefined4 FUN_00227300(undefined *param_1,int param_2)

{
  if (param_1 == (undefined *)0x1) {
    param_1 = &DAT_002cb0f0;
  }
  if (((param_1 != (undefined *)0x0) && (param_2 != 0)) && (*(int *)(param_1 + 0x68) == 0x54485244))
  {
    if (param_1 == (undefined *)0x2) {
      *(undefined4 *)(param_2 + 8) = DAT_002cb0ec;
      *(undefined4 *)(param_2 + 0x14) = DAT_002cb0e4;
      *(undefined4 *)(param_2 + 0xc) = 0;
      *(undefined4 *)(param_2 + 0x10) = DAT_002cb0e0;
      return 0;
    }
    *(undefined4 *)(param_2 + 8) = *(undefined4 *)(param_1 + 0x78);
    *(undefined4 *)(param_2 + 0x14) = *(undefined4 *)(param_1 + 0x74);
    *(undefined4 *)(param_2 + 0xc) = *(undefined4 *)(param_1 + 0x7c);
    *(undefined4 *)(param_2 + 0x10) = *(undefined4 *)(param_1 + 0x70);
    return 0;
  }
  return 0xffff0001;
}


// ===== xos_get_cpu_load @ 0022735c (363 bytes)

undefined4 xos_get_cpu_load(int *param_1,int *param_2,int param_3)

{
  undefined6 uVar1;
  undefined1 uVar2;
  undefined1 uVar3;
  undefined1 uVar4;
  undefined1 uVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  uint uVar9;
  int iVar10;
  uint uVar11;
  uint uVar12;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar13;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar14;
  int iVar15;
  int iVar16;
  undefined8 uVar17;
  
  if (((param_1 != (int *)0x0) && (param_2 != (int *)0x0)) && (*param_2 != 0)) {
    uVar12 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL
                   );
    uVar1 = wsr_ps(uVar12 & 0xfffffff0 | 2);
    uVar2 = (undefined1)((uint6)uVar1 >> 8);
    uVar3 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar4 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar5 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar13 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    iVar7 = 0;
    iVar10 = DAT_002cb5a8;
    if (DAT_002cb5a8 == 0) {
      iVar7 = 0;
    }
    else {
      do {
        iVar10 = *(int *)(iVar10 + 8);
        iVar7 = iVar7 + 1;
      } while (iVar10 != 0);
    }
    iVar7 = iVar7 + 1;
    if (iVar7 <= *param_2) {
      uVar11 = 0;
      piVar6 = param_1;
      if (DAT_002cb5a8 == 0) {
        iVar10 = 0;
        uVar11 = 0;
      }
      else {
        iVar10 = 0;
        iVar16 = DAT_002cb5a8;
        do {
          *piVar6 = iVar16;
          piVar6[3] = *(int *)(iVar16 + 0x7c);
          piVar6[2] = *(int *)(iVar16 + 0x78);
          iVar8 = DAT_00237858;
          uVar14 = *(uint *)(iVar16 + 0x70);
          iVar15 = *(int *)(iVar16 + 0x74);
          piVar6[5] = iVar15;
          piVar6[4] = uVar14;
          if (iVar8 == iVar16) {
            iVar8 = rsr_ccount(in_CCOUNT);
            uVar9 = iVar8 - *(int *)(iVar16 + 0x6c);
            iVar15 = piVar6[5];
            uVar14 = uVar9 + piVar6[4];
            piVar6[4] = uVar14;
            if (uVar14 < uVar9) {
              iVar15 = iVar15 + 1;
            }
            piVar6[5] = iVar15;
          }
          iVar10 = iVar15 + iVar10;
          uVar11 = uVar14 + uVar11;
          if (param_3 != 0) {
            *(undefined4 *)(iVar16 + 0x78) = 0;
            *(undefined4 *)(iVar16 + 0x7c) = 0;
            *(undefined4 *)(iVar16 + 0x74) = 0;
            *(undefined4 *)(iVar16 + 0x70) = 0;
          }
          piVar6 = piVar6 + 6;
          iVar16 = *(int *)(iVar16 + 8);
          if (uVar11 < uVar14) {
            iVar10 = iVar10 + 1;
          }
        } while (iVar16 != 0);
      }
      *piVar6 = 2;
      piVar6[2] = DAT_002cb0ec;
      uVar14 = DAT_002cb0e0;
      piVar6[3] = 0;
      iVar16 = DAT_002cb0e4;
      piVar6[5] = DAT_002cb0e4;
      piVar6[4] = uVar14;
      if (param_3 != 0) {
        DAT_002cb0ec = 0;
        DAT_002cb0e4 = 0;
        DAT_002cb0e0 = 0;
      }
      iVar16 = iVar16 + iVar10;
      if (uVar14 + uVar11 < uVar14) {
        iVar16 = iVar16 + 1;
      }
      uVar9 = rsr_ps((char)uVar1,uVar2,uVar3,uVar4,uVar5,uVar13);
      wsr_ps(uVar12 & 0xf | uVar9 & 0xfffffff0);
      rsync();
      *param_2 = iVar7;
      if (0 < iVar7) {
        do {
          uVar17 = FUN_002358e0(param_1[4],param_1[5],100,0);
          iVar10 = __udivdi3((int)uVar17,(int)((ulonglong)uVar17 >> 0x20),uVar14 + uVar11,iVar16);
          param_1[1] = iVar10;
          iVar7 = iVar7 + -1;
          param_1 = param_1 + 6;
        } while (iVar7 != 0);
      }
      return 0;
    }
    *param_2 = iVar7;
    uVar11 = rsr_ps((char)uVar1,uVar2,uVar3,uVar4,uVar5,uVar13);
    wsr_ps(uVar12 & 0xf | uVar11 & 0xfffffff0);
    rsync();
  }
  return 0xffff0001;
}


// ===== FUN_002274c8 @ 002274c8 (21 bytes)

void FUN_002274c8(int *param_1)

{
  if (*param_1 != 0) {
    FUN_002353f4(param_1,*param_1);
  }
  return;
}


// ===== xos_thread_create @ 002274e0 (517 bytes)

/* called with thread entry, name, stack [inference] */

undefined4
xos_thread_create(undefined4 *param_1,int param_2,int param_3,undefined4 param_4,int param_5,
                 int param_6,uint param_7,char param_8,uint *param_9,uint param_10)

{
  undefined6 uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  uint uVar3;
  
  if (param_1 == (undefined4 *)0x0) {
    return 0xffff0001;
  }
  FUN_00227770();
  if ((param_10 >> 0xf & 1) == 0) {
    if (param_5 == 0) {
      return 0xffff0001;
    }
    if (param_3 == 0) {
      return 0xffff0001;
    }
    if (param_8 < '\0') {
      return 0xffff0001;
    }
    if ('\x0f' < param_8) {
      return 0xffff0001;
    }
    if (param_2 != 0) {
      if (param_6 != 0) {
        return 0xffff0001;
      }
      if (param_2 != 0) goto LAB_0022754e;
    }
    if (param_6 == 0) {
      return 0xffff0001;
    }
  }
LAB_0022754e:
  uVar3 = param_10 & 4;
  if ((param_10 >> 2 & 1) == 0) {
    if ((param_6 != 0) && (param_7 < 0x1b8)) {
      return 0xffff0012;
    }
  }
  else if ((param_6 != 0) && (param_7 < 0xe8)) {
    return 0xffff0012;
  }
  *param_1 = 0;
  param_1[8] = param_6;
  param_1[0xb] = param_4;
  param_1[10] = param_3;
  param_1[0x1a] = 0x54485244;
  param_1[9] = param_6 + param_7 & 0xfffffff0;
  if ((param_10 & (uint)&DAT_00008000) == 0) {
    if ((param_10 & 2) == 0) {
      param_1[3] = &LAB_00228c94;
      param_1[7] = FUN_00228cfc;
      if (param_2 != 0) {
        return 0xffff0013;
      }
      if (uVar3 == 0) {
        FUN_0023546c(param_1,param_6,1);
      }
      else {
        FUN_0023546c(param_1,param_6,0);
      }
    }
    else {
      param_1[3] = &LAB_00228c94;
      param_1[7] = FUN_00228c44;
      if (param_2 == 0) {
        if (uVar3 == 0) {
          FUN_0023546c(param_1,param_6,1);
        }
        else {
          FUN_0023546c(param_1,param_6,0);
        }
      }
      else {
        if ((*(uint *)(param_2 + 0x34) & 2) == 0) {
          return 0xffff0010;
        }
        if (*(char *)(param_2 + 0x32) != param_8) {
          return 0xffff0011;
        }
        if ((param_7 != 0) &&
           ((uint)(*(int *)(param_2 + 0x24) - *(int *)(param_2 + 0x20)) < param_7)) {
          return 0xffff0012;
        }
        param_1[8] = *(int *)(param_2 + 0x20);
        param_1[9] = *(undefined4 *)(param_2 + 0x24);
        param_1[5] = *(undefined4 *)(param_2 + 0x14);
      }
    }
  }
  else {
    param_1[7] = FUN_00228cfc;
    param_1[3] = &LAB_00228b56;
  }
  param_1[0x10] = param_2;
  *(char *)((int)param_1 + 0x32) = param_8;
  *(char *)((int)param_1 + 0x33) = param_8;
  param_1[0xe] = param_5;
  param_1[0xd] = param_10;
  FUN_00228e84(param_1);
  if (param_9 != (uint *)0x0) {
    if (uVar3 == 0) {
      uVar3 = *param_9;
      if ((uVar3 & 1) != 0) {
        *(short *)(param_1 + 0x15) = (short)param_9[1];
      }
    }
    else {
      *(undefined2 *)(param_1 + 0x15) = 0;
      uVar3 = *param_9;
    }
    if ((uVar3 & 4) != 0) {
      param_1[0x11] = param_9[2];
    }
  }
  param_1[0x23] = 0;
  param_1[0x21] = param_1 + 0x20;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
  rsync();
  *DAT_002cb5ac = param_1;
  DAT_002cb5ac = param_1 + 2;
  uVar3 = rsr_ps((char)uVar1,(char)((uint6)uVar1 >> 8),(char)((uint6)uVar1 >> 0x10),
                 (char)((uint6)uVar1 >> 0x18),(char)((uint6)uVar1 >> 0x20),
                 (char)((uint6)uVar1 >> 0x28));
  uVar3 = uVar3 & 0xfffffff0 | uVar2 & 0xf;
  wsr_ps(uVar3);
  rsync();
  if ((param_10 & 1) == 0) {
    FUN_00227a24(param_1,0,0,uVar3);
  }
  else {
    param_1[0xf] = "suspend";
  }
  return 0;
}


// ===== FUN_002276f0 @ 002276f0 (113 bytes)

undefined1  [12] FUN_002276f0(int param_1,undefined4 param_2,undefined4 param_3)

{
  undefined6 uVar1;
  int *piVar2;
  uint uVar5;
  undefined1 auVar3 [12];
  undefined1 auVar4 [12];
  int iVar6;
  int *piVar7;
  uint uVar8;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar9;
  undefined1 in_st_PSUM;
  undefined1 uVar10;
  undefined1 in_st_PSWOE;
  undefined1 uVar11;
  undefined1 in_st_PSEXCM;
  undefined1 uVar12;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar13;
  undefined1 in_st_PSOWB;
  undefined1 uVar14;
  
  piVar2 = DAT_002cb5ac;
  if (((param_1 == 0) || (DAT_00237858 == param_1)) || (*(char **)(param_1 + 0x3c) != "exited")) {
    auVar4._4_4_ = param_2;
    auVar4._0_4_ = 0xffff0014;
    auVar4._8_4_ = param_3;
    return auVar4;
  }
  uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = wsr_ps(uVar5 & 0xfffffff0 | 2);
  uVar11 = (undefined1)uVar1;
  uVar13 = (undefined1)((uint6)uVar1 >> 8);
  uVar14 = (undefined1)((uint6)uVar1 >> 0x10);
  uVar10 = (undefined1)((uint6)uVar1 >> 0x18);
  uVar12 = (undefined1)((uint6)uVar1 >> 0x20);
  uVar9 = (undefined1)((uint6)uVar1 >> 0x28);
  rsync();
  piVar7 = &DAT_002cb5a8;
  do {
    iVar6 = *piVar7;
    if (iVar6 == 0) {
LAB_0022773e:
      FUN_00228fb0(param_1);
      uVar8 = rsr_ps(uVar11,uVar13,uVar14,uVar10,uVar12,uVar9);
      wsr_ps(uVar8 & 0xfffffff0 | uVar5 & 0xf);
      rsync();
      auVar3._0_8_ = (ulonglong)uVar5 << 0x20;
      auVar3._8_4_ = 0xfffffff0;
      return auVar3;
    }
    if (param_1 == iVar6) {
      *piVar7 = *(int *)(param_1 + 8);
      if (piVar2 == (int *)(param_1 + 8)) {
        DAT_002cb5ac = piVar7;
      }
      goto LAB_0022773e;
    }
    piVar7 = (int *)(iVar6 + 8);
  } while( true );
}


// ===== FUN_00227770 @ 00227770 (115 bytes)

void FUN_00227770(void)

{
  undefined4 *puVar1;
  
  if (DAT_00237a80 != '\x01') {
    FUN_00227f3c();
    wsr_excsave1(&LAB_00228904);
    DAT_002cb5b4 = 0;
    DAT_002cb5a8 = 0;
    DAT_002cb5b0 = 0;
    DAT_002cb694 = 0;
    DAT_002cb690 = 0;
    DAT_002cb684 = 0;
    DAT_002cb69c = 0;
    DAT_002cb698 = 0;
    puVar1 = &DAT_002cb5a8;
    DAT_002cb5ac = &DAT_002cb5a8;
    if (DAT_002cb680 == (undefined4 *)0x0) {
      puVar1 = (undefined4 *)&DAT_000f4240;
    }
    DAT_002cb5c0 = 0;
    DAT_002cb5c4 = &DAT_002cb5c0;
    DAT_002cb5c8 = 2;
    DAT_002cb680 = puVar1;
    FUN_00228e60();
    FUN_00229224();
    DAT_00237a80 = '\x01';
  }
  return;
}


// ===== FUN_002277e4 @ 002277e4 (11 bytes)

undefined1 FUN_002277e4(void)

{
  return DAT_00237a80;
}


// ===== xos_start @ 002277f0 (178 bytes)

/* last call of main, arg 0 [inference] */

void xos_start(void)

{
  int iVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar2 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  iVar1 = FUN_002278a4();
  if (iVar1 == 1) {
    FUN_00226854(0xffff0014,0);
  }
  FUN_00227770();
  xos_thread_create(&DAT_002cb0f0,0,0,0,"idle",0,0,0,0,&DAT_00008001);
  DAT_002cb123 = 0xff;
  DAT_002cb0fc = FUN_00228b08;
  DAT_00237858 = 0;
  DAT_0023785c = 0;
  DAT_002cb5b8 = 0;
  DAT_00237a81 = 1;
  DAT_002cb12c = "idle";
  if (DAT_002cb5b0 != 0) {
    FUN_00228d68((&DAT_002cb5c0)[(0x1f - LZCOUNT(DAT_002cb5b0)) * 3]);
  }
  FUN_00228d68(&DAT_002cb0f0);
  FUN_00226854(0xffff0020,0);
  return;
}


// ===== FUN_002278a4 @ 002278a4 (11 bytes)

undefined1 FUN_002278a4(void)

{
  return DAT_00237a81;
}


// ===== FUN_002278b0 @ 002278b0 (67 bytes)

undefined4 FUN_002278b0(int param_1)

{
  undefined4 uVar1;
  
  if (DAT_002cb5b0 == 0) {
    uVar1 = FUN_00228120(param_1,&DAT_002cb0f0);
    return uVar1;
  }
  if ((&DAT_002cb5c0)[(0x1f - LZCOUNT(DAT_002cb5b0)) * 3] == param_1) {
    return 0;
  }
  uVar1 = FUN_00228120(param_1);
  return uVar1;
}


// ===== FUN_002278f8 @ 002278f8 (100 bytes)

void FUN_002278f8(void)

{
  char cVar1;
  undefined6 uVar2;
  int *piVar3;
  uint uVar4;
  uint uVar5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar6;
  undefined1 in_st_PSUM;
  undefined1 uVar7;
  undefined1 in_st_PSWOE;
  undefined1 uVar8;
  undefined1 in_st_PSEXCM;
  undefined1 uVar9;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar10;
  undefined1 in_st_PSOWB;
  undefined1 uVar11;
  
  piVar3 = DAT_00237858;
  if (DAT_002cb5b8 == 0) {
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar2 = wsr_ps(uVar4 & 0xfffffff0 | 2);
    uVar8 = (undefined1)uVar2;
    uVar10 = (undefined1)((uint6)uVar2 >> 8);
    uVar11 = (undefined1)((uint6)uVar2 >> 0x10);
    uVar7 = (undefined1)((uint6)uVar2 >> 0x18);
    uVar9 = (undefined1)((uint6)uVar2 >> 0x20);
    uVar6 = (undefined1)((uint6)uVar2 >> 0x28);
    rsync();
    if (*DAT_00237858 != 0) {
      cVar1 = *(char *)((int)DAT_00237858 + 0x33);
      FUN_002353f4(&DAT_002cb5c0 + cVar1 * 3,DAT_00237858);
      FUN_00235410(&DAT_002cb5c0 + cVar1 * 3,piVar3);
      FUN_002278b0(piVar3);
    }
    uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
    wsr_ps(uVar5 & 0xfffffff0 | uVar4 & 0xf);
    rsync();
  }
  return;
}


// ===== FUN_0022795c @ 0022795c (197 bytes)

undefined8 FUN_0022795c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  undefined6 uVar2;
  int iVar3;
  undefined4 uVar4;
  uint uVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 uVar8;
  undefined1 in_st_PSWOE;
  undefined1 uVar9;
  undefined1 in_st_PSEXCM;
  undefined1 uVar10;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar11;
  undefined1 in_st_PSOWB;
  undefined1 uVar12;
  int iVar13;
  
  iVar3 = DAT_00237858;
  cVar1 = *(char *)(DAT_00237858 + 0x33);
  uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if (((uVar5 & 0x20) == 0) && (*(char *)(DAT_00237858 + 0x30) == '\0')) {
    FUN_00226854(0xffff001d,0);
    return CONCAT44(param_2,0xffffffff);
  }
  uVar5 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar2 = wsr_ps(uVar5 & 0xfffffff0 | 2);
  uVar9 = (undefined1)uVar2;
  uVar11 = (undefined1)((uint6)uVar2 >> 8);
  uVar12 = (undefined1)((uint6)uVar2 >> 0x10);
  uVar8 = (undefined1)((uint6)uVar2 >> 0x18);
  uVar10 = (undefined1)((uint6)uVar2 >> 0x20);
  uVar7 = (undefined1)((uint6)uVar2 >> 0x28);
  rsync();
  FUN_002353f4(&DAT_002cb5c0 + cVar1 * 3,DAT_00237858);
  *(undefined4 *)(iVar3 + 0x3c) = param_1;
  iVar13 = (&DAT_002cb5c0)[cVar1 * 3];
  *(undefined1 *)(iVar3 + 0x30) = 0;
  if (iVar13 == 0) {
    DAT_002cb5b0 = DAT_002cb5b0 & (1 << 0x20 - (0x20 - ((int)cVar1 & 0x1fU)) ^ 0xffffffffU);
  }
  if (param_2 != 0) {
    if (param_4 == 0) {
      FUN_00235410(param_2,iVar3);
    }
    else {
      FUN_0023543c(param_2,iVar3);
    }
  }
  if (DAT_002cb5b8 != 0) {
    DAT_002cb5b8 = 0;
  }
  uVar4 = FUN_002278b0(iVar3);
  uVar6 = rsr_ps(uVar9,uVar11,uVar12,uVar8,uVar10,uVar7);
  wsr_ps(uVar6 & 0xfffffff0 | uVar5 & 0xf);
  rsync();
  return CONCAT44(0xfffffff0,uVar4);
}


// ===== FUN_00227a24 @ 00227a24 (203 bytes)

void FUN_00227a24(int param_1,int param_2,undefined4 param_3)

{
  undefined6 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar5;
  undefined1 in_st_PSUM;
  undefined1 uVar6;
  undefined1 in_st_PSWOE;
  undefined1 uVar7;
  undefined1 in_st_PSEXCM;
  undefined1 uVar8;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar9;
  undefined1 in_st_PSOWB;
  undefined1 uVar10;
  
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
  uVar7 = (undefined1)uVar1;
  uVar9 = (undefined1)((uint6)uVar1 >> 8);
  uVar10 = (undefined1)((uint6)uVar1 >> 0x10);
  uVar6 = (undefined1)((uint6)uVar1 >> 0x18);
  uVar8 = (undefined1)((uint6)uVar1 >> 0x20);
  uVar5 = (undefined1)((uint6)uVar1 >> 0x28);
  rsync();
  if (*(char *)(param_1 + 0x30) == '\0') {
    if ((param_2 == 0) || (*(int *)(param_1 + 0x3c) == param_2)) {
      if (*(int *)(param_1 + 0x48) != 0) {
        FUN_002353f4(*(int *)(param_1 + 0x48),param_1);
      }
      FUN_00235410(&DAT_002cb5c0 + *(char *)(param_1 + 0x33) * 3,param_1);
      *(undefined4 *)(param_1 + 0x18) = param_3;
      *(undefined1 *)(param_1 + 0x30) = 1;
      iVar2 = DAT_002cb5b8;
      *(undefined4 *)(param_1 + 0x3c) = 0;
      DAT_002cb5b0 = DAT_002cb5b0 | 1 << 0x20 - (0x20 - (*(byte *)(param_1 + 0x33) & 0x1f));
      if ((iVar2 == 0) && (*(char *)(DAT_00237858 + 0x33) < (char)*(byte *)(param_1 + 0x33))) {
        FUN_002278b0();
      }
      uVar4 = rsr_ps(uVar7,uVar9,uVar10,uVar6,uVar8,uVar5);
      wsr_ps(uVar4 & 0xfffffff0 | uVar3 & 0xf);
      rsync();
    }
    else {
      uVar4 = rsr_ps(uVar7,uVar9,uVar10,uVar6,uVar8,uVar5);
      wsr_ps(uVar4 & 0xfffffff0 | uVar3 & 0xf);
      rsync();
    }
  }
  else {
    uVar4 = rsr_ps(uVar7,uVar9,uVar10,uVar6,uVar8,uVar5);
    wsr_ps(uVar4 & 0xfffffff0 | uVar3 & 0xf);
    rsync();
  }
  return;
}


// ===== FUN_00227af0 @ 00227af0 (240 bytes)

undefined4 FUN_00227af0(int param_1,int param_2)

{
  undefined6 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar4;
  undefined1 in_st_PSUM;
  undefined1 uVar5;
  undefined1 in_st_PSWOE;
  undefined1 uVar6;
  undefined1 in_st_PSEXCM;
  undefined1 uVar7;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar8;
  undefined1 in_st_PSOWB;
  undefined1 uVar9;
  int iVar10;
  
  if ((((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) && (-1 < param_2)) &&
     (param_2 < 0x10)) {
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
    uVar6 = (undefined1)uVar1;
    uVar8 = (undefined1)((uint6)uVar1 >> 8);
    uVar9 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar5 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar4 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    uVar2 = uVar2 & 0xf;
    iVar10 = (int)*(char *)(param_1 + 0x33);
    if (*(char *)(param_1 + 0x32) == param_2) {
      uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
      wsr_ps(uVar2 | uVar3 & 0xfffffff0);
      rsync();
    }
    else {
      if ((*(char *)(param_1 + 0x32) == iVar10) || (iVar10 < param_2)) {
        *(char *)(param_1 + 0x33) = (char)param_2;
      }
      *(char *)(param_1 + 0x32) = (char)param_2;
      if (iVar10 == *(char *)(param_1 + 0x33)) {
        uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
        wsr_ps(uVar2 | uVar3 & 0xfffffff0);
        rsync();
      }
      else {
        if (*(char *)(param_1 + 0x30) == '\0') {
          if (*(int *)(param_1 + 4) != 0) {
            iVar10 = *(int *)(param_1 + 0x48);
            if ((*(ushort *)(iVar10 + 8) & 1) != 0) {
              FUN_002353f4(iVar10,param_1);
              FUN_0023543c(iVar10,param_1);
            }
          }
        }
        else {
          FUN_002280c4(param_1,iVar10);
          if (param_1 == DAT_00237858) {
            if (*(char *)(param_1 + 0x33) < iVar10) {
              FUN_002278b0();
            }
          }
          else if ((int)*(char *)(DAT_00237858 + 0x33) < (int)*(char *)(param_1 + 0x33)) {
            FUN_002278b0();
          }
        }
        uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
        wsr_ps(uVar2 | uVar3 & 0xfffffff0);
        rsync();
      }
    }
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00227be4 @ 00227be4 (78 bytes)

int FUN_00227be4(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  undefined6 uVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar6;
  undefined1 in_st_PSUM;
  undefined1 uVar7;
  undefined1 in_st_PSWOE;
  undefined1 uVar8;
  undefined1 in_st_PSEXCM;
  undefined1 uVar9;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar10;
  undefined1 in_st_PSOWB;
  undefined1 uVar11;
  
  FUN_00227f3c();
  iVar2 = 0;
  while( true ) {
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar4 & 0xfffffff0 | 2);
    uVar8 = (undefined1)uVar1;
    uVar10 = (undefined1)((uint6)uVar1 >> 8);
    uVar11 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar9 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar6 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    iVar3 = FUN_002274c8(param_1);
    uVar5 = rsr_ps(uVar8,uVar10,uVar11,uVar7,uVar9,uVar6);
    uVar1 = wsr_ps(uVar5 & 0xfffffff0 | uVar4 & 0xf);
    in_st_PSWOE = (undefined1)uVar1;
    in_st_PSCALLINC = (undefined1)((uint6)uVar1 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar1 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar1 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar1 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    if (iVar3 == 0) break;
    FUN_00227a24(iVar3,param_2,param_3);
    iVar2 = iVar2 + 1;
  }
  return iVar2;
}


// ===== FUN_00227c38 @ 00227c38 (44 bytes)

undefined4 FUN_00227c38(int param_1,undefined4 param_2)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    if (*(char **)(param_1 + 0x3c) == "exited") {
      return 0xffff0015;
    }
    *(undefined4 *)(param_1 + 0x44) = param_2;
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00227c64 @ 00227c64 (86 bytes)

void FUN_00227c64(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  iVar1 = DAT_00237858;
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar2 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  *(undefined1 *)(iVar1 + 0x31) = 1;
  if (*(code **)(iVar1 + 0x44) != (code *)0x0) {
    param_1 = (**(code **)(iVar1 + 0x44))(param_1);
  }
  *(undefined4 *)(iVar1 + 0x18) = param_1;
  FUN_00227be4(iVar1 + 0x80,"join",param_1);
  FUN_0022795c("exited",0,1,0);
  FUN_00226854(0xffff0020,0);
  return;
}


// ===== FUN_00227cbc @ 00227cbc (125 bytes)

undefined4 FUN_00227cbc(int param_1,undefined4 *param_2)

{
  undefined6 uVar1;
  undefined4 uVar2;
  uint uVar3;
  uint uVar4;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar5;
  undefined1 in_st_PSUM;
  undefined1 uVar6;
  undefined1 in_st_PSWOE;
  undefined1 uVar7;
  undefined1 in_st_PSEXCM;
  undefined1 uVar8;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar9;
  undefined1 in_st_PSOWB;
  undefined1 uVar10;
  
  uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar3 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    uVar3 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar3 & 0xfffffff0 | 2);
    uVar7 = (undefined1)uVar1;
    uVar9 = (undefined1)((uint6)uVar1 >> 8);
    uVar10 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar6 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar8 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar5 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    if ((*(char *)(param_1 + 0x30) == '\0') && (*(char **)(param_1 + 0x3c) == "exited")) {
      uVar2 = *(undefined4 *)(param_1 + 0x18);
    }
    else {
      uVar2 = FUN_0022795c("join",param_1 + 0x80,0,1);
    }
    uVar4 = rsr_ps(uVar7,uVar9,uVar10,uVar6,uVar8,uVar5);
    wsr_ps(uVar4 & 0xfffffff0 | uVar3 & 0xf);
    rsync();
    if (param_2 != (undefined4 *)0x0) {
      *param_2 = uVar2;
    }
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00227d3c @ 00227d3c (163 bytes)

undefined8 FUN_00227d3c(int param_1,undefined4 param_2)

{
  char cVar1;
  undefined6 uVar2;
  undefined4 uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 uVar8;
  undefined1 in_st_PSWOE;
  undefined1 uVar9;
  undefined1 in_st_PSEXCM;
  undefined1 uVar10;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar11;
  undefined1 in_st_PSOWB;
  undefined1 uVar12;
  
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    if (*(char *)(param_1 + 0x30) == '\0') {
      return CONCAT44(param_2,0xffff001d);
    }
    uVar4 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar2 = wsr_ps(uVar4 & 0xfffffff0 | 2);
    uVar9 = (undefined1)uVar2;
    uVar11 = (undefined1)((uint6)uVar2 >> 8);
    uVar12 = (undefined1)((uint6)uVar2 >> 0x10);
    uVar8 = (undefined1)((uint6)uVar2 >> 0x18);
    uVar10 = (undefined1)((uint6)uVar2 >> 0x20);
    uVar7 = (undefined1)((uint6)uVar2 >> 0x28);
    rsync();
    cVar1 = *(char *)(param_1 + 0x33);
    FUN_002353f4(&DAT_002cb5c0 + cVar1 * 3,param_1);
    iVar5 = (&DAT_002cb5c0)[cVar1 * 3];
    *(undefined1 *)(param_1 + 0x30) = 0;
    *(char **)(param_1 + 0x3c) = "suspend";
    if (iVar5 == 0) {
      DAT_002cb5b0 = DAT_002cb5b0 &
                     (1 << 0x20 - (0x20 - (*(byte *)(param_1 + 0x33) & 0x1f)) ^ 0xffffffffU);
    }
    if (DAT_00237858 == param_1) {
      uVar3 = FUN_002278b0(param_1);
    }
    else {
      uVar3 = 0;
    }
    uVar6 = rsr_ps(uVar9,uVar11,uVar12,uVar8,uVar10,uVar7);
    wsr_ps(uVar6 & 0xfffffff0 | uVar4 & 0xf);
    rsync();
    return CONCAT44(uVar4,uVar3);
  }
  return CONCAT44(param_2,0xffff0001);
}


// ===== FUN_00227de0 @ 00227de0 (47 bytes)

undefined4 FUN_00227de0(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    if (*(char **)(param_1 + 0x3c) == "suspend") {
      FUN_00227a24(param_1,"suspend",0);
    }
    return 0;
  }
  return 0xffff0001;
}


// ===== FUN_00227e10 @ 00227e10 (220 bytes)

undefined4 FUN_00227e10(int param_1,undefined4 param_2)

{
  undefined6 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar4;
  undefined1 in_st_PSUM;
  undefined1 uVar5;
  undefined1 in_st_PSWOE;
  undefined1 uVar6;
  undefined1 in_st_PSEXCM;
  undefined1 uVar7;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar8;
  undefined1 in_st_PSOWB;
  undefined1 uVar9;
  
  if ((param_1 == 0) || (*(int *)(param_1 + 0x68) != 0x54485244)) {
    return 0xffff0001;
  }
  if (DAT_00237858 == param_1) {
    return 0xffff0014;
  }
  if (*(char **)(param_1 + 0x3c) == "exited") {
    return 0xffff0015;
  }
  if (*(char *)(param_1 + 0x31) != '\0') {
    return 0;
  }
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
  uVar6 = (undefined1)uVar1;
  uVar8 = (undefined1)((uint6)uVar1 >> 8);
  uVar9 = (undefined1)((uint6)uVar1 >> 0x10);
  uVar5 = (undefined1)((uint6)uVar1 >> 0x18);
  uVar7 = (undefined1)((uint6)uVar1 >> 0x20);
  uVar4 = (undefined1)((uint6)uVar1 >> 0x28);
  rsync();
  FUN_00227f3c();
  if (*(char *)(param_1 + 0x30) == '\0') {
    if (*(char **)(param_1 + 0x3c) == (char *)0x0) {
      FUN_00227f58();
      uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
      wsr_ps(uVar3 & 0xfffffff0 | uVar2 & 0xf);
      rsync();
      return 0xffff0015;
    }
    if (*(int *)(param_1 + 0x48) != 0) {
      FUN_002353f4(*(int *)(param_1 + 0x48),param_1);
      FUN_00227a24(param_1,0,param_2);
      goto LAB_00227e97;
    }
    if (*(char **)(param_1 + 0x3c) != "suspend") {
      FUN_00226854(0xffff0020,0);
      goto LAB_00227e97;
    }
    FUN_00227de0(param_1);
  }
  *(undefined4 *)(param_1 + 0x18) = param_2;
LAB_00227e97:
  if (*(undefined1 **)(param_1 + 0xc) == &LAB_00228d78) {
    **(undefined4 **)(param_1 + 0x10) = &LAB_00228cf0;
  }
  else {
    (*(undefined4 **)(param_1 + 0x10))[0x16] = &LAB_00228cf0;
  }
  FUN_00227f58();
  uVar3 = rsr_ps(uVar6,uVar8,uVar9,uVar5,uVar7,uVar4);
  wsr_ps(uVar3 & 0xfffffff0 | uVar2 & 0xf);
  rsync();
  return 0;
}


// ===== FUN_00227ef4 @ 00227ef4 (71 bytes)

undefined4 FUN_00227ef4(int param_1)

{
  if ((param_1 != 0) && (*(int *)(param_1 + 0x68) == 0x54485244)) {
    if (*(char *)(param_1 + 0x30) != '\0') {
      if (DAT_00237858 == param_1) {
        return 3;
      }
      return 2;
    }
    if (*(char **)(param_1 + 0x3c) != (char *)0x0) {
      if (*(char **)(param_1 + 0x3c) == "exited") {
        return 4;
      }
      return 1;
    }
  }
  return 0;
}


// ===== FUN_00227f3c @ 00227f3c (25 bytes)

undefined8 FUN_00227f3c(void)

{
  undefined4 uVar1;
  
  uVar1 = rsil(2);
  DAT_002cb5b8 = DAT_002cb5b8 + 1;
  wsr_ps(uVar1);
  return CONCAT44(uVar1,DAT_002cb5b8);
}


// ===== FUN_00227f58 @ 00227f58 (47 bytes)

int FUN_00227f58(void)

{
  undefined4 uVar1;
  int iVar2;
  
  uVar1 = rsil(2);
  iVar2 = DAT_002cb5b8 + -1;
  if (((DAT_002cb5b8 != 0) && (DAT_002cb5b8 = iVar2, iVar2 == 0)) &&
     (iVar2 = FUN_002278a4(), iVar2 == 1)) {
    FUN_002278b0(DAT_00237858);
  }
  wsr_ps(uVar1);
  return DAT_002cb5b8;
}


// ===== FUN_00227f88 @ 00227f88 (102 bytes)

void FUN_00227f88(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  if (param_1 != -1) {
    cVar1 = *(char *)(param_2 + 0x1c);
    if ((*(uint *)(param_2 + 0x10) >> 2 & 1) == 0) {
      cVar1 = '\0';
    }
    *(char *)(param_2 + 0x1d) = cVar1;
    iVar4 = *(int *)(param_1 + 0x8c);
    iVar2 = 0;
    for (iVar3 = iVar4; (iVar3 != 0 && (cVar1 < *(char *)(iVar3 + 0x1d)));
        iVar3 = *(int *)(iVar3 + 0x18)) {
      iVar2 = iVar3;
    }
    if (iVar2 == 0) {
      *(int *)(param_1 + 0x8c) = param_2;
      iVar4 = param_2;
    }
    else {
      *(int *)(iVar2 + 0x18) = param_2;
    }
    *(int *)(param_2 + 0x18) = iVar3;
    if (*(char *)(param_1 + 0x33) < *(char *)(iVar4 + 0x1d)) {
      FUN_002280c4(param_1);
    }
  }
  return;
}


// ===== FUN_00227ff0 @ 00227ff0 (100 bytes)

void FUN_00227ff0(int param_1,int param_2)

{
  char cVar1;
  char cVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  
  if (param_1 != -1) {
    iVar4 = *(int *)(param_1 + 0x8c);
    iVar5 = 0;
    for (iVar3 = iVar4; (param_2 != iVar3 && (iVar3 != 0)); iVar3 = *(int *)(iVar3 + 0x18)) {
      iVar5 = iVar3;
    }
    iVar3 = *(int *)(iVar3 + 0x18);
    cVar1 = *(char *)(param_1 + 0x33);
    if (iVar5 == 0) {
      *(int *)(param_1 + 0x8c) = iVar3;
      iVar4 = iVar3;
    }
    else {
      *(int *)(iVar5 + 0x18) = iVar3;
    }
    cVar2 = *(char *)(param_1 + 0x32);
    *(undefined4 *)(param_2 + 0x18) = 0;
    *(undefined1 *)(param_2 + 0x1d) = 0;
    iVar5 = (int)cVar2;
    if (iVar4 != 0) {
      iVar3 = (int)*(char *)(iVar4 + 0x1d);
      iVar5 = (int)(((uint)(iVar3 < iVar5) * iVar5 + (uint)(iVar3 >= iVar5) * iVar3) * 0x1000000) >>
              0x18;
    }
    if (iVar5 < cVar1) {
      FUN_002280c4(param_1);
    }
  }
  return;
}


// ===== FUN_00228054 @ 00228054 (110 bytes)

void FUN_00228054(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  
  iVar4 = *(int *)(param_1 + 0x8c);
  iVar1 = iVar4;
  iVar3 = 0;
  while ((iVar2 = iVar1, param_2 != iVar2 && (iVar2 != 0))) {
    iVar3 = iVar2;
    iVar1 = *(int *)(iVar2 + 0x18);
  }
  iVar1 = *(int *)(iVar2 + 0x18);
  if (iVar3 == 0) {
    *(int *)(param_1 + 0x8c) = iVar1;
    iVar4 = iVar1;
  }
  else {
    *(int *)(iVar3 + 0x18) = iVar1;
  }
  *(char *)(param_2 + 0x1d) = (char)param_3;
  *(undefined4 *)(param_2 + 0x18) = 0;
  iVar1 = iVar4;
  iVar3 = 0;
  while ((iVar2 = iVar1, iVar2 != 0 && (param_3 < *(char *)(iVar2 + 0x1d)))) {
    iVar3 = iVar2;
    iVar1 = *(int *)(iVar2 + 0x18);
  }
  if (iVar3 == 0) {
    *(int *)(param_1 + 0x8c) = param_2;
    iVar4 = param_2;
  }
  else {
    *(int *)(iVar3 + 0x18) = param_2;
  }
  *(int *)(param_2 + 0x18) = iVar2;
  FUN_002280c4(param_1,(int)*(char *)(param_1 + 0x33),(int)*(char *)(iVar4 + 0x1d));
  return;
}


// ===== FUN_002280c4 @ 002280c4 (91 bytes)

void FUN_002280c4(int param_1,uint param_2,uint param_3)

{
  FUN_002353f4(&DAT_002cb5c0 + param_2 * 3,param_1);
  if ((&DAT_002cb5c0)[param_2 * 3] == 0) {
    DAT_002cb5b0 = DAT_002cb5b0 & (1 << 0x20 - (0x20 - (param_2 & 0x1f)) ^ 0xffffffffU);
  }
  *(char *)(param_1 + 0x33) = (char)param_3;
  FUN_00235420(&DAT_002cb5c0 + param_3 * 3,param_1);
  DAT_002cb5b0 = DAT_002cb5b0 | 1 << 0x20 - (0x20 - (param_3 & 0x1f));
  return;
}


// ===== FUN_00228120 @ 00228120 (53 bytes)

undefined4 FUN_00228120(int param_1,undefined4 param_2)

{
  undefined4 uVar1;
  uint uVar2;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  if (DAT_002cb5b8 == 0) {
    uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar2 & 0x20) == 0) {
      uVar1 = 0;
      DAT_0023785c = param_2;
    }
    else {
      uVar1 = (**(code **)(param_1 + 0x1c))(param_2);
    }
    DAT_002cb5b4 = DAT_002cb5b4 + 1;
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_00228158 @ 00228158 (505 bytes)

/* WARNING: Type propagation algorithm not settling */

void FUN_00228158(void)

{
  int *piVar1;
  int *piVar2;
  undefined6 uVar3;
  bool bVar4;
  undefined4 *puVar5;
  undefined *puVar6;
  undefined4 *puVar7;
  uint uVar8;
  undefined *puVar9;
  undefined *puVar10;
  uint uVar11;
  int iVar12;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar13;
  undefined1 in_st_PSUM;
  undefined1 uVar14;
  undefined1 in_st_PSWOE;
  undefined1 uVar15;
  undefined1 in_st_PSEXCM;
  undefined1 uVar16;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar17;
  undefined1 in_st_PSOWB;
  undefined1 uVar18;
  undefined *puVar19;
  
  puVar10 = DAT_002cb684;
  if (DAT_002cb688 == '\0') {
    do {
      uVar8 = DAT_002cb690 + 1;
      if (uVar8 < DAT_002cb690) {
        DAT_002cb694 = DAT_002cb694 + 1;
      }
      iVar12 = rsr_ccount(in_CCOUNT);
      puVar6 = DAT_002cb6a4 + (int)DAT_002cb684;
      puVar9 = (undefined *)(iVar12 - (int)DAT_002cb6a4);
      DAT_002cb690 = uVar8;
      DAT_002cb6a4 = puVar6;
    } while (DAT_002cb684 < puVar9);
    puVar9 = DAT_002cb684 + -(int)puVar9;
    puVar6 = puVar9;
    if (puVar9 < (undefined *)((uint)DAT_002cb684 >> 3)) {
      puVar6 = puVar9 + (int)DAT_002cb684;
    }
  }
  else {
    uVar8 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    if ((uVar8 & 0xf) < 2) {
      puVar10 = (undefined *)(uVar8 & 0xfffffff0 | 2);
      uVar3 = wsr_ps(puVar10);
      in_st_PSWOE = (undefined1)uVar3;
      in_st_PSCALLINC = (undefined1)((uint6)uVar3 >> 8);
      in_st_PSOWB = (undefined1)((uint6)uVar3 >> 0x10);
      in_st_PSUM = (undefined1)((uint6)uVar3 >> 0x18);
      in_st_PSEXCM = (undefined1)((uint6)uVar3 >> 0x20);
      in_st_PSINTLEVEL = (undefined1)((uint6)uVar3 >> 0x28);
      rsync();
    }
    uVar11 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL
                   );
    uVar3 = wsr_ps(uVar8 & 0xf | uVar11 & 0xfffffff0);
    in_st_PSWOE = (undefined1)uVar3;
    in_st_PSCALLINC = (undefined1)((uint6)uVar3 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar3 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar3 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar3 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar3 >> 0x28);
    rsync();
    iVar12 = rsr_ccount(in_CCOUNT);
    if (DAT_002cb6a8 != (undefined4 *)0x0) {
      uVar8 = DAT_002cb698 + (iVar12 - DAT_002cb6a0);
      puVar6 = DAT_002cb69c;
      puVar7 = DAT_002cb6a8;
      if (uVar8 < DAT_002cb698) {
        puVar6 = DAT_002cb69c + 1;
      }
      do {
        bVar4 = false;
        if ((puVar6 <= (undefined *)puVar7[3]) &&
           (((undefined *)puVar7[3] != puVar6 || (uVar8 < (uint)puVar7[2])))) {
          bVar4 = true;
        }
        if (bVar4) {
          puVar10 = PTR_DAT_00237a8c;
          if (puVar7 != (undefined4 *)0x0) {
            uVar8 = DAT_002cb698 + (iVar12 - DAT_002cb6a0);
            puVar6 = DAT_002cb69c;
            if (uVar8 < DAT_002cb698) {
              puVar6 = DAT_002cb69c + 1;
            }
            iVar12 = puVar7[3] - (int)puVar6;
            puVar19 = (undefined *)puVar7[2] + -uVar8;
            puVar9 = (undefined *)0x0;
            if ((undefined *)puVar7[2] < puVar19) {
              iVar12 = iVar12 + -1;
            }
            if ((iVar12 == 0) && (puVar19 < PTR_DAT_00237a8c)) {
              puVar9 = (undefined *)0x1;
            }
            if (puVar9 != (undefined *)0x0) {
              iVar12 = 0;
              puVar19 = PTR_DAT_00237a8c;
            }
            puVar6 = (undefined *)0xffffffff;
            if (iVar12 == 0) {
              puVar6 = puVar19;
            }
            goto LAB_00228205;
          }
          break;
        }
        puVar7 = (undefined4 *)*puVar7;
        puVar10 = (undefined *)0x0;
      } while (puVar7 != (undefined4 *)0x0);
    }
    puVar6 = (undefined *)0xffffffff;
    puVar9 = DAT_002cb69c;
  }
LAB_00228205:
  FUN_002292ac(puVar6,puVar9,puVar10);
  iVar12 = rsr_ccount(in_CCOUNT);
  DAT_002cb698 = (iVar12 - DAT_002cb6a0) + DAT_002cb698;
  if (DAT_002cb698 < (uint)(iVar12 - DAT_002cb6a0)) {
    DAT_002cb69c = DAT_002cb69c + 1;
  }
  DAT_00237a90 = DAT_00237a90 + 1;
  DAT_002cb6a0 = iVar12;
  if (DAT_00237a84 <= DAT_00237a90) {
    DAT_00237a90 = 0;
    FUN_002278f8();
  }
  while( true ) {
    puVar7 = DAT_002cb6a8;
    bVar4 = false;
    if (DAT_002cb6a8 == (undefined4 *)0x0) {
      return;
    }
    if ((DAT_002cb69c <= (undefined *)DAT_002cb6a8[3]) &&
       (((undefined *)DAT_002cb6a8[3] != DAT_002cb69c || (DAT_002cb698 < (uint)DAT_002cb6a8[2])))) {
      bVar4 = true;
    }
    if (bVar4) break;
    uVar8 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar3 = wsr_ps(uVar8 & 0xfffffff0 | 2);
    uVar15 = (undefined1)uVar3;
    uVar17 = (undefined1)((uint6)uVar3 >> 8);
    uVar18 = (undefined1)((uint6)uVar3 >> 0x10);
    uVar14 = (undefined1)((uint6)uVar3 >> 0x18);
    uVar16 = (undefined1)((uint6)uVar3 >> 0x20);
    uVar13 = (undefined1)((uint6)uVar3 >> 0x28);
    rsync();
    piVar1 = DAT_002cb6a8 + 4;
    piVar2 = DAT_002cb6a8 + 5;
    bVar4 = false;
    puVar5 = (undefined4 *)*DAT_002cb6a8;
    *DAT_002cb6a8 = 0;
    DAT_002cb6a8 = puVar5;
    if ((*piVar2 != 0) || (*piVar1 != 0)) {
      bVar4 = true;
    }
    uVar11 = puVar7[2] + *piVar1;
    if (bVar4) {
      iVar12 = puVar7[3] + *piVar2;
      if (uVar11 < (uint)puVar7[2]) {
        iVar12 = iVar12 + 1;
      }
      puVar7[3] = iVar12;
      puVar7[2] = uVar11;
      FUN_00228748(puVar7);
    }
    else {
      *(undefined1 *)(puVar7 + 8) = 0;
    }
    uVar11 = rsr_ps(uVar15,uVar17,uVar18,uVar14,uVar16,uVar13);
    uVar3 = wsr_ps(uVar11 & 0xfffffff0 | uVar8 & 0xf);
    in_st_PSWOE = (undefined1)uVar3;
    in_st_PSCALLINC = (undefined1)((uint6)uVar3 >> 8);
    in_st_PSOWB = (undefined1)((uint6)uVar3 >> 0x10);
    in_st_PSUM = (undefined1)((uint6)uVar3 >> 0x18);
    in_st_PSEXCM = (undefined1)((uint6)uVar3 >> 0x20);
    in_st_PSINTLEVEL = (undefined1)((uint6)uVar3 >> 0x28);
    rsync();
    if ((code *)puVar7[6] != (code *)0x0) {
      (*(code *)puVar7[6])(puVar7[7]);
    }
    if (puVar7[9] != 0) {
      FUN_00227be4(puVar7 + 9,"delay",0);
      FUN_00227f58();
    }
  }
  return;
}


// ===== xos_start_system_timer @ 0022835c (115 bytes)

int xos_start_system_timer(undefined4 param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte bVar4;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  undefined4 auStack_30 [12];
  
  uVar2 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  if ((uVar2 & 0x20) == 0) {
    FUN_00226854(0xffff001c,0);
  }
  FUN_00227770();
  iVar1 = FUN_00229340(param_1,auStack_30);
  if (iVar1 == 0) {
    DAT_00237a88 = auStack_30[0];
    DAT_002cb688 = param_2 == 0;
    iVar1 = param_2;
    if ((bool)DAT_002cb688) {
      iVar1 = -1;
    }
    bVar4 = (1 < DAT_00237a84) * DAT_00237a84 + (1 >= DAT_00237a84);
    DAT_00237a84 = (0x32 < bVar4) * '2' + (0x32 >= bVar4) * bVar4;
    iVar3 = rsr_ccount(in_CCOUNT);
    DAT_002cb6a4 = iVar3 + iVar1;
    DAT_002cb684 = param_2;
    FUN_002293ac(iVar1);
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_002283d4 @ 002283d4 (10 bytes)

undefined4 FUN_002283d4(void)

{
  return DAT_00237a88;
}


// ===== FUN_002283e0 @ 002283e0 (263 bytes)

undefined4
FUN_002283e0(int param_1,undefined4 param_2,uint param_3,uint param_4,uint param_5,
            undefined4 param_6,undefined4 param_7)

{
  undefined6 uVar1;
  uint uVar2;
  uint uVar3;
  int iVar4;
  bool bVar5;
  uint uVar6;
  undefined4 in_CCOUNT;
  undefined1 in_st_PSINTLEVEL;
  undefined1 uVar7;
  undefined1 in_st_PSUM;
  undefined1 uVar8;
  undefined1 in_st_PSWOE;
  undefined1 uVar9;
  undefined1 in_st_PSEXCM;
  undefined1 uVar10;
  undefined1 in_st_PSCALLINC;
  undefined1 uVar11;
  undefined1 in_st_PSOWB;
  undefined1 uVar12;
  uint uVar13;
  uint uVar14;
  
  if (param_1 != 0) {
    if (*(char *)(param_1 + 0x20) != '\0') {
      FUN_002284e8(param_1);
    }
    uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL)
    ;
    uVar1 = wsr_ps(uVar6 & 0xfffffff0 | 2);
    uVar9 = (undefined1)uVar1;
    uVar11 = (undefined1)((uint6)uVar1 >> 8);
    uVar12 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar8 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar10 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    uVar2 = rsr_ps(uVar9,uVar11,uVar12,uVar8,uVar10,uVar7);
    if ((uVar2 & 0xf) < 2) {
      uVar1 = wsr_ps(uVar2 & 0xfffffff0 | 2);
      uVar9 = (undefined1)uVar1;
      uVar11 = (undefined1)((uint6)uVar1 >> 8);
      uVar12 = (undefined1)((uint6)uVar1 >> 0x10);
      uVar8 = (undefined1)((uint6)uVar1 >> 0x18);
      uVar10 = (undefined1)((uint6)uVar1 >> 0x20);
      uVar7 = (undefined1)((uint6)uVar1 >> 0x28);
      rsync();
    }
    uVar3 = rsr_ps(uVar9,uVar11,uVar12,uVar8,uVar10,uVar7);
    uVar1 = wsr_ps(uVar2 & 0xf | uVar3 & 0xfffffff0);
    uVar9 = (undefined1)uVar1;
    uVar11 = (undefined1)((uint6)uVar1 >> 8);
    uVar12 = (undefined1)((uint6)uVar1 >> 0x10);
    uVar8 = (undefined1)((uint6)uVar1 >> 0x18);
    uVar10 = (undefined1)((uint6)uVar1 >> 0x20);
    uVar7 = (undefined1)((uint6)uVar1 >> 0x28);
    rsync();
    iVar4 = rsr_ccount(in_CCOUNT);
    uVar3 = DAT_002cb698 + (iVar4 - DAT_002cb6a0);
    uVar2 = DAT_002cb69c;
    if (uVar3 < DAT_002cb698) {
      uVar2 = DAT_002cb69c + 1;
    }
    uVar13 = param_3;
    uVar14 = param_4;
    if ((param_5 >> 1 & 1) == 0) {
      uVar13 = param_3 + uVar3;
      if ((param_5 >> 4 & 1) == 0) {
        uVar14 = param_4 + uVar2;
        if (uVar13 < param_3) {
          uVar14 = param_4 + uVar2 + 1;
        }
      }
      else {
        uVar13 = *(uint *)(param_1 + 8) + param_3;
        uVar14 = *(int *)(param_1 + 0xc) + param_4;
        if (uVar13 < *(uint *)(param_1 + 8)) {
          uVar14 = uVar14 + 1;
        }
      }
    }
    *(uint *)(param_1 + 0xc) = uVar14;
    *(uint *)(param_1 + 8) = uVar13;
    if ((param_5 & 1) == 0) {
      param_3 = 0;
      param_4 = 0;
    }
    *(uint *)(param_1 + 0x14) = param_4;
    *(uint *)(param_1 + 0x10) = param_3;
    *(undefined4 *)(param_1 + 0x18) = param_6;
    *(undefined4 *)(param_1 + 0x1c) = param_7;
    bVar5 = false;
    if ((uVar14 <= uVar2) && ((uVar14 != uVar2 || (uVar13 < uVar3)))) {
      bVar5 = true;
    }
    if (!bVar5) {
      iVar4 = uVar14 - uVar2;
      if (uVar13 < uVar13 - uVar3) {
        iVar4 = iVar4 + -1;
      }
      FUN_00228748(param_1,uVar14,uVar13 - uVar3,iVar4);
      *(undefined1 *)(param_1 + 0x20) = 1;
      uVar2 = rsr_ps(uVar9,uVar11,uVar12,uVar8,uVar10,uVar7);
      wsr_ps(uVar6 & 0xf | uVar2 & 0xfffffff0);
      rsync();
      return 0;
    }
    uVar2 = rsr_ps(uVar9,uVar11,uVar12,uVar8,uVar10,uVar7);
    wsr_ps(uVar6 & 0xf | uVar2 & 0xfffffff0);
    rsync();
  }
  return 0xffff0001;
}


// ===== FUN_002284e8 @ 002284e8 (122 bytes)

int FUN_002284e8(undefined4 *param_1)

{
  undefined6 uVar1;
  int iVar2;
  undefined4 *puVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint uVar6;
  undefined1 in_st_PSINTLEVEL;
  undefined1 in_st_PSUM;
  undefined1 in_st_PSWOE;
  undefined1 in_st_PSEXCM;
  undefined1 in_st_PSCALLINC;
  undefined1 in_st_PSOWB;
  
  if (param_1 == (undefined4 *)0x0) {
    return -0xffff;
  }
  uVar6 = rsr_ps(in_st_PSWOE,in_st_PSCALLINC,in_st_PSOWB,in_st_PSUM,in_st_PSEXCM,in_st_PSINTLEVEL);
  uVar1 = wsr_ps(uVar6 & 0xfffffff0 | 2);
  rsync();
  iVar2 = -0x10000;
  puVar3 = &DAT_002cb6a8;
  if (*(char *)(param_1 + 8) == '\0') {
    iVar2 = 0;
  }
  else {
    do {
      puVar4 = puVar3;
      puVar3 = (undefined4 *)*puVar4;
      if (puVar3 == (undefined4 *)0x0) goto LAB_00228523;
    } while (param_1 != puVar3);
    *puVar4 = *puVar3;
    iVar2 = 0;
    *(undefined1 *)(param_1 + 8) = 0;
    *param_1 = 0;
  }
LAB_00228523:
  uVar5 = rsr_ps((char)uVar1,(char)((uint6)uVar1 >> 8),(char)((uint6)uVar1 >> 0x10),
                 (char)((uint6)uVar1 >> 0x18),(char)((uint6)uVar1 >> 0x20),
                 (char)((uint6)uVar1 >> 0x28));
  wsr_ps(uVar5 & 0xfffffff0 | uVar6 & 0xf);
  rsync();
  if ((iVar2 == 0) && (param_1[9] != 0)) {
    FUN_00227be4(param_1 + 9,"delay",0xffff000f,0xfffffff0,uVar6 & 0xf);
    FUN_00227f58();
  }
  return iVar2;
}

