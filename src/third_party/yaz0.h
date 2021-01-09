#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef unsigned char u8;
typedef unsigned int u32;

typedef struct
{
	int srcPos, dstPos;
} yaz0_Ret;

typedef struct
{
	char* buffer;
	int size;
} siz_buffer;

u8* Data;
int dstSize;
int sflag;
int pos;

/* functions */
u8* encodeAll (u8* src, int srcSize);
u32 simpleEnc (u8* src, int size, int pos, u32* pMatchPos);
u32 nintendoEnc (u8* src, int size, int pos, u32* pMatchPos);
int encodeYaz0 (u8* src, int srcSize, u8* Data);
#ifdef app
void decodeAll (u8* src, int srcSize, char* srcName, char* dstName);
int main (int argc, char* argv[]);
#else
siz_buffer decodeAll (u8* src, int srcSize);
#endif
yaz0_Ret decodeYaz0 (u8* src, int srcSize, u8* dst, int uncompressedSize);
u32 toDWORD (u32 d);
