#include <cs50.h>
#include <string.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{
    string name = get_string("Name: ");
    int length = string_length(name);
    int length2 = strlen(name);

    printf("%i\n", length);
    printf("%i\n", length2);

    // int n = 0;

    // while (name[n] != '\0')
    // {
    //     n++;
    // }

    // printf("%i\n", n);
}

int string_length(string s)
{
    int n = 0;

    while (s[n] != '\0')
    {
        n++;
    }

    return n;
}
