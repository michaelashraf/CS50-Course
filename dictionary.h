// Declares a dictionary's functionality

#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <stdbool.h>

// Maximum length for a word
// (e.g., pneumonoultramicroscopicsilicovolcanoconiosis)
#define LENGTH 45

// Prototypes
bool load(const char *dictionary);
unsigned int size(void);
bool check(const char *word);
bool unload(void);
bool same_str(const char *a , const char *b);
long long int hash2(const char *s);

#endif // DICTIONARY_H
