// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2011446c @ 2011446c (108 bytes)

void FUN_2011446c(int param_1)

{
  FUN_20151c3c(DAT_20800368,0xffffffff);
  DAT_fcfe3104 = 0x40004;
  FUN_20114144(1);
  FUN_20114168(0xe6);
  FUN_20114244(param_1 + 4,2);
  FUN_20114144(1);
  DAT_fcfe3104 = 0x40000;
  FUN_20152df4(DAT_20800368);
  *(byte *)(param_1 + 4) = *(byte *)(param_1 + 4) & 0xbf;
  return;
}


// ===== FUN_201144d8 @ 201144d8 (80 bytes)

void FUN_201144d8(short *param_1)

{
  undefined1 auStack_10 [4];
  byte local_c;
  byte local_b;
  
  FUN_2011446c(auStack_10);
  *param_1 = (local_b & 0xf) + (ushort)(local_b >> 4) * 2 + (ushort)(local_b >> 4) * 8 +
             ((local_c & 0xf) + (ushort)(local_c >> 4) * 10) * 0x3c;
  return;
}


// ===== FUN_20114528 @ 20114528 (60 bytes)

void FUN_20114528(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  FUN_20114400(&local_18);
  *param_1 = local_18;
  *param_2 = local_17;
  *param_3 = local_16;
  return;
}


// ===== FUN_20114564 @ 20114564 (56 bytes)

void FUN_20114564(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined1 local_18;
  undefined1 local_17;
  undefined1 local_16;
  
  FUN_2011446c(&local_18);
  local_18 = param_1;
  local_17 = param_2;
  local_16 = param_3;
  FUN_20114340(&local_18);
  return;
}


// ===== FUN_2011459c @ 2011459c (60 bytes)

void FUN_2011459c(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3)

{
  undefined1 auStack_18 [4];
  undefined1 local_14;
  undefined1 local_13;
  undefined1 local_12;
  
  FUN_20114400(auStack_18);
  *param_1 = local_14;
  *param_2 = local_13;
  *param_3 = local_12;
  return;
}


// ===== FUN_201145d8 @ 201145d8 (48 bytes)

void FUN_201145d8(undefined1 param_1,undefined1 param_2,undefined1 param_3)

{
  undefined4 local_10;
  undefined4 local_c;
  
  local_c = (uint)CONCAT12(param_3,CONCAT11(param_2,param_1));
  local_10 = 0;
  FUN_201143a0(&local_10);
  return;
}


// ===== FUN_20114608 @ 20114608 (80 bytes)

void FUN_20114608(undefined1 param_1,undefined1 param_2,undefined1 param_3,undefined1 param_4,
                 undefined1 param_5)

{
  undefined1 local_20;
  undefined1 local_1f;
  undefined1 local_1e;
  undefined1 local_1c;
  undefined1 local_1b;
  undefined1 local_1a;
  
  FUN_2011446c(&local_20);
  local_1b = param_5;
  local_1a = 0;
  local_20 = param_1;
  local_1f = param_2;
  local_1e = param_3;
  local_1c = param_4;
  FUN_20114340(&local_20);
  return;
}


// ===== FUN_20114658 @ 20114658 (92 bytes)

void FUN_20114658(undefined1 *param_1,undefined1 *param_2,undefined1 *param_3,undefined1 *param_4,
                 undefined1 *param_5,undefined1 *param_6)

{
  undefined1 local_28;
  undefined1 local_27;
  undefined1 local_26;
  undefined1 local_24;
  undefined1 local_23;
  undefined1 local_22;
  
  FUN_20114400(&local_28);
  *param_1 = local_28;
  *param_2 = local_27;
  *param_3 = local_26;
  *param_4 = local_24;
  *param_5 = local_23;
  *param_6 = local_22;
  return;
}


// ===== FUN_201146b4 @ 201146b4 (196 bytes)

void FUN_201146b4(int *param_1)

{
  byte local_10;
  byte local_f;
  byte local_e;
  byte local_c;
  byte local_b;
  byte local_a;
  
  FUN_20114400(&local_10);
  *param_1 = (local_a & 0xf) + (uint)(local_a >> 4) * 10;
  param_1[1] = (local_b & 0xf) + (uint)(local_b >> 4) * 10;
  param_1[2] = (local_c & 0xf) + (uint)(local_c >> 4) * 10;
  param_1[3] = (local_e & 0xf) + (uint)(local_e >> 4) * 10;
  param_1[4] = (local_f & 0xf) + (uint)(local_f >> 4) * 10 + -1;
  param_1[5] = (local_10 & 0xf) + (uint)(local_10 >> 4) * 10 + 100;
  param_1[6] = 0;
  param_1[7] = 0;
  param_1[8] = 0;
  return;
}


