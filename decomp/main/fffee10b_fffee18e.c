// FT-710_MAIN_V0112.bin — Ghidra decompile, 2 functions

// ===== FUN_fffee10b @ fffee10b (131 bytes)

/* WARNING: Removing unreachable block (ram,0xfffee18b) */

int * FUN_fffee10b(int *param_1)

{
  uint uVar1;
  uint uVar2;
  uint *puVar3;
  uint *puVar4;
  uint uVar5;
  uint *puVar6;
  
  if (param_1 != (int *)0x0) {
    puVar3 = (uint *)(param_1 + -2);
    uVar1 = *puVar3;
    if ((7 < uVar1) && ((uVar1 & 7) == 0)) {
      if ((DAT_00025e5c == (uint *)0x0) || (puVar3 < (uint *)((uint)DAT_00025e5c & 0xff))) {
        param_1[-1] = (int)DAT_00025e5c;
        puVar4 = puVar3;
        DAT_00025e5c = puVar3;
      }
      else {
        puVar6 = (uint *)&DAT_00025e5c;
        do {
          puVar4 = (uint *)*puVar6;
          uVar2 = puVar4[1];
          puVar6 = puVar4 + 1;
          if (((uint)puVar3 & 0xff) <= uVar2) break;
        } while (uVar2 != 0);
        uVar5 = *puVar4 + (int)puVar4;
        if (puVar3 < (uint *)(uVar5 & 0xff)) {
          return param_1;
        }
        if (uVar5 == ((uint)puVar3 & 0xff)) {
          *puVar4 = uVar1 + *puVar4;
        }
        else {
          if ((uVar2 != 0) && (uVar2 < ((int)param_1 + (uVar1 - 8) & 0xff))) {
            return param_1;
          }
          param_1[-1] = uVar2;
          puVar4[1] = (uint)puVar3;
          puVar4 = puVar3;
        }
      }
      param_1 = (int *)puVar4[1];
      if ((param_1 != (int *)0x0) && ((int)puVar4 + *puVar4 == ((uint)param_1 & 0xff))) {
        DAT_00025e58 = 0;
        param_1 = (int *)puVar4[1];
        *puVar4 = *puVar4 + *param_1;
        puVar4[1] = param_1[1];
      }
    }
  }
  return param_1;
}


// ===== FUN_fffee18e @ fffee18e (48 bytes)

int FUN_fffee18e(undefined4 param_1,uint param_2,int param_3)

{
  char cVar1;
  undefined4 uVar2;
  uint uVar3;
  
  uVar3 = *(uint *)(&DAT_fff8e68c + (param_2 & 3) * 4);
  if ((param_2 & 4) != 0) {
    uVar3 = uVar3 | 0x20;
  }
  if ((param_2 & 8) != 0) {
    uVar3 = uVar3 | 0x10;
  }
  if ((param_2 & 0x10) != 0) {
    uVar3 = uVar3 | 8;
  }
  uVar2 = 0x1b6;
  if (param_3 != 0) {
    uVar2 = 0x180;
  }
  cVar1 = FUN_fff8fa1b(param_1,uVar3,uVar2);
  return (int)cVar1;
}

