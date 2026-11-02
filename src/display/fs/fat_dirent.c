/*
 * FT-710 DISPLAY (T24 round 9): small directory-entry and path helpers of the FAT layer: the long-name checksum
 * 0x20144EB8, the path components 0x20147248..0x20147313, an entry's first cluster 0x20146884 / 0x20147588 and the
 * time stamp conversion 0x201475D0. Recreated from the image's disassembly.
 *
 * A path is "X:\dir\name" with Shift-JIS names; a directory entry is the 32-byte entry of the FAT specification
 * (first cluster low word +0x1A, high word +0x14 on FAT32, time +0x16, date +0x18).
 */
#include "fs.h"

/* 0x20144EB8: the checksum a long-name entry carries of its 11-byte 8.3 name: rotate right by one and add, over the
 * first ten bytes, then the eleventh added [fact; the FAT specification's algorithm] */
uint32_t lfn_checksum(const uint8_t *name)
{
    uint32_t s = 0;
    int i = 0;

    do
    {
        s += name[i++];
        s = (s & 1) << 7 | (s & 0xFF) >> 1;
    } while (i < 10);
    return (name[i] + s) & 0xFF;
}

/* 0x20147248: (p, out): the component "\name" at p into out (a Shift-JIS lead byte takes its trail byte along);
 * returns the pointer to the next '\' or the end, 0 when p does not start with '\' [fact] */
const fs_char_t *path_next_component(const fs_char_t *p, fs_char_t *out)
{
    const uint8_t *s = (const uint8_t *)p;
    uint8_t *d = (uint8_t *)out;

    if (*s != '\\')
    {
        return 0;
    }
    s++;
    while (*(const fs_char_t *)s != 0 && *(const fs_char_t *)s != '\\')
    {
        if (sjis_is_lead(*s))
        {
            *d++ = *s++;
        }
        *d++ = *s++;
    }
    *d = 0;
    return (const fs_char_t *)s;
}

/* 0x201472A8: the length of a path rebuilt from its components: each component and a separator, plus the 3 bytes
 * of "X:\"; a last component without a separator after it is not counted [fact] */
int path_components_len(const fs_char_t *path)
{
    const fs_char_t *p = path + 2;
    fs_char_t comp[0x20C];
    int n = 0;

    while (*p != 0)
    {
        p = path_next_component(p, comp);
        if (comp[0] == 0 || *p == 0)
        {
            break;
        }
        n = fs_strlen(comp) + n + 1;
    }
    return n + 3;
}

/* 0x20146884: an entry's first cluster; the high word only for FAT32 (type other than 12 and 16) [fact] */
uint32_t dirent_get_cluster(const uint8_t *e, int type)
{
    if (type != 0x0C && type != 0x10)
    {
        return fat_ld_word(e + 0x1A) + fat_ld_word(e + 0x14) * 0x10000;
    }
    return fat_ld_word(e + 0x1A);
}

/* 0x20147588: stores an entry's first cluster, the same way [fact] */
void dirent_set_cluster(uint8_t *e, uint32_t cl, int type)
{
    if (type != 0x0C && type != 0x10)
    {
        fat_st_word(e + 0x1A, cl & 0xFFFF);
        fat_st_word(e + 0x14, cl >> 16);
        return;
    }
    fat_st_word(e + 0x1A, cl & 0xFFFF);
}

/* 0x201475D0: (tm, time, date): the FAT time and date words (their low halves) to a struct tm: seconds (2 s
 * steps), minutes, hours, day, month - 1, years since 1900 (1980 + y); the last three fields 0 [fact] */
void fat_time_to_tm(int *tm, uint32_t time, uint32_t date)
{
    uint32_t t = fat_ld_word((const uint8_t *)&time);
    uint32_t d = fat_ld_word((const uint8_t *)&date);

    tm[0] = (t & 0x1F) << 1;
    tm[1] = (t >> 5) & 0x3F;
    tm[2] = t >> 11;
    tm[3] = d & 0x1F;
    tm[4] = ((d >> 5) & 0xF) - 1;
    tm[5] = (d >> 9) + 80;
    tm[6] = 0;
    tm[7] = 0;
    tm[8] = 0;
}
