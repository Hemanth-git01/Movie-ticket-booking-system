#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movie.h"
#include "file.c"
#include "movie_available.c"
#include "movie_book_ticket.c"
#include "food_available.c"

// Function declarations
int is_alpha_string(const char *str);
int is_valid_email(const char *email);
int get_valid_choice();
void movie_book_ticket(FILE *file, unsigned int *total_tickets_sold, unsigned int total_tickets);
void movie_available(FILE *file);
void food_available(FILE *file);
FILE* initialize_file(const char* filename);
void close_file(FILE* file);

void displayMenu() {
    printf("Movie Ticket Booking System\n");
    printf("1. View available movies\n");
    printf("2. Book movie tickets\n");
    printf("3. Order food\n");
    printf("4. Exit\n");
}

// Function to get a valid user choice
int getValidChoice() {
    int choice;
    char ch;
    while (1) {
        printf("\nEnter your choice: ");
        if (scanf("%d", &choice) == 1) {
            ch = getchar();
            if (ch == '\n') {
                if (choice >= 1 && choice <= 4) {
                    return choice;
                } else {
                    printf("Invalid choice. Please try again.\n");
                }
            } else {
                printf("Invalid choice. Please enter a valid option.\n");
                while (ch != '\n' && ch != EOF) {
                    ch = getchar();
                }
            }
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
            while (getchar() != '\n');
        }
    }
}


int is_alpha_string(const char *str) {
    while (*str) {
        if (!isalpha((unsigned char)*str)) {
            return 0; // False if non-alphabetic character is found
        }
        str++;
    }
    return 1; // True if all characters are alphabetic
}

int is_valid_email(const char *email) {
    int has_at = 0, has_dot = 0, has_lower = 0;
    while (*email) {
        if (islower(*email)) {
            has_lower = 1;
        } else if (*email == '@') {
            has_at = 1;
        } else if (*email == '.') {
            has_dot = 1;
        }
        email++;
    }
    return has_at && has_dot && has_lower;
}

int main() {
    FILE *file;
    unsigned int total_tickets_sold = 0;
    const unsigned int total_tickets = 50;

    file = initialize_file("booking_records.txt");
    if (file == NULL) {
        return 1;
    }

    int choice;
    displayMenu();

    do {
        choice = getValidChoice();

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
                printf("Exiting the system.\n");
                break;
            default:
                printf("Invalid choice. Please select a valid option.\n");
                break;
        }
    } while (choice != 4);

    close_file(file);
    return 0;
}
