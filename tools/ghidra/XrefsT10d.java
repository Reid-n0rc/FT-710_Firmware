// Print references to addresses or address ranges, with the containing function. (T10d helper)
// Usage: -postScript XrefsT10d.java <out.txt> <addr|lo-hi|name> ...
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import java.io.PrintWriter;

public class XrefsT10d extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] a = getScriptArgs();
        try (PrintWriter out = new PrintWriter(a[0], "UTF-8")) {
            for (int i = 1; i < a.length; i++) {
                String s = a[i];
                Address lo, hi;
                if (s.contains("-")) {
                    String[] p = s.split("-");
                    lo = toAddr(Long.parseLong(p[0].replace("0x", ""), 16));
                    hi = toAddr(Long.parseLong(p[1].replace("0x", ""), 16));
                } else if (s.matches("(0x)?[0-9a-fA-F]+")) {
                    lo = hi = toAddr(Long.parseLong(s.replace("0x", ""), 16));
                } else {
                    Function f = getGlobalFunctions(s).get(0);
                    lo = hi = f.getEntryPoint();
                }
                for (Address x = lo; ; x = x.add(1)) {
                    for (Reference r : getReferencesTo(x)) {
                        Function f = getFunctionContaining(r.getFromAddress());
                        out.printf("%s\t%s\t%s\t%s\n", x, r.getFromAddress(), r.getReferenceType(),
                                f == null ? "-" : f.getName() + "@" + f.getEntryPoint());
                    }
                    if (x.compareTo(hi) >= 0) break;
                }
            }
        }
    }
}
