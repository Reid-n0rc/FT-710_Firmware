#!/usr/bin/env python3
"""Encode a plaintext firmware image into a Yaesu FT-710 .SFL file (inverse of sfl_decode.py).

Usage:
  python3 -I tools/sfl_encode.py [options] INPUT OUT.SFL
  python3 -I tools/sfl_encode.py --check FILE.SFL [FILE.SFL ...]

INPUT is one of:
  * the decoded payload verbatim (`sfl_decode.py --raw` output), with --raw;
  * the converted image that `sfl_decode.py` writes without --raw:
      MC (MAIN)    flat binary at --base (default 0xFFF80000); sibling files
                   INPUT.<ADDR>.bin (e.g. the option-setting memory
                   .FE7F5D00.bin) are picked up as extra clusters. Converted back
                   to S-records. With --layout-from (default: the --header-from
                   file) the original record layout, S0 and S7 records are
                   reused, so an unpatched image re-encodes byte for byte.
                   An input that already starts with "S0" is used as S-record text.
      PC (DISPLAY) raw ARM binary, used as is
      ID (IFDSP)   raw binary, used as is
      SR (SDR)     Xilinx bitstream binary, converted to one line of lowercase
                   ASCII hex + CRLF

Header (docs/sfl-format.md): 8-line comment box (62 chars + CRLF each), then
the 64-byte tag line "<tag> <total file length> <CRC>" with fields at columns
0/16/32. With --header-from ORIG.SFL the comment box and tag are copied from
ORIG (individual fields can still be overridden). The CRC is zlib CRC-32 over
the *encoded* payload continued over the salt A6 EC 9E 13.

Payload encoding: enc[i] = (plain[i] + KEY[i % 43]) & 0xFF (DISPLAY routine
FUN_201149e0, the twin of sfl_decode 0x2011497C).

--check runs the acceptance rules of the DISPLAY update loader
(docs/code/display/update.md section 1) against finished SFL files and
exits non-zero if any rule fails.

Options:
  --tag MC|PC|ID|SR       image type (default: from --header-from)
  --header-from FILE      copy comment box and tag from this SFL
  --layout-from FILE      MAIN only: S-record layout template (default --header-from)
  --raw                   INPUT is the decoded payload verbatim
  --base ADDR             MAIN binary base (default 0xFFF80000)
  --title/--file-name/--product/--version/--date/--copyright TEXT
                          comment-box fields (default: copied, or generated)
  --force                 write even if an acceptance rule fails

This tool never talks to the radio. Do not publish its output (AGENTS.md).
"""
import datetime
import glob
import os
import re
import sys
import zlib

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import sfl_decode  # noqa: E402  (our own sibling module)
import sfl_header  # noqa: E402

KEY = sfl_decode.KEY
CRC_SALT = sfl_decode.CRC_SALT
LINE = 62
TITLES = {"MC": "MAIN CPU FIRMWARE", "PC": "PANEL CPU FIRMWARE",
          "ID": "IFDSP FIRMWARE", "SR": "SDR FIRMWARE"}
IMG_NAMES = {"MC": "MAIN", "PC": "DISPLAY", "ID": "IFDSP", "SR": "SDR"}
MAIN_BASE = 0xFFF80000
SDR_FILE_SIZE = 0x43075A          # fwobj_sdr_run 0x201602AC: exact SFL size
DISPLAY_BANK = 6 * 1024 * 1024    # bank 1 at 0x400000, bank 2 at 0xA00000
IFDSP_ERASE = 0xA0000             # dsp_isp_erase_region 0x2010B0F4
FIELD_KEYS = [("file_name", "FILE NAME"), ("product", "PRODUCT NAME"),
              ("version", "FIRM VERSION"), ("date", "DATE")]


