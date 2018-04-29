#include "dictionary.h"

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    int length = strlen(word);

    trie *trav = root;
    for(int i =0; i<length; i++){
        char ch = (char)tolower(*(word+i));
        int index = INDEX(ch);
        if(index == -58){
            index = 26;
        }

        if(!trav->letters[index]){
            return false;
        }
        else{
            trav = trav->letters[index];
        }
    }
    if(!trav->is_word){
        return false;
    }
    else{
        return true;
    }
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    FILE *dict = fopen(dictionary, "r");

    char *word = malloc(sizeof(char) * (LENGTH+1));

    root = get_node();
    if(!root){
        return false;
    }

    while(fscanf(dict, "%s", word)!= EOF){
        insert(root, word);
        dict_size_g++;
    }
    loaded_g = true;

    return true;
}

// creates a new node for the trie
trie *get_node(void){

    trie *node = malloc(sizeof(trie));
    if(node){
        node->is_word = false;
        for(int i =0; i<ALPHA; i++){
            node->letters[i] = NULL;
        }
    }

    return node;
}

// inserts a letter from the word into a node
void insert(trie *root_l, const char *word){
    trie *node = root_l;

    for(int i =0, length = strlen(word); i<length; i++){
        int index = INDEX(*(word+i));
        if(index == -58){
            index = 26;
        }

        if(!node->letters[index]){
            node->letters[index] = get_node();
        }
        node=node->letters[index];
    }
    node->is_word=true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    if(loaded_g){
        return dict_size_g;
    }
    else{
        return 0;
    }
}

// !!!! DOESN't WORK!!! Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for(int i =0; i<ALPHA; i++){
        if(root->letters[i] != NULL){
            free_trie(&(root->letters[i]));
        }
    }
    return true;
}

// !!!!! DOESN't WORK Unload is the only thing left
void free_trie(trie **root_l){
    for(int i =0; i<ALPHA; i++){
        if(root_l->letters[i] != NULL){
            free_trie(root->letters[i]);
        }
    }
    free(root_l);
}
