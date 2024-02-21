#!/usr/bin/python3
"""Defines an island perimeter measuring function."""


def island_perimeter(grid):
    """Return the perimiter of an island"""
    rows, cols = len(grid), len(grid[0])
    island_size, shared_edges = 0, 0

    for i in range(rows):
        for j in range(cols):
            if grid[i][j] == 1:
                island_size += 1
                if j > 0 and grid[i][j - 1] == 1:
                    shared_edges += 1
                if i > 0 and grid[i - 1][j] == 1:
                    shared_edges += 1

    total_perimeter = island_size * 4 - shared_edges * 2
    return total_perimeter
