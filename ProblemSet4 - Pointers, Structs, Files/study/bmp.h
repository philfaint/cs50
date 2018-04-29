#include <stdint.h>

typedef uint8_t BYTE; // unsigned int of at least 1 byte for RGB (each value is 1 byte long)
typedef uint32_t DWORD; //unsigned int of at least 4 bytes
typedef int32_t LONG; //signed int of at least 4 bytes
typedef uint16_t WORD; //unsigned int of at least 2 bytes

typedef struct{
    WORD  bfType; // always 0x4D42h which is equal to BM
    DWORD bfSize; // total size of file in bytes
    WORD  bfReserved1; // always 0x0
    WORD  bfReserved2; // always 0x0
    DWORD bfOffBits; // where the color array begins: sizeof(bfh) + sizeof(bih)
} __attribute__((__packed__))
BITMAPFILEHEADER;

typedef struct{
    DWORD biSize; // size of the struct itself sizeof(bih)
    LONG  biWidth; // width of the image in pixels
    LONG  biHeight; // height of the image in pixels
    WORD  biPlanes; // the amount of planes. sets to 1
    WORD  biBitCount; // bit count 24 bit
    DWORD biCompression; // BI_RGB means no compression
    DWORD biSizeImage; // 0
    LONG  biXPelsPerMeter; // resolution in pixels/meter
    LONG  biYPelsPerMeter; // resolution in pixels/meter
    DWORD biClrUsed; // 0
    DWORD biClrImportant; // important colors 0
} __attribute__((__packed__))
BITMAPINFOHEADER;

typedef struct{
    BYTE rgbtBlue;
    BYTE rgbtGreen;
    BYTE rgbtRed;
} __attribute__((__packed__))
RGB;