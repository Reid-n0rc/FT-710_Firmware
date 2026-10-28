/* xtensa_isa_dump.c -- dump a Cadence libisa core description (xtensa-modules.c) as JSON.
 *
 * Part of tools/xtensa_sleigh_gen.py (T21a, issue #97). Build and run by the generator:
 *   cc -O1 -w -I<shim> -DMODULES='"<path>/xtensa-modules.c"' xtensa_isa_dump.c -o dump && ./dump > model.json
 * The shim headers (ansidecl.h, xtensa-isa.h, xtensa-isa-internal.h) are written by the generator;
 * they declare the libisa table layout that xtensa-modules.c initialises.
 *
 * Everything that the generator needs and that is code rather than data in xtensa-modules.c is
 * measured here by probing the functions:
 *   - slot get functions: which bundle bit lands in which slot bit (they are pure bit moves);
 *   - field get functions (per slot): which slot bit lands in which field bit;
 *   - opcode encode functions (per slot): the fixed opcode bits;
 *   - operand decode functions: the full value table (fields up to 20 bits) or samples;
 *   - operand undo_reloc (PC-relative operands): samples to fit address = f(pc) + value;
 *   - slot decode functions: random samples, so the generator can check its decode model.
 * No libisa code from binutils is needed: the tables are read directly.
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "xtensa-isa.h"
#include "xtensa-isa-internal.h"
#include MODULES

#define NW 4 /* words in an insn / slot buffer (insn_size 11 -> 3 words; one spare) */

static xtensa_isa_internal *I = &xtensa_modules;

static void jstr(const char *s) {
  putchar('"');
  for (; s && *s; s++) {
    if (*s == '"' || *s == '\\') putchar('\\');
    putchar(*s);
  }
  putchar('"');
}

static unsigned long long rng = 0x9E3779B97F4A7C15ULL;
static uint32 rnd32(void) {
  rng ^= rng << 13; rng ^= rng >> 7; rng ^= rng << 17;
  return (uint32)(rng >> 16);
}

/* Width of a slot in bits: highest slot bit any bundle bit maps to, + 1. */
static int slot_width[64];
static int slot_map[64][128]; /* slot bit -> bundle bit, -1 if none */

static void probe_slots(void) {
  int s, b, w, k;
  for (s = 0; s < I->num_slots; s++) {
    xtensa_slot_internal *sl = &I->slots[s];
    int fmt = -1, len = 0;
    for (k = 0; k < I->num_formats; k++) {
      int j;
      for (j = 0; j < I->formats[k].num_slots; j++)
        if (I->formats[k].slot_id[j] == s) fmt = k;
    }
    len = I->formats[fmt].length;
    for (k = 0; k < 128; k++) slot_map[s][k] = -1;
    slot_width[s] = 0;
    for (b = 0; b < len * 8; b++) {
      uint32 insn[NW], sb[NW];
      memset(insn, 0, sizeof insn);
      memset(sb, 0, sizeof sb);
      insn[b / 32] = 1u << (b % 32);
      sl->get_fn(insn, sb);
      for (w = 0; w < NW; w++)
        for (k = 0; k < 32; k++)
          if (sb[w] & (1u << k)) {
            int sbit = w * 32 + k;
            if (slot_map[s][sbit] != -1) { fprintf(stderr, "slot %d bit %d mapped twice\n", s, sbit); exit(1); }
            slot_map[s][sbit] = b;
            if (sbit + 1 > slot_width[s]) slot_width[s] = sbit + 1;
          }
    }
  }
}

/* Probe a field getter on a slot: field bit i <- slot bit out[i]. Returns width. */
static uint32 field_const; /* value of an implicit (constant) field */
static int probe_field(xtensa_get_field_fn fn, int *out) {
  int b, k, width = 0;
  uint32 zero[NW] = {0, 0, 0, 0};
  for (k = 0; k < 32; k++) out[k] = -1;
  field_const = fn(zero);
  if (field_const) return -1; /* implicit field: constant, reads no bits */
  for (b = 0; b < 96; b++) {
    uint32 sb[NW];
    uint32 v;
    memset(sb, 0, sizeof sb);
    sb[b / 32] = 1u << (b % 32);
    v = fn(sb);
    for (k = 0; k < 32; k++)
      if (v & (1u << k)) {
        if (out[k] != -1) { fprintf(stderr, "field bit %d from 2 slot bits\n", k); exit(1); }
        out[k] = b;
        if (k + 1 > width) width = k + 1;
      }
  }
  return width;
}

