// Apply the state-block structures of a C header (T23c) to the current program. Run after ApplySignatures.java and
// ApplyEnums.java (the fields can use its enums). Headless usage (from the repo root):
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis -scriptPath tools/ghidra \
//     -postScript ApplyEnums.java tools/ghidra/enums_main.h tools/ghidra/enum_uses_main.tsv \
//     -postScript ApplyStructs.java tools/ghidra/structs_main.h
// The header format is described at the top of tools/ghidra/structs_main.h. In short, line by line:
//   struct NAME {  /* size 0xNN: ... */           opens a structure of that size, `};` closes it
//       TYPE name[N]..;  /* +0xOFF ... */          a field at that offset (the comment becomes the field comment)
//       TYPE name : N;  /* +0xOFF.B ... */         a bitfield of N bits at bit B (0 = LSB) of the TYPE-sized unit at +0xOFF
//   TYPE name[N]..;  /* @0xADDR ... */             a typed global at that address (label `name` unless PTR_/DAT_)
//   TYPE *func(...);  /* @0xADDR return ... */     sets the return type of the function at that address
// TYPE is a C integer type, `struct NAME` (declared earlier in the header) or `enum NAME`, an enum that ApplyEnums.java
// (enums_main.h) has already created under /FT710; its size is the enum's @size. A missing enum is an error.
// The structures go to the program's data type manager under /FT710 (replacing an older version of the same name);
// globals replace the data they cover (normally undefined; anything else is reported), so the script is idempotent.
// Labels are added with source IMPORTED and do not replace a USER_DEFINED label (names_main.tsv keeps priority).
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.symbol.*;

