#include <stdio.h>
#include "movie.h"

void movie_available(FILE *file) {
    fprintf(file, "Available Movies\n");
    fprintf(file, "1. KALKI\n2. FIGHTER\n3. MAHARAJA\n");
    printf("Available Movies\n");
    printf("1. KALKI\n2. FIGHTER\n3. MAHARAJA\n");
}
