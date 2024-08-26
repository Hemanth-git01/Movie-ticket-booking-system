#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "movie.h"
#include "file.c"
#include "movie_available.c"
#include "movie_book_ticket.c"
#include "food_available.c"

// Function to get a valid menu choice
int get_valid_choice() {
    int choice;
    char buffer[10];

    while (1) {
        printf("Please enter your choice: ");
        if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
            // Remove trailing newline character
            buffer[strcspn(buffer, "\n")] = '\0';

            // Check if the input is numeric
            int valid_input = 1;
            for (int i = 0; buffer[i] != '\0'; i++) {
                if (!isdigit(buffer[i])) {
                    valid_input = 0;
                    break;
                }
            }

            if (valid_input) {
                choice = atoi(buffer);
                if (choice >= 1 && choice <= 5) {
                    return choice; // Valid choice
                }
            }
        }

        // If invalid input, prompt the user again
       printf("Invalid input. Please enter a number between 1 and 4.\n");
    }
}

int main() {
    FILE *file = initialize_file("output.txt");
    if (!file) {
        return 1;
    }

    unsigned int total_tickets_sold = 0;
    const unsigned int total_tickets = 120;

    printf("Welcome to Movie Ticket Booking\n");

    int choice;
    do {
        // Print the menu only once outside the loop
        printf("\nMain Menu:\n");
        printf("1. Check available movies\n");
        printf("2. Book movie tickets\n");
        printf("3. Order food\n");
        printf("4. Exit\n");

        choice = get_valid_choice();

        switch (choice) {
            case 1:
                movie_available(file);
                break;
            case 2:
                movie_book_ticket(file, &total_tickets_sold, total_tickets);
                break;
            case 3:
                food_available(file);
                break;
            case 4:
                printf("Thank you for using our services\n");
                break;
        }
    } while (choice != 5);

    close_file(file);
    return 0;
}
