# T15a — Bitstream to FASM (SDR)

**Status:** done · **Depends on:** T13 · **Parent:** [T15](T15-fpga-netlist.md)

## Goal
`tools/xc7_fasm.py` (stdlib `.bits` writer + prjxray `FasmDisassembler` wrapper + per-tile-type summary, `selftest`);
FASM in `build/sdr/`; FASM section of `docs/code/sdr/netlist.md`.

## Plan
See the parent [T15 plan](T15-fpga-netlist.md#plan). Concretely:
1. venv with prjxray's Python deps; add `artix7/mapping/` to the prjxray-db sparse checkout (prjxray's `Database` needs
   `mapping/devices.yaml`).
2. Frames from `tools/xc7_db.py` -> prjxray bitdata (same as `bitread -z -y` output) -> `FasmDisassembler` ->
   `fasm.output.merge_and_sort` (what `utils/bit2fasm.py` does after `bitread`).
3. Attribute unexplained bits to tile types; separate the frame ECC.
4. `summary`: FASM lines per tile type, PIP vs LUT INIT vs BRAM INIT vs site features.
5. `selftest`: `.bits` line format; round trip of 5 hand-placed segbits features (CLB LUT INIT, FF ZINI, INT PIP,
   DSP48 AREG, BRAM INIT on the BLOCK_RAM bus) through our frame addressing and prjxray's disassembler.

## Findings
Documented in [`docs/code/sdr/netlist.md` section 1](../code/sdr/netlist.md#1-bitstream-to-fasm-t15a).
- `python3 -I tools/xc7_fasm.py selftest` passes (5/5 features, 0 unexplained bits).
- Full image: 18 s, 549,354 FASM lines, 2,360,912 set bits; 24,224 frame-ECC bits; **407 bits (0.017 %) unexplained**
  (DSP 198, XADC 95, RIOB33 86, rest < 10 each) **[fact]**.
- 367,229 PIP features, 26,608 LUT INITs (= T13's count), 3,453 BRAM INIT lines **[fact]**.
- IOI: 10 IDDR + 12 ODDR in the right bank; left bank has plain outputs **[fact]**.

Installs (see T15 "Proposed shared-file edits" for the docs/tooling.md text): venv
`~/.local/share/ft710-tools/venv` (Python 3.11.2) with `fasm 0.0.2.post88`, `textX 4.4.0`, `Arpeggio 2.0.3`,
`simplejson 4.2.0`, `intervaltree 3.2.1`, `sortedcontainers 2.4.0`, `PyYAML 6.0.3` from PyPI; prjxray-db sparse
checkout extended with `/artix7/mapping/`.

## Follow-ups
- The 198 unexplained DSP bits and 86 RIOB33 bits are gaps in prjxray-db, not in our decode; check whether a newer
  prjxray-db covers them if a DSP option turns out to matter.
