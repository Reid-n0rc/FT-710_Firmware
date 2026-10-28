#!/usr/bin/env python3
"""Read-only CAT backup of an FT-710: identity, region code, E8 memory image and (optionally) the raw EEPROM.

Usage: python3 -I tools/cat_backup.py PORT [OUTDIR] [--baud 38400] [--eeprom]
       python3 -I tools/cat_backup.py --decode E8_RAW.BIN      (offline check of a saved E8 frame)
       python3 -I tools/cat_backup.py --verify OUTDIR          (check a backup against its SHA256SUMS)

PORT is the CP210x "Enhanced" COM port (macOS /dev/cu.SLAB_USBtoUART, Linux /dev/ttyUSB0, Windows COMx); the baud rate must match
menu CAT-1 RATE. OUTDIR defaults to backup-<date>. Everything this script sends is a read:
  ID; VE0;..VE3; JP0710;      -> info.txt                (tested on a radio, 2026-10-28)
  E8;                         -> e8_raw.bin, e8_plain.bin (tested on a radio, 2026-10-28)
  SPR<aH><aL><sum>;           -> eeprom.bin, eeprom_missing.txt   only with --eeprom (tested on a radio, 2026-10-28)
The E8 image holds the memory channels only (docs/code/main/eeprom.md). The EEPROM dump holds everything, including the
calibration table (EEPROM 0x000A..0x010E) and the region code (0x010F), which nothing else can back up.
It never sends a set form: every frame goes through send(), which refuses anything that is not one of the reads above.
The port is opened with RTS and DTR off, because the radio can be set to key the transmitter from them (RPTT SELECT,
PC KEYING).
Checks: the JP0710 region code against its complement bytes, the E8 signature and sum, each SPR reply's sum and address, and
(with --eeprom) the region code in the dump against the JP0710 reply. Every file is listed with its SHA-256 in SHA256SUMS
(the format of `shasum -a 256 -c` / `sha256sum -c`), so --verify can tell later whether a file has changed.
Everything the script reports, with timestamps, goes to backup.log in OUTDIR: warnings (a retried or failed read and its
reason: no reply, ?;, short reply, wrong address, bad checksum), errors, and the traceback of any crash or interruption.
eeprom_missing.txt gives the reason for each unread address. The EEPROM dump stops early if the radio answers none of the
first 32 reads.
See docs/cat-undocumented.md for what to back up, why, and how to restore.
"""
import datetime
import hashlib
import os
import sys
import time

E8_LEN = 10674          # "E8" + 5 header bytes + 10665 data + sum + ";"
E8_DATA = 10665
EEPROM_END = 0x5836     # last EEPROM address (RAM mirror 0x464F..0x9E85)


def parse_jp(reply):
    """JP0710 read reply: 'JP0710' HHLL ~H~L + 10 hex digits of EEPROM header bytes 0..4 + ';' (25 chars).
    Return (code, stamp, problems); code is the 16-bit region code, stamp the header bytes as hex."""
    text = reply.decode(errors="replace")
    if len(text) != 25 or not text.startswith("JP0710") or not text.endswith(";"):
        return None, None, [f"unexpected reply {text!r}"]
    try:
        hi, lo, nhi, nlo = (int(text[i:i + 2], 16) for i in (6, 8, 10, 12))
        int(text[14:24], 16)
    except ValueError:
        return None, None, [f"non-hex digits in {text!r}"]
    problems = [] if (nhi, nlo) == (hi ^ 0xFF, lo ^ 0xFF) else ["check bytes are not the complement of the code"]
    return (hi << 8) | lo, text[14:24], problems


def write_sums(out):
    names = sorted(n for n in os.listdir(out) if n not in ("SHA256SUMS", "backup.log") and os.path.isfile(os.path.join(out, n)))
    with open(os.path.join(out, "SHA256SUMS"), "w") as f:
        for n in names:
            f.write(f"{hashlib.sha256(open(os.path.join(out, n), 'rb').read()).hexdigest()}  {n}\n")
    return len(names)


def verify_sums(out):
    bad = 0
    for line in open(os.path.join(out, "SHA256SUMS")):
        digest, name = line.rstrip("\n").split("  ", 1)
        path = os.path.join(out, name)
        ok = os.path.isfile(path) and hashlib.sha256(open(path, "rb").read()).hexdigest() == digest
        bad += not ok
        print(f"  {'OK     ' if ok else 'CHANGED' if os.path.isfile(path) else 'MISSING'}  {name}")
    print("All files match SHA256SUMS." if not bad else f"{bad} file(s) do not match SHA256SUMS.")
    return 1 if bad else 0


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


READS = {b"ID;", b"VE0;", b"VE1;", b"VE2;", b"VE3;", b"JP0710;", b"E8;"}


def is_spr_read(frame):
    """A 7-byte SPR read: 'SPR' aH aL sum ';' with a correct sum. The firmware writes EEPROM only for 'SPW'."""
    return (len(frame) == 7 and frame[:3] == b"SPR" and frame[6:] == b";"
            and sum(frame[:5]) & 0xFF == frame[5])


