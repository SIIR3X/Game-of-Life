#ifndef GRID_H
#define GRID_H

#include <stdio.h>
#include <stdlib.h>

#define ALIVE 'O'
#define DEAD '.'

/**
 * @brief Structure to represent a grid for Conway's Game of Life.
 */
typedef struct {
	int rows; /**< Number of rows in the grid */
	int cols; /**< Number of columns in the grid */
	char **grid; /**< 2D array to store the state of each cell */
} Grid;

/**
 * @brief Creates a grid with specified rows and columns.
 *
 * @param rows Number of rows in the grid.
 * @param cols Number of columns in the grid.
 * @return Pointer to the created grid.
 */
Grid* create_grid(int rows, int cols);

/**
 * @brief Loads a grid from a file.
 *
 * @param filename Name of the file to load the grid from.
 * @return Pointer to the loaded grid.
 */
void save_grid(const Grid* grid, const char* filename);

/**
 * @brief Destroys a grid and frees its memory.
 *
 * @param grid Pointer to the grid to be destroyed.
 */
Grid* load_grid(const char* filename);

/**
 * @brief Displays the generation counter.
 * 
 * @param generation The current generation number.
 */
void print_generation_counter(int generation);

/**
 * @brief Prints the grid to the console.
 *
 * @param grid Pointer to the grid to be printed.
 */
void print_grid(const Grid* grid);

/**
 * @brief Saves the grid to a file.
 *
 * @param grid Pointer to the grid to be saved.
 * @param filename Name of the file to save the grid to.
 */
void delete_grid(Grid* grid);

#endif // GRID_H