// ===== FUN_20114778 @ 20114778 (60 bytes)

void FUN_20114778(undefined1 *param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_20114268(0);
  *param_1 = uVar1;
  uVar1 = FUN_20114268(0x40);
  param_1[1] = uVar1;
  uVar1 = FUN_20114268(0x10);
  param_1[2] = uVar1;
  uVar1 = FUN_20114268(0x50);
  param_1[3] = uVar1;
  return;
}


// ===== FUN_201147b4 @ 201147b4 (32 bytes)

void FUN_201147b4(void)

{
  FUN_201142cc(0x40,1);
  FUN_201142cc(0x10,1);
  return;
}


// ===== FUN_201147d4 @ 201147d4 (88 bytes)

void FUN_201147d4(void)

{
  undefined4 local_10;
  undefined4 uStack_c;
  undefined4 local_8;
  
  FUN_20114328();
  FUN_201142cc(0,2);
  FUN_201142cc(0x40,0);
  local_10 = 2;
  uStack_c = 0;
  local_8 = 0;
  DAT_20800368 = FUN_2014fd24(0,&local_10);
  return;
}


// ===== FUN_20114850 @ 20114850 (48 bytes)

int FUN_20114850(int *param_1)

{
  int iVar1;
  undefined4 in_cr9;
  undefined4 in_cr13;
  
  iVar1 = coprocessor_movefromRt(0xf,0,0,in_cr9,in_cr13);
  *param_1 = iVar1 - param_1[1];
  param_1[1] = iVar1;
  return *param_1;
}


// ===== scif5_get @ 201148b4 (36 bytes)

/* UART object @0x208DB280 on SCIF5 (0xE8009800), MAIN link */

undefined * scif5_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208db280,&DAT_e8009800,&DAT_201657c8,&DAT_201657b4,param_1);
  return &DAT_208db280;
}


// ===== scif4_get @ 201148d8 (36 bytes)

/* UART object on SCIF4 (0xE8009000) */

undefined * scif4_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208daa30,&DAT_e8009000,&DAT_201657a0,&DAT_2016578c,param_1);
  return &DAT_208daa30;
}


// ===== scif3_get @ 201148fc (36 bytes)

/* UART object on SCIF3 (0xE8008800) */

undefined * scif3_get(undefined4 param_1)

{
  uart_obj_init(&DAT_208da1e0,&DAT_e8008800,&DAT_20165778,&DAT_20165764,param_1);
  return &DAT_208da1e0;
}


// ===== FUN_20114920 @ 20114920 (12 bytes)

undefined4 FUN_20114920(void)

{
  return DAT_208dba9c;
}


// ===== FUN_2011492c @ 2011492c (12 bytes)

undefined4 FUN_2011492c(void)

{
  return DAT_208db24c;
}


// ===== FUN_2011493c @ 2011493c (28 bytes)

void FUN_2011493c(void)

{
  FUN_20163360();
  FUN_20163360(&DAT_208daa30);
  FUN_20163360(&DAT_208db280);
  return;
}


// ===== sfl_decode @ 2011497c (100 bytes)

/* byte-wise key subtraction, see docs/sfl-format.md */

uint sfl_decode(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + iVar2) = *(char *)(param_2 + iVar2) - BYTE_ARRAY_204286f8[uVar1 + 0x148];
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return param_1 % 0x2b;
}


// ===== FUN_201149e0 @ 201149e0 (100 bytes)

uint FUN_201149e0(uint param_1,int param_2,int param_3)

{
  uint uVar1;
  int iVar2;
  
  iVar2 = 0;
  if (0 < param_3) {
    do {
      uVar1 = param_1 % 0x2b;
      param_1 = uVar1 + 1;
      *(byte *)(param_2 + iVar2) = *(char *)(param_2 + iVar2) + BYTE_ARRAY_204286f8[uVar1 + 0x148];
      iVar2 = iVar2 + 1;
    } while (iVar2 < param_3);
  }
  return param_1 % 0x2b;
}


// ===== sfl_stream_init @ 20114a44 (32 bytes)

void sfl_stream_init(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  *param_1 = param_2;
  param_1[2] = 0;
  param_1[3] = param_4;
  param_1[4] = 0;
  param_1[1] = param_3;
  *(undefined1 *)(param_1 + 5) = 0;
  return;
}


