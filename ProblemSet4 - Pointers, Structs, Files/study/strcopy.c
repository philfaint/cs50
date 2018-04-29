#include <stdio.h>
#include <cs50.h>
#include <string.h>

void strcopy(char *a, char *b);

int main(void){

    char *s = get_string();
    if(s==NULL){
        return 1;
    }

    char *t =  malloc((strlen(s) + 1) * sizeof(char));
    strcopy(s,t);

    printf("%s\n", t);
    free(t);
    return 0;
}

void strcopy(char *a, char *b){

    for(int i =0, n = strlen(a); i<n; i++){
        *(b+i) = *(a+i);
    }
}