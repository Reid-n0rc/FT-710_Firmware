Back to the [MAIN overview](README.md)

# MAIN — EEPROM, settings persistence and resets

Sub-task T10e. The page covers the EEPROM driver, the address map, the boot load, what triggers a save, and the reset paths.
Names are the current Ghidra names in `ghidra/FT710_MAIN`. Function names are the names applied in Ghidra (`tools/ghidra/names_main.tsv`, merged by T17) and match `decomp/main/`; a name still in *italics* is a description that was not applied as a Ghidra name. Tags follow AGENTS.md: **[fact]** means seen in code or data at the address given.

## Summary

- **One chip, bit-banged.** All settings live in one SPI EEPROM, the BR25G256 from the service manual (32 KB, 64-byte pages). The chip hangs on port E GPIOs, and the CPU clocks it in software, so no RSPI or SCI is involved. **[fact]** for the driver, **[inference]** for the part number.
- **No data flash.** The R5F56514 has no E2 data flash at all (datasheet Table 1.3, T18), and MAIN never touches 0x00100000 or the flash sequencer. **[fact, scalar-reference search]**
- **RAM mirror.** RAM **0x464F..0x9E85** is a byte-for-byte mirror of EEPROM **0x0000..0x5836** (22,583 bytes): `RAM = 0x464F + EEPROM address`. Every save call passes the pair (EEPROM `a`, RAM `0x464F + a`, `n`). Code reaches the mirror through the base 0x464F plus an offset (about 3,650 references to 0x464F). EEPROM 0x5837..0x7FFF is never read or written, except by `SPR`/`SPW`. **[fact]**
- **No checksum.** The image has no checksum. Its only integrity guard is a "write in progress" flag in the 10-byte header, together with a 32-bit save counter. **[fact]**
- **No timed autosave.** The firmware writes small blocks when a record changes (memory channel, band stack, QMB, keyer text, tuner memory). It writes the whole image only when the radio is going down: a restart or power-off request, the power switch, or a power fail. **[fact]**

```mermaid
flowchart LR
  subgraph EE["BR25G256 SPI EEPROM (32 KB)"]
    H["0x0000 header"]
    CAL["0x000A cal table 0x105"]
    DST["0x010F dest code"]
    REST["0x0112..0x5836 settings"]
  end
  DRV["eeprom_read / eeprom_write<br/>PE0 CS, PE5 SCK, PE6 MOSI, PE7 MISO"]
  EE <--> DRV
  DRV <--> RAM["RAM mirror 0x464F..0x9E85<br/>(RAM = 0x464F + EE addr)"]
  RAM --> E8["CAT E8 dump 0x60C9 (10665 B)"]
  E9["CAT E9 restore"] --> RAM
  SPN["CAT SPN / SPAWE"] --> CAL
  JP["CAT JP"] --> DST
  ZZ["CAT ZZ 99/01"] --> DEF["settings_defaults"]
  DEF --> RAM
  PD["power-down / restart<br/>power_down_save"] -->|eeprom_save_all| DRV
```

## EEPROM driver **[fact]**

| Signal | Pin | Register |
|---|---|---|
| /CS | PE0 | PORTE.PODR 0x8C02E bit 0 (low = selected) |
| SCK | PE5 | PORTE.PODR bit 5 (idle low; data is set up, then SCK goes high then low; mode 0) |
| MOSI (SI) | PE6 | PORTE.PODR bit 6 |
| MISO (SO) | PE7 | PORTE.PIDR 0x8C04E bit 7 |
| /WP | P65 **[inference]** | PORT6.PODR 0x8C026 bit 5. It is driven high only around the status-register write in `eeprom_init` |

- **Bit order.** Bytes are shifted MSB first, with no delays. The bit rate is set by the code speed alone.
- **Instructions used** (the standard 25-series set): `0x03` READ, `0x02` WRITE, `0x05` RDSR, `0x06` WREN, `0x01` WRSR.
- **`eeprom_read`.** It sends `03 aH aL` and then clocks in n bytes. It does **not** poll WIP first. Only boot and `SPR` read, so this does not matter in practice. **[inference]**
- **`eeprom_write`.** It splits the data at 64-byte page boundaries. For each chunk it polls RDSR until WIP = 0, then sends WREN, then `02 aH aL` + data. It does not wait after the last page: the next write's RDSR poll covers that. **[fact]**
- **Addresses are 16 bit.** The decompile drops the middle `eeprom_spi_tx()` argument, which is the address high byte (`MOVU.W 0xa[SP],R1; SHLR #8,R1` at 0xFFFB14BA and 0xFFFB1566). It also types the address as a byte. **[fact, disassembly]**
- **Boot init `eeprom_init`** (`eeprom_init`), called from `app_main` before the load:
  1. /CS high, SCK low, P65 high.
  2. WRSR with the value **0x80**: SRWD = 1, BP1:0 = 00, so no array protection.
  3. P65 low.

  If P65 is /WP, the status register is then locked while the whole array stays writable. **[inference]**

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFFB15AA | `eeprom_spi_tx` | | Shift one byte out on PE6 **[fact]** |
| 0xFFFB15EF | `eeprom_spi_rx` | | Shift one byte in from PE7 **[fact]** |
| 0xFFFB14A4 | `eeprom_read` | | `READ` + 16-bit address, n bytes **[fact]** |
| 0xFFFB14ED | `eeprom_write` | | Page-split write with WIP poll and WREN **[fact]** |
| 0xFFFB01F3 | `eeprom_init` | `eeprom_init` | Port setup and WRSR 0x80 **[fact]** |
| 0xFFFB063E / 0xFFFB0651 | `eeprom_read_raw` / `eeprom_write_raw` | `eeprom_read_raw` / `eeprom_write_raw` | Plain wrappers used only by `cat_SP_eeprom_byte` (SPR/SPW) **[fact]** |

## EEPROM address map **[fact unless marked]**

Derived from every `eeprom_read`/`eeprom_write` call (19 call sites). The blocks tile 0x0000..0x5836 with no gaps.

