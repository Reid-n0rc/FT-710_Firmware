// T24 (IFDSP HiFi4): run functions of the HiFi4 image in Ghidra's p-code emulator for tools/equiv_hifi4_emu.py.
//
// Unicorn has no Xtensa, so the HiFi4 equivalence check runs in Ghidra's p-code emulator (ghidra.pcode.emu.PcodeEmulator)
// on the generated language Xtensa:LE:32:rt600hifi4 (T21a, tools/ghidra/xtensa-rt600hifi4/). Like EquivMainEmu.java
// (MAIN) this script is a server: one JSON request per line on stdin, one answer line "@@EQ <json>" on stdout, so one
// Ghidra process serves a whole check. It only reads the program: run it with -readOnly on a copy of the IFDSP project.
//
// Headless usage (tools/equiv_hifi4_emu.py starts it; by hand for a test):
//   tools/ghidra-headless.sh <projdir> FT710_IFDSP -process FT-710_IFDSP_V0101_hifi4.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript EquivHifi4Emu.java
//
// Requests (one JSON object per line):
//   {"op":"base","name":N,"segs":[[addr,"hex"],...]}   define a named memory image (later runs layer bases)
//   {"op":"blocks","entries":[addr,...]}               basic-block starts (SimpleBlockModel) of the Ghidra function at
//                                                      each address -> {"blocks":{addr:{"blocks":[...],"found":b}}}
//   {"op":"run", "bases":[N,...], "loads":[[addr,"hex"]], "entry":A, "args":[a2,a3,...], "sp":S,
//    "stack":[w,...] (outgoing argument words at the caller's SP), "seed":s, "budget":n,
//    "stubs":{addr:[name,nargs(,ptr_arg,len_arg)]}, "cover":[addr,...], "snap":[[lo,hi],...], "track":[[lo,hi],...],
//    "mmio_fixed":{addr:value}, "fargs":[aed0,...], "exec":[[lo,hi],...] (more code ranges), "trace":true}
//     -> {"end":"return"|"budget"|"fault"|"simcall", "why":..., "ret":[a2,a3] (the callee's a2/a3 = the caller's a10/a11),
//         "sp":..., "steps":n, "mmio":[["r"|"w",addr,size,value],...], "calls":[[name,arg...],...],
//         "userops":[name,...], "ae":{reg:"hex"} (AE/FP state after the run), "diff":[[addr,"hex"],...],
//         "hits":[addr,...], "reads":[addr,...], "forms":[...]}
//   {"op":"quit"}
//
// The windowed ABI (Xtensa ISA: CALLn/CALLXn set PS.CALLINC and a[4n] = n<<30 | return address, ENTRY rotates the
// window by CALLINC and writes the new a[s] = old a1 - frame, RETW/RETW.N rotate back by a0[31:30] and return to
// a0[29:0] | PC[31:30]) is executed here, not by the language: the module models it for the decompiler with the
// pcodeops swap8/rotateRegWindow/restoreRegWindow and a p-code CALL, which the emulator cannot run. The physical
// register file is unbounded (no window overflow or underflow exceptions): the spill code only moves registers to
// the stack and back, and the stack is not compared. The zero-overhead loop end (LEND/LCOUNT/LBEG, Loop Option) is
// also checked here after every instruction that falls through to LEND, because the module's loop-back depends on a
// disassembly context (globalset) that the emulator's decoder does not carry; if the module did loop back itself,
// that is detected (the PC is LBEG) and nothing is done twice.
//
// Memory model (DSP view, tools/ghidra/IfdspHifi4Setup.java): SRAM 0x0..0x47FFFF and its alias 0x20000000..0x2047FFFF,
// the TCM 0x24000000..0x2403FFFF, peripherals 0x40000000..0x4015FFFF. Stores into the image's code and rodata
// (0x200000..0x2367FF) and into the scratch code end the run as a fault (a random pointer would rewrite the code). A peripheral load returns a value from a seeded
// sequence (java.util.Random(seed), or "mmio_fixed") and is recorded with every peripheral store; any other access
// ends the run as a fault. Code may run in the image (0x207000..0x2367FF, the TCM) and in the scratch area
// 0x1B0000..0x1CFFFF where the recreated code is linked. A call to a stub address records (name, a2.. of the callee)
// and returns a seeded value in the callee's a2.
//
// The XCC calling convention of this core passes float arguments in the FP/AE registers (aed0, aed1, ... in the
// order of the float parameters, the value in the L element = bits 31:0) and returns a float in aed0, while integer
// and pointer arguments stay in a2..a7 [fact: fabsf 0x22B680 stores aed0 and returns through aed0, copysignf 0x22B810
// reads aed0 and aed1, scalbnf 0x22B720 takes the int in a2]; "fargs" sets them for an original. GCC (soft float)
// passes floats in the address registers like integers. The few AE operations the checked functions use, which the
// language leaves as named operations, are executed here: AE_S32.L.I/.IP/.X store the L element, AE_L32.I/.IP/.X load a
// word into both elements (the language's FP operations read and write the L element: wfr = zext, rfr = low word)
// [inference: the names and the language's lane model; Open: the H element of AE_L32.I; would be settled by Cadence's
// HiFi4 ISA reference]. AE_MOV copies the register; AE_ZEXT16/AE_SEXT16/AE_ZEXT8 extend (also real p-code since T24);
// CONST.S 0 and 1 give 0.0f and 1.0f [inference: their use as reset and unity values; the other immediates end the
// run]; RSR.CCOUNT gives the next seeded value (the same in both runs); RSIL sets PS.INTLEVEL; the special-register
// moves rsr_/wsr_/xsr_ are plain moves except the interrupt and timer registers. A jump to itself (the
// "while (1);" assertion traps) ends the run as "hang".
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
import java.io.FileDescriptor;
import java.io.FileOutputStream;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Random;
import java.util.Set;
import java.util.TreeSet;

