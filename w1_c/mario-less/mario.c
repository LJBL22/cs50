#include <cs50.h>
#include <stdio.h>

int get_height(void);
void print_grid(int size);
int main(void)
{ // ask user to input height
    int n = get_height();
    // 4. draw one brick in a new line, then next...until the given number
    print_grid(n);
}

int get_height(void)
{
    int num;
    do
    {
        num = get_int("Height: ");
    }
    // 2. the number should be limited from 1 to 8
    // 3. if 2 does not match, go back to 1
    while (num < 1 || num > 8);
    return num;
}

// void print_left_grid(int size)
// {
//     for (int i = 0; i < size; i++)
//         {//execute print brick
//         printf("%i", i);
//         for (int j = 0; j <= i; j++)
//         {
//             printf("%i", j);//check
//             printf("#");
//         }//execute a new line
//         printf("\n");
//         }
// }
void print_grid(int size)
{
    for (int i = 0; i < size; i++)
    { // execute print space
        for (int j = size - 1; j > i; j--)
        {
            printf(" ");
        }
        // execute print brick
        for (int k = 0; k <= i; k++)
        {
            printf("#");
        } // execute a new line
        printf("\n");
    }
}