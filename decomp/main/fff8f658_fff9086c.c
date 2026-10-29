// FT-710_MAIN_V0112.bin — Ghidra decompile, 50 functions

// ===== main @ fff8f658 (5 bytes)

/* Called from PowerON_Reset after BSP init; calls app_main */

void main(void)

{
  app_main();
  return;
}


// ===== R_Systeminit @ fff8f65e (358 bytes)

/* Code Generator init: ports, IWDT, DA, S12AD0/1, SCI0-7, TPU0-3 create, registers 17 interrupt
   callbacks via R_BSP_InterruptWrite */

void R_Systeminit(void)

{
  byte bVar1;
  
  DAT_000803fe = 0xa50b;
  bVar1 = DAT_0008c11f;
  DAT_0008c11f = bVar1 & 0x7f;
  bVar1 = DAT_0008c11f;
  DAT_0008c11f = bVar1 | 0x40;
  DAT_0008c4cc = 0;
  FUN_fff8f7c4();
  R_Pins_Create();
  R_IWDT_Create();
  R_DA_Create();
  R_S12AD0_Create();
  R_S12AD1_Create();
  R_SCI0_Create();
  R_SCI1_Create();
  R_SCI2_Create();
  R_SCI3_Create();
  R_SCI4_Create();
  R_SCI5_Create();
  FUN_fff92e25();
  R_TPU0_Create();
  R_TPU1_Create();
  R_TPU3_Create();
  R_MTU2_Create();
  R_SCI6_Create_IIC();
  R_SCI7_Create();
  R_TPU2_Create();
  FUN_fff8f7ca();
  R_BSP_InterruptWrite(10,-0x709a3);
  R_BSP_InterruptWrite(7,-0x6d820);
  R_BSP_InterruptWrite(0x14,-0x6cba6);
  R_BSP_InterruptWrite(0x15,-0x6cb0f);
  R_BSP_InterruptWrite(0x16,-0x6c879);
  R_BSP_InterruptWrite(0x17,-0x6c7e2);
  R_BSP_InterruptWrite(0x18,-0x6c338);
  R_BSP_InterruptWrite(0x19,-0x6c2a1);
  R_BSP_InterruptWrite(0x1a,-0x6beb8);
  R_BSP_InterruptWrite(0x1b,-0x6be21);
  R_BSP_InterruptWrite(0x1c,-0x6bb89);
  R_BSP_InterruptWrite(0x1d,-0x6baf2);
  R_BSP_InterruptWrite(0x1e,-0x6b763);
  R_BSP_InterruptWrite(0x1f,-0x6b6cc);
  R_BSP_InterruptWrite(0x20,-0x36c11);
  R_BSP_InterruptWrite(0x22,-0x36814);
  R_BSP_InterruptWrite(0x23,-0x36780);
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


// ===== hardware_setup @ fff8f7ec (20 bytes)

/* BSP hardware set-up wrapper called from PowerON_Reset: stubs, R_Systeminit, port init,
   module-stop/ADC reg, reg 0xC5800 */

void hardware_setup(void)

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
  R_Systeminit();
  return;
}


// ===== FUN_fff8f809 @ fff8f809 (112 bytes)

/* WARNING: Removing unreachable block (ram,0xfff8f861) */

void FUN_fff8f809(void)

