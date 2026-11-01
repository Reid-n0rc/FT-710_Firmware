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
| `app/sdr_link.c` | the SCI5 glue (`sdr_link_start`, `sdr_rx_*`, `sdr_send_cmd`), `sdr_send_frame`, `sdr_poll_reply`, `sdr_sum8`, `sdr_check_hex_sum` and the constant / one-setting register updaters (round 2); `sdr_upd_r18_rx_freq`, `sdr_upd_r1d_notch`, `sdr_upd_r1e_passband` (one passband-centre helper) and `sdr_shadow_update` (round 3) |
| `app/cat_link.c` | the CAT ring, ports and busy flags (`cat_ring_*`, `cat_send_reply`, `cat_tx_done_sci0/2/3`, `cat_tx_busy`), `sum8`, `cat_checksum_ok`, `cat_reply_error`, `cat_ID`, `cat_QI/QR/QS/EN/FS`, `cat_ai_holdoff`, `cat_rand8` (round 2) |
| `app/display_link.c` | the SCI1 glue, ACK/NAK, `displink_tx_start`/`_resend`/`_put_sum`, `displink_copy_if_changed`, `mem_zero` and the send-if-changed frame senders 0x20, 0x24, 0x37, 0x39, 0x41, 0x50, 0x62, 0x70, plus 0x23 and the 0x60 hello (round 2) |
| `app/trx_lines.c` | the TX/RX sequencer's lines: `tx_line_get`, `rx_line_get`, `send_a_get`, `send_a_set`/`send_b_set` (gated by ETUN_TXINH_REQ and TX), `ptt_source_get` (round 2); `trx_sequencer`, the RX->TX / TX->RX state machine (round 3) |
| `app/cat_parse.c` | `cat_parse` (ring and E9 slot, mnemonic lookup, power-off gate, reply), `cat_dispatch` with one case per `enum cat_cmd` index (echo, length test, handler; decomp/main/cat_dispatch.tsv), `cat_dispatch_ext`, `cat_ext_SP` (round 3) |
| `app/cat_handlers.c` | the CAT read/set handlers AG AI AO AV BA BC BI CS CT DN EX FN GP KP KR KS LK MA MB MS MX NB NL NR PA PL PR PS RA RG RL SC SD SM ST TX UP VD VG VX ZI (round 3) |
| `app/tuner.c`, `app/keyer.c` | `tuner_task` (dispatch by TUNER SELECT), `tuner_init`, `atu_ac_get`/`atu_tc_get`; `keyer_init`, `keyer_state_clear`, `keyer_ring_next`, `keyer_sidetone_off` (round 2) |
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
python3 -I tools/readability_stats.py readme                               # the README progress block
```

The check needs the decoded image (`build/FT-710_MAIN_V0112.bin`, or `FT710_BUILD=<dir>`), a copy of the MAIN Ghidra
project (`FT710_MAIN_PROJECT=<dir>`, default `/home/user/ghidra_tasks/t24main/proj`; each worker copies it again and
opens it read-only), the rx62t module installed in Ghidra (docs/tooling.md) and `rx-elf-ld` (`RX_BINUTILS=<prefix>`).
`status` with 200 trials and 3 workers takes about 45 minutes for the current functions. It needs the RX module with `tools/ghidra/rx62t-gccforms-fix.patch` (`tools/bootstrap.sh --only rx`; or `GHIDRA_HEADLESS` pointing at a Ghidra that has it): GCC's `REVL Rd,Rd` (`eeprom_hdr_update`) needs the fix. `eeprom_read`/`eeprom_write` are stubs in the checks of their callers (`STUBS`).

## Writing a function

1. Read the disassembly (`rx-elf-objdump -D -b binary -m rx --adjust-vma=0xFFF80000 --start-address=... build/...`)
   and decomp/main; the access order and widths of peripheral registers are compared, so keep them (a 32-bit
   read-modify-write stays one, `bset` on a byte stays a byte operation).
2. Call the image's other functions by their Ghidra name (declare them in `include/main.h`); use its RAM through a
   name in `data_symbols.tsv`. Recreated code must not have `.data` or `.bss` of its own.
3. Build, run `check`; for a difference, `tools/equiv_main_emu.py`'s `run(..., trace=True)` gives the PC and
   registers of the first 400 instructions of both runs. Where random inputs do not reach the interesting cases,
   add a preset to `PRESETS` (a mutation test of the round showed which ones were needed).
