// Ceasar crypto. turns one letter into another on amount of letters

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_LETTERS 26

char upper(char a, int k);
char lower(char a, int k);

int main(int argc, string argv[]){

    if(argc<=1 || argc>2){
        printf("Error\n");
        return 1;
    }

    // get string
    printf("plaintext: ");
    string plaintext = get_string();

    // turn the key from argv into integer
    int k = atoi(argv[1]);

    printf("ciphertext: ");

    // iterate through each character in the string
    for(int i=0, n = strlen(plaintext); i<n; i++){
        // check if it's an alphabet letter
        if(isalpha(plaintext[i])){
            //check if it's Uppercase letter
            if(isupper(plaintext[i])){
                //call upper function and print encrypted letter
                printf("%c", upper(plaintext[i], k));
            }
            // check if it's lower case letter
            else if(islower(plaintext[i])){
                //call lower function and print encrypted letter
                printf("%c", lower(plaintext[i], k));
            }
        }
        // print the unencrypted symbol, if it's not an alphabetic letter
        else
            printf("%c", plaintext[i]);
    }
    printf("\n");
    return 0;
}

// encrypts uppercase letters
char upper(char a, int k){

    string upper_ch = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ch_encrypt;

    for(int j =0; j<ALPHA_LETTERS; j++){
        if(a == upper_ch[j]){
            // compares the current plaintext letter and substitutes it with an encrypted one
            ch_encrypt = upper_ch[(j+k)%26];
        }
    }
    return ch_encrypt;
}

// encrypts lowercase letters
char lower(char a, int k){

    string lower_ch = "abcdefghijklmnopqrstuvwxyz";
    char ch_encrypt;

    for(int j =0; j<ALPHA_LETTERS; j++){
        if (a == lower_ch[j]){
            // compares the current plaintext letter and substitutes it with an encrypted one
            ch_encrypt = lower_ch[(j+k)%26];
        }
    }
    return ch_encrypt;
}
