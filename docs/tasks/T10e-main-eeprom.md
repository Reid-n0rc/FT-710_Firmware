# T10e — MAIN EEPROM, data flash and settings persistence

**Status:** done · **Depends on:** T05 T09 · **Parent:** [T10](T10-docs-main.md)

## Goal
Document this MAIN (RX651) subsystem per the AGENTS.md documentation standard.

## Deliverables
- `docs/code/main/` page(s): eeprom.md. Each page starts with "Back to the [MAIN overview](README.md)" and has function tables
  (`| Address | Ghidra name | Inferred name | Purpose |`), data structures, globals and Mermaid figures (≤ ~25 nodes).
- Proposed Ghidra names in `tools/ghidra/names_main.T10e.tsv` (same format as `names_main.tsv`); the parent merges them
  into `names_main.tsv`, applies them and re-exports `decomp/main`.

## Scope
The EEPROM driver (BR25G256 SPI or bit-banged; locate it), data flash use (0x100000), the settings/memory image at 0x60C9 (E8/E9 dump, 10665 bytes) and its layout, EEPROM address map (e.g. 0x000A table, 0x010F destination code), save/restore and factory-reset paths (ZZ).

## Plan
1. Read the EEPROM driver (`eeprom_read/write/spi_tx/rx`, T05 names) and confirm the port-E pins and the address-byte quirk in the disassembly.
2. List every caller of the driver and of the `eeprom_save_*` wrappers (Ghidra xrefs, `tools/ghidra/T10eXrefs.java`), derive the EEPROM address map from the (EEPROM addr, RAM addr, length) triples, and check that it tiles.
3. Search for data-flash (0x100000..0x107FFF) and FACI/flash-register use (PeriphRefs scalar search).
4. Follow the boot load (`app_main` → loader), the header/dirty flag logic, power-off and power-fail saves, and the factory-reset paths (ZZ, JP, DISPLAY link, `FUN_fffd02f9`).
5. Map the 0x60C9 image (E8/E9) and the other blocks as far as the code shows (channel record layout, menu block), using the CAT handlers that read them.
6. Write `docs/code/main/eeprom.md` (function tables, address map, figures), propose names in `tools/ghidra/names_main.T10e.tsv`, commit.

## Findings
Full write-up: [docs/code/main/eeprom.md](../code/main/eeprom.md).
- **Driver.** The EEPROM is a bit-banged SPI device on PE0 (/CS), PE5 (SCK), PE6 (MOSI) and PE7 (MISO), with 64-byte page writes. At boot `FUN_fffb01f3` writes WRSR = 0x80 with P65 driven high (P65 is probably /WP). No RSPI and no SCI6 is involved. **[fact]**
- **No data flash.** No code references 0x00100000..0x00107FFF or the FACI/flash registers. The only scalar hits are PSW masks. **[fact]**
- **RAM mirror.** RAM 0x464F..0x9E85 mirrors EEPROM 0x0000..0x5836 (RAM = 0x464F + EE). The full address map tiles with no gaps: header, `cfg105` calibration table, dest code, 2×3×12 band-stack records, band-stack indices, memory header + 133 channels, QMB, message/keyer/text slots, 100-entry tuner memory, and the operating-state/menu block. **[fact]** for the layout; the block meanings are partly **[inference]**.
- **Boot load.** Header byte 9 is a "write in progress" flag. Value 1 loads the whole mirror. Value 0 (a save was interrupted) keeps only cal + dest and loads defaults. Any other value runs a full factory init. There is no checksum. **[fact]**
- **When it saves.** Small records are saved when they change (memory channels, band stack, QMB, keyer text, tuner memory). The full save runs only through the restart/power-off request (0x20F4B, `FUN_fff98797`), and that ends in an RX software reset (SWRR). The power switch saves only the operating-state block, and ZZ00 mode suppresses even that. A power fail (ADC 0x20B08 < 0x7DD) saves the opstate block once and then inhibits all record saves. **[fact]**
- **E8/E9 scope.** The image is the memory header + 117 channels. E9's EEPROM write (0x2F49 bytes) also rewrites the 16 60-m/EMG channels from RAM. **[fact]**
- **Calibration and ZZ00.** `cfg105` (EE 0x000A) is the factory alignment table: TX power interpolation and SWR/meter constants. `ZZPE071000;` is the alignment mode: `cal_adjust` edits `cfg105[0x20CE2]`, and a key press saves the table. **[inference]**
- **Decoder bug.** The RX SLEIGH module decodes `MOVU.B/W Rs,Rd` (0x5B/0x5F, ld=11) as a memory load. This hits 107 instructions in 49 functions. Because of it, T09's "binary SP checksum bug" is not real: the checksum length is `len-2`. **[fact]**
- **Names.** 31 names proposed in `tools/ghidra/names_main.T10e.tsv`. New helper scripts: `tools/ghidra/T10eXrefs.java` (references to addresses or ranges) and `tools/ghidra/T10eMovuRegCount.java`.

