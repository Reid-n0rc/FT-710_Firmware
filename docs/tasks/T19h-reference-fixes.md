# T19h — Fix reference-page issues found while writing the guide

**Status:** in progress · **Depends on:** T19a–T19g

## Goal
While writing the guide, the chapter writers found 26 issues in the reference pages: two pages disagreeing, stale text superseded by
later tasks, and small slips. They are listed under `## Reference issues` in T19a–T19g. For each one, check the code or data, fix the
reference page(s) with the correct [fact]/[inference]/[guess] tag and evidence, and correct the guide (`docs/guide/README.md`) wherever
it states, or deliberately avoids, the point.

## Plan
26 issues (T19a 3, T19b 4, T19c 4, T19d 4, T19e 3, T19f 6, T19g 2), numbered here as a1-a3, b1-b4, c1-c4, d1-d4, e1-e3, f1-f6, g1-g2.
Duplicates: b1 = e1 (supply ADC channel).
For each issue, in order of topic:
1. Settle it from evidence: decomp `decomp/<image>/*.c` (grep, targeted reads), the reference pages, the task files of the producing
   tasks (T15/T15b/T15e supersede T10c/T13), the service manual (`pdftotext -f N -l M`), and `build/renesas/*.txt` for RX651 registers.
   Ghidra only if the decompiles cannot settle a point (copy to `<PROJ>_T19h`).
2. Edit only the sentences concerned in the reference page(s): correct the claim with a tag and evidence, or mark superseded text
   ("superseded by T15e: ...") with a pointer; leave both views marked open where the evidence does not settle it.
3. Fix `docs/guide/README.md` where it states or avoided the point (plain language, addresses only in "Where to look").
4. Commit per issue or small group (`T19h: ...`), heartbeat after each group.
Groups: (1) MAIN ADC/power/encoder (b1/e1, b2, b3, b4); (2) SDR link + clocks (a1, a2, f1, f2, f6, g1, g2); (3) DSP link (a3, f3, f4, f5);
(4) DISPLAY (c1, c2, c4, e2, e3); (5) SFL + CAT (c3, d1-d4). Finish with Findings (one line each) and Follow-ups.

## Findings

## Follow-ups
