#!/usr/bin/python3
"""
Rotate a 2D matrix
"""


def rotate_2d_matrix(matrix):
    """
    Rotate the matrix 90 degree clockwise
    """
    matrix_len = len(matrix[0])

    for i in range(matrix_len // 2):
        for j in range(i, matrix_len - i - 1):
            temp = matrix[i][j]

            matrix[i][j] = matrix[matrix_len - 1 - j][i]
            matrix[matrix_len - 1 - j][i] =\
                matrix[matrix_len - 1 - i][matrix_len - 1 - j]

            matrix[matrix_len - 1 - i][matrix_len - 1 - j] =\
                matrix[j][matrix_len - 1 - i]
            matrix[j][matrix_len - 1 - i] = temp

    return matrix
