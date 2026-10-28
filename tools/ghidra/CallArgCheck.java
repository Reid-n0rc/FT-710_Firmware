// T21d (#97 B3): compare every call site's argument/return registers in the disassembly with what the decompiler shows.
// Headless usage (from the repo root, read-only):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript CallArgCheck.java <mismatch.tsv> [<protos.tsv>]
// CC-RX calling convention: arguments in R1..R4, return in R1 (64-bit in R1:R2), R1-R5/R14/R15 caller-saved.
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
        if (mn.equals("PUSHM")) return rangeMask(in);
        if (mn.equals("POPM") || mn.equals("RTSD")) return 0;
        return mask(in.getInputObjects());
    }

    int defs(Instruction in) {
        String mn = in.getMnemonicString();
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
            int u = uses(in) & ~written & 0x6;
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
        for (int i = 0; i < 16; i++) R[i] = currentProgram.getRegister("R" + i);
        clobber = (1 << 1) | (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5) | (1 << 14) | (1 << 15);
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
        int sites = 0, dropped = 0, lost = 0, wide = 0, droppedSig = 0, lostSig = 0, wideSig = 0, failed = 0;
        Set<Function> dropFns = new HashSet<>(), lostFns = new HashSet<>();

        List<Function> funcs = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true))
            if (!f.isExternal() && !f.isThunk()) funcs.add(f);
        Map<Function, String> asmP = new HashMap<>();
        for (Function f : funcs) asmP.put(f, asmParams(f, bm));
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
                int[] s = st.computeIfAbsent(c, k -> new int[7]);
                s[0]++;
                if ((ar & 2) != 0) s[1]++;
                if ((ar & 6) == 6) s[2]++;
                s[3] = Math.max(s[3], aa);
                if ((ar & 2) != 0) s[lastRetSize == 1 ? 4 : lastRetSize == 2 ? 5 : 6]++;
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
                            + ((ar & 2) != 0 ? "R1" : "") + ((ar & 4) != 0 ? "R2" : "") + "\t" + coutSize + "\t"
                            + (sig ? "sig" : "-"));
            }
        }
        ifc.dispose();
        try (PrintWriter out = new PrintWriter(args[0], "UTF-8")) {
            out.println("# CallArgCheck: sites=" + sites + " dropped_arg=" + dropped + " (callee with signature: " + droppedSig
                    + ") lost_ret=" + lost + " (" + lostSig + ") wide_ret=" + wide + " (" + wideSig + ") callees: dropped="
                    + dropFns.size() + " lost=" + lostFns.size() + " decompile_failed=" + failed);
            out.println("kind\tsite\tcaller\tcaller_name\tcallee\tcallee_name\tasm_args\tc_args\tasm_ret_read\tc_ret_size\tcallee_sig");
            for (String s : rows) out.println(s);
        }
        println("CallArgCheck: sites=" + sites + " dropped_arg=" + dropped + " (sig " + droppedSig + ") lost_ret=" + lost
                + " (sig " + lostSig + ") wide_ret=" + wide + " (sig " + wideSig + ") callees dropped=" + dropFns.size()
                + " lost=" + lostFns.size() + " failed=" + failed);

        if (args.length > 1) {
            try (PrintWriter out = new PrintWriter(args[1], "UTF-8")) {
                out.println("entry\tname\tsig_source\tasm_params\tsites\tsites_read_R1\tsites_read_R1R2\tmax_site_args\tc_proto\tentry_insn\tret_use_B_W_L\tret_epilogue");
                for (Function f : funcs) {
                    int[] s = st.getOrDefault(f, new int[7]);
                    Instruction e = getInstructionAt(f.getEntryPoint());
                    out.println(f.getEntryPoint() + "\t" + f.getName() + "\t" + f.getSignatureSource() + "\t"
                            + asmP.get(f) + "\t" + s[0] + "\t" + s[1] + "\t" + s[2] + "\t" + s[3] + "\t"
                            + cproto.getOrDefault(f, "?") + "\t" + (e == null ? "-" : e.toString()) + "\t" + s[4] + "/" + s[5] + "/" + s[6] + "\t" + retEpilogue(f));
                }
            }
        }
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
        StringBuilder sb = new StringBuilder();
        for (int i = 1; i <= 4; i++) {
            if ((m & (1 << i)) == 0) continue;
            String sz = "L";
            Instruction in = getInstructionAt(f.getEntryPoint());
            for (int n = 0; in != null && n < 24; n++, in = in.getNext()) {
                if ((uses(in) & (1 << i)) != 0) {
                    String mn = in.getMnemonicString();
                    if (mn.startsWith("MOV.") && in.toString().contains("[SP]") && in.getNumOperands() == 2
                            && in.getDefaultOperandRepresentation(0).equals("R" + i))
                        sz = mn.substring(4);
                    break;
                }
                if ((defs(in) & (1 << i)) != 0) break;
            }
            if (sb.length() > 0) sb.append(",");
            sb.append("R").append(i).append(":").append(sz);
        }
        return sb.length() == 0 ? "-" : sb.toString();
    }
}
