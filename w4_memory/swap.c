#include <stdio.h>

void swap(int *a, int *b);

int main (void)
{
    int x = 1;
    int y = 2;

    printf("int x is %i while int y is %i\n", x, y);
    swap(&x, &y);// add ampersand &
    printf("int x is %i while int y is %i\n", x, y);
}

void swap(int *a, int *b) // add asterik
{
    int temp = *a;
    *a = *b;
    *b = temp;
}