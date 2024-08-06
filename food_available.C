#include <stdio.h>
#include "movie.h"

void food_available(FILE *file) {
    int choice, size, quantity;
    float price = 0.0, total_price = 0.0;

    printf("Food Menu:\n");
    printf("1. Popcorn - Small (250.00), Medium (350.00), Large (550.00)\n");
    printf("2. Juice - Small (50.00), Medium (80.00), Large (120.00)\n");
    printf("3. Fries - Small (90.00), Medium (130.00), Large (160.00)\n");
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        while (getchar() != '\n');  // Clear the input buffer
        printf("Invalid input. Please enter a number between 1 and 3: ");
    }

    printf("Enter size (1 for Small, 2 for Medium, 3 for Large): ");
    while (scanf("%d", &size) != 1 || size < 1 || size > 3) {
        while (getchar() != '\n');  // Clear the input buffer
        printf("Invalid input. Please enter a size number between 1 and 3: ");
    }

    printf("Enter quantity: ");
    while (scanf("%d", &quantity) != 1 || quantity < 1) {
        while (getchar() != '\n');  // Clear the input buffer
        printf("Invalid input. Please enter a positive number for quantity: ");
    }

    switch (choice) {
        case 1:  // Popcorn
            switch (size) {
                case 1: price = 250.00; break;  // Small
                case 2: price = 350.00; break;  // Medium
                case 3: price = 550.00; break;  // Large
            }
            total_price = price * quantity;
            fprintf(file, "Popcorn ordered - Size: %d, Quantity: %d, Total Price: %.2f\n", size, quantity, total_price);
            printf("Popcorn ordered - Size: %d, Quantity: %d, Total Price: %.2f\n", size, quantity, total_price);
            break;
        case 2:  // Juice
            switch (size) {
                case 1: price = 50.00; break;  // Small
                case 2: price = 80.00; break;  // Medium
                case 3: price = 120.00; break;  // Large
            }
            total_price = price * quantity;
            fprintf(file, "Juice ordered - Size: %d, Quantity: %d, Total Price: %.2f\n", size, quantity, total_price);
            printf("Juice ordered - Size: %d, Quantity: %d, Total Price: %.2f\n", size, quantity, total_price);
            break;
        case 3:  // Fries
            switch (size) {
                case 1: price = 90.00; break;  // Small
                case 2: price = 130.00; break;  // Medium
                case 3: price = 160.00; break;  // Large
            }
            total_price = price * quantity;
            fprintf(file, "Fries ordered - Size: %d, Quantity: %d, Total Price: %.2f\n", size, quantity, total_price);
            printf("Fries ordered - Size: %d, Quantity: %d, Total Price: %.2f\n", size, quantity, total_price);
            break;
        default:
            fprintf(file, "Invalid option\n");
            printf("Invalid option\n");
    }
}
