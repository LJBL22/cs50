# Implements a phone book
from cs50 import get_string

# examples
scores = list()
scores2 = [] # same

peoplee = dict()
peoplee2 = {} # same

people = {                          # dictionary with key-value pairs
    "Carter": "+1-617-495-1000",
    "David": "+1-949-468-2750"
}

# Search for name
name = get_string("Name: ")
if name in people:  # search key
    print(f"Number: {people[name]}") # get the value people[name]