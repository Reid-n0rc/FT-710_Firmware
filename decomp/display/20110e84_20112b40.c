// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_20110e84 @ 20110e84 (12 bytes)

undefined4 FUN_20110e84(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}


// ===== FUN_20110e90 @ 20110e90 (48 bytes)

int FUN_20110e90(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_20110e84();
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_20110ec0 @ 20110ec0 (20 bytes)

void FUN_20110ec0(undefined4 param_1)

{
  FUN_20110e90(param_1);
  return;
}


// ===== FUN_20110ed4 @ 20110ed4 (56 bytes)

void FUN_20110ed4(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_20112e5c(&DAT_20819500,param_1,param_2);
  if (iVar1 != 0) {
    FUN_2015f0ec(&DAT_208193fc,iVar1);
  }
  return;
}


// ===== FUN_20110f0c @ 20110f0c (344 bytes)

undefined4 FUN_20110f0c(void)

{
  undefined4 uVar1;
  int iVar2;
  undefined *local_2c;
  undefined4 local_28;
  undefined4 local_24;
  undefined4 local_20;
  undefined4 local_1c;
  
  iVar2 = DAT_fcff400c;
  if (iVar2 == -0x55443323) {
    iVar2 = FUN_20103e74(0,0,0x340000);
    if (iVar2 == 0) {
      iVar2 = FUN_20103e74(0,0x3e0000,0x14);
      if (iVar2 == 0) {
        iVar2 = FUN_20103e74(0,0x3f0000,0x14);
        if (iVar2 == 0) {
          iVar2 = FUN_20103dd0(0,vec_reset,0x340000);
          if (iVar2 == 0) {
            local_28 = 0;
            local_24 = 0;
            local_20 = 0;
            local_1c = 0;
            local_2c = &DAT_20182018;
            iVar2 = FUN_20103dd0(0x3e0000,&local_2c,0x14);
            if (iVar2 == 0) {
              iVar2 = FUN_20103dd0(0x3f0000,&local_2c,0x14);
              if (iVar2 == 0) {
                uVar1 = 0;
                DAT_fcff400c = 0;
                software_bkpt(0);
              }
              else {
                software_bkpt(4);
                uVar1 = 4;
              }
            }
            else {
              software_bkpt(3);
              uVar1 = 3;
            }
          }
          else {
            software_bkpt(2);
            uVar1 = 2;
          }
        }
        else {
          software_bkpt(1);
          uVar1 = 1;
        }
      }
      else {
        software_bkpt(1);
        uVar1 = 1;
      }
    }
    else {
      software_bkpt(1);
      uVar1 = 1;
    }
  }
  else {
    uVar1 = 0;
  }
  return uVar1;
}


// ===== FUN_20111064 @ 20111064 (20 bytes)

code * FUN_20111064(void)

{
  FUN_2015f55c(&DAT_208193fc);
  return FUN_20110ed4;
}


// ===== FUN_20111098 @ 20111098 (28 bytes)

bool FUN_20111098(void)

{
  return DAT_20450000 == -0x5f463719;
}


// ===== FUN_201110cc @ 201110cc (144 bytes)

void FUN_201110cc(uint *param_1)

{
  ushort uVar1;
  ushort uVar2;
  ushort uVar3;
  ushort uVar4;
  ushort uVar5;
  ushort uVar6;
  ushort uVar7;
  
  uVar1 = DAT_e8005800;
  uVar2 = DAT_e8005802;
  uVar3 = DAT_e8005804;
  uVar4 = DAT_e8005806;
  DAT_20819530 = (uint)(uVar4 >> 4);
  uVar4 = DAT_e8005808;
  uVar5 = DAT_e800580a;
  uVar6 = DAT_e800580c;
  uVar7 = DAT_e800580e;
  DAT_20819524 = (uint)(uVar1 >> 4);
  DAT_20819528 = (uint)(uVar2 >> 4);
  DAT_2081952c = (uint)(uVar3 >> 4);
  DAT_20819534 = (uint)(uVar4 >> 4);
  DAT_20819538 = (uint)(uVar5 >> 4);
  DAT_2081953c = (uint)(uVar6 >> 4);
  DAT_20819540 = (uint)(uVar7 >> 4);
  param_1[3] = DAT_20819530;
  param_1[4] = (uint)(uVar4 >> 4);
  param_1[6] = (uint)(uVar6 >> 4);
  param_1[7] = (uint)(uVar7 >> 4);
  param_1[5] = (uint)(uVar5 >> 4);
  param_1[2] = (uint)(uVar3 >> 4);
  *param_1 = (uint)(uVar1 >> 4);
  param_1[1] = (uint)(uVar2 >> 4);
  return;
}


// ===== FUN_2011115c @ 2011115c (16 bytes)

void FUN_2011115c(void)

{
  DAT_e8005860 = 0x20ff;
  return;
}


// ===== FUN_20111174 @ 20111174 (52 bytes)

undefined * FUN_20111174(int param_1)

{
  if (param_1 < 0) {
    memclr(&DAT_20819560,0xc0000);
  }
  else if (param_1 != 0) {
    memclr(&DAT_20819560,param_1);
  }
  return &DAT_20819560;
}


// ===== FUN_201111c8 @ 201111c8 (12 bytes)

undefined4 FUN_201111c8(void)

{
  undefined4 uVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  uVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  return uVar1;
}


// ===== FUN_201111d4 @ 201111d4 (48 bytes)

int FUN_201111d4(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_201111c8();
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_20111204 @ 20111204 (20 bytes)

void FUN_20111204(undefined4 param_1)

{
  FUN_201111d4(param_1);
  return;
}


// ===== FUN_20111218 @ 20111218 (12 bytes)

void FUN_20111218(undefined4 param_1)

{
  DAT_208001c8 = param_1;
  return;
}


// ===== FUN_20111224 @ 20111224 (76 bytes)

void FUN_20111224(byte param_1,byte param_2)

{
  DAT_2080010c = DAT_2080010c & ~(param_2 & 7) | param_1 & 7;
  FUN_2013baac(DAT_208001c8,0,&DAT_2080010c);
  itron_dly_tsk(1);
  return;
}


// ===== FUN_20111270 @ 20111270 (68 bytes)

void FUN_20111270(byte param_1,byte param_2)

{
  DAT_2080010c = DAT_2080010c & ~(param_2 & 7) | param_1 & 7;
  FUN_2013baac(DAT_208001c8,0,&DAT_2080010c);
  return;
}


// ===== FUN_201112b4 @ 201112b4 (192 bytes)

uint FUN_201112b4(byte *param_1,int param_2,undefined4 *param_3)

{
  uint uVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  uVar1 = 0;
  *param_3 = param_1;
  for (iVar3 = 0; pbVar4 = param_1, iVar3 < param_2; iVar3 = iVar3 + 1) {
    pbVar4 = param_1 + 1;
    uVar2 = (uint)*param_1;
    if (uVar2 == 0) break;
    if ((uVar2 < 0x30) || (0x39 < uVar2)) {
      if ((uVar2 < 0x41) || (0x46 < uVar2)) {
        if ((uVar2 < 0x61) || (0x66 < uVar2)) {
          *param_3 = param_1;
          return uVar1;
        }
        uVar1 = uVar1 << 4 | uVar2 - 0x57;
      }
      else {
        uVar1 = uVar1 << 4 | uVar2 - 0x37;
      }
    }
    else {
      uVar1 = uVar1 << 4 | uVar2 - 0x30;
    }
    param_1 = pbVar4;
  }
  *param_3 = pbVar4;
  return uVar1;
}


// ===== FUN_20111374 @ 20111374 (132 bytes)

int FUN_20111374(byte *param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  byte *pbVar4;
  
  iVar1 = 0;
  *param_3 = param_1;
  for (iVar3 = 0; pbVar4 = param_1, iVar3 < param_2; iVar3 = iVar3 + 1) {
    pbVar4 = param_1 + 1;
    uVar2 = (uint)*param_1;
    if (uVar2 == 0) break;
    if ((uVar2 < 0x30) || (0x39 < uVar2)) {
      *param_3 = param_1;
      return iVar1;
    }
    iVar1 = iVar1 * 10 + (uVar2 - 0x30);
    param_1 = pbVar4;
  }
  *param_3 = pbVar4;
  return iVar1;
}


// ===== FUN_20111410 @ 20111410 (88 bytes)

void FUN_20111410(void)

{
  DAT_208001d4 = DAT_208001d4 ^ 1;
  if (DAT_208001d4 == 0) {
    DAT_208001d5 = 0;
    DAT_208001dc = 0;
    DAT_208001e0 = 0;
  }
  DAT_208001d8 = fb_get_layer_addr(4);
  return;
}


// ===== FUN_20111468 @ 20111468 (24 bytes)

void FUN_20111468(void)

{
  DAT_208001d5 = DAT_208001d5 ^ 1;
  return;
}


// ===== FUN_20111480 @ 20111480 (268 bytes)

void FUN_20111480(undefined4 param_1,uint param_2)

{
  undefined4 uVar1;
  undefined1 *puVar2;
  undefined1 local_18;
  undefined1 uStack_17;
  undefined1 uStack_16;
  undefined1 uStack_15;
  
  uVar1 = DAT_208001cc;
  if (((DAT_208001d8 != 0) && (DAT_208001d5 != '\0')) && (DAT_208001d6 == '\0')) {
    if (0xfb < param_2) {
      param_2 = 0xfc;
    }
    puVar2 = (undefined1 *)(DAT_208001d8 + DAT_208001dc * 0x100);
    local_18 = (undefined1)DAT_208001cc;
    *puVar2 = local_18;
    uStack_17 = (undefined1)((uint)uVar1 >> 8);
    puVar2[1] = uStack_17;
    uStack_16 = (undefined1)((uint)uVar1 >> 0x10);
    puVar2[2] = uStack_16;
    uStack_15 = (undefined1)((uint)uVar1 >> 0x18);
    puVar2[3] = uStack_15;
    memcpy(DAT_208001d8 + DAT_208001dc * 0x100 + 4,param_1,param_2);
    DAT_208001dc = DAT_208001dc + 1 & 0x7ff;
    if (DAT_208001e0 < 0x800) {
      DAT_208001e0 = DAT_208001e0 + 1;
    }
  }
  return;
}


// ===== FUN_2011158c @ 2011158c (444 bytes)

void FUN_2011158c(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  int iVar4;
  int iVar5;
  uint uVar6;
  int *piVar7;
  uint uVar8;
  int iVar9;
  undefined4 uVar10;
  undefined1 auStack_380 [68];
  int local_33c;
  undefined1 auStack_338 [788];
  
  uVar1 = DAT_208001e0;
  if (DAT_208001d8 != 0) {
    DAT_208001d6 = 1;
    if (DAT_208001e0 != 0) {
      uVar2 = DAT_208001dc;
      if (DAT_208001e0 < 0x800) {
        uVar2 = 0;
      }
      sprintf(auStack_380,"I:\\debug_1.log");
      local_33c = fs_fopen(auStack_380,&DAT_2011177c);
      if (local_33c != 0) {
        iVar4 = 0;
        for (uVar8 = 0; uVar8 < uVar1; uVar8 = uVar8 + 1) {
          uVar10 = 0x2f4;
          piVar7 = (int *)(DAT_208001d8 + uVar2 * 0x100);
          uVar2 = uVar2 + 1 & 0x7ff;
          iVar9 = *piVar7;
          sprintf(auStack_338,"%-6d: ",iVar9 - iVar4);
          uVar3 = FUN_20155122(auStack_338);
          iVar4 = fs_fwrite(auStack_338,1,uVar3,local_33c,uVar10);
          iVar5 = FUN_20155122(auStack_338);
          if (iVar5 != iVar4) break;
          for (uVar6 = 0; uVar6 < 0xfc; uVar6 = uVar6 + 1) {
            sprintf(auStack_338 + uVar6 * 3,"%02X ",*(undefined1 *)((int)piVar7 + uVar6 + 4));
          }
          iVar4 = fs_fwrite(auStack_338,1,0x2f4,local_33c);
          if ((iVar4 != 0x2f4) || (iVar4 = fs_fwrite(FUN_20111790,1,2,local_33c), iVar4 != 2))
          break;
          iVar4 = iVar9;
        }
        FUN_20141ff0(local_33c);
      }
    }
    DAT_208001d6 = 0;
  }
  return;
}


// ===== FUN_20111790 @ 20111790 (772 bytes)

void FUN_20111790(void)

{
  undefined1 uVar1;
  int iVar2;
  uint uVar3;
  undefined4 local_18;
  undefined1 auStack_14 [4];
  undefined1 local_10;
  undefined1 local_f;
  undefined1 local_e;
  int local_c;
  undefined *local_8;
  uint local_4;
  
  do {
    while( true ) {
      while( true ) {
        while( true ) {
          do {
            local_18 = 0xffffffff;
            itron_twai_flg(DAT_208001d0,0xffff,5,&local_4);
          } while (local_4 == 1);
          if (local_4 != 2) break;
          local_8 = &DAT_208d9960;
          iVar2 = FUN_2014e320(&DAT_208d9960," ",&local_8);
          if ((iVar2 != 0) && (iVar2 = strcmp(iVar2,"date"), iVar2 == 0)) {
            iVar2 = FUN_2014e320(local_8," ",&local_8);
            if (iVar2 == 0) {
              FUN_20114528(&local_10,auStack_14,&local_18);
            }
            else {
              uVar3 = FUN_201112b4(iVar2,6,&local_c);
              if (local_c != iVar2) {
                FUN_20114564((uVar3 & 0xffffff) >> 0x10,(uVar3 & 0xffff) >> 8,uVar3 & 0xff);
              }
            }
          }
        }
        if (local_4 != 4) break;
        local_8 = &DAT_208d9960;
        iVar2 = FUN_2014e320(&DAT_208d9960," ",&local_8);
        if ((iVar2 != 0) && (iVar2 = strcmp(iVar2,&DAT_20111aa4), iVar2 == 0)) {
          iVar2 = FUN_2014e320(local_8," ",&local_8);
          if (iVar2 == 0) {
            FUN_2011459c(&local_10,auStack_14,&local_18);
          }
          else {
            uVar3 = FUN_201112b4(iVar2,6,&local_c);
            if (local_c != iVar2) {
              FUN_201145d8((uVar3 & 0xffffff) >> 0x10,(uVar3 & 0xffff) >> 8,uVar3 & 0xff);
            }
          }
        }
      }
      if (local_4 != 8) break;
      local_8 = &DAT_208d9960;
      iVar2 = FUN_2014e320(&DAT_208d9960," ",&local_8);
      if ((((iVar2 != 0) && (iVar2 = strcmp(iVar2,&DAT_20111aac), iVar2 == 0)) &&
          (iVar2 = FUN_2014e320(local_8," ",&local_8), iVar2 != 0)) &&
         ((uVar1 = FUN_201112b4(iVar2,2,&local_c), local_c != iVar2 &&
          (iVar2 = FUN_2014e320(local_8," ",&local_8), iVar2 != 0)))) {
        uVar3 = FUN_201112b4(iVar2,4,&local_c);
        if (local_c != iVar2) {
          local_f = (undefined1)(uVar3 & 0xffff);
          local_e = (undefined1)((uVar3 & 0xffff) >> 8);
          local_10 = uVar1;
          FUN_20114e88(&local_10,3);
        }
      }
    }
    if ((local_4 & 0xe000) != 0) {
      if ((local_4 & 0x2000) != 0) {
        FUN_20111410();
      }
      if (local_4 == 0x4000) {
        FUN_20111468();
      }
      if (local_4 == 0x8000) {
        FUN_2011158c();
      }
    }
  } while( true );
}


// ===== FUN_20111ab0 @ 20111ab0 (1368 bytes)

void FUN_20111ab0(undefined4 param_1,int param_2)

{
  char cVar1;
  int iVar2;
  int iVar3;
  
  cVar1 = *(char *)(param_2 + 0xc);
  if ((cVar1 != '\0') || (*(char *)(param_2 + 5) != '\0')) {
    iVar2 = FUN_20112e5c(&DAT_208d9980,param_1,param_2);
    if (cVar1 == ':') {
      if ((DAT_20808a84 & 1) == 0) {
        DAT_20808a84 = DAT_20808a84 | 1;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffffe;
      }
    }
    else if (cVar1 == ';') {
      if ((DAT_20808a84 & 2) == 0) {
        DAT_20808a84 = DAT_20808a84 | 2;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffffd;
      }
    }
    else if (cVar1 == '<') {
      if ((DAT_20808a84 & 4) == 0) {
        DAT_20808a84 = DAT_20808a84 | 4;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffffb;
      }
    }
    else if (cVar1 == '=') {
      if ((DAT_20808a84 & 8) == 0) {
        DAT_20808a84 = DAT_20808a84 | 8;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffff7;
      }
    }
    else if (cVar1 == '>') {
      if ((DAT_20808a84 & 0x10) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x10;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffffef;
      }
    }
    else if (cVar1 == '?') {
      if ((DAT_20808a84 & 0x20) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x20;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffffdf;
      }
      itron_set_flg(DAT_208001d0,0x2000);
    }
    else if (cVar1 == '@') {
      if ((DAT_20808a84 & 0x40) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x40;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffffbf;
      }
      itron_set_flg(DAT_208001d0,0x4000);
    }
    else if (cVar1 == 'A') {
      if ((DAT_20808a84 & 0x80) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x80;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xffffff7f;
      }
      itron_set_flg(DAT_208001d0,0x8000);
    }
    else if (cVar1 == 'B') {
      if ((DAT_20808a84 & 0x100) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x100;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffeff;
      }
    }
    else if (cVar1 == 'C') {
      if ((DAT_20808a84 & 0x200) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x200;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffdff;
      }
    }
    else if (cVar1 == 'D') {
      if ((DAT_20808a84 & 0x400) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x400;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffffbff;
      }
    }
    else if (cVar1 == 'E') {
      if ((DAT_20808a84 & 0x800) == 0) {
        DAT_20808a84 = DAT_20808a84 | 0x800;
      }
      else {
        DAT_20808a84 = DAT_20808a84 & 0xfffff7ff;
      }
    }
    else if ((iVar2 == 0) || (iVar3 = strncmp("date",iVar2,4), iVar3 != 0)) {
      if ((iVar2 == 0) || (iVar3 = strncmp(&DAT_20112018,iVar2,4), iVar3 != 0)) {
        if ((iVar2 == 0) || (iVar3 = strncmp(&DAT_20112020,iVar2,4), iVar3 != 0)) {
          if ((iVar2 == 0) || (iVar3 = strcmp("reset",iVar2), iVar3 != 0)) {
            if ((iVar2 == 0) || (iVar3 = strcmp(&DAT_20112030,iVar2), iVar3 != 0)) {
              if ((iVar2 != 0) && (iVar2 = strncmp(&DAT_20112034,iVar2,4), iVar2 == 0)) {
                iVar2 = FUN_201351ac();
                if (iVar2 == 2) {
                  FUN_2013518c();
                }
                else {
                  FUN_2013519c();
                }
              }
            }
            else {
              FUN_20100268();
            }
          }
          else {
            FUN_20114df4();
          }
        }
        else {
          memcpy(&DAT_208d9960,iVar2,0x20);
          itron_set_flg(DAT_208001d0,8);
        }
      }
      else {
        memcpy(&DAT_208d9960,iVar2,0x20);
        itron_set_flg(DAT_208001d0,4);
      }
    }
    else {
      memcpy(&DAT_208d9960,iVar2,0x20);
      itron_set_flg(DAT_208001d0,2);
    }
  }
  return;
}


// ===== FUN_2011203c @ 2011203c (120 bytes)

code * FUN_2011203c(void)

{
  code *pcVar1;
  int iVar2;
  
  DAT_208001d0 = itron_acre_flg(0,&DAT_20165548);
  if (DAT_208001d0 < 1) {
    pcVar1 = (code *)0x0;
  }
  else {
    iVar2 = itron_acre_tsk(0,&DAT_2016552c);
    if (iVar2 < 1) {
      pcVar1 = (code *)0x0;
    }
    else {
      iVar2 = itron_sta_tsk(iVar2,0);
      if (iVar2 == 0) {
        pcVar1 = FUN_20111ab0;
      }
      else {
        pcVar1 = (code *)0x0;
      }
    }
  }
  return pcVar1;
}


// ===== FUN_201120c8 @ 201120c8 (48 bytes)

int FUN_201120c8(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== FUN_201120fc @ 201120fc (16 bytes)

void FUN_201120fc(undefined4 param_1)

{
  memcpy(&DAT_60501b64,param_1,0x97);
  return;
}


// ===== FUN_2011210c @ 2011210c (28 bytes)

void FUN_2011210c(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_20120dc8();
  memcpy(&DAT_605016a4,uVar1,600);
  return;
}


// ===== FUN_20112128 @ 20112128 (28 bytes)

void FUN_20112128(void)

{
  undefined4 uVar1;
  
  uVar1 = FUN_201344a0();
  memcpy(&DAT_60501000,uVar1,0x352);
  return;
}


// ===== FUN_20112144 @ 20112144 (20 bytes)

void FUN_20112144(void)

{
  DAT_60501ff0 = 0x1ee01ff;
  DAT_60501ff4 = 0x1ee01ff;
  DAT_60501ff8 = 0x1ee01ff;
  DAT_60501ffc = 0x1ee01ff;
  return;
}


// ===== FUN_20112158 @ 20112158 (60 bytes)

void FUN_20112158(void)

{
  DAT_e8200440 = &DAT_60501000;
  DAT_e8200444 = 0xe800c804;
  DAT_e8200448 = 0x1000;
  FUN_20157160(&DAT_e8200468,1,0);
  return;
}


// ===== FUN_20112180 @ 20112180 (40 bytes)

void FUN_20112180(void)

{
  thunk_FUN_201120c8(&DAT_2045d490);
  DAT_20450014 = DAT_20450014 + 1;
  FUN_20137e00();
  FUN_20112158();
  return;
}


// ===== FUN_201121a8 @ 201121a8 (12 bytes)

void FUN_201121a8(undefined4 param_1)

{
  DAT_20450004 = param_1;
  return;
}


// ===== FUN_201121b4 @ 201121b4 (128 bytes)

void FUN_201121b4(void)

{
  int iVar1;
  undefined4 local_10;
  
  local_10 = 0xeeafccba;
  iVar1 = FUN_2015507c(&DAT_60500000,&local_10,4);
  if (iVar1 != 0) {
    DAT_2045d4ac = DAT_2045d4ac + 1;
    return;
  }
  DAT_2045d4a8 = DAT_2045d4a8 + 1;
  DAT_2045d4b4 = DAT_60500000;
  DAT_2045d4b8 = DAT_60500004;
  DAT_2045d4bc = DAT_60500008;
  DAT_2045d4c0 = DAT_6050000c;
  DAT_2045d4c4 = DAT_60500010;
  DAT_2045d4c8 = DAT_60500014;
  DAT_2045d4cc = DAT_60500018;
  DAT_2045d4d0 = DAT_6050001c;
  DAT_2045d4dc = DAT_60500028;
  DAT_2045d4d4 = DAT_60500020;
  DAT_2045d4d8 = DAT_60500024;
  return;
}


// ===== FUN_20112264 @ 20112264 (36 bytes)

void FUN_20112264(void)

{
  FUN_201121b4();
  DAT_20450018 = DAT_20450018 + 1;
  FUN_20137e54();
  FUN_20137e40();
  return;
}


// ===== FUN_20112288 @ 20112288 (456 bytes)

void FUN_20112288(void)

{
  bool bVar1;
  bool bVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  bool bVar7;
  
  FUN_20137904();
  FUN_20137e00();
  FUN_20137910(1,0,0);
  FUN_20137e34(FUN_20112180);
  FUN_2011d9a8(0,1);
  FUN_2011f7b4(0);
  FUN_2011f138(0);
  FUN_20112158();
  iVar6 = DAT_20450014;
  iVar5 = 0;
  bVar1 = true;
  iVar4 = 0;
  bVar2 = false;
  FUN_20112144();
  do {
    do {
      itron_dly_tsk(1);
      if ((!bVar2) && (DAT_20450004 != 0)) {
        bVar2 = true;
        FUN_20137af8();
        FUN_20137e88(FUN_20112264);
        FUN_20137e00();
        FUN_20137e54();
        FUN_2011f1ac(0);
        FUN_2011f7b4(0);
        FUN_20137910(1,0,0);
        FUN_20137b04(1,&DAT_e800c804,&DAT_60500000,0x1000);
        DAT_2045d4a8 = 0;
        DAT_2045d4ac = 0;
        DAT_2045d4b0 = 0;
        FUN_20137e40();
        FUN_20112158();
        itron_dly_tsk(0x32);
        FUN_2011f138(0);
      }
      iVar4 = iVar4 + 1;
      if (iVar4 == 4) {
        thunk_FUN_201120c8(&DAT_2045d498);
        iVar4 = 0;
        FUN_2011210c();
        FUN_20112128();
      }
      iVar5 = iVar5 + 1;
    } while (iVar5 != 0x32);
    thunk_FUN_201120c8(&DAT_2045d4a0);
    iVar3 = DAT_20450014;
    iVar5 = 0;
    bVar7 = iVar6 != DAT_20450014;
    if (bVar7) {
      bVar1 = false;
    }
    iVar6 = iVar3;
    if (!bVar7 && !bVar1) {
      bVar1 = true;
      FUN_20137e00();
      if (bVar2) {
        FUN_20137e54();
      }
      FUN_2011f1ac(0);
      FUN_2011f7b4(0);
      FUN_20137910(1,0,0);
      if (bVar2) {
        FUN_20137b04(1,&DAT_e800c804,&DAT_60500000,0x1000);
        DAT_2045d4a8 = 0;
        DAT_2045d4ac = 0;
        DAT_2045d4b0 = 0;
        FUN_20137e40();
      }
      FUN_20112158();
      FUN_2011f138(0);
    }
  } while( true );
}


// ===== FUN_20112450 @ 20112450 (40 bytes)

void FUN_20112450(void)

{
  int iVar1;
  
  iVar1 = itron_acre_tsk(0,&DAT_20165554);
  if (0 < iVar1) {
    itron_sta_tsk(iVar1,0);
    return;
  }
  return;
}


// ===== FUN_20112478 @ 20112478 (36 bytes)

void FUN_20112478(void)

{
  FUN_20135dd4();
  return;
}


// ===== sdr_spi_stats_print @ 2011249c (572 bytes)

/* CS_POLL / MOSI_OK/NG / MISO_OK/NG / FRAMES */

void sdr_spi_stats_print(undefined4 param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined1 auStack_a0 [128];
  
  if (DAT_20450004 != 0) {
    uVar2 = 0x400;
    iVar1 = FUN_201008ac(2,0xd);
    if (DAT_20450008 != iVar1) {
      DAT_2045d4b0 = DAT_2045d4b0 + 1;
    }
    if ((((DAT_2045d4a8 == 0) || (DAT_2045d4ac != 0)) || (DAT_2045d4bc == 0)) ||
       ((DAT_2045d4c0 != 0 || (DAT_2045d4b0 == 0)))) {
      uVar2 = 0xc800;
    }
    DAT_20450008 = iVar1;
    fb_fill_rect(param_1,uVar2,0x104,600,200,0xaf);
    DAT_20450010 = DAT_20450010 + 1;
    if (DAT_20450010 == 0x14) {
      DAT_20450010 = 0;
      DAT_2045000c = DAT_2045d490;
    }
    sprintf(auStack_a0,"testmode");
    FUN_20112478(param_1,auStack_a0,0x109,0x25d);
    sprintf(auStack_a0," CS_POLL=%u\n",DAT_2045d4b0);
    FUN_20112478(param_1,auStack_a0,0x11d,0x25d);
    sprintf(auStack_a0," MOSI_OK=%u",DAT_2045d4a8);
    FUN_20112478(param_1,auStack_a0,0x131,0x25d);
    sprintf(auStack_a0," MOSI_NG=%u",DAT_2045d4ac);
    FUN_20112478(param_1,auStack_a0,0x145,0x25d);
    sprintf(auStack_a0," FRAMES =%u",DAT_2045d4b8);
    FUN_20112478(param_1,auStack_a0,0x163,0x25d);
    sprintf(auStack_a0," MISO_OK=%u",DAT_2045d4bc);
    FUN_20112478(param_1,auStack_a0,0x177,0x25d);
    sprintf(auStack_a0," MISO_NG=%u",DAT_2045d4c0);
    FUN_20112478(param_1,auStack_a0,0x18b,0x25d);
    sprintf(auStack_a0," msec=%u",(uint)(DAT_2045000c * 1000) / 6000000);
    FUN_20112478(param_1,auStack_a0,0x19f,0x25d);
  }
  return;
}


// ===== FUN_2011275c @ 2011275c (24 bytes)

void FUN_2011275c(int param_1,undefined1 param_2)

{
  (&DAT_208d99a4)[param_1 * 5] = (char)param_1;
  (&DAT_208d99a5)[param_1 * 5] = param_2;
  return;
}


// ===== FUN_20112778 @ 20112778 (92 bytes)

void FUN_20112778(void)

{
  int iVar1;
  int unaff_r4;
  int local_4;
  
  do {
    do {
      do {
        iVar1 = itron_twai_flg(*(undefined4 *)(unaff_r4 + 0x14),1,5,&local_4,0xffffffff);
      } while (iVar1 != 0);
    } while (local_4 != 1);
    if (DAT_20800495 != '\0') {
      FUN_20115b04(&DAT_208d99b3);
    }
    FUN_2011775c(0x24);
  } while( true );
}


// ===== FUN_201127d8 @ 201127d8 (88 bytes)

void FUN_201127d8(int param_1)

{
  DAT_208001fc = *(short *)(param_1 + 0x86);
  if (DAT_208001fc != DAT_208001fe) {
    FUN_2011275c(1,(int)(char)((char)DAT_208001fc - (char)DAT_208001fe));
    DAT_208001fe = DAT_208001fc;
    if (DAT_20800495 != '\0') {
      FUN_20115b04(&DAT_208d99a9);
      return;
    }
  }
  return;
}


// ===== FUN_20112834 @ 20112834 (96 bytes)

void FUN_20112834(int param_1)

{
  DAT_20800202 = *(short *)(param_1 + 6);
  if (DAT_20800202 != DAT_20800204) {
    FUN_2011275c(2,(int)(char)((char)DAT_20800202 - (char)DAT_20800204));
    DAT_20800204 = DAT_20800202;
    DAT_20808536 = DAT_20800202;
    if (DAT_20800495 != '\0') {
      FUN_20115b04(&DAT_208d99ae);
      return;
    }
  }
  return;
}


// ===== FUN_20112894 @ 20112894 (8 bytes)

undefined8 FUN_20112894(int param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = 0;
  iVar5 = 0;
  if (0 < DAT_208001f4) {
    do {
      iVar1 = iVar5 * 2;
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + (uint)*(ushort *)(param_1 + iVar1);
    } while (iVar5 < DAT_208001f4);
  }
  uVar3 = __aeabi_uidivmod(iVar2);
  uVar6 = uVar3 & 0x80000000;
  if ((int)uVar6 < 0) {
    uVar3 = -uVar3;
  }
  uVar4 = uVar3 << LZCOUNT(uVar3);
  if (uVar4 == 0) {
    return 0;
  }
  return CONCAT44(uVar6 + (0x41d - LZCOUNT(uVar3)) * 0x100000 + (uVar4 >> 0xb),uVar4 << 0x15);
}


// ===== FUN_2011289c @ 2011289c (68 bytes)

undefined8 FUN_2011289c(undefined4 param_1,int param_2,undefined4 param_3,int param_4)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int iVar5;
  uint uVar6;
  
  iVar2 = 0;
  iVar5 = 0;
  if (0 < *(int *)(param_2 + 0x10)) {
    do {
      iVar1 = iVar5 * 2;
      iVar5 = iVar5 + 1;
      iVar2 = iVar2 + (uint)*(ushort *)(param_4 + iVar1);
    } while (iVar5 < *(int *)(param_2 + 0x10));
  }
  uVar3 = __aeabi_uidivmod(iVar2);
  uVar6 = uVar3 & 0x80000000;
  if ((int)uVar6 < 0) {
    uVar3 = -uVar3;
  }
  uVar4 = uVar3 << LZCOUNT(uVar3);
  if (uVar4 == 0) {
    return 0;
  }
  return CONCAT44(uVar6 + (0x41d - LZCOUNT(uVar3)) * 0x100000 + (uVar4 >> 0xb),uVar4 << 0x15);
}


// ===== FUN_201128d8 @ 201128d8 (28 bytes)

int FUN_201128d8(int param_1,int param_2,int param_3)

{
  if (0xe < (param_2 - param_1) + 7U) {
    param_3 = param_1;
  }
  return param_3;
}


// ===== FUN_201128f8 @ 201128f8 (116 bytes)

void FUN_201128f8(undefined4 param_1)

{
  undefined4 uVar1;
  uint uVar2;
  uint uVar3;
  undefined1 local_20 [32];
  
  uVar3 = 0;
  FUN_20155274(param_1,0x20);
  FUN_20155274(&DAT_208d99c8,0x20);
  do {
    do {
      FUN_201525f8(0xffffffff);
      FUN_201110cc(local_20);
      uVar1 = local_20._0_4_;
      FUN_201110cc(local_20);
      (&DAT_208d9a08)[uVar3] = (short)uVar1;
      (&DAT_208d99c8)[uVar3] = (short)local_20._4_4_;
      uVar2 = uVar3 + 1;
      uVar3 = uVar2 & 0x1f;
    } while ((int)uVar2 <= (int)DAT_208001f4);
    DAT_208001f4 = uVar2;
  } while( true );
}


// ===== FUN_2011296c @ 2011296c (360 bytes)

void FUN_2011296c(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  undefined8 uVar4;
  
  uVar4 = FUN_20112894(&DAT_208d9a08);
  FUN_20164888((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
  uVar1 = FUN_20164cf0();
  uVar4 = FUN_20112894(&DAT_208d99c8);
  FUN_20164888((int)uVar4,(int)((ulonglong)uVar4 >> 0x20),0,0x3fe00000);
  uVar2 = FUN_20164cf0();
  uVar3 = FUN_201128d8(uVar1,DAT_208001ea,DAT_208001ee);
  DAT_208001f0 = FUN_201128d8(uVar2,DAT_208001ec,DAT_208001f0);
  DAT_2080020e = uVar1 >> 4;
  DAT_20800208 = uVar2 >> 4;
  DAT_208001ea = uVar1;
  DAT_208001ec = uVar2;
  DAT_208001ee = uVar3;
  if ((DAT_20800208 != DAT_2080020a) &&
     (DAT_208001e5 = DAT_208001e5 + '\x01', DAT_208001e5 == '\x02')) {
    if ((DAT_208001e7 != '\0') && (FUN_2011275c(4,(int)(char)DAT_20800208), DAT_20800495 != '\0')) {
      FUN_20115b04(&DAT_208d99b8);
    }
    DAT_208001e7 = '\x01';
    DAT_2080020a = DAT_20800208;
    DAT_208001e5 = '\0';
  }
  if ((DAT_2080020e != DAT_20800210) &&
     (DAT_208001e6 = DAT_208001e6 + '\x01', DAT_208001e6 == '\x02')) {
    if ((DAT_208001e8 != '\0') && (FUN_2011275c(5,(int)(char)DAT_2080020e), DAT_20800495 != '\0')) {
      FUN_20115b04(&DAT_208d99bd);
    }
    DAT_208001e8 = '\x01';
    DAT_20800210 = DAT_2080020e;
    DAT_208001e6 = '\0';
  }
  return;
}


// ===== FUN_20112aec @ 20112aec (84 bytes)

void FUN_20112aec(void)

{
  byte bVar1;
  
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 & 0xfd;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 & 0xfb;
  DAT_fcff0381 = 4;
  DAT_fcff0386 = 0;
  DAT_fcff0001 = 7;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 4;
  bVar1 = DAT_fcff0280;
  DAT_fcff0280 = bVar1 | 2;
  return;
}


// ===== FUN_20112b40 @ 20112b40 (120 bytes)

void FUN_20112b40(void)

{
  ushort uVar1;
  ushort uVar2;
  undefined2 uVar3;
  char cVar4;
  undefined4 extraout_r2;
  
  FUN_201177a0(0x24);
  uVar1 = DAT_fcfe320c;
  uVar2 = DAT_fcfe320c;
  if ((uVar1 & 0xf) >> 3 == (uVar2 & 0x3f) >> 5) {
    cVar4 = -1;
  }
  else {
    cVar4 = '\x01';
  }
  DAT_208001e4 = DAT_208001e4 + cVar4;
  FUN_2011275c(3);
  uVar1 = DAT_fcfef804;
  if ((uVar1 & 0x10) != 0) {
    uVar1 = DAT_fcfef804;
    DAT_fcfef804 = uVar1 & 0xffef;
  }
  uVar3 = DAT_fcfef804;
  itron_set_flg(DAT_208001f8,1,extraout_r2,uVar3);
  return;
}

