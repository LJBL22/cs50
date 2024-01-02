#include <cs50.h>
#include <stdio.h>

long get_card_num(void);
bool checksum(long number);
void get_card_type(long number);

int main(void)
{
    long number = get_card_num();
    bool result = checksum(number);
    if (result == 0)
    {
        printf("INVALID\n");
    }
    else
    {
        get_card_type(number);
    }
}

long get_card_num(void)
{
    long number = get_long("Number: ");
    return number;
}

// checksum
bool checksum(long number)
{
    // deal with the even
    int sum = 0;
    int i = 1;
    long number2 = number;
    while (number >= 10)
    {
        int last_two = number % 100 / 10;
        number = number / 100;
        int x = last_two * 2;
        if (x >= 10)
        {
            x = x % 10 + x / 10;
        }
        sum += x;
    }
    // deal with the odd
    do
    {
        int last_one = number2 % 10;
        number2 = number2 / 100;
        sum += last_one;
    }
    while (number2 >= 1);

    return (sum % 10 == 0);
}

// length & starting digits
// passed both then decide which card type
void get_card_type(long number)
{
    if ((number >= 34e13 && number < 35e13) || (number >= 37e13 && number < 38e13))
    {
        printf("AMEX\n");
    }
    else if ((number >= 51e14 && number < 56e14))
    {
        printf("MASTERCARD\n");
    }
    else if ((number >= 4e12 && number < 5e12) || (number >= 4e15 && number < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}