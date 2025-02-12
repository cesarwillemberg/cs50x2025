#include <stdio.h>

void print_row(int width)

int main(void)
{
    // for (int i = 0; i < 4; i++)
    // {
    //     printf("?");
    // }
    // printf("\n");

    // for (int i = 0; i < 3; i++)
    // {
    //     printf("#\n");
    // }

    const int n = 4;
    for (int i = 0; i < n; i++) {
        // for (int j = 0; j < n; j++) {
        //     printf("#");
        // }
        // printf("\n");
        print_row(n);
    }
}

void print_row(int width) {
    for (int i = 0; i < width; i++) {
        printf("#");
    }
    printf("\n");
}
