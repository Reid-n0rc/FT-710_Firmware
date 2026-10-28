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


# --------------------------------------------------------------------------------------------------
# Semantics
# --------------------------------------------------------------------------------------------------
# Hand-written p-code for the base-ISA and FPU operations that appear in FLIX slots or that the
# generator emits in the 24/16-bit formats. Placeholders: {rN} = operand N read (iclass order, including
# invisible operands), {wN} = operand N written. Immediates are constants, PC-relative operands are
# memory references (*:4 address) as in the stock module, so {rN} of l32r reads the literal and a branch
# does "goto {rN}". The generic fall-back for everything else is a named p-code operation per opcode.

SEM = {
    "nop": "",
    "add": "{w0} = {r1} + {r2};", "add.n": "{w0} = {r1} + {r2};",
    "addx2": "{w0} = ({r1} << 1) + {r2};", "addx4": "{w0} = ({r1} << 2) + {r2};",
    "addx8": "{w0} = ({r1} << 3) + {r2};",
    "sub": "{w0} = {r1} - {r2};",
    "subx2": "{w0} = ({r1} << 1) - {r2};", "subx4": "{w0} = ({r1} << 2) - {r2};",
    "subx8": "{w0} = ({r1} << 3) - {r2};",
    "addi": "{w0} = {r1} + {r2};", "addi.n": "{w0} = {r1} + {r2};", "addmi": "{w0} = {r1} + {r2};",
    "and": "{w0} = {r1} & {r2};", "or": "{w0} = {r1} | {r2};", "xor": "{w0} = {r1} ^ {r2};",
    "neg": "{w0} = -{r1};",
    "abs": "local v:4 = {r1}; {w0} = (v ^ (v s>> 31)) - (v s>> 31);",
    "min": "local a:4 = {r1}; local b:4 = {r2}; {w0} = a; if (a s<= b) goto <done>; {w0} = b; <done>",
    "max": "local a:4 = {r1}; local b:4 = {r2}; {w0} = a; if (a s>= b) goto <done>; {w0} = b; <done>",
    "minu": "local a:4 = {r1}; local b:4 = {r2}; {w0} = a; if (a <= b) goto <done>; {w0} = b; <done>",
    "maxu": "local a:4 = {r1}; local b:4 = {r2}; {w0} = a; if (a >= b) goto <done>; {w0} = b; <done>",
    "mov.n": "{w0} = {r1};",
    "movi": "{w0} = {r1};", "movi.n": "{w0} = {r1};",
    "moveqz": "if ({r2} != 0) goto <done>; {w0} = {r1}; <done>",
    "movnez": "if ({r2} == 0) goto <done>; {w0} = {r1}; <done>",
    "movltz": "if ({r2} s>= 0) goto <done>; {w0} = {r1}; <done>",
    "movgez": "if ({r2} s< 0) goto <done>; {w0} = {r1}; <done>",
    "movt": "if ({r2} == 0) goto <done>; {w0} = {r1}; <done>",
    "movf": "if ({r2} != 0) goto <done>; {w0} = {r1}; <done>",
    "extui": "{w0} = ({r1} >> {r2}) & ((1 << {r3}) - 1);",
    "slli": "{w0} = {r1} << {r2};", "srli": "{w0} = {r1} >> {r2};", "srai": "{w0} = {r1} s>> {r2};",
    "sll": "{w0} = {r1} << (32 - SAR);", "srl": "{w0} = {r1} >> SAR;", "sra": "{w0} = {r1} s>> SAR;",
    "src": "local v:8 = (zext({r1}) << 32) | zext({r2}); v = v >> SAR; {w0} = v:4;",
    "ssl": "SAR = 32 - ({r0} & 31);", "ssr": "SAR = {r0} & 31;",
    "ssai": "SAR = {r0};", "ssa8l": "SAR = ({r0} & 3) << 3;", "ssa8b": "SAR = 32 - (({r0} & 3) << 3);",
    "sext": "local sh:4 = 31 - {r2}; {w0} = ({r1} << sh) s>> sh;",
    "mull": "{w0} = {r1} * {r2};",
    "quou": "{w0} = {r1} / {r2};", "quos": "{w0} = {r1} s/ {r2};",
    "remu": "{w0} = {r1} % {r2};", "rems": "{w0} = {r1} s% {r2};",
    "ret": "return [a0];", "ret.n": "return [a0];", "jx": "goto [{r0}];",
    "l32r": "{w0} = {r1};",
    "l32i": "{w0} = *:4 ({r1} + {r2});", "l32i.n": "{w0} = *:4 ({r1} + {r2});",
    "l16ui": "{w0} = zext(*:2 ({r1} + {r2}));", "l16si": "{w0} = sext(*:2 ({r1} + {r2}));",
    "l8ui": "{w0} = zext(*:1 ({r1} + {r2}));",
    "s32i": "*:4 ({r1} + {r2}) = {r0};", "s32i.n": "*:4 ({r1} + {r2}) = {r0};",
    "s16i": "*:2 ({r1} + {r2}) = {r0}:2;", "s8i": "*:1 ({r1} + {r2}) = {r0}:1;",
    # FPU on the AE_DR registers (single precision in the low 32 bits) [inference: operand register files];
    # the upper half of the destination is written as zero [guess].
    "add.s": "{w0} = zext({r1}:4 f+ {r2}:4);", "sub.s": "{w0} = zext({r1}:4 f- {r2}:4);",
    "mul.s": "{w0} = zext({r1}:4 f* {r2}:4);",
    "madd.s": "{w0} = zext({r0}:4 f+ ({r1}:4 f* {r2}:4));",
    "msub.s": "{w0} = zext({r0}:4 f- ({r1}:4 f* {r2}:4));",
    "abs.s": "{w0} = zext(abs({r1}:4));", "neg.s": "{w0} = zext(f- {r1}:4);",
    "mov.s": "{w0} = {r1};",
    "wfr": "{w0} = zext({r1});", "rfr": "{w0} = {r1}:4;",
    # FP compares write a BR pair (b0:b1, one flag per lane of the 2-way vector FPU [inference]): generic.
    "orb": "{w0} = {r1} | {r2};", "andb": "{w0} = {r1} & {r2};", "xorb": "{w0} = {r1} ^ {r2};",
    "andbc": "{w0} = {r1} & ({r2} ^ 1);", "orbc": "{w0} = {r1} | ({r2} ^ 1);",
}

