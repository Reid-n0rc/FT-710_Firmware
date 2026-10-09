#!/usr/bin/env python3
"""Parse a Xilinx 7-series configuration bitstream (raw .bin, no .bit header).

Written for T08 (FT-710 SDR image, build/FT-710_SDR_V0104.bin) but generic for
7-series bitstreams. Stdlib only.

Usage:
    python3 -I tools/xbit_parse.py IMAGE.bin                 # summary + packet log
    python3 -I tools/xbit_parse.py IMAGE.bin --all-packets   # do not collapse NOP runs
    python3 -I tools/xbit_parse.py IMAGE.bin --frames        # FDRI frame statistics
    python3 -I tools/xbit_parse.py IMAGE.bin --lead          # test hypotheses for the
                                                             # word(s) before the sync
                                                             # (incl. CRC-32/BZIP2, ~15 s)
    python3 -I tools/xbit_parse.py IMAGE.bin --bram          # BRAM content frames
                                                             # (XC7A50T layout)
    python3 -I tools/xbit_parse.py IMAGE.bin --dump-fdri OUT # write raw FDRI payload

What it does:
  * finds the sync word AA995566 and reports what precedes it (bus-width
    pattern 000000BB 11220044, padding, any leading words);
  * walks type-1 / type-2 packets and decodes register writes (CMD, IDCODE,
    COR0/COR1, CTL0/CTL1, MASK, FAR, FDRI, CRC, WBSTAR, TIMER, ...);
  * flags compression (MFWR / multi-frame writes) and encryption (CTL0.DEC,
    CBC writes, encrypted-FDRI patterns);
  * re-computes the 7-series configuration CRC (CRC-32C over {addr5,data32})
    and checks it against every CRC register write;
  * --frames: splits FDRI into 101-word frames and reports non-zero frames,
    zero/padding frames and printable strings.

Register/command names follow Xilinx UG470 (7 Series FPGAs Configuration).
"""
import struct
import sys
import zlib

SYNC = 0xAA995566
WORDS_PER_FRAME = 101  # 7-series

REGS = {
    0x00: "CRC", 0x01: "FAR", 0x02: "FDRI", 0x03: "FDRO", 0x04: "CMD",
    0x05: "CTL0", 0x06: "MASK", 0x07: "STAT", 0x08: "LOUT", 0x09: "COR0",
    0x0A: "MFWR", 0x0B: "CBC", 0x0C: "IDCODE", 0x0D: "AXSS", 0x0E: "COR1",
    0x10: "WBSTAR", 0x11: "TIMER", 0x13: "RBCRC_SW", 0x16: "BOOTSTS",
    0x18: "CTL1", 0x1F: "BSPI",
}
CMDS = {
    0: "NULL", 1: "WCFG", 2: "MFW", 3: "LFRM/DGHIGH", 4: "RCFG", 5: "START",
    6: "RCAP", 7: "RCRC", 8: "AGHIGH", 9: "SWITCH", 10: "GRESTORE",
    11: "SHUTDOWN", 12: "GCAPTURE", 13: "DESYNC", 15: "IPROG", 16: "CRCC",
    17: "LTIMER", 18: "BSPI_READ", 19: "FALL_EDGE",
}
OPS = {0: "NOP", 1: "READ", 2: "WRITE", 3: "RSVD"}

# Subset of the Xilinx 7-series IDCODE table (UG470 Table 1-1), without the
# 4-bit revision field.
IDCODES = {
    0x362D093: "XC7A35T", 0x362C093: "XC7A50T", 0x3632093: "XC7A75T",
    0x3631093: "XC7A100T", 0x3636093: "XC7A200T", 0x362E093: "XC7A15T",
    0x37C4093: "XC7S25", 0x362F093: "XC7S50", 0x3622093: "XC7S6/XC7S15",
    0x3647093: "XC7K70T", 0x364C093: "XC7K160T", 0x3651093: "XC7K325T",
    0x3727093: "XC7Z010", 0x372C093: "XC7Z015", 0x3722093: "XC7Z020",
}
# UG470 Table 1-1 "Configuration bitstream length" in bits.
BITSTREAM_BITS = {"XC7A15T": 17536096, "XC7A35T": 17536096,
                  "XC7A50T": 17536096, "XC7A75T": 30606304,
                  "XC7A100T": 30606304, "XC7A200T": 77845216}


def words(data, off):
    n = (len(data) - off) // 4
    return struct.unpack_from(">%dI" % n, data, off)


def decode_far(v):
    return {"block": (v >> 23) & 7, "top": (v >> 22) & 1, "row": (v >> 17) & 0x1F,
            "col": (v >> 7) & 0x3FF, "minor": v & 0x7F}


