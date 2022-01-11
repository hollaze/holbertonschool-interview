#!/usr/bin/python3
"""
In a text file, there is a single character H.
Your text editor can execute only two operations in this file:
Copy All and Paste.
Given a number n, write a method that calculates the fewest number of
operations needed to result in exactly n H characters in the file.
Example:
n = 9
H => Copy All => Paste => HH => Paste =>HHH =>
Copy All => Paste => HHHHHH => Paste => HHHHHHHHH
Number of operations: 6
"""


def minOperations(n):
    """
    minOperations : Calculates the fewest number of
                    operations needed to result in exactly n H
    Parameter :
        (int) n : number of H to get
    Return :
        Number of operations
    """

    if n <= 1:
        return (0)

    k = 2

    # Check if is prime number
    while k * k <= n:
        if n % k == 0:
            return (minOperations(k) + minOperations(n // k))
        k += 1

    return (n)
