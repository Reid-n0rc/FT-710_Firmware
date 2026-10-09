// List the functions that touch given peripheral register ranges, via references or
// scalar operands (e.g. `MOV.L #0x8A0A0,R14`) that fall inside a range.
// Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" <proj> -process <prog> -noanalysis -readOnly \
//     -scriptPath tools/ghidra -postScript PeriphRefs.java <out.tsv> NAME:0xSTART:0xEND ...
// Output TSV: range, function entry, function name, hits, first instruction addresses.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;
import ghidra.program.model.listing.Instruction;
import ghidra.program.model.scalar.Scalar;
import ghidra.program.model.symbol.Reference;

import java.io.PrintWriter;
import java.util.LinkedHashMap;
import java.util.Map;

public class PeriphRefs extends GhidraScript {
    @Override
    protected void run() throws Exception {
        String[] a = getScriptArgs();
        int n = a.length - 1;
        String[] name = new String[n];
        long[] lo = new long[n], hi = new long[n];
        for (int i = 0; i < n; i++) {
            String[] p = a[i + 1].split(":");
            name[i] = p[0];
            lo[i] = Long.decode(p[1]);
            hi[i] = Long.decode(p[2]);
        }
        @SuppressWarnings("unchecked")
        Map<Function, StringBuilder>[] hits = new Map[n];
        @SuppressWarnings("unchecked")
        Map<Function, Integer>[] cnt = new Map[n];
        for (int i = 0; i < n; i++) {
            hits[i] = new LinkedHashMap<>();
            cnt[i] = new LinkedHashMap<>();
        }
        for (Instruction ins : currentProgram.getListing().getInstructions(true)) {
            java.util.Set<Long> vals = new java.util.HashSet<>();
            for (Reference r : ins.getReferencesFrom()) {
                vals.add(r.getToAddress().getOffset());
            }
            for (int op = 0; op < ins.getNumOperands(); op++) {
                for (Object o : ins.getOpObjects(op)) {
                    if (o instanceof Scalar) vals.add(((Scalar) o).getUnsignedValue());
                }
            }
            for (long v : vals) {
                for (int i = 0; i < n; i++) {
                    if (v >= lo[i] && v <= hi[i]) {
                        Function f = getFunctionContaining(ins.getAddress());
                        if (f == null) continue;
                        cnt[i].merge(f, 1, Integer::sum);
                        StringBuilder sb = hits[i].computeIfAbsent(f, k -> new StringBuilder());
                        if (cnt[i].get(f) <= 4) sb.append(ins.getAddress()).append(String.format("(%X) ", v));
                    }
                }
            }
        }
        try (PrintWriter out = new PrintWriter(a[0], "UTF-8")) {
            out.println("range\tentry\tname\thits\tsample");
            for (int i = 0; i < n; i++) {
                for (Map.Entry<Function, StringBuilder> e : hits[i].entrySet()) {
                    out.println(name[i] + "\t" + e.getKey().getEntryPoint() + "\t" + e.getKey().getName() + "\t"
                            + cnt[i].get(e.getKey()) + "\t" + e.getValue().toString().trim());
                }
            }
        }
        println("PeriphRefs: wrote " + a[0]);
    }
}
