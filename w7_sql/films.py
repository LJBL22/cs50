import csv

with open("films.csv", "r") as file:
    reader = csv.DictReader(file) # from .reader -> .DictReader
    counts = {}
    for row in reader:
        film = row["country"] # from num/slice to string accesptable
        if film in counts:
            counts[film] += 1
        else:
            counts[film] = 1

    ## replace by lambda...
    # def get_value(film):
    #     return counts[film]


    for film in sorted(counts, reverse=True, key=lambda film: counts[film]):
        print(f"{film}: {counts[film]}")

    country = input("Search country: ")
    if country in counts:  # 經常會忘記，if 寫成 for
        print(f"{country}: {counts[country]}")

    # dvd, baidu, cinema = 0, 0, 0

    # for row in reader:
    #     film = row["source"] # from num/slice to string accesptable
    #     if film == "學校DVD":
    #         dvd += 1
    #     elif film == "Baidu":
    #         baidu += 1
    #     elif film == "新竹威秀":
    #         cinema += 1

    # print(f"學校DVD: {dvd}")
    # print(f"Baidu: {baidu}")
    # print(f"新竹威秀: {cinema}")