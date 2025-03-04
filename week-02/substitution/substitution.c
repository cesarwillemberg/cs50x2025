#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validInput(int argc, string argv[]);
string substitutionFunc(string argv[], string plaintext);

int main(int argc, string argv[])
{

    bool isValid = validInput(argc, argv);

    if (isValid)
    {
        string plaintext = get_string("plaintext: ");

        string ciphertext = substitutionFunc(argv, plaintext);

        printf("ciphertext: %s\n", ciphertext);
    }
}

bool validInput(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./subistitution key.\n");
        exit(1);
    }

    int n = strlen(argv[1]);

    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        exit(1);
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Key must only contain alphabetc characters.\n");
            exit(1);
        }
    }

    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        for (int j = i + 1; argv[1][j] != '\0'; j++)
        {
            if (tolower(argv[1][i]) == tolower(argv[1][j]))
            {
                printf("Key must not contain repeated characters.\n");
                exit(1);
            }
        }
    }

    return true;
}

string substitutionFunc(string argv[], string plaintext)
{
    int n = strlen(plaintext);
    char *ciphertext = malloc(n + 1);

    for (int i = 0; i < n; i++)
    {
        char c = plaintext[i];
        if (islower(c))
        {
            int index = c - 'a';
            ciphertext[i] = tolower(argv[1][index]);
        }
        else if (isupper(c))
        {
            int index = c - 'A';
            ciphertext[i] = toupper(argv[1][index]);
        }
        else
        {
            ciphertext[i] = c;
        }
    }

    return ciphertext;
}
