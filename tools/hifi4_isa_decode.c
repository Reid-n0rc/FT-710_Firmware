/* hifi4_isa_decode.c - stand-alone HiFi4 (RT600) instruction decoder for checking other decoders (T22c, #104).
 *
 * It is compiled together with Cadence's MIT-licensed xtensa-modules.c (the RT600 HiFi4 ISA tables, the same file the
 * Zephyr objdump is built from) and uses only its tables and generated functions: format_decoder, the format's slot
 * get functions, each slot's opcode decode function, the slot field getters, operand decode / do_reloc, and the
 * iclass in/out lists. It does NOT use GNU libisa (xtensa-isa.c) or xtensa-dis.c: loading the bytes into the
 * instruction buffer, slot extraction, operand printing and PC-relative handling are written here, and it shares no
 * code with T21a's SLEIGH generator (tools/xtensa_sleigh_gen.py). It therefore checks the decoder drivers (objdump's
 * libisa and Ghidra's generated SLEIGH), not the tables themselves.
 *
 * Build:  gcc -O2 -I<binutils>/include -o hifi4_isa_decode tools/hifi4_isa_decode.c   (with XTENSA_MODULES_C defined
 *         to the path of xtensa-modules.c; tools/hifi4_hand_decode.py does this)
 * Use:    hifi4_isa_decode IMAGE BASE [all]   - reads hex addresses on stdin (one per line), or with "all" decodes at
 *         every byte offset; prints one TSV line per address:
 *   addr  len  format  flags  targets  text  slots
 * flags: B branch, J jump, L loop, C call (from the opcode flags of any slot); targets: PC-relative operand values (comma
 * separated); text: objdump-like ("{ op a, b; op c }" for FLIX bundles); slots: per slot
 * "slot|opcode|slotword hex|operand=field:value:io ..." joined with " ;; ", and register reads/writes as R:..., W:...
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ansidecl.h"
#include <xtensa-isa.h>
#include "xtensa-isa-internal.h"
#include XTENSA_MODULES_C

static xtensa_isa_internal *I = &xtensa_modules;

static void load(const unsigned char *p, size_t avail, uint32 *w)
{
  /* little-endian: byte i of the instruction is bits 8*(i%4).. of word i/4 */
  memset(w, 0, 4 * sizeof(uint32));
  for (size_t i = 0; i < 11 && i < avail; i++)
    w[i / 4] |= (uint32)p[i] << (8 * (i % 4));
}

static void reg_text(char *out, size_t n, int rf, uint32 v, int nregs)
{
  const char *sn = I->regfiles[rf].shortname;
  size_t k = 0;
  for (int i = 0; i < nregs; i++)
    k += snprintf(out + k, n - k, "%s%s%u", i ? ":" : "", sn, v + i);
}

