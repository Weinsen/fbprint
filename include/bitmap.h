#ifndef BITMAP_H
#define BITMAP_H

#include <stdint.h>

typedef struct bitmap_t {
	uint16_t	file;			// 0
	uint32_t	size;			// 2
	uint32_t	reserved;		// 6
	uint32_t	offset;			// 10
	uint32_t 	header;			// 14
	int32_t		width;			// 18
	int32_t		height;			// 22
	uint16_t	planes;			// 26
	uint16_t	bitcount;		// 28
	uint32_t	compression;	// 30
} bitmap_t;

uint32_t little2big(uint8_t* buff, uint8_t len);
void get_bitmap_info(uint8_t *header, bitmap_t *bitmap);

// struct BITMAPV3INFOHEADER
// {
// 	uint32 biSize
// 	int32 biWidth;
// 	int32 biHeight;
// 	uint16 biPlanes;
// 	uint16 biBitCount;
// 	uint32 biCompression;
// 	uint32 biSizeImage;
// 	uint32 biXPelsPerMeter;
// 	uint32 biYPelsPerMeter;
// 	uint32 biClrUsed;
// 	uint32 biClrImportant;
// 	/* new for V3 */
// 	uint32 biRedMask;
// 	uint32 biGreenMask;
// 	uint32 biBlueMask;
// 	uint32 biAlphaMask;
// };

// typedef struct {
//   DWORD        bV5Size;
//   LONG         bV5Width;
//   LONG         bV5Height;
//   WORD         bV5Planes;
//   WORD         bV5BitCount;
//   DWORD        bV5Compression;
//   DWORD        bV5SizeImage;
//   LONG         bV5XPelsPerMeter;
//   LONG         bV5YPelsPerMeter;
//   DWORD        bV5ClrUsed;
//   DWORD        bV5ClrImportant;
//   DWORD        bV5RedMask;
//   DWORD        bV5GreenMask;
//   DWORD        bV5BlueMask;
//   DWORD        bV5AlphaMask;
//   DWORD        bV5CSType;
//   CIEXYZTRIPLE bV5Endpoints;
//   DWORD        bV5GammaRed;
//   DWORD        bV5GammaGreen;
//   DWORD        bV5GammaBlue;
//   DWORD        bV5Intent;
//   DWORD        bV5ProfileData;
//   DWORD        bV5ProfileSize;
//   DWORD        bV5Reserved;
// } BITMAPV5HEADER, *LPBITMAPV5HEADER, *PBITMAPV5HEADER;

#endif

