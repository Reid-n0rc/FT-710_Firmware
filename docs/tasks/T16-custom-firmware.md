# T16 — Custom-firmware groundwork

**Status:** todo · **Depends on:** T04, T11c

## Goal
Prepare everything needed to build and run the owner's own patches safely, without writing to the radio. Background and
evidence: [custom firmware feasibility](../custom-firmware.md).

## Deliverables
- `tools/sfl_encode.py` (stdlib): plaintext → SFL (43-byte key, salted CRC-32, tag line, comment box), with a round-trip
  test against all four shipped images (decode → encode must reproduce the original file byte for byte).
- The update loader's full acceptance rules (tag, length, version, per-image steps), together with T11c.
- A first harmless patch (e.g. a version or banner string in DISPLAY or MAIN), produced as an SFL and verified by
  decode, CRC check and an analysis diff. **Not flashed.**
- A written plan (for owner approval) to enable the DISPLAY USB-keyboard debug console (`debug_unlock` 0x20107E68,
  magic 0xA0B9C8E7 at 0x20450000), via a patch or a JTAG RAM write.
- A JTAG-only (volatile) "hello" bitstream plan for the SDR FPGA: pin and clock constraints from
  `docs/code/sdr/interfaces.md`, what is safe to drive, and the rollback (power cycle).
- The list of debug adapters needed for each recovery path.

## Notes / hints
- **Anything that writes to the radio needs the owner's explicit approval each time.**
- Never publish decoded or patched images.

## Plan
_(fill in before starting)_

## Findings
_(fill in as you go)_

## Follow-ups
