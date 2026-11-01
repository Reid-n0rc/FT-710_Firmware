// T24 (MAIN): run functions of the RX651 image in Ghidra's p-code emulator for tools/equiv_main_emu.py.
//
// Unicorn has no RX, so the MAIN equivalence check runs in Ghidra's p-code emulator (ghidra.pcode.emu.PcodeEmulator)
// on the rx62t SLEIGH module (docs/tooling.md, "Renesas RX processor module"). This script is a server: it reads
// one JSON request per line from stdin and answers each with one line "@@EQ <json>" on stdout, so that the Python
// side (tools/equiv_main_emu.py) keeps one Ghidra process for a whole check instead of paying Ghidra's start-up for
// every trial. It only reads the program: run it with -readOnly on a copy of the MAIN project.
//
// Headless usage (tools/equiv_main_emu.py starts it; by hand for a test):
//   tools/ghidra-headless.sh <projdir> FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript EquivMainEmu.java
//
// Requests (one JSON object per line):
//   {"op":"base","name":N,"segs":[[addr,"hex"],...]}   define a named memory image (later runs layer bases)
//   {"op":"blocks","entries":[addr,...]}               basic-block starts (SimpleBlockModel) of the Ghidra
//                                                      function at each address, and whether it ends in RTE
//                                                      -> {"blocks":{addr:{"blocks":[...],"isr":b,"found":b}}}
//   {"op":"run", "bases":[N,...], "loads":[[addr,"hex"]], "entry":A, "regs":{"R1":v,...}, "sp":S,
//    "stack":[w,...] (words at SP+4.., [SP] = the return address), "seed":s, "budget":n,
//    "stubs":{addr:[name,nargs(,ptr_arg,len_arg)]}, "cover":[addr,...], "snap":[[lo,hi],...], "track":[[lo,hi],...],
//    "mmio_fixed":{addr:value}, "trace":true (PC and R1..R15 before each of the first 400 instructions),
//    "module_fp":true (the FPU instructions by the module's p-code instead of RxFpu), "fpsw":v (FPSW at entry, default 0x100),
//    "stub_rets":{addr:[v,...]} (the return values of a stub, drawn from the seeded sequence)}
//     -> {"end":"return"|"budget"|"fault", "why":..., "r1":v, "r2":v, "regs":[R1..R15], "psw":v, "steps":n,
//         "mmio":[["r"|"w",addr,size,value],...], "calls":[[name,arg...],...], "userops":[name,...],
//         "diff":[[addr,"hex"],...] (snap ranges that differ from the start state), "hits":[addr,...] (cover
//         addresses executed), "reads":[addr,...] (bytes in the track ranges read before any write)}
//   {"op":"quit"}
//
// Memory model: RAM 0x0..0x3FFFF, the image 0xFFF80000..0xFFFFFFFF, the recreated code at 0xFFF00000..0xFFF7FFFF,
// peripheral I/O 0x80000..0xFFFFF and 0x7FC000..0x7FFFFF. A load from I/O returns a value from a seeded sequence
// (java.util.Random(seed), or "mmio_fixed") and is recorded with every I/O store; any access elsewhere ends the run
// as a fault. A call to a stub address records (name, R1..R4 and stack arguments), sets R1 from the same seeded
// sequence and returns (RX BSR/JSR push the return address; the caller pops stack arguments). With ptr_arg and
// len_arg (0-based argument numbers), the call also records the bytes the pointer argument points to, at most
// 0x6000 (a buffer on the stack has an address that depends on the callers' frames; its content does not). The string compare
// pcodeops of the module (scmpu, suntil, swhile) are implemented here after the RXv2 software manual R01US0071EJ0100
// (SCMPU p. 184, SUNTIL p. 196, SWHILE p. 198), because the module leaves them as named operations (T21c), and
// JMP Rs is executed here, because the module's "PC = Rs" does not branch in the emulator (T22a listed it as not
// fixed: MAIN has no JMP Rs; GCC's switch tables use it). tools/ghidra/rx62t-gccforms-fix.patch (T24 round 2) fixes the
// module ("goto [Rs]"); the override stays, so a module without that patch gives the same results. FTOI, ROUND and
// FTOU are executed here after the manual too (T24 MAIN round 4: the module computed a float for all three;
// tools/ghidra/rx62t-fpconv-fix.patch fixes it for the decompiler), and since round 5 every FPU instruction (RxFpu:
// the DN flush, NaN rules, FCMP's O flag, RM and FPSW, which the module does not model; tools/rx_fpu_check.py).
// @category FT710
import com.google.gson.Gson;
import com.google.gson.JsonArray;
import com.google.gson.JsonElement;
import com.google.gson.JsonObject;
import com.google.gson.JsonParser;
import ghidra.app.script.GhidraScript;
import ghidra.pcode.emu.PcodeEmulationCallbacks;
import ghidra.pcode.emu.PcodeEmulator;
import ghidra.pcode.emu.PcodeThread;
import ghidra.pcode.exec.PcodeArithmetic;
import ghidra.pcode.exec.PcodeExecutorState;
import ghidra.pcode.exec.PcodeExecutorStatePiece;
import ghidra.pcode.exec.PcodeFrame;
import ghidra.pcode.exec.PcodeUseropLibrary;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSpace;
import ghidra.program.model.block.CodeBlock;
import ghidra.program.model.block.CodeBlockIterator;
import ghidra.program.model.block.SimpleBlockModel;
import ghidra.program.model.lang.Language;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.Varnode;

