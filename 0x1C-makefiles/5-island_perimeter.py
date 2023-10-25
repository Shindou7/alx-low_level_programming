#!/usr/bin/python3
"""
Module calculateIslandPerimeter
"""


def island_perimeter(grid)):
    """Calculate the perimeter of the island
    in the grid where "1" is found
    """
    perimeter=0

    for row in range(len(grid)):
        for col in range(len(grid[0])):
            if grid[row][col] == 1:
                if row == 0 or grid[row - 1][col] == 0:
                    perimeter += 1  # Top side
                if row == (len(grid) - 1) or grid[row + 1][col] == 0:
                    perimeter += 1  # Bottom side
                if col == 0 or grid[row][col - 1] == 0:
                    perimeter += 1  # Left side
                if col == (len(grid[0]) - 1) or grid[row][col + 1] == 0:
                    perimeter += 1  # Right side
    return perimeter
