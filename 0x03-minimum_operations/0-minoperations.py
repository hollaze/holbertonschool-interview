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


def isPrimeNumber(n):
    """
    isPrimeNumber : Find is n is a prime number

    Parameter :
        (int) n : number

    Return :
        True if n is a prime number, False otherwise
    """
    for i in range(2, n - 1):
        if n % i == 0:
            return (True)
    return (False)


def minOperations(n):
    """
    minOperations : Calculates the fewest number of
                    operations needed to result in exactly n H

    Parameter :
        (int) n : number of H to get

    Return :
        Number of operations
    """

    minActionNumber = 0
    numberOfActions = 0
    divResult = 0
    dividedBy = 0

    if n <= 1:
        return (numberOfActions)

    if isPrimeNumber(n) is False:
        numberOfActions = n
        return (numberOfActions)

    for i in range(2, n - 1):
        if n % i == 0:
            divResult = n / i
            dividedBy = i
            numberOfActions = divResult + dividedBy
            if minActionNumber == 0:
                minActionNumber = numberOfActions
            elif numberOfActions < minActionNumber:
                minActionNumber = dividedBy + divResult

    return (minActionNumber)
