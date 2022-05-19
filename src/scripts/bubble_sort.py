"""Implementation of bubble sort"""


def bubble_sort(array: list[int]) -> None: #1 + n*(n*8)
    """Function, which sorts an array using bubble sort algorithm """
    size = len(array) # 1
    for i in range(size): # n

        for j in range(size): # n

            if array[i] < array[j]: # 1+1+1
                array[i], array[j] = array[j], array[i] # 1+1+1+1+1
