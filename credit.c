#include <cs50.h>
#include <stdio.h>

// Implement a program that determines whether a provided credit card number is valid according to Luhn’s algorithm.
int main(void)
{
    long long cardnumber = 0;

    // get a positive long long card number from the user
    do
    {
        printf("Number: ");
        cardnumber = get_long_long();

    } while (cardnumber <= 0);

    // "twos" refers to the even numbered digits starting on the right side
    int sumTwos = 0, sumNotTwos = 0, twosDigit, notTwosDigit, cardNumLength = 0;
    // keep track of the leftover card number as we chop it from the right side
    long long chopCard = cardnumber;

    // Three steps of Luhn's algorithm below, 1), 2), 3)
    // 1) Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
    do
    {
    // sum the digits that aren't multiplied by 2
    notTwosDigit = chopCard % 10;  // store this digit for later
    sumNotTwos += notTwosDigit;
    cardNumLength++;
    // chop off the rightmost digit
    chopCard /= 10;
    if (chopCard == 0)
    {
        break;
    }

    // multiply the next digit by 2 and add it to the sum
    twosDigit = chopCard % 10;  // store this digit for later
    int evenTimesTwo = twosDigit * 2;
    sumTwos += evenTimesTwo % 10;
    sumTwos += evenTimesTwo / 10;
    cardNumLength++;
    // chop off the rightmost digit
    chopCard /= 10;
    } while (chopCard > 0);

    //  2) Add the sum to the sum of the digits that weren’t multiplied by 2.
    int checksum = sumTwos + sumNotTwos;
    //  3) If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (checksum % 10 == 0)
    {
        // printf("checksum passes \n");
        // printf("%i\n", cardNumLength);

        // start checking card type based on number of digits in the cardnumber, and the first one or two values on the left
        if (cardNumLength == 15 && (notTwosDigit == 3 && (twosDigit == 4 || twosDigit == 7)))
        {
            printf("AMEX\n");
            return 0;
        }
        else if (cardNumLength == 16 && (twosDigit == 5 && (notTwosDigit > 0 && notTwosDigit < 6)))
        {
            printf("MASTERCARD\n");
            return 0;
        }
        else if ((cardNumLength == 13 && notTwosDigit == 4) || (cardNumLength == 16 && twosDigit == 4))
        {
            printf("VISA\n");
            return 0;
        }
        else
        {
        printf("INVALID\n");
        return 0;
        }
    }
    printf("INVALID\n");
}