/*
 * FT-710 IFDSP M33 (T24): the three HiFi4 images in flash and their sizes, for BOARD_DSP_Init (dsp_support.c).
 * The images are Yaesu's DSP code: they are not in this repository. The Makefile passes their paths from the
 * decoded firmware (tools/bootstrap.sh writes build/FT-710_IFDSP_V0101_hifi4_{0_tcm,1_sram_text,2_sram_data}.bin).
 * Layout as in the image: 0x08001844, 0x08021E88, 0x0805A23C, then three size words at 0x0805D41C [fact].
 */
    .section .dspcode, "a", %progbits
    .align 2
    .global dsp_image0_tcm
dsp_image0_tcm:
    .incbin DSP_IMAGE0
dsp_image0_end:
    .global dsp_image1_sram_text
dsp_image1_sram_text:
    .incbin DSP_IMAGE1
dsp_image1_end:
    .global dsp_image2_sram_data
dsp_image2_sram_data:
    .incbin DSP_IMAGE2
dsp_image2_end:
    .align 2
    .global dsp_image0_size
dsp_image0_size:
    .word dsp_image0_end - dsp_image0_tcm
    .global dsp_image1_size
dsp_image1_size:
    .word dsp_image1_end - dsp_image1_sram_text
    .global dsp_image2_size
dsp_image2_size:
    .word dsp_image2_end - dsp_image2_sram_data
