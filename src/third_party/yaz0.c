/*
 yaz0 decompression and compression, concatenated from yaz0dec.cpp
 and yaz0enc.c. Original header of both files follow
Decompression:
    //version 1.0 (20050213)
    //by thakis
Compresssion:
    Yaz0 recompressor
    -----------------
    Original by `shevious`, made into more of a UNIX
    program by ZZT32 (http://64.vg/)
*/

#ifdef app
#undef app

#include "yaz0.h"

u8* Data;
int dstSize;
int sflag;
int pos;

u32 toDWORD (u32 d) {
	u8 w1 = d & 0xFF;
	u8 w2 = (d >> 8) & 0xFF;
	u8 w3 = (d >> 16) & 0xFF;
	u8 w4 = d >> 24;
	return (w1 << 24) | (w2 << 16) | (w3 << 8) | w4;
}

yaz0_Ret decodeYaz0 (u8* src, int srcSize, u8* dst, int uncompressedSize) {
	yaz0_Ret r = { 0, 0 };
	int i;
	//int srcPlace = 0, dstPlace = 0; //current read/write positions

	u32 validBitCount = 0; //number of valid bits left in "code" byte
	u8 currCodeByte;
	while (r.dstPos < uncompressedSize) {
		//read new "code" byte if the current one is used up
		if (validBitCount == 0) {
			currCodeByte = src[r.srcPos];
			++r.srcPos;
			validBitCount = 8;
		}

		if ((currCodeByte & 0x80) != 0) {
			//straight copy
			dst[r.dstPos] = src[r.srcPos];
			r.dstPos++;
			r.srcPos++;
			//if(r.srcPos >= srcSize)
			//  return r;
		} else {
			//RLE part
			u8 byte1 = src[r.srcPos];
			u8 byte2 = src[r.srcPos + 1];
			r.srcPos += 2;
			//if(r.srcPos >= srcSize)
			//  return r;

			u32 dist       = ((byte1 & 0xF) << 8) | byte2;
			u32 copySource = r.dstPos - (dist + 1);

			u32 numBytes = byte1 >> 4;
			if (numBytes == 0) {
				numBytes = src[r.srcPos] + 0x12;
				r.srcPos++;
				//if(r.srcPos >= srcSize)
				//  return r;
			} else
				numBytes += 2;

			//copy run
			for (i = 0; i < numBytes; ++i) {
				dst[r.dstPos] = dst[copySource];
				copySource++;
				r.dstPos++;
			}
		}

		//use next bit from "code" byte
		currCodeByte <<= 1;
		validBitCount -= 1;
	}

	return r;
}

#ifdef app
void decodeAll (u8* src, int srcSize, char* srcName, char* dstName)
#else
siz_buffer decodeAll (u8* src, int srcSize)
#endif
{
	int readBytes = 0;

	if (srcSize >) {
		//search yaz0 block
		while (readBytes + 3 < srcSize
			   && (src[readBytes] != 'Y'
					  || src[readBytes + 1] != 'a'
					  || src[readBytes + 2] != 'z'
					  || src[readBytes + 3] != '0'))
			++readBytes;

		if (readBytes + 3 >= srcSize)
			return; //nothing left to decode

		readBytes += 4;
#ifdef app
		FILE* DataFile;
		if ((DataFile = fopen (dstName, "wb")) == NULL)
			exit (-1);
		printf ("Writing %s\n", dstName);
#endif
		u32 Size = toDWORD (*(u32*)(src + readBytes));
#ifdef app
		printf ("Writing 0x%X bytes\n", Size);
#endif
		u8* Dst = (u8*)malloc (Size + 0x1000);

		readBytes += 12; //4 byte size, 8 byte unused

		yaz0_Ret r = decodeYaz0 (src + readBytes, srcSize - readBytes, Dst, Size);
		readBytes += r.srcPos;
#ifdef app
		printf ("Read 0x%X bytes from input\n", readBytes);

		fwrite (Dst, r.dstPos, 1, DataFile);
		free (Dst);
		fclose (DataFile);
#endif
	}
#ifndef app
	siz_buffer ret = { Dst, r.dstPos };
	return ret;
#endif
}

#ifdef app
int main (int argc, char* argv[]) {
	if (argc < 2) {
		fprintf (stderr, "Usage: %s <infile> <outfile>\n", argv[0]);
		return EXIT_FAILURE;
	}

	FILE* inFile = fopen (argv[1], "rb");
	if (inFile == NULL)
		return EXIT_FAILURE;

	fseek (inFile, 0, SEEK_END);
	int size = ftell (inFile);
	fseek (inFile, 0, SEEK_SET);

	printf ("input file size: 0x%X\n", size);

	u8* buff = malloc (size);

	fread (buff, 1, size, inFile);

	fclose (inFile);

	decodeAll (buff, size, argv[1], argv[2]);
	free (buff);

	return EXIT_SUCCESS;
}
#endif

/* Compression... */

