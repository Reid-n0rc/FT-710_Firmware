// T21d (#97 B3): compare every call site's argument/return registers in the disassembly with what the decompiler shows.
// Headless usage (from the repo root, read-only):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript CallArgCheck.java <mismatch.tsv> [<protos.tsv>]
// CC-RX calling convention: arguments in R1..R4, return in R1 (64-bit in R1:R2), R1-R5/R14/R15 caller-saved.
// ARM (DISPLAY A32/Thumb, IFDSP M33 Thumb-2; T23f): AAPCS, arguments in r0..r3, return in r0 (64-bit r0:r1), r0-r3/r12/lr
// caller-saved. The script maps them onto the same slots (slot k = r(k-1)), so every column below reads "R1..R4" as
// "r0..r3" on ARM; asm_params names the real registers (r0:L, r1:B, ...). On ARM a PUSH/STMDB SP! counts as no use
// (armcc and gcc push r0-r3 to reserve stack as often as to spill an argument; signatures_draft.py treats the pushed ones
// as unknown), the first-use size comes from UXTB/SXTB/UXTH/SXTH or STRB/STRH, and a call reads what its callee reads
// at entry (liveness repeated up to 4 passes). Tail calls ("b func", flow CALL_TERMINATOR) give no return evidence and
// are left out of the per-callee stats. protos.tsv gets three more columns: writes_ret (the function, or what it calls,
// writes R1/r0), sites_read_R2 (call sites that read R2/r1 after the call) and, on ARM, sites_keep_scratch (call sites
// after which r2/r3/r12 are live, or r0/r1 although the callee never writes them: the caller relies on gcc's -fipa-ra).
//
// Disassembly view of a call site (heuristic, documented in docs/tasks/T21-ghidra-gaps.md, T21d):
//   asm_args = highest k such that Rk (k = 1..4) is written in the same basic block before the call and not read again
//              before the call (so a temporary like "MOV.L #x,R1; MOV.B R7,[R1]" is not counted). The scan stops at the
//              block start or at an earlier call.
//   asm_ret  = R1 (and R2) read before being written in the instructions that follow the call (fall-through only,
//              up to 8 instructions, stopping at a branch, call or return).
// Decompiler view: the CALL p-code op at the site in the callee's caller (HighFunction): number of inputs and whether it
// has an output.
// String instructions (SMOVF, SSTR, ...) do not count as argument set-up: their R1-R3 outputs are side effects.
// mismatch.tsv kinds: dropped_arg (asm_args > c_args, and the callee reads one of the missing registers at entry), lost_ret (R1 read after the call, no output in the C),
// wide_ret (R1 and R2 read after the call: a 64-bit return candidate, and the C output is <= 4 bytes).
// protos.tsv: per function, the disassembly-derived prototype (live-in R1..R4 at entry with the size of the first
// spill, how many call sites read R1/R2 afterwards) next to the decompiler's prototype, used to draft signatures_main.tsv.
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileOptions;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.block.CodeBlock;
import ghidra.program.model.block.CodeBlockIterator;
import ghidra.program.model.block.SimpleBlockModel;
import ghidra.program.model.lang.Register;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.pcode.FunctionPrototype;
import ghidra.program.model.pcode.HighFunction;
import ghidra.program.model.pcode.PcodeOp;
import ghidra.program.model.pcode.PcodeOpAST;
import ghidra.program.model.symbol.SourceType;

import java.io.PrintWriter;
import java.util.*;

public class CallArgCheck extends GhidraScript {
    Register[] R = new Register[16];
    int clobber; // caller-saved mask
    boolean arm; // AAPCS instead of CC-RX (T23f)
    String regName(int slot) { return arm ? "r" + (slot - 1) : "R" + slot; }

    int mask(Object[] objs) {
        int m = 0;
        for (Object o : objs) {
            if (o instanceof Register) {
                Register r = (Register) o;
                for (int i = 0; i < 16; i++) if (R[i] != null && R[i].equals(r)) m |= 1 << i;
            }
        }
        return m;
    }

