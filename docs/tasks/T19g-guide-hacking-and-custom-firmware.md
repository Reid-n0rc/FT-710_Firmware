# T19g — Guide: Hacking and custom firmware

**Status:** in progress · **Depends on:** T19 (style guide)

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

## Follow-ups
