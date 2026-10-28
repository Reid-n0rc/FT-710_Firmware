#!/usr/bin/env python3
"""Classify the undefined bytes left in an image's executable blocks, independently of Ghidra (T22d, #104).

usage: python3 -I tools/undefined_classify.py <image> <ranges.tsv> <out.tsv> [--build DIR] [--flix FILE] [--jobs N]
       python3 -I tools/undefined_classify.py summary <out.tsv>...
       python3 -I tools/undefined_classify.py compare <out.tsv> <other.tsv> <start-col> <length-col> <class-col> [a:b,...]

<image>      main | display | m33 | hifi4 (memory maps from docs/memory-maps.md, built into IMAGES below)
<ranges.tsv> tools/ghidra/UndefinedRanges.java output: the only input taken from Ghidra is the list of ranges
             (block, start, end); its refs_in/prev/next columns are copied to the output as context and are not used.
--build      directory with the decoded images (default: build/ of the main checkout)
--flix       decomp/ifdsp/hifi4/flix.dis (hifi4 only): its call/jump targets count as inbound-branch evidence

Every range is cut into sub-runs, each with one class. Steps, in order, on the raw bytes:
  padding        a run of >= 4 equal bytes (or a range that is only 0x00/0xFF/one repeated byte)
  string_ascii   >= 4 printable ASCII (plus \\t \\n \\r, ESC) ending in NUL or at the range end
  string_utf16   >= 4 UTF-16LE characters (ASCII or Shift-JIS-free BMP) ending in a NUL halfword or the range end
  string_sjis    ASCII mixed with >= 2 Shift-JIS double-byte characters, NUL-terminated
  pointer        4-aligned words that point into the image or into the RAM/IO ranges listed per image
                 (value ranges chosen so small integers do not count). A gap that is only pointers is a pointer table.
  code           decodes completely with a non-Ghidra disassembler (rx-elf-objdump / arm-none-eabi-objdump A32 or T32 /
                 the Zephyr RT600 xtensa objdump), no invalid or out-of-bounds instruction, >= 1 control-flow
                 instruction, and either >= 8 bytes long or reached by a branch/call or pointer. "code_weak" when it
                 decodes but misses the last condition.
  float_table    >= 3 aligned words, >= 75 % of them plausible IEEE float32 (0 or 1e-6 <= |x| <= 1e7)
  int_table      >= 2 aligned words or halfwords, >= 75 % small values (< 0x10000 for words, < 0x1000 for halfwords)
  padding_short  1..3 bytes of 0x00 (alignment between items)
  unknown        anything else (Shannon entropy in the evidence)
Inbound evidence for code: branch/call targets from a linear disassembly of the whole executable block with the same
objdump (hifi4: flix.dis), and image words equal to the address (Thumb: address | 1).

Output TSV columns: range_start range_end sub_start sub_end size nonff class evidence ghidra_refs_in ghidra_prev ghidra_next
Byte counts per class use nonff (the T21f metric counts non-0xFF bytes).
"""
import atexit, math, os, re, struct, subprocess, sys, tempfile
from concurrent.futures import ThreadPoolExecutor

HOME = os.path.expanduser('~')
RX_OD = HOME + '/opt/rx-binutils-2.47/bin/rx-elf-objdump'
ARM_OD = 'arm-none-eabi-objdump'
XT_OD = HOME + '/opt/zephyr-sdk-0.17.0/xtensa-nxp_rt600_adsp_zephyr-elf/bin/xtensa-nxp_rt600_adsp_zephyr-elf-objdump'

