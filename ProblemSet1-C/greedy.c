#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(){

    float money;
    int counter=0;

    do{
        printf("How much change is owed?\n");
        money = get_float();
    }while(money<0);

    money*=100;
    int cents = round(money);

    while(cents>=25){
        cents -=25;
        counter++;
    }
    while(cents>=10){
        cents -=10;
        counter++;
    }
    while(cents>=5){
        cents -=5;
        counter++;
    }
    while(cents>=1){
        cents -=1;
        counter++;
    }

    printf("%i\n", counter);

    return 0;
}