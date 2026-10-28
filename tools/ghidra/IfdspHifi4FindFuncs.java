// Post-analysis pass for the IFDSP HiFi4 (Xtensa) program: makes the function list in the DSP SRAM image exactly the
// reference list tools/ghidra/entries_hifi4.tsv (issue #97, B10). That list is every function of the FLIX-aware objdump
// listing decomp/ifdsp/hifi4/flix.dis plus a few documented entries without an `entry` instruction; regenerate it with
//   python3 -I tools/flix_compare.py entries > tools/ghidra/entries_hifi4.tsv
// Steps: (1) disassemble and create a function at every reference entry, first clearing any instruction that overlaps
// the entry without starting there (a mis-decoded FLIX bundle can swallow it), then re-run analysis, repeated until all
// exist; (2) remove every other function outside the TCM (dsp_itcm vectors come from IfdspHifi4Setup.java): with the
// stock language these are data, mid-bundle decodes and branch targets that the mis-sized FLIX bundles turned into
// call targets.
// Headless usage: see IfdspHifi4Setup.java (run as -postScript IfdspHifi4FindFuncs.java [entries.tsv]).
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

public class IfdspHifi4FindFuncs extends GhidraScript {
    static final String KEEP_BLOCK = "dsp_itcm"; // reset/window/interrupt vectors seeded by IfdspHifi4Setup.java

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        File tsv = args.length > 0 ? new File(args[0])
                : new File(getSourceFile().getParentFile().getFile(false), "entries_hifi4.tsv");
        Set<Long> ref = new LinkedHashSet<>();
        try (BufferedReader r = new BufferedReader(new FileReader(tsv))) {
            String ln;
            while ((ln = r.readLine()) != null) {
                if (ln.isEmpty() || ln.startsWith("entry")) continue;
                ref.add(Long.parseLong(ln.split("\t")[0], 16));
            }
        }
        Listing listing = currentProgram.getListing();
        int created = 0, cleared = 0, failed = 0;
        for (int pass = 0; pass < 4; pass++) {
            int found = 0;
            failed = 0;
            for (long e : ref) {
                Address ad = toAddr(e);
                if (getFunctionAt(ad) != null) continue;
                for (int k = 0; k < 3; k++) {
                    Instruction ins = listing.getInstructionContaining(ad.add(k));
                    if (ins != null && !ins.getMinAddress().equals(ad)) {
                        clearListing(ins.getMinAddress(), ins.getMaxAddress());
                        cleared++;
                    }
                }
                if (getInstructionAt(ad) == null) disassemble(ad);
                if (createFunction(ad, null) != null) found++;
                else failed++;
            }
            created += found;
            println("IfdspHifi4FindFuncs pass " + pass + ": " + found + " functions created, " + failed + " failed");
            if (found == 0) break;
            analyzeChanges(currentProgram);
        }
        List<Function> junk = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            MemoryBlock b = getMemoryBlock(f.getEntryPoint());
            if (b != null && b.getName().equals(KEEP_BLOCK)) continue;
            if (!ref.contains(f.getEntryPoint().getOffset())) junk.add(f);
        }
        for (Function f : junk) removeFunction(f);
        println("IfdspHifi4FindFuncs: " + ref.size() + " reference entries (" + tsv.getName() + "), " + created
                + " created, " + cleared + " overlapping instructions cleared, " + failed + " failed, " + junk.size()
                + " other functions removed, " + currentProgram.getFunctionManager().getFunctionCount() + " total");
    }
}