# segments: (address, file, file offset, length) of the initialized executable blocks
# ptr: (lo, hi) value ranges that count as pointers
# linear: (lo, hi) code area for the linear branch-target pass
IMAGES = {
    'main': dict(arch='rx', segs=[(0xFFF80000, 'FT-710_MAIN_V0112.bin', 0, 0x80000)],
                 ptr=[(0xFFF80000, 0xFFFEFFFF)], linear=[(0xFFF8FBDB, 0xFFFEE1BF)], thumb=False,
                 # const data (strings, menu and key tables, vectors, DTBL/BTBL, .data images) ends at 0xFFF8EEA4
                 code_area=[(0xFFF8EEA4, 0xFFFFFFFF)]),
    'display': dict(arch='arm', segs=[(0x20100000, 'FT-710_DISPLAY_V0108.bin', 0, 0x65178)],
                    scan=[(0x20100000, 'FT-710_DISPLAY_V0108.bin', 0, 0)],
                    ptr=[(0x18000000, 0x18FFFFFF), (0x20100000, 0x2042BC0F), (0x2042BC10, 0x209FFFFF),
                         (0x3FE00000, 0x3FFFFFFF), (0x60000000, 0x609FFFFF), (0xE8000000, 0xE82FFFFF),
                         (0xFCFE0000, 0xFCFFFFFF)],
                    linear=[(0x20100000, 0x20165178)], thumb=True),
    'm33': dict(arch='thumb', segs=[(0x08000000, 'FT-710_IFDSP_V0101.bin', 0, 0x1844),
                                    (0x00080000, 'FT-710_IFDSP_V0101.bin', 0x5D428, 0x7EBC)],
                scan=[(0x08000000, 'FT-710_IFDSP_V0101.bin', 0, 0x5D428), (0x00080000, 'FT-710_IFDSP_V0101.bin', 0x5D428, 0)],
                ptr=[(0x08000000, 0x080652EB), (0x00080000, 0x000A1EF7), (0x20000000, 0x2047FFFF),
                     (0x40000000, 0x4015FFFF), (0xE0000000, 0xE00FFFFF)],
                linear=[(0x08000000, 0x08001844), (0x00080000, 0x00087EBC)], thumb=True,
                known=[(0x08000400, 0x080005FF, 'struct', 'FlexSPI NOR config block (FCFB tag at 0x08000400), docs/memory-maps.md')]),
    'hifi4': dict(arch='xtensa', segs=[(0x24020000, 'FT-710_IFDSP_V0101_hifi4.bin', 0x20000, 0x644),
                                       (0x00200000, 'FT-710_IFDSP_V0101_hifi4.bin', 0x20644, 0x36800)],
                  scan=[(0x24000000, 'FT-710_IFDSP_V0101_hifi4.bin', 0, 0x20644),
                        (0x00200000, 'FT-710_IFDSP_V0101_hifi4.bin', 0x20644, 0x383B4)],
                  ptr=[(0x00200000, 0x002FFFFF), (0x24000000, 0x2402FFFF), (0x20020000, 0x2007FFFF),
                       (0x40000000, 0x4015FFFF)],
                  linear=[], thumb=False),
}

BAD = re.compile(r'\*unknown\*|\(bad\)|\.byte\b|\.word\b|\.short\b|UNDEFINED|UNPREDICTABLE|out of bounds|\bill\b')
_CC = r'(eq|ne|cs|cc|hs|lo|mi|pl|vs|vc|hi|ls|ge|lt|gt|le|al)?'
_ARMFLOW = (r'^(b|bl|blx|bx)' + _CC + r'(\.[nw])?\s|^(pop|ldm\w*)\b.*\bpc\b|^\w+' + _CC + r'(\.[nw])?\s+pc,|^(svc|udf)\b')
FLOW = {
    'rx': re.compile(r'^(rts|rtsd|rte|rtfi|bra|bsr|jmp|jsr|b(eq|ne|geu|ltu|gtu|leu|pz|n|ge|lt|gt|le|o|no|c|nc|z|nz))(\.[absw])?\b'),
    'arm': re.compile(_ARMFLOW),
    'thumb': re.compile(_ARMFLOW + r'|^(cbz|cbnz|tbb|tbh)\b'),
    'xtensa': re.compile(r'(^|[{;]\s*)(ret|retw|ret\.n|retw\.n|j|jx|call\d+|callx\d+|b[a-z]+[iz]?(\.n)?|loop\w*|rfe|rfi|rfwo|rfwu)\s'),
}
_UARM = r'^(b|bx)(\.[nw])?\s|^(pop|ldm\w*)(\.[nw])?\s.*\bpc\b'
UNCOND = {  # unconditional end of a function or block
    'rx': re.compile(r'^(rts|rtsd|rte|rtfi|bra|jmp)(\.[absw])?\b'),
    'arm': re.compile(_UARM),
    'thumb': re.compile(_UARM),
    'xtensa': re.compile(r'(^|[{;]\s*)(ret|retw|ret\.n|retw\.n|j|jx|rfe|rfi)\s'),
}
NOPS = {'nop', 'nop.w', 'nop.n', 'nop.s'}
INS = re.compile(r'^\s*([0-9a-f]+):\s+((?:[0-9a-f]{2,8} ?)+)\s*\t(.*)$')
TARGET = re.compile(r'^(?:bsr|bra|b\w*|bl|blx|call\d*|j|jx)\S*\s+(?:#)?0x([0-9a-f]+)')


