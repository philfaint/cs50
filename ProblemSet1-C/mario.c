#include <stdio.h>
#include <cs50.h>

int main(){

    int h = 0;

    //getting the input and checking it to be positive integer
    do{
        printf("Height: ");
        h = get_int();
    }
    while(h>23 || h<0);

    int h2 = ((h*2)+3);

    for(int i =0; i<h; i++){
        for (int j =(h2-1); j>=1; j--){

            if(j == h2/2 || j==((h2/2)+1)){
                printf(" ");
            }
            else if(j<=((h+3)+i) && j>=(h-i)){
                printf("#");
            }
            else if(j>=((h+3)+i))
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}