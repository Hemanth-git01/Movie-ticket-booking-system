#include <stdio.h>
#include <stdlib.h>

FILE* initialize_file(const char* filename) {
    FILE *file = fopen(filename, "a+");
    if (file == NULL) {
        perror("Error opening file");
        return NULL;
    }
    return file;
}

void close_file(FILE* file) {
    if (file != NULL) {
        fclose(file);
    }
}