import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class ApplyStructs extends GhidraScript {
    static final CategoryPath CAT = new CategoryPath("/FT710");
    static final String TYPE = "((?:struct|enum) \\w+|\\w+)";
    static final Pattern OPEN = Pattern.compile("^struct (\\w+) \\{\\s*/\\*\\s*size 0x([0-9A-Fa-f]+)");
    static final Pattern FIELD = Pattern.compile(
            "^\\s+" + TYPE + "\\s*(\\*?)\\s*(\\w+)((?:\\[\\d+\\])*);\\s*/\\*\\s*\\+0x([0-9A-Fa-f]+)\\s*(.*?)\\s*\\*/\\s*$");
    static final Pattern BITFIELD = Pattern.compile(
            "^\\s+" + TYPE + "\\s+(\\w+)\\s*:\\s*(\\d+);\\s*/\\*\\s*\\+0x([0-9A-Fa-f]+)\\.(\\d+)\\s*(.*?)\\s*\\*/\\s*$");
    static final Pattern GLOBAL = Pattern.compile(
            "^" + TYPE + "\\s*(\\*?)\\s*(\\w+)((?:\\[\\d+\\])*);\\s*/\\*\\s*@0x([0-9A-Fa-f]+)\\s*(.*?)\\s*\\*/\\s*$");
    static final Pattern FUNC = Pattern.compile(
            "^" + TYPE + "\\s*(\\*?)\\s*(\\w+)\\(.*\\);\\s*/\\*\\s*@0x([0-9A-Fa-f]+)\\s+return\\b.*\\*/\\s*$");

    DataTypeManager dtm;
    Map<String, DataType> structs = new HashMap<>();

    DataType base(String t) {
        switch (t) {
            case "uint8_t": return ByteDataType.dataType;
            case "int8_t": return SignedByteDataType.dataType;
            case "char": return CharDataType.dataType;
            case "uint16_t": return UnsignedShortDataType.dataType;
            case "int16_t": return ShortDataType.dataType;
            case "uint32_t": return UnsignedIntegerDataType.dataType;
            case "int32_t": return IntegerDataType.dataType;
        }
        if (t.startsWith("struct ")) {
            DataType d = structs.get(t.substring(7));
            if (d != null) return d;
        }
        if (t.startsWith("enum ")) {
            DataType d = dtm.getDataType(CAT, t.substring(5));
            if (d instanceof ghidra.program.model.data.Enum) return d;
            throw new IllegalArgumentException("'" + t + "' is not an enum under " + CAT + " (run ApplyEnums.java first)");
        }
        throw new IllegalArgumentException("unknown type '" + t + "'");
    }

    DataType type(String t, String ptr, String dims) {
        DataType d = base(t);
        if (!ptr.isEmpty()) d = dtm.getPointer(d);
        List<Integer> ns = new ArrayList<>();
        for (Matcher m = Pattern.compile("\\[(\\d+)\\]").matcher(dims); m.find();) ns.add(Integer.parseInt(m.group(1)));
        for (int i = ns.size() - 1; i >= 0; i--) d = new ArrayDataType(d, ns.get(i), d.getLength(), dtm);
        return d;
    }

    @Override
    protected void run() throws Exception {
        dtm = currentProgram.getDataTypeManager();
        Listing listing = currentProgram.getListing();
        SymbolTable st = currentProgram.getSymbolTable();
        List<String> lines = Files.readAllLines(Paths.get(getScriptArgs()[0]));
        int nStruct = 0, nField = 0, nEnumField = 0, nBits = 0, nGlobal = 0, nLabel = 0, nFunc = 0, nCleared = 0, bad = 0;
        StructureDataType cur = null;
        int curSize = 0;
        boolean inComment = false;
        int ln = 0;
        for (String line : lines) {
            ln++;
            String s = line.trim();
            if (inComment) { if (s.contains("*/")) inComment = false; continue; }
            if (cur == null && s.startsWith("/*")) { if (!s.contains("*/")) inComment = true; continue; }
            if (s.isEmpty() || s.startsWith("#") || s.startsWith("//")) continue;
            Matcher m;
            if (cur == null && (m = OPEN.matcher(line)).find()) {
                curSize = Integer.parseInt(m.group(2), 16);
                cur = new StructureDataType(CAT, m.group(1), curSize, dtm);
                continue;
            }
            if (cur != null) {
                if (s.equals("};")) {
                    DataType r = dtm.addDataType(cur, DataTypeConflictHandler.REPLACE_HANDLER);
                    structs.put(cur.getName(), r);
                    nStruct++;
                    cur = null;
                    continue;
                }
                if ((m = BITFIELD.matcher(line)).matches()) {
                    try {
                        DataType d = base(m.group(1));
                        int bits = Integer.parseInt(m.group(3));
                        int off = Integer.parseInt(m.group(4), 16), bit = Integer.parseInt(m.group(5));
                        if (bits < 1 || bit + bits > 8 * d.getLength()) throw new IllegalArgumentException("bitfield does not fit its type");
                        if (off + d.getLength() > curSize) throw new IllegalArgumentException("field past the end");
                        // the unit's bytes must be undefined filler, so that the bitfield takes their place instead of
                        // shifting the components behind it
                        DataTypeComponent c = cur.getComponentContaining(off);
                        if (c != null && c.getDataType() != DataType.DEFAULT && !c.isBitFieldComponent())
                            throw new IllegalArgumentException("+0x" + Integer.toHexString(off) + " is already " + c.getFieldName());
                        cur.insertBitFieldAt(off, d.getLength(), bit, d, bits, m.group(2), m.group(6));
                        if (cur.getLength() != curSize)
                            throw new IllegalArgumentException("bitfield changed the size to 0x" + Integer.toHexString(cur.getLength()));
                        nField++;
                        nBits++;
                        if (d instanceof ghidra.program.model.data.Enum) nEnumField++;
                    } catch (Exception e) {
                        printerr("ApplyStructs: line " + ln + ": " + e.getMessage()); bad++;
                    }
                    continue;
                }
                m = FIELD.matcher(line);
                if (!m.matches()) { printerr("ApplyStructs: line " + ln + ": not a field: " + s); bad++; continue; }
                try {
                    DataType d = type(m.group(1), m.group(2), m.group(4));
                    int off = Integer.parseInt(m.group(5), 16);
                    if (off + d.getLength() > cur.getLength()) throw new IllegalArgumentException("field past the end");
                    cur.replaceAtOffset(off, d, d.getLength(), m.group(3), m.group(6));
                    nField++;
                    if (m.group(1).startsWith("enum ")) nEnumField++;
                } catch (Exception e) {
                    printerr("ApplyStructs: line " + ln + ": " + e.getMessage()); bad++;
                }
                continue;
            }
            if ((m = FUNC.matcher(line)).matches()) {
                Address a = toAddr(Long.parseLong(m.group(4), 16));
                Function f = getFunctionAt(a);
                if (f == null) { printerr("ApplyStructs: no function at " + a); bad++; continue; }
                if (!f.getName().equals(m.group(3))) println("ApplyStructs: warning: " + a + " is " + f.getName() + ", header says " + m.group(3));
                f.setReturnType(type(m.group(1), m.group(2), ""), SourceType.USER_DEFINED);
                nFunc++;
                continue;
            }
            if ((m = GLOBAL.matcher(line)).matches()) {
                try {
                    DataType d = type(m.group(1), m.group(2), m.group(4));
                    Address a = toAddr(Long.parseLong(m.group(5), 16));
                    Address e = a.add(d.getLength() - 1);
                    Data old = listing.getDataAt(a);
                    if (old == null || !old.getDataType().isEquivalent(d) || old.getLength() != d.getLength()) {
                        for (Data x : listing.getDefinedData(new ghidra.program.model.address.AddressSet(a, e), true)) {
                            DataType xt = x.getDataType();
                            if (!(xt instanceof Undefined) && !(xt instanceof DefaultDataType) && !(xt instanceof Pointer)) {
                                println("ApplyStructs: " + m.group(3) + ": replacing " + xt.getName() + " at " + x.getAddress());
                            }
                            nCleared++;
                        }
                        listing.clearCodeUnits(a, e, false);
                        listing.createData(a, d);
                    }
                    String name = m.group(3);
                    if (!name.startsWith("PTR_") && !name.startsWith("DAT_")) {
                        Symbol p = st.getPrimarySymbol(a);
                        if (p == null || !p.getName().equals(name)) {
                            boolean primary = p == null || p.getSource() != SourceType.USER_DEFINED;
                            Symbol ns = st.createLabel(a, name, SourceType.IMPORTED);
                            if (primary) ns.setPrimary();
                            nLabel++;
                        }
                    }
                    nGlobal++;
                } catch (Exception ex) {
                    printerr("ApplyStructs: line " + ln + ": " + ex.getMessage()); bad++;
                }
                continue;
            }
            printerr("ApplyStructs: line " + ln + ": not understood: " + s);
            bad++;
        }
        println("ApplyStructs: " + nStruct + " structures, " + nField + " fields (" + nEnumField + " enum-typed, " + nBits
                + " bitfields), " + nGlobal + " globals (" + nCleared + " data units replaced, " + nLabel + " labels), "
                + nFunc + " return types, " + bad + " errors");
    }
}