int main(int argc, char **argv)
{
  if (argc < 3) { fprintf(stderr, "usage: %s IMAGE BASE [all]\n", argv[0]); return 2; }
  FILE *f = fopen(argv[1], "rb");
  if (!f) { perror(argv[1]); return 1; }
  fseek(f, 0, SEEK_END); long sz = ftell(f); fseek(f, 0, SEEK_SET);
  unsigned char *img = malloc(sz + 16);
  memset(img, 0, sz + 16);
  if (fread(img, 1, sz, f) != (size_t)sz) return 1;
  fclose(f);
  uint32 base = strtoul(argv[2], 0, 0);
  int all = argc > 3 && !strcmp(argv[3], "all");
  char line[64];
  long idx = -1;
  for (;;) {
    uint32 addr;
    if (all) { if (++idx >= sz) break; addr = base + idx; }
    else { if (!fgets(line, sizeof line, stdin)) break; addr = strtoul(line, 0, 16); }
    if (addr < base || addr >= base + (uint32)sz) continue;
    uint32 insn[4], slot[4];
    load(img + (addr - base), sz - (addr - base), insn);
    int fmt = I->format_decode_fn(insn);
    if (fmt < 0) { printf("%x\t0\t-\t\t\t(bad format)\t\n", addr); continue; }
    xtensa_format_internal *F = &I->formats[fmt];
    int len = F->length;
    char text[1024] = "", slots[4096] = "", targets[256] = "", flags[8] = "";
    size_t tk = 0, sk = 0, gk = 0;
    int bad = 0, fB = 0, fJ = 0, fL = 0, fC = 0;
    if (F->num_slots > 1) tk += snprintf(text + tk, sizeof text - tk, "{ ");
    for (int s = 0; s < F->num_slots; s++) {
      int sid = F->slot_id[s];
      xtensa_slot_internal *S = &I->slots[sid];
      memset(slot, 0, sizeof slot);
      S->get_fn(insn, slot);
      int op = S->opcode_decode_fn(slot);
      if (s) { tk += snprintf(text + tk, sizeof text - tk, "; "); sk += snprintf(slots + sk, sizeof slots - sk, " ;; "); }
      if (op < 0) {
        bad = 1;
        tk += snprintf(text + tk, sizeof text - tk, "(bad %s)", S->name);
        sk += snprintf(slots + sk, sizeof slots - sk, "%s|?|%08x", S->name, slot[0]);
        continue;
      }
      xtensa_opcode_internal *O = &I->opcodes[op];
      fB |= O->flags & XTENSA_OPCODE_IS_BRANCH; fJ |= O->flags & XTENSA_OPCODE_IS_JUMP;
      fL |= O->flags & XTENSA_OPCODE_IS_LOOP; fC |= O->flags & XTENSA_OPCODE_IS_CALL;
      xtensa_iclass_internal *C = &I->iclasses[O->iclass_id];
      tk += snprintf(text + tk, sizeof text - tk, "%s", O->name);
      sk += snprintf(slots + sk, sizeof slots - sk, "%s|%s|%08x%08x|", S->name, O->name, slot[1], slot[0]);
      int nvis = 0;
      for (int a = 0; a < C->num_operands; a++) {
        int oid = C->operands[a].u.operand_id;
        char io = C->operands[a].inout;
        int hidden = io == 's';  /* libisa: "sout" operands are invisible and count as outputs */
        if (hidden) io = 'o';
        xtensa_operand_internal *P = &I->operands[oid];
        if (P->field_id < 0 || !S->get_field_fns[P->field_id]) {  /* implicit operand */
          sk += snprintf(slots + sk, sizeof slots - sk, " %s=implicit:%c", P->name, io);
          continue;
        }
        uint32 raw = S->get_field_fns[P->field_id](slot), v = raw;
        if (P->decode && P->decode(&v)) bad = 1;
        if (P->flags & XTENSA_OPERAND_IS_PCRELATIVE) {
          if (P->undo_reloc) P->undo_reloc(&v, addr);  /* relative -> absolute, as a disassembler needs */
          gk += snprintf(targets + gk, sizeof targets - gk, "%s%x", gk ? "," : "", v);
        }
        char vt[64];
        if (P->flags & XTENSA_OPERAND_IS_REGISTER) reg_text(vt, sizeof vt, P->regfile, v, P->num_regs);
        else if (P->flags & XTENSA_OPERAND_IS_PCRELATIVE) snprintf(vt, sizeof vt, "0x%x", v);
        else snprintf(vt, sizeof vt, "%d", (int)v);
        sk += snprintf(slots + sk, sizeof slots - sk, " %s=%u:%s:%c", P->name, raw, vt, io);
        if (hidden || (P->flags & XTENSA_OPERAND_IS_INVISIBLE)) continue;
        tk += snprintf(text + tk, sizeof text - tk, "%s%s", nvis++ ? ", " : " ", vt);
      }
      for (int a = 0; a < C->num_stateOperands; a++)
        sk += snprintf(slots + sk, sizeof slots - sk, " state:%s:%c",
                       I->states[C->stateOperands[a].u.state].name, C->stateOperands[a].inout);
    }
    if (F->num_slots > 1) tk += snprintf(text + tk, sizeof text - tk, " }");
    snprintf(flags, sizeof flags, "%s%s%s%s", fB ? "B" : "", fJ ? "J" : "", fL ? "L" : "", fC ? "C" : "");
    printf("%x\t%d\t%s\t%s\t%s\t%s\t%s\n", addr, bad ? -len : len, F->name, flags, targets, text, slots);
  }
  return 0;
}
