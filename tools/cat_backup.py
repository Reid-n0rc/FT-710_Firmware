#!/usr/bin/env python3
"""Read-only CAT backup of an FT-710: identity, region code, E8 memory image and (optionally) the raw EEPROM.

Usage: python3 -I tools/cat_backup.py PORT [OUTDIR] [--baud 38400] [--eeprom]
       python3 -I tools/cat_backup.py --decode E8_RAW.BIN      (offline check of a saved E8 frame)

PORT is the CP210x "Enhanced" COM port (macOS /dev/cu.SLAB_USBtoUART, Linux /dev/ttyUSB0, Windows COMx); the baud rate must match
menu CAT-1 RATE. OUTDIR defaults to backup-<date>. Everything this script sends is a read:
  ID; VE0;..VE3; JP0710;      -> info.txt                (tested on a radio, 2026-10-28)
  E8;                         -> e8_raw.bin, e8_plain.bin (tested on a radio, 2026-10-28)
  SPR<aH><aL>\\0<sum>;         -> eeprom.bin, eeprom_missing.txt   only with --eeprom; NOT YET TESTED on a radio
The E8 image holds the memory channels only (docs/code/main/eeprom.md). The EEPROM dump holds everything, including the
calibration table (EEPROM 0x000A..0x010E) and the region code (0x010F), which nothing else can back up.
It never sends a set form.
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


class Progress:
    """One status line: bar, percent, count, elapsed time, time left. On a terminal it redraws in place; otherwise it prints
    a line every 10 %."""

    def __init__(self, label, total, unit=""):
        self.label, self.total, self.unit = label, total, unit
        self.start, self.shown = time.time(), -1
        self.tty = sys.stdout.isatty()

    @staticmethod
    def _clock(sec):
        sec = int(sec)
        return f"{sec // 60}:{sec % 60:02d}"

    def update(self, done, note=""):
        pct = 100 * done // self.total if self.total else 100
        if not self.tty and (pct // 10 == self.shown or pct == 100 and done < self.total):
            return
        self.shown = pct // 10
        elapsed = time.time() - self.start
        left = elapsed * (self.total - done) / done if done else 0
        bar = "#" * (pct // 4) + "." * (25 - pct // 4)
        line = (f"  {self.label} [{bar}] {pct:3d}%  {done:,}/{self.total:,}{self.unit}  "
                f"elapsed {self._clock(elapsed)}  left {self._clock(left)}{('  ' + note) if note else ''}")
        print(("\r" + line + "\033[K") if self.tty else line, end="" if self.tty else "\n", flush=True)

    def finish(self, note=""):
        self.update(self.total, note)
        if self.tty:
            print()


def query(s, cmd, n=64, wait=0.4):
    s.reset_input_buffer()
    s.write(cmd)
    time.sleep(wait)
    return s.read(n)


def read_e8(s):
    s.reset_input_buffer()
    s.write(b"E8;")
    bar = Progress("E8", E8_LEN, " B")
    buf, t = b"", time.time()
    while len(buf) < E8_LEN and time.time() - t < 15:
        buf += s.read(min(512, E8_LEN - len(buf)))
        bar.update(len(buf))
    if len(buf) == E8_LEN:
        bar.finish()
    else:
        print()
    return buf


def spr_frame(addr):
    """SPR read of one EEPROM byte: 'SPR' aH aL x sum ';', sum = 8-bit sum of the six bytes before it (cat_SP_eeprom_byte)."""
    body = b"SPR" + bytes([addr >> 8, addr & 0xFF, 0])
    assert body[2:3] == b"R"   # upper-case R = read; 'W' would write EEPROM
    return body + bytes([sum(body) & 0xFF]) + b";"


def read_eeprom(s):
    image, missing = bytearray(EEPROM_END + 1), []
    s.timeout = 0.3
    bar = Progress("EEPROM", EEPROM_END + 1, " B")
    for a in range(EEPROM_END + 1):
        if a % 64 == 0:
            bar.update(a, f"{len(missing)} unread" if missing else "")
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
    bar.finish(f"{len(missing)} unread" if missing else "")
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
    steps = 3 if "--eeprom" in args else 2
    print(f"[1/{steps}] Identity and region code")

    ident = query(s, b"ID;")
    if not ident.startswith(b"ID0800"):
        print(f"No FT-710 on {port} at {baud} baud (ID; -> {ident!r}). Check the port and menu CAT-1 RATE.")
        return 1
    info = [f"date {datetime.datetime.now().isoformat(timespec='seconds')}", f"port {port} {baud}", f"ID; {ident.decode()}"]
    for c in (b"VE0;", b"VE1;", b"VE2;", b"VE3;", b"JP0710;"):
        info.append(f"{c.decode()} {query(s, c).decode(errors='replace')}")
    open(os.path.join(out, "info.txt"), "w").write("\n".join(info) + "\n")
    print("\n".join("  " + x for x in info))

    print(f"[2/{steps}] E8 memory-channel image")
    raw = read_e8(s)
    open(os.path.join(out, "e8_raw.bin"), "wb").write(raw)
    plain, problems = decode_e8(raw)
    if problems:
        print("E8 problems: " + "; ".join(problems))
        return 1
    open(os.path.join(out, "e8_plain.bin"), "wb").write(plain)
    print(f"  E8: {len(raw)} bytes, signature and checksum OK")

    if "--eeprom" in args:
        print(f"[3/{steps}] Full EEPROM dump (untested on a radio; takes several minutes)")
        image, missing = read_eeprom(s)
        open(os.path.join(out, "eeprom.bin"), "wb").write(image)
        open(os.path.join(out, "eeprom_missing.txt"), "w").write("".join(f"0x{a:04X}\n" for a in missing))
        print(f"  EEPROM: {len(image):,} bytes, {len(missing)} addresses unread (see eeprom_missing.txt)")
    s.close()
    print(f"Done. Saved in {out}/")
    return 0


if __name__ == "__main__":
    sys.exit(main())
