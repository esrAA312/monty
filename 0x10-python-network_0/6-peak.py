#!/usr/bin/python3
"""Algorithms for list of integers."""


def find_peak(list_of_integers):
    """Finds a peak in a list of unsorted integers."""
    if not list_of_integers or list_of_integers == []:
        return None
    list_of_integers.sort(reverse=True)
    return list_of_integers[0]
