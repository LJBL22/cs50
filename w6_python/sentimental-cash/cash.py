from cs50 import get_float


def main():
    n = int(get_cents())
    (quarters, n) = divmod(n, 25)
    (dimes, n) = divmod(n, 10)
    (nickels, n) = divmod(n, 5)
    (pennies, n) = divmod(n, 1)
    sum = quarters + dimes + nickels + pennies
    print(f"{sum}")


def get_cents():
    while True:
        try:
            dollars = get_float("Change owed: ")
            if dollars > 0:
                return dollars * 100
        except ValueError:
            print("Not a number")


main()
