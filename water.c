#include <stdio.h>
#include <cs50.h>

int main(void) {
    printf("Minutes: ");
    // get user input for an integer of number of minutes
    // multiply by 12 to get the number of bottles
    int bottles = get_int() * 12;
    printf("Bottles: %i\n", bottles);
}