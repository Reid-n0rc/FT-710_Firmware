# T11d — DISPLAY SPI links (SDR, DSP, FT4222H)

**Status:** done · **Depends on:** T06 · **Parent:** [T11](T11-docs-display.md)

## Goal
Part of T11 (document the DISPLAY firmware). Deliverable: `docs/code/display/spi-links.md`: RSPI0–4 driver, which channel goes where, scope/waterfall data from the SDR, FFT/REC/PLAY data from the DSP, the FT4222H path from the PC.

## Plan
T11d agent, 2026-10-27 (worktree branch). Read-only work on `decomp/display/` plus raw disassembly (`arm-none-eabi-objdump`) where Ghidra lost
jump tables; no Ghidra write needed (the parent applies names).
1. Decode the generic RSPI driver 0x2011D9A8-0x2011F970 (register table 0x20166B4C, per-channel open/ISR/read/write) and the DMAC channel set-ups
   0x20137080-0x20137E88 (CHCFG, DMARS MID/RID, callbacks).
2. Follow each user: `task_spi_slave` (RSPI0 + DMA ch9/ch10), `FUN_20133484`/`FUN_201330d4`/`FUN_201331dc` (RSPI2/RSPI4 + DMA ch3/4/5), the SDR
   update path (`FUN_201107c0`, master mode). Identify channel -> pin group from `pinmux_init`, GPIO reads and the debug-overlay labels.
3. Frame formats, buffers, consumers (scope, AF-FFT, REC/PLAY WAV in `task_audio_codec`, PC TX block).
4. Write `docs/code/display/spi-links.md`, `tools/ghidra/names_display.T11d.tsv`, `tools/ghidra/entries_display.T11d.tsv` (missed ISR stubs and
   late starts); proposed shared-file edits go below. Original plan text follows.

Find the functions for this subsystem from strings, peripheral registers and call graphs in `decomp/display/`; name them in
`tools/ghidra/names_display.tsv`, re-apply with `ApplyNames.java` and re-export `decomp/display/` (separate commit); write the page with function
tables (address, Ghidra name, inferred name, purpose), data structures, globals and Mermaid figures; tag claims [fact]/[inference]/[guess].

## Findings
Page: [docs/code/display/spi-links.md](../code/display/spi-links.md). 129 names proposed in `tools/ghidra/names_display.T11d.tsv`, 19 missed
entries in `tools/ghidra/entries_display.T11d.tsv` (10 RSPI ISR stubs, 5 DMA ISR stubs, 4 late starts).
- DISPLAY is the **SPI slave** on all three links, every one DMA-driven, all 8-bit MSB-first SPI mode 1 (`rspi_hw_config` 0x2011D9A8) [fact].
  RSPI1/RSPI3 unused [fact].
- **SDR = RSPI2** (P8_3..6): 1700-byte frames by DMA ch5 into 0x605C00A0, re-armed by an SS IRQ (GIC 535). The first 850 B go to the scope record
  0x204832BB (25-byte header + 800 points, one per screen column), which feeds the waterfall history [fact/inference]. For the SDR update RSPI2 is switched
  to **master** (about 2 MHz) and sends the image in 0x1000-byte blocks over the FFT pins (`FUN_201107C0`) [fact], which confirms T13's hypothesis.
- **DSP = RSPI4** (P2_8..11): 4600-byte full-duplex frames (DMA ch4 RX ping-pong, ch3 TX). Bytes 0..599 = AF-FFT record (0x208DD73C), bytes 600..4599 = 4000 B of
  PCM that `task_audio_codec` records as WAV **16 kHz, 2 ch, 16 bit**, so 16 frames/s [inference]. TX carries playback PCM from a 16-slot ring, or silence [fact].
- **FT4222H = RSPI0** (P2_12..15): DMA ch9 sends a 4 KB block to the PC continuously (850 B SDR scope + 600 B AF-FFT + 151 B MAIN status + trailer
  0x01EE01FF) [fact]. The bridge reset P2_7 follows bit 2 of the MAIN settings byte 0x208007E8 [fact]. A **test mode** (key code 4 held at start-up) also
  receives PC frames (magic 0xEEAFCCBA) and shows the `CS_POLL/MOSI/MISO/FRAMES` box. That box is the existing `sdr_spi_stats_print`, which is misnamed
  (proposed `pclink_stats_print`) [fact].
- Ghidra drops the `ldr pc,[pc,r0,lsl #2]` jump tables in the RSPI helpers (`rspi_open/start/stop/reset_buffers`). The bodies were read from the disassembly.

## Proposed shared-file edits
- `docs/code/display/README.md` subsystem table: spi-links.md → done. Key findings: "the PC gets the scope/AF-FFT over the FT4222H (RSPI0); DSP REC/PLAY is 16 kHz stereo PCM over RSPI4".
- `docs/hardware.md` (DISPLAY, FT4222H bullet): replace "purpose unknown" with "streams the scope (850 B), AF-FFT (600 B) and a 151-byte status block to the PC in 4 KB SPI frames; DISPLAY is the slave (see docs/code/display/spi-links.md)" [fact for the code].
- `docs/hardware.md` (SDR module update path) and `docs/code/sdr/interfaces.md` open point 1: DISPLAY sends the SDR image over RSPI2 in master mode on the FFT pins [fact: `FUN_201107C0`].
- `docs/memory-maps.md` (DISPLAY): uncached SPI DMA buffers 0x60500000–0x60503FFF and 0x605C00A0/0x605C0780.
- `decomp/display/INDEX.md`: add an "SPI links" section after the rename pass.
- Merge `names_display.T11d.tsv` (including the rename 0x2011249C `sdr_spi_stats_print` → `pclink_stats_print`) and `entries_display.T11d.tsv`.

## Follow-ups
- Confirm the RSPI↔pin and GIC 535/449↔TINT pin mapping with the RZ/A1H datasheet tables (not in the repo).
- T12/T15: the SDR scope header (25 B), the unused second half of each SDR DMA frame, and the DSP frame bytes 1–3 and 602–603.
- T11e: drawing from the scope record / history ring (0x20134318, 0x20134328); T11g: `task_audio_codec` REC/PLAY slot format.

## Status
- 2026-10-27: done (page, names and entries TSVs). Not yet applied to Ghidra or re-exported (that is the parent's rename pass).