public class EquivHifi4Emu extends GhidraScript {
    static final long SRAM_HI = 0x480000L, ALIAS_LO = 0x20000000L, ALIAS_HI = 0x20480000L;
    static final long TCM_LO = 0x24000000L, TCM_HI = 0x24040000L, IO_LO = 0x40000000L, IO_HI = 0x40160000L;   // the peripherals of IfdspHifi4Setup.java
    static final long TEXT_LO = 0x207000L, TEXT_HI = 0x236800L, SCRATCH_LO = 0x1B0000L, SCRATCH_HI = 0x1D0000L;
    static final long STOP = 0x3FFFFFF0L;            // return address of the call (its bits 31:30 are those of the code)
    static final int WB0 = 1 << 12;                  // window base (in units of 4 registers) of the harness's caller
    static final String[] FP_NOOPS = {"memw", "extw", "isync", "dsync", "esync", "rsync", "excw", "nop"};

    static class Fault extends RuntimeException {
        Fault(String m) { super(m); }
    }

    /** SIMCALL (the ISS/QEMU semihosting call): ends the run normally; tools/xtensa_semcheck.py programs stop with it. */
    static class Simcall extends RuntimeException {
        Simcall() { super("simcall"); }
    }


    final Map<String, List<Object[]>> bases = new HashMap<>();
    Language lang;
    AddressSpace ram;
    PrintStream out;
    Register[] ar = new Register[16];

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

    static boolean isIo(long a) {
        return a >= IO_LO && a < IO_HI;
    }

    static boolean isMem(long a, long e) {
        return e <= SRAM_HI || a >= ALIAS_LO && e <= ALIAS_HI || a >= TCM_LO && e <= TCM_HI;
    }

