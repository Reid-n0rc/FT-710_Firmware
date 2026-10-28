// Print every reference to the given addresses (functions or data), with the containing function.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript T10eXrefs.java <out.tsv> 0xADDR[:0xEND] ...
// A range 0xA:0xB lists references to every address in [A,B]. Output TSV: target, from, type, function entry, name.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;

import java.io.PrintWriter;

public class T10eXrefs extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] a = getScriptArgs();
        try (PrintWriter w = new PrintWriter(a[0])) {
            for (int i = 1; i < a.length; i++) {
                String[] p = a[i].split(":");
                long lo = Long.decode(p[0]);
                long hi = p.length > 1 ? Long.decode(p[1]) : lo;
                for (long v = lo; v <= hi; v++) {
                    Address t = toAddr(v);
                    for (Reference r : getReferencesTo(t)) {
                        Address f = r.getFromAddress();
                        Function fn = getFunctionContaining(f);
                        w.printf("%x\t%s\t%s\t%s\t%s%n", v, f, r.getReferenceType(),
                                fn == null ? "-" : fn.getEntryPoint().toString(),
                                fn == null ? "-" : fn.getName());
                    }
                }
            }
        }
    }
}
