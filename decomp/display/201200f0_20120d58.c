// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_201200f0 @ 201200f0 (20 bytes)

void FUN_201200f0(void)

{
  do {
  } while (DAT_2080045a == '\0');
  return;
}


// ===== FUN_20120104 @ 20120104 (20 bytes)

void FUN_20120104(void)

{
  do {
  } while (DAT_2080045b == '\0');
  return;
}


// ===== FUN_20120118 @ 20120118 (48 bytes)

void FUN_20120118(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045c == '\0');
    return;
  }
  do {
  } while (DAT_20800454 == '\0');
  return;
}


// ===== FUN_20120148 @ 20120148 (48 bytes)

void FUN_20120148(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045d == '\0');
    return;
  }
  do {
  } while (DAT_20800455 == '\0');
  return;
}


// ===== FUN_201201c4 @ 201201c4 (48 bytes)

void FUN_201201c4(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045e == '\0');
    return;
  }
  do {
  } while (DAT_20800456 == '\0');
  return;
}


// ===== FUN_201201f4 @ 201201f4 (48 bytes)

void FUN_201201f4(int param_1)

{
  if (param_1 == 0) {
    do {
    } while (DAT_2080045f == '\0');
    return;
  }
  do {
  } while (DAT_20800457 == '\0');
  return;
}


// ===== riic_init @ 20120224 (72 bytes)

/* RIIC 0xFCFEE000 (touch controller TSC2003) */

