// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== main @ fff8f658 (5 bytes)

/* Called from PowerON_Reset after BSP init; calls app_main */

void main(void)

{
  app_main();
  return;
}


// ===== FUN_fff8f65e @ fff8f65e (358 bytes)

void FUN_fff8f65e(void)

{
  byte bVar1;
  
  DAT_000803fe = 0xa50b;
  bVar1 = DAT_0008c11f;
  DAT_0008c11f = bVar1 & 0x7f;
  bVar1 = DAT_0008c11f;
  DAT_0008c11f = bVar1 | 0x40;
  DAT_0008c4cc = 0;
  FUN_fff8f7c4();
  FUN_fff92e49();
  FUN_fff927a9();
  FUN_fff927e5();
  FUN_fff92851();
  FUN_fff92b17();
  R_SCI0_Create();
  R_SCI1_Create();
  R_SCI2_Create();
  R_SCI3_Create();
  R_SCI4_Create();
  R_SCI5_Create();
  FUN_fff92e25();
  FUN_fff949b4();
  FUN_fff94a65();
  FUN_fffb2734();
  FUN_fffc913b();
  R_SCI6_Create_IIC();
  R_SCI7_Create();
  FUN_fffedd07();
  FUN_fff8f7ca();
  FUN_fff8fffb(10,&DAT_fff8f65d);
  FUN_fff8fffb(7,&LAB_fff927e0);
  FUN_fff8fffb(0x14,&LAB_fff9345a);
  FUN_fff8fffb(0x15,&LAB_fff934f1);
  FUN_fff8fffb(0x16,&LAB_fff93787);
  FUN_fff8fffb(0x17,&LAB_fff9381e);
  FUN_fff8fffb(0x18,&LAB_fff93cc8);
  FUN_fff8fffb(0x19,&LAB_fff93d5f);
  FUN_fff8fffb(0x1a,&LAB_fff94148);
  FUN_fff8fffb(0x1b,&LAB_fff941df);
  FUN_fff8fffb(0x1c,&LAB_fff94477);
  FUN_fff8fffb(0x1d,&LAB_fff9450e);
  FUN_fff8fffb(0x1e,&LAB_fff9489d);
  FUN_fff8fffb(0x1f,&LAB_fff94934);
  FUN_fff8fffb(0x20,&LAB_fffc93ef);
  FUN_fff8fffb(0x22,&LAB_fffc97ec);
  FUN_fff8fffb(0x23,&LAB_fffc9880);
  bVar1 = DAT_0008c11f;
  DAT_0008c11f = bVar1 & 0xbf;
  bVar1 = DAT_0008c11f;
  DAT_0008c11f = bVar1 | 0x80;
  DAT_000803fe = 0xa500;
  return;
}


// ===== FUN_fff8f7c4 @ fff8f7c4 (5 bytes)

void FUN_fff8f7c4(void)

{
  FUN_fff8f7c9();
  return;
}


// ===== FUN_fff8f7c9 @ fff8f7c9 (1 bytes)

void FUN_fff8f7c9(void)

{
  return;
}


// ===== FUN_fff8f7ca @ fff8f7ca (34 bytes)

void FUN_fff8f7ca(void)

{
  byte bVar1;
  
  bVar1 = DAT_0008720d;
  DAT_0008720d = bVar1 & 0xbf;
  bVar1 = DAT_0008736e;
  DAT_0008736e = bVar1 & 0xf8 | 8;
  bVar1 = DAT_0008720d;
  DAT_0008720d = bVar1 | 0x40;
  return;
}


// ===== FUN_fff8f7ec @ fff8f7ec (20 bytes)

void FUN_fff8f7ec(void)

{
  FUN_fff8f800();
  FUN_fff8f802();
  FUN_fff8f804();
  FUN_fff91608();
  FUN_fff8f809();
  FUN_fff8f879();
  return;
}


// ===== FUN_fff8f800 @ fff8f800 (2 bytes)

void FUN_fff8f800(void)

{
  return;
}


// ===== FUN_fff8f802 @ fff8f802 (2 bytes)

void FUN_fff8f802(void)

{
  return;
}


// ===== FUN_fff8f804 @ fff8f804 (5 bytes)

void FUN_fff8f804(void)

{
  FUN_fff8f65e();
  return;
}


// ===== FUN_fff8f809 @ fff8f809 (112 bytes)

/* WARNING: Removing unreachable block (ram,0xfff8f861) */

void FUN_fff8f809(void)

{
  undefined4 uVar1;
  uint uVar2;
  
  DAT_000803fe = 0xa502;
  uVar1 = DAT_00080010;
  uVar2 = DAT_00080010;
  DAT_00080010 = uVar2 & 0xfffeffff;
  uVar1 = DAT_00080010;
  DAT_00089163 = 3;
  DAT_0008916e = 0x20;
  DAT_00089163 = 2;
  uVar2 = DAT_00080010;
  DAT_00080010 = uVar2 & 0xfffeffff;
  DAT_000803fe = 0xa500;
  return;
}


