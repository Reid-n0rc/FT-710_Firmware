// Report of missed function starts and undefined code fragments in an ARM image (T21e, issue #97 B7 + B8; written for
// DISPLAY, nothing in it is DISPLAY-specific except the default block name). Read-only unless "define" is given.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript DisplayGaps.java <starts.tsv> <fragments.tsv> [codeBlock [define]]
// starts.tsv: candidate function starts, one row per address, kinds:
//   call_inside       a CALL reference targets an address that is not a function entry (inside a body, or orphan code)
//   call_undefined    a CALL reference targets bytes that are not disassembled
//   after_return      the first code after an instruction with no fall-through (return, tail branch; skipping literal
//                     pools and padding) has no reference at all: dead code inside a body, or a start that was merged
//   after_return_undef  the same place is undefined, and it decodes as valid ARM code (then the undefined ARM functions
//                     that follow it in the same gap are listed too)
//   dead_code         like after_return_undef, but the code falls into another function's body: not a start
//   after_return_thumb  the same place after Thumb code (listed for review; the pseudo-disassembler decodes ARM only)
//   dataptr_inside    an aligned word outside instructions holds the address of an instruction that is not a function
//                     entry (task/vector/callback tables) and is in no function or follows a return
//   addr_taken        an instruction loads the address of undefined bytes that decode as an ARM function
//   tail_target       an unconditional `b` from one function lands inside another function's body, at code that its owner
//                     reaches only by a jump: a function analysis merged into the first function that tail-branched to it
//   jump_inside       any other jump from one function into another's body (shared tails in hand-written library code)
// fragments.tsv: every undefined run in the code block with at least one non-0xFF byte: start, length, non-0xFF bytes,
//   references to it (code and data words), what precedes it, a class (pad / ascii / ptrs / code / data / thumb) and the
//   first pseudo-disassembled instructions. "thumb" = within 0x100 B after Thumb code (armcc library), not classified.
// With a 4th argument "define" (run without -readOnly) every fragment that is not code or thumb is defined as data
// (string, pointers, dword or byte array) with an EOL comment "T21e B8: ...". Run it after FixFuncEntries with the
// reviewed starts, so that real code has become functions first.
// The last lines printed are the totals; the B7 test is "call_inside + call_undefined == 0".
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.app.util.PseudoDisassembler;
import ghidra.app.util.PseudoInstruction;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.address.AddressSetView;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;

public class DisplayGaps extends GhidraScript {
    MemoryBlock code;
    Listing listing;
    PseudoDisassembler pd;
    TreeMap<Address, String[]> starts = new TreeMap<>();   // addr -> {kind, detail}
    Map<Address, List<Address>> dataPtrs = new HashMap<>(); // target -> words that hold it

    boolean inCode(Address a) { return a != null && code.contains(a); }

    String fn(Address a) {
        Function f = getFunctionContaining(a);
        return f == null ? "-" : f.getName() + "@" + f.getEntryPoint();
    }

    void flag(Address a, String kind, String detail) {
        if (!starts.containsKey(a)) starts.put(a, new String[]{kind, detail});
    }

    boolean undefinedAt(Address a) { return getInstructionContaining(a) == null && getDataContaining(a) == null; }

    String pseudo(Address a, int n) {
        StringBuilder sb = new StringBuilder();
        Address p = a;
        for (int i = 0; i < n && inCode(p); i++) {
            try {
                PseudoInstruction pi = pd.disassemble(p);
                if (pi == null) { sb.append("<bad>"); break; }
                if (sb.length() > 0) sb.append(" | ");
                sb.append(pi.toString());
                if (pi.getFlowType().isTerminal() || (!pi.getFlowType().isConditional() && pi.getFlowType().isJump())) break;
                p = p.add(pi.getLength());
            } catch (Exception e) { sb.append(" <bad>"); break; }
        }
        return sb.toString();
    }

    boolean decodesAsCode(Address a) {
        try { return pd.isValidSubroutine(a, true); } catch (Exception e) { return false; }
    }

    /** Skip defined data (literal pools) and zero/0xFF padding words after a no-fall-through instruction. */
    Address skipPool(Address a) throws Exception {
        while (inCode(a)) {
            Data d = getDataContaining(a);
            if (d != null && getInstructionContaining(a) == null) { a = d.getMaxAddress().next(); continue; }
            if (undefinedAt(a) && a.getOffset() % 4 == 0 && inCode(a.add(3))) {
                int w = getInt(a);
                // padding, or a pool word that something reads (ldr rX,[pc,#..] reference)
                if (w == 0 || w == -1 || poolWord(a)) { a = a.add(4); continue; }
            }
            return a;
        }
        return null;
    }

