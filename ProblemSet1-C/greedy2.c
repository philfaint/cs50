#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(){

    float money;
    int counter=0;
    int counter25 = 0;
    int counter10 = 0;
    int counter5 = 0;
    int counter1 = 0;

    do{
        printf("How much change is owed?\n");
        money = get_float();
    }while(money<0);

    money*=100;
    int cents = round(money);
    counter = cents;

    cents /=25;
    counter25 = cents%25;

    cents/=10;
    counter10 = cents%10;

    cents /=5;
    counter5 = cents%5;

    cents/=1;
    counter1 = cents%1;

    counter = counter25+counter10+counter5+counter1;

    printf("%i\n", counter);

    return 0;
}