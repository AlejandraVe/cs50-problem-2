#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float get_grade(string text);

int main(void)
{
    string text;
    float grade;

    text = get_string("Text: ");
    grade = get_grade(text);
    if (grade < 1)
        printf("Before Grade 1\n");
    else if (grade > 16)
        printf("Grade 16+\n");
    else
        printf("Grade %.0f\n", grade);
    return (0);
}

float get_grade(string text)
{
    float avg_sentences;
    float avg_letters;
    float grade;
    float letter_count = 0;
    float sentences_count = 0;
    int total_words = 1; // number of words in the whole text

    for (int i = 0; text[i]; i++)
    {
        if (text[i] == ' ')
            total_words++;
    }
    for (int i = 0; text[i]; i++)
    {
        if (isalpha(text[i]))
            letter_count++;
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            if (text[i + 1] == '.' && text[i + 2] == '.')
                i += 2;
            sentences_count++;
        }
    }
    avg_letters = (letter_count * 100) / total_words;
    avg_sentences = (sentences_count * 100) / total_words;
    grade = (0.0588 * avg_letters) - (0.296 * avg_sentences) - 15.8;
    return (grade);
}
