#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int number;
    struct node *next;
}
node;

int main(int argc, char *argv[]) //= string argv[]
{
    node *list = NULL;

    for (int i = 1; i < argc; i++)
    {
        int number = atoi(argv[i]); //change string to num
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            // David: still need to be done: free previous node momories
            return 1;
        }
        n -> number = number;
        n -> next = NULL;
        n->next = list; // (n*).next points to the current first node of list;
        list = n; // list point to the first node of n;
    }

    // while loop
    node *ptr = list; // a temp pointer (only store addres of nodes) called ptr points to the current first node of list;
    while (ptr != NULL)
    {
        printf("%i\n", ptr -> number);
        ptr = ptr -> next;
    }

    // Free memory
    ptr = list; // reset back to the beginning of list
    while (ptr != NULL)
    {
        node *next = ptr->next;
        free(ptr);
        ptr = next;
    }

    // // for loop
    // for( node *ptr = list; ptr != NULL; ptr = ptr -> next) // not work
    // {
    //     printf("%i\n", ptr -> number);
    // }

    // // Free memory
    // node *ptr = list;
    // while (ptr != NULL)
    // {
    //     node *next = ptr->next;
    //     free(ptr);
    //     ptr = next;
    // }
}