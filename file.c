#include <stdio.h>

FILE* initialize_file(const char* filename) {
    FILE *file = fopen("output.txt", "w");
    if (!file) {
        printf("Error opening file for writing.\n");
        return NULL;
    }
    return file;
}

void close_file(FILE* file) {
    if (file) {
        fclose(file);
    }
}
