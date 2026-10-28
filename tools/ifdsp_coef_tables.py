#!/usr/bin/env python3
"""Find and characterise numeric tables (filter coefficients, windows, sin/cos, gain curves) in the
IFDSP HiFi4 SRAM image (T12e). Stdlib only.

Table starts are the addresses that code loads with L32R (literal pool values) or that a data word
points to, inside the rodata (0x200000-0x2062D4) and .data (0x236800-0x2383B4) ranges. A table runs to
the next referenced address (cap 4096 words). Each table is classified:

  float32 run  -> stats, sum (DC gain of a FIR), mirror symmetry (linear-phase FIR), sin/cos/window
                  shape checks, a magnitude response at Fs (default 12 kHz) with the -3/-6/-40 dB points,
                  and biquad checks (groups of 5 or 6 coefficients with stable poles)
  int16/int32  -> printed as Q15 / Q31 when the words are not plausible floats

usage: python3 -I tools/ifdsp_coef_tables.py <sram_text.bin> [--fs 12000] [--min 8] [--dis fn.dis]
  --dis: a listing from tools/ifdsp_hifi4_dis.py; with it, each table lists the functions that load it.
"""
import cmath, math, re, struct, sys, collections

BASE = 0x200000
RANGES = [(0x200000, 0x2062D4), (0x236800, 0x2383B4)]
TEXT = (0x207000, 0x236800)


def in_ranges(v):
    return any(lo <= v < hi for lo, hi in RANGES)


def f32(w):
    return struct.unpack('<f', struct.pack('<I', w))[0]


def plausible_float(w):
    if w == 0:
        return True
    x = f32(w)
    return math.isfinite(x) and 1e-12 < abs(x) < 1e7


def freq_resp(h, fs, npts=512):
    out = []
    for k in range(npts + 1):
        f = fs / 2 * k / npts
        z = cmath.exp(-2j * math.pi * f / fs)
        acc, zz = 0j, 1 + 0j
        for c in h:
            acc += c * zz
            zz *= z
        out.append((f, abs(acc)))
    return out


def edges(resp):
    """-3, -6, -40 dB crossings relative to the peak; returns the passband type guess too."""
    peak = max(m for _, m in resp) or 1e-30
    db = [(f, 20 * math.log10(max(m, 1e-30) / peak)) for f, m in resp]
    res = {}
    for lvl in (-3, -6, -40):
        cross = [db[i][0] for i in range(1, len(db)) if (db[i - 1][1] >= lvl) != (db[i][1] >= lvl)]
        res[lvl] = cross[:4]
    fpk = max(resp, key=lambda t: t[1])[0]
    dc, ny = db[0][1], db[-1][1]
    if dc > -1 and ny < -20:
        kind = 'lowpass'
    elif dc < -20 and ny > -1:
        kind = 'highpass'
    elif dc < -20 and ny < -20:
        kind = 'bandpass(peak %.0f Hz)' % fpk
    elif dc > -3 and ny > -3 and min(d for _, d in db) < -20:
        kind = 'bandstop'
    else:
        kind = 'other'
    return kind, res


def pole_radius(a1, a2):
    """largest pole radius of 1 + a1 z^-1 + a2 z^-2"""
    disc = a1 * a1 - 4 * a2
    if disc >= 0:
        return max(abs((-a1 + math.sqrt(disc)) / 2), abs((-a1 - math.sqrt(disc)) / 2))
    return math.sqrt(abs(a2))


def biquad_sign(c):
    """c = b0 b1 b2 a1 a2. Returns +1 if 1 + a1 z^-1 + a2 z^-2 is stable, -1 if 1 - a1 z^-1 - a2 z^-2 is,
    None if neither (or the section is trivial)."""
    b0, b1, b2, a1, a2 = c
    if a1 == 0 and a2 == 0:
        return None
    for s in (1, -1):
        if pole_radius(s * a1, s * a2) < 0.99999:
            return s
    return None


def cascade_resp(secs, sign, fs, npts=512):
    out = []
    for k in range(npts + 1):
        f = fs / 2 * k / npts
        z1 = cmath.exp(-2j * math.pi * f / fs)
        h = 1 + 0j
        for b0, b1, b2, a1, a2 in secs:
            h *= (b0 + b1 * z1 + b2 * z1 * z1) / (1 + sign * a1 * z1 + sign * a2 * z1 * z1)
        out.append((f, abs(h)))
    return out


