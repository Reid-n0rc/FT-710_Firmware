#!/bin/sh
# Build the whole recovered FT-710 SDR netlist with Verilator (T15e).
# Needs build/sdr/ft710_sdr.v (tools/xc7_netlist_verilog.py verilog) and Yosys' cells_sim.v (for DSP48E1).
# Block RAMs (RAMB18E1/RAMB36E1) come from hdl/sdr/sim/xc7_bram_vl.v (#164; Yosys' models have no behaviour).
# Output: build/sdr/vl/obj_full/Vft710_sdr (derived; never commit). Usage: hdl/sdr/sim/build_full.sh [REPO]
# Env: NET=<netlist .v> (default build/sdr/ft710_sdr.v), OBJ=<obj dir name>, PROBE_W=<words> for a probed netlist,
#      JOBS=<parallel compile jobs> (default 16; tools/bootstrap.sh passes nproc),
#      TOP=cosim_top for the netlist + RTL co-simulation (adds hdl/sdr/sim/cosim_top.v and the RTL files),
#      MAIN=pins_main.cpp for the pin-activity harness (#90),
#      BRAM=yosys to use Yosys' RAMB18E1 declaration instead (no behaviour: every BRAM output reads 0; the pre-#164
#      models, for comparing old runs; only works with a netlist written with --ramb18).
set -e
REPO=${1:-$(cd "$(dirname "$0")/../../.." && pwd)}
BUILD=${BUILD:-$REPO/build/sdr}
[ -f "$BUILD/ft710_sdr.v" ] || BUILD=/workspace/FT-710_Firmware/build/sdr
HERE=$(cd "$(dirname "$0")" && pwd)
mkdir -p "$BUILD/vl"
cd "$BUILD/vl"
# DSP48E1 (and RAMB18E1's port list for BRAM=yosys) from Yosys, without the $fatal mode checks (they fire on constant-tied mode pins).
# Yosys' model declares IS_{INMODE,OPMODE,ALUMODE,CARRYIN}_INVERTED but ignores them, so the netlist's pin inverters (#91)
# had no effect and every DSP computed Z - (A:B + C + 1) instead of A*B (#172); apply them where the mode pins enter.
python3 -I - /usr/share/yosys/xilinx/cells_sim.v <<'EOF'
import re, sys
s = re.sub(r'\$fatal[^;]*;', ';', open(sys.argv[1]).read())
for a, b in (('INMODEr <= INMODE;', 'INMODEr <= INMODE ^ IS_INMODE_INVERTED;'),
             ('OPMODEr <= OPMODE;', 'OPMODEr <= OPMODE ^ IS_OPMODE_INVERTED;'),
             ('ALUMODEr <= ALUMODE;', 'ALUMODEr <= ALUMODE ^ IS_ALUMODE_INVERTED;'),
             ('CARRYINr <= CARRYIN;', 'CARRYINr <= CARRYIN ^ IS_CARRYIN_INVERTED;'),
             ('CARRYINr = CARRYIN;', 'CARRYINr = CARRYIN ^ IS_CARRYIN_INVERTED;')):
    assert a in s, a
    s = s.replace(a, b)
for m in ('DSP48E1', 'RAMB18E1'):
    i = s.index('module ' + m + ' ')
    open('y_' + m + '.v', 'w').write(s[i:s.index('endmodule', i) + 9] + '\n')
EOF
NET=${NET:-$BUILD/ft710_sdr.v}
BRAMV="$HERE/xc7_bram_vl.v"
[ "$BRAM" = yosys ] && BRAMV=y_RAMB18E1.v
OBJ=${OBJ:-obj_full}
TOP=${TOP:-ft710_sdr}
EXTRA=""
[ "$TOP" = cosim_top ] && EXTRA="$HERE/cosim_top.v $HERE/../uart_link.v $HERE/../uart_rx.v"
XC=""
[ -n "$PROBE_W" ] && XC="-DPROBE_W=$PROBE_W"
timeout 3000 verilator --cc --exe --build -j "${JOBS:-16}" -O3 --x-assign fast --x-initial fast \
  -Wno-fatal -Wno-lint -Wno-style --top-module "$TOP" --prefix Vft710_sdr \
  --output-split 30000 --output-split-cfuncs 3000 -CFLAGS "-O1 -fno-var-tracking $XC" -Mdir "$OBJ" \
  $EXTRA "$HERE/xc7_prims_vl.v" "$BRAMV" y_DSP48E1.v "$NET" "$HERE/${MAIN:-full_main.cpp}"
