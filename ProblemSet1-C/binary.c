//asks user for a decimal number and
//prints it's binary representaion
// without storing it somewhere

#include <stdio.h>


int main(){

    printf("Please enter the decimal number:\n");
    int a = 0;
    scanf("%i", &a);

    int numBits = sizeof(int)*8;

    for(int i = numBits-1; i >=0; i--){
        int isOne = a&(1<<i);

        if(isOne)
            printf("1");
        else
            printf("0");
    }

    printf("\n");
    return 0;
}