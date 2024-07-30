#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "movie.h"

int is_alpha_string(const char *str) {
    while (*str) {
        if (!isalpha(*str)) {
            return 0; // Not an alphabetic string
        }
        str++;
    }
    return 1; // Is an alphabetic string
}

int is_valid_email(const char *email) {
    int  has_lower = 0, has_special = 0;
    while (*email) {
          if (islower(*email)) {
            has_lower = 1;
        } else if (ispunct(*email)) {
            has_special = 1;
        }
        email++;
    }
    return has_lower && has_special;
}

void movie_book_ticket(FILE *file, unsigned int *total_tickets_sold, unsigned int total_tickets) {
    char movie_name[3][20] = {"KALKI", "FIGHTER", "MAHARAJA"};
    int BASE_PRICE[3][3] = {
        {170, 250, 380},
        {150, 220, 430},
        {180, 240, 360}
    };
    char user_CHOICE[20];
    unsigned int TICKETS = 0;
    int CATEGORY = 0;
    char *CATEGORY_NAME[3] = {"SILVER", "GOLD", "RECLINER"};
    int MOVIE_PRICE;

    printf("1. KALKI - Silver:170 , Gold: 250, Recliner: 380\n");
    printf("2. FIGHTER - Silver: 150, Gold: 220, Recliner: 430\n");
    printf("3. MAHARAJA - Silver: 180, Gold: 240, Recliner: 360\n");
    printf("\nEnter the movie name: ");
    scanf("%s", user_CHOICE);

    for (int i = 0; user_CHOICE[i]; i++) {
        user_CHOICE[i] = toupper(user_CHOICE[i]);
    }

    if (!is_alpha_string(user_CHOICE)) {
        printf("Invalid movie name. Please enter a valid movie name.\n");
        return;
    }

    printf("\nNO OF TICKETS YOU WANT TO BOOK: ");
    while (scanf("%u", &TICKETS) != 1) {
        while (getchar() != '\n');
        printf("Invalid input. Please enter a number: ");
    }

    if (*total_tickets_sold + TICKETS > total_tickets) {
        printf("Not enough tickets available. Only %u tickets remaining.\n", total_tickets - *total_tickets_sold);
        return;
    }

    printf("Choose category:\n1. Silver\n2. Gold\n3. Recliner\n");
    printf("Enter your choice: ");
    while (scanf("%d", &CATEGORY) != 1 || CATEGORY < 1 || CATEGORY > 3) {
        while (getchar() != '\n');
        printf("Invalid input. Please enter a number between 1 and 3: ");
    }

    int found = 0;
    for (int i = 0; i < 3; i++) {
        if (strcmp(movie_name[i], user_CHOICE) == 0) {
            printf("%s IS AVAILABLE FOR BOOKING.\n", user_CHOICE);
            found = 1;
            MOVIE_PRICE = TICKETS * BASE_PRICE[i][CATEGORY - 1];
            printf("\nTOTAL PRICE: %d\n", MOVIE_PRICE);
            break;
        }
    }

    if (!found) {
        printf("%s IS NOT AVAILABLE FOR BOOKING.\n", user_CHOICE);
        printf("PLEASE SELECT OTHERS\n");
        return;
    }

    struct Customer *customer = (struct Customer *)malloc(sizeof(struct Customer));
    if (customer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter your name: ");
    scanf("%s", customer->name);

    do {
        printf("Enter your email: ");
        scanf("%s", customer->email);
        if (!is_valid_email(customer->email)) {
            printf("Invalid email. Please enter an email with at least one uppercase letter, one lowercase letter, and one special character.\n");
        }
    } while (!is_valid_email(customer->email));

    customer->tickets = TICKETS;
    strcpy(customer->movie, user_CHOICE);

    *total_tickets_sold += TICKETS;

    fprintf(file, "\nBooking Details:\n");
    fprintf(file, "Name: %s\n", customer->name);
    fprintf(file, "Email: %s\n", customer->email);
    fprintf(file, "Movie: %s\n", customer->movie);
    fprintf(file, "Tickets: %u\n", customer->tickets);
    fprintf(file, "Category: %s\n", CATEGORY_NAME[CATEGORY - 1]);
    fprintf(file, "Total Price: %d\n", MOVIE_PRICE);
    fprintf(file, "Remaining Tickets: %u\n", total_tickets - *total_tickets_sold);

    printf("\nBooking Details:\n");
    printf("Name: %s\n", customer->name);
    printf("Email: %s\n", customer->email);
    printf("Movie: %s\n", customer->movie);
    printf("Tickets: %u\n", customer->tickets);
    printf("Category: %s\n", CATEGORY_NAME[CATEGORY - 1]);
    printf("Total Price: %d\n", MOVIE_PRICE);
    printf("Remaining Tickets: %u\n", total_tickets - *total_tickets_sold);

    free(customer);
}
