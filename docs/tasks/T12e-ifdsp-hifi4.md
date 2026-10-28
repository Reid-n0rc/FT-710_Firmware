# T12e — IFDSP HiFi4 DSP code (threads, audio I/O, tables)

**Status:** done (2026-10-27) · **Parent:** T12 · **Depends on:** T12a

## Goal
`docs/code/ifdsp/hifi4.md`: XOS threads, peripheral base tables and which FLEXCOMM/DMA each thread uses, audio paths (RX IF, TX AF, codec, SPI to DISPLAY), coefficient tables, what can be learned despite the base-ISA-only Xtensa decode.

## Plan
1. Own Ghidra copy `FT710_IFDSP_T12e`; create `tools/ghidra/IfdspHifi4Names.java` (format of `IfdspM33Names.java`), seed with
   the T12a names after checking each one (thread entry = function pointer passed next to the name literal in the creator's
   literal pool; verify with the L32R scan and the decomp), apply to the copy only.
2. Tooling check: look for an open decoder that handles HiFi4 FLIX (binutils xtensa overlays: Espressif `xtensa-overlays`,
   Zephyr `xtensa` SoC overlays for NXP RT600 `nxp_rt600_adsp`; Zephyr SDK ships prebuilt `xtensa-nxp_rt600_adsp_zephyr-elf`
   binutils). If installable from a reputable source, install under `~/opt`, run objdump on the carved image, compare.
3. Threads and drivers: for each creator/entry, list stack size, priority, literal pool (peripherals, buffers, callees);
   map FLEXCOMM2–5 I2S + DMA channels, buffer sizes, sample rate (clock literals, FCLK dividers), FC1 SPI to DISPLAY.
4. Register file: scan every L16UI/S16I off the 0x2006FF00 / 0x20077F00 bases (`tools/ifdsp_regscan.py`, plus the better
   decode if step 2 works) → per-function register reads/writes; cross-reference with the MAIN register list (T12b).
5. Numeric content: new stdlib scanner `tools/ifdsp_coef_tables.py` over rodata 0x200000–0x206498 and .data 0x236800+:
   float32 / Q15 / Q31 runs, symmetry (linear-phase FIR), sum (DC gain), biquad-shaped groups (b0 b1 b2 a1 a2, stability),
   window shapes, sin/cos tables; characterize (taps, cutoff estimate via DFT magnitude) and link to referencing functions.
6. Write `docs/code/ifdsp/hifi4.md` (function tables, Mermaid thread/audio figures, tables section, decode limits), Findings,
   proposed shared-file edits, name TSV if useful; commit. Starting notes from T12a below. No HiFi4 names script exists yet; create `tools/ghidra/IfdspHifi4Names.java` in the same format as `IfdspM33Names.java`.

## Starting notes (from T12a)
- Method that works despite FLIX: a heuristic L32R scan (byte0 low nibble 1; target = ((pc+3)&~3) + (imm16|0xFFFF0000)<<2) per function range from `functions.tsv`, resolving literal values. Scripts: `tools/ifdsp_l32r.py` and `tools/ifdsp_regscan.py` (args: `build/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin decomp/ifdsp/hifi4/functions.tsv`); output `build/ifdsp_hifi4_l32r.txt`.
- Thread creators (name literal → creator): `Thread_Main`+`Thread_Ipc` 0x21C498 (entries 0x21C360, 0x21C3B4; also 0x20060000/0x200631E0, 18.432 MHz, 24 MHz), `Thread_Rx_Audio` 0x220BD0 (entry 0x220F90), `Thread_Spi` 0x224A10 (entry 0x224AA4), `Thread_Rx_Path`+`Thread_Tx_Path` 0x225E40 (entries 0x2262FC, 0x22647C; DMA1 + FC2).
- Peripheral literals per function: DMA0 0x220FD0; FC1 0x2210A4/0x2210DC/0x22111C (buffers 0x200607E0, 0x200619E0); FC2+DMA1 0x225E40; FC3/FC4/FC5 0x2260D8 (8 DMA buffers 0x20062BE0 + n·0xC0); MU-B 0x212D00/0x212DAC/0x21C3B4; SEMA42 0x213D10; FlexSPI 0x20BB00/0x20C92C; SDK FLEXCOMM instance stubs 0x20B904..0x20BA90 (FC0–7, 14, 15); clock/reset driver 0x207D58..0x209B30.
- Register file: DSP uses base 0x2006FF00 (reg = imm8 − 0x80 via L16UI/S16I) and 0x20077F00 (0x4000 + imm8 − 0x80). 0x21BE80 writes defaults to regs 1–0x68 and 0x4001–0x4025 (matches the MAIN register list in T12b). 0x21C060 reads GPIO P0_21/P0_22 and writes reg 0x4004; 0x21F348 writes reg 0x4005 (PWM duty); 0x223320/0x22338C use 0x20078010/12 (regs 0x4008/0x4009); 0x22E990 uses regs 0x21/0x22. Reads mostly happen inside FLIX code and are not decodable.
- Strings: only XOS, rpmsg, libm (`powf`, `sqrtf`) and printf tables — no algorithm names. Float tables in rodata 0x200000–0x206000 and .data 0x236800+.

