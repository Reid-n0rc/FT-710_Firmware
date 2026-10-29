# Task board

Mirrored to GitHub issues (epic #1; numbers in [issues.json](issues.json)) by `tools/issues_sync.py`. One task per session (see AGENTS.md → Task sizing). Update the status here when you start or finish a task.

| ID | Task | Depends on | Status |
|---|---|---|---|
| T01 | [Tooling: install Ghidra + JDK 21](T01-tooling.md) | — | done |
| T02 | [Hardware survey from service manual](T02-hardware-survey.md) | — | done |
| T03 | [SFL container header format](T03-sfl-container.md) | — | done (checksum → T04) |
| T04 | [SFL payload decoding + `tools/sfl_decode.py`](T04-sfl-decode.md) | T03 | done |
| T05 | [MAIN image: arch/base address, Ghidra import, decomp export](T05-decomp-main.md) | T01 T02 T04 | done |
| T06 | [DISPLAY image: same as T05](T06-decomp-display.md) | T01 T02 T04 | done |
| T07 | [IFDSP image: same as T05 (DSP — check Ghidra support)](T07-decomp-ifdsp.md) | T01 T02 T04 | done |
| T08 | [SDR image: split code vs FPGA bitstream, decomp code](T08-decomp-sdr.md) | T01 T02 T04 | done |
| T09 | [CAT command table recovery (MAIN)](T09-cat-commands.md) | T05 | done |
| T09a | [CAT core, reply/AI path, extended + hidden commands](T09a-cat-core-ext.md) | T05 | done |
| T09b | [CAT primary 104-command table, Ghidra names, re-export](T09b-cat-primary.md) | T09a | done |
| T10 | [Document MAIN code (split into sub-tasks)](T10-docs-main.md) | T05 | done |
| T10a | [MAIN overview, boot, main loop and memory map](T10a-main-overview.md) | T05 | done |
| T10b | [MAIN SCI drivers, DISPLAY link (SCI1) and front-panel key events](T10b-main-display-link.md) | T05 | done |
| T10c | [MAIN SDR link (SCI5) and SDR control GPIOs](T10c-main-sdr-link.md) | T05 T13 | done |
| T10d | [MAIN DSP link (SCI4 console protocol, SCI7)](T10d-main-dsp-link.md) | T05 T12a | done |
| T10e | [MAIN EEPROM, data flash and settings persistence](T10e-main-eeprom.md) | T05 T09 | done |
| T10f | [MAIN menu engine (EX) and hidden menu items](T10f-main-menu.md) | T05 T09 | done |
| T10g | [MAIN band, VFO, mode, frequency and memory control](T10g-main-radio-control.md) | T05 T09 | done |
| T10h | [MAIN TX control, protection, meters and other peripherals](T10h-main-tx-peripherals.md) | T05 T09 | done |
| T11 | [Document DISPLAY code](T11-docs-display.md) | T06 | done |
| T11a | [DISPLAY overview, boot and RTOS](T11a-display-overview.md) | T06 | done |
| T11b | [DISPLAY ↔ MAIN UART link](T11b-display-mainlink.md) | T06 | done |
| T11c | [DISPLAY SD card and firmware update paths](T11c-display-update.md) | T06 | done |
| T11d | [DISPLAY SPI links (SDR, DSP, FT4222H)](T11d-display-spi.md) | T06 | done |
| T11e | [DISPLAY GUI and LCD](T11e-display-gui.md) | T06 | done |
| T11f | [DISPLAY input (touch, keys, encoders, USB HID)](T11f-display-input.md) | T06 | done |
| T11g | [DISPLAY misc peripherals and files](T11g-display-misc.md) | T06 | done |
| T12 | [Document IFDSP code](T12-docs-ifdsp.md) | T07 | done |
| T12a | [IFDSP overview + boot/memory map](T12a-ifdsp-overview.md) | T07 | done |
| T12b | [IFDSP M33 console / command link](T12b-ifdsp-m33-console.md) | T12a | done |
| T12c | [IFDSP M33↔HiFi4 IPC (MU-A, rpmsg)](T12c-ifdsp-ipc.md) | T12a | done |
| T12d | [IFDSP M33 platform (boot, DSP loader, RTOS)](T12d-ifdsp-m33-platform.md) | T12a | done |
| T12e | [IFDSP HiFi4 DSP code (threads, audio I/O, tables)](T12e-ifdsp-hifi4.md) | T12a | done |
| T13 | [Document SDR/FPGA](T13-docs-sdr.md) | T08 | done |
| T14 | [System-level documentation + figures](T14-docs-system.md) | T09–T13 | done |
| T15 | [FPGA netlist recovery (SDR)](T15-fpga-netlist.md) | T13 | done |
| T15a | [Bitstream to FASM (SDR)](T15a-fpga-fasm.md) | T13 | done |
| T15b | [FASM to cell-level netlist (SDR)](T15b-fpga-netlist-cells.md) | T15a | done |
| T15c | [Block recognition (SDR)](T15c-fpga-blocks.md) | T15b | done |
| T15d | [Structural Verilog netlist + smoke test (SDR)](T15d-fpga-verilog.md) | T15b | done |
| T15e | [Behavioral RTL of the UART link (SDR)](T15e-fpga-uart-rtl.md) | T15c T15d | done |
| T16 | [Custom-firmware groundwork (SFL encoder, loader rules, first patch)](T16-custom-firmware.md) | T04 T11c | done |
| T17 | [Integration: names, RX decoder fix, re-exports, shared-file edits](T17-integration.md) | T09–T12 | done |
| T18 | [Check the docs against the Renesas RX651 documentation](T18-renesas-docs-check.md) | T05 T10 T17 | done |
| T19 | [Illustrated guide for people](T19-illustrated-guide.md) | T01–T18 | done |
| T19a | [Guide: The radio and how the chips talk](T19a-guide-the-radio-and-how-the-chips-talk.md) | T19 | done |
| T19b | [Guide: A day in the life (power-on, tuning, transmit, scope)](T19b-guide-a-day-in-the-life-power-on-tuning-transmit-scope.md) | T19 | done |
| T19c | [Guide: Firmware files and updates](T19c-guide-firmware-files-and-updates.md) | T19 | done |
| T19d | [Guide: CAT remote control](T19d-guide-cat-remote-control.md) | T19 | done |
| T19e | [Guide: Inside MAIN and DISPLAY](T19e-guide-inside-main-and-display.md) | T19 | done |
| T19f | [Guide: Inside IFDSP and SDR](T19f-guide-inside-ifdsp-and-sdr.md) | T19 | done |
| T19g | [Guide: Hacking and custom firmware](T19g-guide-hacking-and-custom-firmware.md) | T19 | done |
| T19h | [Fix reference-page issues found while writing the guide](T19h-reference-fixes.md) | T19a–g | done |
| T20 | [Onboarding: rebuild everything from the official downloads + getting-started manual](T20-onboarding.md) | T01–T19 | done |
| T21 | [Close the Ghidra decompile gaps (#97)](T21-ghidra-gaps.md) | T05, T07, T11, T12e, T17, T20 | in progress |
| T21a | [HiFi4: SLEIGH generator and the language Xtensa:LE:32:rt600hifi4](T21-ghidra-gaps.md) | T21 | done |
| T21b | [HiFi4: test oracle against flix.dis, function list](T21-ghidra-gaps.md) | T21 | done |
| T21c | [MAIN: RXv2 coverage diff, string ops as pcodeops](T21-ghidra-gaps.md) | T21 | done |
| T21d | [MAIN: spacebase, call signatures, ROM data definition](T21-ghidra-gaps.md) | T21 | done |
| T21e | [DISPLAY: jump tables, missed function starts, fragments](T21-ghidra-gaps.md) | T21 | done |
| T21f | [All images: decompile-quality counts and regression check](T21-ghidra-gaps.md) | T21 | done |
| T21g | [Integration: rebuild the canonical projects, re-export decomp/](T21-ghidra-gaps.md) | T21a–f | done |
| T21h | [MAIN: decode the two RX fragments left undefined](T21-ghidra-gaps.md) | T21c, T21g | done |
| T21i | [MAIN: memory effect for the RX string instructions](T21-ghidra-gaps.md) | T21c, T22e | done |
| T21j | [DISPLAY/IFDSP: T22d's entry, block and data fixes](T21-ghidra-gaps.md) | T21g, T22d | done |
| T22 | [Verify the #97 fixes with independent REA and rizin tools](T22-rea-verification.md) | T21 | in progress |
| T22a | [MAIN: RX fixes and signatures, third-decoder check](T22-rea-verification.md) | T21c, T21d | done |
| T22b | [DISPLAY: jump tables, starts and fragments, second analyser](T22-rea-verification.md) | T21e | done |
| T22c | [HiFi4: rizin base-ISA check, REA decompile with the new language](T22-rea-verification.md) | T21a, T22f | done |
| T22d | [All images: classify the undefined bytes left](T22-rea-verification.md) | T21 | done |
| T22e | [All images: before/after behaviour diff](T22-rea-verification.md) | T21g | done |
| T22f | [REA fork: add the missing device support](T22-rea-verification.md) | – | done |

Later (don't plan these in detail yet): the inter-CPU protocol. Custom-firmware feasibility is assessed in [docs/custom-firmware.md](../custom-firmware.md); the work items are T15 and T16.

## Run plan (2026-10-09)

Parallel agents, each with its own Ghidra project and output dirs; the parent owns this board's top-level rows, `issues_sync.py` and pushes.

1. Wave 1 (parallel): **T13** (SDR, no Ghidra), **T09** (MAIN project), **T11** (DISPLAY project), **T12** (IFDSP project).
2. Wave 2: **T10** (MAIN docs, split into sub-tasks) once T09 has released the MAIN project.
3. Wave 3: **T14** (system docs) once T09–T13 are done.

Agents add their own sub-task rows (`T13a`…) directly under their parent row.