    static final Set<String> STRING_OPS = Set.of("SMOVF", "SMOVB", "SMOVU", "SSTR", "SCMPU", "SUNTIL", "SWHILE", "RMPA");
    Map<Function, Integer> liveInMask = new HashMap<>();
    Map<Function, Integer> tailLiveIn = new HashMap<>();
    Map<Function, Map<Address, Integer>> blockLiveIn = new HashMap<>();
    Map<Function, Map<Address, List<Address>>> blockSucc = new HashMap<>();
    Map<Function, Integer> writeMask = new HashMap<>(); // ARM: registers the function (or anything it calls) may write

    // ARM: least fixpoint of "registers written" over the call graph; an indirect call or an unknown callee writes all
    // caller-saved registers. gcc -fipa-ra keeps values in r0..r3/r12 across a call to a function that never writes them.
    void computeWriteMasks(List<Function> funcs) {
        Map<Function, Integer> local = new HashMap<>();
        Map<Function, Set<Function>> calls = new HashMap<>();
        for (Function f : funcs) {
            int m = 0;
            Set<Function> cs = new HashSet<>();
            for (Instruction in : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                m |= defs(in);
                if (isCall(in)) {
                    Function c = callee(in);
                    if (c == null || c.isExternal()) m |= clobber; else cs.add(c);
                }
            }
            local.put(f, m);
            calls.put(f, cs);
        }
        writeMask = new HashMap<>(local);
        boolean ch = true;
        for (int it = 0; ch && it < 100; it++) {
            ch = false;
            for (Function f : funcs) {
                int m = local.get(f);
                for (Function c : calls.get(f)) m |= writeMask.getOrDefault(c, clobber);
                if (m != writeMask.get(f)) { writeMask.put(f, m); ch = true; }
            }
        }
    }

    // ARM: registers live right after a call instruction in its caller (rest of the block, then the successors' block
    // live-in from asmParams)
    int liveAfter(Instruction call, Function f, SimpleBlockModel bm) throws Exception {
        CodeBlock[] bl = bm.getCodeBlocksContaining(call.getAddress(), monitor);
        if (bl.length == 0 || !blockLiveIn.containsKey(f)) return 0;
        CodeBlock b = bl[0];
        int use = 0, def = 0;
        for (Instruction in = call.getNext(); in != null && b.contains(in.getAddress()); in = in.getNext()) {
            use |= uses(in) & ~def;
            if (isCall(in)) {
                Function c = callee(in);
                // an indirect call (or one to an unknown target) may read any of r0..r3
                use |= (c != null ? liveInMask.getOrDefault(c, 0) : 0x1E) & ~def;
            }
            def |= defs(in);
            if (isCall(in)) def |= clobber;
        }
        int lo = 0;
        for (Address s : blockSucc.get(f).getOrDefault(b.getFirstStartAddress(), List.of())) {
            CodeBlock[] sb = bm.getCodeBlocksContaining(s, monitor);
            Address k = sb.length > 0 ? sb[0].getFirstStartAddress() : s;
            lo |= blockLiveIn.get(f).getOrDefault(k, 0);
        }
        return use | (lo & ~def);
    }

    // PUSHM/POPM/RTSD are modelled as chains of conditional pushes over R1..R15, so Ghidra's input/result objects name
    // every register; use the register range in the operands instead.
    int rangeMask(Instruction in) {
        java.util.regex.Matcher mt = java.util.regex.Pattern.compile("R(\\d+)-R(\\d+)").matcher(in.toString());
        if (!mt.find()) return 0;
        int a = Integer.parseInt(mt.group(1)), b = Integer.parseInt(mt.group(2)), m = 0;
        for (int i = a; i <= b; i++) m |= 1 << i;
        return m;
    }

