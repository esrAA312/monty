#!/usr/bin/python3
"""
 Rotate the given n x n 2D matrix 90 degrees clockwise in-place.
"""


def rotate_2d_matrix(matrix):
    """
    Rotates a given 2D matrix 90 degrees clockwise.
    """
    n = len(matrix)
    # Rotate the matrix layer by layer
    for i in range(n // 2):
        for j in range(i, n - i - 1):
            # Perform the 4-way exchange
            temp = matrix[i][j]
            matrix[i][j] = matrix[n - j - 1][i]
            matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1]
            matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1]
            matrix[j][n - i - 1] = temp