class Image:
    def __init__(self, name, build):
        self.name = name
        self.cfg = IMAGES[name]
        self.arch = self.cfg['arch']
        self.mem = []  # (addr, bytes)
        for a, f, off, n in self.cfg['segs']:
            with open(os.path.join(build, f), 'rb') as fh:
                fh.seek(off)
                self.mem.append((a, fh.read(n)))
        self.words = {}  # pointer value -> list of image addresses holding it (4-aligned)
        scan = []  # the whole file(s), not only the executable blocks, so .rodata/.data pointers count too
        for a, f, off, n in self.cfg.get('scan', self.cfg['segs']):
            with open(os.path.join(build, f), 'rb') as fh:
                fh.seek(off)
                scan.append((a, fh.read(n) if n else fh.read()))
        for a, b in scan:
            for i in range(0, len(b) - 3, 4 if self.arch != 'rx' else 1):
                v = struct.unpack_from('<I', b, i)[0]
                if self.is_ptr(v):
                    self.words.setdefault(v, []).append(a + i)
        self.targets = {}
        self.flix = {}  # hifi4: instruction address -> (length, is_bundle) from flix.dis
        for a, _ in self.mem:
            self.tmpfile(a)  # create before the worker threads start

    def tmpfile(self, base):
        """One temporary copy per segment for objdump (removed at exit)."""
        if not hasattr(self, '_tmp'):
            self._tmp = {}
        if base not in self._tmp:
            fd, path = tempfile.mkstemp(suffix='.bin')
            with os.fdopen(fd, 'wb') as t:
                t.write(self.file_for(base)[1])
            atexit.register(os.unlink, path)
            self._tmp[base] = path
        return self._tmp[base]

    def in_exec(self, v):
        return any(base <= (v & ~1) < base + len(b) for base, b in self.mem)

    def read(self, a, n):
        for base, b in self.mem:
            if base <= a and a + n <= base + len(b):
                return b[a - base:a - base + n]
        raise ValueError('0x%x+%d not in image' % (a, n))

    def is_ptr(self, v):
        return any(lo <= v <= hi for lo, hi in self.cfg['ptr'])

    def file_for(self, a):
        for base, b in self.mem:
            if base <= a < base + len(b):
                return base, b
        raise ValueError(hex(a))


def objdump(img, start, end, thumb=False):
    """Disassemble [start, end) with the non-Ghidra objdump. Returns a list of (addr, len, text)."""
    base, blob = img.file_for(start)
    path = img.tmpfile(base)
    if True:
        if img.arch == 'rx':
            cmd = [RX_OD, '-D', '-z', '-b', 'binary', '-m', 'rx']
        elif img.arch == 'xtensa':
            cmd = [XT_OD, '-D', '-z', '-b', 'binary', '-m', 'xtensa']
        else:
            cmd = [ARM_OD, '-D', '-z', '-b', 'binary', '-m', 'arm'] + (['-M', 'force-thumb'] if thumb else [])
        cmd += ['--adjust-vma=0x%x' % base, '--start-address=0x%x' % start, '--stop-address=0x%x' % end, path]
        out = subprocess.run(cmd, capture_output=True, text=True, timeout=600).stdout
    res = []
    for line in out.splitlines():
        m = INS.match(line)
        if m:
            nb = len(m.group(2).replace(' ', '')) // 2
            res.append((int(m.group(1), 16), nb, m.group(3).strip()))
        elif 'out of bounds' in line and res:
            res.append((res[-1][0] + res[-1][1], 0, 'out of bounds'))
    return res


def collect_targets(img, flix):
    t = {}
    def add(dst, src):
        t.setdefault(dst, []).append(src)
    if img.arch == 'xtensa':
        if flix:
            for line in open(flix, encoding='utf-8', errors='replace'):
                m = INS.match(line)
                if not m:
                    continue
                ia, nb, txt = int(m.group(1), 16), len(m.group(2).replace(' ', '')) // 2, m.group(3)
                if not BAD.search(txt):
                    img.flix[ia] = (nb, txt.startswith('{'))
                for mm in re.finditer(r'\b(call\d+|j|b\w+)\s+(?:[a-z0-9]+,\s*)*0x([0-9a-f]+)', m.group(3)):
                    add(int(mm.group(2), 16), int(m.group(1), 16))
        img.targets = t
        return
    modes = [img.arch == 'thumb'] if img.arch != 'arm' else [False]
    for lo, hi in img.cfg['linear']:
        for th in modes:
            for a, n, txt in objdump(img, lo, hi, thumb=th):
                m = TARGET.match(txt)
                if m:
                    add(int(m.group(1), 16), a)
    img.targets = t


def entropy(b):
    if not b:
        return 0.0
    c = [0] * 256
    for x in b:
        c[x] += 1
    return -sum(n / len(b) * math.log2(n / len(b)) for n in c if n)


PRINT = set(range(0x20, 0x7F)) | {9, 10, 13, 0x1B}


ALNUM = set(b'ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789')


