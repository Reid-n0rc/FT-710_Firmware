// Dump the FT-710 MAIN CAT command dispatch: mnemonic table + BRA.L switch table -> per-command handlers.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript CatDispatch.java <out.tsv> \
//     <mnemTable> <count> <switchTable> <braAddr> [<mnemTable2> <count2> <dispatchFunc2>]
// For MAIN V01-12: 0xFFF805EC 104 0xFFF8F014 0xFFFA3B8A 0xFFF806BC 10 0xFFFA3A2A
//
// Primary table: entry i is the 2-char mnemonic at mnemTable+2*i; the switch (in the dispatcher)
// does `MOV.W [Ri,table],R14 ; BRA.L R14`, so case i = braAddr + (int16)table[i].
// For each case the script walks instructions until the next case start (or an RTS/RTSD that
// is not followed by more code of the same case) and records, in order:
//   "len<op>N" for `CMP #N,R1` + conditional branch after a parameter-length load, and each BSR/JSR target,
// producing e.g. "len==3:FUN_a | len>8:FUN_b". <op> is the condition under which the call runs: the branch
// condition when the call lies at or after the branch target (taken path), else its negation (fall-through
// path); e.g. `CMP #8,R1 ; BGT call` -> "len>8" (T20 fix: this used to print "len==8" for every test).
// Compound tests (the compiler computes a 0/1 flag, then `CMP #0,R1 ; BEQ error`) are rebuilt from the compares
// that set the flag: equality chains as "len==10||len==12", range checks (`CMP #a ; BLT` + `CMP #b ; BGT`) as
// "len>=a&&len<=b"; anything else prints "len==0" (read the case code).
// Secondary table entries are dispatched by compare chain in dispatchFunc2 (CMP #i,R1 ; BEQ x),
// which are listed the same way.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;
import java.util.TreeSet;

public class CatDispatch extends GhidraScript {

    private String mnem(long tab, int i) throws Exception {
        byte[] b = new byte[2];
        currentProgram.getMemory().getBytes(toAddr(tab + 2L * i), b);
        return new String(b, "US-ASCII");
    }

    private String fname(Address a) {
        Function f = getFunctionAt(a);
        return f != null ? f.getName() : ("LAB_" + a);
    }

    // RX conditional branch after `CMP #N,Rd` (flags of Rd - N) -> the relation "Rd <op> N" under which it is taken.
    private static String branchOp(String b) {
        switch (b) {
            case "BEQ": case "BZ": return "==";
            case "BNE": case "BNZ": return "!=";
            case "BGT": case "BGTU": return ">";
            case "BLE": case "BLEU": return "<=";
            case "BGE": case "BGEU": case "BC": return ">=";
            case "BLT": case "BLTU": case "BNC": return "<";
            default: return null;
        }
    }

    // Rebuild the condition of a compound 0/1 flag from the compares that computed it.
    private static String compound(List<String[]> inner) {
        boolean eq = true;
        for (String[] c : inner) eq &= c[1].equals("==") || c[1].equals("!=");
        if (eq) {
            StringBuilder b = new StringBuilder();
            for (String[] c : inner) b.append(b.length() > 0 ? "||" : "").append("len==").append(c[0]);
            return b.toString();
        }
        if (inner.size() == 2 && inner.get(0)[1].equals("<") && inner.get(1)[1].equals(">")) {
            return "len>=" + inner.get(0)[0] + "&&len<=" + inner.get(1)[0];
        }
        return "len==0";
    }

    private static String negate(String op) {
        switch (op) {
            case "==": return "!=";
            case "!=": return "==";
            case ">": return "<=";
            case "<=": return ">";
            case ">=": return "<";
            default: return ">=";
        }
    }

