#!/bin/bash
# Random + directed co-simulation of ft710_uart_link against the whole netlist (T15e).
# Usage: hdl/sdr/sim/cosim_random.sh OUTDIR FIRST_SEED NRUNS FRAMES_PER_RUN
# Needs build/sdr/vl/obj_cosim/Vft710_sdr (TOP=cosim_top build, see hdl/sdr/README.md). Runs NRUNS in parallel.
REPO=$(cd "$(dirname "$0")/../../.." && pwd)
BIN=${BIN:-/workspace/FT-710_Firmware/build/sdr/vl/obj_cosim/Vft710_sdr}
OUT=$1; S0=$2; N=$3; F=$4
mkdir -p "$OUT"
cd "$REPO"
for k in $(seq 0 $((N - 1))); do
  s=$((S0 + k))
  mapfile -t A < <(python3 -I tools/sdr_cosim_check.py gen "$s" "$F")
  timeout 3000 python3 -I tools/sdr_uart_sim.py --bin "$BIN" --gap 0 --raw "${A[@]}" > "$OUT/run_$s.log" 2>&1 &
done
wait
pass=0; fail=0
for k in $(seq 0 $((N - 1))); do
  s=$((S0 + k))
  r=$(python3 -I tools/sdr_cosim_check.py "$OUT/run_$s.log" | tail -1)
  m=$(python3 -I tools/sdr_cosim_check.py "$OUT/run_$s.log" | grep "mismatching")
  echo "seed $s: $r  ($m)"
  [ "$r" = PASS ] && pass=$((pass + 1)) || fail=$((fail + 1))
done
echo "runs passed $pass, failed $fail"
