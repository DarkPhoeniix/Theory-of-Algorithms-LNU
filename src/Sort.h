
#ifndef TASK_01_SORT_H
#define TASK_01_SORT_H

#include <cuchar>

namespace Sort
{
    void bubbleSort(int* array, size_t size);
    void countingSort(int* array, size_t size, int exp = 1);
    void radixSort(int* array, size_t size);
} // namespace Sort

#endif //TASK_01_SORT_H
