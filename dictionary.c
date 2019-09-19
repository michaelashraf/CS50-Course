// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "dictionary.h"

// Represents number of buckets in a hash table
#define N (long long int)1e7

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Represents a hash table
node *hashtable[N];

// Hashes word to a number between 0 and 999999, inclusive, based on its first letter
long long int hash(const char *s)
{
    const int P = 53;

    long long int p_pow = 1;

    long long int hash_value = 0;

    for (int i = 0; i < strlen(s); i++)
    {
        hash_value = (hash_value + (tolower(s[i]) - '\'' + 1) * p_pow) % N;

        p_pow =(p_pow * P) % N;
    }

    return hash_value;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // Initialize hash table
    for (int i = 0; i < N; i++)
    {
        hashtable[i] = NULL;
    }

    // Open dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        unload();
        return false;
    }

    // Buffer for a word
    char word[LENGTH + 1];


    // Insert words into hash table
    while (fscanf(file, "%s", word) != EOF)
    {
        //hash the word to a bucket of the hashtable
        long long int key = hash(word);

        //allocate memory for the new node
        node *new_node = malloc(sizeof(node));

        //check for malloc returning a NULL pointer
        if (!new_node)
        {
            unload();

            return false;
        }

        //check if the hashtable node is pointing to another node
        if (hashtable[key] == NULL)
        {
            hashtable[key] = new_node;

            strcpy(new_node->word , word);

            new_node->next = NULL;
        }
        //insert new node at the beginning of the linked list
        else
        {
            strcpy(new_node->word , word);

            new_node->next = hashtable[key];

            hashtable[key] = new_node;
        }
    }

    // Close dictionary
    fclose(file);

    // Indicate success
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    unsigned int number_of_words = 0;

    for (int i = 0; i < N; i++)
    {
        node *ptr = hashtable[i];

        if (ptr != NULL)
        {
            while (ptr != NULL)
            {
                number_of_words++;

                ptr = ptr->next;
            }
        }
    }

    return number_of_words;
}

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    long long int key = hash(word);

    node *cursor = hashtable[key];

    while (cursor != NULL)
    {
        bool same = same_str(word , cursor->word);

        if (same == true)
        {
            return true;
        }

        cursor = cursor->next;
    }

    return false;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    for (int i = 0; i < N; i++)
    {
        if (hashtable[i] != NULL)
        {
            node *tmp;

            while (hashtable[i] != NULL)
            {
                tmp = hashtable[i];

                hashtable[i] = hashtable[i]->next;

                free(tmp);
            }
        }
    }

    for (int i = 0; i < N; i++)
    {
        if (hashtable[i] != NULL)
        {
            return false;
        }
    }

    return true;
}

bool same_str(const char *a , const char *b)
{
    if (strlen(a) != strlen(b))
    {
        return false;
    }

    else
    {
        for (int i = 0 , n = strlen(a) ; i < n ; i++)
        {
            int diff = tolower(a[i]) - tolower(b[i]);

            if (diff)
            {
                return false;
            }
        }
    }

    return true;
}
