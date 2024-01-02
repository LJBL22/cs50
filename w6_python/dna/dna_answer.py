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
        pattern = list(reader.fieldnames)
    # todo: Read DNA sequence file into a variable
        with open(sys.argv[2]) as dna_txt:
            dna_sequence = dna_txt.read()

    # todo: Find longest match of each STR in DNA sequence
        result = [] # result = list()
        for str in pattern[1:]: # 跳過第一個 "name" 其餘在此 list 中的 STR
            result.append(longest_match(dna_sequence, str))
            # print(result)
    # todo: Check database for matching profiles
        # Check database for matching profiles
        for row in reader: # iterate rows
            name = row['name']
            match = True  # set match as true
            # print(len(pattern)) # 9
            for i in range(1, len(pattern)):  # start from index 1, omit 'name'
                if int(row[pattern[i]]) != result[i - 1]:
                    match = False  # any STR does not match
                    break  # break the loop
            if match:
                print(name)
                break

        if not match: # false + flase = true
            print("No match")


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