{
  uint uVar1;
  uint uVar2;
  undefined4 uVar3;
  
  DAT_000803fe = 0xa502;
  uVar1 = DAT_00080010;
  uVar2 = DAT_00080010;
  DAT_00080010 = uVar2 & 0xfffeffff;
  uVar3 = DAT_00080010;
  DAT_00089163 = 3;
  DAT_0008916e = 0x20;
  DAT_00089163 = 2;
  uVar2 = DAT_00080010;
  DAT_00080010 = uVar2 & 0xfffeffff | uVar1 & 0x10000;
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


// ===== FUN_fff8f8d8 @ fff8f8d8 (29 bytes)

uint FUN_fff8f8d8(void)

{
  uint uVar1;
  
  do {
    uVar1 = DAT_000840c0;
  } while ((uVar1 & 0x1000) == 0);
  uVar1 = Ram00084090;
  return uVar1 & 0xff;
}


// ===== _INIT_IOLIB @ fff8f8f5 (232 bytes)

/* CC-RX runtime: sets up stdin/stdout/stderr FILE structs at 0x25D80 */

void _INIT_IOLIB(void)

{
  uint uVar1;
  
  DAT_0001ff74 = &DAT_00025d80;
  DAT_0001ff78 = &DAT_00025dc8;
  DAT_0001ff7c = &DAT_00025e10;
  freopen(0xfff8f2e9,0xfff8f2f2,&DAT_00025d80);
  DAT_00025d80 = 0x801;
  PTR_DAT_00025d88 = PTR_DAT_00025d84 + 1;
  uVar1 = freopen(0xfff8f2f4,0xfff8f2fe,&DAT_00025dc8);
  if (uVar1 == 0) {
    DAT_00025dc8 = 0xffff;
  }
  DAT_00025dc8 = DAT_00025dc8 | 0x800;
  PTR_DAT_00025dd0 = PTR_DAT_00025dcc + 1;
  uVar1 = freopen(0xfff8f300,0xfff8f2fe,&DAT_00025e10);
  if (uVar1 == 0) {
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
      fclose((&DAT_0001ff74)[local_4]);
    }
  }
  return;
}


// ===== open @ fff8fa1b (167 bytes)

/* lowsrc open(name, mode): matches "C:\stdin"/"C:\stdout"/"C:\stderr" (0xFFF8F2E9/F4/0x300), stores
   the mode in the fd flag bytes 0x1404..0x1406 [inference for the name] */

void open(undefined4 param_1,byte param_2)

{
  int iVar1;
  
  iVar1 = scmpu(param_1,0xfff8f2e9,0xffffffff);
  if (-1 < iVar1 == iVar1 < 1) {
    if ((param_2 & 1) != 0) {
      DAT_00001404 = param_2;
    }
  }
  else {
    iVar1 = scmpu(param_1,0xfff8f2f4,0xffffffff);
    if (-1 < iVar1 == iVar1 < 1) {
      if ((param_2 & 2) != 0) {
        DAT_00001405 = param_2;
      }
    }
    else {
      iVar1 = scmpu(param_1,0xfff8f300,0xffffffff);
      if ((-1 < iVar1 == iVar1 < 1) && ((param_2 & 2) != 0)) {
        DAT_00001406 = param_2;
      }
    }
  }
  return;
}


// ===== close @ fff8fac2 (11 bytes)

/* lowsrc close(fd): returns 1, no-op [inference for the name] */

undefined4 close(void)

{
  return 1;
}


// ===== write @ fff8facd (140 bytes)

/* lowsrc write(fd, buf, n): fd 1/2 with a write flag in 0x1404[fd] -> charput (FUN_fff8f8bb) per
   byte; fd 0 -> -1 [inference for the name] */

uint write(int param_1,void *param_2,int param_3)

{
  undefined1 uVar1;
  bool bVar2;
  uint local_1c;
  int local_14;
  undefined1 *local_8;
  
  if ((((&DAT_00001404)[param_1] & 2) == 0) && (((&DAT_00001404)[param_1] & 4) == 0)) {
    bVar2 = false;
  }
  else {
    bVar2 = true;
  }
  if (bVar2) {
    if (param_1 == 0) {
      local_1c = 0xffffffff;
    }
    else {
      if ((param_1 == 1) || (param_1 == 2)) {
        bVar2 = true;
      }
      else {
        bVar2 = false;
      }
      local_14 = param_3;
      local_8 = param_2;
      if (bVar2) {
        for (; local_1c = param_3, 0 < local_14; local_14 = local_14 + -1) {
          uVar1 = *local_8;
          local_8 = local_8 + 1;
          FUN_fff8f8bb(uVar1);
        }
      }
      else {
        local_1c = 0xffffffff;
      }
    }
  }
  else {
    local_1c = 0xffffffff;
  }
  return local_1c;
}