void riic_init(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC0CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC0CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== FUN_2012026c @ 2012026c (72 bytes)

void FUN_2012026c(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC1CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC1CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== FUN_201202b4 @ 201202b4 (72 bytes)

void FUN_201202b4(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC2CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC2CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== FUN_201202fc @ 201202fc (72 bytes)

void FUN_201202fc(int param_1)

{
  byte bVar1;
  
  if (param_1 != 0) {
    do {
      bVar1 = reg_read8((byte *)&RIIC_RIIC3CR2,7,0x80);
    } while (bVar1 == 0);
    return;
  }
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC3CR2,7,0x80);
  } while (bVar1 == 1);
  return;
}


// ===== FUN_20120344 @ 20120344 (36 bytes)

void FUN_20120344(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC0SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== FUN_20120368 @ 20120368 (36 bytes)

void FUN_20120368(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC1SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== FUN_2012038c @ 2012038c (36 bytes)

void FUN_2012038c(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC2SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== FUN_201203b0 @ 201203b0 (36 bytes)

void FUN_201203b0(void)

{
  byte bVar1;
  
  do {
    bVar1 = reg_read8((byte *)&RIIC_RIIC3SR2,3,8);
  } while (bVar1 == 0);
  return;
}


// ===== FUN_201203d4 @ 201203d4 (8 bytes)

void FUN_201203d4(void)

{
  FUN_20120c04(0);
  return;
}


// ===== FUN_201203dc @ 201203dc (8 bytes)

void FUN_201203dc(void)

{
  FUN_20120c54(0);
  return;
}


// ===== FUN_201203e4 @ 201203e4 (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120ccc) */
/* WARNING: Removing unreachable block (ram,0x20120cd4) */
/* WARNING: Removing unreachable block (ram,0x20120cf8) */
/* WARNING: Removing unreachable block (ram,0x20120cdc) */
/* WARNING: Removing unreachable block (ram,0x20120ce0) */
/* WARNING: Removing unreachable block (ram,0x20120ce4) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120cf0) */

undefined4 FUN_201203e4(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  FUN_20120038(0);
  pvVar1 = riic_base(0);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== FUN_201203ec @ 201203ec (8 bytes)

void FUN_201203ec(void)

{
  FUN_20120c04(1);
  return;
}


// ===== FUN_201203f4 @ 201203f4 (8 bytes)

void FUN_201203f4(void)

{
  FUN_20120c54(1);
  return;
}


// ===== FUN_201203fc @ 201203fc (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120cd4) */
/* WARNING: Removing unreachable block (ram,0x20120cf8) */
/* WARNING: Removing unreachable block (ram,0x20120cdc) */
/* WARNING: Removing unreachable block (ram,0x20120ce0) */
/* WARNING: Removing unreachable block (ram,0x20120ce4) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120ce8) */

undefined4 FUN_201203fc(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  FUN_20120048();
  pvVar1 = riic_base(1);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== FUN_20120404 @ 20120404 (8 bytes)

void FUN_20120404(void)

{
  FUN_20120c04(2);
  return;
}


// ===== FUN_2012040c @ 2012040c (8 bytes)

void FUN_2012040c(void)

{
  FUN_20120c54(2);
  return;
}


// ===== FUN_20120414 @ 20120414 (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120cdc) */
/* WARNING: Removing unreachable block (ram,0x20120ce0) */
/* WARNING: Removing unreachable block (ram,0x20120ce4) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120cf0) */
/* WARNING: Removing unreachable block (ram,0x20120ce8) */

undefined4 FUN_20120414(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  FUN_20120058();
  pvVar1 = riic_base(2);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== FUN_2012041c @ 2012041c (8 bytes)

void FUN_2012041c(void)

{
  FUN_20120c04(3);
  return;
}


// ===== FUN_20120424 @ 20120424 (8 bytes)

void FUN_20120424(void)

{
  FUN_20120c54(3);
  return;
}


// ===== FUN_2012042c @ 2012042c (8 bytes)

/* WARNING: Removing unreachable block (ram,0x20120cf0) */
/* WARNING: Removing unreachable block (ram,0x20120cbc) */
/* WARNING: Removing unreachable block (ram,0x20120cf8) */
/* WARNING: Removing unreachable block (ram,0x20120ce8) */

undefined4 FUN_2012042c(void)

{
  void *pvVar1;
  undefined4 in_r3;
  
  FUN_20120068();
  pvVar1 = riic_base(3);
  reg_rmw8((int)pvVar1 + 0x24,0,6,0x40,in_r3);
  reg_read8((byte *)((int)pvVar1 + 0x24),6,0x40);
  return 0;
}


// ===== FUN_20120454 @ 20120454 (80 bytes)

undefined4 FUN_20120454(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      FUN_2011fc8c();
    }
    else if (param_1 == 1) {
      FUN_2011fd1c();
    }
    else if (param_1 == 2) {
      FUN_2011fdac();
    }
    else if (param_1 == 3) {
      FUN_2011fe34();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== riic_base @ 201204a4 (48 bytes)

/* (ch 0..3): RIIC register base 0xFCFEE000 + 0x400*ch (docs/memory-maps.md) [fact] */

void * riic_base(int param_1)

{
  dword *pdVar1;
  
  pdVar1 = &RIIC_RIIC0CR1;
  if (param_1 != 0) {
    if (param_1 == 1) {
      pdVar1 = &RIIC_RIIC1CR1;
    }
    else if (param_1 == 2) {
      pdVar1 = &RIIC_RIIC2CR1;
    }
    else if (param_1 == 3) {
      pdVar1 = &RIIC_RIIC3CR1;
    }
  }
  return pdVar1;
}


// ===== FUN_201204d4 @ 201204d4 (56 bytes)

void FUN_201204d4(int param_1)

{
  void *pvVar1;
  
  pvVar1 = riic_base(param_1);
  reg_rmw8((int)pvVar1 + 0x24,0,3,8);
  reg_rmw8((int)pvVar1 + 4,1,3,8);
  return;
}


// ===== FUN_2012050c @ 2012050c (180 bytes)

void FUN_2012050c(int param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    riic_init(1);
    FUN_2011febc();
    FUN_2011fefc();
    FUN_2011ff3c(0);
  }
  else if (param_1 == 1) {
    FUN_2012026c(1);
    FUN_2011fecc();
    FUN_2011ff0c();
    FUN_2011ff54(0);
  }
  else if (param_1 == 2) {
    FUN_201202b4(1);
    FUN_2011fedc();
    FUN_2011ff1c();
    FUN_2011ff6c(0);
  }
  else if (param_1 == 3) {
    FUN_201202fc(1);
    FUN_2011feec();
    FUN_2011ff2c();
    FUN_2011ff84(0);
  }
  pvVar1 = riic_base(param_1);
  reg_rmw8((int)pvVar1 + 4,1,2,4);
  return;
}


// ===== FUN_201205c0 @ 201205c0 (180 bytes)

void FUN_201205c0(int param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    riic_init(0);
    FUN_2011febc();
    FUN_2011fefc();
    FUN_2011ff3c(0);
  }
  else if (param_1 == 1) {
    FUN_2012026c(0);
    FUN_2011fecc();
    FUN_2011ff0c();
    FUN_2011ff54(0);
  }
  else if (param_1 == 2) {
    FUN_201202b4(0);
    FUN_2011fedc();
    FUN_2011ff1c();
    FUN_2011ff6c(0);
  }
  else if (param_1 == 3) {
    FUN_201202fc(0);
    FUN_2011feec();
    FUN_2011ff2c();
    FUN_2011ff84(0);
  }
  pvVar1 = riic_base(param_1);
  reg_rmw8((int)pvVar1 + 4,1,1,2);
  return;
}


// ===== FUN_20120674 @ 20120674 (76 bytes)

undefined4 FUN_20120674(uint param_1,uint param_2)

{
  if ((param_1 < 4) && (param_2 < 3)) {
    if (param_2 == 0) {
      FUN_201205c0();
    }
    else if (param_2 == 1) {
      FUN_2012050c();
    }
    else if (param_2 == 2) {
      FUN_201204d4();
    }
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_201206c0 @ 201206c0 (144 bytes)

undefined4 FUN_201206c0(int param_1,undefined1 param_2)

{
  byte bVar1;
  void *pvVar2;
  undefined4 uVar3;
  
  pvVar2 = riic_base(param_1);
  bVar1 = reg_read8((byte *)((int)pvVar2 + 0x24),4,0x10);
  if (bVar1 == 0) {
    uVar3 = 0;
    if (param_1 == 0) {
      FUN_201200c8();
      FUN_2011fefc();
    }
    else if (param_1 == 1) {
      FUN_201200dc();
      FUN_2011ff0c();
    }
    else if (param_1 == 2) {
      FUN_201200f0();
      FUN_2011ff1c();
    }
    else if (param_1 == 3) {
      FUN_20120104();
      FUN_2011ff2c();
    }
    *(undefined1 *)((int)pvVar2 + 0x3c) = param_2;
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}


// ===== FUN_20120750 @ 20120750 (204 bytes)

int FUN_20120750(uint param_1,undefined1 param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  
  if ((param_1 < 4) && (param_3 < 2)) {
    iVar2 = FUN_201206c0(param_1,param_2);
    if (iVar2 == 0) {
      if (param_1 == 0) {
        FUN_20120118(param_3);
        FUN_2011ff3c(param_3);
      }
      else if (param_1 == 1) {
        FUN_20120148(param_3);
        FUN_2011ff54(param_3);
      }
      else if (param_1 == 2) {
        FUN_201201c4(param_3);
        FUN_2011ff6c(param_3);
      }
      else if (param_1 == 3) {
        FUN_201201f4(param_3);
        FUN_2011ff84(param_3);
      }
      pvVar3 = riic_base(param_1);
      bVar1 = reg_read8((byte *)((int)pvVar3 + 0x24),4,0x10);
      if (bVar1 != 0) {
        iVar2 = -2;
      }
    }
    return iVar2;
  }
  return -1;
}


// ===== FUN_2012081c @ 2012081c (232 bytes)

int FUN_2012081c(uint param_1,int param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  void *pvVar3;
  uint uVar4;
  
  if (3 < param_1) {
    return -1;
  }
  if (param_3 == 0) {
    iVar2 = 0;
  }
  else {
    uVar4 = 0;
    do {
      iVar2 = FUN_201206c0(param_1,*(undefined1 *)(param_2 + uVar4));
      if (iVar2 != 0) {
        return iVar2;
      }
      uVar4 = uVar4 + 1;
    } while (uVar4 < param_3);
    if (param_1 == 0) {
      FUN_20120118(0);
      FUN_2011ff3c(0);
    }
    else if (param_1 == 1) {
      FUN_20120148(0);
      FUN_2011ff54(0);
    }
    else if (param_1 == 2) {
      FUN_201201c4(0);
      FUN_2011ff6c(0);
    }
    else if (param_1 == 3) {
      FUN_201201f4(0);
      FUN_2011ff84(0);
    }
    pvVar3 = riic_base(param_1);
    bVar1 = reg_read8((byte *)((int)pvVar3 + 0x24),4,0x10);
    iVar2 = 0;
    if (bVar1 != 0) {
      iVar2 = -2;
    }
  }
  return iVar2;
}


// ===== FUN_20120904 @ 20120904 (20 bytes)

void FUN_20120904(int param_1)

{
  reg_rmw8(param_1 + 0x24,0,4,0x10);
  return;
}


// ===== FUN_20120918 @ 20120918 (100 bytes)

void FUN_20120918(int param_1)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    FUN_20120344();
  }
  else if (param_1 == 1) {
    FUN_20120368();
  }
  else if (param_1 == 2) {
    FUN_2012038c();
  }
  else if (param_1 == 3) {
    FUN_201203b0();
  }
  pvVar1 = riic_base(param_1);
  FUN_20120904();
  reg_rmw8((int)pvVar1 + 0x24,0,3,8);
  return;
}


// ===== FUN_2012097c @ 2012097c (248 bytes)

void FUN_2012097c(int param_1,undefined4 param_2,undefined1 *param_3)

{
  void *pvVar1;
  
  if (param_1 == 0) {
    FUN_20120078();
    FUN_2011febc();
  }
  else if (param_1 == 1) {
    FUN_2012008c();
    FUN_2011fecc();
  }
  else if (param_1 == 2) {
    FUN_201200a0();
    FUN_2011fedc();
  }
  else if (param_1 == 3) {
    FUN_201200b4();
    FUN_2011feec();
  }
  pvVar1 = riic_base(param_1);
  switch(param_2) {
  case 1:
    reg_rmw8((int)pvVar1 + 0x10,1,4,0x10);
    reg_rmw8((int)pvVar1 + 0x10,0,3,8);
    break;
  case 2:
    reg_rmw8((int)pvVar1 + 0x10,1,6,0x40);
    break;
  case 3:
    reg_rmw8((int)pvVar1 + 0x10,1,4,0x10);
    reg_rmw8((int)pvVar1 + 0x10,1,3,8);
    break;
  case 4:
    FUN_201204d4(param_1);
  }
  *param_3 = *(undefined1 *)((int)pvVar1 + 0x40);
  return;
}


// ===== FUN_20120a88 @ 20120a88 (20 bytes)

void FUN_20120a88(uint param_1)

{
  riic_base(param_1);
  return;
}


// ===== FUN_20120a9c @ 20120a9c (272 bytes)

undefined4 FUN_20120a9c(uint param_1,int param_2,uint param_3)

{
  void *pvVar1;
  
  if (3 < param_1) {
    return 0xffffffff;
  }
  if (param_3 != 0) {
    pvVar1 = riic_base(param_1);
    if (param_3 == 1) {
      reg_rmw8((int)pvVar1 + 0x10,1,6,0x40);
      reg_rmw8((int)pvVar1 + 0x10,1,4,0x10);
      reg_rmw8((int)pvVar1 + 0x10,1,3,8);
    }
    FUN_20120a88(param_1);
    if (param_3 != 1) {
      if (param_3 != 2) {
        for (; 3 < param_3; param_3 = param_3 - 1) {
          FUN_2012097c(param_1,0,param_2);
          param_2 = param_2 + 1;
        }
        FUN_2012097c(param_1,2,param_2);
        param_2 = param_2 + 1;
      }
      FUN_2012097c(param_1,3,param_2);
      param_2 = param_2 + 1;
    }
    FUN_2012097c(param_1,4,param_2);
    reg_rmw8((int)pvVar1 + 0x10,0,6,0x40);
    FUN_20120918(param_1);
    return 0;
  }
  return 0;
}


// ===== FUN_20120bac @ 20120bac (28 bytes)

undefined4 FUN_20120bac(uint param_1)

{
  if (param_1 < 4) {
    FUN_20120a88(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20120bc8 @ 20120bc8 (28 bytes)

undefined4 FUN_20120bc8(uint param_1)

{
  if (param_1 < 4) {
    FUN_20120918(param_1);
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20120be4 @ 20120be4 (32 bytes)

undefined4 FUN_20120be4(uint param_1)

{
  if (param_1 < 4) {
    riic_base(param_1);
    FUN_20120904();
    return 0;
  }
  return 0xffffffff;
}


// ===== FUN_20120c04 @ 20120c04 (80 bytes)

undefined4 FUN_20120c04(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      FUN_2011ff9c();
    }
    else if (param_1 == 1) {
      FUN_2011ffac();
    }
    else if (param_1 == 2) {
      FUN_2011ffbc();
    }
    else if (param_1 == 3) {
      FUN_2011ffcc();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_20120c54 @ 20120c54 (80 bytes)

undefined4 FUN_20120c54(uint param_1)

{
  undefined4 uVar1;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      FUN_2011ffdc();
    }
    else if (param_1 == 1) {
      FUN_2011ffec();
    }
    else if (param_1 == 2) {
      FUN_2011fffc();
    }
    else if (param_1 == 3) {
      FUN_20120028();
    }
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_20120cb0 @ 20120cb0 (136 bytes)

undefined4 FUN_20120cb0(uint param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  void *pvVar2;
  
  if (param_1 < 4) {
    if (param_1 == 0) {
      FUN_20120038(0);
    }
    else if (param_1 == 1) {
      FUN_20120048();
    }
    else if (param_1 == 2) {
      FUN_20120058();
    }
    else if (param_1 == 3) {
      FUN_20120068();
    }
    pvVar2 = riic_base(param_1);
    reg_rmw8((int)pvVar2 + 0x24,0,6,0x40,param_4);
    reg_read8((byte *)((int)pvVar2 + 0x24),6,0x40);
    uVar1 = 0;
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}


// ===== FUN_20120d38 @ 20120d38 (108 bytes)

void FUN_20120d38(void)

{
  DAT_208dd994 = 0;
  DAT_208dd995 = 0;
  FUN_20160c70(&DAT_208dce3c);
  FUN_20160d50(&DAT_208dce3c);
  FUN_20160cf0(&DAT_208dce3c);
  FUN_20160de4(&DAT_208dce3c);
  FUN_20160e44(&DAT_208dce3c);
  FUN_20162b50(&DAT_208dd53c);
  __aeabi_memclr4(&DAT_208dd73c,600);
  __aeabi_memset_veneer(&DAT_208dd73c,200,0xff);
  return;
}


// ===== afscope_store_frame @ 20120d40 (188 bytes)

/* 600 B -> 0x208DD73C */

void afscope_store_frame(char *param_1)

{
  if (DAT_208dd994 == '\0') {
    if (*param_1 == '\x01') {
      if ((DAT_208004a0 != '\0') || (DAT_208dd995 != '\0')) goto LAB_20157258;
      memcpy(&DAT_208dd73c,param_1,600);
      DAT_208dd73c = 0xff;
      DAT_208dd73d = 0xff;
      if (((ushort)DAT_20808a84 & 0x400) != 0) {
        memcpy(&DAT_208dd73c,&DAT_20166de8,200);
        memcpy(&DAT_208dd804,&DAT_20166eb0,400);
        return;
      }
    }
  }
  else if (DAT_208dd995 != '\0') {
LAB_20157258:
    __aeabi_memset_veneer(&DAT_208dd73c,600,0xff);
    return;
  }
  return;
}


// ===== FUN_20120d4c @ 20120d4c (20 bytes)

void FUN_20120d4c(undefined1 param_1)

{
  DAT_208dd994 = param_1;
  return;
}


// ===== FUN_20120d58 @ 20120d58 (8 bytes)

void FUN_20120d58(void)

{
  FUN_201571e8(&DAT_208dce3c);
  return;
}

