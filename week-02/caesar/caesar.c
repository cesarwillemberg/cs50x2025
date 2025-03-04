#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool validInput(int argc, string argv[]);
string caesarCipher(string plaintext, int key);

int main(int argc, string argv[])
{

    bool isValid = validInput(argc, argv);

    if (!isValid)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    // Convert argv[1] from a `string` to an `int`
    int key = atoi(argv[1]);

    // Prompt user for plaintext
    string plaintext = get_string("plaintext: ");

    string ciphertext = caesarCipher(plaintext, key);

    printf("ciphertext: %s\n", ciphertext);
}

bool validInput(int argc, string argv[])
{

    // Make sure program was run with just one command-line argument
    if (argc != 2)
    {
        return false;
    }

    // Make sure every character in argv[1] is a digit
    for (int i = 0; argv[1][i] != '\0'; i++)
    {
        if (!isdigit(argv[1][i]))
        {
            return false;
        }
    }

    return true;
}

char *caesarCipher(string plaintext, int key)
{

    int n = strlen(plaintext);
    char *ciphertext = malloc(n + 1);

    if (ciphertext == NULL) // Verifica se a alocação de memória foi bem-sucedida
    {
        return NULL;
    }

    // For each character in the plaintext:
    for (int i = 0; i < n; i++)
    {
        // Rotate the character if it's a letter
        char c = plaintext[i];

        if (islower(c))
        {
            ciphertext[i] = ((c - 'a' + key) % 26) + 'a';
        }
        else if (isupper(c))
        {
            ciphertext[i] = ((c - 'A' + key) % 26) + 'A';
        }
        else
        {
            ciphertext[i] = c;
        }
    }
    ciphertext[n] = '\0';
    return ciphertext;
}