| EEPROM | RAM | Size | Block | Written by |
|---|---|---|---|---|
| 0x0000 | 0x464F | 10 | **Header**. Bytes 0..4: a 5-byte date/time stamp (0x20BB1..5 from `DT`, BCD yy mm dd hh mm), copied in by `JP` set; the tested radio holds 23 06 26 08 56 (`JP0710;` read, 2026-10-28) **[fact, radio]**. Bytes 5..8: a big-endian save counter. Byte 9: state flag (0 = write in progress, 1 = clean) | `eeprom_hdr_update` (twice per save) |
| 0x000A | 0x4659 | 0x105 | `cfg105`: the **factory alignment table**, 261 one-byte items that the firmware's own alignment menu names (`001 [GN] VDD MTR` … `261 [TX] IDD MTR`, ROM 0xFFF817C3) **[fact]**. Full map in [cfg105: the alignment table](#cfg105-the-alignment-table-fact). ROM defaults at `cfg105_defaults` 0xFFF8074F | `eeprom_save_cfg105`: SPAWE, ZZ99, first-boot init, a key in ZZ00 mode (0xFFFBFD76) |
| 0x010F | 0x475E | 3 | **Destination code** (u16 BE 0x475E, default 0x8043) + flag 0x4760, which DISPLAY startup code 5 toggles | `eeprom_save_dest`: JP, ZZ99, `dest_code_set`, first boot |
| 0x0112 | 0x4761 | 3×0x438 | **Band stack, VFO-A**: 3 slots × 12 bands × 90-byte VFO record. Address = 0x0112 + slot·0x438 + band·0x5A | `eeprom_save_bandstack` `eeprom_save_bandstack` |
| 0x0DBA | 0x5409 | 3×0x438 | **Band stack, VFO-B**, same layout | same |
| 0x1A62 | 0x60B1 | 0x18 | Band-stack slot index per band: 12 for A (0x60B1), 12 for B (0x60BD) | `eeprom_save_opstate` |
| 0x1A7A | 0x60C9 | 0x87 | **Memory header**: 0x60C9 = VFO-A channel, 0x60CA = VFO-B channel, 0x60CB..0x614F = 133 "channel valid" bytes | `eeprom_save_memch`, `eeprom_save_image` |
| 0x1B01 | 0x6150 | 133×0x5A | **Memory channels**, 90 bytes each: index 0..98 = 001..099, 99..116 = P1L..P9U, 117..131 = 501..515 (60 m), 132 = EMG | `eeprom_save_memch(ch)`: EEPROM 0x1B01 + ch·0x5A |
| 0x49C3 | 0x9012 | 0x11 + 10×0x5A | **QMB** (quick memory bank) **[inference]**: header 0x9012..0x9022 (count 0x9014, order 0x9015[10], A/B pointers 0x901F..0x9022), then 10 records at 0x9023 (5 or 10 used, set by 0x9AC0) | `eeprom_save_qmb` / `eeprom_save_qmb_slot` |
| 0x4D58 | 0x93A7 | 5×0x98 | **Message memory type 0**: u16 length + 150 bytes = a **CW keying bitstream** (#148). `keyer_task` loads it into the keyer's element buffer 0x120BC (a 1,200-bit ring; `FUN_fffbb024` appends 1 bit per mark unit, 3 for a dash, 0 for a space; position 0x1FA38) **[fact]**; that the stored messages are recorded from the paddle is **[inference]** | `eeprom_save_msg`(0,n)` |
| 0x5050 | 0x969F | 5×0x33 | **Keyer memory text** (`KM`): length + 50 characters | `eeprom_save_msg`(1,n)`: `cat_KM`, the menu editor `FUN_fffe481d` |
| 0x514F | 0x979E | 5×0x32 | **Text slots** (`EM`). Never saved on their own, only by the full save | `eeprom_save_msg`(2,n)` (no caller) |
| 0x5249 | 0x9898 | 0x192 | **Tuner memory** **[fact]** (#148): write index 0x9898, count 0x9899, 100 × {u16 frequency key, 0x1B3AF, 0x1B3AD}. The key is the top four BCD digits of the frequency in Hz (`FUN_fffb4135`), i.e. 10 kHz steps: 0x1420 = 14.20 MHz. 0x1B3AD/0x1B3AF are two of the three internal-tuner relay bytes that `atu_relay_update` sends on /SST6 (getters `FUN_fffec500`/`FUN_fffec50f`); a successful tune copies the search values 0x1B3AE/0x1B3B0 into them (`FUN_fffed12f`), and `atu_mem_store` keeps them per frequency so a later tune can start from them. **Both stored bytes are capacitor banks; the third byte is the L bank** (#166): see [Internal tuner relay bytes](#internal-tuner-relay-bytes-166) | `eeprom_save_atu_mem` from `atu_mem_store` |
| 0x53DB | 0x9A2A | 0x45C | **Operating state**: menu values (0x9A2A.., defaults from ROM 0xFFF80E4A.. at the same offset), PE parameters 0x9ADA, screen-saver time 0x9B0F (menu 040104), band memories 0x9C69/0x9C99, VFO-A record 0x9D09, VFO-B record 0x9D63, active VFO 0x9DBD, VFO states 0x9DBE/0x9DBF, bands 0x9DC3/0x9DC4, auto-power-on flag 0x9DC5, memory backups 0x9DCE/0x9E28. The block ends at 0x9E85 | `eeprom_save_opstate` `eeprom_save_opstate` |

Sizes check: 0x0112 + 2·0xCA8 = 0x1A62; 0x1B01 + 133·0x5A = 0x49C3; 0x49C3 + 0x395 = 0x4D58; … 0x53DB + 0x45C = 0x5837. **[fact]**

### The E8/E9 image (RAM 0x60C9, 10,665 bytes) **[fact]**

`E8` dumps **0x60C9..0x8A71**. A dump from a radio (2026-10-28) had exactly this length, signature and a correct sum, and it is byte for byte the same as EEPROM 0x1A7A.. read with `SPR` on the same radio, which confirms the mirror mapping **[fact, radio]** ([cat-commands.md](../../cat-commands.md#radio-checks)). That is the 0x87-byte memory header plus **117 channel records** (001–099 and P1L–P9U): 0x87 + 117·0x5A = 0x29A9.

`E9` copies the same 10,665 bytes back and calls `eeprom_save_image`. That function writes **0x2F49** bytes (0x60C9..0x9011), so it also rewrites the 16 records of the 60 m/EMG channels (0x8A72..0x9011) from RAM. Those records are not part of the transfer and are left as they were.

The E8/E9 clone therefore carries memories only. Menus, band stacks, calibration and the destination code are not included.

### 90-byte VFO / memory record

VFO-A (0x9D09), VFO-B (0x9D63), memory channels, band-stack slots and QMB slots all share one 90-byte layout. Known offsets **[fact from the CAT handlers, T09]**:

| Offset | Field |
|---|---|
| +0x00 | Low nibble = mode (index into `cat_mode_codes`). High nibble: no reader (#205, below) |
| +0x01 | Bits 3/4: clarifier RX/TX flags. Bit 2: internal ATU on (`AC`). Bit 7: memory-scan **SKIP** (#205) |
| +0x02 | Bits 2–3: repeater shift. Bit 1: **NB on** (#205) |
| +0x03 | Bits 0–1: **ATT** (#205). Bits 3–5: tone/CTCSS mode |
| +0x05 | Bits 0–1: **preamp** IPO/AMP1/AMP2 (#205). Bit 7: name-tag on |
| +0x0B, +0x15, +0x1F, +0x29, +0x33, +0x3D | Six per-mode-class blocks of 10 bytes. Byte 0 is a 5-state per-mode selector, and bytes +7/+8 are a signed 16-bit value (`IS`); see cat-commands-primary.md |
| +0x48 | s16 clarifier offset |
| +0x4A | u32 frequency in Hz (big-endian) |
| +0x4E | 12-character name |

More fields **[fact]** (#73):

| Offset | Field |
|---|---|
| +0x04 | NARROW flags per mode class (`cat_NA`, `key_nar_short`): bit 7 SSB (modes 0/1), bit 5 CW (2/3), bit 3 RTTY (0xC/0xD), bit 2 DATA (8/9/0xE). AM and FM have no flag: NAR switches the mode itself (AM ↔ AM-N, FM ↔ FM-N, DATA-FM ↔ D-FM-N, `FUN_fffc4bd5`). `align_load_preset` also sets bit 4 from preset flag 0x08; bit 4 has no reader in MAIN (#205) **[fact for the scanned forms]** |
| +0x06 | bits 0–3 = DNR level 1..15 (`RL`, `cat_RL` 0xFFFADA46), bit 4 = DNR on (`NR`, `key_dnr_short`); bits 5–7 unused (#161) |
| +0x07..+0x09, +0x47 | no users in MAIN (#161). The defaults write 0, except that the band-stack defaults (`FUN_fffb0779`, a u16 store of 1 at record +0x08 of band 10) give the **50 MHz** band-stack records **+0x08 = 1**. The owner's dump shows exactly that in the four untouched 50 MHz slots (A and B, levels 1 and 2) **[fact: code + dump]** |
| +0x3C..+0x45 | the FM / DATA-FM per-mode block, same layout as the others (#161) |

Defaults (`defaults_memch`) write the first 8 bytes as `0x80040040`, `0x00010200`, `0x0000`. The 20 bytes from +0x46 come from ROM 0xFFF80947, or from 0xFFF80B4F.. for the dest-specific 60 m channels. The full field map, the per-mode block layout and its defaults are in [radio-control.md](radio-control.md#the-0x5a-byte-channel-record).

### Menu block 0x9A2A..0x9C34 (EEPROM 0x53DB..0x55E5) **[fact]** (#73)

`tools/main_menu_table.py` gives the RAM address of all 314 menu items; they cover 362 of the block's 523 bytes. The rest:

- **Menu cursors.** The 2-byte holes after each group (0x9A3D, 0x9A50, 0x9A65, 0x9A7C, 0x9A8F, 0x9AA5, 0x9AB3, 0x9ACF, 0x9AD7, 0x9AEC,
  0x9AF7, 0x9AFF, 0x9B12, 0x9B18, 0x9B1E, 0x9B22..0x9B2D, 0x9B4B, 0x9B6A, 0x9B89, 0x9BA8, 0x9BC7) hold the `{top, row}` cursor of each P2
  group. The menu works on a RAM copy at 0x12238.. (`menu_cursor_of` returns the group's pair). `FUN_fffd405e` copies the block into it
  in `menu_subsys_init`, and `FUN_fffd3d03` copies it back before the power-off save (`io_task`, `supply_undervolt_check`). So the menu
  reopens where it was left. 0x9AF2 is the only byte nothing references.
- **0x9BC9..0x9C34**, after the last preset: the front-panel values that are not menu items. Each is used by the CAT command named:

| RAM | CAT / users | Value |
|---|---|---|
| 0x9BC9 | `menu_defaults_presets`, `FUN_fffc4d93` (per-port refresh) | preset selection **[inference]** |
| 0x9BCA, 0x9BD8 | `FUN_fff9c6ab`, `FUN_fffb13e2` | not traced |
| 0x9BE6..0x9BE8 | `SS` | scope settings |
| 0x9BE9, 0x9BEA | `DA` | dimmer / display |
| 0x9BEC..0x9BEF | `MG`, `tx_mod_gain` | MIC GAIN, 4 values (per mode class) |
| 0x9BF0, 0x9BF1 | `PR`, `PL`, `dsp_set_peq_*`, `dsp_set_proc` | processor on/level, parametric EQ |
| 0x9BF2 | `AO`, `dsp_set_amc_level` | AMC output level |
| 0x9BF3 | `VG`, `dsp_set_vox_gain` | VOX gain |
| 0x9BF4, 0x9BF5 | `VD`, `ptt_arbiter` | VOX delay (u16) |
| 0x9BF6, 0x9BF7 | `AV`, `dsp_set_antivox` | anti-VOX |
| 0x9BF8..0x9BFB | `PC`, the MAX POWER `on_draw` callbacks (EX030401..04) | RF power, 4 values (per band group) |
| 0x9BFC..0x9C00 | `ML` | monitor level / on |
| 0x9C02 | `KR`, `keyer_task` | keyer on |
| 0x9C03 | `KS`, `keyer_task` | key speed |
| 0x9C04 | `KP`, `dsp_set_cw_pitch`, `beep_task`, `sdr_upd_r08/r18` | CW pitch |
| 0x9C05 | `SD`, `FUN_fffbaa81` (keyer TX) | CW break-in delay |
| 0x9C06, 0x9C09..0x9C0F | `AS1` (`FUN_fffb54a0` returns the pointer for the current mode), `dsp_set_aess`, `speaker_route`, `sdr_upd_r16_filter` | **AESS level** per mode: SSB 0x9C06, CW 0x9C09, DATA 0x9C0A, RTTY 0x9C0B, DATA-FM 0x9C0C, PSK 0x9C0D, AM 0x9C0E, FM 0x9C0F; `AS1` = byte × 5 **[fact, #157]** |
| 0x9C07, 0x9C10..0x9C16 | `AS2` (`FUN_fffb552c`), `dsp_set_aess` | **AESS centre** per mode (0 = 700 Hz, 1 = 1000 Hz), same mode order **[fact, #157]** |
| 0x9C08 | `SF`, `displink_build_37` | sub-dial (FUNC knob) function |
| 0x9C17..0x9C34 | `menu_defaults_load` | 30 bytes copied from ROM 0xFFF80FD6, which are all 0 (the "0x1E" in the old reading of this row is the copy length). No other reference **[fact]**; all 0 in the owner's dump |

The "Value" column comes from the CAT command's meaning in [cat-commands.md](../../cat-commands.md) **[inference for the per-byte split
of multi-byte entries]**. The AESS bytes 0x9C06..0x9C16 are reached only through the pointers that `FUN_fffb54a0`/`FUN_fffb552c`
return, so a search for direct references misses them; that is why this page used to say 0x9C09..0x9C34 had no users.

**Flag bits checked in #205** (a scan of every pointer taken from `vfo_rec_ptr`, the working records 0x9D09/0x9D63, the memtune
backups 0x9DCE/0x9E28, the record arrays 0x4761/0x5409 (band stack), 0x6150 (memories) and 0x9023 (QMB), and the absolute bytes
0x9D0A..0x9D0E / 0x9D64..0x9D68):

| Bits | Meaning | Readers and writers **[fact]** |
|---|---|---|
| +0x02 bit 1 | **NB on** | `cat_NB` 0xFFFACC65 (read `NB0n`, set/clear), `key_nb_short` 0xFFFBE96B / `key_nb_long` 0xFFFBE9D6 (via 0x9D0B/0x9D65), `sdr_upd_r1a_nb_level` 0xFFFA1FD1 (SDR reg 0x1A = 0 while it is clear), the AI reporter `FUN_fffdfe7a` |
| +0x03 bits 0–1 | **ATT**: 0 off, 1 6 dB, 2 12 dB, 3 18 dB (`RA0n`, CAT manual) | `cat_RA` 0xFFFAD718; `rf_bpf_update` 0xFFFB56A5 turns it into the /SST3 bits (0 → 0x18000, 1 → 0x8000, 2 → 0x10000, 3 → none) |
| +0x05 bits 0–1 | **Preamp**: 0 IPO, 2 AMP1, 3 AMP2 (1 reads back as IPO) | `cat_PA` 0xFFFAD001; `rf_bpf_update` (0 → 0x20000, 3 → 0x40000, 1/2 → none); `FUN_fffc47dd` steps IPO → AMP1 → AMP2 → IPO (the IPO key **[inference]**), `FUN_fffc4850` sets IPO; `displink_build_30` sends it to the DISPLAY; `FUN_fffb9605`, `FUN_fffe00be` (AI) read it. The defaults write +0x05 = 0x02, i.e. **AMP1** |
| +0x01 bit 7 | **memory-scan SKIP** | `FUN_fffe5e3b` 0xFFFE5E3B (memory channel *n*: 0x6151 + *n* × 0x5A bit 7), used through `FUN_fffe5e1b` (current channel) by the memory-scan steps `FUN_fffe5d8f` (up) / `FUN_fffe5dd5` (down), which step again while the channel is marked, and by `FUN_fffe5c26`; `FUN_fff99ca2` writes `SKIP` or `SCAN` into the memory-list row; `displink_build_41` sends it with the tag bit (+0x05 bit 7) |

So the bits `align_load_preset` copies from its preset row (0xFFF88CD4 + 12·item, byte 1) are **ATT** (+0x03 bits 0–1) and **preamp**
(+0x05 bits 0–1): each alignment step sets the front end it needs **[fact]**. The owner's +0x05 bits 0–1 = 2 or 3 are AMP1/AMP2, and
+0x02 bit 1 is NB on in the bands where it is set **[fact: code + dump]**.

Still without a reader **[fact for the forms scanned above]**: the **high nibble of +0x00**, **+0x01 bit 0**, **+0x04 bit 4** and
+0x03 bits 6–7 (the defaults write +0x03 = 0x80). No V01-12 code writes +0x00 bits 4–7 or +0x01 bit 0 either: every mode setter
(`cat_MD`, `cat_MW`, `FUN_fffc0eb8`, `FUN_fffc6ac4`, `align_load_preset`) keeps the high nibble (`& 0xF0 | mode`), and only the
defaults and whole-record copies (band stack, QMB, memory, clone, SD MEM LIST LOAD) move the byte. So the owner's values (bit 7 clear,
bit 6 mostly clear, +0x01 bit 0 set) were written by something outside this code: an earlier firmware, the E8/E9 clone or an SD memory
list **[inference]**. The disassembly search (#205, 2026-10-29, `rx-elf-objdump` of the whole image) confirms the
decompile **[fact]**:

- `tools/rx_const_refs.py` on 0x9D09..0x9D0A and 0x9D63..0x9D64 finds, apart from reads, only these writes to +0x00/+0x01 of
  the operating records: `defaults_vfo` (32-bit copy from the ROM template 0xFFF80875), `cat_MD`, `FUN_fffc0eb8` and
  `align_load_preset` (all `& 0xF0 | mode` on +0x00), the whole-record copies (`smovf`, 90 bytes) of `memch_load_to_vfo`
  0xFFFC26B4/0xFFFC26D0 (and the other whole-record copies named above), and `& 0xE7` on +0x01 in `memch_load_to_vfo`, `vm_toggle_core` and `cat_CF`
  (`cat_CF` then ORs in bits 3–4, the clarifier; `key_clar_short` sets bit 4). None sets +0x01 bit 0 or +0x00 bits 4–7.
- Every `BSET`/`BCLR`/`BNOT #0, 1[Rn]` in the image (19) is on an I/O register (base 0x87xxx) **[fact]**. Of the 235
  `BSET`/`BCLR #4..7, [Rn]` whose base is not a constant I/O address, most are in the menu value formatters
  (0xFFFC9694..0xFFFD30xx, display text buffers) and I/O drivers (`bu2505_write`, `af_mute_update`, ...); the ones on record
  pointers hit other offsets: the per-mode filter byte (`vfo_filter_byte_ptr` 0xFFFC4B3D returns record +
  0x0B/0x15/0x1F/0x29/0x33/0x3D, used by `FUN_fffc49c1`/`FUN_fffc4a47`; `FUN_fffc0ad4` gets the same pointers), +0x06 in
  `key_dnr_long` (0x9D0F/0x9D69), +0x01 bit 4 in `key_clar_short`, +0x14.. in `FUN_fffc8685`/`FUN_fffc87ab`, and the
  filter bytes in `cat_BC`, `cat_BP`, `cat_CO`, `cat_GT` **[fact for the sites named; the formatter and driver sites were
  classified by function, not one by one]**.
- The ROM holds the 0x01 form only in the 60 m memory-channel templates (32-bit words 0x80040101 at 0xFFF809FB, 0xFFF80B45,
  0xFFF80C17, 0x80040103 at 0xFFF80A05, 0x80040109 at 0xFFF80A0F; EMG 0x80040003 at 0xFFF80C35); every other template is
  0x800400*mm* with *mm* = 0x40/0x42/0xC1 **[fact]**.

So in V01-12 the form can reach an operating record only by a whole-record copy from a record that already holds it
**[fact]**, and the only ROM source is the 60 m channel defaults **[fact]**. In the owner's dump the VFO-A memory pointer is on
a 60 m channel **[fact: dump]**, which fits a memory recall copying a 60 m channel into VFO-A **[inference]**. How 21 band-stack
records and the ordinary memory channels got the form too is not answered by the code: a chain of such copies, or a write from
outside (an earlier firmware, the E8/E9 clone, an SD memory list) **[inference]**. A dump from a radio factory-reset under
V01-12 would separate the two; the meaning of the bits stays open (no reader).

Names added to `tools/ghidra/names_main.tsv` for #205 (they appear in `decomp/` after the next Ghidra re-export; this page still uses
the current `FUN_` names): `preamp_step` 0xFFFC47DD, `preamp_ipo` 0xFFFC4850, `memch_skip_get` 0xFFFE5E3B, `memch_current_skip`
0xFFFE5E1B, `ver_main_ext1` 0xFFF94BD9, `ver_main_ext2` 0xFFF94BE5, `ver_display_date_set` 0xFFF94C1B; and (2026-10-29)
`vfo_filter_byte_ptr` 0xFFFC4B3D plus the data labels `@s_meter_curve` 0xFFF88BFC, `@po_meter_curve` 0xFFF88C74 and
`@tx_row_ptrs` 0xFFF8861C.

## cfg105: the alignment table **[fact]**

(#203.) The 261 bytes at RAM 0x4659 (EEPROM 0x000A..0x010E) are the items of the factory **alignment mode**, one byte per item.
MAIN holds the menu labels itself: a table of 261 × 25 characters at **ROM 0xFFF817C3** (`" 001 [GN] VDD MTR        "` …
`" 261 [TX] IDD MTR        "`), which `displink_build_62` sends to the DISPLAY nine lines at a time, each with its value
(`FUN_fff9c555`) **[fact]**. Item *n* is byte 0x4659 + *n* − 1, `SPN` index *n* and the label "*nnn*"; the store handler is
0xFFF89910[*n* − 1] and the set-up preset is 0xFFF88CD4[*n* − 1] (`align_load_preset`). The service manual's alignment chapter
(FT-710 Technical Supplement, "ALIGNMENT-1..9") uses the same labels and numbers, and enters the mode by holding **[BAND] + [QMB] +
[NAR]** at power-on **[fact: manual]** — the DISPLAY boot code 0x02 in [display-link.md](display-link.md#f0-boot-codes)
**[inference]**. `tools/eeprom_decode.py` prints the table from a dump, with the ROM default next to each value (`--main`).

| Items (RAM) | Label | Read by | ROM default | Owner's radio (dump 2026-10-28) |
|---|---|---|---|---|
| 001 (0x4659) | `[GN] VDD MTR` | `vdd_scale_calc`; stored from AN003 `PA_VDD` >> 4 (`align_store_ui4`, manual: 13.8 V supply, press the DSP knob) | 200 | 193 |
| 002 (0x465A) | `[GN] FAN` | `pa_dac_update`: fan DAC on while the `PA_HF_TH` reading is below it, off above it + 10 | 180 | 195 |
| 003 (0x465B) | `[GN] REF FREQ` | `main_dac_update`: Q1005 ch3 `FADJ` = (item − REF FREQ menu 0x9AC6) × 4; `cal_adjust` clamps it to 25..230 (manual: 250.000000 MHz ± 20 Hz at TP1005) | 128 | 96 |
| 004 (0x465C) | `[GN] TX INH` | `tx_freq_allowed`: TX refused when non-zero | 0 | 0 |
| 005..007 | `[GN] --RESERVED--` | none | 0xFF | 0xFF |
| 008 (0x4660) | `[GN] DBG MODE ENABLE` | `displink_build_60` (frame `0x60` error field = 0xDB: the DISPLAY shows a link-error box instead of resetting), `menu_m4_18_0_draw` (SOFT VERSION shows build strings); see the notes | 0 | 0 |
| 009..013 (0x4661..) | `[MT] PO MTR 100W/50W/20W/10W/5W POS` | **none**: no instruction reads them except the generic menu-text, `SPN` and save paths; `meter_po` uses a fixed ROM curve with the same five positions instead (#205, notes) | 197 139 89 63 46 | same |
| 014..016 (0x4666..) | `[MT] ALC / VDD / IDD MTR POS` | `meter_alc`, `vdd_scale_calc`, `meter_idd`; 014 also scales the `ALC MTR` store (245) | 146 210 175 | same |
| 017..019 (0x4669..) | `[MT] SWR 1.5 / 2.0 / 3.0 MTR POS` | `swr_meter_protect` | 60 90 128 | same |
| 020..022 | `[MT] --RESERVED--` | none | 0xFF | 0xFF |
| 023..027 (0x466F..) | `[RX] RF-AGC 7 / 14 / 21 / 28 / 50` | `main_dac_update`: Q1005 ch5 by RX band (manual: set to 255) | 255 | 255 × 5 |
| 028..032 (0x4674..) | `[RX] IF-AGC 7 / 14 / 21 / 28 / 50` | `dsp_set_freq_range_param` → IFDSP reg 0x63, the IF AGC gain ceiling ([dsp-chains.md](../ifdsp/dsp-chains.md)); manual: −2.0 dB ± 0.5 dB of AF at 10 dBµV | **0** | 190 190 189 188 199 |
| 033..043 (0x4679..) | `[RX] S-MTR 0, 2, 5, 7, 9, +10 … +60` | only 041 (`S-MTR +40`, 0x4681) is read: `meter_s` and `FUN_fffb7e61`; the other ten are never read (#205 disassembly scan, notes): `meter_s` uses a fixed ROM curve whose breakpoints are these ten defaults; all 11 are stored from `dsp_signal_level` | 8 33 74 101 125 140 158 177 198 216 255 | 255 247 74 101 125 140 158 177 **127** 216 87 |
| 044, 045 | `[RX] --RESERVED--` | none | 0xFF | 0xFF |
| 046..048 (0x4686..) | `[RX] FM SQL THW / THN / TI` | `FUN_fffb7cec` (FM squelch); stored from a DSP status read (`align_store_dsp_async`) | 127 37 46 | 126 34 80 |
| 049 (0x4689) | `[RX] SCOPE SDR REF` | `sdr_upd_r27_scope_level` | 170 | 170 |
| 050..058 (0x468A..) | `[TX] MF / HF / VHF PREDR, DRIVE, FINAL BIAS` | `pa_dac_update`: PA DAC Q4041 ch5 `PBIAS` / ch4 `DBIAS` / ch3 `FBIAS`, by band group (`FUN_fffb3337`: 0 = MF, 1..5 = HF, else VHF) | **0** | 168 197 187 / 169 196 196 / 170 196 195 |
| 059..069 (0x4693..) | `[TX] I-ALC 1.8 … 50, 70` | `pa_dac_update`: Q4041 ch10 `IALC` by TX band (manual: 110 W, 60 W on 70 MHz) | 80 | 181 166 169 170 161 171 168 163 156 179 167 |
| 070..219 (0x469E..0x4733) | `[TX] 100W/50W/20W/10W/5W FALC / MTR / TXG <band>`, 15 items per band for 1.8, 3.5, 7, 10, 14, 18, 21, 24, 28, 50 MHz | **FALC** (+0, +3, …): `FUN_fffb667a` interpolates it by power → Q4041 ch2 `FALC`. **TXG** (+2, +5, …): `sdr_upd_r25_tx_drive` interpolates it → SDR reg 0x25. **MTR**: only the 100 W one is read (`FUN_fffb667a` → 0x20B1E, the PO-meter scale of `meter_get_po`); it is stored from AN002 `MCUP_FOR` >> 4 (`align_store_ui2`) | FALC 175 115 62 37 19, MTR 193 140 94 70 52, TXG 192 136 86 61 43 | 14 MHz: FALC 194 131 72 41 22, MTR 82 140 94 70 52, TXG 88 56 37 27 20. Across the ten bands: 100 W FALC 167..196, 100 W MTR 72..82, 100 W TXG 87..164 (1.8 and 50 MHz highest) |
| 220..222 | `[TX] --RESERVED--` (no 100 W on 70 MHz) | none | 0xFF | 0xFF |
| 223..234 (0x4737..0x4742) | `[TX] 50W/20W/10W/5W FALC / MTR / TXG 70` | as above for band index ≥ 10 (pointer table 0xFFF8861C entry 10); `50W MTR 70` is the PO scale there | as the HF defaults | aligned values (not the defaults) |
| 235..245 (0x4743..) | `[TX] REV ALC 1.8 … 50, 70` | `pa_dac_update`: Q4041 ch1 `RALC` by TX band (manual: 50 W into 16.6 Ω) | 50 | 38 43 45 37 45 43 49 42 42 45 7 |
| 246 (0x474E) | `[TX] ALC MTR` | `meter_alc` divisor; stored as AN005 `ALCM` × item 014 / 137 (`align_store_ui8_scaled`) | 128 | 27 |
| 247..260 | `[TX] --RESERVED--` | none | 0xFF | 0xFF |
| 261 (0x475D) | `[TX] IDD MTR` | `meter_idd` divisor | 60 | 60 |

Notes **[fact unless marked]**:

- **The power points are 100, 50, 20, 10 and 5 W.** `FUN_fffb667a` interpolates between them with spans 50, 30, 10, 5; the span 30
  (20 → 50 W) was misread on this page as a "30 W" point. `align_load_preset` sets 100/50/20/10/5 W for items 070..219 and 50/20/10/5 W
  for 223..234, and the labels agree.
- **Only the 100 W `MTR` items are aligned.** The manual's procedure stores `100W MTR` and then adjusts `FALC` and `TXG` at each power;
  the owner's 50/20/10/5 W `MTR` values are exactly the ROM defaults, as are `PO MTR … POS`, the meter positions 014..019, `SCOPE SDR
  REF` and `IDD MTR`. Of the `S-MTR` points only 033, 034, 041 and 043 differ from the defaults, and only 041 is read.
- **Items that must be aligned have a ROM default of 0**: `IF-AGC` 028..032 and the nine bias items. A radio that falls back to
  `cfg105_defaults` (blank EEPROM, `ZZPE071099`) loses its bias and IF-AGC settings **[inference: the PA would run without bias until
  realigned]**.
- 162 of the 261 bytes in the owner's dump differ from the ROM defaults.
- **Items with no operating reader: settled, they are dead in V01-12** (#205, 2026-10-29). `PO MTR … POS` 009..013, the
  `S-MTR` points other than +40 (033..040, 042, 043) and the 50/20/10/5 W `MTR` items (row +4, +7, +10, +13 of 070..219,
  and 227/230/233 on 70 MHz, where the 50 W one, 224 = 0x4738, *is* the PO scale) are never read for operation **[fact:
  disassembly scan below]**.
  - **Method.** The decompile hides this question because CC-RX reaches every EEPROM-mirror byte through `mov.l #0x464F, Rn`
    plus a displacement (3638 such loads in the image; no other `mov.l #imm` of any size and no 32-bit data word anywhere
    holds an address in 0x4650..0x475E except the RAM-pointer init 0x4659 at 0xFFF8EB0C → `PTR_DAT_00025d50` and the TX-row table 0xFFF8861C).
    So a byte search for 0x4661 finds nothing even for items that are read. `tools/rx_const_refs.py` runs the data-xref
    search Ghidra would do on a GNU `rx-elf-objdump` listing of the image: it follows the base through register moves, stack
    spills and forward branches and resolves each `dsp[Rn]` and `[Ri,Rb]` operand **[fact: tool]**.
  - **Result for 0x4659..0x475D.** Every item named "read by" in the table above shows up with its reader (for example 027 and
    058 in `main_dac_update`/`pa_dac_update`, 041 in `meter_s` 0xFFFB7962 and `FUN_fffb7e61` 0xFFFB7E6A). No item listed
    above as dead has a single exact access, and the reserved items have none **[fact]**. The only accesses that can reach
    any item are generic, by item index: `FUN_fff9c555` 0xFFF9C569 (menu text, `[r2,r1]` with r2 = 0x4659),
    `cat_SP_table` 0xFFFA5179/0xFFFA51CE (`SPN`), `cat_SP_eeprom_byte` 0xFFFA527E, and the alignment-mode writers that use
    `PTR_DAT_00025d50` (`align_store_*`, `cal_adjust`, and `FUN_fffbba9f`, which writes only the `FALC` and `TXG` of a
    band row, +0 and +2). The pointer table 0xFFF8861C is read only by `sdr_upd_r25_tx_drive` 0xFFFA2A40, at row offsets
    +2, +5, +8, +11, +14 (the `TXG` items) **[fact: disassembly 0xFFFA2A58..0xFFFA2B20]**.
  - So aligned values in these items are stored and shown in the alignment menu but have no effect. The Ghidra data-xref
    listing confirms it: no reference at all to 0x4661..0x4665, 0x4679..0x4680, 0x4682, 0x4683 or the band-row `MTR` bytes
    0x46A2/A5/A8/AB + 15·*b* and 0x473B/3E/41; the code that keeps 0x4659 in a register and adds a constant (`main_dac_update`
    +22..+25, `pa_dac_update` +1, +49..+56, +58..+68, +234..+244, `FUN_fffb667a` the `FALC` and 100 W `MTR` offsets) was read in
    the listing too **[fact]**. `FUN_fffbba9f` is `align_ialc_park`: while an `I-ALC` item (059..069) is selected it saves that
    band's 100 W `FALC`/`TXG` (50 W on 70 MHz) to 0x12167/0x12168, sets them to 0xFF and restores them when the selection moves **[fact]**.
- **The fixed meter curves** (#205) **[fact: ROM bytes, little-endian `float`]**:
  - **PO** (`meter_po` 0xFFFB7772): P = x² · (P<sub>full</sub> − 0.00694025 · M) / M² + 0.00694025 · x, with x = AN002
    (0x20B06), M = 100 W `MTR` item << 4 (0x20B1E) and P<sub>full</sub> = 100 W (50 W when `FUN_fffb3371` returns 10, the
    70 MHz band), so P = P<sub>full</sub> at x = M. The position is slope · P + offset (clamped to 255) from the first row of
    the 8 × {watts, slope, offset} table at **0xFFF88C74** with P ≥ watts:

    | Row (address) | 0 (0xFFF88C74) | 1 | 2 | 3 | 4 | 5 | 6 | 7 (0xFFF88CC8) |
    |---|---|---|---|---|---|---|---|---|
    | P ≥ (W) | 100 | 50 | 40 | 30 | 20 | 10 | 5 | 0 |
    | slope | 1.18 | 1.16 | 1.3 | 1.6 | 2.0 | 2.5 | 3.6 | 9.2 |
    | offset | 78 | 80 | 73 | 61 | 49 | 39 | 28 | 0 |

    At 100/50/20/10/5 W this gives positions 196/138/89/64/46, within 1 of the `PO MTR … POS` defaults 197/139/89/63/46: the
    curve is those defaults (plus 40 and 30 W points) built into the code **[fact for the numbers; inference that the ROM
    defaults were the source]**.
  - **S** (`meter_s` 0xFFFB7959): x = item 041 (`S-MTR +40`) − `dsp_signal_level()` (reg 3 shadow 0x1B63A), position =
    slope · x + offset clamped to 0..255, from the first row of the 10 × {slope, offset, limit} table at **0xFFF88BFC** (limit
    at +8, 0xFFF88C04 + 12·i) with x ≤ limit; above the last limit the code keeps slope 1.95, offset 177:

    | Row | 0 (0xFFF88BFC) | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 (0xFFF88C68) |
    |---|---|---|---|---|---|---|---|---|---|---|
    | x ≤ | −120 | −104 | −92 | −80 | −60 | −40 | −20 | 0 | 20 | 40 |
    | slope | 5.5 | 2.563 | 2.25 | 2.0 | 0.75 | 0.9 | 0.95 | 1.05 | 0.9 | 1.95 |
    | offset | 693 | 340.5 | 308 | 285 | 185 | 194 | 196 | 198 | 198 | 177 |

    The segments join only in this order, and at the ten limits they give positions 33, 74, 101, 125, 140, 158, 177, 198,
    216, 255: exactly the ROM defaults of `S-MTR 2` … `+60` (034..043), with `+40` (198) at x = 0 **[fact]**. So the S-meter
    has one calibration point (041) and a fixed shape; S0 (033, default 8) is not on the curve (position 0 at x ≈ −126).
    The signal value falls as the signal rises (x grows with signal) **[inference: from the sign of x]**. The owner's
    aligned 034 and 043 sit exactly on the curve's limits relative to their 041: 034 = 041 + 120 and 043 = 041 − 40
    **[fact: dump]**, so the stored points agree with the fixed shape even though only 041 is used.
- **`DBG MODE ENABLE` (008, 0x4660)** (#205) **[fact]**:
  - `displink_build_60` 0xFFF96241: if UI +0x32 (0x20B36, the boot error code) is 0 and 0x4660 ≠ 0, it sends 0xDB in that field.
    The DISPLAY then sets 0x20450029, so on a MAIN-link failure `gui_link_error_popup` shows the unanswered command in hex instead of
    resetting the link ([display-link.md](display-link.md#boot-error-report)).
  - `menu_m4_18_0_draw` 0xFFFCD89B (SOFT VERSION): with 0x4660 ≠ 0 the MAIN row becomes `V01-12-` + 4 characters from ROM
    0xFFFFFF10 (`FUN_fff94bd9`) and 8 from 0xFFFFFF20 (`FUN_fff94be5`), and the DISPLAY row gets 8 more characters from
    `FUN_fff94c0f`. That getter returns 0x143C, the `"yy-mm-dd"` date `displink_rx_F0_hello` builds from hello bytes 4..6 (stored by
    `FUN_fff94c1b`); the decompile shows it as `void`, the pattern of its neighbours (`ver_display` 0x1436 / setter 0xFFF94BFD)
    gives the address **[inference]**. So the DISPLAY row reads `V01-08  23-06-29`. The MAIN ROM holds `"2101"` at 0xFFFFFF10 and `"24-02-16"` at 0xFFFFFF20
    (after `"V01-12"` at 0xFFFFFF00), so the MAIN row reads `V01-12-2101 24-02-16` **[fact: MAIN image]**. `24-02-16` is the release
    date: the SFL header of the same file says `[DATE] : 2024/02/16` **[fact: FT-710_MAIN_V0112.SFL header]**. Open: what `2101`
    encodes; would be settled by a second MAIN release to compare, or the dev string in Yaesu's tools.
  - Nothing else reads it, and nothing but `SPN`, the alignment menu and the defaults writes it. It is a factory/debug display flag,
    not a hidden feature switch **[inference]**.
- The alignment item numbers of this table replace the earlier readings "per-band TX power calibration" (sdr-link.md, cat.md) and
  "per-band DSP calibration" (dsp-link.md) with their names.

## Internal tuner relay bytes (#166)

`atu_relay_update` shifts 24 bits MSB first on /SST6 as `[0x1B3AF][0x1B3AD][0x1B3B1]` (`shreg_write24`(5, …)) **[fact]**. The PA
schematic (Technical Supplement p47, PA unit) shows where they go **[fact: schematic]**:

- /SST6 strobes **Q4030 BU2152FS**, a 24-bit serial-in parallel-out driver (SDAT0/SCLK0 shared). Its outputs P1..P8 are `LX0..LX7`,
  P9..P16 `AC0..AC7`, P17..P24 `TC0..TC7`. Each drives a DTC114EU transistor and one FTR-F3AA012E relay:
  - `LX0..LX7` → relays `L0..L7` (RL4017, RL4021, RL4024, RL4028, RL4031, RL4034, RL4037, RL4040): the **L bank**. Each relay
    has contact ② on one tap of the inductor string and contact ① on **ground** (#205, re-read at 800 dpi). The string runs from the
    capacitor common node through L4052, L4053 … L4059, L4060 and L4061 to ground, with relay L*k* on the tap after the (*k*+1)-th
    inductor (L0 after L4052, L7 after L4059). So the L bank is a **shunt inductor** from the common node to ground, and the first
    closed tap from that node sets its value; it is not a series string with shorted coils **[fact: schematic]**.
  - `AC0..AC7` → relays `C0..C7` (RL4041 … RL4018) and `TC0..TC7` → relays `C8..CF` (RL4042 … RL4019): two **capacitor banks**, each
    switching binary-weighted pairs of 3 kV SL capacitors (C7 and CF: 2 × 150 pF; the smallest steps are about 10 pF). Each column
    is relay contact ① on the bank's bus, contact ② on a capacitor pair, and the pair's other end on one **common node**, shared by
    both banks (the line between the two capacitor rows) and joined to L4052 **[fact: schematic]**. Each bank is therefore a
    capacitor in **series** between its bus and the common node.
- **Bit order.** The /SST4 register Q4040 (same part, same bus) shows the mapping: `pa_relay_update` bit 7 (internal ATU in line),
  bit 8 (AM), bit 9 (RX line) and bit 10 land on Q4040 P8 `TNRON`, P9 `TAM`, P10 `RX` and P11 `4m`, so word bit *n* drives output
  P(*n* + 1) **[fact: code bits vs. schematic labels]**. Applied to /SST6: **0x1B3B1 (bits 0–7) = `LX` = L bank, 0x1B3AD (bits 8–15)
  = `AC` = C0..C7, 0x1B3AF (bits 16–23) = `TC` = C8..CF** **[inference, strong: same part and bus]**.
- **Network: a high-pass T** (#205) **[inference, strong: schematic trace]**. The `TC` bus (contacts ① of RL4019 … RL4042) runs down
  the left edge to contact ② of RL4016 (G5Q-14), whose contact ⑤ is on the line that comes from the left, from the PA low-pass
  filters past the C4575/C4576 sampler, i.e. the **transmitter side**. The `AC` bus (contacts ① of RL4018 … RL4041) runs down the right edge to contact ② of
  RL4020 (G5Q-14), whose common goes through RL4027 (FTR-B4SA012Z) to the C4537/C4538 coupling capacitors and the **ANT** jack: the
  **antenna side**. Contacts ⑤ of RL4016 and RL4020 are joined, which is the bypass path (tuner out); both coils hang on the `TUNER`
  net **[fact for the wiring; which contact is the rest position is not printed]**. So the tuner is TX — C(`TC`, 0x1B3AF) — node —
  C(`AC`, 0x1B3AD) — ANT, with the shunt L (`LX`, 0x1B3B1) from the node to ground. The bus label `ANTS` on the same drawing is a
  separate net that leaves the bus towards the transistor circuit near Q4072..Q4076; it is not either bank's bus, and it was not
  followed to its end **[fact: schematic; purpose open]**. The trace was read from 400–800 dpi renders of p47 (`pdftoppm -r 800 -x … -y …`).
- **The L bank is not searched.** `FUN_fffed12f` sets 0x1B3B1 from ROM **0xFFF87BF1**[0x1B3BB]. 0x1B3BB is `FUN_fffb3371`(TX
  frequency), the 11 TX ranges of the power table (upper limits at 0xFFF8870C: 2.1, 4.7, 7.5, 11.5, 14.5, 20.9, 22, 25.5, 41.5, 60,
  75 MHz, i.e. 1.8, 3.5, 5–7, 10, 14, 18, 21, 24, 28, 50, 70 MHz). The bytes are 00, 80, C0, E0, F0, F8, FC, FC, FE, FF, FF **[fact]**.
  0xFF and 0xFE leave only L4052 (tap L0 closed) or L4052 + L4053; 0x00 (1.8 MHz) leaves the whole string. One more tap closes per
  range step, from the ground end towards the node, so the shunt inductance falls with frequency **[inference: values × schematic]**. The tune
  search steps only the two capacitor bytes (0x1B3AE → 0x1B3AD, 0x1B3B0 → 0x1B3AF), from the per-range table at 0xFFF87BFC ({max,
  start, step, fine step}; max 239, 174, 88, 71, 54, 53, 36, 36, 28, 28, 28) **[fact]**.
- So the tuner memory stores **the two C banks**, and the old question "which byte is L and which is C" has the answer: neither
  stored byte is L. `TC` (0x1B3AF, `[0x1B3AF]` first on the wire) is the **transmitter-side** series capacitor and `AC` (0x1B3AD) the
  **antenna-side** one (#205; previously read from the net names alone) **[inference, strong: schematic trace above]**. The trace that remains
  open is the rest position of RL4016/RL4020/RL4027, which only matters for which state is "tuner in"; a continuity check on the PA
  board (with the owner's approval, radio unpowered) or a clearer copy of p47 would settle it.
- **Dump check.** The owner's tuner memory is full (count 100, write index 24, so the ring has wrapped). Both bytes use the whole
  range their band allows (TC 0..126, AC 0..86; both fall roughly as 1/f, correlation 0.96 and 0.93) and every stored value is
  below its band's search maximum; 15 entries are (0, 0), i.e. no switched capacitor in either bank. No byte behaves like a smaller bank, which fits
  two 8-relay capacitor banks **[fact: dump]**.

## Check against the owner's dump (2026-10-28)

(#203.) The owner's dump (`tools/cat_backup.py --eeprom`, two identical reads; the `E8` image equals EEPROM 0x1A7A.. byte for
byte) was decoded with `tools/eeprom_decode.py`. Only structure and calibration/settings values are given here; frequencies,
memory tags and messages are personal data and stay out of the repository.

**Re-run with the MAIN image (#205, 2026-10-29):** `python3 -I tools/eeprom_decode.py --main build/FT-710_MAIN_V0112.bin
<dump>` reports `ROM name table 0xFFF817C3: matches` (all 261 labels as the tool has them) and `checks: ok` in all seven
sections (header, cfg105, band stacks, memory channels, QMB/messages, tuner memory, operating state); 162 of the 261 items
differ from `cfg105_defaults`, as above **[fact: tool output]**.

**Agrees with this page [fact: dump]:**

- Header: stamp 23 06 26 08 56, save counter 312,810, state flag 1 (clean). Destination 0x50E2 (the `JP` reply), flag 0x4760 = 0
  (TTBF unlock off).
- All 261 `cfg105` bytes are in range; every `--RESERVED--` item is 0xFF; `TX INH` and `DBG MODE ENABLE` are 0.
- Band stacks: 72 records, every mode nibble valid, every frequency inside its band, tone numbers ≤ 49, clarifier 0, tags blank;
  +0x06 bits 5–7, +0x07, +0x09 and +0x47 are 0 everywhere. Current levels 0x60B1/0x60BD are all 0.
- Memory header: the 133 valid flags are 0/1 only (1 regular channel and the 15 destination 60 m channels are valid; the other
  records hold the defaults). QMB: header and all ten records zero (never used). CW message memories: length 0.
- Keyer texts (`KM`): a length byte ≤ 50 and space padding. Text slots (`EM`): 50 bytes, the text ends with **0xFE**, then spaces;
  an empty slot starts with 0xFE **[fact: dump; new detail]**.
- Operating state: active VFO A, both VFO states 1 (VFO), 0x9DC5 = 0 (the last power-off was a normal one), the AESS centre bytes are
  0 (700 Hz) and the AESS levels ≤ 20; 0x9C17..0x9C34 all 0.

**Disagreed, and fixed on this page:**

- The band-stack defaults do not leave +0x08 at 0 in every record: the 50 MHz records get +0x08 = 1 (code and dump, above).
- 0x9C17 is not a single byte with default 0x1E; 0x9C09..0x9C16 are not unused (the AESS bytes).
- The TX power points are 100/50/20/10/5 W, not 100/50/30/10/5 W.
- The `IF-AGC` items 028..032 really do default to 0 in ROM (`cfg105_defaults` 0xFFF8074F + 0x1B..0x1F); the owner's values are
  190/190/189/188/199.

**New [fact: dump; meanings tagged inference or left open as marked]:**

- **Mode byte +0x00, bits 4–7.** The defaults write 0x40 (0xC1 in the USB band-stack defaults). In the dump, the band-stack records
  that differ from their default have bit 7 clear; bit 6 is clear in 21 of the 23 and still set in 2 whose mode was changed (for
  example a default USB record now in DATA-U with high nibble 4). Only the default writers set these bits, and the mode setter
  `FUN_fffc0eb8` keeps them (`rec[0] = rec[0] & 0xF0 | mode`); no V01-12 code reads them (#205, [above](#90-byte-vfo--memory-record))
  **[fact]**. The meaning is open.
- **+0x01, +0x02, +0x05** in used records: +0x01 = 0x05 (bit 2, the ATU flag read by `AC`, and bit 0), +0x02 bit 1 set in some
  bands, +0x05 bits 0–1 = 2 or 3 **[fact for the values]**. Settled in #205: +0x02 bit 1 is **NB on** and +0x05 bits 0–1 the
  **preamp** (2 = AMP1, 3 = AMP2) **[fact: `cat_NB`, `cat_PA`]**; +0x01 bit 0 has no reader in V01-12 and stays open (its only
  writers are the defaults, next item).
- **The +0x00 high nibble and +0x01 bit 0 never occur together** (#205 re-check of the same dump, 2026-10-29, all 90 records in use:
  72 band-stack, 16 memory channels, the two operating records 0x9D09/0x9D63) **[fact: dump]**. Exactly the 38 records whose high
  nibble is 0 have +0x01 bit 0 set (21 band-stack, 15 memory, both operating records); the other 52 have high nibble 4 (20) or
  0xC (32) and bit 0 clear. The ROM defaults come in the same two forms **[fact]**, as one 32-bit store of bytes +0x00..+0x03:
  - `FUN_fffb0779` (band-stack defaults) and `defaults_vfo` @ 0xFFFB06E5 (0x9D09 = 0x80040040) write 0x800400*mm* with
    *mm* = 0x40/0x42/0xC1: high nibble 4 or 0xC, +0x01 = 0;
  - `defaults_memch` @ 0xFFFB0A8F writes 0x80040040 for the ordinary channels, but 0x80040101 / 0x80040103 / 0x80040109 for
    the 60 m channels 501–515 (USB / CW-U / DATA-U at 0x8A72.., 0x5A apart) and 0x80040003 for EMG (0x8FB8): high nibble 0, with
    +0x01 bit 0 set except at EMG.
  Mode changes keep both fields, so the two forms look like one property of the record's origin that later copies carry along,
  not two independent flags **[inference]**. The operating records can get the 0x01 form only by a whole-record copy (memory
  recall and the like) from a record that holds it; the disassembly search is in the
  [flag-bit section above](#90-byte-vfo--memory-record) **[fact]**.
- Other bits across the same 90 records **[fact: dump]**: ATT (+0x03 bits 0–1) is 0 and memory-scan SKIP (+0x01 bit 7) is clear
  everywhere; the preamp is only ever 2 (79) or 3 (11), never the 1 that reads back as IPO; +0x03 bits 6–7 are 2 everywhere,
  as every default writes (+0x03 = 0x80); +0x04 bit 4 is 0 everywhere. NB is on in the VFO-A level-0 band stacks of every band
  except 3.5 and 10 MHz. DBG MODE ENABLE (item 008, 0x4660) is 0.
- AESS: the owner's levels are SSB 15, CW 14, DATA 15, AM 10, FM 17 (`AS1` 75/70/75/50/85), RTTY/DATA-FM/PSK 0. The ROM defaults
  (0xFFF80F6D + 0x3C.., the table `FUN_fffb13e2` copies to 0x9BCA..0x9C16) are SSB/AM/FM 10, the rest 0. Where the level acts:
  [peripherals.md](peripherals.md#speaker-routing-speaker_route-0x20fcc-fact).

## Boot load **[fact]**

`app_main` calls `eeprom_init` and then `eeprom_load_all` before any other subsystem starts.

```mermaid
flowchart TD
  A["app_main"] --> I["eeprom_init eeprom_init<br/>WRSR 0x80"]
  I --> L["eeprom_load_all: read header<br/>EE 0..9 → 0x464F"]
  L --> F{"header byte 9<br/>(0x4658)"}
  F -->|1 clean| ALL["read EE 0..0x5836<br/>→ RAM 0x464F (whole mirror)"]
  F -->|0 save was interrupted| PART["read cal 0x000A + dest 0x010F only<br/>settings_defaults(0)"]
  F -->|other, e.g. 0xFF blank| NEW["zero header<br/>settings_defaults(1)<br/>save cal + dest"]
  PART --> MARK["0x20B45 = 1"]
  NEW --> MARK
  ALL --> WAIT["wait for power-on (0x20B3A)"]
  MARK --> WAIT
  WAIT --> Q{"0x20B45 == 1?"}
  Q -->|yes| SAVE["eeprom_save_all eeprom_save_all<br/>(writes the defaults)"]
  Q -->|no| RUN["subsystem init, main_loop"]
  SAVE --> RUN
```

- **Interrupted save.** A save cut off by a power loss leaves flag 0. The next boot then throws away all user settings and keeps only the calibration table and the destination code. **[fact]**
- **Blank EEPROM.** A blank or foreign EEPROM gets a full factory init: ROM calibration defaults and destination 0x8043. **[fact]** A blank part on a repaired board therefore loses its alignment data, and 0x8043 becomes the default region. **[inference]**
- **Save counter.** `eeprom_hdr_update(f)` increments the counter in header bytes 5..8, stores f in byte 9 and writes the 10-byte header. Every block save calls it twice, f = 0 before the block and f = 1 after it, so the counter grows by 2 per save. **[fact]**

## Save triggers **[fact unless marked]**

The per-record savers (`eeprom_save_memch`, `eeprom_save_bandstack`, `eeprom_save_qmb_slot`, `eeprom_save_msg`, `eeprom_save_atu_mem`) first call `supply_undervolt_check`, and they skip the write when it returns 1. The block savers (`eeprom_save_cfg105`, `eeprom_save_dest`, `eeprom_save_image`, `eeprom_save_all`, `eeprom_save_opstate`, `eeprom_save_qmb`) do not check it.

| Saver | EEPROM | Callers / trigger |
|---|---|---|
| `eeprom_save_all` `eeprom_save_all` | 0x0112..0x5836 | `app_main` after defaults were loaded (0x20B45). `power_down_save` `power_down_save`, run by `displink_tx_schedule` when the restart/power-off request 0x20F4B = 1 is set: `PS0`, ZZ, JP, `dest_code_set`, power fail and menu reset all set it |
| `eeprom_save_opstate` `eeprom_save_opstate` | 0x53DB + 0x1A62 | `io_task` (main loop) when 0x20B30 == 2, i.e. the power switch is off **[inference]**, **unless ZZ00 mode is on** (0x20BBE). Also `supply_undervolt_check` on a power fail |
| `eeprom_save_image` | 0x1A7A, 0x2F49 | `cat_ext_E9` only |
| `eeprom_save_memch(ch)` | 0x1A7A (0x87) + channel | CAT `AM BM MC MT MW CH`, and UI paths `FUN_fffc54cc` (channel step), `FUN_fffc71c7`, `FUN_fffc6ac4/6b34/6b86`, `FUN_fffc1fb6`, `FUN_fffc2b94`, `FUN_fffc4064`, `FUN_fffe273a` |
| `eeprom_save_bandstack` `eeprom_save_bandstack` | band-stack record | `bandstack_save` `bandstack_save`. It compares the active VFO record with its slot (`FUN_fffede1d`, 90-byte memcmp) and writes only on a change. Called from `FUN_fffc17df`/`FUN_fffc184f` (band change) **[inference]** |
| `eeprom_save_qmb` / `eeprom_save_qmb_slot` | QMB | Boot `qmb_boot_init`, `FUN_fff9513c` (pending slot 0x20F83), `qmb_enter`, `FUN_fffc506b`..`FUN_fffc515d` (QMB record flag edits) |
| `eeprom_save_msg` `eeprom_save_msg` | message/keyer text | `cat_KM`, the menu text editor `FUN_fffe481d`, the message recorder in `keyer_task` (main loop) |
| `eeprom_save_atu_mem` `eeprom_save_atu_mem` | 0x5249 | `atu_mem_store` `atu_mem_store`, called by the tuning loop `FUN_fffec8a1`/`FUN_fffecde6` when the SWR is ≤ 1.1 **[inference]** |
| `eeprom_save_cfg105` | 0x000A | `SPAWE`, ZZ99, first boot, and a key in ZZ00 mode (0xFFFBFD76, not inside a defined function) |
| `eeprom_save_dest` | 0x010F | `dest_code_set` (JP, DISPLAY startup code 7, `dest_jumper_apply`), ZZ99, first boot |
| raw byte | any | `SPW` (`cat_SP_eeprom_byte`) |

### Power-down, restart and power fail

```mermaid
sequenceDiagram
  participant SRC as PS0 / ZZ / JP / reset / power fail
  participant ST as 0x20F4B, 0x20B39
  participant DL as `displink_tx_schedule` (DISPLAY-link scheduler)
  participant PD as `power_down_save` power_down_save
  participant EE as EEPROM
  SRC->>ST: 0x20F4B=1, 0x20B39 = 0x10 (PS0) / 0x11 (reset) / 0x90 (power fail)
  DL->>PD: next pass sees 0x20F4B==1
  PD->>PD: build frame 0x1456.., `displink_tx_start`(0xB) (shutdown notice to DISPLAY, inference)
  alt code 0x90 (opstate already saved by supply_undervolt_check)
    PD->>PD: wait timer 0x14 (2 s)
  else code 0x11 (restart)
    PD->>EE: 0x9DC5=1 (power back on), eeprom_save_all
  else other (PS0)
    PD->>EE: 0x9DC5=0, eeprom_save_all
  end
  PD->>PD: `sw_reset`: PRCR=0xA502, SWRR=0xA501 (software reset)
```

- **Restart is a CPU reset.** "Power off" and "restart" are both an RX651 **software reset** (`sw_reset` writes SWRR = 0xA501). After the reset, `app_main` waits for power-on, as on a cold boot. 0x9DC5, which is saved in the opstate block, tells the DISPLAY-link startup (`displink_rx_F0_hello` case 0x10) whether to power straight back on. **[fact]** for the reset, **[inference]** for the meaning of 0x9DC5.
- **Power fail** (`supply_undervolt_check`, `supply_undervolt_check`):
  - It fires when ADC result 0x20B08 drops below **0x7DD**. 0x20B08 is **AN003 `PA_VDD`**, the 13.8 V supply: `adc0_store` 0xFFFB27FB stores `R_S12AD0_Get_ValueResult(3, 0x20B08)` **[fact]**, and the p17 schematic names AN003 `PA_VDD` ([peripherals.md](peripherals.md#adc-s12ad-unit-0-at-0x89000-unit-1-at-0x89100)). (Corrected by T19h: this line used to say "AN002 in the `SPIR` order"; AN002 is `MCUP_FOR` at 0x20B06, and 0x20B08 is SPIR field 4.)
  - It acts only once, latched by 0x20B43.
  - It calls `power_off_io`, sets 0x9DC5 = 1, calls `FUN_fffd3d03` and saves the opstate block. The save runs only if soft timer 0x13 has expired; `trx_init` starts that timer with 2.5 s at power-on.
  - Then it requests the reset with code 0x90.
  - From then on, `supply_undervolt_check` returns 1, and every per-record save is skipped. **[fact]**

## Defaults and factory reset **[fact unless marked]**

`settings_defaults(full)` 0xFFFB0558. With `full == 1` it first copies `cfg105_defaults` → 0x4659, sets 0x4760 = 0 and sets destination 0x475E = 0x8043. Then, in both cases:

| Step | Function | Effect |
|---|---|---|
| 1 | `defaults_vfo` `defaults_vfo` | VFO-A/B records 0x9D09/0x9D63 and 0x9DBD = 0. For dest 0x020B/0x4380/0x60E6, byte +0x46 = 8 |
| 2 | `defaults_bandstack` `defaults_bandstack` | Clears 0x4761..0x60C8 and fills the 6 band-stack sets (`FUN_fffb0779`, dest-dependent) |
| 3 | `defaults_qmb` `defaults_qmb` | Clears 0x9012..0x93A6 |
| 4 | `defaults_memch` `defaults_memch` | Clears 0x60C9..0x9011. Channel 1 is marked valid. Sets default records for 117 channels and dest-specific 60 m channels (e.g. dest 0xD950) |
| 5 | `defaults_msg` `defaults_msg` | Clears 0x93A7..0x9897 and loads the keyer texts from ROM 0xFFF80C53/0xFFF80C86/0xFFF80CB9 |
| 6 | (inline) | Clears the tuner memory 0x9898 (0x192). Copies ROM 0xFFF80D82 → 0x9C69 (0xA0) and 0xFFF80E22 → 0x9C35 (0x28) |
| 7 | `menu_defaults_load` `menu_defaults_load` | Menu values 0x9A2A..0x9C16 from ROM 0xFFF80E4A.. (`menu_defaults_mode`..`FUN_fffb13e2`, piecewise: the cursor bytes are skipped, the presets get their names, and 0x9BCA..0x9C16 come from a separate 0x4D-byte table), and 0x9C17..0x9C34 ← 30 zero bytes from 0xFFF80FD6 |
| 8 | (inline) | 0x9C5D..0x9C65, then clears 0x9DBE..0x9E85 and copies 0xFFF80FC6 → 0x9DBE (0x10) |

`settings_defaults` changes RAM only. The EEPROM is updated by the full save in the restart that follows, or by the first-boot save. **[fact]**

| Path | Code | What is reset | EEPROM write |
|---|---|---|---|
| CAT `ZZPE071099;` | `cat_ext_ZZ` 0xFFFA58A1 | **Everything**, including the calibration table and the destination code (→ 0x8043) | cal + dest at once; the rest by the restart save |
| CAT `ZZPE071001;` | same | All settings except calibration and destination | restart save |
| CAT `ZZPE071000;` | same | Nothing. It sets 0x20BBE = 1, which is **alignment (service-adjust) mode** **[inference]**: key codes < 8 and 0x16..0x19 are blocked, a key saves `cfg105` (0xFFFBFD76), `cal_adjust` edits `cfg105[0x20CE2]`, and the power-switch opstate save is suppressed. `EO` clears it | cfg105 on key |
| CAT `SPN R/W/S`, `SPAWE` | `cat_SP_table`, `cat_ext_SP` | `SPN R` selects calibration item idx (0x20CE2) and tunes to its ROM test frequency (`FUN_fffbb567`, 12-byte records at 0xFFF88CD4). `W` sets the value in RAM. `SPAWE` commits the table | cfg105 |
| CAT `JP0710…` | `cat_ext_JP` → `dest_code_set` | Destination code, then `settings_defaults(0)` and a restart. It also stamps the date/time 0x20BB1..5 into header bytes 0..4 | dest at once; the rest and the header by the restart save |
| Menu reset | `menu_reset_exec` → `reset_select` `reset_select`(0x20BC0) | 0 = memory channels (`defaults_memch`, then channel 1 → VFO), 1 = menus (`menu_defaults_load`), 2 = `settings_defaults(0)`. Then 0x20B39 = 0x11 | restart save |
| Power-on key combination | DISPLAY-link `displink_rx_F0_hello` (startup code at frame +7, T10b) | 0x01: `settings_defaults(0)` + 0x20B45 = 1 (all reset). 0x07: swaps paired destination codes (0xA983/0xB5A7 → 0xD950, 0xD950/0xA4C5 → 0xA983). 0x05: toggles flag 0x4760 | first-boot style save after power-on |
| Interrupted save | `eeprom_load_all` | Like ZZ01 | after power-on |
| Blank EEPROM | `eeprom_load_all` | Like ZZ99 | at once + after power-on |

## Other functions

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFFB142B | `eeprom_hdr_update` | | Counter++, state flag, 10-byte header write **[fact]** |
| 0xFFFB0229 | `eeprom_load_all` | `eeprom_load_all` | Boot load (figure above) **[fact]** |
| 0xFFFB02AF | `eeprom_save_all` | `eeprom_save_all` | EE 0x0112..0x5836 **[fact]** |
| 0xFFFB02CF | `eeprom_save_opstate` | `eeprom_save_opstate` | EE 0x53DB (0x45C) + 0x1A62 (0x18) **[fact]** |
| 0xFFFB0303 | `eeprom_save_bandstack` | `eeprom_save_bandstack` | `(vfoB, band, slot, rec)` **[fact]** |
| 0xFFFB0356 | `eeprom_save_image` | | EE 0x1A7A, 0x2F49 bytes **[fact]** |
| 0xFFFB0376 | `eeprom_save_memch` | | Header 0x87 + channel ch **[fact]** |
| 0xFFFB03C1 / 0xFFFB03E1 | `eeprom_save_qmb` / `eeprom_save_qmb_slot` | `eeprom_save_qmb` / `eeprom_save_qmb_slot` | QMB block / header + one record **[fact]** |
| 0xFFFB0450 | `eeprom_save_msg` | `eeprom_save_msg` | `(type 0..2, n 1..5)` **[fact]** |
| 0xFFFB0509 | `eeprom_save_atu_mem` | `eeprom_save_atu_mem` | EE 0x5249 **[fact]** |
| 0xFFFB0532 / 0xFFFB0544 | `eeprom_save_cfg105` / `eeprom_save_dest` | | No header update and no power-fail check **[fact]** |
| 0xFFFB0558 | `settings_defaults` | | See above |
| 0xFFFB4B28 | `supply_undervolt_check` | `supply_undervolt_check` | See above **[fact]** |
| 0xFFF98797 | `power_down_save` | `power_down_save` | Shutdown message, full save, reset **[fact]** |
| 0xFFFB3E55 | `sw_reset` | `sw_reset` | SWRR = 0xA501 **[fact]** |
| 0xFFFB237A / 0xFFFB23F3 | `swtimer_start` / `swtimer_expired` | `swtimer_start` / `swtimer_expired` | Soft timers (index ≤ 0x4A; flags 0x11FED[n]) **[fact]** |
| 0xFFFC1927 | `bandstack_save` | `bandstack_save` | **[fact]** |
| 0xFFFECEA5 | `atu_mem_store` | `atu_mem_store` | **[fact]** for the data movement, **[inference]** that it is the tuner |
| 0xFFFBBC0A | `cal_adjust` | `cal_adjust` | Pointer table 0x25D50 = 0x4659 and 0x25D4C = 0x20B04 (the DTBL init data at 0xFFF8EADC) give `cfg105[0x20CE2]` **[fact]** |
| 0xFFFB3BA6 | `dest_jumper_apply` | `dest_jumper_apply` | Swaps between paired destination codes (restricted ↔ wide TX coverage) by `jp_p51_get`, the P51 input on net `JP_P51` (schematic, [peripherals.md](peripherals.md)); runs only from `displink_rx_F0_hello` for start modes 1 and 7 **[fact, see [tx-protection.md](tx-protection.md#the-jp_p51-strap-toggles-restricted--wide-dest_jumper_apply-0xfffb3ba6-fact)]** |
| 0xFFF94CAB | `qmb_boot_init` | `qmb_boot_init` | **[fact]** |
| 0xFFFD0288 | `reset_select` | `reset_select` | **[fact]** |

## Globals

| Address | Size | Meaning |
|---|---|---|
| 0x464F | 10 | EEPROM header mirror |
| 0x4658 | u8 | Header state flag (0 = save in progress, 1 = clean) |
| 0x4659 | 0x105 | `cfg105` calibration table; `PTR_DAT_00025d50` points here |
| 0x475E / 0x4760 | u16 + u8 | Destination code + flag |
| 0x60C9 / 0x60CA | u8 | VFO-A / VFO-B memory channel index |
| 0x60CB | 133 | Channel valid flags |
| 0x9DC5 | u8 | Auto power-on after a reset **[inference]** |
| 0x20B04 | struct | System state base (`PTR_DAT_00025d38`, `…4c`, `…54`..`…7c` all = 0x20B04 **[fact, DTBL]**). +0x35 = 0x20B39 restart code, +0x447 = 0x20F4B restart request, +0xBA = 0x20BBE ZZ00 mode, +0x1DE = 0x20CE2 alignment item |
| 0x20B43 | u8 | Power-fail latch |
| 0x20B45 | u8 | "Defaults loaded, save after power-on" |
| 0x20B08 | u16 | ADC result watched for power fail |
| 0x11FED[n] | u8 | Soft-timer expired flags |

## Decoder artifact found here (affects the whole MAIN decompile) **[fact]**

The RX SLEIGH module decodes **`MOVU.B/W Rs,Rd`** (opcode 0x5B/0x5F, ld = 11, register zero-extend) as a memory load `MOVU.x [Rs],Rd`. The module's own comment says "when ld=3 it should be [Rs]". Per the RX instruction set, ld = 11 means register direct.

- **Here.** The decompile shows `eeprom_write(*(u16*)(0x1B01 + ch*0x5A), …)`, but the code really computes `(u16)(0x1B01 + ch*0x5A)`: the bytes at 0xFFFB03B0 are `5F 11`.
- **Size.** `tools/ghidra/T10eMovuRegCount.java` finds **107** such instructions in 49 functions.
- **SP checksum.** At 0xFFFA3867, 0xFFFA38C4, 0xFFFA39BB and 0xFFFA510A (`60 22 5F 22` = `SUB #2,R2; MOVU.W R2,R2`), the checksum length is simply **`len − 2`**. **The "binary SP checksum bug" in [cat.md](cat.md) is this decoder artifact, so SPR/SPW/SPM/SPN/SPA work normally.**

## Further functions (T23g)

Named functions of this subsystem that the tables above did not list yet, one row each (T23g, found with `tools/doc_table_gaps.py`). The purpose is the plate comment of the name in `tools/ghidra/names_*.tsv` (or the `Ifdsp*Names.java` / `*.lib.tsv` entry); rows marked *code shape* have no comment there and give what the decompile shows: the direct callees, the first string, the size and the caller count. Tags as in the names files; a comment without a tag is an inference from the code.

| Address | Ghidra name | Inferred name | Purpose |
|---|---|---|---|
| 0xFFF94BD9 | `ver_main_ext1` |  | Returns 0xFFFFFF10, the ROM string `"2101"`, shown after "V01-12-" in SOFT VERSION when DBG MODE ENABLE (0x4660) is set (#205) **[fact]**; its meaning is open (see above) |
| 0xFFF94BE5 | `ver_main_ext2` |  | Returns 0xFFFFFF20, the ROM string `"24-02-16"` (the release date, as in the SFL header), shown in SOFT VERSION when DBG MODE ENABLE (0x4660) is set (#205) **[fact]** |
| 0xFFF94C1B | `ver_display_date_set` |  | Stores the 8-char DISPLAY date "yy-mm-dd" (from F0 hello bytes 4..6) at 0x143C (#205) **[fact]** |
| 0xFFFB0636 | `reset_memch` |  | -> defaults_memch **[inference]** |
| 0xFFFB063A | `reset_menu` |  | -> defaults_menu **[inference]** |
| 0xFFFB06E5 | `defaults_vfo` |  | Default VFO-A/B working records 0x9D09/0x9D63 (dest-dependent byte +0x46) **[inference]** |
| 0xFFFB0A28 | `defaults_bandstack` |  | Clears 0x4761..0x60C8 and fills 6 band-stack sets (FUN_fffb0779 per set) **[inference]** |
| 0xFFFB0A7C | `defaults_qmb` |  | Clears the QMB block 0x9012 (0x395) **[inference]** |
| 0xFFFB0A8F | `defaults_memch` |  | Clears 0x60C9 (0x2F49), default records for 117 channels, dest-specific 60 m channels **[inference]** |
| 0xFFFB10A4 | `defaults_msg` |  | Clears 0x93A7 (0x4F1), keyer texts from ROM 0xFFF80C53.. **[inference]** |
| 0xFFFBBA9F | `align_ialc_park` |  | (item): while an I-ALC item (index 0x3A..0x44) is selected, saves the band's 100 W FALC/TXG (50 W on 70 MHz) to 0x12167/0x12168 and sets them to 0xFF; restores them on leaving **[fact]** |
| 0xFFFBBC54 | `align_store_ui4` |  | cal[item] = UI-state +4 (0x20B08) >> 4 (item 0) **[inference]** |
| 0xFFFBBC8E | `align_store_ui2` |  | cal[item] = UI-state +2 (0x20B06) >> 4 (54 items from 70) **[inference]** |
| 0xFFFBBCB8 | `align_store_dsp_async` |  | Starts a DSP status read (dsp_status1_raw, timer 0x42 30 ms); the result goes to cal[item] later (items 45..47) **[inference]** |
| 0xFFFBBCFF | `align_store_ui8_scaled` |  | cal[item] = (0x20B0C >> 4) * 0x4666 / 137 rounded (item 245) **[inference]** |
| 0xFFFC47DD | `preamp_step` |  | Record +0x05 bits 0-1: IPO(0) -> AMP1(2) -> AMP2(3) -> IPO, beep 1; the IPO key (#205) **[fact]** |
| 0xFFFC4850 | `preamp_ipo` |  | Record +0x05 bits 0-1 = 0 (IPO), beep 2 (#205) **[fact]** |
| 0xFFFC4B3D | `vfo_filter_byte_ptr` |  | Returns VFO-A/B record (0x9D09/0x9D63) + the per-mode filter byte offset (+0x0B/+0x15/+0x1F/+0x29/+0x33/+0x3D by mode nibble); the decompile shows void (#205) **[fact]** |
| 0xFFFE5E1B | `memch_current_skip` |  | memch_skip_get(memch_current(active VFO)); the scan steps repeat while it is set (#205) **[fact]** |
| 0xFFFE5E3B | `memch_skip_get` |  | Memory channel n: record +0x01 bit 7 (0x6151 + n*0x5A) = memory-scan SKIP (#205) **[fact]** |
