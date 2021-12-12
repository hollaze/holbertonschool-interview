#!/usr/bin/python3
""" You have n number of locked boxes in front of you.
Each box is numbered sequentially from 0 to n - 1 and
each box may contain keys to the other boxes. """


def canUnlockAll(boxes):
    """ Unlock all boxes

    Arg:
        boxes (2D list): boxes to unlock
    """

    keys = [0]

    for key in keys:
        for val in boxes[key]:
            if val not in keys:
                keys.append(val)

    return len(keys) == len(boxes)
