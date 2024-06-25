#include <stdio.h>
#include "grid.h"

void test_create_grid() {
	int t = 0;
	int f = 0;

	fprintf(stderr, "Testing create_grid ");

	Grid* grid = create_grid(5, 5);

	if ( grid != NULL ) { fprintf(stderr,"."); t++; } else { fprintf(stderr,"x"); f++; }
	if ( grid != NULL && grid->rows == 5 ) { fprintf(stderr,"."); t++; } else { fprintf(stderr,"x"); f++; }
	if ( grid != NULL && grid->cols == 5 ) { fprintf(stderr,"."); t++; } else { fprintf(stderr,"x"); f++; }

	int all_dead = 1;
	for (int i = 0; i < grid->rows; i++) {
		for (int j = 0; j < grid->cols; j++) {
			if (grid->grid[i][j] != DEAD) {
				all_dead = 0;
			}
		}
	}
	if (all_dead) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

	delete_grid(grid);

	fprintf(stderr, " DONE (%d/%d)\n", t, t+f);
}

void test_save_grid() {
	int t = 0;
	int f = 0;

	fprintf(stderr, "Testing save_grid ");

	Grid* grid = create_grid(2, 2);
	grid->grid[0][0] = ALIVE;
	grid->grid[1][1] = ALIVE;

	save_grid(grid, "test/test_grid.txt");

	FILE* file = fopen("test/test_grid.txt", "r");
	if (file != NULL) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

	int rows, cols;
	if (fscanf(file, "%d %d\n", &rows, &cols) == 2) {
		if (rows == 2) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
		if (cols == 2) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	}
	else {
		fprintf(stderr, "xx");
		f += 2;
	}

	int ch;
	if ((ch = fgetc(file)) == 'O') { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if ((ch = fgetc(file)) == '.') { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if ((ch = fgetc(file)) == '\n') { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if ((ch = fgetc(file)) == '.') { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if ((ch = fgetc(file)) == 'O') { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if ((ch = fgetc(file)) == '\n') { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

	fclose(file);
	remove("test/test_grid.txt");
	delete_grid(grid);

	fprintf(stderr, " DONE (%d/%d)\n", t, t + f);
}

void test_load_grid() {
	int t = 0;
	int f = 0;

	fprintf(stderr, "Testing load_grid ");

	Grid* grid = create_grid(2, 2);
	grid->grid[0][0] = ALIVE;
	grid->grid[1][1] = ALIVE;

	save_grid(grid, "test/test_grid.txt");

	Grid* loaded_grid = load_grid("test/test_grid.txt");
	if (loaded_grid != NULL) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if (loaded_grid != NULL && loaded_grid->rows == 2) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if (loaded_grid != NULL && loaded_grid->cols == 2) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if (loaded_grid != NULL && loaded_grid->grid[0][0] == ALIVE) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if (loaded_grid != NULL && loaded_grid->grid[0][1] == DEAD) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if (loaded_grid != NULL && loaded_grid->grid[1][0] == DEAD) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }
	if (loaded_grid != NULL && loaded_grid->grid[1][1] == ALIVE) { fprintf(stderr, "."); t++; } else { fprintf(stderr, "x"); f++; }

	remove("test/test_grid.txt");
	delete_grid(grid);
	delete_grid(loaded_grid);

	fprintf(stderr, " DONE (%d/%d)\n", t, t + f);
}

void test_grid() {
	printf("\n\tTEST GRID\n");

	test_create_grid();
	test_save_grid();
	test_load_grid();
}
