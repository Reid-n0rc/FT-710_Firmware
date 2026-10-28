// T21d (#97 B5): define the data that analysis left undefined in MAIN's ROM: strings and pointer tables.
// Headless usage (from the repo root), after ApplyNames.java:
//   tools/ghidra-headless.sh "$PWD/ghidra" FT710_MAIN -process FT-710_MAIN_V0112.bin -noanalysis \
//     -scriptPath tools/ghidra -postScript DefineRomData.java [report.tsv] [code=0xFFF8F658] [dry]
// Scans every undefined range (no instruction, no data) in the initialized executable blocks:
//   string   a run of >= 3 printable ASCII bytes (0x20..0x7E, TAB, CR, LF) ending in NUL -> TerminatedCString
//   pointers a run of >= 2 aligned 4-byte little-endian values that point into ROM (instruction start, defined data start or
//            ROM byte that is not 0xFF) or of >= 4 into labelled/referenced RAM/IO addresses -> pointer each
//   zeros    a run of >= 4 NUL bytes between defined items -> byte[n] (zero-filled constants/padding)
//   code     (code area, from code=<addr>, default 0xFFF8F658 = main in V01-12) a run after an instruction is disassembled;
//            a clean flow that reaches RTS/RTSD/RTE becomes a function (unreferenced CC-RX functions)
//   tables   (const area, below the code area) what is still left: float[n] / uint16[n] / byte[n] by a simple test,
//            with a plate comment that the layout is a guess
// Anything else is listed in the report (address, length, non-0xFF bytes, first bytes, previous instruction, refs).
// "dry" only runs the string/pointer/zero scan without defining anything. Data scans repeat until nothing new is found.
// @category FT710
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.*;
import ghidra.program.model.data.*;
import ghidra.program.model.listing.*;
import ghidra.program.model.mem.MemoryBlock;

import java.io.PrintWriter;
import java.util.*;

public class DefineRomData extends GhidraScript {
    boolean dry;
    int nStr, nPtr, nZero;
    long bStr, bPtr, bZero;

    static boolean printable(int b) { return (b >= 0x20 && b < 0x7F) || b == 9 || b == 10 || b == 13; }

    AddressSet undefinedRom() {
        AddressSet und = new AddressSet();
        for (MemoryBlock blk : currentProgram.getMemory().getBlocks()) {
            if (!blk.isInitialized() || !blk.isExecute()) continue;
            und.add(blk.getStart(), blk.getEnd());
        }
        AddressSet out = new AddressSet(und);
        for (Instruction ins : currentProgram.getListing().getInstructions(und, true)) out.delete(ins.getMinAddress(), ins.getMaxAddress());
        for (Data d : currentProgram.getListing().getDefinedData(und, true)) out.delete(d.getMinAddress(), d.getMaxAddress());
        return out;
    }

    boolean romTarget(long v) {
        Address t = toAddr(v);
        MemoryBlock b = currentProgram.getMemory().getBlock(t);
        if (b == null || !b.isInitialized()) return false;
        if (!b.isExecute()) return true; // RAM copy-down blocks etc.
        if (getInstructionAt(t) != null) return true;
        Data d = getDataAt(t);
        if (d != null && d.isDefined()) return true;
        try { return currentProgram.getMemory().getByte(t) != (byte) 0xFF && getInstructionContaining(t) == null; }
        catch (Exception e) { return false; }
    }

    boolean ramTarget(long v) {
        Address t = toAddr(v);
        MemoryBlock b = currentProgram.getMemory().getBlock(t);
        // RAM/IO values are only taken as pointers when something else already refers to or labels the target
        // (a run of small integers or frequencies would otherwise look like RAM/IO addresses)
        return b != null && !b.isExecute()
                && (currentProgram.getSymbolTable().getPrimarySymbol(t) != null || getReferencesTo(t).length > 0);
    }

