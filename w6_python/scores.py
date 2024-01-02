from cs50 import get_int

scores = [] #  data struc: scores = list()
for i in range(3):
    score = get_int("Score: ")
    # scores.append(score) #  add item to list
    scores += [score] # to concate two lists by += or +

average = sum(scores) / len(scores)
print(f"Average: {average}")

