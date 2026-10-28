# Undocumented CAT commands: risks, paths back and backups

The FT-710 answers 22 CAT commands that Yaesu's CAT manual does not list, plus service forms inside them. This page is for anyone who
wants to try them. For each one it says what it changes, how risky it is, and **how to get back** if something goes wrong. Back up
first (section 2). The full firmware details are in [cat-commands.md](cat-commands.md#extended-table); the plain-language tour is
chapter 5 of the [illustrated guide](guide/README.md#55-the-22-undocumented-commands-by-risk).

> **Read this first.**
> - Everything here comes from reading firmware V01-12. Only the read-only forms marked *tested* have been sent to a radio
>   ([results](cat-commands.md#radio-checks)). Every other form, including all writes, is **untested**.
> - Some commands below change the radio's region (and with it where it may transmit), or overwrite the factory calibration.
>   Some of that **cannot be undone without a backup**, and calibration without a backup can only be redone by a service alignment.
> - You alone are responsible for your radio and for transmitting only where your licence allows. Nothing here is endorsed by Yaesu.
> - The project rule ([AGENTS.md](../AGENTS.md)): nothing is written to a radio without its owner's explicit approval, each time.

## 1. What the radio stores, and which commands erase or overwrite it

| Data | Where | Erased or overwritten by | Backed up by |
|---|---|---|---|
| Memory channels | EEPROM 0x1A7A.. (RAM 0x60C9) | `ZZPE071001;`, `ZZPE071099;`, `JP` set, `E9`, front-panel MEMORY CLEAR / ALL RESET | SD card (Yaesu), `E8` |
| Menu settings, band stacks, VFOs | EEPROM 0x0112.. | `ZZ…01`, `ZZ…99`, `JP` set, front-panel MENU CLEAR / ALL RESET | SD card (Yaesu, menus) |
| **Region (destination) code** | EEPROM 0x010F (2 bytes) | `ZZPE071099;` (→ 0x8043), `JP` set, a strap + reset | write down `JP0710;`; EEPROM dump |
| **Factory calibration** (261-byte alignment table) | EEPROM 0x000A..0x010E | `ZZPE071099;`, `SPAWE`, `SPW`, a key press in `ZZPE071000;` mode, a blank or replaced EEPROM | **EEPROM dump only** |

Two things are worth knowing. The front-panel resets (**EXTENSION SETTING → RESET**, [operating manual](https://www.yaesu.com/Files/4CB893D7-1018-01AF-FA97E9E9AD48B50C/FT-710_OM_ENG_EH080H201_2307N-GS.pdf#page=107) p. 105: MEMORY CLEAR, MENU CLEAR, ALL RESET) never touch the
calibration or the region code **[fact]** ([eeprom.md](code/main/eeprom.md)). Only `ZZPE071099;` and a blank EEPROM reset the
calibration to ROM defaults. Those defaults are generic, not your radio's alignment.

## 2. Back up before you experiment

Do all three, and keep a copy of the files off the radio.

### 2.1 SD card: memories and menus (Yaesu's own method, recommended)

From Yaesu's [FT-710 operating manual](https://www.yaesu.com/Files/4CB893D7-1018-01AF-FA97E9E9AD48B50C/FT-710_OM_ENG_EH080H201_2307N-GS.pdf#page=70) (pp. 68–70):
1. Format the card in the radio once: **FUNC → EXTENSION SETTING → SD CARD → FORMAT → DONE → OK**.
2. **FUNC → EXTENSION SETTING → SD CARD**, touch **DONE** on the memory save item, **NEW**, name it, **ENT**. Wait for "FILE SAVED".
3. Do the same for the setting-menu save item.
4. Copy the files from the card to your PC.

**Restore:** **FUNC → EXTENSION SETTING → SD CARD**, touch **DONE** on the memory or menu load item, pick the file, **OK**. The radio
shows "FILE LOADED" and restarts itself. This is the safest way back after any reset in this page.

### 2.2 CAT: identity, region code and the `E8` memory image

`tools/cat_backup.py` sends only reads: `ID;`, `VE0;`..`VE3;`, `JP0710;` and `E8;`. These were tested on a radio
(2026-10-28).

```
pip install pyserial
python3 -I tools/cat_backup.py /dev/cu.SLAB_USBtoUART     # Windows: COM5 etc.; Linux: /dev/ttyUSB0
```

- Use the CP2105 **Enhanced** port, at the baud rate set in the radio's menu CAT-1 RATE (the script defaults to 38400; pass `--baud`).
- It writes `backup-<date>/info.txt` with the firmware versions and the `JP0710;` reply. The radio sends the region code together
  with its bitwise complement, and the script checks the two against each other. `info.txt` then says, for example,
  `region code 0x50E2 (check bytes OK)`. **Write the code down:** it is the one value you need to know to get the region back
  (section 4).
- It saves `e8_raw.bin` and `e8_plain.bin` and checks the signature and checksum. `E8` holds the memory channels only
  (0x87-byte memory header + 117 channels), not menus, calibration or the region **[fact]**.
- Everything it reports goes to `backup.log` in the backup folder, with timestamps: each retried or failed read and why (no reply,
  `?;`, short reply, wrong address, bad checksum), any warning or error, and the details of a crash or an interruption.
- It finishes with `SHA256SUMS`, the SHA-256 hash of every file in the backup. To check later that nothing has changed (on another
  disk, after a copy, years later), run `python3 -I tools/cat_backup.py --verify backup-<date>`, or `shasum -a 256 -c SHA256SUMS`
  inside the folder.

The reads carry no CRC. `E8` and `SPR` replies carry an 8-bit additive checksum, which the script checks; `ID` and `VE` carry none.
An 8-bit sum catches most single damaged bytes but not every error, which is why section 2.4 also suggests comparing two runs.

### 2.3 Full EEPROM dump: calibration and region

```
python3 -I tools/cat_backup.py /dev/cu.SLAB_USBtoUART --eeprom
```

This also copies the radio's whole EEPROM into `eeprom.bin`. It is the **only** backup of the factory calibration, and it holds the
region code as well. It takes about 2 minutes, because the service command it uses (`SPR`) reads one byte at a time (about 5 ms
each). A progress line shows how far it is, the time left and any bytes that didn't answer. Tested on a radio on 2026-10-28: all
22,583 bytes read with no errors, and the memory-channel part of the dump is byte-for-byte the same as the `E8` image.

The script checks each byte's reply (checksum and address, one retry), lists any addresses that didn't answer in `eeprom_missing.txt`, and compares the region code in the dump (bytes
0x010F..0x0110) with the `JP0710;` reply. It prints a warning if they differ.

### 2.4 Is the backup really read-only?

Yes, as far as the firmware shows. Three things make sure of it:

- **The script can only send reads.** Every byte goes through one function, `send()`, which accepts only `ID;`, `VE0;`..`VE3;`,
  `JP0710;`, `E8;` and correctly formed `SPR` reads, and stops the program on anything else.
- **The firmware only reads for those frames** **[fact, MAIN V01-12]**:
  - `JP0710;` (7 characters) takes the read branch; a region write needs the 15-character set form (`cat_dispatch_ext`).
  - `E8;` copies the memory image into the CAT reply buffer (RAM 0x1C8E..0x463F) and nothing else (`cat_ext_E8` 0xFFFA53A4).
  - `SPR` calls `cat_SP_eeprom_byte` in read mode; EEPROM is written only when the third letter is exactly `W`
    (`cat_ext_SP` 0xFFFA36F2). The receiver takes `SPR` frames by fixed length, so a data byte equal to `;` cannot cut a frame
    short (`cat_rx_byte_hook` 0xFFFB1DAD).
- **The port is opened with RTS and DTR off.** That matters because the radio can key the transmitter from RTS or DTR of its
  Standard USB port (menus RPTT SELECT and PC KEYING), so a backup run on the wrong port could otherwise transmit.

To check it on your own radio, run the backup twice, with the radio left alone in between. The two `e8_plain.bin` files, and the two
`eeprom.bin` files if you used `--eeprom`, should be identical: their lines in the two `SHA256SUMS` files show the same hash. That includes the EEPROM save counter (bytes 0x0005..0x0008), which
goes up on every save **[fact]** ([eeprom.md](code/main/eeprom.md)). (`e8_raw.bin` differs between runs on purpose: the radio
scrambles each `E8` reply with a new random key.)

Done on a radio on 2026-10-28: two runs two minutes apart gave identical `eeprom.bin` and `e8_plain.bin` (0 of 22,583 bytes
different), and the save counter stayed at the same value **[fact, radio]**.

## 3. Every undocumented command: risk and path back

Risk: **none** = no effect; **low** = read only; **medium** = changes a setting you can set back; **high** = can change region,
calibration, all settings or the hardware state, or has no clean path back.

### Reads (safe)

| Command | What it does | Risk | Path back |
|---|---|---|---|
| `VE0;`..`VE3;` | firmware versions of MAIN, DISPLAY, SDR, DSP (*tested*) | low | none needed |
| `JP0710;` | region code + EEPROM date stamp (*tested*) | low | none needed |
| `FD000;` `FD001;` `FD002;` | scope start frequencies (*tested*) | low | none needed |
| `PE0bc;` / `PE2bc;` (b, c = 0..2) | one of 18 EQ-like bytes (*`PE000;` tested*) | low | none needed |
| `SPIR;` | 12 raw ADC readings (*tested*) | low | none needed |
| `E8;` | memory-channel image, 10,674-byte binary reply (*tested*) | low | none needed; it floods the port for ~3 s |
| `EM01;`..`EM05;` | one of five 50-character text slots | low | none needed |
| `SPSRaaaa;` / `SPDRaaaa;` | one SDR-FPGA / IF-DSP register | low | none needed |
| `SPM…` (binary) | 8 meter bytes | low | none needed |
| `SPR…` (binary) | one EEPROM byte (used by section 2.3; *tested*) | low | none needed |
| `SPNR…` (binary) | one calibration-table byte, **but** also tunes the active VFO to that item's test frequency | low–medium | retune the VFO |
| `BY ED EK EU RC RD RS RT RU EN FS QS`, `KT` | no code behind them: `?;` or no reply | none | – |

### Writes that you can set back

| Command | What it changes | Risk | Path back |
|---|---|---|---|
| `FD002ddddddddd;` | the FIX-mode scope start of the current band (saved) | medium | read `FD002;` first, then send the old value back |
| `PEabcnnn;` with a ∈ {0,2}, b, c ∈ {0,1,2} | one mic-EQ-like byte (saved with the menus) | medium | read it first and write it back, or set the EQ in the menu |
| `EM0n<text>;` | a text slot. It sits in the EEPROM mirror, so a later save may keep it **[inference]** | low | read `EM0n;` first and write it back |
| `EO…;` | turns the main dial / FUNC / STEP knob from the PC, and clears eight mode flags | medium | retune or set the knob value back |
| `SPSWaaaavvvv;` / `SPDWaaaavvvv;` | one SDR-FPGA / IF-DSP register, **not saved**. MAIN overwrites it when the setting behind it changes | high (direct hardware state: TX power, filters) | change that setting, or power-cycle **[inference]** |
| `SPNW…` / `SPNS…` (binary) | one calibration entry **in RAM**; `S` re-applies the table | high | power-cycle **without** sending `SPAWE`: the table is reloaded from EEPROM at boot, and normal saves never write it **[inference]** |

### Writes with no easy way back (back up first)

| Command | What it changes | Risk | Path back |
|---|---|---|---|
| `ZZPE071001;` | resets VFOs, memories and menus (like ALL RESET), restarts | high | SD-card load (2.1) |
| `ZZPE071099;` | **full factory reset: also the calibration table and the region** (→ 0x8043, which has no TX ranges), restarts | **highest** | SD-card load for settings; region as in section 4; **calibration only from an EEPROM dump (2.3)**, otherwise a service alignment |
| `ZZPE071000;` | alignment (service-adjust) mode: some keys blocked, and **a key press saves the calibration table** **[inference]** | high | send `EO` (clears the mode; it also retunes), or power-cycle **[inference]**; don't press keys meanwhile |
| `JP0710hhll~h~l;` | **region code**, then resets menus and memories and restarts | high | send `JP` with the old code, then SD-card load; wide codes need section 4 |
| `E9…` (binary) | overwrites all memory channels | high | SD-card load, or `E9` with your own `E8` dump (same risk) |
| `SPW…` (binary) | **any EEPROM byte**, no bounds check | high | `SPW` the old byte, which you only know from a dump (2.3) |
| `SPAWE…` (binary) | saves the RAM calibration table to EEPROM | high | `SPW` the old bytes from a dump (2.3), otherwise a service alignment |
| `PE` with any other a or b | **writes to an arbitrary RAM address** (uninitialized pointer) | high | none defined; power-cycle, then SD-card load or ALL RESET if settings look wrong. **Never send it.** |

Documented commands can also key the transmitter (`TX1`, `MX1`, `KY`, `PB`, `AC` tune), power the radio off (`PS0`) or write EEPROM
(`EX`, memory writes); see [cat-commands.md](cat-commands.md#high-risk-commands-documented-ones-included).

## 4. Getting the region code back

The region code sets the market version and the TX ranges ([tx-protection.md](code/main/tx-protection.md#destination-code-and-tx-coverage)).
Know yours before you start: `JP0710;` (section 2.2).

- **The default 0x8043**, which `ZZPE071099;` and a blank EEPROM set, is in none of the TX tables, so the radio **will not transmit
  at all** until the region is restored **[fact for the tables]**.
- **A restricted code** (0x315B US, 0xA983 Europe, 0xD950 UK, 0x7753, 0xD32D, 0x4380, 0x60E6, 0x020B): send
  `JP0710` + code + its complement + `;`. Example for 0x315B: complement of 31 5B is CE A4, so `JP0710315BCEA4;`. The radio resets its
  menus and memories and restarts; then load them from the SD card.
- **A wide code** (0x50E2, 0xB5A7, 0xA4C5, 0x306F, 0x9CF7): `JP` **cannot** set these. It swaps each for its restricted partner
  (0x50E2 → 0x315B, …) before saving **[fact]** (`cat_ext_JP` 0xFFFA556B). The ways back are the hardware strap on MAIN (P51) plus a
  reset from a power-on key combination, which swaps the restricted code to its wide partner (`dest_jumper_apply`; which key
  combination is not decoded), or two `SPW` writes to EEPROM 0x010F/0x0110 with the old bytes (untested).
- Careful: with the strap **not** fitted, that power-on reset swaps a wide code back to the restricted one.

## 5. Sharing results

Report findings on a GitHub issue. Attach `info.txt`, `e8_*.bin` or `eeprom.bin` if they help; dumps from more radios make it easier to
tell fixed values from per-radio ones (calibration, region, date stamp).
