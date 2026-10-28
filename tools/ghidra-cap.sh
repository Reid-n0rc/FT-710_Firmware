#!/bin/bash
# Run a Ghidra/REA job inside the owner's hardware cap (AGENTS.md "Hardware use"): about 75% of the machine.
# Usage: tools/ghidra-cap.sh <reserve_mb> -- <command...>
#   - at most CAP_SLOTS heavy jobs at once, machine-wide (flock slots in $CAP_DIR) [3]
#   - pinned to the first CAP_CPUS cores (taskset, Linux only) and run at nice 10 [3/4 of nproc]
#   - admitted through tools/memgate.py, which keeps MEMGATE_SAFETY_MB free on top of all reservations [3072]
# Exports CAP_CPUS for the caller's -max-cpu, and GC/compiler threads sized to the cap.
# Defaults: Ghidra and JDK 21 under $OPT_DIR (~/opt), unless GHIDRA_HEADLESS / GHIDRA_JAVA_HOME are set.
set -euo pipefail
[ $# -ge 3 ] && [ "$2" = "--" ] || { echo "usage: $0 <reserve_mb> -- <command...>" >&2; exit 2; }
reserve=$1; shift 2
REPO=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)

if command -v nproc >/dev/null 2>&1; then ncpu=$(nproc); else ncpu=$(sysctl -n hw.ncpu 2>/dev/null || echo 4); fi
CAP_CPUS=${CAP_CPUS:-$(( ncpu * 3 / 4 > 0 ? ncpu * 3 / 4 : 1 ))}
CAP_SLOTS=${CAP_SLOTS:-3}
CAP_DIR=${CAP_DIR:-$HOME/.cache/ft710-ghidra-cap}
export CAP_CPUS
export MEMGATE_DIR=${MEMGATE_DIR:-$HOME/.cache/ft710-memgate}
export MEMGATE_SAFETY_MB=${MEMGATE_SAFETY_MB:-3072}
gc=$(( CAP_CPUS / 2 > 0 ? CAP_CPUS / 2 : 1 ))
export GHIDRA_HEADLESS_JAVA_OPTIONS=${GHIDRA_HEADLESS_JAVA_OPTIONS:-"-XX:ParallelGCThreads=$gc -XX:CICompilerCount=2"}
export GHIDRA_HEADLESS_GC_THREADS=${GHIDRA_HEADLESS_GC_THREADS:-$gc}  # REA fork's knob

# Take a slot; the lock is held by this shell's fd and released when the job exits.
if command -v flock >/dev/null 2>&1; then
  mkdir -p "$CAP_DIR"
  while :; do
    for ((s = 0; s < CAP_SLOTS; s++)); do
      exec {fd}>"$CAP_DIR/slot$s"
      if flock -n "$fd"; then break 2; fi
      exec {fd}>&-
    done
    sleep 10
  done
fi

pin=()
command -v taskset >/dev/null 2>&1 && pin=(taskset -c "0-$(( CAP_CPUS - 1 ))")
gate=()
[ -r /proc/meminfo ] && gate=(python3 -I "$REPO/tools/memgate.py" "$reserve" --)
exec "${pin[@]}" nice -n 10 "${gate[@]}" "$@"
