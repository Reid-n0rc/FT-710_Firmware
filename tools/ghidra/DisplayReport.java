// Read-only analysis report for an FT-710 image (written for DISPLAY, T06; generic enough for others).
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin \
//     -noanalysis -readOnly -scriptPath tools/ghidra -postScript DisplayReport.java <outdir>
// Writes into <outdir>:
//   blocks.tsv       memory blocks (name, start, end, flags)
//   strings.tsv      every defined string with the functions that reference it
//   io_refs.tsv      references into volatile blocks, grouped by 0x100-byte page, with referencing functions
// and prints function counts per block, plus code found in non-executable blocks.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;
import ghidra.program.model.symbol.ReferenceIterator;

import java.io.File;
import java.io.PrintWriter;
import java.util.Map;
import java.util.TreeMap;
import java.util.TreeSet;

public class DisplayReport extends GhidraScript {
    @Override
    protected void run() throws Exception {
        File out = new File(getScriptArgs().length > 0 ? getScriptArgs()[0] : "report");
        out.mkdirs();
        try (PrintWriter w = new PrintWriter(new File(out, "blocks.tsv"), "UTF-8")) {
            w.println("name\tstart\tend\tsize\tinit\tperm\tvolatile");
            for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
                w.println(b.getName() + "\t" + b.getStart() + "\t" + b.getEnd() + "\t" + b.getSize() + "\t"
                        + b.isInitialized() + "\t" + (b.isRead() ? "r" : "-") + (b.isWrite() ? "w" : "-")
                        + (b.isExecute() ? "x" : "-") + "\t" + b.isVolatile());
            }
        }
        Map<String, Integer> perBlock = new TreeMap<>();
        int total = 0;
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            MemoryBlock b = getMemoryBlock(f.getEntryPoint());
            String n = b == null ? "?" : b.getName();
            perBlock.merge(n, 1, Integer::sum);
            total++;
        }
        println("functions total: " + total + " per block: " + perBlock);
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (b.isExecute() || !b.isInitialized()) continue;
            int n = 0;
            Instruction first = null;
            for (Instruction i : currentProgram.getListing().getInstructions(b.getStart(), true)) {
                if (i.getAddress().compareTo(b.getEnd()) > 0) break;
                if (first == null) first = i;
                n++;
            }
            println("instructions in non-exec block " + b.getName() + ": " + n
                    + (first != null ? " first at " + first.getAddress() : ""));
        }
        int strs = 0;
        try (PrintWriter w = new PrintWriter(new File(out, "strings.tsv"), "UTF-8")) {
            w.println("addr\tstring\tfunctions");
            for (Data d : currentProgram.getListing().getDefinedData(true)) {
                if (!d.hasStringValue()) continue;
                TreeSet<String> fns = new TreeSet<>();
                for (Reference r : getReferencesTo(d.getAddress())) {
                    Function f = getFunctionContaining(r.getFromAddress());
                    fns.add(f != null ? f.getName() + "@" + f.getEntryPoint() : "data@" + r.getFromAddress());
                }
                String s = String.valueOf(d.getValue()).replace("\t", "\\t").replace("\n", "\\n").replace("\r", "\\r");
                w.println(d.getAddress() + "\t" + s + "\t" + String.join(",", fns));
                strs++;
            }
        }
        println("defined strings: " + strs);
        Map<Long, TreeSet<String>> io = new TreeMap<>();
        for (MemoryBlock b : currentProgram.getMemory().getBlocks()) {
            if (!b.isVolatile()) continue;
            for (Address a : currentProgram.getReferenceManager().getReferenceDestinationIterator(
                    new ghidra.program.model.address.AddressSet(b.getStart(), b.getEnd()), true)) {
                long page = a.getOffset() & ~0xffL;
                TreeSet<String> s = io.computeIfAbsent(page, k -> new TreeSet<>());
                ReferenceIterator it = currentProgram.getReferenceManager().getReferencesTo(a);
                while (it.hasNext()) {
                    Function f = getFunctionContaining(it.next().getFromAddress());
                    if (f != null) s.add(f.getName());
                }
            }
        }
        try (PrintWriter w = new PrintWriter(new File(out, "io_refs.tsv"), "UTF-8")) {
            w.println("page\tnfuncs\tfunctions");
            for (Map.Entry<Long, TreeSet<String>> e : io.entrySet()) {
                String fl = String.join(",", e.getValue());
                if (fl.length() > 400) fl = fl.substring(0, 400) + "...";
                w.println(String.format("%08X", e.getKey()) + "\t" + e.getValue().size() + "\t" + fl);
            }
        }
        println("io pages referenced: " + io.size());
    }
}
