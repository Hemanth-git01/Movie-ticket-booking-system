#include <stdio.h>
#include "movie.h"
#include "file.c"
#include "movie_available.c"
#include "movie_book_ticket.c"
#include "food_available.c"

int main() {
    FILE *file = initialize_file("output.txt");
    if (!file) {
        return 1;
    }

    int x;
    unsigned int total_tickets_sold = 0;
    const unsigned int total_tickets = 120;

    printf("Welcome to Movie Ticket Booking\n");
    do {
        printf("\nMain Menu:\n");
        printf("1. Check available movies\n");
        printf("2. Book movie tickets\n");
        printf("3. Order food\n");
        printf("4. Exit\n");

        while (scanf("%d", &x) != 1 || x < 1 || x > 4) {
            while (getchar() != '\n'); // Clear invalid input from buffer
            printf("Invalid input. Please enter a number between 1 and 4: ");
        }

        switch (x) {
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
            default:
                printf("WRONG CHOICE!! TRY AGAIN.\n");
        }
    } while (x != 4);

    close_file(file);
    return 0;
}
