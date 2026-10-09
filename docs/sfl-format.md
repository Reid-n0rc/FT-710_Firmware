# SFL firmware file format

Applies to the FT-710 firmware package 2024-02 (all four images). Parser and checker: `tools/sfl_header.py`.

## Container (T03)

| Offset | Size | Contents |
|---|---|---|
| 0x000 | 512 | Comment box: 8 lines, each 62 ASCII chars + CRLF (64 bytes). It starts and ends with a full `*` rule. |
| 0x200 | 64 | Tag line: 62 chars + CRLF, space-padded, three whitespace-separated fields: `<tag> <length> <checksum>` |
| 0x240 | rest | Obfuscated payload (starts at byte 576 in all four files) |

All fields are fixed width, so a parser can slice at 512/576 instead of scanning for line ends.

### Comment box
Line 1 is the image title (`MAIN CPU FIRMWARE`, `PANEL CPU FIRMWARE`, `IFDSP FIRMWARE`, `SDR FIRMWARE`). The following lines are `[FILE NAME]`, `[PRODUCT NAME]`, `[FIRM VERSION]` (`Vxx-yy`) and `[DATE]` (`YYYY/MM/DD`), then a copyright line. The radio's update screen shows a per-file version and compares it with the installed version ("Ready" / same version), which probably comes from this box or from the payload.

### Tag line fields
- **tag**: `MC` = MAIN, `PC` = DISPLAY ("panel CPU"), `ID` = IFDSP, `SR` = SDR. Field columns: tag at column 0, length at column 16, checksum at column 32.
- **length**: decimal, **equals the total file size including the 576-byte header** (verified for all four files).
- **checksum**: 32-bit, 8 uppercase hex digits. **Algorithm still unknown** (see below).

| File | Tag | Length = file size | Payload bytes | Checksum |
|---|---|---|---|---|
| FT-710_MAIN_V0112.SFL | MC | 1355160 | 1354584 | B092FD93 |
| FT-710_DISPLAY_V0108.SFL | PC | 3325520 | 3324944 | 1166734A |
| FT-710_IFDSP_V0101.SFL | ID | 415020 | 414444 | 616282B0 |
| FT-710_SDR_V0104.SFL | SR | 4392794 | 4392218 | 62A7AEF0 |

### Checksum: ruled out (computed over the *encoded* bytes)
Tested on IFDSP; the cheaper subset was also tested on all four images. No match:
- Byte ranges: payload only, whole file, whole file with the checksum field blanked to spaces or to `0`s, comment box + payload, tag line + payload, and payload minus its last 4 bytes.
- CRC-32 polynomials 04C11DB7, 1EDC6F41 (C), A833982B (D), 814141AB (Q), 000000AF (XFER), 741B8CD7 (K), 32583499, each with init 0/FFFFFFFF, refin/refout either way and xorout 0/FFFFFFFF. That covers CRC-32/ISO-HDLC (zlib), BZIP2, MPEG-2, JAMCRC, POSIX, CRC-32C and others.
- 8/16/32-bit sums (BE and LE) and their negations and complements.
- Target values were matched as-is, bit-reversed and byte-swapped.

**Working hypothesis:** the checksum covers the **decoded** payload, so it is tested in T04 once a decoder exists. It may also use a seeded or custom algorithm.

### Payload length alignment
The payload lengths mod 32 are 24 (MAIN), 16 (DISPLAY), 12 (IFDSP) and 26 (SDR). SDR's is not even a multiple of 4. No padding to a cipher block size, so the encoding is byte-granular (stream/XOR or substitution), consistent with the period-32 erased-flash pattern.

### Update process (from `Firmware_Ver_Up_Manual_ENG_FT-710_2211-A.pdf`)
- SFL files are copied to an SD card folder and selected in the menu (`FIRMWARE UPDATE`). There is no PC-side tool.
- **DISPLAY must be updated first**, then MAIN/DSP/SDR. Afterwards the radio powers off, and a reset (DSP RESET + FINE/FAST + POWER) is needed.
- So the **DISPLAY (panel) CPU reads the SD card and transfers** the other images to their CPUs. If direct cryptanalysis stalls, the DISPLAY firmware's SFL loader is the place to find the decode routine and the checksum algorithm. That's a chicken-and-egg problem, because DISPLAY itself is encoded.
- Note: the copy of this manual in `Firmware/` (from the zip) and the one in `Manuals/` (from the website) differ by hash (modified 37 s apart) but have the same title and page count.

## Payload encoding (T04)
_(todo)_
