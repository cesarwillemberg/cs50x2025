#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);
int coleman_liau_index(int letters, int words, int sentences);

int main(void)
{
    // Prompt the user for some text
    string text = get_string("Text: ");

    // Count the number of letters, words, and sentences in the text
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    // Compute the Coleman-Liau index
    int result = coleman_liau_index(letters, words, sentences);

    // printf("%i\n", result);

    // Print the grade level
    if (result < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (result >= 1 && result < 16)
    {
        printf("Grade %i\n", result);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(string text)
{
    // Return the number of letters in text
    int letter = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isalpha(text[i]))
        {
            letter++;
        }
    }

    return letter;
}

int count_words(string text)
{
    // Return the number of words in text
    int words = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (isspace(text[i]))
        {
            words++;
        }
    }

    return words + 1;
}

int count_sentences(string text)
{
    // Return the number of sentences in text
    int sentences = 0;

    for (int i = 0, len = strlen(text); i < len; i++)
    {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }
    }

    return sentences;
}

int coleman_liau_index(int letters, int words, int sentences)
{

    double L = ((double) letters / words) * 100;
    double S = ((double) sentences / words) * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    return index;
}
