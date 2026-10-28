#!/usr/bin/env bash
# FT-710 firmware project bootstrap (T20): rebuild everything that is not in git from the official downloads.
#
#   tools/bootstrap.sh                    # default steps: inputs decode rx ghidra export flix verify
#   tools/bootstrap.sh --only decode      # one step (repeat --only for several, or give a comma list)
#   tools/bootstrap.sh --skip verify      # all default steps but one
#   tools/bootstrap.sh --all              # default steps + sdr (the slow FPGA netlist chain)
#   tools/bootstrap.sh --list             # print the steps and the resolved settings
#
# Steps (in run order):
#   deps    download and unpack, SHA-256 checked, into $OPT_DIR: the Zephyr SDK 0.17.0 RT600 HiFi4 toolchain (Linux and
#           macOS, x86_64 and arm64; for step flix), and Ghidra 12.1.4 + Temurin JDK 21 (Linux x86_64 only; on macOS use
#           Homebrew instead, docs/getting-started.md). Not a default step.
#   inputs  check Firmware/ against docs/inputs.sha256; unpacks the Yaesu zip first if only the zip is there.
#   decode  SFL -> build/*.bin (tools/sfl_decode.py), carve the HiFi4 images (tools/ifdsp_dsp_images.py), check hashes.
#   rx      install the community RX SLEIGH module (stefan00lpf/rx-proc-ghidra @ ea4cd204, data files only) into
#           Ghidra, apply tools/ghidra/rx62t-movu-fix.patch (T17) and tools/ghidra/rx62t-rxv2-fix.patch (T21c) and
#           compile it. Skipped when already installed and patched.
#   ghidra  build the Ghidra projects FT710_MAIN, FT710_DISPLAY, FT710_IFDSP (two programs) with the committed setup,
#           code-discovery and names scripts. A program is rebuilt only when its inputs changed (stamp files).
#   export  re-export the decompiled C (tools/ghidra/ExportDecomp.java) and decomp/main/cat_dispatch.tsv.
#   flix    FLIX-aware HiFi4 listing decomp/ifdsp/hifi4/flix.dis with the Zephyr SDK RT600 objdump (tools/ifdsp_hifi4_dis.py).
#           Skipped with a warning when the objdump is missing (step deps installs it); verify then leaves flix.dis out.
#   verify  diff the exports against the committed decomp/ (INDEX.md and README.md are hand-written, not compared), and
#           compare each decomp/<image>/quality.tsv (decompile-quality counts from ExportDecomp.java) with the committed one
#           (tools/decomp_quality.py compare): fails if any count got worse; better counts are printed.
#   sdr     SDR FPGA chain (T15): prjxray checkouts + venv, FASM, cell netlist, structural Verilog/XDC, Verilator
#           model of the whole netlist and a UART smoke test. Slow (about 5-10 min); not a default step.
#
# Settings (environment variables; defaults in brackets):
#   BOOTSTRAP_OUT        root for build/, ghidra/ and the exported decomp/ [the repo root]. With the repo root the
#                        export overwrites the committed decomp/ and verify uses `git diff`.
#   FIRMWARE_DIR         where the Yaesu SFLs (or the zip) are [$REPO/Firmware]
#   DECOMP_OUT           export target [$BOOTSTRAP_OUT/decomp]
#   OPT_DIR              install root for deps [$HOME/opt];  DL_DIR  download cache [$OPT_DIR/dl]
#   GHIDRA_INSTALL_DIR   Ghidra root (has support/analyzeHeadless) [Homebrew libexec if present, else $OPT_DIR/ghidra_12.1.4_PUBLIC]
#   JAVA_HOME            JDK 21 [Homebrew openjdk@21 if present, else $OPT_DIR/jdk-21.0.13+9]
#   RX_MODULE_DIR        where the RX module goes [$GHIDRA_INSTALL_DIR/Ghidra/Processors/RX]
#   RX_SRC               clone of rx-proc-ghidra [$OPT_DIR/rx-proc-ghidra]
#   JOBS                 CPUs for Ghidra (-max-cpu) and Verilator [all: nproc]
#   GHIDRA_HEADLESS_MAXMEM  Ghidra heap [half the RAM, at most 8G]
#   GHIDRA_TIMEOUT       -analysisTimeoutPerFile seconds [3600];  FORCE=1  rebuild Ghidra programs even if up to date
#   FT710_TOOLS          prjxray checkouts + venv [$HOME/.local/share/ft710-tools];  PRJXRAY, PRJXRAY_DB, FT710_VENV
#   SDR_OUT              SDR derived files [$BOOTSTRAP_OUT/build/sdr]
#   ZEPHYR_SDK           Zephyr SDK root for step flix [$OPT_DIR/zephyr-sdk-0.17.0];  ZEPHYR_OBJDUMP  its RT600 objdump
#
# Uses only committed scripts (tools/, tools/ghidra/, hdl/sdr/sim/). Never talks to a radio.
set -euo pipefail

REPO=$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)
OUT=${BOOTSTRAP_OUT:-$REPO}
mkdir -p "$OUT"
OUT=$(cd "$OUT" && pwd)
FIRMWARE_DIR=${FIRMWARE_DIR:-$REPO/Firmware}
BUILD=$OUT/build
PROJ=$OUT/ghidra
DECOMP_OUT=${DECOMP_OUT:-$OUT/decomp}
OPT_DIR=${OPT_DIR:-$HOME/opt}
DL_DIR=${DL_DIR:-$OPT_DIR/dl}
OS=$(uname -s)
ARCH=$(uname -m)

