# T09a — CAT core, reply/AI path, extended + hidden commands

**Status:** done · **Parent:** [T09](T09-cat-commands.md) · **Depends on:** T05

## Goal
Document how MAIN receives, parses, dispatches and answers CAT commands, and recover every extended/hidden command.

## Deliverables
- `docs/code/main/cat.md`: parser/dispatch `flowchart`, request/reply `sequenceDiagram`, function table, data structures and globals.
- `docs/cat-commands.md`: extended table (`SP EO E8 E9 FD KT PE ZZ VE JP`) and SP sub-commands, each classified read-only vs set with risk notes; reply templates, error reply, AI path, per-port behaviour.

## Plan
1. Core: receive ring (0x11FEB/0x11FEC), port id byte, `cat_parse`, `cat_dispatch`, `cat_dispatch_ext`, reply buffer 0x1C8E + length 0x1B788, error `?;`, send by port (`FUN_fffb1d12`), AI flags and the post-command AI hook, APO reset.
2. The second input path in `cat_parse` (ring at `FUN_fffb1d06`, only `E9`), via disassembly.
3. Each extended handler and the SP sub-command helpers (`FUN_fffa4e31 4e8f 4eed 50f9 520b 5284`, `FUN_fffb0532`), checksum helpers, SDR binary bridge (`FUN_fffa3226`).
4. Templates 0xFFF8F480..0xFFF8F5E4 and the small string tables after `cat_ext_mnemonics`.
5. Write the docs; commit.

## Findings
Full write-up: [code/main/cat.md](../code/main/cat.md), [cat-commands.md](../cat-commands.md#extended-table).

- **Receive path** [fact]:
  - SCI0/2/3 feed `cat_rx_complete`, which fills a 60-slot ring at 0x1E14C. Frames that start with E1/E9 go to a single-slot buffer at 0x1B78C instead.
  - `cat_parse` handles one command per main-loop pass.
  - Port id mapping: 1 = SCI3 (USB Enhanced), 2 = SCI0 (USB Standard), 3 = SCI2 (TUNER/LINEAR jack, CAT-3). That port 1 is CAT-1 and port 2 is CAT-2 is [inference].
- **Replies** [fact]:
  - Replies are built at 0x1C8E, with the length at 0x1B788.
  - The only error reply is `?;`, triggered by flag 0x464A. Sets do not answer on success.
- **AI** [fact]:
  - AI is enabled per port with 0x20B20..22.
  - `cat_ai_poll` @ 0xFFFDD797 runs about 70 change detectors after every parse and sends to every port that has AI on.
  - `cat_ai_holdoff` gives a 200 ms holdoff after a set.
  - Undocumented `FD` also has an AI detector.
- **Extended commands:**
  - `SP` is a service family [fact]:
    - SDR register r/w over SCI5 (`SPS`) and SCI4-device register r/w (`SPD`).
    - Raw ADC dump (`SPIR`).
    - Binary EEPROM byte r/w (`SPR`/`SPW`), the 0x4659 table (`SPN`), meters (`SPM`), and a commit to EEPROM (`SPAWE`).
  - The binary SP forms read their checksum length from RAM[len-2], a bug [fact], so they are probably dead in V01-12 [inference].
  - `E8`/`E9` dump and restore the 10665-byte settings image, obfuscated with a random key and carrying a 07 90 signature [fact].
  - `ZZPE0710xx` [fact]: `99` is a factory reset including EEPROM, `01` resets the settings, `00` sets mode flag 0x20BBE.
  - `JP0710` reads and writes the destination (region) code, then resets and restarts [fact]. Most likely this code sets the TX coverage [inference].
  - `FD` reads and sets band-memory frequencies [fact].
  - `PE` sets 18 byte parameters, most likely the parametric mic EQ [inference]. It has an uninitialized pointer for bad selectors [fact].
  - `EO` is still implemented, although 2306-C dropped it.
  - `KT` is ignored. `VE` needs P1, as in the 2306-C form [fact].
- **Not CAT:** `sdr_bridge_mode` (0xFFFA3226) is an SDR register bridge started from the DISPLAY link [fact].
- **Manual:** 2306-C (and 2211-A) became available mid-task, and the comparison is in cat-commands.md.

## Follow-ups
- Identify the SCI4 device (`SPD`) and the meaning of the `cfg105` table (0x4659) and of the ROM preset table 0xFFF88CD4 (T10).
- Confirm the RAM[len-2] checksum bug by inspecting low RAM 0x0000..0x0066 usage (stack depth) (T10).
- Meaning of `ZZ` mode 0x20BBE and of the restart codes 0x20B39 = 0x10/0x11 (T10, power/state machine).
- SCI receive framing for the 10 kB binary `E9` frame (how ';' inside the data is handled) — check the RXI/ERI ISRs.
