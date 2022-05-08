
#include "Sort.h"

#include <utility>
#include <cstring>
#include <vector>

namespace Sort
{
    namespace
    {
        int findMaximumLength(int* arr, size_t size)
        {
            int max = std::abs(arr[0]);
            for (size_t i = 0; i < size; ++i)
            {
                if (std::abs(arr[i]) > max)
                {
                    max = std::abs(arr[i]);
                }
            }

            return max;
        }
    }

    void bubbleSort(int* array, size_t size)
    {
        for (size_t i = 0; i < size; ++i)
        {
            for (size_t j = 0; j < size; ++j)
            {
                if (array[i] < array[j])
                {
                    std::swap(array[i], array[j]);
                }
            }
        }
    }
} // namespace Sort