def decode_value(reg, v):
    name = REGS.get(reg, "R%02X" % reg)
    if name == "CMD":
        return CMDS.get(v, "?%d" % v)
    if name == "IDCODE":
        return "%s rev %d" % (IDCODES.get(v & 0x0FFFFFFF, "unknown"), v >> 28)
    if name == "FAR":
        f = decode_far(v)
        return "block=%d top=%d row=%d col=%d minor=%d" % (
            f["block"], f["top"], f["row"], f["col"], f["minor"])
    if name == "CTL0":
        # UG470 Table 5-26 (bit positions as best recalled; DEC = bit 6)
        bits = []
        if v & (1 << 0): bits.append("GTS_USR_B")
        if v & (1 << 3): bits.append("PERSIST")
        if (v >> 4) & 3: bits.append("SBITS=%d" % ((v >> 4) & 3))
        if v & (1 << 6): bits.append("DEC(encrypted)")
        if v & (1 << 7): bits.append("FARSRC")
        if v & (1 << 8): bits.append("GLUTMASK_B")
        if v & (1 << 10): bits.append("ConfigFallback")
        if v & (1 << 12): bits.append("OverTempPowerDown")
        if v & (1 << 30): bits.append("ICAP_SELECT")
        if v & (1 << 31): bits.append("EFUSE_KEY")
        return ",".join(bits) or "-"
    if name == "BSPI":
        return "SPI read opcode 0x%02X, bits[9:8]=%d" % (v & 0xFF, (v >> 8) & 3)
    if name == "COR0":
        return ("GWE_CYCLE=%d GTS_CYCLE=%d LOCK_CYCLE=%d MATCH_CYCLE=%d "
                "DONE_CYCLE=%d SSCLKSRC=%d OSCFSEL=%d SINGLE=%d DRIVE_DONE=%d "
                "DONE_PIPE=%d PWRDWN_STAT=%d" % (
                    v & 7, (v >> 3) & 7, (v >> 6) & 7, (v >> 9) & 7,
                    (v >> 12) & 7, (v >> 15) & 3, (v >> 17) & 0x3F,
                    (v >> 23) & 1, (v >> 24) & 1, (v >> 25) & 1, (v >> 27) & 1))
    if name == "COR1":
        return ("BPI_PAGE_SIZE=%d BPI_1ST_READ=%d RBCRC_EN=%d RBCRC_NO_PIN=%d "
                "RBCRC_ACTION=%d PERSIST_DEASSERT=%d" % (
                    v & 3, (v >> 2) & 3, (v >> 8) & 1, (v >> 9) & 1,
                    (v >> 15) & 3, (v >> 17) & 1))
    if name == "WBSTAR":
        return "RS=%d RS_TS_B=%d START_ADDR=0x%07X" % (
            (v >> 30) & 3, (v >> 29) & 1, v & 0x1FFFFFFF)
    if name == "TIMER":
        return "TIMER_CFG_MON=%d TIMER_USR_MON=%d VALUE=%d" % (
            (v >> 30) & 1, (v >> 31) & 1, v & 0x3FFFFFFF)
    return ""


# ---- 7-series configuration CRC (CRC-32C, poly 0x82F63B78 reflected) -----
def _crc_step(crc, val, nbits):
    for i in range(nbits):
        b = ((val >> i) & 1) ^ (crc & 1)
        crc >>= 1
        if b:
            crc ^= 0x82F63B78
    return crc


def cfg_crc_update(crc, addr, data):
    """One 37-bit {addr[4:0], data[31:0]} update, LSB first (UG470/prjxray)."""
    return _crc_step(crc, (addr << 32) | data, 37)


class Packet:
    __slots__ = ("off", "type", "op", "reg", "count", "data")

    def __init__(self, off, typ, op, reg, count, data):
        self.off, self.type, self.op, self.reg = off, typ, op, reg
        self.count, self.data = count, data


def find_sync(data):
    i = data.find(struct.pack(">I", SYNC))
    if i < 0:
        sys.exit("sync word AA995566 not found")
    return i


def parse(data):
    s = find_sync(data)
    w = words(data, s + 4)
    base = s + 4
    pkts = []
    i, last_reg = 0, None
    while i < len(w):
        h = w[i]
        off = base + 4 * i
        typ = h >> 29
        op = (h >> 27) & 3
        if typ == 1:
            reg = (h >> 13) & 0x3FFF
            cnt = h & 0x7FF
            last_reg = reg
        elif typ == 2:
            reg = last_reg
            cnt = h & 0x7FFFFFF
        else:
            pkts.append(Packet(off, typ, op, None, 0, (h,)))
            i += 1
            continue
        dat = w[i + 1:i + 1 + cnt] if op == 2 else ()
        pkts.append(Packet(off, typ, op, reg, cnt, dat))
        i += 1 + (cnt if op == 2 else 0)
    return s, pkts


