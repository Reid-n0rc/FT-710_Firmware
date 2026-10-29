// Create the enums of a C header under /FT710 and apply them to parameters, returns and globals (T23f).
// Headless usage (from the repo root), after ApplySignatures.java:
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript ApplyEnums.java tools/ghidra/enums_main.h tools/ghidra/enum_uses_main.tsv
// Header format (tools/ghidra/enums_main.h): each "enum NAME { A = 0, B = 0x1, ... };" is preceded by a comment that
// holds "@size N" (bytes; becomes the enum's length) and its evidence (becomes the description). A comment after a value
// becomes that value's comment. Only this subset of C is read; the header stays valid C.
// Uses TSV: address<TAB>name<TAB>kind<TAB>enum<TAB>evidence; kind is "param N" (1-based), "return" or "global".
//   param N / return: only the type changes (storage stays); the size must equal the enum's. The function's signature
//     source becomes USER_DEFINED (a locked prototype, as ApplySignatures.java sets it).
//   global: a data item of the enum type, created only over undefined data or a plain integer of the same size.
// The name column is checked: a function with another name, or a global whose label is neither that name nor a default
// DAT_ label, is a warning. Re-running replaces the enums (same path) and is idempotent.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.SourceType;
import ghidra.program.model.symbol.Symbol;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.HashMap;
import java.util.Map;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ApplyEnums extends GhidraScript {
    static final CategoryPath CAT = new CategoryPath("/FT710");

    static String clean(String comment) {
        StringBuilder sb = new StringBuilder();
        for (String l : comment.split("\n")) {
            l = l.trim().replaceFirst("^\\*+\\s?", "").replaceAll("@size\\s+\\d+", "").trim();
            if (l.isEmpty()) continue;
            if (sb.length() > 0) sb.append(' ');
            sb.append(l);
        }
        return sb.toString();
    }

    Map<String, EnumDataType> parse(String text) {
        Map<String, EnumDataType> out = new HashMap<>();
        Pattern blk = Pattern.compile("/\\*((?:(?!\\*/).)*?@size\\s+(\\d+)(?:(?!\\*/).)*)\\*/\\s*enum\\s+(\\w+)\\s*\\{(.*?)\\};",
                Pattern.DOTALL);
        Pattern ent = Pattern.compile("(\\w+)\\s*=\\s*(0[xX][0-9A-Fa-f]+|\\d+)\\s*,?[ \\t]*(?:/\\*(.*?)\\*/)?", Pattern.DOTALL);
        Matcher m = blk.matcher(text);
        while (m.find()) {
            int size = Integer.parseInt(m.group(2));
            EnumDataType e = new EnumDataType(CAT, m.group(3), size);
            e.setDescription(clean(m.group(1)));
            Matcher v = ent.matcher(m.group(4));
            while (v.find()) {
                long val = Long.decode(v.group(2));
                String c = v.group(3) == null ? null : clean(v.group(3));
                e.add(v.group(1), val, c);
            }
            out.put(m.group(3), e);
        }
        return out;
    }

    boolean plainData(Address a, int len) {
        for (int i = 0; i < len; i++) {
            Data d = getDataContaining(a.add(i));
            if (d == null) {
                if (getInstructionContaining(a.add(i)) != null) return false;
                continue;
            }
            DataType t = d.getDataType();
            if (Undefined.isUndefined(t) || t instanceof DefaultDataType) continue;
            if (t instanceof ghidra.program.model.data.Enum && t.getLength() == len && d.getAddress().equals(a)) continue;
            if (t instanceof AbstractIntegerDataType && t.getLength() == len && d.getAddress().equals(a)) continue;
            return false;
        }
        return true;
    }

    @Override
    protected void run() throws Exception {
        String[] args = getScriptArgs();
        DataTypeManager dtm = currentProgram.getDataTypeManager();
        Map<String, EnumDataType> parsed = parse(new String(Files.readAllBytes(Paths.get(args[0])), "UTF-8"));
        Map<String, DataType> enums = new HashMap<>();
        for (var e : parsed.entrySet())
            enums.put(e.getKey(), dtm.addDataType(e.getValue(), DataTypeConflictHandler.REPLACE_HANDLER));
        int values = parsed.values().stream().mapToInt(EnumDataType::getCount).sum();
        println("ApplyEnums: " + enums.size() + " enums (" + values + " values) in " + CAT);
        int params = 0, rets = 0, globals = 0, bad = 0;
        for (String line : Files.readAllLines(Paths.get(args[1]))) {
            if (line.isBlank() || line.startsWith("#")) continue;
            String[] p = line.split("\t");
            Address a = toAddr(Long.parseLong(p[0].replaceFirst("^0x", ""), 16));
            String kind = p[2].trim();
            DataType dt = enums.get(p[3].trim());
            if (dt == null) { printerr("ApplyEnums: " + a + ": unknown enum " + p[3]); bad++; continue; }
            try {
                if (kind.equals("global")) {
                    Symbol s = getSymbolAt(a);
                    if (s != null && !s.getName().equals(p[1]) && s.getSource() != SourceType.DEFAULT)
                        println("ApplyEnums: warning: " + a + " is labelled " + s.getName() + ", TSV says " + p[1]);
                    if (!plainData(a, dt.getLength())) {
                        printerr("ApplyEnums: " + a + " " + p[1] + ": not undefined/plain integer data, left alone");
                        bad++;
                        continue;
                    }
                    DataUtilities.createData(currentProgram, a, dt, dt.getLength(),
                            DataUtilities.ClearDataMode.CLEAR_ALL_CONFLICT_DATA);
                    globals++;
                    continue;
                }
                Function f = getFunctionAt(a);
                if (f == null) { printerr("ApplyEnums: no function at " + a + " (" + p[1] + ")"); bad++; continue; }
                if (!f.getName().equals(p[1])) println("ApplyEnums: warning: " + a + " is " + f.getName() + ", TSV says " + p[1]);
                if (kind.equals("return")) {
                    if (f.getReturnType().getLength() != dt.getLength())
                        throw new IllegalArgumentException("return is " + f.getReturnType().getLength() + " bytes, enum " + dt.getLength());
                    f.setReturnType(dt, SourceType.USER_DEFINED);
                    rets++;
                } else if (kind.startsWith("param ")) {
                    int n = Integer.parseInt(kind.substring(6).trim());
                    Parameter q = f.getParameter(n - 1);
                    if (q == null) throw new IllegalArgumentException("no parameter " + n + " (" + f.getParameterCount() + ")");
                    if (q.getLength() != dt.getLength())
                        throw new IllegalArgumentException("parameter " + n + " is " + q.getLength() + " bytes, enum " + dt.getLength());
                    q.setDataType(dt, false, true, SourceType.USER_DEFINED);
                    params++;
                } else {
                    throw new IllegalArgumentException("unknown kind '" + kind + "'");
                }
                f.setSignatureSource(SourceType.USER_DEFINED);
            } catch (Exception e) {
                printerr("ApplyEnums: " + a + " " + p[1] + " " + kind + ": " + e.getMessage());
                bad++;
            }
        }
        println("ApplyEnums: " + params + " parameters, " + rets + " returns, " + globals + " globals typed, " + bad + " failed");
    }
}
