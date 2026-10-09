# T14 — System-level documentation

**Status:** todo · **Depends on:** T09 T10 T11 T12 T13

## Goal
`docs/code/system.md`: how the whole radio fits together, built from the per-image docs.

## Deliverables
- A figure of the whole-radio block diagram (CPUs, FPGA, buses, USB/CAT path, SD card).
- Sequence diagrams: power-on boot of all CPUs, the firmware-update flow (SD → DISPLAY → MAIN/DSP/SDR), a CAT command round trip (PC → CP2105 → MAIN → other CPUs → reply), and a frequency change from the knob to the SDR.
- The inter-CPU protocol summary (message formats per link), linking to the per-image pages.
