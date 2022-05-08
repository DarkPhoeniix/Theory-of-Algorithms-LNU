
#ifndef TASK_01_UTILITY_H
#define TASK_01_UTILITY_H

namespace Utility
{
    void fillRandom(int* array, int size, int leftBorder, int rightBorder);
    void fillSortedSubArrays(int* array, int size, int leftBorder, int rightBorder);
    void fillSorted(int* array, int size, int leftBorder, int rightBorder);
    void fillSortedWithSwaps(int* array, int size, int leftBorder, int rightBorder);
    void fillSortedReversed(int* array, int size, int leftBorder, int rightBorder);
    void printArray(int* array, int size);
} // namespace Utility

#endif // TASK_01_UTILITY_H
