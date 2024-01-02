// Implements a dictionary's functionality

#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>   // add this
#include <stdlib.h>  // add this
#include <string.h>  // add this
#include <strings.h> // add this 居然有差 s

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// You may change the value of N in dictionary.c,
// so that your hash table can have more buckets.
// ⭐ TODO: Choose number of buckets in hash table
const unsigned int N = 25000;

// Hash table
node *table[N];

// node amount
int total_nodes = 0;

// ⭐ 4. Returns true if word is in dictionary, else false
// be case-“in”sensitive. 不區分大小寫
bool check(const char *word)
{
    // TODO
    // 先得到該 word 位於哪個 linked list
    int index = hash(word);
    // 設立一個暫時的指針 cursor ，首先與該 ll 指向同樣的位址
    node *cursor = table[index];

    // cursor 一個個指向對應的 word
    // 當 next 不是 NULL 的時候 代表都還在這個 ll 中
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0) // case insensitive 比對 string
        {
            return true;
        }
        cursor = cursor->next;
    }
    return false;
}

// 2. Hashes word to a number
// You can look at hash functions you find on the internet to get inspiration
// on how to create a better one but in the end,
// you have to code your own hash function.
// ref01: https://cs50.harvard.edu/x/2023/shorts/hash_tables/
// ref02: https://stackoverflow.com/questions/34595/what-is-a-good-hash-function

unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int hash = 0;
    for (int i = 0; word[i] != '\0'; i++)
    {
        hash = hash * 31 + tolower(word[i]); // tolower return ascii integer
    }
    return hash % N;
}

// 1. Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open the dictionary
    FILE *file = fopen(dictionary, "r");
    if (file == NULL)
    {
        return false;
    }

    // read string from file one at a time
    char dic_word[LENGTH + 1]; // 單字 array

    // 讀取字典中的 string dic_word //當還讀得到單字的時候
    while (fscanf(file, "%s", dic_word) != EOF)
    {
        node *ptr = malloc(sizeof(node));
        if (ptr == NULL)
        {
            return false;
        }
        strcpy(ptr->word, dic_word); // strcpy(儲存的位置, 來源)
        ptr->next = NULL;
        int index = hash(ptr->word); // hash 放入對象當參數\回傳一個 index 值
        // node *table[N]; 思考錯 不用先給 就先空著

        // an array of linked lists
        ptr->next = table[index]; // 原本錯寫 ptr->word 會變成 array type 'char[46]' is not assignable
        table[index] = ptr;
        total_nodes++;
    }
    fclose(file); // 472bytes!!!!
    return true;
}

// 3. Returns number of words in dictionary if loaded, else 0 if not yet loaded
// 回傳字典中的單字總數 i.e. node 數量
// iterate 每個 linked list 計算
// or 在加上 node 的時候就計算好
unsigned int size(void)
{
    // TODO
    return total_nodes;
}

// 5. Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    // iterating each linked list in hash table
    // 製造一個 tmp node
    for (int i = 0; i < N; i++)
    {
        node *cursor = table[i];

        while (cursor != NULL)
        {
            node *tmp = cursor;
            cursor = cursor->next;
            free(tmp);
        }

        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }

    return false;
}