# Questions

## What's `stdint.h`?

    This header defines a set of integral type aliases with specific width requirements

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

     It makes clear that you intend to use the data in a specific way.

     for example, uint8_t means an unsigned int of width 8 bits.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

    BYTE is 1 byte
    DWORD is 4 bytes
    LONG is 4 bytes
    WORD is 2 bytes


## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

    The first two bytes of a BMP is a WORD and denotes bfType, which specifies the file type. It must be set to the signature word BM (0x4D42) to indicate bitmap.


## What's the difference between `bfSize` and `biSize`?

    bfSize is The size, in bytes, of the bitmap file
    
    biSize is the The number of bytes required by the structure.

## What does it mean if `biHeight` is negative?

    If biHeight is negative, the bitmap is a top-down DIB and its origin is the upper-left
    
    corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?

    The biBitCount member of the BITMAPINFOHEADER structure determines the number of bits that define each pixel.

## Why might `fopen` return `NULL` in `copy.c`?

    fopen might return NULL if it cannot open the file for reading or writing  because the file might not exist or some permission error occured while accessing a file such as "read only" or "write protected"

## Why is the third argument to `fread` always `1` in our code?

    this number '1' refers to the number of structures being read, so because every fread call in the code only reads one structure such as BITMAPFILEHEADER, BITMAPINFOHEADER or RGBTRIPLE that's why the third argument is always 1

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

    when bi.biWidth is 3 the padding is assigned a value of 3 because the size of the scanline is 9 bytes and each scanline must be a multiple of 4

## What does `fseek` do?

    fseek shifts the position of the cursor or indicator to a new position in the stream

## What is `SEEK_CUR`?

    SEEK_CUR is the current position in the file
