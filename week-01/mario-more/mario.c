#include <cs50.h>
#include <stdio.h>

void addSpace(int width, int total_width);
void layer(int width);
void wall(int width);

int main(void)
{
    int width;
    do
    {
        width = get_int("Height: ");
    }
    while (width < 1);

    wall(width);
}

void wall(int width)
{
    for (int i = 0; i < width; i++)
    {
        addSpace(i, width);
        layer(i);
        printf("  ");
        layer(i);
        printf("\n");
    }
}

void layer(int width)
{
    for (int i = 0; i <= width; i++)
    {
        printf("#");
    }
}

void addSpace(int width, int total_width)
{
    for (int i = 0; i < total_width - width - 1; i++)
    {
        printf(" ");
    }
}
