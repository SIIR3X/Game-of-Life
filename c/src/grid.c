#include "grid.h"

/**
 * @brief Creates a grid with specified rows and columns.
 *
 * @param rows Number of rows in the grid.
 * @param cols Number of columns in the grid.
 * @return Pointer to the created grid.
 */
Grid* create_grid(int rows, int cols) {
	Grid* grid = (Grid*)malloc(sizeof(Grid));
	grid->rows = rows;
	grid->cols = cols;
	grid->grid = (char**)malloc(rows * sizeof(char*));

	for (int i = 0; i < rows; i++) {
		grid->grid[i] = (char*)malloc(cols * sizeof(char));

		for (int j = 0; j < cols; j++) {
			grid->grid[i][j] = DEAD;
		}
	}

	return grid;
}

/**
 * @brief Saves the grid to a file.
 *
 * The first line of the file will contain the number of rows and columns.
 * Subsequent lines will contain the grid data.
 *
 * @param grid Pointer to the grid to be saved.
 * @param filename Name of the file to save the grid to.
 */
void save_grid(const Grid* grid, const char* filename) {
	FILE* file = fopen(filename, "w");
	if (file == NULL) {
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	// Write the number of rows and columns as the first line
	fprintf(file, "%d %d\n", grid->rows, grid->cols);

	for (int i = 0; i < grid->rows; i++) {
		for (int j = 0; j < grid->cols; j++) {
			fputc(grid->grid[i][j], file);
		}

		fputc('\n', file);
	}

	fclose(file);
}

/**
 * @brief Loads a grid from a file.
 *
 * The first line of the file should contain the number of rows and columns.
 * Subsequent lines should contain the grid data.
 *
 * @param filename Name of the file to load the grid from.
 * @return Pointer to the loaded grid.
 */
Grid* load_grid(const char* filename) {
	FILE* file = fopen(filename, "r");
	if (file == NULL) {
		perror("Failed to open file");
		exit(EXIT_FAILURE);
	}

	int rows, cols;
	if (fscanf(file, "%d %d\n", &rows, &cols) != 2) {
		perror("Failed to read grid dimensions");
		fclose(file);
		exit(EXIT_FAILURE);
	}

	Grid* grid = create_grid(rows, cols);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			int ch = fgetc(file);
			
			if (ch == EOF || ch == '\n') {
				break;
			}

			grid->grid[i][j] = (char)ch;
		}

		fgetc(file);
	}

	fclose(file);

	return grid;
}

/**
 * @brief Displays the generation counter.
 *
 * @param generation The current generation number.
 */
void print_generation_counter(int generation) {
    printf("Generation: %d\n", generation);
}

/**
 * @brief Affiche la grille à l'écran.
 *
 * @param grid Le pointeur vers la grille à afficher.
 */
void print_grid(const Grid* grid) {
    for (int i = 0; i < grid->rows; i++) {
        for (int j = 0; j < grid->cols; j++) {
            printf("%c", grid->grid[i][j] == ALIVE ? 'O' : '.');
        }
		
        printf("\n");
    }
}

/**
 * @brief Delete a grid and frees its memory.
 *
 * @param grid Pointer to the grid to delete.
 */
void delete_grid(Grid* grid) {
	for (int i = 0; i < grid->rows; i++) {
		free(grid->grid[i]);
	}

	free(grid->grid);
	free(grid);
}
