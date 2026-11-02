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
| `scope_spi.v` | `ft710_scope_spi`: **scope frame serializer** (#186), master of the DISPLAY's RSPI2 link on N14 (data) / T18 (select) / R18 (clock): 1,700-byte frame every 614,400 `dsp_clk` cycles, 32 clocks per bit, bytes 0-849 from the ping-pong RAM RAMB18_X2Y21, bytes 850-1699 = 0xCC, address test pattern | **matches the netlist slice cycle by cycle** (`tb_scope_spi.v -DSTRUCT`, 5 frames, 0 mismatching clocks) |
| `adc_dc.v` | `ft710_adc_dc`: **ADC capture and DC removal** of one channel (netlist.md 3.7): SRL + flip-flop + x register (4 clocks), `acc += x*2^9 - dc` (44 bit), `dc = acc[43:20]`, `y = x*2^9 - en*dc` | **matches the netlist slices of both channels cycle by cycle** (`tb_adc_dc.v -DSTRUCT`, `-DCHB`: 4,000,000 clocks each, 0 mismatching clocks) |
| `adc_gain.v` | `ft710_adc_gain`: **per-channel gain** (DSP48 `y * g`, g = reg 0x12/0x13, 0x8000 = unity), rounding at bit 15 half away from zero, symmetric clamp to +/-(2^23 - 1), 8-bit override field (word = v * 2^16 while v != 0) | **matches the netlist slices of both channels cycle by cycle** (`tb_adc_gain.v -DSTRUCT`, `-DCHB`: 2,000,000 clocks each, 0 mismatching clocks) |
| `adc_combine.v` | `ft710_adc_combine`: **A + B combine at 5 MSPS**: operand registers (strobe, reset), the two 32-bit adders, the output mux under reg 0x04 bits 11/10 (A + B, A * 8, B) and the level flag u (set when l[16:1] > thr, cleared when l[15:0] < thr) | **matches the netlist slice cycle by cycle** (`tb_adc_combine.v -DSTRUCT`: 2,000,000 clocks, 0 mismatching clocks) |
| `regfile.v` | `ft710_regfile`: **write side of the register file** (T24 round 2; netlist.md 5.2): 42 registers (0x03..0x37) at the addresses, bit masks and reset values found in the netlist, written from the shared bus (16-bit address, 16-bit data, one-clock strobe), global synchronous reset (0x27 has none) | **matches the netlist slice cycle by cycle** (`tb_regfile.v -DSTRUCT`: 2,000,000 clocks, 598 flip-flops, 0 mismatching clocks) **and the whole netlist** (`tb_regfile.v -DTRACE` on UART B runs, below) |
| `scope_wr_data.v` | `ft710_scope_wr_data`: **data path of the scope RAM writer** (netlist.md 5.6): sample + reg 0x26 copy, reference reg 0x27[7:0] minus half of it, scale bit 0x27[15], sign clamp, rounding, byte clamp to 0xFE; the byte written into RAMB18_X2Y21 port A | **matches the netlist slice cycle by cycle** (`tb_scope_wr_data.v -DSTRUCT`: 1,000,000 clocks, 0 mismatching clocks) |
| `tb_regfile.v`, `tb_regfile_ports.vh`, `tb_regfile_map.vh` | register-file testbench (slice and whole-netlist trace); the two lists name the slice ports and the 598 flip-flops (generated in round 2, cell names only) | PASS |
| `tb_scope_wr_data.v` | writer data path testbench (integer reference; with `-DSTRUCT` against the slice) | PASS |
| `sim/regmap_main.cpp` | Register-map harness for the whole netlist (T24 round 2): MAIN frames on UART B, logs every change of a probed net (write enables, register flip-flops, bus flip-flops) that is quiet before the first frame | gave the write-enable pulses per frame and the traces for `tb_regfile.v -DTRACE` |
| `tb_adc_dc.v`, `tb_adc_gain.v`, `tb_adc_combine.v` | testbenches for the three: RTL alone (behaviour and a reference model) and with `-DSTRUCT` against the slices | PASS (Icarus) |
| `tb_scope_spi.v` | serializer testbench: RAM model, frame decoder (length, period, bank, contents, test mode, disable), with `-DSTRUCT` against the slice | PASS (Icarus, 35 s) |
| `sim/scope_main.cpp` | Whole-netlist harness for the scope port (#186): holds R15 high (pins driven), copies the three output flops onto their pads, decodes frames, prints the enable/mode flops. Needs a probed netlist (command in the file) | |
| `sim/scope_wr_main.cpp` | Whole-netlist harness for the scope RAM writer (#186): logs port-A writes of RAMB18_X2Y21 (index runs, bank contents) next to the decoded frames. Needs a probed netlist (command in the file) | showed the centre-out sweep (852 writes per frame, indexes 425 ∓ k), that the sent bytes equal the written ones, and that reg 0x27 shifts all 850 bytes alike |
| `tb_uart_console.v` | console testbench: plays a line file, prints the TX bytes, small register model | used by `tools/sdr_console_check.py` |
| `uart_charclass.v` | `ft710_uart_charclass`: character classes of the parsers (hex digits, `r`/`w`/`x`, `,`/space, CR/LF/BS) | sets taken from the netlist LUTs |
| `tb_uart_rx.v` | RX testbench: MAIN-style frames, edge bytes, +/-2 % baud error; with `-DSTRUCT` also against the netlist slice | PASS, 0 mismatches in 260,417 clocks |
| `tb_uart_tx.v` | TX looped back into RX | PASS |
| `tb_uart_link.v` | link on its own with a register model: boot read of reg 0 (`r010437`), write + read-back, bad/lower-case checksum, junk prefix, empty line | PASS (Icarus, 7 s) |
| `sim/xc7_prims_vl.v` | Verilator models of LUT6/LUT6_2/CARRY4/FD*/SRLC32E/RAMD*/BUF*/IO/IDDR/ODDR/MMCM for the recovered netlist | |
| `sim/xc7_bram_vl.v` | Behavioural RAMB18E1 / RAMB36E1 (UG473 widths, INIT layout, byte enables, write modes, output register, inverted pins) (#164). Before #164 the Yosys declarations were used and every block RAM read 0 | `sim/tb_bram.v`: PASS |
| `sim/tb_bram.v` | BRAM model test: RAMB36 x9 against two RAMB18 x4 halves with interleaved INIT (data + parity), x9 writes, x18 byte enables, SDP x36 | PASS (Icarus) |
| `sim/full_main.cpp`, `sim/build_full.sh` | Verilator harness and build for the **whole** netlist (UART players/decoders, probe and snapshot output) | 63k cells, ~15,000 clocks/s |
| `sim/pins_main.cpp` | Pin-activity harness for the whole netlist (#90): toggle counts, burst gaps and optional edge logs of the unassigned outputs, with MAIN register frames played on UART B. Build with `MAIN=pins_main.cpp OBJ=obj_pins hdl/sdr/sim/build_full.sh` | found the I2S port and the two power-up SPI transfers; `CONSOLE=`/`INPUTS=` (#89) showed `#` = hex E, BS = hex B on the console and that no input gates `x`; `ADC=noise` / `ADC=sine:PERIOD` drive the 14 ADC pairs (#91) |
| `sim/adc_main.cpp` | Two-channel ADC harness (#172): drives channel A and B with the traced bit map (needs `-DIDDR_DDR`, the DDR IDDR stand-in in `xc7_prims_vl.v`), MAIN frames on UART B, probe snapshots | confirmed the 14-bit two's-complement words, the DC tracker and the gain registers 0x12/0x13 |
| `sim/ddc_main.cpp` | RX IF stream harness (#193): ADC tone (`ADC=tone:F:AMP`, #172 bit map), MAIN frames on UART B, M17/V16 half-frame words (`H` lines), probe dumps (`DUMP=`, `DUMPBITS=`), toggle counts (`PROBE_COUNT=1`), per-probe change hashes (`PROBE_HASH=1`), per-channel inputs (`ADC1=off`, `ADC2=off|tone:...`), 32-bit probe ports for wide probe sets (`PROBE_PORTS=1`). Build with `MAIN=ddc_main.cpp VDEFS="+define+MMCM_FRAC +define+IDDR_DDR"`; `MMCM_FRAC` (in `xc7_prims_vl.v`) makes the bottom MMCM give `DSP_CLK` = 18.432 MHz instead of passing 125 MHz through | found the RX LO = reg 0x18/0x19, the 72.000 kHz FIFO in front of M17, and that reg 0x0A leaves the RX words unchanged (netlist.md 3.8); the A + B channel combine and its reg 0x04 bits (3.7, #172) |
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

Scope serializer (#186), RTL alone and against its netlist slice:

```sh
iverilog -g2012 -o /tmp/sc.vvp hdl/sdr/tb_scope_spi.v hdl/sdr/scope_spi.v && vvp -n /tmp/sc.vvp
python3 -I tools/xc7_netlist_verilog.py slice build/sdr/netlist.json build/sdr/sim/scope_ser.v \
  --seeds SLICE_X12Y48/AFF,SLICE_X5Y50/AFF,SLICE_X12Y49/AFF,SLICE_X15Y49/AFF,SLICE_X58Y49/AFF,SLICE_X58Y49/BFF,SLICE_X58Y49/B5FF,SLICE_X58Y49/CFF,SLICE_X58Y49/A5FF,SLICE_X58Y50/CFF,SLICE_X58Y50/AFF,SLICE_X58Y50/A5FF,SLICE_X58Y50/BFF,SLICE_X34Y53/AFF \
  --depth 12 --stop RAMB18_X2Y21,SLICE_X28Y73/A5FF,SLICE_X40Y60/BFF,SLICE_X1Y47/AFF
iverilog -g2012 -DSTRUCT -o /tmp/scs.vvp hdl/sdr/tb_scope_spi.v hdl/sdr/scope_spi.v build/sdr/sim/scope_ser.v \
  /usr/share/yosys/xilinx/cells_sim.v && vvp -n /tmp/scs.vvp
```

RX front end (T24): DC removal, gain and the A + B combine against their netlist slices. The slices are the exact
cell sets that `tools/sdr_progress.py` counts for the blocks `adc_dc_a`, `adc_dc_b`, `adc_gain_a`, `adc_gain_b`,
`adc_combine_mux` (rows in `tools/sdr_blocks.tsv`: seeds, `slice:N` depth and stop list), written by `--slice`. The
gain slices need a DSP48E1 model with the pin inverters applied (as `hdl/sdr/sim/build_full.sh` does for Verilator):

```sh
for b in adc_dc_a adc_dc_b adc_gain_a adc_gain_b adc_combine_mux; do
  python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice $b build/sdr/sim/$b.v; done
sed -e 's/\$fatal[^;]*;/;/g' -e 's/INMODEr <= INMODE;/INMODEr <= INMODE ^ IS_INMODE_INVERTED;/' \
  -e 's/OPMODEr <= OPMODE;/OPMODEr <= OPMODE ^ IS_OPMODE_INVERTED;/' -e 's/ALUMODEr <= ALUMODE;/ALUMODEr <= ALUMODE ^ IS_ALUMODE_INVERTED;/' \
  -e 's/CARRYINr <= CARRYIN;/CARRYINr <= CARRYIN ^ IS_CARRYIN_INVERTED;/' -e 's/CARRYINr = CARRYIN;/CARRYINr = CARRYIN ^ IS_CARRYIN_INVERTED;/' \
  /usr/share/yosys/xilinx/cells_sim.v > build/sdr/sim/cells_sim_dsp.v
iverilog -g2012 -o /tmp/dc.vvp hdl/sdr/tb_adc_dc.v hdl/sdr/adc_dc.v && vvp -n /tmp/dc.vvp           # RTL alone
iverilog -g2012 -DSTRUCT -DCYCLES=4000000 -o /tmp/dca.vvp hdl/sdr/tb_adc_dc.v hdl/sdr/adc_dc.v \
  build/sdr/sim/adc_dc_a.v /usr/share/yosys/xilinx/cells_sim.v && vvp -n /tmp/dca.vvp           # -DCHB with adc_dc_b.v
iverilog -g2012 -DCYCLES=200000 -o /tmp/g.vvp hdl/sdr/tb_adc_gain.v hdl/sdr/adc_gain.v && vvp -n /tmp/g.vvp
iverilog -g2012 -DSTRUCT -DCYCLES=2000000 -o /tmp/ga.vvp hdl/sdr/tb_adc_gain.v hdl/sdr/adc_gain.v \
  build/sdr/sim/adc_gain_a.v build/sdr/sim/cells_sim_dsp.v && vvp -n /tmp/ga.vvp               # -DCHB with adc_gain_b.v
iverilog -g2012 -DCYCLES=200000 -o /tmp/c.vvp hdl/sdr/tb_adc_combine.v hdl/sdr/adc_combine.v && vvp -n /tmp/c.vvp
iverilog -g2012 -DSTRUCT -DCYCLES=2000000 -o /tmp/cs.vvp hdl/sdr/tb_adc_combine.v hdl/sdr/adc_combine.v \
  build/sdr/sim/adc_combine_mux.v /usr/share/yosys/xilinx/cells_sim.v && vvp -n /tmp/cs.vvp
```

The testbenches drive every slice input that the compared outputs should not depend on (the other half of a shared
LUT6_2, which belongs to other logic) with random bits, so a dependence the RTL lacks shows as a mismatch; the unused
DSP cascade inputs (ACIN/BCIN/PCIN from the DSP below) are left open. Speed: about 18,000 clocks/s (DC slice) in
Icarus 11.

Register file and scope writer data path (T24 round 2). The slices are the `regfile` and `scope_wr_data` rows of
`tools/sdr_blocks.tsv` (the `regfile` seeds use the `ffs-fed:` generator of `tools/sdr_progress.py`):

```sh
python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice regfile build/sdr/sim/regfile.v
iverilog -g2012 -DSTRUCT -DCYCLES=2000000 -I hdl/sdr -o /tmp/rf.vvp hdl/sdr/tb_regfile.v hdl/sdr/regfile.v \
  build/sdr/sim/regfile.v /usr/share/yosys/xilinx/cells_sim.v && vvp -n /tmp/rf.vvp
python3 -I tools/sdr_progress.py build/sdr/netlist.json --slice scope_wr_data build/sdr/sim/scope_wr_data.v
iverilog -g2012 -DSTRUCT -DCYCLES=1000000 -o /tmp/sw.vvp hdl/sdr/tb_scope_wr_data.v hdl/sdr/scope_wr_data.v \
  build/sdr/sim/scope_wr_data.v /usr/share/yosys/xilinx/cells_sim.v && vvp -n /tmp/sw.vvp
```

Whole-netlist register runs: probe the bus flip-flops, the register-file candidates and their enables (1,478 probes,
47 words; the list is every flip-flop whose D or CE fan-in reaches a bus flip-flop, plus those flip-flops' CE drivers),
build with `regmap_main.cpp`, play frames, and replay the log against the RTL:

```sh
python3 -I tools/xc7_probe_netlist.py --ports build/sdr/vl/OBJ/probe_ports.h --declared build/sdr/netlist.json \
  build/sdr/ft710_sdr.v build/sdr/vl/rm.v build/sdr/vl/rm.names @PROBES
NET=$PWD/build/sdr/vl/rm.v OBJ=OBJ PROBE_W=47 PROBE_PORTS=1 MAIN=regmap_main.cpp hdl/sdr/sim/build_full.sh
build/sdr/vl/OBJ/Vft710_sdr 6000000 w00115F55 w000818F1 ... > rm.log       # frames without checksum
python3 -I tools/sdr_regfile_trace.py enables build/sdr/vl/rm.names rm.log   # enables pulsed per frame
python3 -I tools/sdr_regfile_trace.py trace build/sdr/vl/rm.names rm.log hdl/sdr/tb_regfile_map.vh rm.tr
iverilog -g2012 -DTRACE='"rm.tr"' -I hdl/sdr -o /tmp/rft.vvp hdl/sdr/tb_regfile.v hdl/sdr/regfile.v && vvp -n /tmp/rft.vvp
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
