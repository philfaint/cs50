// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// define alphabet size + \' and define the index for letter in the trie node
#define ALPHA 27
#define INDEX(c) ((int)c - (int)'a')

// trie structure
typedef struct trie{
    bool is_word;
    struct trie *letters[ALPHA];
} trie;

// global variable for the dictionary size and loaded var
unsigned int dict_size_g;
bool loaded_g;
trie *root;

// Prototypes
bool check(const char *word);
bool load(const char *dictionary);
unsigned int size(void);
bool unload(void);
trie *get_node(void);
void insert(trie *root, const char *word);
void free_trie(trie **root_l);

#endif // DICTIONARY_H
