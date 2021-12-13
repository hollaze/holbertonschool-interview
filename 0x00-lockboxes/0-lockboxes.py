#!/usr/bin/python3
""" You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes. """


def canUnlockAll(boxes):
    """
    canUnlockAll - unlock all boxes

    Parameter:
        boxes: 2D list - boxes to unlock
    """
    keys = [0]

    for val in boxes:
        for key in keys:
            keys.append(val)
            print(keys)

    return (True)
