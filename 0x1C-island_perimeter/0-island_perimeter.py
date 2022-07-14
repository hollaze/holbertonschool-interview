#!/usr/bin/python3
"""
Create a function def island_perimeter(grid): that
returns the perimeter of the island described in grid
"""


def island_perimeter(grid):
    """
    Return the perimeter of the island described in grid
    """

    perimeter = 0

    for i in range(len(grid)):
        for j in range(len(grid[0])):
            if grid[i][j] == 1:
                perimeter += 4

                if j > 0 and grid[i][j - 1] == 1:
                    perimeter -= 2

                elif i > 0 and grid[i - 1][j] == 1:
                    perimeter -= 2

    return perimeter
