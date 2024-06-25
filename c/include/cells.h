#ifndef CELLS_H
#define CELLS_H

#include "grid.h"

/**
 * @brief Initializes the grid with a specified number of alive cells.
 *
 * @param grid Pointer to the grid to be initialized.
 * @param num_alive_cells Number of alive cells to be placed in the grid.
 */
void initialize_grid(Grid* grid, int num_alive_cells);

/**
 * @brief Updates the grid to the next generation.
 *
 * @param grid Pointer to the grid to be updated.
 */
void update_grid(Grid* grid);

/**
 * @brief Counts the number of alive neighbors for a given cell.
 *
 * @param grid Pointer to the grid.
 * @param row Row index of the cell.
 * @param col Column index of the cell.
 * @return Number of alive neighbors.
 */
int count_alive_neighbors(const Grid* grid, int row, int col);

#endif // CELLS_H
