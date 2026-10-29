// Create functions at known entry points that auto-analysis missed or merged into a neighbour (T11).
// Typical case: RTOS task entries that never return and start with an `ldr` before the `push`. Ghidra then either
// extends the previous function over them, or (DisplayFindCode's prologue pass) starts a function at the `push`,
// 4-8 bytes too late.
// Headless usage (from the repo root), run before ApplyNames.java:
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript FixFuncEntries.java tools/ghidra/entries_display.tsv
// A second script argument "nolate" skips step (1): for tables of entries that are only reached through pointers
// (MAIN key handlers, entries_main.tsv, #70), where a neighbour without call references is still a real entry.
// TSV format: address[<TAB>drop|thumb][<TAB>comment]; "#" lines and blank lines are ignored. "thumb" disassembles a
// still-undefined entry as Thumb (ARM images; T21e).
// For each address: (1) functions that start within the first 8 fall-through instructions after it are removed (late
// starts; the walk stops at a call, and a function that has call references is kept, T21e); (2) the function containing it, if it starts earlier, is removed and later re-created at its old entry (so its
// body is recomputed and stops at the new entry), unless column 2 is "drop" (the old entry was data); (3) the function at
// the address is (re)created. The script is idempotent.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;

import java.nio.file.Files;
import java.nio.file.Paths;

public class FixFuncEntries extends GhidraScript {
    boolean hasCallers(Function f) {
        for (ghidra.program.model.symbol.Reference r : getReferencesTo(f.getEntryPoint()))
            if (r.getReferenceType().isCall()) return true;
        return false;
    }

    @Override
    protected void run() throws Exception {
        int made = 0, late = 0, bad = 0;
        boolean nolate = getScriptArgs().length > 1 && getScriptArgs()[1].equals("nolate");
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            if (line.isBlank() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            Address a = toAddr(Long.decode(p[0].startsWith("0x") ? p[0] : "0x" + p[0]));
            boolean drop = p.length > 1 && p[1].trim().equals("drop");
            boolean thumb = p.length > 1 && p[1].trim().equals("thumb");
            Function old = getFunctionContaining(a);
            Address oldEntry = null;
            if (old != null && !old.getEntryPoint().equals(a)) {
                oldEntry = old.getEntryPoint();
                removeFunction(old);
                if (drop) clearListing(oldEntry, a.subtract(1));
            } else if (old != null) {
                removeFunction(old);
            }
            if (getInstructionAt(a) == null) {
                clearListing(a);
                if (thumb) new ghidra.app.cmd.disassemble.ArmDisassembleCommand(a, null, true).applyTo(currentProgram, monitor);
                else disassemble(a);
            }
            Instruction ins = getInstructionAt(a);
            for (int i = 0; i < 8 && ins != null && !nolate; i++) {
                Address next = ins.getFallThrough();
                // stop at a call: the code after it may follow a call that never returns (T21e: an entry that ends
                // in `bl task_loop` sits right before sd_task_create, which is no late start)
                if (next == null || ins.getFlowType().isCall()) break;
                Function f2 = getFunctionAt(next);
                if (f2 != null && hasCallers(f2)) break;   // called directly: a real entry, keep it
                if (f2 != null) { removeFunction(f2); late++; }
                ins = getInstructionAt(next);
            }
            Function f = createFunction(a, null);
            if (f == null) { printerr("FixFuncEntries: cannot create function at " + a); bad++; continue; }
            made++;
            if (oldEntry != null && !drop && getFunctionAt(oldEntry) == null) {
                if (createFunction(oldEntry, null) == null) printerr("FixFuncEntries: cannot re-create " + oldEntry);
            }
        }
        println("FixFuncEntries: " + made + " created, " + late + " late starts removed, " + bad + " failed");
    }
}
