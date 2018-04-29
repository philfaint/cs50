//asks user to input the lowercase letter and
//gives an uppercase letter instead

#include <stdio.h>
#include <cs50.h>

int main(){

    char c;

    do{
        printf("Enter the lowercase character: ");
        c=get_char();
    }while(c < 'a' || c > 'z');

    printf("%c\n", c-('a'-'A'));
    return 0;
}