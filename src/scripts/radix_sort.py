"""Implementation of radix sort in python"""

#1 + n + 10 + n*7 + 50 + 2 + k*15 + 1 + 2*n*7
# 1 + 10 + 50 + 2 + 1
# 22n + 15y

# 64 + 22x + 15y
def counting_sort(array: list[int], radix: int):
    """Function, which sorts an array by specified radix
    using counting sort algorithm
    """
    array_length = len(array) #1

    output = [0 for _ in range(array_length)] #n

    count = [0 for _ in range(10)] # 10

    for i in range(0, array_length): # n
        index = array[i] // radix # 1 + 1 + 1
        count[index % 10] += 1 # 1 + 1 + 1 + 1

    for i in range(1, 10): # 9
        count[i] += count[i - 1] #1 + 1 + 1 + 1 + 1

    i = array_length - 1 # 1 + 1
    while i >= 0: # k
        index = array[i] // radix # 1 + 1 + 1
        output[count[index % 10] - 1] = array[i] # 1 + 1 + 1 + 1 + 1 + 1
        count[index % 10] -= 1 # 1 + 1 + 1 + 1
        i -= 1 # 1 + 1

    last_appended_index = 0 # 1
    for i in range(0, len(array)): # n
        if output[i] < 0: # 1 + 1
            array[last_appended_index] = output[i] # 1 + 1 +1
            last_appended_index += 1 # 1 + 1

    for i in range(0, len(array)): # n + 1
        if output[i] > 0: # 1 + 1
            array[last_appended_index] = output[i] #1 + 1 + 1
            last_appended_index += 1 # 1 + 1

#n + 1 + k * (63 + 22x + 15y) + 2
def radix_sort(array: list[int]):
    """Function, which sorts an array using radix sort algorithm"""
    maximum_element = max(array) #n

    radix = 1 # 1
    while maximum_element / radix > 1: #k * (64 + 22x + 15y)
        counting_sort(array, radix)
        radix *= 10 # 1 + 1
