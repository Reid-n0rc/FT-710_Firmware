/*
 * FT-710 DISPLAY (T24 round 9): the FAT file-system layer, 0x20140BE8..0x2014E1FF (docs/code/display/filesystem.md).
 *
 * The layer's characters are signed: its byte loads are ldrsb and its results sxtb [fact: fs_stricmp 0x2014D39C,
 * fs_toupper 0x2014D36C], so it was built with signed chars; fs_char_t keeps that. Which library it is stays
 * open (filesystem.md, "Open questions").
 */
#ifndef FS_H
#define FS_H

#include <stdint.h>

typedef signed char fs_char_t;
typedef uint16_t fs_wchar_t;

/* string and byte helpers (fs/fs_string.c) */
int fs_toupper(int c);
int fs_tolower(int c);
int sjis_is_lead(int c);
void fs_memset(void *dst, int c, uint32_t n, uint32_t block);
void fs_memcpy(void *dst, const void *src, uint32_t n);
int fs_strlen(const fs_char_t *s);
uint32_t fat_ld_word(const uint8_t *p);
uint32_t fat_ld_dword(const uint8_t *p);
void fat_st_word(uint8_t *p, uint32_t v);
void fat_st_dword(uint8_t *p, uint32_t v);

#endif
