# T14 — System-level documentation

**Status:** in progress · **Depends on:** T09 T10 T11 T12 T13

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
