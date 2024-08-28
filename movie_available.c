#include "movie.h"
#include <stdio.h>
#include <stdlib.h>

// Function to show available movies
void movie_available(FILE *file) {
    fprintf(file, "Available Movies\n");
    fprintf(file, "1. KALKI\n2. FIGHTER\n3. MAHARAJA\n");
    printf("Available Movies\n");
    printf("1. KALKI\n2. FIGHTER\n3. MAHARAJA\n");
}
