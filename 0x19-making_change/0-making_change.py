#!/usr/bin/python3
"""
Making money Change
"""
import sys


def makeChange(coins, total):
    """
    Given a pile of coins of different values,
    determine the fewest number of coins needed
    to meet a given amount total
    """
    sum = 0

    if (total <= 0):
        return 0

    coins.sort(reverse=True)

    for i in coins:

        quotient, rest = divmod(total, i)

        total = rest
        sum += quotient

    if (total != 0):
        return -1

    return sum
