# T15b — FASM to cell-level netlist (SDR)

**Status:** done · **Depends on:** T15a · **Parent:** [T15](T15-fpga-netlist.md)

## Goal
`tools/xc7_netlist.py` (stdlib): cells (LUT INIT, FF, CARRY4, DSP48E1, BRAM, IOB, MMCM, BUFG) and nets via active PIPs
over `tileconn.json`; JSON netlist in `build/sdr/`; `selftest` on a hand-built FASM case.

## Plan
See the parent [T15 plan](T15-fpga-netlist.md#plan). Lazy node building from tileconn, union-find over nodes joined by
FASM PIPs and `always` pseudo-PIPs, site mapping by tile_type site coordinates (prjxray `_Y{y%2}` rule for IOB/IOI/
DSP/RAMB18), a SLICE BEL model, hard blocks kept as site-level cells with features as parameters.

## Findings
Documented in [`docs/code/sdr/netlist.md` section 2](../code/sdr/netlist.md#2-fasm-to-cell-level-netlist-t15b).
- `selftest` passes: a hand-built FASM toggle flop (LUT6 `!A1` -> FDRE, AQ routed back to A1 through 4 INT PIPs) gives
  the expected cells, params, constants and connectivity.
- Full design: 63,824 cells, 134,639 nets, **no multi-driver net**, LUT and FF counts equal T13's exactly **[fact]**.
- Pitfalls fixed: site-through `always` pseudo-PIPs (BUFHCE) merged the clock nets; `PRECYINIT.C0` is a default in
  carry-free slices; IMUX wires default to VCC; LUTs without INIT bits are constant 0 **[fact]**.
- T13 correction: the DSP `Z*REG` bits mean "register = 0" (prjxray fuzzer), so 55 DSPs have MREG = 0 and 9 have
  PREG = 0; 12 use the pre-adder (`USE_DPORT`) **[fact]**.

## Follow-ups
- `USE_MULT` of DSP48E1 is not in prjxray-db; decide from routing (A/B connected) in T15d, or fuzz it.
- O5 halves of SRL16/RAM32 pairs: DI2 source assumed to be the X bypass pin; verify against UG474 Figure 2-x.
- `docs/code/sdr/resources.md` (T13) should get the DSP register correction (parent/T13 owner: the T15 task may edit
  sdr pages other than README, done in T15c).
