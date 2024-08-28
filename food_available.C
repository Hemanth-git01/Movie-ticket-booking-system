#include "movie.h"
#include <stdio.h>
#include <stdlib.h>

// Function to show available food items
void food_available(FILE *file) {
    int choice, size, quantity;
    float price = 0.0, total_price = 0.0;

    printf("Food Menu:\n");
    printf("1. Popcorn - Small (250.00), Medium (350.00), Large (550.00)\n");
    printf("2. Juice - Small (50.00), Medium (80.00), Large (120.00)\n");
    printf("3. Fries - Small (90.00), Medium (130.00), Large (160.00)\n");
    printf("Enter your choice: ");
    while (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        while (getchar() != '\n'); // Clear the input buffer
        printf("Invalid input. Please enter a number between 1 and 3: ");
    }

    printf("Enter size (1 for Small, 2 for Medium, 3 for Large): ");
    while (scanf("%d", &size) != 1 || size < 1 || size > 3) {
        while (getchar() != '\n'); // Clear the input buffer
        printf("Invalid input. Please enter a number between 1 and 3: ");
    }

    printf("Enter quantity: ");
    while (scanf("%d", &quantity) != 1 || quantity < 1) {
        while (getchar() != '\n'); // Clear the input buffer
        printf("Invalid input. Please enter a positive number: ");
    }

    switch (choice) {
        case 1:
            price = (size == 1) ? 250.00 : (size == 2) ? 350.00 : 550.00;
            break;
        case 2:
            price = (size == 1) ? 50.00 : (size == 2) ? 80.00 : 120.00;
            break;
        case 3:
            price = (size == 1) ? 90.00 : (size == 2) ? 130.00 : 160.00;
            break;
    }

    total_price = price * quantity;
    fprintf(file, "Food Item: %d, Size: %d, Quantity: %d, Total Price: %.2f\n", choice, size, quantity, total_price);
    printf("Total Price: %.2f\n", total_price);
}
