#include<stdio.h>
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