if [ -d /opt/homebrew/opt/ghidra/libexec ] && [ -z "${GHIDRA_INSTALL_DIR:-}" ]; then
  GHIDRA_INSTALL_DIR=/opt/homebrew/opt/ghidra/libexec
fi
GHIDRA_INSTALL_DIR=${GHIDRA_INSTALL_DIR:-$OPT_DIR/ghidra_12.1.4_PUBLIC}
if [ -z "${JAVA_HOME:-}" ] || ! "${JAVA_HOME}/bin/java" -version 2>&1 | grep -q 'version "2[1-9]'; then
  if [ -d /opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home ]; then
    JAVA_HOME=/opt/homebrew/opt/openjdk@21/libexec/openjdk.jdk/Contents/Home
  else
    JAVA_HOME=$OPT_DIR/jdk-21.0.13+9
  fi
fi
export JAVA_HOME
RX_MODULE_DIR=${RX_MODULE_DIR:-$GHIDRA_INSTALL_DIR/Ghidra/Processors/RX}
RX_SRC=${RX_SRC:-$OPT_DIR/rx-proc-ghidra}

if command -v nproc >/dev/null 2>&1; then ncpu=$(nproc); else ncpu=$(sysctl -n hw.ncpu 2>/dev/null || echo 4); fi
JOBS=${JOBS:-$ncpu}
if [ -z "${GHIDRA_HEADLESS_MAXMEM:-}" ]; then
  if [ -r /proc/meminfo ]; then memk=$(awk '/^MemTotal:/ {print $2}' /proc/meminfo)
  else memk=$(( $(sysctl -n hw.memsize 2>/dev/null || echo 8589934592) / 1024 )); fi
  memg=$(( memk / 1024 / 1024 / 2 )); [ "$memg" -gt 8 ] && memg=8; [ "$memg" -lt 2 ] && memg=2
  GHIDRA_HEADLESS_MAXMEM=${memg}G
fi
export GHIDRA_HEADLESS_MAXMEM
GHIDRA_TIMEOUT=${GHIDRA_TIMEOUT:-3600}
FORCE=${FORCE:-0}
FT710_TOOLS=${FT710_TOOLS:-$HOME/.local/share/ft710-tools}
PRJXRAY=${PRJXRAY:-$FT710_TOOLS/prjxray}
PRJXRAY_DB=${PRJXRAY_DB:-$FT710_TOOLS/prjxray-db/artix7}
FT710_VENV=${FT710_VENV:-$FT710_TOOLS/venv}
export PRJXRAY PRJXRAY_DB FT710_VENV
SDR_OUT=${SDR_OUT:-$BUILD/sdr}
ZEPHYR_SDK=${ZEPHYR_SDK:-$OPT_DIR/zephyr-sdk-0.17.0}
ZEPHYR_OBJDUMP=${ZEPHYR_OBJDUMP:-$ZEPHYR_SDK/xtensa-nxp_rt600_adsp_zephyr-elf/bin/xtensa-nxp_rt600_adsp_zephyr-elf-objdump}
FLIX_DONE=0

# Pinned versions (docs/tooling.md).
GHIDRA_URL=https://github.com/NationalSecurityAgency/ghidra/releases/download/Ghidra_12.1.4_build/ghidra_12.1.4_PUBLIC_20260921.zip
GHIDRA_SHA=ddac49f903da9d5bac833e5cc79395098b9c33cfd3279be5f31bd00387d2d4db
JDK_URL=https://github.com/adoptium/temurin21-binaries/releases/download/jdk-21.0.13%2B9/OpenJDK21U-jdk_x64_linux_hotspot_21.0.13_9.tar.gz
JDK_SHA=d7f5d5cf865a2902b70ff549b97586a7d3f234e016f041ab447ea740c7d66d1c
RX_GIT=https://github.com/stefan00lpf/rx-proc-ghidra
RX_COMMIT=ea4cd20403c2e359f0de0cead2850d6be173b67a
RX_SINC_ORIG=42f51c2cc890cb4b396b1e1dce2dc85048ceaa3124c217088d58b5cba0758f12
RX_SINC_T17=d32178a96244f0c28202b6f1b76dfedbef7d2edbafe086354e17520b51c0011b
RX_SINC_FIXED=9eadf83b841c0545e80044954d45f1f5b176c3df97035bb5720bb347ea156a11
PRJXRAY_GIT=https://github.com/f4pga/prjxray
PRJXRAY_COMMIT=c9f02d8576042325425824647ab5555b1bc77833
PRJXRAY_DB_GIT=https://github.com/f4pga/prjxray-db
PRJXRAY_DB_COMMIT=0a0addedd73e7e4139d52a6d8db4258763e0f1f3
ZEPHYR_URL=https://github.com/zephyrproject-rtos/sdk-ng/releases/download/v0.17.0
ZEPHYR_TC=xtensa-nxp_rt600_adsp_zephyr-elf  # SHA-256 per platform from the release's sha256.sum
ZEPHYR_SHA_linux_x86_64=2e0a54e20056b82cae12593e5d936d1e22cdb3f90cb9e77d59c500a5ad4abdc2
ZEPHYR_SHA_linux_aarch64=c099e411daec57b6c4e4824d1a1e3ebf2ed607103dc04b66919ae19c14bbfbfa
ZEPHYR_SHA_macos_aarch64=31b6072b911d2324443d58ec0176bd560eba3b3095c9aba18c3f40c2de8f5785
ZEPHYR_SHA_macos_x86_64=f95f8a3fa5fc864a5f731f492dfe8bb96e1c3b3a1ae5455dc68ffddb04c609cd
VENV_PKGS="fasm==0.0.2.post88 textX==4.4.0 Arpeggio==2.0.3 simplejson==4.2.0 intervaltree==3.2.1 sortedcontainers==2.4.0 PyYAML==6.0.3"

