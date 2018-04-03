// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: resize resize_int infile outfile\n");
        return 1;
    }

    //convert 1st argument to int
    int n = atoi(argv[1]);

    //check if its between 1 and 100
    if (n < 1 || n > 100)
    {
        fprintf(stderr, "resize_int should be between 1 and 100\n");
        return 4;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    //old padding
    int padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //declared and assigned values for old width and old height
    int old_width, old_height;
    old_width = bi.biWidth;
    old_height = bi.biHeight;
    bi.biWidth *= n;
    bi.biHeight *= n;
    // printf("%i", bi.biWidth);

    // determine padding for scanlines
    int padding_new = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    //New header changes
    //changing bi.biSizeImage
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + padding_new) * abs(bi.biHeight);

    //changing bf.bfSize
    bf.bfSize =  bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines

    for (int i = 0, biHeight = abs(old_height); i < biHeight; i++)
    {
        //The array increment variable initialized
        int inc = 0;

        // arr of RGBTRIPLE declared
        RGBTRIPLE arr[((sizeof(RGBTRIPLE) * bi.biWidth))];
        // iterate over pixels in scanline
        for (int j = 0; j < old_width; j++)
        {

            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // printf("reading a pixel\n");
            //loop through the array n times and add triple to it
            for (int k = 0; k < n; k++)
            {
                arr[inc] = triple;
                inc++;


            }

        }
        inc = 0; //reset inc
        //loop again n times to write to file (vertically) and also padding
        for (int l = 0; l < n; l++)
        {
            // write RGB triple (arr) to outfile width times
            for (int o = 0; o < (bi.biWidth) ; o++)
            {
                fwrite(&arr[inc], sizeof(RGBTRIPLE), 1, outptr);
                //  printf("      writing a pixel\n");
                inc++;
            }

            //write padding here
            for (int m = 0; m < padding_new; m++)
            {
                fputc(0x00, outptr);
                //  printf("putting a pad byte\n");
            }

            inc = 0;
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

    }





    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
