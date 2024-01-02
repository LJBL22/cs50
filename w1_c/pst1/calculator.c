#include <cs50.h>
#include <stdio.h>

//integer
int main(void)
{
    int x = get_int("x: ");
    int y = get_int("y: ");

    printf("%i\n", x + y); //%i means int variable
}

// float
int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    float z = (float) x / (float) y;
    printf("%.20f\n", z); //%li means long int variable //%f means float number
}

// more precise by using double (64 digit)
int main(void)
{
    long x = get_long("x: ");
    long y = get_long("y: ");

    double z = (double) x / (double) y;
    printf("%.20f\n", z); //%li means long int variable //%f means float number
}