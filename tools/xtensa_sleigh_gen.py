#!/usr/bin/env python3
"""Generate a Ghidra SLEIGH language for the RT600 HiFi4 core from Cadence's xtensa-modules.c (T21a, #97).

Input: `xtensa-modules.c` from Zephyr sdk-ng (overlays/xtensa_nxp_rt600_adsp/binutils/bfd), MIT-licensed by
Cadence; pinned in docs/tooling.md. The generator compiles a small probe (tools/xtensa_isa_dump.c) against it,
reads the probe's JSON, parses the slot decode functions from the C text, and writes the language files.

    python3 -I tools/xtensa_sleigh_gen.py extract  --modules ~/opt/dl/xtensa-modules.c   # -> build dir model.json
    python3 -I tools/xtensa_sleigh_gen.py generate --modules ~/opt/dl/xtensa-modules.c \
        --stock ~/opt/ghidra_12.1.4_PUBLIC/Ghidra/Processors/Xtensa/data/languages --out tools/ghidra/xtensa-rt600hifi4
    python3 -I tools/xtensa_sleigh_gen.py disasm   --modules ... --image file.bin --base 0x200000 --start A --end B
                                              # reference disassembler from the same model (objdump spelling)

The output is a new language variant, Xtensa:LE:32:rt600hifi4, that extends Ghidra's stock Xtensa module
(docs/code/ifdsp/ghidra-flix.md, "The SLEIGH language").
"""
import argparse
import hashlib
import json
import os
import re
import subprocess
import sys

HERE = os.path.dirname(os.path.abspath(__file__))
MODULES_SHA256 = "9e218b19033b93ad53b042f86a643034033a2322cfd09c138592c6255e53f372"

# --------------------------------------------------------------------------------------------------
# Probe build
# --------------------------------------------------------------------------------------------------

SHIM_ANSIDECL = "#define ATTRIBUTE_UNUSED __attribute__((unused))\n"

SHIM_ISA = r"""/* Minimal libisa public types for compiling xtensa-modules.c (written for T21a). */
#ifndef XTISA_SHIM_H
#define XTISA_SHIM_H
#include <stdint.h>
typedef uint32_t uint32;
typedef int xtensa_opcode, xtensa_format, xtensa_regfile, xtensa_state, xtensa_sysreg,
            xtensa_interface, xtensa_funcUnit;
#define XTENSA_UNDEFINED -1
typedef uint32 xtensa_insnbuf_word;
typedef xtensa_insnbuf_word *xtensa_insnbuf;
typedef struct { xtensa_funcUnit unit; int stage; } xtensa_funcUnit_use;
#endif
"""

