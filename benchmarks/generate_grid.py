import random
import argparse

def generate_grid(rows, cols, num_alive_cells):
    """
    Generates a grid for Conway's Game of Life with specified dimensions and number of alive cells.

    Args:
    rows (int): Number of rows in the grid.
    cols (int): Number of columns in the grid.
    num_alive_cells (int): Number of alive cells to be placed in the grid.

    Returns:
    list: 2D list representing the grid.
    """
    # Initializes the grid with only dead cells
    grid = [['.' for _ in range(cols)] for _ in range(rows)]

    # Use a set to track unique positions for alive cells
    alive_cells = set()

    # Randomly place alive cells in the grid
    while len(alive_cells) < num_alive_cells:
        cell = (random.randint(0, rows - 1), random.randint(0, cols - 1))
        alive_cells.add(cell)

    # Mark the alive cells in the grid
    for (r, c) in alive_cells:
        grid[r][c] = '0'

    return grid

def save_grid_to_file(grid, filename):
    """
    Saves the grid to a file.

    Args:
    grid (list): 2D list representing the grid.
    filename (str): Name of the file to save the grid.
    """
    with open(filename, 'w') as file:
        for row in grid:
            file.write(''.join(row) + '\n')

def main():
    """
    Main function to parse arguments and generate the grid.
    """
    # Argument parser for command line arguments
    parser = argparse.ArgumentParser(description="Generate a grid for Conway's Game of Life.")
    parser.add_argument('rows', type=int, help='Number of rows in the grid')
    parser.add_argument('cols', type=int, help='Number of columns in the grid')
    parser.add_argument('num_alive_cells', type=int, help='Number of alive cells in the grid')
    parser.add_argument('filename', type=str, help='Output file to save the grid')

    # Parse the command line arguments
    args = parser.parse_args()

    # Generate the grid with specified parameters
    grid = generate_grid(args.rows, args.cols, args.num_alive_cells)

    # Save the generated grid to a file
    save_grid_to_file(grid, args.filename)

if __name__ == "__main__":
    main()
