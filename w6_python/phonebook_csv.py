import csv

name = input("Name: ")
number = input("Number: ")

# file = open("phonebook.csv", "a") # append mode (similar to write)
with open("phonebook.csv", "a") as file:
# indent
    # writer = csv.writer(file)
    # writer.writerow([name, number])
    # 將上面收到的 input variable 以 list 的方式寫入
    # 收到 david 0910 就會傳入 ["david", "0910"]
    write_dict = csv.DictWriter(file, fieldnames=["name", "number"])
    write_dict.writerow({"name": name, "number": number})
# file.close()
