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
    while(temp!=0){
        temp/=10;
        figures++; // count the amount of figures
    }
    
    temp = a;
    if(a<0){
        temp=-temp;  //turn a negarive integer into a positive
    }
    
    for(int i =0; i<figures; i++){ //print digits reversed
        printf("%i", temp%10);
        temp/=10;
        
        if(i==(figures-1) && (a<0)){ // if the figure is negative and it's last digit we print '-'
            printf("-");
        }
    }
    
    return 0;
}
