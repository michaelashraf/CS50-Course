// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    for (int i = 0 , n = strlen(argv[1]); i < n; i++)
    {
        if (argv[1][i] < '0' || argv[1][i] > '9')
        {
            fprintf(stderr, "n, the resize factor, must be an integer.\n");
            return 1;
        }
    }

    int resize_factor = atoi(argv[1]);

    if (resize_factor <= 0 || resize_factor > 100)
    {
         fprintf(stderr, "n, the resize factor, must satisfy 0 < n <= 100.\n");
         return 1;
    }

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];


    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 1;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 1;
    }

    // read infile's BITMAPFILEHEADER
     BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 1;
    }

    //remember original width and height of infile
    int original_width = bi.biWidth;
    int original_height = abs(bi.biHeight);

    // determine  original padding for scanlines
    int old_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    //update the BITMAPINFOHEADER width and height
    bi.biWidth *= resize_factor;
    bi.biHeight *= resize_factor;


    // determine  padding after resize for scanlines
    int resized_padding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;


    //updating the rest of BITMAPINFOHEADER
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + resized_padding) * abs(bi.biHeight);

    //updating the BITMAPFILEHEADER
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0; i < original_height; i++)
    {
        //for n-1 times
        for (int j = 0; j < resize_factor - 1; j++)
        {
            // iterate over pixels in scanline
            for (int k = 0; k < original_width; k++)
            {
                // temporary storage
                RGBTRIPLE triple;

                // read RGB triple from infile
                fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

                //write the pixel for n times
                for (int l = 0; l < resize_factor; l++)
                {
                    // write RGB triple to outfile
                    fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
                }
            }
            //add padding to the outfile
            for (int m = 0; m < resized_padding; m++)
            {
                fputc(0x00, outptr);
            }

            //send infile cursor back
            fseek(inptr, -1 * (original_width * sizeof(RGBTRIPLE)), SEEK_CUR);
        }

        for (int k = 0; k < original_width; k++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int l = 0; l < resize_factor; l++)
            {
                // write RGB triple to outfile
                fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
            }
        }
        // then add it back (to demonstrate how)
        for (int m = 0; m < resized_padding; m++)
        {
            fputc(0x00, outptr);
        }

        fseek(inptr, old_padding, SEEK_CUR);


    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
