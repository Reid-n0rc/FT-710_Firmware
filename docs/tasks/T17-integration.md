# T17 — Integration: names, RX decoder fix, re-exports, shared-file edits

**Status:** done · **Depends on:** T09–T13 sub-tasks

## Goal
Fold the parallel sub-task results (T09–T12) into the shared files: apply every proposed Ghidra name and missed function
entry, fix the RX SLEIGH `MOVU.B/W Rs,Rd` decoder bug found in T10e (against the Renesas RXv2 software manual), re-analyse and
re-export `decomp/main`, `decomp/display`, `decomp/ifdsp`, switch the pages from proposed (italic) names to final names, and
apply every sub-task's "Proposed shared-file edits".

## Plan
Owner: T17 agent (worktree branch), 2026-10-27. Shared Ghidra projects `ghidra/FT710_{MAIN,DISPLAY,IFDSP}` in the main checkout
(only T17 writes them); exports go into this worktree's `decomp/`. One commit per step, decomp re-exports in their own commits.
1. **RX decoder.** Check `MOVU` (2) ld=11 and the string ops against the RXv2 software manual (pp. 124, 184-198, 259), patch the
   installed `rx62t.sinc` (backup `rx62t.sinc.orig-ea4cd204`), recompile with `support/sleigh`, store the diff as
   `tools/ghidra/rx62t-movu-fix.patch`, document it in `docs/tooling.md`.
2. **MAIN.** A script merges `names_main.T10?.tsv` into `names_main.tsv` (dedupe by address, list conflicts; pick the most specific
   name, keep names already used in the pages when equal). Full re-import with the fixed module (`-max-cpu 16`, 8 GB), ApplyNames,
   ExportDecomp, CatDispatch. Check the listed MOVU functions and the SP checksum sites in the new export.
3. **DISPLAY.** Merge `names_display.T11?.tsv` / `entries_display.T11?.tsv` (renames per T11b/c/e/f), FixFuncEntries → ApplyNames →
   ExportDecomp on the existing project, refresh the INDEX file columns.
