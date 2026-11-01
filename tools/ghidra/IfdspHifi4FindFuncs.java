// Post-analysis pass for the IFDSP HiFi4 (Xtensa) program: makes the function list in the DSP SRAM image exactly the
// reference list tools/ghidra/entries_hifi4.tsv (issue #97, B10). That list is every function of the FLIX-aware objdump
// listing decomp/ifdsp/hifi4/flix.dis plus a few documented entries without an `entry` instruction; regenerate it with
//   python3 -I tools/flix_compare.py entries > tools/ghidra/entries_hifi4.tsv
// Steps: (1) disassemble and create a function at every reference entry, first clearing any instruction that overlaps
// the entry without starting there (a mis-decoded FLIX bundle can swallow it), then re-run analysis, repeated until all
// exist. An overlapping instruction that the flow reaches (it has a fall-through predecessor or a flow reference) is
// real code of the previous function, so the entry is wrong: it is reported (WARN) and skipped, never cleared. That is
// how 0x218480 and 0x233818 were made: their 0x36 `entry` byte is inside the bundles 0x21847D (ifft_cplxf_ie) and
// 0x233815 (fft_realf_ie). (2) Repair a project built before that check: a non-reference function whose entry sits in
// a fall-through gap (the instruction before it falls through to an address that no instruction covers) is removed,
// its body cleared, the gap disassembled again (dropping the bogus decode's error bookmarks that now sit inside an
// instruction) and the previous function's body recomputed. (3) Remove every other
// function outside the TCM (dsp_itcm vectors come from IfdspHifi4Setup.java): with the stock language these are data,
// mid-bundle decodes and branch targets that the mis-sized FLIX bundles turned into call targets.
// Headless usage: see IfdspHifi4Setup.java (run as -postScript IfdspHifi4FindFuncs.java [entries.tsv]); on an existing
// program: -process FT-710_IFDSP_V0101_hifi4.bin -noanalysis -postScript IfdspHifi4FindFuncs.java
// @category FT710
import ghidra.app.cmd.function.CreateFunctionCmd;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.address.AddressSet;
import ghidra.program.model.listing.Bookmark;
import ghidra.program.model.listing.BookmarkType;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.mem.MemoryBlock;
import ghidra.program.model.symbol.Reference;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.LinkedHashSet;
import java.util.List;
import java.util.Set;

public class IfdspHifi4FindFuncs extends GhidraScript {
    static final String KEEP_BLOCK = "dsp_itcm"; // reset/window/interrupt vectors seeded by IfdspHifi4Setup.java

    /** True if the flow reaches ins: an instruction falls through to it, or a flow reference (branch, jump) targets it. */
    private boolean reached(Instruction ins) {
        if (ins.getFallFrom() != null) return true;
        for (Reference r : getReferencesTo(ins.getMinAddress())) {
            if (r.getReferenceType().isFlow()) return true;
        }
        return false;
    }

    private boolean keep(Function f) {
        MemoryBlock b = getMemoryBlock(f.getEntryPoint());
        return b != null && b.getName().equals(KEEP_BLOCK);
    }

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
        Set<Long> inside = new LinkedHashSet<>();
        for (int pass = 0; pass < 4; pass++) {
            int found = 0;
            failed = 0;
            for (long e : ref) {
                Address ad = toAddr(e);
                if (getFunctionAt(ad) != null || inside.contains(e)) continue;
                Instruction over = null;
                for (int k = 0; k < 3 && over == null; k++) {
                    Instruction ins = listing.getInstructionContaining(ad.add(k));
                    if (ins != null && !ins.getMinAddress().equals(ad) && reached(ins)) over = ins;
                }
                if (over != null) {
                    printerr("WARN IfdspHifi4FindFuncs: entry " + ad + " is inside the reached instruction at "
                            + over.getMinAddress() + " (" + over + "); not a function entry, skipped (fix "
                            + tsv.getName() + ")");
                    inside.add(e);
                    continue;
                }
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
        // (2) repair: non-reference functions that start in a fall-through gap of the previous function
        List<Function> grow = new ArrayList<>();
        int repaired = 0, bookmarks = 0;
        List<Function> gapped = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (keep(f) || ref.contains(f.getEntryPoint().getOffset())) continue;
            Address e = f.getEntryPoint();
            Instruction p = listing.getInstructionBefore(e);
            if (p == null || p.getFallThrough() == null) continue;
            Address ft = p.getFallThrough();
            if (ft.compareTo(e) < 0 && listing.getInstructionContaining(ft) == null) gapped.add(f);
        }
        for (Function f : gapped) {
            Address e = f.getEntryPoint();
            Instruction p = listing.getInstructionBefore(e);
            Address ft = p.getFallThrough();
            Function owner = getFunctionContaining(p.getMinAddress());
            AddressSet body = new AddressSet(f.getBody());
            removeFunction(f);
            clearListing(body);
            disassemble(ft);
            // the bogus decode's "Bad Instruction" bookmarks (e.g. 0x218483, "flow from 00218480") that now sit inside
            // a real instruction
            for (Address x : new AddressSet(ft, body.getMaxAddress().add(16)).getAddresses(true)) {
                for (Bookmark b : currentProgram.getBookmarkManager().getBookmarks(x, BookmarkType.ERROR)) {
                    if (listing.getInstructionContaining(x) != null) {
                        removeBookmark(b);
                        bookmarks++;
                    }
                }
            }
            println("IfdspHifi4FindFuncs: removed " + f.getName() + " (entry " + e + " in the fall-through gap at " + ft
                    + " after " + p.getMinAddress() + "), cleared " + body.getNumAddresses() + " bytes, disassembled "
                    + ft + (owner != null ? " for " + owner.getName() : ""));
            if (owner != null) grow.add(owner);
            repaired++;
        }
        if (repaired > 0) analyzeChanges(currentProgram);
        // (3) every other non-reference function outside the TCM
        List<Function> junk = new ArrayList<>();
        for (Function f : currentProgram.getFunctionManager().getFunctions(true)) {
            if (keep(f)) continue;
            if (!ref.contains(f.getEntryPoint().getOffset())) junk.add(f);
        }
        for (Function f : junk) removeFunction(f);
        for (Function f : grow) {
            long before = f.getBody().getNumAddresses();
            CreateFunctionCmd.fixupFunctionBody(currentProgram, f, monitor);
            println("IfdspHifi4FindFuncs: " + f.getName() + " body " + before + " -> " + f.getBody().getNumAddresses()
                    + " bytes");
        }
        println("IfdspHifi4FindFuncs: " + ref.size() + " reference entries (" + tsv.getName() + "), " + created
                + " created, " + cleared + " overlapping instructions cleared, " + failed + " failed, " + inside.size()
                + " inside a reached instruction (skipped), " + repaired + " repaired (" + bookmarks
                + " stale error bookmarks removed), " + junk.size() + " other functions removed, " + currentProgram.getFunctionManager().getFunctionCount() + " total");
    }
}
