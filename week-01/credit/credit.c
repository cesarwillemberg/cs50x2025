#include <cs50.h>
#include <math.h>
#include <stdio.h>

int get_every_other_digit(long cardNumber);
int multiplybytwo(int secondDigit);
int count_quant_digits(long cardNumber);
bool validVisaCard(long cardNumber, int quantDigits);
bool validAmexCard(long cardNumber, int quantDigits);
bool validMasterCard(long cardNumber, int quantDigits);

int main(void)
{
    long cardNumber = get_long("Number: ");
    int ever_other_digit_sum = get_every_other_digit(cardNumber);
    int quantDigits = count_quant_digits(cardNumber);

    int validVisa = validVisaCard(cardNumber, quantDigits);
    int validAmax = validAmexCard(cardNumber, quantDigits);
    int validMaster = validMasterCard(cardNumber, quantDigits);

    if (ever_other_digit_sum % 10 != 0)
    {
        printf("INVALID\n");
        return 0;
    }
    else if (validVisa)
    {
        printf("VISA\n");
    }
    else if (validAmax)
    {
        printf("AMEX\n");
    }
    else if (validMaster)
    {
        printf("MASTERCARD\n");
    }
    else
    {
        printf("INVALID\n");
        return 0;
    }
}

bool validVisaCard(long cardNumber, int quantDigits)
{
    if (quantDigits == 13)
    {
        int firstDigit = cardNumber / pow(10, 12);
        if (firstDigit == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else if (quantDigits == 16)
    {
        int firstDigit = cardNumber / pow(10, 15);
        if (firstDigit == 4)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}

bool validAmexCard(long cardNumber, int quantDigits)
{
    if (quantDigits == 15)
    {
        int firstTwoDigit = cardNumber / pow(10, 13);
        if (firstTwoDigit == 34 || firstTwoDigit == 37)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}

bool validMasterCard(long cardNumber, int quantDigits)
{
    if (quantDigits == 16)
    {
        int firstDigit = cardNumber / pow(10, 14);
        if (firstDigit > 50 && firstDigit < 56)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }
    return false;
}

int count_quant_digits(long cardNumber)
{
    int count = 0;

    while (cardNumber > 0)
    {
        count++;
        cardNumber = cardNumber / 10;
    }
    return count;
}

int get_every_other_digit(long cardNumber)
{
    int sum = 0;
    bool alternatedBetweenDigit = false;

    while (cardNumber > 0)
    {
        if (alternatedBetweenDigit)
        {
            int secondDigit = cardNumber % 10;
            int numberMultiplied = multiplybytwo(secondDigit);
            sum += numberMultiplied;
        }
        else
        {
            int firstDigit = cardNumber % 10;
            sum += firstDigit;
        }
        alternatedBetweenDigit = !alternatedBetweenDigit;
        cardNumber = cardNumber / 10;
    }
    return sum;
}

int multiplybytwo(int secondDigit)
{
    int multiplyTheDigit = secondDigit * 2;
    int sum = 0;
    while (multiplyTheDigit > 0)
    {
        int multiplyLastDigit = multiplyTheDigit % 10;
        sum += multiplyLastDigit;
        multiplyTheDigit = multiplyTheDigit / 10;
    }

    return sum;
}
