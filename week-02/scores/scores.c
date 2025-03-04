#include <cs50.h>
#include <stdio.h>

// int main(void)
// {
    // int n = 3;
    // int score1 = 72;
    // int score2 = 73;
    // int score3 = 33;
    // int scores[n];
    // scores[0] = 72;
    // scores[1] = 73;
    // scores[2] = 33;
    // for(int i = 0; i < n; i++)
    // {
    //     scores[i] = get_int("Score: ");
    // }
    // Print average
    // printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) /  (float) 3.0);
    // printf("Average: %f\n", (scores[0] + scores[1] + scores[2]) /  (float) n);
// }

//Const
const int N = 3;

//Prototype
float average(int length, int array[]);

int main(void)
{
    // GET scores
    int scores[N];
    for(int i = 0; i < N; i++)
    {
        scores[i] = get_int("Scores: ");
    }

    //Print average
    printf("Average: %f\n", average(N, scores));

}

float average(int length, int array[])
{
    // Calculate average
    int sum = 0;
    for(int i = 0; i < length; i++)
    {
        sum += array[i];
    }
    return sum / (float) length;
}