ALL_STEPS="deps inputs decode rx ghidra export flix verify sdr"
DEFAULT_STEPS="inputs decode rx ghidra export flix verify"

log()  { printf '\n== [%s] %s\n' "$(date +%H:%M:%S)" "$*"; }
info() { printf '   %s\n' "$*"; }
die()  { printf 'bootstrap: error: %s\n' "$*" >&2; exit 1; }
need() { command -v "$1" >/dev/null 2>&1 || die "'$1' not found; see docs/getting-started.md ($2)"; }
sha256() { if command -v sha256sum >/dev/null 2>&1; then sha256sum "$1" | cut -d' ' -f1; else shasum -a 256 "$1" | cut -d' ' -f1; fi; }
py() { python3 -I "$@"; }

# Check every "<sha>  <prefix>/..." line of docs/inputs.sha256 against files under $2.
check_hashes() {
  local prefix=$1 root=$2 bad=0 n=0 sum path f
  while read -r sum path; do
    case "$sum" in ''|'#'*) continue ;; esac
    case "$path" in "$prefix"/*) ;; *) continue ;; esac
    f=$root/${path#"$prefix"/}
    n=$((n + 1))
    if [ ! -f "$f" ]; then info "MISSING $f"; bad=$((bad + 1))
    elif [ "$(sha256 "$f")" != "$sum" ]; then info "MISMATCH $f"; bad=$((bad + 1))
    else info "ok  $path"; fi
  done < "${REPO_SUMS:-$REPO/docs/inputs.sha256}"
  [ "$bad" -eq 0 ] || return 1
  info "$n files match docs/inputs.sha256"
}

headless() {  # headless <project> <analyzeHeadless args...>
  local p=$1; shift
  [ -x "$GHIDRA_INSTALL_DIR/support/analyzeHeadless" ] || die "no analyzeHeadless in $GHIDRA_INSTALL_DIR (step deps, or set GHIDRA_INSTALL_DIR)"
  mkdir -p "$PROJ" "$OUT/logs"
  local run=$OUT/logs/ghidra_last_run.log rc=0
  GHIDRA_JAVA_HOME=$JAVA_HOME GHIDRA_HEADLESS=$GHIDRA_INSTALL_DIR/support/analyzeHeadless \
    "$REPO/tools/ghidra-headless.sh" "$PROJ" "$p" "$@" -max-cpu "$JOBS" -scriptPath "$REPO/tools/ghidra" \
    > "$run" 2>&1 || rc=$?
  cat "$run" >> "$OUT/logs/ghidra_$p.log"
  [ "$rc" -eq 0 ] || { tail -30 "$run" >&2; die "Ghidra run failed (log: $OUT/logs/ghidra_$p.log)"; }
  grep -q -i -E 'ERROR.*script|REPORT: .*failed' "$run" && { grep -E 'ERROR|failed' "$run" | head -10 >&2; die "a Ghidra script failed (log: $OUT/logs/ghidra_$p.log)"; }
  grep -E '^(INFO|WARN|ERROR) +(ExportDecomp|ApplyNames|FixFuncEntries|CatDispatch|Display|Ifdsp|SetupRX651)|> (ExportDecomp|ApplyNames|FixFuncEntries|CatDispatch|Display|Ifdsp|SetupRX651)' \
    "$run" | sed -e 's/ (GhidraScript) *$//' -e 's/^INFO  //' | tail -n 3 | sed 's/^/   /' || true
}

# Stamp = hash of everything a program depends on; skip the rebuild when it is unchanged.
# A program is up to date when its stamp matches. A committed project (in git, no stamp yet) is kept as is: rebuild it with FORCE=1.
stamp_ok() {
  [ "$FORCE" != 1 ] && [ -f "$PROJ/$1.gpr" ] || return 1
  if [ ! -f "$PROJ/.stamp_$2" ] && git -C "$REPO" ls-files --error-unmatch "ghidra/$1.gpr" >/dev/null 2>&1 && [ "$PROJ" = "$REPO/ghidra" ]; then
    info "$1: using the committed project (FORCE=1 rebuilds it)"; return 0
  fi
  [ -f "$PROJ/.stamp_$2" ] && [ "$(cat "$PROJ/.stamp_$2")" = "$3" ]
}
sha256_stdin() { if command -v sha256sum >/dev/null 2>&1; then sha256sum | cut -d' ' -f1; else shasum -a 256 | cut -d' ' -f1; fi; }
stamp_of() { local f; for f in "$@"; do sha256 "$f"; done | sha256_stdin; }

# ---------------------------------------------------------------- deps
fetch() {  # fetch <url> <file> <sha>
  if [ ! -f "$2" ] || [ "$(sha256 "$2")" != "$3" ]; then
    info "download $1"; curl -fL --retry 3 -o "$2.part" "$1"; mv "$2.part" "$2"
  fi
  [ "$(sha256 "$2")" = "$3" ] || die "SHA-256 mismatch for $2"
  info "ok  $(basename "$2") ($3)"
}
step_deps() {
  need curl "curl"; need tar "tar"
  mkdir -p "$OPT_DIR" "$DL_DIR"
  log "deps: Zephyr SDK 0.17.0 $ZEPHYR_TC toolchain into $ZEPHYR_SDK"
  local plat sha
  case "$OS/$ARCH" in
    Linux/x86_64) plat=linux-x86_64 ;; Linux/aarch64|Linux/arm64) plat=linux-aarch64 ;;
    Darwin/arm64) plat=macos-aarch64 ;; Darwin/x86_64) plat=macos-x86_64 ;; *) plat="" ;;
  esac
  if [ -x "$ZEPHYR_OBJDUMP" ]; then info "Zephyr RT600 objdump present: $ZEPHYR_OBJDUMP"
  elif [ -z "$plat" ]; then info "No Zephyr SDK build for $OS/$ARCH; step flix will be skipped"
  else
    sha=ZEPHYR_SHA_${plat//-/_}
    fetch "$ZEPHYR_URL/toolchain_${plat}_$ZEPHYR_TC.tar.xz" "$DL_DIR/zephyr_${plat}_$ZEPHYR_TC.tar.xz" "${!sha}"
    mkdir -p "$ZEPHYR_SDK"; tar -xJf "$DL_DIR/zephyr_${plat}_$ZEPHYR_TC.tar.xz" -C "$ZEPHYR_SDK"
    [ -x "$ZEPHYR_OBJDUMP" ] || die "unpacked toolchain has no objdump at $ZEPHYR_OBJDUMP"
    "$ZEPHYR_OBJDUMP" --version | head -1 | sed 's/^/   /'
  fi
  log "deps: Ghidra 12.1.4 + Temurin JDK 21.0.13+9 into $OPT_DIR"
  if [ "$OS" != Linux ] || [ "$ARCH" != x86_64 ]; then
    info "Not Linux x86_64. Install with Homebrew instead:  brew install ghidra   (pulls openjdk@21)"
    return 0
  fi
  need unzip "unzip"
  if [ -x "$GHIDRA_INSTALL_DIR/support/analyzeHeadless" ]; then info "Ghidra present: $GHIDRA_INSTALL_DIR"
  else
    fetch "$GHIDRA_URL" "$DL_DIR/ghidra.zip" "$GHIDRA_SHA"
    unzip -q -o "$DL_DIR/ghidra.zip" -d "$OPT_DIR"
    [ -x "$GHIDRA_INSTALL_DIR/support/analyzeHeadless" ] || die "unpacked Ghidra is not at $GHIDRA_INSTALL_DIR (set GHIDRA_INSTALL_DIR=$OPT_DIR/ghidra_12.1.4_PUBLIC)"
  fi
  if [ -x "$JAVA_HOME/bin/java" ]; then info "JDK present: $JAVA_HOME"
  else
    fetch "$JDK_URL" "$DL_DIR/jdk21.tar.gz" "$JDK_SHA"
    tar -xzf "$DL_DIR/jdk21.tar.gz" -C "$OPT_DIR"
    [ -x "$JAVA_HOME/bin/java" ] || die "unpacked JDK is not at $JAVA_HOME (set JAVA_HOME=$OPT_DIR/jdk-21.0.13+9)"
  fi
  "$JAVA_HOME/bin/java" -version 2>&1 | head -1 | sed 's/^/   /'
}

# ---------------------------------------------------------------- inputs
step_inputs() {
  log "inputs: $FIRMWARE_DIR"
  local zip=$FIRMWARE_DIR/FT-710_Firmware_updata_202402.zip
  if [ ! -f "$FIRMWARE_DIR/FT-710_MAIN_V0112.SFL" ] && [ -f "$zip" ]; then
    need unzip "unzip"
    info "unpacking $(basename "$zip")"
    unzip -q -o -j "$zip" -d "$FIRMWARE_DIR"
  fi
  if [ ! -f "$FIRMWARE_DIR/FT-710_MAIN_V0112.SFL" ]; then
    die "no SFLs in $FIRMWARE_DIR. Download https://yaesu.com/Files/BB2B47AE-1018-01AF-FAE48FDCB1919193/FT-710_Firmware_updata_202402.zip into it"
  fi
  if [ ! -f "$zip" ]; then
    info "(the zip itself is absent; checking the unpacked files only)"
    grep -v 'updata_202402.zip' "$REPO/docs/inputs.sha256" > "$OUT/.inputs.tmp"
    REPO_SUMS=$OUT/.inputs.tmp
  fi
  check_hashes Firmware "$FIRMWARE_DIR" || die "Firmware/ does not match docs/inputs.sha256 (a different firmware package?)"
}

# ---------------------------------------------------------------- decode
step_decode() {
  log "decode: SFL -> $BUILD"
  need python3 "Python 3"
  mkdir -p "$BUILD"
  local img
  for img in MAIN_V0112 DISPLAY_V0108 IFDSP_V0101 SDR_V0104; do
    py "$REPO/tools/sfl_decode.py" "$FIRMWARE_DIR/FT-710_$img.SFL" "$BUILD/FT-710_$img.bin" | sed 's/^/   /'
  done
  py "$REPO/tools/ifdsp_dsp_images.py" "$BUILD/FT-710_IFDSP_V0101.bin" "$BUILD" | sed 's/^/   /'
  check_hashes build "$BUILD" || die "decoded images do not match docs/inputs.sha256"
}

# ---------------------------------------------------------------- rx
step_rx() {
  log "rx: Renesas RX SLEIGH module in $RX_MODULE_DIR"
  local lang=$RX_MODULE_DIR/data/languages
  if [ -f "$lang/rx62t.sinc" ] && [ "$(sha256 "$lang/rx62t.sinc")" = "$RX_SINC_FIXED" ] \
     && [ -f "$lang/rx62t.sla" ] && [ "$lang/rx62t.sla" -nt "$lang/rx62t.sinc" ]; then
    info "installed, patched (rx62t.sinc $RX_SINC_FIXED) and compiled"
    return 0
  fi
  [ -d "$GHIDRA_INSTALL_DIR/Ghidra/Processors" ] || die "no Ghidra at $GHIDRA_INSTALL_DIR (step deps, or set GHIDRA_INSTALL_DIR)"
  need patch "patch"
  if [ ! -f "$lang/rx62t.sinc" ]; then
    need git "git"
    if [ ! -d "$RX_SRC/.git" ]; then git clone -q "$RX_GIT" "$RX_SRC"; fi
    git -C "$RX_SRC" fetch -q origin "$RX_COMMIT" 2>/dev/null || true
    git -C "$RX_SRC" -c advice.detachedHead=false checkout -q "$RX_COMMIT"
    [ "$(sha256 "$RX_SRC/data/languages/rx62t.sinc")" = "$RX_SINC_ORIG" ] || die "unexpected rx62t.sinc in $RX_SRC"
    mkdir -p "$lang"
    # data files only: no Java, no jars, no scripts from the module
    cp "$RX_SRC"/data/languages/rx62t.{slaspec,sinc,ldefs,pspec,cspec,opinion} "$lang/"
    : > "$RX_MODULE_DIR/Module.manifest"
    info "copied the six rx62t.* language files from $RX_GIT @ ${RX_COMMIT:0:8}"
  fi
  if [ "$(sha256 "$lang/rx62t.sinc")" = "$RX_SINC_ORIG" ]; then
    cp "$lang/rx62t.sinc" "$lang/rx62t.sinc.orig-ea4cd204"
    (cd "$RX_MODULE_DIR" && patch -s -p1 < "$REPO/tools/ghidra/rx62t-movu-fix.patch")
    info "applied tools/ghidra/rx62t-movu-fix.patch (T17)"
  fi
  if [ "$(sha256 "$lang/rx62t.sinc")" = "$RX_SINC_T17" ]; then
    [ -f "$lang/rx62t.sinc.t17" ] || cp "$lang/rx62t.sinc" "$lang/rx62t.sinc.t17"
    [ -f "$lang/rx62t.sla" ] && [ ! -f "$lang/rx62t.sla.t17" ] && cp "$lang/rx62t.sla" "$lang/rx62t.sla.t17"
    (cd "$RX_MODULE_DIR" && patch -s -p1 < "$REPO/tools/ghidra/rx62t-rxv2-fix.patch")
    info "applied tools/ghidra/rx62t-rxv2-fix.patch (T21c: MUL .UB, XCHG memory, SCCnd, string ops as pcodeops)"
  fi
  [ "$(sha256 "$lang/rx62t.sinc")" = "$RX_SINC_FIXED" ] || die "rx62t.sinc in $lang is neither the original nor a T17/T21c-patched file"
  [ -f "$lang/rx62t.sla" ] && [ ! -f "$lang/rx62t.sla.orig-ea4cd204" ] && cp "$lang/rx62t.sla" "$lang/rx62t.sla.orig-ea4cd204"
  "$GHIDRA_INSTALL_DIR/support/sleigh" "$lang/rx62t.slaspec" > "$OUT/logs/sleigh.txt" 2>&1 \
    || { tail -20 "$OUT/logs/sleigh.txt" >&2; die "sleigh compile failed"; }
  info "compiled rx62t.sla (log: $OUT/logs/sleigh.txt; the 8 NOP-constructor warnings are expected)"
}

# ---------------------------------------------------------------- ghidra
G=$REPO/tools/ghidra
build_main() {
  local bin=$BUILD/FT-710_MAIN_V0112.bin
  local st; st=$(stamp_of "$bin" "$G/SetupRX651.java" "$G/ApplyNames.java" "$G/names_main.tsv" "$RX_MODULE_DIR/data/languages/rx62t.sinc")
  if stamp_ok FT710_MAIN main "$st"; then info "FT710_MAIN up to date"; return; fi
  info "FT710_MAIN: import rx62t:LE:32:default @ 0xFFF80000, SetupRX651, analysis, ApplyNames names_main.tsv"
  rm -f "$PROJ/.stamp_main"
  headless FT710_MAIN -import "$bin" -overwrite \
    -processor rx62t:LE:32:default -loader BinaryLoader -loader-baseAddr 0xFFF80000 -analysisTimeoutPerFile "$GHIDRA_TIMEOUT" \
    -preScript SetupRX651.java copy=0xFFF8EADC:0xFFF8EC1C:0x25D20 copy=0xFFF8EE4C:0xFFF8EEA4:0x1FF1A copy=0xFFF8EC1C:0xFFF8EE4C:0x1B3CC \
    -postScript ApplyNames.java "$G/names_main.tsv"
  echo "$st" > "$PROJ/.stamp_main"
}
build_display() {
  local bin=$BUILD/FT-710_DISPLAY_V0108.bin prog=FT-710_DISPLAY_V0108.bin
  local st; st=$(stamp_of "$bin" "$G/DisplaySetup.java" "$G/DisplayFindCode.java" "$G/FixFuncEntries.java" "$G/entries_display.tsv" "$G/ApplyNames.java" "$G/names_display.tsv")
  if stamp_ok FT710_DISPLAY display "$st"; then info "FT710_DISPLAY up to date"; return; fi
  info "FT710_DISPLAY: import ARM:LE:32:v7 @ 0x20100000, DisplaySetup, analysis, DisplayFindCode x2, FixFuncEntries, ApplyNames"
  rm -f "$PROJ/.stamp_display"
  headless FT710_DISPLAY -import "$bin" -overwrite \
    -processor ARM:LE:32:v7 -loader BinaryLoader -loader-baseAddr 0x20100000 \
    -preScript DisplaySetup.java -analysisTimeoutPerFile "$GHIDRA_TIMEOUT"
  headless FT710_DISPLAY -process "$prog" -noanalysis -analysisTimeoutPerFile "$GHIDRA_TIMEOUT" -postScript DisplayFindCode.java
  headless FT710_DISPLAY -process "$prog" -noanalysis -analysisTimeoutPerFile "$GHIDRA_TIMEOUT" -postScript DisplayFindCode.java
  headless FT710_DISPLAY -process "$prog" -noanalysis -postScript FixFuncEntries.java "$G/entries_display.tsv"
  headless FT710_DISPLAY -process "$prog" -noanalysis -postScript ApplyNames.java "$G/names_display.tsv"
  echo "$st" > "$PROJ/.stamp_display"
}
build_ifdsp() {
  local m33=$BUILD/FT-710_IFDSP_V0101.bin hifi=$BUILD/FT-710_IFDSP_V0101_hifi4.bin st
  st=$(stamp_of "$m33" "$G/IfdspM33Setup.java" "$G/IfdspFindFuncs.java" "$G/IfdspM33Names.java")
  if stamp_ok FT710_IFDSP ifdsp_m33 "$st"; then info "FT710_IFDSP/M33 up to date"
  else
    info "FT710_IFDSP/M33: import ARM:LE:32:v8-m @ 0x08000000, IfdspM33Setup, analysis, IfdspFindFuncs, IfdspM33Names"
    rm -f "$PROJ/.stamp_ifdsp_m33"
    headless FT710_IFDSP -import "$m33" -overwrite \
      -processor ARM:LE:32:v8-m -loader BinaryLoader -loader-baseAddr 0x08000000 \
      -preScript IfdspM33Setup.java -postScript IfdspFindFuncs.java -postScript IfdspM33Names.java -analysisTimeoutPerFile "$GHIDRA_TIMEOUT"
    echo "$st" > "$PROJ/.stamp_ifdsp_m33"
  fi
  st=$(stamp_of "$hifi" "$G/IfdspHifi4Setup.java" "$G/IfdspHifi4FindFuncs.java" "$G/IfdspHifi4Names.java")
  if stamp_ok FT710_IFDSP ifdsp_hifi4 "$st"; then info "FT710_IFDSP/HiFi4 up to date"
  else
    info "FT710_IFDSP/HiFi4: import Xtensa:LE:32:default @ 0, IfdspHifi4Setup, analysis, IfdspHifi4FindFuncs, IfdspHifi4Names"
    rm -f "$PROJ/.stamp_ifdsp_hifi4"
    headless FT710_IFDSP -import "$hifi" -overwrite \
      -processor Xtensa:LE:32:default -loader BinaryLoader -loader-baseAddr 0x0 \
      -preScript IfdspHifi4Setup.java -postScript IfdspHifi4FindFuncs.java -postScript IfdspHifi4Names.java -analysisTimeoutPerFile "$GHIDRA_TIMEOUT"
    echo "$st" > "$PROJ/.stamp_ifdsp_hifi4"
  fi
}
step_ghidra() {
  log "ghidra: projects in $PROJ (JOBS=$JOBS, heap $GHIDRA_HEADLESS_MAXMEM; logs in $OUT/logs/)"
  [ -f "$BUILD/FT-710_MAIN_V0112.bin" ] || die "no decoded images in $BUILD (run step decode)"
  [ -f "$RX_MODULE_DIR/data/languages/rx62t.sla" ] || die "RX module missing (run step rx)"
  build_main
  build_display
  build_ifdsp
}

# ---------------------------------------------------------------- export
step_export() {
  log "export: decompiled C -> $DECOMP_OUT"
  [ -f "$PROJ/FT710_MAIN.gpr" ] || die "no Ghidra projects in $PROJ (run step ghidra)"
  mkdir -p "$DECOMP_OUT"/{main,display,ifdsp/m33,ifdsp/hifi4}
  headless FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
    -postScript ExportDecomp.java "$DECOMP_OUT/main" 50 \
    -postScript CatDispatch.java "$DECOMP_OUT/main/cat_dispatch.tsv" 0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
  headless FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly -analysisTimeoutPerFile "$GHIDRA_TIMEOUT" \
    -postScript ExportDecomp.java "$DECOMP_OUT/display" 50
  headless FT710_IFDSP -process FT-710_IFDSP_V0101.bin -noanalysis -readOnly -postScript ExportDecomp.java "$DECOMP_OUT/ifdsp/m33" 50
  headless FT710_IFDSP -process FT-710_IFDSP_V0101_hifi4.bin -noanalysis -readOnly -postScript ExportDecomp.java "$DECOMP_OUT/ifdsp/hifi4" 50
  local d; for d in main display ifdsp/m33 ifdsp/hifi4; do
    info "$d: $(($(wc -l < "$DECOMP_OUT/$d/functions.tsv") - 1)) functions, $(grep -l 'decompile failed' "$DECOMP_OUT/$d"/*.c 2>/dev/null | wc -l | tr -d ' ') file(s) with a failure, $(awk -F'\t' '$1=="warnings"{print $2}' "$DECOMP_OUT/$d/quality.tsv" 2>/dev/null) warnings (quality.tsv)"
  done
}

# ---------------------------------------------------------------- verify
step_flix() {
  log "flix: FLIX-aware HiFi4 listing -> $DECOMP_OUT/ifdsp/hifi4/flix.dis"
  if [ ! -x "$ZEPHYR_OBJDUMP" ]; then
    info "WARNING: no Zephyr RT600 objdump at $ZEPHYR_OBJDUMP (run step deps, or set ZEPHYR_OBJDUMP); skipped"
    return 0
  fi
  local text=$BUILD/FT-710_IFDSP_V0101_hifi4_1_sram_text.bin tsv=$DECOMP_OUT/ifdsp/hifi4/functions.tsv
  [ -f "$text" ] || die "no $text (run step decode)"
  [ -f "$tsv" ] || tsv=$REPO/decomp/ifdsp/hifi4/functions.tsv
  mkdir -p "$DECOMP_OUT/ifdsp/hifi4"
  py "$REPO/tools/ifdsp_hifi4_dis.py" "$ZEPHYR_OBJDUMP" "$text" "$tsv" "$DECOMP_OUT/ifdsp/hifi4/flix.dis" \
    "$REPO/tools/ghidra/IfdspHifi4Names.java" 2>&1 | tail -n 1 | sed 's/^/   /'
  FLIX_DONE=1
}
step_verify() {
  log "verify: $DECOMP_OUT against the committed decomp/"
  local rc=0 qrc=0 noflix="" d old
  [ "$FLIX_DONE" = 1 ] || noflix="-x flix.dis"
  # quality.tsv is not diffed byte for byte: it is compared metric by metric below (T21f, #97 B11).
  if [ "$DECOMP_OUT" = "$REPO/decomp" ]; then
    git -C "$REPO" diff --stat -- decomp/ ':(exclude,glob)decomp/**/quality.tsv' | tail -n 5
    git -C "$REPO" diff --quiet -- decomp/ ':(exclude,glob)decomp/**/quality.tsv' \
      && [ -z "$(git -C "$REPO" ls-files --others --exclude-standard -- decomp/ ':(exclude,glob)decomp/**/quality.tsv')" ] || rc=1
  else
    diff -r -q -x INDEX.md -x README.md -x quality.tsv -x sdr $noflix "$REPO/decomp" "$DECOMP_OUT" > "$OUT/logs/verify.txt" 2>&1 || rc=1
    if [ "$rc" -ne 0 ]; then
      sed 's/^/   /' "$OUT/logs/verify.txt" | head -n 20
      diff -r -u -x INDEX.md -x README.md -x quality.tsv -x sdr $noflix "$REPO/decomp" "$DECOMP_OUT" > "$OUT/decomp.diff" || true
      info "full diff: $OUT/decomp.diff ($(wc -l < "$OUT/decomp.diff") lines)"
    fi
  fi
  if [ "$rc" -eq 0 ]; then info "IDENTICAL: the re-exported decomps match decomp/ byte for byte"; fi
  # Decompile-quality regression check: no count in the fresh quality.tsv may be higher than in the committed one.
  for d in main display ifdsp/m33 ifdsp/hifi4; do
    [ -f "$DECOMP_OUT/$d/quality.tsv" ] || { info "$d: no quality.tsv in the export (old ExportDecomp?)"; qrc=1; continue; }
    old=$OUT/logs/quality_committed_${d//\//_}.tsv
    if [ "$DECOMP_OUT" = "$REPO/decomp" ]; then
      git -C "$REPO" show "HEAD:decomp/$d/quality.tsv" > "$old" 2>/dev/null || { info "$d: no committed quality.tsv; skipped"; continue; }
    else
      [ -f "$REPO/decomp/$d/quality.tsv" ] || { info "$d: no committed quality.tsv; skipped"; continue; }
      cp "$REPO/decomp/$d/quality.tsv" "$old"
    fi
    py "$REPO/tools/decomp_quality.py" compare "$old" "$DECOMP_OUT/$d/quality.tsv" "$d" | sed 's/^/   /' || qrc=1  # pipefail
  done
  [ "$qrc" -eq 0 ] || die "decompile quality got worse (see WORSE above), or a quality.tsv is missing"
  [ "$rc" -eq 0 ] || die "the export differs from decomp/ (see above). If you changed names or scripts on purpose, commit the new export"
}

