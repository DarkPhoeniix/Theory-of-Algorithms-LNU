
#include "Utility.h"
#include "Sort.h"

#include <iostream>
#include <chrono>

const int SIZE = 100000;

int main(int argc, char* argv[])
{
    int* array = new int[SIZE];

    Utility::fillRandom(array, SIZE, -100, 100);

    std::chrono::time_point start = std::chrono::high_resolution_clock::now();
    Sort::bubbleSort(array, SIZE);
    std::chrono::time_point end = std::chrono::high_resolution_clock::now();

    std::cout << "Bubble sort: " << '\n'
        << "size: " << SIZE << '\n'
        << "time: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    Utility::fillRandom(array, SIZE, -100, 100);

    start = std::chrono::high_resolution_clock::now();
    Sort::countingSort(array, SIZE);
    end = std::chrono::high_resolution_clock::now();

    std::cout << "Counting sort: " << '\n'
              << "size: " << SIZE << '\n'
              << "time: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    Utility::fillRandom(array, SIZE, -100, 100);

    start = std::chrono::high_resolution_clock::now();
    Sort::radixSort(array, SIZE);
    end = std::chrono::high_resolution_clock::now();

    std::cout << "Radix sort: " << '\n'
              << "size: " << SIZE << '\n'
              << "time: " <<  std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms" << std::endl;

    delete[] array;

    return 0;
}
