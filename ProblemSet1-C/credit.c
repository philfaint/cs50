#include <stdio.h>
#include <cs50.h>

long long enterNumber(void); //this function asks user to enter the credit card number
int ccFigures(long long cc_number); //this function finds out the amount of digits in credit card number
int ccSum(long long cc_number, int cc_figures); //this function finds out the sum of digits in credit card number
int firstDigits(long long cc_number, int cc_figures); //finds out first digits of the credit card number
void result(int sum, int firstdigits); //shows the result - credit card type

int main(){

    long long cc_number = enterNumber(); //finds out credit card number
    int cc_figures = ccFigures(cc_number); //finds out amount of digits in credit card number
    int sum = ccSum(cc_number, cc_figures);
    int firstdigits = firstDigits(cc_number, cc_figures);
    result(sum, firstdigits);
    return 0;
}

long long enterNumber(void){

    long long a = 0;
    do{
        printf("Number: ");
        a = get_long_long();
    }while(a<1);

    return a;
}

int ccFigures(long long cc_number){

    int cc_figures = 0;

    while(cc_number!=0){
        cc_number/=10;
        cc_figures++;
    }
    return cc_figures;
}

int ccSum(long long cc_number, int cc_figures){

    long long temp = cc_number;
    int sum = 0;
    int k = 0;
    int j =0;

    for(int i =0; i<cc_figures; i++){
        j = temp%10;
        temp/=10;
        sum+=j;

        k = (temp%10)*2;
        temp /= 10;
        if(k>=10){
            sum = sum + (k%10);
            k/=10;
        }
        sum+=k;
    }
    return sum;
}

int firstDigits(long long cc_number, int cc_figures){
    int firstdigits = 0;

    if (cc_figures==13){
        firstdigits=cc_number/100000000000;
    }
    else if (cc_figures==15){
        firstdigits=cc_number/10000000000000;
    }
    else if(cc_figures==16){
        firstdigits=cc_number/100000000000000;
    }
    return firstdigits;
}

void result(int sum, int firstdigits){

    if((sum%10)==0 && (firstdigits==34 || firstdigits == 37)){
        printf("AMEX\n");
    }
    else if((sum%10)==0 && (firstdigits==51 || firstdigits == 52 || firstdigits == 53 || firstdigits == 54 || firstdigits == 55)){
        printf("MASTERCARD\n");
    }
    else if((sum%10)==0 && (firstdigits/10==4)){
        printf("VISA\n");
    }
    else{
        printf("INVALID\n");
    }
}
