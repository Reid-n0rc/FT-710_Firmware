#!/bin/bash
# FLIX test oracle, end to end (issue #97, A step 7): import the HiFi4 image with a given Xtensa language into a scratch
# Ghidra project, run setup, function pass and names as bootstrap does, export the listing, decode every flix.dis address, decompile
# FUN_0020bb74 (B9), and compare everything with decomp/ifdsp/hifi4/flix.dis (tools/flix_compare.py).
#
# Usage: tools/flix_oracle.sh <language-id> [outdir]
#   e.g. tools/flix_oracle.sh Xtensa:LE:32:default build/oracle/default
# Env:
#   IMAGE     HiFi4 image (default build/FT-710_IFDSP_V0101_hifi4.bin, from tools/ifdsp_dsp_images.py)
#   PROJDIR   scratch Ghidra project dir (default ghidra/; Ghidra refuses paths with a component starting with '.',
#             so set it when the repo is in e.g. .claude/worktrees/)
#   HEADLESS  command that runs analyzeHeadless as "<cmd> <projdir> <proj> args..." (default tools/ghidra-headless.sh;
#             a wrapper such as a RAM slot limiter can be put here, it gets the repo root as an extra first argument
#             if HEADLESS_ROOTARG=1)
#   TIMEOUT   seconds for each Ghidra run (default 3600)
# Output in <outdir> (default build/oracle/<language-id with ':' -> '_'>):
#   listing.tsv / decode.tsv          Ghidra exports (ExportListing.java)
#   listing/ decode/                  summary.txt, mismatches.tsv, by_mnemonic.tsv for each
#   functions.tsv                     Ghidra's function entries, compared with the flix.dis entries in functions.txt
#   b9.txt                            listing + decompile (or the error) of FUN_0020bb74
# Exit status 0 only if both the listing and the decode match flix.dis 100 % and the function lists match.
set -u
ROOT=$(cd "$(dirname "$0")/.." && pwd)
LANG_ID=${1:?usage: tools/flix_oracle.sh <language-id> [outdir]}
OUT=${2:-$ROOT/build/oracle/${LANG_ID//:/_}}
IMAGE=${IMAGE:-$ROOT/build/FT-710_IFDSP_V0101_hifi4.bin}
PROJDIR=${PROJDIR:-$ROOT/ghidra}
HEADLESS=${HEADLESS:-$ROOT/tools/ghidra-headless.sh}
TIMEOUT=${TIMEOUT:-3600}
PROJ=FT710_IFDSP_oracle_${LANG_ID//[^A-Za-z0-9]/_}
mkdir -p "$OUT" "$PROJDIR"
OUT=$(cd "$OUT" && pwd)
cd "$ROOT" || exit 2

run() {
  if [ "${HEADLESS_ROOTARG:-0}" = 1 ]; then
    timeout "$TIMEOUT" "$HEADLESS" "$ROOT" "$PROJDIR" "$PROJ" "$@"
  else
    timeout "$TIMEOUT" "$HEADLESS" "$PROJDIR" "$PROJ" "$@"
  fi
}

python3 -I tools/flix_compare.py addrs > "$OUT/addrs.txt" || exit 2
echo "== import $IMAGE as $LANG_ID -> $PROJDIR/$PROJ"
run -import "$IMAGE" -overwrite -processor "$LANG_ID" -loader BinaryLoader -loader-baseAddr 0x0 \
  -scriptPath "$ROOT/tools/ghidra" -preScript IfdspHifi4Setup.java -postScript IfdspHifi4FindFuncs.java -postScript IfdspHifi4Names.java \
  -postScript ExportListing.java "$OUT/listing.tsv" listing \
  -postScript ExportFuncList.java "$OUT/functions.tsv" \
  -analysisTimeoutPerFile "$TIMEOUT" > "$OUT/import.log" 2>&1 || { echo "import failed, see $OUT/import.log"; exit 2; }
echo "== decode every flix.dis address, decompile FUN_0020bb74"
run -process "$(basename "$IMAGE")" -noanalysis -readOnly -scriptPath "$ROOT/tools/ghidra" \
  -postScript ExportListing.java "$OUT/decode.tsv" decode "$OUT/addrs.txt" \
  -postScript DumpListing.java "$OUT/b9.txt" decomp 0x0020bb74 > "$OUT/decode.log" 2>&1 \
  || { echo "decode failed, see $OUT/decode.log"; exit 2; }
rc=0
for m in listing decode; do
  echo "== $m"
  python3 -I tools/flix_compare.py compare "$OUT/$m.tsv" "$OUT/$m" || rc=1
done
echo "== functions"
python3 -I tools/flix_compare.py funcs "$OUT/functions.tsv" "$OUT/functions_diff.tsv" || rc=1
echo "== B9 FUN_0020bb74"
grep -m1 -E 'decompile failed|^[a-z].*FUN_0020bb74\(' "$OUT/b9.txt" || echo "(see $OUT/b9.txt)"
exit $rc
