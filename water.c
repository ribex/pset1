#include <stdio.h>
#include <cs50.h>

int main(void) {

    // Implement a program that reports a user’s water usage, converting minutes spent in the shower to bottles of drinking water.

    int minutes;

    // prompt the user for valid input of a positive int
    do {
        printf("Minutes: ");
        minutes = get_int();
    } while (minutes < 1);

    // multiply by 12 to get the number of bottles
    int bottles = minutes * 12;
    printf("Bottles: %i\n", bottles);
}