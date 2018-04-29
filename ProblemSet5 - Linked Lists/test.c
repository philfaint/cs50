#include <stdio.h>

void print(int &b){
    printf("%i\n", b);
    printf("%i\n", &b);
}

int main(void){

    int a = 25;

    print(&a);
    return 0;
}