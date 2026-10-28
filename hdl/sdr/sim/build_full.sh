#!/bin/sh
# Build the whole recovered FT-710 SDR netlist with Verilator (T15e).
# Needs build/sdr/ft710_sdr.v (tools/xc7_netlist_verilog.py verilog) and Yosys' cells_sim.v (for DSP48E1, RAMB18E1).
# Output: build/sdr/vl/obj_full/Vft710_sdr (derived; never commit). Usage: hdl/sdr/sim/build_full.sh [REPO]
# Env: NET=<netlist .v> (default build/sdr/ft710_sdr.v), OBJ=<obj dir name>, PROBE_W=<words> for a probed netlist,
#      JOBS=<parallel compile jobs> (default 16; tools/bootstrap.sh passes nproc),
#      TOP=cosim_top for the netlist + RTL co-simulation (adds hdl/sdr/sim/cosim_top.v and the RTL files).
set -e
REPO=${1:-$(cd "$(dirname "$0")/../../.." && pwd)}
BUILD=${BUILD:-$REPO/build/sdr}
[ -f "$BUILD/ft710_sdr.v" ] || BUILD=/workspace/FT-710_Firmware/build/sdr
HERE=$(cd "$(dirname "$0")" && pwd)
mkdir -p "$BUILD/vl"
cd "$BUILD/vl"
# DSP48E1 and RAMB18E1 from Yosys, without the $fatal mode checks (they fire on constant-tied mode pins)
python3 -I - /usr/share/yosys/xilinx/cells_sim.v <<'EOF'
import re, sys
s = re.sub(r'\$fatal[^;]*;', ';', open(sys.argv[1]).read())
for m in ('DSP48E1', 'RAMB18E1'):
    i = s.index('module ' + m + ' ')
    open('y_' + m + '.v', 'w').write(s[i:s.index('endmodule', i) + 9] + '\n')
EOF
NET=${NET:-$BUILD/ft710_sdr.v}
OBJ=${OBJ:-obj_full}
TOP=${TOP:-ft710_sdr}
EXTRA=""
[ "$TOP" = cosim_top ] && EXTRA="$HERE/cosim_top.v $HERE/../uart_link.v $HERE/../uart_rx.v"
XC=""
[ -n "$PROBE_W" ] && XC="-DPROBE_W=$PROBE_W"
timeout 3000 verilator --cc --exe --build -j "${JOBS:-16}" -O3 --x-assign fast --x-initial fast \
  -Wno-fatal -Wno-lint -Wno-style --top-module "$TOP" --prefix Vft710_sdr \
  --output-split 30000 --output-split-cfuncs 3000 -CFLAGS "-O1 -fno-var-tracking $XC" -Mdir "$OBJ" \
  $EXTRA "$HERE/xc7_prims_vl.v" y_DSP48E1.v y_RAMB18E1.v "$NET" "$HERE/full_main.cpp"
