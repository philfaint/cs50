//asks user to input the lowercase letter and
//gives an uppercase letter instead.
// bitwise implementation

#include <stdio.h>
#include <cs50.h>

int main(){

    char c;

    do{
        printf("Enter the lowercase character: ");
        c=get_char();
    }while(c < 'a' || c > 'z');

    printf("%c\n", c^('a'^'A'));// aXORA = 32 - difference between two figures. cXOR32 - is c-32 - gives us the opposite upper case


    return 0;
}