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
    if total <= 0:
        return 0

    res = minCoins(coins, total)

    if res == 0:
        return -1

    return res


def minCoins(coins, total):
    """
    Find the minimum coins needed to make the change
    """
    table = [0 for i in range(total + 1)]
    table[0] = 0

    for i in range(1, total + 1):
        table[i] = sys.maxsize

    for i in range(1, total + 1):
        for j in range(len(coins)):

            if (coins[j] <= i):
                sub_res = table[i - coins[j]]

                if (sub_res != sys.maxsize and
                        sub_res + 1 < table[i]):
                    table[i] = sub_res + 1

    if table[total] == sys.maxsize:
        return -1

    return table[total]
