#!/usr/bin/python3
"""
Given a list of non-negative integers representing walls of width 1, calculate
how much water will be retained after it rains.

Assuming that the ends of the list (before index 0 and after
index walls[-1]) are not walls, meaning they will not retain water.
"""


def rain(walls):
    """
    rain function
    """
    wallNumber = len(walls)
    water = 0

    for i in range(1, wallNumber - 1):
        left = walls[i]
        for j in range(i):
            left = max(left, walls[j])
        right = walls[i]

        for j in range(i + 1, wallNumber):
            right = max(right, walls[j])

        water = water + (min(left, right) - walls[i])
    return water