# ---------------------------------------------------------------- sdr
sdr_deps() {
  need git "git"
  mkdir -p "$FT710_TOOLS"
  if [ ! -d "$PRJXRAY/.git" ]; then
    info "clone prjxray @ ${PRJXRAY_COMMIT:0:7}"; git clone -q "$PRJXRAY_GIT" "$PRJXRAY"
  fi
  [ "$(git -C "$PRJXRAY" rev-parse HEAD)" = "$PRJXRAY_COMMIT" ] || git -C "$PRJXRAY" -c advice.detachedHead=false checkout -q "$PRJXRAY_COMMIT"
  local dbroot=${PRJXRAY_DB%/artix7}
  if [ ! -d "$dbroot/.git" ]; then
    info "clone prjxray-db @ ${PRJXRAY_DB_COMMIT:0:7} (sparse: artix7 xc7a50t, ~80 MB)"
    git clone -q --filter=blob:none --no-checkout "$PRJXRAY_DB_GIT" "$dbroot"
    git -C "$dbroot" sparse-checkout set --no-cone '/artix7/*.db' '/artix7/*.json' '/artix7/*.yaml' '/artix7/mask_*' '/artix7/xc7a50t*/' '/artix7/mapping/'
    git -C "$dbroot" -c advice.detachedHead=false checkout -q "$PRJXRAY_DB_COMMIT"
  fi
  [ "$(git -C "$dbroot" rev-parse HEAD)" = "$PRJXRAY_DB_COMMIT" ] || die "prjxray-db in $dbroot is not at $PRJXRAY_DB_COMMIT"
  [ -f "$PRJXRAY_DB/mapping/devices.yaml" ] || git -C "$dbroot" sparse-checkout add '/artix7/mapping/'
  if [ ! -x "$FT710_VENV/bin/python" ]; then
    info "venv $FT710_VENV: $VENV_PKGS"
    python3 -m venv "$FT710_VENV"
    # shellcheck disable=SC2086
    "$FT710_VENV/bin/pip" install -q $VENV_PKGS
  fi
}
step_sdr() {
  log "sdr: FPGA chain into $SDR_OUT (T15a-e)"
  need python3 "Python 3"; need verilator "Verilator 5"; need yosys "Yosys (for its Xilinx cells_sim.v)"
  [ -f "$BUILD/FT-710_SDR_V0104.bin" ] || die "no $BUILD/FT-710_SDR_V0104.bin (run step decode)"
  sdr_deps
  mkdir -p "$SDR_OUT"
  local t0=$SECONDS
  py "$REPO/tools/xc7_db.py" "$BUILD/FT-710_SDR_V0104.bin" frames | grep -E "MATCH|MISMATCH" | sed "s/^/   /"
  py "$REPO/tools/xc7_fasm.py" fasm "$BUILD/FT-710_SDR_V0104.bin" "$SDR_OUT/FT-710_SDR_V0104.fasm" --unknown "$SDR_OUT/unknown_bits.txt" | tail -n 3 | sed 's/^/   /'
  py "$REPO/tools/xc7_netlist.py" build "$SDR_OUT/FT-710_SDR_V0104.fasm" "$SDR_OUT/netlist.json" | tail -n 3 | sed 's/^/   /'
  py "$REPO/tools/xc7_netlist_verilog.py" verilog "$SDR_OUT/netlist.json" "$SDR_OUT/ft710_sdr.v" --xdc "$SDR_OUT/ft710_sdr.xdc" | tail -n 3 | sed 's/^/   /'
  py "$REPO/tools/xc7_netlist_verilog.py" prims "$SDR_OUT/prims.v" | sed 's/^/   /'
  py "$REPO/tools/xc7_netlist_verilog.py" simprims "$SDR_OUT/simprims.v" | sed 's/^/   /'
  info "netlist done in $((SECONDS - t0)) s; building the Verilator model (JOBS=$JOBS)"
  BUILD=$SDR_OUT JOBS=$JOBS "$REPO/hdl/sdr/sim/build_full.sh" "$REPO" > "$SDR_OUT/build_full.log" 2>&1 \
    || { tail -20 "$SDR_OUT/build_full.log" >&2; die "Verilator build failed (log: $SDR_OUT/build_full.log)"; }
  info "UART smoke test (MAIN frame r0000 on UART B, console on UART A):"
  py "$REPO/tools/sdr_uart_sim.py" --bin "$SDR_OUT/vl/obj_full/Vft710_sdr" b:r0000 "a:=r 0000\r" | sed 's/^/   /'
  info "sdr done in $((SECONDS - t0)) s"
}

