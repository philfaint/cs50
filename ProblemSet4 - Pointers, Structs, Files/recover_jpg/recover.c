#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

typedef uint8_t BYTE;
#define BLOCK_SIZE 512

int main(int argc, char* argv[]){

    if(argc != 2){
        fprintf(stderr, "Usage: ./recover file_name\n");
        return 1;
    }

    FILE *card = fopen(argv[1], "r");
    if(card == NULL){
        fprintf(stderr, "Can't open the memory card!\n");
        return 2;
    }

    BYTE buffer[BLOCK_SIZE];
    _Bool found = 0;
    char filename[8];
    int k = 0;
    FILE *image;

    while(fread(buffer, 1, BLOCK_SIZE, card) != 0){

        sprintf(filename, "%03d.jpg", k);

        if(buffer[0] == 0xff &&
            buffer[1] == 0xd8 &&
            buffer[2] == 0xff &&
            (buffer[3] & 0xf0) == 0xe0){
                image = fopen(filename, "w");
                fwrite(buffer, 1, BLOCK_SIZE, image);
                found = 1;
                k++;
            }
        else if (found){
            fwrite(buffer, 1, BLOCK_SIZE, image);
        }
    }

    fclose(image);
    fclose(card);

    return 0;
}