# Branch conditions (target = last operand). The ".w15" forms are the FLIX-slot variants of the base branches.
BRANCH = {
    "beqz": "{r0} == 0", "bnez": "{r0} != 0", "bltz": "{r0} s< 0", "bgez": "{r0} s>= 0",
    "beq": "{r0} == {r1}", "bne": "{r0} != {r1}", "blt": "{r0} s< {r1}", "bge": "{r0} s>= {r1}",
    "bltu": "{r0} < {r1}", "bgeu": "{r0} >= {r1}",
    "beqi": "{r0} == {r1}", "bnei": "{r0} != {r1}", "blti": "{r0} s< {r1}", "bgei": "{r0} s>= {r1}",
    "bltui": "{r0} < {r1}", "bgeui": "{r0} >= {r1}",
    "bany": "({r0} & {r1}) != 0", "bnone": "({r0} & {r1}) == 0",
    "ball": "(~{r0} & {r1}) == 0", "bnall": "(~{r0} & {r1}) != 0",
    "bbc": "(({r0} >> ({r1} & 31)) & 1) == 0", "bbs": "(({r0} >> ({r1} & 31)) & 1) != 0",
    "bbci": "(({r0} >> {r1}) & 1) == 0", "bbsi": "(({r0} >> {r1}) & 1) != 0",
}

# Loops (operands: ars, ulabel8) -- as the stock module does it, with LBEG at the end of the bundle.
LOOP = {
    "loop": "",
    "loopgtz": "if ({r0} s<= 0) goto {r1};",
    "loopnez": "if ({r0} == 0) goto {r1};",
}

# States that would only clutter the decompiler output; they are left out of the generic p-code.
NOISE_STATES = {"CPENABLE", "InvalidFlag", "DivZeroFlag", "OverflowFlag", "UnderflowFlag", "InexactFlag",
                "RoundMode", "XTSYNC", "ERI_RAW_INTERLOCK"}

# --------------------------------------------------------------------------------------------------
# SLEIGH emitter
# --------------------------------------------------------------------------------------------------

TOKENS = {2: ("bx16", "b16"), 3: ("bx24", "b24"), 6: ("fx48", "x48"), 11: ("fx88", "x88")}

STOCK_SR = ["LBEG", "LEND", "LCOUNT", "SAR", "BR", "LITBASE", "SCOMPARE1", "ACCLO", "ACCHI", "M0", "M1", "M2",
            "M3", "WindowBase", "WindowStart", "PTEVADDR", "MMID", "RASID", "ITLBCFG", "DTLBCFG",
            "IBREAKENABLE", "MEMCTL", "CACHEATTR", "ATOMCTL", "DDR", "MEPC", "MEPS", "MESAVE", "MESR", "MECR",
            "MEVADDR", "IBREAKA0", "IBREAKA1", "DBREAKA0", "DBREAKA1", "DBREAKC0", "DBREAKC1", "EPC1", "EPC2",
            "EPC3", "EPC4", "EPC5", "EPC6", "EPC7", "DEPC", "EPS2", "EPS3", "EPS4", "EPS5", "EPS6", "EPS7",
            "EXCSAVE1", "EXCSAVE2", "EXCSAVE3", "EXCSAVE4", "EXCSAVE5", "EXCSAVE6", "EXCSAVE7", "CPENABLE",
            "INTERRUPT", "INTSET", "INTCLEAR", "INTENABLE", "PS", "VECBASE", "EXCCAUSE", "DEBUGCAUSE",
            "CCOUNT", "PRID", "ICOUNT", "ICOUNTLEVEL", "EXCVADDR", "CCOMPARE0", "CCOMPARE1", "CCOMPARE2",
            "MISC0", "MISC1", "MISC2", "MISC3", "THREADPTR", "FCR", "FSR", "ACC"]

