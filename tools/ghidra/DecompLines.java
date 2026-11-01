// Print the decompiled C of some functions with the instruction address of each line's statement (T23i), to find the
// address for a row of tools/ghidra/comments_<image>.tsv: a PRE comment at that address prints above that line.
// Headless usage (from the repo root; read-only):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript DecompLines.java <out.txt> <function name or entry address> ...
// Each output line is "<address>  <C line>"; the address is the statement's root p-code op (blank for lines without
// a statement, such as braces and declarations). Lines of a statement that wraps carry the address on the first line.
// @category FT710
import ghidra.app.decompiler.*;
import ghidra.app.decompiler.component.DecompilerUtils;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.pcode.PcodeOp;

import java.io.PrintWriter;
import java.util.List;

public class DecompLines extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        DecompInterface ifc = new DecompInterface();
        DecompileOptions opts = new DecompileOptions();
        opts.grabFromProgram(currentProgram);
        ifc.setOptions(opts);
        ifc.openProgram(currentProgram);
        try (PrintWriter w = new PrintWriter(args[0], "UTF-8")) {
            for (int i = 1; i < args.length; i++) {
                Function f = null;
                for (Function g : currentProgram.getFunctionManager().getFunctions(true)) {
                    if (g.getName().equals(args[i])) { f = g; break; }
                }
                if (f == null) {
                    try { f = getFunctionAt(toAddr(Long.parseLong(args[i].replaceFirst("^0x", ""), 16))); } catch (Exception e) { }
                }
                if (f == null) { w.println("// no function " + args[i]); continue; }
                DecompileResults r = ifc.decompileFunction(f, 60, monitor);
                w.println("// ===== " + f.getName() + " @ " + f.getEntryPoint());
                if (r == null || r.getCCodeMarkup() == null) { w.println("// decompile failed"); continue; }
                List<ClangLine> lines = DecompilerUtils.toLines(r.getCCodeMarkup());
                for (ClangLine l : lines) {
                    Address at = null;
                    StringBuilder sb = new StringBuilder();
                    for (int k = 0; k < l.getIndent(); k++) sb.append(' ');
                    for (ClangToken t : l.getAllTokens()) {
                        sb.append(t.getText());
                        if (at == null) {
                            ClangNode p = t.Parent();
                            while (p != null && !(p instanceof ClangStatement)) p = p.Parent();
                            if (p != null) {
                                PcodeOp op = ((ClangStatement) p).getPcodeOp();
                                if (op != null) at = op.getSeqnum().getTarget();
                            }
                        }
                    }
                    w.printf("%-9s %s%n", at == null ? "" : at.toString(), sb);
                }
            }
        }
        ifc.dispose();
    }
}
