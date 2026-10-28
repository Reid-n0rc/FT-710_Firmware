// Export the undefined byte ranges of every initialized executable block as TSV (T22d, #104), for classification by
// tools/undefined_classify.py. "Undefined" is the same set ExportDecomp.java counts for undefined_nonff_bytes:
// block bytes that are neither an instruction nor defined data.
// Headless usage (from the repo root; works with -readOnly):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript UndefinedRanges.java <out.tsv>
// Columns: block  start  end(inclusive)  len  nonff  refs_in  function  prev  next
//   nonff     bytes in the range that are not 0xFF (ranges with nonff = 0 are left out)
//   refs_in   Ghidra references to any address in the range (shown for context; the classifier does not use it)
//   function  entry of the function whose body contains the range start, or "-"
//   prev/next what the listing has right before / after the range: "I" instruction, "D:<datatype>" data, "-" none
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressRange;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Data;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.ReferenceManager;

import java.io.PrintWriter;

public class UndefinedRanges extends GhidraScript {
    private String kind(CodeUnit cu) {
        if (cu == null) return "-";
        if (cu instanceof Instruction) return "I";
        Data d = (Data) cu;
        if (!d.isDefined()) return "-";
        return "D:" + d.getDataType().getName().replaceAll("\\s", "_");
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        if (args.length < 1) throw new IllegalArgumentException("usage: UndefinedRanges.java <out.tsv>");
        Listing lst = currentProgram.getListing();
        ReferenceManager rm = currentProgram.getReferenceManager();
        long total = 0, nranges = 0;
        try (PrintWriter w = new PrintWriter(args[0], "UTF-8")) {
            w.println("block\tstart\tend\tlen\tnonff\trefs_in\tfunction\tprev\tnext");
            for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
                if (!blk.isInitialized() || !blk.isExecute()) continue;
                AddressSet und = new AddressSet(blk.getStart(), blk.getEnd());
                for (Instruction ins : lst.getInstructions(blk.getStart(), true)) {
                    if (ins.getMinAddress().compareTo(blk.getEnd()) > 0) break;
                    und.delete(ins.getMinAddress(), ins.getMaxAddress());
                }
                for (Data d : lst.getDefinedData(blk.getStart(), true)) {
                    if (d.getMinAddress().compareTo(blk.getEnd()) > 0) break;
                    und.delete(d.getMinAddress(), d.getMaxAddress());
                }
                String bname = blk.getName().replaceAll("\\s", "_");
                for (AddressRange r : und) {
                    byte[] buf = new byte[(int) r.getLength()];
                    currentProgram.getMemory().getBytes(r.getMinAddress(), buf);
                    long n = 0;
                    for (byte x : buf) if (x != (byte) 0xFF) n++;
                    if (n == 0) continue;
                    int refs = 0;
                    for (Address a = r.getMinAddress(); a != null && a.compareTo(r.getMaxAddress()) <= 0; a = a.next()) {
                        refs += rm.getReferenceCountTo(a);
                    }
                    Function f = currentProgram.getFunctionManager().getFunctionContaining(r.getMinAddress());
                    CodeUnit prev = r.getMinAddress().equals(blk.getStart()) ? null
                            : lst.getCodeUnitContaining(r.getMinAddress().subtract(1));
                    CodeUnit next = r.getMaxAddress().equals(blk.getEnd()) ? null
                            : lst.getCodeUnitAt(r.getMaxAddress().add(1));
                    w.printf("%s\t0x%s\t0x%s\t%d\t%d\t%d\t%s\t%s\t%s%n", bname, r.getMinAddress(), r.getMaxAddress(),
                            r.getLength(), n, refs, f == null ? "-" : "0x" + f.getEntryPoint(), kind(prev), kind(next));
                    total += n;
                    nranges++;
                }
            }
        }
        println("UndefinedRanges: " + nranges + " ranges, " + total + " undefined non-0xFF bytes -> " + args[0]);
    }
}