    /** An undefined word that only instructions reference, and not as a flow target (ldr rX,[pc,#..]): a literal-pool entry. */
    boolean poolWord(Address a) {
        Reference[] rs = getReferencesTo(a);
        if (rs.length == 0) return false;
        for (Reference r : rs) if (r.getReferenceType().isFlow() || getInstructionAt(r.getFromAddress()) == null) return false;
        // an ldr reads a pool word (READ); a DATA reference from an instruction to a word that looks like an ARM
        // function start is an address being taken (ldr rX,=func): that is code, not pool
        for (Reference r : rs) if (!r.getReferenceType().isRead()) try { return !plausibleArmStart(a); } catch (Exception e) { return true; }
        return true;
    }

    boolean isThumb(Address a) {
        ghidra.program.model.lang.Register t = currentProgram.getRegister("TMode");
        if (t == null) return false;
        java.math.BigInteger v = currentProgram.getProgramContext().getValue(t, a, false);
        return v != null && v.signum() != 0;
    }

    /** A plausible first instruction of an ARM function: unconditional (cond AL), not a branch into the middle of code. */
    boolean plausibleArmStart(Address a) throws Exception {
        if (a.getOffset() % 4 != 0) return false;
        int w = getInt(a);
        return (w >>> 28) == 0xE;
    }

    /**
     * Flag the ARM function that starts in undefined bytes at n, then the ones that follow it in the same undefined run
     * (a chain of small dead helpers is found in one pass).
     */
    void undefChain(Address n, String after) throws Exception {
        for (int f = 0; f < 64 && n != null; f++) {
            // up to 3 leading words that cannot start an ARM function (conditional encodings: constants, pool words
            // nothing references by address) are skipped
            Address c = n;
            for (int k = 0; k < 3 && c != null && inCode(c) && undefinedAt(c) && !plausibleArmStart(c); k++) c = c.add(4);
            if (c == null || !inCode(c) || !undefinedAt(c) || !plausibleArmStart(c) || hasFlowRef(c) || !decodesAsCode(c)) return;
            // linear end of this one: the first unconditional instruction without fall-through
            // (beyond every forward branch target seen so far, so a body with a `b` over a pool is not split)
            Address p = c, end = null, reach = c;
            String merge = null;
            for (int i = 0; i < 512 && inCode(p) && undefinedAt(p); i++) {
                PseudoInstruction pi;
                try { pi = pd.disassemble(p); } catch (Exception e) { pi = null; }
                if (pi == null) return;
                Address nx = p.add(pi.getLength());
                if (pi.getFlowType().isJump() && !pi.getFlowType().isCall())
                    for (Address t : pi.getFlows()) {
                        if (t.compareTo(reach) > 0 && t.subtract(c) < 0x1000) reach = t;
                        if (merge == null) merge = intoBody(t);
                    }
                if (!pi.getFlowType().isConditional() && !pi.getFlowType().hasFallthrough() && nx.compareTo(reach) > 0) { end = nx; break; }
                p = nx;
                if (!undefinedAt(p) && p.compareTo(reach) <= 0) {   // skip a pool inside the body
                    Address q = skipPool(p);
                    if (q == null || q.equals(p)) return;
                    p = q;
                }
            }
            // only falling into a body makes it dead code; a jump into one is a tail branch (cross-jumping), see (3a)
            merge = null;
            if (end == null && p != null && !undefinedAt(p)) merge = intoBody(p);
            // dead code inside a function (jumped over, falls into the function's body again): not a start
            flag(c, merge != null ? "dead_code" : "after_return_undef", after + (c.equals(n) ? "" : "; skipped "
                    + (c.subtract(n) / 4) + " data word(s)") + (merge != null ? "; joins " + merge : "") + "; " + pseudo(c, 4));
            if (end == null) return;
            n = skipPool(end);
            after = "chained after " + c;
        }
    }

    /** "name@entry at a" when a is an existing instruction inside a function body but not its entry, else null. */
    String intoBody(Address a) {
        if (getInstructionAt(a) == null) return null;
        Function g = getFunctionContaining(a);
        if (g == null || g.getEntryPoint().equals(a)) return null;
        return g.getName() + "@" + g.getEntryPoint() + " at " + a;
    }

    boolean hasFlowRef(Address a) {
        for (Reference r : getReferencesTo(a)) if (r.getReferenceType().isFlow()) return true;
        return false;
    }

