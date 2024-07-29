#include <stdio.h>
#include "movie.h"

void food_available(FILE *file) {
    int y;
    printf("Food Menu:\n");
    printf("1. Popcorn\n2. Juice\n3. Fries\n");
    printf("Enter your choice: ");
    while (scanf("%d", &y) != 1 || y < 1 || y > 3) {
        while (getchar() != '\n');
        printf("Invalid input. Please enter a number between 1 and 3: ");
    }

    switch (y) {
        case 1:
            fprintf(file, "Popcorn ordered\n");
            printf("Popcorn ordered\n");
            break;
        case 2:
            fprintf(file, "Juice ordered\n");
            printf("Juice ordered\n");
            break;
        case 3:
            fprintf(file, "Fries ordered\n");
            printf("Fries ordered\n");
            break;
        default:
            fprintf(file, "Invalid option\n");
            printf("Invalid option\n");
    }
}