# ---------------------------------------------------------------- main
usage() { sed -n '2,46p' "${BASH_SOURCE[0]}" | sed 's/^# \{0,1\}//'; }
steps=""; skip=" "
while [ $# -gt 0 ]; do
  case "$1" in
    --only) shift; [ $# -gt 0 ] || die "--only needs a step"; steps="$steps ${1//,/ }" ;;
    --only=*) v=${1#--only=}; steps="$steps ${v//,/ }" ;;
    --skip) shift; [ $# -gt 0 ] || die "--skip needs a step"; skip="$skip${1//,/ } " ;;
    --skip=*) v=${1#--skip=}; skip="$skip${v//,/ } " ;;
    --all) steps="$DEFAULT_STEPS sdr" ;;
    --list)
      echo "steps: $ALL_STEPS (default: $DEFAULT_STEPS)"
      for v in REPO OUT FIRMWARE_DIR BUILD PROJ DECOMP_OUT OPT_DIR GHIDRA_INSTALL_DIR JAVA_HOME RX_MODULE_DIR JOBS GHIDRA_HEADLESS_MAXMEM FT710_TOOLS SDR_OUT ZEPHYR_OBJDUMP; do
        printf '  %-24s %s\n' "$v" "${!v}"; done
      exit 0 ;;
    -h|--help) usage; exit 0 ;;
    *) die "unknown argument '$1' (try --help)" ;;
  esac
  shift
done
[ -n "$steps" ] || steps=$DEFAULT_STEPS
for s in $steps; do case " $ALL_STEPS " in *" $s "*) ;; *) die "unknown step '$s' (steps: $ALL_STEPS)" ;; esac; done
mkdir -p "$OUT/logs"
for s in $ALL_STEPS; do
  case " $steps " in *" $s "*) ;; *) continue ;; esac
  case "$skip" in *" $s "*) continue ;; esac
  "step_$s"
done
log "done ($steps )"
