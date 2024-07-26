#include <stdio.h>
#include "movie.h"

void food_available() {
    int y;
    printf("Food Menu:\n");
    printf("1. Popcorn\n2. Juice\n3. Fries\n");
    printf("Enter your choice: ");
     while (scanf("%d", &y) != 1 || y < 1 || y > 3) {
        while (getchar() != '\n'); // Clear invalid input from buffer
        printf("Invalid input. Please enter a number between 1 and 3: ");
    }


    switch (y) {
        case 1:
            printf("Popcorn ordered\n");
            break;
        case 2:
            printf("Juice ordered\n");
            break;
        case 3:
            printf("Fries ordered\n");
            break;
        default:
            printf("Invalid option\n");
    }
}
