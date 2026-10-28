// Export instructions as TSV for the FLIX test oracle (tools/flix_compare.py, issue #97 A step 7).
// Headless usage (from the repo root; normally through tools/flix_oracle.sh):
//   tools/ghidra-headless.sh <projdir> <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript ExportListing.java <out.tsv> listing
//   ... -postScript ExportListing.java <out.tsv> decode <addrs.txt>
// Modes:
//   listing  every instruction in the program's listing after analysis (what the decompiler sees).
//   decode   decode one instruction at each hex address in <addrs.txt> (one per line, '#' comments) with the
//            PseudoDisassembler, independent of flow and of what analysis created; nothing is written to the
//            program. This measures the language's decoder alone.
// Output columns: addr (8 hex digits), len, mnemonic, operands (Ghidra's text, separators as printed), bytes (hex).
// A failed decode is written as: addr, 0, "!error", message, "".
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.app.util.PseudoDisassembler;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.listing.InstructionIterator;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.PrintWriter;

public class ExportListing extends GhidraScript {
    static String clean(String s) {
        return s.replace('\t', ' ').replace('\n', ' ');
    }

    static String row(Instruction ins) throws Exception {
        String mn = ins.getMnemonicString();
        String all = ins.toString();
        String ops = all.startsWith(mn) ? all.substring(mn.length()).trim() : all;
        StringBuilder hex = new StringBuilder();
        for (byte b : ins.getBytes()) hex.append(String.format("%02x", b & 0xFF));
        return String.format("%08x\t%d\t%s\t%s\t%s", ins.getAddress().getOffset(), ins.getLength(),
                clean(mn), clean(ops), hex);
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        String mode = args.length > 1 ? args[1] : "listing";
        int n = 0, bad = 0;
        try (PrintWriter out = new PrintWriter(args[0], "UTF-8")) {
            out.println("addr\tlen\tmnemonic\toperands\tbytes");
            if (mode.equals("listing")) {
                InstructionIterator it = currentProgram.getListing().getInstructions(true);
                while (it.hasNext() && !monitor.isCancelled()) {
                    out.println(row(it.next()));
                    n++;
                }
            } else if (mode.equals("decode")) {
                PseudoDisassembler pd = new PseudoDisassembler(currentProgram);
                try (BufferedReader r = new BufferedReader(new FileReader(args[2]))) {
                    String ln;
                    while ((ln = r.readLine()) != null) {
                        ln = ln.trim();
                        if (ln.isEmpty() || ln.startsWith("#")) continue;
                        Address a = toAddr(Long.parseLong(ln.replaceFirst("^0x", ""), 16));
                        n++;
                        try {
                            Instruction ins = pd.disassemble(a);
                            if (ins == null) throw new Exception("no instruction");
                            out.println(row(ins));
                        } catch (Exception e) {
                            bad++;
                            out.println(String.format("%08x\t0\t!error\t%s\t", a.getOffset(),
                                    clean(String.valueOf(e.getMessage()))));
                        }
                    }
                }
            } else {
                throw new IllegalArgumentException("mode must be listing or decode: " + mode);
            }
        }
        println("ExportListing: " + mode + " " + n + " instructions (" + bad + " failed) -> " + args[0]);
    }
}
