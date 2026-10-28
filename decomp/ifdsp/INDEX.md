# IFDSP decompile index (FT-710_IFDSP_V0101, NXP i.MX RT685)

Ghidra 12.1.4 output for the IF DSP image (T07). There are two programs in the Ghidra project `ghidra/FT710_IFDSP`:

| Dir | Program | Core / language | Functions exported | Decompile failures | Notes |
|---|---|---|---|---|---|
| `m33/` | `FT-710_IFDSP_V0101.bin` | Cortex-M33, `ARM:LE:32:v8-m` | 426 (318 in SRAM, 108 in flash, mostly IRQ stubs); 387 named (T17) | 0 | The rest of the 31.5 KB SRAM code range is literal pools and rodata. T12d: the "undecodable instruction" T07 saw at 0x80A24/0x80A90 is 0xFFFFFFFF padding after a literal pool; 0x80A24 was the inside of `OTFAD_Init` 0x80A18 (T17 removed that entry and the one at 0x800EE inside `POWER_CalculateSafetyCount` 0x800E8) |
| `hifi4/` | `FT-710_IFDSP_V0101_hifi4.bin` | Cadence HiFi4, `Xtensa:LE:32:default` | 1148; 111 named (T17, `IfdspHifi4Names.java`) | 1 (`FUN_0020bb74`, the decompiler process died) | **Low quality:** 955 functions hit HiFi4 FLIX bundles or bad data. See "HiFi4 limitations" |

Each `*.c` file holds 50 functions and is named `<first>_<last>.c` by entry address. `functions.tsv` lists entry, name, size, callers and file.
Memory map and derivation: `docs/memory-maps.md`, IFDSP section. Claims are tagged **[fact]** (seen in code or data) or **[inference]**.

## How to regenerate

```sh
python3 -I tools/sfl_decode.py Firmware/FT-710_IFDSP_V0101.SFL build/FT-710_IFDSP_V0101.bin
python3 -I tools/ifdsp_dsp_images.py build/FT-710_IFDSP_V0101.bin build      # carves the 3 HiFi4 images
# Cortex-M33
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -import build/FT-710_IFDSP_V0101.bin -overwrite \
  -processor ARM:LE:32:v8-m -loader BinaryLoader -loader-baseAddr 0x08000000 -scriptPath tools/ghidra \
  -preScript IfdspM33Setup.java -postScript IfdspFindFuncs.java -postScript IfdspM33Names.java \
  -postScript ExportDecomp.java decomp/ifdsp/m33 50 -analysisTimeoutPerFile 3600
# HiFi4
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -import build/FT-710_IFDSP_V0101_hifi4.bin -overwrite \
  -processor Xtensa:LE:32:default -loader BinaryLoader -loader-baseAddr 0x0 -scriptPath tools/ghidra \
  -preScript IfdspHifi4Setup.java -postScript IfdspHifi4FindFuncs.java -postScript IfdspHifi4Names.java \
  -postScript ExportDecomp.java decomp/ifdsp/hifi4 50 -analysisTimeoutPerFile 3600
# HiFi4 FLIX-aware listing decomp/ifdsp/hifi4/flix.dis (T12e; Zephyr SDK RT600 objdump, see docs/tooling.md; bootstrap step flix):
python3 -I tools/ifdsp_hifi4_dis.py ~/opt/zephyr-sdk-0.17.0/xtensa-nxp_rt600_adsp_zephyr-elf/bin/xtensa-nxp_rt600_adsp_zephyr-elf-objdump \
  build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin decomp/ifdsp/hifi4/functions.tsv decomp/ifdsp/hifi4/flix.dis tools/ghidra/IfdspHifi4Names.java
# Inspect a few functions without a full export:
tools/ghidra-headless.sh "$PWD/ghidra" FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis -readOnly \
  -scriptPath tools/ghidra -postScript DumpFuncs.java build/ifdsp_funcs.c main 0x00084ad8
```

## Architecture in one paragraph

The M33 runs a small **FreeRTOS** application entirely from SRAM (copied to 0x00080000 by `ResetISR`). `main` sets up clocks, pins and
GPIO, loads the three **HiFi4 images** (`BOARD_DSP_Init`), releases the DSP stall, and handshakes over **MU-A**. It then starts three tasks:
**Command Task** (a text console on **FLEXCOMM0 USART** with a `>> ` prompt), and **IpcRecvTask/IpcSendTask** (rpmsg-lite over MU-A to the DSP). **[fact]**
The DSP image runs **Cadence XOS** threads `Thread_Main`, `Thread_Ipc`, `Thread_Rx_Audio`, `Thread_Spi`, `Thread_Rx_Path` and `Thread_Tx_Path`
**[inference from strings at DSP 0x206370]**, and it holds the peripheral base tables for FLEXCOMM0–7, DMA and GPIO. The M33 never touches
FLEXCOMM1–5, so the RX-IF/TX-AF I2S, the codec I2S and the FFT/REC/PLAY SPI to the DISPLAY CPU (docs/hardware.md Q2002) are all **driven by the DSP** **[inference]**.

