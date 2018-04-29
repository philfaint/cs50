#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{

    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }

    // n must be a float, otherwise return error
    char *tail;
    float f = strtod(argv[1], &tail);

    if ((f <= 0.0f) || (f >= 100.0f))
    {
        fprintf(stderr, "Resize factor must be within bounts (0, 100)\n");
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
    BITMAPFILEHEADER in_bf;
    fread(&in_bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER in_bi;
    fread(&in_bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (in_bf.bfType != 0x4d42 || in_bf.bfOffBits != 54 || in_bi.biSize != 40 ||
        in_bi.biBitCount != 24 || in_bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }

    // create BITMAPFILEHEADER and BITMAPINFOHEADER for the resized outfile
    BITMAPFILEHEADER out_bf = in_bf;
    BITMAPINFOHEADER out_bi = in_bi;

    // rescale BITMAPINFOHEADER's width and height
    out_bi.biWidth = in_bi.biWidth * f;
    out_bi.biHeight = in_bi.biHeight * f;

    // determine infile and outfile padding
    int in_padding = (4 - (in_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int out_padding = (4 - (out_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    // calculate out_bi.biSizeImage
    out_bi.biSizeImage = ( out_bi.biWidth * sizeof(RGBTRIPLE) + out_padding ) * abs(out_bi.biHeight);

    // update BITMAPFILEHEADER's bfSize
    out_bf.bfSize = out_bi.biSizeImage + out_bf.bfOffBits;

    // write outfile's BITMAPFILEHEADER
    fwrite(&out_bf, sizeof(BITMAPFILEHEADER), 1, outptr);
    fwrite(&out_bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // iterate over infile's scanlines

    float newHeightIndex = 0;
    for (int i = 0, biHeight = abs(in_bi.biHeight); i < biHeight; i++)
    {
        RGBTRIPLE* line = malloc(sizeof(RGBTRIPLE) * in_bi.biWidth);

        // copy infile's scanline
        for (int j = 0; j < in_bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            line[j] = triple;
        }

        // skip inptr over infile's padding, if any
        fseek(inptr, in_padding, SEEK_CUR);


        while (newHeightIndex < (i+1) )
        {
            for (int z = 0; z < out_bi.biWidth; z++)
            {
                int pixel = z/f;
                fwrite(&line[pixel], sizeof(RGBTRIPLE), 1, outptr);
            }

            // then add new padding to outfile
            for (int k = 0; k < out_padding; k++)
            {
                fputc(0x00, outptr);
            }

            newHeightIndex += (1/f);

        }

        free(line);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}