#ifndef MOVIE_H
#define MOVIE_H

#include <stdio.h>

#define MAX_NAME_LENGTH 50
#define MAX_EMAIL_LENGTH 100

// Structure to hold customer information
struct Customer {
    char name[MAX_NAME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    unsigned int tickets;
    char movie[20];
};

// Function declarations
int is_alpha_string(const char *str);          // Function to check if the string contains only alphabetic characters
int is_valid_email(const char *email);        // Function to validate the email

void movie_book_ticket(FILE *file, unsigned int *total_tickets_sold, unsigned int total_tickets);
void movie_available(FILE *file);
void food_available(FILE *file);
FILE* initialize_file(const char* filename);
void close_file(FILE* file);

#endif // MOVIE_H
