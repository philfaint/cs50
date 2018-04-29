#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main(int argc, string argv[]){

    if(argc<=1||argc>2){
        return 1;
    }

    FILE* words = fopen("words", "r"); // words - pointer to file. fopen arguments - "file name", "r" (read only), "w" (write)
    if (words == NULL)
    {
        printf("File does not exist.\n");
        return 1;
    }

    string word = argv[1]; // assigned command line argument to a string
    char s[128]; // created an array of chars where we'll store words from file

    while(fscanf(words, "%s\n", s) == 1){
        // scanf will scan each word in the file and store it to s string. fscanf returns 1 if it found a word based on arguments
        if(strcmp(word, s) == 0) // compare our word to the word in dictionary
            printf("YES!\n");
    }

    fclose(words);
    return 0;
}