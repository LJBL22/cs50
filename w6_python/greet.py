# Prints a command-line argument
from sys import argv

if len(argv) == 2:
    print(f"hello, {argv[1]}")
else:
    print("hello, world")

# Printing command-line arguments using a slice
for arg in argv[1:]: # print 每一個參數 除了第一個 (i.e. greet.py)
    print(arg)