## while loop 寫法
# j = 0
# while j < 3:
#     print("ha")
#     j += 1

## 引入了 def main() 以避免在 function 在被宣告之前就呼告的問題
## 因而需要寫 main() ，以執行主要程式碼 i.e. 該 function

def main():
    for i in range(3):
        meow()
        i += 1

def meow():
    print("meow")

main()

## 將 for loop 從 main 中移出
def main2():
    woof(3)

def woof(n):
    for n in range(3):
        print("woof")

main2()

