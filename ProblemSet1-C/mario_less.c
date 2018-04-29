#include <stdio.h>
#include <cs50.h>

int main(){

    int h = 0;

    do{
        printf("Height: ");
        h = get_int();
    }
    while(h>23 || h<0);

    for(int i =1; i<=h; i++){
        for (int j =h; j>=0; j--){
            if(j<=i){
                printf("#");
            }
            else
                printf(" ");
        }
        printf("\n");
    }

    return 0;
}