// ===== sfl_crc @ 20114a64 (112 bytes)

/* salted CRC-32 over the file */

uint sfl_crc(undefined4 param_1)

{
  int iVar1;
  uint uVar2;
  undefined4 uVar3;
  undefined1 auStack_110 [256];
  undefined4 local_10;
  
  uVar3 = 0xffffffff;
  local_10 = 0x139eeca6;
  crc32_make_table();
  while (iVar1 = fs_fread(auStack_110,1,0x100,param_1), iVar1 != 0) {
    uVar3 = crc32_update(uVar3,iVar1,auStack_110);
  }
  uVar2 = crc32_update(uVar3,4,&local_10);
  return ~uVar2;
}


// ===== FUN_20114ae0 @ 20114ae0 (92 bytes)

uint FUN_20114ae0(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined1 uVar1;
  uint local_c;
  
  if (0 < *(int *)(param_1 + 0x10)) {
    if (*(int *)(param_1 + 8) < *(int *)(param_1 + 0x10)) {
      local_c = CONCAT31((int3)((uint)param_4 >> 8),
                         *(undefined1 *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8)));
      uVar1 = sfl_decode(*(undefined1 *)(param_1 + 0x14),&local_c,1);
      *(undefined1 *)(param_1 + 0x14) = uVar1;
      *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + 1;
      local_c = local_c & 0xff;
    }
    else {
      local_c = 0xffffffff;
    }
    return local_c;
  }
  return 0xffffffff;
}


// ===== FUN_20114b3c @ 20114b3c (192 bytes)

int FUN_20114b3c(int param_1,int param_2,undefined4 *param_3)

{
  int iVar1;
  int iVar2;
  
  if (param_3[3] == 0) {
    iVar2 = FUN_20142390(param_1,param_2,*param_3);
    return iVar2;
  }
  if (0 < param_2) {
    iVar2 = 0;
    if (0 < param_2 + -1) {
      do {
        iVar1 = FUN_20114ae0(param_3);
        if (iVar1 == -1) {
          iVar1 = fs_fread(param_3[1],1,param_3[3],*param_3);
          if (iVar1 == 0) break;
          param_3[4] = iVar1;
          param_3[2] = 0;
        }
        else {
          *(char *)(param_1 + iVar2) = (char)iVar1;
          iVar2 = iVar2 + 1;
          if (iVar1 == 10) break;
        }
      } while (iVar2 < param_2 + -1);
    }
    *(undefined1 *)(param_1 + iVar2) = 0;
    if ((iVar2 != 0) || (param_2 < 2)) {
      return param_1;
    }
  }
  return 0;
}


// ===== FUN_20114bfc @ 20114bfc (72 bytes)

int FUN_20114bfc(undefined4 param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined1 uVar1;
  int iVar2;
  
  iVar2 = fs_fread();
  if ((iVar2 != 0) && (*(int *)(param_4 + 0xc) != 0)) {
    uVar1 = sfl_decode(*(undefined1 *)(param_4 + 0x14),param_1,iVar2);
    *(undefined1 *)(param_4 + 0x14) = uVar1;
  }
  return iVar2;
}


// ===== FUN_20114c44 @ 20114c44 (92 bytes)

void FUN_20114c44(undefined4 param_1,int param_2,int param_3,undefined4 *param_4)

{
  undefined1 uVar1;
  
  if (param_4[3] != 0) {
    uVar1 = FUN_201149e0(*(undefined1 *)(param_4 + 5),param_1,param_2 * param_3);
    *(undefined1 *)(param_4 + 5) = uVar1;
    fs_fwrite(param_1,param_2,param_3,*param_4);
    return;
  }
  fs_fwrite(param_1,param_2,param_3,*param_4);
  return;
}


// ===== sfl_read_header @ 20114ca0 (336 bytes)

/* reads the 0x40-byte header block */

