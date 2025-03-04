#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

string logical_of_game(string answerPlayerOne, string answerPlayerTwo);
int calculate_score(string playerAnswer);

int main(void)
{

    // ask word player one
    string answerPlayerOne = get_string("Player 1: ");

    // ask woard player two
    string answerPlayerTwo = get_string("Player 2: ");

    // restul equals logica_of_game
    string result = logical_of_game(answerPlayerOne, answerPlayerTwo);

    // show the result
    printf("%s\n", result);
}

string logical_of_game(string answerPlayerOne, string answerPlayerTwo)
{
    // logical the game
    //  add up the points of the player one
    int scorePlayerOne = calculate_score(answerPlayerOne);

    // add up the points of the player two
    int scorePlayerTwo = calculate_score(answerPlayerTwo);

    // compare the scores and return the winner
    if (scorePlayerOne > scorePlayerTwo)
    {
        return ("Player 1 wins!");
    }
    else if (scorePlayerOne < scorePlayerTwo)
    {
        return ("Player 2 wins!");
    }
    else
    {
        return ("Tie");
    }
}

int calculate_score(string playerAnswer)
{
    int score = 0;
    // percorrer a resposta do player
    for (int i = 0, len = strlen(playerAnswer); i < len; i++)
    {
        if (isupper(playerAnswer[i]))
        {
            score += POINTS[playerAnswer[i] - 'A'];
        }
        else if (islower(playerAnswer[i]))
        {
            score += POINTS[playerAnswer[i] - 'a'];
        }
    }

    return score;
}