def check_crcs(pkts):
    """Return list of (packet offset, expected, computed) for CRC writes."""
    crc, res = 0, []
    for p in pkts:
        if p.op != 2 or p.type not in (1, 2):
            continue
        if p.reg == 0x04 and p.data and p.data[0] == 7:  # RCRC
            crc = 0
            continue
        if p.reg == 0x00:  # CRC register write: compare, then reset
            res.append((p.off, p.data[0], crc))
            crc = 0
            continue
        for v in p.data:
            crc = cfg_crc_update(crc, p.reg & 0x1F, v)
        if p.reg == 0x04 and p.data and p.data[0] == 7:
            crc = 0
    return res


def print_packets(pkts, show_all):
    nop_run = None
    for p in pkts + [None]:
        is_nop = p is not None and p.type == 1 and p.op == 0
        if is_nop and not show_all:
            if nop_run is None:
                nop_run = [p.off, 0]
            nop_run[1] += 1
            continue
        if nop_run:
            print("  %07X  NOP x%d" % (nop_run[0], nop_run[1]))
            nop_run = None
        if p is None:
            break
        if p.type not in (1, 2):
            print("  %07X  ?? word %08X (type %d)" % (p.off, p.data[0], p.type))
            continue
        name = REGS.get(p.reg, "R%02X" % (p.reg or 0))
        if p.op == 2 and p.count == 1:
            print("  %07X  T%d WRITE %-8s = %08X  %s" % (
                p.off, p.type, name, p.data[0], decode_value(p.reg, p.data[0])))
        elif p.op == 2:
            print("  %07X  T%d WRITE %-8s %d words (%d bytes, %.2f frames)" % (
                p.off, p.type, name, p.count, 4 * p.count,
                p.count / WORDS_PER_FRAME))
        else:
            print("  %07X  T%d %s %s count=%d" % (p.off, p.type, OPS[p.op],
                                                 name, p.count))


def fdri_payload(pkts):
    out = []
    for p in pkts:
        if p.op == 2 and p.reg == 0x02:
            out.extend(p.data)
    return out