    int nonFF(Address s, long len) throws Exception {
        int n = 0;
        for (long i = 0; i < len; i++) if ((getByte(s.add(i)) & 0xff) != 0xff) n++;
        return n;
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        code = currentProgram.getMemory().getBlock(args.length > 2 ? args[2] : ".text");
        listing = currentProgram.getListing();
        pd = new PseudoDisassembler(currentProgram);
        long cs = code.getStart().getOffset(), ce = code.getEnd().getOffset();

        // data words that point into the code block (outside instructions)
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (!b.isInitialized()) continue;
            for (long o = (b.getStart().getOffset() + 3) & ~3L; o + 3 <= b.getEnd().getOffset(); o += 4) {
                Address w = toAddr(o);
                if (getInstructionContaining(w) != null) continue;
                long v = getInt(w) & 0xffffffffL;
                if (v < cs || v > ce) continue;
                dataPtrs.computeIfAbsent(toAddr(v & ~1L), k -> new ArrayList<>()).add(w);
            }
        }

        // (1) call targets
        int calls = 0;
        ReferenceIterator it = currentProgram.getReferenceManager().getReferenceIterator(code.getStart());
        while (it.hasNext()) {
            Reference r = it.next();
            if (!r.getReferenceType().isCall()) continue;
            calls++;
            Address t = r.getToAddress();
            if (!inCode(t) || getFunctionAt(t) != null) continue;
            if (getInstructionAt(t) == null) flag(t, "call_undefined", "called from " + r.getFromAddress() + " in " + fn(r.getFromAddress()));
            else flag(t, "call_inside", "called from " + r.getFromAddress() + "; inside " + fn(t));
        }

        // (2) code after a return / tail branch that nothing reaches
        for (Instruction ins : listing.getInstructions(code.getStart(), true)) {
            monitor.checkCancelled();
            if (!inCode(ins.getAddress())) break;
            if (ins.getFallThrough() != null || ins.getFlowType().isConditional()) continue;
            if (ins.getFlowType().isComputed() && ins.getFlowType().isJump()) continue;   // jump tables follow
            Address n = skipPool(ins.getMaxAddress().next());
            if (n == null || getFunctionAt(n) != null) continue;
            if (hasFlowRef(n) || getInstructionAt(n) != null && getReferencesTo(n).length > 0) continue;
            Instruction ni = getInstructionAt(n);
            if (ni != null) {
                String eol = getEOLComment(n);
                if (eol != null && eol.startsWith("T21e B8: dead code")) continue;   // disassembled by the define step
                flag(n, "after_return", "after " + ins.getAddress() + " " + ins + "; inside " + fn(n) + "; " + ni);
            } else if (undefinedAt(n)) {
                if (isThumb(ins.getAddress())) {
                    // the pseudo-disassembler decodes undefined bytes as ARM; Thumb gaps are listed for review only
                    flag(n, "after_return_thumb", "after Thumb " + ins.getAddress() + " " + ins + "; " + hex(n, 8));
                    continue;
                }
                undefChain(n, "after " + ins.getAddress() + " " + ins);
            }
        }

        // (3) data words pointing at an instruction that is not an entry, in no function (or merged after a return)
        for (Map.Entry<Address, List<Address>> e : dataPtrs.entrySet()) {
            Address t = e.getKey();
            if (getFunctionAt(t) != null || getInstructionAt(t) == null) continue;
            Function f = getFunctionContaining(t);
            if (f != null) {
                Instruction prev = getInstructionBefore(t);
                boolean afterRet = prev != null && prev.getFallThrough() == null && !hasFlowRef(t);
                if (!afterRet) continue;
            }
            flag(t, "dataptr_inside", "word at " + e.getValue().get(0) + (e.getValue().size() > 1 ? " (+" + (e.getValue().size() - 1) + ")" : "")
                    + "; inside " + fn(t));
        }

        // (3a) jumps from one function into the body of another (not at its entry): a shared tail-call target that is
        // no function yet, or code that a new entry claimed from its neighbour (then the entry is wrong)
        it = currentProgram.getReferenceManager().getReferenceIterator(code.getStart());
        while (it.hasNext()) {
            Reference r = it.next();
            if (!r.getReferenceType().isJump() || r.getReferenceType().isComputed()) continue;
            Address t = r.getToAddress();
            Function ff = getFunctionContaining(r.getFromAddress()), ft = getFunctionContaining(t);
            if (ff == null || ft == null || ff == ft || ft.getEntryPoint().equals(t)) continue;
            // a tail branch (unconditional b) to code that its owner reaches only by a jump (no fall-through into it)
            Instruction ji = getInstructionAt(r.getFromAddress()), before = getInstructionBefore(t);
            boolean tail = ji != null && !ji.getFlowType().isConditional() && ji.getFallThrough() == null
                    && (before == null || before.getFallThrough() == null || !before.getFallThrough().equals(t));
            flag(t, tail ? "tail_target" : "jump_inside","jump from " + r.getFromAddress() + " in " + fn(r.getFromAddress()) + " into " + fn(t));
        }

