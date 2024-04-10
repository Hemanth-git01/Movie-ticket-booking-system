#include<stdio.h>
#include<string.h>
#include"main.h"
// MOVIE NAME DISPLAY FUNCTION
void movie_available() {
   printf("Available Movies\n");
   printf("Avengers\nEnd game\nInterstealer\n");
}
//TICKET BOOKING FUNCTION
void movie_book_ticket() {
    char movie_name[3][20] = {"AVENGERS", "ENDGAME", "INTERSTEALER"};
    int PRICE[3] = {250, 500, 650};
    char user_CHOICE[20];
    unsigned int TICKETS = 0;
    int MOVIE_PRICE;

    printf("   PER TICKET DEPEND ON MOVIE  \n AVENGERS-  250   \n ENDGAME -  500 \n INTERSTEALER   -  650\n");
    printf("\nEnter the movie name: ");
    scanf("%s", user_CHOICE);
    printf("\nNO OF TICKETS YOU WANT TO BOOK:");
    scanf("%u", &TICKETS);

    int found = 0;
//PRICE CALCULATING USING FOR LOOP
    for(int i = 0; i < 3; i++) {
        if(strcmp(movie_name[i], user_CHOICE) == 0) {
            printf("%s IS AVAILABLE FOR BOOKING.\n", user_CHOICE);
            found = 1;
            MOVIE_PRICE = TICKETS * PRICE[i];
            printf("\nTOTAL PRICE: %d", MOVIE_PRICE);
        }
    }

    if (!found) {
        printf("%s IS NOT AVAILABLE FOR BOOKING.\n", user_CHOICE);
        printf("PLEASE SELECT OTHERS");
    }

    struct Customer customer;
    printf("\nEnter your name: ");
    scanf("%s", customer.name);
    printf("\nEnter your email: ");
    scanf("%s", customer.email);
    customer.tickets = TICKETS;
    strcpy(customer.movie, user_CHOICE);
}
//FUNCTION FOR FOOD MENU AVAILABLITY
void food_available() {
    int y;
    printf("popcorn PRESS 1 \n Juice PRESS 2 \n fries PRESS 3 \n");
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

    printf("Welcome to Movie Ticket Booking\n ");
    do {
        printf("enter 1 to check movie\n ");
        printf("enter 2 to book movie\n ");
        printf("enter 3 to food menu\n ");
        printf("enter 4 to exit\n ");
        scanf("%d", &x);
//SWITCH STATEMENT FOR MENU IS USED
        switch(x) {
            case 1:
                movie_available();
                break;
            case 2:
                movie_book_ticket();
                break;
            case 3:
                food_available();
                break;
            case 4:
                printf("Thank you for using services\n");
                break;
            default:
                printf("WRONG CHOICE!! TRY AGAIN.\n");
        }
    } while(x != 4);
}
