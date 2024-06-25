#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "cells.h"

void test_initialize_grid() {
    int t = 0;
    int f = 0;

    fprintf(stderr, "Testing initialize_grid ");

    Grid* grid = create_grid(5, 5);
    initialize_grid(grid, 5);

    int alive_count = 0;
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            if (grid->grid[i][j] == ALIVE) {
                alive_count++;
            }
        }
    }
    if (alive_count == 5) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

    delete_grid(grid);
    fprintf(stderr, " DONE (%d/%d)\n", t, t + f);
}

void test_update_grid() {
    int t = 0;
    int f = 0;

    fprintf(stderr, "Testing update_grid ");

    Grid* grid = create_grid(3, 3);
    grid->grid[0][0] = ALIVE;
    grid->grid[0][1] = ALIVE;
    grid->grid[1][0] = ALIVE;

    update_grid(grid);

    if (grid->grid[0][0] == ALIVE) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
    if (grid->grid[0][1] == ALIVE) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
    if (grid->grid[1][0] == ALIVE) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
    if (grid->grid[1][1] == ALIVE) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

    delete_grid(grid);
    fprintf(stderr, " DONE (%d/%d)\n", t, t + f);
}

void test_count_alive_neighbors() {
    int t = 0;
    int f = 0;

    fprintf(stderr, "Testing count_alive_neighbors ");

    Grid* grid = create_grid(3, 3);
    grid->grid[0][0] = ALIVE;
    grid->grid[0][1] = ALIVE;
    grid->grid[1][0] = ALIVE;

    int count = count_alive_neighbors(grid, 1, 1);
    if (count == 3) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

    count = count_alive_neighbors(grid, 0, 0);
    if (count == 2) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

    delete_grid(grid);
    
    fprintf(stderr, " DONE (%d/%d)\n", t, t + f);
}

void test_cells() {
    printf("\n\tTEST CELLS\n");

    test_initialize_grid();
    test_update_grid();
    test_count_alive_neighbors();
}
