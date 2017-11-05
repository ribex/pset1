#include <cs50.h>
#include <stdio.h>

int main(void)
{

    long long cardnumber = 0;

    do
    {
        printf("Number: ");
        cardnumber = get_long_long();

    } while (cardnumber <= 0);

    int sumTwos = 0, sumNotTwos = 0, twosDigit, notTwosDigit, cardNumLength = 0;
    long long chopCard = cardnumber;

    // Multiply every other digit by 2, starting with the number’s second-to-last digit, and then add those products' digits together.
    do
    {
    // sum the digits that aren't multiplied by 2
    notTwosDigit = chopCard % 10;
    sumNotTwos += notTwosDigit;
    cardNumLength++;
    // chop off the rightmost digit
    chopCard /= 10;

    // multiply the next digit by 2
    twosDigit = chopCard % 10;
    int evenTimesTwo = twosDigit * 2;
    sumTwos += evenTimesTwo % 10;
    sumTwos += evenTimesTwo / 10;
    cardNumLength++;
    // chop off the rightmost digit
    chopCard /= 10;
    } while (chopCard > 0);

    // Add the sum to the sum of the digits that weren’t multiplied by 2.
    int checksum = sumTwos + sumNotTwos;
    //  If the total’s last digit is 0 (or, put more formally, if the total modulo 10 is congruent to 0), the number is valid!
    if (checksum % 10 != 0)
    {
        printf("Not valid\n");
    }
    else
    {
        printf("Valid\n");
    }

    // cc company

    // print output

    // printf("%lli\n", cardnumber);
}