def find_strings(b, a0, pointed):
    """Return list of (off, len, class, evidence) for strings in b (address a0).

    pointed(addr) tells whether an image word points at addr. A string needs a NUL (or the range end) after it and
    either enough length (ASCII >= 6 with a letter or digit, UTF-16 >= 4 chars, Shift-JIS >= 3 double-byte chars and
    >= 8 bytes) or a pointer to its first byte (then ASCII >= 1 char, e.g. "rb", "CR")."""
    out, i, n = [], 0, len(b)
    while i < n:
        ptr = pointed(a0 + i)
        # ASCII
        j = i
        while j < n and b[j] in PRINT:
            j += 1
        L = j - i
        aligned_pad = (a0 + i) % 4 == 0 and j < n and all(x == 0 for x in b[j:j + ((-(a0 + j)) % 4)])
        after_nul = i > 0 and b[i - 1] == 0
        if L and (j == n or b[j] == 0) and any(c in ALNUM for c in b[i:j]) and (
                L >= 6 or (ptr and L >= 1) or (L >= 2 and aligned_pad) or (L >= 3 and after_nul)):
            k = j
            while k < n and b[k] == 0 and (k == j or (a0 + k) % 4):
                k += 1
            out.append((i, k - i, 'string_ascii', repr(b[i:j][:40].decode('latin-1')) + ('; pointer to start' if ptr else '')))
            i = k
            continue
        # Shift-JIS (lead 0x81-0x9F / 0xE0-0xEF, trail 0x40-0xFC except 0x7F)
        j, dbl = i, 0
        while j < n:
            c = b[j]
            if c in PRINT:
                j += 1
            elif (0x81 <= c <= 0x9F or 0xE0 <= c <= 0xEF) and j + 1 < n and 0x40 <= b[j + 1] <= 0xFC and b[j + 1] != 0x7F:
                j += 2
                dbl += 1
            else:
                break
        if dbl and j < n and b[j] == 0 and ((dbl >= 3 and j - i >= 8) or (ptr and dbl >= 2)):
            try:
                txt = b[i:j].decode('shift_jis')
                out.append((i, j + 1 - i, 'string_sjis', repr(txt[:30]) + ('; pointer to start' if ptr else '')))
                i = j + 1
                continue
            except UnicodeDecodeError:
                pass
        # UTF-16LE
        j = i
        while j + 1 < n and b[j + 1] == 0 and b[j] in PRINT:
            j += 2
        letters = sum(1 for c in b[i:j:2] if c in ALNUM and not 0x30 <= c <= 0x39)
        if ((j - i) // 2 >= (1 if ptr else 4) and (j + 1 >= n or (b[j] == 0 and b[j + 1] == 0)) and (a0 + i) % 2 == 0
                and 2 * letters >= (j - i) // 2):
            k = min(n, j + 2)
            out.append((i, k - i, 'string_utf16', repr(b[i:j:2][:40].decode('latin-1')) + ('; pointer to start' if ptr else '')))
            i = k
            continue
        i += 1
    return out


def monotonic_runs(b):
    """Byte tables: >= 16 bytes that only go up or only go down (e.g. gamma/log curves)."""
    out, i, n = [], 0, len(b)
    while i < n - 1:
        nxt = i + 1
        for sign in (1, -1):
            j = i + 1
            while j < n and (b[j] - b[j - 1]) * sign >= 0:
                j += 1
            if j - i >= 16 and len(set(b[i:j])) >= 8:
                out.append((i, j - i, 'int_table', 'u8 %s %d..%d, %d bytes' % (
                    'rising' if sign > 0 else 'falling', b[i], b[j - 1], j - i)))
                nxt = j
                break
            # a later start inside this run cannot reach further, except from its last plateau
            p = j - 1
            while p > i and b[p - 1] == b[p]:
                p -= 1
            nxt = max(nxt, p)
        i = nxt
    return out


def ctype_runs(b):
    """C library character-class tables: one byte per character, digits share one value, A-Z and a-z each share a bit."""
    out, n = [], len(b)
    for s in range(0, n - 0x7B):
        dg = b[s + 0x30:s + 0x3A]
        if len(set(dg)) != 1 or not dg[0]:
            continue
        up, lo = b[s + 0x41:s + 0x5B], b[s + 0x61:s + 0x7B]
        ub = lb = 0xFF
        for x in up:
            ub &= x
        for x in lo:
            lb &= x
        if ub and lb and ub != lb and not (ub & dg[0]) and not (lb & dg[0]):
            e = min(n, s + 0x100)
            out.append((s, e - s, 'int_table', 'ctype table (digits 0x%02X, upper bit 0x%02X, lower bit 0x%02X)' % (
                dg[0], ub, lb)))
            break
    return out


def monotonic_words(b, a):
    """>= 8 aligned u32 words that strictly rise or fall (e.g. reciprocal tables 2^32/n)."""
    out, k, n = [], (-a) % 4, len(b)
    ws = [struct.unpack_from('<I', b, o)[0] for o in range(k, n - 3, 4)]
    i = 0
    while i < len(ws) - 1:
        for sign in (1, -1):
            j = i + 1
            while j < len(ws) and (ws[j] - ws[j - 1]) * sign > 0:
                j += 1
            if j - i >= 8:
                fl = [struct.unpack('<f', struct.pack('<I', w))[0] for w in ws[i:j]]
                good = sum(1 for w, f in zip(ws[i:j], fl) if w == 0 or (math.isfinite(f) and 1e-6 <= abs(f) <= 1e7))
                if good >= 0.75 * (j - i):
                    out.append((k + 4 * i, 4 * (j - i), 'float_table', 'float32 %s %g..%g, %d words' % (
                        'rising' if sign > 0 else 'falling', fl[0], fl[-1], j - i)))
                else:
                    out.append((k + 4 * i, 4 * (j - i), 'int_table', 'u32 %s 0x%08x..0x%08x, %d words' % (
                        'rising' if sign > 0 else 'falling', ws[i], ws[j - 1], j - i)))
                i = j - 1
                break
        i += 1
    return out


def fill_runs(b):
    out, i, n = [], 0, len(b)
    while i < n:
        j = i
        while j < n and b[j] == b[i]:
            j += 1
        if j - i >= (4 if b[i] in (0, 0xFF) else 8):
            out.append((i, j - i, 'padding', '%d x 0x%02X' % (j - i, b[i])))
        i = j
    return out


class Classifier:
    def __init__(self, img):
        self.img = img

    def inbound(self, a, n):
        ev = []
        tg = [d for d in range(a, a + n) if d in self.img.targets]
        if tg:
            src = self.img.targets[tg[0]][0]
            ev.append('branch to 0x%x from 0x%x (%d targets in run)' % (tg[0], src, len(tg)))
        th = self.img.cfg['thumb']
        pr = [v for v in range(a, a + n) for v in ([v, v | 1] if th else [v]) if v in self.img.words]
        if pr:
            ev.append('pointer to 0x%x at 0x%x' % (pr[0], self.img.words[pr[0]][0]))
        return ev, bool(tg) or (bool(pr) and (pr[0] == a or pr[0] == a | 1))

    def try_code(self, a, n):
        ca = self.img.cfg.get('code_area')
        if ca and not any(lo <= a <= hi for lo, hi in ca):
            return None
        modes = {'rx': [False], 'xtensa': [False], 'thumb': [True], 'arm': [False, True]}[self.img.arch]
        best = None
        for th in modes:
            if self.img.arch == 'arm' and not th and a % 4:
                continue
            ins = objdump(self.img, a, a + n, thumb=th)
            if not ins:
                continue
            covered = sum(x[1] for x in ins)
            bad = [x for x in ins if BAD.search(x[2])]
            flow = [x for x in ins if FLOW[self.img.arch].search(x[2])]
            # a direct branch/call to an address outside the executable blocks means this is not code
            wild = [x for x in ins if TARGET.match(x[2]) and not self.img.in_exec(int(TARGET.match(x[2]).group(1), 16))]
            ok = not bad and not wild and covered == n
            cand = (ok, len(flow), th, ins, bad)
            if best is None or cand[:2] > best[:2]:
                best = cand
        if best is None or not best[0]:
            return None
        ok, nflow, th, ins, bad = best
        if all(x[2].split()[0] in NOPS for x in ins):
            return 'padding', '%d nop instructions' % len(ins)
        ev, reached = self.inbound(a, n)
        thumb_entry = self.img.cfg['thumb'] and (a | 1) in self.img.words and (a | 1) != a
        if nflow == 0 and not thumb_entry:  # without flow, only a Thumb function pointer (address | 1) makes it code
            return None
        mode = {'rx': 'RX', 'xtensa': 'Xtensa', 'thumb': 'T32', 'arm': 'T32' if th else 'A32'}[self.img.arch]
        last = ins[-1][2].split('\t')[0] if ins else ''
        e = '%s %d insns, %d flow, last %s' % (mode, len(ins), nflow, last)
        cls = 'code' if (n >= 8 or reached) else 'code_weak'
        lastflow = bool(UNCOND[self.img.arch].search(ins[-1][2]))
        return cls, '; '.join([e] + ev), lastflow

    def table(self, b, a):
        n = len(b)
        k = (-a) % 4
        m = (n - k) // 4
        if m >= 3:
            ws = struct.unpack('<%dI' % m, b[k:k + 4 * m])
            fl = [struct.unpack('<f', struct.pack('<I', w))[0] for w in ws]
            good = sum(1 for w, f in zip(ws, fl) if w == 0 or (math.isfinite(f) and 1e-6 <= abs(f) <= 1e7))
            nz = sum(1 for w in ws if w)
            if good >= 0.75 * len(ws) and nz >= 2:
                edge = '' if (k == 0 and 4 * m == n) else ' (aligned words from +%d; %d edge bytes)' % (k, n - 4 * m)
                return 'float_table', '%d words, %d plausible float32, e.g. %s%s' % (
                    len(ws), good, ', '.join('%g' % f for f in fl[:4]), edge)
        if a % 4 == 0 and n >= 8 and n % 4 == 0:
            ws = struct.unpack('<%dI' % (n // 4), b)
            small = sum(1 for w in ws if w < 0x10000)
            if small >= 0.75 * len(ws):
                return 'int_table', '%d u32, %d < 0x10000, e.g. %s' % (len(ws), small, ', '.join('%d' % w for w in ws[:4]))
            mid = sum(1 for w in ws if w < 0x1000000)
            if len(ws) >= 4 and mid >= 0.75 * len(ws):
                return 'int_table', '%d u32, %d < 2^24, e.g. %s' % (len(ws), mid, ', '.join('%d' % w for w in ws[:4]))
        if a % 2 == 0 and n >= 4 and n % 2 == 0:
            hs = struct.unpack('<%dH' % (n // 2), b)
            small = sum(1 for h in hs if h < 0x1000)
            if small >= 0.75 * len(hs):
                return 'int_table', '%d u16, %d < 0x1000, e.g. %s' % (len(hs), small, ', '.join('%d' % h for h in hs[:4]))
        return None

    def records(self, b):
        """Arrays of fixed-size records: byte i equals byte i+p far more often than chance, for some period p."""
        n = len(b)
        if n < 32:
            return None
        cnt = [0] * 256
        for x in b:
            cnt[x] += 1
        chance = sum(c * c for c in cnt) / (n * n)
        best = None
        for p in range(2, min(129, n // 3)):
            m = sum(1 for i in range(n - p) if b[i] == b[i + p]) / (n - p)
            if best is None or m > best[1] + 0.02:
                best = (p, m)
        if best and best[1] >= 0.5 and best[1] >= 2 * chance:
            return 'struct_table', 'records of %d bytes (%.0f %% of bytes repeat at +%d, chance %.0f %%), %d records' % (
                best[0], 100 * best[1], best[0], 100 * chance, n // best[0])
        return None

    def ptr_words(self, b, a):
        """Offsets of 4-aligned pointer words in b."""
        res = []
        for off in range((-a) % 4, len(b) - 3, 4):
            v = struct.unpack_from('<I', b, off)[0]
            if self.img.is_ptr(v):
                res.append(off)
        return res

    def gap(self, b, a):
        """Classify a gap with no fill and no strings. Returns list of (off, len, class, evidence)."""
        n = len(b)
        if n == 0:
            return []
        if all(x == 0 for x in b) and n < 4:
            return [(0, n, 'padding_short', '%d x 0x00' % n)]
        pw = self.ptr_words(b, a)
        if pw and len(pw) * 4 == n:
            return [(0, n, 'pointer', '%d word(s), first 0x%08x' % (len(pw), struct.unpack_from('<I', b, 0)[0]))]
        c = self.try_code(a, n)
        if c:
            return [(0, n, c[0], c[1])]
        if pw:
            # split out pointer runs, classify the rest
            out, pos = [], 0
            runs = []
            for off in pw:
                if runs and runs[-1][1] == off:
                    runs[-1][1] = off + 4
                else:
                    runs.append([off, off + 4])
            for s, e in runs:
                out += [(pos + o, l, k, ev) for o, l, k, ev in self.rest(b[pos:s], a + pos)]
                out.append((s, e - s, 'pointer', '%d word(s), first 0x%08x' % ((e - s) // 4, struct.unpack_from('<I', b, s)[0])))
                pos = e
            out += [(pos + o, l, k, ev) for o, l, k, ev in self.rest(b[pos:], a + pos)]
            return out
        return self.rest(b, a, tried_code=True)

    def rest(self, b, a, tried_code=False):
        n = len(b)
        if n == 0:
            return []
        if all(x == 0 for x in b) and n < 4:
            return [(0, n, 'padding_short', '%d x 0x00' % n)]
        if not tried_code:
            c = self.try_code(a, n)
            if c:
                return [(0, n, c[0], c[1])]
        t = self.table(b, a) or self.records(b)
        if t:
            return [(0, n, t[0], t[1])]
        ev, _ = self.inbound(a, n)
        if a in self.img.words or (n >= 8 and a + ((-a) % 4) in self.img.words):
            return [(0, n, 'data_ref', '; '.join(['pointer to start; entropy %.2f bits/byte, %s' % (
                entropy(b), b[:8].hex())] + ev))]
        return [(0, n, 'unknown', '; '.join(['entropy %.2f bits/byte, %s' % (entropy(b), b[:8].hex())] + ev))]

    def classify(self, a, b):
        # 0a. hifi4: bytes covered by flix.dis instructions (objdump from the function entries) are code
        if self.img.flix:
            cov = [None] * len(b)
            # walk back to an instruction that may cover the range start
            starts = [x for x in range(a - 15, a + len(b)) if x in self.img.flix]
            for x in starts:
                ln, bun = self.img.flix[x]
                for y in range(max(x, a), min(x + ln, a + len(b))):
                    cov[y - a] = bun
            if any(c is not None for c in cov):
                out, i = [], 0
                while i < len(b):
                    j = i
                    if cov[i] is not None:
                        while j < len(b) and cov[j] is not None:
                            j += 1
                        nb = sum(1 for x in starts if a + i <= x < a + j)
                        bun = sum(1 for x in starts if a + i <= x < a + j and self.img.flix[x][1])
                        out.append((i, j - i, 'code', 'flix.dis: %d insns, %d FLIX bundles' % (nb, bun)))
                    else:
                        while j < len(b) and cov[j] is None:
                            j += 1
                        sub = self.classify_noflix(a + i, b[i:j])
                        out += [(i + o, l, k, e) for o, l, k, e in sub]
                    i = j
                return out
        return self.classify_noflix(a, b)

    def classify_noflix(self, a, b):
        # 0. known structures from docs/memory-maps.md
        for lo, hi, k, ev in self.img.cfg.get('known', []):
            if lo <= a + len(b) - 1 and a <= hi:
                s0, e0 = max(lo, a) - a, min(hi, a + len(b) - 1) - a + 1
                return (self.classify_noflix(a, b[:s0]) if s0 else []) + [(s0, e0 - s0, k, ev)] + \
                    [(e0 + o, l, kk, ee) for o, l, kk, ee in (self.classify_noflix(a + e0, b[e0:]) if e0 < len(b) else [])]
        # 1. the whole range (without trailing fill) is code reached from elsewhere
        t = len(b)
        while t > 0 and b[t - 1] in (0, 0xFF):
            t -= 1
        #    or ends in a control-flow instruction (a function tail such as Thumb "bx lr" = "pG")
        long_fill = any(r[1] >= 16 for r in fill_runs(b))  # zero/fill blocks decode as code too
        for t in ([len(b), t] if t != len(b) else [t]):
            if t < 2 or long_fill:
                continue
            c = self.try_code(a, t)
            if not c or c[0] == 'padding':
                continue
            if self.inbound(a, t)[1] or c[2]:
                res = [(0, t, c[0], c[1] + ('' if self.inbound(a, t)[1] else '; ends in a control-flow instruction'))]
                if t < len(b):
                    res.append((t, len(b) - t, 'padding' if len(b) - t >= 4 else 'padding_short', 'after code'))
                return res
        # 2. NULs around one short printable run (single-character strings such as "\\", "r", "\r\n")
        core = b.strip(b'\0')
        if core and len(core) <= 4 and all(x in PRINT for x in core) and b[0] == 0:
            i = b.index(core)
            return [(0, i, 'padding_short', 'NUL before string'),
                    (i, len(b) - i, 'string_ascii', repr(core.decode('latin-1')) + ' between NULs')]
        th = self.img.cfg['thumb']
        pointed = lambda x: x in self.img.words or (th and (x | 1) in self.img.words)
        marks = sorted(ctype_runs(b) + monotonic_words(b, a) + fill_runs(b) + monotonic_runs(b) + find_strings(b, a, pointed),
                       key=lambda m: (m[0], -m[1]))
        # drop overlaps (fill wins over strings that start inside it, first come first served)
        sel, end = [], 0
        for m in marks:
            if m[0] >= end:
                sel.append(m)
                end = m[0] + m[1]
        if len(sel) == 1 and sel[0][1] == len(b):
            return sel
        out, pos = [], 0
        for off, ln, k, ev in sel:
            out += [(pos + o, l, kk, e) for o, l, kk, e in self.gap(b[pos:off], a + pos)]
            out.append((off, ln, k, ev))
            pos = off + ln
        out += [(pos + o, l, kk, e) for o, l, kk, e in self.gap(b[pos:], a + pos)]
        return out


def main(argv):
    if argv and argv[0] == 'summary':
        return summary(argv[1:])
    if argv and argv[0] == 'compare':
        return compare(argv[1:])
    args, opts = [], {}
    it = iter(argv)
    for x in it:
        if x.startswith('--'):
            opts[x[2:]] = next(it)
        else:
            args.append(x)
    if len(args) != 3:
        print(__doc__)
        return 2
    name, rpath, opath = args
    build = opts.get('build', '/workspace/FT-710_Firmware/build')
    img = Image(name, build)
    collect_targets(img, opts.get('flix'))
    cl = Classifier(img)
    rows = []
    with open(rpath) as f:
        hdr = f.readline().rstrip('\n').split('\t')
        for line in f:
            r = dict(zip(hdr, line.rstrip('\n').split('\t')))
            rows.append(r)

    def work(r):
        a, e = int(r['start'], 16), int(r['end'], 16)
        b = img.read(a, e - a + 1)
        return r, a, e, b, cl.classify(a, b)

    with ThreadPoolExecutor(int(opts.get('jobs', os.cpu_count() or 4))) as ex:
        results = list(ex.map(work, rows))
    with open(opath, 'w') as o:
        o.write('range_start\trange_end\tsub_start\tsub_end\tsize\tnonff\tclass\tevidence\tghidra_refs_in\tghidra_prev\tghidra_next\n')
        for r, a, e, b, subs in results:
            assert sum(s[1] for s in subs) == len(b), (hex(a), subs)
            for off, ln, k, ev in subs:
                nonff = sum(1 for x in b[off:off + ln] if x != 0xFF)
                if nonff == 0:
                    continue
                o.write('0x%08x\t0x%08x\t0x%08x\t0x%08x\t%d\t%d\t%s\t%s\t%s\t%s\t%s\n' % (
                    a, e, a + off, a + off + ln - 1, ln, nonff, k, ev.replace('\t', ' '),
                    r.get('refs_in', ''), r.get('prev', ''), r.get('next', '')))
    return summary([opath])


FAMILY = {'code': 'code', 'code_weak': 'code', 'padding': 'pad', 'padding_short': 'pad', 'string_ascii': 'string',
          'string_utf16': 'string', 'string_sjis': 'string', 'pointer': 'ptr', 'int_table': 'data',
          'float_table': 'data', 'struct_table': 'data', 'struct': 'data', 'data_ref': 'data', 'unknown': 'unknown'}


def compare(argv):
    """compare <out.tsv> <other.tsv> <start-col> <length-col> <class-col> [map=a:b,c:d]
    Byte-level agreement (non-0xFF bytes) between this script's classes (as families) and another classification,
    e.g. T21e's frags_def.tsv (columns start, length, class). Prints a matrix and the disagreeing runs."""
    out, other, sc, lc, cc = argv[:5]
    cmap = dict(x.split(':') for x in argv[5].split(',')) if len(argv) > 5 else {}
    mine = {}
    with open(out) as f:
        f.readline()
        for line in f:
            c = line.rstrip('\n').split('\t')
            for x in range(int(c[2], 16), int(c[3], 16) + 1):
                mine[x] = FAMILY.get(c[6], c[6])
    mat, dis = {}, []
    with open(other) as f:
        hdr = f.readline().rstrip('\n').split('\t')
        for line in f:
            r = dict(zip(hdr, line.rstrip('\n').split('\t')))
            s, n, k = int(r[sc], 16), int(r[lc], 0), r[cc]
            k = cmap.get(k, k)
            got = {}
            for x in range(s, s + n):
                if x in mine:
                    got[mine[x]] = got.get(mine[x], 0) + 1
            for m, cnt in got.items():
                mat[(k, m)] = mat.get((k, m), 0) + cnt
            if set(got) - {k}:
                dis.append((s, n, k, got))
    ks = sorted({a for a, _ in mat})
    ms = sorted({b for _, b in mat})
    print('other\\mine\t' + '\t'.join(ms))
    for k in ks:
        print(k + '\t' + '\t'.join(str(mat.get((k, m), 0)) for m in ms))
    agree = sum(v for (a, b), v in mat.items() if a == b)
    print('agree %d of %d bytes' % (agree, sum(mat.values())))
    for s, n, k, got in dis:
        print('  0x%08x %4d %-7s mine %s' % (s, n, k, ', '.join('%s %d' % kv for kv in sorted(got.items()))))
    return 0


def summary(paths):
    for p in paths:
        tot, cnt = {}, {}
        with open(p) as f:
            f.readline()
            for line in f:
                c = line.split('\t')
                tot[c[6]] = tot.get(c[6], 0) + int(c[5])
                cnt[c[6]] = cnt.get(c[6], 0) + 1
        print('%s: %d non-0xFF bytes' % (p, sum(tot.values())))
        for k in sorted(tot, key=lambda k: -tot[k]):
            print('  %-14s %8d bytes  %5d runs' % (k, tot[k], cnt[k]))
    return 0


if __name__ == '__main__':
    sys.exit(main(sys.argv[1:]))
