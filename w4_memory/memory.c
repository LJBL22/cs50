#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int *x = malloc(3 * sizeof(int));
    if (x == NULL)
    // malloc: This function returns the address of the first byte of memory allocated
    // or NULL in cases of error
    // (as when insufficient memory is available).
    {
        return 1;
    }

    x[0] = 72;
    x[1] = 73;
    x[2] = 33;

    free(x);
    return 0;
}