        // (3b) instructions that take the address of undefined bytes that decode as an ARM function (ldr rX,=func)
        it = currentProgram.getReferenceManager().getReferenceIterator(code.getStart());
        while (it.hasNext()) {
            Reference r = it.next();
            Address t = r.getToAddress();
            if (r.getReferenceType().isFlow() || r.getReferenceType().isRead() || !inCode(t)) continue;
            if (getInstructionAt(r.getFromAddress()) == null || !undefinedAt(t) || isThumb(r.getFromAddress())) continue;
            if (plausibleArmStart(t) && decodesAsCode(t))
                flag(t, "addr_taken", "address taken at " + r.getFromAddress() + " in " + fn(r.getFromAddress()) + "; " + pseudo(t, 4));
        }

        int[] counts = new int[10];
        String[] kinds = {"call_inside", "call_undefined", "after_return", "after_return_undef", "dataptr_inside", "after_return_thumb", "addr_taken", "jump_inside", "dead_code", "tail_target"};
        try (PrintWriter pw = new PrintWriter(args[0], "UTF-8")) {
            pw.println("address\tkind\tdetail");
            for (Map.Entry<Address, String[]> e : starts.entrySet()) {
                pw.println(e.getKey() + "\t" + e.getValue()[0] + "\t" + e.getValue()[1]);
                for (int i = 0; i < kinds.length; i++) if (kinds[i].equals(e.getValue()[0])) counts[i]++;
            }
        }

