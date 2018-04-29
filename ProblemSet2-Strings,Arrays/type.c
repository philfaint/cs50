// type like a teenager with every second letter as capital

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void){

    string s = get_string();
    int count = 0;

    for(int i =0, n = strlen(s); i<n; i++){
        if(isalpha(s[i])){
            if(!(count%2))
                // s[i] = T; ~('a'-'A') = 32 otherwise: 1011111. So if the letter is already capital, this
                // will keep it capital. If it's not, it will make it capital.
                s[i] &= ~('a'-'A');
            else
                s[i] |= ('a'-'A');
            count++;
        }
    }
    printf("%s\n", s);
    return 0;
}