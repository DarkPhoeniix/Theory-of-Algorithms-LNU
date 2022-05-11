"""Implementation of bubble sort"""


def bubble_sort(array: list[int]) -> None:
    """Function, which sorts an array using bubble sort algorithm """
    size = len(array)
    for i in range(size):
        for j in range(size):
            if array[i] < array[j]:
                array[i], array[j] = array[j], array[i]
