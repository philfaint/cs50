#include <stdio.h>
#include <string.h>

#include "bmp.h"

int main(void){

    //declare structs for headers and rgb
    BITMAPFILEHEADER bfh;
    BITMAPINFOHEADER bih;
    RGB rgb;

    //set image resolution
    const int width = 512;
    const int height = 512;

    memset(&bfh, 0, sizeof(bfh)); // init bfh struct with 0

    //set values for fields of BFH struct
    bfh.bfType = 0x4d42;
    bfh.bfReserved1 = 0x0;
    bfh.bfReserved2 = 0x0;
    bfh.bfOffBits = sizeof(bfh) + sizeof(bih);

    // set values for BIH struct
    memset(&bih, 0, sizeof(bih)); // init bih struct with 0
    bih.biSize = sizeof(bih);
    bih.biWidth = width;
    bih.biHeight = height;
    bih.biPlanes = 1;
    bih.biBitCount = 0x18; // 24 bits per pixel
    bih.biSizeImage = sizeof(bih.biWidth)*sizeof(bih.biHeight);
    bih.biClrUsed = 32768;

    bfh.bfSize = sizeof(bfh) + sizeof(bih) + bih.biSizeImage;

    FILE *file = fopen("image2.bmp", "w");
    if(file == NULL){
        printf("Could not open.\n");
        return 1;
    }

    //write two headers into the bmp file
    fwrite(&bfh, sizeof(bfh), 1, file);
    fwrite(&bih, sizeof(bih), 1, file);

    //put rgb values to draw something into the file after headers
    //int mid = (bih.biWidth/2)-1;

    for(int i = bih.biHeight/2; i<bih.biHeight ; i++){
        for(int j =0; j<bih.biWidth; j++){
            if(j >= (bih.biWidth/2)-i && j<= (bih.biWidth/2)+i){
                rgb.rgbtBlue = 0x00;
                rgb.rgbtGreen = 0xff;
                rgb.rgbtRed = 0x00;
                fwrite(&rgb, sizeof(rgb), 1, file);
            }
            else{
                rgb.rgbtBlue = 0xff;
                rgb.rgbtGreen = 0xff;
                rgb.rgbtRed = 0xff;
                fwrite(&rgb, sizeof(rgb), 1, file);
            }
        }
    }


    /*for(int i =0; i<bih.biHeight/2; i++){

        for(int j = 0; j<bih.biWidth; j++){
            if(j>=mid-i && j <= mid+i){
                rgb.rgbtBlue = 0x00;
                rgb.rgbtGreen = 0xff;
                rgb.rgbtRed = 0x00;
                fwrite(&rgb, sizeof(rgb), 1, file);
            }
            else{
                rgb.rgbtBlue = 0xff;
                rgb.rgbtGreen = 0xff;
                rgb.rgbtRed = 0xff;
                fwrite(&rgb, sizeof(rgb), 1, file);
            }
        }
    }
    for(int i =bih.biHeight/2; i>=0; i--){
        for(int j = bih.biWidth; j>=0; j--){
            if(j <= i+(bih.biWidth/2) ){
                rgb.rgbtBlue = 0xff;
                rgb.rgbtGreen = 0xff;
                rgb.rgbtRed = 0xff;
                fwrite(&rgb, sizeof(rgb), 1, file);
            }
            else{
                rgb.rgbtBlue = 0x00;
                rgb.rgbtGreen = 0xff;
                rgb.rgbtRed = 0x00;
                fwrite(&rgb, sizeof(rgb), 1, file);
            }
        }
    }*/


    fclose(file);
    return 0;
}