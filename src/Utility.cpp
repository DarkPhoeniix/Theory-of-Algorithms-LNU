
#include <algorithm>
#include <cuchar>
#include <utility>
#include <iostream>
#include <random>

namespace Utility
{
    void fillRandom(int *array, int size, int leftBorder, int rightBorder)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(leftBorder, rightBorder);

        for (size_t i = 0; i < size; ++i)
        {
            array[i] = distrib(gen);
        }
    }

    void fillSortedSubArrays(int* array, int size, int leftBorder, int rightBorder)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> distrib(leftBorder, rightBorder);

        int step = size / 10;
        for (size_t i = 0; i < size; ++i)
        {
            array[i] = distrib(gen);
        }

        for (size_t i = 0; i < size; i += step)
        {
            std::sort((array + i), (array + i + step));
        }
    }

    void fillSorted(int* array, int size, int leftBorder, int rightBorder)
    {
        fillRandom(array, size, leftBorder, rightBorder);

        std::sort(array, array + size);
    }

    void fillSortedWithSwaps(int* array, int size, int leftBorder, int rightBorder)
    {
        fillSorted(array, size, leftBorder, rightBorder);

        int step = size / 10;
        for (size_t i = 0; i < size; i += step)
        {
            std::swap(array[i], array[i + 1]);
        }
    }

    void fillSortedReversed(int* array, int size, int leftBorder, int rightBorder)
    {
        fillRandom(array, size, leftBorder, rightBorder);

        std::sort(array, array + size, std::greater<>());
    }

    void printArray(int* array, int size)
    {
        std::cout << std::endl;
        std::for_each(array, array + size, [](auto item){ std::cout << item << ' '; });
        std::cout << std::endl;
    }
} // namespace Utility
