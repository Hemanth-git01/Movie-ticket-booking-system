#include <stdio.h>
#include<stdlib.h>


// Function to display available seats
void displaySeats() {
    printf("Available Seats:\n");
    printf("  1 2 3 4 5 6 7 8 9 10\n");

}

// Function to book a seat
void bookSeat() {
    int row, col;
    printf("Enter row and column number (e.g., 2 3): ");

}

// Function to display food/snack menu
void displayMenu() {
    printf("Food/Snack Menu:\n");

}

// Function to take food/snack order
void orderFood() {
    int choice, quantity;
    printf("Enter item number to order: ");

}

// Main function
int main() {
    int option;
    do {
        printf("1. Display Available Seats\n");
        printf("2. Book a Seat\n");
        printf("3. Display Food/Snack Menu\n");
        printf("4. Order Food/Snack\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &option);

        switch (option) {
            case 1:
                displaySeats();
                break;
            case 2:
                bookSeat();
                break;
            case 3:
                displayMenu();
                break;
            case 4:
                orderFood();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option.\n");
        }
    } while (option != 5);

    return 0;
}
