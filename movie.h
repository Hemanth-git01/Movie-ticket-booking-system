#ifndef MOVIE_H
#define MOVIE_H

struct Customer {
    char name[50];
    char email[50];
    unsigned int tickets;
    char movie[20];
};

void movie_available();
void movie_book_ticket(unsigned int *total_tickets_sold, unsigned int total_tickets);
void food_available();

#endif
