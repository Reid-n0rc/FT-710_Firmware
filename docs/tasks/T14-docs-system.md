# T14 — System-level documentation

**Status:** done · **Depends on:** T09 T10 T11 T12 T13

## Goal
`docs/code/system.md`: how the whole radio fits together, built from the per-image docs.

## Deliverables
- A figure of the whole-radio block diagram (CPUs, FPGA, buses, USB/CAT path, SD card).
- Sequence diagrams: power-on boot of all CPUs, the firmware-update flow (SD → DISPLAY → MAIN/DSP/SDR), a CAT command round trip (PC → CP2105 → MAIN → other CPUs → reply), and a frequency change from the knob to the SDR.
- The inter-CPU protocol summary (message formats per link), linking to the per-image pages.

## Plan
Built from the pages only (docs/hardware.md, memory-maps.md, cat-commands.md, custom-firmware.md, docs/code/{main,display,ifdsp,sdr}/*.md);
the decomp is used only to settle a contradiction.

1. Read every per-image README and the link pages on both ends of each link (MAIN display-link/sdr-link/dsp-link/cat/radio-control/
   tx-protection/ui-keys, DISPLAY mainlink/update/spi-links/input/peripherals/boot-rtos, IFDSP control-link/hifi4, SDR interfaces).
2. Write `docs/code/system.md`, figures split so each stays ≤ ~25 nodes:
   - block diagrams: (a) processors and inter-CPU buses, (b) USB/CAT/PC path (hub, CP2105, CM119B, FT4222H), (c) audio/IF signal path,
     plus a debug-header table;
   - sequences: power-on of all CPUs; firmware update overview + one per image (MAIN serial boot, DISPLAY bank write, IFDSP ISP relay,
     SDR RSPI2 + bridge); CAT round trip with AI; frequency change dial → SDR NCO + display; TX key-down; scope/waterfall path to GUI and PC;
   - inter-CPU protocol table (framing, baud, checksum, ack/retry, page);
   - "where to find X" index across images;
   - contradictions / open questions list with a resolution or owner per row.
3. Settle the DISPLAY encoder-pin question (input.md MTU2 ch1/ch2 vs peripherals.md P10_x) from `decomp/display` and fix the page if clear.
4. Update the top-level `README.md` with a short overview linking system.md and the per-image READMEs.
5. Findings, follow-ups, proposed shared-file/board edits here; status done; commit.

## Findings
Deliverable: [`docs/code/system.md`](../code/system.md). 14 Mermaid figures (all parse with mermaid 10.9.1; each flowchart ≤ 13 nodes),
the inter-CPU protocol table (13 links incl. the unused SCI7 / SCIF4), a "where to find X" index (20 topics × 4 images), and a
contradictions/open-questions list (C1–C13, O1–O6). Top-level `README.md` now has an overview linking system.md and the per-image READMEs.

Cross-image findings (the tags are the claims' tags):
- **Control topology [fact]:** DISPLAY powers and releases MAIN (`RX_PWR_ON` P7_9, `RX_RESET` P7_10) and wakes it with `F0`; MAIN releases
  the FPGA (P77, then waits 1 s) before the RT685 (P71); the RT685 runs on the FPGA's `DSP_CLK`, which explains the order **[inference]**.
- **Common link design [inference from facts on each page]:** all three MAIN control UARTs are shadow-register links: send only on change,
  one frame per `main_loop` pass, implicit retry via the shadow. The DISPLAY link does the same per frame. FPGA and DSP never send unsolicited
  data on their UARTs; their bulk data (scope, AF-FFT, REC/PLAY) goes straight to the DISPLAY over SPI with the FPGA/RT685 as master.
- **C3 settled from decomp/display [fact for the call path]:** `F0` code 6 is sent only by `mainlink_hello_key6` 0x2011668C, called only
  from `logo_fade_in` 0x2012FD94 (from `power_on_request` 0x2012FFCC and `gui_main_loop` 0x20130188 when boot combination 6 is held); plus the
  MAIN-update writer sends it to the new MAIN. So code 6 = "DISPLAY in maintenance/loader screen, keep MAIN off". Both link pages describe it
  differently ("going down" / "normal").
- **F0 hello is sent only after power-on [inference]:** the callers of `mainlink_hello_poweron` 0x201165F4 are `opening_screen` and
  `mainlink_wait_status`; the loop is 30 × (`mainlink_send_hello`, `itron_dly_tsk(5)`), so MAIN's "every ~50 ms" is wrong (C2).
- **C4 (encoder pins) settled, page fixed:** `docs/code/display/peripherals.md` rows for P3_1/P3_3, P3_2/P3_5, P9_0, P10_0/1/3 plus a note.
  Schematic ENC*n* = firmware id *n*+1; ENC2 P3_3/P3_5 = IRQ4 encoder id 3 **[fact: `renc_irq4_isr` reads PPR3 bits 3/5]**; ENC0
  (P10_0/P10_1) and ENC1 (P9_0/P10_3) are the only encoder pins put into a peripheral function by `pinmux_init` 0x20101190, so they are the
  MTU2 ch1/ch2 TCLK inputs **[inference]**; ENC3 (P3_1/P3_2) has no handler **[inference]**.
- **C1 baud:** MAIN SCI1 is 340 909 bit/s, nominal 345600 on the DISPLAY side: 1.4 % apart, not a fault **[inference]**.
- **C9 new open point:** DSP blocks at 12 kHz **[inference, strong]** vs. REC WAV at 16 kHz; the FC1 buffer spacing (0x1200) does match
  the 0x11F8-byte RSPI4 frame **[fact]**.
- **C7 open:** the FPGA boots from flash address 0, the update writes 0x240000 / 0x480000 (golden + multiboot?) — for T15.
- **C6 open:** how `PS1;` reaches the DISPLAY while the link is down is not traced on either side.

## Follow-ups
- C6: trace MAIN readers of 0x20B9C / 0x1B3D0 in the power-off loop and DISPLAY callers of `FUN_20117288` (T10b/T11b owners).
- C7 / O3: SDR flash slot layout, reg 0x32 commands, scope frame header and rate (T15).
- C9: HiFi4 `Thread_Spi` packing of the 4000-byte PCM part (T12e follow-up).
- O1: how `boot_error` 0x20B36 is shown (DISPLAY use of the `0x60` frame).
- O2: map MAIN 0x43/0x44/0x45 + C3/C4/C5 to the DISPLAY `sdmenu_*` MemList/Menu backup code.
- O4/O5 (hardware): CM119B analog routing, RZ/A1H USB0/USB1 lines through J6002.
- With the RZ/A1H pin-function table (not in the repo), confirm which of P10_0/P10_1/P9_0/P10_3 is TCLKA..D.

## Proposed shared-file edits
1. `docs/code/display/mainlink.md` §1 "Line": replace "345600 baud … on both sides" with "345600 baud nominal (DISPLAY `scif_open(0x54600)`);
   MAIN's SCI1 setting gives 340 909 bit/s (1.4 % low), within UART tolerance [inference]" (C1).
2. `docs/code/display/mainlink.md` §4 DISPLAY → MAIN, row 0xF0: replace "6 = normal" with "6 = sent by `mainlink_hello_key6` from
   `logo_fade_in` (boot combination 6, maintenance/loader screen) and by the MAIN-update writer; MAIN marks the link down and stays off" (C3).
   Row 0xE6: "beep request (MAIN calls `beep_request`(1..3)) [inference]" (C5).
3. `docs/code/main/display-link.md`: in the link-control figure change "every ~50 ms" to "every 5 ms (`itron_dly_tsk(5)`, ≈ one 10 ms
   tick)" (C2). F0 boot-code table, row 0x06: meaning "DISPLAY maintenance/loader screen (boot combination 6) or first hello after a MAIN
   update" (C3). E2 row: "SD-card state (DISPLAY `mainlink_send_sd_state`) [inference]". Frame 0x40 row: replace the scope/meter guess with
   "status + menu list (five 0x2D-byte text slots, DISPLAY side) [fact on the DISPLAY side]" (C5).
4. `docs/code/sdr/README.md` key findings: "MAIN's `SDR_UPDATE` drives the module pin labelled WP; it is held **low** during an update, so it
   acts as an update-mode input to the FPGA, not a plain write-protect [inference] (main/sdr-link.md)". Boot figure: "MAIN reads reg 0 and 1
   after a 1 s wait [fact, main/sdr-link.md]" (C8, C13).
5. `docs/custom-firmware.md` summary table: drop "(hardware.md says J1005, see below)" (C10); "DISPLAY updates itself by writing the
   other bank (running 1 → bank 2 at 0x18A00000, else bank 1 at 0x18400000)" (C11); IFDSP bullet: MAIN side is [fact] (`dsp_isp_bridge`
   0xFFFA0C79, main/dsp-link.md) (C12).
6. `docs/hardware.md`: link `code/main/peripherals.md#gpio-map` is broken; the anchor is `#gpio-map-fact-unless-tagged`. Q2002 boot
   configuration bullet: "[fact for the DISPLAY side, inference for MAIN]" → "[fact, both sides: display/update.md §7, main/dsp-link.md]" (C12).
7. `docs/code/ifdsp/README.md` or hifi4.md: note the 12 kHz vs 16 kHz REC rate question (C9).

### Board changes (proposal)
- `docs/tasks/README.md`: T14 row status → **done**.