def send(s, frame):
    """The only way this script writes to the port. Anything but the known read frames stops the program."""
    if frame not in READS and not is_spr_read(frame):
        raise SystemExit(f"refusing to send {frame!r}: not a read-only frame")
    s.write(frame)


def open_port(port, baud):
    import serial
    s = serial.Serial()
    s.port, s.baudrate, s.timeout = port, baud, 0.6
    s.rts = False   # set before open, so the lines are never raised: RTS/DTR can be PTT or CW keying on the radio
    s.dtr = False
    s.open()
    return s


def query(s, cmd, n=64, wait=0.4):
    s.reset_input_buffer()
    send(s, cmd)
    time.sleep(wait)
    return s.read(n)


def read_e8(s):
    s.reset_input_buffer()
    send(s, b"E8;")
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
    """SPR read of one EEPROM byte: 'SPR' aH aL sum ';' (7 bytes), sum = 8-bit sum of the five bytes before it.
    The receiver takes SPR frames as exactly 7 bytes (cat_rx_byte_hook); the reply is 'SPR' aH aL data sum ';' (8 bytes),
    sum over the six bytes before it (cat_SP_eeprom_byte)."""
    body = b"SPR" + bytes([addr >> 8, addr & 0xFF])
    assert body[2:3] == b"R"   # upper-case R = read; 'W' would write EEPROM
    return body + bytes([sum(body) & 0xFF]) + b";"


class Log:
    """Writes timestamped lines to OUTDIR/backup.log and echoes them to the screen. Problems are marked WARNING or ERROR."""

    def __init__(self, path):
        self.f = open(path, "a", encoding="utf-8")
        self.errors = self.warnings = 0

    def _write(self, level, msg, echo):
        stamp = datetime.datetime.now().isoformat(timespec="milliseconds")
        for line in str(msg).splitlines() or [""]:
            self.f.write(f"{stamp} {level:7s} {line}\n")
        self.f.flush()
        if echo:
            print(msg if level == "INFO" else f"  {level}: {str(msg).strip()}", flush=True)

    def info(self, msg, echo=True):
        self._write("INFO", msg, echo)

    def warning(self, msg, echo=True):
        self.warnings += 1
        self._write("WARNING", msg, echo)

    def error(self, msg, echo=True):
        self.errors += 1
        self._write("ERROR", msg, echo)


def spr_problem(frame, reply):
    """Why an SPR reply is unusable, or None if it is good."""
    if not reply:
        return "no reply"
    if reply == b"?;":
        return "radio answered ?; (error)"
    if len(reply) != 8:
        return f"short reply ({len(reply)} bytes: {reply.hex(' ')})"
    if reply[:5] != frame[:5]:
        return f"reply is for another address ({reply.hex(' ')})"
    if reply[7:] != b";" or sum(reply[:6]) & 0xFF != reply[6]:
        return f"bad checksum ({reply.hex(' ')})"
    return None


DETAIL_LIMIT = 50   # failed attempts logged one by one; after that only counted
GIVE_UP_AFTER = 32  # stop if this many addresses in a row fail from the start: the radio is not answering SPR


def read_eeprom(s, log):
    image, missing, reasons, recovered, details = bytearray(EEPROM_END + 1), {}, {}, 0, 0
    s.timeout = 0.3
    bar = Progress("EEPROM", EEPROM_END + 1, " B")
    for a in range(EEPROM_END + 1):
        if a % 64 == 0:
            bar.update(a, f"{len(missing)} unread" if missing else "")
        f = spr_frame(a)
        why = None
        for attempt in (1, 2):
            s.reset_input_buffer()
            send(s, f)
            r = s.read(8)
            why = spr_problem(f, r)
            if why is None:
                recovered += attempt == 2
                break
            reasons[why.split(" (")[0]] = reasons.get(why.split(" (")[0], 0) + 1
            if details < DETAIL_LIMIT:
                details += 1
                log.warning(f"EEPROM 0x{a:04X} attempt {attempt}: {why}", echo=False)
        if why is not None:
            missing[a] = why
            if len(missing) == GIVE_UP_AFTER and a == GIVE_UP_AFTER - 1:
                print()
                log.error(f"the first {GIVE_UP_AFTER} addresses all failed ({why}); the radio is not answering SPR. Stopping.")
                return None, missing
            continue
        image[a] = r[5]
    bar.finish(f"{len(missing)} unread" if missing else "")
    if reasons:
        log.info("EEPROM failed attempts by reason: " + ", ".join(f"{k}: {v}" for k, v in sorted(reasons.items())), echo=False)
    if recovered:
        log.info(f"EEPROM: {recovered} addresses needed a second attempt", echo=False)
    return bytes(image), missing