def frames_report(pkts):
    fd = fdri_payload(pkts)
    nfr = len(fd) // WORDS_PER_FRAME
    print("FDRI: %d words = %d frames of %d words (+%d words)" % (
        len(fd), nfr, WORDS_PER_FRAME, len(fd) % WORDS_PER_FRAME))
    zero = [all(v == 0 for v in fd[k * 101:(k + 1) * 101]) for k in range(nfr)]
    print("  all-zero frames: %d, non-zero frames: %d" % (sum(zero), nfr - sum(zero)))
    # runs of zero / non-zero frames
    runs, cur, start = [], zero[0], 0
    for k in range(1, nfr + 1):
        if k == nfr or zero[k] != cur:
            runs.append((start, k - start, cur))
            if k < nfr:
                cur, start = zero[k], k
    big = [r for r in runs if r[2] and r[1] >= 64]
    print("  zero-frame runs >= 64 frames (frame index, length):")
    for r in big:
        print("    %6d +%d" % (r[0], r[1]))
    nz = [k for k in range(nfr) if not zero[k]]
    print("  last non-zero frame: %d of %d" % (nz[-1] if nz else -1, nfr))
    # density per 1/32 of the stream
    step = max(1, nfr // 32)
    print("  set-bit density per %d-frame slice:" % step)
    line = []
    for a in range(0, nfr, step):
        seg = fd[a * 101:min(nfr, a + step) * 101]
        bits = sum(bin(v).count("1") for v in seg)
        line.append("%5.2f%%" % (100.0 * bits / (32 * len(seg))))
    for j in range(0, len(line), 8):
        print("    " + " ".join(line[j:j + 8]))
    raw = struct.pack(">%dI" % len(fd), *fd)
    strs = find_strings(raw, 6)
    print("  printable strings (>=6 chars) in FDRI (big-endian words): %d" % len(strs))
    for o, t in strs[:20]:
        print("    +%06X %r" % (o, t))
    raw_le = struct.pack("<%dI" % len(fd), *fd)
    strs = find_strings(raw_le, 6)
    print("  printable strings (>=6 chars) in FDRI (byte-swapped words): %d" % len(strs))
    for o, t in strs[:20]:
        print("    +%06X %r" % (o, t))


# Block-type-1 (BRAM content) layout derived empirically for this XC7A50T
# stream: after 4390 block-0 frames, three FAR rows of BRAM columns
# (3, 2 and 3 columns of 128 frames each), each row followed by 2 pad frames.
BRAM_LAYOUT = {"XC7A50T": (4390, (3, 2, 3))}


def bram_report(pkts, dev="XC7A50T"):
    import hashlib
    fd = fdri_payload(pkts)
    start, rows = BRAM_LAYOUT[dev]
    print("BRAM content (block type 1) region assumed to start at frame %d" % start)
    segs, f = [], start
    for ncol in rows:
        for _ in range(ncol):
            segs.append(f)
            f += 128
        pad = fd[f * 101:(f + 2) * 101]
        print("  row ends at frame %d; 2 pad frames all-zero: %s" % (f, not any(pad)))
        f += 2
    print("  region ends at frame %d of %d" % (f, len(fd) // 101))
    idx = [w for w in range(101) if w != 50]  # word 50 = HCLK/ECC word
    groups = {}
    for si, s0 in enumerate(segs):
        dens = []
        for slot in range(10):
            ws = idx[slot * 10:(slot + 1) * 10]
            v = [fd[(s0 + m) * 101 + w] for m in range(128) for w in ws]
            bits = sum(bin(x).count("1") for x in v)
            dens.append("%5.1f" % (100.0 * bits / (len(v) * 32)))
            if bits:
                key = hashlib.md5(struct.pack(">%dI" % len(v), *v)).hexdigest()[:8]
                groups.setdefault(key, []).append("c%d.%d" % (si, slot))
        print("  column %d (frame %d) slot bit-density %%: %s" % (si, s0, " ".join(dens)))
    used = sum(len(g) for g in groups.values())
    print("  non-empty 10-word slots (~1 RAMB36 each, assumed): %d of %d; "
          "distinct contents: %d" % (used, 10 * len(segs), len(groups)))
    for k, g in groups.items():
        if len(g) > 1:
            print("    identical content %s: %s" % (k, ", ".join(g)))


def find_strings(b, n):
    out, cur, st = [], bytearray(), 0
    for i, c in enumerate(b):
        if 0x20 <= c < 0x7F:
            if not cur:
                st = i
            cur.append(c)
        else:
            if len(cur) >= n and len(set(cur)) > 2:
                out.append((st, cur.decode()))
            cur = bytearray()
    return out


def crc32_bzip2(data, crc=0xFFFFFFFF):
    """CRC-32/BZIP2: poly 0x04C11DB7, MSB-first, init/xorout 0xFFFFFFFF."""
    tbl = _BZ_TBL
    for b in data:
        crc = ((crc << 8) & 0xFFFFFFFF) ^ tbl[(crc >> 24) ^ b]
    return crc ^ 0xFFFFFFFF


def _bz_table():
    t = []
    for i in range(256):
        c = i << 24
        for _ in range(8):
            c = ((c << 1) ^ 0x04C11DB7) & 0xFFFFFFFF if c & 0x80000000 else (c << 1) & 0xFFFFFFFF
        t.append(c)
    return t


_BZ_TBL = _bz_table()


def bitrev32(v):
    return int("{:032b}".format(v)[::-1], 2)


def lead_report(data, s, pkts):
    lead = struct.unpack(">I", data[:4])[0]
    print("Leading word: %08X (LE read %08X)" % (lead, struct.unpack("<I", data[:4])[0]))
    print("  bytes before sync: 0x%X; pad after word: %s" % (
        s, "all FF" if set(data[4:s - 0x10]) == {0xFF} else "mixed"))
    body = data[4:]
    from_sync = data[s:]
    cands = {}
    for nm, blk in (("file[4:]", body), ("file[0x1000:] (bus-width onward)", data[0x1000:]),
                    ("sync onward", from_sync), ("whole file", data)):
        c = zlib.crc32(blk)
        cands["crc32 " + nm] = c
        cands["~crc32 " + nm] = c ^ 0xFFFFFFFF
        cands["adler32 " + nm] = zlib.adler32(blk)
        cands["sum8 " + nm] = sum(blk) & 0xFFFFFFFF
        n = len(blk) // 4
        cands["sum32be " + nm] = sum(struct.unpack(">%dI" % n, blk[:4 * n])) & 0xFFFFFFFF
        cands["sum32le " + nm] = sum(struct.unpack("<%dI" % n, blk[:4 * n])) & 0xFFFFFFFF
        cands["len " + nm] = len(blk)
        cands["len*8 " + nm] = len(blk) * 8
    fd = fdri_payload(pkts)
    cands["FDRI words"] = len(fd)
    cands["sync byte-reversed"] = 0x665599AA
    cands["sync bit-reversed"] = bitrev32(SYNC)
    cands["sync nibble-swapped"] = 0xAA995566 >> 4 | (0xAA995566 & 0xF) << 28
    hits = []
    for k, v in cands.items():
        for form, x in (("", lead), ("byteswap", struct.unpack("<I", data[:4])[0]),
                        ("bitrev", bitrev32(lead)), ("~", lead ^ 0xFFFFFFFF)):
            if v == x:
                hits.append("%s == %s(lead)" % (k, form))
    print("  hypotheses tested: %d candidate values x 4 forms" % len(cands))
    for k in ("sync byte-reversed", "sync bit-reversed", "crc32 file[4:]",
              "len file[4:]", "len*8 file[4:]"):
        print("    %-24s %08X" % (k, cands[k]))
    print("  matches among the simple candidates: %s" % (", ".join(hits) or "none"))
    bz = crc32_bzip2(data[0x1000:])
    print("  CRC-32/BZIP2 over file[0x1000:] (the standard Vivado .bin, %d bytes) = %08X -> %s" % (
        len(data) - 0x1000, bz, "MATCHES the leading word" if bz == lead else "no match"))
    print("  XOR with sync: %08X; lead bytes as text: %r" % (lead ^ SYNC, data[:4]))


def main():
    a = sys.argv[1:]
    if not a or a[0] in ("-h", "--help"):
        print(__doc__)
        return
    data = open(a[0], "rb").read()
    s, pkts = parse(data)
    print("File: %s, %d bytes" % (a[0], len(data)))
    print("Sync AA995566 at 0x%X" % s)
    bw = data.find(bytes.fromhex("000000BB11220044"))
    print("Bus-width detect 000000BB 11220044 at 0x%X" % bw)
    print("Bytes before sync: %d; FF padding runs: lead word + %d FF + bus-width + %d FF" % (
        s, bw - 4 if bw > 0 else -1, s - bw - 8 if bw > 0 else -1))
    print("Packets: %d" % len(pkts))
    if not any(x in a for x in ("--lead", "--frames", "--bram")) or "--all-packets" in a:
        print_packets(pkts, "--all-packets" in a)
    ids = [p.data[0] for p in pkts if p.op == 2 and p.reg == 0x0C and p.data]
    for v in ids:
        dev = IDCODES.get(v & 0x0FFFFFFF, "unknown")
        print("IDCODE %08X -> %s" % (v, dev))
        if dev in BITSTREAM_BITS:
            exp = BITSTREAM_BITS[dev] // 8
            # A Vivado .bin starts with 8 dummy FFFFFFFF words before the bus-width word.
            got = len(data) - (bw - 32)
            print("  UG470 bitstream length %d bits = %d bytes; this stream from "
                  "the 32 FF dummy bytes before bus-width (file 0x%X): %d bytes (%s)" % (
                      BITSTREAM_BITS[dev], exp, bw - 32, got,
                      "MATCH" if got == exp else "differs"))
    fd = fdri_payload(pkts)
    print("FDRI total %d words = %d frames + %d words" % (
        len(fd), len(fd) // WORDS_PER_FRAME, len(fd) % WORDS_PER_FRAME))
    mfwr = any(p.op == 2 and p.reg == 0x0A for p in pkts)
    ctl0 = [p.data[0] for p in pkts if p.op == 2 and p.reg == 0x05]
    masks = [p.data[0] for p in pkts if p.op == 2 and p.reg == 0x06]
    cbc = any(p.op == 2 and p.reg == 0x0B for p in pkts)
    enc = any(v & (1 << 6) for v in ctl0)
    print("Compressed (MFWR writes): %s" % ("yes" if mfwr else "no"))
    print("Encrypted (CTL0.DEC / CBC write): %s (CTL0 writes %s, MASK writes %s)" % (
        "yes" if enc or cbc else "no",
        [hex(v) for v in ctl0], [hex(v) for v in masks]))
    for off, exp, got in check_crcs(pkts):
        print("CRC write at 0x%X: stream %08X, computed %08X -> %s" % (
            off, exp, got, "OK" if exp == got else "MISMATCH"))
    if "--frames" in a:
        frames_report(pkts)
    if "--bram" in a:
        bram_report(pkts)
    if "--lead" in a:
        lead_report(data, s, pkts)
    if "--dump-fdri" in a:
        out = a[a.index("--dump-fdri") + 1]
        open(out, "wb").write(struct.pack(">%dI" % len(fd), *fd))
        print("wrote %s" % out)


if __name__ == "__main__":
    main()