    int uses(Instruction in) {
        String mn = in.getMnemonicString();
        if (arm) {
            String m = mn.toLowerCase();
            if (m.startsWith("push") || (m.startsWith("stmdb") && in.toString().toLowerCase().contains("sp!"))) return 0;
            if ((m.equals("cpy") || m.equals("mov")) && in.getNumOperands() == 2
                    && in.getDefaultOperandRepresentation(0).equals(in.getDefaultOperandRepresentation(1))) return 0; // nop
            return mask(in.getInputObjects());
        }
        if (mn.equals("PUSHM")) return rangeMask(in);
        if (mn.equals("POPM") || mn.equals("RTSD")) return 0;
        return mask(in.getInputObjects());
    }

    int defs(Instruction in) {
        String mn = in.getMnemonicString();
        if (arm) return mask(in.getResultObjects());
        if (mn.equals("PUSHM")) return 0;
        if (mn.equals("POPM") || mn.equals("RTSD")) return rangeMask(in);
        return mask(in.getResultObjects());
    }

    boolean isCall(Instruction in) { return in.getFlowType().isCall(); }

    Function callee(Instruction in) {
        Address[] fl = in.getFlows();
        if (fl == null || fl.length == 0) return null;
        Function c = getFunctionAt(fl[0]);
        if (c != null && c.isThunk()) c = c.getThunkedFunction(true);
        return c;
    }

    // asm arguments: bitmask of R1..R4 live-defined in the block before the call
    int asmArgs(Instruction call, SimpleBlockModel bm) throws Exception {
        CodeBlock[] bl = bm.getCodeBlocksContaining(call.getAddress(), monitor);
        Address start = bl.length > 0 ? bl[0].getFirstStartAddress() : call.getAddress();
        int defined = 0, seen = 0, readLater = 0;
        Instruction in = call.getPrevious();
        while (in != null && in.getAddress().compareTo(start) >= 0) {
            if (isCall(in)) break;
            int out = defs(in) & ~seen;
            if (STRING_OPS.contains(in.getMnemonicString().replaceAll("\\..*", ""))) out = 0;
            defined |= out & ~readLater;  // written, not read again before the call: an argument
            seen |= out;                  // consumed temporaries are resolved too
            readLater |= uses(in);
            if (in.getAddress().equals(start)) break;
            in = in.getPrevious();
        }
        return defined & 0x1E; // R1..R4
    }

    // R1/R2 read before written after the call: bit1 = R1, bit2 = R2
    int lastRetSize; // size the caller gives R1 at its first read after the call: 1/2 from MOV.B/MOV.W R1,..., else 4

    int retSize(Instruction in) {
        String mn = in.getMnemonicString();
        if (arm) return armUseSize(in, 1);
        if (in.getNumOperands() == 2 && in.getDefaultOperandRepresentation(0).equals("R1")) {
            if (mn.equals("MOV.B")) return 1;
            if (mn.equals("MOV.W")) return 2;
        }
        return 4;
    }

    int asmRet(Instruction call) {
        int written = 0, used = 0;
        lastRetSize = 0;
        Instruction in = call.getNext();
        for (int n = 0; in != null && n < 8; n++) {
            if (n > 0 && hasFlowRefTo(in)) break; // a join: other paths reach here
            int u = uses(in) & ~written & (arm ? 0x201E : 0x6); // ARM: also r2, r3, r12 (sites_keep_scratch)
            if ((u & 2) != 0 && (used & 2) == 0) lastRetSize = retSize(in);
            used |= u;
            written |= defs(in);
            if (isCall(in) || in.getFlowType().isJump() || in.getFlowType().isTerminal()) break;
            in = in.getNext();
        }
        return used;
    }

    boolean hasFlowRefTo(Instruction in) {
        for (var r : getReferencesTo(in.getAddress())) if (r.getReferenceType().isFlow()) return true;
        return false;
    }

