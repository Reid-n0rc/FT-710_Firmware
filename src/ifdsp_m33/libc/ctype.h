/*
 * FT-710 IFDSP M33 (T24): <ctype.h> as the image's C library (NXP Redlib, closed source) implements it: one flag byte
 * per character in a table of 384 entries (0x87D04): 128 zeros for negative signed chars, then characters 0..255
 * (entry 0 at 0x87D84) [fact: console_rx_char tests (0x87D84)[c] & 1 for white space, tolower 0x84E24 indexes
 * base + 0x80; values read from the image]. The table's real name is not known.
 */
#ifndef T24_CTYPE_H_
#define T24_CTYPE_H_

#define _CT_SPACE 0x01U /* \t \n \v \f \r and space */
#define _CT_PUNCT 0x02U
#define _CT_BLANK 0x04U /* space */
#define _CT_LOWER 0x08U
#define _CT_UPPER 0x10U
#define _CT_DIGIT 0x20U
#define _CT_CNTRL 0x40U
#define _CT_XDIGIT 0x80U /* a-f, A-F (digits have _CT_DIGIT) */

extern const unsigned char redlib_ctype[384];
#define redlib_ctype_table (redlib_ctype + 128)

#define isspace(c)  (redlib_ctype_table[(unsigned char)(c)] & _CT_SPACE)
#define isdigit(c)  (redlib_ctype_table[(unsigned char)(c)] & _CT_DIGIT)
#define isupper(c)  (redlib_ctype_table[(unsigned char)(c)] & _CT_UPPER)
#define islower(c)  (redlib_ctype_table[(unsigned char)(c)] & _CT_LOWER)
#define isalpha(c)  (redlib_ctype_table[(unsigned char)(c)] & (_CT_UPPER | _CT_LOWER))
#define isxdigit(c) (redlib_ctype_table[(unsigned char)(c)] & (_CT_DIGIT | _CT_XDIGIT))

int tolower(int c);
int toupper(int c);

#endif /* T24_CTYPE_H_ */