def shape(x):
    n = len(x)
    notes = []
    mx = max(abs(v) for v in x) or 1
    sym = max(abs(x[i] - x[n - 1 - i]) for i in range(n // 2)) / mx if n > 1 else 1
    asym = max(abs(x[i] + x[n - 1 - i]) for i in range(n // 2)) / mx if n > 1 else 1
    if sym < 1e-4:
        notes.append('symmetric')
    elif asym < 1e-4:
        notes.append('antisymmetric')
    # odd-length symmetric with a centre tap: check also n-1
    for N in (n, n + 1, n - 1, 2 * n, 4 * n, 2 * (n - 1), 4 * (n - 1)):
        if N < 4:
            continue
        for nm, fn in (('sin', math.sin), ('cos', math.cos)):
            err = max(abs(x[k] - fn(2 * math.pi * k / N)) for k in range(n))
            if err < 1e-4:
                notes.append('%s(2*pi*k/%d)' % (nm, N))
                break
    if min(x) >= 0 and sym < 1e-3 and x[0] < 0.2 * mx and abs(x[n // 2] - mx) < 1e-6 * mx + 1e-9:
        notes.append('window-like')
    mono = all(x[i] <= x[i + 1] for i in range(n - 1)) or all(x[i] >= x[i + 1] for i in range(n - 1))
    if mono and n > 4:
        notes.append('monotonic %.4g..%.4g' % (x[0], x[-1]))
    return notes


def main():
    a = sys.argv[1:]
    binf = a[0]
    fs = float(a[a.index('--fs') + 1]) if '--fs' in a else 12000.0
    minw = int(a[a.index('--min') + 1]) if '--min' in a else 8
    dis = a[a.index('--dis') + 1] if '--dis' in a else None
    d = open(binf, 'rb').read()
    word = lambda v: struct.unpack_from('<I', d, v - BASE)[0]
    refs = collections.defaultdict(set)
    for o in range(0, len(d) - 3, 4):  # literal pools (in .text) and data pointers
        v = struct.unpack_from('<I', d, o)[0]
        if in_ranges(v) and v % 4 == 0:
            refs[v].add(BASE + o)
    users = collections.defaultdict(set)
    if dis:
        cur = None
        for ln in open(dis):
            m = re.match(r';; ---- ([0-9a-f]+) (\S+)', ln)
            if m:
                cur = '%s' % m.group(2) if not m.group(2).startswith('FUN_') else m.group(1)
                continue
            for m in re.finditer(r'l32r\s+a\d+, 0x[0-9a-f]+ \(0x([0-9a-f]+)\)', ln):
                v = int(m.group(1), 16)
                if in_ranges(v):
                    users[v].add(cur)
    # code literal pools are inside TEXT; a value is a table start if referenced from a pool or data
    starts = sorted(v for v in refs if in_ranges(v))
    hi_of = lambda v: next(h for lo, h in RANGES if lo <= v < h)
    for i, s in enumerate(starts):
        e = min(starts[i + 1] if i + 1 < len(starts) else hi_of(s), hi_of(s), s + 4 * 4096)
        n = (e - s) // 4
        if n < minw:
            continue
        ws = [word(s + 4 * k) for k in range(n)]
        nz = [w for w in ws if w]
        if len(nz) < minw // 2:
            continue
        pf = sum(1 for w in ws if plausible_float(w)) / n
        src = sorted(users.get(s, ())) or ['ptr@' + ','.join('%x' % p for p in sorted(refs[s]) if not TEXT[0] <= p < TEXT[1])]
        head = '%08x  %4d words  used by %s' % (s, n, ' '.join(src)[:90])
        if pf > 0.97:
            # trim trailing zeros (padding)
            x = [f32(w) for w in ws]
            while len(x) > minw and x[-1] == 0:
                x.pop()
            n2 = len(x)
            mn, mx = min(x), max(x)
            notes = shape(x)
            line = '%s\n    float32 n=%d min=%.6g max=%.6g sum=%.6g %s' % (head, n2, mn, mx, sum(x), ' '.join(notes))
            print(line)
            print('    first: ' + ' '.join('%.6g' % v for v in x[:8]))
            if 'symmetric' in notes or 'antisymmetric' in notes or (abs(sum(x) - 1) < 0.02 and n2 >= 15):
                kind, ed = edges(freq_resp(x, fs))
                print('    FIR @%g Hz: %s  -3dB %s  -6dB %s  -40dB %s' % (
                    fs, kind, ['%.0f' % f for f in ed[-3]], ['%.0f' % f for f in ed[-6]], ['%.0f' % f for f in ed[-40]]))
            nb = n2 // 5
            if nb >= 1 and n2 - 5 * nb <= 1:
                secs = [x[5 * k:5 * k + 5] for k in range(nb)]
                sg = [biquad_sign(c) for c in secs]
                real = [c for c, g in zip(secs, sg) if g is not None]
                if real and all(g in (None, sg[0]) for g in sg) and sg[0] is not None:
                    kind, ed = edges(cascade_resp(secs, sg[0], fs))
                    dc = abs(cascade_resp(secs, sg[0], fs, 1)[0][1])
                    order = sum(1 if c[2] == 0 and c[4] == 0 else 2 for c in secs)
                    print('    IIR cascade %d sections (b0 b1 b2 a1 a2, a-sign %+d, order %d) @%g Hz: %s, |H(0)|=%.3g'
                          '  -3dB %s  -6dB %s  -40dB %s' % (nb, sg[0], order, fs, kind, dc,
                          ['%.0f' % f for f in ed[-3]], ['%.0f' % f for f in ed[-6]], ['%.0f' % f for f in ed[-40]]))
        else:
            q = [w - (1 << 32) if w & 0x80000000 else w for w in ws]
            h16 = [struct.unpack_from('<h', d, s - BASE + 2 * k)[0] for k in range(2 * n)]
            print('%s\n    int n=%d (not float) first int32: %s' % (head, n, ' '.join(str(v) for v in q[:8])))
            print('    as int16: ' + ' '.join(str(v) for v in h16[:16]))


if __name__ == '__main__':
    main()
