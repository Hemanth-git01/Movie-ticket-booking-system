#include <stdio.h>
#include "movie.h"

void movie_available(FILE *file) {
    fprintf(file, "Available Movies\n");
    fprintf(file, "1. AVENGERS\n2. ENDGAME\n3. INTERSTELLAR\n");
    printf("Available Movies\n");
    printf("1. AVENGERS\n2. ENDGAME\n3. INTERSTELLAR\n");
}
