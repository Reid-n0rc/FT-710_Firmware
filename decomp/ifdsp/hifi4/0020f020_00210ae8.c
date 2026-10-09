// FT-710_IFDSP_V0101_hifi4.bin — Ghidra decompile, 50 functions

// ===== FUN_0020f020 @ 0020f020 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f020(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f060 @ 0020f060 (5 bytes)

void FUN_0020f060(void)

{
  return;
}


// ===== FUN_0020f068 @ 0020f068 (34 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f068(void)

{
  memw();
  memw();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f0bc @ 0020f0bc (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f0bc(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f154 @ 0020f154 (195 bytes)

/* WARNING: Control flow encountered bad instruction data */

undefined4
FUN_0020f154(undefined4 param_1,undefined4 *param_2,uint param_3,uint param_4,undefined4 param_5,
            uint param_6)

{
  uint uVar1;
  uint unaff_a8;
  undefined4 unaff_a9;
  uint uVar2;
  uint unaff_a11;
  uint in_a12;
  undefined4 in_a13;
  uint in_a14;
  
  if ((param_2 != (undefined4 *)0x0) && (param_3 != 0)) {
    flix();
    uVar2 = (uint)*(byte *)((int)param_2 + 0xd);
    flix();
    flix();
    if ((in_a12 & unaff_a11) == 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (unaff_a8 < uVar2) {
      uVar2 = (uint)*(byte *)((int)param_2 + 0xd);
      flix();
      cust0();
      if (in_a14 < uVar2) {
        uVar2 = (uint)*(byte *)((int)param_2 + 0xd);
        flix();
        param_2 = *(undefined4 **)(*(byte *)(param_2 + 3) + 0x1c);
        if (0xb < param_6) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
        goto LAB_0020f202;
      }
      if ((unaff_a11 & param_3) != 0) {
        return 4;
      }
      uVar1 = unaff_a11 & param_4;
    }
    else {
      if ((param_3 & 1) != 0) {
        return 4;
      }
      uVar1 = param_4 & 1;
    }
    if (uVar1 == 0) {
      memw();
      memw();
      if (param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] != 0) {
        return 0xa8e;
      }
      memw();
      *param_2 = in_a13;
      memw();
      memw();
      param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 5] = param_3;
      memw();
      param_2 = param_2 + (uint)*(byte *)(param_2 + 0xd) * 2;
      memw();
      unaff_a9 = 0;
LAB_0020f202:
      param_2[6] = param_4;
      memw();
      memw();
      flix();
      if (uVar2 != 0xfffffffd) {
        *(undefined4 *)(uVar2 + 0x1fc) = unaff_a9;
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      flix();
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return 4;
}


// ===== FUN_0020f260 @ 0020f260 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f260(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f2c0 @ 0020f2c0 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f2c0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f35c @ 0020f35c (180 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020f40a) overlaps instruction at (ram,0x0020f409)
    */

undefined4
FUN_0020f35c(undefined4 param_1,undefined4 *param_2,uint param_3,uint param_4,undefined4 param_5,
            uint param_6)

{
  uint uVar1;
  uint unaff_a8;
  uint uVar2;
  uint unaff_a11;
  uint in_a12;
  uint in_a14;
  
  if ((param_2 != (undefined4 *)0x0) && (param_3 != 0)) {
    flix();
    uVar2 = (uint)*(byte *)((int)param_2 + 0xd);
    flix();
    flix();
    if ((in_a12 & unaff_a11) == 0) {
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    if (unaff_a8 < uVar2) {
      uVar2 = (uint)*(byte *)((int)param_2 + 0xd);
      flix();
      cust0();
      if (in_a14 < uVar2) {
        flix();
        if (param_6 < 0xc) {
                    /* WARNING: Bad instruction - Truncating control flow here */
          halt_baddata();
        }
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
      if ((unaff_a11 & param_3) != 0) {
        return 4;
      }
      uVar1 = unaff_a11 & param_4;
    }
    else {
      if ((param_3 & 1) != 0) {
        return 4;
      }
      uVar1 = param_4 & 1;
    }
    if (uVar1 == 0) {
      memw();
      memw();
      if (param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] != 0) {
        return 0xa8e;
      }
      memw();
      *param_2 = 4;
      memw();
      memw();
      param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 5] = param_3;
      memw();
      memw();
      param_2[(uint)*(byte *)(param_2 + 0xd) * 2 + 6] = param_4;
      memw();
      memw();
      flix();
      if (uVar2 != 0xfffffffd) {
        *(undefined4 *)(uVar2 + 0x1fc) = 0;
        flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
        halt_baddata();
      }
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
  }
  return 4;
}


// ===== FUN_0020f468 @ 0020f468 (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f468(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f4c8 @ 0020f4c8 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f4c8(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f4f0 @ 0020f4f0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f4f0(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f518 @ 0020f518 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f518(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020f8a0 @ 0020f8a0 (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020f8a0(void)

{
  flix();
  cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fb70 @ 0020fb70 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fb70(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fb98 @ 0020fb98 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fb98(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fbc0 @ 0020fbc0 (93 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x0020fc2c) overlaps instruction at (ram,0x0020fc2a)
    */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0020fbc0(uint param_1,int param_2,undefined4 param_3,int param_4)

{
  char cVar1;
  uint in_a14;
  int in_a15;
  
  flix();
  if (in_a15 == 0) {
    return;
  }
  flix();
  cVar1 = (param_1 < in_a14) * (char)param_1 + (param_1 >= in_a14) * (char)in_a14;
  cust0();
  if (in_a14 == 0) {
    memw();
    *(char *)(param_2 + 4) = (char)(((_DAT_fffffc0d & *(uint *)(param_4 + 0x38)) >> 0x10) + 1 >> 3);
    memw();
    if ((_DAT_fffffc0d & 0x400) == 0) {
      *(char *)(param_2 + 4) = cVar1;
    }
    if (*(char *)(param_2 + 4) == '\x03') {
      *(char *)(param_2 + 4) = cVar1;
    }
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  func_0x001dc85c();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fbd0 @ 0020fbd0 (20 bytes)

void FUN_0020fbd0(int *param_1)

{
  int in_a15;
  
  if (*param_1 != 0) {
    flix();
    *(int *)(in_a15 + 0x3c) = in_a15;
  }
  return;
}


// ===== FUN_0020fbe4 @ 0020fbe4 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fbe4(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fc7c @ 0020fc7c (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fc7c(undefined4 param_1,undefined4 param_2)

{
  FUN_0020fbc0(param_2);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fd3a @ 0020fd3a (17 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fd3a(undefined4 param_1)

{
  int unaff_retaddr;
  int in_a13;
  
  if (unaff_retaddr != 0x80) {
    *(BADSPACEBASE **)(in_a13 + 0x3c) = register0x00000004;
    FUN_0020ff80();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  uRam00000040 = param_1;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fd54 @ 0020fd54 (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fd54(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fe90 @ 0020fe90 (10 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fe90(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020fea8 @ 0020fea8 (13 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020fea8(undefined4 param_1,undefined4 param_2)

{
  FUN_0020fbc0(param_2);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0020ff80 @ 0020ff80 (22 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_0020ff80(undefined4 param_1)

{
  int in_a13;
  int in_a14;
  
  flix();
  flix();
  func_0x001f01e0(param_1,in_a13 * 8 - in_a14);
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002101ec @ 002101ec (8 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002101ec(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210294 @ 00210294 (2 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210294(void)

{
  undefined4 unaff_retaddr;
  int unaff_a11;
  
  *(undefined4 *)(unaff_a11 + 4) = unaff_retaddr;
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210420 @ 00210420 (47 bytes)

void FUN_00210420(void)

{
  memw();
  memw();
  memw();
  flix();
  memw();
  flix();
  FUN_00213880();
  return;
}


// ===== FUN_002104f0 @ 002104f0 (11 bytes)

undefined4 FUN_002104f0(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x9c);
}


// ===== FUN_002104fc @ 002104fc (38 bytes)

void FUN_002104fc(int param_1,uint param_2)

{
  uint uVar1;
  
  memw();
  *(uint *)(param_1 + 0x9c) = param_2;
  memw();
  uVar1 = *(uint *)(param_1 + 0x9c);
  while ((param_2 & uVar1) != 0) {
    memw();
    uVar1 = *(uint *)(param_1 + 0x9c);
  }
  return;
}


// ===== FUN_00210524 @ 00210524 (20 bytes)

void FUN_00210524(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x90) = *(uint *)(param_1 + 0x90) | param_2;
  return;
}


// ===== FUN_00210538 @ 00210538 (11 bytes)

void FUN_00210538(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x94) = param_2;
  return;
}


// ===== FUN_00210544 @ 00210544 (11 bytes)

undefined4 FUN_00210544(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x90);
}


// ===== FUN_00210550 @ 00210550 (11 bytes)

undefined4 FUN_00210550(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x98);
}


// ===== FUN_0021055c @ 0021055c (10 bytes)

undefined4 FUN_0021055c(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x1c);
}


// ===== FUN_00210568 @ 00210568 (10 bytes)

void FUN_00210568(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x1c) = param_2;
  return;
}


// ===== FUN_00210574 @ 00210574 (18 bytes)

void FUN_00210574(int param_1,uint param_2)

{
  memw();
  memw();
  *(uint *)(param_1 + 0x10) = *(uint *)(param_1 + 0x10) | param_2;
  return;
}


// ===== FUN_00210588 @ 00210588 (10 bytes)

void FUN_00210588(int param_1,undefined4 param_2)

{
  memw();
  *(undefined4 *)(param_1 + 0x14) = param_2;
  return;
}


// ===== FUN_00210594 @ 00210594 (10 bytes)

undefined4 FUN_00210594(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x10);
}


// ===== FUN_002105a0 @ 002105a0 (10 bytes)

undefined4 FUN_002105a0(int param_1)

{
  memw();
  return *(undefined4 *)(param_1 + 0x18);
}


// ===== FUN_002105ac @ 002105ac (11 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002105ac(void)

{
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002105c0 @ 002105c0 (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002105c0(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210650 @ 00210650 (9 bytes)

void FUN_00210650(void)

{
  flix();
  FUN_00208690();
  return;
}


// ===== FUN_002106a4 @ 002106a4 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002106a4(void)

{
  int unaff_a11;
  int in_a15;
  
  flix();
  if (unaff_a11 != in_a15) {
    memw();
    flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_002106ec @ 002106ec (6 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_002106ec(void)

{
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210784 @ 00210784 (91 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Instruction at (ram,0x00210793) overlaps instruction at (ram,0x00210792)
    */

undefined8 FUN_00210784(int param_1,int param_2)

{
  int unaff_retaddr;
  uint in_a7;
  uint in_a13;
  int in_a15;
  uint in_t0;
  undefined8 uVar1;
  
  uVar1 = FUN_00210c20(param_1);
  if ((int)uVar1 != 3) {
    return CONCAT44(param_2,&DAT_00001ee6);
  }
  flix();
  if ((in_a13 & in_t0) != 0) {
    memw();
    memw();
    *(uint *)(param_1 + 0x84) = *(uint *)(param_1 + 0x84) & in_t0 | in_a7;
    flix();
    if ((int)((ulonglong)uVar1 >> 0x20) == in_a15) {
      memw();
      flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
      halt_baddata();
    }
    cust0();
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
  if (in_a13 != 0) {
    param_2 = unaff_retaddr + 5;
  }
  FUN_00210568(param_1);
  memw();
  memw();
  flix();
  return CONCAT44(param_2,param_1);
}


// ===== FUN_002107ec @ 002107ec (39 bytes)

undefined4 FUN_002107ec(int param_1)

{
  uint uVar1;
  
  memw();
  uVar1 = (*(uint *)(param_1 + 0x88) & 0xc0) >> 6;
  if (uVar1 - 2 < 2) {
    return *(undefined4 *)(&DAT_00200408 + uVar1 * 4);
  }
  return 0;
}


// ===== FUN_00210814 @ 00210814 (18 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210814(void)

{
  memw();
  flix();
  func_0x001f08fc();
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210834 @ 00210834 (23 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210834(undefined4 param_1)

{
  undefined1 *in_a13;
  undefined1 auStack_20 [32];
  
  flix();
  cust1();
  func_0x0024a154(param_1,1);
  if (auStack_20 < in_a13) {
                    /* WARNING: Bad instruction - Truncating control flow here */
    halt_baddata();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_0021089c @ 0021089c (135 bytes)

/* WARNING: Control flow encountered bad instruction data */
/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

void FUN_0021089c(undefined4 param_1)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  int extraout_a3;
  undefined4 extraout_a3_00;
  int in_a7;
  int in_a13;
  int in_a14;
  
  iVar3 = FUN_002105ac(param_1);
  flix();
  iVar2 = 0x2108bb;
  FUN_002120cc();
  *(int *)(iVar2 + 0x24) = in_a13;
  flix();
  flix();
  flix();
  flix();
  FUN_00213910(*(undefined4 *)(&DAT_00200408 + iVar3 * 4),&DAT_00200408,&DAT_40020e00);
  bVar1 = *(byte *)(extraout_a3 + 0x1c);
  if (bVar1 != 0) {
    flix();
  }
  flix();
  iVar2 = 0x2108fa;
  func_0x001f0a68();
  flix();
  flix();
  flix();
  iVar2 = *(int *)(iVar2 + 4);
  if (in_a14 == 0) {
    *(uint *)(ram0x00000034 + 0x38) = (uint)bVar1;
    func_0x001fb6d8(iVar2,extraout_a3_00,in_a13 + iVar2 + in_a7);
    flix();
    func_0x001f0ae4();
    flix();
  }
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}


// ===== FUN_00210ae8 @ 00210ae8 (35 bytes)

/* WARNING: Control flow encountered bad instruction data */

void FUN_00210ae8(int param_1)

{
  undefined1 unaff_a10;
  
  *(undefined **)(param_1 + 0x18) = &DAT_002625a0;
  *(undefined4 *)(param_1 + 0x14) = 12500000;
  flix();
  *(undefined1 *)(param_1 + 0xc) = unaff_a10;
  flix();
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

