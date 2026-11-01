/* The settings store of the MAIN image, recreated for T24: the RAM mirror of the BR25G256 EEPROM and the functions
 * that load it at boot, save parts of it and reset it to the ROM defaults (docs/code/main/eeprom.md).
 *
 * The whole EEPROM 0x0000..0x5836 is mirrored byte for byte in RAM at 0x464F, so every block is saved as
 * eeprom_write(ee, &ee_mirror[ee], n) [fact: each save below loads 0x464F + the EEPROM address as the buffer;
 * eeprom.md "EEPROM address map"]. Every save except the calibration and destination code is bracketed by
 * eeprom_hdr_update(0) / (1): the header's state byte is 0 while a save is in progress, so a power cut in the middle
 * is seen at the next boot (eeprom_load_all). */
#include "iodefine.h"
#include "main.h"
#include "main_ram.h"

/* EEPROM addresses of the blocks (eeprom.md "EEPROM address map") [fact: the write calls below] */
#define EE_HDR        0x0000u   /* 10-byte header: stamp[5], save count (big endian)[4], state */
#define EE_HDR_COUNT  5u
#define EE_HDR_STATE  9u
#define EE_HDR_LEN    10u
#define EE_CFG105     0x000Au   /* factory alignment table, 261 items */
#define EE_CFG105_LEN 0x105u
#define EE_DEST       0x010Fu   /* destination code, 3 bytes */
#define EE_DEST_LEN   3u
#define EE_BANDSTACK  0x0112u   /* band stack VFO-A; VFO-B 0xCA8 further */
#define EE_BANDSTACK_B_OFS 0xCA8u
#define EE_BS_SLOT    0x438u    /* 12 bands x 90 bytes */
#define EE_REC        0x5Au     /* one VFO / memory record */
#define EE_BS_LEVEL   0x1A62u   /* band-stack slot index per band, 2 x 12 */
#define EE_BS_LEVEL_LEN 0x18u
#define EE_MEMHDR     0x1A7Au   /* memory header: channels of A and B, 133 valid bytes */
#define EE_MEMHDR_LEN 0x87u
#define EE_MEMCH      0x1B01u   /* 133 memory channels */
#define EE_IMAGE_LEN  0x2F49u   /* header + all channels (E9 clone) */
#define EE_QMB        0x49C3u   /* QMB header 0x11 bytes, then 10 records */
#define EE_QMB_REC    0x49D4u
#define EE_QMB_LEN    0x395u
#define EE_MSG_CW     0x4D58u   /* message memory type 0: 5 x 0x98 */
#define EE_MSG_KEYER  0x5050u   /* keyer texts (KM): 5 x 0x33 */
#define EE_MSG_TEXT   0x514Fu   /* text slots (EM): 5 x 0x32 */
#define EE_ATU_MEM    0x5249u   /* tuner memory, 0x192 bytes */
#define EE_ATU_MEM_LEN 0x192u
#define EE_OPSTATE    0x53DBu   /* operating state: menus, VFOs, bands */
#define EE_OPSTATE_LEN 0x45Cu
#define EE_SIZE       0x5837u
#define EE_SAVE_ALL_LEN 0x5725u /* 0x0112..0x5836 */

/* mirror indices (= EEPROM addresses) of parts of the operating-state block: RAM address - 0x464F [fact:
 * settings_defaults] */
#define OPS_ZERO_9C17   (0x9C17u - 0x464Fu)   /* 30 bytes from ROM 0xFFF80FD6 (all 0, eeprom.md) */
#define OPS_SCOPE       (0x9C35u - 0x464Fu)   /* 0x28 bytes from ROM 0xFFF80E22 */
#define OPS_FLAGS_9C5D  (0x9C5Du - 0x464Fu)   /* 12 flag bytes 0x9C5D..0x9C68 */
#define OPS_BANDMEM     (0x9C69u - 0x464Fu)   /* band memories, 0xA0 bytes from ROM 0xFFF80D82 */
#define OPS_VFO_STATE   (0x9DBEu - 0x464Fu)   /* VFO states and the rest of the block, 200 bytes */

/* eeprom_init 0xFFFB01F3: /CS high, SCK low, then with P65 high WRSR (0x01) = 0x80 (SRWD set, no block protect)
 * [fact: the port writes; P65 as the chip's /WP is an inference, eeprom.md] */
void eeprom_init(void)
{
    PORTE_PODR |= 0x01u;            /* PE0 /CS high */
    PORTE_PODR &= (uint8_t)~0x20u;  /* PE5 SCK low */
    PORT6_PODR |= 0x20u;            /* P65 high: writes to the status register allowed */
    PORTE_PODR &= (uint8_t)~0x01u;
    eeprom_spi_tx(0x01u);           /* WRSR */
    eeprom_spi_tx(0x80u);
    PORTE_PODR |= 0x01u;
    PORT6_PODR &= (uint8_t)~0x20u;
}

/* eeprom_load_all 0xFFFB0229: read the header; state 1 = a complete image: read all of it. State 0 = a save was
 * cut off: keep the calibration and the destination code, the rest from the defaults. Anything else (a blank
 * EEPROM): clear the header, full defaults, save calibration and destination [fact] */
