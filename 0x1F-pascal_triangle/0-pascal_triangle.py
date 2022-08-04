#!/usr/bin/python3
"""
Pascal's Triangle
"""


def pascal_triangle(n):
    """
    Returns a list of lists of integers
    representing the Pascal’s triangle of n
    """

    t = []
    if n <= 0:
        return t
    t = [[1]]
    if n == 1:
        return t
    t = []
    for i in range(n):
        base = [1]
        for j in range(i):
            base.append(sum(t[-1][j:j+2]))
        t.append(base)
    return t
