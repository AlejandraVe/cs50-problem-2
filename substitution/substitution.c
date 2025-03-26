#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int check_rules(int argc, string argv[]);
string compare_text(string plaintext, string argv[]);
void ft_substitute(string argv[]);
char change_cipher(char c, string argv[]);
int check_duplicates(string argv[]);

int main(int argc, string argv[])
{
    if (check_rules(argc, argv))
        return (0);
    else
        return (1);
}

void ft_substitute(string argv[])
{
    int i = 0;
    string plaintext;
    string ciphertext;

    plaintext = get_string("plaintext: ");
    ciphertext = compare_text(plaintext, argv);
    while (plaintext[i])
    {
        if (islower(plaintext[i]))
            ciphertext[i] = tolower(ciphertext[i]);
        if (isupper(plaintext[i]))
            ciphertext[i] = toupper(ciphertext[i]);
        if (!isalpha(plaintext[i]))
            ciphertext[i] = plaintext[i];
        i++;
    }
    printf("ciphertext: %s\n", ciphertext);
}

string compare_text(string plaintext, string argv[])
{
    int i = 0;
    int j = 0;

    while (plaintext[i])
        i++;
    string ciphertext = malloc(sizeof(string) * (i + 1));
    for (int i = 0; plaintext[i]; i++)
        ciphertext[i] = plaintext[i];
    i = 0;
    while (ciphertext[i]) // this makes the plaintext lowercase
    {
        if (isupper(ciphertext[i]))
            ciphertext[i] = tolower(ciphertext[i]);
        i++;
    }
    while (ciphertext[j])
    {
        if (isalpha(ciphertext[j]))
            ciphertext[j] = change_cipher(ciphertext[j], argv);
        j++;
    }
    return (ciphertext);
}

char change_cipher(char c, string argv[])
{
    int i = 0;
    char ret;
    string alphabet = "abcdefghijklmnopqrstuvwxyz"; // 97 in Ascii*/

    while (alphabet[i])
    {
        if (alphabet[i] == c)
            break;
        i++;
    }
    ret = argv[1][i];
    return (argv[1][i]);
}

int check_rules(int argc, string argv[])
{
    int alpha = 1; // my boolean to know if all the characters are alphabetic
    int duplicates = 0; // my boolean to know if there are no duplicates
    int i = 0;

    if (argc != 2 )
    {
        printf("Usage: ./substitution key\n");
        return (0);
    }
    while (argv[1][i])
    {
        if (isalpha(argv[1][i]))
            alpha = 1;
        else
        {
            alpha = 0;
            break;
        }
        i++;
    }
    duplicates = check_duplicates(argv);
    if (strlen(argv[1]) != 26 && alpha == 1)
    {
        printf("Key must contain 26 characters\n");
        return (0);
    }
    else if (alpha == 0)
    {
        printf("Usage: ./substitution key\n");
        return (0);
    }
    else if (duplicates == 0)
    {
        printf("Key must not contain duplicates\n");
        return (0);
    }
    else if (strlen(argv[1]) == 26 && alpha == 1 && duplicates == 1)
        ft_substitute(argv);
    return (alpha);
}

int check_duplicates(string argv[])
{
    int i = 0;
    int j = 1;
    int ret = 1;

    string temp = malloc(sizeof(string) * (strlen(argv[1]) + 1));
    for (int n = 0; argv[1][n]; n++)
        temp[n] = argv[1][n];
    for (int i = 0; temp[i]; i++)
    {
        if (isupper(temp[i]))
            temp[i] = tolower(temp[i]);
    }
    while (temp[i])
    {
        j = 1;
        while (temp[i] != temp[i + j] && temp[i + j])
        {
            j++;
            ret = 1;
        }
        if (temp[i] == temp[j + i])
        {
            ret = 0;
            break;
        }
        i++;
    }
    return (ret);
}
