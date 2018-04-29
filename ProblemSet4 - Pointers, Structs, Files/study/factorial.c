#include <stdio.h>

int fact(int n){
    if(n==1)
        return 1;
    else
        return n*fact(n-1);
}

int main(void){

    int n =5;
    printf("%i\n", fact(n));
    return 1;
}