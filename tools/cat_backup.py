#!/usr/bin/env python3
"""Read-only CAT backup of an FT-710: identity, region code, E8 memory image and (optionally) the raw EEPROM.

Usage: python3 -I tools/cat_backup.py PORT [OUTDIR] [--baud 38400] [--eeprom]
       python3 -I tools/cat_backup.py --decode E8_RAW.BIN      (offline check of a saved E8 frame)

PORT is the CP210x "Enhanced" COM port (macOS /dev/cu.SLAB_USBtoUART, Linux /dev/ttyUSB0, Windows COMx); the baud rate must match
menu CAT-1 RATE. OUTDIR defaults to backup-<date>. Everything this script sends is a read:
  ID; VE0;..VE3; JP0710;      -> info.txt                (tested on the owner's radio, 2026-10-28)
  E8;                         -> e8_raw.bin, e8_plain.bin (tested on the owner's radio, 2026-10-28)
  SPR<aH><aL>\\0<sum>;         -> eeprom.bin, eeprom_missing.txt   only with --eeprom; NOT YET TESTED on a radio
The E8 image holds the memory channels only (docs/code/main/eeprom.md). The EEPROM dump holds everything, including the
calibration table (EEPROM 0x000A..0x010E) and the region code (0x010F), which nothing else can back up.
It never sends a set form. The files contain your memory channels and settings: keep them private.
See docs/cat-undocumented.md for what to back up, why, and how to restore.
"""
import datetime
import os
import sys
import time

E8_LEN = 10674          # "E8" + 5 header bytes + 10665 data + sum + ";"
E8_DATA = 10665
EEPROM_END = 0x5836     # last EEPROM address (RAM mirror 0x464F..0x9E85)


def decode_e8(raw):
    """Return (plain_bytes, problems). Frame: E8, k, k+7, k+0x90, k, k, data+k ..., sum, ';' (docs/cat-commands.md#ext-e8)."""
    problems = []
    if len(raw) != E8_LEN:
        problems.append(f"length {len(raw)}, expected {E8_LEN}")
        return None, problems
    if raw[:2] != b"E8" or raw[-1:] != b";":
        problems.append("frame does not start with E8 / end with ;")
    k = raw[2]
    if [(b - k) & 0xFF for b in raw[2:7]] != [0, 7, 0x90, 0, 0]:
        problems.append("header signature 00 07 90 00 00 not found")
    plain = bytes((b - k) & 0xFF for b in raw[7:7 + E8_DATA])
    if (sum(plain) + k) & 0xFF != raw[-2]:
        problems.append("checksum mismatch")
    return plain, problems


def query(s, cmd, n=64, wait=0.4):
    s.reset_input_buffer()
    s.write(cmd)
    time.sleep(wait)
    return s.read(n)


def read_e8(s):
    s.reset_input_buffer()
    s.write(b"E8;")
    buf, t = b"", time.time()
    while len(buf) < E8_LEN and time.time() - t < 15:
        buf += s.read(E8_LEN - len(buf))
    return buf


def spr_frame(addr):
    """SPR read of one EEPROM byte: 'SPR' aH aL x sum ';', sum = 8-bit sum of the six bytes before it (cat_SP_eeprom_byte)."""
    body = b"SPR" + bytes([addr >> 8, addr & 0xFF, 0])
    assert body[2:3] == b"R"   # upper-case R = read; 'W' would write EEPROM
    return body + bytes([sum(body) & 0xFF]) + b";"


def read_eeprom(s, log):
    image, missing = bytearray(EEPROM_END + 1), []
    s.timeout = 0.3
    for a in range(EEPROM_END + 1):
        f = spr_frame(a)
        r = b""
        for _ in range(2):
            s.reset_input_buffer()
            s.write(f)
            r = s.read(8)
            if len(r) == 8 and r[:5] == f[:5] and r[7:] == b";" and sum(r[:6]) & 0xFF == r[6]:
                break
        else:
            missing.append(a)
            continue
        image[a] = r[5]
        if a % 0x400 == 0:
            log(f"  EEPROM 0x{a:04X} / 0x{EEPROM_END:04X}")
    return bytes(image), missing


def main():
    args = sys.argv[1:]
    if args[:1] == ["--decode"]:
        plain, problems = decode_e8(open(args[1], "rb").read())
        print("E8 OK" if not problems else "E8 problems: " + "; ".join(problems))
        return 0 if not problems else 1
    if not args or args[0].startswith("-"):
        print(__doc__)
        return 2
    import serial

    baud = int(args[args.index("--baud") + 1]) if "--baud" in args else 38400
    pos = [a for i, a in enumerate(args) if not a.startswith("-") and (i == 0 or args[i - 1] != "--baud")]
    port = pos[0]
    out = pos[1] if len(pos) > 1 else "backup-" + datetime.datetime.now().strftime("%Y%m%d-%H%M")
    os.makedirs(out, exist_ok=True)
    s = serial.Serial(port, baud, timeout=0.6)

    ident = query(s, b"ID;")
    if not ident.startswith(b"ID0800"):
        print(f"No FT-710 on {port} at {baud} baud (ID; -> {ident!r}). Check the port and menu CAT-1 RATE.")
        return 1
    info = [f"date {datetime.datetime.now().isoformat(timespec='seconds')}", f"port {port} {baud}", f"ID; {ident.decode()}"]
    for c in (b"VE0;", b"VE1;", b"VE2;", b"VE3;", b"JP0710;"):
        info.append(f"{c.decode()} {query(s, c).decode(errors='replace')}")
    open(os.path.join(out, "info.txt"), "w").write("\n".join(info) + "\n")
    print("\n".join(info))

    raw = read_e8(s)
    open(os.path.join(out, "e8_raw.bin"), "wb").write(raw)
    plain, problems = decode_e8(raw)
    if problems:
        print("E8 problems: " + "; ".join(problems))
        return 1
    open(os.path.join(out, "e8_plain.bin"), "wb").write(plain)
    print(f"E8: {len(raw)} bytes, signature and checksum OK")

    if "--eeprom" in args:
        print("EEPROM dump with SPR (untested on a radio; about 22,600 reads)")
        image, missing = read_eeprom(s, print)
        open(os.path.join(out, "eeprom.bin"), "wb").write(image)
        open(os.path.join(out, "eeprom_missing.txt"), "w").write("".join(f"0x{a:04X}\n" for a in missing))
        print(f"EEPROM: {len(image)} bytes, {len(missing)} addresses unread (see eeprom_missing.txt)")
    s.close()
    print(f"Saved in {out}/ - keep it private (memory channels, settings, calibration).")
    return 0


if __name__ == "__main__":
    sys.exit(main())