def encode(plain):
    n = len(KEY)
    stream = (KEY * (len(plain) // n + 1))[:len(plain)]
    return bytes((c + k) & 0xFF for c, k in zip(plain, stream))


def box_line(text):
    s = "*  " + text
    if len(s) > LINE - 1:
        raise ValueError(f"comment line too long: {text!r}")
    return (s.ljust(LINE - 1) + "*\r\n").encode("ascii")


def make_box(title, fields, copyright_text):
    rule = ("*" * LINE + "\r\n").encode("ascii")
    out = [rule, box_line(title)]
    for _, name in FIELD_KEYS:
        out.append(box_line(f"{'[' + name + ']':<15}: {fields[name]}"))
    out.append(box_line(copyright_text))
    out.append(rule)
    return b"".join(out)


def make_tagline(tag, length, crc):
    s = f"{tag:<16}{length:<16}{crc:08X}"
    return (s.ljust(LINE) + "\r\n").encode("ascii")


# ---------------------------------------------------------------- S-records

def srec_line(rtype, addr, data, alen):
    body = bytes([alen + len(data) + 1]) + addr.to_bytes(alen, "big") + data
    return b"S" + rtype + body.hex().upper().encode() + b"%02X" % (~sum(body) & 0xFF) + b"\r\n"


def srec_template(text):
    """Return (S0 line, [(addr, len)], terminator line) from S-record text."""
    s0, layout, term = None, [], None
    for line in text.split(b"\r\n"):
        if not line:
            continue
        t = line[1:2]
        if t == b"0":
            s0 = line + b"\r\n"
        elif t == b"3":
            b = bytes.fromhex(line[2:].decode())
            layout.append((int.from_bytes(b[1:5], "big"), len(b) - 6))
        elif t in b"789":
            term = line + b"\r\n"
        else:
            raise ValueError(f"unsupported S-record type in template: {line[:4]!r}")
    return s0, layout, term


def binary_to_srec(clusters, template_text=None):
    """clusters: list of (base, bytes). Returns S-record text."""
    def byte_at(addr):
        for base, buf in clusters:
            if base <= addr < base + len(buf):
                return buf[addr - base]
        raise KeyError(addr)

    if template_text is None:
        # Generic layout: 16-byte S3 records. All-0xFF chunks are skipped in the
        # main (code flash) cluster only; small extra clusters such as the
        # option-setting memory are always written in full.
        out = [srec_line(b"0", 0, b"", 2)]
        main = max(clusters, key=lambda c: len(c[1]))
        for base, buf in sorted(clusters):
            for off in range(0, len(buf), 16):
                chunk = bytes(buf[off:off + 16])
                if base != main[0] or chunk != b"\xff" * len(chunk):
                    out.append(srec_line(b"3", base + off, chunk, 4))
        entry = int.from_bytes(main[1][-4:], "little") if main[0] + len(main[1]) == 1 << 32 else 0
        out.append(srec_line(b"7", entry, b"", 4))
        return b"".join(out)

    s0, layout, term = srec_template(template_text)
    covered = set()
    out = [s0]
    for addr, n in layout:
        out.append(srec_line(b"3", addr, bytes(byte_at(a) for a in range(addr, addr + n)), 4))
        covered.update(range(addr, addr + n))
    # Bytes that differ from 0xFF but are not covered by the layout would be lost.
    lost = [base + i for base, buf in clusters for i, c in enumerate(buf)
            if c != 0xFF and base + i not in covered]
    if lost:
        raise ValueError(f"{len(lost)} non-0xFF bytes outside the template layout "
                         f"(first at 0x{lost[0]:08X}); use --layout-from '' for a generic layout")
    out.append(term)
    return b"".join(out)


# ------------------------------------------------------------- acceptance

def check(data, path=None):
    """Return a list of (ok, rule) for the DISPLAY update loader's checks."""
    res = []
    try:
        h = sfl_header.parse(data)
    except ValueError as e:
        return [(False, f"header parse: {e}")]
    tagline = data[512:576]
    res.append((len(tagline) == 64 and b"\0" not in tagline and tagline.endswith(b"\r\n"),
                "tag line is 64 bytes, CRLF, no NUL (sfl_read_header 0x20114CA0)"))
    tok = tagline.split()
    res.append((len(tok) >= 3 and re.fullmatch(rb"[0-9A-Fa-f]{1,8}", tok[2]) is not None,
                "3rd token is <= 8 hex digits"))
    payload = data[576:]
    crc = sfl_decode.sfl_crc(payload)
    res.append((crc == h["checksum"], f"salted CRC-32 {crc:08X} == header {h['checksum']:08X} (sfl_crc 0x20114A64)"))
    # The loader ignores tag and length, but sfl_header / our tools rely on them.
    res.append((h["length"] == len(data), "length field == file size (not checked by the radio)"))
    res.append((h["tag"] in TITLES, f"tag {h['tag']} known (not checked by the radio)"))
    block3 = data[3 * 64:4 * 64]
    i = block3.find(b" : ")
    res.append((not (i >= 0 and block3[i + 3:i + 11] == b"#UP0    "),
                "comment block 3 is not '#UP0' (loader-write trigger, fwobj_display_run 0x201607E8)"))
    tag = h["tag"]
    if path is not None:
        base = os.path.basename(path)
        img = IMG_NAMES.get(tag, "?")
        res.append((re.fullmatch(rf"FT-710_{img}_V....\.sfl", base, re.I) is not None,
                    f"file name FT-710_{img}_V????.SFL (fwname_pattern_match 0x20163600)"))
    plain = sfl_decode.decode(payload)
    if tag == "SR":
        res.append((len(data) == SDR_FILE_SIZE, f"SDR file size {len(data)} == 0x43075A (fwobj_sdr_run 0x201602AC)"))
        body = plain.rstrip(b"\r\n")
        res.append((re.fullmatch(rb"[0-9a-fA-F]*", body) is not None and len(body) % 2 == 0,
                    "SDR payload is one line of hex"))
    elif tag == "PC":
        res.append((len(data) >= 0x242, "DISPLAY file size >= 0x242"))
        res.append((len(payload) <= DISPLAY_BANK, f"DISPLAY payload {len(payload)} <= 6 MiB bank"))
        res.append((plain[3:4] == b"\xea", "DISPLAY offset 0 is an ARM B (vector table)"))
    elif tag == "ID":
        res.append((len(payload) <= IFDSP_ERASE, f"IFDSP payload {len(payload)} <= 0xA0000 erase region"))
        res.append((plain[0x400:0x404] == b"FCFB", "IFDSP FlexSPI config block 'FCFB' at 0x400"))
    elif tag == "MC":
        try:
            recs, entry = sfl_decode.parse_srec(plain)
            res.append((True, f"MAIN S-records parse, record checksums valid ({len(recs)} records)"))
            res.append((entry is not None, "MAIN S7 entry record present"))
        except ValueError as e:
            res.append((False, f"MAIN S-records: {e}"))
    return res


# ------------------------------------------------------------------- main

def parse_args(argv):
    opts = {"raw": False, "force": False, "check": False, "base": MAIN_BASE}
    pos = []
    it = iter(argv)
    valued = {"--tag", "--header-from", "--layout-from", "--base", "--title", "--file-name",
              "--product", "--version", "--date", "--copyright"}
    for a in it:
        if a in ("--raw", "--force", "--check"):
            opts[a[2:]] = True
        elif a in valued:
            v = next(it, None)
            if v is None:
                sys.exit(f"{a} needs a value")
            opts[a[2:].replace("-", "_")] = v
        elif a.startswith("--"):
            sys.exit(f"unknown option {a}\n\n{__doc__}")
        else:
            pos.append(a)
    if isinstance(opts["base"], str):
        opts["base"] = int(opts["base"], 0)
    return opts, pos


def build(opts, src, dst):
    tmpl = None
    if opts.get("header_from"):
        with open(opts["header_from"], "rb") as fh:
            tmpl = fh.read()
        th = sfl_header.parse(tmpl)
    tag = opts.get("tag") or (th["tag"] if tmpl else None)
    if tag not in TITLES:
        sys.exit("need --tag MC|PC|ID|SR or --header-from")
    with open(src, "rb") as fh:
        data = fh.read()

    if opts["raw"]:
        plain = data
    elif tag == "MC":
        if data.startswith(b"S0"):
            plain = data
        else:
            clusters = [(opts["base"], data)]
            for extra in sorted(glob.glob(glob.escape(src) + ".*.bin")):
                m = re.fullmatch(r"\.([0-9A-Fa-f]{8})\.bin", extra[len(src):])
                if m:
                    with open(extra, "rb") as fh:
                        clusters.append((int(m.group(1), 16), fh.read()))
            layout = opts.get("layout_from", opts.get("header_from"))
            ttext = None
            if layout:
                with open(layout, "rb") as fh:
                    lt = fh.read()
                ttext = sfl_decode.decode(lt[sfl_header.PAYLOAD_OFF:])
            plain = binary_to_srec(clusters, ttext)
    elif tag == "SR":
        plain = data.hex().encode() + b"\r\n"
    else:
        plain = data

    if tmpl and not any(opts.get(k) for k in ("title", "file_name", "product", "version", "date", "copyright")):
        box = tmpl[:sfl_header.COMMENT_LEN]
    else:
        f = th["fields"] if tmpl else {}
        base = os.path.basename(dst)
        m = re.search(r"_V(\d\d)(\d\d)\.", base)
        fields = {
            "FILE NAME": opts.get("file_name") or base,
            "PRODUCT NAME": opts.get("product") or f.get("PRODUCT NAME", "FT-710"),
            "FIRM VERSION": opts.get("version") or (f"V{m.group(1)}-{m.group(2)}" if m else f.get("FIRM VERSION", "V00-00")),
            "DATE": opts.get("date") or f.get("DATE") or datetime.date.today().strftime("%Y/%m/%d"),
        }
        title = opts.get("title") or (th["title"] if tmpl else TITLES[tag])
        cline = opts.get("copyright")
        if cline is None:
            cline = tmpl[6 * 64 + 1:7 * 64 - 3].decode().strip() if tmpl else ""
        box = make_box(title, fields, cline)

    enc = encode(plain)
    crc = sfl_decode.sfl_crc(enc)
    total = sfl_header.PAYLOAD_OFF + len(enc)
    out = box + make_tagline(tag, total, crc) + enc
    assert len(box) == sfl_header.COMMENT_LEN
    assert sfl_decode.decode(enc) == plain

    results = check(out, dst)
    bad = [r for ok, r in results if not ok]
    for r in bad:
        print(f"  FAIL: {r}", file=sys.stderr)
    if bad and not opts["force"]:
        sys.exit(f"{dst}: not written ({len(bad)} acceptance rule(s) failed; --force to override)")
    os.makedirs(os.path.dirname(os.path.abspath(dst)), exist_ok=True)
    with open(dst, "wb") as fh:
        fh.write(out)
    print(f"{dst}: tag={tag} length={total} checksum {crc:08X}, payload {len(enc)} bytes")
    return 0


def main(argv):
    opts, pos = parse_args(argv)
    if opts["check"]:
        if not pos:
            sys.exit(__doc__)
        rc = 0
        for path in pos:
            with open(path, "rb") as fh:
                data = fh.read()
            print(path)
            for ok, rule in check(data, path):
                print(f"  {'ok  ' if ok else 'FAIL'} {rule}")
                rc |= 0 if ok else 1
        return rc
    if len(pos) != 2:
        sys.exit(__doc__)
    return build(opts, pos[0], pos[1])


if __name__ == "__main__":
    sys.exit(main(sys.argv[1:]))
