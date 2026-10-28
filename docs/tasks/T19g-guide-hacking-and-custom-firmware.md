# T19g — Guide: Hacking and custom firmware

**Status:** done · **Depends on:** T19 (style guide)

## Goal
Write the draft chapter `docs/guide/parts/08-hacking-and-custom-firmware.md` with its SVG pictures in `docs/guide/img/`, for the single guide document, following the style guide in [T19](T19-illustrated-guide.md).

## Plan
Chapter `## 8. Hacking and custom firmware`, sources: custom-firmware.md, patches/README.md, patches/fpga-jtag-hello.md,
hardware.md (headers), T16, T18, system.md §2.4/§8 (C7), tx-protection.md (US 60 m), T09 (read-only CAT candidates),
sdr/netlist.md §5.3 (FPGA `[IF]>` console). Chapter 4 owns the update mechanism and SFL format; only point there.

Sections and figures:
1. 8.1 Is it possible? — `img/08-scorecard.svg`: per-chip scorecard (signed, encrypted, lock bits, debug header, toolchain).
2. 8.2 The debug headers — `img/08-debug-headers.svg`: four FFC connectors drawn with numbered pins, board/chip, adapter.
3. 8.3 How risky is each step? — `img/08-risk-ladder.svg`: six rungs from zero risk to "never".
4. 8.4 The prepared patches — `img/08-patches.svg`: banner and gate patch byte anatomy + JTAG RAM-write alternative,
   stamped NOT APPLIED; Mermaid flow of the debug-console plan (step 0 → step 1 → rollback).
5. 8.5 The FPGA "hello" — `img/08-fpga-hello.svg`: stage-1 design inside the FPGA (BSCANE2, CFGMCLK counter, USERID,
   no pins), cable on J2001, rollback by power cycle.
6. 8.6 Decisions waiting for the owner — `img/08-decisions.svg`: checklist with risk tags.
7. 8.7 Golden rules — `img/08-golden-rules.svg`: three rules + the option-setting memory hazards.
8. 8.8 Where to look.
Each SVG checked with xmllint + rsvg-convert and viewed; commit per figure/section.

## Findings
Draft chapter `docs/guide/parts/08-hacking-and-custom-firmware.md` ("## 8. Hacking and custom firmware"): In short, then
8.1 scorecard (no signatures, no encryption, option memory all 0xFF, OTP unknown, HiFi4 the hard part; patching first),
8.2 the four debug headers and adapters (+ SD card as recovery), 8.3 risk ladder (rungs 0–5 with the way back),
8.4 the prepared patches (banner, one-byte debug gate, JTAG RAM write; NOT APPLIED) with a Mermaid flow of the
step 0 / step 1 plan and its risks, 8.5 FPGA hello stage 1 (plan only; stage 2 and the `[IF]>` console),
8.6 decisions waiting for the owner (incl. C6/C7/C9 note), 8.7 golden rules, 8.8 Where to look (addresses here only).
Chapter 4 is pointed to for the update mechanism and SFL format.

Figures (7 SVG + 1 Mermaid), all checked with xmllint + rsvg-convert and viewed:
- `img/08-scorecard.svg` — per-chip scorecard (Fig 8.1)
- `img/08-debug-headers.svg` — J1004, J6003, J2009, J2001 pinouts + adapters (Fig 8.2)
- `img/08-risk-ladder.svg` — risk ladder (Fig 8.3)
- `img/08-patches.svg` — banner, gate patch bytes, JTAG RAM alternative, stamped NOT APPLIED (Fig 8.4)
- Mermaid — debug-console plan step 0 → step 1 → rollback (Fig 8.5)
- `img/08-fpga-hello.svg` — FPGA stage-1 design and procedure, PLAN ONLY (Fig 8.6)
- `img/08-decisions.svg` — owner decision checklist (Fig 8.7)
- `img/08-golden-rules.svg` — three rules + option-byte one-way doors (Fig 8.8)

## Glossary terms
- SFL — Yaesu's update-file format: a text header plus a payload scrambled with a fixed 43-byte key and a salted CRC-32.
- Option-setting memory — 116 bytes in the RX651 flash that hold its protection and start-up settings (ID code, lock bits, watchdog start).
- OTP fuses — one-time-programmable bits in the RT685 that can enable signed or encrypted boot.
- FINE — Renesas' one-wire debug interface used by the E1/E2 emulators.
- Serial boot mode — the RX651's built-in ROM loader, selected by pins at reset, that programs the flash over a UART.
- JTAG — the standard 4/5-wire test and debug port used to halt CPUs, read and write memory, and load FPGAs.
- SWD — ARM's two-wire Serial Wire Debug, a slimmer alternative to JTAG for Cortex-M chips.
- FFC — flat flexible cable; the debug headers are FFC sockets that need a breakout board.
- Verilator — an open-source simulator that turns Verilog into a fast C++ model; used for the recovered FPGA netlist.
- USERCODE — a 32-bit value stored in an FPGA bitstream and readable over JTAG; identifies which design is loaded.
- BSCANE2 — a Xilinx primitive that lets the FPGA design add its own registers to the JTAG chain.
- Dual bank — DISPLAY keeps two image slots in its SPI flash and boots the one whose flag is valid.

## Reference issues
- `docs/patches/fpga-jtag-hello.md` (stage 2, follow-ups) and `docs/custom-firmware.md` blocker 3 / next steps still say the
  UART_DBG pin and the netlist are future T15 work. T15/T15e have since mapped UART A = UART_DBG (M18/L18, CSG324 names)
  and found the stock `[IF]>` debug console ([code/sdr/netlist.md](../code/sdr/netlist.md) §5.3, interfaces.md). Stale,
  not contradictory; the guide mentions the console as a later finding.
- `docs/patches/fpga-jtag-hello.md` "Package" says "CPG236 bonds 57, CSG325 82, FTG256 97" of 116 sites; netlist.md §3.1
  says those packages "lack 19 to 59" of them. 116 − 57 = 59 and 116 − 97 = 19, so they agree; no fix needed (noted only
  because the two phrasings look different).

## Follow-ups
- Parent: fix the cross-chapter anchors (`#4-firmware-files-and-updates`, `#5-cat-remote-control`,
  `#7-inside-ifdsp-and-sdr`) and renumber figures (the Mermaid flow is Figure 8.5 here).
