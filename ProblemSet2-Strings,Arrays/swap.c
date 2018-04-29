// swap two values without using the third variable
#include <stdio.h>
#include <cs50.h>

int main(void){

    int x = get_int();
    int y = get_int();
    printf("x i %i\ny is %i\n", x, y);
    x = x^y;
    y = x^y;
    x = x^y;
    printf("x i %i\ny is %i\n", x, y);
    return 0;
}