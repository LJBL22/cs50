from cs50 import get_string
print("Hello, World.")

answer = get_string("What's your name? ")
print("Hello, " + answer)
print("Hello,", answer) # print function provide space between
print(f"Hello, {answer}") # format strings (fstrings)