REG_NAMES = {"AR": "a", "AE_DR": "aed", "AE_VALIGN": "u", "AE_EP": "aep", "BR": "b"}  # SLEIGH register prefix
REG_SIZE = {"AR": 4, "MR": 4, "BR": 1, "AE_DR": 8, "AE_VALIGN": 8, "AE_EP": 1,
            "BR2": 2, "BR4": 4, "BR8": 8, "BR16": 16}


def size_bytes(bits):
    for n in (1, 2, 4, 8, 16):
        if bits <= n * 8:
            return n
    raise ValueError(bits)


def runs(bits):
    """Group [(bit, value_or_index)] sorted by bit into maximal runs of consecutive bits."""
    out = []
    for b, v in sorted(bits):
        if out and out[-1][1] + 1 == b:
            out[-1][1] = b
            out[-1][2].append(v)
        else:
            out.append([b, b, [v]])
    return out


class Emitter:
    def __init__(self, M, staged=True):
        self.M = M
        self.staged = staged
        self.fields = {}       # token -> {name: (lo, hi)}
        self.attach = {}       # regfile -> set of field names
        self.subtables = {}    # name -> list of constructor lines
        self.pcodeops = set()
        self.stock_pcodeops = set()
        self.reserved = set()
        self.stats = {}

    # ---- fields and constraints ----

    def field(self, length, lo, hi, attach=None):
        tok, pre = TOKENS[length]
        name = f"{pre}_{lo}_{hi}" + (f"_{attach}" if attach else "")
        self.fields.setdefault(tok, {})[name] = (lo, hi)
        if attach:
            self.attach.setdefault(attach, set()).add(name)
        return name

    def constraint(self, length, bitvals):
        """bitvals: {bundle_bit: 0/1} -> SLEIGH pattern text."""
        terms = []
        for lo, hi, vals in runs(bitvals.items()):
            v = sum(b << i for i, b in enumerate(vals))
            terms.append(f"{self.field(length, lo, hi)}={v}")
        return " & ".join(terms)

    def value_expr(self, length, bundle_bits):
        """Field value from bundle bits (LSB first) -> (SLEIGH expression, [fields used])."""
        parts = []
        used = []
        # group consecutive bundle bits that are also consecutive field bits
        cur = None
        for i, b in enumerate(bundle_bits):
            if cur and cur[1] + 1 == b and cur[3] + 1 == i:
                cur[1] = b
                cur[3] = i
            else:
                cur = [b, b, i, i]
                parts.append(cur)
        terms = []
        for lo, hi, flo, fhi in parts:
            f = self.field(length, lo, hi)
            used.append(f)
            terms.append(f if flo == 0 else f"({f} << {flo})")
        return " | ".join(terms) if len(terms) > 1 else terms[0], used

    # ---- operands ----

    def reg_name(self, rf, v, nregs=1):
        """SLEIGH display text and exported varnode for register v of register file rf."""
        name = rf["name"]
        short = rf["short"]
        disp = f"{short}{v}"
        if nregs > 1:  # register group, objdump prints b0:b1
            disp = ":".join(f"{short}{v + k}" for k in range(nregs))
            if name == "BR":
                return disp, f"br{nregs}_{v}"
            return disp, self.reg_name(rf, v)[1]
        if name in REG_NAMES:
            return None, f"{REG_NAMES[name]}{v}"
        if name == "MR":
            return disp, f"M{v}"
        if name.startswith("BR"):
            return disp, f"br{REG_SIZE[name]}_{v}"
        raise ValueError(name)

    def operand(self, si, oid):
        """Subtable for operand oid in slot si; returns its name."""
        name = f"o{si}_{oid}"
        if name in self.subtables:
            return name
        M = self.M
        od = M.operands[oid]
        slot = M.slots[si]
        length = M.formats[M.slot_fmt[si][0]]["length"]
        fbits = slot["fieldmap"][od["field"]]
        if fbits == []:
            fbits = 0
        if isinstance(fbits, int):  # implicit field
            raw_vals = None
            const = fbits
        else:
            const = None
            bb = [slot["map"][b] for b in fbits]
        is_reg = od["flags"] & 1
        pcrel = od["flags"] & 2
        lines = []
        if is_reg:
            rf = M.regfiles[od["regfile"]]
            if const is not None:
                v = M.operand_value(od, const)
                disp, reg = self.reg_name(rf, v, od["num_regs"])
                lines.append(f'{name}: {disp_text(disp, reg)} is epsilon {{ export {reg}; }}')
            else:
                dec = od["decode"]
                ident = dec is None or all(dec[x] == x for x in range(len(dec)))
                contiguous = all(bb[i] + 1 == bb[i + 1] for i in range(len(bb) - 1))
                if ident and contiguous and rf["name"] in REG_NAMES and od["num_regs"] == 1:
                    f = self.field(length, bb[0], bb[-1], attach=rf["name"])
                    lines.append(f"{name}: {f} is {f} {{ export {f}; }}")
                else:
                    for x in range(1 << len(bb)):
                        v = M.operand_value(od, x)
                        if v is None:
                            continue
                        disp, reg = self.reg_name(rf, v, od["num_regs"])
                        c = self.constraint(length, {bb[i]: (x >> i) & 1 for i in range(len(bb))})
                        lines.append(f'{name}: {disp_text(disp, reg)} is {c} {{ export {reg}; }}')
        else:
            if const is not None:
                v = M.operand_value(od, const)
                pat, expr = "epsilon", str(sx32(v))
            else:
                raw, used = self.value_expr(length, bb)
                pat = " & ".join(dict.fromkeys(used))
                expr = decode_expr(od, raw, len(bb))
            if expr is None:  # no closed form: one constructor per value
                for x in range(1 << len(bb)):
                    v = M.operand_value(od, x)
                    if v is None:
                        continue
                    c = self.constraint(length, {bb[i]: (x >> i) & 1 for i in range(len(bb))})
                    lines.append(self.imm_ctor(name, od, c, str(sx32(v))))
            else:
                lines.append(self.imm_ctor(name, od, pat, expr))
        self.subtables[name] = lines
        return name

    def imm_ctor(self, name, od, pat, expr):
        if od["flags"] & 2:
            add, mask = Model.reloc_form(od)
            base = "inst_start" if not add else f"(inst_start + {add})"
            if mask:
                base = f"({base} & ~{mask})"
            return f"{name}: val is {pat} [ val = ({base} + ({expr})) & 0xffffffff; ] {{ export *:4 val; }}"
        e = expr.strip("()")
        if re.fullmatch(r"[a-z0-9_]+", e) and e == pat:  # identity: export the field itself
            return f"{name}: {e} is {e} {{ export *[const]:4 {e}; }}"
        return f"{name}: val is {pat} [ val = {expr}; ] {{ export *[const]:4 val; }}"

    # ---- registers and states ----

    def state_reg(self, st):
        n = self.M.states[st]["name"]
        if n in STOCK_SR:
            return n
        return "st_" + n

    # ---- per-opcode constructor bodies ----

    def op_semantics(self, opc, opnames, inouts, regsizes, wnames):
        """Return (compute, commit) p-code text for one operation. opnames[i] = operand subtable,
        wnames[i] = where output i is written in the compute part (staging register or the operand)."""
        M = self.M
        o = M.opcodes[opc]
        name = o["name"]
        base = name[:-4] if name.endswith(".w15") else name
        r = {f"r{i}": n for i, n in enumerate(opnames)}
        w = {f"w{i}": wnames[i] for i in range(len(opnames))}
        commit = []
        for i, io in enumerate(inouts):
            if io in "oms" and wnames[i] != opnames[i]:
                commit.append(f"{opnames[i]} = {wnames[i]};")
        if o["flags"] & 1 and base in BRANCH:  # conditional branch: target is the last operand
            cond = BRANCH[base].format(**r)
            tgt = opnames[-1]
            if self.staged_ctx:
                return f"bcond = {cond};", "\n".join(commit + [f"if (bcond) goto {tgt};"])
            return f"if ({cond}) goto {tgt};", ""
        if o["flags"] & 4 and name in LOOP:
            body = (f"LCOUNT = {r['r0']} - 1; LBEG = inst_next; LEND = &{r['r1']}; " + LOOP[name].format(**r))
            return "", body if self.staged_ctx else body
        if name in SEM:
            return SEM[name].format(**r, **w), "\n".join(commit)
        return self.generic(opc, opnames, inouts, regsizes, wnames), "\n".join(commit)

    def generic(self, opc, opnames, inouts, regsizes, wnames):
        M = self.M
        o = M.opcodes[opc]
        ic = M.iclasses[o["iclass"]]
        op = pcodeop_name(o["name"])
        ins = [n for n, io in zip(opnames, inouts) if io in "im"]
        outs = [(wnames[i], regsizes[i]) for i, io in enumerate(inouts) if io in "oms" and regsizes[i]]
        for st, io in ic["states"]:
            if M.states[st]["name"] in NOISE_STATES:
                continue
            reg = self.state_reg(st)
            if io in "im":
                ins.append(reg)
            if io in "om":
                outs.append((reg, self.state_size(st)))
        args = ", ".join(ins)
        if not outs:
            self.pcodeops.add(op)
            return f"{op}({args});"
        lines = []
        for k, (dst, sz) in enumerate(outs):
            opk = op if k == 0 else f"{op}_{k}"
            self.pcodeops.add(opk)
            lines.append(f"local ot{k}:{sz} = {opk}({args});")
        for k, (dst, sz) in enumerate(outs):
            lines.append(f"{dst} = ot{k};")
        return " ".join(lines)

    def state_size(self, st):
        n = self.M.states[st]["name"]
        if n == "ACC":
            return 8
        if n in STOCK_SR:
            return 4
        return size_bytes(self.M.states[st]["bits"])

    def opcode_parts(self, si, opc, pos, staged):
        """Display, operand subtables and semantics for opcode opc in slot si at slot position pos."""
        M = self.M
        o = M.opcodes[opc]
        ic = M.iclasses[o["iclass"]]
        opnames, inouts, regsizes, disp = [], [], [], []
        for oid, io in ic["ops"]:
            od = M.operands[oid]
            n = self.operand(si, oid)
            opnames.append(n)
            inouts.append(io)
            regsizes.append(REG_SIZE[M.regfiles[od["regfile"]]["name"]] * max(1, od["num_regs"])
                            if od["flags"] & 1 else 0)
            if not (od["flags"] & 4 or io == "s"):
                disp.append(n)
        wnames = list(opnames)
        if staged:
            k = 0
            for i, io in enumerate(inouts):
                if io in "oms" and regsizes[i]:
                    wnames[i] = f"w{pos}_{k}_{regsizes[i]}"
                    self.stage_regs.add((pos, k))
                    k += 1
        self.staged_ctx = staged
        compute, commit = self.op_semantics(opc, opnames, inouts, regsizes, wnames)
        text = '"' + o["name"] + (' "^' + '^", "^'.join(disp) if disp else '"')
        return text, opnames, compute, commit

    # ---- whole language ----

    def emit(self, stock_dir, outdir, keep_stock):
        M = self.M
        self.stage_regs = set()
        os.makedirs(outdir, exist_ok=True)
        stock_ops = self.stock_pcodeops_of(stock_dir)
        self.reserved = stock_ops
        flix_lines = []
        # FLIX slot subtables
        for fi, fmt in enumerate(M.formats):
            if len(fmt["slots"]) < 2:
                continue
            length = fmt["length"]
            for pos, si in enumerate(fmt["slots"]):
                slot = M.slots[si]
                tname = f"S{si}"
                lines, wlines = [], []
                seen = []
                for cube, opc in self.live_cubes(si):
                    pat = self.constraint(length, {slot["map"][b]: v for b, v in cube.items()})
                    text, opnames, compute, commit = self.opcode_parts(si, opc, pos, self.staged)
                    pat_all = " & ".join([p for p in [pat] if p] + list(dict.fromkeys(opnames))) or "epsilon"
                    lines.append(f"{tname}: {text} is {pat_all} {{ {compute} }}")
                    if self.staged:
                        wpat = " & ".join([p for p in [pat] if p] + list(dict.fromkeys(opnames))) or "epsilon"
                        wlines.append(f"{tname}w: is {wpat} {{ {commit} }}")
                flix_lines.append(f"\n# ---- slot {slot['name']} (format {fmt['name']}, position {pos}) ----")
                flix_lines += lines
                if self.staged:
                    flix_lines += wlines
        # format (bundle) constructors
        root = []
        for fi, fmt in enumerate(M.formats):
            if len(fmt["slots"]) < 2:
                continue
            length = fmt["length"]
            bits = {}
            for terms, f in M.format_tests:
                if f == fi:
                    for wd, mask, val in terms:
                        for k in range(32):
                            if (mask >> k) & 1:
                                bits[wd * 32 + k] = (val >> k) & 1
            pat = self.constraint(length, bits)
            sl = [f"S{si}" for si in fmt["slots"]]
            disp = '"{ "^' + '^"; "^'.join(sl) + '^" }"'
            body = " ".join(f"build {s};" for s in sl)
            subs = list(sl)
            if self.staged:
                # commit order: slots without control flow first, the branch/loop slot (position 0) last
                cf = [si for si in fmt["slots"] if self.slot_has_cf(si)]
                order = [si for si in fmt["slots"] if si not in cf] + cf
                body += " " + " ".join(f"build S{si}w;" for si in order)
                subs += [f"S{si}w" for si in fmt["slots"]]
            root.append(f"# {fmt['name']}: {length} bytes, {len(sl)} slots")
            root.append(f":{disp} is {pat} & {' & '.join(subs)} {{ {body} }}")
        # base formats: operations stock Ghidra lacks or gets wrong
        base_lines = []
        for si in (0, 1, 2):
            length = M.formats[M.slot_fmt[si][0]]["length"]
            for cube, opc in self.live_cubes(si):
                name = M.opcodes[opc]["name"]
                if name in keep_stock:
                    continue
                pat = self.constraint(length, {M.slots[si]["map"][b]: v for b, v in cube.items()})
                text, opnames, compute, commit = self.opcode_parts(si, opc, 0, False)
                pat_all = " & ".join([pat] + list(dict.fromkeys(opnames)))
                disp = text[1:].replace('"^', " ", 1) if '"^' in text else text[1:-1]
                base_lines.append(f":{root_display(name, text)} is {pat_all} {{ {compute} }}")
        return flix_lines, root, base_lines

    def slot_has_cf(self, si):
        return any(self.M.opcodes[opc]["flags"] & 5 for _, opc in self.M.slots[si]["cubes"])

    def live_cubes(self, si):
        """Cubes of a slot in decode order, minus those fully shadowed by an earlier, less specific one;
        raises if two cubes partially overlap (SLEIGH would pick the wrong one)."""
        cubes = self.M.slots[si]["cubes"]
        live = []
        for j, (cj, oj) in enumerate(cubes):
            dead = False
            for ci, oi in live:
                common = set(ci) & set(cj)
                if any(ci[b] != cj[b] for b in common):
                    continue  # disjoint
                if set(ci) <= set(cj):
                    dead = True  # j inside i, i first: j never decodes
                    break
                if set(cj) <= set(ci):
                    continue  # i more specific and first: SLEIGH agrees
                raise ValueError(f"slot {self.M.slots[si]['name']}: partial overlap of "
                                 f"{self.M.opcodes[oi]['name']} and {self.M.opcodes[oj]['name']}")
            if not dead:
                live.append((cj, oj))
        return live

    @staticmethod
    def stock_pcodeops_of(stock_dir):
        # only the stock file this language includes (the install directory also holds our own files)
        return set(re.findall(r"define pcodeop (\w+);", open(os.path.join(stock_dir, "xtensaMain.sinc")).read()))


