#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(){
    // get the string from the user
    string s = get_string();

    // check if get_string returned an actual string
    if(s!=NULL){

        // iterate through each of the characters in string
        for(int i = 0, n = strlen(s); i<n; i++){

            // print ith character in the string s
            printf("%c\n", s[i]);
        }
    }
    return 0;
}