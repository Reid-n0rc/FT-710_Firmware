// FT-710_DISPLAY_V0108.bin — Ghidra decompile, 50 functions

// ===== FUN_2013c928 @ 2013c928 (56 bytes)

undefined4 FUN_2013c928(int param_1,int *param_2)

{
  undefined4 uVar1;
  
  if (param_1 != 1) {
    (*(code *)((undefined4 *)param_2[1])[1])();
    return 0;
  }
                    /* WARNING: Could not recover jumptable at 0x2013c95c. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)param_2[1])((int)*(short *)(*param_2 + 0x2c4));
  return uVar1;
}


// ===== FUN_2013c960 @ 2013c960 (112 bytes)

undefined4 FUN_2013c960(int *param_1)

{
  int iVar1;
  int iVar2;
  
  *(undefined2 *)(*param_1 + 0x2ac) = 0;
  (**(code **)(param_1[1] + 0x2c))();
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0,0,0,*param_1);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013c9d0 @ 2013c9d0 (488 bytes)

undefined4 FUN_2013c9d0(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
    if (iVar1 != 0) {
      uVar3 = 0;
      while( true ) {
        iVar2 = (**(code **)(param_1[1] + 0x48))(1,0,0xff8000,*param_1);
        if (iVar2 != 0) {
          return 0xfffffff7;
        }
        (**(code **)(param_1[1] + 0x4c))(3,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0) break;
        uVar3 = uVar3 + 1;
        FUN_2013fd3c(1);
        if (999 < uVar3) {
          return 0xffffffff;
        }
      }
      *(undefined2 *)(*param_1 + 0x2c4) = 0xffff;
      *(undefined2 *)(*param_1 + 0x2c6) = 1;
      return 0;
    }
    (**(code **)(param_1[1] + 0x4c))(1,*param_1);
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x29,1,0,*param_1);
    if (iVar1 == 0) {
      (**(code **)(param_1[1] + 0x4c))(3,*param_1);
      uVar3 = *(uint *)(*param_1 + 0x2b0) & 0xff8000;
      if (uVar3 != 0) {
        if (2 < iVar2) {
          return 0xffffffff;
        }
        uVar4 = 0;
        do {
          iVar2 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
          if (iVar2 == 0) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            iVar2 = (**(code **)(param_1[1] + 0x48))(0x29,1,uVar3,*param_1);
            if ((iVar2 == 0) &&
               ((**(code **)(param_1[1] + 0x4c))(3,*param_1),
               (*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0)) {
              return 0;
            }
          }
          uVar4 = uVar4 + 1;
          FUN_2013fd3c(1);
          if (999 < uVar4) {
            return 0xffffffff;
          }
        } while( true );
      }
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xffffffff;
    }
  } while( true );
}


// ===== FUN_2013cbb8 @ 2013cbb8 (560 bytes)

int FUN_2013cbb8(int *param_1)

{
  int iVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  
  iVar1 = (**(code **)(param_1[1] + 0x48))(8,0,0x1aa,*param_1);
  if ((iVar1 == 0) &&
     ((**(code **)(param_1[1] + 0x4c))(7,*param_1), *(int *)(*param_1 + 0x2b0) == 0x1aa)) {
    iVar1 = (**(code **)(param_1[1] + 0x48))(5,0);
    if (iVar1 != 0) {
      iVar1 = 0;
      do {
        iVar2 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
        if (iVar2 == 0) {
          (**(code **)(param_1[1] + 0x4c))(1,*param_1);
          iVar2 = (**(code **)(param_1[1] + 0x48))(0x29,1,0,*param_1);
          if (iVar2 == 0) {
            (**(code **)(param_1[1] + 0x4c))(3,*param_1);
            uVar4 = *(uint *)(*param_1 + 0x2b0) & 0xff8000;
            if (uVar4 != 0) {
              if (2 < iVar1) {
                return -1;
              }
              uVar3 = 0;
              do {
                iVar1 = (**(code **)(param_1[1] + 8))();
                if (iVar1 != 0) {
                  return iVar1;
                }
                iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,0,*param_1);
                if (iVar1 == 0) {
                  (**(code **)(param_1[1] + 0x4c))(1,*param_1);
                  iVar1 = (**(code **)(param_1[1] + 0x48))(0x29,1,uVar4 | 0x41000000,*param_1);
                  if ((iVar1 == 0) &&
                     ((**(code **)(param_1[1] + 0x4c))(3,*param_1),
                     (*(uint *)(*param_1 + 0x2b0) & 0x80000000) != 0)) {
                    if ((*(uint *)(*param_1 + 0x2b0) & 0x40000000) == 0) {
                      return 1;
                    }
                    iVar1 = (**(code **)(param_1[1] + 0x1c))(0);
                    iVar2 = *param_1;
                    if (((*(uint *)(iVar2 + 0x2b0) & 0x1000000) != 0) && (iVar1 == 0)) {
                      *(ushort *)(iVar2 + 0x2c0) = *(ushort *)(iVar2 + 0x2c0) | 4;
                    }
                    return 0;
                  }
                }
                uVar3 = uVar3 + 1;
                FUN_2013fd3c(1);
                if (999 < uVar3) {
                  return -1;
                }
              } while( true );
            }
          }
        }
        iVar1 = iVar1 + 1;
        if (2 < iVar1) {
          return -1;
        }
      } while( true );
    }
    iVar1 = -5;
  }
  else {
    iVar1 = -9;
  }
  return iVar1;
}


// ===== FUN_2013cde8 @ 2013cde8 (256 bytes)

int FUN_2013cde8(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  while (iVar1 = (**(code **)(param_1[1] + 0x48))(0xb,0,0,*param_1), iVar1 != 0) {
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return -9;
    }
  }
  if (2 < iVar2) {
    return -9;
  }
  (**(code **)(param_1[1] + 0x4c))(1,*param_1);
  if ((*(uint *)(*param_1 + 0x2b0) & 0x2c80008) != 0) {
    return -0x17;
  }
  iVar2 = FUN_2013c928(0,param_1);
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = (**(code **)(param_1[1] + 0x10))();
  if (iVar2 != 2) {
    return -9;
  }
  (**(code **)(param_1[1] + 0x38))();
  FUN_2013fd3c(10);
  iVar2 = (**(code **)(param_1[1] + 0x14))();
  if (iVar2 != 0) {
    return iVar2;
  }
  iVar2 = FUN_2013c928(1,param_1);
  if (iVar2 == 0) {
    FUN_2013fd3c(1);
    iVar2 = (**(code **)(param_1[1] + 0x10))();
    if (iVar2 != 3) {
      return -9;
    }
    return 0;
  }
  return iVar2;
}


// ===== FUN_2013cee8 @ 2013cee8 (152 bytes)

undefined4 FUN_2013cee8(int *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  
  iVar3 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(2,0,0,*param_1);
    if (iVar1 == 0) {
      if (2 < iVar3) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      uVar2 = 0;
      do {
        *(undefined1 *)(*param_1 + uVar2 + 0x211) = *(undefined1 *)(*param_1 + uVar2 + 0x2b0);
        uVar2 = uVar2 + 1 & 0xff;
      } while (uVar2 < 0x10);
      return 0;
    }
    iVar3 = iVar3 + 1;
  } while (iVar3 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d0bc @ 2013d0bc (156 bytes)

undefined4 FUN_2013d0bc(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(9,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 0x2b0;
        iVar3 = iVar2 + 0x201;
        iVar2 = iVar2 + 1;
        *(undefined1 *)(*param_1 + iVar3) = *(undefined1 *)(*param_1 + iVar1);
      } while (iVar2 < 0x10);
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d158 @ 2013d158 (104 bytes)

undefined4 FUN_2013d158(byte *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 >> 6 < 2) && ((*param_1 & 0x3f) >> 2 < 3)) && ((param_1[1] & 0x80) == 0)) &&
     ((((param_1[3] & 0x80) == 0 && ((param_1[5] & 0xf) < 0xc)) && ((param_1[0xe] & 3) < 2)))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


// ===== FUN_2013d1c8 @ 2013d1c8 (112 bytes)

undefined4 FUN_2013d1c8(byte *param_1)

{
  undefined4 uVar1;
  
  if ((((*param_1 >> 6 < 4) && ((*param_1 & 0x3f) >> 2 < 5)) && ((param_1[1] & 0x80) == 0)) &&
     ((((param_1[3] & 0x80) == 0 && ((param_1[5] & 0xf) < 0xc)) &&
      (((param_1[0xc] & 0x1f) >> 2 < 8 && ((param_1[0xe] & 3) < 2)))))) {
    uVar1 = 0;
  }
  else {
    uVar1 = 0xfffffffb;
  }
  return uVar1;
}


// ===== FUN_2013d238 @ 2013d238 (156 bytes)

undefined4 FUN_2013d238(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(10,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar2) {
        return 0xfffffff7;
      }
      (**(code **)(param_1[1] + 0x4c))(2,*param_1);
      iVar2 = 0;
      do {
        iVar1 = iVar2 + 0x2b0;
        iVar3 = iVar2 + 0x211;
        iVar2 = iVar2 + 1;
        *(undefined1 *)(*param_1 + iVar3) = *(undefined1 *)(*param_1 + iVar1);
      } while (iVar2 < 0x10);
      return 0;
    }
    iVar2 = iVar2 + 1;
  } while (iVar2 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d398 @ 2013d398 (156 bytes)

undefined4 FUN_2013d398(uint *param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  uint uVar3;
  int iVar4;
  
  iVar4 = 0;
  do {
    iVar1 = (**(code **)(param_2[1] + 0x48))(0xd,0,(uint)*(ushort *)(*param_2 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      if (2 < iVar4) {
        return 0xfffffff7;
      }
      (**(code **)(param_2[1] + 0x4c))(1,*param_2);
      uVar3 = *(uint *)(*param_2 + 0x2b0);
      if ((uVar3 & *(uint *)(&DAT_2042022c + (uint)*(ushort *)(*param_2 + 0x2c6) * 4)) == 0) {
        uVar2 = 0;
        *param_1 = uVar3;
      }
      else {
        uVar2 = 0xffffffe9;
      }
      return uVar2;
    }
    iVar4 = iVar4 + 1;
  } while (iVar4 < 3);
  return 0xfffffff7;
}


// ===== FUN_2013d434 @ 2013d434 (200 bytes)

undefined4 FUN_2013d434(int param_1,int *param_2)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar3 = 0;
  if (param_1 == 0) {
    do {
      iVar1 = (**(code **)(param_2[1] + 0x48))(7,0,0,*param_2);
      if (iVar1 == 0) {
        return 0;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  else {
    do {
      iVar1 = (**(code **)(param_2[1] + 0x48))(7,0,param_1 << 0x10,*param_2);
      if (iVar1 == 0) {
        if (2 < iVar3) {
          return 0xfffffff7;
        }
        (**(code **)(param_2[1] + 0x4c))(1,*param_2);
        uVar2 = 0;
        if ((*(uint *)(&DAT_20420224 + (uint)*(ushort *)(*param_2 + 0x2c6) * 4) &
            *(uint *)(*param_2 + 0x2b0)) != 0) {
          uVar2 = 0xffffffe9;
        }
        return uVar2;
      }
      iVar3 = iVar3 + 1;
    } while (iVar3 < 3);
  }
  return 0xfffffff7;
}


// ===== FUN_2013d4fc @ 2013d4fc (248 bytes)

int FUN_2013d4fc(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  int iVar1;
  uint uVar2;
  uint local_10;
  
  local_10 = param_4;
  iVar1 = FUN_2013d398(&local_10,param_1);
  if (iVar1 == 0) {
    if ((local_10 & 0x1e00) == 0x800) {
      return 0;
    }
    if ((local_10 & 0x1e00) == 0xa00) {
      iVar1 = FUN_2013d434(0,param_1);
      if (iVar1 != 0) {
        return iVar1;
      }
      if ((local_10 & 0x1e00) == 0xa00) goto LAB_2013d5d4;
    }
    if ((local_10 & 0x1e00) == 0x600) {
LAB_2013d5d4:
      iVar1 = FUN_2013d434(*(undefined2 *)(*param_1 + 0x2aa),param_1);
      return iVar1;
    }
    if ((local_10 & 0x1e00) == 0xc00) {
      iVar1 = (**(code **)(param_1[1] + 0x54))(*param_1);
      if (iVar1 == 0) {
        uVar2 = 0;
        do {
          iVar1 = FUN_2013d398(&local_10,param_1);
          if (iVar1 != 0) {
            return iVar1;
          }
          if ((local_10 & 0x1e00) == 0x800) {
            return 0;
          }
          iVar1 = (**(code **)(param_1[1] + 8))();
          if (iVar1 != 0) {
            return iVar1;
          }
          uVar2 = uVar2 + 1;
        } while (uVar2 < 0x20000);
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -9;
    }
  }
  return iVar1;
}


// ===== FUN_2013d5f4 @ 2013d5f4 (336 bytes)

int FUN_2013d5f4(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = FUN_2013d4fc(param_1);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_1[1] + 0x50))(8,1,*param_1), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
      if (iVar3 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
          return -0x17;
        }
        iVar3 = (**(code **)(param_1[1] + 0x48))(0x33,1,0);
        if (iVar3 == 0) {
          if (iVar2 < 3) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
              return -0x17;
            }
            iVar2 = (**(code **)(param_1[1] + 0x44))(4);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar1 = (**(code **)(param_1[1] + 0x5c))(iVar1 + 0x221,8);
            if (iVar1 != 0) {
              return iVar1;
            }
                    /* WARNING: Could not recover jumptable at 0x2013d740. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            iVar1 = (**(code **)(param_1[1] + 0x44))(2);
            return iVar1;
          }
          break;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== FUN_2013d744 @ 2013d744 (212 bytes)

undefined4 FUN_2013d744(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar2 = 0;
  do {
    iVar1 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
    if (iVar1 == 0) {
      (**(code **)(param_1[1] + 0x4c))(1,*param_1);
      if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
        return 0xffffffe9;
      }
      iVar1 = (**(code **)(param_1[1] + 0x48))(6,1,*(undefined2 *)(*param_1 + 0x2ac));
      if (iVar1 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        (**(code **)(param_1[1] + 0x2c))(*(undefined2 *)(*param_1 + 0x2ac));
        return 0;
      }
    }
    iVar2 = iVar2 + 1;
    if (2 < iVar2) {
      return 0xfffffff7;
    }
  } while( true );
}


// ===== FUN_2013d818 @ 2013d818 (336 bytes)

int FUN_2013d818(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar2 = FUN_2013d4fc(param_1);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_1[1] + 0x50))(0x40,1,*param_1), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_1[1] + 0x48))(0x37,0,(uint)*(ushort *)(*param_1 + 0x2aa) << 0x10);
      if (iVar3 == 0) {
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
          return -0x17;
        }
        iVar3 = (**(code **)(param_1[1] + 0x48))(0xd,1,0);
        if (iVar3 == 0) {
          if (iVar2 < 3) {
            (**(code **)(param_1[1] + 0x4c))(1,*param_1);
            if ((*(uint *)(*param_1 + 0x2b0) & 0xff98008) != 0) {
              return -0x17;
            }
            iVar2 = (**(code **)(param_1[1] + 0x44))(4);
            if (iVar2 != 0) {
              return iVar2;
            }
            iVar1 = (**(code **)(param_1[1] + 0x5c))(iVar1 + 0x229,0x40);
            if (iVar1 != 0) {
              return iVar1;
            }
                    /* WARNING: Could not recover jumptable at 0x2013d964. Too many branches */
                    /* WARNING: Treating indirect jump as call */
            iVar1 = (**(code **)(param_1[1] + 0x44))(2);
            return iVar1;
          }
          break;
        }
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== FUN_2013d968 @ 2013d968 (260 bytes)

