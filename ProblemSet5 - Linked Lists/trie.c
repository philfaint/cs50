#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define LENGTH 45
#define INDEX(c)  ((int)c - (int)'a')

typedef struct trie_new{
    bool is_word;
    struct trie_new *alpha[27];
} trie_new;

trie_new *get_node(void);
void insert(const char* word, trie_new *root);


int main(void){

    FILE *file = fopen("large", "r");
    if(!file){
        printf("Error!");
        return 1;
    }

    char *word = malloc(sizeof(char) * (LENGTH+1));

    trie_new *root = get_node();

    while(fscanf(file, "%s", word)!=EOF){

        insert(word, root);
    };


    return 0;
}

trie_new *get_node(void){

    trie_new* node = malloc(sizeof(trie_new));
    if(node){
        node->is_word = false;
        for(int i =0; i<27; i++){
            node->alpha[i] = NULL;
        }
    }
    return node;
}

void insert(const char* word, trie_new *root){

    trie_new *node = root;
    for(int i = 0, length = strlen(word); i<length; i++){
        int index = INDEX(*(word + i));
        if(index == -58){
            index = 26;
        }

        if(!node->alpha[index]){
            node->alpha[index] = get_node();
        }

        node = node->alpha[index];
    }
    node->is_word = true;
}
