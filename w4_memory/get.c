#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    // // get_int
    // int x;
    // printf("Input: ");
    // scanf("%i", &x);
    // // scan user's keyboard for input
    // // location of memory : &x
    // printf("Output: %i\n", x);

    // get_string
    // char *s = NULL;
    char *s = malloc(strlen(s) * sizeof(char));
    printf("s: ");
    scanf("%s", s);
    printf("s: %s\n", s);

    free(s);
}

// Use of uninitialised value of size 8
// Invalid read of size 1
// stack overflow?

// get_string
// see each char and use malloc (sounds like a loop)