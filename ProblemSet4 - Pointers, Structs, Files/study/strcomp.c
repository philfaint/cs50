#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>

_Bool str_comp(char *a, char *b);

int main(void){

    char *s = get_string();
    if(s==NULL){
        return 1;
    }
    char *t = malloc((strlen(s) + 1) * sizeof(char));

    for(int i = 0, n = strlen(s); i<n; i++){
        if(isalpha(*(s+i))){
            *(t+i) = (*(s+i) ^ ('a'^'A'));
        }
        else
            *(t+i) = *(s+i);
    }
    printf("%s\n", t);
    str_comp(s, t) ? printf("Equal\n") : printf("Not equal\n");

    free(t);
    return 0;
}

_Bool str_comp(char *a, char *b){
    if(strlen(a) != strlen(b)){
        return 0;
    }

    for(int i =0, n = strlen(a); i<n; i++){
        if(*(a+i) != *(b+i)){
            return 0;
        }
    }

    return 1;
}