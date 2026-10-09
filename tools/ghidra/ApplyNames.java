// Apply function names (and optional plate comments) from a TSV file to the current program.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript ApplyNames.java tools/ghidra/names_main.tsv
// TSV format: address<TAB>name[<TAB>comment]; '#' lines and blank lines are ignored.
// A name starting with '@' (e.g. @cat_mnemonics) sets a primary data label instead of a function.
// A function is created at the address if none exists. Existing user names are overwritten,
// so the TSV is the reproducible source of names for the project (keep it in sync with docs).
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Function;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.Files;
import java.nio.file.Paths;

public class ApplyNames extends GhidraScript {
    @Override
    protected void run() throws Exception {
        int ok = 0, bad = 0;
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            if (line.isBlank() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            Address a = toAddr(Long.decode(p[0].startsWith("0x") ? p[0] : "0x" + p[0]));
            if (p[1].startsWith("@")) {
                createLabel(a, p[1].substring(1), true, SourceType.USER_DEFINED);
                if (p.length > 2 && !p[2].isBlank()) {
                    currentProgram.getListing().setComment(a, CodeUnit.PLATE_COMMENT, p[2]);
                }
                ok++;
                continue;
            }
            Function f = getFunctionAt(a);
            if (f == null) {
                if (getInstructionAt(a) == null) disassemble(a);
                f = createFunction(a, p[1]);
            }
            if (f == null) {
                printerr("ApplyNames: no function at " + a + " for " + p[1]);
                bad++;
                continue;
            }
            f.setName(p[1], SourceType.USER_DEFINED);
            if (p.length > 2 && !p[2].isBlank()) {
                currentProgram.getListing().setComment(a, CodeUnit.PLATE_COMMENT, p[2]);
            }
            ok++;
        }
        println("ApplyNames: " + ok + " applied, " + bad + " failed");
    }
}