    /** One emulation run: the callbacks see every load, store and missing user operation. */
    class Run implements PcodeEmulationCallbacks<byte[]> {
        final Random rng;
        final Map<Long, Long> fixed = new HashMap<>();
        final List<Object[]> mmio = new ArrayList<>();
        final Set<String> userops = new TreeSet<>();
        final List<long[]> trackRanges = new ArrayList<>();
        final Set<Long> written = new HashSet<>();
        final TreeSet<Long> reads = new TreeSet<>();
        PcodeArithmetic<byte[]> arith;
        PcodeThread<byte[]> thread;
        // the physical address register file: a[i] of the current window is phys[4 * wb + i]
        final Map<Integer, Long> phys = new HashMap<>();
        int wb = WB0;
        int callinc = 0;

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
            if (store && (a < TEXT_HI && e > 0x200000L || a < SCRATCH_HI && e > SCRATCH_LO))
                throw new Fault(String.format("store of %d bytes into code at 0x%x", size, a));
            if (isMem(a, e)) return;
            if (isIo(a) && e <= IO_HI) return;
            throw new Fault(String.format("%s of %d bytes at 0x%x", store ? "store" : "load", size, a));
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
            } else {
                for (long b = a; b < a + size; b++)
                    if (!written.contains(b) && inTrack(b)) reads.add(b);
            }
        }

        @Override
        public void beforeStore(PcodeThread<byte[]> t, PcodeOp op, AddressSpace space, byte[] offset, int size,
                                byte[] value) {
            if (space != ram) return;
            check(val(offset), size, true);
        }

        boolean branched;

        /** a branch of the instruction to a code address was taken (internal p-code branches are not counted) */
        @Override
        public void afterBranch(PcodeThread<byte[]> t, PcodeOp op, ghidra.program.model.address.Address target) {
            if (target.getAddressSpace() == ram) branched = true;
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
            } else if (!trackRanges.isEmpty()) {
                for (long b = a; b < a + size; b++) if (inTrack(b)) written.add(b);
            }
        }

        long rdmem(long a, int n) {
            check(a, n, false);
            byte[] b = thread.getState().inspectConcrete(ram.getAddress(a), n);
            long v = 0;
            for (int k = n - 1; k >= 0; k--) v = (v << 8) | (b[k] & 0xff);
            return v;
        }

        long reg(String n) {
            return val(thread.getState().getVar(lang.getRegister(n), PcodeExecutorStatePiece.Reason.INSPECT));
        }

        long areg(int i) {
            return val(thread.getState().getVar(ar[i], PcodeExecutorStatePiece.Reason.INSPECT));
        }

        void setReg(String n, long v) {
            Register r = lang.getRegister(n);
            thread.getState().setVar(r, arith.fromConst(v, r.getMinimumByteSize()));
        }

        void setA(int i, long v) {
            thread.getState().setVar(ar[i], arith.fromConst(v & 0xFFFFFFFFL, 4));
        }

        /** Window rotation by n (units of 4 registers): spill the 16 visible registers, move WindowBase, reload. */
        void rotate(int n) {
            for (int i = 0; i < 16; i++) phys.put(4 * wb + i, areg(i));
            wb += n;
            for (int i = 0; i < 16; i++) setA(i, phys.getOrDefault(4 * wb + i, 0L));
            setReg("WindowBase", wb & 0xF);
        }

        long r0ps() {
            return reg("PS");
        }

        void setCallinc(int n) {
            callinc = n;
            long ps = reg("PS");
            setReg("PS", (ps & ~(3L << 16)) | ((long) n << 16));
        }

        @Override
        public boolean handleMissingUserop(PcodeThread<byte[]> t, PcodeOp op, PcodeFrame frame, String name,
                                           PcodeUseropLibrary<byte[]> library) {
            PcodeExecutorState<byte[]> st = t.getState();
            int nin = op.getNumInputs();
            long[] in = new long[nin];
            for (int i = 1; i < nin; i++) {
                Varnode v = op.getInput(i);
                if (v.getSize() <= 8)
                    in[i] = arith.toLong(st.getVar(v, PcodeExecutorStatePiece.Reason.INSPECT), PcodeArithmetic.Purpose.OTHER);
            }
            for (String s : FP_NOOPS)
                if (name.equals(s)) {
                    return true;
                }
            if (name.equals("simcall")) throw new Simcall();
            userops.add(name);
            Varnode o = op.getOutput();
            long res;
            // special registers through the generated rsr_/wsr_/xsr_ operations: the plain register semantics
            // (RSR: at = SR; WSR: SR = at; XSR: at = SR and SR = at) for every special register whose read has no
            // side effect; the interrupt and timer registers are not modelled and end the run
            if (name.equals("ae_s32_l_i") || name.equals("ae_s32_l_ip") || name.equals("ae_s32_l_x")) {
                res = in[1] & 0xFFFFFFFFL;                  // the L (low) element of the AE register (see the header)
            } else if ((name.equals("ae_l32_i") || name.equals("ae_l32_ip") || name.equals("ae_l32_x")) && nin == 2) {
                long v = in[1] & 0xFFFFFFFFL;               // the word, replicated to both elements
                res = v | (v << 32);
            } else if (name.equals("ae_mov") && nin == 2) {
                res = in[1];                                  // AE_MOV: the whole 64-bit register
            } else if (name.equals("ae_zext16") && nin == 2) {
                res = in[1] & 0xFFFF;                         // AE_ZEXT16 ar, as (address registers)
            } else if (name.equals("ae_zext8") && nin == 2) {
                res = in[1] & 0xFF;
            } else if (name.equals("ae_sext16") && nin == 2) {
                res = (long) (short) in[1] & 0xFFFFFFFFL;
            } else if (name.equals("const_s") && nin == 2 && (in[1] == 0 || in[1] == 1)) {
                res = in[1] == 0 ? 0 : 0x3F800000L;           // CONST.S 0 / 1: 0.0f / 1.0f (header)
            } else if (name.equals("rsr_ccount")) {
                res = rng.nextInt() & 0xFFFFFFFFL;            // CCOUNT: from the seeded sequence, the same in both runs
            } else if (name.equals("rsil")) {                     // RSIL at, level: at = PS, PS.INTLEVEL = level
                long ps = r0ps();
                setReg("PS", (ps & ~0xFL) | (in[1] & 0xF));
                res = ps;
            } else if (name.startsWith("rsr_") && nin == 2 && !name.contains("interrupt") && !name.contains("ccount")) res = in[1];
            else if (name.equals("wsr_ps") && nin == 2) res = in[1];
            else if (name.startsWith("wsr_") && nin == 2 && (o == null || o.getSize() <= 4) && !name.contains("intset")
                    && !name.contains("intclear") && !name.contains("intenable")) res = in[1];
            else if (name.startsWith("xsr_") && name.endsWith("_1") && nin == 3) res = in[1];
            else if (name.startsWith("xsr_") && nin == 3) res = in[2];
            else throw new Fault("unimplemented pcodeop " + name);
            if (o != null) st.setVar(o, arith.fromConst(res, o.getSize()));
            return true;
        }
    }

    static int len(int b0) {
        int op0 = b0 & 0xF;
        if (op0 == 0xE) return 6;
        if (op0 == 0xF) return 11;
        if (op0 >= 8) return 2;
        return 3;
    }

    JsonObject doRun(JsonObject q) {
        long seed = q.has("seed") ? q.get("seed").getAsLong() : 1;
        Run r = new Run(seed);
        PcodeEmulator emu = new PcodeEmulator(lang, r);
        r.arith = emu.getArithmetic();
        PcodeExecutorState<byte[]> shared = emu.getSharedState();
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
                String[] s = new String[a.size()];
                for (int i = 0; i < s.length; i++) s[i] = a.get(i).getAsString();
                stubs.put(Long.decode(e.getKey()), s);
            }
        List<long[]> xr = new ArrayList<>();
        if (q.has("exec"))
            for (JsonElement e : q.getAsJsonArray("exec")) {
                JsonArray a = e.getAsJsonArray();
                xr.add(new long[]{lv(a.get(0)), lv(a.get(1))});
            }
        Set<Long> cover = new HashSet<>();
        if (q.has("cover")) for (JsonElement e : q.getAsJsonArray("cover")) cover.add(lv(e));
        Set<Long> hits = new TreeSet<>();

        PcodeThread<byte[]> t = emu.newThread();
        r.thread = t;
        // the caller: window WB0, a1 = SP, a8 = return address of a CALL8, the arguments in a10..a15
        long sp = q.has("sp") ? lv(q.get("sp")) : 0x1E0000L;
        r.setReg("PS", 0x00040020L);   // WOE = 1, UM = 1, INTLEVEL 0 (as in a thread)
        r.setReg("WindowBase", WB0 & 0xF);
        r.setReg("WindowStart", 1);
        r.setReg("FCR", 0);
        r.setReg("FSR", 0);
        for (int i = 0; i < 16; i++) r.setA(i, 0);
        r.setA(1, sp);
        r.setA(8, (2L << 30) | (STOP & 0x3FFFFFFFL));
        if (q.has("args")) {
            int k = 0;
            for (JsonElement e : q.getAsJsonArray("args")) {
                if (k < 6) r.setA(10 + k, lv(e));
                k++;
            }
        }
        if (q.has("fargs")) {                          // XCC float arguments: aed0.. (L element), H = 0
            int k = 0;
            for (JsonElement e : q.getAsJsonArray("fargs"))
                r.setReg("aed" + k++, lv(e));
        }
        if (q.has("stack")) {
            int k = 0;
            for (JsonElement e : q.getAsJsonArray("stack")) writeLE(shared, sp + 4L * k++, lv(e));
        }
        r.setCallinc(2);
        long entry = lv(q.get("entry"));
        t.overrideCounter(ram.getAddress(entry));
        long budget = q.has("budget") ? q.get("budget").getAsLong() : 2000000;
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
                    // reached by a CALLn of the caller: the callee's a2.. are the caller's a[4n+2]..
                    int n = Integer.parseInt(stub[1]), base = 4 * r.callinc;
                    JsonArray c = new JsonArray();
                    c.add(stub[0]);
                    for (int k = 0; k < n && base + 2 + k < 16; k++) c.add(r.areg(base + 2 + k));
                    if (stub.length >= 4) {
                        int pi = Integer.parseInt(stub[2]), li = Integer.parseInt(stub[3]);
                        long ptr = c.get(1 + pi).getAsLong(), ln = Math.min(c.get(1 + li).getAsLong(), 0x4000);
                        if (isMem(ptr, ptr + ln)) c.add(hex(shared.inspectConcrete(ram.getAddress(ptr), (int) ln), 0, (int) ln));
                    }
                    calls.add(c);
                    long ret = new long[]{0, 0, 0, 1, 0xFFFFFFFFL, r.rng.nextInt() & 0xFFFFFFFFL}[r.rng.nextInt(6)];
                    long ra = r.areg(base);
                    if (base == 0) throw new Fault(String.format("stub %s reached without a windowed call", stub[0]));
                    r.setA(base + 2, ret);
                    t.overrideCounter(ram.getAddress((ra & 0x3FFFFFFFL) | (pc & 0xC0000000L)));
                    steps++;
                    continue;
                }
                boolean ok = pc >= TEXT_LO && pc < TEXT_HI || pc >= SCRATCH_LO && pc < SCRATCH_HI || pc >= TCM_LO && pc < TCM_HI;
                for (long[] x : xr) ok |= pc >= x[0] && pc < x[1];
                if (!ok) throw new Fault(String.format("execute at 0x%x", pc));
                byte[] ib = shared.inspectConcrete(ram.getAddress(pc), 3);
                int b0 = ib[0] & 0xff, b1 = ib[1] & 0xff, b2 = ib[2] & 0xff;
                long w = b0 | (b1 << 8) | ((long) b2 << 16);
                if (trace != null && trace.size() < 2000) {
                    JsonArray st = new JsonArray();
                    st.add(pc);
                    for (int k = 0; k < 16; k++) st.add(r.areg(k));
                    trace.add(st);
                }
                int il = len(b0);
                // the windowed ABI, executed here (see the header)
                if (il == 3 && (w & 0xF) == 5 && ((w >> 4) & 3) != 0) {           // CALL4/8/12
                    int n = (int) ((w >> 4) & 3);
                    long off = (w >> 6) & 0x3FFFF;
                    if ((off & 0x20000) != 0) off -= 0x40000;
                    long tgt = ((pc & ~3L) + (off << 2) + 4) & 0xFFFFFFFFL;
                    r.setA(4 * n, ((long) n << 30) | ((pc + 3) & 0x3FFFFFFFL));
                    r.setCallinc(n);
                    t.overrideCounter(ram.getAddress(tgt));
                    steps++;
                    continue;
                }
                if (il == 3 && (w & 0xFFF00F) == 0 && ((w >> 4) & 0xC) == 0xC && ((w >> 4) & 3) != 0) {   // CALLX4/8/12
                    int n = (int) ((w >> 4) & 3), s = (int) ((w >> 8) & 0xF);
                    long tgt = r.areg(s);
                    r.setA(4 * n, ((long) n << 30) | ((pc + 3) & 0x3FFFFFFFL));
                    r.setCallinc(n);
                    t.overrideCounter(ram.getAddress(tgt));
                    steps++;
                    continue;
                }
                if (il == 3 && (w & 0xFF) == 0x36) {                                 // ENTRY as, imm
                    int s = (int) ((w >> 8) & 0xF);
                    long frame = ((w >> 12) & 0xFFF) << 3;
                    if (r.callinc == 0) throw new Fault(String.format("entry at 0x%x after a CALL0", pc));
                    long newsp = (r.areg(1) - frame) & 0xFFFFFFFFL;
                    int n = r.callinc;
                    r.rotate(n);
                    r.setA(s, newsp);
                    r.setCallinc(0);
                    t.overrideCounter(ram.getAddress(pc + 3));
                    steps++;
                    continue;
                }
                boolean retw = il == 3 && w == 0x000090L || il == 2 && (b0 | (b1 << 8)) == 0xF01D;
                if (retw) {                                                          // RETW, RETW.N
                    long a0 = r.areg(0);
                    int n = (int) (a0 >>> 30);
                    if (n == 0) throw new Fault(String.format("retw at 0x%x with a0[31:30] = 0", pc));
                    r.rotate(-n);
                    t.overrideCounter(ram.getAddress((a0 & 0x3FFFFFFFL) | (pc & 0xC0000000L)));
                    steps++;
                    continue;
                }
                long lend = r.reg("LEND"), lcount = r.reg("LCOUNT");
                r.branched = false;
                t.stepInstruction();
                steps++;
                long npc = t.getCounter().getOffset();
                if (npc == pc) {
                    // a jump to itself (the assertion trap "while (1);" of rpmsg-lite and newlib): the run can only
                    // end in the budget; end it now (both builds stop the same way, at their own address)
                    end = "hang";
                    break;
                }
                Instruction ins = t.getInstruction();
                long fall = pc + (ins != null ? ins.getLength() : il);
                if (npc == fall && !r.branched && fall == lend && lcount != 0 && r.reg("LEND") == lend) {
                    // Loop Option: the instruction ends at LEND, falls through (a taken branch, also one to LEND,
                    // leaves the loop: newlib's strncpy.S exits its byte loop with "beqz a8, 1f" where 1: is LEND)
                    // and LCOUNT != 0 -> LCOUNT - 1, continue at LBEG
                    r.setReg("LCOUNT", (r.reg("LCOUNT") - 1) & 0xFFFFFFFFL);
                    t.overrideCounter(ram.getAddress(r.reg("LBEG")));
                }
            }
        } catch (Fault f) {
            end = "fault";
            why = f.getMessage();
        } catch (Simcall f) {
            end = "simcall";
        } catch (Exception e) {
            Throwable c = e;
            while (c.getCause() != null && !(c instanceof Fault) && !(c instanceof Simcall)) c = c.getCause();
            end = c instanceof Simcall ? "simcall" : "fault";
            why = (c instanceof Fault) ? c.getMessage() : c instanceof Simcall ? "" : (e.getClass().getSimpleName() + ": " + e.getMessage());
        }
        JsonObject res = new JsonObject();
        res.addProperty("end", end);
        res.addProperty("why", why);
        res.addProperty("steps", steps);
        res.addProperty("wb", r.wb - WB0);
        JsonArray ret = new JsonArray();
        ret.add(r.areg(10));
        ret.add(r.areg(11));
        res.add("ret", ret);
        res.addProperty("sp", r.areg(1));
        JsonArray regs = new JsonArray();
        for (int k = 0; k < 16; k++) regs.add(r.areg(k));
        res.add("regs", regs);
        JsonObject ae = new JsonObject();
        for (String n : new String[]{"aed0", "aed1", "aed2", "aed3", "aed4", "aed5", "aed6", "aed7", "aed8", "aed9",
                "aed10", "aed11", "aed12", "aed13", "aed14", "aed15", "u0", "u1", "u2", "u3", "FCR", "FSR", "SAR"}) {
            Register g = lang.getRegister(n);
            if (g == null) continue;
            byte[] v = t.getState().getVar(g, PcodeExecutorStatePiece.Reason.INSPECT);
            ae.addProperty(n, hex(v, 0, v.length));
        }
        res.add("ae", ae);
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

    JsonObject doBlocks(JsonObject q) throws Exception {
        SimpleBlockModel model = new SimpleBlockModel(currentProgram);
        JsonObject blocks = new JsonObject();
        for (JsonElement e : q.getAsJsonArray("entries")) {
            long a = lv(e);
            Function f = currentProgram.getFunctionManager().getFunctionAt(ram.getAddress(a));
            JsonArray arr = new JsonArray();
            if (f != null) {
                CodeBlockIterator it = model.getCodeBlocksContaining(f.getBody(), monitor);
                while (it.hasNext()) {
                    CodeBlock b = it.next();
                    arr.add(b.getFirstStartAddress().getOffset());
                }
            }
            JsonObject o = new JsonObject();
            o.add("blocks", arr);
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
        for (int i = 0; i < 16; i++) ar[i] = lang.getRegister("a" + i);
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