undefined4 sfl_read_header(undefined4 param_1,int param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined1 auStack_118 [64];
  undefined1 local_d8;
  undefined1 *local_18;
  int local_14;
  
  local_18 = auStack_118;
  iVar3 = 0;
  do {
    iVar1 = fs_fread(auStack_118,1,0x40,param_1);
    if (iVar1 == 0) {
      return 1;
    }
    if ((param_2 != 0) && (iVar3 == 3)) {
      memcpy(param_2,auStack_118,0x40);
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 9);
  local_d8 = 0;
  iVar3 = FUN_20155122(auStack_118);
  if (iVar3 == 0x40) {
    iVar3 = sfl_crc(param_1);
    fs_fseek(param_1,0);
    iVar1 = 0;
    do {
      iVar2 = fs_fread(auStack_118,1,0x40,param_1);
      if (iVar2 == 0) {
        return 1;
      }
      iVar1 = iVar1 + 1;
    } while (iVar1 < 8);
    iVar1 = FUN_20142390(auStack_118,0x100,param_1);
    if ((((iVar1 != 0) && (iVar1 = FUN_2014e320(local_18,&DAT_20114df0,&local_18), iVar1 != 0)) &&
        (iVar1 = FUN_2014e320(local_18,&DAT_20114df0,&local_18), iVar1 != 0)) &&
       (((iVar1 = FUN_2014e320(local_18,&DAT_20114df0,&local_18), iVar1 != 0 &&
         (iVar2 = FUN_201112b4(iVar1,8,&local_14), local_14 != iVar1)) && (iVar2 == iVar3)))) {
      return 0;
    }
  }
  return 1;
}


// ===== FUN_20114df4 @ 20114df4 (148 bytes)

void FUN_20114df4(void)

{
  FUN_2014e884(0,1);
  FUN_20101d14();
  FUN_20101b60(0);
  FUN_20101dec(0);
  FUN_20101d2c(1);
  itron_dly_tsk(5);
  itron_dly_tsk(0x96);
  FUN_20101d2c(0);
  gpio_p7_9_11(1);
  itron_dly_tsk(4);
  FUN_20101c74(0);
  gpio_rx_reset(1);
  itron_dly_tsk(1);
  FUN_20101c8c(1);
  gpio_rx_reset(0);
  itron_dly_tsk(0xe);
  FUN_20101cbc(1);
  FUN_20100268();
  return;
}


// ===== FUN_20114e88 @ 20114e88 (84 bytes)

void FUN_20114e88(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  
  iVar1 = FUN_201589f4(DAT_20450020 + 0x938);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(short *)(iVar1 + 6) = (short)param_2;
  memcpy(iVar1 + 8,param_1,param_2);
  FUN_20158adc(DAT_20450020 + 0x938,iVar1);
  return;
}


// ===== FUN_20114edc @ 20114edc (112 bytes)

undefined4 FUN_20114edc(int param_1)

{
  int iVar1;
  
  iVar1 = param_1 * 100;
  while( true ) {
    if (DAT_2045001c != '\0') {
      return 1;
    }
    if ((param_1 != 0) && (iVar1 = iVar1 + -1, iVar1 == 0)) break;
    itron_dly_tsk(1);
    if (((byte)DAT_20808a84 & 1) != 0) {
      return 1;
    }
  }
  DAT_2045001d = 1;
  return 0;
}


// ===== FUN_20114f4c @ 20114f4c (120 bytes)

void FUN_20114f4c(void)

{
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  
  memclr(&DAT_2045d4e0,0x1ae0);
  DAT_20450020 = FUN_20158e8c(&DAT_2045d4e0);
  iVar1 = itron_acre_tsk(0,&DAT_201657dc);
  if ((0 < iVar1) && (iVar2 = itron_acre_flg(0,&DAT_201657f8), 0 < iVar2)) {
    *(int *)(DAT_20450020 + 0x14) = iVar2;
    uVar3 = scif4_get();
    *(undefined4 *)(DAT_20450020 + 0x10) = uVar3;
    itron_sta_tsk(iVar1);
    return;
  }
  return;
}


// ===== FUN_20115000 @ 20115000 (12 bytes)

void FUN_20115000(undefined4 param_1)

{
  memcpy(param_1,&DAT_2045f8c0,0x240);
  return;
}


// ===== FUN_2011500c @ 2011500c (12 bytes)

void FUN_2011500c(undefined4 param_1)

{
  memcpy(param_1,&DAT_2045fb00,0x240);
  return;
}


// ===== FUN_20115018 @ 20115018 (12 bytes)

undefined1 FUN_20115018(void)

{
  return DAT_20450026;
}


// ===== FUN_20115024 @ 20115024 (24 bytes)

undefined1 FUN_20115024(undefined4 param_1)

{
  FUN_201636f8(param_1,&DAT_2045006d);
  return DAT_20450024;
}


// ===== FUN_20115060 @ 20115060 (12 bytes)

undefined4 FUN_20115060(void)

{
  return DAT_2045005c;
}


// ===== FUN_2011506c @ 2011506c (32 bytes)

bool FUN_2011506c(undefined4 param_1)

{
  int iVar1;
  
  iVar1 = FUN_2015507c(&DAT_2045f8c0,param_1,0x240);
  return iVar1 != 0;
}


// ===== FUN_2011508c @ 2011508c (16 bytes)

void FUN_2011508c(undefined4 param_1)

{
  memcpy(&DAT_2045f8c0,param_1,0x240);
  return;
}


// ===== task_cmd_interval @ 2011509c (68 bytes)

void task_cmd_interval(void)

{
  DAT_20450050 = 0;
  do {
    do {
      FUN_201525f8(0xffffffff);
    } while (DAT_20450050 < 1);
    FUN_20152bb0(DAT_20450054,0xffffffff);
    DAT_20450050 = DAT_20450050 + -1;
    FUN_201511e8(DAT_20450054);
  } while( true );
}


// ===== FUN_201150e0 @ 201150e0 (12 bytes)

void FUN_201150e0(undefined1 param_1)

{
  DAT_2045002d = param_1;
  return;
}


// ===== FUN_201150ec @ 201150ec (12 bytes)

undefined1 FUN_201150ec(void)

{
  return DAT_2045002d;
}


// ===== FUN_201150f8 @ 201150f8 (924 bytes)

void FUN_201150f8(undefined4 param_1,undefined4 param_2)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  char cVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = FUN_20158630(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar2 + 4) = 0xaa;
  *(short *)(iVar2 + 6) = (short)param_2 + 1;
  memcpy(iVar2 + 8,param_1,param_2);
  bVar1 = *(byte *)(iVar2 + 8);
  if (bVar1 == 0xf0 || bVar1 == 0xf1) {
    cVar5 = '\0';
    iVar3 = 0;
    iVar6 = *(ushort *)(iVar2 + 6) - 1;
    if (0 < iVar6) {
      do {
        iVar7 = iVar2 + iVar3;
        iVar3 = iVar3 + 1;
        cVar5 = cVar5 + *(char *)(iVar7 + 8);
      } while (iVar3 < iVar6);
    }
    *(char *)((uint)*(ushort *)(iVar2 + 6) + iVar2 + 7) = cVar5;
    FUN_20158744(DAT_20450060 + 0x8218,iVar2);
    return;
  }
  if (DAT_2080049c == '\0') {
    if (DAT_2045002a == '\0') {
      memclr(&DAT_2045efc0,0x105);
      memcpy(&DAT_2045efc0,param_1,param_2);
      DAT_20450038 = param_2;
      FUN_201150e0(*(undefined1 *)(iVar2 + 8));
      cVar5 = '\0';
      iVar3 = 0;
      iVar6 = *(ushort *)(iVar2 + 6) - 1;
      if (0 < iVar6) {
        do {
          iVar7 = iVar2 + iVar3;
          iVar3 = iVar3 + 1;
          cVar5 = cVar5 + *(char *)(iVar7 + 8);
        } while (iVar3 < iVar6);
      }
      *(char *)((uint)*(ushort *)(iVar2 + 6) + iVar2 + 7) = cVar5;
      FUN_20158744(DAT_20450060 + 0x8218,iVar2);
      DAT_2045002a = 1;
      DAT_2045002c = 0;
      FUN_20151680(DAT_20450064);
      return;
    }
    if (bVar1 == 0xe4) {
      DAT_20470108 = 0;
      memcpy(&DAT_20470108,param_1,param_2);
      DAT_2045f241 = 1;
      return;
    }
    if (bVar1 < 0xe5) {
      if (bVar1 == 0xe0) {
        uVar4 = DAT_2045002e + 1 & 0xff;
        DAT_2045002e = (byte)(uVar4 % 10);
        iVar2 = (uVar4 % 10) * 5;
        FUN_20163668(iVar2 + 0x20470117,(uVar4 / 10) * -5,uVar4 * -0x33333333);
        memcpy(iVar2 + 0x20470117,param_1,param_2);
        DAT_2045f244 = 1;
        return;
      }
      if (bVar1 < 0xe1) {
        if (bVar1 == 0xc3) {
          FUN_20155274(&DAT_20470165,0x22);
          memcpy(&DAT_20470165,param_1,param_2);
          DAT_2045f249 = 1;
          return;
        }
        if (bVar1 == 0xc4) {
          FUN_20155274(&DAT_20470187,0x106);
          memcpy(&DAT_20470187,param_1,param_2);
          DAT_2045f24a = 1;
          return;
        }
        if (bVar1 == 0xc5) {
          FUN_20163684();
          memcpy(&DAT_2047028d,param_1,param_2);
          DAT_2045f24b = 1;
        }
      }
      else {
        if (bVar1 == 0xe2) {
          FUN_20163684(&DAT_20470149);
          memcpy(&DAT_20470149,param_1,param_2);
          DAT_2045f245 = 1;
          return;
        }
        if (bVar1 == 0xe3) {
          DAT_20470100 = 0;
          DAT_20470104 = 0;
          memcpy(&DAT_20470100,param_1,param_2);
          DAT_2045f240 = 1;
          return;
        }
      }
    }
    else {
      if (bVar1 == 0xe7) {
        FUN_20155274(&DAT_20470153,9);
        memcpy(&DAT_20470153,param_1,param_2);
        DAT_2045f247 = 1;
        return;
      }
      if (bVar1 < 0xe8) {
        if (bVar1 == 0xe5) {
          DAT_2047010c = 0;
          memcpy(&DAT_2047010c,param_1,param_2);
          DAT_2045f242 = 1;
          return;
        }
        if (bVar1 == 0xe6) {
          DAT_2047014f = 0;
          DAT_20470150 = 0;
          DAT_20470151 = 0;
          DAT_20470152 = 0;
          memcpy(&DAT_2047014f,param_1,param_2);
          DAT_2045f246 = 1;
          return;
        }
      }
      else {
        if (bVar1 == 0xe8) {
          FUN_201636b8(&DAT_2047015c);
          memcpy(&DAT_2047015c,param_1,param_2);
          DAT_2045f248 = 1;
          return;
        }
        if (bVar1 == 0xf1) {
          memclr(&DAT_20470110,7);
          memcpy(&DAT_20470110,param_1,param_2);
          DAT_2045f243 = 1;
          return;
        }
      }
    }
  }
  return;
}


