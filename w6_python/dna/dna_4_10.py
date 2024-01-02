import csv
import sys


def main():

    # todo: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    # todo: Read database file into a variable
    with open(sys.argv[1], 'r') as database:
        reader = csv.DictReader(database)  # read as a dictionary
        for row in reader:
            pattern = list(row.keys()) # read keys 存在 List 中
            # pattern2 = list(row.values()) # read values 存在 List 中
            # pattern3 = list(row.items()) # read items 存在 List 中
            # # 從 dict_keys(['name', 'AGATC', 'AATG', 'TATC'])
            # # 變成 ['name', 'AGATC', 'AATG', 'TATC']
            # print(pattern) # ['name', 'AGATC', 'AATG', 'TATC']
            # print(pattern2) # ['Alice', '2', '8', '3']
            # print(pattern3) # [('name', 'Alice'), ('AGATC', '2'), ('AATG', '8'), ('TATC', '3')]
            break

    # todo: Read DNA sequence file into a variable
        with open(sys.argv[2]) as dna_txt:
                dna_sequence = dna_txt.read()
    # todo: Find longest match of each STR in DNA sequence
        result = list()
        for i in range(len(pattern)):
            if pattern[i] != 'name':
                result.append(longest_match(dna_sequence, pattern[i]))
                # print(result)
    # todo: Check database for matching profiles
    # 例如現在是 4 所以要進入 dictionary 去查找誰的 AGATC 是 4 （看來是Bob)
        for row in reader: # [alice, 3, 2, 5]
            name = row['name'] # alice
            match = True # 每一個 row 的起始都設定為 true
            # print(len(pattern)) # 9 但不知道為什麼印了足足多了 10+ 次
            for i in range(1, len(pattern)): # [4,1,5] 從1開始給三個數值
                count = int(row[pattern[i]]) # pattern ['name', 'AGATC', 'AATG', 'TATC']
        #         print(count)
        #         print(result[i - 1])
                if count != result[i - 1]:
                    match = False
                    break
            if match:
                print(name)
                break
        if not match:
            print("No match")

        #     if (!match) print("No match")
        #     sys.exit(1)
        # print(f"{name}")
        # sys.exit(0)


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
