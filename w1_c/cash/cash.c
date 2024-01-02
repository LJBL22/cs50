#include <cs50.h>
#include <stdio.h>

int get_cents(void);
int calculate_quarters(int cents);
int calculate_dimes(int cents);
int calculate_nickels(int cents);
int calculate_pennies(int cents);

int main(void)
{
    // Ask how many cents the customer is owed
    int cents = get_cents();

    // Calculate the number of quarters to give the customer
    int quarters = calculate_quarters(cents);
    cents = cents - quarters * 25;

    // Calculate the number of dimes to give the customer
    int dimes = calculate_dimes(cents);
    cents = cents - dimes * 10;

    // Calculate the number of nickels to give the customer
    int nickels = calculate_nickels(cents);
    cents = cents - nickels * 5;

    // Calculate the number of pennies to give the customer
    int pennies = calculate_pennies(cents);
    cents = cents - pennies * 1;

    // Sum coins
    int coins = quarters + dimes + nickels + pennies;

    // Print total number of coins to give the customer
    printf("%i\n", coins);
}

int get_cents(void)
{
    int money;
    do
    {
        money = get_int("Change owed: ");
    }
    while (money < 0);
    return money;
}

int calculate_quarters(int cents)
{
    int coin_number = 0;
    while (cents >= 25)
    {
        cents = cents - 25;
        coin_number++;
    }
    return coin_number;
}

int calculate_dimes(int cents)
{
    int coin_number = 0;
    while (cents >= 10)
    {
        cents = cents - 10;
        coin_number++;
    }
    return coin_number;
}

int calculate_nickels(int cents)
{
    int coin_number = 0;
    while (cents >= 5)
    {
        cents = cents - 5;
        coin_number++;
    }
    return coin_number;
}

int calculate_pennies(int cents)
{
    int coin_number = 0;
    while (cents >= 1)
    {
        cents = cents - 1;
        coin_number++;
    }
    return coin_number;
}
