#include <cs50.h>
#include <stdio.h>

void greedyAlgorithm(int money);

int main(void)
{
    int money;
    do
    {
        money = get_int("Change owed: ");
    }
    while (money < 1);

    greedyAlgorithm(money);
}

void greedyAlgorithm(int money)
{
    int coins[] = {25, 10, 5, 1};
    int count = 0;

    for (int i = 0; i < 4; i++)
    {
        count += money / coins[i];
        money %= coins[i];
    }

    printf("%d\n", count);
}
