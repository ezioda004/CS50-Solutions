# Questions

## What's `stdint.h`?

It's a header file. It allow programmers to write more portable code by 
providing a set of typedefs that specify exact-width integer types, 
together with the defined minimum and maximum allowable values for each 
type, using macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and 
`uint16_t` in a program?

It’s easier to have aliases to use interchangeably for explicit fixed 
width integers. Specifies the number of bytes because one system an int 
might be a long in another.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, 
respectively?

BYTE is 1 byte
DWORD is 4 bytes
LONG is 4 bytes
WORD is 2 bytes


## What (in ASCII, decimal, or hexadecimal) must the first two bytes of 
any BMP file be? Leading bytes used to identify file formats (with high 
probability) are generally called "magic numbers."

The first 2 bytes of the BMP file format are the character "B" then the 
character "M" in ASCII encoding.
ASCII: "BM"
decimal:
Hexadecimal: x0424d


## What's the difference between `bfSize` and `biSize`?

bfsize: The file size in bytes of the full BMP, that includes both 
header and image.
biSize: The file size in bytes of the header part of a BMP.


## What does it mean if `biHeight` is negative?

 If biHeight is positive, the bitmap is a bottom-up DIB and its origin 
is the lower-left corner. If biHeight is negative, the bitmap is a 
top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth 
(i.e., bits per pixel)?

The biBitCount determines the number of bits that define each pixel and 
the maximum number of colors in the bitmap.

## Why might `fopen` return `NULL` in lines 24 and 32 of `copy.c`?

In input maybe because it can't find the specific file name as argument? 
Likewise for output file.

## Why is the third argument to `fread` always `1` in our code?

It specifes the number of elements to read, and we're only reading 
BITMAPFILEHEADER I think.

## What value does line 63 of `copy.c` assign to `padding` if 
`bi.biWidth` is `3`?

(4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
(4 - (3 * 3 % 4) % 4;
(4 - 1 % 4);
(4 - 1);
3;

## What does `fseek` do?

fseek() function is used to move the file position to a desired location 
within the file . It takes the following form: fssek(file_ptr, offset, 
position) ; file_ptr is a pointer to the file concerned, offset is a 
number or variable of type long, and position is an integer number.

## What is `SEEK_CUR`?

SEEK_CUR : Current position of the file pointer

