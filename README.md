# Movie Ticket Booking System

This project is a basic movie ticket booking system written in C. Users can view a list of available movies, book tickets for those movies, and order food items such as popcorn, juice, and fries. The system includes a main menu with options for each function, ensuring an easy and interactive experience. The program also manages ticket availability and provides detailed booking confirmations.
## Features

- **Check Available Movies**: Users can view a list of available movies.
- **Book Movie Tickets**: Users can book tickets for available movies.
- **Order Food**: Users can order food items like popcorn, juice, and fries.

## Files

- `main.c`: Contains the main function and the menu logic.
- `movie.h`: Contains declarations of the functions and the `Customer` structure.
- `movie_available.c`: Contains the implementation of the `movie_available` function.
- `movie_book_ticket.c`: Contains the implementation of the `movie_book_ticket` function.
- `food_available.c`: Contains the implementation of the `food_available` function.

## How to Compile

To compile the project, use the following command:

```sh
gcc main.c movie_available.c movie_book_ticket.c food_available.c -o movie_booking