def disp_text(disp, reg):
    # a bare identifier in a display section becomes an operand, so per-value registers display as text
    return f'"{disp or reg}"'


def root_display(name, text):
    """Root constructor display from a slot display ("name "^a^", "^b): mnemonic then operands."""
    if '"^' not in text:
        return name
    rest = text[len(name) + 4:]  # after '"name "^'
    return name + " " + rest


def sx32(v):
    return v - (1 << 32) if v & 0x80000000 else v


def decode_expr(od, raw, width):
    """Closed form of an operand decode table as a SLEIGH expression of raw (None if not linear)."""
    d = od["decode"]
    if d is None:
        return raw
    vals = [(x, sx32(v)) for x, v in enumerate(d[:1 << width]) if v is not None]
    if not vals:
        return "0"
    for signed in (False, True):
        def X(x):
            return x - (1 << width) if signed and x >> (width - 1) else x
        if len(vals) == 1:
            k, c = 0, vals[0][1]
        else:
            (x0, v0), (x1, v1) = vals[0], vals[1]
            if X(x1) == X(x0):
                continue
            k = (v1 - v0) // (X(x1) - X(x0))
            c = v0 - k * X(x0)
        if all(((k * X(x) + c) - v) % (1 << 32) == 0 for x, v in vals):
            xr = f"(({raw} ^ {1 << (width - 1)}) - {1 << (width - 1)})" if signed else f"({raw})"
            e = xr
            if k == 0:
                return str(c)
            if k != 1:
                if k > 0 and k & (k - 1) == 0:
                    e = f"({e} << {k.bit_length() - 1})"
                else:
                    e = f"({e} * {k})"
            if c:
                e = f"({e} + {c})" if c > 0 else f"({e} - {-c})"
            return e
    return None


