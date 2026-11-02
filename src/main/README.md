# MAIN (RX651): recreated source (T24)

The source of the FT-710 control program (`FT-710_MAIN_V0112`, Renesas RX651), recreated function by function. The
image was built with **Renesas CC-RX** at optimization level 0, with Renesas Code Generator (`r_cg_*`) drivers and no
RTOS (identification and its evidence: [docs/tasks/T24-source-recreation.md](../../docs/tasks/T24-source-recreation.md),
"MAIN, round 1"). CC-RX is not available here, so the recreated C is built with **GCC 13.3.0 for RX**
(`-mcpu=rx600`, docs/tooling.md "GCC for RX") and each function is checked against the original by differential
emulation in Ghidra's p-code emulator (`tools/equiv_main_emu.py` with `tools/ghidra/EquivMainEmu.java`; Unicorn has no
RX). A few trivial functions (empty `*_UserInit` hooks, the TPU start/stop pairs) come out byte-identical at their
original addresses. What the code does: [docs/code/main/](../../docs/code/main/README.md). Per-function status:
[status.tsv](status.tsv) (generated).

| Path | What |
|---|---|
| `drivers/sci_cfg.h` | the six SCI channels as constant descriptions (registers, interrupt bits, pins, driver state); every value with the function it comes from |
| `drivers/r_cg_sci.c` | `R_SCIn_Create`, `_Start`, `_Stop`, `_Serial_Receive`, `_Serial_Send`, `_Create_UserInit` for SCI0..SCI5 (one inline helper per operation, folded per channel) |
| `drivers/r_cg_sci_user.c` | the TXI/RXI interrupt handlers, the TEI/ERI group-interrupt handlers, Yaesu's callbacks and receive hooks (`r_sci0_rx_byte_hook`, `sci3_rx_byte_hook`, `sci5_rx_byte_hook`, `sci4_rx_frame_done`, ...) |
| `drivers/eeprom.c` | the BR25G256 SPI EEPROM, bit-banged on port E: `eeprom_spi_tx`, `eeprom_spi_rx`, `eeprom_read`, `eeprom_write` (64-byte pages, WIP poll) |
| `drivers/r_cg_misc.c` | IWDT (`R_IWDT_Create`, `iwdt_refresh`), DA (`R_DA_Create`, `R_DA0_Start/Stop`, `dac0_write`), TPU0/TPU1 (`R_TPUn_Create/Start/Stop`, the TGIA handlers) |
| `drivers/r_cg_s12ad.c` | S12AD unit 0 and 1: `R_S12ADn_Create/Start/Stop/Get_ValueResult` and the scan-end handlers |
| `drivers/r_cg_init.c` | `icu_select_init` (selectable interrupt sources), `R_Pins_Create`, `mpc_pin_functions_init`, `FUN_fff92e25` (ICU IRQ disable) |
| `lib/runtime.c` | the CC-RX library pieces: `strncmp` (no NUL stop), `__udiv64`, lowsrc `charput`/`charget`/`close`, `sbrk`, `heap_getmem` |
| `bsp/r_bsp.c` | `R_BSP_InterruptRequestEnable/Disable` and the CC-RX intrinsic helpers `get_bpsw`, `get_bpc`, `get_extb`, `get_acc_hi`, `get_acc_mi` |
| `app/settings.c` | the settings store: the RAM mirror of the EEPROM at 0x464F, `eeprom_init`, `eeprom_load_all`, `eeprom_hdr_update`, the `eeprom_save_*` family, `settings_defaults`, `reset_memch`/`reset_menu`, `eeprom_read_raw`/`_write_raw` (round 2) |
| `app/reglink.h` | the register-link protocol shared by the DSP (SCI4) and SDR (SCI5) links: frame, sum, reply check, write-if-changed, over a constant link description (round 2) |
| `app/dsp_link.c` | `dsp_send_frame`, `dsp_check_reply`, `dsp_sum8`, `dsp_reply_sum_ok`, `dsp_set_demod` and the constant and route-table register setters (round 2); the TX audio, parametric EQ, AMC, CTCSS, DNR, DNF, CONTOUR, APF, notch, HCUT/LCUT, AF tone, AGC, RF gain, AESS and IF-AGC setters (`struct af_menu` over the six mode-group menus) and `dsp_shadow_store` as a register -> slot table (round 3) |
| `app/sdr_link.c` | the SCI5 glue (`sdr_link_start`, `sdr_rx_*`, `sdr_send_cmd`), `sdr_send_frame`, `sdr_poll_reply`, `sdr_sum8`, `sdr_check_hex_sum` and the constant / one-setting register updaters (round 2); `sdr_upd_r18_rx_freq`, `sdr_upd_r1d_notch`, `sdr_upd_r1e_passband` (one passband-centre helper) and `sdr_shadow_update` (round 3); `sdr_task`, one register write per pass (round 4); `sdr_upd_r25_tx_drive`, the TX drive interpolated in the band's TX gain row (round 5) |
| `app/cat_link.c` | the CAT ring, ports and busy flags (`cat_ring_*`, `cat_send_reply`, `cat_tx_done_sci0/2/3`, `cat_tx_busy`), `sum8`, `cat_checksum_ok`, `cat_reply_error`, `cat_ID`, `cat_QI/QR/QS/EN/FS`, `cat_ai_holdoff`, `cat_rand8` (round 2) |
| `app/display_link.c` | the SCI1 glue, ACK/NAK, `displink_tx_start`/`_resend`/`_put_sum`, `displink_copy_if_changed`, `mem_zero` and the send-if-changed frame senders 0x20, 0x24, 0x37, 0x39, 0x41, 0x50, 0x62, 0x70, plus 0x23 and the 0x60 hello (round 2); `displink_task` (receive, ACK/NAK, gap and ACK window), `displink_rx_E1_encoder`, the 0x97-byte status block `displink_build_status` and the frame builders 0x30, 0x31, 0x37, 0x39, 0x41, 0x60, 0x70, `dispreq_e7_task` (round 4); `displink_tx_schedule` (the send priority list) and `displink_rx_F0_hello` (the DISPLAY's version, date and boot code) (round 5) |
| `app/tasks.c` | the small main-loop tasks `wdt_kick`, `rf_ctrl_task`, `io_task`, `scan_task`, `dispreq_e8_task` (round 4) |
| `app/trx_lines.c` | the TX/RX sequencer's lines: `tx_line_get`, `rx_line_get`, `send_a_get`, `send_a_set`/`send_b_set` (gated by ETUN_TXINH_REQ and TX), `ptt_source_get` (round 2); `trx_sequencer`, the RX->TX / TX->RX state machine (round 3) |
| `app/cat_parse.c` | `cat_parse` (ring and E9 slot, mnemonic lookup, power-off gate, reply), `cat_dispatch` with one case per `enum cat_cmd` index (echo, length test, handler; decomp/main/cat_dispatch.tsv), `cat_dispatch_ext`, `cat_ext_SP` (round 3) |
| `app/cat_handlers.c` | the CAT read/set handlers AG AI AO AV BA BC BI CS CT DN EX FN GP KP KR KS LK MA MB MS MX NB NL NR PA PL PR PS RA RG RL SC SD SM ST TX UP VD VG VX ZI (round 3); SQ, SF, DT, EM, KM (round 4); AB, AM, BM (round 6) |
| `app/cat_util.h` | the helpers the CAT handler files share: the reply end, the key filter, decimal print and parse in 8, 16 bits, the mode -> per-mode block selector, big-endian u16 (round 4) |
| `app/cat_scope.c` | `cat_SS`, the scope settings (round 4) |
| `app/cat_dsp.c` | `cat_CO`, `cat_BP`, `cat_SH`, `cat_GT`: CONTOUR/APF, NOTCH, WIDTH, AGC on the per-mode block (round 4) |
| `app/cat_vfo.c` | `cat_FA_FB`, `cat_IF_OI`, `cat_CF`, `cat_MR`, `cat_MW`, `cat_MC`, `cat_VM`: VFO frequency, information, clarifier, memory read/write/recall, V/M (round 4) |
| `app/tuner.c`, `app/keyer.c` | `tuner_task` (dispatch by TUNER SELECT), `tuner_init`, `atu_ac_get`/`atu_tc_get`; `keyer_init`, `keyer_state_clear`, `keyer_ring_next`, `keyer_sidetone_off` (round 2); `keyer_task`, the keyer and message-memory state machine; `tuner_int_task`, `tuner_ext_task`, `tuner_atas_task`, `tuner_rearm` (round 4) |
| `app/beep.c` | `beep_task`, the beep patterns on soft timer 0x16 (round 5; the request, stop and tone functions are in `ui_beep.c`) |
| `app/swr_squelch.c` | `swr_meter_protect` (SWR, HI-SWR alarm, pinning), `fm_noise_squelch`, `signal_level_squelch`: the float code step for step in the image's order (round 5) |
| `app/fpu_conv.h` | `ftou()` (CC-RX's FTOU, which GCC for RX has not) and a bit-level `is_nan()` (GCC tests float compares with S alone, so a NaN passes `a >= b`) (round 5) |
| `app/keys.c` | `ladder_key_task`, the remote-keypad dispatch over three action tables (round 5) |
| `app/main_loop.c` | `main_loop`, the 16 tasks for ever; checked for one pass (round 5) |
| `app/cat_ai_ex.c` | CAT auto information for the EX menu: `cat_ai_ex_scan` over the 296-entry detector table, `cat_ai_ex`, `cat_ai_ex_holdoff`, the formatters `ai_ex_fmt_u8` / `ai_ex_fmt_u16_4`, the detectors as one macro per shape and the 18 PRESET-row detectors (round 6; `ai_ex010517` not: it reads an uninitialised stack byte) |
| `app/cat_ai.c` | `cat_ai_poll`, the AI broadcaster, and 53 of its detectors (`cat_ai_AC` .. `cat_ai_VX`, `cat_ai_FD`, `cat_ai_IF_OI`); not `cat_ai_MG`, `cat_ai_MX` (uninitialised returns) and `cat_ai_SS` (round 6) |
| `app/cat_ext.c` | the extended commands `cat_ext_JP` (region code) and `cat_ext_EO` (frequency and encoder steps) (round 6) |
| `bsp/r_bsp_sys.c` | the FIT BSP (UI track): `R_BSP_SoftwareLock`/`HardwareLock` and unlocks, `R_BSP_InterruptsEnable/Disable`, `R_BSP_CpuInterruptLevelRead/Write`, `R_BSP_RegisterProtectEnable/Disable`, `R_BSP_SoftwareDelay`, `R_BSP_InterruptWrite/Read/Control`, `bsp_fit_interrupts_control`, `bsp_interrupt_group_enable_disable`, `bsp_interrupt_enable_disable`, the exception vectors and SWINT ISRs, the software-interrupt queue (`R_BSP_SoftwareInterrupt*`, `bsp_swint_*`), the clocks (`get_iclk_freq_hz`, `mcu_clock_setup`, `clock_source_select`), `bsp_non_existent_port_init`, the CC-RX setters (byte-identical) |
| `app/meters.c` | VDD, IDD, ALC, PO, COMP and S meters, their 16-sample averages and getters, `meter_task`, `adc_scan_blocking`, `vdd_scale_calc`, `remote_keypad_scan` (UI track) |
| `app/ui_dial.c`, `app/ui_beep.c` | `dial_step_hz`, `dial_step_mode_hz`, `ch_step_hz`, `ch_step_scale`; `beep_request`, `beep_stop`, `beep_pattern_get`, `tone_idle`, `tone_set` (UI track) |
| `app/ui_funcknob.c`, `app/ui_keys.c`, `app/ui_kbd.c` | the FUNC-knob pop-up entries and steps (`funcknob_*`); `key_class_of`, `key_assign_slot`, `key_call_*`, `key_slot_*`, `key_nop`, `key_task_init`, the CONTOUR / APF reset keys; the frame-0x50 keyboard builders `dl50_*`, `kbd_fmt_char_pos`, `kbd_copy_text` (UI track) |
| `include/ui.h` | the image's functions the UI-track files call (kept apart from main.h) |
| `include/main.h`, `include/main_ram.h`, `include/r_cg_sci.h`, `include/cat_cmds.h` | the image's functions the recreated code calls, its RAM variables, the SCI prototypes, the CAT handler prototypes |
| `data_symbols.tsv` | RAM variables used by the recreated code → original address, with evidence |
| `aliases.tsv` | recreated functions whose name is not the Ghidra name (none yet) |

The register macros (`SCI0_SCR`, `ICU_GENBL0`, ...) are generated at build time into `out/include/iodefine.h` from
`tools/ghidra/sfr_rx651.tsv` by `tools/main_iodefine.py`, so the source uses the names decomp/main uses. The typed state blocks
(`g_ui`, `g_opstate`, `g_cfg105`, `memch`, ...) come the same way from `tools/ghidra/structs_main.h` (T23c) into
`out/include/ft710_state.h` (`tools/main_structs.py`): packed structs with filler arrays and an offset assert per
field, with the enums of `tools/ghidra/enums_main.h`; `equiv_main_emu.py` places those globals at their addresses.

## Build and check

```sh
make -C src/main CROSS=$HOME/opt/rx-gcc-13.3.0/bin/rx-elf-          # objects in src/main/out/obj (ignored)
python3 -I tools/equiv_main_emu.py check eeprom_write R_SCI0_Serial_Send   # one or more functions
python3 -I tools/equiv_main_emu.py check --object drivers/eeprom.o         # all functions of an object
python3 -I tools/equiv_main_emu.py status                                  # everything -> status.tsv
python3 -I tools/equiv_main_emu.py status --object app/cat_vfo.o           # rerun these, keep the other rows
python3 -I tools/readability_stats.py readme                               # the README progress block
```

The check needs the decoded image (`build/FT-710_MAIN_V0112.bin`, or `FT710_BUILD=<dir>`), a copy of the MAIN Ghidra
project (`FT710_MAIN_PROJECT=<dir>`, default `/home/user/ghidra_tasks/t24main/proj`; each worker copies it again and
opens it read-only), the rx62t module installed in Ghidra (docs/tooling.md) and `rx-elf-ld` (`RX_BINUTILS=<prefix>`).
`status` with 200 trials takes about an hour and a half with 2 workers for the current functions (round 4). Every
temporary file of a run (link scripts, the workers' project copies, Ghidra logs) is under one `equiv_main_run_*`
directory (`EQUIV_MAIN_SCRATCH`, default the system temp directory) that the run removes when it ends, also on
SIGTERM/SIGINT; a directory left by a run killed with SIGKILL is removed by the next run. FTOI, ROUND and FTOU are
executed by `EquivMainEmu.java` after the RXv2 manual (the module computed a float for all three;
`tools/rx_fpconv_check.py`); since round 5 every FPU instruction is (`RxFpu`: DN flush, NaN rules, FCMP's O flag, RM, FPSW; `tools/rx_fpu_check.py`). Round 5 also needs `tools/ghidra/rx62t-minmax-fix.patch` for GCC's `MIN` (the module computed an unsigned minimum for MIN and MAX); `bootstrap.sh --only rx` installs it, or `GHIDRA_HEADLESS` points at a Ghidra with it. An endless function is checked for one pass (`FUNC_STOP`: the run ends at the n-th call of a stubbed callee). It needs the RX module with `tools/ghidra/rx62t-gccforms-fix.patch` (`tools/bootstrap.sh --only rx`; or `GHIDRA_HEADLESS` pointing at a Ghidra that has it): GCC's `REVL Rd,Rd` (`eeprom_hdr_update`) needs the fix. `eeprom_read`/`eeprom_write` are stubs in the checks of their callers (`STUBS`).

## Writing a function

1. Read the disassembly (`rx-elf-objdump -D -b binary -m rx --adjust-vma=0xFFF80000 --start-address=... build/...`)
   and decomp/main; the access order and widths of peripheral registers are compared, so keep them (a 32-bit
   read-modify-write stays one, `bset` on a byte stays a byte operation).
2. Call the image's other functions by their Ghidra name (declare them in `include/main.h`); use its RAM through a
   name in `data_symbols.tsv`. Recreated code must not have `.data` or `.bss` of its own.
3. Build, run `check`; for a difference, `tools/equiv_main_emu.py`'s `run(..., trace=True)` gives the PC and
   registers of the first 400 instructions of both runs. Where random inputs do not reach the interesting cases,
   add a preset to `PRESETS` (a mutation test of the round showed which ones were needed). A task whose gates are
   functions of the whole radio state can stub them with chosen return values (`FUNC_STUBS`), and a function with
   many cases can get more trials (`FUNC_TRIALS`); a preset can enumerate cases by trial number (`_TRIAL`).
4. An image callee that uses all of a register its caller fills from a byte (signature `uint`, e.g.
   `bcd_to_ascii2`) is declared with `uint32_t`: GCC passes a `uint8_t` argument loaded with the sign-extending
   `MOV.B` (round 4, `cat_DT`).
