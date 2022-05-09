
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

    void countingSort(int* array, size_t size, int exp)
    {
        int range = 10;

        int* count = new int[range];
        int* result = new int[size];

        for (size_t i = 0; i < range; ++i)
        {
            count[i] = 0;
        }

        for (size_t i = 0; i < size; ++i)
        {
            ++count[std::abs((array[i] / exp) % 10)];
        }

        for (size_t i = 1; i < range; ++i)
        {
            count[i] += count[i - 1];
        }

        for (int i = (static_cast<int>(size) - 1); i >= 0; i--)
        {
            result[(count[std::abs((array[i] / exp) % 10)] - 1)] = array[i];
            --count[std::abs((array[i] / exp) % 10)];
        }

        for (int i = 0; i < size; ++i)
        {
            array[i] = result[i];
        }

        delete[] result;
        delete[] count;
    }

    void radixSort(int* array, size_t size)
    {
        int max = findMaximumLength(array, size);
        int* sortedWithoutSign = new int[size];

        for (size_t i = 0; i < size; ++i)
        {
            sortedWithoutSign[i] = array[i];
        }

        for (int radix = 1; max / radix > 0; radix *= 10)
        {
            countingSort(sortedWithoutSign, size, radix);
        }

        int i = 0;
        for (int j = (static_cast<int>(size) - 1); j >= 0; --j)
        {
            if (sortedWithoutSign[j] < 0)
            {
                array[i++] = sortedWithoutSign[j];
            }
        }

        for (int j = 0; j < size; ++j)
        {
            if (sortedWithoutSign[j] >= 0)
            {
                array[i++] = sortedWithoutSign[j];
            }
        }
    }
} // namespace Sort
