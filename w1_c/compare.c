#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int x = get_int("what is x? ");
    int y = get_int("what is y? ");

    if (x < y)
    {
        printf("x is less than y\n");
    }
    else if (x > y)
    {
        printf("y is less than x\n");
    }
    else
    {
        printf("x is equal to y\n");
    }
}