## Cortex-M33: notable functions (`m33/`)

| Address | Name | File | What it does |
|---|---|---|---|
| 0x080011A8 | `ResetISR` | 000874b0_080012ec.c | VTOR=0x08001000, MSP=0x200000, MSPLIM=0x1FF000, calls `SystemInit`, walks `__data_section_table`/`__bss_section_table`, then `call_main` **[fact]** |
| 0x08001222 / 0x08001234 | `data_init` / `bss_init` | 000874b0_080012ec.c | memcpy / memset loops for the copy tables **[fact]** |
| 0x08001540 | `SystemInit` | 080012f4_08001668.c | FPU enable (CPACR/NSACR), SYSCTL0 DSPSTALL=1, CACHE64 (0x40033000) setup **[fact]** |
| 0x080017A8 | `call_main` | 08001678_08001808.c | → `main` |
| 0x000872AE / 0x0008106C | `main` / `app_main` | 00086778_00087470.c | `main` calls `stdio_init` and tail-jumps to `app_main` (Ghidra shows both bodies merged under `main`): board init (clock/pins/GPIO port 0–2, INPUTMUX 0x40026000), `BOARD_DSP_Init`, then MU-A handshake: polls `MU_SR (0x40110060) & 7` for 1 and then 3, enables things via 0x40112000. Creates the tasks and starts the scheduler **[fact]** |
| 0x00084AD8 | `BOARD_DSP_Init` | 00084150_00085e2c.c | **DSP loader**: clock/reset setup (`CLOCK_InitSysPfd`, `CLOCK_AttachClk`, `CLOCK_SetClkDiv`, `DSP_Init`), 3× `DSP_CopyImage({src,dst,size})`: 0x08001844→0x24000000 (0x20644), 0x08021E88→0x00200000 (0x383B4), 0x0805A23C→0x20040000 (0x31E0), then `SYSCTL0 DSPSTALL (0x4000200C) = 0` **[fact]** |
| 0x00086EAA | `DSP_CopyImage` | 00086778_00087470.c | memcpy wrapper taking the {src,dst,size} struct **[fact]** |
| 0x00080D0C | `uart0_init` | 0008000c_000818b8.c | FLEXCOMM0 (0x40106000) USART setup **[fact: base]** |
| 0x00080E50 | `FLEXCOMM0_IRQHandler` | 0008000c_000818b8.c | **USART link**: RX into a 1 KB ring (0x87EC8) and notifies the Command Task. TX drains a 1 KB ring (0x882D4) to FIFOWR **[fact]** |
| 0x00080CA4 | `uart0_write` | 0008000c_000818b8.c | queues bytes into the TX ring and enables the TX interrupt **[inference]** |
| 0x00080D78 | `CommandTask` | 0008000c_000818b8.c | waits on a notification, pulls RX bytes, calls `console_rx_char` **[fact]** |
| 0x00081430 | `console_rx_char` | 0008000c_000818b8.c | line editor + command interpreter (Ctrl+C, echo, `d`/`D` hex dump of 0x40 16-bit words via `regfile_read`, `r`, `?` error reply, `>> ` prompt) **[fact: strings]**. FC0 carries `DSP_UMISO/UMOSI`, which also go to the J2009 debug header (docs/hardware.md). **T12: this is the MAIN↔IFDSP control link** (MAIN sends `i DB00` and `r`/`w` register frames; see `docs/code/ifdsp/control-link.md`) **[fact]** |
| 0x000813B4 / 0x000812FC | `console_cmd_r` / `console_cmd_d` | 0008000c_000818b8.c | print `r %04X %04X` / ` %04X` dumps **[fact]** |
| 0x00080FE8 | `ipc_print_dsp_reply` | 0008000c_000818b8.c | formats DSP replies by category/command: 0 = "Component versions from DSP", 1 = Mute on/off/error, 3 = "DSP Version %04X" **[fact]** |
| 0x00080F80 | `create_IpcTasks` | 0008000c_000818b8.c | creates `IpcRecvTask` (0x85FC6) and `IpcSendTask` (0x80F50), stack 0x1800 each **[fact]** |
| 0x00080E20 | `create_CommandTask` | 0008000c_000818b8.c | `xTaskCreate(CommandTask, "Command Task", 0x1800, …)` **[fact]** |
| 0x000818B8 | `MU_A_IRQHandler` | 0008000c_000818b8.c | dispatches MU-A interrupts to registered callbacks (table at 0x88720) **[fact]** |
| 0x00081C28 | `rpmsg_lite_master_init` | 000818d0_00082ae0.c | rpmsg-lite `rx_vq`/`tx_vq` setup **[inference]** |
| 0x00082278 / 0x00082418 / 0x00082DB0 | `xTaskCreate` / `vTaskStartScheduler` / `prvTimerTask` | 000818d0_00082ae0.c | FreeRTOS kernel (`Tmr Svc`, `TmrQ`) **[inference]** |
| 0x00080AC0 / 0x00080B20 / 0x00086558 | PendSV / SVC / SysTick | | FreeRTOS ARM_CM33 port handlers (in SRAM) **[inference]** |
| 0x00084EB0 | `vsnprintf_core` | 00084150_00085e2c.c | printf engine (`0123456789abcdef`, `(null)`) used by `snprintf`/`sprintf` **[inference]** |