SHIM_INTERNAL = r"""/* Layout of the libisa tables that xtensa-modules.c initialises (written for T21a). */
#ifndef XTISA_SHIM_INTERNAL_H
#define XTISA_SHIM_INTERNAL_H
#define XTENSA_OPERAND_IS_REGISTER 0x1
#define XTENSA_OPERAND_IS_PCRELATIVE 0x2
#define XTENSA_OPERAND_IS_INVISIBLE 0x4
#define XTENSA_OPERAND_IS_UNKNOWN 0x8
#define XTENSA_OPCODE_IS_BRANCH 0x1
#define XTENSA_OPCODE_IS_JUMP 0x2
#define XTENSA_OPCODE_IS_LOOP 0x4
#define XTENSA_OPCODE_IS_CALL 0x8
#define XTENSA_STATE_IS_EXPORTED 0x1
#define XTENSA_STATE_IS_SHARED_OR 0x2
#define XTENSA_INTERFACE_HAS_SIDE_EFFECT 0x1
typedef void (*xtensa_format_encode_fn)(xtensa_insnbuf);
typedef void (*xtensa_get_slot_fn)(const xtensa_insnbuf, xtensa_insnbuf);
typedef void (*xtensa_set_slot_fn)(xtensa_insnbuf, const xtensa_insnbuf);
typedef int (*xtensa_opcode_decode_fn)(const xtensa_insnbuf);
typedef uint32 (*xtensa_get_field_fn)(const xtensa_insnbuf);
typedef void (*xtensa_set_field_fn)(xtensa_insnbuf, uint32);
typedef int (*xtensa_immed_decode_fn)(uint32 *);
typedef int (*xtensa_immed_encode_fn)(uint32 *);
typedef int (*xtensa_do_reloc_fn)(uint32 *, uint32);
typedef int (*xtensa_undo_reloc_fn)(uint32 *, uint32);
typedef void (*xtensa_opcode_encode_fn)(xtensa_insnbuf);
typedef int (*xtensa_format_decode_fn)(const xtensa_insnbuf);
typedef int (*xtensa_length_decode_fn)(const unsigned char *);
typedef const struct { const char *name; int length; xtensa_format_encode_fn encode_fn;
  int num_slots; const int *slot_id; } xtensa_format_internal;
typedef const struct { const char *name; const char *format; int position;
  xtensa_get_slot_fn get_fn; xtensa_set_slot_fn set_fn;
  const xtensa_get_field_fn *get_field_fns; const xtensa_set_field_fn *set_field_fns;
  xtensa_opcode_decode_fn opcode_decode_fn; const char *nop_name; } xtensa_slot_internal;
/* This core's operand table carries two extra trailing members (not used here). */
typedef const struct { const char *name; int field_id; xtensa_regfile regfile; int num_regs;
  uint32 flags; xtensa_immed_encode_fn encode; xtensa_immed_decode_fn decode;
  xtensa_do_reloc_fn do_reloc; xtensa_undo_reloc_fn undo_reloc; int extra0; int extra1; }
  xtensa_operand_internal;
typedef const struct { union { int operand_id; xtensa_state state; } u; char inout; }
  xtensa_arg_internal;
typedef const struct { int num_operands; xtensa_arg_internal *operands; int num_stateOperands;
  xtensa_arg_internal *stateOperands; int num_interfaceOperands;
  xtensa_interface *interfaceOperands; } xtensa_iclass_internal;
typedef const struct { const char *name; int iclass_id; uint32 flags;
  const xtensa_opcode_encode_fn *encode_fns; int num_funcUnit_uses;
  xtensa_funcUnit_use *funcUnit_uses; } xtensa_opcode_internal;
typedef const struct { const char *name; const char *shortname; xtensa_regfile parent;
  int num_bits; int num_entries; } xtensa_regfile_internal;
typedef const struct { const char *name; int num_bits; uint32 flags; int class_id; char inout; }
  xtensa_interface_internal;
typedef const struct { const char *name; int num_copies; } xtensa_funcUnit_internal;
typedef const struct { const char *name; int num_bits; uint32 flags; } xtensa_state_internal;
typedef const struct { const char *name; int number; int is_user; } xtensa_sysreg_internal;
typedef struct { const char *key; union { xtensa_opcode opcode; xtensa_sysreg sysreg;
  xtensa_state state; xtensa_interface intf; xtensa_funcUnit fun; } u; } xtensa_lookup_entry;
typedef struct {
  int is_big_endian; int insn_size; int insnbuf_size;
  int num_formats; xtensa_format_internal *formats;
  xtensa_format_decode_fn format_decode_fn; xtensa_length_decode_fn length_decode_fn;
  int num_slots; xtensa_slot_internal *slots; int num_fields;
  int num_operands; xtensa_operand_internal *operands;
  int num_iclasses; xtensa_iclass_internal *iclasses;
  int num_opcodes; xtensa_opcode_internal *opcodes; xtensa_lookup_entry *opname_lookup_table;
  int num_regfiles; xtensa_regfile_internal *regfiles;
  int num_states; xtensa_state_internal *states; xtensa_lookup_entry *state_lookup_table;
  int num_sysregs; xtensa_sysreg_internal *sysregs; xtensa_lookup_entry *sysreg_lookup_table;
  int max_sysreg_num[2]; xtensa_sysreg *sysreg_table[2];
  int num_interfaces; xtensa_interface_internal *interfaces; xtensa_lookup_entry *interface_lookup_table;
  int num_funcUnits; xtensa_funcUnit_internal *funcUnits; xtensa_lookup_entry *funcUnit_lookup_table;
} xtensa_isa_internal;
#endif
"""


def sha256(path):
    h = hashlib.sha256()
    with open(path, "rb") as f:
        for chunk in iter(lambda: f.read(1 << 20), b""):
            h.update(chunk)
    return h.hexdigest()


