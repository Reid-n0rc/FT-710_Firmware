# Inside the Yaesu FT-710: an illustrated guide

This guide explains how the FT-710's firmware works, in plain language and with pictures. It is for anyone who knows what a CPU, a serial
port and an FPGA are and wants to understand what goes on inside the radio. You don't need to read code. It summarises a long
reverse-engineering project on the owner's own radio. The detailed reference pages, with every address and every piece of evidence, live
elsewhere in this repository, and each chapter ends with links to them.

![Overview of the FT-710: four chips (DISPLAY, MAIN, SDR FPGA, IF DSP) inside the case, the links between them, the antenna, the speaker and the USB connection to a PC, with badges showing which chapter covers each part](img/00-guide-map.svg)

*Figure 0.1 — The radio in one picture. The numbered badges show which chapter covers each part.*

**How to read it.** Chapters 1–3 give the big picture: what is inside, how the chips talk, and what happens when you use the radio. Read
them in order. Chapters 4–8 can be read in any order. The glossary at the end defines every technical term; terms link to it the first
time they appear.

**How sure are we?** Plain statements were seen directly in the firmware or the service manual. Where the guide says *(inference)*, the
claim follows from the evidence but wasn't seen directly. *(guess)* marks an educated guess. Nothing in this guide has been tested on the
radio itself unless the text says so. The project's rule is that nothing is written to the radio without the owner's explicit approval.

**Colours.** Each chip keeps the same colour in every picture: blue for MAIN, green for DISPLAY, purple for the IF DSP,
orange for the SDR FPGA and grey for other hardware. Red marks something dangerous, and amber marks something to be careful with.
