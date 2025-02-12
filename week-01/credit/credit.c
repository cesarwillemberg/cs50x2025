#include <cs50.h>
#include <math.h>
#include <stdio.h>

int every_other_digit(long cardNumber);
int multiplayAndSum(int last_digit);
int number_of_digits(long cardNumber);
bool isValidAmex(long cardNumber, int numDigit);
bool isValidMasterCard(long cardNumber, int numDigit);
bool isValidVisa(long cardNumber, int numDigit);

int main(void)
{
    long cardNumber = get_long("Number: ");
    int sum_every_other_digit = every_other_digit(cardNumber);
    int numDigits = number_of_digits(cardNumber);
    bool amax = isValidAmex(cardNumber, numDigits);
    bool master = isValidMasterCard(cardNumber, numDigits);
    bool visa = isValidVisa(cardNumber, numDigits);
    if (sum_every_other_digit % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (amax == true)
    {
        printf("AMEX\n");
    }
    else if (master == true)
    {
        printf("MASTERCARD\n");
    }
    else if (visa == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

bool isValidAmex(long cardNumber, int numDigit)
{
    int first_two_digits = cardNumber / pow(10, 13);
    if ((numDigit == 15) && (first_two_digits == 34 || first_two_digits == 37))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidMasterCard(long cardNumber, int numDigit)
{
    int first_two_digits = cardNumber / pow(10, 14);
    if ((numDigit == 16) && (first_two_digits > 50 && first_two_digits < 56))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool isValidVisa(long cardNumber, int numDigit)
{
    if (numDigit == 13)
    {
        int first_digit = cardNumber / pow(10, 12);
        if (first_digit == 4)
        {
            return true;
        }
    }

    else if (numDigit == 16)
    {
        int first_digit = cardNumber / pow(10, 15);
        if (first_digit == 4)
        {
            return true;
        }
    }
    return false;
}

int number_of_digits(long cardNumber)
{
    int count = 0;
    while (cardNumber > 0)
    {
        count += 1;
        cardNumber = cardNumber / 10;
    }

    return count;
}

int every_other_digit(long cardNumber)
{
    int sum = 0;
    bool isAlternateDigit = false;

    while (cardNumber > 0)
    {
        if (isAlternateDigit == true)
        {
            int last_digit = cardNumber % 10;
            int product = multiplayAndSum(last_digit);
            sum = sum + product;
        }
        else
        {
            int last_digit = cardNumber % 10;
            sum = sum + last_digit;
        }
        isAlternateDigit = !isAlternateDigit;
        cardNumber = cardNumber / 10;
    }
    return sum;
}

int multiplayAndSum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;
    while (multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;
    }
    return sum;
}
