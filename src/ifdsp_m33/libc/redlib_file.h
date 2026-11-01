/*
 * FT-710 IFDSP M33 (T24): the stream structure of the image's C library (NXP Redlib, closed source), as its code uses
 * it. 0x3C bytes [fact: stdio_init's three streams at 0x88B78/0x88BB4/0x88BF0, memset(f, 0, 0x3C) in sprintf
 * 0x85A9C and _Cfclose 0x876AA]. The field meanings are read from the code that uses them [inference: functions
 * named]; Redlib's own field names are not known (Open: would be settled by Redlib's stdio.h internals from an
 * MCUXpresso IDE install).
 */
#ifndef REDLIB_FILE_H
#define REDLIB_FILE_H

typedef struct redlib_file
{
    unsigned char *ptr;     /* +0x00 next character in the buffer */
    int rcount;             /* +0x04 characters left to read */
    int wcount;             /* +0x08 room left to write (sprintf: 0x7FFFFFFF, counts down) */
    unsigned int flags;     /* +0x0C mode and state bits, below */
    unsigned char *base;    /* +0x10 buffer */
    int fd;                 /* +0x14 host handle for the __sys_* calls */
    int pos;                /* +0x18 file position of base */
    int bufsize;            /* +0x1C */
    int tmpid;              /* +0x20 tmpfile id (_Cfclose: __sys_tmpnam) */
    unsigned char ch[4];    /* +0x24 one-character buffer (unbuffered streams) */
    int seekpos;            /* +0x28 pending seek target (flag 0x20) */
    unsigned char *hiwater; /* +0x2C end of the written part of the buffer */
    int bufsize2;           /* +0x30 copy of bufsize while writing */
    int reserved[2];        /* +0x34 */
} redlib_file_t;

/* flags (+0x0C) [fact: masks in the code] */
#define RF_READ 0x1u
#define RF_WRITE 0x2u
#define RF_BIN 0x4u
#define RF_APPEND 0x8000u
#define RF_FBF 0x100u   /* setvbuf _IOFBF */
#define RF_LBF 0x200u   /* setvbuf _IOLBF */
#define RF_NBF 0x400u   /* setvbuf _IONBF */
#define RF_ALLOC 0x800u /* buffer from _Csys_alloc, freed by _Cfclose */

extern redlib_file_t __redlib_streams[3]; /* stdin, stdout, stderr at 0x88B78 [fact] */

int __sys_close(int fd);
int __sys_flen(int fd);
int __sys_istty(int fd);
int __sys_remove(const char *name, int len);
int __sys_seek(int fd, int pos);
int __sys_tmpnam(char *buf, int id, int len);
int __sys_write(int fd, const void *buf, int len);
void __sys_appexit(void);

int _Cwrite_buffer(const unsigned char *buf, int len, redlib_file_t *f);
int _Cfflush1(redlib_file_t *f);
int _Cfclose(redlib_file_t *f);
redlib_file_t *_Cfdopen(int fd, const char *mode, redlib_file_t *f);
void file_clear_flag20(redlib_file_t *f);
int file_flush_write_buffer(redlib_file_t *f);
void *_Csys_alloc(unsigned int n);

#endif
