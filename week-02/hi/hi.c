#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // char c1 = 'H';
    // char c2 = 'I';
    // char c3 = '!';

    // printf("%c%c%c\n", c1, c2, c3);
    // printf("%i %i %i \n", c1, c2, c3);

    // string s = "HI!";
    // string t = "BYE!";
    // printf("%s\n", s);
    // printf("%s\n", t);


    // printf("%c%c%c\n", s[0], s[1], s[2]);
    // printf("%i %i %i %i \n", s[0], s[1], s[2], s[3]);

    // printf("%c%c%c%c\n", t[0], t[1], t[2], t[3]);
    // printf("%i %i %i %i %i \n", t[0], t[1], t[2], t[3], t[4]);

    string words[2];
    words[0] = "HI!";
    words[1] = "BYE!";

    printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
    printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);
}
