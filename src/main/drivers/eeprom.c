/* BR25G256 SPI EEPROM (Q1008, 32 KB) driver of the MAIN image, recreated for T24.
 *
 * The SPI is bit-banged on port E (docs/code/main/eeprom.md): PE0 = /CS, PE5 = SCK, PE6 = MOSI (PORTE.PODR),
 * PE7 = MISO (PORTE.PIDR). Mode 0, MSB first: the data bit is set while SCK is low and sampled after SCK rises.
 * Every port access below is the image's, in its order [fact: the disassembly at each function's address]. */
#include "iodefine.h"
#include "main.h"

#define EE_CS   0x01u    /* PE0 */
#define EE_SCK  0x20u    /* PE5 */
#define EE_MOSI 0x40u    /* PE6 */
#define EE_MISO 0x80u    /* PE7 */

/* BR25G256 commands (the datasheet's instruction set; the values are in the code) */
#define EE_WRITE 0x02u
#define EE_READ  0x03u
#define EE_RDSR  0x05u
#define EE_WREN  0x06u
#define EE_PAGE  64u     /* write page size [fact: 0x40 - (addr & 0x3F) in eeprom_write] */

void eeprom_spi_tx(uint8_t b);
uint8_t eeprom_spi_rx(void);

/* eeprom_spi_tx 0xFFFB15AA: one byte out on MOSI, MSB first; SCK low at the end */
void eeprom_spi_tx(uint8_t b)
{
    uint8_t i;

    PORTE_PODR &= (uint8_t)~EE_SCK;
    for (i = 0; i < 8u; i++) {
        if (b & 0x80u)
            PORTE_PODR |= EE_MOSI;
        else
            PORTE_PODR &= (uint8_t)~EE_MOSI;
        PORTE_PODR |= EE_SCK;
        b = (uint8_t)(b << 1);
        PORTE_PODR &= (uint8_t)~EE_SCK;
    }
}

/* eeprom_spi_rx 0xFFFB15EF: one byte in from MISO, MSB first, sampled while SCK is high */
uint8_t eeprom_spi_rx(void)
{
    uint8_t v = 0, i;

    for (i = 0; i < 8u; i++) {
        v = (uint8_t)(v << 1);
        PORTE_PODR |= EE_SCK;
        if (PORTE_PIDR & EE_MISO)
            v |= 0x01u;
        PORTE_PODR &= (uint8_t)~EE_SCK;
    }
    return v;
}

/* eeprom_read 0xFFFB14A4: READ + 16-bit address, then n bytes */
void eeprom_read(uint16_t addr, uint8_t *buf, uint16_t n)
{
    uint16_t i;

    PORTE_PODR &= (uint8_t)~EE_CS;
    eeprom_spi_tx(EE_READ);
    eeprom_spi_tx((uint8_t)(addr >> 8));
    eeprom_spi_tx((uint8_t)addr);
    for (i = 0; i < n; i++)
        buf[i] = eeprom_spi_rx();
    PORTE_PODR |= EE_CS;
}

/* eeprom_write 0xFFFB14ED: in page-sized pieces; for each one, poll RDSR until WIP (bit 0) is clear, WREN, then
 * WRITE + address + data. Two nops separate the WREN and WRITE chip selects (0xFFFB1558) */
void eeprom_write(uint16_t addr, uint8_t *buf, uint16_t n)
{
    uint8_t chunk, i, sr;

    while (n != 0u) {
        chunk = (uint8_t)(EE_PAGE - (addr & (EE_PAGE - 1u)));
        if (chunk >= n)
            chunk = (uint8_t)n;
        n = (uint16_t)(n - chunk);
        do {
            PORTE_PODR &= (uint8_t)~EE_CS;
            eeprom_spi_tx(EE_RDSR);
            sr = eeprom_spi_rx();
            PORTE_PODR |= EE_CS;
        } while (sr & 0x01u);
        PORTE_PODR &= (uint8_t)~EE_CS;
        eeprom_spi_tx(EE_WREN);
        PORTE_PODR |= EE_CS;
        __asm__ volatile("nop\n\tnop");
        PORTE_PODR &= (uint8_t)~EE_CS;
        eeprom_spi_tx(EE_WRITE);
        eeprom_spi_tx((uint8_t)(addr >> 8));
        eeprom_spi_tx((uint8_t)addr);
        for (i = 0; i < chunk; i++)
            eeprom_spi_tx(*buf++);
        PORTE_PODR |= EE_CS;
        addr = (uint16_t)(addr + chunk);
    }
}
