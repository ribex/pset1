#include <stdio.h>
#include <cs50.h>

int main(void) {

    int height;

    // prompt the user for valid input between 0 and 23 inclusive
    do {
        printf("Height: ");
        height = get_int();
    } while ((height > 23) || (height < 0));

    int spaces = height - 1;
    for (int i = 0; i < height; i++) {

        // each row has height + 1 total characters
        // print spaces
        for (int j = spaces - i; j > 0; j--) {
            printf(" ");
        }

        // print # blocks
        for (int k = 0; k < i + 2; k++) {
            printf("#");
        }

        printf("  ");

        // print # blocks
        for (int k = 0; k < i + 2; k++) {
            printf("#");
        }

        // print spaces
        for (int j = spaces - i; j > 0; j--) {
            printf(" ");
        }

        // print a newline per row
        printf("\n");
    }

}