// ===== FUN_fff8f879 @ fff8f879 (66 bytes)

void FUN_fff8f879(void)

{
  uint uVar1;
  undefined4 local_4;
  
  uVar1 = DAT_000c5800;
  local_4 = uVar1 & 0xfffca9b8 | 0x42130;
  DAT_000c5800 = local_4;
  return;
}


// ===== FUN_fff8f8bb @ fff8f8bb (29 bytes)

void FUN_fff8f8bb(byte param_1)

{
  uint uVar1;
  
  do {
    uVar1 = DAT_000840c0;
  } while ((uVar1 & 0x100) != 0);
  DAT_00084080 = (uint)param_1;
  return;
}


// ===== _INIT_IOLIB @ fff8f8f5 (232 bytes)

/* CC-RX runtime: sets up stdin/stdout/stderr FILE structs at 0x25D80 */

void _INIT_IOLIB(void)

{
  int iVar1;
  
  DAT_0001ff74 = &DAT_00025d80;
  DAT_0001ff78 = &DAT_00025dc8;
  DAT_0001ff7c = &DAT_00025e10;
  FUN_fffedd9a("C:\\stdin",&DAT_fff8f2f2,&DAT_00025d80);
  DAT_00025d80 = 0x801;
  PTR_DAT_00025d88 = PTR_DAT_00025d84 + 1;
  iVar1 = FUN_fffedd9a("C:\\stdout",&DAT_fff8f2fe,&DAT_00025dc8);
  if (iVar1 == 0) {
    DAT_00025dc8 = 0xffff;
  }
  DAT_00025dc8 = DAT_00025dc8 | 0x800;
  PTR_DAT_00025dd0 = PTR_DAT_00025dcc + 1;
  iVar1 = FUN_fffedd9a("C:\\stderr",&DAT_fff8f2fe,&DAT_00025e10);
  if (iVar1 == 0) {
    DAT_00025e10 = 0xffff;
  }
  DAT_00025e10 = DAT_00025e10 | 0x800;
  PTR_DAT_00025e18 = PTR_DAT_00025e14 + 1;
  return;
}


// ===== _CLOSEALL @ fff8f9dd (62 bytes)

/* CC-RX runtime: closes the 20 stdio slots at 0x1FF74 (reached only if main returns) */

void _CLOSEALL(void)

{
  int local_4;
  
  for (local_4 = 0; local_4 < 0x14; local_4 = local_4 + 1) {
    if ((*(ushort *)(&DAT_0001ff74)[local_4] & 7) != 0) {
      FUN_fffeddc9((&DAT_0001ff74)[local_4]);
    }
  }
  return;
}


// ===== FUN_fff8fa1b @ fff8fa1b (167 bytes)

void FUN_fff8fa1b(char *param_1,byte param_2,undefined4 param_3,undefined4 param_4,uint *param_5)

{
  char cVar1;
  char cVar2;
  bool bVar3;
  char *pcVar4;
  char *pcVar5;
  int iVar6;
  undefined4 *in_R14;
  undefined4 *puVar7;
  byte bVar8;
  
  iVar6 = -1;
  pcVar5 = "C:\\stdin";
  pcVar4 = param_1;
  do {
    if (iVar6 == 0) {
      bVar8 = 3;
      bVar3 = true;
      goto code_r0xfff8fa31;
    }
    cVar1 = *pcVar4;
    cVar2 = *pcVar5;
    pcVar4 = pcVar4 + 1;
    pcVar5 = pcVar5 + 1;
    iVar6 = iVar6 + -1;
  } while ((cVar1 != '\0') && (cVar1 == cVar2));
  bVar8 = -1 < (char)(cVar1 - cVar2);
  bVar3 = false;
code_r0xfff8fa31:
  if ((bool)(bVar8 & 1)) {
    *in_R14 = 1;
  }
  if (!(bool)(bVar8 & 1) || bVar3) {
    *param_5 = (uint)(!(bool)(bVar8 & 1) || bVar3);
  }
  puVar7 = (undefined4 *)((int)in_R14 - ((uint)param_5 & 0xff));
  if (puVar7 == (undefined4 *)0x0) {
    if ((param_2 & 1) != 0) {
      DAT_00001404 = param_2;
    }
  }
  else {
    iVar6 = -1;
    pcVar5 = "C:\\stdout";
    pcVar4 = param_1;
    do {
      if (iVar6 == 0) {
        bVar8 = 3;
        bVar3 = true;
        goto code_r0xfff8fa63;
      }
      cVar1 = *pcVar4;
      cVar2 = *pcVar5;
      pcVar4 = pcVar4 + 1;
      pcVar5 = pcVar5 + 1;
      iVar6 = iVar6 + -1;
    } while ((cVar1 != '\0') && (cVar1 == cVar2));
    bVar8 = -1 < (char)(cVar1 - cVar2);
    bVar3 = false;
code_r0xfff8fa63:
    if ((bool)(bVar8 & 1)) {
      *puVar7 = 1;
    }
    if (!(bool)(bVar8 & 1) || bVar3) {
      *param_5 = (uint)(!(bool)(bVar8 & 1) || bVar3);
    }
    puVar7 = (undefined4 *)((int)puVar7 - ((uint)param_5 & 0xff));
    if (puVar7 == (undefined4 *)0x0) {
      if ((param_2 & 2) != 0) {
        DAT_00001405 = param_2;
      }
    }
    else {
      iVar6 = -1;
      pcVar4 = "C:\\stderr";
      do {
        if (iVar6 == 0) {
          bVar8 = 3;
          bVar3 = true;
          goto code_r0xfff8fa95;
        }
        cVar1 = *param_1;
        cVar2 = *pcVar4;
        param_1 = param_1 + 1;
        pcVar4 = pcVar4 + 1;
        iVar6 = iVar6 + -1;
      } while ((cVar1 != '\0') && (cVar1 == cVar2));
      bVar8 = -1 < (char)(cVar1 - cVar2);
      bVar3 = false;
code_r0xfff8fa95:
      if ((bool)(bVar8 & 1)) {
        *puVar7 = 1;
      }
      if (!(bool)(bVar8 & 1) || bVar3) {
        *param_5 = (uint)(!(bool)(bVar8 & 1) || bVar3);
      }
      if ((puVar7 == (undefined4 *)((uint)param_5 & 0xff)) && ((param_2 & 2) != 0)) {
        DAT_00001406 = param_2;
      }
    }
  }
  return;
}


