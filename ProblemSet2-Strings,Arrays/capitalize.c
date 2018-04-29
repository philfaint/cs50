#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){

    // get sting from the user
    string s = get_string();

    //check if get_string returned a string
    if (s != NULL){

        // iterate through each character in the string
        for(int i =0, n=strlen(s); i<n; i++){

            // check if the character is in lower case
            /*if (s[i] >= 'a' && s[i] <= 'z')
                // print this character in upper case using the function toupper
                printf("%c", toupper(s[i]));
            else
                printf("%c", s[i]);*/

            printf("%c", toupper(s[i]));
        }
    }
    printf("\n");
    return 0;
}