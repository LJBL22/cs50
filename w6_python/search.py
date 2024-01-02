# Implements linear search for names
import sys

# A list of names
names = ["Bill", "Charlie", "Fred", "George", "Ginny", "Percy", "Ron"]

# Ask for name
name = input("Add name: ")

# Search for name
# for n in names:
#     if name == n: # 輸入的名字等於 names 裡面的 item i.e. n
#         print("found")
#         sys.exit(0)

if name.capitalize() in names: #  python 可以直接做 linear search # 超強功能首字大寫其他小寫
    print("found")
    sys.exit(0)

print("Not found")
sys.exit(1)