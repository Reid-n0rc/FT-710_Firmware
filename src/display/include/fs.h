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

/* A drive record (0x74 bytes, a linked list from fs_drive_list 0x20808BA0): the device, the BPB fields that
 * fat_mount fills in, allocation hints, the FAT and directory sector caches, the cluster-use map and flags
 * [fact: the offsets of fat_mount 0x20148FCC, fs_drive_attach 0x2014A5DC, fat_clust2sect 0x20144980,
 * fat_table_sector_get 0x2014919C, clmap_clear 0x2014969C, fs_drive_sem_create 0x2014DD4C, sd_mount_volume
 * 0x2013E43C, sd_card_poll 0x2013FC68] */
typedef struct fs_drive
{
    struct fs_drive *next;    /* +0x00 */
    uint16_t spc;             /* +0x04: sectors per cluster */
    uint16_t rsv;             /* +0x06: reserved sectors (the FAT starts here) */
    uint16_t nfats;           /* +0x08 */
    uint16_t root_entries;    /* +0x0A: FAT12/16 root directory entries */
    uint32_t fat_size;        /* +0x0C: sectors per FAT */
    uint8_t fat_type;         /* +0x10: 0x0C, 0x10, 0x20 (FAT32) or 0x40 (exFAT, not mounted) */
    fs_char_t letter;         /* +0x11: drive letter, upper case */
    uint8_t _r12[2];
    uint32_t sectors;         /* +0x14: total sectors of the volume */
    int (*op)(struct fs_drive *d, int cmd, uint32_t a, uint32_t b, uint32_t c);   /* +0x18: driver entry */
    uint32_t ctx;             /* +0x1C: the driver's argument at attach */
    uint8_t _r20[4];
    const void *sd;           /* +0x24: the SD handle once attached (driver op 5) */
    uint32_t alloc_hint;      /* +0x28: where the next cluster search starts */
    uint32_t freed_hint;      /* +0x2C: the first cluster freed since */
    uint32_t first;           /* +0x30: first sector of the volume on the device */
    uint32_t root_cluster;    /* +0x34: FAT32 */
    uint8_t _r38[2];
    uint16_t fsinfo;          /* +0x3A: FAT32 FSInfo sector */
    uint32_t free_count;      /* +0x3C: FSInfo free clusters, -1 unknown */
    uint32_t next_free;       /* +0x40: FSInfo next free cluster, -1 unknown */
    uint8_t *fat_cache;       /* +0x44 */
    uint16_t fat_cache_hdr;   /* +0x48: slot header words before the sectors */
    uint16_t fat_cache_slots; /* +0x4A */
    uint8_t *dir_cache;       /* +0x4C */
    uint16_t dir_cache_hdr;   /* +0x50 */
    uint16_t dir_cache_slots; /* +0x52 */
    uint8_t _r54[4];
    uint8_t *clmap;           /* +0x58: cluster-use bitmap */
    uint8_t _r5c[4];
    uint32_t clmap_clusters;  /* +0x60: clusters the bitmap covers */
    uint8_t _r64[4];
    int8_t flags;             /* +0x68: bit 0 removable, 5 write protected, 6 card in, 7 mounted */
    uint8_t _r69[3];
    uint32_t bps;             /* +0x6C: bytes per sector */
    int sem;                  /* +0x70: device semaphore (shared by the drives of one device) */
} fs_drive_t;

_Static_assert(sizeof(fs_drive_t) == 0x74, "drive record size");

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
