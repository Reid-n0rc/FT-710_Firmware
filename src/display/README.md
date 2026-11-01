# DISPLAY (RZ/A1H Cortex-A9): recreated source (T24, started)

The source of the FT-710 front-panel program (`FT-710_DISPLAY_V0108`), to be recreated function by function. The
image was built with **armcc** (ARM Compiler 5) on the **NORTi** µITRON kernel (docs/code/display/README.md).
Neither is available, so nothing here can be byte-identical: the recreated C is built with GCC and each function is
checked against the original by differential emulation (`tools/equiv_display_emu.py`, Unicorn in A32 mode).
Plan and status: [docs/tasks/T24-source-recreation.md](../../docs/tasks/T24-source-recreation.md).

| Path | What |
|---|---|
| `app/crc.c` | `crc16_xmodem` (0x2010AA30): equivalent, 200 trials |

## Check

```sh
arm-none-eabi-gcc -O2 -marm -mcpu=cortex-a9 -ffunction-sections -c app/crc.c -o out/crc.o
FT710_BUILD=/path/to/build python3 -I ../../tools/equiv_display_emu.py out/crc.o crc16_xmodem=2010aa30
```

The harness takes leaf functions without data references for now. **Never commit `out/`.**
