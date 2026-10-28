// Prints the references to each address given on the command line (hex, with or without 0x), with the
// containing function of every referencing instruction/data. Read-only helper (T11c).
// Usage: -postScript XrefsList.java 2010dcbc 2015f55c ...   (or one argument "@file" with one address per line)
//@category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.Reference;
import java.nio.file.*;
import java.util.*;

public class XrefsList extends GhidraScript {
    @Override
    public void run() throws Exception {
        List<String> args = new ArrayList<>(Arrays.asList(getScriptArgs()));
        if (args.size() == 1 && args.get(0).startsWith("@")) {
            args = Files.readAllLines(Paths.get(args.get(0).substring(1)));
        }
        for (String a : args) {
            a = a.trim();
            if (a.isEmpty() || a.startsWith("#")) continue;
            Address addr = toAddr(Long.parseUnsignedLong(a.replaceFirst("^0x", ""), 16));
            Function tf = getFunctionAt(addr);
            println("== " + addr + (tf != null ? " " + tf.getName() : ""));
            for (Reference r : getReferencesTo(addr)) {
                Address from = r.getFromAddress();
                Function f = getFunctionContaining(from);
                println("   " + from + " " + r.getReferenceType() + " in " + (f != null ? f.getName() + "@" + f.getEntryPoint() : "-"));
            }
        }
    }
}
