#include <time.h>
#include <stdlib.h>
#include "cells.h"

/**
 * @brief Initializes the grid with a specified number of alive cells.
 *
 * @param grid Pointer to the grid to be initialized.
 * @param num_alive_cells Number of alive cells to be placed in the grid.
 */
void initialize_grid(Grid* grid, int num_alive_cells) {
	srand(time(NULL));  // Seed the random number generator

	// Randomly place alive cells in the grid
	int placed_alive_cells = 0;
	while (placed_alive_cells < num_alive_cells) {
		int row = rand() % grid->rows;
		int col = rand() % grid->cols;

		if (grid->grid[row][col] == DEAD) {
			grid->grid[row][col] = ALIVE;
			placed_alive_cells++;
		}
	}
}

/**
 * @brief Updates the grid to the next generation.
 *
 * @param grid Pointer to the grid to be updated.
 */
void update_grid(Grid* grid) {
	Grid* new_grid = create_grid(grid->rows, grid->cols);

	for (int i = 0; i < grid->rows; i++) {
		for (int j = 0; j < grid->cols; j++) {
			int alive_neighbors = count_alive_neighbors(grid, i, j);

			if (grid->grid[i][j] == ALIVE) {
				new_grid->grid[i][j] = (alive_neighbors < 2 || alive_neighbors > 3) ? DEAD : ALIVE;
			} 
			else {
				new_grid->grid[i][j] = (alive_neighbors == 3) ? ALIVE : DEAD;
			}
		}
	}

	// Copy new grid state back to the original grid
	for (int i = 0; i < grid->rows; i++) {
		for (int j = 0; j < grid->cols; j++) {
			grid->grid[i][j] = new_grid->grid[i][j];
		}
	}

	delete_grid(new_grid);
}

/**
 * @brief Counts the number of alive neighbors for a given cell.
 *
 * @param grid Pointer to the grid.
 * @param row Row index of the cell.
 * @param col Column index of the cell.
 * @return Number of alive neighbors.
 */
int count_alive_neighbors(const Grid* grid, int row, int col) {
	int alive_count = 0;

	for (int i = -1; i <= 1; i++) {
		for (int j = -1; j <= 1; j++) {
			if (i == 0 && j == 0) continue; // Skip the cell itself

			int r = row + i;
			int c = col + j;
			if (r >= 0 && r < grid->rows && c >= 0 && c < grid->cols) {
				if (grid->grid[r][c] == ALIVE) {
					alive_count++;
				}
			}
		}
	}

	return alive_count;
}