    boolean define(Address a, DataType dt, int len) throws Exception {
        if (dry) return true;
        try {
            currentProgram.getListing().clearCodeUnits(a, a.add(len - 1), false);
            currentProgram.getListing().createData(a, dt, len);
            return true;
        } catch (Exception e) {
            printerr("DefineRomData: " + a + " " + dt.getName() + ": " + e.getMessage());
            return false;
        }
    }

    // one pass over an undefined range; returns the number of items defined
    int scan(AddressRange r, List<String> rest) throws Exception {
        int n = (int) r.getLength();
        byte[] m = new byte[n];
        currentProgram.getMemory().getBytes(r.getMinAddress(), m);
        Address base = r.getMinAddress();
        long b0 = base.getOffset();
        int defined = 0, i = 0;
        int restStart = -1;
        while (i < n) {
            int u = m[i] & 0xFF;
            // pointer table (aligned)
            if (((b0 + i) & 3) == 0 && i + 8 <= n) {
                int k = i, rom = 0, ram = 0;
                while (k + 4 <= n) {
                    long v = (m[k] & 0xFFL) | (m[k + 1] & 0xFFL) << 8 | (m[k + 2] & 0xFFL) << 16 | (m[k + 3] & 0xFFL) << 24;
                    if (v != 0 && romTarget(v) && currentProgram.getMemory().getBlock(toAddr(v)).isExecute()) rom++;
                    else if (v != 0 && ramTarget(v)) ram++;
                    else break;
                    k += 4;
                }
                int cnt = (k - i) / 4;
                if (cnt >= 2 && (rom * 2 >= cnt || cnt >= 4)) {
                    flushRest(rest, base, restStart, i, m);
                    restStart = -1;
                    for (int j = i; j < k; j += 4) if (define(base.add(j), PointerDataType.dataType, 4)) { nPtr++; bPtr += 4; defined++; }
                    i = k;
                    continue;
                }
            }
            // string
            if (printable(u)) {
                int k = i;
                while (k < n && printable(m[k] & 0xFF)) k++;
                if (k < n && m[k] == 0 && k - i >= 3) {
                    flushRest(rest, base, restStart, i, m);
                    restStart = -1;
                    if (define(base.add(i), TerminatedStringDataType.dataType, k - i + 1)) { nStr++; bStr += k - i + 1; defined++; }
                    i = k + 1;
                    continue;
                }
            }
            // zero run
            if (u == 0) {
                int k = i;
                while (k < n && m[k] == 0) k++;
                if (k - i >= 4) {
                    flushRest(rest, base, restStart, i, m);
                    restStart = -1;
                    if (define(base.add(i), new ArrayDataType(ByteDataType.dataType, k - i, 1), k - i)) { nZero++; bZero += k - i; defined++; }
                    i = k;
                    continue;
                }
            }
            if (u != 0xFF) { if (restStart < 0) restStart = i; }
            else { flushRest(rest, base, restStart, i, m); restStart = -1; }
            i++;
        }
        flushRest(rest, base, restStart, n, m);
        return defined;
    }

    void flushRest(List<String> rest, Address base, int s, int e, byte[] m) {
        if (rest == null || s < 0 || e <= s) return;
        StringBuilder hx = new StringBuilder();
        int nn = 0;
        for (int j = s; j < e; j++) if (m[j] != (byte) 0xFF) nn++;
        for (int j = s; j < Math.min(e, s + 16); j++) hx.append(String.format("%02x", m[j] & 0xFF));
        Address a = base.add(s);
        Function f = getFunctionContaining(a);
        Instruction prev = getInstructionBefore(a);
        rest.add(a + "\t" + (e - s) + "\t" + nn + "\t" + hx + "\t" + (prev == null ? "-" : prev.getAddress() + " " + prev)
                + "\t" + (getReferencesTo(a).length));
    }

    int countStrings() {
        int c = 0;
        for (Data d : currentProgram.getListing().getDefinedData(true)) if (d.hasStringValue()) c++;
        return c;
    }

