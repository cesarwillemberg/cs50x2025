#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // printf("hello, world\n");
    string name = get_string("What's your name? ");
    printf("hello, %s\n", name);
}

// clang hello.c
// clang -o hello hello.c
// rm a.out
// clang -o hello hello.c -lcs50
