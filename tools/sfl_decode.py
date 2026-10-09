#!/usr/bin/env python3
"""Decode a Yaesu FT-710 .SFL firmware file into a raw binary.

Usage: python3 -I tools/sfl_decode.py [--raw] Firmware/X.SFL build/X.bin

Payload encoding (see docs/sfl-format.md, "Payload encoding (T04)"):
  plain[i] = (enc[i] - KEY[i % 43]) & 0xFF,  i counted from payload start (0x240)
KEY is a 43-byte permutation of 1..43, taken from the DISPLAY firmware's .data
section (decoder routine at VMA 0x2011497C in DISPLAY V01-08).

Checksum (tag-line field): CRC-32/ISO-HDLC (zlib) over the *encoded* payload,
continued over the 4 salt bytes A6 EC 9E 13 (DISPLAY routine at 0x20114A64).

What the decoded payload contains depends on the image:
  MC (MAIN)    Motorola S-record text (Renesas RX). Flattened to a binary of the
               main code cluster (0xFFF80000-0xFFFFFFFF, gaps = 0xFF); other
               clusters (option-setting memory at 0xFE7F5D00) go to
               <out>.<ADDR>.bin.
  PC (DISPLAY) raw ARM binary, load address 0x20100000 (Renesas RZ/A-class).
  ID (IFDSP)   raw binary, FlexSPI XIP image based at 0x08000000 (NXP i.MX RT6xx).
  SR (SDR)     one line of ASCII hex; converted to a Xilinx 7-series bitstream.
With --raw, the decoded payload is written verbatim and no conversion is done.
"""
import os
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sfl_header  # noqa: E402  (our own sibling module)

KEY = bytes.fromhex(
    "1e271b1211161917242529"
    "1c0d0b06040301020507"
    "0c0e0f181d20222a2b08"
    "090a101314151a1f2128"
    "2326"
)
CRC_SALT = bytes.fromhex("a6ec9e13")
CLUSTER_GAP = 0x100000  # S-record address gaps larger than this start a new output file

assert sorted(KEY) == list(range(1, 44))


def decode(payload):
    n = len(KEY)
    reps = len(payload) // n + 1
    stream = (KEY * reps)[:len(payload)]
    return bytes((c - k) & 0xFF for c, k in zip(payload, stream))


def sfl_crc(payload):
    return zlib.crc32(CRC_SALT, zlib.crc32(payload)) & 0xFFFFFFFF


def parse_srec(text):
    """Return (list of (addr, bytes), entry or None). Verifies record checksums."""
    recs, entry = [], None
    for lineno, line in enumerate(text.split(b"\n"), 1):
        line = line.strip()
        if not line:
            continue
        if line[:1] != b"S":
            raise ValueError(f"S-record line {lineno}: bad start {line[:8]!r}")
        t = line[1:2]
        b = bytes.fromhex(line[2:].decode("ascii"))
        if b[0] != len(b) - 1 or (sum(b) & 0xFF) != 0xFF:
            raise ValueError(f"S-record line {lineno}: bad length/checksum")
        alen = {b"0": 2, b"1": 2, b"2": 3, b"3": 4, b"5": 2, b"6": 3,
                b"7": 4, b"8": 3, b"9": 2}[t]
        addr = int.from_bytes(b[1:1 + alen], "big")
        if t in b"123":
            recs.append((addr, b[1 + alen:-1]))
        elif t in b"789":
            entry = addr
    return recs, entry


def flatten(recs):
    """Group records into clusters; return list of (base, bytearray)."""
    recs = sorted(recs)
    clusters = []
    for addr, data in recs:
        if clusters and addr - clusters[-1][1] <= CLUSTER_GAP:
            clusters[-1][1] = max(clusters[-1][1], addr + len(data))
            clusters[-1][2].append((addr, data))
        else:
            clusters.append([addr, addr + len(data), [(addr, data)]])
    out = []
    for base, end, items in clusters:
        buf = bytearray(b"\xff" * (end - base))
        for addr, data in items:
            buf[addr - base:addr - base + len(data)] = data
        out.append((base, buf))
    return out


def main(argv):
    raw = "--raw" in argv
    args = [a for a in argv if a != "--raw"]
    if len(args) != 2:
        sys.exit(__doc__)
    src, dst = args
    with open(src, "rb") as fh:
        data = fh.read()
    h = sfl_header.parse(data)
    if h["length"] != len(data):
        print(f"warning: header length {h['length']} != file size {len(data)}", file=sys.stderr)
    payload = data[h["payload_offset"]:]
    crc = sfl_crc(payload)
    crc_ok = crc == h["checksum"]
    print(f"{src}: tag={h['tag']} version={h['fields'].get('FIRM VERSION')} "
          f"checksum {h['checksum']:08X} {'OK' if crc_ok else f'MISMATCH (computed {crc:08X})'}")
    plain = decode(payload)
    os.makedirs(os.path.dirname(os.path.abspath(dst)), exist_ok=True)

    if raw:
        outputs = [(dst, plain, None)]
    elif plain.startswith(b"S0"):
        recs, entry = parse_srec(plain)
        clusters = flatten(recs)
        main_base, main_buf = max(clusters, key=lambda c: len(c[1]))
        outputs = [(dst, main_buf, main_base)]
        for base, buf in clusters:
            if base != main_base:
                outputs.append((f"{dst}.{base:08X}.bin", buf, base))
        print(f"  S-record: {len(recs)} data records, entry 0x{entry:08X}" if entry is not None
              else f"  S-record: {len(recs)} data records")
    elif h["tag"] == "SR" and set(plain.strip()) <= set(b"0123456789abcdefABCDEF"):
        outputs = [(dst, bytes.fromhex(plain.strip().decode("ascii")), None)]
        print("  ASCII hex converted to binary")
    else:
        outputs = [(dst, plain, None)]

    for path, buf, base in outputs:
        with open(path, "wb") as fh:
            fh.write(buf)
        where = f" @ 0x{base:08X}" if base is not None else ""
        print(f"  wrote {path} ({len(buf)} bytes{where})")
    return 0 if crc_ok else 1


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