    static int highest(int m) { int k = 0; for (int i = 1; i <= 4; i++) if ((m & (1 << i)) != 0) k = i; return k; }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        arm = currentProgram.getLanguage().getProcessor().toString().equalsIgnoreCase("ARM");
        if (arm) {
            // slot k = r(k-1) for k = 1..13 (r0..r12), 14 = lr, 15 = sp; caller-saved r0-r3, r12, lr
            for (int i = 1; i <= 13; i++) R[i] = currentProgram.getRegister("r" + (i - 1));
            R[14] = currentProgram.getRegister("lr");
            R[15] = currentProgram.getRegister("sp");
            clobber = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 13) | (1 << 14);
        } else {
            for (int i = 0; i < 16; i++) R[i] = currentProgram.getRegister("R" + i);
            clobber = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 14) | (1 << 15);
        }
        SimpleBlockModel bm = new SimpleBlockModel(currentProgram);

        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);

        // per-callee stats
        Map<Function, int[]> st = new HashMap<>(); // sites, readR1, readR2, maxAsmArgs
        Map<Function, String> cproto = new HashMap<>();
        List<String> rows = new ArrayList<>();
        int tailSites = 0, sites = 0, dropped = 0, lost = 0, wide = 0, droppedSig = 0, lostSig = 0, wideSig = 0, failed = 0;
        Set<Function> dropFns = new HashSet<>(), lostFns = new HashSet<>();

        List<Function> funcs = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            if (!f.isExternal() && !f.isThunk()) funcs.add(f);
        Map<Function, String> asmP = new HashMap<>();
        for (Function f : funcs) asmP.put(f, asmParams(f, bm));
        // ARM: more passes, each call reading the live-in registers its callee had in the pass before
        for (int pass = 0; arm && pass < 3; pass++) {
            tailLiveIn = new HashMap<>(liveInMask);
            for (Function f : funcs) asmP.put(f, asmParams(f, bm));
            if (liveInMask.equals(tailLiveIn)) break;
        }
        if (arm) computeWriteMasks(funcs);
        monitor.initialize(funcs.size());
        for (Function f : funcs) {
            monitor.checkCancelled();
            monitor.incrementProgress(1);
            DecompileResults r = ifc.decompileFunction(f, 60, monitor);
            HighFunction hf = (r != null && r.decompileCompleted()) ? r.getHighFunction() : null;
            if (hf == null) { failed++; continue; }
            FunctionPrototype p = hf.getFunctionPrototype();
            StringBuilder sb = new StringBuilder();
            sb.append(p.getReturnType().getDisplayName()).append(" (");
            for (int i = 0; i < p.getNumParams(); i++) {
                if (i > 0) sb.append(", ");
                sb.append(p.getParam(i).getDataType().getDisplayName());
            }
            sb.append(")");
            cproto.put(f, sb.toString());
            Map<Address, PcodeOpAST> calls = new HashMap<>();
            Iterator<PcodeOpAST> it = hf.getPcodeOps();
            while (it.hasNext()) {
                PcodeOpAST op = it.next();
                if (op.getOpcode() == PcodeOp.CALL) calls.put(op.getSeqnum().getTarget(), op);
            }
            for (Instruction in : currentProgram.getListing().getInstructions(f.getBody(), true)) {
                if (!isCall(in)) continue;
                Function c = callee(in);
                if (c == null) continue;
                sites++;
                int am = asmArgs(in, bm), aa = highest(am), ar = asmRet(in);
                int[] s = st.computeIfAbsent(c, k -> new int[9]);
                // a tail call (ARM "b func"/"b.w func", flow CALL_TERMINATOR) returns to the caller's caller: what follows
                // it is another function or a literal pool, so it gives no return evidence and is left out of the stats
                if (in.getFlowType().isTerminal()) { tailSites++; continue; }
                s[0]++;
                if ((ar & 2) != 0) s[1]++;
                if ((ar & 6) == 6) s[2]++;
                s[3] = Math.max(s[3], aa);
                if ((ar & 2) != 0) s[lastRetSize == 1 ? 4 : lastRetSize == 2 ? 5 : 6]++;
                if ((ar & 4) != 0) s[7]++;            // r1 / R1 read (with or without r0)
                if (arm) { // the caller relies on the callee keeping a register: r2/r3/r12 live after the call, or r0/r1
                    // live although the callee (with what it calls) never writes them (gcc -fipa-ra)
                    int la = liveAfter(in, f, bm), wm = writeMask.getOrDefault(c, clobber);
                    if ((la & 0x2018) != 0 || (la & 6 & ~wm) != 0) s[8]++;
                }
                PcodeOpAST op = calls.get(in.getAddress());
                if (op == null) continue; // call removed (unreachable block)
                int ca = op.getNumInputs() - 1;
                boolean cout = op.getOutput() != null;
                int coutSize = cout ? op.getOutput().getSize() : 0;
                boolean sig = c.getSignatureSource() == SourceType.USER_DEFINED;
                List<String> kinds = new ArrayList<>();
                // dropped only if the callee itself reads a register beyond the C argument count at its entry
                int calleeIn = liveInMask.getOrDefault(c, 0x1E);
                boolean calleeReads = (calleeIn & ~((1 << (ca + 1)) - 1) & am) != 0;
                if (aa > ca && calleeReads) { kinds.add("dropped_arg"); dropped++; dropFns.add(c); if (sig) droppedSig++; }
                if ((ar & 2) != 0 && !cout) { kinds.add("lost_ret"); lost++; lostFns.add(c); if (sig) lostSig++; }
                if ((ar & 6) == 6 && coutSize <= 4) { kinds.add("wide_ret"); wide++; if (sig) wideSig++; }
                for (String k : kinds)
                    rows.add(k + "\t" + in.getAddress() + "\t" + f.getEntryPoint() + "\t" + f.getName() + "\t"
                            + c.getEntryPoint() + "\t" + c.getName() + "\t" + aa + "\t" + ca + "\t"
                            + ((ar & 2) != 0 ? regName(1) : "") + ((ar & 4) != 0 ? regName(2) : "") + "\t" + coutSize + "\t"
                            + (sig ? "sig" : "-"));
            }
        }
        ifc.dispose();
        try (PrintWriter out = new PrintWriter(args[0], "UTF-8")) {
            out.println("# CallArgCheck: sites=" + sites + " dropped_arg=" + dropped + " (callee with signature: " + droppedSig
                    + ") lost_ret=" + lost + " (" + lostSig + ") wide_ret=" + wide + " (" + wideSig + ") callees: dropped="
                    + dropFns.size() + " lost=" + lostFns.size() + " decompile_failed=" + failed
                    + (tailSites > 0 ? " tail_calls_skipped=" + tailSites : ""));
            out.println("kind\tsite\tcaller\tcaller_name\tcallee\tcallee_name\tasm_args\tc_args\tasm_ret_read\tc_ret_size\tcallee_sig");
            for (String s : rows) out.println(s);
        }
        println("CallArgCheck: sites=" + sites + " dropped_arg=" + dropped + " (sig " + droppedSig + ") lost_ret=" + lost
                + " (sig " + lostSig + ") wide_ret=" + wide + " (sig " + wideSig + ") callees dropped=" + dropFns.size()
                + " lost=" + lostFns.size() + " failed=" + failed);

        if (args.length > 1) {
            try (PrintWriter out = new PrintWriter(args[1], "UTF-8")) {
                out.println("entry\tname\tsig_source\tasm_params\tsites\tsites_read_R1\tsites_read_R1R2\tmax_site_args\tc_proto\tentry_insn\tret_use_B_W_L\tret_epilogue\twrites_ret\tsites_read_R2\tsites_keep_scratch");
                for (Function f : funcs) {
                    int[] s = st.getOrDefault(f, new int[9]);
                    Instruction e = getInstructionAt(f.getEntryPoint());
                    out.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + f.getSignatureSource() + "\t"
                            + asmP.get(f) + "\t" + s[0] + "\t" + s[1] + "\t" + s[2] + "\t" + s[3] + "\t"
                            + cproto.getOrDefault(f, "?") + "\t" + (e == null ? "-" : e.toString()) + "\t" + s[4] + "/" + s[5] + "/" + s[6] + "\t" + retEpilogue(f) + "\t" + (writesRet(f) ? 1 : 0)
                            + "\t" + s[7] + "\t" + s[8]);
                }
            }
        }
    }

    // writes_ret: 1 if any instruction of the function (a call included) writes the return register R1 / r0. A caller
    // that reads r0 after calling a function that never writes it relies on gcc's -fipa-ra (the M33 code does), which is
    // not a return value.
    boolean writesRet(Function f) {
        if (arm) return (writeMask.getOrDefault(f, clobber) & 2) != 0; // transitive over the call graph
        for (Instruction in : currentProgram.getListing().getInstructions(f.getBody(), true))
            if ((defs(in) & 2) != 0 || isCall(in)) return true;
        return false;
    }

    // the CC-RX -O0 return idiom: the instruction right before each RTS/RTSD loads R1 from the frame
    // (MOVU.B/MOVU.W = unsigned 1/2 bytes, MOV.B/MOV.W = signed, MOV.L = 4), or stores R1 to the frame
    // (SB/SW/SL; not right after a call). "-" if no return has it, "mixed" if they differ.
    String retEpilogue(Function f) {
        String res = null;
        boolean any = false;
        for (Instruction in : currentProgram.getListing().getInstructions(f.getBody(), true)) {
            String mn = in.getMnemonicString();
            if (!mn.equals("RTS") && !mn.equals("RTSD")) continue;
            if (mn.equals("RTSD") && (rangeMask(in) & 2) != 0) continue; // pops R1 itself
            Instruction pv = in.getPrevious();
            String k = "-";
            if (pv != null && pv.getNumOperands() == 2 && pv.getDefaultOperandRepresentation(1).equals("R1")
                    && pv.getDefaultOperandRepresentation(0).contains("[")) {
                String pm = pv.getMnemonicString();
                k = pm.equals("MOVU.B") ? "UB" : pm.equals("MOVU.W") ? "UW" : pm.equals("MOV.B") ? "B"
                        : pm.equals("MOV.W") ? "W" : pm.equals("MOV.L") ? "L" : "-";
            } else if (pv != null && pv.getNumOperands() == 2 && pv.getDefaultOperandRepresentation(0).equals("R1")
                    && pv.getDefaultOperandRepresentation(1).contains("[SP]") && pv.getMnemonicString().startsWith("MOV.")
                    && pv.getPrevious() != null && !isCall(pv.getPrevious())) {
                // the other -O0 form: R1 is stored to the return slot right before the return (not a call result)
                k = "S" + pv.getMnemonicString().substring(4);
            }
            if (!k.equals("-")) any = true;
            res = res == null ? k : res.equals(k) ? res : "mixed";
        }
        return res == null || !any ? "-" : res;
    }

    // ARM: the width an instruction gives slot register `slot` (r(slot-1)) when it reads it: UXTB/SXTB or STRB of it = 1,
    // UXTH/SXTH or STRH of it = 2, anything else 4. Only the register being narrowed or stored counts (operand 1 of the
    // extend, operand 0 of the store).
    int armUseSize(Instruction in, int slot) {
        String m = in.getMnemonicString().toLowerCase().replaceAll("\\..*", "");
        String rn = "r" + (slot - 1);
        int n = in.getNumOperands();
        if ((m.startsWith("uxtb") || m.startsWith("sxtb") || m.startsWith("uxth") || m.startsWith("sxth")) && n >= 2
                && in.getDefaultOperandRepresentation(1).equalsIgnoreCase(rn))
            return m.charAt(3) == 'b' ? 1 : 2;
        if ((m.startsWith("strb") || m.startsWith("strh")) && n >= 1 && in.getDefaultOperandRepresentation(0).equalsIgnoreCase(rn))
            return m.startsWith("strb") ? 1 : 2;
        return 4;
    }

    // live-in R1..R4 at the entry (block-level liveness; calls clobber R1-R5/R14/R15 and use nothing),
    // each with the size of the first instruction that reads it if that is a MOV.B/W/L spill, else L.
    String asmParams(Function f, SimpleBlockModel bm) throws Exception {
        Map<Address, int[]> ud = new HashMap<>(); // use, def
        Map<Address, List<Address>> succ = new HashMap<>();
        CodeBlockIterator bi = bm.getCodeBlocksContaining(f.getBody(), monitor);
        while (bi.hasNext()) {
            CodeBlock b = bi.next();
            int use = 0, def = 0;
            for (Instruction in : currentProgram.getListing().getInstructions(b, true)) {
                use |= uses(in) & ~def;
                // ARM: a call reads what its callee reads at entry (previous pass), so a caller that passes its own
                // r0..r3 on unchanged (wrappers, tail calls) keeps them as parameters
                if (arm && isCall(in)) {
                    Function c = callee(in);
                    if (c != null) use |= tailLiveIn.getOrDefault(c, 0) & ~def;
                }
                def |= defs(in);
                if (isCall(in)) def |= clobber;
            }
            ud.put(b.getFirstStartAddress(), new int[]{use, def});
            List<Address> sl = new ArrayList<>();
            var di = b.getDestinations(monitor);
            while (di.hasNext()) {
                var d = di.next();
                if (d.getFlowType().isCall()) continue;
                Address a = d.getDestinationAddress();
                if (f.getBody().contains(a)) sl.add(a);
            }
            succ.put(b.getFirstStartAddress(), sl);
        }
        Map<Address, Integer> liveIn = new HashMap<>();
        boolean ch = true;
        for (int iter = 0; ch && iter < 200; iter++) {
            ch = false;
            for (Address a : ud.keySet()) {
                int lo = 0;
                for (Address s : succ.get(a)) {
                    CodeBlock[] sb = bm.getCodeBlocksContaining(s, monitor);
                    Address k = sb.length > 0 ? sb[0].getFirstStartAddress() : s;
                    lo |= liveIn.getOrDefault(k, 0);
                }
                int[] u = ud.get(a);
                int li = u[0] | (lo & ~u[1]);
                if (li != liveIn.getOrDefault(a, 0)) { liveIn.put(a, li); ch = true; }
            }
        }
        int m = liveIn.getOrDefault(f.getEntryPoint(), 0) & 0x1E;
        liveInMask.put(f, m);
        blockLiveIn.put(f, liveIn);
        blockSucc.put(f, succ);
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 4; i++) {
            if ((m & (1 << i)) == 0) continue;
            String sz = "L";
            Instruction in = getInstructionAt(f.getEntryPoint());
            for (int n = 0; in != null && n < 24; n++, in = in.getNext()) {
                if ((uses(in) & (1 << i)) != 0) {
                    String mn = in.getMnemonicString();
                    if (arm) {
                        int k = armUseSize(in, i);
                        if (k == 1) sz = "B"; else if (k == 2) sz = "W";
                    } else if (mn.startsWith("MOV.") && in.toString().contains("[SP]") && in.getNumOperands() == 2
                            && in.getDefaultOperandRepresentation(0).equals("R" + i))
                        sz = mn.substring(4);
                    break;
                }
                if ((defs(in) & (1 << i)) != 0) break;
            }
            if (sb.length() > 0) sb.append(",");
            sb.append(regName(i)).append(":").append(sz);
        }
        return sb.length() == 0 ? "-" : sb.toString();
    }
}