def extract(modules, build):
    """Compile and run the probe; return the model dict (cached in build/model.json)."""
    os.makedirs(os.path.join(build, "shim"), exist_ok=True)
    digest = sha256(modules)
    if digest != MODULES_SHA256:
        print(f"warning: {modules} SHA-256 {digest} differs from the pinned {MODULES_SHA256}", file=sys.stderr)
    cache = os.path.join(build, "model.json")
    stamp = os.path.join(build, "model.sha256")
    probe_src = os.path.join(HERE, "xtensa_isa_dump.c")
    key = digest + " " + sha256(probe_src)
    if os.path.exists(cache) and os.path.exists(stamp) and open(stamp).read() == key:
        with open(cache) as f:
            return json.load(f)
    for name, text in (("ansidecl.h", SHIM_ANSIDECL), ("xtensa-isa.h", SHIM_ISA),
                       ("xtensa-isa-internal.h", SHIM_INTERNAL)):
        with open(os.path.join(build, "shim", name), "w") as f:
            f.write(text)
    exe = os.path.join(build, "xtensa_isa_dump")
    subprocess.run(["cc", "-O1", "-w", "-I" + os.path.join(build, "shim"),
                    '-DMODULES="%s"' % os.path.abspath(modules), probe_src, "-o", exe], check=True)
    with open(cache, "w") as f:
        subprocess.run([exe], stdout=f, check=True)
    with open(stamp, "w") as f:
        f.write(key)
    with open(cache) as f:
        return json.load(f)


# --------------------------------------------------------------------------------------------------
# Model: formats, slots, decode cubes, operands
# --------------------------------------------------------------------------------------------------

def _tokens(text):
    return re.findall(r"[A-Za-z_]\w*|0x[0-9a-fA-F]+|\d+|&&|\|\||==|[(){};]", text)


def parse_decode_function(body, fieldfn_to_id):
    """Parse a Slot_*_decode body into an ordered list of ([(field_id, value), ...], OPCODE_NAME)."""
    toks = _tokens(body)
    pos = 0
    out = []

    def peek():
        return toks[pos] if pos < len(toks) else None

    def set_pos(p):
        nonlocal pos
        pos = p

    def take(expect=None):
        nonlocal pos
        t = toks[pos]
        if expect is not None and t != expect:
            raise ValueError(f"decode parse: expected {expect!r}, got {t!r} at {pos}: {toks[pos-5:pos+5]}")
        pos += 1
        return t

    # condition grammar: or := and ('||' and)*; and := atom ('&&' atom)*; atom := F (insn) == N | '(' or ')'
    # result: disjunctive normal form, a list of conjunctions [(field_id, value), ...]
    def p_or():
        alts = p_and()
        while peek() == "||":
            take()
            alts = alts + p_and()
        return alts

    def p_and():
        alts = p_atom()
        while peek() == "&&":
            take()
            rhs = p_atom()
            alts = [a + b for a in alts for b in rhs]
        return alts

    def p_atom():
        if peek() == "(":
            take()
            r = p_or()
            take(")")
            return r
        fn = take()
        take("(")
        take("insn")
        take(")")
        take("==")
        v = int(take(), 0)
        return [[(fieldfn_to_id[fn], v)]]

    def stmt(ctx):
        t = peek()
        if t == "if":
            take()
            take("(")
            alts = p_or()
            take(")")
            save = pos
            for c in alts:
                set_pos(save)
                stmt(ctx + c)
        elif t == "{":
            take()
            while peek() != "}":
                stmt(ctx)
            take("}")
        elif t == "return":
            take()
            name = take()
            take(";")
            if name != "XTENSA_UNDEFINED":
                out.append((ctx, name))
        else:
            raise ValueError(f"decode parse: unexpected {t!r}")

    while pos < len(toks):
        stmt([])
    return out


