#include <stdio.h>
#include <cs50.h>

int main(){

    int minutes;

    do{
    printf("Minutes: ");
    minutes = get_int();
    }
    while(minutes<1);

    //printf("Minutes: %i\n", minutes);
    printf("Bottles: %i\n", minutes*12);
    return 0;
}