#!/usr/bin/python3
"""An island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island.
    """
    width = len(grid[0])
    height = len(grid)
    corners = 0
    length = 0

    for i in range(height):
        for j in range(width):
            if grid[i][j] == 1:
                length += 1
                if (j > 0 and grid[i][j - 1] == 1):
                    corners += 1
                if (i > 0 and grid[i - 1][j] == 1):
                    corners += 1
    return  length * 4 - corners * 2
