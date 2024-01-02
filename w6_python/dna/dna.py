import csv
import sys


def main():
    # todo: Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)
    # todo: Read database file into a variable
    with open(sys.argv[1], "r") as database:
        reader = csv.DictReader(database)  # read as a dictionary
        data = list(reader)
        # print(data)

        pattern = [data[0].keys()]

        # pattern = reader.fieldnames  # 儲存標題
        # todo: Read DNA sequence file into a variable
        with open(sys.argv[2]) as dna_txt:
            dna_sequence = dna_txt.read()
        # todo: Find longest match of each STR in DNA sequence
        result = list()
        for i in range(len(pattern)):
            if pattern[i] != "name":
                result.append(longest_match(dna_sequence, pattern[i]))
        # todo: Check database for matching profiles
            for row in reader:
                name = row["name"]
                match = True  # 每一個 row 的起始都設定為 true
                for i in range(1, len(pattern)):  # [4,1,5] 從1開始給三個數值
                    count = int(
                        row[pattern[i]]
                    )  # pattern ['name', 'AGATC', 'AATG', 'TATC']
                    if count != result[i - 1]:
                        match = False
                        break
                if match:
                    print(name)
                    sys.exit(0)
                if not match:
                    print("No match")
                    sys.exit(1)


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
