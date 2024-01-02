#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int main(void)
{
    // GET A TEXT
    string text = get_string("Text: ");
    int letters = count_letters(text);
    int words = count_words(text);
    // printf("%i letters\n %i words\n", letters, words);
    int sentences = count_sentences(text);
    // printf("%i sentences\n", sentences);
    float L = (float) letters / words * 100;
    float S = (float) sentences / words * 100;
    // printf("%f\n", l);
    // printf("%f\n", s);
    int grade = round(0.0588 * L - 0.296 * S - 15.8);
    // DETERMINE ITS READING LEVEL
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", grade);
    }
}

int count_letters(string text)
{
    int sum = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isalpha(text[i]))
        {
            sum++;
        }
    }
    return sum;
}
int count_words(string text)
{
    int sum = 1;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (isblank(text[i]))
        {
            sum++;
        }
    }
    return sum;
}
int count_sentences(string text)
{
    int sum = 0;
    for (int i = 0, length = strlen(text); i < length; i++)
    {
        if (text[i] == '.' | text[i] == '?' | text[i] == '!')
        {
            sum++;
        }
    }
    return sum;
}