def pcodeop_name(mnem):
    return mnem.replace(".", "_")


LANG_ID = "Xtensa:LE:32:rt600hifi4"
PREFIX = "xtensa_rt600hifi4"
HEADER = """# Generated by tools/xtensa_sleigh_gen.py (FT-710 firmware project, T21a / issue #97) -- do not edit.
# Source: Cadence xtensa-modules.c for the NXP RT600 HiFi4 core (Zephyr sdk-ng overlays/xtensa_nxp_rt600_adsp,
# commit 15daabb, SHA-256 9e218b19...f372), Copyright (c) Tensilica Inc., MIT licence:
#   Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
#   documentation files (the "Software"), to deal in the Software without restriction, including without
#   limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the
#   Software, and to permit persons to whom the Software is furnished to do so, subject to the following
#   conditions: The above copyright notice and this permission notice shall be included in all copies or
#   substantial portions of the Software. THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND.
"""
STOCK_HEADER = """# Copied from Ghidra 12.1.4 Ghidra/Processors/Xtensa/data/languages/{name} (Apache License 2.0)
# by tools/xtensa_sleigh_gen.py{note}.
"""


def filter_stock_instructions(text, drop):
    """Comment out stock root constructors whose mnemonic is in drop. Returns (text, dropped names)."""
    out, dropped = [], set()
    lines = text.split("\n")
    i = 0
    while i < len(lines):
        ln = lines[i]
        mm = re.match(r'^:\^?"?([A-Za-z0-9_.]+)', ln)
        if mm and mm.group(1) in drop:
            depth, started = 0, False
            while True:
                cur = lines[i]
                depth += cur.count("{") - cur.count("}")
                started = started or "{" in cur
                out.append("#T21a# " + cur)
                i += 1
                if started and depth <= 0:
                    break
            dropped.add(mm.group(1))
            continue
        out.append(ln)
        i += 1
    return "\n".join(out), dropped


