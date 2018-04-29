#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
    // get a name from user
    string name = get_string();

    // check whether there was no error
    if(name != NULL){

        // iterate through each letter in the string
        for(int i =0, n = strlen(name); i<n; i++){

            // check if the first character is not a space and print it
            if((i == 0) && (name[0] != ' ')){
                printf("%c", toupper(name[0]));
            }

            // check if next character is NOT space and the current one is space
            else if((name[i+1] != ' ') && (name[i] == ' ')){

                // check if the next character that we're about to print is an alphabetic letter
                if(isalpha(name[i+1]))
                    printf("%c", toupper(name[i+1]));
            }
        }
    }
    printf("\n");
    return 0;
}