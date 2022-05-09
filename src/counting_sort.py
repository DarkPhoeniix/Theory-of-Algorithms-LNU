"""Implementation of counting sort in python"""


def counting_sort(array: list[int], radix: int):
    """Function, which sorts an array by specified radix
    using counting sort algorithm
    """
    array_length = len(array)

    output = [0 for _ in range(array_length)]

    count = [0 for _ in range(10)]

    for i in range(0, array_length):
        index = array[i] // radix
        count[index % 10] += 1

    for i in range(1, 10):
        count[i] += count[i - 1]

    i = array_length - 1
    while i >= 0:
        index = array[i] // radix
        output[count[index % 10] - 1] = array[i]
        count[index % 10] -= 1
        i -= 1

    last_appended_index = 0
    for i in range(0, len(array)):
        if output[i] < 0:
            array[last_appended_index] = output[i]
            last_appended_index += 1

    for i in range(0, len(array)):
        if output[i] > 0:
            array[last_appended_index] = output[i]
            last_appended_index += 1