int main(void) {
  int i, j, s, f;
  probe_slots();
  printf("{\n");
  /* register files */
  printf("\"regfiles\": [");
  for (i = 0; i < I->num_regfiles; i++) {
    xtensa_regfile_internal *r = &I->regfiles[i];
    printf("%s{\"name\":", i ? "," : ""); jstr(r->name);
    printf(",\"short\":"); jstr(r->shortname);
    printf(",\"parent\":%d,\"bits\":%d,\"entries\":%d}", r->parent, r->num_bits, r->num_entries);
  }
  printf("],\n\"states\": [");
  for (i = 0; i < I->num_states; i++) {
    printf("%s{\"name\":", i ? "," : ""); jstr(I->states[i].name);
    printf(",\"bits\":%d,\"flags\":%u}", I->states[i].num_bits, I->states[i].flags);
  }
  printf("],\n\"sysregs\": [");
  for (i = 0; i < I->num_sysregs; i++) {
    printf("%s{\"name\":", i ? "," : ""); jstr(I->sysregs[i].name);
    printf(",\"number\":%d,\"user\":%d}", I->sysregs[i].number, I->sysregs[i].is_user);
  }
  printf("],\n\"interfaces\": [");
  for (i = 0; i < I->num_interfaces; i++) {
    printf("%s{\"name\":", i ? "," : ""); jstr(I->interfaces[i].name);
    printf(",\"bits\":%d,\"inout\":\"%c\"}", I->interfaces[i].num_bits, I->interfaces[i].inout);
  }
  printf("],\n\"formats\": [");
  for (i = 0; i < I->num_formats; i++) {
    xtensa_format_internal *fm = &I->formats[i];
    uint32 insn[NW];
    memset(insn, 0, sizeof insn);
    fm->encode_fn(insn);
    printf("%s{\"name\":", i ? "," : ""); jstr(fm->name);
    printf(",\"length\":%d,\"slots\":[", fm->length);
    for (j = 0; j < fm->num_slots; j++) printf("%s%d", j ? "," : "", fm->slot_id[j]);
    printf("],\"encode\":[%u,%u,%u]", insn[0], insn[1], insn[2]);
    /* decode check of the encoded template */
    printf(",\"decode_of_encode\":%d}", I->format_decode_fn(insn));
  }
  printf("],\n\"slots\": [");
  for (s = 0; s < I->num_slots; s++) {
    xtensa_slot_internal *sl = &I->slots[s];
    printf("%s\n{\"name\":", s ? "," : ""); jstr(sl->name);
    printf(",\"format\":"); jstr(sl->format);
    printf(",\"position\":%d,\"nop\":", sl->position); jstr(sl->nop_name);
    printf(",\"width\":%d,\"map\":[", slot_width[s]);
    for (j = 0; j < slot_width[s]; j++) printf("%s%d", j ? "," : "", slot_map[s][j]);
    printf("],\"fields\":{");
    {
      int first = 1;
      for (f = 0; f < I->num_fields; f++) {
        int bits[32], w;
        if (!sl->get_field_fns[f]) continue;
        w = probe_field(sl->get_field_fns[f], bits);
        printf("%s\"%d\":", first ? "" : ",", f);
        first = 0;
        if (w < 0) { printf("%u", field_const); continue; }
        printf("[");
        for (j = 0; j < w; j++) printf("%s%d", j ? "," : "", bits[j]);
        printf("]");
      }
    }
    printf("},\"samples\":[");
    /* random decode samples (slot buffer words, opcode) */
    for (j = 0; j < 4000; j++) {
      uint32 sb[NW];
      int w, op;
      memset(sb, 0, sizeof sb);
      for (w = 0; w * 32 < slot_width[s]; w++) {
        int nb = slot_width[s] - w * 32;
        sb[w] = rnd32() ^ (rnd32() << 16);
        if (nb < 32) sb[w] &= (1u << nb) - 1;
      }
      op = sl->opcode_decode_fn(sb);
      printf("%s[%u,%u,%u,%d]", j ? "," : "", sb[0], sb[1], sb[2], op);
    }
    printf("]}");
  }
  printf("],\n\"operands\": [");
  for (i = 0; i < I->num_operands; i++) {
    xtensa_operand_internal *o = &I->operands[i];
    int width = -1, v;
    /* field width: from any slot that has the field */
    if (o->field_id >= 0)
      for (s = 0; s < I->num_slots && width < 0; s++)
        if (I->slots[s].get_field_fns[o->field_id]) {
          int bits[32];
          width = probe_field(I->slots[s].get_field_fns[o->field_id], bits);
          if (width < 0) width = 0;
        }
    printf("%s\n{\"name\":", i ? "," : ""); jstr(o->name);
    printf(",\"field\":%d,\"regfile\":%d,\"num_regs\":%d,\"flags\":%u,\"width\":%d",
           o->field_id, o->regfile, o->num_regs, o->flags, width);
    printf(",\"decode\":");
    if (!o->decode) printf("null");
    else if (width >= 0 && width <= 20) {
      printf("[");
      for (v = 0; v < (1 << width); v++) {
        uint32 x = (uint32)v;
        int err = o->decode(&x);
        if (err) printf("%snull", v ? "," : "");
        else printf("%s%u", v ? "," : "", x);
      }
      printf("]");
    } else printf("\"wide\"");
    printf(",\"reloc\":");
    if ((o->flags & XTENSA_OPERAND_IS_PCRELATIVE) && o->undo_reloc) {
      static const uint32 pcs[] = {0, 1, 2, 3, 4, 5, 6, 7, 0x1000, 0x1001, 0x1002, 0x1003, 0x20000d, 0x7ffffff};
      static const uint32 vals[] = {0, 0x10, 0x100, 0xfffffff0u};
      int a, b, first = 1;
      printf("[");
      for (a = 0; a < (int)(sizeof pcs / sizeof pcs[0]); a++)
        for (b = 0; b < (int)(sizeof vals / sizeof vals[0]); b++) {
          uint32 x = vals[b];
          int err = o->undo_reloc(&x, pcs[a]);
          printf("%s[%u,%u,%u,%d]", first ? "" : ",", pcs[a], vals[b], x, err);
          first = 0;
        }
      printf("]");
    } else printf("null");
    printf("}");
  }
  printf("],\n\"iclasses\": [");
  for (i = 0; i < I->num_iclasses; i++) {
    xtensa_iclass_internal *c = &I->iclasses[i];
    printf("%s\n{\"ops\":[", i ? "," : "");
    for (j = 0; j < c->num_operands; j++)
      printf("%s[%d,\"%c\"]", j ? "," : "", c->operands[j].u.operand_id, c->operands[j].inout);
    printf("],\"states\":[");
    for (j = 0; j < c->num_stateOperands; j++)
      printf("%s[%d,\"%c\"]", j ? "," : "", c->stateOperands[j].u.state, c->stateOperands[j].inout);
    printf("],\"intf\":[");
    for (j = 0; j < c->num_interfaceOperands; j++)
      printf("%s%d", j ? "," : "", c->interfaceOperands[j]);
    printf("]}");
  }
  printf("],\n\"opcodes\": [");
  for (i = 0; i < I->num_opcodes; i++) {
    xtensa_opcode_internal *op = &I->opcodes[i];
    int first = 1;
    printf("%s\n{\"name\":", i ? "," : ""); jstr(op->name);
    printf(",\"iclass\":%d,\"flags\":%u,\"enc\":{", op->iclass_id, op->flags);
    for (s = 0; s < I->num_slots; s++) {
      uint32 sb[NW];
      if (!op->encode_fns[s]) continue;
      memset(sb, 0, sizeof sb);
      op->encode_fns[s](sb);
      printf("%s\"%d\":[%u,%u,%u,%d]", first ? "" : ",", s, sb[0], sb[1], sb[2],
             I->slots[s].opcode_decode_fn(sb));
      first = 0;
    }
    printf("}}");
  }
  printf("]\n}\n");
  return 0;
}
