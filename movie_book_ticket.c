#include "movie.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int is_valid_integer(const char *input) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (!isdigit(input[i])) {
            return 0;  // Return false if a non-digit character is found
        }
    }
    return 1;  // Return true if the input contains only digits
}


void movie_book_ticket(FILE *file, unsigned int *total_tickets_sold, unsigned int total_tickets) {
    char movie_name[3][20] = {"KALKI", "FIGHTER", "MAHARAJA"};
    int BASE_PRICE[3][3] = {
        {170, 250, 380},
        {150, 220, 430},
        {180, 240, 360}
    };
    char user_choice[20];
    unsigned int tickets = 0;
    int category = 0;
    char *CATEGORY_NAME[3] = {"SILVER", "GOLD", "RECLINER"};
    int movie_price;
    int valid_movie = 0;

    printf("1. KALKI - Silver:170 , Gold: 250, Recliner: 380\n");
    printf("2. FIGHTER - Silver: 150, Gold: 220, Recliner: 430\n");
    printf("3. MAHARAJA - Silver: 180, Gold: 240, Recliner: 360\n");

    while (!valid_movie) {
        printf("\nEnter the movie name: ");
        scanf("%s", user_choice);

        for (int i = 0; user_choice[i]; i++) {
            user_choice[i] = toupper(user_choice[i]);
        }
        if (!is_alpha_string(user_choice)) {
            printf("Invalid movie name. Please enter a valid movie name.\n");
            continue;
        }

        for (int i = 0; i < 3; i++) {
            if (strcmp(movie_name[i], user_choice) == 0) {
                printf("%s available for booking\n", user_choice);
                valid_movie = 1;
                break;
            }
        }

        if (!valid_movie) {
            printf("%s IS NOT AVAILABLE FOR BOOKING.\n", user_choice);
            printf("PLEASE SELECT FROM THE LISTED MOVIES\n");
        }
    }

    printf("\nNO OF TICKETS YOU WANT TO BOOK: ");
    while (scanf("%u", &tickets) != 1 || tickets < 1) {
        while (getchar() != '\n'); // Clear the input buffer
        printf("Invalid input. Please enter a positive number: ");
    }

    if (*total_tickets_sold + tickets > total_tickets) {
        printf("Not enough tickets available. Only %u tickets remaining.\n", total_tickets - *total_tickets_sold);
        return;
    }

    printf("Choose category:\n1. Silver\n2. Gold\n3. Recliner\n");
    printf("Enter your choice: ");
    while (1) {
        int result = scanf("%d", &category);
        while (getchar() != '\n'); // Clear the input buffer

        if (result != 1 || category < 1 || category > 3) {
            printf("Invalid input. Please enter a number between 1 and 3: ");
        } else {
            break;
        }
    }

    for (int i = 0; i < 3; i++) {
        if (strcmp(movie_name[i], user_choice) == 0) {
            movie_price = tickets * BASE_PRICE[i][category - 1];
            printf("\nTOTAL PRICE: %d\n", movie_price);
            break;
        }
    }

    struct Customer *customer = (struct Customer *)malloc(sizeof(struct Customer));
    if (customer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    do {
        printf("\nEnter your name: ");
        scanf("%s", customer->name);
        if (!is_alpha_string(customer->name)) {
            printf("Invalid name. Please enter a name with only alphabetic characters.\n");
        }
    } while (!is_alpha_string(customer->name));

    do {
        printf("Enter your email: ");
        scanf("%s", customer->email);
        if (!is_valid_email(customer->email)) {
            printf("Invalid email. Please enter an email with at least one lowercase letter and one at and one dot .\n");
        }
    } while (!is_valid_email(customer->email));

    customer->tickets = tickets;
    strcpy(customer->movie, user_choice);

    *total_tickets_sold += tickets;

    fprintf(file, "Name: %s, Email: %s, Movie: %s, Tickets: %u, Category: %s, Total Price: %d\n", customer->name, customer->email, customer->movie, customer->tickets, CATEGORY_NAME[category - 1], movie_price);

    printf("TICKET BOOKED SUCCESSFULLY!\n");
    free(customer);
}
