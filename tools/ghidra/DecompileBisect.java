// Find the instruction that makes the decompiler fail on a function (issue #97, B9).
// Headless (read-only, nothing is saved):
//   tools/ghidra-headless.sh <projdir> <proj> -process <prog> -noanalysis -readOnly -scriptPath tools/ghidra \
//     -postScript DecompileBisect.java <out.txt> <func addr>
// 1. Decompiles the function as it is and records the result.
// 2. If it fails: walks the function's instructions from the last to the first and overwrites each one with `retw.n`
//    (1d f0), so the flow ends there (the patched region only grows, so no undo is needed); decompiles after each step.
//    Clearing the listing is not enough: the decompiler re-decodes undefined bytes itself. The first instruction whose
//    replacement makes the decompile succeed is the culprit candidate.
// 3. Confirms: restores the original bytes, re-disassembles from the entry, overwrites only the candidate with `nop`
//    (3 bytes) or `nop.n` (2 bytes), keeping the flow, and decompiles again.
// Writes every probe and the decompiler's error messages to <out.txt>.
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;

import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.List;

public class DecompileBisect extends GhidraScript {
    DecompInterface ifc;
    PrintWriter out;

    String decomp(Function f) {
        DecompileResults r = ifc.decompileFunction(f, 60, monitor);
        if (r.decompileCompleted()) return null;
        String e = r.getErrorMessage();
        if (!ifc.getLastMessage().isEmpty()) e += " | last message: " + ifc.getLastMessage();
        // a dead process must be restarted
        ifc.dispose();
        ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        return e == null ? "?" : e.replace('\n', ' ');
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        out = new PrintWriter(args[0], "UTF-8");
        Address ea = toAddr(Long.decode(args[1]));
        Function f = getFunctionAt(ea);
        ifc = new DecompInterface();
        ifc.openProgram(currentProgram);
        List<Instruction> ins = new ArrayList<>();
        for (Instruction i : currentProgram.getListing().getInstructions(f.getBody(), true)) ins.add(i);
        Address end = f.getBody().getMaxAddress();
        String e0 = decomp(f);
        out.println("function " + f.getName() + " @ " + ea + ", " + ins.size() + " instructions, body to " + end);
        out.println("as is: " + (e0 == null ? "OK" : "FAILED: " + e0));
        if (e0 == null) { out.close(); return; }
        Address ca = null;
        String txt = "";
        int len = 0;
        int blen = (int) (end.subtract(ea) + 1);
        byte[] orig = getBytes(ea, blen);
        for (int k = ins.size() - 1; k > 0; k--) {
            Instruction i = ins.get(k);
            Address ia = i.getMinAddress();
            String it = i.toString();
            int il = i.getLength();
            clearListing(ia, end);
            setBytes(ia, new byte[] {0x1d, (byte) 0xf0});
            disassemble(ia);
            String e = decomp(f);
            out.println("retw.n at " + ia + " (" + it + "): " + (e == null ? "OK" : "FAILED: " + e));
            out.flush();
            if (e == null) { ca = ia; txt = it; len = il; break; }
        }
        if (ca != null) {
            clearListing(ea, end);
            setBytes(ea, orig);
            disassemble(ea);
            String eAll = decomp(f);
            out.println("original bytes restored: " + (eAll == null ? "OK" : "FAILED: " + eAll));
            clearListing(ca, ca.add(len - 1));
            setBytes(ca, len >= 3 ? new byte[] {(byte) 0xf0, 0x20, 0x00} : new byte[] {0x3d, (byte) 0xf0});
            disassemble(ca);
            String e1 = decomp(f);
            out.println("candidate " + ca + " (" + txt + "), replaced alone by nop: " + (e1 == null ? "OK -> culprit" : "FAILED: " + e1));
        }
        out.close();
        ifc.dispose();
    }
}