String-referencing functions: `console_rx_char`, `console_cmd_d`, `console_cmd_r`, `ipc_print_dsp_reply`, `create_*Task*`,
`rpmsg_lite_master_init`, `prvCheckForValidListAndQueue` (`TmrQ`), `xTimerCreateTimerTask` (`Tmr Svc`), `_Csys_alloc` (`*** _Csys_alloc failed`), `vsnprintf_core`.
Grep `"` in `m33/*.c` to find them.

Not present on the M33: no I2S, SPI or I2C peripheral access (FLEXCOMM1–7 pages are never referenced) **[fact]**. T12 correction: the M33
does configure the TLV320AIC3204 codec, through a GPIO bit-banged SPI (`aic3204_init` 0x00080BD0), and it drives SCT0 PWM output 0 **[fact]**.
T12 renamed 140 M33 functions, and T17 merged the T12b–d proposals (`tools/ghidra/IfdspM33Names.java`, 322 names with plate comments,
conflicts in `tools/ghidra/names_ifdsp.picks.tsv`); the full function tables are in `docs/code/ifdsp/`.

## HiFi4: notable addresses (`hifi4/`)

| Address | Name | What |
|---|---|---|
| 0x24020000 | `_ResetVector` | J → 0x24020044 (thunk, so not in the export) |
| 0x24020044 | `FUN_24020044` | reset handler: INTENABLE=0, VECBASE=0x24020400, ATOMCTL=0x15, I/D cache invalidate, then a bad instruction (unsupported in Ghidra's Xtensa module) |
| 0x24020400–0x24020540 | `_WindowOverflow4` … `_WindowUnderflow12` | register-window vectors |
| 0x2402057C–0x2402063C | `_Vector_57c` … `_Vector_63c` | interrupt-level / exception vectors (levels not yet assigned) |
| 0x002062D4.. / 0x00206370.. | strings | `rx_vq`, `tx_vq`, the rpmsg `VQ: %s - size=%d…` debug format; XOS thread names; XOS thread states (`suspend`, `delay`, `exited`, `event`, `mutex`) |
| 0x00206498.. | `.literal` | L32R literal pools: SRAM pointers, peripheral bases |
| 0x00207000–0x002367FF | `.text` | 1081 `entry` prologues (all seeded as functions) |
| 0x00236800–0x002383B3 | `.data` | float coefficient tables (filters) **[inference]** |

### HiFi4 limitations
Ghidra's Xtensa module decodes the base ISA only. It maps every `op0=0xE` word to a 3-byte `FLIX` placeholder, but HiFi4 FLIX bundles
are wider (T12c: the op0=0xE bundles in this image look 6 bytes long, `tools/ifdsp_xtdis.py`), so disassembly desynchronises inside any DSP kernel. Most function bodies are truncated at the first bundle
(the average exported body is 26 bytes). Control code (XOS, rpmsg, drivers) decompiles partly. The signal-processing code does not.
Function **entries** are still reliable, because they come from 4-aligned `entry a1,N` prologues. For the real instruction stream use
the FLIX-aware listing [`hifi4/flix.dis`](hifi4/flix.dis) (about 52,000 lines, 1065 functions with names), made with the Zephyr SDK RT600
HiFi4 objdump (`tools/ifdsp_hifi4_dis.py`, command above; T12e, `docs/code/ifdsp/hifi4.md`). It is committed (issue #87) and
rebuilt and compared by `tools/bootstrap.sh` (step `flix`). What Ghidra itself would need to decode the bundles (and the size of the gap: 891 of 1065 functions, 46 % of the code
bytes) is in [`docs/code/ifdsp/ghidra-flix.md`](../../docs/code/ifdsp/ghidra-flix.md).
