#include <cs50.h>
#include <stdio.h>

int get_positive_int(void);
void meow(int n);

int main(void)
{
    // int i = 3;
    // while (i < 0) {
    //     printf("meow\n");
    //     i--;
    // }
    // int i = 0;
    // while (i < 3) {
    //     printf("meow\n");
    //     i++;
    // }
    // for(int i = 0; i < 3; i++) {
    //     // printf("meow\n");
    //     // meow();
    // }
    // while (true) {
    //     printf("meow\n");
    // }

    int n = get_positive_int();
    meow(n);

}

int get_positive_int(void) {
    int n;
    do {
        n = get_int("Number: ");
    }
    while (n < 1);
    return n;
}

void meow(int n)
{
    // printf("meow\n");

    for (int i = 0; i < n; i++) {
        printf("meow\n");
    }
}