void eeprom_load_all(void)
{
    uint8_t state;
    uint8_t i;

    eeprom_read(EE_HDR, &ee_mirror[EE_HDR], EE_HDR_LEN);
    state = ee_mirror[EE_HDR + EE_HDR_STATE];
    if (state == 1u) {
        eeprom_read(EE_HDR, &ee_mirror[EE_HDR], EE_SIZE);
        return;
    }
    if (state == 0u) {
        eeprom_read(EE_CFG105, &ee_mirror[EE_CFG105], EE_CFG105_LEN);
        eeprom_read(EE_DEST, &ee_mirror[EE_DEST], EE_DEST_LEN);
        settings_defaults(0);
    } else {
        for (i = 0; i < EE_HDR_LEN; i++)
            ee_mirror[EE_HDR + i] = 0;
        settings_defaults(1);
        eeprom_save_cfg105();
        eeprom_save_dest();
    }
    ui_defaults_loaded = 1;
}

/* eeprom_hdr_update 0xFFFB142B: save count + 1 (big endian in header bytes 5..8), state byte, write the header */
void eeprom_hdr_update(uint8_t state)
{
    uint8_t *count = &ee_mirror[EE_HDR + EE_HDR_COUNT];
    uint32_t n = 0;
    uint8_t i;

    for (i = 0; i < 4u; i++)
        n |= (uint32_t)count[i] << ((3u - i) * 8u);
    n++;
    for (i = 0; i < 4u; i++)
        count[i] = (uint8_t)(n >> ((3u - i) * 8u));
    ee_mirror[EE_HDR + EE_HDR_STATE] = state;
    eeprom_write(EE_HDR, &ee_mirror[EE_HDR], EE_HDR_LEN);
}

/* eeprom_save_all 0xFFFB02AF: everything after the calibration and destination (power-down, first boot) */
void eeprom_save_all(void)
{
    eeprom_hdr_update(0);
    eeprom_write(EE_BANDSTACK, &ee_mirror[EE_BANDSTACK], EE_SAVE_ALL_LEN);
    eeprom_hdr_update(1);
}

/* eeprom_save_opstate 0xFFFB02CF: the operating state and the band-stack slot indices */
void eeprom_save_opstate(void)
{
    eeprom_hdr_update(0);
    eeprom_write(EE_OPSTATE, &ee_mirror[EE_OPSTATE], EE_OPSTATE_LEN);
    eeprom_write(EE_BS_LEVEL, &ee_mirror[EE_BS_LEVEL], EE_BS_LEVEL_LEN);
    eeprom_hdr_update(1);
}

/* eeprom_save_bandstack 0xFFFB0303: one 90-byte band-stack record (VFO-B when vfo_b != 0) from rec; nothing while
 * the supply is too low. The EEPROM address is computed in 16 bits [fact: mov.w at 0xFFFB0331/0xFFFB033C] */
void eeprom_save_bandstack(uint8_t vfo_b, uint8_t band, uint8_t slot, uint8_t *rec)
{
    uint16_t ee = EE_BANDSTACK;

    if (supply_undervolt_check() == 1u)
        return;
    if (vfo_b != 0u)
        ee = (uint16_t)(ee + EE_BANDSTACK_B_OFS);
    ee = (uint16_t)(ee + slot * EE_BS_SLOT);
    ee = (uint16_t)(ee + band * EE_REC);
    eeprom_hdr_update(0);
    eeprom_write(ee, rec, EE_REC);
    eeprom_hdr_update(1);
}

/* eeprom_save_image 0xFFFB0356: memory header and all channels (after an E9 clone) */
void eeprom_save_image(void)
{
    eeprom_hdr_update(0);
    eeprom_write(EE_MEMHDR, &ee_mirror[EE_MEMHDR], EE_IMAGE_LEN);
    eeprom_hdr_update(1);
}

/* eeprom_save_memch 0xFFFB0376: memory header and channel ch */
void eeprom_save_memch(uint8_t ch)
{
    uint32_t ofs;

    if (supply_undervolt_check() == 1u)
        return;
    eeprom_hdr_update(0);
    eeprom_write(EE_MEMHDR, &ee_mirror[EE_MEMHDR], EE_MEMHDR_LEN);
    ofs = (uint32_t)ch * EE_REC;
    eeprom_write((uint16_t)(ofs + EE_MEMCH), &ee_mirror[ofs + EE_MEMCH], EE_REC);
    eeprom_hdr_update(1);
}

/* eeprom_save_qmb 0xFFFB03C1: the whole QMB block */
void eeprom_save_qmb(void)
{
    eeprom_hdr_update(0);
    eeprom_write(EE_QMB, &ee_mirror[EE_QMB], EE_QMB_LEN);
    eeprom_hdr_update(1);
}

