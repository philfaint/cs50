// modified caesar encryption. enter keyword as a command line argument (only alphabetic letters)

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_CHAR 26

int key(string key, int i);
char crypt_upper(char c, int k);
char crypt_lower(char c, int k);
_Bool key_check(string key);

int main(int argc, string argv[]){

    int k =0;
    if(argc<=1 || argc > 2){
        return 1;
    }

    if(key_check(argv[1]) == 0){
        return 1;
    }

    printf("plaintext: ");
    string plaintext = get_string();
    printf("ciphertext: ");

    int m = 0;

    for(int i = 0, n = strlen(plaintext); i < n; i++){
        if(plaintext[i] != ' ' && isalpha(plaintext[i])){
            k = key(argv[1], m);
            m++;

            if(isupper(plaintext[i])){
                printf("%c", crypt_upper(plaintext[i], k));
            }
            else if(islower(plaintext[i])){
                printf("%c", crypt_lower(plaintext[i], k));
            }
        }
        else{
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}

_Bool key_check(string key){

    for(int i =0, n = strlen(key); i<n; i++){
        if(!isalpha(key[i])){
            return 0;
        }
    }
    return 1;
}

int key(string key, int number){

    int key_num = number % strlen(key); //0
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int k = 0;

    for(int i =0, n = strlen(key); i<n; i++){
        key[i] = toupper(key[i]);
    }

    for(int i = 0; i < ALPHA_CHAR; i++){
        if(alpha[i] == key[key_num])
            k = i;
    }
    return k;
}

char crypt_upper(char c, int k){
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char crypt_char;

    for(int i =0; i<ALPHA_CHAR; i++){
        if(c == alpha[i])
            crypt_char = alpha[(i+k)%26];
    }
    return crypt_char;
}

char crypt_lower(char c, int k){
    string alpha = "abcdefghijklmnopqrstuvwxyz";
    char crypt_char;

    for(int i =0; i < ALPHA_CHAR; i++){
        if(c == alpha[i])
            crypt_char = alpha[(i+k)%26];
    }
    return crypt_char;
}
