#!/usr/bin/python3
""" determines if a given data set represents a valid UTF-8 encoding """


def validUTF8(data):
    """ return True if the data set represents a valid UTF-8 encoding
        False otherwise"""
    for value in data:
        if value < 32 or value > 126:
            return False

    return True
