"""Implementation of radix sort in python"""
from counting_sort import counting_sort


def radix_sort(array: list[int]):
    """Function, which sorts an array using radix sort algorithm"""
    maximum_element = max(array)

    radix = 1
    while maximum_element / radix > 1:
        counting_sort(array, radix)
        radix *= 10