## Findings
- **FLIX decode solved**: the Zephyr SDK v0.17.0 toolchain `xtensa-nxp_rt600_adsp_zephyr-elf` (binutils 2.38 with the RT600 HiFi4
  overlay; official GitHub release, SHA-256 checked) disassembles the whole image, FLIX bundles and HiFi4/FPU ops included. Installed in
  `~/opt/zephyr-sdk-0.17.0/`. `tools/ifdsp_hifi4_dis.py` makes a per-function listing (1065 functions; 57 bogus Ghidra entries dropped).
- **Threads [fact]**: Main prio 4 (100 ms poll: GPIO → reg 0x4004, 1 s XOS CPU load → regs 0x2000–0x2007), Ipc prio 13 (rpmsg remote,
  msgq 10 × 152 B), Rx_Path / Tx_Path prio 7 (2 ms blocks, woken by the codec DAC / ADC DMA callbacks), Rx_Audio prio 6 (12-block
  batches), Spi prio 5 (scope/spectrum to DISPLAY). All six T12a entry addresses confirmed from the `xos_thread_create` arguments.
- **Audio I/O [fact]**: FC2 TX (TX AF, DMA1 ch5), FC3 RX (RX IF, ch6), FC4 RX (codec ADC, ch8), FC5 TX (codec DAC, ch11); all I2S
  slave, 32-bit / 64-bit frame, 24-frame ping-pong DMA (8 × 0xC0 at 0x20062BE0). FC1 = SPI master 1 MHz on DMA0 ch2/3. HiFi4 clock
  594 MHz. Sample rate **12 kHz** [inference: 1/12000 constants, 5999 Hz clamp].
- **Register file**: defaults table and a per-register reader/writer table with thread attribution in the page; reg 6 = mode
  (jump table of 11), reg 0x20 = TX gain in dB, reg 0x45 = type + frequency, reg 0x4020 selects one of four 257-tap FIRs.
- **Tables**: `tools/ifdsp_coef_tables.py` characterises ~100 referenced tables: four 257-tap linear-phase lowpass FIRs (700/1000 Hz,
  sharp/gentle), seven IIR voice passbands (35–3199 … 23–4137 Hz; SSB TX BPF-style), CTCSS 50-tone list + 316 Hz subtone lowpass +
  ~300 Hz highpasses, FFT twiddles (2π/1024, 2π/512), ramps, libm polynomials. All float32; no Q15/Q31 tables.
- `tools/ghidra/IfdspHifi4Names.java`: 67 names, applied to `ghidra/FT710_IFDSP_T12e` (67/67 ok).

## Follow-ups
- Per-algorithm documentation of the RX/TX chains (NR, NB, notch, AGC, demod) from the FLIX listing; map reg 6 values to modes with
  T10/T12b MAIN setters.
- Parent: apply `IfdspHifi4Names.java` to the shared project, re-export `decomp/ifdsp/hifi4/`, consider committing a FLIX listing.

## Proposed shared-file edits
- `docs/tooling.md`: add "Zephyr SDK 0.17.0 `xtensa-nxp_rt600_adsp_zephyr-elf` toolchain (GNU binutils 2.38, RT600 HiFi4 core
  overlay). Source: https://github.com/zephyrproject-rtos/sdk-ng/releases/tag/v0.17.0, asset
  `toolchain_linux-x86_64_xtensa-nxp_rt600_adsp_zephyr-elf.tar.xz` (SHA-256 2e0a54e20056b82cae12593e5d936d1e22cdb3f90cb9e77d59c500a5ad4abdc2,
  matches the release sha256.sum), extracted to `~/opt/zephyr-sdk-0.17.0/` (no install script, no sudo). Its objdump decodes the IFDSP
  HiFi4 FLIX bundles; used by `tools/ifdsp_hifi4_dis.py`." and list `tools/ifdsp_hifi4_dis.py`, `tools/ifdsp_coef_tables.py`,
  `tools/ghidra/IfdspHifi4Names.java`. Note: Espressif overlays (ESP32 cores) do not match the RT600 config, so they were not tried.
- `decomp/ifdsp/INDEX.md` "HiFi4 limitations": replace the "correct decode needs the RT685 core configuration" sentence with a pointer
  to the Zephyr RT600 objdump + `tools/ifdsp_hifi4_dis.py`, and add the regeneration command; add `-postScript IfdspHifi4Names.java` to the
  HiFi4 import command. Optionally commit the FLIX listing as `decomp/ifdsp/hifi4/flix.dis` (~53k lines, private repo).
- `docs/code/ifdsp/README.md`: correct "FC4 codec I2S out / FC5 in" wording to "FC4 = codec ADC into the DSP (I2S RX), FC5 = DAC from
  the DSP (I2S TX)"; add HiFi4 594 MHz, 12 kHz / 24-sample blocks; thread priorities (Main 4, Ipc 13, Rx/Tx_Path 7, Rx_Audio 6, Spi 5).
- `docs/memory-maps.md` (IFDSP): DSP .bss 0x2383B4–~0x2CC000; DMA buffers 0x20062BE0 + n·0xC0; regs 0x2000–0x2007 = XOS CPU load.

## Status
Done 2026-10-27: `docs/code/ifdsp/hifi4.md`, `tools/ifdsp_hifi4_dis.py`, `tools/ifdsp_coef_tables.py`, `tools/ghidra/IfdspHifi4Names.java`.