def stock_split(text):
    """Stock root constructors: {name: [header lines]}."""
    heads = {}
    for mm in re.finditer(r'^:\^?"?([A-Za-z0-9_.]+)"?(.*)$', text, re.M):
        heads.setdefault(mm.group(1), []).append(mm.group(2))
    return heads


def generate(M, stock_dir, outdir, staged=True):
    os.makedirs(outdir, exist_ok=True)
    stock_ins = open(os.path.join(stock_dir, "xtensaInstructions.sinc")).read()
    heads = stock_split(stock_ins)
    core_base = {M.opcodes[opc]["name"] for si in (0, 1, 2) for _, opc in M.slots[si]["cubes"]}
    fp_regs = re.compile(r"\b(fr|fs|ft)\b")
    drop = {n for n in heads if n not in core_base}
    drop |= {n for n, hs in heads.items() if any(fp_regs.search(h) for h in hs)}
    drop |= set(EXTRA_DROP)
    keep = set(heads) - drop
    filtered, dropped = filter_stock_instructions(stock_ins, drop)

    E = Emitter(M, staged=staged)
    flix_lines, root, base_lines = E.emit(stock_dir, outdir, keep)

    # registers, tokens, attaches, pcodeops
    R = [HEADER, "# Registers, tokens and p-code operations for the RT600 HiFi4 (FLIX) extension.\n"]
    R.append("define register offset=0x4000 size=8 [ " + " ".join(f"aed{i}" for i in range(16)) + " ];")
    R.append("define register offset=0x4080 size=8 [ u0 u1 u2 u3 ];")
    R.append("define register offset=0x40a0 size=1 [ aep0 aep1 aep2 aep3 ];")
    for sz in (2, 4, 8, 16):  # BR views over b0..b15 (one byte per boolean, stock layout at 0x200)
        R.append(f"define register offset=0x200 size={sz} [ " + " ".join(f"br{sz}_{v}" for v in range(0, 16, sz)) + " ];")
    off = 0x4100
    for st in M.states:
        n = st["name"]
        if n in STOCK_SR:
            continue
        sz = size_bytes(st["bits"])
        off = (off + sz - 1) // sz * sz
        R.append(f"define register offset={off:#x} size={sz} [ st_{n} ];  # state {n}, {st['bits']} bits")
        off += sz
    off = (off + 0xff) // 0x100 * 0x100
    R.append("# staging registers for bundle parallelism: slot position p, output k (all sizes overlap)")
    for p in range(4):
        for k in range(4):
            for sz in (1, 2, 4, 8, 16):
                R.append(f"define register offset={off:#x} size={sz} [ w{p}_{k}_{sz} ];")
            off += 16
    R.append(f"define register offset={off:#x} size=1 [ bcond ];")
    R.append("")
    for tok in ("bx24", "bx16", "fx48", "fx88"):
        bits = {"bx24": 24, "bx16": 16, "fx48": 48, "fx88": 88}[tok]
        fl = E.fields.get(tok, {})
        if not fl:
            continue
        R.append(f"define token {tok}({bits})")
        for name, (lo, hi) in sorted(fl.items(), key=lambda x: (x[1], x[0])):
            R.append(f"  {name} = ({lo},{hi})")
        R.append(";")
    regs = {"AR": [f"a{i}" for i in range(16)], "AE_DR": [f"aed{i}" for i in range(16)],
            "AE_VALIGN": ["u0", "u1", "u2", "u3"], "AE_EP": ["aep0", "aep1", "aep2", "aep3"],
            "BR": [f"b{i}" for i in range(16)]}
    for rf, names in sorted(E.attach.items()):
        R.append(f"attach variables [ {' '.join(sorted(names))} ] [ {' '.join(regs[rf])} ];")
    R.append("")
    for op in sorted(E.pcodeops - E.reserved):
        R.append(f"define pcodeop {op};")

    files = {}
    files[f"{PREFIX}_regs.sinc"] = "\n".join(R) + "\n"
    opnd_lines = [ln for name in E.subtables for ln in E.subtables[name]]
    files[f"{PREFIX}_flix.sinc"] = HEADER + "\n# Operand sub-tables o<slot>_<operand>.\n" + "\n".join(opnd_lines) + \
        "\n\n# FLIX slot sub-tables (S<slot>: compute, S<slot>w: commit).\n" + "\n".join(flix_lines) + "\n"
    files[f"{PREFIX}_bundles.sinc"] = HEADER + "\n# FLIX bundle (format) constructors.\n" + "\n".join(root) + "\n"
    files[f"{PREFIX}_base.sinc"] = HEADER + \
        "\n# 24/16-bit operations of this core that the stock module lacks or decodes on the wrong registers.\n" + \
        "\n".join(base_lines) + "\n"
    files[f"{PREFIX}_stock_instructions.sinc"] = STOCK_HEADER.format(
        name="xtensaInstructions.sinc",
        note=f"; constructors marked #T21a# are dropped ({len(dropped)} mnemonics: not in this core, or on the "
             "f0..f15 FPU registers that this core does not have)") + filtered
    for name in ("xtensaArch.sinc", "xtensaMain.sinc"):
        files[f"{PREFIX}_{name}"] = STOCK_HEADER.format(name=name, note="") + open(os.path.join(stock_dir, name)).read()
    files[f"{PREFIX}.slaspec"] = HEADER + f"""
@define ENDIAN "little"
@include "{PREFIX}_xtensaArch.sinc"
@include "{PREFIX}_regs.sinc"
@include "{PREFIX}_xtensaMain.sinc"
@include "{PREFIX}_flix.sinc"

with : phase=1 {{
@include "{PREFIX}_stock_instructions.sinc"
@include "{PREFIX}_base.sinc"
@include "{PREFIX}_bundles.sinc"
}}
"""
    files[f"{PREFIX}.ldefs"] = f"""<?xml version="1.0" encoding="UTF-8"?>
<!-- Generated by tools/xtensa_sleigh_gen.py (T21a, issue #97). -->
<language_definitions>
  <language processor="Xtensa"
            endian="little"
            size="32"
            variant="rt600hifi4"
            version="1.0"
            slafile="{PREFIX}.sla"
            processorspec="{PREFIX}.pspec"
            manualindexfile="../manuals/xtensa.idx"
            id="{LANG_ID}">
    <description>Tensilica Xtensa LE, NXP RT600 HiFi4 DSP (FLIX bundles, AE_DR, HiFi4/FPU ops)</description>
    <compiler name="default" spec="xtensa.cspec" id="default"/>
    <external_name tool="gnu" name="xtensa"/>
  </language>
</language_definitions>
"""
    files[f"{PREFIX}.pspec"] = open(os.path.join(stock_dir, "xtensa.pspec")).read()
    for name, text in files.items():
        with open(os.path.join(outdir, name), "w") as f:
            f.write(text)
    nslot = sum(1 for ln in flix_lines if re.match(r"^S\d+:", ln))
    print(f"generated {outdir}: {nslot} slot constructors, {len(base_lines)} base constructors, "
          f"{len(E.pcodeops - E.reserved)} pcodeops, dropped {len(dropped)} stock mnemonics")
    return files


