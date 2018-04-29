// gets hash as a command line argument. generate up to 4 symbols alphabetic
// password and compares it's hash with the entered  hash. If they
// are the same - shows the password.

#include <crypt.h>
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

#define ALPHA_LETTERS 26

string hash_gen(string pass, string salt);
_Bool hash_compare(string hash, string hash_test);

int main(int argc, string argv[]){

    if(argc <= 1 || argc>2){
        printf("ERROR\n");
        return 1;
    }

    string hash = argv[1];
    char pass_one[2] = "\0";
    char pass_two[3] = "\0";
    char pass_three[4] = "\0";
    char pass_four[5] = "\0";
    string hash_test;
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    // generates one alphabetic symbol pass
    for(int i =0, n = strlen(alpha); i<n; i++){
        pass_one[0] = alpha[i];
        hash_test = hash_gen(pass_one, "50");
        if(hash_compare(hash, hash_test)!=0){
            printf("%s\n", pass_one);
            return 0;
        }
    }

    // generates two alphabetic symbol pass
    for(int i =0, n = strlen(alpha); i<n; i++){
        pass_two[0] = alpha[i];
        for(int j = 0; j<n; j++){
            pass_two[1] = alpha[j];
            hash_test = hash_gen(pass_two, "50");
            if(hash_compare(hash, hash_test)!=0){
                printf("%s\n", pass_two);
                return 0;
            }
        }
    }

    // generates three alphabetic symbol pass
    for(int i =0, n = strlen(alpha); i < n; i++){
        pass_three[0] = alpha[i];
        for(int j = 0; j<n; j++){
            pass_three[1] = alpha[j];
            for(int k =0; k<n; k++){
                pass_three[2] = alpha[k];
                hash_test = hash_gen(pass_three, "50");
                if(hash_compare(hash, hash_test)!=0){
                    printf("%s\n", pass_three);
                    return 0;
                }
            }
        }
    }

    // generates four alphabetic symbol pass
    for(int i =0, n = strlen(alpha); i<n; i++){
        pass_four[0] = alpha[i];
        for(int j =0; j<n; j++){
            pass_four[1] = alpha[j];
            for(int k =0; k<n; k++){
                pass_four[2] = alpha[k];
                for(int m = 0; m<n; m++){
                    pass_four[3] = alpha[m];
                    hash_test = hash_gen(pass_four, "50");
                    if(hash_compare(hash, hash_test)!=0){
                        printf("%s\n", pass_four);
                        return 0;
                    }
                }
            }
        }
    }

    return 0;
}

// creates hash for the generated password
string hash_gen(string pass, string salt){
    return crypt(pass, salt);
}

// compares generated hash with the hash entered by user
_Bool hash_compare(string hash, string hash_test){

    if(strlen(hash)!=strlen(hash_test)){
        return 0;
    }
    else{
        for(int i =0, n = strlen(hash); i<n; i++){
            if(hash[i] != hash_test[i])
                return 0;
        }
    }
    return 1;
}