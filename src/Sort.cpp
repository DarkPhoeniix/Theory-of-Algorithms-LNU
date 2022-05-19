
#include "Sort.h"

#include <algorithm>
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

    void bubbleSort(int* array, size_t size) // O(4n^2) --> O(n^2)
    {
        for (size_t i = 0; i < size; ++i) // n(n(4))
        {
            for (size_t j = 0; j < size; ++j) // n(4)
            {
                if (array[i] < array[j]) // 1+1+1
                {
                    std::swap(array[i], array[j]); // 1
                }
            }
        }
    }

    void countingSort(int* array, size_t size, int exp) // O(11+5k) --> O(k)
    {
        int range = 10; // 1

        int* count = new int[range]; // 1+1
        int* result = new int[size]; // 1+1

        for (size_t i = 0; i < range; ++i) // 1+k(1+1+1)
        {
            count[i] = 0; // 1
        }

        for (size_t i = 0; i < size; ++i) // 1+k(1+1+1+1+1+1+1+1)
        {
            ++count[std::abs((array[i] / exp) % 10)];
        }

        for (size_t i = 1; i < range; ++i) // 1+k(1+1+1+1+1)
        {
            count[i] += count[i - 1];
        }

        for (int i = (static_cast<int>(size) - 1); i >= 0; i--) // 1+k(1+1+1+1+1+1+1+1+1+1+1+1+1+1+1+1)
        {
            result[(count[std::abs((array[i] / exp) % 10)] - 1)] = array[i];
            --count[std::abs((array[i] / exp) % 10)];
        }

        for (int i = 0; i < size; ++i) // 1+k(1+1+1+1+1)
        {
            array[i] = result[i];
        }

        delete[] result;
        delete[] count;
    }

    void radixSort(int* array, size_t size) // O(7+17n+m*k) --> O(k*m+n) | k=10 --> O(m+n)
    {
        int max = findMaximumLength(array, size); // 1
        int* sortedWithoutSign = new int[size]; // 1+1

        for (size_t i = 0; i < size; ++i) // 1+n(1+1+1+1+1) -> n
        {
            sortedWithoutSign[i] = array[i];
        }

        for (int radix = 1; max / radix > 0; radix *= 10) // 1+m(O(k)) -> k*m
        {
            countingSort(sortedWithoutSign, size, radix);
        }

        int i = 0;
        for (int j = (static_cast<int>(size) - 1); j >= 0; --j) // 1+n(1+1+1+1+1+1) -> n
        {
            if (sortedWithoutSign[j] < 0)
            {
                array[i++] = sortedWithoutSign[j];
            }
        }

        for (int j = 0; j < size; ++j) // 1+n(1+1+1+1+1+1+1) -> n
        {
            if (sortedWithoutSign[j] >= 0)
            {
                array[i++] = sortedWithoutSign[j];
            }
        }
    }

    void stdSort(int* array, size_t size)
    {
        std::sort(array, array + size);
    }
} // namespace Sort