    // Walk one case body, stopping at 'stop' (exclusive) or after the last return.
    private String walk(Address start, Address stop, int maxIns) {
        StringBuilder sb = new StringBuilder();
        Instruction ins = getInstructionAt(start);
        if (ins == null) {
            disassemble(start);
            ins = getInstructionAt(start);
        }
        String pendingLen = null;   // N of the last CMP #N
        String pendingOp = null;    // condition of the conditional branch that followed it
        Address pendingTgt = null;  // that branch's target
        List<String[]> inner = new ArrayList<>();  // earlier {N, op} compares since the last call (compound tests)
        for (int k = 0; ins != null && k < maxIns; k++) {
            if (stop != null && ins.getAddress().compareTo(stop) >= 0) break;
            String mn = ins.getMnemonicString().toUpperCase();
            String base = mn.contains(".") ? mn.substring(0, mn.indexOf('.')) : mn;
            if (mn.startsWith("CMP") && ins.getNumOperands() == 2) {
                Object[] o0 = ins.getOpObjects(0);
                if (o0.length == 1 && o0[0] instanceof Scalar) {
                    if (pendingLen != null && pendingOp != null && !pendingLen.equals("0")) {
                        inner.add(new String[] {pendingLen, pendingOp});
                    }
                    pendingLen = Long.toString(((Scalar) o0[0]).getUnsignedValue());
                    pendingOp = null;
                    pendingTgt = null;
                }
            } else if (pendingLen != null && pendingOp == null && branchOp(base) != null) {
                Address[] fl = ins.getFlows();
                pendingOp = branchOp(base);
                pendingTgt = fl.length > 0 ? fl[0] : null;
            } else if (mn.startsWith("BSR") || mn.startsWith("JSR")) {
                for (Reference r : ins.getReferencesFrom()) {
                    if (r.getReferenceType().isCall()) {
                        if (sb.length() > 0) sb.append(" | ");
                        if (pendingLen != null && pendingLen.equals("0") && !inner.isEmpty()) {
                            sb.append(compound(inner)).append(':');
                        } else if (pendingLen != null) {
                            String op;
                            if (pendingOp == null || pendingTgt == null) {
                                op = "==";  // no conditional branch seen: keep the old notation
                            } else if (ins.getAddress().compareTo(pendingTgt) >= 0) {
                                op = pendingOp;           // call on the taken path
                            } else {
                                op = negate(pendingOp);   // call on the fall-through path
                            }
                            sb.append("len").append(op).append(pendingLen).append(':');
                        }
                        sb.append(fname(r.getToAddress())).append('@').append(r.getToAddress());
                        pendingLen = null;
                        pendingOp = null;
                        pendingTgt = null;
                        inner.clear();
                    }
                }
            } else if ((mn.startsWith("BRA") || mn.startsWith("RTS")) && stop == null) {
                // compare-chain targets end at a return or an unconditional branch to the common exit
                break;
            }
            ins = ins.getNext();
        }
        return sb.toString();
    }

    @Override
    protected void run() throws Exception {
        String[] a = getScriptArgs();
        long tab = Long.decode(a[1]);
        int n = Integer.parseInt(a[2]);
        long sw = Long.decode(a[3]);
        long bra = Long.decode(a[4]);
        List<Address> cases = new ArrayList<>();
        TreeSet<Address> starts = new TreeSet<>();
        for (int i = 0; i < n; i++) {
            short off = currentProgram.getMemory().getShort(toAddr(sw + 2L * i));
            Address c = toAddr(bra + off);
            cases.add(c);
            starts.add(c);
        }
        Function disp = getFunctionContaining(toAddr(bra));
        Address fend = disp != null ? disp.getBody().getMaxAddress().add(1) : null;
        try (PrintWriter out = new PrintWriter(a[0], "UTF-8")) {
            out.println("table\tindex\tmnemonic\tcase_addr\thandlers (len<op>N: the case calls the handler when the total command length incl. mnemonic and ';' satisfies <op> (==, !=, >, <=, >=, <) N; a||b / a&&b = compound test rebuilt from the flag's compares, len==0 = compound test not decoded, read the case code; empty = switch default -> error reply)");
            for (int i = 0; i < n; i++) {
                Address c = cases.get(i);
                Address next = starts.higher(c);
                if (next == null) next = fend;
                out.println("primary\t" + i + "\t" + mnem(tab, i) + "\t" + c + "\t" + walk(c, next, 400));
            }
            if (a.length >= 8) {
                long tab2 = Long.decode(a[5]);
                int n2 = Integer.parseInt(a[6]);
                Function f2 = getFunctionAt(toAddr(Long.decode(a[7])));
                // collect "CMP #i,R1 ; BEQ target" pairs from the compare chain
                Instruction ins = getInstructionAt(f2.getEntryPoint());
                long lastImm = -1;
                java.util.Map<Long, Address> tgt = new java.util.HashMap<>();
                for (int k = 0; ins != null && k < 60; k++) {
                    String mn = ins.getMnemonicString().toUpperCase();
                    if (mn.startsWith("CMP")) {
                        Object[] o0 = ins.getOpObjects(0);
                        if (o0.length == 1 && o0[0] instanceof Scalar) lastImm = ((Scalar) o0[0]).getUnsignedValue();
                    } else if ((mn.startsWith("BEQ") || mn.startsWith("BNE")) && lastImm >= 0) {
                        Address t = ins.getFlows().length > 0 ? ins.getFlows()[0] : null;
                        if (mn.startsWith("BEQ")) {
                            tgt.put(lastImm, t);
                        } else {
                            tgt.put(lastImm, ins.getFallThrough());
                            break; // the chain ends with CMP #k ; BNE exit
                        }
                    }
                    ins = ins.getNext();
                }
                TreeSet<Address> st2 = new TreeSet<>(tgt.values());
                Address f2end = f2.getBody().getMaxAddress().add(1);
                for (int i = 0; i < n2; i++) {
                    Address t = tgt.get((long) i);
                    Address nx = t == null ? null : st2.higher(t);
                    if (nx == null) nx = f2end;
                    out.println("secondary\t" + i + "\t" + mnem(tab2, i) + "\t" + (t == null ? "-" : t.toString())
                            + "\t" + (t == null ? (i == 0 ? "special-cased by caller (FUN_fffa36f2)" : "no case")
                                    : walk(t, nx, 400)));
                }
            }
        }
        println("CatDispatch: wrote " + a[0]);
    }
}