## Follow-ups
- **Fix the RX SLEIGH module.** In `rx62t.sinc`, `movu_ldu_src` with `mode_ld = 0x3` must be the register zext, not `[reg4_4]`. Then re-run the analysis and re-export `decomp/main`, since 107 sites in 49 functions change. Check the other images' RX use: DISPLAY is ARM, so only MAIN is affected.
- **Correct the T09 docs.** Fix `docs/code/main/cat.md` and `docs/cat-commands.md` (SP checksum section): SPR/SPW/SPM/SPN/SPA have a valid checksum over `len-2` bytes and are usable, which raises their risk.
- **T10g:** the full 90-byte record field map and the menu-block (0x9A2A..0x9C34) field map; the latter goes with T10f.
- **T10h:** confirm ADC AN002 = supply voltage, P65 = EEPROM /WP (schematic), and the tuner-memory semantics of 0x1B3AD/0x1B3AF.
- **T10b:** the DISPLAY startup codes in `FUN_fff9546a` (0x01 reset, 0x05, 0x07 region swap, 0x10 auto power-on).
- The meaning of message type 0 (0x93A7, 5 × 0x98 from 0x120BC).

## Proposed shared-file edits
- `docs/code/main/cat.md`, section "Binary SP checksum bug": replace it with a note that `MOVU.W [R2],R2` at 0xFFFA3867/38C4/39BB/510A is a decoder artifact (bytes `5F 22` = `MOVU.W R2,R2`), so `n = len-2` and the checksum is a normal 8-bit sum over the frame without the sum byte and `;`. Remove the "unusable in V01-12" claims. In the function table, change the `eeprom_save_image`/`settings_defaults` rows to link to eeprom.md.
- `docs/cat-commands.md`: the same correction wherever the SP checksum bug is mentioned. Raise SPR/SPW/SPN/SPA to "usable, high risk".
- `decomp/main/INDEX.md`, under "Known decompiler artifacts": add "`MOVU.B/W Rs,Rd` (0x5B/0x5F) is shown as a memory load `[Rs]` (107 sites; `tools/ghidra/T10eMovuRegCount.java`)".
- `docs/memory-maps.md` (MAIN): mark 0x00100000 data flash as **unused** (no references). Add RAM 0x464F..0x9E85 = EEPROM mirror (RAM = 0x464F + EE addr) with a link to eeprom.md.
- `docs/hardware.md` (MAIN): EEPROM BR25G256 on PE0/PE5/PE6/PE7, bit-banged; P65 probably /WP.
- `docs/tooling.md`: record the RX module MOVU defect next to the module entry.
- `tools/ghidra/names_main.tsv`: merge `names_main.T10e.tsv`. `timer_start`/`timer_expired` may collide with other sub-tasks' names for 0xFFFB237A/0xFFFB23F3.
