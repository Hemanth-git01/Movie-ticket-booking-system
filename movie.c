#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

// Declaration of Customer structure
struct Customer {
    char name[50];
    char email[50];
    unsigned int tickets;
    char movie[20];
};

// MOVIE NAME DISPLAY FUNCTION
void movie_available() {
    printf("Available Movies\n");
    printf("1. AVENGERS - 250\n2. ENDGAME - 500\n3. INTERSTELLAR - 650\n");
}

// TICKET BOOKING FUNCTION
void movie_book_ticket(unsigned int *total_tickets_sold, unsigned int total_tickets) {
    char movie_name[3][20] = {"AVENGERS", "ENDGAME", "INTERSTELLAR"};
    int PRICE[3] = {250, 500, 650};
    char user_CHOICE[20];
    unsigned int TICKETS = 0;
    int MOVIE_PRICE;

    printf("1. AVENGERS - 250\n2. ENDGAME - 500\n3. INTERSTELLAR - 650\n");
    printf("\nEnter the movie name: ");
    scanf("%s", user_CHOICE);

    // Convert user input to uppercase to handle case sensitivity
    for (int i = 0; user_CHOICE[i]; i++) {
        user_CHOICE[i] = toupper(user_CHOICE[i]);
    }

    printf("\nNO OF TICKETS YOU WANT TO BOOK: ");
    scanf("%u", &TICKETS);

    if (*total_tickets_sold + TICKETS > total_tickets) {
        printf("Not enough tickets available. Only %u tickets remaining.\n", total_tickets - *total_tickets_sold);
        return;
    }

    int found = 0;
    // PRICE CALCULATING USING FOR LOOP
    for (int i = 0; i < 3; i++) {
        if (strcmp(movie_name[i], user_CHOICE) == 0) {
            printf("%s IS AVAILABLE FOR BOOKING.\n", user_CHOICE);
            found = 1;
            MOVIE_PRICE = TICKETS * PRICE[i];
            printf("\nTOTAL PRICE: %d\n", MOVIE_PRICE);
            break;
        }
    }

    if (!found) {
        printf("%s MOVIE IS NOT AVAILABLE FOR BOOKING.\n", user_CHOICE);
        printf("PLEASE SELECT OTHERS\n");
        return;
    }

    // Allocate memory for customer using malloc
    struct Customer *customer = (struct Customer *)malloc(sizeof(struct Customer));
    if (customer == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    printf("\nEnter your name: ");
    scanf("%s", customer->name);
    printf("Enter your email: ");
    scanf("%s", customer->email);
    customer->tickets = TICKETS;
    strcpy(customer->movie, user_CHOICE);

    *total_tickets_sold += TICKETS;

    // Displaying customer details
    printf("\nBooking Details:\n");
    printf("Name: %s\n", customer->name);
    printf("Email: %s\n", customer->email);
    printf("Movie: %s\n", customer->movie);
    printf("Tickets: %u\n", customer->tickets);
    printf("Total Price: %d\n", MOVIE_PRICE);
    printf("Remaining Tickets: %u\n", total_tickets - *total_tickets_sold);

    // Free allocated memory
    free(customer);
}

// FUNCTION FOR FOOD MENU AVAILABILITY
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

int main() {
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
        printf("Enter your choice: ");
        scanf("%d", &x);

        // SWITCH STATEMENT FOR MENU
        switch (x) {
            case 1:
                movie_available();
                break;
            case 2:
                movie_book_ticket(&total_tickets_sold, total_tickets);
                break;
            case 3:
                food_available();
                break;
            case 4:
                printf("Thank you for using our services\n");
                break;
            default:
                printf("WRONG CHOICE!! TRY AGAIN.\n");
        }
    } while (x != 4);

    return 0;
}
