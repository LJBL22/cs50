s = input("Do you agree? ")

# if s == "Y" or "y":
# if s in ["Y", "y"]:

# if s.lower() in ["y", "yes"]:
#     print("Agree.")
# elif s.lower() in ["N", "n"]:
#     print("Not agree.")

s = s.lower()

if s in ["y", "yes"]:
    print("Agree.")
elif s in ["N", "n"]:
    print("Not agree.")