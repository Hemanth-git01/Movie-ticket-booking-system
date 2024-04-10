#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include<stdio.h>
//TO STORE CUSTOMER DETAILS
struct Customer {
    char name[50];
    char email[50];
    int tickets;
    char movie[20];
};
void movie_available();
void movie_book_ticket();
void food_available();
#endif