class Model:
    def __init__(self, modules, build):
        self.m = extract(modules, build)
        text = open(modules).read()
        self.text = text
        m = self.m
        self.regfiles = m["regfiles"]
        self.states = m["states"]
        self.formats = m["formats"]
        self.slots = m["slots"]
        self.operands = m["operands"]
        self.iclasses = m["iclasses"]
        self.opcodes = m["opcodes"]
        # opcode enum names
        enum = re.search(r"enum xtensa_opcode_id \{(.*?)\};", text, re.S).group(1)
        self.opcode_enum = {n: i for i, n in enumerate(re.findall(r"OPCODE_\w+", enum))}
        assert len(self.opcode_enum) == len(self.opcodes)
        # field function names per slot (from the Slot_*_get_field_fns arrays)
        fieldfns = {}
        for mm in re.finditer(r"static xtensa_get_field_fn\s+(Slot_\w+)_get_field_fns\[\] = \{(.*?)\};", text, re.S):
            names = [x.strip() for x in mm.group(2).split(",") if x.strip()]
            fieldfns[mm.group(1)] = names
        # slots[] table: decode function name per slot
        st = re.search(r"static xtensa_slot_internal slots\[\] = \{(.*?)\n\};", text, re.S).group(1)
        decoders = re.findall(r"(Slot_\w+)_decode", st)
        getfns = re.findall(r"(Slot_\w+)_get_field_fns", st)
        assert len(decoders) == len(self.slots) == len(getfns)
        self.slot_fmt = {}
        for fi, f in enumerate(self.formats):
            for pos, s in enumerate(f["slots"]):
                self.slot_fmt[s] = (fi, pos)
        for si, s in enumerate(self.slots):
            names = fieldfns[getfns[si]]
            fn2id = {n: i for i, n in enumerate(names) if n != "0"}
            body = re.search(r"\n%s_decode \(const xtensa_insnbuf insn\)\n\{(.*?)\n\}\n" % decoders[si], text, re.S).group(1)
            entries = parse_decode_function(body, fn2id)
            s["fieldmap"] = {int(k): v for k, v in s["fields"].items()}
            cubes = []
            for terms, name in entries:
                cube = {}
                ok = True
                for fid, v in terms:
                    bits = s["fieldmap"][fid]
                    if isinstance(bits, int):  # implicit field: constant
                        ok = ok and bits == v
                        continue
                    if v >> len(bits):
                        ok = False
                    for i, sb in enumerate(bits):
                        bv = (v >> i) & 1
                        if cube.get(sb, bv) != bv:
                            ok = False
                        cube[sb] = bv
                if ok:
                    cubes.append((cube, self.opcode_enum[name]))
            s["cubes"] = cubes
            s["index"] = si
        self.format_tests = self._parse_format_decoder(text)

    @staticmethod
    def _parse_format_decoder(text):
        body = re.search(r"\nformat_decoder \(const xtensa_insnbuf insn\)\n\{(.*?)\n\}", text, re.S).group(1)
        tests = []
        for mm in re.finditer(r"if \((.*?)\)\n\s*return (\d+);", body, re.S):
            terms = re.findall(r"\(insn\[(\d)\] & (0x[0-9a-f]+|\d+)\) == (0x[0-9a-f]+|\d+)", mm.group(1))
            tests.append(([(int(w), int(a, 0), int(b, 0)) for w, a, b in terms], int(mm.group(2))))
        return tests

    # ---- reference decoding (pure model, used to check the model and as a test oracle) ----

    @staticmethod
    def words(data):
        b = bytes(data) + bytes(16)
        return [int.from_bytes(b[i * 4:i * 4 + 4], "little") for i in range(4)]

    def format_of(self, w):
        for terms, f in self.format_tests:
            if all((w[k] & a) == v for k, a, v in terms):
                return f
        return -1

    def slot_value(self, si, w):
        """Slot buffer as an int (slot bit i = bundle bit map[i])."""
        v = 0
        for i, bb in enumerate(self.slots[si]["map"]):
            if (w[bb // 32] >> (bb % 32)) & 1:
                v |= 1 << i
        return v

    def decode_slot(self, si, sv):
        for cube, opc in self.slots[si]["cubes"]:
            if all(((sv >> b) & 1) == v for b, v in cube.items()):
                return opc
        return -1

    def opnd_field(self, si, opnd, sv):
        bits = self.slots[si]["fieldmap"].get(opnd["field"])
        if bits is None:
            return None
        if isinstance(bits, int):
            return bits
        return sum(((sv >> b) & 1) << i for i, b in enumerate(bits))

    def check_samples(self):
        bad = 0
        for si, s in enumerate(self.slots):
            for w0, w1, w2, opc in s["samples"]:
                sv = w0 | (w1 << 32) | (w2 << 64)
                got = self.decode_slot(si, sv)
                if got != opc:
                    bad += 1
                    if bad < 10:
                        print(f"sample mismatch slot {s['name']}: {sv:#x} lib={opc} model={got}", file=sys.stderr)
        # every encodable opcode decodes to itself through the model
        for oi, o in enumerate(self.opcodes):
            for si, (w0, w1, w2, dec) in o["enc"].items():
                sv = w0 | (w1 << 32) | (w2 << 64)
                if self.decode_slot(int(si), sv) != oi or dec != oi:
                    bad += 1
                    if bad < 20:
                        print(f"encode mismatch {o['name']} slot {si}: lib={dec} model={self.decode_slot(int(si), sv)}",
                              file=sys.stderr)
        return bad


    # ---- operand values ----

    def operand_value(self, opnd, field):
        """Decoded operand value (libisa decode), as an unsigned 32-bit int, or None if invalid."""
        d = opnd["decode"]
        if d is None:
            return field
        return d[field]

    @staticmethod
    def reloc_form(opnd):
        """PC-relative operand: return (add, mask) with address = ((pc + add) & ~mask) + value."""
        for add, mask in ((0, 0), (0, 3), (3, 3)):
            if all(((((pc + add) & ~mask) + v) & 0xffffffff) == x for pc, v, x, err in opnd["reloc"]):
                return add, mask
        raise ValueError("unknown reloc form for " + opnd["name"])

    def disasm(self, data, addr):
        """Disassemble one instruction like objdump: (length, text) or (1, '.byte 0x..')."""
        w = self.words(data)
        f = self.format_of(w)
        if f < 0 or self.formats[f]["length"] > len(data):
            return 1, ".byte %#02x" % data[0]
        fmt = self.formats[f]
        parts = []
        for si in fmt["slots"]:
            sv = self.slot_value(si, w)
            opc = self.decode_slot(si, sv)
            if opc < 0:
                return 1, ".byte %#02x" % data[0]
            parts.append(self.format_op(si, opc, sv, addr))
        text = "; ".join(parts)
        if len(parts) > 1:
            text = "{ " + text + " }"
        return fmt["length"], text

    def format_op(self, si, opc, sv, addr):
        o = self.opcodes[opc]
        ops = []
        for oid, inout in self.iclasses[o["iclass"]]["ops"]:
            od = self.operands[oid]
            if od["flags"] & 4 or inout == "s":  # invisible; 's' = libisa "sout" (invisible output)
                continue
            fv = self.opnd_field(si, od, sv)
            v = self.operand_value(od, fv)
            if od["flags"] & 1:
                rf = self.regfiles[od["regfile"]]
                s = "%s%u" % (rf["short"], v)
                for k in range(1, od["num_regs"]):
                    s += ":%s%u" % (rf["short"], v + k)
                ops.append(s)
            elif od["flags"] & 2:
                add, mask = self.reloc_form(od)
                ops.append("0x%x" % ((((addr + add) & ~mask) + v) & 0xffffffff))
            else:
                sv32 = v - (1 << 32) if v & 0x80000000 else v
                ops.append("%d" % sv32 if -256 < sv32 < 256 else "0x%x" % v)
        return o["name"] + ("\t" + ", ".join(ops) if ops else "")


def read_flix_dis(path):
    """Yield (address, bytes, text) from an objdump-style listing; annotations are stripped."""
    rx = re.compile(r"^\s+([0-9a-f]+):\t([0-9a-f]+)\s+\t(.*)$")
    for line in open(path):
        mm = rx.match(line.rstrip("\n"))
        if not mm:
            continue
        text = mm.group(3)
        text = re.sub(r"  ; .*$", "", text)
        text = re.sub(r"(l32r\t\w+, 0x[0-9a-f]+) \(0x[0-9a-f]+\)", r"\1", text)
        yield int(mm.group(1), 16), bytes.fromhex(mm.group(2)), text


def selftest(M, dis):
    n = bad = 0
    for addr, b, text in read_flix_dis(dis):
        if text.startswith(".byte"):  # padding between functions (objdump decodes only inside a function)
            continue
        n += 1
        ln, t = M.disasm(b + bytes(11), addr)
        if t.startswith(".byte"):
            ln = 1
        if ln != len(b) or t != text:
            bad += 1
            if bad <= 20:
                print(f"{addr:x}: {b.hex()}\n  objdump: {text}\n  model:   {t} (len {ln})")
    print(f"selftest: {n - bad}/{n} instructions match objdump exactly")
    return bad


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["extract", "check", "selftest"])
    ap.add_argument("--dis", default=os.path.join(HERE, "..", "decomp", "ifdsp", "hifi4", "flix.dis"))
    ap.add_argument("--modules", default=os.path.expanduser("~/opt/dl/xtensa-modules.c"))
    ap.add_argument("--build", default=os.path.expanduser("~/.cache/xtensa_sleigh_gen"))
    a = ap.parse_args()
    if a.cmd == "extract":
        m = extract(a.modules, a.build)
        print({k: len(v) for k, v in m.items()})
    elif a.cmd == "check":
        M = Model(a.modules, a.build)
        print("cubes per slot:", {s["name"]: len(s["cubes"]) for s in M.slots})
        print("model mismatches:", M.check_samples())
    elif a.cmd == "selftest":
        sys.exit(1 if selftest(Model(a.modules, a.build), a.dis) else 0)
