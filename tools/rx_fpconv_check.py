#!/usr/bin/env python3
"""T24 MAIN round 4: FTOI, FTOU and ROUND in the MAIN equivalence engine against the RXv2 software manual
R01US0071EJ0100 (FTOI p. 103 and FTOU p. 106 round towards 0; ROUND p. 171 by FPSW.RM, here 0 = nearest, ties to
even; NaN and out of range per Table 1.5, p. 26, with EV = 0).

  python3 -I tools/rx_fpconv_check.py           the engine (EquivMainEmu.java executes the three after the manual)
  python3 -I tools/rx_fpconv_check.py module    the module's own p-code (to check tools/ghidra/rx62t-fpconv-fix.patch;
                                                 GHIDRA_HEADLESS may point at a Ghidra with the patch installed)

Each of the three (and FTOU from memory) runs on 21 values: zeros, ties, fractions, negative values, the limits
around 2^31 and 2^32, infinities and NaN; the needs are those of equiv_main_emu.py (decoded image, project copy).
With the T21i..T24 module all three gave the float bits of src rounded half away from zero (FTOU of 50.7:
0x424C0000). With the patch every in-range value agrees (NaN, out-of-range values and FTOU of values <= -1 are
left to the engine)."""
import os, struct, subprocess, sys, tempfile
MODULE = len(sys.argv) > 1 and sys.argv[1] == 'module'
sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import equiv_main_emu as E

AS = E.tool('RX_BINUTILS', os.path.join(E.HOME, 'opt/rx-binutils-2.42/bin/rx-elf-'), 'as')
LD = E.tool('RX_BINUTILS', os.path.join(E.HOME, 'opt/rx-binutils-2.42/bin/rx-elf-'), 'ld')
src = """
 .text
 .global _t_ftou
_t_ftou: ftou r1, r2
 mov.l r2, r1
 rts
 .global _t_ftoi
_t_ftoi: ftoi r1, r2
 mov.l r2, r1
 rts
 .global _t_round
_t_round: round r1, r2
 mov.l r2, r1
 rts
 .global _t_ftoum
_t_ftoum: sub #8, r0
 mov.l r1, 4[r0]
 ftou 4[r0].l, r1
 add #8, r0
 rts
"""
d = tempfile.mkdtemp(dir=E.scratch_root())
open(d + '/t.s', 'w').write(src)
subprocess.run([AS, '-mcpu=rxv2', d + '/t.s', '-o', d + '/t.o'], check=True)
subprocess.run([LD, '-Ttext=0xFFF00000', '-e', '_t_ftou', d + '/t.o', '-o', d + '/t.elf'], check=True)
from elftools.elf.elffile import ELFFile
elf = ELFFile(open(d + '/t.elf', 'rb'))
txt = elf.get_section_by_name('.text')
syms = {s.name: s['st_value'] for s in elf.get_section_by_name('.symtab').iter_symbols()}
img = E.Image()
eng = E.Engine(img)
eng.send({'op': 'base', 'name': 'new', 'segs': [[txt['sh_addr'], txt.data().hex()]]})
f2b = lambda x: struct.unpack('<I', struct.pack('<f', x))[0]
vals = [0.0, -0.0, 0.4, 0.5, 1.5, 2.5, 50.7, 254.999, -0.7, -1.0, -2.5, -3.5, 2147483520.0, 2147483648.0,
        4294967040.0, 4294967296.0, -2147483648.0, -2147483904.0, float('inf'), float('-inf'), float('nan')]
import math
def expect(name, v):
    # RXv2 software manual R01US0071EJ0100: FTOI p. 103 / FTOU p. 106 truncate; ROUND p. 171 with RM = 0; Table 1.5
    if name in ('t_ftou', 't_ftoum'):
        if math.isnan(v) or v >= 2**32 or v <= -1:
            return 0 if math.copysign(1, v) < 0 else 0xFFFFFFFF
        return int(v) & 0xFFFFFFFF
    if math.isnan(v):
        return 0x7FFFFFFF if math.copysign(1, v) > 0 else 0x80000000
    if math.isinf(v):
        return 0x7FFFFFFF if v > 0 else 0x80000000
    x = int(v) if name == 't_ftoi' else round(v)
    if math.isinf(x) or x >= 2**31 or x < -2**31:
        return 0x7FFFFFFF if v > 0 else 0x80000000
    return x & 0xFFFFFFFF
bad = []
for name in ('t_ftou', 't_ftoi', 't_round', 't_ftoum'):
    for v in vals:
        if MODULE:
            r = eng.send({'op': 'run', 'bases': ['image', 'ram', 'new'], 'entry': syms['_' + name], 'sp': E.STACK,
                          'seed': 1, 'budget': 1000, 'regs': {'R1': f2b(v)}, 'stack': [], 'loads': [], 'snap': E.SNAP,
                          'track': E.TRACK, 'stubs': {}, 'cover': [], 'module_fp': True})
        else:
            r = E.run(eng, ['image', 'ram', 'new'], syms['_' + name], [f2b(v), 0, 0, 0], [], 1, 1000, {}, (), False)
        exp = expect(name, v)
        ok = r['end'] == 'return' and r['r1'] == exp
        bad.append(ok)
        print(f'{name:8s} {v!r:>14} -> {r["end"]} r1=0x{r["r1"]:08x} psw=0x{r["psw"]:08x} manual 0x{exp:08x} {"ok" if ok else "FAIL"}')
eng.close()
print(f'rx_fpconv_check: {sum(bad)} of {len(bad)} agree with the manual')
sys.exit(0 if all(bad) else 1)
