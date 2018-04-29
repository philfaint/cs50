// prints initials

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){
    // get First and Second and Middle name
    string name = get_string();

    // walk through each letter
    for(int i = 0, n = strlen(name); i < n; i++){
        // print first letter of First name
        if(i == 0)
            printf("%c", toupper(name[i]));
        // print first letters of the following names
        else if(name[i] == ' ')
            printf("%c", toupper(name[i+1]));
    }
    printf("\n");

    return 0;
}