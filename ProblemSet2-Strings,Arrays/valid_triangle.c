#include <stdio.h>
#include <cs50.h>

_Bool valid_triangle(int a, int b, int c);

int main(void){

    int a = get_int();
    int b = get_int();
    int c = get_int();
    _Bool valid = valid_triangle(a, b, c);

    valid==1 ? printf("Valid\n") : printf("Not Valid\n");
    return 0;
}

_Bool valid_triangle(int a, int b, int c){
    if((a>=0 && b>=0 && c>=0) && (a+b>=c && b+c>=a && c+a>=b))
        return 1;
    else
        return 0;
}