// ===== FUN_fff8fac2 @ fff8fac2 (11 bytes)

undefined4 FUN_fff8fac2(void)

{
  return 1;
}


// ===== FUN_fff8facd @ fff8facd (140 bytes)

void FUN_fff8facd(int param_1,undefined1 *param_2,int param_3)

{
  undefined1 uVar1;
  bool bVar2;
  int local_14;
  undefined1 *local_8;
  
  if ((((&DAT_00001404)[param_1] & 2) == 0) && (((&DAT_00001404)[param_1] & 4) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if ((bVar2) && (param_1 != 0)) {
    if ((param_1 == 1) || (param_1 == 2)) {
      bVar2 = true;
    }
    else {
      bVar2 = false;
    }
    local_14 = param_3;
    local_8 = param_2;
    if (bVar2) {
      for (; 0 < local_14; local_14 = local_14 + -1) {
        uVar1 = *local_8;
        local_8 = local_8 + 1;
        FUN_fff8f8bb(uVar1);
      }
    }
  }
  return;
}


// ===== PowerON_Reset @ fff8fbdb (100 bytes)

/* Reset: sets USP=0x1004 ISP=0x1404 INTB=0xFFF8E6DC EXTB=0xFFFFFF80 FPSW=0x100, calls init chain,
   then main */

void PowerON_Reset(void)

{
  hw_init_clock();
  _INITSCT();
  FUN_fff8ff5f();
  _INIT_IOLIB();
  FUN_fff8ffc4();
  FUN_fff8ff3d();
  FUN_fff8f7ec();
  FUN_fff90097(0xb,1,0x10000000);
  main();
  _CLOSEALL();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_fff8fc4d @ fff8fc4d (10 bytes)

void FUN_fff8fc4d(void)

{
  FUN_fff91303();
  return;
}


// ===== FUN_fff8fc57 @ fff8fc57 (277 bytes)

undefined1 FUN_fff8fc57(uint param_1,undefined *param_2)

{
  bool bVar1;
  uint extraout_R2;
  uint uVar2;
  uint uStack_20;
  uint uStack_1c;
  uint uStack_14;
  
  if ((param_2 == &DAT_000f4240) || (param_2 == (undefined *)0x3e8)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (param_2 != (undefined *)0x1)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    return 0;
  }
  uStack_14 = FUN_fff8fc4d();
  if (param_2 == &DAT_000f4240) {
    uVar2 = 0xffffffff;
    if (uStack_14 != 0) {
      uVar2 = 0xffffffff / uStack_14;
    }
    if (param_1 <= uVar2) {
      bVar1 = true;
      goto LAB_fff8fcb2;
    }
  }
  bVar1 = false;
LAB_fff8fcb2:
  if (bVar1) {
    uStack_14 = uStack_14 * param_1;
    if (param_2 != (undefined *)0x0) {
      uStack_14 = uStack_14 / (uint)param_2;
    }
    if (uStack_14 < 3) {
      uStack_14 = 0;
    }
    else {
      uStack_14 = uStack_14 - 2;
    }
    uStack_20 = uStack_14 >> 2;
    if (uStack_20 == 0) {
      return 0;
    }
  }
  else {
    uStack_20 = FUN_fffede41((int)((ulonglong)param_1 * (ulonglong)uStack_14),
                             (int)((ulonglong)param_1 * (ulonglong)uStack_14 >> 0x20),param_2,
                             (int)param_2 >> 0x1f);
    uStack_1c = extraout_R2;
    if (-(uint)(uStack_20 < 3) <= extraout_R2) {
      bVar1 = 1 < uStack_20;
      uStack_20 = uStack_20 - 2;
      uStack_1c = (extraout_R2 - 1) +
                  (uint)(CARRY4(extraout_R2,(uint)bVar1) || extraout_R2 + bVar1 != 0);
    }
    uStack_20 = uStack_20 >> 2;
    if ((uStack_1c >> 2 == 0) && (uStack_20 != 0)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      return 0;
    }
  }
  do {
    uStack_20 = uStack_20 - 1;
  } while (uStack_20 != 0);
  return 1;
}


// ===== FUN_fff8fd84 @ fff8fd84 (23 bytes)

void FUN_fff8fd84(void)

{
  uint in_PSW;
  
  if ((in_PSW & 0x100000) != 0) {
    return;
  }
  return;
}


// ===== FUN_fff8fd9b @ fff8fd9b (29 bytes)

void FUN_fff8fd9b(void)

{
  return;
}


// ===== FUN_fff8fdb8 @ fff8fdb8 (132 bytes)

undefined1 FUN_fff8fdb8(undefined4 param_1)

{
  uint in_PSW;
  undefined1 local_6;
  
  local_6 = 0;
  if ((in_PSW & 0x100000) == 0) {
    local_6 = 1;
    switch(param_1) {
    case 0:
      break;
    case 1:
      break;
    case 2:
      break;
    case 3:
      break;
    case 4:
      break;
    case 5:
      break;
    case 6:
      break;
    case 7:
      break;
    case 8:
      break;
    case 9:
      break;
    case 10:
      break;
    case 0xb:
      break;
    case 0xc:
      break;
    case 0xd:
      break;
    case 0xe:
      break;
    case 0xf:
      break;
    default:
      local_6 = 0;
    }
  }
  return local_6;
}


// ===== FUN_fff8ff3d @ fff8ff3d (34 bytes)

void FUN_fff8ff3d(void)

{
  uint local_4;
  
  for (local_4 = 0; local_4 < 4; local_4 = local_4 + 1) {
    *(undefined2 *)(&DAT_0001b5fc + local_4 * 2) = 0;
  }
  return;
}


// ===== FUN_fff8ff5f @ fff8ff5f (35 bytes)

void FUN_fff8ff5f(void)

{
  uint local_4;
  
  for (local_4 = 0; local_4 < 0x74; local_4 = local_4 + 1) {
    *(undefined4 *)(&DAT_0001ffc4 + local_4 * 4) = 0;
  }
  return;
}


// ===== FUN_fff8ff82 @ fff8ff82 (33 bytes)

void FUN_fff8ff82(uint param_1)

{
  *(uint *)(&DAT_00087200 + (param_1 >> 3)) =
       *(uint *)(&DAT_00087200 + (param_1 >> 3)) | 1 << (param_1 & 7);
  return;
}


// ===== FUN_fff8ffa3 @ fff8ffa3 (33 bytes)

void FUN_fff8ffa3(uint param_1)

{
  *(uint *)(&DAT_00087200 + (param_1 >> 3)) =
       *(uint *)(&DAT_00087200 + (param_1 >> 3)) & ~(1 << (param_1 & 7));
  return;
}


// ===== FUN_fff8ffc4 @ fff8ffc4 (55 bytes)

void FUN_fff8ffc4(void)

{
  uint local_4;
  
  for (local_4 = 0; local_4 < 0x5f; local_4 = local_4 + 1) {
    *(undefined4 *)(&DAT_00020194 + local_4 * 4) = 0x10000000;
  }
  FUN_fff92014();
  FUN_fff9089e(0);
  FUN_fff9089e(1);
  return;
}


// ===== FUN_fff8fffb @ fff8fffb (75 bytes)

void FUN_fff8fffb(int param_1,int param_2)

{
  bool bVar1;
  
  if ((param_2 == 0) || (param_2 == 0x10000000)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (bVar1) {
    *(undefined4 *)(&DAT_00020194 + param_1 * 4) = 0x10000000;
  }
  else {
    *(int *)(&DAT_00020194 + param_1 * 4) = param_2;
  }
  return;
}


// ===== FUN_fff90097 @ fff90097 (234 bytes)

void FUN_fff90097(undefined4 param_1,int param_2,undefined4 *param_3)

{
  bool bVar1;
  
  if (param_2 == 6) {
    FUN_fff90181(0,param_3);
  }
  else if (param_2 == 1) {
    FUN_fff916ac(param_1,1);
  }
  else if (param_2 == 2) {
    FUN_fff916ac(param_1,0);
  }
  else if (param_2 == 3) {
    if ((param_3 == (undefined4 *)0x0) || (param_3 == (undefined4 *)0x10000000)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      FUN_fff901f8(param_1,1,*param_3);
    }
  }
  else if (param_2 == 4) {
    FUN_fff901f8(param_1,0,0);
  }
  else if (param_2 == 5) {
    FUN_fff90181(1,param_3);
  }
  return;
}


// ===== FUN_fff90181 @ fff90181 (119 bytes)

/* WARNING: Removing unreachable block (ram,0xfff901f5) */

undefined4 FUN_fff90181(char param_1,uint *param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint in_PSW;
  uint local_20;
  undefined4 local_14;
  
  uVar3 = in_PSW & 0xfffffff0 | (uint)(param_2 == (uint *)0x0) << 1;
  if (((bool)((byte)(uVar3 >> 1) & 1)) ||
     (uVar3 = in_PSW & 0xfffffff0 | (uint)(param_2 == (uint *)0x10000000) << 1,
     (bool)((byte)(uVar3 >> 1) & 1))) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if (bVar1) {
    if ((uVar3 & 0x100000) == 0) {
      local_14 = 0;
      if (param_1 == '\x01') {
        local_20 = *param_2;
      }
      else {
        uVar3 = FUN_fff8fd9b();
        *param_2 = uVar3;
        local_20 = 0xf;
      }
      if (*param_2 < 0xf) {
        cVar2 = FUN_fff8fdb8(local_20);
        if (cVar2 == '\0') {
          local_14 = 5;
        }
      }
      else {
        local_14 = 5;
      }
    }
    else {
      local_14 = 3;
    }
  }
  else {
    local_14 = 2;
  }
  return local_14;
}


// ===== FUN_fff901f8 @ fff901f8 (949 bytes)

void FUN_fff901f8(int param_1,char param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  uint local_1c;
  
  if (param_2 == '\x01') {
    if ((param_3 == 0) || (0xf < param_3)) {
      bVar3 = true;
    }
    else {
      bVar3 = false;
    }
    if (bVar3) {
      bVar3 = true;
      goto LAB_fff90228;
    }
  }
  bVar3 = false;
LAB_fff90228:
  if (!bVar3) {
    if ((param_1 < 0x10) || (0xf < param_1)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (!bVar3) {
      if ((param_1 < 0x11) || (0x12 < param_1)) {
        bVar3 = false;
      }
      else {
        bVar3 = true;
      }
      local_1c = param_3;
      if (bVar3) {
        if (param_2 == '\x01') {
          FUN_fff8ffa3(0x6a);
          bVar1 = DAT_0008706a;
          DAT_0008706a = bVar1 & 0xfe;
          bVar1 = DAT_0008736a;
          if (param_3 <= (bVar1 & 0xf)) {
            bVar1 = DAT_0008736a;
            local_1c = bVar1 & 0xf;
          }
          bVar1 = DAT_0008736a;
          DAT_0008736a = bVar1 & 0xf0 | (byte)local_1c & 0xf;
          FUN_fff8ff82(0x6a);
        }
        else {
          iVar2 = DAT_00087640;
          if (iVar2 == 0) {
            FUN_fff8ffa3(0x6a);
            bVar1 = DAT_0008736a;
            DAT_0008736a = bVar1 & 0xf0;
          }
        }
      }
      else {
        if ((param_1 < 0x14) || (0x30 < param_1)) {
          bVar3 = false;
        }
        else {
          bVar3 = true;
        }
        if (bVar3) {
          if (param_2 == '\x01') {
            FUN_fff8ffa3(0x6e);
            bVar1 = DAT_0008706e;
            DAT_0008706e = bVar1 & 0xfe;
            bVar1 = DAT_0008736e;
            if (param_3 <= (bVar1 & 0xf)) {
              bVar1 = DAT_0008736e;
              local_1c = bVar1 & 0xf;
            }
            bVar1 = DAT_0008736e;
            DAT_0008736e = bVar1 & 0xf0 | (byte)local_1c & 0xf;
            FUN_fff8ff82(0x6e);
          }
          else {
            iVar2 = DAT_00087670;
            if (iVar2 == 0) {
              FUN_fff8ffa3(0x6e);
              bVar1 = DAT_0008736e;
              DAT_0008736e = bVar1 & 0xf0;
            }
          }
        }
        else {
          if ((param_1 < 0x32) || (0x49 < param_1)) {
            bVar3 = false;
          }
          else {
            bVar3 = true;
          }
          if (bVar3) {
            if (param_2 == '\x01') {
              FUN_fff8ffa3(0x6f);
              bVar1 = DAT_0008706f;
              DAT_0008706f = bVar1 & 0xfe;
              bVar1 = DAT_0008736f;
              if (param_3 <= (bVar1 & 0xf)) {
                bVar1 = DAT_0008736f;
                local_1c = bVar1 & 0xf;
              }
              bVar1 = DAT_0008736f;
              DAT_0008736f = bVar1 & 0xf0 | (byte)local_1c & 0xf;
              FUN_fff8ff82(0x6f);
            }
            else {
              iVar2 = DAT_00087674;
              if (iVar2 == 0) {
                FUN_fff8ffa3(0x6f);
                bVar1 = DAT_0008736f;
                DAT_0008736f = bVar1 & 0xf0;
              }
            }
          }
          else {
            if ((param_1 < 0x4b) || (0x4b < param_1)) {
              bVar3 = false;
            }
            else {
              bVar3 = true;
            }
            if (bVar3) {
              if (param_2 == '\x01') {
                FUN_fff8ffa3(0x6b);
                bVar1 = DAT_0008706b;
                DAT_0008706b = bVar1 & 0xfe;
                bVar1 = DAT_0008736b;
                if (param_3 <= (bVar1 & 0xf)) {
                  bVar1 = DAT_0008736b;
                  local_1c = bVar1 & 0xf;
                }
                bVar1 = DAT_0008736b;
                DAT_0008736b = bVar1 & 0xf0 | (byte)local_1c & 0xf;
                FUN_fff8ff82(0x6b);
              }
              else {
                iVar2 = DAT_00087678;
                if (iVar2 == 0) {
                  FUN_fff8ffa3(0x6b);
                  bVar1 = DAT_0008736b;
                  DAT_0008736b = bVar1 & 0xf0;
                }
              }
            }
            else {
              if ((param_1 < 0x4d) || (0x56 < param_1)) {
                bVar3 = false;
              }
              else {
                bVar3 = true;
              }
              if (bVar3) {
                if (param_2 == '\x01') {
                  FUN_fff8ffa3(0x70);
                  bVar1 = DAT_00087070;
                  DAT_00087070 = bVar1 & 0xfe;
                  bVar1 = DAT_00087370;
                  if (param_3 <= (bVar1 & 0xf)) {
                    bVar1 = DAT_00087370;
                    local_1c = bVar1 & 0xf;
                  }
                  bVar1 = DAT_00087370;
                  DAT_00087370 = bVar1 & 0xf0 | (byte)local_1c & 0xf;
                  FUN_fff8ff82(0x70);
                }
                else {
                  iVar2 = DAT_00087870;
                  if (iVar2 == 0) {
                    FUN_fff8ffa3(0x70);
                    bVar1 = DAT_00087370;
                    DAT_00087370 = bVar1 & 0xf0;
                  }
                }
              }
              else {
                if ((param_1 < 0x58) || (0x5c < param_1)) {
                  bVar3 = false;
                }
                else {
                  bVar3 = true;
                }
                if (bVar3) {
                  if (param_2 == '\x01') {
                    FUN_fff8ffa3(0x71);
                    bVar1 = DAT_00087071;
                    DAT_00087071 = bVar1 & 0xfe;
                    bVar1 = DAT_00087371;
                    if (param_3 <= (bVar1 & 0xf)) {
                      bVar1 = DAT_00087371;
                      local_1c = bVar1 & 0xf;
                    }
                    bVar1 = DAT_00087371;
                    DAT_00087371 = bVar1 & 0xf0 | (byte)local_1c & 0xf;
                    FUN_fff8ff82(0x71);
                  }
                  else {
                    iVar2 = DAT_00087874;
                    if (iVar2 == 0) {
                      FUN_fff8ffa3(0x71);
                      bVar1 = DAT_00087371;
                      DAT_00087371 = bVar1 & 0xf0;
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return;
}


// ===== SuperVisorInst @ fff905ad (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfff905be) */
/* WARNING: Removing unreachable block (ram,0xfff905ad) */
/* WARNING: Removing unreachable block (ram,0xfff905af) */
/* WARNING: Removing unreachable block (ram,0xfff905c0) */

undefined4 SuperVisorInst(undefined4 param_1)

{
  FUN_fff90097(0,0,0x10000000);
  return param_1;
}


// ===== AccessExc @ fff905c4 (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfff905d5) */
/* WARNING: Removing unreachable block (ram,0xfff905c4) */
/* WARNING: Removing unreachable block (ram,0xfff905c6) */
/* WARNING: Removing unreachable block (ram,0xfff905d7) */

undefined4 AccessExc(undefined4 param_1)

{
  FUN_fff90097(4,0,0x10000000);
  return param_1;
}


// ===== UndefinedInst @ fff905db (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfff905ec) */
/* WARNING: Removing unreachable block (ram,0xfff905db) */
/* WARNING: Removing unreachable block (ram,0xfff905dd) */
/* WARNING: Removing unreachable block (ram,0xfff905ee) */

undefined4 UndefinedInst(undefined4 param_1)

{
  FUN_fff90097(1,0,0x10000000);
  return param_1;
}


// ===== FloatingPoint @ fff905f2 (41 bytes)

/* WARNING: Removing unreachable block (ram,0xfff90615) */
/* WARNING: Removing unreachable block (ram,0xfff905f2) */
/* WARNING: Removing unreachable block (ram,0xfff905f4) */
/* WARNING: Removing unreachable block (ram,0xfff90617) */

undefined4 FloatingPoint(undefined4 param_1)

{
  FUN_fff90097(3,0,0x10000000);
  return param_1;
}


// ===== NMI @ fff9061b (487 bytes)

/* WARNING: Removing unreachable block (ram,0xfff9061b) */
/* WARNING: Removing unreachable block (ram,0xfff9061d) */

void NMI(void)

{
  byte bVar1;
  bool bVar2;
  
  bVar1 = DAT_00087580;
  if (((bVar1 & 1) == 1) && (bVar1 = DAT_00087581, (bVar1 & 1) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff90097(2,0,0x10000000);
    bVar1 = DAT_00087582;
    DAT_00087582 = bVar1 | 1;
  }
  bVar1 = DAT_00087580;
  if (((bVar1 >> 1 & 1) == 1) && (bVar1 = DAT_00087581, (bVar1 >> 1 & 1) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff90097(5,0,0x10000000);
    bVar1 = DAT_00087582;
    DAT_00087582 = bVar1 | 2;
  }
  bVar1 = DAT_00087580;
  if (((bVar1 >> 2 & 1) == 1) && (bVar1 = DAT_00087581, (bVar1 >> 2 & 1) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff90097(6,0,0x10000000);
    bVar1 = DAT_00087582;
    DAT_00087582 = bVar1 | 4;
  }
  bVar1 = DAT_00087580;
  if (((bVar1 >> 3 & 1) == 1) && (bVar1 = DAT_00087581, (bVar1 >> 3 & 1) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff90097(7,0,0x10000000);
    bVar1 = DAT_00087582;
    DAT_00087582 = bVar1 | 8;
  }
  bVar1 = DAT_00087580;
  if (((bVar1 >> 4 & 1) == 1) && (bVar1 = DAT_00087581, (bVar1 >> 4 & 1) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff90097(8,0,0x10000000);
    bVar1 = DAT_00087582;
    DAT_00087582 = bVar1 | 0x10;
  }
  bVar1 = DAT_00087580;
  if (((bVar1 >> 5 & 1) == 1) && (bVar1 = DAT_00087581, (bVar1 >> 5 & 1) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    FUN_fff90097(9,0,0x10000000);
    bVar1 = DAT_00087582;
    DAT_00087582 = bVar1 | 0x20;
  }
  bVar1 = DAT_00087580;
  if (((bVar1 >> 6 & 1) == 1) && (bVar1 = DAT_00087581, (bVar1 >> 6 & 1) == 1)) {
    bVar2 = true;
  }
  else {
    bVar2 = false;
  }
  if (bVar2) {
    bVar1 = DAT_00081201;
    if ((bVar1 & 1) == 1) {
      FUN_fff90097(0xc,0,0x10000000);
      bVar1 = DAT_00081201;
      DAT_00081201 = bVar1 & 0xfe;
    }
    bVar1 = DAT_00081241;
    if ((bVar1 & 1) == 1) {
      FUN_fff90097(0xd,0,0x10000000);
      bVar1 = DAT_00081241;
      DAT_00081241 = bVar1 & 0xfe;
    }
  }
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== Undefined_0xD8 @ fff90802 (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfff90813) */
/* WARNING: Removing unreachable block (ram,0xfff90802) */
/* WARNING: Removing unreachable block (ram,0xfff90804) */
/* WARNING: Removing unreachable block (ram,0xfff90815) */

undefined4 Undefined_0xD8(undefined4 param_1)

{
  FUN_fff90097(10,0,0x10000000);
  return param_1;
}


// ===== vec016_BSC_BUSERR @ fff90819 (30 bytes)

/* WARNING: Removing unreachable block (ram,0xfff90831) */
/* WARNING: Removing unreachable block (ram,0xfff90819) */
/* WARNING: Removing unreachable block (ram,0xfff9081b) */
/* WARNING: Removing unreachable block (ram,0xfff90833) */

undefined4 vec016_BSC_BUSERR(undefined4 param_1)

{
  byte bVar1;
  
  bVar1 = DAT_00081300;
  DAT_00081300 = bVar1 | 1;
  FUN_fff90097(0xb,0,0x10000000);
  return param_1;
}


// ===== FUN_fff90837 @ fff90837 (39 bytes)

/* WARNING: Control flow encountered unimplemented instructions */

void FUN_fff90837(void)

{
                    /* WARNING: Unimplemented instruction - Truncating control flow here */
  halt_unimplemented();
}


// ===== FUN_fff9086c @ fff9086c (25 bytes)

undefined1 FUN_fff9086c(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fff90837(&DAT_0001ffc4 + param_1 * 4);
  return uVar1;
}


// ===== FUN_fff9089e @ fff9089e (273 bytes)

void FUN_fff9089e(int param_1)

{
  byte bStack_11;
  int local_10;
  char cStack_9;
  
  local_10 = 0;
  if (param_1 == 1) {
    cStack_9 = FUN_fff9086c(0x73);
  }
  else if (param_1 == 0) {
    cStack_9 = FUN_fff9086c(0x72);
  }
  else {
    local_10 = 3;
  }
  if ((local_10 == 0) && (cStack_9 == '\x01')) {
    *(undefined4 *)(&DAT_00020310 + param_1 * 4) = 1;
    FUN_fff90f9b(param_1,2,0x10000000);
    FUN_fff90f9b(param_1,5,0x10000000);
    FUN_fff90f9b(param_1,3);
    (&DAT_00001432)[param_1] = 1;
    for (bStack_11 = 0; bStack_11 < 9; bStack_11 = bStack_11 + 1) {
      *(undefined4 *)(&DAT_00020318 + (uint)bStack_11 * 0xc + param_1 * 0x6c) = 0;
      *(undefined1 **)(param_1 * 0x6c + (uint)bStack_11 * 0xc + 0x2031c) = &LAB_fff910bc;
      *(undefined4 *)(param_1 * 0x6c + (uint)bStack_11 * 0xc + 0x20320) = 0x10000000;
    }
    (&DAT_0000142e)[param_1] = 0;
    (&DAT_00001430)[param_1] = 0;
    (&DAT_0000142c)[param_1] = 0;
    FUN_fff90f9b(param_1,1,0x10000000);
  }
  return;
}


// ===== FUN_fff90ba6 @ fff90ba6 (144 bytes)

void FUN_fff90ba6(int param_1,byte *param_2)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = DAT_00087303;
    *param_2 = bVar1 & 0xf;
    bVar1 = DAT_00087203;
    param_2[1] = bVar1 >> 2 & 1;
    bVar1 = DAT_0008701a;
    param_2[2] = bVar1 & 1;
    param_2[3] = bRam00001433;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = DAT_00087303;
  *param_2 = bVar1 & 0xf;
  bVar1 = DAT_00087203;
  param_2[1] = bVar1 >> 3 & 1;
  bVar1 = DAT_0008701b;
  param_2[2] = bVar1 & 1;
  param_2[3] = DAT_00001432;
  return;
}


// ===== FUN_fff90c36 @ fff90c36 (32 bytes)

void FUN_fff90c36(int param_1)

{
  if (param_1 == 1) {
    FUN_fff8ff82(0x1a);
    return;
  }
  if (param_1 != 0) {
    return;
  }
  FUN_fff8ff82(0x1b);
  return;
}


// ===== FUN_fff90c56 @ fff90c56 (32 bytes)

void FUN_fff90c56(int param_1)

{
  if (param_1 == 1) {
    FUN_fff8ffa3(0x1a);
    return;
  }
  if (param_1 != 0) {
    return;
  }
  FUN_fff8ffa3(0x1b);
  return;
}


// ===== FUN_fff90c76 @ fff90c76 (171 bytes)

void FUN_fff90c76(int param_1,byte *param_2)

{
  byte bVar1;
  undefined1 auStack_1c [7];
  byte bStack_15;
  byte *local_14;
  byte *local_8;
  int local_4;
  
  if (*param_2 < 0x10) {
    local_14 = param_2;
    local_8 = param_2;
    local_4 = param_1;
    FUN_fff90097(0x5e,6,auStack_1c);
    if (local_4 == 1) {
      bVar1 = DAT_00087203;
      bStack_15 = bVar1 >> 2 & 1;
      FUN_fff8ffa3(0x1a);
      bVar1 = DAT_00087303;
      DAT_00087303 = bVar1 & 0xf0 | *local_14 & 0xf;
      if (bStack_15 == 1) {
        FUN_fff8ff82(0x1a);
      }
    }
    else if (local_4 == 0) {
      bVar1 = DAT_00087203;
      bStack_15 = bVar1 >> 3 & 1;
      FUN_fff8ffa3(0x1b);
      bVar1 = DAT_00087303;
      DAT_00087303 = bVar1 & 0xf0 | *local_14 & 0xf;
      if (bStack_15 == 1) {
        FUN_fff8ff82(0x1b);
      }
    }
    FUN_fff90097(0x5e,5,auStack_1c);
  }
  return;
}


// ===== FUN_fff90d21 @ fff90d21 (33 bytes)

void FUN_fff90d21(int param_1)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = DAT_000872e1;
    DAT_000872e1 = bVar1 | 1;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = DAT_000872e0;
  DAT_000872e0 = bVar1 | 1;
  return;
}


// ===== FUN_fff90d42 @ fff90d42 (33 bytes)

void FUN_fff90d42(int param_1)

{
  byte bVar1;
  
  if (param_1 == 1) {
    bVar1 = DAT_0008701a;
    DAT_0008701a = bVar1 & 0xfe;
    return;
  }
  if (param_1 != 0) {
    return;
  }
  bVar1 = DAT_0008701b;
  DAT_0008701b = bVar1 & 0xfe;
  return;
}


// ===== FUN_fff90d63 @ fff90d63 (17 bytes)

void FUN_fff90d63(int param_1)

{
  (&DAT_00001432)[param_1] = 1;
  return;
}


// ===== FUN_fff90d74 @ fff90d74 (17 bytes)

void FUN_fff90d74(int param_1)

{
  (&DAT_00001432)[param_1] = 0;
  return;
}

