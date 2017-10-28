#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void) {

    printf("O hai! ");

    // get valid user input above 0
    float changeInput;
    do {
        printf("How much change is owed?\n");
        changeInput = get_float();
    } while (changeInput < 0);

    // convert change from float: multiply by 100 and then round
    int change = round(changeInput * 100);

    // printf("pennies = %i\n", change);

    int quarter = 25;
    int dime = 10;
    int nickel = 5;
    int penny = 1;

    // calculate number of quarters
    int quarters = change / quarter;
    // calculate leftover change
    change = change % quarter;
    // printf("%i\n", quarters);
    // printf("balance after quarters = %i\n", change);

    int dimes = change / dime;
    change = change % dime;
    // printf("%i\n", dimes);
    // printf("balance after dimes = %i\n", change);

    int nickels = change / nickel;
    change = change % nickel;
    // printf("%i\n", nickels);
    // printf("balance after nickels = %i\n", change);

    int pennies = change / penny;
    change = change % penny;
    // printf("%i\n", pennies);
    // printf("balance after pennies = %i\n", change);

    int coins = quarters + dimes + nickels + pennies;
    printf("%i\n", coins);
}