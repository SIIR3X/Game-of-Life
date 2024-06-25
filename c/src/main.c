#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "grid.h"
#include "cells.h"

void clear_screen() {
    printf("\e[1;1H\e[2J");
}

int main(int argc, char *argv[]) {
    if (argc != 5) {
        fprintf(stderr, "Usage: %s <rows> <cols> <num_alive_cells> <num_generations>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int rows = atoi(argv[1]);
    int cols = atoi(argv[2]);
    int num_alive_cells = atoi(argv[3]);
    int num_generations = atoi(argv[4]);

    if (rows <= 0 || cols <= 0 || num_alive_cells < 0 || num_alive_cells > rows * cols || num_generations <= 0) {
        fprintf(stderr, "Invalid arguments. Ensure rows and cols are positive, num_alive_cells is non-negative and does not exceed total cells, and num_generations is positive.\n");
        return EXIT_FAILURE;
    }

    Grid* grid = create_grid(rows, cols);
    initialize_grid(grid, num_alive_cells);

    for (int gen = 0; gen < num_generations; gen++) {
        clear_screen();
        print_generation_counter(gen+1);
        print_grid(grid);
        update_grid(grid);
        usleep(200000);
    }

    delete_grid(grid);
    
    return EXIT_SUCCESS;
}
