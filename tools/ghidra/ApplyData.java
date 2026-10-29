// Apply data types (and code-only disassembly) from a TSV file to the current program (T21j, from T22d's classes).
// Headless usage (from the repo root), after the analysis and function passes:
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_DISPLAY -process FT-710_DISPLAY_V0108.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript ApplyData.java tools/ghidra/data_display.tsv
// TSV format: address<TAB>type<TAB>count[<TAB>name[<TAB>comment]]; '#' lines and blank lines are ignored.
//   type   float, int32, uint32, uint16, byte, char, pointer, each optionally with dimensions (char[4]); string = a
//          NUL-terminated C string of count bytes (NUL included); code = disassemble count bytes' worth of flow at the
//          address without creating a function.
//   count  number of elements (an array when > 1).
//   name   optional label at the address (plate comment = column 5).
// The range is cleared of data first (instructions are left alone: a row that overlaps code fails). Arrays of a scalar
// type are split at every address inside them that has a reference, so separate tables that sit back to back keep
// their own start addresses. The script is idempotent.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.CodeUnit;
import ghidra.program.model.listing.Listing;
import ghidra.program.model.symbol.SourceType;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.List;

public class ApplyData extends GhidraScript {
    DataType base(String t) {
        switch (t) {
            case "float": return FloatDataType.dataType;
            case "int32": return IntegerDataType.dataType;
            case "uint32": return UnsignedIntegerDataType.dataType;
            case "uint16": return UnsignedShortDataType.dataType;
            case "byte": return ByteDataType.dataType;
            case "char": return CharDataType.dataType;
            case "pointer": return PointerDataType.dataType;
            default: throw new IllegalArgumentException("unknown type " + t);
        }
    }

    DataType parse(String t) {
        int i = t.indexOf('[');
        DataType d = base(i < 0 ? t : t.substring(0, i));
        List<Integer> dims = new ArrayList<>();
        for (String s : (i < 0 ? "" : t.substring(i)).split("\\[")) {
            if (!s.isEmpty()) dims.add(Integer.parseInt(s.replace("]", "")));
        }
        for (int k = dims.size() - 1; k >= 0; k--) d = new ArrayDataType(d, dims.get(k), d.getLength());
        return d;
    }

    @Override
    protected void run() throws Exception {
        Listing l = currentProgram.getListing();
        int ok = 0, bad = 0, pieces = 0;
        for (String line : Files.readAllLines(Paths.get(getScriptArgs()[0]))) {
            if (line.isBlank() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            Address a = toAddr(Long.decode(p[0].startsWith("0x") ? p[0] : "0x" + p[0]));
            String type = p[1];
            int count = Integer.parseInt(p[2]);
            try {
                if (type.equals("code")) {
                    if (getInstructionAt(a) == null) disassemble(a);
                    if (getInstructionAt(a) == null) throw new IllegalStateException("does not disassemble");
                } else if (type.equals("string")) {
                    l.clearCodeUnits(a, a.add(count - 1), false);
                    createAsciiString(a, count);
                } else {
                    DataType d = parse(type);
                    int n = d.getLength();
                    Address end = a.add((long) n * count - 1);
                    if (getInstructionContaining(a) != null || l.getInstructions(new ghidra.program.model.address.AddressSet(a, end), true).hasNext())
                        throw new IllegalStateException("overlaps code");
                    l.clearCodeUnits(a, end, false);
                    // split scalar arrays at referenced elements
                    List<Integer> cuts = new ArrayList<>();
                    cuts.add(0);
                    if (count > 1 && !(d instanceof Array)) {
                        for (int k = 1; k < count; k++) {
                            if (currentProgram.getReferenceManager().hasReferencesTo(a.add((long) k * n))) cuts.add(k);
                        }
                    }
                    cuts.add(count);
                    for (int c = 0; c + 1 < cuts.size(); c++) {
                        int from = cuts.get(c), len = cuts.get(c + 1) - from;
                        Address s = a.add((long) from * n);
                        createData(s, len == 1 ? d : new ArrayDataType(d, len, n));
                        pieces++;
                    }
                }
                if (p.length > 3 && !p[3].isBlank()) createLabel(a, p[3], true, SourceType.USER_DEFINED);
                if (p.length > 4 && !p[4].isBlank()) l.setComment(a, CodeUnit.PLATE_COMMENT, p[4]);
                ok++;
            } catch (Exception e) {
                printerr("ApplyData: " + a + " " + type + "[" + count + "]: " + e.getMessage());
                bad++;
            }
        }
        println("ApplyData: " + ok + " applied (" + pieces + " data items), " + bad + " failed");
    }
}
