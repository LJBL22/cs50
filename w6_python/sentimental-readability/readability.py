from cs50 import get_string


def main():
    # get a text
    text = get_string("Text: ")
    letters = count_letters(text)
    words = text.count(" ") + 1
    sentences = text.count(".") + text.count("?") + text.count("!")

    # the Coleman-Liau formula
    L = float(letters / words * 100)
    S = float(sentences / words * 100)
    grade = round(0.0588 * L - 0.296 * S - 15.8)

    # DETERMINE ITS READING LEVEL
    if grade < 1:
        print("Before Grade 1")
    elif grade >= 16:
        print("Grade 16+")
    else:
        print(f"Grade {grade}")


def count_letters(text):
    letters = 0
    for i in range(len(text)):
        if text[i].isalpha():
            letters += 1
    return letters


main()
