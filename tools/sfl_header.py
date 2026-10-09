#!/usr/bin/env python3
"""Parse and sanity-check the header of Yaesu FT-710 .SFL firmware files.

Usage: python3 -I tools/sfl_header.py Firmware/*.SFL

Layout (see docs/sfl-format.md):
  0x000-0x1FF  comment box: 8 lines x 64 bytes (62 ASCII chars + CRLF)
  0x200-0x23F  tag line: 64 bytes (62 chars + CRLF), whitespace-separated
               <tag> <total file length, decimal> <checksum, 8 hex digits>
  0x240-EOF    obfuscated payload
"""
import re
import sys

COMMENT_LEN = 512
TAGLINE_LEN = 64
PAYLOAD_OFF = COMMENT_LEN + TAGLINE_LEN
LINE_LEN = 64


def parse(data):
    if len(data) < PAYLOAD_OFF:
        raise ValueError("file shorter than SFL header")
    lines = [data[i:i + LINE_LEN] for i in range(0, COMMENT_LEN, LINE_LEN)]
    for i, line in enumerate(lines):
        if not (line.startswith(b"*") and line.endswith(b"*\r\n")):
            raise ValueError(f"comment line {i} malformed: {line!r}")
    fields = {}
    for line in lines:
        m = re.match(rb"\*\s+\[([A-Z ]+)\]\s*:\s*(.*?)\s*\*\r\n", line)
        if m:
            fields[m.group(1).decode()] = m.group(2).decode()
    title = lines[1][1:-3].strip().decode()
    tagline = data[COMMENT_LEN:PAYLOAD_OFF]
    if not tagline.endswith(b"\r\n"):
        raise ValueError(f"tag line not CRLF-terminated: {tagline!r}")
    tag, length, checksum = tagline.split()
    return {
        "title": title,
        "fields": fields,
        "tag": tag.decode(),
        "length": int(length),
        "checksum": int(checksum, 16),
        "payload_offset": PAYLOAD_OFF,
        "payload_length": len(data) - PAYLOAD_OFF,
    }


def main(paths):
    ok = True
    for path in paths:
        with open(path, "rb") as fh:
            data = fh.read()
        h = parse(data)
        length_ok = h["length"] == len(data)
        ok &= length_ok
        print(f"{path}: tag={h['tag']} title={h['title']!r} "
              f"version={h['fields'].get('FIRM VERSION')} date={h['fields'].get('DATE')} "
              f"length={h['length']} ({'= file size' if length_ok else f'!= file size {len(data)}'}) "
              f"checksum={h['checksum']:08X} payload@0x{h['payload_offset']:X}+{h['payload_length']}")
    return 0 if ok else 1


if __name__ == "__main__":
    if len(sys.argv) < 2:
        sys.exit(__doc__)
    sys.exit(main(sys.argv[1:]))
