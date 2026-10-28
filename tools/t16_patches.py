#!/usr/bin/env python3
"""Build and verify the T16 DISPLAY patches as SFL files (build/ only, never flashed).

Usage: python3 -I tools/t16_patches.py [PATCH ...]      (default: all)
       python3 -I tools/t16_patches.py --list

Patches (docs/patches/README.md):
  banner      bootloader_screen title "YAESU FT-710 BOOT LOADER V01-02" -> "... T16-01"
              (6 bytes in .rodata at VMA 0x204280D5, file offset 0x3280D5)
  debuggate   debug_enabled 0x20111098: `movne r0,#0` at 0x201110AC -> `movne r0,#1`
              (1 byte at file offset 0x110AC), opens the USB-keyboard debug console

For each patch the script
  1. decodes Firmware/FT-710_DISPLAY_V0108.SFL and checks its CRC,
  2. checks the expected original bytes at each offset (refuses on mismatch),
  3. writes the patched binary and encodes it with sfl_encode (comment box copied,
     DATE field set to the build date) into build/t16/patch/<name>/,
  4. decodes the new SFL again and compares it with the patched binary,
  5. runs sfl_encode.check (the update loader's acceptance rules),
  6. byte-diffs original vs patched (must be exactly the patched bytes),
  7. diffs arm-none-eabi-objdump listings of the two binaries (if installed),
  8. prints the decoded-image CRC-32 that the loader would write into the bank flag.
Nothing is sent to the radio.
"""
import contextlib
import datetime
import io
import os
import shutil
import subprocess
import sys
import zlib

TOOLS = os.path.dirname(os.path.abspath(__file__))
sys.path.insert(0, TOOLS)
import sfl_decode  # noqa: E402
import sfl_encode  # noqa: E402
import sfl_header  # noqa: E402

ROOT = os.path.dirname(TOOLS).split("/.claude/worktrees/")[0]
SRC = os.path.join(ROOT, "Firmware", "FT-710_DISPLAY_V0108.SFL")
OUT = os.path.join(ROOT, "build", "t16", "patch")
BASE = 0x20100000

# (file offset, original bytes, new bytes). Only the patched bytes are recorded here.
PATCHES = {
    "banner": [(0x3280D5, b"V01-02", b"T16-01")],
    "debuggate": [(0x110AC, bytes.fromhex("0000a013"), bytes.fromhex("0100a013"))],
}


def objdump(path, start, stop):
    tool = shutil.which("arm-none-eabi-objdump")
    if not tool:
        return None
    r = subprocess.run([tool, "-D", "-b", "binary", "-marm", f"--adjust-vma=0x{BASE:X}",
                        f"--start-address=0x{start:X}", f"--stop-address=0x{stop:X}", path],
                       capture_output=True, text=True, check=True, timeout=600)
    return [ln for ln in r.stdout.splitlines() if ln[:1] == " " or ln[:2] == "20"]


def build(name):
    edits = PATCHES[name]
    outdir = os.path.join(OUT, name)
    os.makedirs(outdir, exist_ok=True)
    with open(SRC, "rb") as fh:
        sfl = fh.read()
    h = sfl_header.parse(sfl)
    payload = sfl[sfl_header.PAYLOAD_OFF:]
    assert sfl_decode.sfl_crc(payload) == h["checksum"], "original CRC mismatch"
    orig = sfl_decode.decode(payload)
    img = bytearray(orig)
    for off, old, new in edits:
        if img[off:off + len(old)] != old:
            sys.exit(f"{name}: unexpected bytes at 0x{off:X}: {bytes(img[off:off + len(old)]).hex()}")
        assert len(old) == len(new)
        img[off:off + len(new)] = new
    orig_bin = os.path.join(outdir, "orig.bin")
    patched_bin = os.path.join(outdir, "patched.bin")
    with open(orig_bin, "wb") as fh:
        fh.write(orig)
    with open(patched_bin, "wb") as fh:
        fh.write(img)

    dst = os.path.join(outdir, os.path.basename(SRC))
    f = h["fields"]
    cline = sfl[6 * 64 + 1:7 * 64 - 3].decode().strip()
    with contextlib.redirect_stdout(io.StringIO()):
        sfl_encode.main(["--header-from", SRC, "--tag", "PC", "--title", h["title"],
                         "--file-name", f["FILE NAME"], "--product", f["PRODUCT NAME"],
                         "--version", f["FIRM VERSION"],
                         "--date", datetime.date.today().strftime("%Y/%m/%d"),
                         "--copyright", cline, patched_bin, dst])
    with open(dst, "rb") as fh:
        new_sfl = fh.read()
    nh = sfl_header.parse(new_sfl)
    back = sfl_decode.decode(new_sfl[sfl_header.PAYLOAD_OFF:])

    print(f"== {name}: {dst}")
    print(f"  SFL size {len(new_sfl)} (orig {len(sfl)}), tag {nh['tag']}, CRC {nh['checksum']:08X} (orig {h['checksum']:08X})")
    ok = back == bytes(img)
    print(f"  decode(new SFL) == patched binary: {ok}")
    res = sfl_encode.check(new_sfl, dst)
    for good, rule in res:
        print(f"  {'ok  ' if good else 'FAIL'} {rule}")
    ok &= all(g for g, _ in res)
    diff = [i for i in range(len(orig)) if orig[i] != img[i]]
    want = sorted(i for off, old, new in edits for i in range(off, off + len(new)) if old[i - off] != new[i - off])
    print(f"  byte diff: {len(diff)} byte(s) at " + ", ".join(f"0x{i:X} {orig[i]:02X}->{img[i]:02X}" for i in diff))
    ok &= diff == want
    hdr_diff = [i for i in range(sfl_header.COMMENT_LEN) if sfl[i] != new_sfl[i]]
    print(f"  comment box differs in {len(hdr_diff)} byte(s) (DATE field only)" if hdr_diff else "  comment box identical")
    for off, old, new in edits:
        start = (off & ~3) - 8
        a, b = objdump(orig_bin, BASE + start, BASE + off + len(new) + 8), objdump(patched_bin, BASE + start, BASE + off + len(new) + 8)
        if a is None:
            print("  (arm-none-eabi-objdump not found; listing diff skipped)")
            break
        print(f"  listing around VMA 0x{BASE + off:08X}:")
        for la, lb in zip(a, b):
            print(f"    {'  ' if la == lb else '- '}{la.strip()}")
            if la != lb:
                print(f"    + {lb.strip()}")
    full_a = objdump(orig_bin, BASE, BASE + len(orig))
    if full_a is not None:
        full_b = objdump(patched_bin, BASE, BASE + len(img))
        nd = sum(1 for la, lb in zip(full_a, full_b) if la != lb)
        print(f"  whole-image listing: {len(full_a)} lines, {nd} line(s) differ")
        ok &= len(full_a) == len(full_b) and nd == len({i & ~3 for i in diff})
    print(f"  CRC-32 (zlib) of the decoded image, input to the bank flag +0x10 (update.md s.6): {zlib.crc32(bytes(img)):08X}")
    print(f"  RESULT: {'PASS' if ok else 'FAIL'}")
    return ok


def main(argv):
    if "--list" in argv:
        for k, v in PATCHES.items():
            print(k, [(hex(o), a.hex(), b.hex()) for o, a, b in v])
        return 0
    names = argv or list(PATCHES)
    return 0 if all([build(n) for n in names]) else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
