#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_grid(int size);
int main(void)
{
    int n = get_height();
    print_grid(n);
}

int get_height()
{
    int n;
    do
    {
        n = get_int("Height: ");
    }
    while (n > 8 || n < 1);
    return n;
}

void print_grid(int size)
{
    int i, j; // each j in different scope
    for (i = 0; i < size; i++)
    { // execute print space
        for (j = size - 1; j > i; j--)
        {
            printf(" ");
        }
        // execute print brick
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        // excute print 2 spaces
        printf("  ");
        // execute print brick
        for (j = 0; j <= i; j++)
        {
            printf("#");
        }
        // execute a new line
        printf("\n");
    }
}