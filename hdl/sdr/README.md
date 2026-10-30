# hdl/sdr — reconstructed HDL for the FT-710 SDR FPGA (T15e)

Hand-written Verilog that re-implements interfaces of the FT-710 SDR module's XC7A50T design, the owner's own
reconstruction from the netlist recovered in T15 ([docs/code/sdr/netlist.md](../../docs/code/sdr/netlist.md)). It
contains no bitstream data. The recovered structural netlist and everything built from it are derived data and stay
in `build/` (never committed).

| File | What | Status |
|---|---|---|
| `uart_rx.v` | `ft710_uart_rx`: 115,200 baud 8N1 receiver at 125 MHz (bit timer 1,086, sample at 542, 10-stage shift register, byte + strobe) | **matches the netlist cycle by cycle** (`tb_uart_rx.v -DSTRUCT`) |
| `uart_link.v` | `ft710_uart_link`: **MAIN's register link** (UART B, V12 in / U12 out = MAIN's SCI5): 11-character window, `r`/`w` frames with checksum, read reply / ACK / `?`, register-bus port | **matches the whole netlist cycle by cycle on the TX pin** (co-simulation, below) |
| `uart_tx.v` | `ft710_uart_tx`: generic transmitter with the console's bit timer (shift strobe at count 32) | loopback only; the link has its own transmitter in `uart_link.v` |
| `uart_console.v`, `uart_console_echo.vh` | `ft710_uart_console`: **UART A debug console** (prompt `[IF]>`, echo, 15-character line buffer with BS, CR matcher: `r`/`w`, `E`/`D` listings, `#` quiet mode, `Err`), byte-level (#147, #204) | **same bytes as the whole netlist** for `sim/console_lines.txt` (`tools/sdr_console_check.py`); not cycle-accurate; the garbage burst of a BS typed during an echo is not modelled |
| `tb_uart_console.v` | console testbench: plays a line file, prints the TX bytes, small register model | used by `tools/sdr_console_check.py` |
| `uart_charclass.v` | `ft710_uart_charclass`: character classes of the parsers (hex digits, `r`/`w`/`x`, `,`/space, CR/LF/BS) | sets taken from the netlist LUTs |
| `tb_uart_rx.v` | RX testbench: MAIN-style frames, edge bytes, +/-2 % baud error; with `-DSTRUCT` also against the netlist slice | PASS, 0 mismatches in 260,417 clocks |
| `tb_uart_tx.v` | TX looped back into RX | PASS |
| `tb_uart_link.v` | link on its own with a register model: boot read of reg 0 (`r010437`), write + read-back, bad/lower-case checksum, junk prefix, empty line | PASS (Icarus, 7 s) |
| `sim/xc7_prims_vl.v` | Verilator models of LUT6/LUT6_2/CARRY4/FD*/SRLC32E/RAMD*/BUF*/IO/IDDR/ODDR/MMCM for the recovered netlist | |
| `sim/xc7_bram_vl.v` | Behavioural RAMB18E1 / RAMB36E1 (UG473 widths, INIT layout, byte enables, write modes, output register, inverted pins) (#164). Before #164 the Yosys declarations were used and every block RAM read 0 | `sim/tb_bram.v`: PASS |
| `sim/tb_bram.v` | BRAM model test: RAMB36 x9 against two RAMB18 x4 halves with interleaved INIT (data + parity), x9 writes, x18 byte enables, SDP x36 | PASS (Icarus) |
| `sim/full_main.cpp`, `sim/build_full.sh` | Verilator harness and build for the **whole** netlist (UART players/decoders, probe and snapshot output) | 63k cells, ~15,000 clocks/s |
| `sim/pins_main.cpp` | Pin-activity harness for the whole netlist (#90): toggle counts, burst gaps and optional edge logs of the unassigned outputs, with MAIN register frames played on UART B. Build with `MAIN=pins_main.cpp OBJ=obj_pins hdl/sdr/sim/build_full.sh` | found the I2S port and the two power-up SPI transfers; `CONSOLE=`/`INPUTS=` (#89) showed that no input gates `x` (its "BS = hex B" is superseded: BS edits the line, #204); `ADC=noise` / `ADC=sine:PERIOD` drive the 14 ADC pairs (#91) |
| `sim/cosim_top.v`, `sim/cosim_directed.sh`, `sim/cosim_random.sh` | netlist and `ft710_uart_link` side by side, TX compared every clock | see results |

## The link protocol (UART B, MAIN's UART5) [fact, whole-netlist simulation]

| Line before CR (last characters of the 11-character window) | Reply |
|---|---|
| `r` + 4 hex address + 2 hex sum | `r` + 4 hex value + 2 hex sum (7 bytes, no CR); e.g. `r000032` -> `r010437` (register 0 = 0x0104 = V01-04) |
| `w` + 4 hex address + 4 hex value + 2 hex sum | ACK `0x06` (1 byte) |
| anything else | `?` (0x3F) |

- The sum is the 8-bit sum of the characters before it. The FPGA compares the two sum characters with its own
  upper-case rendering: address/value digits may be lower case, sum digits may not.
- Only the last 7 (read) or 11 (write) characters count: junk, LF or extra letters in front are ignored. CR neither
  enters nor clears the window, so **an empty line repeats the previous command**. LF and BS have no function here.
- `x` is not a command on this link: every `x` frame shape tried (0-10 hex digits, with and without sum, after the
  `0x37 = 0xBCC5` unlock) answers `?`.
- Timing after the receiver's CR strobe: read-data latch +37 clocks, first start bit +74 (read), +69 (ACK), +37
  (`?`, line not frame-shaped), +45/+47 (read-shaped, first/second sum digit wrong), +49/+51 (write-shaped). Reply bytes
  are start + 8 data + 2 stop bits plus 3 clocks (11,949 clocks).

The debug console on UART A (M18/L18) is described in netlist.md section 5.3; its byte-level RTL is `uart_console.v` (#147).

## Running the tests

Icarus Verilog 11, Yosys 0.23 and Verilator 5.006 (Debian packages, see the T15/T15e task files). Behavioural only:

```sh
iverilog -g2012 -o /tmp/rx.vvp hdl/sdr/tb_uart_rx.v hdl/sdr/uart_rx.v && vvp -n /tmp/rx.vvp
iverilog -g2012 -o /tmp/tx.vvp hdl/sdr/tb_uart_tx.v hdl/sdr/uart_tx.v hdl/sdr/uart_rx.v && vvp -n /tmp/tx.vvp
iverilog -g2012 -o /tmp/l.vvp hdl/sdr/tb_uart_link.v hdl/sdr/uart_link.v hdl/sdr/uart_rx.v && vvp -n /tmp/l.vvp
```

Receiver against its netlist slice (needs `build/sdr/netlist.json` from T15b):

```sh
python3 -I tools/xc7_netlist_verilog.py slice build/sdr/netlist.json build/sdr/sim/uart_a_rx.v \
  --seeds SLICE_X1Y92/AFF,SLICE_X1Y93/AFF,SLICE_X1Y93/B5FF,SLICE_X1Y93/BFF,SLICE_X1Y93/CFF,SLICE_X1Y93/DFF,SLICE_X2Y93/AFF,SLICE_X2Y93/BFF,SLICE_X2Y93/CFF \
  --depth 4
iverilog -g2012 -DSTRUCT -o /tmp/rxc.vvp hdl/sdr/tb_uart_rx.v hdl/sdr/uart_rx.v build/sdr/sim/uart_a_rx.v \
  /usr/share/yosys/xilinx/cells_sim.v && vvp -n /tmp/rxc.vvp
```

Block-RAM model (#164):

```sh
iverilog -g2012 -o /tmp/tbb.vvp hdl/sdr/sim/tb_bram.v hdl/sdr/sim/xc7_bram_vl.v && vvp -n /tmp/tbb.vvp
```

Whole netlist in Verilator (needs `build/sdr/ft710_sdr.v` from T15d; ~2.5 min build with `-j 16`; `BRAM=yosys` with a
`--ramb18` netlist rebuilds the pre-#164 model whose block RAMs read 0):

```sh
hdl/sdr/sim/build_full.sh                                   # -> build/sdr/vl/obj_full/Vft710_sdr
python3 -I tools/sdr_uart_sim.py b:r0000 b:w00151234 b:r0015 "a:=r 0000\r"   # MAIN frames on B, console on A
```

Link RTL against the whole netlist (the netlist's read-data bus feeds the RTL, so the reply values agree):

```sh
python3 -I tools/xc7_probe_netlist.py build/sdr/netlist.json build/sdr/ft710_sdr.v build/sdr/vl/ft710_rd.v \
  build/sdr/vl/rd.names SLICE_X9Y67/AFF SLICE_X13Y64/AFF SLICE_X11Y66/AFF SLICE_X12Y68/CFF SLICE_X10Y67/AFF \
  SLICE_X12Y68/AFF SLICE_X10Y67/BFF SLICE_X11Y65/CFF SLICE_X14Y66/CFF SLICE_X10Y66/BFF SLICE_X10Y66/AFF \
  SLICE_X14Y66/BFF SLICE_X14Y66/DFF SLICE_X12Y68/BFF SLICE_X14Y70/AFF SLICE_X15Y106/CLUT SLICE_X7Y101/BLUT
TOP=cosim_top NET=build/sdr/vl/ft710_rd.v OBJ=obj_cosim PROBE_W=1 hdl/sdr/sim/build_full.sh
hdl/sdr/sim/cosim_directed.sh build/sdr/vl/cosim_dir          # 4 runs, 24 directed lines
hdl/sdr/sim/cosim_random.sh build/sdr/vl/cosim 300 18 12      # 18 parallel runs x 12 random lines
```

The probe order above is the one `cosim_top.v` expects (its `rdata` assignment maps them to bits 15..0).

**Results [fact].** Directed: 4/4 runs pass (MAIN's boot reads, the `0x37` unlock, writes and read-back, every NAK
latency class, junk, LF, empty line). Random (reads, writes, corrupted sums, lower-case sums, wrong lengths, junk
prefixes, lines split by idle gaps): see the T15e task file for the run counts; all runs since the empty-line rule
pass with **0 mismatching clocks** on the TX pin. What is not compared: the RTL's bus strobes (the netlist's
write path is spread over the shared register bank; writes are checked through read-back), and a CR that arrives
while a reply is still being sent (the netlist restarts the reply; not exercised).

Slice and probe ports are named after their driving cell pin (`i_IOB_X0Y41_I`, `w_SLICE_X10Y76_BFF_Q`), so the
scripts do not depend on the net numbering of a particular netlist build.