    @Override
    protected void run() throws Exception {
        int str0 = countStrings();
        String[] args = getScriptArgs();
        dry = Arrays.asList(args).contains("dry");
        String report = null;
        for (String a : args) {
            if (a.startsWith("code=")) codeStart = toAddr(Long.decode(a.substring(5)));
            else if (!a.equals("dry")) report = a;
        }
        if (codeStart == null) codeStart = toAddr(0xFFF8F658L); // MAIN V01-12: main(), the first code after the const area
        dataPasses();
        if (!dry) {
            // unreferenced code after a return in the code area: disassemble, and make a function if it reaches a return
            // repeat: a function can end inside a run and leave the next function of the run undefined
            for (int pass = 1; pass <= 10; pass++) {
                int before = nFunc + nIns;
                for (AddressRange r : undefinedRom()) code(r);
                if (nFunc + nIns == before) break;
            }
            println("DefineRomData: code fragments: " + nFunc + " functions (" + bFunc + " B), " + nIns + " other ("
                    + bIns + " B)");
            dataPasses();
            // what is left in the const area are numeric tables of unknown layout: typed arrays
            for (AddressRange r : undefinedRom()) table(r);
            println("DefineRomData: const tables: " + nTab + " (" + bTab + " B)");
        }
        List<String> rest = new ArrayList<>();
        for (AddressRange r : undefinedRom()) scanRestOnly(r, rest);
        long left = 0;
        for (String s : rest) left += Long.parseLong(s.split("\t")[2]);
        println("DefineRomData: strings " + nStr + " (" + bStr + " B), pointers " + nPtr + " (" + bPtr + " B), zero runs " + nZero
                + " (" + bZero + " B); left undefined non-0xFF: " + left + " B in " + rest.size() + " runs" + (dry ? " [dry]" : ""));
        println("DefineRomData: defined strings in the program: " + str0 + " -> " + countStrings());
        if (report != null) {
            try (PrintWriter out = new PrintWriter(report, "UTF-8")) {
                out.println("# DefineRomData: undefined non-0xFF runs left; address, length, non-0xFF bytes, first bytes, previous instruction, refs");
                out.println("address\tlength\tnonff\tbytes\tprev_insn\trefs");
                for (String s : rest) out.println(s);
            }
        }
    }


    Address codeStart;
    Set<Address> failed = new HashSet<>();
    int nFunc, nIns, nTab;
    long bFunc, bIns, bTab;

    void dataPasses() throws Exception {
        for (int pass = 1; pass <= 5; pass++) {
            int d = 0;
            for (AddressRange r : undefinedRom()) d += scan(r, null);
            println("DefineRomData: data pass " + pass + ": " + d + " items");
            if (d == 0 || dry) break;
        }
    }

    // code area: each undefined run that starts after an instruction is disassembled; a run that decodes into one
    // flow ending in RTS/RTSD/RTE (no bad instruction) becomes a function (an unreferenced CC-RX function)
    void code(AddressRange r) throws Exception {
        Address a = r.getMinAddress();
        if (a.compareTo(codeStart) < 0) return;
        if (currentProgram.getMemory().getByte(a) == (byte) 0xFF) return;
        if (!failed.add(a)) return; // tried before and it did not decode
        Address end = r.getMaxAddress();
        ghidra.app.cmd.disassemble.DisassembleCommand dc = new ghidra.app.cmd.disassemble.DisassembleCommand(a, new AddressSet(r), true);
        dc.applyTo(currentProgram, monitor);
        AddressSetView got = dc.getDisassembledAddressSet();
        if (got == null || got.isEmpty()) return;
        boolean bad = false, ret = false;
        for (Instruction in : currentProgram.getListing().getInstructions(got, true)) {
            String mn = in.getMnemonicString();
            if (mn.startsWith("RTS") || mn.equals("RTE")) ret = true;
        }
        Iterator<Bookmark> bit = currentProgram.getBookmarkManager().getBookmarksIterator(a, true);
        while (bit.hasNext()) {
            Bookmark bm = bit.next();
            if (bm.getAddress().compareTo(end) > 0) break; // the disassembly is restricted to the run
            if (bm.getTypeString().equals(BookmarkType.ERROR)) { bad = true; break; }
        }
        long len = got.getNumAddresses();
        if (bad || !got.getMinAddress().equals(a)) {
            currentProgram.getListing().clearCodeUnits(got.getMinAddress(), got.getMaxAddress(), false);
            currentProgram.getBookmarkManager().removeBookmarks(new AddressSet(a, end),
                    BookmarkType.ERROR, monitor);
            println("DefineRomData: " + a + ": does not decode cleanly, left undefined (listed in the report)");
            return;
        }
        if (ret && len > 1 && getFunctionContaining(a) == null && createFunction(a, null) != null) { nFunc++; bFunc += len; }
        else { nIns++; bIns += len; }
    }

