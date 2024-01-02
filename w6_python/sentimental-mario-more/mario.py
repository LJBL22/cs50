from cs50 import get_int

while True:
    n = get_int("Height: ")
    if n > 0 and n < 9:
        break

for i in range(n):
    # print() # (possible space) + brick + space2 + brick
    # print(" " * (n-1-i) + "#" * (i+1) + "  " + "#" * (i+1))
    space = " " * (n - 1 - i)
    brick = "#" * (i + 1)
    print(f"{space}{brick}  {brick}")