def backup(args, log, out):
    baud = int(args[args.index("--baud") + 1]) if "--baud" in args else 38400
    port = [a for i, a in enumerate(args) if not a.startswith("-") and (i == 0 or args[i - 1] != "--baud")][0]
    steps = 3 if "--eeprom" in args else 2
    log.info(f"cat_backup.py, port {port}, {baud} baud, options {' '.join(a for a in args if a.startswith('-')) or 'none'}", echo=False)
    s = open_port(port, baud)
    try:
        log.info(f"[1/{steps}] Identity and region code")
        ident = query(s, b"ID;")
        if not ident.startswith(b"ID0800"):
            log.error(f"no FT-710 on {port} at {baud} baud (ID; -> {ident!r}). Check the port and menu CAT-1 RATE.")
            return 1
        info = [f"date {datetime.datetime.now().isoformat(timespec='seconds')}", f"port {port} {baud}", f"ID; {ident.decode()}"]
        for c in (b"VE0;", b"VE1;", b"VE2;", b"VE3;"):
            r = query(s, c)
            info.append(f"{c.decode()} {r.decode(errors='replace')}")
            if not r.startswith(c[:3]):
                log.warning(f"{c.decode()} answered {r!r}")
        code = None
        for attempt in (1, 2):
            jp = query(s, b"JP0710;")
            code, stamp, problems = parse_jp(jp)
            if not problems:
                break
            log.warning(f"JP0710; attempt {attempt}: " + "; ".join(problems))
        info.append(f"JP0710; {jp.decode(errors='replace')}")
        if problems:
            log.error("region code could not be verified: " + "; ".join(problems))
            info.append("region code UNVERIFIED: " + "; ".join(problems))
            code = None
        else:
            info.append(f"region code 0x{code:04X} (check bytes OK), EEPROM header stamp {stamp}")
        open(os.path.join(out, "info.txt"), "w").write("\n".join(info) + "\n")
        log.info("\n".join("  " + x for x in info))

        log.info(f"[2/{steps}] E8 memory-channel image")
        raw = read_e8(s)
        open(os.path.join(out, "e8_raw.bin"), "wb").write(raw)
        plain, problems = decode_e8(raw)
        if problems:
            log.error("E8: " + "; ".join(problems))
            return 1
        open(os.path.join(out, "e8_plain.bin"), "wb").write(plain)
        log.info(f"  E8: {len(raw)} bytes, signature and checksum OK")

        if "--eeprom" in args:
            log.info(f"[3/{steps}] Full EEPROM dump (about 2 minutes)")
            started = time.time()
            image, missing = read_eeprom(s, log)
            with open(os.path.join(out, "eeprom_missing.txt"), "w") as f:
                f.write("".join(f"0x{a:04X}  {why}\n" for a, why in sorted(missing.items())))
            if image is None:
                return 1
            open(os.path.join(out, "eeprom.bin"), "wb").write(image)
            msg = f"  EEPROM: {len(image):,} bytes in {time.time() - started:.0f} s, {len(missing)} addresses unread"
            (log.warning if missing else log.info)(msg + (" (see eeprom_missing.txt)" if missing else ""))
            dump_code = (image[0x010F] << 8) | image[0x0110]
            if code is None or 0x010F in missing or 0x0110 in missing:
                log.warning("region code in the dump could not be compared with JP0710")
            elif dump_code == code:
                log.info(f"  Region code in the dump (0x{dump_code:04X}) matches JP0710.")
            else:
                log.error(f"region code in the dump (0x{dump_code:04X}) differs from JP0710 (0x{code:04X})")
    finally:
        s.close()
    return 0


def main():
    args = sys.argv[1:]
    if args[:1] == ["--decode"]:
        plain, problems = decode_e8(open(args[1], "rb").read())
        print("E8 OK" if not problems else "E8 problems: " + "; ".join(problems))
        return 0 if not problems else 1
    if args[:1] == ["--verify"]:
        return verify_sums(args[1])
    if not args or args[0].startswith("-"):
        print(__doc__)
        return 2
    pos = [a for i, a in enumerate(args) if not a.startswith("-") and (i == 0 or args[i - 1] != "--baud")]
    out = pos[1] if len(pos) > 1 else "backup-" + datetime.datetime.now().strftime("%Y%m%d-%H%M")
    os.makedirs(out, exist_ok=True)
    log = Log(os.path.join(out, "backup.log"))
    try:
        rc = backup(args, log, out)
    except KeyboardInterrupt:
        print()
        log.error("interrupted by the user; the backup is incomplete")
        rc = 1
    except SystemExit as e:
        log.error(str(e))
        rc = 1
    except Exception:
        import traceback
        log.error("unexpected failure:\n" + traceback.format_exc().rstrip())
        rc = 1
    n = write_sums(out)
    log.info(f"  SHA-256 of {n} files written to SHA256SUMS (backup.log is not included: it keeps growing)")
    summary = f"{log.errors} error(s), {log.warnings} warning(s)"
    if rc == 0 and not log.errors:
        log.info(f"Done, {summary}. Saved in {out}/  (check later with --verify {out})")
    else:
        log.info(f"FAILED, {summary}. Details in {os.path.join(out, 'backup.log')}")
        rc = rc or 1
    return rc


if __name__ == "__main__":
    sys.exit(main())
