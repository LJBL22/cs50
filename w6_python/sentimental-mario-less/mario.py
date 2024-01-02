from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(n):
    space = " " * (n - 1 - i)
    brick = "#" * (i + 1)
    print(f"{space}{brick}")
