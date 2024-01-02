# from cs50 import get_int

# # 寫法一
# while True:
#     n = get_int("Height: ")
#     if n > 0:
#         break

# for i in range(n):
#     print("#")

# 寫法二

def main():
    # while True: # 放錯位置結果一直被問....
        n = get_height()
        for i in range(n):
            print("#")

def get_height():
    while True:
        # n = get_int("Height: ")
        try:
            n = int(input("Height: "))
            if n > 0:
                return n
        except ValueError:
             print("Not an integer")

main()