# stock constructors replaced by generated ones although the name exists in this core (display differs)
# (found by compiling: identical patterns). Stock's mula.da.*.ldinc sit on the encodings of mula.dd.*.ldinc.
# Stock bany/bnone/ball/bnall print the target first (found with the flix.dis comparison).
EXTRA_DROP = ["mula.da.hh.ldinc", "mula.da.hl.ldinc", "mula.da.lh.ldinc", "mula.da.ll.ldinc", "sext",
              "bany", "bnone", "ball", "bnall",
              # T21b oracle (decode mode): wrong value, trailing comma, shadowing or missing encodings in stock
              "movi.n", "remu", "rems", "quou", "quos", "bgeui", "bltui", "ret", "jx", "licw", "mul.dd.lh",
              "ret.n", "any4", "all4", "any8", "all8"]


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("cmd", choices=["extract", "check", "selftest", "generate"])
    ap.add_argument("--stock", default=os.path.expanduser("~/opt/ghidra_12.1.4_PUBLIC/Ghidra/Processors/Xtensa/data/languages"))
    ap.add_argument("--out", default=os.path.join(HERE, "ghidra", "xtensa-rt600hifi4"))
    ap.add_argument("--no-stage", action="store_true", help="write slot results directly (no bundle parallelism)")
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
    elif a.cmd == "generate":
        generate(Model(a.modules, a.build), a.stock, a.out, staged=not a.no_stage)