        // (4) undefined fragments
        AddressSetView undef = listing.getUndefinedRanges(new AddressSet(code.getStart(), code.getEnd()), true, monitor);
        int frags = 0, defined = 0, disassembledDead = 0; long fragBytes = 0, fragNonFF = 0;
        boolean define = args.length > 3 && args[3].equals("define");
        Map<String, long[]> byClass = new TreeMap<>();
        try (PrintWriter pw = args.length > 1 ? new PrintWriter(args[1], "UTF-8") : null) {
            if (pw != null) pw.println("start\tlength\tnonFF\trefs\tafter\tclass\tfirst");
            for (AddressRange r : undef) {
                Address s = r.getMinAddress();
                long len = r.getLength();
                int nf = nonFF(s, len);
                if (nf == 0) continue;
                StringBuilder refs = new StringBuilder();
                for (long i = 0; i < len; i++) {
                    Address a = s.add(i);
                    for (Reference x : getReferencesTo(a)) refs.append(x.getFromAddress()).append(x.getReferenceType().isFlow() ? "(flow) " : "(data) ");
                    List<Address> dp = dataPtrs.get(a);
                    if (dp != null) for (Address w : dp) refs.append(w).append("(word) ");
                }
                Instruction pi = getInstructionBefore(s);
                Data pdat = getDataBefore(s);
                String after;
                if (pi != null && pi.getMaxAddress().next().equals(s))
                    after = (pi.getFallThrough() == null ? "end:" : "code:") + pi;
                else if (pdat != null && pdat.getMaxAddress().next().equals(s)) after = "data:" + pdat.getDataType().getName();
                else after = "?";
                String cls;
                int zero = 0, print = 0;
                for (long i = 0; i < len; i++) {
                    int b = getByte(s.add(i)) & 0xff;
                    if (b == 0) zero++;
                    if (b >= 0x20 && b < 0x7f || b == 9 || b == 10 || b == 13) print++;
                }
                Instruction near = getInstructionBefore(s);
                boolean thumbZone = near != null && isThumb(near.getAddress()) && s.subtract(near.getAddress()) < 0x100;
                boolean asciiLike = len >= 4 && print + zero >= len * 0.9 && print >= 3 && print * 2 >= len;
                if (thumbZone && zero + (len - nf) != len && !asciiLike) cls = "thumb";   // Thumb library code/tables: listed, not defined
                else if (zero + (len - nf) == len) cls = "pad";
                else if (asciiLike) cls = "ascii";
                else if (len % 4 == 0 && s.getOffset() % 4 == 0 && allPtrs(s, len)) cls = "ptrs";
                else if (plausibleArmStart(s) && decodesAsCode(s)) cls = "code";
                else cls = "data";
                frags++; fragBytes += len; fragNonFF += nf;
                byClass.computeIfAbsent(cls, k -> new long[3]);
                byClass.get(cls)[0]++; byClass.get(cls)[1] += len; byClass.get(cls)[2] += nf;
                if (pw != null) pw.println(s + "\t" + len + "\t" + nf + "\t" + refs.toString().trim() + "\t" + after + "\t" + cls + "\t"
                        + (cls.equals("code") || cls.equals("data") ? pseudo(s, 4) : hex(s, Math.min(len, 16))));
                Address dead = null;
                for (Map.Entry<Address, String[]> e : starts.subMap(s, true, s.add(len - 1), true).entrySet())
                    if (e.getValue()[0].equals("dead_code")) { dead = e.getKey(); break; }
                if (define && dead != null) {
                    // dead code inside a function: disassemble it (no function), so it reads as code
                    new ghidra.app.cmd.disassemble.ArmDisassembleCommand(dead, new AddressSet(dead, s.add(len - 1)), false).applyTo(currentProgram, monitor);
                    setEOLComment(dead, "T21e B8: dead code (no reference; joins the function body around it)");
                    disassembledDead++;
                } else if (define && !cls.equals("code") && !cls.equals("thumb")) defined += defineData(s, len, cls, refs.length() > 0);
            }
        }
        if (define) println("DisplayGaps define: " + defined + " fragments defined as data, " + disassembledDead + " dead-code fragments disassembled");
        println("DisplayGaps: " + calls + " call references; starts: call_inside " + counts[0] + ", call_undefined " + counts[1]
                + ", after_return " + counts[2] + ", after_return_undef " + counts[3] + ", dataptr_inside " + counts[4] + ", after_return_thumb " + counts[5] + ", addr_taken " + counts[6] + ", jump_inside " + counts[7] + ", dead_code " + counts[8] + ", tail_target " + counts[9]);
        StringBuilder sb = new StringBuilder();
        for (Map.Entry<String, long[]> e : byClass.entrySet())
            sb.append(", ").append(e.getKey()).append(" ").append(e.getValue()[0]).append("/").append(e.getValue()[1]).append(" B/").append(e.getValue()[2]).append(" nonFF");
        println("DisplayGaps: fragments " + frags + ", " + fragBytes + " B, " + fragNonFF + " non-0xFF B" + sb);
        println("DisplayGaps: B7 test " + (counts[0] + counts[1] == 0 ? "PASS" : "FAIL") + " (call targets that are not function entries: " + (counts[0] + counts[1]) + ")");
    }

    /** B8: define a non-code fragment as data (string, pointers, dwords or bytes) with an EOL comment. */
    int defineData(Address s, long len, String cls, boolean referenced) {
        try {
            if (cls.equals("ascii") && (getByte(s.add(len - 1)) == 0 || len > 1)) {
                createAsciiString(s, (int) len);
            } else if (cls.equals("ptrs")) {
                for (long i = 0; i < len; i += 4) createData(s.add(i), ghidra.program.model.data.PointerDataType.dataType);
            } else if (s.getOffset() % 4 == 0 && len % 4 == 0) {
                if (len == 4) createData(s, ghidra.program.model.data.DWordDataType.dataType);
                else createData(s, new ghidra.program.model.data.ArrayDataType(ghidra.program.model.data.DWordDataType.dataType, (int) (len / 4), 4));
            } else if (len == 1) {
                createData(s, ghidra.program.model.data.ByteDataType.dataType);
            } else {
                createData(s, new ghidra.program.model.data.ArrayDataType(ghidra.program.model.data.ByteDataType.dataType, (int) len, 1));
            }
            setEOLComment(s, "T21e B8: " + (referenced ? "" : "unreferenced ") + cls + " fragment (" + len + " B)");
            return 1;
        } catch (Exception e) {
            printerr("DisplayGaps define " + s + ": " + e.getMessage());
            return 0;
        }
    }

    boolean allPtrs(Address s, long len) throws Exception {
        for (long i = 0; i < len; i += 4) {
            long v = getInt(s.add(i)) & 0xffffffffL;
            if (getMemoryBlock(toAddr(v & ~1L)) == null && v != 0) return false;
        }
        return true;
    }

    String hex(Address s, long n) throws Exception {
        StringBuilder sb = new StringBuilder();
        for (long i = 0; i < n; i++) sb.append(String.format("%02x", getByte(s.add(i)) & 0xff));
        return sb.toString();
    }
}
