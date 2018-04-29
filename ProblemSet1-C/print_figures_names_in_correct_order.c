//
//  main.c
//  test
//
//  Created by Maxim Gerun on 29.09.17.
//  Copyright © 2017 Maxim Gerun. All rights reserved.
//

#include <stdio.h>

int main(){
    
    int a = 0;
    int figures = 0;
    
    printf("Enter the number:");
    scanf("%i", &a);
    
    int temp = a;
    int temp2 = 0;
    int temp3 = 0;
    while(temp!=0){
        temp/=10;
        figures++; // count the amount of figures
    }
    
    temp = a;
    if(a<0){
        temp=-temp;  //turn a negarive integer into a positive
    }
    
    while(temp!=0){  //turn the figure backwards. 256 turns into 652, etc.
        temp2 = temp%10;
        temp3 = (temp2+temp3)*10;
        temp/=10;
    }
    
    temp3/=10;
    
    for(int i =0; i<figures; i++){ //print digits reversed
        switch(temp3%10){
            case 1:
                printf("one ");
                break;
            case 2:
                printf("two ");
                break;
            case 3:
                printf("three ");
                break;
            case 4:
                printf("four ");
                break;
            case 5:
                printf("five ");
                break;
            case 6:
                printf("six ");
                break;
            case 7:
                printf("seven ");
                break;
            case 8:
                printf("eight ");
                break;
            case 9:
                printf("nine ");
                break;
            case 0:
                printf("zero ");
                break;
            default:
                printf("not a number\n");
                break;
        }
        temp3/=10;
        
    }
    printf("\n");
    
    return 0;
}
