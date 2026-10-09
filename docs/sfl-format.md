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
- **checksum**: 32-bit, 8 uppercase hex digits. **Solved in T04:** CRC-32 over the *encoded* payload plus a 4-byte salt (see "Payload encoding (T04)" below).

| File | Tag | Length = file size | Payload bytes | Checksum |
|---|---|---|---|---|
| FT-710_MAIN_V0112.SFL | MC | 1355160 | 1354584 | B092FD93 |
| FT-710_DISPLAY_V0108.SFL | PC | 3325520 | 3324944 | 1166734A |
| FT-710_IFDSP_V0101.SFL | ID | 415020 | 414444 | 616282B0 |
| FT-710_SDR_V0104.SFL | SR | 4392794 | 4392218 | 62A7AEF0 |

### Checksum: ruled out in T03 (computed over the *encoded* bytes)
**Superseded:** T04 found the algorithm in the DISPLAY loader. It is zlib CRC-32 over the encoded payload, continued over the salt `A6 EC 9E 13`. T03's search missed it only because of the salt. The list below is kept for the record.

Tested on IFDSP; the cheaper subset was also tested on all four images. No match:
- Byte ranges: payload only, whole file, whole file with the checksum field blanked to spaces or to `0`s, comment box + payload, tag line + payload, and payload minus its last 4 bytes.
- CRC-32 polynomials 04C11DB7, 1EDC6F41 (C), A833982B (D), 814141AB (Q), 000000AF (XFER), 741B8CD7 (K), 32583499, each with init 0/FFFFFFFF, refin/refout either way and xorout 0/FFFFFFFF. That covers CRC-32/ISO-HDLC (zlib), BZIP2, MPEG-2, JAMCRC, POSIX, CRC-32C and others.
- 8/16/32-bit sums (BE and LE) and their negations and complements.
- Target values were matched as-is, bit-reversed and byte-swapped.

~~Working hypothesis: the checksum covers the decoded payload.~~ Wrong. It covers the encoded payload, plus a salt (see T04).

### Payload length alignment
The payload lengths mod 32 are 24 (MAIN), 16 (DISPLAY), 12 (IFDSP) and 26 (SDR). SDR's is not even a multiple of 4. No padding to a cipher block size, so the encoding is byte-granular (stream/XOR or substitution), confirmed in T04 as a period-43 additive key.

### Update process (from `Firmware_Ver_Up_Manual_ENG_FT-710_2211-A.pdf`)
- SFL files are copied to an SD card folder and selected in the menu (`FIRMWARE UPDATE`). There is no PC-side tool.
- **DISPLAY must be updated first**, then MAIN/DSP/SDR. Afterwards the radio powers off, and a reset (DSP RESET + FINE/FAST + POWER) is needed.
- So the **DISPLAY (panel) CPU reads the SD card and transfers** the other images to their CPUs. If direct cryptanalysis stalls, the DISPLAY firmware's SFL loader is the place to find the decode routine and the checksum algorithm. That's a chicken-and-egg problem, because DISPLAY itself is encoded.
- Note: the copy of this manual in `Firmware/` (from the zip) and the one in `Manuals/` (from the website) differ by hash (modified 37 s apart) but have the same title and page count.

## Payload encoding (T04)

Implemented in `tools/sfl_decode.py`.

### Scheme
A byte-wise subtraction with a fixed 43-byte key that repeats from the payload start (file offset 0x240):

```
plain[i] = (enc[i] - KEY[i mod 43]) mod 256        i = payload offset (0-based)
KEY = 1E 27 1B 12 11 16 19 17 24 25 29 1C 0D 0B 06 04 03 01 02 05 07 0C 0E 0F
      18 1D 20 22 2A 2B 08 09 0A 10 13 14 15 1A 1F 21 28 23 26
```
- KEY is a permutation of the values 1..43. The **period is 43, not 32**. T03's "period 32" was a misreading.
- The same key is used for all four images, with no drift over the whole file. Phase 0 is the first payload byte. The radio's encoder is the same loop with `+`.