import java.io.BufferedReader;
import java.math.BigInteger;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.io.FileOutputStream;
import java.io.FileDescriptor;
import java.util.ArrayList;
import java.util.BitSet;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class EquivMainEmu extends GhidraScript {
    static final long STACK_LO = 0x0, RAM_HI = 0x40000;
    static final long IO_LO = 0x80000, IO_HI = 0x100000, IO2_LO = 0x7FC000, IO2_HI = 0x800000;
    static final long ROM_LO = 0xFFF80000L, SCRATCH_LO = 0xFFF00000L, TOP = 0x100000000L;
    static final long STOP = 0xFFFFF000L;

    static class Fault extends RuntimeException {
        Fault(String m) { super(m); }
    }

    static class Stop extends RuntimeException {
        Stop(String m) { super(m); }
    }

    final Map<String, List<Object[]>> bases = new HashMap<>();
    Language lang;
    AddressSpace ram;
    PrintStream out;

    static byte[] unhex(String s) {
        byte[] b = new byte[s.length() / 2];
        for (int i = 0; i < b.length; i++) b[i] = (byte) Integer.parseInt(s.substring(2 * i, 2 * i + 2), 16);
        return b;
    }

    static String hex(byte[] b, int off, int len) {
        StringBuilder sb = new StringBuilder(2 * len);
        for (int i = off; i < off + len; i++) sb.append(String.format("%02x", b[i] & 0xff));
        return sb.toString();
    }

    static long lv(JsonElement e) {
        return e.getAsLong() & 0xFFFFFFFFL;
    }

    /** One emulation run: the callbacks see every load, store and instruction. */
    class Run implements PcodeEmulationCallbacks<byte[]> {
        final Random rng;
        final Map<Long, Long> fixed = new HashMap<>();
        final List<Object[]> mmio = new ArrayList<>();
        final List<String> userops = new ArrayList<>();
        final List<long[]> trackRanges = new ArrayList<>();
        final BitSet written = new BitSet((int) RAM_HI);
        final TreeSet<Long> reads = new TreeSet<>();
        PcodeArithmetic<byte[]> arith;
        PcodeThread<byte[]> thread;

        Run(long seed) {
            rng = new Random(seed);
        }

        long val(byte[] v) {
            return arith.toLong(v, PcodeArithmetic.Purpose.OTHER) & 0xFFFFFFFFL;
        }

        boolean inTrack(long a) {
            for (long[] r : trackRanges) if (a >= r[0] && a < r[1]) return true;
            return false;
        }

        void check(long a, int size, boolean store) {
            long e = a + size;
            if (e <= RAM_HI) return;
            if (a >= IO_LO && e <= IO_HI || a >= IO2_LO && e <= IO2_HI) return;
            if (!store && a >= SCRATCH_LO && e <= TOP) return;
            throw new Fault(String.format("%s of %d bytes at 0x%x", store ? "store" : "load", size, a));
        }

        boolean isIo(long a) {
            return a >= IO_LO && a < IO_HI || a >= IO2_LO && a < IO2_HI;
        }

        @Override
        public void beforeLoad(PcodeThread<byte[]> t, PcodeOp op, AddressSpace space, byte[] offset, int size) {
            if (space != ram) return;
            long a = val(offset);
            check(a, size, false);
            if (isIo(a)) {
                long v;
                Long f = fixed.get(a);
                if (f != null) v = f;
                else v = rng.nextLong() & (size >= 8 ? -1L : ((1L << (8 * size)) - 1));
                t.getState().setVar(ram, a, size, true, arith.fromConst(v, size));
                mmio.add(new Object[]{"r", a, size, v});
            } else if (a < RAM_HI) {
                for (long b = a; b < a + size && b < RAM_HI; b++)
                    if (!written.get((int) b) && inTrack(b)) reads.add(b);
            }
        }

        @Override
        public void afterStore(PcodeThread<byte[]> t, PcodeOp op, AddressSpace space, byte[] offset, int size,
                               byte[] value) {
            if (space != ram) return;
            long a = val(offset);
            if (isIo(a)) {
                long v = arith.toLong(value, PcodeArithmetic.Purpose.OTHER);
                if (size < 8) v &= (1L << (8 * size)) - 1;
                mmio.add(new Object[]{"w", a, size, v});
            } else if (a < RAM_HI) {
                written.set((int) a, (int) Math.min(a + size, RAM_HI));
            }
        }

        @Override
        public void beforeStore(PcodeThread<byte[]> t, PcodeOp op, AddressSpace space, byte[] offset, int size,
                                byte[] value) {
            if (space != ram) return;
            long a = val(offset);
            check(a, size, true);
        }

        /** A data load as the module's p-code does it (beforeLoad): checked, an I/O load drawn from the sequence and
         *  recorded, a tracked RAM byte noted; size 1, 2 or 4, sign-extended when signed. */
        long load(long a, int size, boolean signed) {
            check(a, size, false);
            long v;
            if (isIo(a)) {
                Long f = fixed.get(a);
                v = f != null ? f : rng.nextLong() & ((1L << (8 * size)) - 1);
                mmio.add(new Object[]{"r", a, size, v});
            } else {
                if (a < RAM_HI)
                    for (long b = a; b < a + size && b < RAM_HI; b++)
                        if (!written.get((int) b) && inTrack(b)) reads.add(b);
                byte[] b = thread.getState().inspectConcrete(ram.getAddress(a), size);
                v = 0;
                for (int i = size - 1; i >= 0; i--) v = v << 8 | (b[i] & 0xffL);
            }
            if (signed && size < 4 && (v & (1L << (8 * size - 1))) != 0) v -= 1L << (8 * size);
            return v & 0xFFFFFFFFL;
        }

        byte rd(long a) {
            check(a, 1, false);
            if (a < RAM_HI && !written.get((int) a) && inTrack(a)) reads.add(a);
            return thread.getState().inspectConcrete(ram.getAddress(a), 1)[0];
        }

        long reg(String n) {
            return val(thread.getState().getVar(lang.getRegister(n), PcodeExecutorStatePiece.Reason.INSPECT));
        }

        void setReg(String n, long v) {
            Register r = lang.getRegister(n);
            thread.getState().setVar(r, arith.fromConst(v, r.getMinimumByteSize()));
        }

        @Override
        public boolean handleMissingUserop(PcodeThread<byte[]> t, PcodeOp op, PcodeFrame frame, String name,
                                           PcodeUseropLibrary<byte[]> library) {
            PcodeExecutorState<byte[]> st = t.getState();
            long[] in = new long[op.getNumInputs()];
            for (int i = 1; i < op.getNumInputs(); i++)
                in[i] = val(st.getVar(op.getInput(i), PcodeExecutorStatePiece.Reason.INSPECT));
            long res;
            userops.add(name);
            if (name.equals("scmpu")) {
                // compare bytes *R1, *R2 until they differ, a NUL or R3 bytes; result *R1 - *R2 of the last pair
                long a = in[1], b = in[2], n = in[3];
                int x = 0, y = 0;
                while (n-- > 0) {
                    x = rd(a++) & 0xff;
                    y = rd(b++) & 0xff;
                    if (x != y || x == 0) break;
                }
                res = (x - y) & 0xFFFFFFFFL;
            } else if (name.equals("suntil") || name.equals("swhile")) {
                // R1 = pointer, R2 = value, R3 = count, size: until (stop on ==) / while (stop on !=)
                long a = in[1], v = in[2], n = in[3];
                int sz = (int) in[4];
                if (sz != 1 && sz != 2 && sz != 4) sz = 1;
                long mask = sz == 4 ? 0xFFFFFFFFL : (1L << (8 * sz)) - 1;
                boolean until = name.equals("suntil");
                long cur = 0;
                while (n > 0) {
                    cur = 0;
                    for (int k = 0; k < sz; k++) cur |= (rd(a + k) & 0xffL) << (8 * k);
                    a += sz;
                    n--;
                    if (until ? (cur == (v & mask)) : (cur != (v & mask))) break;
                }
                setReg("R3", n);
                res = a;
            } else {
                throw new Fault("unimplemented pcodeop " + name);
            }
            Varnode o = op.getOutput();
            if (o != null) st.setVar(o, arith.fromConst(res, o.getSize()));
            return true;
        }
    }

    JsonObject doRun(JsonObject q) {
        long seed = q.has("seed") ? q.get("seed").getAsLong() : 1;
        Run r = new Run(seed);
        PcodeEmulator emu = new PcodeEmulator(lang, r);
        r.arith = emu.getArithmetic();
        PcodeExecutorState<byte[]> shared = emu.getSharedState();
        // start state: the bases in order, then the loads; remember the start bytes of the snap ranges
        for (JsonElement b : q.getAsJsonArray("bases")) {
            List<Object[]> segs = bases.get(b.getAsString());
            if (segs == null) throw new IllegalArgumentException("no base " + b.getAsString());
            for (Object[] s : segs) shared.setConcrete(ram.getAddress((Long) s[0]), (byte[]) s[1]);
        }
        if (q.has("loads"))
            for (JsonElement e : q.getAsJsonArray("loads")) {
                JsonArray a = e.getAsJsonArray();
                shared.setConcrete(ram.getAddress(lv(a.get(0))), unhex(a.get(1).getAsString()));
            }
        if (q.has("mmio_fixed"))
            for (Map.Entry<String, JsonElement> e : q.getAsJsonObject("mmio_fixed").entrySet())
                r.fixed.put(Long.decode(e.getKey()), lv(e.getValue()));
        if (q.has("track"))
            for (JsonElement e : q.getAsJsonArray("track")) {
                JsonArray a = e.getAsJsonArray();
                r.trackRanges.add(new long[]{lv(a.get(0)), lv(a.get(1))});
            }
        List<long[]> snap = new ArrayList<>();
        List<byte[]> before = new ArrayList<>();
        if (q.has("snap"))
            for (JsonElement e : q.getAsJsonArray("snap")) {
                JsonArray a = e.getAsJsonArray();
                long lo = lv(a.get(0)), hi = lv(a.get(1));
                snap.add(new long[]{lo, hi});
                before.add(shared.inspectConcrete(ram.getAddress(lo), (int) (hi - lo)));
            }
        Map<Long, String[]> stubs = new HashMap<>();
        if (q.has("stubs"))
            for (Map.Entry<String, JsonElement> e : q.getAsJsonObject("stubs").entrySet()) {
                JsonArray a = e.getValue().getAsJsonArray();
                stubs.put(Long.decode(e.getKey()), a.size() >= 4
                        ? new String[]{a.get(0).getAsString(), a.get(1).getAsString(), a.get(2).getAsString(), a.get(3).getAsString()}
                        : new String[]{a.get(0).getAsString(), a.get(1).getAsString()});
            }
        // "stub_rets":{addr:[v,...]}: the values a stub returns, drawn from the seeded sequence (default {0, 0, 0, 1,
        // FFFFFFFFh, random}); T24 MAIN round 4: a task's gate functions stubbed to reach its state machine
        Map<Long, long[]> stubRets = new HashMap<>();
        if (q.has("stub_rets"))
            for (Map.Entry<String, JsonElement> e : q.getAsJsonObject("stub_rets").entrySet()) {
                JsonArray a = e.getValue().getAsJsonArray();
                long[] v = new long[a.size()];
                for (int k = 0; k < v.length; k++) v[k] = lv(a.get(k));
                stubRets.put(Long.decode(e.getKey()), v);
            }
        Set<Long> cover = new HashSet<>();
        if (q.has("cover")) for (JsonElement e : q.getAsJsonArray("cover")) cover.add(lv(e));
        Set<Long> hits = new TreeSet<>();

        PcodeThread<byte[]> t = emu.newThread();
        r.thread = t;
        // registers: everything 0 except what the request gives; SP and the return address
        long sp = q.has("sp") ? lv(q.get("sp")) : 0xF00;
        if (q.has("regs"))
            for (Map.Entry<String, JsonElement> e : q.getAsJsonObject("regs").entrySet())
                r.setReg(e.getKey(), lv(e.getValue()));
        r.setReg("SP", sp);
        r.setReg("PSW", q.has("psw") ? lv(q.get("psw")) : 0x00030000L);
        r.setReg("FPSW", q.has("fpsw") ? lv(q.get("fpsw")) : 0x100);   // MAIN: 0x100 at 0xFFF8FBFF
        r.setReg("INTB", 0xFFF8E6DCL);
        r.setReg("EXTB", 0xFFFFFF80L);
        writeLE(shared, sp, STOP);
        if (q.has("stack")) {
            int k = 1;
            for (JsonElement e : q.getAsJsonArray("stack")) writeLE(shared, sp + 4L * k++, lv(e));
        }
        long entry = lv(q.get("entry"));
        t.overrideCounter(ram.getAddress(entry));
        long budget = q.has("budget") ? q.get("budget").getAsLong() : 2000000;
        // "module_fp": true runs the FPU instructions on the module's own p-code (to test a SLEIGH change)
        boolean moduleFp = q.has("module_fp") && q.get("module_fp").getAsBoolean();
        List<JsonArray> calls = new ArrayList<>();
        JsonArray trace = q.has("trace") && q.get("trace").getAsBoolean() ? new JsonArray() : null;
        String end = "budget", why = "";
        long steps = 0;
        try {
            while (steps < budget) {
                long pc = t.getCounter().getOffset();
                if (pc == STOP) {
                    end = "return";
                    break;
                }
                if (cover.contains(pc)) hits.add(pc);
                String[] stub = stubs.get(pc);
                if (stub != null) {
                    int n = Integer.parseInt(stub[1]);
                    JsonArray c = new JsonArray();
                    c.add(stub[0]);
                    long csp = r.reg("SP");
                    for (int k = 0; k < n; k++) {
                        if (k < 4) c.add(r.reg("R" + (k + 1)));
                        else c.add(readLE(shared, csp + 4L * (k - 3)));
                    }
                    if (stub.length >= 4) {
                        int pi = Integer.parseInt(stub[2]), li = Integer.parseInt(stub[3]);
                        long ptr = c.get(1 + pi).getAsLong(), len = c.get(1 + li).getAsLong() & 0xFFFF;
                        if (len > 0x6000) len = 0x6000;
                        if (ptr >= 0 && ptr + len <= 0x40000)
                            c.add(hex(shared.inspectConcrete(ram.getAddress(ptr), (int) len), 0, (int) len));
                    }
                    calls.add(c);
                    long[] rv = stubRets.get(pc);
                    long ret = rv != null ? rv[r.rng.nextInt(rv.length)]
                            : new long[]{0, 0, 0, 1, 0xFFFFFFFFL, r.rng.nextInt() & 0xFFFFFFFFL}[r.rng.nextInt(6)];
                    r.setReg("R1", ret);
                    long ra = readLE(shared, csp);
                    r.setReg("SP", csp + 4);
                    t.overrideCounter(ram.getAddress(ra));
                    steps++;
                    continue;
                }
                if (!(pc >= ROM_LO || pc >= SCRATCH_LO && pc < ROM_LO)) throw new Fault(String.format("execute at 0x%x", pc));
                if (trace != null && trace.size() < 400) {
                    JsonArray st = new JsonArray();
                    st.add(pc);
                    for (int k = 1; k <= 15; k++) st.add(r.reg("R" + k));
                    trace.add(st);
                }
                // JMP Rs (7F 0s): the module's p-code is "PC = Rs" without a branch, so the emulator falls through
                // (found here: GCC emits JMP for switch tables, CC-RX never does). Executed here instead.
                byte[] op2 = shared.inspectConcrete(ram.getAddress(pc), 2);
                if ((op2[0] & 0xff) == 0x7F && (op2[1] & 0xF0) == 0x00) {
                    int rs = op2[1] & 0x0F;
                    t.overrideCounter(ram.getAddress(r.reg(rs == 0 ? "SP" : "R" + rs)));
                    steps++;
                    continue;
                }
                // Every FPU instruction (T24 MAIN round 5; FTOI / ROUND / FTOU since round 4) is executed by RxFpu after
                // the RXv2 manual: the module computes them with the host's IEEE arithmetic (no DN flush, host NaNs, no
                // O flag on FCMP, no FPSW; FTOI / ROUND / FTOU returned a float before rx62t-fpconv-fix.patch;
                // tools/rx_fpu_check.py). Rd, PSW.Z/S/O and FPSW are set from the model.
                FpIns fi = moduleFp ? null : fpuDecode(shared, pc);
                if (fi != null) {
                    long addr = fi.mode == 2 ? (r.reg(regName(fi.rs)) + fi.dsp) & 0xFFFFFFFFL : 0;
                    int dest0 = (int) r.reg(regName(fi.rd));
                    int src2 = fi.rs2 >= 0 ? (int) r.reg(regName(fi.rs2)) : dest0;
                    long srcReg = fi.mode == 1 ? r.reg(regName(fi.rs)) : 0;
                    long psw0 = r.reg("PSW");
                    int fpsw0 = (int) r.reg("FPSW");
                    // not stepped: the module does not decode UTOF (FC 54..57); the load goes through Run.load
                    long src = fi.mode == 0 ? fi.imm : fi.mode == 1 ? srcReg : r.load(addr, fi.size, fi.signed);
                    t.overrideCounter(ram.getAddress(pc + fi.len));
                    steps++;
                    RxFpu u = new RxFpu(fpsw0);
                    int res = 0;
                    int[] zso = null;
                    switch (fi.op) {
                        case 0: res = u.add(src2, (int) src, true); break;
                        case 2: res = u.add(src2, (int) src, false); break;
                        case 3: res = u.mul(src2, (int) src); break;
                        case 4: res = u.div(src2, (int) src); break;
                        case 1: zso = u.cmp(src2, (int) src); break;
                        case 5: res = u.toInt(0, (int) src); break;
                        case 6: res = u.toInt(1, (int) src); break;
                        case 9: res = u.toInt(2, (int) src); break;
                        case 8: res = u.sqrt((int) src); break;
                        case 16: res = u.itof((int) src); break;          // signed 32-bit after the memex extension
                        default: res = u.itof(src & 0xFFFFFFFFL); break;   // 17 UTOF
                    }
                    r.setReg("FPSW", u.fpswAfter() & 0xFFFFFFFFL);
                    if (u.trap()) {                // the destination and the flags stay; the exception starts here
                        r.setReg(regName(fi.rd), dest0 & 0xFFFFFFFFL);
                        r.setReg("PSW", psw0);
                        throw new Fault(String.format("floating-point exception at 0x%x (FPSW 0x%08x)", pc,
                                u.fpswAfter()));
                    }
                    long psw = psw0;
                    if (fi.op == 1) {
                        r.setReg(regName(fi.rd), dest0 & 0xFFFFFFFFL);    // FCMP has no destination
                        if (u.flagsChange())
                            psw = (psw0 & ~0xEL) | (zso[0] << 1) | (zso[1] << 2) | (zso[2] << 3);
                    } else {
                        r.setReg(regName(fi.rd), res & 0xFFFFFFFFL);
                        // Z: a zero of either sign for the arithmetic (p. 87), the integer 0 for the conversions
                        boolean z = fi.op < 5 || fi.op == 8 ? (res & 0x7FFFFFFF) == 0 : res == 0;
                        if (u.flagsChange())
                            psw = (psw0 & ~6L) | (z ? 2 : 0) | ((res >>> 31) & 1L) << 2;
                    }
                    r.setReg("PSW", psw);
                    continue;
                }
                t.stepInstruction();
                steps++;
            }
        } catch (Fault f) {
            end = "fault";
            why = f.getMessage();
        } catch (Exception e) {
            Throwable c = e;
            while (c.getCause() != null && !(c instanceof Fault)) c = c.getCause();
            end = "fault";
            why = (c instanceof Fault) ? c.getMessage() : (e.getClass().getSimpleName() + ": " + e.getMessage());
        }
        JsonObject res = new JsonObject();
        res.addProperty("end", end);
        res.addProperty("why", why);
        res.addProperty("steps", steps);
        res.addProperty("r1", r.reg("R1"));
        res.addProperty("r2", r.reg("R2"));
        res.addProperty("sp", r.reg("SP"));
        res.addProperty("psw", r.reg("PSW"));
        res.addProperty("fpsw", r.reg("FPSW"));
        JsonArray regs = new JsonArray();
        for (int k = 1; k <= 15; k++) regs.add(r.reg("R" + k));
        res.add("regs", regs);
        JsonArray mm = new JsonArray();
        for (Object[] m : r.mmio) {
            JsonArray a = new JsonArray();
            a.add((String) m[0]);
            a.add((Long) m[1]);
            a.add((Integer) m[2]);
            a.add((Long) m[3]);
            mm.add(a);
        }
        res.add("mmio", mm);
        JsonArray ca = new JsonArray();
        for (JsonArray c : calls) ca.add(c);
        res.add("calls", ca);
        JsonArray uo = new JsonArray();
        for (String u : r.userops) uo.add(u);
        res.add("userops", uo);
        JsonArray diff = new JsonArray();
        for (int i = 0; i < snap.size(); i++) {
            long lo = snap.get(i)[0], hi = snap.get(i)[1];
            byte[] now = shared.inspectConcrete(ram.getAddress(lo), (int) (hi - lo));
            byte[] was = before.get(i);
            int k = 0;
            while (k < now.length) {
                if (now[k] == was[k]) {
                    k++;
                    continue;
                }
                int s = k;
                while (k < now.length && now[k] != was[k]) k++;
                JsonArray d = new JsonArray();
                d.add(lo + s);
                d.add(hex(now, s, k - s));
                diff.add(d);
            }
        }
        res.add("diff", diff);
        JsonArray ha = new JsonArray();
        for (Long h : hits) ha.add(h);
        res.add("hits", ha);
        JsonArray ra = new JsonArray();
        for (Long a : r.reads) ra.add(a);
        res.add("reads", ra);
        if (trace != null) res.add("trace", trace);
        return res;
    }

    static void writeLE(PcodeExecutorState<byte[]> st, long a, long v) {
        byte[] b = {(byte) v, (byte) (v >> 8), (byte) (v >> 16), (byte) (v >> 24)};
        st.setConcrete(st.getLanguage().getDefaultSpace().getAddress(a), b);
    }

    /**
     * The RX FPU after the RXv2 software manual R01US0071EJ0100 (T24 MAIN round 5): FADD (p. 87), FCMP (p. 90), FDIV
     * (p. 93), FMUL (p. 95), FSQRT (p. 98), FSUB (p. 100), FTOI (p. 103), FTOU (p. 106), ITOF (p. 110), ROUND (p. 171),
     * UTOF (p. 201) and the FPSW (p. 20/21) with the exception rules of section 1.3 (p. 24..27). Exact arithmetic on
     * (sign, BigInteger mantissa, exponent), one rounding by FPSW.RM. The module computes these with the host's IEEE
     * arithmetic: no DN flush, NaN results of the host, no O flag on FCMP, no FPSW (tools/rx_fpu_check.py).
     *
     * Decisions taken from the manual's text, each checked by tools/rx_fpu_check.py against an independent model:
     * DN = 1 reads a denormal operand as a zero of its sign (p. 21 note 2) and returns a zero for an underflow
     * (Table 1.2); underflow is a nonzero exact result below 2^-126 before rounding (*Open: before or after rounding,
     * p. 24 does not say; would be settled by a result just below 2^-126 that rounds to it, run on an RX651*), and
     * the zero keeps the result's sign (*Open: the sign; same test*). NaN results follow Table 1.6; an invalid
     * operation without a NaN operand gives 7FFFFFFFh. The S and Z flags (and FCMP's O) do not change when an exception
     * is generated (the note under each flag table); "generated" is read as the manual uses it for the cause flags, so
     * also for a masked exception (CX of a rounded result) (*Open: whether the hardware keeps S/Z on a masked
     * exception; would be settled by FADD 0.1f, 0.2f on an RX651 and reading PSW*). An enabled exception or
     * unimplemented processing (DN = 0 and a denormal operand or underflow, p. 27) leaves the destination unchanged and
     * starts the floating-point exception: the run ends there as a fault.
     */
    static final class RxFpu {
        static final int CV = 1 << 2, CO = 1 << 3, CZ = 1 << 4, CU = 1 << 5, CX = 1 << 6, CE = 1 << 7, DN = 1 << 8;
        static final int QNAN_DEFAULT = 0x7FFFFFFF;
        static final BigInteger ONE = BigInteger.ONE;
        final int fpsw;
        int cause;            // CV..CE of this instruction
        boolean zsFromResult = true;

        RxFpu(int fpsw) {
            this.fpsw = fpsw;
        }

        int rm() { return fpsw & 3; }

        boolean dn() { return (fpsw & DN) != 0; }

        static boolean isNaN(int b) { return (b & 0x7F800000) == 0x7F800000 && (b & 0x7FFFFF) != 0; }

        static boolean isSNaN(int b) { return isNaN(b) && (b & 0x400000) == 0; }

        static boolean isInf(int b) { return (b & 0x7FFFFFFF) == 0x7F800000; }

        static boolean isZero(int b) { return (b & 0x7FFFFFFF) == 0; }

        static boolean isDenormal(int b) { return (b & 0x7F800000) == 0 && (b & 0x7FFFFF) != 0; }

        /** A source operand: a denormal is a signed zero with DN = 1 and unimplemented processing with DN = 0. */
        int in(int b) {
            if (!isDenormal(b)) return b;
            if (dn()) return b & 0x80000000;
            cause |= CE;
            return b;
        }

        /** Table 1.6 for two operands; d is the operand in dest's place (src2 of the 3-operand forms). */
        int nan2(int d, int s) {
            boolean sd = isSNaN(d), ss = isSNaN(s);
            if (sd || ss) cause |= CV;
            if (sd) return d | 0x400000;          // two SNaNs: dest; an SNaN and a QNaN or a real value: the SNaN
            if (ss) return s | 0x400000;
            return isNaN(d) ? d : s;               // two QNaNs: dest; a QNaN and a real value: the QNaN
        }

        int invalid() {
            cause |= CV;
            return QNAN_DEFAULT;
        }

        static BigInteger mant(int b) {
            int e = (b >>> 23) & 0xFF;
            return BigInteger.valueOf(e == 0 ? (b & 0x7FFFFF) : (b & 0x7FFFFF) | 0x800000);
        }

        static int expo(int b) {
            int e = (b >>> 23) & 0xFF;
            return (e == 0 ? 1 : e) - 150;
        }

        int signedZero(boolean neg) { return neg ? 0x80000000 : 0; }

        /** Round sign * m * 2^e (sticky: the exact value is a little above m * 2^e) to single by FPSW.RM. */
        int round(boolean neg, BigInteger m, int e, boolean sticky) {
            int len = m.bitLength();
            int ex = e + len - 1;
            if (ex < -126) {                      // underflow (Table 1.2): 0 with DN = 1, unimplemented with DN = 0
                cause |= CU;
                if (!dn()) cause |= CE;
                return signedZero(neg);
            }
            int shift = len - 24;
            BigInteger r;
            boolean inexact;
            if (shift <= 0) {
                r = m.shiftLeft(-shift);
                inexact = sticky;
            } else {
                r = m.shiftRight(shift);
                BigInteger rem = m.subtract(r.shiftLeft(shift)), half = ONE.shiftLeft(shift - 1);
                inexact = rem.signum() != 0 || sticky;
                int c = rem.compareTo(half);
                boolean up;
                switch (rm()) {
                    case 0: up = c > 0 || c == 0 && (sticky || r.testBit(0)); break;
                    case 1: up = false; break;
                    case 2: up = inexact && !neg; break;
                    default: up = inexact && neg; break;
                }
                if (up) {
                    r = r.add(ONE);
                    if (r.bitLength() > 24) {
                        r = r.shiftRight(1);
                        ex++;
                    }
                }
            }
            if (ex > 127) {                       // overflow, Table 1.1 (EO = 0), with inexact (its note)
                cause |= CO | CX;
                int rmv = rm();
                boolean inf = rmv == 0 || rmv == 2 && !neg || rmv == 3 && neg;
                return (neg ? 0x80000000 : 0) | (inf ? 0x7F800000 : 0x7F7FFFFF);
            }
            if (inexact) cause |= CX;
            return (neg ? 0x80000000 : 0) | (ex + 127) << 23 | (r.intValue() & 0x7FFFFF);
        }

        /** FADD / FSUB: d + s or d - s (d: dest or src2). */
        int add(int d, int s, boolean sub) {
            d = in(d);
            s = in(s);
            if ((cause & CE) != 0) return d;
            if (isNaN(d) || isNaN(s)) return nan2(d, s);
            if (sub) s ^= 0x80000000;
            boolean nd = d < 0, ns = s < 0;
            if (isInf(d) || isInf(s)) {
                if (isInf(d) && isInf(s) && nd != ns) return invalid();
                return isInf(d) ? d : s;
            }
            if (isZero(d) && isZero(s)) return nd == ns ? d : signedZero(rm() == 3);
            if (isZero(d)) return s;
            if (isZero(s)) return d;
            int ed = expo(d), es = expo(s), e = Math.min(ed, es);
            BigInteger a = mant(d).shiftLeft(ed - e), b = mant(s).shiftLeft(es - e);
            BigInteger sum = (nd ? a.negate() : a).add(ns ? b.negate() : b);
            if (sum.signum() == 0) return signedZero(rm() == 3);
            return round(sum.signum() < 0, sum.abs(), e, false);
        }

        int mul(int d, int s) {
            d = in(d);
            s = in(s);
            if ((cause & CE) != 0) return d;
            if (isNaN(d) || isNaN(s)) return nan2(d, s);
            boolean neg = (d ^ s) < 0;
            if (isInf(d) || isInf(s)) {
                if (isZero(d) || isZero(s)) return invalid();
                return signedZero(neg) | 0x7F800000;
            }
            if (isZero(d) || isZero(s)) return signedZero(neg);
            return round(neg, mant(d).multiply(mant(s)), expo(d) + expo(s), false);
        }

        /** FDIV: d / s. */
        int div(int d, int s) {
            d = in(d);
            s = in(s);
            if ((cause & CE) != 0) return d;
            if (isNaN(d) || isNaN(s)) return nan2(d, s);
            boolean neg = (d ^ s) < 0;
            if (isInf(d)) return isInf(s) ? invalid() : signedZero(neg) | 0x7F800000;
            if (isInf(s)) return signedZero(neg);
            if (isZero(s)) {
                if (isZero(d)) return invalid();
                cause |= CZ;                       // Table 1.4
                return signedZero(neg) | 0x7F800000;
            }
            if (isZero(d)) return signedZero(neg);
            BigInteger[] qr = mant(d).shiftLeft(50).divideAndRemainder(mant(s));
            return round(neg, qr[0], expo(d) - expo(s) - 50, qr[1].signum() != 0);
        }

        int sqrt(int s) {
            s = in(s);
            if ((cause & CE) != 0) return s;
            if (isNaN(s)) {
                if (isSNaN(s)) {
                    cause |= CV;
                    return s | 0x400000;
                }
                return s;
            }
            if (isZero(s)) return s;
            if (s < 0) return invalid();
            if (isInf(s)) return s;
            BigInteger m = mant(s);
            int e = expo(s);
            if ((e & 1) != 0) {
                m = m.shiftLeft(1);
                e--;
            }
            m = m.shiftLeft(60);
            e -= 60;
            BigInteger r = m.sqrt();
            return round(false, r, e / 2, r.multiply(r).compareTo(m) != 0);
        }

        /** FCMP src, src2: {Z, S, O} of src2 compared with src (p. 90). */
        int[] cmp(int s2, int s) {
            s2 = in(s2);
            s = in(s);
            if ((cause & CE) != 0) return null;
            if (isNaN(s2) || isNaN(s)) {
                if (isSNaN(s2) || isSNaN(s)) cause |= CV;
                return new int[]{0, 0, 1};
            }
            if (isZero(s2) && isZero(s)) return new int[]{1, 0, 0};
            float a = Float.intBitsToFloat(s2), b = Float.intBitsToFloat(s);   // ordered, no denormal: exact
            return new int[]{a == b ? 1 : 0, a < b ? 1 : 0, 0};
        }

        /** ITOF / UTOF (p. 110 / p. 201): 0 is +0 whatever RM says. */
        int itof(long v) {
            if (v == 0) return 0;
            return round(v < 0, BigInteger.valueOf(Math.abs(v)), 0, false);
        }

        /** FTOI (kind 0), ROUND (1, by FPSW.RM), FTOU (2); Table 1.5 for NaN and out of range. */
        int toInt(int kind, int s) {
            s = in(s);
            if ((cause & CE) != 0) return s;
            boolean neg = s < 0;
            int over = kind == 2 ? (neg ? 0 : 0xFFFFFFFF) : (neg ? 0x80000000 : 0x7FFFFFFF);
            if (isNaN(s) || isInf(s)) {
                cause |= CV;
                return over;
            }
            if (isZero(s)) return 0;
            BigInteger m = mant(s);
            int e = expo(s);
            BigInteger q;
            boolean inexact;
            if (e >= 0) {
                q = m.shiftLeft(e);
                inexact = false;
            } else {
                if (e < -40) {                    // |src| < 2^-16: the same as any value below one half
                    m = ONE;
                    e = -40;
                }
                q = m.shiftRight(-e);
                BigInteger rem = m.subtract(q.shiftLeft(-e)), half = ONE.shiftLeft(-e - 1);
                inexact = rem.signum() != 0;
                if (kind == 1 && inexact) {
                    int c = rem.compareTo(half);
                    boolean up;
                    switch (rm()) {
                        case 0: up = c > 0 || c == 0 && q.testBit(0); break;
                        case 1: up = false; break;
                        case 2: up = !neg; break;
                        default: up = neg; break;
                    }
                    if (up) q = q.add(ONE);
                }
            }
            BigInteger v = neg ? q.negate() : q;
            BigInteger lo = BigInteger.valueOf(kind == 2 ? 0 : Integer.MIN_VALUE);
            BigInteger hi = BigInteger.valueOf(kind == 2 ? 0xFFFFFFFFL : Integer.MAX_VALUE);
            if (v.compareTo(lo) < 0 || v.compareTo(hi) > 0) {
                cause |= CV;
                return over;
            }
            if (inexact) cause |= CX;
            return v.intValue();
        }

        /** True when the instruction starts the floating-point exception: unimplemented processing, or a cause whose
         *  enable bit EV..EX (FPSW bits 10..14) is set (p. 21). */
        boolean trap() {
            return (cause & CE) != 0 || (cause & (fpsw >>> 8) & 0x7C) != 0;
        }

        /** FPSW after the instruction: the cause flags are those of this instruction; each Fj (bits 26..30) is set
         *  with its cause unless Ej is 1 (notes 3..7, p. 21); FS (bit 31) is FU | FZ | FO | FV. */
        int fpswAfter() {
            int f = (fpsw & ~0xFC) | cause;
            int sticky = (cause & 0x7C) & ~((fpsw >>> 8) & 0x7C);
            f |= sticky << 24;
            f = (f & 0x7FFFFFFF) | (((f >>> 26) & 0xF) != 0 ? 0x80000000 : 0);
            return f;
        }

        /** Whether S and Z (and FCMP's O) take the result: not when an exception is generated (masked or not). */
        boolean flagsChange() {
            return cause == 0;
        }
    }

    static String regName(int n) {
        return n == 0 ? "SP" : "R" + n;
    }

    /** An FPU instruction: op 0 FSUB, 1 FCMP, 2 FADD, 3 FMUL, 4 FDIV, 5 FTOI, 6 ROUND, 8 FSQRT, 9 FTOU, 16 ITOF,
     *  17 UTOF; the source is an immediate (mode 0), the register rs (1) or memory at rs + dsp (2) of size bytes;
     *  rs2 is src2 of the 3-operand forms (-1: the destination is src2). */
    static final class FpIns {
        int op, rd, rs, rs2 = -1, mode, size = 4, len = 3;
        long imm, dsp;
        boolean signed;
    }

    /** Decodes the FPU forms of the manual's instruction code pages (p. 240..247, 271, 299): FD 72 imm32, FC with
     *  ld, 06 with memex (ITOF / UTOF) and FF 3-operand (FSUB / FADD / FMUL); null for anything else. */
    static FpIns fpuDecode(PcodeExecutorState<byte[]> st, long pc) {
        byte[] c = st.inspectConcrete(st.getLanguage().getDefaultSpace().getAddress(pc), 8);
        int b0 = c[0] & 0xff, b1 = c[1] & 0xff, b2 = c[2] & 0xff;
        FpIns f = new FpIns();
        if (b0 == 0xFD && b1 == 0x72 && (b2 >> 4) <= 4) {
            f.op = b2 >> 4;
            f.rd = b2 & 15;
            f.mode = 0;
            f.imm = (c[3] & 0xffL) | (c[4] & 0xffL) << 8 | (c[5] & 0xffL) << 16 | (c[6] & 0xffL) << 24;
            f.len = 7;
            return f;
        }
        if (b0 == 0xFF && ((b1 >> 4) == 8 || (b1 >> 4) == 0xA || (b1 >> 4) == 0xB)) {
            f.op = (b1 >> 4) == 8 ? 0 : (b1 >> 4) == 0xA ? 2 : 3;
            f.rd = b1 & 15;
            f.mode = 1;
            f.rs = b2 >> 4;
            f.rs2 = b2 & 15;
            return f;
        }
        int ld, regs;
        if (b0 == 0xFC) {
            int k = b1 >> 2;
            ld = b1 & 3;
            regs = b2;
            if (k >= 0x20 && k <= 0x26 || k == 0x28 || k == 0x29) f.op = k - 0x20;
            else if (k == 0x11 || k == 0x15) {          // ITOF / UTOF, memex UB (register: the whole register)
                f.op = k == 0x11 ? 16 : 17;
                f.size = 1;
            } else return null;
            f.dsp = ld == 1 ? (c[3] & 0xffL) : ld == 2 ? ((c[3] & 0xffL) | (c[4] & 0xffL) << 8) : 0;
        } else if (b0 == 0x06 && (b1 & 0x3C) == 0x20 && (b1 & 3) != 3 && (b2 == 0x11 || b2 == 0x15)) {
            int mi = b1 >> 6;                             // memex B, W, L, UW (p. 55: B and W are sign-extended)
            ld = b1 & 3;
            regs = c[3] & 0xff;
            f.op = b2 == 0x11 ? 16 : 17;
            f.size = mi == 0 ? 1 : mi == 2 ? 4 : 2;
            f.signed = mi == 0 || mi == 1;
            f.dsp = ld == 1 ? (c[4] & 0xffL) : ld == 2 ? ((c[4] & 0xffL) | (c[5] & 0xffL) << 8) : 0;
        } else return null;
        f.len = (b0 == 0x06 ? 4 : 3) + (ld == 1 ? 1 : ld == 2 ? 2 : 0);
        f.dsp *= f.size;
        f.rs = regs >> 4;
        f.rd = regs & 15;
        f.mode = ld == 3 ? 1 : 2;
        return f;
    }

    static long readLE(PcodeExecutorState<byte[]> st, long a) {
        byte[] b = st.inspectConcrete(st.getLanguage().getDefaultSpace().getAddress(a), 4);
        return (b[0] & 0xffL) | (b[1] & 0xffL) << 8 | (b[2] & 0xffL) << 16 | (b[3] & 0xffL) << 24;
    }

    JsonObject doBlocks(JsonObject q) throws Exception {
        SimpleBlockModel model = new SimpleBlockModel(currentProgram);
        JsonObject blocks = new JsonObject();
        for (JsonElement e : q.getAsJsonArray("entries")) {
            long a = lv(e);
            Function f = currentProgram.getFunctionManager().getFunctionAt(ram.getAddress(a));
            JsonArray arr = new JsonArray();
            boolean isr = false;
            if (f != null) {
                CodeBlockIterator it = model.getCodeBlocksContaining(f.getBody(), monitor);
                while (it.hasNext()) {
                    CodeBlock b = it.next();
                    arr.add(b.getFirstStartAddress().getOffset());
                }
                for (Instruction ins : currentProgram.getListing().getInstructions(f.getBody(), true))
                    if (ins.getMnemonicString().equalsIgnoreCase("RTE")) isr = true;
            }
            JsonObject o = new JsonObject();
            o.add("blocks", arr);
            o.addProperty("isr", isr);
            o.addProperty("found", f != null);
            blocks.add(String.valueOf(a), o);
        }
        JsonObject res = new JsonObject();
        res.add("blocks", blocks);
        return res;
    }

    @Override
    protected void run() throws Exception {
        lang = currentProgram.getLanguage();
        ram = currentProgram.getAddressFactory().getDefaultAddressSpace();
        out = new PrintStream(new FileOutputStream(FileDescriptor.out), true, "UTF-8");
        Gson gson = new Gson();
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in, "UTF-8"));
        out.println("@@EQ {\"ready\":true}");
        String line;
        while ((line = in.readLine()) != null) {
            if (line.isBlank()) continue;
            JsonObject q = JsonParser.parseString(line).getAsJsonObject();
            String op = q.get("op").getAsString();
            JsonObject res;
            try {
                switch (op) {
                    case "quit":
                        out.println("@@EQ {\"bye\":true}");
                        return;
                    case "base": {
                        List<Object[]> segs = new ArrayList<>();
                        for (JsonElement e : q.getAsJsonArray("segs")) {
                            JsonArray a = e.getAsJsonArray();
                            segs.add(new Object[]{lv(a.get(0)), unhex(a.get(1).getAsString())});
                        }
                        bases.put(q.get("name").getAsString(), segs);
                        res = new JsonObject();
                        res.addProperty("ok", true);
                        break;
                    }
                    case "blocks":
                        res = doBlocks(q);
                        break;
                    case "run":
                        res = doRun(q);
                        break;
                    default:
                        throw new IllegalArgumentException("unknown op " + op);
                }
            } catch (Exception e) {
                res = new JsonObject();
                res.addProperty("error", e.toString());
            }
            out.println("@@EQ " + gson.toJson(res));
        }
    }
}
