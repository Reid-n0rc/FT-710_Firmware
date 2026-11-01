#!/bin/sh
# T24 MAIN round 2: check the rx62t SLEIGH semantics of the instruction forms only the GCC-built src/main code uses
# (rx_semcheck.py GCC_FORMS) against rx_semcheck.py's model of the RXv2 manual, the way T22a checked MAIN's own forms.
#   tools/rx_semcheck_forms.sh <workdir>
# Assembles the forms (rx-elf-as/ld, raw at 0xFFF00000), imports the binary into a scratch Ghidra project in <workdir>
# (rx62t:LE:32:default, no analysis), decodes every instruction with ExportListing.java, generates the cases, runs
# RxEmuStep.java and checks. Exit status 0 when every case agrees. Nothing here reads the firmware.
# Environment: RX_BINUTILS (prefix, default ~/opt/rx-binutils-2.42/bin/rx-elf-), the tools/ghidra-headless.sh variables.
set -eu
REPO=$(cd "$(dirname "$0")/.." && pwd)
W=${1:?usage: rx_semcheck_forms.sh <workdir>}
BU=${RX_BINUTILS:-$HOME/opt/rx-binutils-2.42/bin/rx-elf-}
mkdir -p "$W"
W=$(cd "$W" && pwd)
python3 -I "$REPO/tools/rx_semcheck.py" forms "$W/forms.s"
"${BU}as" -o "$W/forms.o" "$W/forms.s"
"${BU}ld" -Ttext=0xFFF00000 -e _start -o "$W/forms.elf" "$W/forms.o"
"${BU}objcopy" -O binary -j .text "$W/forms.elf" "$W/forms.bin"
# every instruction address except the zero filler (BRK) before the forward branch target
"${BU}objdump" -d -z "$W/forms.elf" \
  | awk -F'\t' '/^fff[0-9a-f]+:\t/ && $3 != "" && $3 !~ /^brk/ { sub(":", "", $1); sub(/^ +/, "", $1); print "0x" $1 }' \
  > "$W/addrs.txt"
rm -rf "$W/proj"
mkdir -p "$W/proj"
"$REPO/tools/ghidra-headless.sh" "$W/proj" forms -import "$W/forms.bin" -loader BinaryLoader \
  -loader-baseAddr 0xFFF00000 -processor rx62t:LE:32:default -noanalysis \
  -scriptPath "$REPO/tools/ghidra" -postScript ExportListing.java "$W/decode.tsv" decode "$W/addrs.txt" \
  > "$W/import.log" 2>&1
python3 -I "$REPO/tools/rx_semcheck.py" gen "$W/decode.tsv" "$W/cases.tsv" --per-shape 400 --trials 8
"$REPO/tools/ghidra-headless.sh" "$W/proj" forms -process forms.bin -noanalysis -readOnly \
  -scriptPath "$REPO/tools/ghidra" -postScript RxEmuStep.java "$W/cases.tsv" "$W/emu.tsv" > "$W/emu.log" 2>&1
python3 -I "$REPO/tools/rx_semcheck.py" check "$W/cases.tsv" "$W/emu.tsv" --fails "$W/fails.tsv"
