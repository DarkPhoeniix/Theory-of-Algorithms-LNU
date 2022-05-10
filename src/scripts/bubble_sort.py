"""Implementation of bubble sort"""


def bubble_sort(array: list[int], array_length: int) -> None:
    """Function, which sorts an array using bubble sort algorithm """
    for i in range(array_length):
        for j in range(array_length):
            if array[i] < array[j]:
                array[i], array[j] = array[j], array[i]
    print(array)