4. **IFDSP.** Fold `names_ifdsp.T12{b,c,d}.tsv` into `IfdspM33Names.java` (creates + T12d's removals) and check `IfdspHifi4Names.java`;
   rebuild both programs per `decomp/ifdsp/INDEX.md` with the HiFi4 names script added.
5. **Pages.** Script: replace italic proposed names in `docs/code/{main,display,ifdsp}/*.md` with the applied names (from the
   merged TSVs / functions.tsv), then fix conflict renames.
6. **Shared-file edits.** Work through every `## Proposed shared-file edits` section (T10a-h, T11b-g, T12b-e; T09a/b and T13 have
   none, T13 follow-ups for hardware.md), RX651 hardware manual for quick [inference] → [fact] upgrades.
7. Findings, follow-ups, board changes for the parent.

## Findings
### 1. RX SLEIGH decoder (fixed) [fact]
- RXv2 software manual R01US0071EJ0100 p. 124 / p. 259: `MOVU.size src,dest` format (2) is `0101 1 sz ld rs rd`, and **ld = 11b is the
  register source Rs** (zero-extend); 00/01/10 are [Rs]/dsp:8/dsp:16. The module (`ea4cd204`) decoded ld = 11 as `[Rs]`.
- Also wrong (pp. 184–198): `SCMPU` cleared Z when both strings ended together and used a signed C; `SUNTIL` set no flags; `SWHILE`
  compared the pointer R1 with R2 and stepped .W/.L by 1. `SMOVF`/`SMOVB`/`SSTR` are correct.
- Fix applied to `~/opt/ghidra_12.1.4_PUBLIC/Ghidra/Processors/RX/data/languages/rx62t.sinc` (original kept as `*.orig-ea4cd204`),
  recompiled with `support/sleigh` (same 8 NOP warnings). Patch: `tools/ghidra/rx62t-movu-fix.patch`; record in `docs/tooling.md`.
  REA (MCP and CLI) uses the same installed module.
- **Result on MAIN** (full re-import): all **107** `MOVU.B/W Rs,Rd` sites (`T10eMovuRegCount.java`) now list as register forms, 0 as `[Rs]`.
  - SP checksum sites 0xFFFA3867/38C4/39BB (`cat_ext_SP`) and 0xFFFA510A (`cat_SP_table`) now read `MOVU.W R2,R2`; the decompile is
    `cat_checksum_ok(cmd+4, len-2)`. The "binary SP checksum bug" is withdrawn in cat.md / cat-commands.md.
  - `displink_tx_req` (FUN_fff98bcd) passes `len-1` (was a load from address len-1); `dsp_isp_bridge` (FUN_fffa0c79) indexes the
    buffer with `(len+3) & 0xff` (was a load from address len+3); `dsp_set_vox_gain` (FUN_fff9dc8a) computes `'d' - tx_mod_gain()`
    (was a load from 100-x); `dsp_set_hcut`/`dsp_set_lcut` (FUN_fff9eae7/ed0e) compute `(x-1)*0x32+700` (was `*(short*)(x-1)`);
    `dsp_set_cw_pitch` (FUN_fff9f638) computes `(v+0x1e)*10` (was a load).
  - `sdr_upd_r18_rx_freq` (FUN_fffa1c69), `vfo_mode` (FUN_fffb3196) and `menu_value_rw` (FUN_fffd504c) contain no MOVU Rs,Rd; their
    decompile is unchanged apart from names, so whatever looked odd there is not this decoder bug.
### 2. MAIN
- `names_main.tsv`: 1147 entries (T05/T09 base + T10a–h). **65 conflicts** (table below), resolved by "the sub-task that owns the subsystem
  page wins", plus `sum8` duplicate → `dsp_sum8`. Comment fixes: `@sci_baud_table` field order (T10b), `cat_checksum_ok` note.
- Re-export: 2268 functions (T05: 2252; the 16 new are functions ApplyNames created at names the sub-tasks gave to code labels),
  0 decompile failures, 1136 named. `cat_dispatch.tsv` is unchanged.
- RX651 hardware manual (r01uh0590): PCLKB = 60 MHz is now [fact] (PLLCR 0x1300 → 24 MHz × 10, SCKCR 0x21C21222 → ICLK 120,
  PCLKB 60 MHz; §9.2), the selectable vectors 130/138/142/144/186/189 are [fact] from the `icu_select_init` SLIBXR/SLIBR writes
  (§15.2.25–26, Table 15.3), TPU TCR/TIER and SCI SMR/SEMR meanings [fact] (§26.2, §37.2). Correction: `sdr-link.md` baud formula is
  PCLKB/(8·65), not /(4·65) (the 115 385 baud figure was right).
### 3. DISPLAY
- `names_display.tsv` 768 names, `entries_display.tsv` 68 entries; **49 name conflicts** (below). FixFuncEntries: 68 entries, 8 late
  starts removed. Export: 2087 functions, 0 failures, 772 named. 0x201378B0 is DMAC **channel 8** (0xE8200400), so `dmac8_m2m_start`.
### 4. IFDSP
- `IfdspM33Names.java`: 322 names (now with plate comments), `MERGE_INTO` removes the false entries 0x800EE and 0x80A24 so
  `POWER_CalculateSafetyCount` 0x800E8 and `OTFAD_Init` 0x80A18 own their bodies; NEW entries created. `IfdspHifi4Names.java`: 99 names;
  HiFi4 conflicts go to T12e (owner, FLIX-aware), and T12c's duplicate `memset` at 0x233410 became `xthal_set_region_attribute`
  [inference]. Export: M33 426 functions (0 failures, 387 named), HiFi4 1148 (1 failure as before, 111 named).
- Declined: T12b's proposal to rename MAIN `dsp_*` functions to `ifdsp_*` (T10d owns the DSP link page; `dsp_*` kept).
### 5. Pages and shared files
- `tools/pages_final_names.py` switched every `docs/code/{main,display,ifdsp}` page (plus the INDEX files, cat-commands*, memory-maps,
  hardware) to the applied names: losing names → chosen names, `FUN_<addr>` → name where one exists, italic proposals → code names; the
  "names in italics are proposals" header sentences were rewritten. Manual: `sum8`/`dsp_sum8` in dsp-link.md, `gpio_rx_update(_b)` swap in
  update.md, `vecNNN_isr` → ISR names. Left on purpose: `Thread_Main`/`Thread_Ipc`/`main` (string/thread names), M33 rename chain in ipc.md
  (ipc.md already used the new names).
- Every "Proposed shared-file edits" item of T10a–h, T11b–g, T12b–e and T16 was applied (hardware.md, memory-maps.md, cat.md,
  cat-commands*.md, code/main/README.md, display README/boot-rtos, sdr interfaces/resources, sfl-format.md, tooling.md, the three INDEX
  files, ifdsp README), except those targeting `docs/custom-firmware.md` (see follow-ups). T09a/b have no such section.
- Debug header: **J1004** (p35 parts list: J1004 = 08FLT-SM2 P1091201; J1005 = SB20-08WS P0090615, the cable connector named on p5);
  p17 has no extractable text, so T10c's reading of the symbol stands.
- New tools: `tools/names_merge.py`, `tools/ifdsp_names_java.py`, `tools/pages_final_names.py`, `tools/index_refresh.py`,
  `tools/ghidra/names_{main,display,ifdsp}.picks.tsv`.

### Name conflicts and resolutions

#### MAIN (65 conflicts, `tools/ghidra/names_main.picks.tsv`)

| Address | Chosen | Reason / losers |
|---|---|---|
| 0xFFF89D24 | `scope_span_table` | T10b (ui-keys.md); loser @scope_spans (T10g) |
| 0xFFF8F65E | `R_Systeminit` | T10a+T10h agree; loser hw_periph_init (T10b) |
| 0xFFF927CE | `iwdt_refresh` | T10h owner; loser R_IWDT_Restart (T10a) |
| 0xFFF9283D | `dac0_write` | T10h owner; loser da_write (T10a) |
| 0xFFF92B01 | `r_s12ad0_scan_end_isr` | T10h owner; loser vec186_S12ADI0 (T10a / SetupRX651) |
| 0xFFF92E0F | `r_s12ad1_scan_end_isr` | T10h owner; loser vec189_S12ADI1 (T10a / SetupRX651) |
| 0xFFF92E49 | `R_Pins_Create` | T10h owner; loser R_PORT_Create (T10a) |
| 0xFFF94536 | `sci4_rx_frame_done` | T10d owner (SCI4 = DSP link); loser r_sci4_callback_receiveend (T10b) |
| 0xFFF94548 | `sci4_rx_frame_len` | T10d owner; loser sci4_rx_byte_hook (T10b) |
| 0xFFF94A57 | `r_tpu0_tgia_isr` | T10h owner; loser vec130_TPU0_TGI0A (T10a) |
| 0xFFF94AEC | `r_tpu1_tgia_isr` | T10h owner; loser vec144_TPU1_TGI1A (T10a) |
| 0xFFF94CAB | `qmb_boot_init` | T10e (most specific: re-validates QMB recall state); losers startup_state_init (T10a), ui_link_init (T10b) |
| 0xFFF94D6F | `displink_task` | T10b owner; loser display_link_task (T10a) |
| 0xFFF95331 | `displink_rx_dispatch` | T10b owner; loser display_rx_dispatch (T10a) |
| 0xFFF9546A | `displink_rx_F0_hello` | T10b owner; loser display_power_on_msg (T10a) |
| 0xFFF98797 | `power_down_save` | T10e: the function notifies DISPLAY (0x7F frame), saves and resets, so the T10e name covers it; loser displink_tx_7F_power (T10b) |
| 0xFFF9D1B9 | `dsp_link_poll` | T10d owner; loser dsp_link_task (T10a) |
| 0xFFF9D8A4 | `dsp_reg_access` | T10d owner (device 4 = IFDSP register file); loser dev4_reg_access (T05/T09 base) |
| 0xFFF9D94D | `dsp_isp_request` | T10d owner; loser dsp_tunnel_request (T10b) |
| 0xFFF9FB6E | `dsp_set_freq_range_param` | T10g (value chosen by frequency range, used in radio-control.md); loser dsp_set_band_cal (T10d, not used in any page) |
| 0xFFFA0C79 | `dsp_isp_bridge` | T10d owner; loser dsp_isp_tunnel (T10b) |
| 0xFFFA1132 | `sdr_init` | T10c owner; loser sdr_link_init (T10a) |
| 0xFFFA11ED | `sdr_task` | T10c owner; losers sdr_link_task (T10a), sdr_update_poll (T10g) |
| 0xFFFA162C | `sdr_upd_r08_tx_freq` | T10c owner (register-numbered updater family); loser sdr_set_tx_freq (T10g) |
| 0xFFFA1C69 | `sdr_upd_r18_rx_freq` | T10c owner; loser sdr_set_rx_freq (T10g) |
| 0xFFFA2758 | `sdr_upd_r20_scope_freq` | T10c owner; loser sdr_set_scope_center (T10g) |
| 0xFFFA30F9 | `sdr_send_frame` | T10c owner; loser sdr_reg_send (T10g) |
| 0xFFFB01F3 | `eeprom_init` | T10e owner; loser eeprom_wrsr_init (T10a) |
| 0xFFFB0229 | `eeprom_load_all` | T10e owner; loser settings_load (T10a) |
| 0xFFFB02CF | `eeprom_save_opstate` | T10e owner; losers eeprom_save_state (T10a), menu_save_eeprom (T10f), eeprom_save_vfo_block (T10g) |
| 0xFFFB1168 | `menu_defaults_load` | T10f owner (menu value block); loser defaults_menu (T10e) |
| 0xFFFB1632 | `sci_start_all` | T10b owner (sci.md); loser sci_rx_start_all (T10a) |
| 0xFFFB1900 | `tunlin_port_mode` | T10h: setting 0x9AB7 is the TUN/LIN PORT SELECT menu (0 EXT-TUNER, 1 LINEAR, 2 CAT-3, 3 GPO); loser sci2_port_mode (T10b) |
| 0xFFFB1F83 | `shreg_bus_init` | T10h owner; loser power_on_io (T10a) |
| 0xFFFB2288 | `swtimer_tick` | T10h owner (timers); losers sw_timer_tick (T10a), timer_tick (T10d) |
| 0xFFFB237A | `swtimer_start` | T10h owner; losers sw_timer_start (T10a), soft_timer_start (T10b), timer_start_ms (T10d), timer_start (T10e) |
| 0xFFFB23F3 | `swtimer_expired` | T10h owner; losers sw_timer_expired (T10a), soft_timer_expired (T10b), timer_expired (T10d, T10e) |
| 0xFFFB2419 | `blink_set` | T10h owner; loser sw_blink_set (T10a) |
| 0xFFFB2469 | `tone_sample_isr` | T10h owner; loser tone_dac_step (T10a) |
| 0xFFFB24D8 | `spk_softstart_isr` | T10h owner; loser tpu2_pulse_isr (T10a) |
| 0xFFFB259C | `slowtimer_tick` | T10h owner; loser sw_timer_slow_tick (T10a) |
| 0xFFFB27D1 | `r_tpu3_tgia_isr` | T10h owner; loser vec142_TPU3_TGI3A (T10a) |
| 0xFFFB28D1 | `dac_init_idle` | T10h owner; loser tone_init (T10a) |
| 0xFFFB28E2 | `beep_task` | T10h owner; loser tone_task (T10a) |
| 0xFFFB2E1E | `tone_set` | T10h owner; loser tone_start (T10a) |
| 0xFFFB3BA6 | `dest_jumper_apply` | T10h (JP_P51 strap, tx-protection.md); loser dest_code_fixup (T10e) |
| 0xFFFB3E55 | `sw_reset` | T10a+T10h agree; loser mcu_software_reset (T10e) |
| 0xFFFB4B28 | `supply_undervolt_check` | T10h owner; losers supply_monitor (T10a), power_fail_check (T10e) |
| 0xFFFB55C2 | `rf_ctrl_task` | T10h owner; loser portctl_task (T10a) |
| 0xFFFB6CDE | `trx_init` | T10h owner; loser txrx_init (T10a) |
| 0xFFFB6D56 | `io_task` | T10h owner; loser txrx_power_task (T10a) |
| 0xFFFB6FAC | `tx_line_get` | T10h owner (GPIO); loser gpio_tx_line (T10c) |
| 0xFFFB7051 | `sdr_reset_set` | T10h owner; loser gpio_sdr_reset (T10c) |
| 0xFFFB7067 | `sdr_update_set` | T10h owner; loser gpio_sdr_update (T10c) |
| 0xFFFB7080 | `dsp_reset_set` | T10h owner; losers gpio_dsp_reset (T10c), dsp_reset_pin (T10d) |
| 0xFFFB7098 | `dsp_update_set` | T10h owner; losers gpio_dsp_update (T10c), dsp_update_pin (T10d) |
| 0xFFFB70B0 | `af_reset_set` | T10h owner; loser gpio_af_reset (T10c) |
| 0xFFFB70C9 | `pa_pon_set` | T10h owner; loser gpio_pa_pon (T10c) |
| 0xFFFB721A | `rx_line_get` | T10h owner; loser gpio_rx_line (T10c) |
| 0xFFFB7A40 | `remote_keypad_scan` | T10h owner; loser ladder_key_decode (T10a) |
| 0xFFFBBD58 | `key_task` | T10b owner (ui-keys.md); loser event_task (T10a) |
| 0xFFFBC35F | `key_call_press` | T10b owner; loser event_handler_lookup (T10a) |
| 0xFFFC1927 | `bandstack_save` | T10g owner (radio control); loser bandstack_store (T10e) |
| 0xFFFEDD8C | `r_tpu2_tgia_isr` | T10h owner; loser vec138_TPU2_TGI2A (T10a) |
| 0xFFFA0C01 | `dsp_sum8` | T17: T10d proposed sum8, which duplicates sum8 @ 0xFFFB01AF (EEPROM); renamed to keep names unique |

#### DISPLAY (49 conflicts, `tools/ghidra/names_display.picks.tsv`)

| Address | Chosen | Reason / losers |
|---|---|---|
| 0x20100268 | `wdt_system_reset` | T11b/c/g agree; loser wdt_reset (T11f) |
| 0x20101C74 | `gpio_rx_update` | T11g owner (GPIO); loser gpio_rx_update_2 (T11c) |
| 0x20101CA4 | `gpio_rx_update_b` | T11g owner; loser gpio_rx_update (T11c, the names were swapped) |
| 0x20101DC4 | `gpio_dvr` | T11g owner (gpio_* family); loser dvi_ctrl_pins (T11e) |
| 0x20102708 | `touch_cal_load` | T11f (the 48-byte block holds 6 doubles of touch calibration); loser flashcfg_load (T11g) |
| 0x20102774 | `touch_cal_save` | T11f; loser flashcfg_save (T11g) |
| 0x201033E8 | `tsc2007_tint_isr` | T11f (TSC2007 touch interrupt); loser intc_irq_setup (T06) |
| 0x20106DC8 | `audio_codec_post` | T11d (mailbox of task_audio_codec); loser audio_post_block (T11g) |
| 0x2010A630 | `kbd_layout_tables_init` | T11f owner (USB keyboard); loser kbdmap_tables_init (T11c) |
| 0x2010A898 | `kbdtest_line` | T11f owner; loser kbdmap_handler (T11c) |
| 0x2010A8F8 | `kbdtest_init` | T11f owner; loser kbdmap_init (T11c) |
| 0x2010F370 | `sdmenu_write_dat` | T11g owner (MemList/Menu .dat files, sdmenu_* family); loser sfl_write_file (T11c) |
| 0x2010F60C | `sdmenu_save_file` | T11g owner; loser backup_save_dat (T11c) |
| 0x2010F81C | `sdmenu_load_file` | T11g owner; loser sfl_load_file (T06) |
| 0x201107C0 | `sdr_spi_master_write` | T11d owner (RSPI2); loser sdr_spi_send_block (T11c) |
| 0x20110DA8 | `sdr_debug_init` | T11c owner (sdr_debug_cmd family); loser sdrdbg_init (T11f) |
| 0x20111224 | `kbd_led_status` | T11f owner; loser usbkbd_set_leds (T11c) |
| 0x20111410 | `mainlink_trace_toggle` | T11b owner (the ring logs MAIN-link frames); loser dbglog_toggle (T11f) |
| 0x20111468 | `mainlink_trace_pause` | T11b owner; loser dbglog_pause (T11f) |
| 0x20111480 | `mainlink_trace` | T11b owner; loser dbglog_write (T11f) |
| 0x2011158C | `mainlink_trace_dump` | T11b owner; loser dbglog_dump (T11f) |
| 0x201121A8 | `pclink_set_testmode` | T11d owner (pclink_* family with pclink_stats_print); losers sdr_testmode_set (T11e), spi_slave_test_enable (T11f) |
| 0x2011249C | `pclink_stats_print` | T11d owner; loser sdr_spi_stats_print (T06) |
| 0x20113294 | `mainlink_send_key` | T11b owner (mainlink_send_* family); loser key_event_send (T11f) |
| 0x20114DF4 | `system_reboot` | T11g: describes the whole sequence (FS off, LCD off, MAIN reset pulse, WDT reset); losers mainlink_fail_reset (T11b), update_finish_reset (T11c), system_reset_all (T11f) |
| 0x20114E88 | `uart4_send` | T11b owner (SCIF4 link object; SCIF4 is never started in V01-08); loser dsp_queue_frame (T11f) |
| 0x20115780 | `mainlink_send_enc` | T11b owner; loser renc_frame_queue (T11f) |
| 0x2011598C | `pot5_filter` | T11f owner (front-panel pots); loser renc_ad5_changed (T11b) |
| 0x20115A48 | `pot4_filter` | T11f owner; loser renc_ad4_changed (T11b) |
| 0x20115B04 | `mainlink_renc_event` | T11b owner; loser renc_event_send (T11f) |
| 0x201162A4 | `mainlink_send_hello` | T11b owner; loser powerup_frame (T11f) |
| 0x20116518 | `mainlink_rx_ctrl` | T11b owner; loser mainlink_pause (T11c) |
| 0x20116560 | `mainlink_inject_rx` | T11b rename (it replays a frame locally, it does not transmit); loser mainlink_send_cmd (T06) |
| 0x201165F4 | `mainlink_hello_poweron` | T11b owner; loser powerup_send_combo (T11f) |
| 0x20120E9C | `mainlink_send_touch_key` | T11b owner; loser gui_key_send (T11f) |
| 0x20121C3C | `scr_screen_saver` | T11e owner (GUI, scr_* family); loser gui_screensaver_step (T11b) |
| 0x20125F6C | `scr_lcd_test` | T11e owner; loser gui_lcd_test_pattern (T11b) |
| 0x2012E8F4 | `rtc_set_from_main` | T11e owner; loser gui_rtc_set (T11b) |
| 0x2012EBB8 | `gui_screen_update` | T11e owner; loser gui_apply_frame (T11b) |
| 0x2013059C | `screenshot_popup` | T11e fix (it is the "SCREEN SHOT" popup); loser screen_shot_menu (T06) |
| 0x201355BC | `fb_clear_rect` | T11e fix (fills with 0 = transparent); loser fb_copy_rect (T06) |
| 0x20132320 | `vdc5_module_start` | T11e owner (VDC5); loser vdc5_clock_on (T11g) |
| 0x20132398 | `vdc5_module_stop` | T11e owner; loser vdc5_clock_off (T11g) |
| 0x20134E70 | `debug_cmd_line_read` | T11b (family with debug_replay_send_cmd); loser sendcmd_parse_line (T11e) |
| 0x20134FDC | `debug_replay_send_cmd` | T11b rename (it replays SEND_CMD.TXT); losers debug_recv_cmd_log (T06), test_disp_replay (T11e) |
| 0x201367B4 | `debug_overlay_draw` | T11f (more specific); loser debug_overlay (T11e) |
| 0x201378B0 | `dmac8_m2m_start` | T11d: base 0xE8200400 is DMAC channel 8 (ch0-7 at 0xE8200000 + 0x40*n, ch8-15 at 0xE8200400 + 0x40*(n-8)); loser dmac0_copy (T11e) |
| 0x2015F1F0 | `fwdbg_verify_bank1` | T11c owner (fwdbg_* family with fwdbg_task_create); losers display_flash_verify_bank1 (T11f), display_flash_write_bank (T06) |
| 0x2015F348 | `fwdbg_write_other_bank` | T11c owner; loser display_flash_write_other_bank (T11f) |

#### IFDSP (8 conflicts, `tools/ghidra/names_ifdsp.picks.tsv`)

| Address | Chosen | Reason / losers |
|---|---|---|
| 0x0021BD40 | `ipc_handle_msg` | T12e owner; loser handle_srtm_msg (T12c) |
| 0x0021BE80 | `regfile_set_defaults` | T12e + T12b agree; loser regfile_init_defaults (T12c) |
| 0x0021C060 | `tx_gpio_to_reg4004` | T12e owner; loser regfile_update_gpio_status (T12b) |
| 0x0021C360 | `Thread_Main_entry` | T12e owner (the thread is named "Thread_Main"; this is its entry); loser Thread_Main (T12c) |
| 0x0021C3B4 | `Thread_Ipc_entry` | T12e owner; loser Thread_Ipc (T12c) |
| 0x0021C498 | `xos_create_main_ipc_threads` | T12e owner (the DSP main); loser main (T12c) |
| 0x0021F348 | `meter_to_reg4005` | T12e owner; loser status_level_update (T12b) |
| 0x00233410 | `xthal_set_region_attribute` | T17: T12c proposed memset, which duplicates memset @ 0x235EB0 (T12e); the calls (0x20060000, 0x31E0, 2, 0) / (0x20070000, 0x10000, 2, 0) from the DSP main match the Xtensa HAL (vaddr, size, cattr, flags) signature [inference] (control-link.md, hifi4.md) |

## Follow-ups
- `docs/custom-firmware.md` (T16 owns it): T11c (replace blocker 4 with the update.md §1 check list; SDR row of "Update and recovery
  paths": DISPLAY sends the bitstream over RSPI2 while MAIN bridges registers; no CRC check at boot; key-6 maintenance mode and JTAG
  `loader_selfinstall` recovery) and T11f (the 1-byte debug-console gate patch / options table from input.md) were not applied.
- DISPLAY encoders: `input.md` says encoders 1/2 use MTU2 ch1/ch2, `peripherals.md` puts the ENC0 pins on P10_x; hardware.md follows
  input.md. Recheck.
- HiFi4 `xthal_set_region_attribute` 0x233410 is an inference from the call arguments; confirm in the FLIX listing.
- Optional: commit the HiFi4 FLIX listing (`decomp/ifdsp/hifi4/flix.dis`, ~53k lines) as T12e suggested (command in decomp/ifdsp/INDEX.md).
- The T10x sub-task follow-ups that asked for a recheck after the MOVU fix are answered above (T10b, T10c, T10d).
- Commit hygiene: the step-4 name-script changes landed in the decomp/ifdsp export commit (8c89f31), not in a commit of their own.

### Board changes for the parent (docs/tasks/README.md)
- T17 → done. No new sub-tasks.

## Status
- 2026-10-28: done. Steps 1–7 committed on the T17 worktree branch (RX fix, MAIN/DISPLAY/IFDSP merges and re-exports, pages,
  shared-file edits). Not pushed; `tools/issues_sync.py` not run.
