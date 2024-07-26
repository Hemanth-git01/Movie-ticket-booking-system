#include <stdio.h>
#include "movie.h"

void food_available() {
    int y;
    printf("Food Menu:\n");
    printf("1. Popcorn\n2. Juice\n3. Fries\n");
    printf("Enter your choice: ");
    scanf("%d", &y);

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