    // const area: a leftover run becomes float[n] if most 4-byte words look like normal floats, uint16[n] if most
    // 16-bit words have a zero high byte, else byte[n]; each gets a plate comment that the layout is a guess
    void table(AddressRange r) throws Exception {
        Address a = r.getMinAddress();
        if (a.compareTo(codeStart) >= 0) return;
        int n = (int) r.getLength();
        byte[] m = new byte[n];
        currentProgram.getMemory().getBytes(a, m);
        int s = 0, e = n;
        while (s < e && m[s] == (byte) 0xFF) s++;
        while (e > s && m[e - 1] == (byte) 0xFF) e--;
        if (e - s < 1) return;
        Address st = a.add(s);
        int len = e - s;
        DataType dt;
        String kind;
        int fl = 0, w16 = 0;
        if ((st.getOffset() & 3) == 0 && len % 4 == 0 && len >= 8) {
            for (int j = s; j < e; j += 4) {
                int v = (m[j] & 0xFF) | (m[j + 1] & 0xFF) << 8 | (m[j + 2] & 0xFF) << 16 | (m[j + 3] & 0xFF) << 24;
                int ex = (v >>> 23) & 0xFF;
                if (v == 0 || (ex >= 0x70 && ex <= 0x90)) fl++;
            }
        }
        if ((st.getOffset() & 1) == 0 && len % 2 == 0 && len >= 4)
            for (int j = s; j < e; j += 2) if (m[j + 1] == 0) w16++;
        if (fl * 10 >= (len / 4) * 9 && len >= 8 && fl > 0 && hasNonzeroFloat(m, s, e)) {
            dt = new ArrayDataType(FloatDataType.dataType, len / 4, 4); kind = "float";
        } else if (w16 * 10 >= (len / 2) * 8 && len >= 4) {
            dt = new ArrayDataType(UnsignedShortDataType.dataType, len / 2, 2); kind = "uint16";
        } else {
            dt = new ArrayDataType(ByteDataType.dataType, len, 1); kind = "byte";
        }
        if (define(st, dt, len)) {
            nTab++; bTab += len;
            setPlateComment(st,
                    "T21d DefineRomData: constant table, " + kind + "[" + dt.getLength() / ((Array) dt).getElementLength()
                            + "] is a layout guess (no code reference decoded yet)");
        }
    }

    boolean hasNonzeroFloat(byte[] m, int s, int e) {
        int nz = 0;
        for (int j = s; j < e; j += 4) if (m[j] != 0 || m[j + 1] != 0 || m[j + 2] != 0 || m[j + 3] != 0) nz++;
        return nz * 2 >= (e - s) / 4;
    }

    void scanRestOnly(AddressRange r, List<String> rest) throws Exception {
        int n = (int) r.getLength();
        byte[] m = new byte[n];
        currentProgram.getMemory().getBytes(r.getMinAddress(), m);
        int s = -1;
        for (int i = 0; i < n; i++) {
            if (m[i] != (byte) 0xFF) { if (s < 0) s = i; }
            else if (s >= 0) {
                // treat short 0xFF gaps (< 4) inside a run as part of it
                int k = i; while (k < n && m[k] == (byte) 0xFF) k++;
                if (k - i < 4 && k < n) { i = k - 1; continue; }
                flushRest(rest, r.getMinAddress(), s, i, m); s = -1;
            }
        }
        flushRest(rest, r.getMinAddress(), s, n, m);
    }
}
