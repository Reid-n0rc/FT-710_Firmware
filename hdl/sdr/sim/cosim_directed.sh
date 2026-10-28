#!/bin/bash
# Directed co-simulation of ft710_uart_link against the whole netlist (T15e): MAIN's boot reads, writes,
# malformed lines and the NAK latency cases. Usage: hdl/sdr/sim/cosim_directed.sh OUTDIR
REPO=$(cd "$(dirname "$0")/../../.." && pwd)
BIN=${BIN:-/workspace/FT-710_Firmware/build/sdr/vl/obj_cosim/Vft710_sdr}
OUT=$1
mkdir -p "$OUT"
cd "$REPO"
run(){ n=$1; shift; timeout 3000 python3 -I tools/sdr_uart_sim.py --bin "$BIN" --raw "$@" > "$OUT/run_$n.log" 2>&1; }
run d1 b:r0000 b:r0001 b:w0037BCC5 b:r0037 b:w00151234 b:r0015 &
run d2 "b:=r0CB651\r" "b:=r0CB660\r" "b:=wC89BD51642\r" "b:=wC89BD516FD\r" "b:=r0CB6G5\r" "b:=w001512347b\r" &
run d3 "b:=zzr000032\r" "b:=r000032\n" "b:=\r" "b:=\rr000032\r" "b:=w000r000032\r" "b:=r00ff9E\r" &
run d4 b:r0003 b:w0003ABCD b:r0003 b:w00030000 b:r0003 "b:=r00ff9e\r" &
wait
pass=0; fail=0
for f in "$OUT"/run_d*.log; do
  r=$(python3 -I tools/sdr_cosim_check.py "$f" | tail -1)
  echo "$(basename "$f"): $r  ($(python3 -I tools/sdr_cosim_check.py "$f" | grep mismatching))"
  [ "$r" = PASS ] && pass=$((pass + 1)) || fail=$((fail + 1))
done
echo "runs passed $pass, failed $fail"