// simple and straight encoding scheme for Yaz0
u32 simpleEnc (u8* src, int size, int pos, u32* pMatchPos) {
	int startPos = pos - 0x1000, j, i;
	u32 numBytes = 1;
	u32 matchPos = 0;

	if (startPos < 0)
		startPos = 0;
	for (i = startPos; i < pos; i++) {
		for (j = 0; j < size - pos; j++) {
			if (src[i + j] != src[j + pos])
				break;
		}
		if (j > numBytes) {
			numBytes = j;
			matchPos = i;
		}
	}
	*pMatchPos = matchPos;
	if (numBytes == 2)
		numBytes = 1;
	return numBytes;
}

// a lookahead encoding scheme for ngc Yaz0
u32 nintendoEnc (u8* src, int size, int pos, u32* pMatchPos) {
	int startPos = pos - 0x1000;
	u32 numBytes = 1;
	static u32 numBytes1;
	static u32 matchPos;
	static int prevFlag = 0;

	// if prevFlag is set, it means that the previous position was determined by look-ahead try.
	// so just use it. this is not the best optimization, but nintendo's choice for speed.
	if (prevFlag == 1) {
		*pMatchPos = matchPos;
		prevFlag   = 0;
		return numBytes1;
	}
	prevFlag   = 0;
	numBytes   = simpleEnc (src, size, pos, &matchPos);
	*pMatchPos = matchPos;

	// if this position is RLE encoded, then compare to copying 1 byte and next position(pos+1) encoding
	if (numBytes >= 3) {
		numBytes1 = simpleEnc (src, size, pos + 1, &matchPos);
		// if the next position encoding is +2 longer than current position, choose it.
		// this does not guarantee the best optimization, but fairly good optimization with speed.
		if (numBytes1 >= numBytes + 2) {
			numBytes = 1;
			prevFlag = 1;
		}
	}
	return numBytes;
}

int encodeYaz0 (u8* src, int srcSize, u8* Data) {
	yaz0_Ret r = { 0, 0 };
	u8 dst[24]; // 8 codes * 3 bytes maximum
	int dstSize = 0;
	int percent = -1;
	int i;
	static double perc, last_perc;

	u32 validBitCount = 0; //number of valid bits left in "code" byte
	u8 currCodeByte   = 0;
	while (r.srcPos < srcSize) {
		u32 numBytes;
		u32 matchPos;
		u32 srcPosBak;

		numBytes = nintendoEnc (src, srcSize, r.srcPos, &matchPos);
		if (numBytes < 3) {
			//straight copy
			dst[r.dstPos] = src[r.srcPos];
			r.dstPos++;
			r.srcPos++;
			//set flag for straight copy
			currCodeByte |= (0x80 >> validBitCount);
		} else {
			//RLE part
			u32 dist = r.srcPos - matchPos - 1;
			u8 byte1, byte2, byte3;

			if (numBytes >= 0x12) // 3 byte encoding
			{
				byte1           = 0 | (dist >> 8);
				byte2           = dist & 0xff;
				dst[r.dstPos++] = byte1;
				dst[r.dstPos++] = byte2;
				// maximum runlength for 3 byte encoding
				if (numBytes > 0xff + 0x12)
					numBytes = 0xff + 0x12;
				byte3           = numBytes - 0x12;
				dst[r.dstPos++] = byte3;
			} else // 2 byte encoding
			{
				byte1           = ((numBytes - 2) << 4) | (dist >> 8);
				byte2           = dist & 0xff;
				dst[r.dstPos++] = byte1;
				dst[r.dstPos++] = byte2;
			}
			r.srcPos += numBytes;
		}
		validBitCount++;
		//write eight codes
		if (validBitCount == 8) {
			Data[pos] = currCodeByte;
			pos++;
			for (i = 0; i < /*=*/r.dstPos; pos++, i++)
				Data[pos] = dst[i];
			dstSize += r.dstPos + 1;

			srcPosBak     = r.srcPos;
			currCodeByte  = 0;
			validBitCount = 0;
			r.dstPos      = 0;
		}
	}
	if (validBitCount > 0) {
		Data[pos] = currCodeByte;
		pos++;
		for (i = 0; i < /*=*/r.dstPos; pos++, i++)
			Data[pos] = dst[i];
		dstSize += r.dstPos + 1;

		currCodeByte  = 0;
		validBitCount = 0;
		r.dstPos      = 0;
	}

	return dstSize;
}

u8* encodeAll (u8* src, int srcSize) {
	Data = (u8*)malloc (srcSize + 0x20); //should be enough, sometimes outsize > insize; thats what the +0x20 is for

	// write 4 bytes yaz0 header
	Data[0] = 'Y';
	Data[1] = 'a';
	Data[2] = 'z';
	Data[3] = '0';

	// write 4 bytes uncompressed size
	Data[4] = (srcSize >> 24) & 0xFF;
	Data[5] = (srcSize >> 16) & 0xFF;
	Data[6] = (srcSize >> 8) & 0xFF;
	Data[7] = srcSize & 0xFF;

	// write 8 bytes unused dummy
	memset (&Data[8], 0, 8);

	pos = 16;

	//encode
	dstSize = encodeYaz0 (src, srcSize, Data);

	return Data;
}

#define app
#endif
