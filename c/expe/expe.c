#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "cells.h"

void save_result(double time_spent, const char* output_filename) {
    FILE* output_file = fopen(output_filename, "w");
    if (output_file == NULL) {
        perror("Failed to open output file");
        return;
    }

    fprintf(output_file, "C execution time: %f ms\n", time_spent * 1000);

    fclose(output_file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <input_grid_file>\n", argv[0]);
        return EXIT_FAILURE;
    }
    
    const char* input_filename = argv[1];
    const char* output_filename = "expe/expe_result.txt";

    Grid* grid = load_grid(input_filename);

    clock_t start = clock();

    update_grid(grid);

    clock_t end = clock();

    delete_grid(grid);

    double time_spent = (double)(end - start) / CLOCKS_PER_SEC;

    save_result(time_spent, output_filename);

    return EXIT_SUCCESS;
}