/* eeprom_save_qmb_slot 0xFFFB03E1: the QMB header (its length is the distance to the first record) and record slot */
void eeprom_save_qmb_slot(uint8_t slot)
{
    uint16_t hdr_len = (uint16_t)(&ee_mirror[EE_QMB_REC] - &ee_mirror[EE_QMB]);
    uint32_t ofs;

    if (supply_undervolt_check() == 1u)
        return;
    eeprom_hdr_update(0);
    eeprom_write(EE_QMB, &ee_mirror[EE_QMB], hdr_len);
    ofs = (uint32_t)slot * EE_REC;
    eeprom_write((uint16_t)(ofs + hdr_len + EE_QMB), &ee_mirror[ofs + EE_QMB_REC], EE_REC);
    eeprom_hdr_update(1);
}

/* eeprom_save_msg 0xFFFB0450: message n (1..5) of a type: 0 = CW message memory, 1 = keyer text (KM), anything
 * else = text slot (EM); types above 2 are ignored. The offset is computed in 16 bits [fact: mov.w 6[r0]] */
void eeprom_save_msg(int32_t type, int32_t n)
{
    uint16_t ofs, base, len;

    if (supply_undervolt_check() == 1u || type > 2)
        return;
    if (n < 1 || n > 5)
        return;
    n--;
    eeprom_hdr_update(0);
    if (type == 0) {
        base = EE_MSG_CW;
        len = 0x98u;
    } else if (type == 1) {
        base = EE_MSG_KEYER;
        len = 0x33u;
    } else {
        base = EE_MSG_TEXT;
        len = 0x32u;
    }
    ofs = (uint16_t)(n * len);
    eeprom_write((uint16_t)(ofs + base), &ee_mirror[(uint32_t)ofs + base], len);
    eeprom_hdr_update(1);
}

/* eeprom_save_atu_mem 0xFFFB0509: the tuner memory */
void eeprom_save_atu_mem(void)
{
    if (supply_undervolt_check() == 1u)
        return;
    eeprom_hdr_update(0);
    eeprom_write(EE_ATU_MEM, &ee_mirror[EE_ATU_MEM], EE_ATU_MEM_LEN);
    eeprom_hdr_update(1);
}

/* eeprom_save_cfg105 0xFFFB0532 / eeprom_save_dest 0xFFFB0544: no header update, no supply check [fact] */
void eeprom_save_cfg105(void)
{
    eeprom_write(EE_CFG105, &ee_mirror[EE_CFG105], EE_CFG105_LEN);
}

void eeprom_save_dest(void)
{
    eeprom_write(EE_DEST, &ee_mirror[EE_DEST], EE_DEST_LEN);
}

static void copy_bytes(uint8_t *dst, const uint8_t *src, uint32_t n)
{
    while (n--)
        *dst++ = *src++;
}

static void clear_bytes(uint8_t *dst, uint32_t n)
{
    while (n--)
        *dst++ = 0;
}

/* settings_defaults 0xFFFB0558: everything from the ROM defaults; factory = 1 also the calibration table and the
 * destination code (eeprom.md "Defaults", steps 1..8) [fact] */
void settings_defaults(uint8_t factory)
{
    if (factory == 1u) {
        copy_bytes(&ee_mirror[EE_CFG105], cfg105_defaults, EE_CFG105_LEN);
        copy_bytes(&ee_mirror[EE_DEST], dest_defaults, EE_DEST_LEN);
    }
    defaults_vfo();
    defaults_bandstack();
    defaults_qmb();
    defaults_memch();
    defaults_msg();
    clear_bytes(&ee_mirror[EE_ATU_MEM], EE_ATU_MEM_LEN);
    copy_bytes(&ee_mirror[OPS_BANDMEM], bandmem_defaults, 0xA0u);
    copy_bytes(&ee_mirror[OPS_SCOPE], scope_defaults, 0x28u);
    menu_defaults_load();
    /* 0x9C5D..0x9C68: all 0 except 0x9C60 = 1 [fact: the three mov.l at 0xFFFB05E5..0xFFFB05F3] */
    clear_bytes(&ee_mirror[OPS_FLAGS_9C5D], 12u);
    ee_mirror[OPS_FLAGS_9C5D + 3u] = 1;
    clear_bytes(&ee_mirror[OPS_VFO_STATE], 200u);
    copy_bytes(&ee_mirror[OPS_VFO_STATE], vfo_state_defaults, 0x10u);
    copy_bytes(&ee_mirror[OPS_ZERO_9C17], zero_9c17_defaults, 30u);
}

/* reset_memch 0xFFFB0636, reset_menu 0xFFFB063A: the reset menu's two partial resets */
void reset_memch(void)
{
    defaults_memch();
}

void reset_menu(void)
{
    menu_defaults_load();
}

/* eeprom_read_raw 0xFFFB063E, eeprom_write_raw 0xFFFB0651: plain wrappers for CAT SPR/SPW */
void eeprom_read_raw(uint16_t addr, uint8_t *buf, uint16_t n)
{
    eeprom_read(addr, buf, n);
}

void eeprom_write_raw(uint16_t addr, uint8_t *buf, uint16_t n)
{
    eeprom_write(addr, buf, n);
}
