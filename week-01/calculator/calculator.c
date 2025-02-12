#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // // Prompt user for x
    // int x = get_int("x: ");

    // // Prompt user for y
    // int y = get_int("y: ");

    // // Add numbers
    // int z = x + y;

    // // Perform addition
    // printf("%i\n", z);

    // // int dollars = 1;
    // int dollars = 1;
    // while (true) {
    //     // char c = get_char("Here's $%i. Double it and give to next person? ", dollars);
    //     char c = get_char("Here's $%li. Double it and give to next person? ", dollars);
    //     if (c == 'y') {
    //         dollars *= 2;
    //     }
    //     else {
    //         break;
    //     }
    // }
    // // printf("Here's $%i.\n", dollars);
    // printf("Here's $%li.\n", dollars);

    // Prompt user for x
    // int x = get_int("x: ");

    // // Prompt user for y
    // int y = get_int("y: ");

    // // Divide x by y
    // printf("%i\n", x / y);

    // Prompt user for x
    float x = get_float("x: ");

    // Prompt user for y
    float y = get_float("y: ");

    // Divide x by y
    printf("%.50f\n", x / y);
}


}
