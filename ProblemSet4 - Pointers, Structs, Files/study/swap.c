#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b);

int main(int argc, char* argv[]){

    if(argc!=3){
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    swap(&a,&b);

    printf("%i %i \n", a,b);

    return 0;
}

void swap(int *a, int *b){
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}