// ===== mainlink_queue_frame @ 20115494 (644 bytes)

/* WARNING: Type propagation algorithm not settling */

void mainlink_queue_frame(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  undefined1 local_30 [4];
  undefined4 local_2c;
  undefined4 uStack_28;
  
  local_2c = param_1;
  uStack_28 = param_2;
  memcpy(&DAT_2045f4a0,param_1,param_2);
  if (DAT_20800496 != '\0' || DAT_20800494 != '\0') {
    if (DAT_2045f4a0 != -0x1a) {
      if ((DAT_208f0b2a == '@') && (DAT_20800494 != '\0')) {
        if ((DAT_2045f4a0 == -0x20) &&
           (((DAT_2045f4a1 == 1 && (DAT_2045f4a2 == '\x03')) && (DAT_2045f4a3 == '\x0f')))) {
          DAT_20808533 = 1;
          return;
        }
        if (DAT_20800496 == '\0') goto LAB_20115704;
      }
      if (DAT_2045f4a0 != -0x20) {
        return;
      }
      if (2 < DAT_2045f4a1) {
        return;
      }
      if (DAT_2045f4a2 != '\x03') {
        return;
      }
      if (DAT_2045f4a3 != '\0') {
        return;
      }
    }
    goto LAB_20115704;
  }
  if (DAT_208f0b2a == '{') {
    if ((DAT_208f0b2b != '\0') && (DAT_2045f4a0 == -0x1e)) {
      local_30[0] = 0xe4;
      DAT_20800488 = 1;
      FUN_201150f8(local_30,4);
      goto LAB_2011553c;
    }
  }
  else {
LAB_2011553c:
    if (((((DAT_208f0b2a == '@') && (DAT_2045f4a0 == -0x20)) &&
         ((DAT_2045f4a1 == 1 &&
          ((((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')) && (DAT_208f0bc2 == '\0')) &&
           (((DAT_208f0bc6 & 0x10) != 0 && ((DAT_208f0bc5 & 2) != 0)))))))) &&
        (((uint)DAT_208f0bc4 + (DAT_208f0bc6 & 0xf) == 5 &&
         ((iVar1 = FUN_2015507c((DAT_208f0bc6 & 0xf) * 0x2d + 0x208f0c46,"FIRMWARE UPDATE      ",
                                0x15), iVar1 == 0 && (DAT_208000b2 == '\0')))))) &&
       (iVar1 = FUN_20103ba0(), iVar1 != 0)) {
      DAT_20450027 = 1;
      DAT_20800494 = 1;
      DAT_20808533 = 0;
      return;
    }
  }
  if (DAT_20800494 != '\0') {
    return;
  }
  if ((((DAT_20450027 != '\0') && (DAT_2045f4a0 == -0x20)) && (DAT_2045f4a1 == 0)) &&
     ((DAT_2045f4a2 == '\x03' && (DAT_2045f4a3 == '\x0f')))) {
    DAT_20450027 = 0;
    return;
  }
LAB_20115704:
  FUN_201150f8(local_2c,param_2);
  return;
}


// ===== FUN_20115780 @ 20115780 (420 bytes)

void FUN_20115780(byte *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  uint uVar4;
  int iVar5;
  int iVar6;
  
  if (DAT_20800495 == '\0') {
    return;
  }
  if (DAT_2045002a != '\0') {
    FUN_20152bb0(DAT_20450058,0xffffffff);
    uVar4 = (uint)*param_1;
    DAT_2045002b = DAT_2045002b | (byte)(1 << uVar4);
    iVar5 = (&DAT_2045f224)[uVar4];
    if (iVar5 < 10) {
      FUN_201636cc(&DAT_2045f0c5 + iVar5 * 5 + uVar4 * 0x32,param_1);
      (&DAT_2045f224)[uVar4] = iVar5 + 1;
    }
    else {
      iVar5 = iVar5 * 5 + uVar4 * 0x32;
      cVar2 = (&DAT_2045f0c5)[iVar5 + -4];
      FUN_201636cc(&DAT_2045f0c5 + iVar5 + -5,param_1);
      switch(uVar4) {
      case 1:
      case 2:
      case 3:
        iVar1 = (int)(char)param_1[1] + (int)cVar2;
        if (iVar1 < 0) {
          if (iVar1 < -0x7f) {
            iVar1 = -0x7f;
          }
          iVar1 = iVar1 + 0x100;
        }
        else if (0x7f < iVar1) {
          iVar1 = 0x7f;
        }
        (&DAT_2045f0c5)[iVar5 + -4] = (char)iVar1;
        break;
      case 4:
      case 5:
        (&DAT_2045f0c5)[iVar5 + -4] = param_1[1];
      }
    }
    FUN_201511e8(DAT_20450058);
    return;
  }
  iVar5 = FUN_20158630(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar5 + 4) = 0xaa;
  *(undefined2 *)(iVar5 + 6) = 7;
  *(undefined1 *)(iVar5 + 8) = 0xe1;
  FUN_201636cc(iVar5 + 9,param_1);
  FUN_201636a8(&DAT_20450068);
  FUN_201636cc(&DAT_20450068,param_1);
  FUN_201150e0(*(undefined1 *)(iVar5 + 8));
  cVar2 = '\0';
  iVar1 = 0;
  iVar3 = *(ushort *)(iVar5 + 6) - 1;
  if (0 < iVar3) {
    do {
      iVar6 = iVar5 + iVar1;
      iVar1 = iVar1 + 1;
      cVar2 = cVar2 + *(char *)(iVar6 + 8);
    } while (iVar1 < iVar3);
  }
  *(char *)((uint)*(ushort *)(iVar5 + 6) + iVar5 + 7) = cVar2;
  FUN_20158744(DAT_20450060 + 0x8218,iVar5);
  DAT_2045002a = 1;
  DAT_2045002c = 0;
  FUN_20151680(DAT_20450064);
  return;
}


// ===== FUN_2011593c @ 2011593c (80 bytes)

void FUN_2011593c(int param_1,byte *param_2)

{
  byte *pbVar1;
  byte bVar2;
  uint uVar3;
  
  uVar3 = 1;
  bVar2 = *param_2;
  if (param_1 != 0) {
    do {
      pbVar1 = param_2 + uVar3;
      uVar3 = uVar3 + 1 & 0xff;
      if (bVar2 < *pbVar1) {
        bVar2 = *pbVar1;
      }
    } while (uVar3 < 4);
    return;
  }
  do {
    pbVar1 = param_2 + uVar3;
    uVar3 = uVar3 + 1 & 0xff;
    if (*pbVar1 < bVar2) {
      bVar2 = *pbVar1;
    }
  } while (uVar3 < 4);
  return;
}


// ===== FUN_2011598c @ 2011598c (188 bytes)

undefined4 FUN_2011598c(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (DAT_20450030 != param_1) {
    if (DAT_2045003c == 1) {
      uVar3 = param_1 | param_1 << 8;
      DAT_2045003c = 0;
      DAT_20450040 = uVar3 | uVar3 << 0x10;
    }
    DAT_20450030 = (byte)param_1;
    DAT_20450031 = DAT_20450031 + 1;
    if (3 < DAT_20450031) {
      DAT_20450031 = 0;
    }
    *(byte *)((int)&DAT_20450040 + (uint)DAT_20450031) = DAT_20450030;
    if (((param_1 - 3 < 0xfa) && ((char)DAT_20450040 != DAT_20450040._2_1_)) &&
       (DAT_20450040._1_1_ != DAT_20450040._3_1_)) {
      iVar1 = FUN_2011593c(1,&DAT_20450040);
      iVar2 = FUN_2011593c(0,&DAT_20450040);
      if (2 < iVar1 - iVar2) {
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}


// ===== FUN_20115a48 @ 20115a48 (188 bytes)

undefined4 FUN_20115a48(uint param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  undefined4 uVar4;
  
  uVar4 = 0;
  if (DAT_20450032 != param_1) {
    if (DAT_20450044 == 1) {
      uVar3 = param_1 | param_1 << 8;
      DAT_20450044 = 0;
      DAT_20450048 = uVar3 | uVar3 << 0x10;
    }
    DAT_20450032 = (byte)param_1;
    DAT_20450033 = DAT_20450033 + 1;
    if (3 < DAT_20450033) {
      DAT_20450033 = 0;
    }
    *(byte *)((int)&DAT_20450048 + (uint)DAT_20450033) = DAT_20450032;
    if (((param_1 - 3 < 0xfa) && ((char)DAT_20450048 != DAT_20450048._2_1_)) &&
       (DAT_20450048._1_1_ != DAT_20450048._3_1_)) {
      iVar1 = FUN_2011593c(1,&DAT_20450048);
      iVar2 = FUN_2011593c(0,&DAT_20450048);
      if (2 < iVar1 - iVar2) {
        uVar4 = 1;
      }
    }
  }
  return uVar4;
}


// ===== FUN_20115b04 @ 20115b04 (220 bytes)

void FUN_20115b04(char *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  bool bVar1;
  int iVar2;
  char cVar3;
  undefined4 local_10;
  
  if (DAT_20800496 != '\0') {
    return;
  }
  local_10 = param_4;
  iVar2 = FUN_20116dac();
  if (iVar2 == 0) {
    return;
  }
  if (*param_1 == '\x04') {
    iVar2 = FUN_20115a48(param_1[1]);
    if (iVar2 == 0) {
      bVar1 = false;
      goto LAB_20115b68;
    }
  }
  else if (*param_1 == '\x05') {
    iVar2 = FUN_2011598c(param_1[1]);
    bVar1 = false;
    if (iVar2 == 0) goto LAB_20115b68;
  }
  bVar1 = true;
LAB_20115b68:
  cVar3 = DAT_208f0b2a;
  if ((DAT_208f0b2a == '{') && (cVar3 = '\0', DAT_208f0b2b != '\0')) {
    if (bVar1) {
      DAT_208f0b2b = '\0';
      local_10 = 0xe4;
      DAT_20800488 = 1;
      mainlink_queue_frame(&local_10,4);
      if (*param_1 == '\x04' || *param_1 == '\x05') {
        FUN_20115780(param_1);
      }
    }
    return;
  }
  FUN_20115780(param_1,&DAT_208f0b2a,cVar3,local_10);
  return;
}


// ===== FUN_20115be0 @ 20115be0 (148 bytes)

void FUN_20115be0(undefined4 param_1,undefined4 param_2)

{
  int iVar1;
  int iVar2;
  char cVar3;
  int iVar4;
  int iVar5;
  
  iVar1 = FUN_20158630(DAT_20450060 + 0x8218);
  *(undefined2 *)(iVar1 + 4) = 0xaa;
  *(short *)(iVar1 + 6) = (short)param_2 + 1;
  memcpy(iVar1 + 8,param_1,param_2);
  cVar3 = '\0';
  iVar2 = 0;
  iVar4 = *(ushort *)(iVar1 + 6) - 1;
  if (0 < iVar4) {
    do {
      iVar5 = iVar1 + iVar2;
      iVar2 = iVar2 + 1;
      cVar3 = cVar3 + *(char *)(iVar5 + 8);
    } while (iVar2 < iVar4);
  }
  *(char *)((uint)*(ushort *)(iVar1 + 6) + iVar1 + 7) = cVar3;
  FUN_20158744(DAT_20450060 + 0x8218,iVar1);
  return;
}

