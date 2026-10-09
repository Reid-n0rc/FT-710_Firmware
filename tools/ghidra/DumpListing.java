// Dump the disassembly listing (and optionally the decompile) of an address or function to a file.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript DumpListing.java <out.txt> <addr|name>[:<nInsns>] ...
// Each spec: a hex address (0xFFF8FBDB) or a function/label name, optional :N instruction count
// (default: the whole function if one starts there, else 64 instructions). Instructions that are
// not yet disassembled are disassembled in the read-only session (not saved).
// With "decomp" as a spec, every following function is also decompiled.
// @category FT710
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.symbol.Reference;

import java.io.PrintWriter;
import java.util.List;

public class DumpListing extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        boolean decomp = false;
        DecompInterface ifc = null;
        try (PrintWriter out = new PrintWriter(args[0], "UTF-8")) {
            for (int i = 1; i < args.length; i++) {
                String spec = args[i];
                if (spec.equals("decomp")) {
                    decomp = true;
                    ifc = new DecompInterface();
                    ifc.openProgram(currentProgram);
                    continue;
                }
                int n = -1;
                int c = spec.lastIndexOf(':');
                if (c > 0) {
                    n = Integer.parseInt(spec.substring(c + 1));
                    spec = spec.substring(0, c);
                }
                Address a;
                if (spec.startsWith("0x")) {
                    a = toAddr(Long.decode(spec));
                } else {
                    List<Function> fs = getGlobalFunctions(spec);
                    if (fs.isEmpty()) {
                        out.println("## not found: " + spec);
                        continue;
                    }
                    a = fs.get(0).getEntryPoint();
                }
                Function f = getFunctionAt(a);
                out.println("## " + spec + " @ " + a + (f != null ? " func " + f.getName() : ""));
                if (getInstructionAt(a) == null) {
                    disassemble(a);
                }
                Instruction ins = getInstructionAt(a);
                int lim = n > 0 ? n : (f != null ? 100000 : 64);
                for (int k = 0; ins != null && k < lim; k++) {
                    if (n <= 0 && f != null && !f.getBody().contains(ins.getAddress())) break;
                    StringBuilder sb = new StringBuilder();
                    sb.append(ins.getAddress()).append("  ").append(ins.toString());
                    for (Reference r : ins.getReferencesFrom()) {
                        if (r.getReferenceType().isFlow() || r.getReferenceType().isData()) {
                            sb.append("  ; -> ").append(r.getToAddress());
                            var s = getSymbolAt(r.getToAddress());
                            if (s != null) sb.append(" ").append(s.getName());
                        }
                    }
                    out.println(sb);
                    ins = ins.getNext();
                }
                if (decomp && f != null) {
                    DecompileResults r = ifc.decompileFunction(f, 60, monitor);
                    out.println(r.decompileCompleted() ? r.getDecompiledFunction().getC()
                            : "// decompile failed: " + r.getErrorMessage());
                }
                out.println();
            }
        }
        if (ifc != null) ifc.dispose();
    }
}