### How it was derived
1. Small hexdumps of each payload showed a repeating run at the start of IFDSP and SDR. Its period is 43 bytes, and it repeats again at payload offset 0x2B. IFDSP's first 43 bytes are exactly a permutation of 1..43. SDR's run is the same sequence plus a constant 0x66 per byte, which means additive (not XOR) with plaintext `0x00` (IFDSP) and `0x66` (SDR, ASCII `f`).
2. Taking KEY = IFDSP payload[0:43] and subtracting it from MAIN gave `S00E0000…\r\nS311FE7F5D00FFFF…`, a Motorola S-record. All four images then decoded cleanly.
3. Confirmed in code: the key is the first object of DISPLAY's `.data` (file offset 0x328840, VMA 0x20428840). The routine at VMA **0x2011497C** (DISPLAY V01-08, load base 0x20100000) does `pos %= 43; buf[i] -= KEY[pos]; pos = (pos+1) & 0xFF` and returns the updated position, so it can stream in chunks. Its twin at 0x201149E0 does the `+=` (encode).

### Checksum (tag-line field), solved
The routine at DISPLAY VMA **0x20114A64** works like this:

```
crc = 0xFFFFFFFF
while (n = fread(buf, 1, 256, f)) crc = crc32_update(crc, n, buf)    // table init 0x20100A14, update 0x20100A5C
crc = crc32_update(crc, 4, "\xA6\xEC\x9E\x13")                  // salt = LE word 0x139EECA6 (literal at 0x20114ADC)
return ~crc
```
The polynomial is 0xEDB88320, reflected (literal at 0x20100A94). That is CRC-32/ISO-HDLC, so in Python it is `zlib.crc32(SALT, zlib.crc32(encoded_payload))`. It is computed over the **encoded** payload (bytes 0x240..EOF), not the plaintext. It matches all four files: B092FD93, 1166734A, 616282B0 and 62A7AEF0. Over the decoded payload or the whole file it does not match. `sfl_decode.py` verifies the CRC and exits non-zero on a mismatch.

### Decoded payload contents
| Image | Plaintext format | `sfl_decode.py` output | Evidence |
|---|---|---|---|
| MAIN (MC) | Motorola S-record (S0/S3/S7, CRLF), 28227 data records, all record checksums valid, 451451 data bytes. S0 name `AH080H_Mmot`. | Flattened: `X.bin` = 0xFFF80000..0xFFFFFFFF (512 KiB, gaps 0xFF). `X.bin.FE7F5D00.bin` = 116 B of option-setting memory. | Address map and S7 entry 0xFFF8FBDB match the **Renesas RX651** (R5F56514, 512 KB code flash) from docs/hardware.md: option-setting memory at FE7F5D00, code ending at the fixed vector table, reset vector @0xFFFFFFFC = 0xFFF8FBDB, other exception vectors 0xFFF905AD… There are 3.5k strings: `V01-12`, the menu texts, and the CAT mnemonic table `ABACAGAIAMAO…FAFB…IDIF…` with answer templates (`FA000000000;`, `IF000…;`, `MD00;`). |
| DISPLAY (PC) | Raw binary | `X.bin` as is (3324944 B) | ARM (A32) reset/exception vector table of `B` instructions at offset 0. Literal pools resolve with a **load base of 0x20100000** (RAM). A .data copy routine reads from a 0x18000000 SPI-flash window, consistent with the RZ/A1H (R7S721001) in docs/hardware.md. Strings: `YAESU FT-710 FIRMWARE UPDATE`, `YAESU FT-710 BOOT LOADER V01-02`, `FT-710_MAIN_V`…`FT-710_SDR_V` (SD-card file matching), `I:\FT-710\…`. It holds the SFL decoder and the CRC routine. |
| IFDSP (ID) | Raw binary | `X.bin` as is (414444 B) | Zeros to 0x400, `FCFB` (FlexSPI NOR config block) at 0x400, and a Cortex-M vector table at 0x1000: SP 0x00200000, reset 0x080011A9 (Thumb, odd). Word +0x20 = 0x642EC = image length − 0x1000. This is the **NXP i.MX RT685** FlexSPI boot layout, **XIP base 0x08000000** for file offset 0. Strings: `DSP Version %04X`, `Component versions from DSP:`, newlib printf tables. |
| SDR (SR) | One line of lowercase ASCII hex + CRLF | Hex converted to a 2196108-byte bitstream | It starts with the 4-byte word `993966C2` (purpose unknown), then FF padding, then the **Xilinx 7-series** bus-width pattern `000000BB 11220044`, sync `AA995566`, and type-1 packets. IDCODE written = **0x0362C093** (Artix-7 XC7A50T by the Xilinx IDCODE table; docs/hardware.md lists the FPGA vendor as unknown). |

Use `--raw` to get the decoded payload verbatim (S-record or hex text) without conversion.