int FUN_2013d968(undefined4 param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_2;
  iVar2 = FUN_2013d4fc(param_2);
  if ((iVar2 == 0) && (iVar2 = (**(code **)(param_2[1] + 0x50))(0x40,1,*param_2), iVar2 == 0)) {
    iVar2 = 0;
    do {
      iVar3 = (**(code **)(param_2[1] + 0x48))(6,0,param_1,*param_2);
      if (iVar3 == 0) {
        if (iVar2 < 3) {
          (**(code **)(param_2[1] + 0x4c))(1,*param_2);
          if ((*(uint *)(*param_2 + 0x2b0) & 0x82f80008) != 0) {
            return -0x17;
          }
          iVar2 = (**(code **)(param_2[1] + 0x44))(4);
          if (iVar2 != 0) {
            return iVar2;
          }
          iVar1 = (**(code **)(param_2[1] + 0x5c))(iVar1 + 0x269,0x40);
          if (iVar1 != 0) {
            return iVar1;
          }
                    /* WARNING: Could not recover jumptable at 0x2013da68. Too many branches */
                    /* WARNING: Treating indirect jump as call */
          iVar1 = (**(code **)(param_2[1] + 0x44))(2);
          return iVar1;
        }
        break;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
    iVar2 = -9;
  }
  return iVar2;
}


// ===== FUN_2013de60 @ 2013de60 (296 bytes)

uint FUN_2013de60(int *param_1)

{
  uint uVar1;
  int iVar2;
  uint uVar3;
  
  (**(code **)(param_1[1] + 0x34))(0);
  uVar1 = FUN_2013d968(0xffffff,param_1);
  if ((uVar1 == 0) &&
     (uVar1 = *(byte *)(*param_1 + 0x272) & 1, (*(byte *)(*param_1 + 0x272) & 1) != 0)) {
    iVar2 = (**(code **)(param_1[1] + 0x18))(0);
    if (iVar2 == 0) {
      uVar3 = 0;
      while ((uVar1 = (**(code **)(param_1[1] + 8))(), uVar1 == 0 &&
             (uVar1 = FUN_2013d968(0xfff0ff,param_1), uVar1 == 0))) {
        iVar2 = *param_1;
        if (800 < CONCAT11(*(undefined1 *)(iVar2 + 0x269),*(undefined1 *)(iVar2 + 0x26a)))
        goto LAB_2013df04;
        if ((*(char *)(iVar2 + 0x27a) != '\x01') || ((*(byte *)(iVar2 + 0x282) & 1) == 0)) {
          if ((~*(byte *)(iVar2 + 0x278) & 0xf) == 0) {
            return 0;
          }
          uVar1 = FUN_2013d968(0x80fff0ff,param_1);
          if (uVar1 != 0) {
            return uVar1;
          }
          if ((*(byte *)(*param_1 + 0x278) & 0xf) == 0) {
            (**(code **)(param_1[1] + 0x34))(0);
            return 0;
          }
        }
        uVar3 = uVar3 + 1;
        if (0x1ffff < uVar3) {
          return 0xffffffff;
        }
      }
    }
    else {
LAB_2013df04:
      uVar1 = 0;
    }
  }
  return uVar1;
}


// ===== FUN_2013df88 @ 2013df88 (1084 bytes)

uint FUN_2013df88(int *param_1)

{
  byte bVar1;
  ushort uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  uint uVar6;
  int iVar7;
  uint uVar8;
  uint uVar9;
  bool bVar10;
  
  *(undefined2 *)(*param_1 + 0x2c4) = 1;
  iVar7 = *param_1;
  uVar6 = *(byte *)(iVar7 + 0x221) & 0xf;
  if (((*(byte *)(iVar7 + 0x221) & 0xf) != 0) &&
     (uVar6 = *(byte *)(iVar7 + 0x205) & 0x40, (*(byte *)(iVar7 + 0x205) & 0x40) != 0)) {
    if ((*(byte *)(iVar7 + 0x2c0) & 4) == 0) {
      uVar6 = FUN_2013d968(0xffffff,param_1);
      if ((uVar6 == 0) &&
         (uVar6 = *(byte *)(*param_1 + 0x276) & 2, (*(byte *)(*param_1 + 0x276) & 2) != 0)) {
        uVar8 = 0;
        while (uVar6 = FUN_2013d968(0xfffff1,param_1), uVar6 == 0) {
          iVar7 = *param_1;
          if (800 < CONCAT11(*(undefined1 *)(iVar7 + 0x269),*(undefined1 *)(iVar7 + 0x26a))) {
            return 0;
          }
          if ((*(char *)(iVar7 + 0x27a) != '\x01') || ((*(byte *)(iVar7 + 0x286) & 2) == 0)) {
            if ((~*(byte *)(iVar7 + 0x279) & 0xf) == 0) {
              return 0;
            }
            uVar6 = FUN_2013d968(0x80fffff1,param_1);
            if (uVar6 != 0) {
              return uVar6;
            }
            if ((*(byte *)(*param_1 + 0x279) & 0xf) == 1) {
              (**(code **)(param_1[1] + 0x30))(1);
              *(undefined2 *)(*param_1 + 0x2c4) = 2;
              return 0;
            }
            uVar6 = (**(code **)(param_1[1] + 8))();
            if (uVar6 != 0) {
              return uVar6;
            }
          }
          uVar8 = uVar8 + 1;
          if (0x1ffff < uVar8) {
            return 0xffffffff;
          }
        }
      }
      return uVar6;
    }
    uVar6 = FUN_2013de60();
    if (uVar6 == 0) {
      (**(code **)(param_1[1] + 0x3c))(0);
      uVar6 = FUN_2013d968(0xffffff,param_1);
      if (uVar6 == 0) {
        uVar6 = 0xfffff1;
        bVar1 = *(byte *)(*param_1 + 0x276);
        if ((bVar1 & 8) == 0) {
          if ((bVar1 & 0x10) == 0) {
            if ((bVar1 & 4) == 0) {
              if ((bVar1 & 2) == 0) {
                return bVar1 & 2;
              }
              uVar8 = 2;
            }
            else {
              uVar8 = 4;
              uVar6 = 0xff3ff2;
            }
          }
          else {
            uVar8 = 0x10;
            uVar6 = 0xff3ff4;
          }
        }
        else {
          uVar8 = 8;
          uVar6 = 0xff3ff3;
        }
        uVar9 = 0;
        do {
          uVar3 = (**(code **)(param_1[1] + 8))();
          if (uVar3 != 0) {
            return uVar3;
          }
          uVar3 = FUN_2013d968(uVar6,param_1);
          if (uVar3 != 0) {
            return uVar3;
          }
          uVar3 = uVar6 & 0xf;
          iVar7 = (**(code **)(param_1[1] + 0x1c))(uVar3);
          iVar4 = *param_1;
          uVar2 = CONCAT11(*(undefined1 *)(iVar4 + 0x269),*(undefined1 *)(iVar4 + 0x26a));
          bVar10 = uVar2 == 800;
          if (uVar2 < 0x321) {
            bVar10 = iVar7 == 0;
          }
          if (bVar10) {
            if (((*(char *)(iVar4 + 0x27a) != '\x01') || ((*(byte *)(iVar4 + 0x286) & uVar8) == 0))
               && ((uVar6 == 0xfffff1 ||
                   ((*(char *)(iVar4 + 0x27a) != '\x01' || ((*(byte *)(iVar4 + 0x280) & 8) == 0)))))
               ) {
              if ((~*(byte *)(iVar4 + 0x279) & 0xf) == 0) {
                return 0;
              }
              if ((~(*(byte *)(iVar4 + 0x278) >> 4) & 0xf) == 0) {
                return 0;
              }
              uVar5 = FUN_2013d968(uVar6 | 0x80000000,param_1);
              if (uVar5 != 0) {
                return uVar5;
              }
              uVar5 = (uint)*(byte *)(*param_1 + 0x279);
              if (((uVar5 & 0xf) == uVar3) &&
                 ((uVar6 == 0xfffff1 ||
                  ((uVar6 & 0xffff) >> 0xc == (uint)(*(byte *)(*param_1 + 0x278) >> 4))))) {
                uVar5 = uVar5 & 0xf;
                if (uVar5 == 1) {
                  (**(code **)(param_1[1] + 0x3c))(1);
                  *(undefined2 *)(*param_1 + 0x2c2) = 1;
                  *(undefined2 *)(*param_1 + 0x2c4) = 2;
                  return 0;
                }
                if (uVar5 == 2) {
                  (**(code **)(param_1[1] + 0x3c))(2);
                  *(undefined2 *)(*param_1 + 0x2c2) = 2;
                  *(undefined2 *)(*param_1 + 0x2c4) = 3;
                  return 0;
                }
                if (uVar5 == 3) {
                  (**(code **)(param_1[1] + 0x3c))(3);
                  *(undefined2 *)(*param_1 + 0x2c2) = 3;
                  *(undefined2 *)(*param_1 + 0x2c4) = 4;
                  return 0;
                }
                if (uVar5 == 4) {
                  (**(code **)(param_1[1] + 0x3c))(4);
                  *(undefined2 *)(*param_1 + 0x2c2) = 4;
                  *(undefined2 *)(*param_1 + 0x2c4) = 2;
                  return 0;
                }
              }
            }
          }
          else {
            if (uVar3 == 1) {
              return 0;
            }
            if (uVar3 == 3) {
              if ((*(byte *)(iVar4 + 0x276) & 0x10) == 0) goto LAB_2013dca4;
              uVar6 = uVar6 + 1;
              uVar8 = (uVar8 & 0x7f) << 1;
            }
            else if (uVar3 == 4) {
              uVar8 = uVar8 >> 2;
              uVar6 = uVar6 - 2;
            }
            else {
LAB_2013dca4:
              uVar8 = uVar8 >> 1;
              uVar6 = uVar6 - 1;
            }
          }
          uVar9 = uVar9 + 1;
        } while (uVar9 < 0x20000);
        uVar6 = 0xffffffff;
      }
      return uVar6;
    }
  }
  return uVar6;
}


// ===== FUN_2013dff0 @ 2013dff0 (624 bytes)

int FUN_2013dff0(int *param_1)

{
  ushort uVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  undefined4 unaff_r4;
  
  iVar4 = (**(code **)(param_1[1] + 8))();
  if (iVar4 != 0) {
    return iVar4;
  }
  *(undefined2 *)(*param_1 + 0x2c0) = 0;
  *(undefined2 *)(*param_1 + 0x2c2) = 0;
  *(undefined2 *)(*param_1 + 0x2c4) = 0;
  *(undefined2 *)(*param_1 + 0x2c6) = 0;
  (**(code **)(param_1[1] + 0x30))(0);
  iVar4 = FUN_2013c928(1,param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  FUN_2013fd3c(1);
  iVar4 = FUN_2013c960(param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = FUN_2013cbb8(param_1);
  if (iVar4 == 0) {
    uVar1 = *(ushort *)(*param_1 + 0x2c0);
    *(ushort *)(*param_1 + 0x2c0) = uVar1 | 2;
    if ((uVar1 & 4) == 0) goto LAB_2013e0c0;
    iVar4 = FUN_2013cde8(param_1);
  }
  else {
    if (iVar4 == 1) {
      *(ushort *)(*param_1 + 0x2c0) = *(ushort *)(*param_1 + 0x2c0) | 1;
      goto LAB_2013e0c0;
    }
    if (iVar4 != -9) {
      return iVar4;
    }
    *(ushort *)(*param_1 + 0x2c0) = *(ushort *)(*param_1 + 0x2c0) | 1;
    iVar4 = FUN_2013c9d0(param_1);
  }
  if (iVar4 != 0) {
    return iVar4;
  }
LAB_2013e0c0:
  iVar4 = FUN_2013cee8(param_1);
  if (iVar4 != 0) {
    return iVar4;
  }
  iVar4 = 0;
  if (*(short *)(*param_1 + 0x2c6) == 1) {
    do {
      iVar2 = (**(code **)(param_1[1] + 0x48))(3,0,0x10000,*param_1,unaff_r4);
      if (iVar2 == 0) {
        if (2 < iVar4) {
          return -9;
        }
        (**(code **)(param_1[1] + 0x4c))(1,*param_1);
        *(undefined2 *)(*param_1 + 0x2aa) = 1;
        uVar3 = *(uint *)(*param_1 + 0x2b0);
        if ((uVar3 & 0xd80000) != 0) {
          if (((uVar3 & 0xd80000) == 0x400000) && ((uVar3 & 0x1e00) == 0x400)) {
            return 0;
          }
          return -0x17;
        }
        return 0;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
  }
  else {
    do {
      iVar2 = (**(code **)(param_1[1] + 0x48))(3,0,0,*param_1);
      if (iVar2 == 0) {
        if (2 < iVar4) {
          return -9;
        }
        (**(code **)(param_1[1] + 0x4c))(6,*param_1);
        *(short *)(*param_1 + 0x2aa) = (short)((uint)*(undefined4 *)(*param_1 + 0x2b0) >> 0x10);
        if ((*(uint *)(*param_1 + 0x2b0) & 0xe000) == 0) {
          return 0;
        }
        return -8;
      }
      iVar4 = iVar4 + 1;
    } while (iVar4 < 3);
  }
  return -9;
}


// ===== FUN_2013e124 @ 2013e124 (304 bytes)

int FUN_2013e124(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_2013d0bc();
  if (iVar1 == 0) {
    if (*(short *)(*param_1 + 0x2c6) == 1) {
      iVar1 = FUN_2013d1c8(*param_1 + 0x201);
    }
    else {
      iVar1 = FUN_2013d158();
    }
    if ((iVar1 == 0) && (iVar1 = FUN_2013d238(param_1), iVar1 == 0)) {
      iVar1 = *param_1;
      if ((((*(char *)(iVar1 + 0x211) != '\0') || (*(char *)(iVar1 + 0x212) != '\0')) ||
          (*(char *)(iVar1 + 0x213) != '\0')) &&
         ((((*(char *)(iVar1 + 0x214) != '\0' || (*(char *)(iVar1 + 0x215) != '\0')) ||
           ((*(char *)(iVar1 + 0x216) != '\0' ||
            ((*(char *)(iVar1 + 0x217) != '\0' || (*(char *)(iVar1 + 0x218) != '\0')))))) ||
          ((*(char *)(iVar1 + 0x219) != '\0' ||
           (((((*(char *)(iVar1 + 0x21a) != '\0' || (*(char *)(iVar1 + 0x21b) != '\0')) ||
              (*(char *)(iVar1 + 0x21c) != '\0')) ||
             ((*(char *)(iVar1 + 0x21d) != '\0' || (*(char *)(iVar1 + 0x21e) != '\0')))) ||
            (*(char *)(iVar1 + 0x21f) != '\0')))))))) {
        return 0;
      }
      return -5;
    }
  }
  return iVar1;
}


// ===== FUN_2013e190 @ 2013e190 (84 bytes)

void FUN_2013e190(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 *param_4)

{
  int iVar1;
  
  iVar1 = FUN_2013d434(param_1,param_4);
  if ((iVar1 == 0) &&
     (iVar1 = (**(code **)(param_4[1] + 0x50))(param_2,param_3,*param_4), iVar1 == 0)) {
    FUN_2013d434(0,param_4);
    return;
  }
  return;
}


// ===== FUN_2013e1e4 @ 2013e1e4 (76 bytes)

int FUN_2013e1e4(int *param_1)

{
  int iVar1;
  
  iVar1 = FUN_2013d5f4();
  if (iVar1 == 0) {
    iVar1 = *param_1;
    if ((*(byte *)(iVar1 + 0x222) & 4) == 0) {
      *(undefined2 *)(iVar1 + 0x2ac) = 0;
      return 0;
    }
    *(undefined2 *)(iVar1 + 0x2ac) = 2;
    iVar1 = 0;
  }
  return iVar1;
}


// ===== FUN_2013e230 @ 2013e230 (132 bytes)

void FUN_2013e230(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
    param_1 = param_1 << 9;
  }
  iVar1 = FUN_2013d4fc(param_4);
  if ((iVar1 == 0) &&
     ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
      (iVar1 = (**(code **)(param_4[1] + 0x40))(), iVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e2ac. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    (**(code **)(param_4[1] + 0x58))(param_1,param_2,param_3,*param_4);
    return;
  }
  return;
}


// ===== FUN_2013e2b4 @ 2013e2b4 (156 bytes)

int FUN_2013e2b4(int param_1,undefined4 param_2,undefined4 param_3,int *param_4)

{
  int iVar1;
  
  iVar1 = (**(code **)(param_4[1] + 0xc))();
  if (iVar1 == 0) {
    if ((*(byte *)(*param_4 + 0x2c0) & 2) == 0) {
      param_1 = param_1 << 9;
    }
    iVar1 = FUN_2013d4fc(param_4);
    if ((iVar1 == 0) &&
       ((*(short *)(*param_4 + 0x2c2) != 2 && *(short *)(*param_4 + 0x2c2) != 3 ||
        (iVar1 = (**(code **)(param_4[1] + 0x40))(), iVar1 == 0)))) {
                    /* WARNING: Could not recover jumptable at 0x2013e348. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (**(code **)(param_4[1] + 0x60))(param_1,param_2,param_3,*param_4);
      return iVar1;
    }
  }
  else {
    iVar1 = -7;
  }
  return iVar1;
}


// ===== FUN_2013e35c @ 2013e35c (112 bytes)

int FUN_2013e35c(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    iVar2 = 0;
    do {
      iVar1 = (**(code **)(*(int *)(param_5 + 4) + 8))();
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_2013e230(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 3);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}


// ===== FUN_2013e3cc @ 2013e3cc (112 bytes)

int FUN_2013e3cc(int param_1,uint param_2,undefined4 param_3,undefined4 param_4,int param_5)

{
  int iVar1;
  int iVar2;
  
  if (param_2 < *(uint *)(param_1 + 0x14)) {
    iVar2 = 0;
    do {
      iVar1 = (**(code **)(*(int *)(param_5 + 4) + 8))();
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = FUN_2013e2b4(*(int *)(param_1 + 0x30) + param_2,param_3,param_4,param_5);
      if (iVar1 == 0) {
        return 0;
      }
      iVar2 = iVar2 + 1;
    } while (iVar2 < 1);
  }
  else {
    iVar1 = -2;
  }
  return iVar1;
}


// ===== FUN_2013e43c @ 2013e43c (208 bytes)

int FUN_2013e43c(int param_1,int *param_2)

{
  int iVar1;
  
  iVar1 = FUN_2013e230(0,*param_2 + 1,1,param_2);
  if (iVar1 == 0) {
    iVar1 = FUN_201490f8(param_1,*param_2 + 1);
    if (iVar1 == 0) {
      iVar1 = FUN_2013e230(*(undefined4 *)(param_1 + 0x30),*param_2 + 1,1,param_2);
      if (iVar1 != 0) {
        return iVar1;
      }
      iVar1 = fat_mount(param_1,*param_2 + 1);
      if (-1 < iVar1) {
        if (*(char *)(param_1 + 0x10) == ' ') {
          iVar1 = FUN_2013e230(*(int *)(param_1 + 0x30) + (uint)*(ushort *)(param_1 + 0x3a),
                               *param_2 + 1,1,param_2);
          if (iVar1 != 0) {
            return iVar1;
          }
          FUN_20148f40(param_1,*param_2 + 1);
        }
        return 0;
      }
    }
    iVar1 = -4;
  }
  return iVar1;
}


// ===== FUN_2013e71c @ 2013e71c (700 bytes)

int FUN_2013e71c(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                undefined4 param_5,int *param_6)

{
  byte bVar1;
  int iVar2;
  int iVar3;
  
  switch(param_2) {
  default:
    return -3;
  case 1:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = FUN_2013e35c(param_1,param_3,param_4,param_5,param_6);
      return iVar2;
    }
    break;
  case 2:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = FUN_2013e3cc(param_1,param_3,param_4,param_5,param_6);
      return iVar2;
    }
    break;
  case 5:
    iVar2 = (**(code **)(param_6[1] + 100))();
    if ((iVar2 == 0) && (iVar2 = FUN_2013f9fc(param_1,*(undefined1 *)*param_6), iVar2 == 0)) {
      *(int **)(param_1 + 0x24) = param_6;
      return 0;
    }
    return -8;
  case 7:
    if ((*(byte *)(param_1 + 0x68) & 0x40) != 0) {
      iVar2 = (**(code **)(param_6[1] + 0x24))();
      if (iVar2 == 0) {
        iVar3 = 0;
        do {
          iVar2 = (**(code **)(param_6[1] + 0x20))(2);
          if ((((((iVar2 == 0) && (iVar2 = FUN_2013dff0(param_6), iVar2 == 0)) &&
                (iVar2 = FUN_2013e124(param_6), iVar2 == 0)) &&
               ((iVar2 = FUN_2013e190(*(undefined2 *)(*param_6 + 0x2aa),0x200,1,param_6), iVar2 == 0
                && (iVar2 = FUN_2013d434(*(undefined2 *)(*param_6 + 0x2aa),param_6), iVar2 == 0))))
              && ((*(short *)(*param_6 + 0x2c6) == 1 ||
                  (((iVar2 = FUN_2013e1e4(param_6), iVar2 == 0 &&
                    (iVar2 = FUN_2013d744(param_6), iVar2 == 0)) &&
                   ((iVar2 = FUN_2013df88(param_6), iVar2 == 0 &&
                    (iVar2 = FUN_2013d818(param_6), iVar2 == 0)))))))) &&
             ((iVar2 = FUN_2013c928(1,param_6), iVar2 == 0 &&
              (((*(short *)(*param_6 + 0x2c2) != 2 && *(short *)(*param_6 + 0x2c2) != 3 ||
                (iVar2 = (**(code **)(param_6[1] + 0x40))(), iVar2 == 0)) &&
               (iVar2 = FUN_2013e43c(param_1,param_6), iVar2 == 0)))))) {
            thunk_FUN_20150c3c();
            *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) | 0x80;
            iVar2 = (**(code **)(param_6[1] + 0xc))();
            if (iVar2 == 0) {
              bVar1 = *(byte *)(param_1 + 0x68) & 0xdf;
            }
            else {
              bVar1 = *(byte *)(param_1 + 0x68) | 0x20;
            }
            *(byte *)(param_1 + 0x68) = bVar1;
            thunk_FUN_20152d28();
            return 0;
          }
          iVar3 = iVar3 + 1;
        } while (iVar3 < 3);
      }
      return iVar2;
    }
    break;
  case 8:
    (**(code **)(param_6[1] + 0x28))();
    thunk_FUN_20150c3c();
    *(byte *)(param_1 + 0x68) = *(byte *)(param_1 + 0x68) & 0x7f;
    thunk_FUN_20152d28();
    return 0;
  case 9:
                    /* WARNING: Could not recover jumptable at 0x2013e358. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar2 = (**(code **)(param_6[1] + 8))();
    return iVar2;
  }
  return -6;
}


// ===== FUN_2013e7e8 @ 2013e7e8 (24 bytes)

void FUN_2013e7e8(int param_1)

{
  if (*(int *)(param_1 + 0x2f4) != 0) {
    *(int *)(param_1 + 0x2f4) = *(int *)(param_1 + 0x2f4) + -1;
  }
  return;
}


// ===== FUN_2013e800 @ 2013e800 (12 bytes)

void FUN_2013e800(undefined4 param_1,int param_2)

{
  *(undefined4 *)(param_2 + 0x2f4) = param_1;
  *(undefined4 *)(param_2 + 0x2f8) = param_1;
  return;
}


// ===== FUN_2013e8d0 @ 2013e8d0 (420 bytes)

int FUN_2013e8d0(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int iVar6;
  int iVar7;
  
  iVar2 = *param_1;
  iVar7 = 0;
  FUN_2014d148(iVar2 + 1,0,0x200,0);
  cVar1 = *(char *)(iVar2 + 0x2dc);
  if (cVar1 == '\f') {
    FUN_2014d128(*param_1 + 1,&DAT_20420254,3);
  }
  else if (cVar1 == '\x10') {
    FUN_2014d128(*param_1 + 1,&DAT_20420257,4);
  }
  else {
    if (cVar1 != ' ') {
      return -2;
    }
    FUN_2014d128(*param_1 + 1,&DAT_204202f3,0xc);
  }
  iVar6 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4);
  iVar3 = FUN_2013e2b4(iVar6,*param_1 + 1,1,param_1);
  if (iVar3 == 0) {
    if (*(char *)(iVar2 + 0x2dc) != '@') {
      iVar7 = *(int *)(iVar2 + 0x2d0) + (uint)*(ushort *)(iVar2 + 0x2e4) + *(int *)(iVar2 + 0x2e0);
      iVar4 = FUN_2013e2b4(iVar7,*param_1 + 1,1,param_1);
      iVar3 = 0;
      if (iVar4 != 0) {
        return iVar4;
      }
    }
    FUN_2013e7e8(*param_1);
    FUN_2014d148(*param_1 + 1,0,0x200);
    iVar4 = *(int *)(iVar2 + 0x2e0);
    if ((*(char *)(iVar2 + 0x2dc) != '@') && (uVar5 = 0, iVar4 != 1)) {
      do {
        iVar7 = iVar7 + 1;
        iVar6 = iVar6 + 1;
        iVar2 = FUN_2013e2b4(iVar6,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        iVar2 = FUN_2013e2b4(iVar7,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        FUN_2013e7e8(*param_1);
        uVar5 = uVar5 + 1;
        iVar3 = 0;
      } while (uVar5 < iVar4 - 1U);
    }
  }
  return iVar3;
}


// ===== FUN_2013ea74 @ 2013ea74 (332 bytes)

void FUN_2013ea74(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  FUN_2014d148(iVar1 + 1,0,0x200);
  FUN_2014d128(*param_1 + 1,DAT_20808b4c,4);
  FUN_2014d128(*param_1 + 0x1e5,DAT_20808b50,4);
  FUN_2014d918(*param_1 + 0x1e9,0xffffffff);
  FUN_2014d918(*param_1 + 0x1ed,0xffffffff);
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  iVar2 = *(int *)(iVar1 + 0x2d0);
  iVar3 = FUN_2013e2b4(iVar2 + 1,*param_1 + 1,1,param_1);
  if ((iVar3 == 0) && (iVar2 = FUN_2013e2b4(iVar2 + 7,*param_1 + 1,1,param_1), iVar2 == 0)) {
    FUN_2014d148(*param_1 + 1,0,0x200);
    *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
    *(undefined1 *)(*param_1 + 0x200) = 0xaa;
    iVar1 = *(int *)(iVar1 + 0x2d0);
    iVar2 = FUN_2013e2b4(iVar1 + 2,*param_1 + 1,1,param_1);
    if (iVar2 == 0) {
      FUN_2013e2b4(iVar1 + 8,*param_1 + 1,1,param_1);
      return;
    }
  }
  return;
}


// ===== FUN_2013ebc0 @ 2013ebc0 (112 bytes)

uint FUN_2013ebc0(void)

{
  uint local_28;
  uint local_24;
  uint local_20;
  uint local_1c;
  int local_18;
  int local_14;
  
  FUN_2014e1dc(&local_28);
  return local_14 + 0x76cU & 0xffff | local_24 & 0xffff | (local_20 & 0xff) << 8 |
         ((local_28 & 0xff) * 0x100 + (local_1c | (local_18 + 1) * 0x100 & 0xff00U)) * 0x10000;
}


// ===== FUN_2013ec30 @ 2013ec30 (564 bytes)

void FUN_2013ec30(int *param_1)

{
  int iVar1;
  undefined4 uVar2;
  int iVar3;
  
  iVar1 = *param_1;
  FUN_2014d148(iVar1 + 1,0,0x200);
  if (*(char *)(iVar1 + 0x2dc) != ' ') {
    FUN_2014d128(*param_1 + 1,&DAT_2042025b,0x3e);
    FUN_2014d8ec(*param_1 + 0xc,*(undefined2 *)(iVar1 + 0x2da));
    *(undefined1 *)(*param_1 + 0xe) = *(undefined1 *)(iVar1 + 0x2d8);
    FUN_2014d8ec(*param_1 + 0xf,*(undefined2 *)(iVar1 + 0x2e4));
    FUN_2014d8ec(*param_1 + 0x17,*(undefined2 *)(iVar1 + 0x2e0));
    FUN_2014d8ec(*param_1 + 0x19,*(undefined2 *)(iVar1 + 0x2c8));
    FUN_2014d8ec(*param_1 + 0x1b,*(undefined2 *)(iVar1 + 0x2ca));
    FUN_2014d918(*param_1 + 0x1d,*(undefined4 *)(iVar1 + 0x2d0));
    if (*(uint *)(iVar1 + 0x2d4) < 0x10000) {
      FUN_2014d8ec(*param_1 + 0x14,*(uint *)(iVar1 + 0x2d4) & 0xffff);
    }
    else {
      FUN_2014d918(*param_1 + 0x21);
    }
    uVar2 = FUN_2013ebc0();
    FUN_2014d918(*param_1 + 0x28,uVar2);
    if (*(char *)(iVar1 + 0x2dc) == '\f') {
      *(undefined1 *)(*param_1 + 0x3b) = 0x32;
    }
    *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
    *(undefined1 *)(*param_1 + 0x200) = 0xaa;
    FUN_2013e2b4(*(undefined4 *)(iVar1 + 0x2d0),*param_1 + 1,1,param_1);
    return;
  }
  FUN_2014d128(*param_1 + 1,&DAT_20420299,0x5a);
  FUN_2014d8ec(*param_1 + 0xc,*(undefined2 *)(iVar1 + 0x2da));
  *(undefined1 *)(*param_1 + 0xe) = *(undefined1 *)(iVar1 + 0x2d8);
  FUN_2014d8ec(*param_1 + 0xf,*(undefined2 *)(iVar1 + 0x2e4));
  FUN_2014d8ec(*param_1 + 0x19,*(undefined2 *)(iVar1 + 0x2c8));
  FUN_2014d8ec(*param_1 + 0x1b,*(undefined2 *)(iVar1 + 0x2ca));
  FUN_2014d918(*param_1 + 0x1d,*(undefined4 *)(iVar1 + 0x2d0));
  FUN_2014d918(*param_1 + 0x21,*(undefined4 *)(iVar1 + 0x2d4));
  FUN_2014d918(*param_1 + 0x25,*(undefined4 *)(iVar1 + 0x2e0));
  uVar2 = FUN_2013ebc0();
  FUN_2014d918(*param_1 + 0x44,uVar2);
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  iVar3 = *(int *)(iVar1 + 0x2d0);
  iVar1 = FUN_2013e2b4(iVar3,*param_1 + 1,1,param_1);
  if (iVar1 == 0) {
    FUN_2013e2b4(iVar3 + 6,*param_1 + 1,1,param_1);
    return;
  }
  return;
}


// ===== FUN_2013ee64 @ 2013ee64 (88 bytes)

void FUN_2013ee64(ushort *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 extraout_r1;
  uint uVar2;
  
  *param_2 = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (param_1[1] != 0)) {
    if (*(uint *)(param_1 + 4) < 0xfb0400) {
      FUN_20156260(*(uint *)(param_1 + 4),param_1[1] * uVar2);
      uVar1 = FUN_20156260(extraout_r1,uVar2);
    }
    else {
      uVar1 = 0xfe;
    }
    *param_2 = uVar1;
  }
  return;
}


// ===== FUN_2013eebc @ 2013eebc (128 bytes)

void FUN_2013eebc(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  char extraout_r1;
  uint uVar2;
  uint uVar3;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (uVar1 = param_1[1], uVar1 != 0)) {
    uVar3 = *(uint *)(param_1 + 4);
    if (uVar3 < 0xfb0400) {
      FUN_20156260(uVar3,uVar2);
      uVar2 = FUN_20156260(uVar3,uVar1 * uVar2);
      *param_2 = (byte)((uVar2 >> 8) << 6) | extraout_r1 + 1U;
    }
    else {
      uVar2 = 0xff;
      *param_2 = 0xff;
    }
    param_2[1] = (byte)uVar2;
  }
  return;
}


// ===== FUN_2013ef3c @ 2013ef3c (96 bytes)

void FUN_2013ef3c(int param_1,undefined1 *param_2)

{
  char cVar1;
  undefined1 uVar2;
  
  cVar1 = *(char *)(param_1 + 0x14);
  if (cVar1 == '\f' || cVar1 == '\x10') {
    if (*(uint *)(param_1 + 0xc) < 0x7fa8) {
      uVar2 = 1;
    }
    else if (*(uint *)(param_1 + 0xc) < 0x10000) {
      uVar2 = 4;
    }
    else {
      uVar2 = 6;
    }
  }
  else {
    if (cVar1 != ' ') {
      return;
    }
    if (*(uint *)(param_1 + 0xc) < 0xfb0400) {
      *param_2 = 0xb;
      return;
    }
    uVar2 = 0xc;
  }
  *param_2 = uVar2;
  return;
}


// ===== FUN_2013ef9c @ 2013ef9c (100 bytes)

void FUN_2013ef9c(ushort *param_1,undefined1 *param_2)

{
  undefined1 uVar1;
  undefined4 extraout_r1;
  uint uVar2;
  
  *param_2 = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (param_1[1] != 0)) {
    if (*(uint *)(param_1 + 6) < 0xfb0400) {
      FUN_20156260(*(int *)(param_1 + 4) + *(uint *)(param_1 + 6) + -1,param_1[1] * uVar2);
      uVar1 = FUN_20156260(extraout_r1,uVar2);
    }
    else {
      uVar1 = 0xfe;
    }
    *param_2 = uVar1;
  }
  return;
}


// ===== FUN_2013f000 @ 2013f000 (136 bytes)

void FUN_2013f000(ushort *param_1,byte *param_2)

{
  ushort uVar1;
  char extraout_r1;
  uint uVar2;
  int iVar3;
  
  *param_2 = 0;
  param_2[1] = 0;
  uVar2 = (uint)*param_1;
  if ((uVar2 != 0) && (uVar1 = param_1[1], uVar1 != 0)) {
    if (*(uint *)(param_1 + 6) < 0xfb0400) {
      iVar3 = *(int *)(param_1 + 4) + *(uint *)(param_1 + 6);
      FUN_20156260(iVar3 + -1,uVar2);
      uVar2 = FUN_20156260(iVar3 + -1,uVar1 * uVar2);
      *param_2 = (byte)((uVar2 >> 8) << 6) | extraout_r1 + 1U;
    }
    else {
      uVar2 = 0xff;
      *param_2 = 0xff;
    }
    param_2[1] = (byte)uVar2;
  }
  return;
}


// ===== FUN_2013f088 @ 2013f088 (184 bytes)

void FUN_2013f088(int *param_1)

{
  int iVar1;
  int iVar2;
  int iVar3;
  
  iVar1 = *param_1;
  iVar3 = iVar1 + 0x2c8;
  FUN_2014d148(iVar1 + 1,0,0x200);
  iVar2 = *param_1;
  FUN_2013ee64(iVar3,iVar2 + 0x1c0);
  FUN_2013eebc(iVar3,iVar2 + 0x1c1);
  FUN_2013ef3c(iVar3,iVar2 + 0x1c3);
  FUN_2013ef9c(iVar3,iVar2 + 0x1c4);
  FUN_2013f000(iVar3,iVar2 + 0x1c5);
  FUN_2014d918(iVar2 + 0x1c7,*(undefined4 *)(iVar1 + 0x2d0));
  FUN_2014d918(iVar2 + 0x1cb,*(undefined4 *)(iVar1 + 0x2d4));
  *(undefined1 *)(*param_1 + 0x1ff) = 0x55;
  *(undefined1 *)(*param_1 + 0x200) = 0xaa;
  FUN_2013e2b4(0,*param_1 + 1,1,param_1);
  return;
}


// ===== FUN_2013f15c @ 2013f15c (36 bytes)

undefined4 FUN_2013f15c(int param_1)

{
  byte bVar1;
  undefined4 uVar2;
  
  bVar1 = *(byte *)(param_1 + 5) & 0xf;
  if (bVar1 == 10) {
    uVar2 = 0x400;
  }
  else if (bVar1 == 0xb) {
    uVar2 = 0x800;
  }
  else {
    uVar2 = 0x200;
  }
  return uVar2;
}


// ===== FUN_2013f180 @ 2013f180 (36 bytes)

uint FUN_2013f180(int param_1)

{
  return (*(byte *)(param_1 + 8) & 0xc0 |
         ((uint)*(byte *)(param_1 + 7) | (*(byte *)(param_1 + 6) & 3) << 8) << 8) >> 6;
}


// ===== FUN_2013f1a4 @ 2013f1a4 (108 bytes)

undefined4 FUN_2013f1a4(int param_1)

{
  uint uVar1;
  undefined4 uVar2;
  
  uVar1 = (*(byte *)(param_1 + 10) & 0x80 | (*(byte *)(param_1 + 9) & 3) << 8) >> 7;
  if (uVar1 == 0) {
    uVar2 = 4;
  }
  else if (uVar1 == 1) {
    uVar2 = 8;
  }
  else if (uVar1 == 2) {
    uVar2 = 0x10;
  }
  else if (uVar1 == 3) {
    uVar2 = 0x20;
  }
  else if (uVar1 == 4) {
    uVar2 = 0x40;
  }
  else if (uVar1 == 5) {
    uVar2 = 0x80;
  }
  else if (uVar1 == 6) {
    uVar2 = 0x100;
  }
  else {
    uVar2 = 0x200;
  }
  return uVar2;
}


// ===== FUN_2013f210 @ 2013f210 (40 bytes)

void FUN_2013f210(uint param_1,undefined4 param_2)

{
  if (param_1 < 0x7e0000) {
    FUN_2014d128(param_2,&DAT_20420300,0x2c);
    return;
  }
  FUN_2014d128(param_2,&DAT_2042032c,0x2c);
  return;
}


// ===== FUN_2013f238 @ 2013f238 (264 bytes)

void FUN_2013f238(uint param_1,undefined4 param_2)

{
  param_1 = param_1 >> 9;
  if (param_1 < 0x1000) {
    FUN_2014d128(param_2,&DAT_20420358,0x2c);
    return;
  }
  if (param_1 < 0x4000) {
    FUN_2014d128(param_2,&DAT_20420384,0x2c);
    return;
  }
  if (param_1 < 0x8000) {
    FUN_2014d128(param_2,&DAT_204203b0,0x2c);
    return;
  }
  if (param_1 < 0x10000) {
    FUN_2014d128(param_2,&DAT_204203dc,0x2c);
    return;
  }
  if (param_1 < 0x20000) {
    FUN_2014d128(param_2,&DAT_20420408,0x2c);
    return;
  }
  if (param_1 < 0x40000) {
    FUN_2014d128(param_2,&DAT_20420434,0x2c);
    return;
  }
  if (param_1 < 0x80000) {
    FUN_2014d128(param_2,&DAT_20420460,0x2c);
    return;
  }
  if (param_1 < 0xfc000) {
    FUN_2014d128(param_2,&DAT_2042048c,0x2c);
    return;
  }
  if (param_1 < 0x1f8000) {
    FUN_2014d128(param_2,&DAT_204204b8,0x2c);
    return;
  }
  if (param_1 < 0x3f0000) {
    FUN_2014d128(param_2,&DAT_204204e4,0x2c);
    return;
  }
  FUN_2014d128(param_2,&DAT_20420510,0x2c);
  return;
}


// ===== FUN_2013f340 @ 2013f340 (1116 bytes)

undefined4 FUN_2013f340(int *param_1)

{
  undefined2 uVar1;
  ushort uVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  uint uVar7;
  uint uVar8;
  byte *pbVar9;
  uint uVar10;
  uint uVar11;
  int iVar12;
  int iVar13;
  uint uVar14;
  undefined8 uVar15;
  undefined4 local_28;
  
  local_28 = 0;
  iVar3 = *param_1;
  pbVar9 = (byte *)(iVar3 + 0x201);
  if (*pbVar9 >> 6 == 1) {
    uVar10 = (uint)CONCAT21(CONCAT11(*(undefined1 *)(iVar3 + 0x208),*(undefined1 *)(iVar3 + 0x209)),
                            *(undefined1 *)(iVar3 + 0x20a)) * 0x400 + 0x400;
    FUN_2013f210(uVar10,iVar3 + 0x2c8);
    if (uVar10 < 0x4000000) {
      *(uint *)(iVar3 + 0x2d4) = uVar10;
      iVar4 = (int)*(char *)(iVar3 + 0x2dc);
      if (iVar4 != 0x40) {
        uVar11 = (uint)*(ushort *)(iVar3 + 0x2d8);
        iVar6 = FUN_20156260(uVar10,uVar11);
        iVar5 = (uint)*(ushort *)(iVar3 + 0x2da) << 3;
        uVar15 = FUN_20156260(iVar6 * iVar4,iVar5);
        *(int *)(iVar3 + 0x2e0) = (int)uVar15;
        iVar13 = (uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15;
        iVar6 = 1;
        *(int *)(iVar3 + 0x2e0) = iVar13;
        uVar7 = *(uint *)(iVar3 + 0x2cc);
        if (uVar7 <= (uint)(iVar13 * 2)) {
          do {
            iVar6 = iVar6 + 1;
          } while (uVar7 * iVar6 < (uint)(iVar13 * 2) || uVar7 * iVar6 + iVar13 * -2 == 0);
        }
        uVar14 = uVar7 * iVar6 + iVar13 * -2;
        uVar8 = uVar14 & 0xffff;
        *(short *)(iVar3 + 0x2e4) = (short)uVar14;
        if (uVar8 < 9) {
          uVar8 = uVar8 + uVar7;
          *(short *)(iVar3 + 0x2e4) = (short)uVar8;
        }
        iVar6 = (uVar8 & 0xffff) + iVar13 * 2;
        *(int *)(iVar3 + 0x2e8) = iVar6;
        iVar12 = uVar10 - *(int *)(iVar3 + 0x2d0);
        iVar6 = FUN_20156260(iVar12 - iVar6,uVar11);
        *(int *)(iVar3 + 0x2ec) = iVar6 + 1;
        uVar15 = FUN_20156260((iVar6 + 2) * iVar4,iVar5);
        *(int *)(iVar3 + 0x2f0) = (int)uVar15;
        iVar6 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
        *(int *)(iVar3 + 0x2f0) = iVar6;
        if (iVar13 != iVar6) {
          do {
            if (*(uint *)(iVar3 + 0x2e0) < *(uint *)(iVar3 + 0x2f0)) {
              *(uint *)(iVar3 + 0x2e8) = *(int *)(iVar3 + 0x2e8) + uVar7;
              *(short *)(iVar3 + 0x2e4) = *(short *)(iVar3 + 0x2e4) + (short)uVar7;
              iVar6 = *(int *)(iVar3 + 0x2e8);
            }
            else {
              iVar6 = *(uint *)(iVar3 + 0x2e0) - 1;
              iVar13 = 1;
              *(int *)(iVar3 + 0x2e0) = iVar6;
              if (uVar7 <= (uint)(iVar6 * 2)) {
                do {
                  iVar13 = iVar13 + 1;
                } while (uVar7 * iVar13 < (uint)(iVar6 * 2) || uVar7 * iVar13 + iVar6 * -2 == 0);
              }
              uVar10 = uVar7 * iVar13 + iVar6 * -2;
              uVar14 = uVar10 & 0xffff;
              *(short *)(iVar3 + 0x2e4) = (short)uVar10;
              if (uVar14 < 9) {
                uVar14 = uVar14 + uVar7;
                *(short *)(iVar3 + 0x2e4) = (short)uVar14;
              }
              iVar6 = (uVar14 & 0xffff) + iVar6 * 2;
              *(int *)(iVar3 + 0x2e8) = iVar6;
            }
            iVar6 = FUN_20156260(iVar12 - iVar6,uVar11);
            *(int *)(iVar3 + 0x2ec) = iVar6 + 1;
            uVar15 = FUN_20156260((iVar6 + 2) * iVar4,iVar5);
            *(int *)(iVar3 + 0x2f0) = (int)uVar15;
            iVar6 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
            *(int *)(iVar3 + 0x2f0) = iVar6;
          } while (*(int *)(iVar3 + 0x2e0) != iVar6);
        }
        FUN_2013e800(*(int *)(iVar3 + 0x2e0) + uVar11,*param_1);
      }
      *(int *)(iVar3 + 0x2d4) = *(int *)(iVar3 + 0x2d4) - *(int *)(iVar3 + 0x2cc);
    }
    else {
      local_28 = 0xfffffffb;
    }
  }
  else if (*pbVar9 >> 6 == 0) {
    iVar4 = FUN_2013f15c(pbVar9);
    iVar5 = FUN_2013f180(pbVar9);
    iVar6 = FUN_2013f1a4(pbVar9);
    uVar10 = (iVar5 + 1) * iVar6 * iVar4;
    FUN_2013f238(uVar10,iVar3 + 0x2c8);
    uVar10 = uVar10 >> 9;
    *(uint *)(iVar3 + 0x2d4) = uVar10;
    uVar1 = *(undefined2 *)(iVar3 + 0x2d8);
    iVar5 = FUN_20156260(uVar10);
    iVar6 = (int)*(char *)(iVar3 + 0x2dc);
    iVar4 = (uint)*(ushort *)(iVar3 + 0x2da) << 3;
    uVar15 = FUN_20156260(iVar5 * iVar6);
    uVar7 = (uint)uVar15 & 0xffff;
    uVar14 = ((int)((ulonglong)uVar15 >> 0x20) != 0) + uVar7;
    *(uint *)(iVar3 + 0x2e0) = uVar7;
    *(uint *)(iVar3 + 0x2e0) = uVar14;
    uVar2 = *(ushort *)(iVar3 + 0x2e4);
    uVar11 = (uint)uVar2 + uVar14 * 2 + 0x20;
    *(uint *)(iVar3 + 0x2e8) = uVar11;
    uVar7 = *(uint *)(iVar3 + 0x2cc);
    if (uVar7 < uVar11) {
      uVar15 = FUN_20156260(uVar11,uVar7);
      uVar8 = uVar7 * ((uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15) - uVar11;
    }
    else {
      uVar8 = uVar7 - uVar11;
    }
    *(uint *)(iVar3 + 0x2d0) = uVar8;
    if (uVar8 != uVar7) {
      uVar8 = uVar8 + uVar7;
      *(uint *)(iVar3 + 0x2d0) = uVar8;
    }
    iVar5 = FUN_20156260((uVar10 - uVar8) - uVar11,uVar1);
    *(int *)(iVar3 + 0x2ec) = iVar5 + 1;
    uVar15 = FUN_20156260((iVar5 + 2) * iVar6,iVar4);
    *(int *)(iVar3 + 0x2f0) = (int)uVar15;
    uVar11 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
    *(uint *)(iVar3 + 0x2f0) = uVar11;
    if (uVar14 != uVar11) {
      do {
        if (*(uint *)(iVar3 + 0x2e0) < uVar11) {
          uVar11 = *(int *)(iVar3 + 0x2d0) + uVar7;
          *(uint *)(iVar3 + 0x2d0) = uVar11;
        }
        else {
          *(uint *)(iVar3 + 0x2e0) = uVar11;
          uVar11 = (uint)uVar2 + uVar11 * 2 + 0x20;
          *(uint *)(iVar3 + 0x2e8) = uVar11;
          if (uVar7 < uVar11) {
            uVar15 = FUN_20156260(uVar11,uVar7);
            uVar11 = uVar7 * ((uint)((int)((ulonglong)uVar15 >> 0x20) != 0) + (int)uVar15) - uVar11;
          }
          else {
            uVar11 = uVar7 - uVar11;
          }
          *(uint *)(iVar3 + 0x2d0) = uVar11;
          if (uVar11 != uVar7) {
            uVar11 = uVar11 + uVar7;
            *(uint *)(iVar3 + 0x2d0) = uVar11;
          }
        }
        iVar5 = FUN_20156260((uVar10 - uVar11) - *(int *)(iVar3 + 0x2e8),uVar1);
        *(int *)(iVar3 + 0x2ec) = iVar5 + 1;
        uVar15 = FUN_20156260((iVar5 + 2) * iVar6,iVar4);
        *(int *)(iVar3 + 0x2f0) = (int)uVar15;
        uVar11 = (int)uVar15 + (uint)((int)((ulonglong)uVar15 >> 0x20) != 0);
        *(uint *)(iVar3 + 0x2f0) = uVar11;
      } while (*(uint *)(iVar3 + 0x2e0) != uVar11);
    }
    FUN_2013e800(*(int *)(iVar3 + 0x2e0) + 0x20,*param_1);
    *(int *)(iVar3 + 0x2d4) = *(int *)(iVar3 + 0x2d4) - *(int *)(iVar3 + 0x2d0);
  }
  else {
    local_28 = 0xffffffff;
  }
  return local_28;
}


// ===== FUN_2013f79c @ 2013f79c (356 bytes)

int FUN_2013f79c(int *param_1)

{
  char cVar1;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined4 unaff_r4;
  uint uVar5;
  
  FUN_2014d148(*param_1 + 0x2c8,0,0x2c);
  iVar3 = FUN_2013f340(param_1);
  if ((((iVar3 == 0) && (iVar3 = FUN_2013f088(param_1), iVar3 == 0)) &&
      ((*(char *)(*param_1 + 0x2dc) == '@' ||
       ((iVar3 = FUN_2013ec30(param_1), iVar3 == 0 &&
        ((*(char *)(*param_1 + 0x2dc) != ' ' || (iVar3 = FUN_2013ea74(param_1), iVar3 == 0))))))))
     && (iVar3 = FUN_2013e8d0(param_1), iVar3 == 0)) {
    iVar3 = *param_1;
    FUN_2014d148(iVar3 + 1,0,0x200,0,unaff_r4);
    cVar1 = *(char *)(iVar3 + 0x2dc);
    if (cVar1 == '\f' || cVar1 == '\x10') {
      uVar5 = 0x20;
      iVar3 = *(int *)(iVar3 + 0x2d0) + (uint)*(ushort *)(iVar3 + 0x2e4) +
              *(int *)(iVar3 + 0x2e0) * 2;
    }
    else {
      if (cVar1 != ' ') {
        return -2;
      }
      uVar5 = (uint)*(ushort *)(iVar3 + 0x2d8);
      iVar3 = *(int *)(iVar3 + 0x2d0) + (uint)*(ushort *)(iVar3 + 0x2e4) +
              *(int *)(iVar3 + 0x2e0) * 2;
    }
    uVar4 = 0;
    if (uVar5 != 0) {
      do {
        iVar2 = FUN_2013e2b4(iVar3,*param_1 + 1,1,param_1);
        if (iVar2 != 0) {
          return iVar2;
        }
        FUN_2013e7e8(*param_1);
        uVar4 = uVar4 + 1;
        iVar3 = iVar3 + 1;
      } while (uVar4 < uVar5);
    }
    return 0;
  }
  return iVar3;
}


// ===== FUN_2013f83c @ 2013f83c (328 bytes)

int FUN_2013f83c(int *param_1)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (**(code **)(param_1[1] + 0x24))();
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = 0;
  do {
    iVar2 = (**(code **)(param_1[1] + 0x20))(2);
    if ((iVar2 == 0) && (iVar2 = FUN_2013dff0(param_1), iVar2 == 0)) {
      if (*(short *)(*param_1 + 0x2c6) == 1) {
        return -5;
      }
      iVar2 = FUN_2013e124(param_1);
      if ((((((iVar2 == 0) &&
             (iVar2 = FUN_2013e190(*(undefined2 *)(*param_1 + 0x2aa),0x200,1,param_1), iVar2 == 0))
            && (iVar2 = FUN_2013d434(*(undefined2 *)(*param_1 + 0x2aa),param_1), iVar2 == 0)) &&
           ((iVar2 = FUN_2013e1e4(param_1), iVar2 == 0 &&
            (iVar2 = FUN_2013d744(param_1), iVar2 == 0)))) &&
          ((iVar2 = FUN_2013df88(param_1), iVar2 == 0 &&
           (iVar2 = FUN_2013c928(1,param_1), iVar2 == 0)))) &&
         (((*(short *)(*param_1 + 0x2c2) != 2 && *(short *)(*param_1 + 0x2c2) != 3 ||
           (iVar2 = (**(code **)(param_1[1] + 0x40))(), iVar2 == 0)) &&
          (iVar2 = FUN_2013f79c(param_1), iVar2 == 0)))) {
        return 0;
      }
    }
    iVar1 = iVar1 + 1;
    if (2 < iVar1) {
      return iVar2;
    }
  } while( true );
}


// ===== FUN_2013f984 @ 2013f984 (96 bytes)

undefined4 FUN_2013f984(char param_1)

{
  undefined1 uVar1;
  int iVar2;
  undefined4 uVar3;
  int local_10;
  
  local_10 = DAT_20808ba0;
  iVar2 = FUN_2014a4a4();
  if (iVar2 != 0) {
    return 0xfffffff8;
  }
  uVar1 = FUN_2014d35c((int)param_1);
  iVar2 = FUN_20144918(uVar1,&local_10);
  if (iVar2 == 0) {
    if (*(int *)(local_10 + 0x24) == 0) {
      return 0xfffffff8;
    }
    uVar3 = FUN_2013f83c();
  }
  else {
    uVar3 = 0xfffffffe;
  }
  return uVar3;
}