// ===== FUN_fff8fb59 @ fff8fb59 (113 bytes)

/* WARNING: Removing unreachable block (ram,0xfff8fbc7) */

int FUN_fff8fb59(int param_1,char *param_2,int param_3)

{
  bool bVar1;
  char cVar2;
  int iStack_1c;
  int iStack_18;
  char *pcStack_c;
  
  if ((((&DAT_00001404)[param_1] & 1) == 0) && (((&DAT_00001404)[param_1] & 4) == 0)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  iStack_18 = param_3;
  pcStack_c = param_2;
  if (bVar1) {
    for (; iStack_1c = param_3, 0 < iStack_18; iStack_18 = iStack_18 + -1) {
      cVar2 = FUN_fff8f8d8();
      *pcStack_c = cVar2;
      if (*pcStack_c == '\r') {
        *pcStack_c = '\n';
      }
      pcStack_c = pcStack_c + 1;
    }
  }
  else {
    iStack_1c = -1;
  }
  return iStack_1c;
}


// ===== FUN_fff8fbca @ fff8fbca (17 bytes)

undefined4 FUN_fff8fbca(void)

{
  return 0xffffffff;
}


// ===== PowerON_Reset @ fff8fbdb (100 bytes)

/* Reset: sets USP=0x1004 ISP=0x1404 INTB=0xFFF8E6DC EXTB=0xFFFFFF80 FPSW=0x100, calls init chain,
   then main */

void PowerON_Reset(void)

{
  hw_init_clock();
  _INITSCT();
  bsp_callbacks_clear();
  _INIT_IOLIB();
  bsp_interrupt_open();
  FUN_fff8ff3d();
  hardware_setup();
  R_BSP_InterruptControl(0xb,1,(void *)0x10000000);
  main();
  _CLOSEALL();
  do {
                    /* WARNING: Do nothing block with infinite loop */
  } while( true );
}


// ===== FUN_fff8fc3f @ fff8fc3f (14 bytes)

undefined4 FUN_fff8fc3f(void)

{
  return 0x50040;
}


// ===== FUN_fff8fc4d @ fff8fc4d (10 bytes)

uint FUN_fff8fc4d(void)

{
  uint uVar1;
  
  uVar1 = FUN_fff91303();
  return uVar1;
}


// ===== FUN_fff8fc57 @ fff8fc57 (277 bytes)

byte FUN_fff8fc57(uint param_1,void *param_2)

{
  bool bVar1;
  uint uVar2;
  ulonglong uVar3;
  undefined8 uStack_20;
  uint uStack_14;
  
  if ((param_2 == &DAT_000f4240) || (param_2 == &DAT_000003e8)) {
    bVar1 = false;
  }
  else {
    bVar1 = true;
  }
  if ((bVar1) && (param_2 != (void *)0x1)) {
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
    if (param_2 != (void *)0x0) {
      uStack_14 = uStack_14 / (uint)param_2;
    }
    if (uStack_14 < 3) {
      uStack_14 = 0;
    }
    else {
      uStack_14 = uStack_14 - 2;
    }
    uStack_14 = uStack_14 >> 2;
    if (uStack_14 == 0) {
      return 0;
    }
  }
  else {
    uVar3 = FUN_fffede41((uint)((ulonglong)param_1 * (ulonglong)uStack_14),
                         (uint)((ulonglong)param_1 * (ulonglong)uStack_14 >> 0x20),(uint)param_2,
                         (int)param_2 >> 0x1f);
    uStack_20._4_4_ = (uint)(uVar3 >> 0x20);
    uStack_20._0_4_ = (uint)uVar3;
    if (uStack_20._4_4_ != 0 || uStack_20._4_4_ == 0 && 2 < (uint)uStack_20) {
      uStack_20 = CONCAT44(uStack_20._4_4_ + -1 + (uint)(1 < (uint)uStack_20),(uint)uStack_20 - 2);
      uVar3 = uStack_20;
    }
    uStack_20 = uVar3;
    uStack_14 = (uint)uStack_20 >> 2 | uStack_20._4_4_ << 0x1e;
    if ((uStack_20._4_4_ >> 2 == 0) && (uStack_14 != 0)) {
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
    uStack_14 = uStack_14 - 1;
  } while (uStack_14 != 0);
  return 1;
}


// ===== FUN_fff8fd6d @ fff8fd6d (23 bytes)

void FUN_fff8fd6d(void)

{
  uint in_PSW;
  
  if ((in_PSW & 0x100000) != 0) {
    return;
  }
  return;
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


// ===== FUN_fff8fe3c @ fff8fe3c (132 bytes)

void FUN_fff8fe3c(int param_1)

{
  ushort uVar1;
  byte bVar2;
  undefined1 auStack_8 [4];
  int iStack_4;
  
  iStack_4 = param_1;
  R_BSP_InterruptControl(0x5e,6,auStack_8);
  if (*(short *)(&DAT_0001b5fc + iStack_4 * 2) != 0) {
    *(short *)(&DAT_0001b5fc + iStack_4 * 2) = *(short *)(&DAT_0001b5fc + iStack_4 * 2) + -1;
  }
  if (*(short *)(&DAT_0001b5fc + iStack_4 * 2) == 0) {
    if (iStack_4 == 3) {
      bVar2 = DAT_0008c11f;
      DAT_0008c11f = bVar2 & 0x7f;
      bVar2 = DAT_0008c11f;
      DAT_0008c11f = bVar2 & 0xbf;
      bVar2 = DAT_0008c11f;
      DAT_0008c11f = bVar2 | 0x80;
    }
    else {
      uVar1 = DAT_000803fe;
      DAT_000803fe = (uVar1 | 0xa500) & ~*(ushort *)((int)&PTR_DAT_fff87ed0 + iStack_4 * 2);
    }
  }
  R_BSP_InterruptControl(0x5e,5,auStack_8);
  return;
}


// ===== FUN_fff8fec0 @ fff8fec0 (108 bytes)

void FUN_fff8fec0(int param_1)

{
  ushort uVar1;
  byte bVar2;
  undefined1 auStack_8 [4];
  int iStack_4;
  
  iStack_4 = param_1;
  R_BSP_InterruptControl(0x5e,6,auStack_8);
  if (*(short *)(&DAT_0001b5fc + iStack_4 * 2) == 0) {
    if (iStack_4 == 3) {
      bVar2 = DAT_0008c11f;
      DAT_0008c11f = bVar2 & 0x7f;
      bVar2 = DAT_0008c11f;
      DAT_0008c11f = bVar2 | 0x40;
    }
    else {
      uVar1 = DAT_000803fe;
      DAT_000803fe = uVar1 | *(ushort *)((int)&PTR_DAT_fff87ed0 + iStack_4 * 2) | 0xa500;
    }
  }
  *(short *)(&DAT_0001b5fc + iStack_4 * 2) = *(short *)(&DAT_0001b5fc + iStack_4 * 2) + 1;
  R_BSP_InterruptControl(0x5e,5,auStack_8);
  return;
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


// ===== bsp_callbacks_clear @ fff8ff5f (35 bytes)

/* Clears 0x74 words at 0x1FFC4 (BSP interrupt callback table) [inference] */

void bsp_callbacks_clear(void)

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
  (&DAT_00087200)[param_1 >> 3] = (&DAT_00087200)[param_1 >> 3] | '\x01' << ((byte)param_1 & 7);
  return;
}


// ===== FUN_fff8ffa3 @ fff8ffa3 (33 bytes)

void FUN_fff8ffa3(uint param_1)

{
  (&DAT_00087200)[param_1 >> 3] = (&DAT_00087200)[param_1 >> 3] & ~('\x01' << ((byte)param_1 & 7));
  return;
}


// ===== bsp_interrupt_open @ fff8ffc4 (55 bytes)

/* Group callback table 0x20194 = FIT_NO_FUNC, icu_select_init, two group set-ups [inference] */

void bsp_interrupt_open(void)

{
  uint local_4;
  
  for (local_4 = 0; local_4 < 0x5f; local_4 = local_4 + 1) {
    *(undefined4 *)(&DAT_00020194 + local_4 * 4) = 0x10000000;
  }
  icu_select_init();
  FUN_fff9089e(0);
  FUN_fff9089e(1);
  return;
}


// ===== R_BSP_InterruptWrite @ fff8fffb (75 bytes)

/* Registers a group-interrupt callback by index (0x14..0x23 = TEI0/ERI0..TEI7/ERI7) [inference] */

uint R_BSP_InterruptWrite(int param_1,int param_2)

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
  return 0;
}


// ===== FUN_fff90046 @ fff90046 (81 bytes)

void FUN_fff90046(int param_1,undefined4 *param_2)

{
  bool bVar1;
  
  if ((*(int *)(&DAT_00020194 + param_1 * 4) == 0) ||
     (*(int *)(&DAT_00020194 + param_1 * 4) == 0x10000000)) {
    bVar1 = true;
  }
  else {
    bVar1 = false;
  }
  if (!bVar1) {
    *param_2 = *(undefined4 *)(&DAT_00020194 + param_1 * 4);
  }
  return;
}


// ===== R_BSP_InterruptControl @ fff90097 (234 bytes)

/* BSP interrupt control; group ISRs call it with (id, 0, FIT_NO_VALUE 0x10000000) to run the
   callback [inference] */

uint R_BSP_InterruptControl(uint param_1,int param_2,void *param_3)

{
  bool bVar1;
  uint local_18;
  uint local_14;
  void *local_c;
  int local_8;
  uint local_4;
  
  local_14 = 0;
  local_c = param_3;
  local_8 = param_2;
  local_4 = param_1;
  if (param_2 == 6) {
    local_14 = FUN_fff90181('\0',param_3);
  }
  else if (param_2 == 1) {
    local_14 = FUN_fff916ac(param_1,'\x01');
  }
  else if (param_2 == 2) {
    local_14 = FUN_fff916ac(param_1,'\0');
  }
  else if (param_2 == 3) {
    if ((param_3 == (void *)0x0) || (param_3 == (void *)0x10000000)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_14 = FUN_fff901f8(param_1,'\x01',*(uint *)param_3);
    }
    else {
      local_14 = 2;
    }
  }
  else if (param_2 == 4) {
    local_14 = FUN_fff901f8(param_1,'\0',0);
  }
  else if (param_2 == 5) {
    local_14 = FUN_fff90181('\x01',param_3);
  }
  else if (param_2 == 0) {
    if ((*(int *)(&DAT_00020194 + param_1 * 4) == 0) ||
       (*(int *)(&DAT_00020194 + param_1 * 4) == 0x10000000)) {
      bVar1 = false;
    }
    else {
      bVar1 = true;
    }
    if (bVar1) {
      local_18 = param_1;
      (**(code **)(&DAT_00020194 + param_1 * 4))(&local_18);
    }
    else {
      local_14 = 1;
    }
  }
  else {
    local_14 = 2;
  }
  return local_14;
}


// ===== FUN_fff90181 @ fff90181 (119 bytes)

/* WARNING: Removing unreachable block (ram,0xfff901f5) */

uint FUN_fff90181(char param_1,uint *param_2)

{
  bool bVar1;
  char cVar2;
  uint uVar3;
  uint in_PSW;
  uint local_20;
  uint local_14;
  
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

uint FUN_fff901f8(int param_1,char param_2,uint param_3)

{
  byte bVar1;
  int iVar2;
  bool bVar3;
  uint local_1c;
  uint local_18;
  uint local_14;
  
  local_14 = 0;
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
  if (bVar3) {
    local_18 = 2;
  }
  else {
    if ((param_1 < 0x10) || (0xf < param_1)) {
      bVar3 = false;
    }
    else {
      bVar3 = true;
    }
    if (bVar3) {
      local_14 = 2;
    }
    else {
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
          else {
            local_14 = 4;
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
            else {
              local_14 = 4;
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
              else {
                local_14 = 4;
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
                else {
                  local_14 = 4;
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
                  else {
                    local_14 = 4;
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
                    else {
                      local_14 = 4;
                    }
                  }
                }
                else {
                  local_14 = 2;
                }
              }
            }
          }
        }
      }
    }
    local_18 = local_14;
  }
  return local_18;
}


// ===== SuperVisorInst @ fff905ad (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfff905be) */
/* WARNING: Removing unreachable block (ram,0xfff905ad) */
/* WARNING: Removing unreachable block (ram,0xfff905af) */
/* WARNING: Removing unreachable block (ram,0xfff905c0) */

undefined4 SuperVisorInst(undefined4 param_1)

{
  R_BSP_InterruptControl(0,0,(void *)0x10000000);
  return param_1;
}


// ===== AccessExc @ fff905c4 (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfff905d5) */
/* WARNING: Removing unreachable block (ram,0xfff905c4) */
/* WARNING: Removing unreachable block (ram,0xfff905c6) */
/* WARNING: Removing unreachable block (ram,0xfff905d7) */

undefined4 AccessExc(undefined4 param_1)

{
  R_BSP_InterruptControl(4,0,(void *)0x10000000);
  return param_1;
}


// ===== UndefinedInst @ fff905db (23 bytes)

/* WARNING: Removing unreachable block (ram,0xfff905ec) */
/* WARNING: Removing unreachable block (ram,0xfff905db) */
/* WARNING: Removing unreachable block (ram,0xfff905dd) */
/* WARNING: Removing unreachable block (ram,0xfff905ee) */

undefined4 UndefinedInst(undefined4 param_1)

{
  R_BSP_InterruptControl(1,0,(void *)0x10000000);
  return param_1;
}


// ===== FloatingPoint @ fff905f2 (41 bytes)

/* WARNING: Removing unreachable block (ram,0xfff90615) */
/* WARNING: Removing unreachable block (ram,0xfff905f2) */
/* WARNING: Removing unreachable block (ram,0xfff905f4) */
/* WARNING: Removing unreachable block (ram,0xfff90617) */

undefined4 FloatingPoint(undefined4 param_1)

{
  R_BSP_InterruptControl(3,0,(void *)0x10000000);
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
    R_BSP_InterruptControl(2,0,(void *)0x10000000);
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
    R_BSP_InterruptControl(5,0,(void *)0x10000000);
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
    R_BSP_InterruptControl(6,0,(void *)0x10000000);
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
    R_BSP_InterruptControl(7,0,(void *)0x10000000);
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
    R_BSP_InterruptControl(8,0,(void *)0x10000000);
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
    R_BSP_InterruptControl(9,0,(void *)0x10000000);
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
      R_BSP_InterruptControl(0xc,0,(void *)0x10000000);
      bVar1 = DAT_00081201;
      DAT_00081201 = bVar1 & 0xfe;
    }
    bVar1 = DAT_00081241;
    if ((bVar1 & 1) == 1) {
      R_BSP_InterruptControl(0xd,0,(void *)0x10000000);
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
  R_BSP_InterruptControl(10,0,(void *)0x10000000);
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
  R_BSP_InterruptControl(0xb,0,(void *)0x10000000);
  return param_1;
}


// ===== FUN_fff90837 @ fff90837 (39 bytes)

bool FUN_fff90837(int *param_1)

{
  int iVar1;
  
  iVar1 = *param_1;
  *param_1 = 1;
  return iVar1 == 0;
}


// ===== FUN_fff9085e @ fff9085e (14 bytes)

undefined1 FUN_fff9085e(undefined4 *param_1)

{
  *param_1 = 0;
  return 1;
}


// ===== FUN_fff9086c @ fff9086c (25 bytes)

undefined1 FUN_fff9086c(int param_1)

{
  undefined1 uVar1;
  
  uVar1 = FUN_fff90837(&DAT_0001ffc4 + param_1 * 4);
  return uVar1;
}

